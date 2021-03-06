<?php
/**
 * @file
 * intel_ea_feature.feeds_importer_default.inc
 */

/**
 * Implements hook_feeds_importer_default().
 */
function intel_ea_feature_feeds_importer_default() {
  $export = array();

  $feeds_importer = new stdClass();
  $feeds_importer->disabled = FALSE; /* Edit this to true to make a default feeds_importer disabled initially */
  $feeds_importer->api_version = 1;
  $feeds_importer->id = 'feed';
  $feeds_importer->config = array(
    'name' => 'Feed',
    'description' => 'Import RSS or Atom feeds, create nodes from feed items.',
    'fetcher' => array(
      'plugin_key' => 'FeedsHTTPFetcher',
      'config' => array(
        'auto_detect_feeds' => 1,
        'use_pubsubhubbub' => 0,
        'designated_hub' => '',
        'request_timeout' => NULL,
        'auto_scheme' => 'http',
      ),
    ),
    'parser' => array(
      'plugin_key' => 'FeedsSyndicationParser',
      'config' => array(),
    ),
    'processor' => array(
      'plugin_key' => 'FeedsNodeProcessor',
      'config' => array(
        'bundle' => 'feed_item',
        'update_existing' => '0',
        'expire' => '-1',
        'mappings' => array(
          0 => array(
            'source' => 'title',
            'target' => 'title',
            'unique' => 0,
          ),
          1 => array(
            'source' => 'timestamp',
            'target' => 'created',
            'unique' => FALSE,
          ),
          2 => array(
            'source' => 'url',
            'target' => 'url',
            'unique' => 1,
          ),
          3 => array(
            'source' => 'guid',
            'target' => 'guid',
            'unique' => 1,
          ),
          4 => array(
            'source' => 'description',
            'target' => 'field_feed_item_description',
            'format' => 'wysiwyg_basic',
          ),
        ),
        'input_format' => 'wysiwyg_basic',
        'author' => 0,
        'authorize' => 1,
        'skip_hash_check' => 0,
      ),
    ),
    'content_type' => 'feed',
    'update' => 0,
    'import_period' => '1800',
    'expire_period' => 3600,
    'import_on_create' => 1,
    'process_in_background' => FALSE,
  );
  $export['feed'] = $feeds_importer;

  return $export;
}
