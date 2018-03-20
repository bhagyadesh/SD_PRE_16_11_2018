<?php
/**
 * @file
 * intel_isdm_feature.features.fe_block_settings.inc
 */

/**
 * Implements hook_default_fe_block_settings().
 */
function intel_isdm_feature_default_fe_block_settings() {
  $export = array();

  $export['version'] = '2.0';

  $export['current_search-partner_companies'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'partner_companies',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => 'member-roster
member-roster/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '1',
  );

  $export['current_search-solutions_directory'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'solutions_directory',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'current_search',
    'node_types' => array(),
    'pages' => 'solutions-directory
solutions-directory/*',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => 'content',
        'status' => '1',
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => '<none>',
    'visibility' => '1',
  );

  $export['delta_blocks-branding'] = array(
    'cache' => 8,
    'custom' => '0',
    'delta' => 'branding',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'delta_blocks',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => 'navigation',
        'status' => '1',
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['intel_ea_community-company_articles'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'company_articles',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'intel_ea_community',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => 'Articles',
    'visibility' => '0',
  );

  $export['intel_ea_community-company_whitepapers'] = array(
    'cache' => '1',
    'custom' => '0',
    'delta' => 'company_whitepapers',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'intel_ea_community',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['lang_dropdown-language'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'language',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'lang_dropdown',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['user-login'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'login',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'user',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-68d6390386d57482a0de28d777ead28a'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => '68d6390386d57482a0de28d777ead28a',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => 'header-one',
        'status' => '1',
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-browse_by_type-block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'browse_by_type-block',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => 'header-two',
        'status' => '1',
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => '',
    'visibility' => '0',
  );

  $export['views-eabbff18cfdeb0049dd5467c1989eb60'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'eabbff18cfdeb0049dd5467c1989eb60',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => 'header-three',
        'status' => '1',
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => 'Partners by Market Segment',
    'visibility' => '0',
  );

  $export['views-isdm_partners_by_loc-block'] = array(
    'cache' => -1,
    'custom' => '0',
    'delta' => 'isdm_partners_by_loc-block',
    'i18n_block_language' => array(),
    'i18n_mode' => '0',
    'module' => 'views',
    'node_types' => array(),
    'pages' => '',
    'roles' => array(),
    'themes' => array(
      'bootstrap' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'bootstrap',
        'weight' => '0',
      ),
      'intel' => array(
        'region' => '',
        'status' => 0,
        'theme' => 'intel',
        'weight' => '0',
      ),
      'intel_isdm_bootstrap' => array(
        'region' => 'header-four',
        'status' => '1',
        'theme' => 'intel_isdm_bootstrap',
        'weight' => '0',
      ),
    ),
    'title' => 'Partners by Location',
    'visibility' => '0',
  );

  return $export;
}
