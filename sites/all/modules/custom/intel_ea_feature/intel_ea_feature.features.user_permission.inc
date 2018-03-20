<?php
/**
 * @file
 * intel_ea_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function intel_ea_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: access administration menu.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: access administration pages.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Solutions Admin',
      4 => 'Primary Admin Contact',
      5 => 'Solutions Directory Editor',
    ),
    'module' => 'system',
  );

  // Exported permission: access all views.
  $permissions['access all views'] = array(
    'name' => 'access all views',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: access content.
  $permissions['access content'] = array(
    'name' => 'access content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Intel Solutions Admin',
      2 => 'anonymous user',
      3 => 'authenticated user',
    ),
    'module' => 'node',
  );

  // Exported permission: access content overview.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Solutions Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: access contextual links.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'contextual',
  );

  // Exported permission: access media browser.
  $permissions['access media browser'] = array(
    'name' => 'access media browser',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Intel Solutions Admin',
      6 => 'Primary Admin Contact',
      7 => 'Solutions Directory Editor',
    ),
    'module' => 'media',
  );

  // Exported permission: access private fields.
  $permissions['access private fields'] = array(
    'name' => 'access private fields',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: access rules debug.
  $permissions['access rules debug'] = array(
    'name' => 'access rules debug',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: access site in maintenance mode.
  $permissions['access site in maintenance mode'] = array(
    'name' => 'access site in maintenance mode',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'system',
  );

  // Exported permission: access site reports.
  $permissions['access site reports'] = array(
    'name' => 'access site reports',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: access user profiles.
  $permissions['access user profiles'] = array(
    'name' => 'access user profiles',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'user',
  );

  // Exported permission: add media from remote sources.
  $permissions['add media from remote sources'] = array(
    'name' => 'add media from remote sources',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'media_internet',
  );

  // Exported permission: administer actions.
  $permissions['administer actions'] = array(
    'name' => 'administer actions',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer advanced pane settings.
  $permissions['administer advanced pane settings'] = array(
    'name' => 'administer advanced pane settings',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer any user.
  $permissions['administer any user'] = array(
    'name' => 'administer any user',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: administer associated user.
  $permissions['administer associated user'] = array(
    'name' => 'administer associated user',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: administer blocks.
  $permissions['administer blocks'] = array(
    'name' => 'administer blocks',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
    ),
    'module' => 'block',
  );

  // Exported permission: administer ckeditor styles.
  $permissions['administer ckeditor styles'] = array(
    'name' => 'administer ckeditor styles',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'ckeditor_styles',
  );

  // Exported permission: administer content translations.
  $permissions['administer content translations'] = array(
    'name' => 'administer content translations',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'i18n_node',
  );

  // Exported permission: administer content types.
  $permissions['administer content types'] = array(
    'name' => 'administer content types',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: administer custom formatters.
  $permissions['administer custom formatters'] = array(
    'name' => 'administer custom formatters',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'custom_formatters',
  );

  // Exported permission: administer delta blocks.
  $permissions['administer delta blocks'] = array(
    'name' => 'administer delta blocks',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'delta_blocks',
  );

  // Exported permission: administer dependencies.
  $permissions['administer dependencies'] = array(
    'name' => 'administer dependencies',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'conditional_fields',
  );

  // Exported permission: administer entityform types.
  $permissions['administer entityform types'] = array(
    'name' => 'administer entityform types',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: administer facets.
  $permissions['administer facets'] = array(
    'name' => 'administer facets',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'facetapi',
  );

  // Exported permission: administer features.
  $permissions['administer features'] = array(
    'name' => 'administer features',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: administer field collections.
  $permissions['administer field collections'] = array(
    'name' => 'administer field collections',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_collection',
  );

  // Exported permission: administer field permissions.
  $permissions['administer field permissions'] = array(
    'name' => 'administer field permissions',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: administer file types.
  $permissions['administer file types'] = array(
    'name' => 'administer file types',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: administer files.
  $permissions['administer files'] = array(
    'name' => 'administer files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: administer filters.
  $permissions['administer filters'] = array(
    'name' => 'administer filters',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: administer flags.
  $permissions['administer flags'] = array(
    'name' => 'administer flags',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: administer google analytics.
  $permissions['administer google analytics'] = array(
    'name' => 'administer google analytics',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: administer image styles.
  $permissions['administer image styles'] = array(
    'name' => 'administer image styles',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'image',
  );

  // Exported permission: administer languages.
  $permissions['administer languages'] = array(
    'name' => 'administer languages',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: administer linkit.
  $permissions['administer linkit'] = array(
    'name' => 'administer linkit',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'linkit',
  );

  // Exported permission: administer main-menu menu items.
  $permissions['administer main-menu menu items'] = array(
    'name' => 'administer main-menu menu items',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer management menu items.
  $permissions['administer management menu items'] = array(
    'name' => 'administer management menu items',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer media browser.
  $permissions['administer media browser'] = array(
    'name' => 'administer media browser',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'media',
  );

  // Exported permission: administer menu.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu',
  );

  // Exported permission: administer menu-administration menu items.
  $permissions['administer menu-administration menu items'] = array(
    'name' => 'administer menu-administration menu items',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer menu-eligible-opportunities menu items.
  $permissions['administer menu-eligible-opportunities menu items'] = array(
    'name' => 'administer menu-eligible-opportunities menu items',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer menu-general-resources menu items.
  $permissions['administer menu-general-resources menu items'] = array(
    'name' => 'administer menu-general-resources menu items',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer menu-member-roster-navigation menu items.
  $permissions['administer menu-member-roster-navigation menu items'] = array(
    'name' => 'administer menu-member-roster-navigation menu items',
    'roles' => array(),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer menu-membership menu items.
  $permissions['administer menu-membership menu items'] = array(
    'name' => 'administer menu-membership menu items',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer menu-reports menu items.
  $permissions['administer menu-reports menu items'] = array(
    'name' => 'administer menu-reports menu items',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer menu-site-navigation menu items.
  $permissions['administer menu-site-navigation menu items'] = array(
    'name' => 'administer menu-site-navigation menu items',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer meta tags.
  $permissions['administer meta tags'] = array(
    'name' => 'administer meta tags',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'metatag',
  );

  // Exported permission: administer mini panels.
  $permissions['administer mini panels'] = array(
    'name' => 'administer mini panels',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: administer modules.
  $permissions['administer modules'] = array(
    'name' => 'administer modules',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer navigation menu items.
  $permissions['administer navigation menu items'] = array(
    'name' => 'administer navigation menu items',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer nodes.
  $permissions['administer nodes'] = array(
    'name' => 'administer nodes',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: administer page manager.
  $permissions['administer page manager'] = array(
    'name' => 'administer page manager',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: administer pane access.
  $permissions['administer pane access'] = array(
    'name' => 'administer pane access',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer panels layouts.
  $permissions['administer panels layouts'] = array(
    'name' => 'administer panels layouts',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer panels styles.
  $permissions['administer panels styles'] = array(
    'name' => 'administer panels styles',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: administer pathauto.
  $permissions['administer pathauto'] = array(
    'name' => 'administer pathauto',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: administer permissions.
  $permissions['administer permissions'] = array(
    'name' => 'administer permissions',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: administer redirects.
  $permissions['administer redirects'] = array(
    'name' => 'administer redirects',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'redirect',
  );

  // Exported permission: administer rules.
  $permissions['administer rules'] = array(
    'name' => 'administer rules',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: administer search_api.
  $permissions['administer search_api'] = array(
    'name' => 'administer search_api',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'search_api',
  );

  // Exported permission: administer site configuration.
  $permissions['administer site configuration'] = array(
    'name' => 'administer site configuration',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer software updates.
  $permissions['administer software updates'] = array(
    'name' => 'administer software updates',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer taxonomy.
  $permissions['administer taxonomy'] = array(
    'name' => 'administer taxonomy',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: administer themes.
  $permissions['administer themes'] = array(
    'name' => 'administer themes',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: administer url aliases.
  $permissions['administer url aliases'] = array(
    'name' => 'administer url aliases',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'path',
  );

  // Exported permission: administer user settings.
  $permissions['administer user settings'] = array(
    'name' => 'administer user settings',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: administer user-menu menu items.
  $permissions['administer user-menu menu items'] = array(
    'name' => 'administer user-menu menu items',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'menu_admin_per_menu',
  );

  // Exported permission: administer users.
  $permissions['administer users'] = array(
    'name' => 'administer users',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'user',
  );

  // Exported permission: administer video styles.
  $permissions['administer video styles'] = array(
    'name' => 'administer video styles',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'video_embed_field',
  );

  // Exported permission: administer views.
  $permissions['administer views'] = array(
    'name' => 'administer views',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'views',
  );

  // Exported permission: administer xmlsitemap.
  $permissions['administer xmlsitemap'] = array(
    'name' => 'administer xmlsitemap',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'xmlsitemap',
  );

  // Exported permission: assign Alliance Marketing Expert role.
  $permissions['assign Alliance Marketing Expert role'] = array(
    'name' => 'assign Alliance Marketing Expert role',
    'roles' => array(
      0 => 'Alliance Staff Admin',
      1 => 'Intel Admin',
      2 => 'Intel Market Development Manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Alliance Staff Admin role.
  $permissions['assign Alliance Staff Admin role'] = array(
    'name' => 'assign Alliance Staff Admin role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Alliance Staff Employee role.
  $permissions['assign Alliance Staff Employee role'] = array(
    'name' => 'assign Alliance Staff Employee role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Co-Marketing (MDF) Contact role.
  $permissions['assign Co-Marketing (MDF) Contact role'] = array(
    'name' => 'assign Co-Marketing (MDF) Contact role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Co-Marketing Affiliate role.
  $permissions['assign Co-Marketing Affiliate role'] = array(
    'name' => 'assign Co-Marketing Affiliate role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Co-Marketing Associate role.
  $permissions['assign Co-Marketing Associate role'] = array(
    'name' => 'assign Co-Marketing Associate role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Co-Marketing General role.
  $permissions['assign Co-Marketing General role'] = array(
    'name' => 'assign Co-Marketing General role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Co-Marketing Premier role.
  $permissions['assign Co-Marketing Premier role'] = array(
    'name' => 'assign Co-Marketing Premier role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Executive role.
  $permissions['assign Executive role'] = array(
    'name' => 'assign Executive role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Intel Admin role.
  $permissions['assign Intel Admin role'] = array(
    'name' => 'assign Intel Admin role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Intel Employee role.
  $permissions['assign Intel Employee role'] = array(
    'name' => 'assign Intel Employee role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Intel Field Applications Engineer role.
  $permissions['assign Intel Field Applications Engineer role'] = array(
    'name' => 'assign Intel Field Applications Engineer role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Intel Field Sales Engineer role.
  $permissions['assign Intel Field Sales Engineer role'] = array(
    'name' => 'assign Intel Field Sales Engineer role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Intel Market Development Manager role.
  $permissions['assign Intel Market Development Manager role'] = array(
    'name' => 'assign Intel Market Development Manager role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Leads Contact role.
  $permissions['assign Leads Contact role'] = array(
    'name' => 'assign Leads Contact role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Primary Admin Contact role.
  $permissions['assign Primary Admin Contact role'] = array(
    'name' => 'assign Primary Admin Contact role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Primary Co-Marketing (MDF) Contact role.
  $permissions['assign Primary Co-Marketing (MDF) Contact role'] = array(
    'name' => 'assign Primary Co-Marketing (MDF) Contact role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Primary Contact role.
  $permissions['assign Primary Contact role'] = array(
    'name' => 'assign Primary Contact role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Primary Leads Contact role.
  $permissions['assign Primary Leads Contact role'] = array(
    'name' => 'assign Primary Leads Contact role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Primary Marketing Contact role.
  $permissions['assign Primary Marketing Contact role'] = array(
    'name' => 'assign Primary Marketing Contact role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Primary Sales Contact role.
  $permissions['assign Primary Sales Contact role'] = array(
    'name' => 'assign Primary Sales Contact role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Primary Admin Contact',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign Solutions Directory Editor role.
  $permissions['assign Solutions Directory Editor role'] = array(
    'name' => 'assign Solutions Directory Editor role',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Member Admin',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: assign all roles.
  $permissions['assign all roles'] = array(
    'name' => 'assign all roles',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'role_delegation',
  );

  // Exported permission: block IP addresses.
  $permissions['block IP addresses'] = array(
    'name' => 'block IP addresses',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'system',
  );

  // Exported permission: bypass file access.
  $permissions['bypass file access'] = array(
    'name' => 'bypass file access',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: bypass node access.
  $permissions['bypass node access'] = array(
    'name' => 'bypass node access',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: bypass rules access.
  $permissions['bypass rules access'] = array(
    'name' => 'bypass rules access',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'rules',
  );

  // Exported permission: can manage GlobalLink translation tasks.
  $permissions['can manage GlobalLink translation tasks'] = array(
    'name' => 'can manage GlobalLink translation tasks',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'transperfect',
  );

  // Exported permission: can manage GlobalLink translation tasks and settings.
  $permissions['can manage GlobalLink translation tasks and settings'] = array(
    'name' => 'can manage GlobalLink translation tasks and settings',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'transperfect',
  );

  // Exported permission: can view GlobalLink translation tasks.
  $permissions['can view GlobalLink translation tasks'] = array(
    'name' => 'can view GlobalLink translation tasks',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'transperfect',
  );

  // Exported permission: cancel account.
  $permissions['cancel account'] = array(
    'name' => 'cancel account',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'user',
  );

  // Exported permission: change layouts in place editing.
  $permissions['change layouts in place editing'] = array(
    'name' => 'change layouts in place editing',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: change own username.
  $permissions['change own username'] = array(
    'name' => 'change own username',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Primary Admin Contact',
    ),
    'module' => 'user',
  );

  // Exported permission: create company content.
  $permissions['create company content'] = array(
    'name' => 'create company content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create component content.
  $permissions['create component content'] = array(
    'name' => 'create component content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create feed content.
  $permissions['create feed content'] = array(
    'name' => 'create feed content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Member Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create feed_item content.
  $permissions['create feed_item content'] = array(
    'name' => 'create feed_item content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create field_acceptance_date.
  $permissions['create field_acceptance_date'] = array(
    'name' => 'create field_acceptance_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_account_managers.
  $permissions['create field_account_managers'] = array(
    'name' => 'create field_account_managers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_agreed.
  $permissions['create field_agreed'] = array(
    'name' => 'create field_agreed',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_agreement_date.
  $permissions['create field_agreement_date'] = array(
    'name' => 'create field_agreement_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_agreement_identifier.
  $permissions['create field_agreement_identifier'] = array(
    'name' => 'create field_agreement_identifier',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_applications_engineers.
  $permissions['create field_applications_engineers'] = array(
    'name' => 'create field_applications_engineers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_community_tag.
  $permissions['create field_community_tag'] = array(
    'name' => 'create field_community_tag',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_embedded_processor_support.
  $permissions['create field_embedded_processor_support'] = array(
    'name' => 'create field_embedded_processor_support',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_future_agreement_date.
  $permissions['create field_future_agreement_date'] = array(
    'name' => 'create field_future_agreement_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_future_membership.
  $permissions['create field_future_membership'] = array(
    'name' => 'create field_future_membership',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_future_membership_type.
  $permissions['create field_future_membership_type'] = array(
    'name' => 'create field_future_membership_type',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_marketing_expert.
  $permissions['create field_marketing_expert'] = array(
    'name' => 'create field_marketing_expert',
    'roles' => array(
      0 => 'Alliance Staff Admin',
      1 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_membership_type.
  $permissions['create field_membership_type'] = array(
    'name' => 'create field_membership_type',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_renewal_signee.
  $permissions['create field_renewal_signee'] = array(
    'name' => 'create field_renewal_signee',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_sales_engineers.
  $permissions['create field_sales_engineers'] = array(
    'name' => 'create field_sales_engineers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_solutions_directiory_id.
  $permissions['create field_solutions_directiory_id'] = array(
    'name' => 'create field_solutions_directiory_id',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create field_sponsoring_business_units.
  $permissions['create field_sponsoring_business_units'] = array(
    'name' => 'create field_sponsoring_business_units',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: create files.
  $permissions['create files'] = array(
    'name' => 'create files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Intel Solutions Admin',
      6 => 'Primary Admin Contact',
      7 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: create formula content.
  $permissions['create formula content'] = array(
    'name' => 'create formula content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Solutions Directory Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create mini panels.
  $permissions['create mini panels'] = array(
    'name' => 'create mini panels',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels_mini',
  );

  // Exported permission: create notification content.
  $permissions['create notification content'] = array(
    'name' => 'create notification content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: create opportunity content.
  $permissions['create opportunity content'] = array(
    'name' => 'create opportunity content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create page content.
  $permissions['create page content'] = array(
    'name' => 'create page content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create solution content.
  $permissions['create solution content'] = array(
    'name' => 'create solution content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Solutions Admin',
      4 => 'Solutions Directory Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create story content.
  $permissions['create story content'] = array(
    'name' => 'create story content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Solutions Directory Editor',
    ),
    'module' => 'node',
  );

  // Exported permission: create training_section content.
  $permissions['create training_section content'] = array(
    'name' => 'create training_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create training_sub_section content.
  $permissions['create training_sub_section content'] = array(
    'name' => 'create training_sub_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: create url aliases.
  $permissions['create url aliases'] = array(
    'name' => 'create url aliases',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'path',
  );

  // Exported permission: delete any audio files.
  $permissions['delete any audio files'] = array(
    'name' => 'delete any audio files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete any company content.
  $permissions['delete any company content'] = array(
    'name' => 'delete any company content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any component content.
  $permissions['delete any component content'] = array(
    'name' => 'delete any component content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any document files.
  $permissions['delete any document files'] = array(
    'name' => 'delete any document files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete any entityform.
  $permissions['delete any entityform'] = array(
    'name' => 'delete any entityform',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'entityform',
  );

  // Exported permission: delete any feed content.
  $permissions['delete any feed content'] = array(
    'name' => 'delete any feed content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any feed_item content.
  $permissions['delete any feed_item content'] = array(
    'name' => 'delete any feed_item content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any formula content.
  $permissions['delete any formula content'] = array(
    'name' => 'delete any formula content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any image files.
  $permissions['delete any image files'] = array(
    'name' => 'delete any image files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete any notification content.
  $permissions['delete any notification content'] = array(
    'name' => 'delete any notification content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any opportunity content.
  $permissions['delete any opportunity content'] = array(
    'name' => 'delete any opportunity content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any page content.
  $permissions['delete any page content'] = array(
    'name' => 'delete any page content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any solution content.
  $permissions['delete any solution content'] = array(
    'name' => 'delete any solution content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any story content.
  $permissions['delete any story content'] = array(
    'name' => 'delete any story content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any training_section content.
  $permissions['delete any training_section content'] = array(
    'name' => 'delete any training_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any training_sub_section content.
  $permissions['delete any training_sub_section content'] = array(
    'name' => 'delete any training_sub_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete any video files.
  $permissions['delete any video files'] = array(
    'name' => 'delete any video files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete own audio files.
  $permissions['delete own audio files'] = array(
    'name' => 'delete own audio files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete own company content.
  $permissions['delete own company content'] = array(
    'name' => 'delete own company content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own component content.
  $permissions['delete own component content'] = array(
    'name' => 'delete own component content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own document files.
  $permissions['delete own document files'] = array(
    'name' => 'delete own document files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete own entityform.
  $permissions['delete own entityform'] = array(
    'name' => 'delete own entityform',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: delete own feed content.
  $permissions['delete own feed content'] = array(
    'name' => 'delete own feed content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own feed_item content.
  $permissions['delete own feed_item content'] = array(
    'name' => 'delete own feed_item content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own formula content.
  $permissions['delete own formula content'] = array(
    'name' => 'delete own formula content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own image files.
  $permissions['delete own image files'] = array(
    'name' => 'delete own image files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete own notification content.
  $permissions['delete own notification content'] = array(
    'name' => 'delete own notification content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own opportunity content.
  $permissions['delete own opportunity content'] = array(
    'name' => 'delete own opportunity content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own page content.
  $permissions['delete own page content'] = array(
    'name' => 'delete own page content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own solution content.
  $permissions['delete own solution content'] = array(
    'name' => 'delete own solution content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Intel Solutions Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own story content.
  $permissions['delete own story content'] = array(
    'name' => 'delete own story content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own training_section content.
  $permissions['delete own training_section content'] = array(
    'name' => 'delete own training_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own training_sub_section content.
  $permissions['delete own training_sub_section content'] = array(
    'name' => 'delete own training_sub_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: delete own video files.
  $permissions['delete own video files'] = array(
    'name' => 'delete own video files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: delete revisions.
  $permissions['delete revisions'] = array(
    'name' => 'delete revisions',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: delete terms in 1.
  $permissions['delete terms in 1'] = array(
    'name' => 'delete terms in 1',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 10.
  $permissions['delete terms in 10'] = array(
    'name' => 'delete terms in 10',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 11.
  $permissions['delete terms in 11'] = array(
    'name' => 'delete terms in 11',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 12.
  $permissions['delete terms in 12'] = array(
    'name' => 'delete terms in 12',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 13.
  $permissions['delete terms in 13'] = array(
    'name' => 'delete terms in 13',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 14.
  $permissions['delete terms in 14'] = array(
    'name' => 'delete terms in 14',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 15.
  $permissions['delete terms in 15'] = array(
    'name' => 'delete terms in 15',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 17.
  $permissions['delete terms in 17'] = array(
    'name' => 'delete terms in 17',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 18.
  $permissions['delete terms in 18'] = array(
    'name' => 'delete terms in 18',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 19.
  $permissions['delete terms in 19'] = array(
    'name' => 'delete terms in 19',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 2.
  $permissions['delete terms in 2'] = array(
    'name' => 'delete terms in 2',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 20.
  $permissions['delete terms in 20'] = array(
    'name' => 'delete terms in 20',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 21.
  $permissions['delete terms in 21'] = array(
    'name' => 'delete terms in 21',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 22.
  $permissions['delete terms in 22'] = array(
    'name' => 'delete terms in 22',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 23.
  $permissions['delete terms in 23'] = array(
    'name' => 'delete terms in 23',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 24.
  $permissions['delete terms in 24'] = array(
    'name' => 'delete terms in 24',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 25.
  $permissions['delete terms in 25'] = array(
    'name' => 'delete terms in 25',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 26.
  $permissions['delete terms in 26'] = array(
    'name' => 'delete terms in 26',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 27.
  $permissions['delete terms in 27'] = array(
    'name' => 'delete terms in 27',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 28.
  $permissions['delete terms in 28'] = array(
    'name' => 'delete terms in 28',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 29.
  $permissions['delete terms in 29'] = array(
    'name' => 'delete terms in 29',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 3.
  $permissions['delete terms in 3'] = array(
    'name' => 'delete terms in 3',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 31.
  $permissions['delete terms in 31'] = array(
    'name' => 'delete terms in 31',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 32.
  $permissions['delete terms in 32'] = array(
    'name' => 'delete terms in 32',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 33.
  $permissions['delete terms in 33'] = array(
    'name' => 'delete terms in 33',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 4.
  $permissions['delete terms in 4'] = array(
    'name' => 'delete terms in 4',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 5.
  $permissions['delete terms in 5'] = array(
    'name' => 'delete terms in 5',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 6.
  $permissions['delete terms in 6'] = array(
    'name' => 'delete terms in 6',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 7.
  $permissions['delete terms in 7'] = array(
    'name' => 'delete terms in 7',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 8.
  $permissions['delete terms in 8'] = array(
    'name' => 'delete terms in 8',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: delete terms in 9.
  $permissions['delete terms in 9'] = array(
    'name' => 'delete terms in 9',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: display drupal links.
  $permissions['display drupal links'] = array(
    'name' => 'display drupal links',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: download any audio files.
  $permissions['download any audio files'] = array(
    'name' => 'download any audio files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download any document files.
  $permissions['download any document files'] = array(
    'name' => 'download any document files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download any image files.
  $permissions['download any image files'] = array(
    'name' => 'download any image files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download any video files.
  $permissions['download any video files'] = array(
    'name' => 'download any video files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download own audio files.
  $permissions['download own audio files'] = array(
    'name' => 'download own audio files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download own document files.
  $permissions['download own document files'] = array(
    'name' => 'download own document files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download own image files.
  $permissions['download own image files'] = array(
    'name' => 'download own image files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: download own video files.
  $permissions['download own video files'] = array(
    'name' => 'download own video files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit any audio files.
  $permissions['edit any audio files'] = array(
    'name' => 'edit any audio files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit any company content.
  $permissions['edit any company content'] = array(
    'name' => 'edit any company content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any company name.
  $permissions['edit any company name'] = array(
    'name' => 'edit any company name',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: edit any component content.
  $permissions['edit any component content'] = array(
    'name' => 'edit any component content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any document files.
  $permissions['edit any document files'] = array(
    'name' => 'edit any document files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit any entityform.
  $permissions['edit any entityform'] = array(
    'name' => 'edit any entityform',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'entityform',
  );

  // Exported permission: edit any feed content.
  $permissions['edit any feed content'] = array(
    'name' => 'edit any feed content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any feed_item content.
  $permissions['edit any feed_item content'] = array(
    'name' => 'edit any feed_item content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any formula content.
  $permissions['edit any formula content'] = array(
    'name' => 'edit any formula content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any image files.
  $permissions['edit any image files'] = array(
    'name' => 'edit any image files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit any notification content.
  $permissions['edit any notification content'] = array(
    'name' => 'edit any notification content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any opportunity content.
  $permissions['edit any opportunity content'] = array(
    'name' => 'edit any opportunity content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any page content.
  $permissions['edit any page content'] = array(
    'name' => 'edit any page content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any solution content.
  $permissions['edit any solution content'] = array(
    'name' => 'edit any solution content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any story content.
  $permissions['edit any story content'] = array(
    'name' => 'edit any story content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any training_section content.
  $permissions['edit any training_section content'] = array(
    'name' => 'edit any training_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any training_sub_section content.
  $permissions['edit any training_sub_section content'] = array(
    'name' => 'edit any training_sub_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit any video files.
  $permissions['edit any video files'] = array(
    'name' => 'edit any video files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit associated company.
  $permissions['edit associated company'] = array(
    'name' => 'edit associated company',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Intel Market Development Manager',
      3 => 'Primary Admin Contact',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: edit associated feed.
  $permissions['edit associated feed'] = array(
    'name' => 'edit associated feed',
    'roles' => array(
      0 => 'Alliance Marketing Expert',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Intel Market Development Manager',
      4 => 'Member Admin',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: edit associated formula.
  $permissions['edit associated formula'] = array(
    'name' => 'edit associated formula',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Solutions Directory Editor',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: edit associated solution.
  $permissions['edit associated solution'] = array(
    'name' => 'edit associated solution',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Solutions Directory Editor',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: edit associated story.
  $permissions['edit associated story'] = array(
    'name' => 'edit associated story',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Solutions Directory Editor',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: edit field_acceptance_date.
  $permissions['edit field_acceptance_date'] = array(
    'name' => 'edit field_acceptance_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_account_managers.
  $permissions['edit field_account_managers'] = array(
    'name' => 'edit field_account_managers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_agreed.
  $permissions['edit field_agreed'] = array(
    'name' => 'edit field_agreed',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_agreement_date.
  $permissions['edit field_agreement_date'] = array(
    'name' => 'edit field_agreement_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_agreement_identifier.
  $permissions['edit field_agreement_identifier'] = array(
    'name' => 'edit field_agreement_identifier',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_applications_engineers.
  $permissions['edit field_applications_engineers'] = array(
    'name' => 'edit field_applications_engineers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_community_tag.
  $permissions['edit field_community_tag'] = array(
    'name' => 'edit field_community_tag',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_embedded_processor_support.
  $permissions['edit field_embedded_processor_support'] = array(
    'name' => 'edit field_embedded_processor_support',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_future_agreement_date.
  $permissions['edit field_future_agreement_date'] = array(
    'name' => 'edit field_future_agreement_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_future_membership.
  $permissions['edit field_future_membership'] = array(
    'name' => 'edit field_future_membership',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_future_membership_type.
  $permissions['edit field_future_membership_type'] = array(
    'name' => 'edit field_future_membership_type',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_marketing_expert.
  $permissions['edit field_marketing_expert'] = array(
    'name' => 'edit field_marketing_expert',
    'roles' => array(
      0 => 'Alliance Staff Admin',
      1 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_membership_type.
  $permissions['edit field_membership_type'] = array(
    'name' => 'edit field_membership_type',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_renewal_signee.
  $permissions['edit field_renewal_signee'] = array(
    'name' => 'edit field_renewal_signee',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_sales_engineers.
  $permissions['edit field_sales_engineers'] = array(
    'name' => 'edit field_sales_engineers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_solutions_directiory_id.
  $permissions['edit field_solutions_directiory_id'] = array(
    'name' => 'edit field_solutions_directiory_id',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit field_sponsoring_business_units.
  $permissions['edit field_sponsoring_business_units'] = array(
    'name' => 'edit field_sponsoring_business_units',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit meta tags.
  $permissions['edit meta tags'] = array(
    'name' => 'edit meta tags',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Primary Admin Contact',
    ),
    'module' => 'metatag',
  );

  // Exported permission: edit own audio files.
  $permissions['edit own audio files'] = array(
    'name' => 'edit own audio files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit own company content.
  $permissions['edit own company content'] = array(
    'name' => 'edit own company content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own component content.
  $permissions['edit own component content'] = array(
    'name' => 'edit own component content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own document files.
  $permissions['edit own document files'] = array(
    'name' => 'edit own document files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit own entityform.
  $permissions['edit own entityform'] = array(
    'name' => 'edit own entityform',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: edit own feed content.
  $permissions['edit own feed content'] = array(
    'name' => 'edit own feed content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own feed_item content.
  $permissions['edit own feed_item content'] = array(
    'name' => 'edit own feed_item content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own field_acceptance_date.
  $permissions['edit own field_acceptance_date'] = array(
    'name' => 'edit own field_acceptance_date',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_account_managers.
  $permissions['edit own field_account_managers'] = array(
    'name' => 'edit own field_account_managers',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_agreed.
  $permissions['edit own field_agreed'] = array(
    'name' => 'edit own field_agreed',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_agreement_date.
  $permissions['edit own field_agreement_date'] = array(
    'name' => 'edit own field_agreement_date',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_agreement_identifier.
  $permissions['edit own field_agreement_identifier'] = array(
    'name' => 'edit own field_agreement_identifier',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_applications_engineers.
  $permissions['edit own field_applications_engineers'] = array(
    'name' => 'edit own field_applications_engineers',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_community_tag.
  $permissions['edit own field_community_tag'] = array(
    'name' => 'edit own field_community_tag',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_embedded_processor_support.
  $permissions['edit own field_embedded_processor_support'] = array(
    'name' => 'edit own field_embedded_processor_support',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_future_agreement_date.
  $permissions['edit own field_future_agreement_date'] = array(
    'name' => 'edit own field_future_agreement_date',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_future_membership.
  $permissions['edit own field_future_membership'] = array(
    'name' => 'edit own field_future_membership',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_future_membership_type.
  $permissions['edit own field_future_membership_type'] = array(
    'name' => 'edit own field_future_membership_type',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_marketing_expert.
  $permissions['edit own field_marketing_expert'] = array(
    'name' => 'edit own field_marketing_expert',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_membership_type.
  $permissions['edit own field_membership_type'] = array(
    'name' => 'edit own field_membership_type',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_renewal_signee.
  $permissions['edit own field_renewal_signee'] = array(
    'name' => 'edit own field_renewal_signee',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_sales_engineers.
  $permissions['edit own field_sales_engineers'] = array(
    'name' => 'edit own field_sales_engineers',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_solutions_directiory_id.
  $permissions['edit own field_solutions_directiory_id'] = array(
    'name' => 'edit own field_solutions_directiory_id',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own field_sponsoring_business_units.
  $permissions['edit own field_sponsoring_business_units'] = array(
    'name' => 'edit own field_sponsoring_business_units',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: edit own formula content.
  $permissions['edit own formula content'] = array(
    'name' => 'edit own formula content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own image files.
  $permissions['edit own image files'] = array(
    'name' => 'edit own image files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit own notification content.
  $permissions['edit own notification content'] = array(
    'name' => 'edit own notification content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own opportunity content.
  $permissions['edit own opportunity content'] = array(
    'name' => 'edit own opportunity content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own page content.
  $permissions['edit own page content'] = array(
    'name' => 'edit own page content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own solution content.
  $permissions['edit own solution content'] = array(
    'name' => 'edit own solution content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Intel Solutions Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own story content.
  $permissions['edit own story content'] = array(
    'name' => 'edit own story content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own training_section content.
  $permissions['edit own training_section content'] = array(
    'name' => 'edit own training_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own training_sub_section content.
  $permissions['edit own training_sub_section content'] = array(
    'name' => 'edit own training_sub_section content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: edit own video files.
  $permissions['edit own video files'] = array(
    'name' => 'edit own video files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Primary Admin Contact',
      2 => 'Solutions Directory Editor',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: edit revisions.
  $permissions['edit revisions'] = array(
    'name' => 'edit revisions',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Primary Admin Contact',
      6 => 'Solutions Directory Editor',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: edit terms in 1.
  $permissions['edit terms in 1'] = array(
    'name' => 'edit terms in 1',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 10.
  $permissions['edit terms in 10'] = array(
    'name' => 'edit terms in 10',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 11.
  $permissions['edit terms in 11'] = array(
    'name' => 'edit terms in 11',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 12.
  $permissions['edit terms in 12'] = array(
    'name' => 'edit terms in 12',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 13.
  $permissions['edit terms in 13'] = array(
    'name' => 'edit terms in 13',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 14.
  $permissions['edit terms in 14'] = array(
    'name' => 'edit terms in 14',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 15.
  $permissions['edit terms in 15'] = array(
    'name' => 'edit terms in 15',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 17.
  $permissions['edit terms in 17'] = array(
    'name' => 'edit terms in 17',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 18.
  $permissions['edit terms in 18'] = array(
    'name' => 'edit terms in 18',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 19.
  $permissions['edit terms in 19'] = array(
    'name' => 'edit terms in 19',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 2.
  $permissions['edit terms in 2'] = array(
    'name' => 'edit terms in 2',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 20.
  $permissions['edit terms in 20'] = array(
    'name' => 'edit terms in 20',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 21.
  $permissions['edit terms in 21'] = array(
    'name' => 'edit terms in 21',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 22.
  $permissions['edit terms in 22'] = array(
    'name' => 'edit terms in 22',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 23.
  $permissions['edit terms in 23'] = array(
    'name' => 'edit terms in 23',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 24.
  $permissions['edit terms in 24'] = array(
    'name' => 'edit terms in 24',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 25.
  $permissions['edit terms in 25'] = array(
    'name' => 'edit terms in 25',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 26.
  $permissions['edit terms in 26'] = array(
    'name' => 'edit terms in 26',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 27.
  $permissions['edit terms in 27'] = array(
    'name' => 'edit terms in 27',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 28.
  $permissions['edit terms in 28'] = array(
    'name' => 'edit terms in 28',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 29.
  $permissions['edit terms in 29'] = array(
    'name' => 'edit terms in 29',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 3.
  $permissions['edit terms in 3'] = array(
    'name' => 'edit terms in 3',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 31.
  $permissions['edit terms in 31'] = array(
    'name' => 'edit terms in 31',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 32.
  $permissions['edit terms in 32'] = array(
    'name' => 'edit terms in 32',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 33.
  $permissions['edit terms in 33'] = array(
    'name' => 'edit terms in 33',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 4.
  $permissions['edit terms in 4'] = array(
    'name' => 'edit terms in 4',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 5.
  $permissions['edit terms in 5'] = array(
    'name' => 'edit terms in 5',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 6.
  $permissions['edit terms in 6'] = array(
    'name' => 'edit terms in 6',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 7.
  $permissions['edit terms in 7'] = array(
    'name' => 'edit terms in 7',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 8.
  $permissions['edit terms in 8'] = array(
    'name' => 'edit terms in 8',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: edit terms in 9.
  $permissions['edit terms in 9'] = array(
    'name' => 'edit terms in 9',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: flag displayed_end_user.
  $permissions['flag displayed_end_user'] = array(
    'name' => 'flag displayed_end_user',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: flag promoted_end_user.
  $permissions['flag promoted_end_user'] = array(
    'name' => 'flag promoted_end_user',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: flush caches.
  $permissions['flush caches'] = array(
    'name' => 'flush caches',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: grant content access.
  $permissions['grant content access'] = array(
    'name' => 'grant content access',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'content_access',
  );

  // Exported permission: grant own content access.
  $permissions['grant own content access'] = array(
    'name' => 'grant own content access',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'content_access',
  );

  // Exported permission: manage features.
  $permissions['manage features'] = array(
    'name' => 'manage features',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'features',
  );

  // Exported permission: notify of path changes.
  $permissions['notify of path changes'] = array(
    'name' => 'notify of path changes',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'pathauto',
  );

  // Exported permission: opt-in or out of tracking.
  $permissions['opt-in or out of tracking'] = array(
    'name' => 'opt-in or out of tracking',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: publish revisions.
  $permissions['publish revisions'] = array(
    'name' => 'publish revisions',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of any company content.
  $permissions['publish revisions of any company content'] = array(
    'name' => 'publish revisions of any company content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of any component content.
  $permissions['publish revisions of any component content'] = array(
    'name' => 'publish revisions of any component content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of any formula content.
  $permissions['publish revisions of any formula content'] = array(
    'name' => 'publish revisions of any formula content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of any solution content.
  $permissions['publish revisions of any solution content'] = array(
    'name' => 'publish revisions of any solution content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of own company content.
  $permissions['publish revisions of own company content'] = array(
    'name' => 'publish revisions of own company content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of own component content.
  $permissions['publish revisions of own component content'] = array(
    'name' => 'publish revisions of own component content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of own formula content.
  $permissions['publish revisions of own formula content'] = array(
    'name' => 'publish revisions of own formula content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: publish revisions of own solution content.
  $permissions['publish revisions of own solution content'] = array(
    'name' => 'publish revisions of own solution content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: revert revisions.
  $permissions['revert revisions'] = array(
    'name' => 'revert revisions',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: select account cancellation method.
  $permissions['select account cancellation method'] = array(
    'name' => 'select account cancellation method',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'user',
  );

  // Exported permission: show format selection for entityform.
  $permissions['show format selection for entityform'] = array(
    'name' => 'show format selection for entityform',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for field_collection_item.
  $permissions['show format selection for field_collection_item'] = array(
    'name' => 'show format selection for field_collection_item',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for file.
  $permissions['show format selection for file'] = array(
    'name' => 'show format selection for file',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for node.
  $permissions['show format selection for node'] = array(
    'name' => 'show format selection for node',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for rules_config.
  $permissions['show format selection for rules_config'] = array(
    'name' => 'show format selection for rules_config',
    'roles' => array(),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for taxonomy_term.
  $permissions['show format selection for taxonomy_term'] = array(
    'name' => 'show format selection for taxonomy_term',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format selection for user.
  $permissions['show format selection for user'] = array(
    'name' => 'show format selection for user',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show format tips.
  $permissions['show format tips'] = array(
    'name' => 'show format tips',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: show more format tips link.
  $permissions['show more format tips link'] = array(
    'name' => 'show more format tips link',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'better_formats',
  );

  // Exported permission: translate admin strings.
  $permissions['translate admin strings'] = array(
    'name' => 'translate admin strings',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: translate content.
  $permissions['translate content'] = array(
    'name' => 'translate content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
      3 => 'Solutions Directory Editor',
    ),
    'module' => 'translation',
  );

  // Exported permission: translate interface.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'locale',
  );

  // Exported permission: translate user-defined strings.
  $permissions['translate user-defined strings'] = array(
    'name' => 'translate user-defined strings',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'i18n_string',
  );

  // Exported permission: unflag displayed_end_user.
  $permissions['unflag displayed_end_user'] = array(
    'name' => 'unflag displayed_end_user',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: unflag promoted_end_user.
  $permissions['unflag promoted_end_user'] = array(
    'name' => 'unflag promoted_end_user',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'flag',
  );

  // Exported permission: unpublish current revision.
  $permissions['unpublish current revision'] = array(
    'name' => 'unpublish current revision',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Primary Admin Contact',
      6 => 'Solutions Directory Editor',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: use PHP for tracking visibility.
  $permissions['use PHP for tracking visibility'] = array(
    'name' => 'use PHP for tracking visibility',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'googleanalytics',
  );

  // Exported permission: use flag import.
  $permissions['use flag import'] = array(
    'name' => 'use flag import',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'flag',
  );

  // Exported permission: use ipe with page manager.
  $permissions['use ipe with page manager'] = array(
    'name' => 'use ipe with page manager',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use media wysiwyg.
  $permissions['use media wysiwyg'] = array(
    'name' => 'use media wysiwyg',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Primary Admin Contact',
      6 => 'Solutions Directory Editor',
    ),
    'module' => 'media_wysiwyg',
  );

  // Exported permission: use page manager.
  $permissions['use page manager'] = array(
    'name' => 'use page manager',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'page_manager',
  );

  // Exported permission: use panels caching features.
  $permissions['use panels caching features'] = array(
    'name' => 'use panels caching features',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels dashboard.
  $permissions['use panels dashboard'] = array(
    'name' => 'use panels dashboard',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels in place editing.
  $permissions['use panels in place editing'] = array(
    'name' => 'use panels in place editing',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use panels locks.
  $permissions['use panels locks'] = array(
    'name' => 'use panels locks',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: use text format wysiwyg_advanced.
  $permissions['use text format wysiwyg_advanced'] = array(
    'name' => 'use text format wysiwyg_advanced',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format wysiwyg_advanced_w_styles.
  $permissions['use text format wysiwyg_advanced_w_styles'] = array(
    'name' => 'use text format wysiwyg_advanced_w_styles',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format wysiwyg_basic.
  $permissions['use text format wysiwyg_basic'] = array(
    'name' => 'use text format wysiwyg_basic',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Intel Solutions Admin',
      6 => 'Primary Admin Contact',
      7 => 'Solutions Directory Editor',
    ),
    'module' => 'filter',
  );

  // Exported permission: use text format wysiwyg_basic_w_links.
  $permissions['use text format wysiwyg_basic_w_links'] = array(
    'name' => 'use text format wysiwyg_basic_w_links',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'filter',
  );

  // Exported permission: view any entityform.
  $permissions['view any entityform'] = array(
    'name' => 'view any entityform',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'entityform',
  );

  // Exported permission: view any pre-release formula.
  $permissions['view any pre-release formula'] = array(
    'name' => 'view any pre-release formula',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Employee',
      5 => 'Intel Field Applications Engineer',
      6 => 'Intel Field Sales Engineer',
      7 => 'Intel Market Development Manager',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: view any pre-release solution.
  $permissions['view any pre-release solution'] = array(
    'name' => 'view any pre-release solution',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Employee',
      5 => 'Intel Field Applications Engineer',
      6 => 'Intel Field Sales Engineer',
      7 => 'Intel Market Development Manager',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: view associated pre-release formula.
  $permissions['view associated pre-release formula'] = array(
    'name' => 'view associated pre-release formula',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: view associated pre-release solution.
  $permissions['view associated pre-release solution'] = array(
    'name' => 'view associated pre-release solution',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'intel_ea_module',
  );

  // Exported permission: view field_acceptance_date.
  $permissions['view field_acceptance_date'] = array(
    'name' => 'view field_acceptance_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_account_managers.
  $permissions['view field_account_managers'] = array(
    'name' => 'view field_account_managers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_agreed.
  $permissions['view field_agreed'] = array(
    'name' => 'view field_agreed',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_agreement_date.
  $permissions['view field_agreement_date'] = array(
    'name' => 'view field_agreement_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_agreement_identifier.
  $permissions['view field_agreement_identifier'] = array(
    'name' => 'view field_agreement_identifier',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_applications_engineers.
  $permissions['view field_applications_engineers'] = array(
    'name' => 'view field_applications_engineers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_community_tag.
  $permissions['view field_community_tag'] = array(
    'name' => 'view field_community_tag',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_embedded_processor_support.
  $permissions['view field_embedded_processor_support'] = array(
    'name' => 'view field_embedded_processor_support',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_future_agreement_date.
  $permissions['view field_future_agreement_date'] = array(
    'name' => 'view field_future_agreement_date',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_future_membership.
  $permissions['view field_future_membership'] = array(
    'name' => 'view field_future_membership',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_future_membership_type.
  $permissions['view field_future_membership_type'] = array(
    'name' => 'view field_future_membership_type',
    'roles' => array(
      0 => 'Administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_marketing_expert.
  $permissions['view field_marketing_expert'] = array(
    'name' => 'view field_marketing_expert',
    'roles' => array(
      0 => 'Alliance Staff Admin',
      1 => 'Intel Admin',
      2 => 'anonymous user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_membership_type.
  $permissions['view field_membership_type'] = array(
    'name' => 'view field_membership_type',
    'roles' => array(
      0 => 'Administrator',
      1 => 'anonymous user',
      2 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_renewal_signee.
  $permissions['view field_renewal_signee'] = array(
    'name' => 'view field_renewal_signee',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_sales_engineers.
  $permissions['view field_sales_engineers'] = array(
    'name' => 'view field_sales_engineers',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_solutions_directiory_id.
  $permissions['view field_solutions_directiory_id'] = array(
    'name' => 'view field_solutions_directiory_id',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view field_sponsoring_business_units.
  $permissions['view field_sponsoring_business_units'] = array(
    'name' => 'view field_sponsoring_business_units',
    'roles' => array(
      0 => 'Administrator',
      1 => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view files.
  $permissions['view files'] = array(
    'name' => 'view files',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Intel Solutions Admin',
      2 => 'anonymous user',
      3 => 'authenticated user',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own entityform.
  $permissions['view own entityform'] = array(
    'name' => 'view own entityform',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'entityform',
  );

  // Exported permission: view own field_acceptance_date.
  $permissions['view own field_acceptance_date'] = array(
    'name' => 'view own field_acceptance_date',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_account_managers.
  $permissions['view own field_account_managers'] = array(
    'name' => 'view own field_account_managers',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_agreed.
  $permissions['view own field_agreed'] = array(
    'name' => 'view own field_agreed',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_agreement_date.
  $permissions['view own field_agreement_date'] = array(
    'name' => 'view own field_agreement_date',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_agreement_identifier.
  $permissions['view own field_agreement_identifier'] = array(
    'name' => 'view own field_agreement_identifier',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_applications_engineers.
  $permissions['view own field_applications_engineers'] = array(
    'name' => 'view own field_applications_engineers',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_community_tag.
  $permissions['view own field_community_tag'] = array(
    'name' => 'view own field_community_tag',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_embedded_processor_support.
  $permissions['view own field_embedded_processor_support'] = array(
    'name' => 'view own field_embedded_processor_support',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_future_agreement_date.
  $permissions['view own field_future_agreement_date'] = array(
    'name' => 'view own field_future_agreement_date',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_future_membership.
  $permissions['view own field_future_membership'] = array(
    'name' => 'view own field_future_membership',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_future_membership_type.
  $permissions['view own field_future_membership_type'] = array(
    'name' => 'view own field_future_membership_type',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_marketing_expert.
  $permissions['view own field_marketing_expert'] = array(
    'name' => 'view own field_marketing_expert',
    'roles' => array(),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_membership_type.
  $permissions['view own field_membership_type'] = array(
    'name' => 'view own field_membership_type',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_renewal_signee.
  $permissions['view own field_renewal_signee'] = array(
    'name' => 'view own field_renewal_signee',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_sales_engineers.
  $permissions['view own field_sales_engineers'] = array(
    'name' => 'view own field_sales_engineers',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_solutions_directiory_id.
  $permissions['view own field_solutions_directiory_id'] = array(
    'name' => 'view own field_solutions_directiory_id',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own field_sponsoring_business_units.
  $permissions['view own field_sponsoring_business_units'] = array(
    'name' => 'view own field_sponsoring_business_units',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: view own files.
  $permissions['view own files'] = array(
    'name' => 'view own files',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own private files.
  $permissions['view own private files'] = array(
    'name' => 'view own private files',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view own unpublished content.
  $permissions['view own unpublished content'] = array(
    'name' => 'view own unpublished content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Intel Solutions Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: view pane admin links.
  $permissions['view pane admin links'] = array(
    'name' => 'view pane admin links',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'panels',
  );

  // Exported permission: view private files.
  $permissions['view private files'] = array(
    'name' => 'view private files',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'file_entity',
  );

  // Exported permission: view revision status messages.
  $permissions['view revision status messages'] = array(
    'name' => 'view revision status messages',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Marketing Expert',
      2 => 'Alliance Staff Admin',
      3 => 'Intel Admin',
      4 => 'Intel Market Development Manager',
      5 => 'Primary Admin Contact',
      6 => 'Solutions Directory Editor',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions.
  $permissions['view revisions'] = array(
    'name' => 'view revisions',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'node',
  );

  // Exported permission: view revisions of any company content.
  $permissions['view revisions of any company content'] = array(
    'name' => 'view revisions of any company content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of any component content.
  $permissions['view revisions of any component content'] = array(
    'name' => 'view revisions of any component content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of any formula content.
  $permissions['view revisions of any formula content'] = array(
    'name' => 'view revisions of any formula content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of any solution content.
  $permissions['view revisions of any solution content'] = array(
    'name' => 'view revisions of any solution content',
    'roles' => array(
      0 => 'Administrator',
      1 => 'Alliance Staff Admin',
      2 => 'Intel Admin',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of own company content.
  $permissions['view revisions of own company content'] = array(
    'name' => 'view revisions of own company content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of own component content.
  $permissions['view revisions of own component content'] = array(
    'name' => 'view revisions of own component content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of own formula content.
  $permissions['view revisions of own formula content'] = array(
    'name' => 'view revisions of own formula content',
    'roles' => array(),
    'module' => 'revisioning',
  );

  // Exported permission: view revisions of own solution content.
  $permissions['view revisions of own solution content'] = array(
    'name' => 'view revisions of own solution content',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'revisioning',
  );

  // Exported permission: view the administration theme.
  $permissions['view the administration theme'] = array(
    'name' => 'view the administration theme',
    'roles' => array(
      0 => 'Administrator',
    ),
    'module' => 'system',
  );

  return $permissions;
}
