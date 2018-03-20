<?php
/**
 * @file
 * intel_isdm_feature.features.field.inc
 */

/**
 * Implements hook_field_default_fields().
 */
function intel_isdm_feature_field_default_fields() {
  $fields = array();

  // Exported field: 'node-company-field_erpm_company_number'.
  $fields['node-company-field_erpm_company_number'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_erpm_company_number',
      'field_permissions' => array(
        'type' => '0',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'company',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 29,
        ),
        'diff_standard' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'individual_solution' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'roster_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'roster_list_premier' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'solution_list' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'solution_list_quickview' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
        'teaser' => array(
          'label' => 'above',
          'settings' => array(),
          'type' => 'hidden',
          'weight' => 0,
        ),
      ),
      'entity_type' => 'node',
      'field_name' => 'field_erpm_company_number',
      'label' => 'ERPM Company Number',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'wysiwyg_advanced' => 'wysiwyg_advanced',
            'wysiwyg_advanced_w_styles' => 'wysiwyg_advanced_w_styles',
            'wysiwyg_basic' => 'wysiwyg_basic',
            'wysiwyg_basic_w_links' => 'wysiwyg_basic_w_links',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => '10',
              ),
              'wysiwyg_advanced' => array(
                'weight' => '-8',
              ),
              'wysiwyg_advanced_w_styles' => array(
                'weight' => '-7',
              ),
              'wysiwyg_basic' => array(
                'weight' => '-10',
              ),
              'wysiwyg_basic_w_links' => array(
                'weight' => '-9',
              ),
            ),
          ),
        ),
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => '0',
        'user_register_form' => FALSE,
      ),
      'transperfect_translate_field' => 1,
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '2',
      ),
    ),
  );

  // Exported field: 'user-user-field_sso_enterprise_id'.
  $fields['user-user-field_sso_enterprise_id'] = array(
    'field_config' => array(
      'active' => '1',
      'cardinality' => '1',
      'deleted' => '0',
      'entity_types' => array(),
      'field_name' => 'field_sso_enterprise_id',
      'field_permissions' => array(
        'type' => '2',
      ),
      'foreign keys' => array(
        'format' => array(
          'columns' => array(
            'format' => 'format',
          ),
          'table' => 'filter_format',
        ),
      ),
      'indexes' => array(
        'format' => array(
          0 => 'format',
        ),
      ),
      'locked' => '0',
      'module' => 'text',
      'settings' => array(
        'max_length' => '255',
      ),
      'translatable' => '0',
      'type' => 'text',
    ),
    'field_instance' => array(
      'bundle' => 'user',
      'default_value' => NULL,
      'deleted' => '0',
      'description' => '',
      'display' => array(
        'default' => array(
          'label' => 'above',
          'module' => 'text',
          'settings' => array(),
          'type' => 'text_default',
          'weight' => 12,
        ),
      ),
      'entity_type' => 'user',
      'field_name' => 'field_sso_enterprise_id',
      'label' => 'SSO Enterprise ID',
      'required' => 0,
      'settings' => array(
        'better_formats' => array(
          'allowed_formats' => array(
            'plain_text' => 'plain_text',
            'wysiwyg_advanced' => 'wysiwyg_advanced',
            'wysiwyg_advanced_w_styles' => 'wysiwyg_advanced_w_styles',
            'wysiwyg_basic' => 'wysiwyg_basic',
            'wysiwyg_basic_w_links' => 'wysiwyg_basic_w_links',
          ),
          'allowed_formats_toggle' => 0,
          'default_order_toggle' => 0,
          'default_order_wrapper' => array(
            'formats' => array(
              'plain_text' => array(
                'weight' => '10',
              ),
              'wysiwyg_advanced' => array(
                'weight' => '-8',
              ),
              'wysiwyg_advanced_w_styles' => array(
                'weight' => '-7',
              ),
              'wysiwyg_basic' => array(
                'weight' => '-10',
              ),
              'wysiwyg_basic_w_links' => array(
                'weight' => '-9',
              ),
            ),
          ),
        ),
        'linkit' => array(
          'button_text' => 'Search',
          'enable' => 0,
          'profile' => '',
        ),
        'text_processing' => '0',
        'user_register_form' => 0,
      ),
      'widget' => array(
        'active' => 1,
        'module' => 'text',
        'settings' => array(
          'maxlength_js' => 0,
          'maxlength_js_label' => 'Content limited to @limit characters, remaining: <strong>@remaining</strong>',
          'size' => '60',
        ),
        'type' => 'text_textfield',
        'weight' => '57',
      ),
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('ERPM Company Number');
  t('SSO Enterprise ID');

  return $fields;
}
