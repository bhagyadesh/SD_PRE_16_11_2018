<?php
/**
 * @file
 * intel_ea_feature.delta.inc
 */

/**
 * Implements hook_delta_default_templates().
 */
function intel_ea_feature_delta_default_templates() {
  $export = array();

  $delta = new stdClass();
  $delta->disabled = FALSE; /* Edit this to true to make a default delta disabled initially */
  $delta->api_version = 3;
  $delta->machine_name = 'alliance_training_center';
  $delta->name = 'Alliance Training Center';
  $delta->description = 'Intel theme settings for the Alliance Training Center pages.';
  $delta->theme = 'intel';
  $delta->mode = 'preserve';
  $delta->parent = '';
  $delta->settings = array(
    'theme_intel_settings' => array(
      'alpha_exclude' => array(
        'sites/all/modules/contrib/date/date_api/date.css' => 0,
        'sites/all/modules/contrib/date/date_popup/themes/datepicker.1.7.css' => 0,
        'modules/field/theme/field.css' => 0,
        'modules/node/node.css' => 0,
        'sites/all/modules/development/search_krumo/search_krumo.css' => 0,
        'modules/user/user.css' => 0,
        'sites/all/modules/contrib/views/css/views.css' => 0,
        'misc/vertical-tabs.css' => 0,
        'modules/aggregator/aggregator.css' => 0,
        'modules/block/block.css' => 0,
        'modules/dblog/dblog.css' => 0,
        'modules/file/file.css' => 0,
        'modules/filter/filter.css' => 0,
        'modules/help/help.css' => 0,
        'modules/menu/menu.css' => 0,
        'modules/openid/openid.css' => 0,
        'modules/profile/profile.css' => 0,
        'modules/statistics/statistics.css' => 0,
        'modules/syslog/syslog.css' => 0,
        'modules/system/admin.css' => 0,
        'modules/system/maintenance.css' => 0,
        'modules/system/system.css' => 0,
        'modules/system/system.admin.css' => 0,
        'modules/system/system.base.css' => 0,
        'modules/system/system.maintenance.css' => 0,
        'modules/system/system.menus.css' => 0,
        'modules/system/system.messages.css' => 0,
        'modules/system/system.theme.css' => 0,
        'modules/taxonomy/taxonomy.css' => 0,
        'modules/tracker/tracker.css' => 0,
        'modules/update/update.css' => 0,
      ),
      'alpha_region_preface_first_columns' => '9',
      'alpha_region_preface_second_columns' => '3',
    ),
  );
  $export['alliance_training_center'] = $delta;

  return $export;
}
