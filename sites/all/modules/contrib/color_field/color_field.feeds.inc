<?php
/**
 * @file
 * Implementation of Feeds mapping API for color_field.
 */

/**
 * Implements hook_feeds_processor_targets_alter().
 *
 * @see \Feeds\FeedsNodeProcessor::getMappingTargets()
 */
function color_field_feeds_processor_targets_alter(&$targets, $entity_type, $bundle_name) {
  foreach (field_info_instances($entity_type, $bundle_name) as $name => $instance) {
    $info = field_info_field($name);
    if ($info['type'] == 'color_field_rgb') {
      $targets[$name] = array(
        'name' => $instance['label'],
        'callback' => 'color_field_feeds_set_target',
      );
    }
  }
}

/**
 * Implements hook_feeds_set_target().
 */
function color_field_feeds_set_target($source, $entity, $target, $feed_element) {
  if (empty($feed_element)) {
    return;
  }

  if (!is_array($feed_element)) {
    $feed_element = array($feed_element);
  }

  $info = field_info_field($target);

  // Iterate over all values.
  $field = isset($entity->$target) ? $entity->$target : array($entity->language => array());

  // Allow for multiple mappings to the same target.
  $delta = count($field[$entity->language]);

  foreach ($feed_element as $f) {
    // Test rgb field format.
    $regexp = '@^#[0-9a-fA-F]{6}$@';
    if (!preg_match($regexp, $f)) {
      break;
    }

    if ($info['cardinality'] == $delta) {
      break;
    }

    if (is_object($f) && ($f instanceof FeedsElement)) {
      $f = $f->getValue();
    }

    if (is_scalar($f)) {
      $field[$entity->language][$delta]['rgb'] = $f;
      $delta;
    }
  }

  $entity->$target = $field;
}