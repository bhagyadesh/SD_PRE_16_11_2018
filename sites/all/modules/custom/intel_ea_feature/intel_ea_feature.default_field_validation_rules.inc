<?php
/**
 * @file
 * intel_ea_feature.default_field_validation_rules.inc
 */

/**
 * Implements hook_default_field_validation_rule().
 */
function intel_ea_feature_default_field_validation_rule() {
  $export = array();

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Additional Resources External URL';
  $rule->name = 'additional_resources_external_ur';
  $rule->field_name = 'field_additional_resources';
  $rule->col = 'url';
  $rule->entity_type = 'node';
  $rule->bundle = 'solution';
  $rule->validator = 'field_validation_url_validator';
  $rule->settings = array(
    'external' => 1,
    'internal' => 0,
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      4 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      5 => 0,
      16 => 0,
      6 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
      21 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must be a valid external URL.';
  $export['additional_resources_external_ur'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Company Website External URL';
  $rule->name = 'company_website_external_url';
  $rule->field_name = 'field_website';
  $rule->col = 'url';
  $rule->entity_type = 'node';
  $rule->bundle = 'company';
  $rule->validator = 'field_validation_url_validator';
  $rule->settings = array(
    'external' => 1,
    'internal' => 0,
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      4 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      5 => 0,
      16 => 0,
      6 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
      21 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must be a valid external URL.';
  $export['company_website_external_url'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Datasheet External URL';
  $rule->name = 'datasheet_external_url';
  $rule->field_name = 'field_datasheet';
  $rule->col = 'url';
  $rule->entity_type = 'node';
  $rule->bundle = 'solution';
  $rule->validator = 'field_validation_url_validator';
  $rule->settings = array(
    'external' => 1,
    'internal' => 0,
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      4 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      5 => 0,
      16 => 0,
      6 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
      21 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must be a valid external URL.';
  $export['datasheet_external_url'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Product Brief External URL';
  $rule->name = 'product_brief_external_url';
  $rule->field_name = 'field_brief';
  $rule->col = 'url';
  $rule->entity_type = 'node';
  $rule->bundle = 'solution';
  $rule->validator = 'field_validation_url_validator';
  $rule->settings = array(
    'external' => 1,
    'internal' => 0,
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      4 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      5 => 0,
      16 => 0,
      6 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
      21 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must be a valid external URL.';
  $export['product_brief_external_url'] = $rule;

  $rule = new stdClass();
  $rule->disabled = FALSE; /* Edit this to true to make a default rule disabled initially */
  $rule->api_version = 2;
  $rule->rulename = 'Product Web Page External URL';
  $rule->name = 'product_web_page_external_url';
  $rule->field_name = 'field_website';
  $rule->col = 'url';
  $rule->entity_type = 'node';
  $rule->bundle = 'solution';
  $rule->validator = 'field_validation_url_validator';
  $rule->settings = array(
    'external' => 1,
    'internal' => 0,
    'bypass' => 0,
    'roles' => array(
      2 => 0,
      3 => 0,
      4 => 0,
      8 => 0,
      9 => 0,
      10 => 0,
      11 => 0,
      12 => 0,
      13 => 0,
      14 => 0,
      15 => 0,
      5 => 0,
      16 => 0,
      6 => 0,
      17 => 0,
      18 => 0,
      19 => 0,
      20 => 0,
      21 => 0,
    ),
    'errors' => 0,
  );
  $rule->error_message = '[field-name] must be a valid external URL.';
  $export['product_web_page_external_url'] = $rule;

  return $export;
}
