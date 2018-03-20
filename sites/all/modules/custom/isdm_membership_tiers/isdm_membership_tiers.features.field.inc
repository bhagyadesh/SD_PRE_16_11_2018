<?php
/**
 * @file
 * isdm_membership_tiers.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function isdm_membership_tiers_field_default_fields() {
  $fields = array();

  // Exported field: 'taxonomy_term-membership_tier-checkbox_radio_tree_cardinality'.
  $fields['taxonomy_term-membership_tier-checkbox_radio_tree_cardinality'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'checkbox_radio_tree_cardinality',
      'foreign keys' => array(),
      'indexes' => array(
        'value' => array(
          0 => 'value',
        ),
      ),
      'locked' => '0',
      'module' => 'list',
      'settings' => array(
        'allowed_values' => array(
          -1 => 'Unlimited',
          1 => '1',
        ),
        'allowed_values_function' => '',
      ),
      'translatable' => '0',
      'type' => 'list_integer',
    ),
    'field_instance' => array(
      'bundle' => 'membership_tier',
      'default_value' => array(
        0 => array(
          'value' => 1,
        ),
      ),
      'deleted' => '0',
      'description' => 'Specify the number of child terms widgets should allow to be selected. Determines if radios or checkboxes will be used.',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'taxonomy_term',
      'field_name' => 'checkbox_radio_tree_cardinality',
      'label' => 'Child cardinality',
      'required' => TRUE,
      'settings' => array(
        'user_register_form' => FALSE,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'options',
        'settings' => array(),
        'type' => 'options_select',
        'weight' => 41,
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Child cardinality');
  t('Specify the number of child terms widgets should allow to be selected. Determines if radios or checkboxes will be used.');

  return $fields;
}
