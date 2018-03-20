<?php
/**
 * @file
 * intel_isdm_feature.entityqueue_default.inc
 */

/**
 * Implements hook_entityqueue_default_queues().
 */
function intel_isdm_feature_entityqueue_default_queues() {
  $export = array();

  $queue = new EntityQueue();
  $queue->disabled = FALSE; /* Edit this to true to make a default queue disabled initially */
  $queue->api_version = 1;
  $queue->name = 'home_page_market_segments';
  $queue->label = 'Home Page Market Segments';
  $queue->language = 'en';
  $queue->handler = 'simple';
  $queue->target_type = 'taxonomy_term';
  $queue->settings = array(
    'target_bundles' => array(
      'market_segments' => 'market_segments',
    ),
    'min_size' => '12',
    'max_size' => '12',
    'act_as_queue' => 0,
  );
  $export['home_page_market_segments'] = $queue;

  return $export;
}
