<?php
/**
 * @file
 * intel_ea_feature.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function intel_ea_feature_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: menu-administration:admin/content
  $menu_links['menu-administration:admin/content'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/content',
    'router_path' => 'admin/content',
    'link_title' => 'Manage Content',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-37',
  );
  // Exported menu link: menu-administration:admin/people/create
  $menu_links['menu-administration:admin/people/create'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'admin/people/create',
    'router_path' => 'admin/people/create',
    'link_title' => 'Add a User',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-48',
  );
  // Exported menu link: menu-administration:https://www-ssl.intel.com/content/www/us/en/secure/profile/myprofile.html#/isa
  $menu_links['menu-administration:https://www-ssl.intel.com/content/www/us/en/secure/profile/myprofile.html#/isa'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'https://www-ssl.intel.com/content/www/us/en/secure/profile/myprofile.html#/isa',
    'router_path' => '',
    'link_title' => 'Add/Manage Users & Company Information',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '1',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-47',
  );
  // Exported menu link: menu-administration:member-resource-center/manage-feed
  $menu_links['menu-administration:member-resource-center/manage-feed'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'member-resource-center/manage-feed',
    'router_path' => 'member-resource-center/manage-feed',
    'link_title' => 'Manage Company News Feed',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-33',
  );
  // Exported menu link: menu-administration:member-resource-center/manage-formulas
  $menu_links['menu-administration:member-resource-center/manage-formulas'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'member-resource-center/manage-formulas',
    'router_path' => 'member-resource-center/manage-formulas',
    'link_title' => 'Manage Formulas',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-42',
  );
  // Exported menu link: menu-administration:member-resource-center/manage-solutions
  $menu_links['menu-administration:member-resource-center/manage-solutions'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'member-resource-center/manage-solutions',
    'router_path' => 'member-resource-center/manage-solutions',
    'link_title' => 'Manage Solutions',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-44',
  );
  // Exported menu link: menu-administration:member-resource-center/manage-stories
  $menu_links['menu-administration:member-resource-center/manage-stories'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'member-resource-center/manage-stories',
    'router_path' => 'member-resource-center/manage-stories',
    'link_title' => 'Manage Case Studies / Press Releases',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-35',
  );
  // Exported menu link: menu-administration:member-resource-center/manage-users
  $menu_links['menu-administration:member-resource-center/manage-users'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'member-resource-center/manage-users',
    'router_path' => 'member-resource-center/manage-users',
    'link_title' => 'Manage Users',
    'options' => array(
      'alter' => TRUE,
    ),
    'module' => 'system',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-49',
  );
  // Exported menu link: menu-administration:menutoken/52e85a72d7cca
  $menu_links['menu-administration:menutoken/52e85a72d7cca'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'menutoken/52e85a72d7cca',
    'router_path' => 'menutoken/%',
    'link_title' => 'Edit Member Profile',
    'options' => array(
      'menu_token_link_path' => 'node/[current-user:field-company:nid]/edit',
      'menu_token_data' => array(
        'user' => array(
          'type' => 'user',
          'plugin' => 'user_context',
          'options' => array(),
        ),
      ),
      'menu_token_options' => array(
        'clear' => 0,
      ),
      'attributes' => array(
        'title' => 'Edit Member Profile',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-45',
  );
  // Exported menu link: menu-administration:node/27034
  $menu_links['menu-administration:node/27034'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/27034',
    'router_path' => 'node/%',
    'link_title' => 'Direction for Products in Business Site',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-41',
  );
  // Exported menu link: menu-administration:node/32808
  $menu_links['menu-administration:node/32808'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/32808',
    'router_path' => 'node/%',
    'link_title' => 'Manage Company Logo',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-administration:node/3651
  $menu_links['menu-administration:node/3651'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/3651',
    'router_path' => 'node/%',
    'link_title' => 'Communication Recipients Table',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '1',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-36',
  );
  // Exported menu link: menu-administration:node/add/component
  $menu_links['menu-administration:node/add/component'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/add/component',
    'router_path' => 'node/add/component',
    'link_title' => 'Add a Component',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-39',
  );
  // Exported menu link: menu-administration:node/add/formula
  $menu_links['menu-administration:node/add/formula'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/add/formula',
    'router_path' => 'node/add/formula',
    'link_title' => 'Add a Formula',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-40',
  );
  // Exported menu link: menu-administration:node/add/notification
  $menu_links['menu-administration:node/add/notification'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/add/notification',
    'router_path' => 'node/add/notification',
    'link_title' => 'Add a Notification',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-38',
  );
  // Exported menu link: menu-administration:node/add/solution
  $menu_links['menu-administration:node/add/solution'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/add/solution',
    'router_path' => 'node/add/solution',
    'link_title' => 'Add a Solution',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-43',
  );
  // Exported menu link: menu-administration:node/add/story
  $menu_links['menu-administration:node/add/story'] = array(
    'menu_name' => 'menu-administration',
    'link_path' => 'node/add/story',
    'router_path' => 'node/add/story',
    'link_title' => 'Add a Case Study / Press Release',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-34',
  );
  // Exported menu link: menu-site-navigation:member-resource-center
  $menu_links['menu-site-navigation:member-resource-center'] = array(
    'menu_name' => 'menu-site-navigation',
    'link_path' => 'member-resource-center',
    'router_path' => 'member-resource-center',
    'link_title' => 'Members Resource Center',
    'options' => array(),
    'module' => 'system',
    'hidden' => '0',
    'external' => '0',
    'has_children' => '0',
    'expanded' => '0',
    'weight' => '-46',
  );
  // Exported menu link: menu-view-all-companies:member-roster
  $menu_links['menu-view-all-companies:member-roster'] = array(
    'menu_name' => 'menu-view-all-companies',
    'link_path' => 'member-roster',
    'router_path' => 'member-roster',
    'link_title' => 'View Full Company List',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
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
  t('Add a Case Study / Press Release');
  t('Add a Component');
  t('Add a Formula');
  t('Add a Notification');
  t('Add a Solution');
  t('Add a User');
  t('Add/Manage Users & Company Information');
  t('Communication Recipients Table');
  t('Direction for Products in Business Site');
  t('Edit Member Profile');
  t('Manage Case Studies / Press Releases');
  t('Manage Company Logo');
  t('Manage Company News Feed');
  t('Manage Content');
  t('Manage Formulas');
  t('Manage Solutions');
  t('Manage Users');
  t('Members Resource Center');
  t('View Full Company List');


  return $menu_links;
}
