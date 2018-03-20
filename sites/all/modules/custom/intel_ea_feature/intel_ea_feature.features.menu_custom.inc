<?php
/**
 * @file
 * intel_ea_feature.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function intel_ea_feature_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-administration.
  $menus['menu-administration'] = array(
    'menu_name' => 'menu-administration',
    'title' => 'Members Database Admin Area',
    'description' => 'Members Database Admin Area',
    'language' => 'und',
    'i18n_mode' => '5',
  );
  
  
  // Exported menu: menu-reports.
  $menus['menu-reports'] = array(
    'menu_name' => 'menu-reports',
    'title' => 'Members Database Reporting',
    'description' => 'Members Database Reporting',
    'language' => 'und',
    'i18n_mode' => '5',
  );
  // Exported menu: menu-site-navigation.
  $menus['menu-site-navigation'] = array(
    'menu_name' => 'menu-site-navigation',
    'title' => 'Site Navigation',
    'description' => 'Top left Intel site navigation.',
    'language' => 'und',
    'i18n_mode' => '5',
  );
  // Exported menu: menu-view-all-companies.
  $menus['menu-view-all-companies'] = array(
    'menu_name' => 'menu-view-all-companies',
    'title' => 'View All Companies',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => '5',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Members Database Admin Area');
  t('Members Database Reporting');
  t('Site Navigation');
  t('Top left Intel site navigation.');
  t('View All Companies');


  return $menus;
}
