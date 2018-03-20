<?php

require_once TPT_ROOT . '/' . ('transperfect_core_constants.inc');

/*
 * hook transperfect_is_node_translatable
 */

function tpt_is_node_translatable($node, $drupal_target_locale = NULL) {
  $result = module_invoke_all('transperfect_is_node_translatable', $node, $drupal_target_locale);
  if (count($result) > 0) {
    return TRUE;
  }
  return FALSE;
}

/*
 * hook transperfect_is_field_translatable
 */

function tpt_is_field_translatable($node, $field, $drupal_target_locale = NULL) {
  $result = module_invoke_all('transperfect_is_field_translatable', $node, $field, $drupal_target_locale);
  if (count($result) > 0) {
    return TRUE;
  }
  return FALSE;
}

/*
 * hook transperfect_translate_node_for_language
 */

function tpt_translate_node_for_language($node, $drupal_target_locale) {
  $result = module_invoke_all('transperfect_translate_node_for_language', $node, $drupal_target_locale);
  if (count($result) > 0) {
    return TRUE;
  }
  return FALSE;
}

/*
 * hook transperfect_import_translation
 */

function tpt_update_node($source_node, $target_node) {
  foreach (module_implements('transperfect_import_translation') as $module) {
    $function = $module . '_transperfect_import_translation';
    $function($source_node->nid, $target_node);
  }
}

function get_locale_name($locale_code) {
  $result = db_select('transperfect_locale', 'tl')
          ->fields('tl')
          ->condition('locale_code', $locale_code, '=')
          ->execute();
  $locale_name = '';
  foreach ($result as $row) {
    $locale_name = $row->locale_desc;
  }
  return $locale_name;
}

function get_drupal_locale_name($tpt_locale_code) {
  $result = db_select('transperfect_locale', 'tl')
          ->fields('tl')
          ->condition('locale_code', $tpt_locale_code, '=')
          ->execute();
  $locale_name = '';
  foreach ($result as $row) {
    $locale_name = $row->drupal_locale_desc;
  }
  return $locale_name;
}

function get_sent_tpt_rows_by_nid($nid) {
  $result = db_select('transperfect_core', 'tc')
          ->fields('tc')
          ->condition('nid', $nid, '=')
          ->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN')
          ->execute();
  $rows = array();
  foreach ($result as $row) {
    $rows[] = $row;
  }
  return $rows;
}

function get_transperfect_row($row_id) {
  $result = db_select('transperfect_core', 'tc')
          ->fields('tc')
          ->condition('rid', $row_id, '=')
          ->execute();
  foreach ($result as $row) {
    return $row;
  }
}

function get_transperfect_row_by_nid_and_locale($nid, $source, $target) {
  $result = db_select('transperfect_core', 'tc')
          ->fields('tc')
          ->condition('nid', $nid, '=')
          ->condition('source', $source, '=')
          ->condition('target', $target, '=')
          ->execute();
  foreach ($result as $row) {
    return $row;
  }

  return FALSE;
}

function get_tpt_locale_code($drupal_locale) {
  $result = db_select('transperfect_locale', 'tl')
          ->fields('tl')
          ->condition('drupal_locale_code', $drupal_locale, '=')
          ->execute();
  $locale_code = '';
  foreach ($result as $row) {
    $locale_code = $row->locale_code;
  }
  return $locale_code;
}

function get_drupal_locale_code($locale_code) {
  $result = db_select('transperfect_locale', 'tl')
          ->fields('tl')
          ->condition('locale_code', $locale_code, '=')
          ->execute();
  $drupal_code = '';
  foreach ($result as $row) {
    $drupal_code = $row->drupal_locale_code;
  }
  return $drupal_code;
}

function convert_date_to_timestamp($date) {
  list($month, $day, $year) = explode('/', $date);
  $seconds = mktime(0, 0, 0, $month, $day, $year);
  $due_date_in_milli_sec = $seconds * 1000;

  return $due_date_in_milli_sec;
}

function is_preview_enabled() {
  $preview_enabled = variable_get('transperfect_enable_preview', 1);
  if ($preview_enabled == 0) {
    return FALSE;
  }
  return TRUE;
}

function pager_array_splice($data, $limit = 9, $element = 0) {
  global $pager_page_array, $pager_total, $pager_total_items;
  $page = isset($_GET['page']) ? $_GET['page'] : '';

  // Convert comma-separated $page to an array, used by other functions.
  $pager_page_array = explode(',', $page);

  // We calculate the total of pages as ceil(items / limit).
  $pager_total_items[$element] = count($data);
  $pager_total[$element] = ceil($pager_total_items[$element] / $limit);
  $pager_page_array[$element] = max(0, min((int) $pager_page_array[$element], ((int) $pager_total[$element]) - 1));
  return array_slice($data, $pager_page_array[$element] * $limit, $limit, TRUE);
}

function format_display_string($string) {
  if (mb_strlen($string) > 25) {
    return mb_substr($string, 0, 25) . "...";
  }
  return $string;
}

function format_file_name($string) {
  $bad = array_merge(
          array_map('chr', range(0, 31)), array("<", ">", ":", '"', "/", "\\", "|", "?", "*", ";", "&", " ", "."));
  $name = str_replace($bad, "_", utf8_decode(preg_replace('/[^(\x20-\x7F)]*/', '', $string)));
  if (strlen($name) > 50) {
    $name = substr($name, 0, 50);
  }
  return $name;
}

function escapeJsonString($value) { // list from www.json.org: (\b backspace, \f formfeed)
  $escapers = array("\\", "/", "\"", "\n", "\r", "\t", "\x08", "\x0c");
  $replacements = array("\\\\", "\\/", "\\\"", "\\n", "\\r", "\\t", "\\f", "\\b");
  $result = str_replace($escapers, $replacements, $value);
  return $result;
}

function pending_submissions_exists() {
  $result = db_select('transperfect_core', 'tc')
          ->fields('tc')
          ->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN')
          ->execute();

  foreach ($result as $row) {
    if (isset($row)) {
      return TRUE;
    }
  }

  return FALSE;
}

function pending_submissions_exists_for_content_type($type) {
  $result = db_select('transperfect_core', 'tc')
          ->fields('tc')
          ->condition('status', array(TPT_STATUS_SENT_FOR_TRANSLATIONS, TPT_STATUS_ERROR), 'IN')
          ->condition('type', $type, '=')
          ->execute();

  foreach ($result as $row) {
    return TRUE;
  }

  return FALSE;
}

function get_mapped_drupal_locales($remove_default = TRUE) {
  $languages = array();
  $result = db_select('transperfect_locale', 'tl')
          ->fields('tl')
          ->isNotNull('drupal_locale_code')
          ->orderBy('locale_desc', 'ASC')
          ->execute();
  foreach ($result as $row) {
    if ($remove_default) {
      if (language_default()->language == $row->drupal_locale_code) {
        continue;
      }
    }
    $languages[$row->drupal_locale_code] = $row->drupal_locale_desc;
  }

  return $languages;
}

function get_config_fields($content_type) {
  $arr = array();
  $result = db_select('transperfect_field_config', 'tf')
          ->fields('tf')
          ->condition('content_type', $content_type, '=')
          ->execute();
  foreach ($result as $row) {
    $arr[$row->field_name] = $row;
  }

  return $arr;
}

function get_pending_fields($content_type) {
  $config_fields = get_config_fields($content_type);
  $field_info_arr = field_info_instances('node', $content_type);
  $field_info_arr[] = array('field_name' => 'title', 'label' => 'Title');
  if (module_exists('metatag')) {
    $field_info_arr[] = array('field_name' => 'metatags', 'label' => 'Meta tags');
  }
  $field_arr = array();
  foreach ($field_info_arr as $field_info) {
    $field_name = $field_info['field_name'];
    if ($field_name != 'metatag' && $field_name != 'title') {
      $field = field_info_field($field_name);
      if ($field['type'] != 'list_boolean'
              && $field['type'] != 'image'
              && $field['type'] != 'file'
              && $field['type'] != 'taxonomy_term_reference') {
        if (!isset($config_fields[$field_name])) {
          $field_arr[$field_name] = $field_info['label'];
        }
      }
    }
    else {
      if (!isset($config_fields[$field_name])) {
        $field_arr[$field_name] = $field_info['label'];
      }
    }
  }
  asort($field_arr);
  return $field_arr;
}

function get_translatable_node_types_and_names() {
  $arr = array();
  $node_types = node_type_get_types();
  foreach ($node_types as $node_type) {
    if (translation_supported_type($node_type->type)) {
      $arr[$node_type->type] = $node_type->name;
    }
  }
  asort($arr);
  return $arr;
}

function get_translatable_node_types() {
  $arr = array();
  $node_types = node_type_get_types();
  foreach ($node_types as $node_type) {
    if (translation_supported_type($node_type->type)) {
      $arr[] = $node_type->type;
    }
  }
  return $arr;
}

function get_parent_bundle_name($entity_type, $content_type, $field_name) {
  $bundle = '';
  $result = db_select('transperfect_field_config', 'tf')
          ->fields('tf')
          ->condition('content_type', $content_type, '=')
          ->condition('entity_type', $entity_type, '=')
          ->condition('field_name', $field_name, '=')
          ->execute();
  foreach ($result as $row) {
    $bundle = $row->bundle;
  }
  return $bundle;
}

function is_field_configured_for_translation($entity_type, $bundle_name, $field_name, $content_type) {
  $result = db_select('transperfect_field_config', 'tf')
          ->fields('tf')
          ->condition('content_type', $content_type, '=')
          ->condition('entity_type', $entity_type, '=')
          ->condition('bundle', $bundle_name, '=')
          ->condition('field_name', $field_name, '=')
          ->execute();
  foreach ($result as $row) {
    if ($row->translatable == 1) {
      return TRUE;
    }
  }
  return FALSE;
}

function startsWith($haystack, $needle) {
  return !strncmp($haystack, $needle, strlen($needle));
}

function get_drupal_locale() {
  $languages = array();
  $result = db_select('languages', 'l')
          ->fields('l')
          ->condition('enabled', '1', '=')
          ->execute();
  foreach ($result as $row) {
    $languages[$row->language] = $row->name;
  }

  return $languages;
}

function get_mapped_tpt_locales_with_drupal_desc($remove_default = TRUE) {
  $languages = array();
  $result = db_select('transperfect_locale', 'tl')
          ->fields('tl')
          ->isNotNull('drupal_locale_code')
          ->orderBy('locale_desc', 'ASC')
          ->execute();
  foreach ($result as $row) {
    if ($remove_default) {
      if (language_default()->language == $row->drupal_locale_code) {
        continue;
      }
    }
    $languages[$row->locale_code] = $row->drupal_locale_desc;
  }

  return $languages;
}

/**
 * Build array out of search criteria specified in request variables
 */
function drupal_search_query() {
  $filters = array();

  drupal_static_reset('language_list');
  $languages = locale_language_list('name');
  unset($languages['en']);

  $filters['string'] = array(
      'title' => t('String contains'),
      'description' => t('Leave blank to show all strings. The filter is case sensitive.'),
  );

  $filters['language'] = array(
      'title' => t('Language'),
      'options' => array_merge(array('all' => t('All languages'), 'en' => t('English (provided by Drupal)')), $languages),
  );

  $filters['translation'] = array(
      'title' => t('Filter in'),
      'options' => array('all' => t('Both translated and untranslated strings'), 'translated' => t('Only translated strings'), 'untranslated' => t('Only untranslated strings')),
  );

  return $filters;
}

function transperfect_get_source($group) {
  $result = db_query("SELECT lid, source, context, location FROM {locales_source} WHERE textgroup = :textgroup", array(':textgroup' => $group));
  $strings = array();
  foreach ($result as $child) {
    $string = array(
        'lid' => $child->lid,
        'location' => $child->location,
        'source' => $child->source,
        'context' => $child->context,
    );
    $strings[$child->lid] = $string;
  }
  return $strings;
}

function load_source_data($lid) {
  $results = db_select('locales_source', 'ls')
          ->fields('ls')
          ->condition('lid', $lid, '=')
          ->execute();

  $rows = array();
  foreach ($results as $item) {
    $rows[] = $item;
  }

  return $rows;
}

function get_transperfect_other_row($row_id, $type) {
  $result = db_select('transperfect_core_' . $type, 'tc')
          ->fields('tc')
          ->condition('rid', $row_id, '=')
          ->execute();
  foreach ($result as $row) {
    return $row;
  }
}

function get_PD_projects() {
  $proj_arr = variable_get('transperfect_pd_projects', array());
  if (count($proj_arr) > 0) {
    $projects = variable_get('transperfect_pd_projectid', "");
    if ($projects != '') {
      $arr = explode(',', $projects);
      foreach ($arr as $value) {
        if (isset($proj_arr[$value])) {
          $proj_arr[$value] = $proj_arr[$value];
        }
        else {
          $proj_arr[$value] = $value;
        }
      }
    }
  }

  return $proj_arr;
}

function gl_log($type, $severity, $message) {

  //Always log anything with severity error and warning
  if ($severity == TPT_LOGGING_SEVERITY_ERROR || $severity == TPT_LOGGING_SEVERITY_WARNING) {
    db_insert('transperfect_log')
            ->fields(array('severity' => $severity, 'type' => $type, 'message' => $message, 'timestamp' => REQUEST_TIME))
            ->execute();
    return;
  }

  $debug_type = variable_get('transperfect_debug_type', TPT_LOGGING_CONFIG_INFO);

  if ($debug_type == TPT_LOGGING_CONFIG_DISABLED) {
    return;
  }

  if ($debug_type == TPT_LOGGING_CONFIG_INFO && $severity == TPT_LOGGING_SEVERITY_DEBUG) {
    return;
  }

  db_insert('transperfect_log')
          ->fields(array('severity' => $severity, 'type' => $type, 'message' => $message, 'timestamp' => REQUEST_TIME))
          ->execute();
  return;
}