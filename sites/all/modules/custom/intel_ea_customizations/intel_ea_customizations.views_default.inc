<?php
/**
 * Implements hook_views_default_views().
 */
function intel_ea_customizations_views_default_views() {
 
// exported view goes here
$view = new view();
$view->name = 'member_roster_print_all';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'member roster print all';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'Member Roster Print';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'perm';
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '50';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'view_node' => 'view_node',
  'php' => 'php',
  'title' => 'title',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'view_node' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);

/* Display: Print Companies */
$handler = $view->new_display('page', 'Print Companies', 'page_2');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['path'] = 'member-roster-print';
$handler->display->display_options['menu']['type'] = 'normal';
$handler->display->display_options['menu']['title'] = 'Print Member Roster';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['name'] = 'management';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: All Companies */
$handler = $view->new_display('page', 'All Companies', 'page');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
$handler->display->display_options['path'] = 'member-roster-print/all';
$handler->display->display_options['menu']['type'] = 'default tab';
$handler->display->display_options['menu']['title'] = 'All';
$handler->display->display_options['menu']['weight'] = '0';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;
$handler->display->display_options['tab_options']['title'] = 'All';
$handler->display->display_options['tab_options']['weight'] = '0';

/* Display: Premier Companies */
$handler = $view->new_display('page', 'Premier Companies', 'page_3');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1324 => '1324',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator_id'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['label'] = 'Membership Tier (field_membership_tier)';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['identifier'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/premier';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Alliance Premier';
$handler->display->display_options['menu']['weight'] = '1';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Associate Companies */
$handler = $view->new_display('page', 'Associate Companies', 'page_4');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1325 => '1325',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator_id'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['label'] = 'Membership Tier (field_membership_tier)';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['identifier'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/associate';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Alliance Associate';
$handler->display->display_options['menu']['weight'] = '2';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Affiliate Companies */
$handler = $view->new_display('page', 'Affiliate Companies', 'page_1');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1326 => '1326',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator_id'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['label'] = 'Membership Tier (field_membership_tier)';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['identifier'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/affiliate';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Alliance Affiliate';
$handler->display->display_options['menu']['weight'] = '3';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: General Companies */
$handler = $view->new_display('page', 'General Companies', 'page_5');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1327 => '1327',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator_id'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['label'] = 'Membership Tier (field_membership_tier)';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['identifier'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/general';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'Alliance General';
$handler->display->display_options['menu']['weight'] = '4';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Platinum Companies */
$handler = $view->new_display('page', 'Platinum Companies', 'page_6');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1328 => '1328',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator_id'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['label'] = 'Membership Tier (field_membership_tier)';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['identifier'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/platinum';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'ITP Platinum';
$handler->display->display_options['menu']['weight'] = '5';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Gold Companies */
$handler = $view->new_display('page', 'Gold Companies', 'page_7');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['path']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['path']['alter']['target'] = '_blank';
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['field_membership_tier']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1329 => '1329',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator_id'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['label'] = 'Membership Tier (field_membership_tier)';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['identifier'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/gold';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'ITP Gold';
$handler->display->display_options['menu']['weight'] = '5';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Registered Companies */
$handler = $view->new_display('page', 'Registered Companies', 'page_8');
$handler->display->display_options['defaults']['style_plugin'] = FALSE;
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'path' => 'path',
  'title' => 'title',
  'php' => 'php',
  'field_membership_tier' => 'field_membership_tier',
);
$handler->display->display_options['style_options']['default'] = 'title';
$handler->display->display_options['style_options']['info'] = array(
  'path' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'php' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'field_membership_tier' => array(
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
$handler->display->display_options['defaults']['style_options'] = FALSE;
$handler->display->display_options['defaults']['row_plugin'] = FALSE;
$handler->display->display_options['defaults']['row_options'] = FALSE;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Path */
$handler->display->display_options['fields']['path']['id'] = 'path';
$handler->display->display_options['fields']['path']['table'] = 'node';
$handler->display->display_options['fields']['path']['field'] = 'path';
$handler->display->display_options['fields']['path']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['title']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[path]';
$handler->display->display_options['fields']['php']['alter']['target'] = '_blank';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Partner Name';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1330 => '1330',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator_id'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['label'] = 'Membership Tier (field_membership_tier)';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['operator'] = 'field_membership_tier_tid_op';
$handler->display->display_options['filters']['field_membership_tier_tid']['expose']['identifier'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/registered';
$handler->display->display_options['menu']['type'] = 'tab';
$handler->display->display_options['menu']['title'] = 'ITP Registered';
$handler->display->display_options['menu']['weight'] = '7';
$handler->display->display_options['menu']['context'] = 0;
$handler->display->display_options['menu']['context_only_inline'] = 0;

/* Display: Data export All */
$handler = $view->new_display('views_data_export', 'Data export All', 'views_data_export_1');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['path'] = 'print-member-roster/xls-all';
$handler->display->display_options['displays'] = array(
  'page_2' => 'page_2',
  'page' => 'page',
  'default' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: Data export Premier */
$handler = $view->new_display('views_data_export', 'Data export Premier', 'views_data_export_2');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1324 => '1324',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['path'] = 'print-member-roster/xls-premier';
$handler->display->display_options['displays'] = array(
  'page_3' => 'page_3',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: Data export Associate */
$handler = $view->new_display('views_data_export', 'Data export Associate', 'views_data_export_3');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1325 => '1325',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['path'] = 'print-member-roster/xls-associate';
$handler->display->display_options['displays'] = array(
  'page_4' => 'page_4',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: Data export Affiliate */
$handler = $view->new_display('views_data_export', 'Data export Affiliate', 'views_data_export_4');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1326 => '1326',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['path'] = 'print-member-roster/xls-affiliate';
$handler->display->display_options['displays'] = array(
  'page_1' => 'page_1',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: Data export General */
$handler = $view->new_display('views_data_export', 'Data export General', 'views_data_export_5');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1327 => '1327',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['path'] = 'print-member-roster/xls-general';
$handler->display->display_options['displays'] = array(
  'page_5' => 'page_5',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: Data export Platinum */
$handler = $view->new_display('views_data_export', 'Data export Platinum', 'views_data_export_6');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1328 => '1328',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['path'] = 'print-member-roster/xls-platinum';
$handler->display->display_options['displays'] = array(
  'page_6' => 'page_6',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: Data export Gold */
$handler = $view->new_display('views_data_export', 'Data export Gold', 'views_data_export_7');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1329 => '1329',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['path'] = 'print-member-roster/xls-gold';
$handler->display->display_options['displays'] = array(
  'page_7' => 'page_7',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_8' => 0,
);

/* Display: Data export Registered */
$handler = $view->new_display('views_data_export', 'Data export Registered', 'views_data_export_8');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'views_data_export_xls';
$handler->display->display_options['style_options']['provide_file'] = 1;
$handler->display->display_options['style_options']['parent_sort'] = 0;
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'Number of Entries';
$handler->display->display_options['fields']['php']['alter']['make_link'] = TRUE;
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1330 => '1330',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['path'] = 'print-member-roster/xls-registered';
$handler->display->display_options['displays'] = array(
  'page_8' => 'page_8',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
);

/* Display: PDF All */
$handler = $view->new_display('pdf', 'PDF All', 'pdf_1');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'pdf_table';
$handler->display->display_options['style_options']['info'] = array(
  'field_membership_tier' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '',
    ),
  ),
);
$handler->display->display_options['style_options']['position'] = array(
  'last_writing_position' => 1,
  'x' => '',
  'y' => '',
  'width' => '',
  'row_height' => '',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'No of Entries';
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['label'] = '';
$handler->display->display_options['fields']['field_membership_tier']['element_label_colon'] = FALSE;
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['path'] = 'member-roster-print/pdf-all';
$handler->display->display_options['displays'] = array(
  'page_2' => 'page_2',
  'page' => 'page',
  'default' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: PDF Premier */
$handler = $view->new_display('pdf', 'PDF Premier', 'pdf_2');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'pdf_table';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '60px',
    ),
  ),
  'php' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '80px',
    ),
  ),
  'field_membership_tier' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '100px',
    ),
  ),
);
$handler->display->display_options['style_options']['position'] = array(
  'last_writing_position' => 1,
  'x' => '',
  'y' => '',
  'width' => '',
  'row_height' => '',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'No of Entries';
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1324 => '1324',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/pdf-premier';
$handler->display->display_options['displays'] = array(
  'page_3' => 'page_3',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: PDF Associate */
$handler = $view->new_display('pdf', 'PDF Associate', 'pdf_3');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'pdf_table';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '60px',
    ),
  ),
  'php' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '80px',
    ),
  ),
  'field_membership_tier' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '100px',
    ),
  ),
);
$handler->display->display_options['style_options']['position'] = array(
  'last_writing_position' => 1,
  'x' => '',
  'y' => '',
  'width' => '',
  'row_height' => '',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'No of Entries';
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1325 => '1325',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/pdf-associate';
$handler->display->display_options['displays'] = array(
  'page_4' => 'page_4',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: PDF Affiliate */
$handler = $view->new_display('pdf', 'PDF Affiliate', 'pdf_4');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'pdf_table';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '60px',
    ),
  ),
  'php' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '80px',
    ),
  ),
  'field_membership_tier' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '100px',
    ),
  ),
);
$handler->display->display_options['style_options']['position'] = array(
  'last_writing_position' => 1,
  'x' => '',
  'y' => '',
  'width' => '',
  'row_height' => '',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'No of Entries';
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1326 => '1326',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/pdf-affiliate';
$handler->display->display_options['displays'] = array(
  'page_1' => 'page_1',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: PDF General */
$handler = $view->new_display('pdf', 'PDF General', 'pdf_5');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'pdf_table';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '60px',
    ),
  ),
  'php' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '80px',
    ),
  ),
  'field_membership_tier' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '100px',
    ),
  ),
);
$handler->display->display_options['style_options']['position'] = array(
  'last_writing_position' => 1,
  'x' => '',
  'y' => '',
  'width' => '',
  'row_height' => '',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'No of Entries';
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1327 => '1327',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/pdf-general';
$handler->display->display_options['displays'] = array(
  'page_5' => 'page_5',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_6' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: PDF Platinum */
$handler = $view->new_display('pdf', 'PDF Platinum', 'pdf_6');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'pdf_table';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '60px',
    ),
  ),
  'php' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '80px',
    ),
  ),
  'field_membership_tier' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '100px',
    ),
  ),
);
$handler->display->display_options['style_options']['position'] = array(
  'last_writing_position' => 1,
  'x' => '',
  'y' => '',
  'width' => '',
  'row_height' => '',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'No of Entries';
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1328 => '1328',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/pdf-platinum';
$handler->display->display_options['displays'] = array(
  'page_6' => 'page_6',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_7' => 0,
  'page_8' => 0,
);

/* Display: PDF Gold */
$handler = $view->new_display('pdf', 'PDF Gold', 'pdf_7');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'pdf_table';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '60px',
    ),
  ),
  'php' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '80px',
    ),
  ),
  'field_membership_tier' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '100px',
    ),
  ),
);
$handler->display->display_options['style_options']['position'] = array(
  'last_writing_position' => 1,
  'x' => '',
  'y' => '',
  'width' => '',
  'row_height' => '',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'No of Entries';
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1329 => '1329',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/pdf-gold';
$handler->display->display_options['displays'] = array(
  'page_7' => 'page_7',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_8' => 0,
);

/* Display: PDF Registered */
$handler = $view->new_display('pdf', 'PDF Registered', 'pdf_8');
$handler->display->display_options['pager']['type'] = 'none';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['style_plugin'] = 'pdf_table';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '60px',
    ),
  ),
  'php' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '80px',
    ),
  ),
  'field_membership_tier' => array(
    'header_style' => array(
      'text' => array(
        'font_size' => '18px',
        'font_family' => 'courier',
        'font_style' => array(
          'b' => 'b',
          'u' => 'u',
          'i' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'body_style' => array(
      'text' => array(
        'font_size' => '',
        'font_family' => 'default',
        'font_style' => array(
          'b' => 0,
          'i' => 0,
          'u' => 0,
          'd' => 0,
          'o' => 0,
        ),
        'align' => NULL,
        'hyphenate' => NULL,
        'color' => '',
      ),
      'render' => array(
        'is_html' => 1,
      ),
    ),
    'position' => array(
      'width' => '100px',
    ),
  ),
);
$handler->display->display_options['style_options']['position'] = array(
  'last_writing_position' => 1,
  'x' => '',
  'y' => '',
  'width' => '',
  'row_height' => '',
);
$handler->display->display_options['defaults']['fields'] = FALSE;
/* Field: Content: Link */
$handler->display->display_options['fields']['view_node']['id'] = 'view_node';
$handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
$handler->display->display_options['fields']['view_node']['field'] = 'view_node';
$handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Partner Name';
$handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
/* Field: Global: PHP */
$handler->display->display_options['fields']['php']['id'] = 'php';
$handler->display->display_options['fields']['php']['table'] = 'views';
$handler->display->display_options['fields']['php']['field'] = 'php';
$handler->display->display_options['fields']['php']['label'] = 'No of Entries';
$handler->display->display_options['fields']['php']['alter']['path'] = '[view_node]';
$handler->display->display_options['fields']['php']['empty'] = '0';
$handler->display->display_options['fields']['php']['use_php_setup'] = 0;
$handler->display->display_options['fields']['php']['php_output'] = '<?php print get_partner_products_count($data->nid) ?>';
$handler->display->display_options['fields']['php']['use_php_click_sortable'] = '1';
$handler->display->display_options['fields']['php']['php_click_sortable'] = '';
/* Field: Content: Membership Tier */
$handler->display->display_options['fields']['field_membership_tier']['id'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['field'] = 'field_membership_tier';
$handler->display->display_options['fields']['field_membership_tier']['type'] = 'taxonomy_term_reference_plain';
$handler->display->display_options['fields']['field_membership_tier']['delta_offset'] = '0';
$handler->display->display_options['defaults']['sorts'] = FALSE;
/* Sort criterion: Content: Title */
$handler->display->display_options['sorts']['title']['id'] = 'title';
$handler->display->display_options['sorts']['title']['table'] = 'node';
$handler->display->display_options['sorts']['title']['field'] = 'title';
$handler->display->display_options['defaults']['filter_groups'] = FALSE;
$handler->display->display_options['defaults']['filters'] = FALSE;
/* Filter criterion: Content: Published */
$handler->display->display_options['filters']['status']['id'] = 'status';
$handler->display->display_options['filters']['status']['table'] = 'node';
$handler->display->display_options['filters']['status']['field'] = 'status';
$handler->display->display_options['filters']['status']['value'] = 1;
$handler->display->display_options['filters']['status']['group'] = 1;
$handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'word';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;
/* Filter criterion: Content: Language */
$handler->display->display_options['filters']['language']['id'] = 'language';
$handler->display->display_options['filters']['language']['table'] = 'node';
$handler->display->display_options['filters']['language']['field'] = 'language';
$handler->display->display_options['filters']['language']['value'] = array(
  'en' => 'en',
);
/* Filter criterion: Content: Membership Tier (field_membership_tier) */
$handler->display->display_options['filters']['field_membership_tier_tid']['id'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['table'] = 'field_data_field_membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['field'] = 'field_membership_tier_tid';
$handler->display->display_options['filters']['field_membership_tier_tid']['value'] = array(
  1330 => '1330',
);
$handler->display->display_options['filters']['field_membership_tier_tid']['type'] = 'select';
$handler->display->display_options['filters']['field_membership_tier_tid']['vocabulary'] = 'membership_tier';
$handler->display->display_options['filters']['field_membership_tier_tid']['hierarchy'] = 1;
$handler->display->display_options['path'] = 'member-roster-print/pdf-registered';
$handler->display->display_options['displays'] = array(
  'page_8' => 'page_8',
  'default' => 0,
  'page_2' => 0,
  'page' => 0,
  'page_3' => 0,
  'page_4' => 0,
  'page_1' => 0,
  'page_5' => 0,
  'page_6' => 0,
  'page_7' => 0,
);


 $views[$view->name] = $view;
 
 // companies list view for intel admin.
 
 $view = new view();
$view->name = 'companies_list';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'node';
$view->human_name = 'companies list';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'companies list';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  21 => '21',
  9 => '9',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '100';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'title' => 'title',
  'created' => 'created',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'title' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: Content: Title */
$handler->display->display_options['fields']['title']['id'] = 'title';
$handler->display->display_options['fields']['title']['table'] = 'node';
$handler->display->display_options['fields']['title']['field'] = 'title';
$handler->display->display_options['fields']['title']['label'] = 'Company Title';
$handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
/* Field: Content: Post date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'node';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Created date in Solutions Directory';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
/* Sort criterion: Content: Post date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'node';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: Content: Type */
$handler->display->display_options['filters']['type']['id'] = 'type';
$handler->display->display_options['filters']['type']['table'] = 'node';
$handler->display->display_options['filters']['type']['field'] = 'type';
$handler->display->display_options['filters']['type']['value'] = array(
  'company' => 'company',
);
/* Filter criterion: Content: Title */
$handler->display->display_options['filters']['title']['id'] = 'title';
$handler->display->display_options['filters']['title']['table'] = 'node';
$handler->display->display_options['filters']['title']['field'] = 'title';
$handler->display->display_options['filters']['title']['operator'] = 'contains';
$handler->display->display_options['filters']['title']['exposed'] = TRUE;
$handler->display->display_options['filters']['title']['expose']['operator_id'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['label'] = 'Title';
$handler->display->display_options['filters']['title']['expose']['operator'] = 'title_op';
$handler->display->display_options['filters']['title']['expose']['identifier'] = 'title';
$handler->display->display_options['filters']['title']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
  33 => 0,
  34 => 0,
  35 => 0,
  36 => 0,
  37 => 0,
);
$handler->display->display_options['filters']['title']['expose']['autocomplete_filter'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_items'] = '10';
$handler->display->display_options['filters']['title']['expose']['autocomplete_min_chars'] = '0';
$handler->display->display_options['filters']['title']['expose']['autocomplete_field'] = 'title';
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_suggestion'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_raw_dropdown'] = 1;
$handler->display->display_options['filters']['title']['expose']['autocomplete_dependent'] = 0;

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'companies-list';

 $views[$view->name] = $view;
 
 // Views to generate user data for intel admin.
 
 $view = new view();
$view->name = 'user_list_for_inteladmin_role';
$view->description = '';
$view->tag = 'default';
$view->base_table = 'users';
$view->human_name = 'user list for inteladmin';
$view->core = 7;
$view->api_version = '3.0';
$view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

/* Display: Master */
$handler = $view->new_display('default', 'Master', 'default');
$handler->display->display_options['title'] = 'user list';
$handler->display->display_options['use_more_always'] = FALSE;
$handler->display->display_options['access']['type'] = 'role';
$handler->display->display_options['access']['role'] = array(
  21 => '21',
  9 => '9',
);
$handler->display->display_options['cache']['type'] = 'none';
$handler->display->display_options['query']['type'] = 'views_query';
$handler->display->display_options['exposed_form']['type'] = 'basic';
$handler->display->display_options['pager']['type'] = 'full';
$handler->display->display_options['pager']['options']['items_per_page'] = '100';
$handler->display->display_options['pager']['options']['offset'] = '0';
$handler->display->display_options['pager']['options']['id'] = '0';
$handler->display->display_options['pager']['options']['quantity'] = '9';
$handler->display->display_options['style_plugin'] = 'table';
$handler->display->display_options['style_options']['columns'] = array(
  'name' => 'name',
  'mail' => 'mail',
  'created' => 'created',
);
$handler->display->display_options['style_options']['default'] = '-1';
$handler->display->display_options['style_options']['info'] = array(
  'name' => array(
    'sortable' => 1,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'mail' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
  'created' => array(
    'sortable' => 0,
    'default_sort_order' => 'asc',
    'align' => '',
    'separator' => '',
    'empty_column' => 0,
  ),
);
/* Field: User: Name */
$handler->display->display_options['fields']['name']['id'] = 'name';
$handler->display->display_options['fields']['name']['table'] = 'users';
$handler->display->display_options['fields']['name']['field'] = 'name';
$handler->display->display_options['fields']['name']['label'] = 'User name';
$handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
$handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
/* Field: User: E-mail */
$handler->display->display_options['fields']['mail']['id'] = 'mail';
$handler->display->display_options['fields']['mail']['table'] = 'users';
$handler->display->display_options['fields']['mail']['field'] = 'mail';
$handler->display->display_options['fields']['mail']['link_to_user'] = '0';
/* Field: User: Created date */
$handler->display->display_options['fields']['created']['id'] = 'created';
$handler->display->display_options['fields']['created']['table'] = 'users';
$handler->display->display_options['fields']['created']['field'] = 'created';
$handler->display->display_options['fields']['created']['label'] = 'Created date in Solutions Directory';
$handler->display->display_options['fields']['created']['date_format'] = 'short';
$handler->display->display_options['fields']['created']['second_date_format'] = 'privatemsg_current_day';
/* Sort criterion: User: Created date */
$handler->display->display_options['sorts']['created']['id'] = 'created';
$handler->display->display_options['sorts']['created']['table'] = 'users';
$handler->display->display_options['sorts']['created']['field'] = 'created';
$handler->display->display_options['sorts']['created']['order'] = 'DESC';
/* Filter criterion: User: Name */
$handler->display->display_options['filters']['uid']['id'] = 'uid';
$handler->display->display_options['filters']['uid']['table'] = 'users';
$handler->display->display_options['filters']['uid']['field'] = 'uid';
$handler->display->display_options['filters']['uid']['value'] = '';
$handler->display->display_options['filters']['uid']['exposed'] = TRUE;
$handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['label'] = 'User Name';
$handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
$handler->display->display_options['filters']['uid']['expose']['identifier'] = 'uid';
$handler->display->display_options['filters']['uid']['expose']['remember_roles'] = array(
  2 => '2',
  1 => 0,
  3 => 0,
  4 => 0,
  8 => 0,
  9 => 0,
  10 => 0,
  11 => 0,
  12 => 0,
  13 => 0,
  28 => 0,
  14 => 0,
  15 => 0,
  5 => 0,
  16 => 0,
  6 => 0,
  27 => 0,
  25 => 0,
  24 => 0,
  26 => 0,
  29 => 0,
  17 => 0,
  18 => 0,
  19 => 0,
  20 => 0,
  21 => 0,
  30 => 0,
  31 => 0,
  32 => 0,
  33 => 0,
  34 => 0,
  35 => 0,
  36 => 0,
  37 => 0,
);

/* Display: Page */
$handler = $view->new_display('page', 'Page', 'page');
$handler->display->display_options['path'] = 'user-created-list';

 $views[$view->name] = $view;
// return views
  return $views;
}
