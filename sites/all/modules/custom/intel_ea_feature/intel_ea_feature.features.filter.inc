<?php
/**
 * @file
 * intel_ea_feature.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function intel_ea_feature_filter_default_formats() {
  $formats = array();

  // Exported format: WYSIWYG Advanced.
  $formats['wysiwyg_advanced'] = array(
    'format' => 'wysiwyg_advanced',
    'name' => 'WYSIWYG Advanced',
    'cache' => '0',
    'status' => '1',
    'weight' => '-8',
    'filters' => array(
      'filter_autop' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_tokens' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'media_filter' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => '50',
        'status' => '1',
        'settings' => array(
          'local_paths' => '/',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  // Exported format: WYSIWYG Advanced w/ Styles.
  $formats['wysiwyg_advanced_w_styles'] = array(
    'format' => 'wysiwyg_advanced_w_styles',
    'name' => 'WYSIWYG Advanced w/ Styles',
    'cache' => '1',
    'status' => '1',
    'weight' => '-7',
    'filters' => array(
      'filter_autop' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'media_filter' => array(
        'weight' => '2',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => '50',
        'status' => '1',
        'settings' => array(
          'local_paths' => '/',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  // Exported format: WYSIWYG Basic.
  $formats['wysiwyg_basic'] = array(
    'format' => 'wysiwyg_basic',
    'name' => 'WYSIWYG Basic',
    'cache' => '1',
    'status' => '1',
    'weight' => '-10',
    'filters' => array(
      'filter_autop' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => '50',
        'status' => '1',
        'settings' => array(
          'local_paths' => '/',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  // Exported format: WYSIWYG Basic w/ Links.
  $formats['wysiwyg_basic_w_links'] = array(
    'format' => 'wysiwyg_basic_w_links',
    'name' => 'WYSIWYG Basic w/ Links',
    'cache' => '0',
    'status' => '1',
    'weight' => '-9',
    'filters' => array(
      'filter_autop' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_url' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(
          'filter_url_length' => '72',
        ),
      ),
      'filter_tokens' => array(
        'weight' => '0',
        'status' => '1',
        'settings' => array(),
      ),
      'filter_htmlcorrector' => array(
        'weight' => '10',
        'status' => '1',
        'settings' => array(),
      ),
      'pathologic' => array(
        'weight' => '50',
        'status' => '1',
        'settings' => array(
          'local_paths' => '/',
          'protocol_style' => 'full',
        ),
      ),
    ),
  );

  return $formats;
}
