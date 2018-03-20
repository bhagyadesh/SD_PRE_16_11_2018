<?php
/**
 * @file
 * intel_ea_feature.file_default_displays.inc
 */

/**
 * Implements hook_file_default_displays().
 */
function intel_ea_feature_file_default_displays() {
  $export = array();

  $file_display = new stdClass();
  $file_display->api_version = 1;
  $file_display->name = 'document__preview__file_field_media_large_icon';
  $file_display->weight = 0;
  $file_display->status = TRUE;
  $file_display->settings = '';
  $export['document__preview__file_field_media_large_icon'] = $file_display;

  return $export;
}
