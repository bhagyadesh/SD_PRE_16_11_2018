<?php
/**
 * @file
 * intel_isdm_user_import_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function intel_isdm_user_import_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'idsm_user_import';
  $feeds_importer->config = array(
    'name' => 'IDSM User Import',
    'description' => 'Imports IDSM Users from CSV',
    'fetcher' => array(
      'plugin_key' => 'FeedsFileFetcher',
      'config' => array(
        'allowed_extensions' => 'txt csv tsv xml opml',
        'direct' => 0,
        'directory' => 'public://feeds',
        'allowed_schemes' => array(
          'public' => 'public',
        ),
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsCSVParser',
      'config' => array(
        'delimiter' => ',',
        'no_headers' => 0,
      ),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsUserProcessor',
      'config' => array(
        'roles' => array(
          20 => '20',
          3 => 0,
          4 => 0,
          8 => 0,
          9 => 0,
          10 => 0,
          11 => 0,
          12 => 0,
          13 => 0,
          28 => 0,
          14 => 0,
          15 => 0,
          5 => 0,
          16 => 0,
          6 => 0,
          27 => 0,
          25 => 0,
          24 => 0,
          26 => 0,
          29 => 0,
          17 => 0,
          18 => 0,
          19 => 0,
          21 => 0,
          30 => 0,
          31 => 0,
          32 => 0,
        ),
        'status' => '1',
        'defuse_mail' => 0,
        'mappings' => array(
          0 => array(
            'source' => 'Business Person Email',
            'target' => 'mail',
            'unique' => FALSE,
          ),
          1 => array(
            'source' => 'Business Person Email',
            'target' => 'name',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'Business Person First Name',
            'target' => 'field_first_name',
            'unique' => FALSE,
          ),
          3 => array(
            'source' => 'Business Person Last Name',
            'target' => 'field_last_name',
            'unique' => FALSE,
          ),
          4 => array(
            'source' => 'Company Name',
            'target' => 'field_company:label',
            'unique' => FALSE,
          ),
          5 => array(
            'source' => 'Work Phone',
            'target' => 'field_work_phone',
            'unique' => FALSE,
          ),
          6 => array(
            'source' => 'Country',
            'target' => 'field_address:country',
            'unique' => FALSE,
          ),
          7 => array(
            'source' => 'Company Role',
            'target' => 'field_company_role',
            'unique' => FALSE,
          ),
        ),
        'update_existing' => '0',
        'update_non_existent' => 'skip',
        'input_format' => 'plain_text',
        'skip_hash_check' => 0,
        'bundle' => 'user',
      ),
    ),
    'content_type' => '',
    'update' => 0,
    'import_period' => '-1',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => 0,
  );
  $export['idsm_user_import'] = $feeds_importer;

  return $export;
}
