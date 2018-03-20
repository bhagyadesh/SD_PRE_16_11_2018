<?php
/**
 * @file
 * intel_ea_feature.features.wysiwyg.inc
 */

/**
 * Implements hook_wysiwyg_default_profiles().
 */
function intel_ea_feature_wysiwyg_default_profiles() {
  $profiles = array();

  // Exported profile: wysiwyg_advanced
  $profiles['wysiwyg_advanced'] = array(
    'format' => 'wysiwyg_advanced',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'add_to_summaries' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Source' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'ShowBlocks' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Table' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => '0',
      'acf_allowed_content' => '',
      'css_setting' => 'self',
      'css_path' => '%bsites/all/themes/custom/intel/css/global.css, %bsites/all/themes/custom/intel/css/intel.css',
      'stylesSet' => '',
      'block_formats' => 'p,h2,h3,h4,h5,h6',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 1,
      'ckeditor_styles' => array(
        'stylesheetparser' => 0,
      ),
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: wysiwyg_advanced_w_styles
  $profiles['wysiwyg_advanced_w_styles'] = array(
    'format' => 'wysiwyg_advanced_w_styles',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'add_to_summaries' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'JustifyLeft' => 1,
          'JustifyCenter' => 1,
          'JustifyRight' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Anchor' => 1,
          'Superscript' => 1,
          'Subscript' => 1,
          'Source' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'ShowBlocks' => 1,
          'SpecialChar' => 1,
          'Format' => 1,
          'Styles' => 1,
          'Table' => 1,
          'CreateDiv' => 1,
        ),
        'drupal' => array(
          'media' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => '0',
      'acf_allowed_content' => '',
      'css_setting' => 'self',
      'css_path' => '%bsites/all/themes/custom/intel/css/global.css, %bsites/all/themes/custom/intel/css/intel.css',
      'stylesSet' => '',
      'block_formats' => 'p,h2,h3,h4,h5,h6',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 1,
      'ckeditor_styles' => array(
        'stylesheetparser' => 0,
      ),
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: wysiwyg_basic
  $profiles['wysiwyg_basic'] = array(
    'format' => 'wysiwyg_basic',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'add_to_summaries' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'SpecialChar' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => '0',
      'acf_allowed_content' => '',
      'css_setting' => 'self',
      'css_path' => '%bsites/all/themes/custom/intel/css/global.css, %bsites/all/themes/custom/intel/css/intel.css',
      'stylesSet' => '',
      'block_formats' => '',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 1,
      'ckeditor_styles' => array(
        'stylesheetparser' => 0,
      ),
    ),
    'rdf_mapping' => array(),
  );

  // Exported profile: wysiwyg_basic_w_links
  $profiles['wysiwyg_basic_w_links'] = array(
    'format' => 'wysiwyg_basic_w_links',
    'editor' => 'ckeditor',
    'settings' => array(
      'default' => 1,
      'user_choose' => 0,
      'show_toggle' => 1,
      'add_to_summaries' => 1,
      'theme' => 'advanced',
      'language' => 'en',
      'buttons' => array(
        'default' => array(
          'Bold' => 1,
          'Italic' => 1,
          'BulletedList' => 1,
          'NumberedList' => 1,
          'Outdent' => 1,
          'Indent' => 1,
          'Undo' => 1,
          'Redo' => 1,
          'Link' => 1,
          'Unlink' => 1,
          'Cut' => 1,
          'Copy' => 1,
          'Paste' => 1,
          'PasteText' => 1,
          'PasteFromWord' => 1,
          'SpecialChar' => 1,
        ),
      ),
      'toolbarLocation' => 'top',
      'resize_enabled' => 1,
      'default_toolbar_grouping' => 0,
      'simple_source_formatting' => 0,
      'acf_mode' => '0',
      'acf_allowed_content' => '',
      'css_setting' => 'self',
      'css_path' => '%bsites/all/themes/custom/intel/css/global.css, %bsites/all/themes/custom/intel/css/intel.css',
      'stylesSet' => '',
      'block_formats' => '',
      'advanced__active_tab' => 'edit-basic',
      'forcePasteAsPlainText' => 1,
      'ckeditor_styles' => array(
        'stylesheetparser' => 0,
      ),
    ),
    'rdf_mapping' => array(),
  );

  return $profiles;
}
