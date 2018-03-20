<?php
/**
 * @file
 * intel_ea_feature.custom_formatters.inc
 */

/**
 * Implements hook_custom_formatters_defaults().
 */
function intel_ea_feature_custom_formatters_defaults() {
  $export = array();

  $formatter = new stdClass();
  $formatter->disabled = FALSE; /* Edit this to true to make a default formatter disabled initially */
  $formatter->api_version = 2;
  $formatter->name = 'file_content_pdf';
  $formatter->label = 'File: Content PDF';
  $formatter->description = '';
  $formatter->mode = 'php';
  $formatter->field_types = 'file';
  $formatter->code = 'return l(t(\'PDF Download of All Content\'), file_create_url($variables[\'#items\'][\'0\'][\'uri\']), array(\'attributes\' => array(\'class\' => \'download-link\')));';
  $formatter->fapi = '';
  $export['file_content_pdf'] = $formatter;

  return $export;
}
