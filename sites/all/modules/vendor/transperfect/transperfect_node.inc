<?php

require_once TPT_ROOT . '/' . ('transperfect_settings.inc');
require_once TPT_ROOT . '/' . ('transperfect_common.inc');
require_once TPT_ROOT . '/' . ('gl_ws/gl_ws_common.inc');

function build_filters() {

  $filters = array();

  $filters['modified'] = array(
      'title' => 'Show',
      'field' => 'changed',
      'form-type' => 'radios',
      'options' => array('&nbsp;&nbsp;' . t('Modified Content') . '&nbsp;&nbsp;&nbsp;&nbsp;',
          '&nbsp;&nbsp;' . t('Everything') . '&nbsp;&nbsp;'),
  );

  $revisioning_module_exists = module_exists("revisioning");
  if ($revisioning_module_exists) {
    $filters['status'] = array(
        'title' => TPT_LABEL_STATUS,
        'options' => array(
            'status-1' => t('Latest Published Revision'),
            'status-0' => t('Latest Modified Revision'),
            'promote-1' => t('Promoted'),
            'promote-0' => t('Not Promoted'),
            'sticky-1' => t('Sticky'),
            'sticky-0' => t('Not Sticky'),
        ),
        'form-type' => 'select',
    );
  }
  else {
    $filters['status'] = array(
        'title' => TPT_LABEL_STATUS,
        'options' => array(
            '[any]' => t('Any'),
            'status-1' => t('Published'),
            'status-0' => t('Not Published'),
            'promote-1' => t('Promoted'),
            'promote-0' => t('Not Promoted'),
            'sticky-1' => t('Sticky'),
            'sticky-0' => t('Not Sticky'),
        ),
        'form-type' => 'select',
    );
  }

  $languages = get_mapped_drupal_locales(FALSE);
  foreach ($languages as $key => $lang) {
    $lang_filter[$key] = $lang;
  }

  $filters['language_name'] = array(
      'title' => TPT_LABEL_SOURCE_LANG,
      'field' => 'language',
      'options' => $lang_filter,
      'form-type' => 'select',
  );

  $filters['node_parent'] = array(
      'title' => t('Parent Node'),
      'field' => 'node_parent',
      'form-type' => 'checkbox',
  );

  $filters['target_language'] = array(
      'title' => TPT_LABEL_TARGET_LANG,
      'field' => 'language',
      'options' => $lang_filter,
      'form-type' => 'select',
  );

  $n_arr = array('[any]' => t('Any'));
  $t_arr = get_translatable_node_types_and_names();
  $node_types_filter = $n_arr + $t_arr;
  $filters['type'] = array(

      'title' => t('Type'), // TPT_LABEL_CONTENT_TYPE,
      'field' => 'type',
      'options' => $node_types_filter,
      'form-type' => 'select',
  );
  

  $my_field = field_info_field('field_solution_type');
  $allowed_values = list_allowed_values($my_field);
  $content_types_filter = $n_arr + $allowed_values;
  
  $filters['content_type'] = array(
      'title' => t('Content type'),
      'field' => 'field_solution_type_value',
      'options' => $content_types_filter,
      'form-type' => 'select',
  );

 
  $filters['title'] = array(
      'title' => 'Title',
      'field' => 'title',
      'form-type' => 'textfield',
  );

  $filters['modified-after'] = array(
      'title' => 'Modified After',
      'field' => 'changed',
      'form-type' => 'textfield',
  );

  return $filters;
}

function transpefect_build_filter_query(SelectQuery $query) {
  $revisioning_module_exists = module_exists("revisioning");
  $filters = build_filters();
  $count = 0;
  foreach (isset($_SESSION['transperfect_dashboard_filter']) ? $_SESSION['transperfect_dashboard_filter'] : array() as $filter) {
    list($key, $value) = $filter;
	
	if ($key == 'content_type') {
	 $query->join('field_data_field_solution_type', 'st', 'n.nid = st.entity_id');
	 $query->condition('st.field_solution_type_value', $value, '=');
	}
    elseif ($key == 'modified-after') {
      $query->condition($filters[$key]['field'], $value, '>=');
    }
    elseif ($key != 'modified' && $key != 'title' && $key != 'target_language' && $key != 'status' && $key != 'node_parent') {
      $query->condition('n.'.$filters[$key]['field'], $value);
    }
    elseif ($key == 'title') {
      $query->condition($filters[$key]['field'], '%' . $value . '%', 'LIKE');
    }
    elseif ($key == 'status' && !$revisioning_module_exists) {
      list($key, $value) = explode('-', $value, 2);
      $query->condition($key, $value, '=');
    }
    elseif ($key == 'node_parent') {
      if ($value == 1) {
        $query->where('tnid = nid OR tnid = 0');
      }
    }
    $count++;
  }
}

function send_for_translations($nids, $pd4, $submission_name, $due_date, $project_code, $source_locale, $target_locale_arr, $submission_details) {
  $node_check = variable_get('transperfect_implementation_type', 0);
  $submitter = $submission_details['submitter'];
  $globalLink_arr = array();
  foreach ($nids as $nid) {
    list($nid, $vid) = explode('-', $nid, 2);
    $rows = get_sent_tpt_rows_by_nid($nid);
    $target_arr = $target_locale_arr;
    foreach ($rows as $row) {
      if (array_search($row->target, $target_locale_arr)) {
        unset($target_arr[$row->target]);
      }
    }

    if (empty($target_arr)) {
      gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_WARNING, "Skipping nid - [" . $nid . "]");
      continue;
    }

    $node = node_load($nid, $vid);

    if ($node_check == 1) {
      foreach ($target_arr as $key => $target_locale) {
        if (!tpt_translate_node_for_language($node, get_drupal_locale_code($target_locale))) {
          unset($target_arr[$key]);
        }
      }
    }

    if (empty($target_arr)) {
      gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_WARNING, "Skipping nid - [" . $nid . "]");
      continue;
    }

    $drupal_target_arr = array();
    foreach ($target_arr as $target_locale) {
      array_push($drupal_target_arr, get_drupal_locale_code($target_locale));
    }

    $tnid = NULL;
    $tvid = NULL;

    $name = '.xml';
    $xml = get_xml($node, $drupal_target_arr, $tnid, $tvid, $name);
    if (!$xml) {
      gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_WARNING, "Cannot create XML. Skipping nid - [" . $nid . "]");
      continue;
    }

    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_DEBUG, $xml);

    $globalLink = new GlobalLink();
    $globalLink->nid = $node->nid;
    $globalLink->vid = $node->vid;
    $globalLink->title = $node->title;
    $globalLink->type = $node->type;
    $globalLink->metadata = 'Node';
    $globalLink->sourceLocale = $source_locale;
    $globalLink->targetLocale = $target_arr;
    $globalLink->sourceXML = $xml;
    $globalLink->sourceFileName = $name;
    $globalLink->submissionName = $submission_name;
    $globalLink->dueDate = $due_date;
    $globalLink->submissionInstructions = $submission_details['instructions'] . "\nSubmitter: " . $submitter;
    $globalLink_arr[] = $globalLink;
  }

  if (!empty($globalLink_arr)) {
    sendDocumentsForTranslationToPD($globalLink_arr, $pd4, $project_code, $submitter);
  }
  return $globalLink_arr;
}

function update_node_ticket_id($arr, $project_code) {
  foreach ($arr as $globalLink) {
    $nid = $globalLink->nid;
    $node = node_load($nid);
    $target_locale_arr = $globalLink->targetLocale;
    foreach ($target_locale_arr as $target_locale) {
      $row = get_transperfect_row_by_nid_and_locale($nid, $globalLink->sourceLocale, $target_locale);
      if ($row) {
        db_update('transperfect_core')
                ->fields(array('vid' => $globalLink->vid, 'title' => $globalLink->title, 'document_ticket' => $globalLink->documentTicket,
                    'submission' => $globalLink->submissionName, 'submission_ticket' => $globalLink->submissionTicket,
                    'status' => TPT_STATUS_SENT_FOR_TRANSLATIONS, 'timestamp' => REQUEST_TIME, 'last_modified' => $node->changed, 'changed' => 0, 'project_code' => $project_code))
                ->condition('rid', $row->rid, '=')
                ->execute();
      }
      else {
        db_insert('transperfect_core')
                ->fields(array('nid' => $globalLink->nid, 'vid' => $globalLink->vid, 'type' => $globalLink->type, 'title' => $globalLink->title,
                    'source' => $globalLink->sourceLocale, 'target' => $target_locale, 'document_ticket' => $globalLink->documentTicket,
                    'submission' => $globalLink->submissionName, 'submission_ticket' => $globalLink->submissionTicket,
                    'status' => TPT_STATUS_SENT_FOR_TRANSLATIONS, 'timestamp' => REQUEST_TIME, 'last_modified' => $node->changed, 'changed' => 0, 'project_code' => $project_code))
                ->execute();
      }
    }
  }
}

function update_node_change_flag($nids, $source, $tgts) {

  gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_INFO, "CHANGED Status Cleared for Node Ids - [" . implode(",", $nids) . "]");

  $insert_arr = array();
  $tgt_arr = array_keys($tgts);
  foreach ($tgt_arr as $tgt) {
    foreach ($nids as $nid) {
      $insert_arr[$tgt][$nid] = TRUE;
    }
  }
  foreach ($tgt_arr as $tgt) {
    foreach ($nids as $nid) {
      $result = db_select('transperfect_core', 'tc')
              ->fields('tc')
              ->condition('nid', $nid, '=')
              ->condition('target', $tgt, '=')
              ->execute();
      foreach ($result as $item) {
        db_update('transperfect_core')
                ->fields(array('timestamp' => REQUEST_TIME, 'changed' => 2))
                ->condition('rid', $item->rid, '=')
                ->execute();
        $insert_arr[$tgt][$nid] = FALSE;
      }
    }
  }

  foreach ($tgt_arr as $tgt) {
    foreach ($nids as $nid) {
      if (isset($insert_arr[$tgt]) && isset($insert_arr[$tgt][$nid])) {
        if ($insert_arr[$tgt][$nid]) {
          $node = node_load($nid);
          db_insert('transperfect_core')
                  ->fields(array('nid' => $nid, 'vid' => $node->vid, 'type' => $node->type, 'title' => $node->title,
                      'source' => $source, 'target' => $tgt, 'document_ticket' => '',
                      'submission' => '', 'submission_ticket' => '',
                      'status' => TPT_STATUS_PENDING_TRANSLATIONS, 'timestamp' => REQUEST_TIME, 'last_modified' => $node->changed, 'changed' => 2))
                  ->execute();
        }
      }
    }
  }
}

function cancel_select_records($rowids, $pd4) {
  $globalLink_arr = array();
  foreach ($rowids as $rid) {
    $row = get_transperfect_row($rid);
    $globalLink = new GlobalLink();
    $globalLink->tptRowId = $row->rid;
    $globalLink->documentTicket = $row->document_ticket;
    $globalLink->submissionTicket = $row->submission_ticket;
    $globalLink_arr[$rid] = $globalLink;
  }

  cancel_select_documents($pd4, $globalLink_arr);
  update_transperfect_row_document($globalLink_arr);
}

function cancel_submission($selected_submission) {
  $pd4 = get_project_director_details();
  $globalLink = new GlobalLink();
  $submission_ticket = get_submission_ticket($selected_submission);
  $globalLink->submissionName = $selected_submission;
  $globalLink->submissionTicket = $submission_ticket;

  cancel_ProjectDirector_submission($pd4, $globalLink);
  update_transperfect_row_submission($globalLink);
}

function get_submission_ticket($submission_name) {
  $query = db_select('transperfect_core', 'tc');
  $query->fields('tc');
  $query->condition('submission', $submission_name, '=');
  $results = $query->execute();
  foreach ($results as $row) {
    if ($row->submission_ticket != '') {
      return $row->submission_ticket;
    }
  }
}

function update_transperfect_row_document(&$globalLink_arr) {
  foreach ($globalLink_arr as $globalLink) {
    if ($globalLink->cancelled) {
      db_update('transperfect_core')
              ->fields(array('status' => TPT_STATUS_PENDING_TRANSLATIONS, 'timestamp' => REQUEST_TIME, 'changed' => 1))
              ->condition('rid', $globalLink->tptRowId, '=')
              ->execute();
    }
  }
}

function update_transperfect_row_submission(&$globalLink) {
  db_update('transperfect_core')
          ->fields(array('status' => TPT_STATUS_PENDING_TRANSLATIONS, 'timestamp' => REQUEST_TIME, 'changed' => 1))
          ->condition('submission_ticket', $globalLink->submissionTicket, '=')
          ->condition('submission', $globalLink->submissionName, '=')
          ->execute();
}

function get_distinct_active_submission_names() {
  $query = db_select('transperfect_core', 'tc');
  $query->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN');
  $query->distinct();
  $query->fields('tc');
  $results = $query->execute();
  $arr = array('' => '-- Select a Submission --');
  foreach ($results as $row) {
    $arr[$row->submission] = $row->submission;
  }
  return $arr;
}

function get_submission_from_nid($nid) {
  $query = db_select('transperfect_core', 'tc');
  $query->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN');
  $query->condition('nid', $nid, '=');
  $query->distinct();
  $query->fields('tc');
  $results = $query->execute();
  foreach ($results as $row) {
    //Return the first one
    return $row->submission;
  }
}

function get_tpt_row_id_from_submission($submission_ticket, $document_ticket, $target_locale) {
  $query = db_select('transperfect_core', 'tc');
  $query->condition('submission_ticket', $submission_ticket, '=');
  $query->condition('document_ticket', $document_ticket, '=');
  $query->condition('target', $target_locale, '=');
  $query->fields('tc');
  $results = $query->execute();
  foreach ($results as $row) {
    //Return the first one
    return $row->rid;
  }
}

function update_deleted_records($pd4, $globalLink) {
  try {
    $globalLink->status = TPT_STATUS_SOURCE_DELETED;
    sendDownloadConfirmation($globalLink->targetTicket, $pd4);
    update_tpt_status($globalLink);
  }
  catch (SoapFault $se) {
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "SOAP Exception in Sending Download Confirmation - update_deleted_records - Code[$se->faultcode], Message[$se->faultstring]");
    form_set_error('', check_plain('Web Services Error: ' . $se->faultcode . ' - ' . $se->faultstring));
  }
  catch (Exception $e) {
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "Exception in update_deleted_records - File[$e->getFile()], Line[$e->getLine()], Code[$e->getCode], Message[$e->getMessage]");
    form_set_error('', check_plain('Error: ' . $e->getMessage()));
  }

  return TRUE;
}

function get_translated_content($pd4, &$globalLink_arr) {
  try {
    $count = 0;
    foreach ($globalLink_arr as $globalLink) {
      if (!$globalLink->sourceDeleted) {
        $globalLink->targetXML = downloadTargetResource($pd4, $globalLink->targetTicket);
        if (isset($globalLink->targetXML)) {
          $count++;
          update_node($globalLink);
          if ($globalLink->status != TPT_STATUS_ERROR) {
            sendDownloadConfirmation($globalLink->targetTicket, $pd4);
            update_tpt_status($globalLink);
          }
          else {
            $count--;
          }
        }
      }
    }
  }
  catch (SoapFault $se) {
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "SOAP Exception in Sending Download Confirmation - get_translated_content - Code[$se->faultcode], Message[$se->faultstring]");
    form_set_error('', check_plain('Web Services Error: ' . $se->faultcode . ' - ' . $se->faultstring));
  }
  catch (Exception $e) {
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "Exception in get_translated_content - File[$e->getFile()], Line[$e->getLine()], Code[$e->getCode], Message[$e->getMessage]");
    form_set_error('', check_plain('Error: ' . $e->getMessage()));
  }

  return $count;
}

function update_tpt_status(&$globalLink) {
  if ($globalLink->status != TPT_STATUS_SOURCE_DELETED && $globalLink->status != TPT_STATUS_ERROR) {
    $row = get_transperfect_row_by_nid_and_locale($globalLink->nid, $globalLink->sourceLocale, $globalLink->targetLocale);
    $node = node_load($row->nid);
    if ($node->vid != $row->vid) {
      db_update('transperfect_core')
              ->fields(array(
                  'vid' => $node->vid,
                  'title' => $node->title,
                  'status' => TPT_STATUS_PENDING_TRANSLATIONS,
                  'timestamp' => REQUEST_TIME
                      )
              )
              ->condition('rid', $row->rid, '=')
              ->execute();
    }
    else {
      db_update('transperfect_core')
              ->fields(array('status' => TPT_STATUS_PENDING_TRANSLATIONS, 'timestamp' => REQUEST_TIME))
              ->condition('rid', $row->rid, '=')
              ->execute();
    }
  }
  elseif ($globalLink->status == TPT_STATUS_SOURCE_DELETED) {
    $row = get_transperfect_row_by_nid_and_locale($globalLink->nid, $globalLink->sourceLocale, $globalLink->targetLocale);
    db_update('transperfect_core')
            ->fields(array(
                'status' => TPT_STATUS_SOURCE_DELETED,
                'document_ticket' => '',
                'submission_ticket' => '',
                'timestamp' => REQUEST_TIME,
                    )
            )
            ->condition('rid', $row->rid, '=')
            ->execute();
  }
  elseif ($globalLink->status == TPT_STATUS_ERROR) {
    $row = get_transperfect_row_by_nid_and_locale($globalLink->nid, $globalLink->sourceLocale, $globalLink->targetLocale);
    db_update('transperfect_core')
            ->fields(array(
                'status' => TPT_STATUS_ERROR,
                'timestamp' => REQUEST_TIME,
                    )
            )
            ->condition('rid', $row->rid, '=')
            ->execute();
  }
}

function get_nid(&$globalLink) {
  $translated_arr = get_content_attributes_from_xml($globalLink->targetXML);
  if (count($translated_arr) > 0) {
    $globalLink->nid = isset($translated_arr['nid']) ? $translated_arr['nid'] : 0;
    $globalLink->tptRowId = isset($translated_arr['rid']) ? $translated_arr['rid'] : 0;
    return TRUE;
  }
  return FALSE;
}

function update_node(&$globalLink, $t_arr = NULL) {
  $success = FALSE;
  try {
    $default_language = language_default();
    $default_language_code = $default_language->language;
    $publish_node = variable_get('transperfect_publish_node', 0);
    $field_collection_module_exists = module_exists("field_collection");
    $metatag_module_exists = module_exists("metatag");
    $exclude_title_module_exists = module_exists('exclude_node_title');
    $revisioning_module_exists = module_exists("revisioning");

    if ($t_arr != NULL) {
      $translated_arr = $t_arr;
    }
    else {
      $translated_arr = get_translated_array($globalLink->targetXML);
    }

    $target_nid = $translated_arr['nid'];
    $target_vid = $translated_arr['vid'];
    $target_title = '';
    if (isset($translated_arr['title'])) {
      $target_title = $translated_arr['title'];
    }

    $globalLink->nid = $target_nid;
    $globalLink->vid = $target_vid;


    $node = node_load($target_nid, $target_vid);
    if (!$node || is_null($node) || !is_object($node)) {
      $globalLink->status = TPT_STATUS_SOURCE_DELETED;
      return;
    }

    //check if already a translation set is present
    $tnid = $node->nid;
    if (!empty($node->tnid) && $node->nid != $node->tnid) {
      $tnid = $node->tnid;
    }
    $node_arr = translation_node_get_translations($tnid);
    $updateFlag = FALSE;
    if (sizeof($node_arr) > 0) {
      foreach ($node_arr as $_tnode) {
        if ($_tnode->language == get_drupal_locale_code($globalLink->targetLocale)) {
          $updateFlag = TRUE;
          break;
        }
      }
    }

    if ($updateFlag) {
      foreach ($node_arr as $_tnode) {
        if ($node->nid == $_tnode->nid) {
          continue;
        }
        if ($_tnode->language != get_drupal_locale_code($globalLink->targetLocale)) {
          continue;
        }

        //Create a node and save
        $new_node = unserialize(serialize($node));
        unset($new_node->nid);
        unset($new_node->vid);

        $new_node->nid = $_tnode->nid;
        $new_node->vid = 0;
        $new_node->tnid = $node->tnid;
        $new_node->language = $_tnode->language;
        $new_node->revision = 1;

        module_load_include('inc', 'node', 'node.pages');
        //Fix for menu link issue
        //  node_object_prepare($new_node);

        $nodepath = drupal_lookup_path('alias', "node/" . $node->nid);
        //Get the path object of the tnode, so that we can get the pid
        $path = path_load("node/" . $_tnode->nid);
        if ($nodepath === FALSE) {
          //Just leave empty for now
        }
        else {
          if ($path) {
            //update the path object with source node alias, but with tnode pid
            $new_node->path = array('pid' => $path['pid'], 'alias' => $nodepath, 'pathauto' => FALSE);
          }
          else {
            //update the path object with the alias
            $new_node->path = array('alias' => $nodepath, 'pathauto' => FALSE);
          }
        }

        if ($publish_node == 0) {
          $new_node->status = 0;
        }
        elseif ($publish_node == 1) {
          $new_node->status = 1;
        }
        else {
          $new_node->status = $node->status;
        }

        if ($revisioning_module_exists) {
          $new_node->is_pending = FALSE;
          $new_node->revision_moderation = FALSE;
        }

        //update it with translated content
        if ($target_title != '') {
          $new_node->title = $target_title;
        }

        $new_node->tpt_skip = TRUE;

        if ($metatag_module_exists) {
          if (isset($translated_arr['metatag'])) {
            $target_metatag_arr = $translated_arr['metatag'];
            $metatags_names = array_keys($node->metatags);
            $n_metatag = &$new_node->metatags;
            foreach ($metatags_names as $name) {
              if (isset($target_metatag_arr[$name]) && isset($target_metatag_arr[$name][0])) {
                $glObj = $target_metatag_arr[$name]['0'];
                if (is_object($glObj)) {
                  $translated_content = $glObj->translatedContent;
                }
                else {
                  $translated_content = $glObj;
                }
                $n_metatag[$name] = array('value' => $translated_content);
              }
            }
          }
        }

        if ($field_collection_module_exists && isset($translated_arr['field_collection'])) {
          //Unset the field collection as it will be created later
          $t_fc_arr = $translated_arr['field_collection'];
          $fcs = array_keys($t_fc_arr);
          foreach ($fcs as $fc) {
            if (isset($new_node->$fc)) {
              unset($new_node->$fc);
            }
          }
        }

        $success = save_translated_node_with_fields($node, $new_node, $translated_arr);

        // Exclude Title Module Support
        if ($success && $exclude_title_module_exists) {
          $exclude = _exclude_node_title($node->nid);
          $exclude_list = variable_get('exclude_node_title_nid_list', array());
          $is_excluded = array_search($new_node->nid, $exclude_list);
          if ($exclude && $is_excluded === FALSE) {
            $exclude_list[] = $new_node->nid;
            variable_set('exclude_node_title_nid_list', $exclude_list);
          }
          elseif ($exclude === FALSE && $is_excluded) {
            unset($exclude_list[$is_excluded]);
            variable_set('exclude_node_title_nid_list', $exclude_list);
          }
        }

        if ($success) {
          update_node_tnid($node->nid, $tnid);
          $globalLink->status = TPT_STATUS_PUBLISHED;
        }
        else {
          $globalLink->status = TPT_STATUS_ERROR;
        }
      }
    }
    else {
      //Create a node and save
      $new_node = unserialize(serialize($node));
      unset($new_node->nid);
      unset($new_node->vid);

      module_load_include('inc', 'node', 'node.pages');
      node_object_prepare($new_node);

      //IF translating from default to any other language e.g. en to fr
      if ($default_language_code == $node->language) {
        //Set the tnid from the source node
        $new_node->tnid = $node->nid;
      }
      else {
        // Translating from non default to non default
        // Set the tnid from the default node
        $new_node->tnid = $tnid;
      }

      $nodepath = drupal_lookup_path('alias', "node/" . $node->nid);

      if ($nodepath === FALSE) {
        //Just leave empty for now
      }
      else {
        $new_node->path = array('alias' => $nodepath, 'pathauto' => FALSE);
      }

      if ($publish_node == 0) {
        $new_node->status = 0;
      }
      elseif ($publish_node == 1) {
        $new_node->status = 1;
      }
      else {
        $new_node->status = $node->status;
      }

      if ($revisioning_module_exists) {
        $new_node->is_pending = FALSE;
        $new_node->revision_moderation = FALSE;
      }

      $lang = get_drupal_locale_code($globalLink->targetLocale);
      if ($lang == '') {
        throw new Exception("Locale Mapping not found.");
      }
      $new_node->language = $lang;

      //update it with translated content
      if ($target_title != '') {
        $new_node->title = $target_title;
      }
      $new_node->tpt_skip = TRUE;

      if ($metatag_module_exists) {
        if (isset($translated_arr['metatag'])) {
          $target_metatag_arr = $translated_arr['metatag'];
          $metatags_names = array_keys($node->metatags);
          $n_metatag = &$new_node->metatags;
          foreach ($metatags_names as $name) {
            if (isset($target_metatag_arr[$name]) && isset($target_metatag_arr[$name][0])) {
              $glObj = $target_metatag_arr[$name]['0'];
              if (is_object($glObj)) {
                $translated_content = $glObj->translatedContent;
              }
              else {
                $translated_content = $glObj;
              }
              $n_metatag[$name] = array('value' => $translated_content);
            }
          }
        }
      }

      if ($field_collection_module_exists && isset($translated_arr['field_collection'])) {
        //Unset the field collection as it will be created later
        $t_fc_arr = $translated_arr['field_collection'];
        $fcs = array_keys($t_fc_arr);
        foreach ($fcs as $fc) {
          if (isset($new_node->$fc)) {
            unset($new_node->$fc);
          }
        }
      }

      $success = save_translated_node_with_fields($node, $new_node, $translated_arr);
      // Exclude Title Module Support
      if ($success && $exclude_title_module_exists) {
        $exclude = _exclude_node_title($node->nid);
        if ($exclude) {
          $exclude_list = variable_get('exclude_node_title_nid_list', array());
          $exclude_list[] = $new_node->nid;
          variable_set('exclude_node_title_nid_list', $exclude_list);
        }
      }

      if ($success) {
        if ($nodepath) {
          if (module_exists('pathauto')) {
            $node->path['pathauto'] = FALSE;
          }
        }

        update_node_tnid($node->nid, $tnid);
        $globalLink->status = TPT_STATUS_PUBLISHED;
      }
      else {
        $globalLink->status = TPT_STATUS_ERROR;
      }
    }
  }
  catch (Exception $e) {
    $globalLink->status = TPT_STATUS_ERROR;
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "Exception in Receive Translations - Update Node - File[$e->getFile()], Line[$e->getLine()], Code[$e->getCode], Message[$e->getMessage]");
  }
}

function update_node_tnid($nid, $tnid) {
  db_update('node')->fields(array('tnid' => $tnid))->condition('nid', $nid, '=')->execute();
}

function get_translated_array($xml) {
  if (is_null($xml) || !is_string($xml) || $xml == '') {
    return array();
  }

  $dom = new DomDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);

  $arr = array();

  $contents = $dom->getElementsByTagName('content');
  foreach ($contents as $content) {
    if (!is_null($content->attributes)) {
      foreach ($content->attributes as $attrName => $attrNode) {
        if ('rid' == $attrName) {
          $arr['rid'] = $attrNode->value;
        }
        if ('nid' == $attrName) {
          $arr['nid'] = $attrNode->value;
        }
        elseif ('vid' == $attrName) {
          $arr['vid'] = $attrNode->value;
        }
      }
    }
  }

  $titles = $dom->getElementsByTagName('title');
  foreach ($titles as $title) {
    $arr['title'] = $title->nodeValue;
  }

  $fields = $dom->getElementsByTagName('field');

  foreach ($fields as $field) {

    $fieldObject = new GLField();
    $fieldObject->type = 'field';
    $fieldObject->translatedContent = $field->nodeValue;

    if (!is_null($field->attributes)) {
      foreach ($field->attributes as $attrName => $attrNode) {
        switch ($attrName) {
          case 'entity_type':
            $fieldObject->entityType = $attrNode->value;
            continue 2;
          case 'content_type':
            $fieldObject->contentType = $attrNode->value;
            continue 2;
          case 'parent_fc':
            $fieldObject->parentFCName = $attrNode->value;
            continue 2;
          case 'bundle':
            $fieldObject->bundle = $attrNode->value;
            continue 2;
          case 'entity_id':
            $fieldObject->entityId = $attrNode->value;
            continue 2;
          case 'field_name':
            $fieldObject->fieldName = $attrNode->value;
            continue 2;
          case 'label':
            $fieldObject->fieldLabel = $attrNode->value;
            continue 2;
          case 'delta':
            $fieldObject->delta = $attrNode->value;
            continue 2;
          case 'format':
            $fieldObject->format = $attrNode->value;
            continue 2;
        }
      }
      if (is_null($fieldObject->entityId)) {
        $fieldObject->entityId = '0';
      }
      if (is_null($fieldObject->bundle)) {
        $fieldObject->bundle = $fieldObject->fieldName;
      }
      if (is_null($fieldObject->delta)) {
        $fieldObject->delta = '0';
      }
      if ($fieldObject->entityType == 'node') {
        $arr[$fieldObject->fieldName][LANGUAGE_NONE][$fieldObject->delta] = $fieldObject;
      }
      else {
        $arr['field_collection'][$fieldObject->parentFCName][$fieldObject->bundle][$fieldObject->entityId][$fieldObject->fieldName][LANGUAGE_NONE][$fieldObject->delta] = $fieldObject;
      }
    }
  }

  $metatags = $dom->getElementsByTagName('metatag');

  foreach ($metatags as $metatag) {

    $metatagObject = new GLField();
    $metatagObject->type = 'metatag';
    $metatagObject->translatedContent = $metatag->nodeValue;

    if (!is_null($metatag->attributes)) {
      foreach ($metatag->attributes as $attrName => $attrNode) {
        switch ($attrName) {
          case 'entity_type':
            $metatagObject->entityType = $attrNode->value;
            continue 2;
          case 'content_type':
            $fieldObject->contentType = $attrNode->value;
            continue 2;
          case 'bundle':
            $fieldObject->bundle = $attrNode->value;
            continue 2;
          case 'entity_id':
            $metatagObject->entityId = $attrNode->value;
            continue 2;
          case 'name':
            $metatagObject->fieldName = $attrNode->value;
            continue 2;
          case 'label':
            $metatagObject->fieldLabel = $attrNode->value;
            continue 2;
        }
      }
      if (is_null($metatagObject->entityId)) {
        $metatagObject->entityId = '0';
      }
      if (is_null($metatagObject->bundle)) {
        $metatagObject->bundle = $metatagObject->fieldName;
      }
      $arr['metatag'][$metatagObject->bundle][$metatagObject->entityId] = $metatagObject;
    }
  }
  return $arr;
}

function get_active_submission_by_nid($nid) {

  $query = db_select('transperfect_core', 'tc');
  $query->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN');
  $query->condition('nid', $nid, '=');
  $query->fields('tc');
  $results = $query->execute();
  $arr = array();
  foreach ($results as $row) {
    if (array_key_exists($row->submission, $arr)) {
      $t_arr = $arr[$row->submission];
      $t_arr[$row->target] = $row->vid;
      $arr[$row->submission] = $t_arr;
    }
    else {
      $_arr = array($row->target => $row->vid);
      $arr[$row->submission] = $_arr;
    }
  }
  return $arr;
}

function get_active_submission_rows_by_nid($nids) {
  $query = db_select('transperfect_core', 'tc');
  $query->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN');
  $query->condition('nid', $nids, 'IN');
  $query->fields('tc');
  $results = $query->execute();
  $arr = array();
  foreach ($results as $row) {
    if (array_key_exists($row->nid, $arr)) {
      array_push($arr[$row->nid], $row);
    }
    else {
      $arr[$row->nid] = array($row);
    }
  }
  $final_arr = array();
  foreach ($arr as $nid => $nid_arr) {
    $sub_arr = array();
    foreach ($nid_arr as $r) {
      if (array_key_exists($r->submission, $sub_arr)) {
        array_push($sub_arr[$r->submission], $r->target);
      }
      else {
        $sub_arr[$r->submission] = array($r->vid => $r->target);
      }
    }
    if (count($sub_arr) > 0) {
      $final_arr[$nid] = $sub_arr;
    }
  }
  if (count($final_arr) > 0) {
    return $final_arr;
  }
  return FALSE;
}

function transperfect_node_save(&$node) {
  try {
    node_save($node);
  }
  catch (Exception $e) {
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "Error in creating a translated node - File[$e->getFile()], Line[$e->getLine()], Code[$e->getCode], Message[$e->getMessage]");
    return FALSE;
  }

  return TRUE;
}

function save_translated_node_with_fields($node, &$tnode, $t_arr) {
  $field_arr = field_info_instances('node', $node->type);
  $keys = array_keys($field_arr);
  foreach ($keys as $field) {
    $items = field_get_items('node', $node, $field);
    if ($items) {
      $field_def = field_read_field($field);
      if ($field_def['type'] != 'list_boolean' && $field_def['type'] != 'image' && $field_def['type'] != 'file' && $field_def['type'] != 'taxonomy_term_reference' && $field_def['type'] != 'field_collection') {
        if (isset($t_arr[$field])) {
          $format = '';
          $arr = $tnode->$field;
          $t_field_arr = $t_arr[$field][LANGUAGE_NONE];
          if (isset($arr[LANGUAGE_NONE]) && is_array($arr[LANGUAGE_NONE])) {
            $updated = FALSE;
            foreach ($arr[LANGUAGE_NONE] as $delta => $n_field) {
              if (isset($t_field_arr[$delta])) {
                $f_arr = array();
                $glObj = $t_field_arr[$delta];
                if (is_object($glObj)) {
                  $translated_content = $glObj->translatedContent;
                }
                else {
                  $translated_content = $glObj;
                }
                if (isset($n_field['format'])) {
                  $format = $n_field['format'];
                }
                if ($format != '') {
                  $f_arr['format'] = $format;
                }
                if ($field_def['type'] == 'link_field') {
                  $n_field['title'] = $translated_content;
                  $arr[LANGUAGE_NONE][$delta] = $n_field;
                }
                else {
                  $f_arr['value'] = $translated_content;
                  $arr[LANGUAGE_NONE][$delta] = $f_arr;
                }
                $updated = TRUE;
              }
            }
            if ($updated) {
              $tnode->$field = $arr;
            }
          }
        }
      }
    }
  }

  $is_hook_enabled = variable_get('transperfect_implementation_type', 0);
  if ($is_hook_enabled == 1) {
    tpt_update_node($node, $tnode);
  }

  $success = transperfect_node_save($tnode);
  if ($success) {
    if (module_exists("field_collection") && isset($t_arr['field_collection'])) {
      save_field_collections($node, $tnode, $t_arr);
    }
  }

  return $success;
}

function save_field_collections($node, $tnode, $t_arr) {
  $field_arr = field_info_instances('node', $node->type);
  $keys = array_keys($field_arr);
  foreach ($keys as $field) {
    $items = field_get_items('node', $node, $field);
    if ($items) {
      $field_def = field_read_field($field);
      if ($field_def['type'] == 'field_collection') {
        if (isset($t_arr['field_collection'][$field])) {
          foreach ($items as $entity_id_arr) {
            if (isset($entity_id_arr['value'])) {
              $fc_entity_id = $entity_id_arr['value'];
              save_field_collections_recursively('node', $tnode, $fc_entity_id, $t_arr['field_collection'][$field]);
            }
          }
        }
      }
    }
  }
}

function save_field_collections_recursively($entity_type, $host_entity, $fc_entity_id, $translated_fc_arr) {
  $fieldCollectionItemEntity = entity_load_unchanged('field_collection_item', $fc_entity_id);
  if (!$fieldCollectionItemEntity) {
    return;
  }
  $field_collection_name = $fieldCollectionItemEntity->field_name;

  $field_collection_item_array = get_object_vars($fieldCollectionItemEntity);
  $arr = array_keys($field_collection_item_array);
  $new_field_collection_arr = array('field_name' => $field_collection_name);
  foreach ($arr as $key) {
    // Check if this key exists; If true then read this.
    $fc_field_def = field_read_field($key);
    if ($fc_field_def && !empty($fc_field_def) && isset($fc_field_def['type'])) {
      if ($fc_field_def['type'] != 'list_boolean' && $fc_field_def['type'] != 'image' && $fc_field_def['type'] != 'file' && $fc_field_def['type'] != 'taxonomy_term_reference' && $fc_field_def['type'] != 'field_collection') {
        if (isset($field_collection_item_array[$key]) && isset($field_collection_item_array[$key][LANGUAGE_NONE])) {
          $field_data_arr = $field_collection_item_array[$key][LANGUAGE_NONE];
          foreach ($field_data_arr as $delta => $field_data) {
            if (isset($translated_fc_arr[$field_collection_name][$fc_entity_id][$key][LANGUAGE_NONE][$delta])) {
              $glObj = $translated_fc_arr[$field_collection_name][$fc_entity_id][$key][LANGUAGE_NONE][$delta];
              if (is_object($glObj)) {
                $translated_content = $glObj->translatedContent;
              }
              else {
                $translated_content = $glObj;
              }
              if (isset($field_data['format'])) {
                $format = $field_data['format'];
                $new_field_collection_arr[$key][LANGUAGE_NONE][$delta] = array('value' => $translated_content, 'format' => $format);
              }
              else {
                $new_field_collection_arr[$key][LANGUAGE_NONE][$delta] = array('value' => $translated_content);
              }
            }
            else {
              $new_field_collection_arr[$key][LANGUAGE_NONE][$delta] = $field_data;
            }
          }
        }
      }
      elseif ($fc_field_def['type'] != 'field_collection') {
        if (isset($field_collection_item_array[$key]) && isset($field_collection_item_array[$key][LANGUAGE_NONE])) {
          $field_data_arr = $field_collection_item_array[$key][LANGUAGE_NONE];
          $new_field_collection_arr[$key][LANGUAGE_NONE] = $field_data_arr;
        }
      }
    }
  }

  if ($entity_type != 'node') {
    $host_entity->tpt_skip = TRUE;
  }
  $field_collection_item = entity_create('field_collection_item', $new_field_collection_arr); // Create new field collection item.
  $field_collection_item->setHostEntity($entity_type, $host_entity); // Attach it to the node.
  $field_collection_item->save(TRUE); // Save field-collection item

  field_attach_presave($entity_type, $host_entity);
  field_attach_update($entity_type, $host_entity);

  //Now set the child FC if any
  foreach ($arr as $key) {
    // Check if this key exists; If true then read this.
    $fc_field_def = field_read_field($key);
    if ($fc_field_def && !empty($fc_field_def) && isset($fc_field_def['type'])) {
      if ($fc_field_def['type'] == 'field_collection') {
        $items = field_get_items('field_collection_item', $fieldCollectionItemEntity, $key);
        if ($items) {
          foreach ($items as $entity_id_arr) {
            if (isset($entity_id_arr['value'])) {
              $fc_entity_id = $entity_id_arr['value'];
              save_field_collections_recursively('field_collection_item', $field_collection_item, $fc_entity_id, $translated_fc_arr);
            }
          }
        }
      }
    }
  }
}

function get_xml($node, $target_arr, $tnid = NULL, $tvid = NULL, &$name = '', $for_display = FALSE) {
  if (is_null($node)) {
    return TPT_STATUS_SOURCE_DELETED;
  }
  elseif (!$node) {
    return TPT_STATUS_SOURCE_DELETED;
  }

  if ($node && is_object($node)) {
    if ($node->language != 'en') {
      $name = 'Node_' . $node->nid . '_Non_English' . $name;
    }
    else {
      $name = format_file_name($node->title) . $name;
    }
    $xml = generate_xml_document($node, $target_arr, $tnid, $tvid, $for_display);
    return $xml;
  }

  return TPT_STATUS_SOURCE_DELETED;
}

function generate_xml_document($node, $target_arr, $tnid = NULL, $tvid = NULL, $for_display = FALSE) {

  $is_hook_enabled = variable_get('transperfect_implementation_type', 0);

  try {
    $dom = new DOMDocument('1.0', 'UTF-8');
    $dom->formatOutput = TRUE;

    $root = $dom->createElement("content");
    $nid = $dom->createAttribute('nid');
    if ($tnid != NULL) {
      $nid->value = $tnid;
    }
    else {
      $nid->value = $node->nid;
    }
    $root->appendChild($nid);

    $vid = $dom->createAttribute('vid');
    if ($tvid != NULL) {
      $vid->value = $tvid;
    }
    else {
      $vid->value = $node->vid;
    }
    $root->appendChild($vid);

    $dom->appendChild($root);

    if ($for_display) {
      insert_child_element($dom, $root, "title", $node->title);
    }
    elseif (is_field_configured_for_translation('node', $node->type, 'title', $node->type) && $is_hook_enabled == 0) {
      insert_child_element($dom, $root, "title", $node->title);
    }
    elseif ($is_hook_enabled == 1) {
      if (tpt_is_field_translatable($node, 'title', $target_arr)) {
        insert_child_element($dom, $root, "title", $node->title);
      }
    }

    $field_arr = field_info_instances('node', $node->type);
    $keys = array_keys($field_arr);
    foreach ($keys as $field) {
      $field_def = field_read_field($field);
      $items = field_get_items('node', $node, $field);
      if ($items) {
        $parent_fc = '';
        if ($field_def['type'] == 'field_collection') {
          $parent_fc = $field;
          if (isset($items[0]['revision_id'])) {
            $fieldCollectionItemEntity = entity_load('field_collection_item', array($items[0]['value']), array('revision_id' => $items[0]['revision_id']));
          }
        }
        traverse_fields_and_field_collections('node', $node->type, $parent_fc, $node->type, $node->nid, $items, $field, $dom, $root, $node, $target_arr, $is_hook_enabled);
      }
    }

    if (module_exists("metatag")) {
      if (isset($node->metatags)) {
        if ($for_display) {
          $metatags = $node->metatags;
          foreach ($metatags as $name => $value) {
            if (isset($value['value'])) {
              insert_child_element($dom, $root, "metatag", $value['value'], array('entity_type' => 'node', 'name' => $name, 'label' => 'Metatag - ' . ucwords($name)));
            }
          }
        }
        elseif (is_field_configured_for_translation('node', $node->type, 'metatags', $node->type)) {
          $metatags = $node->metatags;
          foreach ($metatags as $name => $value) {
            if (isset($value['value'])) {
              insert_child_element($dom, $root, "metatag", $value['value'], array('entity_type' => 'node', 'name' => $name, 'label' => 'Metatag - ' . ucwords($name)));
            }
          }
        }
      }
    }
  }
  catch (Exception $e) {
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "Exception in creating XML - File[$e->getFile()], Line[$e->getLine()], Code[$e->getCode], Message[$e->getMessage]");
    throw $e;
  }

  $root_element = $dom->getElementsByTagName('content')->item(0);
  if (!$root_element->hasChildNodes()) {
    return FALSE;
  }

  return $dom->saveXML();
}

function insert_child_element($dom, $root, $elem_name, $elem_value, $attributes = NULL) {
  if ($elem_name && $elem_value) {
    $item = $dom->createElement($elem_name);
    if (isset($attributes) && is_array($attributes)) {
      foreach ($attributes as $key => $value) {
        $item->setAttribute($key, $value);
      }
    }
    $text = $dom->createTextNode($elem_value);
    $item->appendChild($text);
    $root->appendChild($item);
  }
}

function traverse_fields_and_field_collections($entity_type, $content_type, $parent_fc, $bundle, $entity_id, $items, $field, $dom, $root, $source_node, $target_arr, $is_hook_enabled = 0) {
  if ($items) {
    $field_def = field_read_field($field);
    if ($field_def['type'] != 'list_boolean' && $field_def['type'] != 'image' && $field_def['type'] != 'file' && $field_def['type'] != 'taxonomy_term_reference') {
      if ($field_def['type'] != 'field_collection') {
        if ($is_hook_enabled == 0) {
          if (is_field_configured_for_translation($entity_type, $bundle, $field, $content_type)) {
            //Regular Text Field, get the content directly from items array
            foreach ($items as $delta => $item) {
              if (isset($item['value']) && is_string($item['value'])) {
                $f_label = field_info_instance($entity_type, $field, $bundle);
                $f_value = $item['value'];
                $f_format = (isset($item['format']) && !is_null($item['format'])) ? $item['format'] : '';
                insert_child_element($dom, $root, "field", $f_value, array('entity_type' => $entity_type, 'content_type' => $content_type, 'parent_fc' => $parent_fc, 'bundle' => $bundle, 'entity_id' => $entity_id, 'field_name' => $field, 'label' => $f_label['label'], 'delta' => $delta, 'format' => $f_format));
              }
              elseif ($field_def['type'] == 'link_field' && isset($item['title']) && is_string($item['title'])) {
                $f_label = field_info_instance($entity_type, $field, $bundle);
                $f_value = $item['title'];
                $f_format = (isset($item['format']) && !is_null($item['format'])) ? $item['format'] : '';
                insert_child_element($dom, $root, "field", $f_value, array('entity_type' => $entity_type, 'content_type' => $content_type, 'parent_fc' => $parent_fc, 'bundle' => $bundle, 'entity_id' => $entity_id, 'field_name' => $field, 'label' => $f_label['label'], 'delta' => $delta, 'format' => $f_format));
              }
            }
          }
        }
        else {
          if (tpt_is_field_translatable($source_node, $field, $target_arr)) {
            //Regular Text Field, get the content directly from items array
            foreach ($items as $delta => $item) {
              if (isset($item['value']) && is_string($item['value'])) {
                $f_label = field_info_instance($entity_type, $field, $bundle);
                $f_value = $item['value'];
                $f_format = (isset($item['format']) && !is_null($item['format'])) ? $item['format'] : '';
                insert_child_element($dom, $root, "field", $f_value, array('entity_type' => $entity_type, 'content_type' => $content_type, 'parent_fc' => $parent_fc, 'bundle' => $bundle, 'entity_id' => $entity_id, 'field_name' => $field, 'label' => $f_label['label'], 'delta' => $delta, 'format' => $f_format));
              }
              elseif ($field_def['type'] == 'link_field' && isset($item['title']) && is_string($item['title'])) {
                $f_label = field_info_instance($entity_type, $field, $bundle);
                $f_value = $item['title'];
                $f_format = (isset($item['format']) && !is_null($item['format'])) ? $item['format'] : '';
                insert_child_element($dom, $root, "field", $f_value, array('entity_type' => $entity_type, 'content_type' => $content_type, 'parent_fc' => $parent_fc, 'bundle' => $bundle, 'entity_id' => $entity_id, 'field_name' => $field, 'label' => $f_label['label'], 'delta' => $delta, 'format' => $f_format));
              }
            }
          }
        }
      }
      elseif (module_exists("field_collection")) {
        //Field Collection field, read the entity id from item and load
        //Entity object and then do recursion for nested field collections.
        foreach ($items as $entity_id_arr) {
          if (isset($entity_id_arr['value'])) {
            $fc_entity_id = $entity_id_arr['value'];
            $fieldCollectionItemEntityArr = array();
            if (isset($entity_id_arr['revision_id'])) {
              $fieldCollectionItemEntityArr = entity_load('field_collection_item', array($fc_entity_id), array('revision_id' => $entity_id_arr['revision_id']));
            }
            else {
              $fieldCollectionItemEntityArr = entity_load('field_collection_item', $fc_entity_id);
            }
            if (!$fieldCollectionItemEntityArr || !is_array($fieldCollectionItemEntityArr) || sizeof($fieldCollectionItemEntityArr) < 1) {
              continue;
            }
            $fieldCollectionItemEntity = $fieldCollectionItemEntityArr[$fc_entity_id];
            $field_collection_name = $fieldCollectionItemEntity->field_name;
            $field_collection_item_array = get_object_vars($fieldCollectionItemEntity);
            $arr = array_keys($field_collection_item_array);
            foreach ($arr as $key) {
              // Check if this key exists; If true then read this.
              $fc_field_def = field_read_field($key);
              if ($fc_field_def && !empty($fc_field_def) && isset($fc_field_def['type'])) {
                if ($fc_field_def['type'] != 'list_boolean' && $fc_field_def['type'] != 'image' && $fc_field_def['type'] != 'file' && $fc_field_def['type'] != 'taxonomy_term_reference') {
                  $fc_item = field_get_items('field_collection_item', $fieldCollectionItemEntity, $key);
                  if ($fc_item) {
                    traverse_fields_and_field_collections('field_collection_item', $content_type, $parent_fc, $field_collection_name, $fc_entity_id, $fc_item, $key, $dom, $root, $source_node, $target_arr, $is_hook_enabled);
                  }
                }
              }
            }
          }
        }
      }
    }
  }
}

function get_node_title(&$globalLink) {
  $result = db_select('transperfect_core', 'tc')
          ->fields('tc')
          ->condition('document_ticket', $globalLink->documentTicket, '=')
          ->condition('submission_ticket', $globalLink->submissionTicket, '=')
          ->execute();
  foreach ($result as $item) {
    $nid = $item->nid;
    $node = node_load($nid, $item->vid);
    $globalLink->nid = $nid;
    $globalLink->vid = $item->vid;
    $globalLink->tptRowId = $item->rid;
    $globalLink->title = $item->title;
    if ($item->status == TPT_STATUS_SENT_FOR_TRANSLATIONS)
      $globalLink->status = TPT_STATUS_COMPLETED;
    elseif ($item->status == TPT_STATUS_ERROR)
      $globalLink->status = TPT_STATUS_ERROR;
    if (!$node || is_null($node) || !is_object($node)) {
      return FALSE;
    }
    else {
      $title = l(format_display_string($node->title), 'node/' . $item->nid);
      return $title;
    }
  }
  return FALSE;
}

function get_content_attributes_from_xml($xml) {
  if (is_null($xml) || !is_string($xml) || $xml == '') {
    return array();
  }

  $dom = new DomDocument;
  $dom->preserveWhiteSpace = FALSE;
  $dom->loadXML($xml);

  $arr = array();

  $contents = $dom->getElementsByTagName('content');
  foreach ($contents as $content) {
    if (!is_null($content->attributes)) {
      foreach ($content->attributes as $attrName => $attrNode) {
        if ('rid' == $attrName) {
          $arr['rid'] = $attrNode->value;
        }
        if ('nid' == $attrName) {
          $arr['nid'] = $attrNode->value;
        }
        elseif ('vid' == $attrName) {
          $arr['vid'] = $attrNode->value;
        }
      }
    }
  }

  return $arr;
}

function save_modified_translation($rid, $target_ticket, $orig_arr, $tgt_arr) {
  try {
    $row = get_transperfect_row($rid);
    foreach ($orig_arr as $key => $orig) {
      if (!isset($tgt_arr[$key])) {
        $tgt_arr[$key] = $orig;
      }
    }

    $globalLink = new GlobalLink();
    $globalLink->tptRowId = $rid;
    $globalLink->status = $row->status;
    $globalLink->title = $row->title;
    $globalLink->sourceLocale = $row->source;
    $globalLink->targetLocale = $row->target;
    $globalLink->nid = $row->nid;
    $globalLink->vid = $row->vid;
    $globalLink->documentTicket = $row->document_ticket;
    $globalLink->submissionTicket = $row->submission_ticket;
    $globalLink->submissionName = $row->submission;
    $globalLink->targetTicket = $target_ticket;
    update_node($globalLink, $tgt_arr);
    if ($globalLink->status != TPT_STATUS_ERROR) {
      $pd4 = get_project_director_details();
      sendDownloadConfirmation($globalLink->targetTicket, $pd4);
      update_tpt_status($globalLink);
    }

    return TRUE;
  }
  catch (SoapFault $se) {
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "SOAP Exception in Sending Download Confirmation - save_modified_translation - Code[$se->faultcode], Message[$se->faultstring]");
    form_set_error('', check_plain('Web Services Error: ' . $se->faultcode . ' - ' . $se->faultstring));
  }
  catch (Exception $e) {
    gl_log(TPT_OBJECT_TYPE_CONTENT, TPT_LOGGING_SEVERITY_ERROR, "Exception in Node Update - save_modified_translation - File[$e->getFile()], Line[$e->getLine()], Code[$e->getCode], Message[$e->getMessage]");
    form_set_error('', check_plain('Error: ' . $e->getMessage()));
  }

  return FALSE;
}

function update_submission_status($submission_ticket, $status = TPT_STATUS_CANCELLED) {
  db_update('transperfect_core')
          ->fields(array(
              'status' => $status,
              'timestamp' => REQUEST_TIME
                  )
          )
          ->condition('submission_ticket', $submission_ticket, '=')
          ->execute();
}

function get_submission_status() {
  $query = db_select('transperfect_core', 'tc');
  $query->fields('tc', array('submission_ticket'));
  $query->distinct();
  $query->condition('status', TPT_STATUS_SENT_FOR_TRANSLATIONS, '=');
  $results = $query->execute();
  foreach ($results as $row) {
    if ($row->submission_ticket) {
      try {
        $pd4 = get_project_director_details();
        $status = get_status($pd4, $row->submission_ticket);
        if (!$status || $status == PD_STATUS_CANCELLED) {
          update_submission_status($row->submission_ticket);
        }
      }
      catch (SoapFault $se) {
        update_submission_status($row->submission_ticket);
      }
      catch (Exception $ex) {
        update_submission_status($row->submission_ticket);
      }
    }
  }
}

function check_tpt_status($rids_arr) {
  $status = TRUE;
  $query = db_select('transperfect_core', 'tc')
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

function clear_cancelled_documents() {
  $count = 0;
  $query = db_select('transperfect_core', 'tc')
          ->fields('tc', array('submission_ticket'))
          ->distinct()
          ->condition('status', TPT_STATUS_CANCELLED, '=');
  $results = $query->execute();
  foreach ($results as $item) {
    update_submission_status($item->submission_ticket, TPT_STATUS_PENDING_TRANSLATIONS);
    $count++;
  }

  return $count;
}