<?php

require_once TPT_ROOT . '/' . ('transperfect_settings.inc');
require_once TPT_ROOT . '/' . ('transperfect_common.inc');
require_once TPT_ROOT . '/' . ('gl_ws/gl_ws_common.inc');
require_once TPT_ROOT . '/' . ('gl_ws/gl_ws_receive_translations.inc');

function send_taxonomies_for_translations($lids, $pd4, $submission_name, $due_date, $project_code, $source_locale, $target_locale_arr, $submission_details) {
  $strings = transperfect_get_taxonomy_strings(get_drupal_locale_code($source_locale), 'taxonomy');
  $submitter = $submission_details['submitter'];
  $globalLink_arr = array();
  foreach ($lids as $lid) {
    $rows = get_sent_tpt_taxonomy_rows_by_bid($lid);
    $target_arr = $target_locale_arr;
    foreach ($rows as $row) {
      if (array_search($row->target, $target_locale_arr)) {
        unset($target_arr[$row->target]);
      }
    }
    if (empty($target_arr)) {
      continue;
    }

    $title_string_arr = isset($strings["taxonomy:term:$lid:name"]) ? $strings["taxonomy:term:$lid:name"] : FALSE;
    $desc_string_arr = isset($strings["taxonomy:term:$lid:description"]) ? $strings["taxonomy:term:$lid:description"] : FALSE;
    if (!$title_string_arr) {
      continue;
    }
    $xml = get_taxonomy_xml($lid, $title_string_arr, $desc_string_arr);

    $name = "Taxonomy_" . $lid . ".xml";
    $globalLink = new GlobalLink();
    $globalLink->type = 'taxonomy';
    $globalLink->metadata = "Taxonomy";
    $globalLink->sourceLocale = $source_locale;
    $globalLink->targetLocale = $target_arr;
    $globalLink->sourceXML = $xml;
    $globalLink->sourceFileName = $name;
    $globalLink->submissionName = $submission_name;
    $globalLink->dueDate = $due_date;
    $globalLink->otherObjectId = $lid;
    $globalLink->submissionInstructions = $submission_details['instructions'] . "\nSubmitter: " . $submitter;
    $globalLink_arr[] = $globalLink;
  }

  if (!empty($globalLink_arr)) {
    sendDocumentsForTranslationToPD($globalLink_arr, $pd4, $project_code, $submitter);
  }
  return $globalLink_arr;
}

function get_taxonomy_xml($lid, $title_string_arr, $desc_string_arr) {
  $dom = new DOMDocument('1.0', 'UTF-8');
  $dom->formatOutput = TRUE;

  $root = $dom->createElement("content");
  $dom->appendChild($root);

  $id = $dom->createAttribute('bid');
  $id->value = $lid;
  $root->appendChild($id);

  if ($title_string_arr) {
    insert_child_element($dom, $root, "taxonomy", $title_string_arr['source'], array('name' => 'name', 'lid' => $title_string_arr['lid'],
        'location' => $title_string_arr['location'],
        'context' => $title_string_arr['context']));
  }
  if ($desc_string_arr) {
    insert_child_element($dom, $root, "taxonomy", $desc_string_arr['source'], array('name' => 'description', 'lid' => $desc_string_arr['lid'],
        'location' => $desc_string_arr['location'],
        'context' => $desc_string_arr['context']));
  }

  $xml = $dom->saveXML();
  return $xml;
}

function transperfect_get_taxonomy_strings($language = NULL, $group = 'taxonomy') {
  if (isset($language)) {
    $result = db_query("SELECT s.lid, s.source, s.context, s.location, t.plid, t.plural FROM {locales_source} s LEFT JOIN {locales_target} t ON s.lid = t.lid AND t.language = :language WHERE s.textgroup = :textgroup ORDER BY t.plid, t.plural", array(':language' => $language, ':textgroup' => $group));
  }
  else {
    $result = db_query("SELECT s.lid, s.source, s.context, s.location, t.plid, t.plural FROM {locales_source} s LEFT JOIN {locales_target} t ON s.lid = t.lid WHERE s.textgroup = :textgroup ORDER BY t.plid, t.plural", array(':textgroup' => $group));
  }
  $strings = array();
  foreach ($result as $child) {
    $string = array(
        'lid' => $child->lid,
        'location' => $child->location,
        'source' => $child->source,
        'context' => $child->context,
    );
    $strings[$child->location] = $string;
  }
  return $strings;
}

function update_taxonomy_ticket_id($arr, $project_code) {
  foreach ($arr as $globalLink) {
    $target_locale_arr = $globalLink->targetLocale;
    $type = $globalLink->type;
    if ($type == 'taxonomy') {
      $bid = $globalLink->otherObjectId;
      $taxonomy = taxonomy_term_load($bid);
      foreach ($target_locale_arr as $target_locale) {
        $row = get_transperfect_taxonomy_row($bid, $type, $globalLink->sourceLocale, $target_locale);
        if ($row) {
          db_update('transperfect_core_taxonomy')
                  ->fields(array('title' => $taxonomy->name, 'document_ticket' => $globalLink->documentTicket,
                      'submission' => $globalLink->submissionName, 'submission_ticket' => $globalLink->submissionTicket,
                      'status' => TPT_STATUS_SENT_FOR_TRANSLATIONS, 'timestamp' => REQUEST_TIME, 'last_modified' => REQUEST_TIME, 'project_code' => $project_code))
                  ->condition('rid', $row->rid, '=')
                  ->execute();
        }
        else {
          db_insert('transperfect_core_taxonomy')
                  ->fields(array('object_id' => $bid, 'object_type' => $globalLink->type, 'title' => $taxonomy->name,
                      'source' => $globalLink->sourceLocale, 'target' => $target_locale, 'document_ticket' => $globalLink->documentTicket,
                      'submission' => $globalLink->submissionName, 'submission_ticket' => $globalLink->submissionTicket,
                      'status' => TPT_STATUS_SENT_FOR_TRANSLATIONS, 'timestamp' => REQUEST_TIME, 'last_modified' => REQUEST_TIME, 'project_code' => $project_code))
                  ->execute();
        }
      }
    }
  }
}

function get_transperfect_taxonomy_row($object_id, $object_type, $source, $target) {
  $result = db_select('transperfect_core_taxonomy', 'tco')
          ->fields('tco')
          ->condition('object_id', $object_id, '=')
          ->condition('object_type', $object_type, '=')
          ->condition('source', $source, '=')
          ->condition('target', $target, '=')
          ->execute();
  foreach ($result as $row) {
    return $row;
  }

  return FALSE;
}

function update_deleted_taxonomy_records($pd4, $globalLink) {
  try {
    $globalLink->status = TPT_STATUS_SOURCE_DELETED;
    sendDownloadConfirmation($globalLink->targetTicket, $pd4);
    update_tpt_taxonomy_status($globalLink, TPT_STATUS_SOURCE_DELETED);
  }
  catch (SoapFault $se) {
    gl_log(TPT_OBJECT_TYPE_TAXONOMY, TPT_LOGGING_SEVERITY_ERROR, "SOAP Exception in Sending Download Confirmation - update_deleted_taxonomy_records - Code[$se->faultcode], Message[$se->faultstring]");
    form_set_error('', check_plain('Web Services Error: ' . $se->faultcode . ' - ' . $se->faultstring));
    return FALSE;
  }
  catch (Exception $e) {
    gl_log(TPT_OBJECT_TYPE_TAXONOMY, TPT_LOGGING_SEVERITY_ERROR, "Exception in update_deleted_taxonomy_records - File[$e->getFile()], Line[$e->getLine()], Code[$e->getCode], Message[$e->getMessage]");
    form_set_error('', check_plain('Error: ' . $e->getMessage()));
    return FALSE;
  }

  return TRUE;
}

function get_taxonomy_translation_status($bid, $tgt_locale, &$title) {
  $query = db_select('transperfect_core_taxonomy', 'tco');
  $query->condition('object_id', $bid, '=');
  $query->condition('target', $tgt_locale, '=');
  $query->distinct();
  $query->fields('tco');
  $results = $query->execute();
  foreach ($results as $row) {
    $title = $row->title;
    $s_taxonomy = taxonomy_term_load($bid);
    if (!$s_taxonomy || is_null($s_taxonomy))
      return TPT_STATUS_SOURCE_DELETED;
    elseif ($row->status == TPT_STATUS_SENT_FOR_TRANSLATIONS)
      return TPT_STATUS_COMPLETED;
    elseif ($row->status == TPT_STATUS_ERROR)
      return TPT_STATUS_ERROR;
  }

  return TPT_STATUS_SENT_FOR_TRANSLATIONS;
}

function get_taxonomy_active_submission_names() {
  $query = db_select('transperfect_core_taxonomy', 'tco');
  $query->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN');
  $query->distinct();
  $query->fields('tco');
  $results = $query->execute();
  $arr = array('' => '-- Select a Submission --');
  foreach ($results as $row) {
    $arr[$row->submission] = $row->submission;
  }
  return $arr;
}

function cancel_taxonomy_records($rowids, $pd4) {
  $globalLink_arr = array();
  foreach ($rowids as $rid) {
    $row = get_transperfect_other_row($rid, 'taxonomy');
    $globalLink = new GlobalLink();
    $globalLink->tptRowId = $row->rid;
    $globalLink->documentTicket = $row->document_ticket;
    $globalLink->submissionTicket = $row->submission_ticket;
    $globalLink_arr[$rid] = $globalLink;
  }

  cancel_select_documents($pd4, $globalLink_arr);
  update_taxonomy_row_document($globalLink_arr);
}

function update_taxonomy_row_document(&$globalLink_arr) {
  foreach ($globalLink_arr as $globalLink) {
    if ($globalLink->cancelled) {
      db_update('transperfect_core_taxonomy')
              ->fields(array('status' => TPT_STATUS_PENDING_TRANSLATIONS, 'timestamp' => REQUEST_TIME))
              ->condition('rid', $globalLink->tptRowId, '=')
              ->execute();
    }
  }
}

function cancel_taxonomy_submission($selected_submission) {
  $pd4 = get_project_director_details();
  $globalLink = new GlobalLink();
  $submission_ticket = get_taxonomy_submission_ticket($selected_submission);
  $globalLink->submissionName = $selected_submission;
  $globalLink->submissionTicket = $submission_ticket;

  cancel_ProjectDirector_submission($pd4, $globalLink);
  update_transperfect_taxonomy_submission($globalLink);
}

function get_taxonomy_submission_ticket($submission_name) {
  $query = db_select('transperfect_core_taxonomy', 'tc');
  $query->fields('tc');
  $query->condition('submission', $submission_name, '=');
  $results = $query->execute();
  foreach ($results as $row) {
    if ($row->submission_ticket != '') {
      return $row->submission_ticket;
    }
  }
}

function update_transperfect_taxonomy_submission(&$globalLink) {
  db_update('transperfect_core_taxonomy')
          ->fields(array('status' => TPT_STATUS_PENDING_TRANSLATIONS, 'timestamp' => REQUEST_TIME))
          ->condition('submission_ticket', $globalLink->submissionTicket, '=')
          ->condition('submission', $globalLink->submissionName, '=')
          ->execute();
}

function get_translated_taxonomies($pd4, &$globalLink_arr) {
  $count = 0;
  $source_link = array('link_title' => 'No Title');
  $strings = transperfect_get_taxonomy_strings(NULL, 'taxonomy');
  foreach ($globalLink_arr as $globalLink) {
    if (!$globalLink->sourceDeleted) {
      $targetXML = downloadTargetResource($pd4, $globalLink->targetTicket);
      if (isset($targetXML)) {
        $count++;
        $language = get_drupal_locale_code($globalLink->targetLocale);
        $translated_arr = get_translated_taxonomy_items($targetXML);
        try {
          $bid = $translated_arr['bid'];
          foreach ($translated_arr as $attribute => $translations) {
            if ($attribute == 'bid') {
              continue;
            }
            $source = '';
            if ($attribute == 'name') {
              $title_string_arr = isset($strings["taxonomy:term:$bid:name"]) ? $strings["taxonomy:term:$bid:name"] : FALSE;
              if (!$title_string_arr) {
                throw new Exception("Source string not found for taxonomy id $bid and field name $attribute");
              }
              $source = $title_string_arr['source'];
            }
            elseif ($attribute == 'description') {
              $description_string_arr = isset($strings["taxonomy:term:$bid:description"]) ? $strings["taxonomy:term:$bid:description"] : FALSE;
              if (!$description_string_arr) {
                //throw new Exception("Source string not found for taxonomy id $bid and field name $attribute");
                continue;
              }
              $source = $description_string_arr['source'];
            }
            $report = &drupal_static(__FUNCTION__, array('additions' => 0, 'updates' => 0, 'deletes' => 0, 'skips' => 0));
            _locale_import_one_string_db($report, $language, $translations['context'], $source, $translations['translation'], 'taxonomy', $translations['location'], LOCALE_IMPORT_OVERWRITE);
          }

          update_tpt_taxonomy_status($globalLink);
          sendDownloadConfirmation($globalLink->targetTicket, $pd4);
        }
        catch (SoapFault $se) {
          $count--;
          update_tpt_taxonomy_status($globalLink, TPT_STATUS_ERROR);
          gl_log(TPT_OBJECT_TYPE_TAXONOMY, TPT_LOGGING_SEVERITY_ERROR, "SOAP Exception in Sending Download Confirmation - update_deleted_taxonomy_records - Code[$se->faultcode], Message[$se->faultstring]");
          form_set_error('', check_plain('Web Services Error: ' . $se->faultcode . ' - ' . $se->faultstring));
        }
        catch (Exception $e) {
          $count--;
          update_tpt_taxonomy_status($globalLink, TPT_STATUS_ERROR);
          gl_log(TPT_OBJECT_TYPE_TAXONOMY, TPT_LOGGING_SEVERITY_ERROR, "Exception in Saving taxonomy Objects - File[$e->getFile()], Line[$e->getLine()], Code[$e->getCode], Message[$e->getMessage]");
          form_set_error('', check_plain('Error: ' . $e->getMessage()));
        }
      }
    }
  }
  return $count;
}

function get_translated_taxonomy_items($xml) {
  if (is_null($xml) || !is_string($xml) || $xml == '') {
    return array();
  }

  $dom = new DomDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);

  $contents = $dom->getElementsByTagName('content');

  $bid = '';
  foreach ($contents as $content) {
    if (!is_null($content->attributes)) {
      foreach ($content->attributes as $attrName => $attrNode) {
        if ('bid' == $attrName) {
          $bid = $attrNode->value;
        }
      }
    }
  }

  if ($bid == '') {
    return array();
  }

  $taxonomy_arr = array();
  $taxonomy_arr['bid'] = $bid;

  $taxonomies = $dom->getElementsByTagName('taxonomy');
  foreach ($taxonomies as $taxonomy) {
    if (!is_null($taxonomy->attributes)) {
      $b_arr = array();
      foreach ($taxonomy->attributes as $attrName => $attrNode) {
        $b_arr[$attrName] = $attrNode->value;
      }
      $b_arr['translation'] = $taxonomy->nodeValue;
      $taxonomy_arr[$b_arr['name']] = $b_arr;
    }
  }

  return $taxonomy_arr;
}

function update_tpt_taxonomy_status(&$globalLink, $status = TPT_STATUS_PENDING_TRANSLATIONS) {
  db_update('transperfect_core_taxonomy')
          ->fields(array('status' => $status, 'timestamp' => REQUEST_TIME))
          ->condition('submission', $globalLink->submissionName, '=')
          ->condition('document_ticket', $globalLink->documentTicket, '=')
          ->condition('source', $globalLink->sourceLocale, '=')
          ->condition('target', $globalLink->targetLocale, '=')
          ->execute();
}

function get_active_taxonomy_submission_rows($object_id) {
  $query = db_select('transperfect_core_taxonomy', 'tc');
  $query->condition('status', TPT_STATUS_SENT_FOR_TRANSLATIONS, '=');
  $query->condition('object_id', $object_id, '=');
  $query->fields('tc');
  $results = $query->execute();
  $arr = array();
  foreach ($results as $row) {
    if (array_key_exists($row->object_id, $arr)) {
      array_push($arr[$row->object_id], $row);
    }
    else {
      $arr[$row->object_id] = array($row);
    }
  }
  $final_arr = array();
  foreach ($arr as $bid => $bid_arr) {
    $sub_arr = array();
    foreach ($bid_arr as $r) {
      if (array_key_exists($r->submission, $sub_arr)) {
        array_push($sub_arr[$r->submission], $r->target);
      }
      else {
        $sub_arr[$r->submission] = array($r->target);
      }
    }
    if (count($sub_arr) > 0) {
      $final_arr[$bid] = $sub_arr;
    }
  }
  if (count($final_arr) > 0) {
    return $final_arr;
  }
  return FALSE;
}

function get_sent_tpt_taxonomy_rows_by_bid($bid) {
  $result = db_select('transperfect_core_taxonomy', 'tc')
          ->fields('tc')
          ->condition('object_id', $bid, '=')
          ->condition('status', TPT_STATUS_SENT_FOR_TRANSLATIONS, '=')
          ->execute();
  $rows = array();
  foreach ($result as $row) {
    $rows[] = $row;
  }
  return $rows;
}

function get_tpt_taxonomy_row_id_from_submission($submission_ticket, $document_ticket, $target_locale) {
  $result = db_select('transperfect_core_taxonomy', 'tc')
          ->condition('submission_ticket', $submission_ticket, '=')
          ->condition('document_ticket', $document_ticket, '=')
          ->condition('target', $target_locale, '=')
          ->fields('tc')
          ->execute();
  foreach ($result as $row) {
    return $row->rid;
  }
}

function load_taxonomy_data($tid) {
  $query = db_select('taxonomy_term_data', 'td')
          ->fields('td')
          ->condition('tid', $tid, '=');

  $results = $query->execute();

  $rows = array();
  foreach ($results as $item) {
    $rows[] = $item;
  }

  return $rows;
}

function get_arr_taxonomy_items($xml) {
  if (is_null($xml) || !is_string($xml) || $xml == '') {
    return array();
  }

  $dom = new DomDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);
  $contents = $dom->getElementsByTagName('content');
  $bid = '';
  foreach ($contents as $content) {
    if (!is_null($content->attributes)) {
      foreach ($content->attributes as $attrName => $attrNode) {
        if ('bid' == $attrName) {
          $bid = $attrNode->value;
        }
      }
    }
  }

  if ($bid == '') {
    return array();
  }

  $block_arr = array();
  $block_arr['bid'] = $bid;
  $blocks = $dom->getElementsByTagName('taxonomy');
  foreach ($blocks as $block) {
    if (!is_null($block->attributes)) {
      $b_arr = array();
      foreach ($block->attributes as $attrName => $attrNode) {
        $b_arr[$attrName] = $attrNode->value;
      }
      $block_arr[$b_arr['name']] = $block->nodeValue;
    }
  }

  return $block_arr;
}

function get_vocabulary_list() {
  $v_arr = array('[any]' => 'Any');
  $arr = array();
  $vocabs = taxonomy_vocabulary_load_multiple(FALSE);
  foreach ($vocabs as $vocab) {
    if ($vocab->i18n_mode == 1) {
      $arr[$vocab->vid] = $vocab->name;
    }
  }
  asort($arr);
  return $v_arr + $arr;
}

function get_distinct_active_taxonomy_submission_names() {
  $query = db_select('transperfect_core_taxonomy', 'tc');
  $query->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN');
  $query->distinct();
  $query->fields('tc');
  $results = $query->execute();
  $arr = array('[any]' => t(' Any '));
  foreach ($results as $row) {
    $arr[$row->submission] = $row->submission;
  }
  return $arr;
}

function update_taxonomy_submission_status($submission_ticket, $status = TPT_STATUS_CANCELLED) {
  db_update('transperfect_core_taxonomy')
          ->fields(array(
              'status' => $status,
              'timestamp' => REQUEST_TIME
                  )
          )
          ->condition('submission_ticket', $submission_ticket, '=')
          ->execute();
}

function get_taxonomy_submission_status() {
  $query = db_select('transperfect_core_taxonomy', 'tc');
  $query->fields('tc', array('submission_ticket'));
  $query->distinct();
  $query->condition('status', TPT_STATUS_SENT_FOR_TRANSLATIONS, '=');
  $results = $query->execute();
  foreach ($results as $row) {
    if ($row->submission_ticket) {
      try {
        $pd4 = get_project_director_details();
        $doc_status = get_status($pd4, $row->submission_ticket);
        if (!$doc_status || $doc_status == PD_STATUS_CANCELLED) {
          update_taxonomy_submission_status($row->submission_ticket);
        }
      }
      catch (SoapFault $se) {
        update_taxonomy_submission_status($row->submission_ticket);
      }
      catch (Exception $ex) {
        update_taxonomy_submission_status($row->submission_ticket);
      }
    }
  }
}

function check_tpt_taxonomy_status($rids_arr) {
  $status = TRUE;
  $query = db_select('transperfect_core_taxonomy', 'tc')
          ->fields('tc', array('rid'))
          ->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN');
  $results = $query->execute();
  $rows = array();
  foreach ($results as $item) {
    $rows[$item->rid] = $item->rid;
  }

  foreach ($rids_arr as $val) {
    if (!in_array($val, $rows)) {
      unset($rids_arr[$val]);
      $status = FALSE;
    }
  }

  if (!$status) {
    drupal_set_message(t('Cannot cancel documents that have been cancelled in Globallink.'), 'warning', NULL);
  }

  return $rids_arr;
}

function clear_cancelled_taxonomy_documents() {
  $count = 0;
  $query = db_select('transperfect_core_taxonomy', 'tc')
          ->fields('tc', array('submission_ticket'))
          ->distinct()
          ->condition('status', TPT_STATUS_CANCELLED, '=');
  $results = $query->execute();
  foreach ($results as $item) {
    update_taxonomy_submission_status($item->submission_ticket, TPT_STATUS_PENDING_TRANSLATIONS);
    $count++;
  }

  return $count;
}