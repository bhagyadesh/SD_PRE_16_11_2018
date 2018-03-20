<?php
/**
 * @file
 * intel_isdm_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function intel_isdm_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: main-menu:<front>
  $menu_links['main-menu:<front>'] = array(
    'menu_name' => 'main-menu',
    'link_path' => '<front>',
    'router_path' => '',
    'link_title' => 'Browse By Market Segment',
    'options' => array(
      'menu_attach_block' => array(
        'name' => '',
        'use_ajax' => 0,
        'no_drop' => 0,
        'dropped' => 0,
        'on_hover' => 0,
        'orientation' => 'horizontal',
        'mlid' => 0,
        'plid' => 0,
      ),
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:member-roster
  $menu_links['main-menu:member-roster'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'member-roster',
    'router_path' => 'member-roster',
    'link_title' => 'Partners',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Exported menu link: main-menu:solutions-directory
  $menu_links['main-menu:solutions-directory'] = array(
    'menu_name' => 'main-menu',
    'link_path' => 'solutions-directory',
    'router_path' => 'solutions-directory',
    'link_title' => 'Browse by Type',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '0',
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Browse By Market Segment');
  t('Browse by Type');
  t('Partners');


  return $menu_links;
}
