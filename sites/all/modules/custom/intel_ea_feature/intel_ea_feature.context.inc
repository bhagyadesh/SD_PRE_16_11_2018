<?php
/**
 * @file
 * intel_ea_feature.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function intel_ea_feature_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'alliance_training_center';
  $context->description = 'Control the placement of blocks on the Alliance Training Center pages.';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'training_section' => 'training_section',
        'training_sub_section' => 'training_sub_section',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'training-center' => 'training-center',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'content',
          'weight' => '-5',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
        'easy_breadcrumb-easy_breadcrumb' => array(
          'module' => 'easy_breadcrumb',
          'delta' => 'easy_breadcrumb',
          'region' => 'preface_first',
          'weight' => '-9',
        ),
        'lang_dropdown-language' => array(
          'module' => 'lang_dropdown',
          'delta' => 'language',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Alliance Training Center pages.');
  t('block');
  $export['alliance_training_center'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'alliance_training_center_home';
  $context->description = 'The home page of the Alliance Training Center';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'training-center' => 'training-center',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'training-center-home',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('The home page of the Alliance Training Center');
  $export['alliance_training_center_home'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'alliance_training_center_theme';
  $context->description = 'Intel theme settings for the Alliance Training Center pages.';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'training_section' => 'training_section',
        'training_sub_section' => 'training_sub_section',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'path' => array(
      'values' => array(
        'training-center' => 'training-center',
      ),
    ),
  );
  $context->reactions = array(
    'delta' => array(
      'delta_template' => 'alliance_training_center',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Intel theme settings for the Alliance Training Center pages.');
  t('theme');
  $export['alliance_training_center_theme'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'co_marketing_tool';
  $context->description = 'Control the placement of blocks on the Co-Marketing Tool pages.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'co-marketing-tool' => 'co-marketing-tool',
        'co-marketing-tool/*' => 'co-marketing-tool/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'Alliance Staff Admin' => 'Alliance Staff Admin',
        'Alliance Staff Employee' => 'Alliance Staff Employee',
        'Co-Marketing (MDF) Contact' => 'Co-Marketing (MDF) Contact',
        'Intel Admin' => 'Intel Admin',
        'Intel Employee' => 'Intel Employee',
        'Intel Market Development Manager' => 'Intel Market Development Manager',
        'Primary Admin Contact' => 'Primary Admin Contact',
        'Primary Co-Marketing (MDF) Contact' => 'Primary Co-Marketing (MDF) Contact',
        'Primary Contact' => 'Primary Contact',
        'Primary Marketing Contact' => 'Primary Marketing Contact',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-eligible-opportunities' => array(
          'module' => 'menu',
          'delta' => 'menu-eligible-opportunities',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'menu-menu-general-resources' => array(
          'module' => 'menu',
          'delta' => 'menu-general-resources',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'intel_ea_module-mdf_tool_login' => array(
          'module' => 'intel_ea_module',
          'delta' => 'mdf_tool_login',
          'region' => 'preface_second',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Co-Marketing Tool pages.');
  t('block');
  $export['co_marketing_tool'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'company';
  $context->description = 'Control the placement of blocks on a Company page.';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'company' => 'company',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array();
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on a Company page.');
  t('block');
  $export['company'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'general_membership';
  $context->description = 'Control the placement of blocks on the General Membership pages.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'eform/submit/general-membership-application' => 'eform/submit/general-membership-application',
        'eform/general-membership-application/confirm*' => 'eform/general-membership-application/confirm*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the General Membership pages.');
  t('block');
  $export['general_membership'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'global_blocks';
  $context->description = 'Global placement for site-wide blocks on Intel EA.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~member-roster' => '~member-roster',
        '~member-roster/field_*' => '~member-roster/field_*',
        '~member-roster/print' => '~member-roster/print',
        '~training-center' => '~training-center',
        '~training-center/*' => '~training-center/*',
        '~member-resource-center' => '~member-resource-center',
        '~member-resource-center/*' => '~member-resource-center/*',
        '~user' => '~user',
        '~user/*' => '~user/*',
        '~node/*' => '~node/*',
        '~node/*/*' => '~node/*/*',
        '~node/*/view' => '~node/*/view',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'content',
          'weight' => '-5',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'content',
          'weight' => '1',
        ),
        'intel_theme-sidebar_title_block' => array(
          'module' => 'intel_theme',
          'delta' => 'sidebar_title_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'menu-menu-site-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-site-navigation',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'intel_theme-page_title_block' => array(
          'module' => 'intel_theme',
          'delta' => 'page_title_block',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'lang_dropdown-language' => array(
          'module' => 'lang_dropdown',
          'delta' => 'language',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Global placement for site-wide blocks on Intel EA.');
  t('block');
  $export['global_blocks'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'marketplace_newsletter_archive';
  $context->description = 'Control the placement of blocks on the Marketplace Newsletter Archive page.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'solutions-directory/newsletter-archive' => 'solutions-directory/newsletter-archive',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'intel_ea_module-intel_contact_links' => array(
          'module' => 'intel_ea_module',
          'delta' => 'intel_contact_links',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Marketplace Newsletter Archive page.');
  t('block');
  $export['marketplace_newsletter_archive'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'member_resource_center';
  $context->description = 'Control the placement of blocks on the Member Resource Center pages.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'node/*' => 'node/*',
        '~node' => '~node',
        '~node/add/*' => '~node/add/*',
        '~node/*/*' => '~node/*/*',
        '~node/*/view' => '~node/*/view',
        'user' => 'user',
        'user/*' => 'user/*',
        'member-resource-center' => 'member-resource-center',
        'member-resource-center/*' => 'member-resource-center/*',
        'entityform/*' => 'entityform/*',
        'entityform/*/edit' => 'entityform/*/edit',
      ),
    ),
    'user' => array(
      'values' => array(
        'authenticated user' => 'authenticated user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'content',
          'weight' => '-8',
        ),
        'intel_theme-sidebar_title_block' => array(
          'module' => 'intel_theme',
          'delta' => 'sidebar_title_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'menu-menu-site-navigation' => array(
          'module' => 'menu',
          'delta' => 'menu-site-navigation',
          'region' => 'header_first',
          'weight' => '-10',
        ),
        'intel_ea_module-mrc_header_graphic' => array(
          'module' => 'intel_ea_module',
          'delta' => 'mrc_header_graphic',
          'region' => 'header_second',
          'weight' => '-10',
        ),
        'lang_dropdown-language' => array(
          'module' => 'lang_dropdown',
          'delta' => 'language',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
        'intel_ea_module-mrc_bread_crumb' => array(
          'module' => 'intel_ea_module',
          'delta' => 'mrc_bread_crumb',
          'region' => 'preface_second',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Member Resource Center pages.');
  t('block');
  $export['member_resource_center'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'member_resource_center_class';
  $context->description = 'A context class for the Member Resource Center pages.';
  $context->tag = 'theme';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'company' => 'company',
        'solution' => 'solution',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
    'path' => array(
      'values' => array(
        'admin/people/create' => 'admin/people/create',
        'admin/people' => 'admin/people',
        'user/*/edit' => 'user/*/edit',
        'users/*' => 'users/*',
        'co-marketing-tool' => 'co-marketing-tool',
        'co-marketing-tool/*' => 'co-marketing-tool/*',
        'entityform/*' => 'entityform/*',
        'entityform/*/edit' => 'entityform/*/edit',
      ),
    ),
  );
  $context->reactions = array(
    'theme_html' => array(
      'class' => 'context-member-resource-center',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('A context class for the Member Resource Center pages.');
  t('theme');
  $export['member_resource_center_class'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'member_roster';
  $context->description = 'Control the placement of blocks on the Member Roster page.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'member-roster' => 'member-roster',
        'member-roster/field_*' => 'member-roster/field_*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'content',
          'weight' => '-5',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '0',
        ),
        'panels_mini-mr_filters_group' => array(
          'module' => 'panels_mini',
          'delta' => 'mr_filters_group',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Member Roster page.');
  t('block');
  $export['member_roster'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'member_roster_print';
  $context->description = 'Control the placement of blocks on the Member Roster print page.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'member-roster/print' => 'member-roster/print',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Member Roster print page.');
  t('block');
  $export['member_roster_print'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'member_roster_print_regions';
  $context->description = 'Disable regions for the Member Roster print page.';
  $context->tag = 'theme';
  $context->conditions = array(
    'views' => array(
      'values' => array(
        'member_roster_printable' => 'member_roster_printable',
      ),
    ),
  );
  $context->reactions = array(
    'region' => array(
      'intel' => array(
        'disable' => array(
          'sidebar_first' => 'sidebar_first',
          'header_first' => 'header_first',
          'header_second' => 'header_second',
          'preface_second' => 'preface_second',
          'page_top' => 0,
          'page_bottom' => 0,
          'content' => 0,
          'user_first' => 0,
          'user_second' => 0,
          'branding' => 0,
          'menu' => 0,
          'sidebar_second' => 0,
          'preface_first' => 0,
          'preface_third' => 0,
          'postscript_first' => 0,
          'postscript_second' => 0,
          'postscript_third' => 0,
          'postscript_fourth' => 0,
          'footer_first' => 0,
          'footer_second' => 0,
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Disable regions for the Member Roster print page.');
  t('theme');
  $export['member_roster_print_regions'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'membership_renewal';
  $context->description = 'Control the placement of blocks on the Membership Renewal pages.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'eform/submit/membership-renewal-application' => 'eform/submit/membership-renewal-application',
        'eform/membership-renewal-application/confirm*' => 'eform/membership-renewal-application/confirm*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Membership Renewal pages.');
  t('block');
  $export['membership_renewal'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'menu_mrc';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        '~storys' => '~storys',
        '~storys/*' => '~storys/*',
        '~node' => '~node',
        '~node/*' => '~node/*',
        'user' => 'user',
        'user/*' => 'user/*',
        'member-resource-center' => 'member-resource-center',
        'member-resource-center/*' => 'member-resource-center/*',
        'entityform/*' => 'entityform/*',
        'entityform/*/edit' => 'entityform/*/edit',
      ),
    ),
    'user' => array(
      'values' => array(
        'Administrator' => 'Administrator',
        'Alliance Marketing Expert' => 'Alliance Marketing Expert',
        'Alliance Staff Admin' => 'Alliance Staff Admin',
        'Alliance Staff Employee' => 'Alliance Staff Employee',
        'Co-Marketing (MDF) Contact' => 'Co-Marketing (MDF) Contact',
        'Co-Marketing Affiliate' => 'Co-Marketing Affiliate',
        'Co-Marketing Associate' => 'Co-Marketing Associate',
        'Co-Marketing Distributor' => 'Co-Marketing Distributor',
        'Co-Marketing General' => 'Co-Marketing General',
        'Co-Marketing Premier' => 'Co-Marketing Premier',
        'Executive' => 'Executive',
        'Intel Admin' => 'Intel Admin',
        'Intel Employee' => 'Intel Employee',
        'Intel Field Applications Engineer' => 'Intel Field Applications Engineer',
        'Intel Field Sales Engineer' => 'Intel Field Sales Engineer',
        'Intel Market Development Manager' => 'Intel Market Development Manager',
        'Intel Solutions Admin' => 'Intel Solutions Admin',
        'Leads Contact' => 'Leads Contact',
        'Member Admin' => 'Member Admin',
        'Non-Alliance Employee' => 'Non-Alliance Employee',
        'Primary Admin Contact' => 'Primary Admin Contact',
        'Primary Co-Marketing (MDF) Contact' => 'Primary Co-Marketing (MDF) Contact',
        'Primary Contact' => 'Primary Contact',
        'Primary Leads Contact' => 'Primary Leads Contact',
        'Primary Marketing Contact' => 'Primary Marketing Contact',
        'Primary Sales Contact' => 'Primary Sales Contact',
        'Solutions Directory Editor' => 'Solutions Directory Editor',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'menu-menu-administration' => array(
          'module' => 'menu',
          'delta' => 'menu-administration',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'menu-menu-reports' => array(
          'module' => 'menu',
          'delta' => 'menu-reports',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'intel_ea_module-mrc_membership' => array(
          'module' => 'intel_ea_module',
          'delta' => 'mrc_membership',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'intel_ea_module-mrc_help_links' => array(
          'module' => 'intel_ea_module',
          'delta' => 'mrc_help_links',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['menu_mrc'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opportunity';
  $context->description = 'Control the placement of blocks on an Opportunity page.';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'opportunity' => 'opportunity',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on an Opportunity page.');
  t('block');
  $export['opportunity'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'opportunity_group';
  $context->description = 'Control the placement of blocks on an Opportunity Group page.';
  $context->tag = 'block';
  $context->conditions = array(
    'taxonomy_term' => array(
      'values' => array(
        'opportunity_group' => 'opportunity_group',
      ),
      'options' => array(
        'term_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on an Opportunity Group page.');
  t('block');
  $export['opportunity_group'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'prerelease_solutions_directory';
  $context->description = 'Control the placement of blocks on the Prerelease Solutions Directory page.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'solutions-directory' => 'solutions-directory',
        'solutions-directory/*/*' => 'solutions-directory/*/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'Administrator' => 'Administrator',
        'Alliance Staff Admin' => 'Alliance Staff Admin',
        'Alliance Staff Employee' => 'Alliance Staff Employee',
        'Intel Admin' => 'Intel Admin',
        'Intel Employee' => 'Intel Employee',
        'Intel Field Applications Engineer' => 'Intel Field Applications Engineer',
        'Intel Field Sales Engineer' => 'Intel Field Sales Engineer',
        'Intel Market Development Manager' => 'Intel Market Development Manager',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-559fdf69060fc9cab68ca2bf8cd0bf3b' => array(
          'module' => 'views',
          'delta' => '559fdf69060fc9cab68ca2bf8cd0bf3b',
          'region' => 'content',
          'weight' => '-9',
        ),
        'current_search-solutions_directory' => array(
          'module' => 'current_search',
          'delta' => 'solutions_directory',
          'region' => 'content',
          'weight' => '-8',
        ),
        'intel_ea_module-solutions_directory_facet_text' => array(
          'module' => 'intel_ea_module',
          'delta' => 'solutions_directory_facet_text',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'panels_mini-sd_filters_group' => array(
          'module' => 'panels_mini',
          'delta' => 'sd_filters_group',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'intel_ea_module-intel_contact_links' => array(
          'module' => 'intel_ea_module',
          'delta' => 'intel_contact_links',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Prerelease Solutions Directory page.');
  t('block');
  $export['prerelease_solutions_directory'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'reports_companies';
  $context->description = '';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'member-resource-center/user' => 'member-resource-center/user',
        'member-resource-center/user/*' => 'member-resource-center/user/*',
        'member-resource-center/site-web-analytics' => 'member-resource-center/site-web-analytics',
        'member-resource-center/site-web-analytics/*' => 'member-resource-center/site-web-analytics/*',
        'node/add' => 'node/add',
        'node/add/*' => 'node/add/*',
        'node/*/*' => 'node/*/*',
        '~node/*/view' => '~node/*/view',
        'member-resource-center/co-marketing/trademarks' => 'member-resource-center/co-marketing/trademarks',
        'member-resource-center/co-marketing/trademarks/*' => 'member-resource-center/co-marketing/trademarks/*',
        'member-resource-center/embedded-innovator-article-opportunities' => 'member-resource-center/embedded-innovator-article-opportunities',
        'member-resource-center/embedded-innovator-article-opportunities/*' => 'member-resource-center/embedded-innovator-article-opportunities/*',
        'member-resource-center/supports-intel-atom-locked-logo' => 'member-resource-center/supports-intel-atom-locked-logo',
        'member-resource-center/supports-intel-atom-locked-logo/*' => 'member-resource-center/supports-intel-atom-locked-logo/*',
        'member-resource-center/intel-brand-advantage-program' => 'member-resource-center/intel-brand-advantage-program',
        'member-resource-center/intel-brand-advantage-program/*' => 'member-resource-center/intel-brand-advantage-program/*',
        'member-resource-center/business-connections' => 'member-resource-center/business-connections',
        'member-resource-center/business-connections/*' => 'member-resource-center/business-connections/*',
        'member-resource-center/events' => 'member-resource-center/events',
        'member-resource-center/events/*' => 'member-resource-center/events/*',
        'member-resource-center/reports' => 'member-resource-center/reports',
        'member-resource-center/reports/*' => 'member-resource-center/reports/*',
        'member-resource-center/alliance-marketing-por' => 'member-resource-center/alliance-marketing-por',
        'member-resource-center/alliance-marketing-por/*' => 'member-resource-center/alliance-marketing-por/*',
        'member-resource-center/manage-users' => 'member-resource-center/manage-users',
        'member-resource-center/manage-users/*' => 'member-resource-center/manage-users/*',
        'member-resource-center/launch-kits' => 'member-resource-center/launch-kits',
        'member-resource-center/launch-kits/*' => 'member-resource-center/launch-kits/*',
        'member-resource-center/benefits-expectations' => 'member-resource-center/benefits-expectations',
        'member-resource-center/benefits-expectations/*' => 'member-resource-center/benefits-expectations/*',
        'member-resource-center/participation-criteria' => 'member-resource-center/participation-criteria',
        'member-resource-center/participation-criteria/*' => 'member-resource-center/participation-criteria/*',
        'member-resource-center/business-overview' => 'member-resource-center/business-overview',
        'member-resource-center/business-overview/*' => 'member-resource-center/business-overview/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-help' => array(
          'module' => 'system',
          'delta' => 'help',
          'region' => 'content',
          'weight' => '-10',
        ),
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
        'masquerade-masquerade' => array(
          'module' => 'masquerade',
          'delta' => 'masquerade',
          'region' => 'content',
          'weight' => '-8',
        ),
        'intel_theme-sidebar_title_block' => array(
          'module' => 'intel_theme',
          'delta' => 'sidebar_title_block',
          'region' => 'sidebar_first',
          'weight' => '-10',
        ),
        'views-a4d368b58db956208626a0bb0c90ed69' => array(
          'module' => 'views',
          'delta' => 'a4d368b58db956208626a0bb0c90ed69',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'views-current_user-block_1' => array(
          'module' => 'views',
          'delta' => 'current_user-block_1',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
        'intel_ea_module-mrc_program_contacts' => array(
          'module' => 'intel_ea_module',
          'delta' => 'mrc_program_contacts',
          'region' => 'sidebar_first',
          'weight' => '-7',
        ),
        'views-current_user-primary_contact' => array(
          'module' => 'views',
          'delta' => 'current_user-primary_contact',
          'region' => 'sidebar_first',
          'weight' => '-6',
        ),
        'menu-menu-administration' => array(
          'module' => 'menu',
          'delta' => 'menu-administration',
          'region' => 'sidebar_first',
          'weight' => '-5',
        ),
        'menu-menu-reports' => array(
          'module' => 'menu',
          'delta' => 'menu-reports',
          'region' => 'sidebar_first',
          'weight' => '-4',
        ),
        'intel_ea_module-mrc_membership' => array(
          'module' => 'intel_ea_module',
          'delta' => 'mrc_membership',
          'region' => 'sidebar_first',
          'weight' => '-3',
        ),
        'intel_ea_module-mrc_help_links' => array(
          'module' => 'intel_ea_module',
          'delta' => 'mrc_help_links',
          'region' => 'sidebar_first',
          'weight' => '-2',
        ),
        'lang_dropdown-language' => array(
          'module' => 'lang_dropdown',
          'delta' => 'language',
          'region' => 'preface_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('block');
  $export['reports_companies'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'solution';
  $context->description = 'Control the placement of blocks on a Solution page.';
  $context->tag = 'block';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'formula' => 'formula',
        'solution' => 'solution',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'delta_blocks-page-title' => array(
          'module' => 'delta_blocks',
          'delta' => 'page-title',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on a Solution page.');
  t('block');
  $export['solution'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'solutions_directory';
  $context->description = 'Control the placement of blocks on the Solutions Directory page.';
  $context->tag = 'block';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'solutions-directory' => 'solutions-directory',
        'solutions-directory/*/*' => 'solutions-directory/*/*',
      ),
    ),
    'user' => array(
      'values' => array(
        'Alliance Marketing Expert' => 'Alliance Marketing Expert',
        'Co-Marketing (MDF) Contact' => 'Co-Marketing (MDF) Contact',
        'Co-Marketing Affiliate' => 'Co-Marketing Affiliate',
        'Co-Marketing Associate' => 'Co-Marketing Associate',
        'Co-Marketing General' => 'Co-Marketing General',
        'Co-Marketing Premier' => 'Co-Marketing Premier',
        'Executive' => 'Executive',
        'Leads Contact' => 'Leads Contact',
        'Primary Admin Contact' => 'Primary Admin Contact',
        'Primary Co-Marketing (MDF) Contact' => 'Primary Co-Marketing (MDF) Contact',
        'Primary Contact' => 'Primary Contact',
        'Primary Leads Contact' => 'Primary Leads Contact',
        'Primary Marketing Contact' => 'Primary Marketing Contact',
        'Primary Sales Contact' => 'Primary Sales Contact',
        'Solutions Directory Editor' => 'Solutions Directory Editor',
        'anonymous user' => 'anonymous user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'panels_mini-sd_filters_group' => array(
          'module' => 'panels_mini',
          'delta' => 'sd_filters_group',
          'region' => 'sidebar_first',
          'weight' => '-9',
        ),
        'intel_ea_module-intel_contact_links' => array(
          'module' => 'intel_ea_module',
          'delta' => 'intel_contact_links',
          'region' => 'sidebar_first',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Control the placement of blocks on the Solutions Directory page.');
  t('block');
  $export['solutions_directory'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'user_login';
  $context->description = 'Block on the Login page.';
  $context->tag = '';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'member-resource-center/login' => 'member-resource-center/login',
        'member-resource-center/user' => 'member-resource-center/user',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'block-9' => array(
          'module' => 'block',
          'delta' => '8',
          'region' => 'postscript_first',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Block on the Login page.');
  $export['user_login'] = $context;

  return $export;
}
