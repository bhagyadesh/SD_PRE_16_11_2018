<?php
/**
 * @file
 * intel_ea_feature.ckeditor_style_rules.inc
 */

/**
 * Implements hook_ckeditor_style_rule_default().
 */
function intel_ea_feature_ckeditor_style_rule_default() {
  $export = array();

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '33';
  $ckeditor_style_rule->name = 'A Die Button';
  $ckeditor_style_rule->machine_name = 'a_die_button';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'a';
  $ckeditor_style_rule->attributes = array(
    'class' => 'die-button',
    'style' => '',
  );
  $export['a_die_button'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '23';
  $ckeditor_style_rule->name = 'DIV Blue Gradient Background';
  $ckeditor_style_rule->machine_name = 'div_blue_gradient_background';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'div';
  $ckeditor_style_rule->attributes = array(
    'class' => 'blue-gradient-background',
    'style' => '',
  );
  $export['div_blue_gradient_background'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '35';
  $ckeditor_style_rule->name = 'DIV Blue Gradient Background Narrow';
  $ckeditor_style_rule->machine_name = 'div_blue_gradient_background_narrow';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'div';
  $ckeditor_style_rule->attributes = array(
    'class' => 'blue-gradient-background narrow',
    'style' => '',
  );
  $export['div_blue_gradient_background_narrow'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '34';
  $ckeditor_style_rule->name = 'DIV Grey Background Narrow';
  $ckeditor_style_rule->machine_name = 'div_grey_background_narrow';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'div';
  $ckeditor_style_rule->attributes = array(
    'class' => 'grey-background narrow',
    'style' => '',
  );
  $export['div_grey_background_narrow'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '22';
  $ckeditor_style_rule->name = 'DIV White Background';
  $ckeditor_style_rule->machine_name = 'div_white_background';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'div';
  $ckeditor_style_rule->attributes = array(
    'class' => 'white-background',
    'style' => '',
  );
  $export['div_white_background'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '27';
  $ckeditor_style_rule->name = 'DIV White Background Full';
  $ckeditor_style_rule->machine_name = 'div_white_background_full';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'div';
  $ckeditor_style_rule->attributes = array(
    'class' => 'white-background full',
    'style' => '',
  );
  $export['div_white_background_full'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '29';
  $ckeditor_style_rule->name = 'DIV White Background Narrow';
  $ckeditor_style_rule->machine_name = 'div_white_background_narrow';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'div';
  $ckeditor_style_rule->attributes = array(
    'class' => 'white-background narrow',
    'style' => '',
  );
  $export['div_white_background_narrow'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '31';
  $ckeditor_style_rule->name = 'DIV White Background Narrow Introduction';
  $ckeditor_style_rule->machine_name = 'div_white_background_narrow_intro';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'div';
  $ckeditor_style_rule->attributes = array(
    'class' => 'white-background narrow intro',
    'style' => '',
  );
  $export['div_white_background_narrow_intro'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '4';
  $ckeditor_style_rule->name = 'H2 Blue';
  $ckeditor_style_rule->machine_name = 'h2_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h2';
  $ckeditor_style_rule->attributes = array(
    'class' => 'blue',
    'style' => '',
  );
  $export['h2_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '9';
  $ckeditor_style_rule->name = 'H3 Thin Dark Blue';
  $ckeditor_style_rule->machine_name = 'h3_thin_dark_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h3';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thin-dark-blue',
    'style' => '',
  );
  $export['h3_thin_dark_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '10';
  $ckeditor_style_rule->name = 'H4 Thick Blue';
  $ckeditor_style_rule->machine_name = 'h4_thick_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h4';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thick-blue',
    'style' => '',
  );
  $export['h4_thick_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '12';
  $ckeditor_style_rule->name = 'H4 Thick Dark Blue';
  $ckeditor_style_rule->machine_name = 'h4_thick_dark_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h4';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thick-dark-blue',
    'style' => '',
  );
  $export['h4_thick_dark_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '14';
  $ckeditor_style_rule->name = 'H4 Thick White';
  $ckeditor_style_rule->machine_name = 'h4_thick_white';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h4';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thick-white',
    'style' => '',
  );
  $export['h4_thick_white'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '11';
  $ckeditor_style_rule->name = 'H4 Thin Blue';
  $ckeditor_style_rule->machine_name = 'h4_thin_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h4';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thin-blue',
    'style' => '',
  );
  $export['h4_thin_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '13';
  $ckeditor_style_rule->name = 'H4 Thin Dark Blue';
  $ckeditor_style_rule->machine_name = 'h4_thin_dark_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h4';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thin-dark-blue',
    'style' => '',
  );
  $export['h4_thin_dark_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '15';
  $ckeditor_style_rule->name = 'H4 Thin White';
  $ckeditor_style_rule->machine_name = 'h4_thin_white';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h4';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thin-white',
    'style' => '',
  );
  $export['h4_thin_white'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '17';
  $ckeditor_style_rule->name = 'H5 Blue';
  $ckeditor_style_rule->machine_name = 'h5_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h5';
  $ckeditor_style_rule->attributes = array(
    'class' => 'blue',
    'style' => '',
  );
  $export['h5_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '24';
  $ckeditor_style_rule->name = 'H5 Light Blue';
  $ckeditor_style_rule->machine_name = 'h5_light_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h5';
  $ckeditor_style_rule->attributes = array(
    'class' => 'light-blue',
    'style' => '',
  );
  $export['h5_light_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '18';
  $ckeditor_style_rule->name = 'H6 Thick Dark Blue';
  $ckeditor_style_rule->machine_name = 'h6_thick_dark_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'h6';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thick-dark-blue',
    'style' => '',
  );
  $export['h6_thick_dark_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '28';
  $ckeditor_style_rule->name = 'P Big Blue';
  $ckeditor_style_rule->machine_name = 'p_big_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'p';
  $ckeditor_style_rule->attributes = array(
    'class' => 'big-blue',
    'style' => '',
  );
  $export['p_big_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '25';
  $ckeditor_style_rule->name = 'P Small Grey';
  $ckeditor_style_rule->machine_name = 'p_small_grey';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'p';
  $ckeditor_style_rule->attributes = array(
    'class' => 'small-grey',
    'style' => '',
  );
  $export['p_small_grey'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '26';
  $ckeditor_style_rule->name = 'SPAN Thick Dark Blue';
  $ckeditor_style_rule->machine_name = 'span_thick_dark_blue';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'span';
  $ckeditor_style_rule->attributes = array(
    'class' => 'thick-dark-blue',
    'style' => '',
  );
  $export['span_thick_dark_blue'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '32';
  $ckeditor_style_rule->name = 'TABLE Blue Header';
  $ckeditor_style_rule->machine_name = 'table_blue_header';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'table';
  $ckeditor_style_rule->attributes = array(
    'class' => 'blue-header',
    'style' => '',
  );
  $export['table_blue_header'] = $ckeditor_style_rule;

  $ckeditor_style_rule = new stdClass();
  $ckeditor_style_rule->disabled = FALSE; /* Edit this to true to make a default ckeditor_style_rule disabled initially */
  $ckeditor_style_rule->api_version = 1;
  $ckeditor_style_rule->rid = '30';
  $ckeditor_style_rule->name = 'TABLE Introduction';
  $ckeditor_style_rule->machine_name = 'table_introduction';
  $ckeditor_style_rule->styleset = 'wysiwyg_advanced_w_styles';
  $ckeditor_style_rule->description = '';
  $ckeditor_style_rule->element = 'table';
  $ckeditor_style_rule->attributes = array(
    'class' => 'intro',
    'style' => '',
  );
  $export['table_introduction'] = $ckeditor_style_rule;

  return $export;
}
