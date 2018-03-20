<?php
/**
 * @file
 * intel_ea_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function intel_ea_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_views_node_custom';
  $view->description = 'Find and manage content.';
  $view->tag = 'admin';
  $view->base_table = 'node';
  $view->human_name = 'Administration: Nodes (custom)';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Content';
  $handler->display->display_options['css_class'] = 'admin-views-view';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'menu';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = 50;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'views_bulk_operations' => 'views_bulk_operations',
    'title' => 'title',
    'timestamp' => 'title',
    'type' => 'type',
    'name' => 'name',
    'status' => 'status',
    'changed' => 'changed',
    'edit_node' => 'edit_node',
    'delete_node' => 'edit_node',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'views_bulk_operations' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '&nbsp;',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '&emsp;',
      'empty_column' => 0,
    ),
    'delete_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'No content available.';
  /* Relationship: Content: Author */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Relationship: Content: Taxonomy terms on node */
  $handler->display->display_options['relationships']['term_node_tid']['id'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['table'] = 'node';
  $handler->display->display_options['relationships']['term_node_tid']['field'] = 'term_node_tid';
  $handler->display->display_options['relationships']['term_node_tid']['vocabularies'] = array(
    'forums' => 0,
    'tags' => 0,
  );
  /* Field: Bulk operations: Content */
  $handler->display->display_options['fields']['views_bulk_operations']['id'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['table'] = 'node';
  $handler->display->display_options['fields']['views_bulk_operations']['field'] = 'views_bulk_operations';
  $handler->display->display_options['fields']['views_bulk_operations']['label'] = '';
  $handler->display->display_options['fields']['views_bulk_operations']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['display_type'] = '0';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['enable_select_all_pages'] = 1;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['force_single'] = 0;
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_settings']['entity_load_capacity'] = '10';
  $handler->display->display_options['fields']['views_bulk_operations']['vbo_operations'] = array(
    'action::node_assign_owner_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change author',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_delete_item' => array(
      'selected' => 1,
      'skip_confirmation' => 0,
      'override_label' => 1,
      'label' => 'Delete',
      'postpone_processing' => 0,
    ),
    'action::views_bulk_operations_modify_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Change value',
      'settings' => array(
        'show_all_tokens' => 1,
        'display_values' => array(
          '_all_' => '_all_',
        ),
      ),
      'postpone_processing' => 0,
    ),
    'action::node_make_sticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Stick',
      'postpone_processing' => 0,
    ),
    'action::node_make_unsticky_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unstick',
      'postpone_processing' => 0,
    ),
    'action::node_promote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Promote to front page',
      'postpone_processing' => 0,
    ),
    'action::node_publish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Publish',
      'postpone_processing' => 0,
    ),
    'action::node_unpromote_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Demote from front page',
      'postpone_processing' => 0,
    ),
    'action::node_unpublish_action' => array(
      'selected' => 1,
      'skip_confirmation' => 1,
      'override_label' => 1,
      'label' => 'Unpublish',
      'postpone_processing' => 0,
    ),
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: Content: Has new content */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'history';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Author';
  $handler->display->display_options['fields']['name']['hide_alter_empty'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Updated';
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Operations';
  /* Field: Content: Delete link */
  $handler->display->display_options['fields']['delete_node']['id'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['delete_node']['field'] = 'delete_node';
  $handler->display->display_options['fields']['delete_node']['label'] = '';
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
  $handler->display->display_options['filters']['title']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['remember'] = TRUE;
  /* Filter criterion: User: Name */
  $handler->display->display_options['filters']['uid']['id'] = 'uid';
  $handler->display->display_options['filters']['uid']['table'] = 'users';
  $handler->display->display_options['filters']['uid']['field'] = 'uid';
  $handler->display->display_options['filters']['uid']['relationship'] = 'uid';
  $handler->display->display_options['filters']['uid']['value'] = '';
  $handler->display->display_options['filters']['uid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['uid']['expose']['operator_id'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['label'] = 'Author';
  $handler->display->display_options['filters']['uid']['expose']['operator'] = 'uid_op';
  $handler->display->display_options['filters']['uid']['expose']['identifier'] = 'author';
  $handler->display->display_options['filters']['uid']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember'] = TRUE;
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['relationship'] = 'term_node_tid';
  $handler->display->display_options['filters']['vid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['vid']['expose']['operator_id'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['label'] = 'Vocabulary';
  $handler->display->display_options['filters']['vid']['expose']['operator'] = 'vid_op';
  $handler->display->display_options['filters']['vid']['expose']['identifier'] = 'vid';
  $handler->display->display_options['filters']['vid']['expose']['remember'] = TRUE;
  /* Filter criterion: Content: Market Segments (field_market_segments) */
  $handler->display->display_options['filters']['field_market_segments_tid']['id'] = 'field_market_segments_tid';
  $handler->display->display_options['filters']['field_market_segments_tid']['table'] = 'field_data_field_market_segments';
  $handler->display->display_options['filters']['field_market_segments_tid']['field'] = 'field_market_segments_tid';
  $handler->display->display_options['filters']['field_market_segments_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_market_segments_tid']['expose']['operator_id'] = 'field_market_segments_tid_op';
  $handler->display->display_options['filters']['field_market_segments_tid']['expose']['label'] = 'Market Segments';
  $handler->display->display_options['filters']['field_market_segments_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_market_segments_tid']['expose']['operator'] = 'field_market_segments_tid_op';
  $handler->display->display_options['filters']['field_market_segments_tid']['expose']['identifier'] = 'field_market_segments_tid';
  $handler->display->display_options['filters']['field_market_segments_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_market_segments_tid']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_market_segments_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_market_segments_tid']['vocabulary'] = 'market_segments';
  $handler->display->display_options['filters']['field_market_segments_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_market_segments_tid']['error_message'] = FALSE;
  /* Filter criterion: Content: Processors (field_processors_list) */
  $handler->display->display_options['filters']['field_processors_list_tid']['id'] = 'field_processors_list_tid';
  $handler->display->display_options['filters']['field_processors_list_tid']['table'] = 'field_data_field_processors_list';
  $handler->display->display_options['filters']['field_processors_list_tid']['field'] = 'field_processors_list_tid';
  $handler->display->display_options['filters']['field_processors_list_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_processors_list_tid']['expose']['operator_id'] = 'field_processors_list_tid_op';
  $handler->display->display_options['filters']['field_processors_list_tid']['expose']['label'] = 'Processors';
  $handler->display->display_options['filters']['field_processors_list_tid']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['field_processors_list_tid']['expose']['operator'] = 'field_processors_list_tid_op';
  $handler->display->display_options['filters']['field_processors_list_tid']['expose']['identifier'] = 'field_processors_list_tid';
  $handler->display->display_options['filters']['field_processors_list_tid']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['field_processors_list_tid']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_processors_list_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_processors_list_tid']['vocabulary'] = 'processors';
  $handler->display->display_options['filters']['field_processors_list_tid']['hierarchy'] = 1;
  $handler->display->display_options['filters']['field_processors_list_tid']['error_message'] = FALSE;

  /* Display: System */
  $handler = $view->new_display('system', 'System', 'system_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['hide_admin_links'] = TRUE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['path'] = 'admin/content';
  $translatables['admin_views_node_custom'] = array(
    t('Defaults'),
    t('Content'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No content available.'),
    t('author'),
    t('term'),
    t('- Choose an operation -'),
    t('Change author'),
    t('Delete'),
    t('Change value'),
    t('Stick'),
    t('Unstick'),
    t('Promote to front page'),
    t('Publish'),
    t('Demote from front page'),
    t('Unpublish'),
    t('Title'),
    t('Type'),
    t('Author'),
    t('Published'),
    t('Updated'),
    t('Language'),
    t('Operations'),
    t('Vocabulary'),
    t('Market Segments'),
    t('Processors'),
    t('System'),
  );
  $export['admin_views_node_custom'] = $view;

  $view = new view();
  $view->name = 'broken_links';
  $view->description = 'Display a list of broken links.';
  $view->tag = 'default';
  $view->base_table = 'linkchecker_link';
  $view->human_name = 'Broken links';
  $view->core = 0;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Defaults */
  $handler = $view->new_display('default', 'Defaults', 'default');
  $handler->display->display_options['title'] = 'Broken links';
  $handler->display->display_options['items_per_page'] = 0;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    21 => '21',
    3 => '3',
    9 => '9',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'url' => 'url',
    'code' => 'code',
    'error' => 'error',
    'link_edit' => 'link_edit',
    'nid' => 'nid',
    'edit_node' => 'edit_node',
    'cid' => 'cid',
    'edit_comment' => 'edit_comment',
    'bid' => 'bid',
    'block_edit' => 'block_edit',
    'redirect_add' => 'redirect_add',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = 'url';
  $handler->display->display_options['style_options']['info'] = array(
    'url' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'code' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'error' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_edit' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_node' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'cid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_comment' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'bid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'block_edit' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'redirect_add' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['style_options']['empty_table'] = TRUE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No broken links have been found.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Relationship: Broken links: Content with link */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'linkchecker_node';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['relationship'] = 'nid';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  /* Relationship: Content: Current Membership Type (field_membership_type) */
  $handler->display->display_options['relationships']['field_membership_type_tid']['id'] = 'field_membership_type_tid';
  $handler->display->display_options['relationships']['field_membership_type_tid']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['relationships']['field_membership_type_tid']['field'] = 'field_membership_type_tid';
  $handler->display->display_options['relationships']['field_membership_type_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_membership_type_tid']['label'] = 'Membership Type';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Company';
  /* Field: Content: Current Membership Type */
  $handler->display->display_options['fields']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['relationship'] = 'nid';
  $handler->display->display_options['fields']['field_membership_type']['label'] = 'Membership Type';
  $handler->display->display_options['fields']['field_membership_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_membership_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'field_membership_type_tid';
  $handler->display->display_options['fields']['name']['label'] = 'Membership Type';
  $handler->display->display_options['fields']['name']['empty'] = '[field_membership_type]';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Page';
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['relationship'] = 'nid';
  /* Field: Broken links: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['url']['hide_empty'] = TRUE;
  /* Field: Broken links: HTTP status code */
  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['code']['field'] = 'code';
  $handler->display->display_options['fields']['code']['label'] = 'Response';
  $handler->display->display_options['fields']['code']['separator'] = '';
  /* Field: Broken links: Error message */
  $handler->display->display_options['fields']['error']['id'] = 'error';
  $handler->display->display_options['fields']['error']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['error']['field'] = 'error';
  $handler->display->display_options['fields']['error']['label'] = 'Error';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'nid';
  $handler->display->display_options['fields']['edit_node']['label'] = 'Edit node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['edit_node']['alter']['text'] = '<li>Edit node [nid]</li>';
  $handler->display->display_options['fields']['edit_node']['hide_empty'] = TRUE;
  /* Field: Broken links: Block ID */
  $handler->display->display_options['fields']['bid']['id'] = 'bid';
  $handler->display->display_options['fields']['bid']['table'] = 'linkchecker_block_custom';
  $handler->display->display_options['fields']['bid']['field'] = 'bid';
  $handler->display->display_options['fields']['bid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['bid']['separator'] = '';
  /* Field: Broken links: Edit block */
  $handler->display->display_options['fields']['block_edit']['id'] = 'block_edit';
  $handler->display->display_options['fields']['block_edit']['table'] = 'linkchecker_block_custom';
  $handler->display->display_options['fields']['block_edit']['field'] = 'block_edit';
  $handler->display->display_options['fields']['block_edit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['block_edit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['block_edit']['alter']['text'] = '<li>Edit block [bid]</li>';
  $handler->display->display_options['fields']['block_edit']['hide_empty'] = TRUE;
  /* Field: Broken links: Create redirect */
  $handler->display->display_options['fields']['redirect_add']['id'] = 'redirect_add';
  $handler->display->display_options['fields']['redirect_add']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['redirect_add']['field'] = 'redirect_add';
  $handler->display->display_options['fields']['redirect_add']['exclude'] = TRUE;
  $handler->display->display_options['fields']['redirect_add']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['redirect_add']['alter']['text'] = '<li>Create redirect</li>';
  $handler->display->display_options['fields']['redirect_add']['hide_empty'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>
  [edit_node]
  [block_edit]
  [redirect_add]
</ul>';
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  /* Sort criterion: Broken links: Last checked */
  $handler->display->display_options['sorts']['last_checked']['id'] = 'last_checked';
  $handler->display->display_options['sorts']['last_checked']['table'] = 'linkchecker_link';
  $handler->display->display_options['sorts']['last_checked']['field'] = 'last_checked';
  $handler->display->display_options['sorts']['last_checked']['order'] = 'DESC';
  /* Filter criterion: Broken links: Last checked */
  $handler->display->display_options['filters']['last_checked']['id'] = 'last_checked';
  $handler->display->display_options['filters']['last_checked']['table'] = 'linkchecker_link';
  $handler->display->display_options['filters']['last_checked']['field'] = 'last_checked';
  $handler->display->display_options['filters']['last_checked']['operator'] = '!=';
  $handler->display->display_options['filters']['last_checked']['value']['value'] = '0';
  $handler->display->display_options['filters']['last_checked']['group'] = 1;
  /* Filter criterion: Broken links: Status */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'linkchecker_link';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Field: Company (field_company) */
  $handler->display->display_options['filters']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['filters']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['relationship'] = 'nid';
  $handler->display->display_options['filters']['field_company_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_company_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator_id'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['identifier'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Broken links: HTTP status code */
  $handler->display->display_options['filters']['code']['id'] = 'code';
  $handler->display->display_options['filters']['code']['table'] = 'linkchecker_link';
  $handler->display->display_options['filters']['code']['field'] = 'code';
  $handler->display->display_options['filters']['code']['operator'] = 'not in';
  $handler->display->display_options['filters']['code']['value'] = array(
    200 => '200',
    206 => '206',
    302 => '302',
    304 => '304',
    401 => '401',
    403 => '403',
  );
  $handler->display->display_options['filters']['code']['group'] = 1;
  $handler->display->display_options['filters']['code']['exposed'] = TRUE;
  $handler->display->display_options['filters']['code']['expose']['operator_id'] = 'code_op';
  $handler->display->display_options['filters']['code']['expose']['label'] = 'HTTP status code';
  $handler->display->display_options['filters']['code']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['code']['expose']['operator'] = 'code_op';
  $handler->display->display_options['filters']['code']['expose']['identifier'] = 'code';
  $handler->display->display_options['filters']['code']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['code']['expose']['remember_roles'] = array(
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
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'nid';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'zh-hant' => 'zh-hant',
    'en' => 'en',
    'ja' => 'ja',
    'ko' => 'ko',
    'pt-br' => 'pt-br',
    'ru' => 'ru',
    'es' => 'es',
  );
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;

  /* Display: Broken links */
  $handler = $view->new_display('page', 'Broken links', 'broken_links');
  $handler->display->display_options['display_description'] = 'Shows a list of broken links in content.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'member-resource-center/reports/broken-links';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Broken links';
  $handler->display->display_options['menu']['description'] = 'Shows a list of broken links in content.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'menu-reports';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Broken links export */
  $handler = $view->new_display('views_data_export', 'Broken links export', 'broken_links_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Company';
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title']['label'] = 'Page';
  /* Field: Broken links: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['url']['hide_empty'] = TRUE;
  /* Field: Broken links: HTTP status code */
  $handler->display->display_options['fields']['code']['id'] = 'code';
  $handler->display->display_options['fields']['code']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['code']['field'] = 'code';
  $handler->display->display_options['fields']['code']['label'] = 'Response';
  $handler->display->display_options['fields']['code']['separator'] = '';
  /* Field: Broken links: Error message */
  $handler->display->display_options['fields']['error']['id'] = 'error';
  $handler->display->display_options['fields']['error']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['error']['field'] = 'error';
  $handler->display->display_options['fields']['error']['label'] = 'Error';
  $handler->display->display_options['path'] = 'member-resource-center/reports/broken-links/export';
  $handler->display->display_options['displays'] = array(
    'broken_links' => 'broken_links',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $handler->display->display_options['segment_size'] = '100';
  $translatables['broken_links'] = array(
    t('Defaults'),
    t('Broken links'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No broken links have been found.'),
    t('Node'),
    t('Company'),
    t('Membership Type'),
    t('[field_membership_type]'),
    t('Page'),
    t('Language'),
    t('URL'),
    t('Response'),
    t('.'),
    t('Error'),
    t('Nid'),
    t('Edit node'),
    t('<li>Edit node [nid]</li>'),
    t('Block ID'),
    t('Edit block'),
    t('<li>Edit block [bid]</li>'),
    t('Create redirect'),
    t('<li>Create redirect</li>'),
    t('Operations'),
    t('<ul>
  [edit_node]
  [block_edit]
  [redirect_add]
</ul>'),
    t('HTTP status code'),
    t('Shows a list of broken links in content.'),
    t('Broken links export'),
  );
  $export['broken_links'] = $view;

  $view = new view();
  $view->name = 'companies';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Companies';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content translation: Source translation */
  $handler->display->display_options['filters']['source_translation']['id'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['table'] = 'node';
  $handler->display->display_options['filters']['source_translation']['field'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['operator'] = '1';
  $translatables['companies'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Entity Reference'),
  );
  $export['companies'] = $view;

  $view = new view();
  $view->name = 'company_solutions';
  $view->description = 'Member Roster company solutions listed by category.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Company Solutions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more'] = TRUE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['use_more_text'] = 'View All';
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = '<front>';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '4';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  /* Field: Field: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'field_data_field_image';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => 'segment_product_images_179x135',
    'image_link' => 'content',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['max_length'] = '75';
  $handler->display->display_options['fields']['title']['alter']['trim'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['html'] = TRUE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  /* Field: Content: Company Name */
  $handler->display->display_options['fields']['field_component_company_name']['id'] = 'field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['table'] = 'field_data_field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['field'] = 'field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_component_company_name']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Updated date */
  $handler->display->display_options['sorts']['changed']['id'] = 'changed';
  $handler->display->display_options['sorts']['changed']['table'] = 'node';
  $handler->display->display_options['sorts']['changed']['field'] = 'changed';
  $handler->display->display_options['sorts']['changed']['order'] = 'DESC';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'company' => 'company',
  );
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
    'solution' => 'solution',
  );

  /* Display: Systems */
  $handler = $view->new_display('panel_pane', 'Systems', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Systems';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['link_url'] = '<front>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Categories (field_categories) */
  $handler->display->display_options['filters']['field_categories_tid']['id'] = 'field_categories_tid';
  $handler->display->display_options['filters']['field_categories_tid']['table'] = 'field_data_field_categories';
  $handler->display->display_options['filters']['field_categories_tid']['field'] = 'field_categories_tid';
  $handler->display->display_options['filters']['field_categories_tid']['value'] = array(
    124 => '124',
  );
  $handler->display->display_options['filters']['field_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_categories_tid']['vocabulary'] = 'categories';
  $handler->display->display_options['filters']['field_categories_tid']['hierarchy'] = 1;

  /* Display: Services */
  $handler = $view->new_display('panel_pane', 'Services', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Services';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['link_url'] = '<front>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Categories (field_categories) */
  $handler->display->display_options['filters']['field_categories_tid']['id'] = 'field_categories_tid';
  $handler->display->display_options['filters']['field_categories_tid']['table'] = 'field_data_field_categories';
  $handler->display->display_options['filters']['field_categories_tid']['field'] = 'field_categories_tid';
  $handler->display->display_options['filters']['field_categories_tid']['value'] = array(
    126 => '126',
  );
  $handler->display->display_options['filters']['field_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_categories_tid']['vocabulary'] = 'categories';
  $handler->display->display_options['filters']['field_categories_tid']['hierarchy'] = 1;

  /* Display: Products & Components */
  $handler = $view->new_display('panel_pane', 'Products & Components', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Products & Components';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['link_url'] = '<front>';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Categories (field_categories) */
  $handler->display->display_options['filters']['field_categories_tid']['id'] = 'field_categories_tid';
  $handler->display->display_options['filters']['field_categories_tid']['table'] = 'field_data_field_categories';
  $handler->display->display_options['filters']['field_categories_tid']['field'] = 'field_categories_tid';
  $handler->display->display_options['filters']['field_categories_tid']['value'] = array(
    125 => '125',
  );
  $handler->display->display_options['filters']['field_categories_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_categories_tid']['reduce_duplicates'] = TRUE;
  $handler->display->display_options['filters']['field_categories_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_categories_tid']['vocabulary'] = 'categories';
  $handler->display->display_options['filters']['field_categories_tid']['hierarchy'] = 1;
  $translatables['company_solutions'] = array(
    t('Master'),
    t('View All'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_company'),
    t('All'),
    t('Systems'),
    t('more'),
    t('View panes'),
    t('Services'),
    t('Products & Components'),
  );
  $export['company_solutions'] = $view;

  $view = new view();
  $view->name = 'components';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Components';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
    'solution' => 'solution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
    'solution' => 'solution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content translation: Source translation */
  $handler->display->display_options['filters']['source_translation']['id'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['table'] = 'node';
  $handler->display->display_options['filters']['source_translation']['field'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['operator'] = '1';
  $handler->display->display_options['filters']['source_translation']['group'] = 1;
  $translatables['components'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Entity Reference'),
  );
  $export['components'] = $view;

  $view = new view();
  $view->name = 'current_user';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Current User';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';

  /* Display: Company Info */
  $handler = $view->new_display('panel_pane', 'Company Info', 'company_info');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Current Membership Type */
  $handler->display->display_options['fields']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['field_membership_type']['label'] = '';
  $handler->display->display_options['fields']['field_membership_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_membership_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Welcome [field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'eu_short';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Last Company Update: [changed]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filter criterion: Content: Current Agreement (field_agreement_identifier) */
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['id'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['table'] = 'field_data_field_agreement_identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['field'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['value'] = array(
    779 => '779',
    605 => '605',
    606 => '606',
    611 => '611',
    612 => '612',
    613 => '613',
    614 => '614',
    615 => '615',
    618 => '618',
    623 => '623',
    624 => '624',
    621 => '621',
    622 => '622',
    627 => '627',
    628 => '628',
    631 => '631',
    632 => '632',
    1088 => '1088',
    1089 => '1089',
    633 => '633',
    634 => '634',
    625 => '625',
    626 => '626',
  );
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['vocabulary'] = 'membership_segments';
  /* Filter criterion: Content: Current Membership Type (field_membership_type) */
  $handler->display->display_options['filters']['field_membership_type_tid']['id'] = 'field_membership_type_tid';
  $handler->display->display_options['filters']['field_membership_type_tid']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['filters']['field_membership_type_tid']['field'] = 'field_membership_type_tid';
  $handler->display->display_options['filters']['field_membership_type_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_membership_type_tid']['value'] = array(
    557 => '557',
    558 => '558',
    559 => '559',
    560 => '560',
    556 => '556',
    561 => '561',
    562 => '562',
  );
  $handler->display->display_options['filters']['field_membership_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_membership_type_tid']['vocabulary'] = 'membership_type';
  $handler->display->display_options['filters']['field_membership_type_tid']['hierarchy'] = 1;

  /* Display: Membership Renewal */
  $handler = $view->new_display('panel_pane', 'Membership Renewal', 'membership_renewal');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['inline'] = array(
    'field_agreement_date' => 'field_agreement_date',
  );
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<b>Membership Renewal</b>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  /* Field: Content: Expiration Date of Current Agreement */
  $handler->display->display_options['fields']['field_agreement_date']['id'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['table'] = 'field_data_field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['field'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['field_agreement_date']['label'] = 'Expiration Date';
  $handler->display->display_options['fields']['field_agreement_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_agreement_date']['settings'] = array(
    'format_type' => 'eu_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Current Agreement */
  $handler->display->display_options['fields']['field_agreement_identifier']['id'] = 'field_agreement_identifier';
  $handler->display->display_options['fields']['field_agreement_identifier']['table'] = 'field_data_field_agreement_identifier';
  $handler->display->display_options['fields']['field_agreement_identifier']['field'] = 'field_agreement_identifier';
  $handler->display->display_options['fields']['field_agreement_identifier']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['field_agreement_identifier']['label'] = 'Current Membership';
  $handler->display->display_options['fields']['field_agreement_identifier']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_agreement_identifier']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Content: Current Membership Type (field_membership_type) */
  $handler->display->display_options['filters']['field_membership_type_tid']['id'] = 'field_membership_type_tid';
  $handler->display->display_options['filters']['field_membership_type_tid']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['filters']['field_membership_type_tid']['field'] = 'field_membership_type_tid';
  $handler->display->display_options['filters']['field_membership_type_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_membership_type_tid']['value'] = array(
    557 => '557',
    558 => '558',
    559 => '559',
    560 => '560',
    556 => '556',
    561 => '561',
    562 => '562',
  );
  $handler->display->display_options['filters']['field_membership_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_membership_type_tid']['vocabulary'] = 'membership_type';
  $handler->display->display_options['filters']['field_membership_type_tid']['hierarchy'] = 1;

  /* Display: Intel Account Managers */
  $handler = $view->new_display('block', 'Intel Account Managers', 'intel_account_managers');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel Contact';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_account_managers_target_id']['id'] = 'field_account_managers_target_id';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['table'] = 'field_data_field_account_managers';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['field'] = 'field_account_managers_target_id';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['label'] = 'Intel Account Managers';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_account_managers_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_account_managers_target_id';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_account_managers_target_id';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '[mail]';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="mailto:[mail]">[field_first_name] [field_last_name]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['block_caching'] = '2';

  /* Display: Company Users */
  $handler = $view->new_display('page', 'Company Users', 'company_users');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage Users';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    5 => '5',
    8 => '8',
    9 => '9',
    11 => '11',
    12 => '12',
    13 => '13',
    14 => '14',
    15 => '15',
    16 => '16',
    17 => '17',
    18 => '18',
    19 => '19',
    20 => '20',
  );
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No users match the specified criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg_basic';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_company_user']['id'] = 'reverse_field_company_user';
  $handler->display->display_options['relationships']['reverse_field_company_user']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_company_user']['field'] = 'reverse_field_company_user';
  $handler->display->display_options['relationships']['reverse_field_company_user']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['reverse_field_company_user']['label'] = 'Company Users';
  $handler->display->display_options['relationships']['reverse_field_company_user']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['name']['label'] = 'User';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Work Phone Number */
  $handler->display->display_options['fields']['field_work_phone']['id'] = 'field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['table'] = 'field_data_field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['field'] = 'field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['field_work_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_work_phone']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['mail']['label'] = 'Email';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['login']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['login']['date_format'] = 'eu_short';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_user] [edit_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by company name, first name, last name, username or email address';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'mail' => 'mail',
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'reverse_field_company_user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    'all' => 'all',
    8 => '8',
    14 => '14',
    15 => '15',
    5 => '5',
    16 => '16',
    6 => '6',
    17 => '17',
    18 => '18',
    19 => '19',
    20 => '20',
    21 => '21',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Roles';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['rid']['expose']['reduce'] = TRUE;
  $handler->display->display_options['path'] = 'member-resource-center/manage-users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Users';
  $handler->display->display_options['menu']['weight'] = '-49';
  $handler->display->display_options['menu']['name'] = 'menu-administration';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Company Solutions */
  $handler = $view->new_display('page', 'Company Solutions', 'company_solutions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage Solutions';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No solutions match the specified criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg_basic';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_company_node']['id'] = 'reverse_field_company_node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['field'] = 'reverse_field_company_node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['reverse_field_company_node']['label'] = 'Company Solutions';
  $handler->display->display_options['relationships']['reverse_field_company_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_node] [edit_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['field_end_user_description']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by Name or Description';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_end_user_description' => 'field_end_user_description',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'en' => 'en',
    'ja' => 'ja',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Pre-Release (field_pre_release) */
  $handler->display->display_options['filters']['field_pre_release_value']['id'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['filters']['field_pre_release_value']['field'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['field_pre_release_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pre_release_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator_id'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['label'] = 'Pre-Release';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['identifier'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['path'] = 'member-resource-center/manage-solutions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Solutions';
  $handler->display->display_options['menu']['weight'] = '-46';
  $handler->display->display_options['menu']['name'] = 'menu-administration';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Membership Renewal Button */
  $handler = $view->new_display('attachment', 'Membership Renewal Button', 'membership_renewal_button');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'views-row-membership-renewal-button';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Expiration Date of Current Agreement */
  $handler->display->display_options['fields']['field_agreement_date']['id'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['table'] = 'field_data_field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['field'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['field_agreement_date']['label'] = '';
  $handler->display->display_options['fields']['field_agreement_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_agreement_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agreement_date']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_agreement_date']['settings'] = array(
    'format_type' => 'eu_short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="/member-resource-center/membership-renewal-application" class="white-button">Renew Membership</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Content: Expiration Date of Current Agreement (field_agreement_date) */
  $handler->display->display_options['filters']['field_agreement_date_value_1']['id'] = 'field_agreement_date_value_1';
  $handler->display->display_options['filters']['field_agreement_date_value_1']['table'] = 'field_data_field_agreement_date';
  $handler->display->display_options['filters']['field_agreement_date_value_1']['field'] = 'field_agreement_date_value';
  $handler->display->display_options['filters']['field_agreement_date_value_1']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_agreement_date_value_1']['operator'] = '<';
  $handler->display->display_options['filters']['field_agreement_date_value_1']['group'] = 1;
  $handler->display->display_options['filters']['field_agreement_date_value_1']['default_date'] = 'now +60 days';
  /* Filter criterion: Content: Future Agreement (field_future_membership) */
  $handler->display->display_options['filters']['field_future_membership_tid']['id'] = 'field_future_membership_tid';
  $handler->display->display_options['filters']['field_future_membership_tid']['table'] = 'field_data_field_future_membership';
  $handler->display->display_options['filters']['field_future_membership_tid']['field'] = 'field_future_membership_tid';
  $handler->display->display_options['filters']['field_future_membership_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_future_membership_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_future_membership_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_future_membership_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_future_membership_tid']['vocabulary'] = 'membership_segments';
  /* Filter criterion: Content: Future Membership Type (field_future_membership_type) */
  $handler->display->display_options['filters']['field_future_membership_type_tid']['id'] = 'field_future_membership_type_tid';
  $handler->display->display_options['filters']['field_future_membership_type_tid']['table'] = 'field_data_field_future_membership_type';
  $handler->display->display_options['filters']['field_future_membership_type_tid']['field'] = 'field_future_membership_type_tid';
  $handler->display->display_options['filters']['field_future_membership_type_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_future_membership_type_tid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_future_membership_type_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_future_membership_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_future_membership_type_tid']['vocabulary'] = 'membership_type';
  /* Filter criterion: Content: Expiration Date of Future Agreement (field_future_agreement_date) */
  $handler->display->display_options['filters']['field_future_agreement_date_value']['id'] = 'field_future_agreement_date_value';
  $handler->display->display_options['filters']['field_future_agreement_date_value']['table'] = 'field_data_field_future_agreement_date';
  $handler->display->display_options['filters']['field_future_agreement_date_value']['field'] = 'field_future_agreement_date_value';
  $handler->display->display_options['filters']['field_future_agreement_date_value']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_future_agreement_date_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_future_agreement_date_value']['group'] = 1;
  $handler->display->display_options['displays'] = array(
    'membership_renewal' => 'membership_renewal',
    'default' => 0,
    'company_info' => 0,
    'intel_account_managers' => 0,
    'company_users' => 0,
    'company_solutions' => 0,
  );
  $handler->display->display_options['attachment_position'] = 'after';

  /* Display: Alliance Marketing Expert */
  $handler = $view->new_display('block', 'Alliance Marketing Expert', 'block_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Partner Marketing Contact';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['id'] = 'field_marketing_expert_target_id';
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['table'] = 'field_data_field_marketing_expert';
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['field'] = 'field_marketing_expert_target_id';
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['label'] = 'Alliance Marketing Expert';
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_marketing_expert_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_marketing_expert_target_id';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_marketing_expert_target_id';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '[mail]';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="mailto:[mail]">[field_first_name] [field_last_name]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Content: Current Membership Type (field_membership_type) */
  $handler->display->display_options['filters']['field_membership_type_tid']['id'] = 'field_membership_type_tid';
  $handler->display->display_options['filters']['field_membership_type_tid']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['filters']['field_membership_type_tid']['field'] = 'field_membership_type_tid';
  $handler->display->display_options['filters']['field_membership_type_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_membership_type_tid']['value'] = array(
    557 => '557',
    558 => '558',
    559 => '559',
    1154 => '1154',
  );
  $handler->display->display_options['filters']['field_membership_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_membership_type_tid']['vocabulary'] = 'membership_type';
  $handler->display->display_options['block_caching'] = '2';

  /* Display: Company Formulas */
  $handler = $view->new_display('page', 'Company Formulas', 'page_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage Formulas';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No solutions match the specified criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg_basic';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_company_node']['id'] = 'reverse_field_company_node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['field'] = 'reverse_field_company_node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['reverse_field_company_node']['label'] = 'Company Formulas';
  $handler->display->display_options['relationships']['reverse_field_company_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_node] [edit_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['field_end_user_description']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'formula' => 'formula',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by Name or Description';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_end_user_description' => 'field_end_user_description',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'en' => 'en',
    'ja' => 'ja',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Pre-Release (field_pre_release) */
  $handler->display->display_options['filters']['field_pre_release_value']['id'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['filters']['field_pre_release_value']['field'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['field_pre_release_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pre_release_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator_id'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['label'] = 'Pre-Release';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['identifier'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['path'] = 'member-resource-center/manage-formulas';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Formulas';
  $handler->display->display_options['menu']['weight'] = '-44';
  $handler->display->display_options['menu']['name'] = 'menu-administration';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Company Stories */
  $handler = $view->new_display('page', 'Company Stories', 'company_stories');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Manage Case Studies / Press Releases';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No stories match the specified criteria.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg_basic';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_company_node']['id'] = 'reverse_field_company_node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['field'] = 'reverse_field_company_node';
  $handler->display->display_options['relationships']['reverse_field_company_node']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['reverse_field_company_node']['label'] = 'Company Stories';
  $handler->display->display_options['relationships']['reverse_field_company_node']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_node] [edit_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  $handler->display->display_options['filters']['uid_current']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['type']['value'] = array(
    'story' => 'story',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by Name or Body';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_company_node';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Published';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['path'] = 'member-resource-center/manage-stories';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Manage Case Studies / Press Releases';
  $handler->display->display_options['menu']['weight'] = '-37';
  $handler->display->display_options['menu']['name'] = 'menu-administration';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Primary Contact */
  $handler = $view->new_display('block', 'Primary Contact', 'primary_contact');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Primary Contact';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No primary contact set.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg_basic';
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_account_managers_target_id';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_account_managers_target_id';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['relationship'] = 'field_account_managers_target_id';
  $handler->display->display_options['fields']['mail']['label'] = '';
  $handler->display->display_options['fields']['mail']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['mail']['alter']['text'] = '[mail]';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<a href="mailto:[mail]">[field_first_name] [field_last_name]</a>';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Field: Company (field_company) */
  $handler->display->display_options['arguments']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['arguments']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['arguments']['field_company_target_id']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_company_target_id']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['field_company_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_company_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_company_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['value'] = array(
    17 => '17',
  );
  $handler->display->display_options['block_caching'] = '2';
  $translatables['current_user'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Company'),
    t('Company Info'),
    t('Welcome [field_first_name] [field_last_name]'),
    t('Last Company Update: [changed]'),
    t('View panes'),
    t('Membership Renewal'),
    t('<b>Membership Renewal</b>'),
    t('Expiration Date'),
    t('Current Membership'),
    t('Intel Account Managers'),
    t('Intel Contact'),
    t('[mail]'),
    t('<a href="mailto:[mail]">[field_first_name] [field_last_name]</a>'),
    t('Company Users'),
    t('Manage Users'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('No users match the specified criteria.'),
    t('User'),
    t('Last Name'),
    t('First Name'),
    t('Phone'),
    t('Email'),
    t('Roles'),
    t('Last login'),
    t('Active'),
    t('Link'),
    t('Edit link'),
    t('Operations'),
    t('[view_user] [edit_node]'),
    t('Search'),
    t('Search by company name, first name, last name, username or email address'),
    t('Company Solutions'),
    t('Manage Solutions'),
    t('No solutions match the specified criteria.'),
    t('Title'),
    t('Categories'),
    t('Published'),
    t('Updated date'),
    t('[view_node] [edit_node]'),
    t('Developer Description'),
    t('Business User Description – Optional'),
    t('Search by Name or Description'),
    t('Language'),
    t('Pre-Release'),
    t('State'),
    t('Membership Renewal Button'),
    t('<a href="/member-resource-center/membership-renewal-application" class="white-button">Renew Membership</a>'),
    t('Alliance Marketing Expert'),
    t('Partner Marketing Contact'),
    t('Company Formulas'),
    t('Manage Formulas'),
    t('Company Stories'),
    t('Manage Case Studies / Press Releases'),
    t('No stories match the specified criteria.'),
    t('Search by Name or Body'),
    t('Primary Contact'),
    t('No primary contact set.'),
    t('All'),
  );
  $export['current_user'] = $view;

  $view = new view();
  $view->name = 'current_user_non_alliance';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Current User Non Alliance';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_class'] = 'views-field-title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Welcome [field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['changed']['label'] = '';
  $handler->display->display_options['fields']['changed']['exclude'] = TRUE;
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'eu_short';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Last Company Update: [changed]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Filter criterion: User: Current */
  $handler->display->display_options['filters']['uid_current']['id'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['table'] = 'users';
  $handler->display->display_options['filters']['uid_current']['field'] = 'uid_current';
  $handler->display->display_options['filters']['uid_current']['value'] = '1';
  /* Filter criterion: Content: Current Membership Type (field_membership_type) */
  $handler->display->display_options['filters']['field_membership_type_tid']['id'] = 'field_membership_type_tid';
  $handler->display->display_options['filters']['field_membership_type_tid']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['filters']['field_membership_type_tid']['field'] = 'field_membership_type_tid';
  $handler->display->display_options['filters']['field_membership_type_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_membership_type_tid']['value'] = array(
    1154 => '1154',
  );
  $handler->display->display_options['filters']['field_membership_type_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_membership_type_tid']['vocabulary'] = 'membership_type';
  $handler->display->display_options['filters']['field_membership_type_tid']['hierarchy'] = 1;

  /* Display: NA User Company Info */
  $handler = $view->new_display('panel_pane', 'NA User Company Info', 'non_alliance_company_info');
  $translatables['current_user_non_alliance'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Company'),
    t('Welcome [field_first_name] [field_last_name]'),
    t('Last Company Update: [changed]'),
    t('NA User Company Info'),
    t('View panes'),
  );
  $export['current_user_non_alliance'] = $view;

  $view = new view();
  $view->name = 'feed_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_solutions';
  $view->human_name = 'Feed View';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Solutions Directory Feed';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '<none>';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '7';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = '<none>';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '15, 30, 60, 120, 180';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['style_options']['columns'] = '3';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'solution_list';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = '“No results matched your search.”';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
  $handler->display->display_options['sorts']['created_1']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['created_1']['field'] = 'created';
  $handler->display->display_options['sorts']['created_1']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created_1']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created_1']['expose']['label'] = 'Most recent';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Sort criterion: Company » Current Membership Type: Weight (indexed) */
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['id'] = 'field_company_field_membership_type_weight';
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['field'] = 'field_company_field_membership_type_weight';
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['expose']['label'] = 'Membership Level';
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Indexed Content: Pre-Release */
  $handler->display->display_options['filters']['field_pre_release']['id'] = 'field_pre_release';
  $handler->display->display_options['filters']['field_pre_release']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['field_pre_release']['field'] = 'field_pre_release';
  $handler->display->display_options['filters']['field_pre_release']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Indexed Content: Promoted to frontpage */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '0';
  $handler->display->display_options['filters']['promote']['expose']['operator_id'] = 'promote_op';
  $handler->display->display_options['filters']['promote']['expose']['label'] = 'Promoted to frontpage';
  $handler->display->display_options['filters']['promote']['expose']['operator'] = 'promote_op';
  $handler->display->display_options['filters']['promote']['expose']['identifier'] = 'promote';
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['search_api_views_fulltext']['fields'] = array(
    'title' => 'title',
    'body:value' => 'body:value',
    'field_company:title' => 'field_company:title',
    'field_end_user_description:value' => 'field_end_user_description:value',
  );
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '<none>';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'description' => '',
        'language' => '',
        'category' => '',
        'image' => '',
        'copyright' => '',
        'managingEditor' => '',
        'webMaster' => '',
        'generator' => '',
        'docs' => '',
        'cloud' => '',
        'ttl' => '',
        'skipHours' => '',
        'skipDays' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['item'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'title',
        'link' => 'url',
        'description' => 'body',
        'author' => '',
        'category' => '',
        'comments' => '',
        'enclosure' => 'field_image',
        'guid' => '',
        'pubDate' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['feed_settings'] = array(
    'absolute_paths' => 0,
    'feed_in_links' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'enclosure_image';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '160x120',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['exclude'] = TRUE;
  /* Field: Indexed Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['empty'] = '[field_end_user_description]';
  /* Field: Indexed Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'solutions-directory/oldfeed';
  $handler->display->display_options['displays'] = array(
    'search_results' => 'search_results',
    'default' => 0,
    'featured_products' => 0,
    'solution_facets' => 0,
    'company_facets' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_2');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['exposed_form'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '<none>';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'description' => '',
        'language' => '',
        'category' => '',
        'image' => '',
        'copyright' => '',
        'managingEditor' => '',
        'webMaster' => '',
        'generator' => '',
        'docs' => '',
        'cloud' => '',
        'ttl' => '',
        'skipHours' => '',
        'skipDays' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['item'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'title',
        'link' => 'url',
        'description' => 'body',
        'author' => '',
        'category' => '',
        'comments' => '',
        'enclosure' => 'field_image',
        'guid' => '',
        'pubDate' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['feed_settings'] = array(
    'absolute_paths' => 0,
    'feed_in_links' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['type'] = 'enclosure_image';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '160x120',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['exclude'] = TRUE;
  /* Field: Indexed Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['empty'] = '[field_end_user_description]';
  /* Field: Indexed Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'member-roster/oldfeed';
  $handler->display->display_options['displays'] = array(
    'search_results' => 'search_results',
    'default' => 0,
    'featured_products' => 0,
    'solution_facets' => 0,
    'company_facets' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'solutions-directory/test';
  $translatables['feed_view'] = array(
    t('Master'),
    t('Solutions Directory Feed'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('<none>'),
    t('Asc'),
    t('Desc'),
    t('- All -'),
    t('Offset'),
    t('First'),
    t('Previous'),
    t('Next'),
    t('Last'),
    t('“No results matched your search.”'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Most recent'),
    t('Relevance'),
    t('Membership Level'),
    t('Promoted to frontpage'),
    t('Feed'),
    t('Business User Description – Optional'),
    t('[field_end_user_description]'),
    t('Page'),
  );
  $export['feed_view'] = $view;

  $view = new view();
  $view->name = 'general_membership_submissions';
  $view->description = 'A list of all entityforms submissions';
  $view->tag = 'entityforms';
  $view->base_table = 'entityform';
  $view->human_name = 'General Membership Submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any entityform';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'name' => 'name',
    'entityform_id' => 'entityform_id',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
    'entityform_id' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['content'] = 'No entityforms have been created yet';
  /* Relationship: Entityform: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'entityform';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: Entityform: First Name */
  $handler->display->display_options['fields']['field_gma_first_name']['id'] = 'field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['table'] = 'field_data_field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['field'] = 'field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_gma_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gma_first_name']['element_label_colon'] = FALSE;
  /* Field: Entityform: Last Name */
  $handler->display->display_options['fields']['field_gma_last_name']['id'] = 'field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['table'] = 'field_data_field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['field'] = 'field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['label'] = 'Submitter';
  $handler->display->display_options['fields']['field_gma_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_gma_last_name']['alter']['text'] = '[field_gma_first_name] [field_gma_last_name]';
  /* Field: Entityform: Company Name */
  $handler->display->display_options['fields']['field_gma_company_name']['id'] = 'field_gma_company_name';
  $handler->display->display_options['fields']['field_gma_company_name']['table'] = 'field_data_field_gma_company_name';
  $handler->display->display_options['fields']['field_gma_company_name']['field'] = 'field_gma_company_name';
  /* Field: Entityform Type: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'entityform_type';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = 'Form Type';
  /* Field: Entityform: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Entityform: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entityform';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  /* Field: Entityform: Link */
  $handler->display->display_options['fields']['link_entityform']['id'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['link_entityform']['field'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['label'] = 'View submission';
  /* Field: Entityform: Edit Link */
  $handler->display->display_options['fields']['edit_entityform']['id'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['edit_entityform']['field'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['label'] = 'Edit submission';
  /* Field: Entityform: Delete Link */
  $handler->display->display_options['fields']['delete_entityform']['id'] = 'delete_entityform';
  $handler->display->display_options['fields']['delete_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['delete_entityform']['field'] = 'delete_entityform';
  $handler->display->display_options['fields']['delete_entityform']['label'] = 'Delete submission';
  $handler->display->display_options['fields']['delete_entityform']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Entityform: Date submitted */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Entityform: Entityform Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'entityform';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['type']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['type']['title'] = 'Submissions for %1';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  /* Filter criterion: Entityform: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'general_membership_application' => 'general_membership_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Entityform: Date submitted */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entityform';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Date submitted';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  /* Filter criterion: Entityform: Draft */
  $handler->display->display_options['filters']['draft']['id'] = 'draft';
  $handler->display->display_options['filters']['draft']['table'] = 'entityform';
  $handler->display->display_options['filters']['draft']['field'] = 'draft';
  $handler->display->display_options['filters']['draft']['operator'] = '!=';
  $handler->display->display_options['filters']['draft']['value']['value'] = '1';
  $handler->display->display_options['filters']['draft']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'entityforms_admin_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'entityform-submissions/submissions/%/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['description'] = 'View Submissions for all Entityforms';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Submissions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: XML Data export */
  $handler = $view->new_display('views_data_export', 'XML Data export', 'autofields_xml');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%1-title_submissions_%timestamp-full.xml';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'entityforms';
  $handler->display->display_options['style_options']['item_node'] = 'entityform';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entityform: First Name */
  $handler->display->display_options['fields']['field_gma_first_name']['id'] = 'field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['table'] = 'field_data_field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['field'] = 'field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_gma_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gma_first_name']['element_label_colon'] = FALSE;
  /* Field: Entityform: Last Name */
  $handler->display->display_options['fields']['field_gma_last_name']['id'] = 'field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['table'] = 'field_data_field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['field'] = 'field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['label'] = 'Submitter';
  $handler->display->display_options['fields']['field_gma_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_gma_last_name']['alter']['text'] = '[field_gma_last_name] [field_gma_last_name]';
  /* Field: Entityform Type: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'entityform_type';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = 'Form Type';
  /* Field: Entityform: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Entityform: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entityform';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Entityform: Entityform Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'entityform';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['type']['title'] = 'entityform_submissions_%1';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['path'] = 'entityform-submissions/downloads/%/xml';
  $handler->display->display_options['displays'] = array(
    'entityforms_admin_page' => 'entityforms_admin_page',
    'autofields_table' => 'autofields_table',
    'block_1' => 'block_1',
    'default' => 0,
  );

  /* Display: CSV Data export */
  $handler = $view->new_display('views_data_export', 'CSV Data export', 'autofields_csv');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'submission_%1-title.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['encoding'] = 'ASCII';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entityform: First Name */
  $handler->display->display_options['fields']['field_gma_first_name']['id'] = 'field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['table'] = 'field_data_field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['field'] = 'field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_gma_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gma_first_name']['element_label_colon'] = FALSE;
  /* Field: Entityform: Last Name */
  $handler->display->display_options['fields']['field_gma_last_name']['id'] = 'field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['table'] = 'field_data_field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['field'] = 'field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['label'] = 'Submitter';
  $handler->display->display_options['fields']['field_gma_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_gma_last_name']['alter']['text'] = '[field_gma_first_name] [field_gma_last_name]';
  /* Field: Entityform Type: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'entityform_type';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = 'Form Type';
  /* Field: Entityform: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Entityform: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entityform';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Entityform: Entityform Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'entityform';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['type']['title'] = 'entityform_submissions_%1';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['path'] = 'entityform-submissions/downloads/%/csv';
  $handler->display->display_options['displays'] = array(
    'entityforms_admin_page' => 'entityforms_admin_page',
    'autofields_table' => 'autofields_table',
    'default' => 0,
  );

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'autofields_table');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Entityform: First Name */
  $handler->display->display_options['fields']['field_gma_first_name']['id'] = 'field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['table'] = 'field_data_field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['field'] = 'field_gma_first_name';
  $handler->display->display_options['fields']['field_gma_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_gma_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_gma_first_name']['element_label_colon'] = FALSE;
  /* Field: Entityform: Last Name */
  $handler->display->display_options['fields']['field_gma_last_name']['id'] = 'field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['table'] = 'field_data_field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['field'] = 'field_gma_last_name';
  $handler->display->display_options['fields']['field_gma_last_name']['label'] = 'Submitter';
  $handler->display->display_options['fields']['field_gma_last_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_gma_last_name']['alter']['text'] = '[field_gma_first_name] [field_gma_last_name]';
  /* Field: Entityform: Link */
  $handler->display->display_options['fields']['link_entityform']['id'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['link_entityform']['field'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['label'] = 'View submission';
  /* Field: Entityform Type: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'entityform_type';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = 'Form Type';
  /* Field: Entityform: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Entityform: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entityform';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['path'] = 'entityform-submissions/submissions/%/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['description'] = 'View Submissions for all Entityforms';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['general_membership_submissions'] = array(
    t('Master'),
    t('List'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Empty '),
    t('No entityforms have been created yet'),
    t('User Submitting'),
    t('Submitter'),
    t('[field_gma_first_name] [field_gma_last_name]'),
    t('Company Name'),
    t('Form Type'),
    t('Date submitted'),
    t('Date changed'),
    t('View submission'),
    t('Edit submission'),
    t('Delete submission'),
    t('All'),
    t('Submissions for %1'),
    t('Page'),
    t('XML Data export'),
    t('[field_gma_last_name] [field_gma_last_name]'),
    t('entityform_submissions_%1'),
    t('CSV Data export'),
    t('Table'),
  );
  $export['general_membership_submissions'] = $view;

  $view = new view();
  $view->name = 'google_analytics_reports';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'google_analytics';
  $view->human_name = 'Google Analytics Reports';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Company Profile Page (Member Roster): Pageviews';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'date' => 'date',
    'pageviews' => 'pageviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
    'pageviews' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 0,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No data available.';
  $handler->display->display_options['empty']['area']['format'] = 'wysiwyg_basic';
  /* Field: Time dimensions: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'm/d/y';
  /* Field: Page tracking metrics: Pageviews */
  $handler->display->display_options['fields']['pageviews']['id'] = 'pageviews';
  $handler->display->display_options['fields']['pageviews']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['pageviews']['field'] = 'pageviews';
  $handler->display->display_options['fields']['pageviews']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['pageviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['pageviews']['precision'] = '0';
  /* Sort criterion: Time dimensions: Date */
  $handler->display->display_options['sorts']['date']['id'] = 'date';
  $handler->display->display_options['sorts']['date']['table'] = 'google_analytics';
  $handler->display->display_options['sorts']['date']['field'] = 'date';
  /* Contextual filter: Google Analytics: Start date of report */
  $handler->display->display_options['arguments']['start_date_1']['id'] = 'start_date_1';
  $handler->display->display_options['arguments']['start_date_1']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['start_date_1']['field'] = 'start_date';
  $handler->display->display_options['arguments']['start_date_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['start_date_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['start_date_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['start_date_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['start_date_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['start_date_1']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['start_date_1']['validate']['fail'] = 'ignore';
  /* Contextual filter: Google Analytics: End date of report */
  $handler->display->display_options['arguments']['end_date']['id'] = 'end_date';
  $handler->display->display_options['arguments']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['end_date']['field'] = 'end_date';
  $handler->display->display_options['arguments']['end_date']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['end_date']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['end_date']['default_argument_options']['index'] = '4';
  $handler->display->display_options['arguments']['end_date']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['end_date']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['end_date']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['end_date']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['end_date']['validate']['fail'] = 'ignore';
  /* Filter criterion: Page tracking metrics: Pageviews */
  $handler->display->display_options['filters']['pageviews']['id'] = 'pageviews';
  $handler->display->display_options['filters']['pageviews']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['pageviews']['field'] = 'pageviews';
  $handler->display->display_options['filters']['pageviews']['operator'] = '>';
  $handler->display->display_options['filters']['pageviews']['value']['value'] = '0';

  /* Display: Member: Pageviews */
  $handler = $view->new_display('block', 'Member: Pageviews', 'member');
  $handler->display->display_options['display_description'] = 'Number of pageviews of the member page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'date' => 'date',
    'pageviews' => 'pageviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_replace',
      'aggr_par_column' => 'Total',
    ),
    'pageviews' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_group_and_compress' => 'views_aggregator_group_and_compress',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Custom variables or columns dimensions: Custom Variable (Value XX) */
  $handler->display->display_options['arguments']['customVarValueXX']['id'] = 'customVarValueXX';
  $handler->display->display_options['arguments']['customVarValueXX']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['customVarValueXX']['field'] = 'customVarValueXX';
  $handler->display->display_options['arguments']['customVarValueXX']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['customVarValueXX']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['customVarValueXX']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['customVarValueXX']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['customVarValueXX']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['customVarValueXX']['custom_field_number'] = '2';
  /* Contextual filter: Google Analytics: Start date of report */
  $handler->display->display_options['arguments']['start_date_1']['id'] = 'start_date_1';
  $handler->display->display_options['arguments']['start_date_1']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['start_date_1']['field'] = 'start_date';
  $handler->display->display_options['arguments']['start_date_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['start_date_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['start_date_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['start_date_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['start_date_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['start_date_1']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['start_date_1']['validate']['fail'] = 'ignore';
  /* Contextual filter: Google Analytics: End date of report */
  $handler->display->display_options['arguments']['end_date']['id'] = 'end_date';
  $handler->display->display_options['arguments']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['end_date']['field'] = 'end_date';
  $handler->display->display_options['arguments']['end_date']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['end_date']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['end_date']['default_argument_options']['index'] = '4';
  $handler->display->display_options['arguments']['end_date']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['end_date']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['end_date']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['end_date']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['end_date']['validate']['fail'] = 'ignore';

  /* Display: Member: Request Quote clicks */
  $handler = $view->new_display('block', 'Member: Request Quote clicks', 'member_request_quote');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Company Profile Page (Member Roster): Contact Button clicks';
  $handler->display->display_options['display_description'] = 'Number of clicks on the Request Quote button from the member page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'date' => 'date',
    'totalEvents' => 'totalEvents',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_replace',
      'aggr_par_column' => 'Total',
    ),
    'totalEvents' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Time dimensions: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'm/d/y';
  /* Field: Event tracking metrics: Total Events */
  $handler->display->display_options['fields']['totalEvents']['id'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['totalEvents']['field'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['label'] = 'Clicks';
  $handler->display->display_options['fields']['totalEvents']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['totalEvents']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Event tracking dimensions: Event Label */
  $handler->display->display_options['arguments']['eventLabel']['id'] = 'eventLabel';
  $handler->display->display_options['arguments']['eventLabel']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['eventLabel']['field'] = 'eventLabel';
  $handler->display->display_options['arguments']['eventLabel']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['eventLabel']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['eventLabel']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['eventLabel']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['eventLabel']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Google Analytics: Start date of report */
  $handler->display->display_options['arguments']['start_date_1']['id'] = 'start_date_1';
  $handler->display->display_options['arguments']['start_date_1']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['start_date_1']['field'] = 'start_date';
  $handler->display->display_options['arguments']['start_date_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['start_date_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['start_date_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['start_date_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['start_date_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['start_date_1']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['start_date_1']['validate']['fail'] = 'ignore';
  /* Contextual filter: Google Analytics: End date of report */
  $handler->display->display_options['arguments']['end_date']['id'] = 'end_date';
  $handler->display->display_options['arguments']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['end_date']['field'] = 'end_date';
  $handler->display->display_options['arguments']['end_date']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['end_date']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['end_date']['default_argument_options']['index'] = '4';
  $handler->display->display_options['arguments']['end_date']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['end_date']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['end_date']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['end_date']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['end_date']['validate']['fail'] = 'ignore';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event tracking dimensions: Event Action */
  $handler->display->display_options['filters']['eventAction']['id'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventAction']['field'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['value'] = 'Contact Member';
  /* Filter criterion: Event tracking dimensions: Event Category */
  $handler->display->display_options['filters']['eventCategory']['id'] = 'eventCategory';
  $handler->display->display_options['filters']['eventCategory']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventCategory']['field'] = 'eventCategory';
  $handler->display->display_options['filters']['eventCategory']['value'] = 'Member Details';
  /* Filter criterion: Event tracking metrics: Total Events */
  $handler->display->display_options['filters']['totalEvents']['id'] = 'totalEvents';
  $handler->display->display_options['filters']['totalEvents']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['totalEvents']['field'] = 'totalEvents';
  $handler->display->display_options['filters']['totalEvents']['operator'] = '>';
  $handler->display->display_options['filters']['totalEvents']['value']['value'] = '0';

  /* Display: Member: Website clicks */
  $handler = $view->new_display('block', 'Member: Website clicks', 'member_website');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Company Profile Page (Member Roster): Clicks to Company Website';
  $handler->display->display_options['display_description'] = 'Number of clicks on the Website button from the member page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'date' => 'date',
    'totalEvents' => 'totalEvents',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_replace',
      'aggr_par_column' => 'Total',
    ),
    'totalEvents' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Time dimensions: Date */
  $handler->display->display_options['fields']['date']['id'] = 'date';
  $handler->display->display_options['fields']['date']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['date']['field'] = 'date';
  $handler->display->display_options['fields']['date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['date']['date_format'] = 'custom';
  $handler->display->display_options['fields']['date']['custom_date_format'] = 'm/d/y';
  /* Field: Event tracking metrics: Total Events */
  $handler->display->display_options['fields']['totalEvents']['id'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['totalEvents']['field'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['label'] = 'Clicks';
  $handler->display->display_options['fields']['totalEvents']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Event tracking dimensions: Event Label */
  $handler->display->display_options['arguments']['eventLabel']['id'] = 'eventLabel';
  $handler->display->display_options['arguments']['eventLabel']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['eventLabel']['field'] = 'eventLabel';
  $handler->display->display_options['arguments']['eventLabel']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['eventLabel']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['eventLabel']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['eventLabel']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['eventLabel']['summary_options']['items_per_page'] = '25';
  /* Contextual filter: Google Analytics: Start date of report */
  $handler->display->display_options['arguments']['start_date_1']['id'] = 'start_date_1';
  $handler->display->display_options['arguments']['start_date_1']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['start_date_1']['field'] = 'start_date';
  $handler->display->display_options['arguments']['start_date_1']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['start_date_1']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['start_date_1']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['start_date_1']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['start_date_1']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['start_date_1']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['start_date_1']['validate']['fail'] = 'ignore';
  /* Contextual filter: Google Analytics: End date of report */
  $handler->display->display_options['arguments']['end_date']['id'] = 'end_date';
  $handler->display->display_options['arguments']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['end_date']['field'] = 'end_date';
  $handler->display->display_options['arguments']['end_date']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['end_date']['default_argument_type'] = 'raw';
  $handler->display->display_options['arguments']['end_date']['default_argument_options']['index'] = '4';
  $handler->display->display_options['arguments']['end_date']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['end_date']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['end_date']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['end_date']['validate']['type'] = 'numeric';
  $handler->display->display_options['arguments']['end_date']['validate']['fail'] = 'ignore';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event tracking dimensions: Event Action */
  $handler->display->display_options['filters']['eventAction']['id'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventAction']['field'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['value'] = 'Company Webpage';
  /* Filter criterion: Event tracking dimensions: Event Category */
  $handler->display->display_options['filters']['eventCategory']['id'] = 'eventCategory';
  $handler->display->display_options['filters']['eventCategory']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventCategory']['field'] = 'eventCategory';
  $handler->display->display_options['filters']['eventCategory']['value'] = 'Member Details';
  /* Filter criterion: Event tracking metrics: Total Events */
  $handler->display->display_options['filters']['totalEvents']['id'] = 'totalEvents';
  $handler->display->display_options['filters']['totalEvents']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['totalEvents']['field'] = 'totalEvents';
  $handler->display->display_options['filters']['totalEvents']['operator'] = '>';
  $handler->display->display_options['filters']['totalEvents']['value']['value'] = '0';

  /* Display: Content: Pageviews */
  $handler = $view->new_display('block', 'Content: Pageviews', 'content');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Solutions Directory Products: Pageviews';
  $handler->display->display_options['display_description'] = 'Number of pageviews of member related content pages.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'customVarValue(n)' => 'customVarValue(n)',
    'pageviews' => 'pageviews',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'customVarValue(n)' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_replace',
      'aggr_par_column' => 'Total',
    ),
    'pageviews' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Custom variables or columns dimensions: Custom Variable (Value XX) */
  $handler->display->display_options['fields']['customVarValueXX']['id'] = 'customVarValueXX';
  $handler->display->display_options['fields']['customVarValueXX']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['customVarValueXX']['field'] = 'customVarValueXX';
  $handler->display->display_options['fields']['customVarValueXX']['label'] = 'Content ID';
  $handler->display->display_options['fields']['customVarValueXX']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['customVarValueXX']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['customVarValueXX']['custom_field_number'] = '4';
  /* Field: Page tracking metrics: Pageviews */
  $handler->display->display_options['fields']['pageviews']['id'] = 'pageviews';
  $handler->display->display_options['fields']['pageviews']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['pageviews']['field'] = 'pageviews';
  $handler->display->display_options['fields']['pageviews']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['pageviews']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Page tracking metrics: Pageviews */
  $handler->display->display_options['sorts']['pageviews']['id'] = 'pageviews';
  $handler->display->display_options['sorts']['pageviews']['table'] = 'google_analytics';
  $handler->display->display_options['sorts']['pageviews']['field'] = 'pageviews';
  $handler->display->display_options['sorts']['pageviews']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;

  /* Display: Content: Request Quote */
  $handler = $view->new_display('block', 'Content: Request Quote', 'content_request_quote');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Solutions Directory Products: Request Quote clicks';
  $handler->display->display_options['display_description'] = 'Number of clicks on the Request Quote button from the content page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'eventLabel' => 'eventLabel',
    'totalEvents' => 'totalEvents',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'eventLabel' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_replace',
      'aggr_par_column' => 'Total',
    ),
    'totalEvents' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Event tracking dimensions: Event Label */
  $handler->display->display_options['fields']['eventLabel']['id'] = 'eventLabel';
  $handler->display->display_options['fields']['eventLabel']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['eventLabel']['field'] = 'eventLabel';
  $handler->display->display_options['fields']['eventLabel']['label'] = 'Content ID';
  $handler->display->display_options['fields']['eventLabel']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['eventLabel']['element_label_colon'] = FALSE;
  /* Field: Event tracking metrics: Total Events */
  $handler->display->display_options['fields']['totalEvents']['id'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['totalEvents']['field'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['label'] = 'Clicks';
  $handler->display->display_options['fields']['totalEvents']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['totalEvents']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event tracking dimensions: Event Label */
  $handler->display->display_options['sorts']['eventLabel']['id'] = 'eventLabel';
  $handler->display->display_options['sorts']['eventLabel']['table'] = 'google_analytics';
  $handler->display->display_options['sorts']['eventLabel']['field'] = 'eventLabel';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event tracking dimensions: Event Category */
  $handler->display->display_options['filters']['eventCategory_1']['id'] = 'eventCategory_1';
  $handler->display->display_options['filters']['eventCategory_1']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventCategory_1']['field'] = 'eventCategory';
  $handler->display->display_options['filters']['eventCategory_1']['value'] = 'Product Details';
  $handler->display->display_options['filters']['eventCategory_1']['group'] = 1;
  /* Filter criterion: Event tracking dimensions: Event Action */
  $handler->display->display_options['filters']['eventAction']['id'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventAction']['field'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['value'] = 'Contact Member';
  $handler->display->display_options['filters']['eventAction']['group'] = 1;

  /* Display: Content: Contact Intel clicks */
  $handler = $view->new_display('block', 'Content: Contact Intel clicks', 'content_contact_intel');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Solutions Directory Products: Contact Intel clicks';
  $handler->display->display_options['display_description'] = 'Number of clicks on the Contact Intel button from the content page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'eventLabel' => 'eventLabel',
    'totalEvents' => 'totalEvents',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'eventLabel' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_replace',
      'aggr_par_column' => 'Total',
    ),
    'totalEvents' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Event tracking dimensions: Event Label */
  $handler->display->display_options['fields']['eventLabel']['id'] = 'eventLabel';
  $handler->display->display_options['fields']['eventLabel']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['eventLabel']['field'] = 'eventLabel';
  $handler->display->display_options['fields']['eventLabel']['label'] = 'Content ID';
  $handler->display->display_options['fields']['eventLabel']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['eventLabel']['element_label_colon'] = FALSE;
  /* Field: Event tracking metrics: Total Events */
  $handler->display->display_options['fields']['totalEvents']['id'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['totalEvents']['field'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['label'] = 'Clicks';
  $handler->display->display_options['fields']['totalEvents']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['totalEvents']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event tracking dimensions: Event Label */
  $handler->display->display_options['sorts']['eventLabel']['id'] = 'eventLabel';
  $handler->display->display_options['sorts']['eventLabel']['table'] = 'google_analytics';
  $handler->display->display_options['sorts']['eventLabel']['field'] = 'eventLabel';
  $handler->display->display_options['sorts']['eventLabel']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event tracking dimensions: Event Category */
  $handler->display->display_options['filters']['eventCategory_1']['id'] = 'eventCategory_1';
  $handler->display->display_options['filters']['eventCategory_1']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventCategory_1']['field'] = 'eventCategory';
  $handler->display->display_options['filters']['eventCategory_1']['value'] = 'Product Details';
  $handler->display->display_options['filters']['eventCategory_1']['group'] = 1;
  /* Filter criterion: Event tracking dimensions: Event Action */
  $handler->display->display_options['filters']['eventAction']['id'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventAction']['field'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['value'] = 'Contact Intel';
  $handler->display->display_options['filters']['eventAction']['group'] = 1;

  /* Display: Content: Linked Resources clicks */
  $handler = $view->new_display('block', 'Content: Linked Resources clicks', 'content_datasheet');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Solutions Directory Products: Linked Resources clicks';
  $handler->display->display_options['display_description'] = 'Number of clicks on the Datasheet link from the content page.';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'views_aggregator';
  $handler->display->display_options['style_options']['columns'] = array(
    'eventLabel' => 'eventLabel',
    'totalEvents' => 'totalEvents',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'eventLabel' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_replace',
      'aggr_par_column' => 'Total',
    ),
    'totalEvents' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
      'has_aggr' => 0,
      'aggr' => array(
        'views_aggregator_first' => 'views_aggregator_first',
      ),
      'aggr_par' => '',
      'has_aggr_column' => 1,
      'aggr_column' => 'views_aggregator_sum',
      'aggr_par_column' => '',
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Event tracking dimensions: Event Label */
  $handler->display->display_options['fields']['eventLabel']['id'] = 'eventLabel';
  $handler->display->display_options['fields']['eventLabel']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['eventLabel']['field'] = 'eventLabel';
  $handler->display->display_options['fields']['eventLabel']['label'] = 'Content ID';
  $handler->display->display_options['fields']['eventLabel']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['eventLabel']['element_label_colon'] = FALSE;
  /* Field: Event tracking metrics: Total Events */
  $handler->display->display_options['fields']['totalEvents']['id'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['totalEvents']['field'] = 'totalEvents';
  $handler->display->display_options['fields']['totalEvents']['label'] = 'Clicks';
  $handler->display->display_options['fields']['totalEvents']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['totalEvents']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Event tracking dimensions: Event Label */
  $handler->display->display_options['sorts']['eventLabel']['id'] = 'eventLabel';
  $handler->display->display_options['sorts']['eventLabel']['table'] = 'google_analytics';
  $handler->display->display_options['sorts']['eventLabel']['field'] = 'eventLabel';
  $handler->display->display_options['sorts']['eventLabel']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'AND',
    2 => 'OR',
  );
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Event tracking dimensions: Event Category */
  $handler->display->display_options['filters']['eventCategory_1']['id'] = 'eventCategory_1';
  $handler->display->display_options['filters']['eventCategory_1']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventCategory_1']['field'] = 'eventCategory';
  $handler->display->display_options['filters']['eventCategory_1']['value'] = 'Product Details';
  $handler->display->display_options['filters']['eventCategory_1']['group'] = 1;
  /* Filter criterion: Event tracking dimensions: Event Action */
  $handler->display->display_options['filters']['eventAction']['id'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventAction']['field'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction']['value'] = 'Download Datasheet';
  $handler->display->display_options['filters']['eventAction']['group'] = 2;
  /* Filter criterion: Event tracking dimensions: Event Action */
  $handler->display->display_options['filters']['eventAction_1']['id'] = 'eventAction_1';
  $handler->display->display_options['filters']['eventAction_1']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventAction_1']['field'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction_1']['value'] = 'Product Webpage';
  $handler->display->display_options['filters']['eventAction_1']['group'] = 2;
  /* Filter criterion: Event tracking dimensions: Event Action */
  $handler->display->display_options['filters']['eventAction_2']['id'] = 'eventAction_2';
  $handler->display->display_options['filters']['eventAction_2']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['eventAction_2']['field'] = 'eventAction';
  $handler->display->display_options['filters']['eventAction_2']['value'] = 'External Resource';
  $handler->display->display_options['filters']['eventAction_2']['group'] = 2;
  $translatables['google_analytics_reports'] = array(
    t('Master'),
    t('Company Profile Page (Member Roster): Pageviews'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('No data available.'),
    t('Date'),
    t('Pageviews'),
    t('.'),
    t(','),
    t('All'),
    t('Member: Pageviews'),
    t('Number of pageviews of the member page.'),
    t('Member: Request Quote clicks'),
    t('Company Profile Page (Member Roster): Contact Button clicks'),
    t('Number of clicks on the Request Quote button from the member page.'),
    t('Clicks'),
    t('Member: Website clicks'),
    t('Company Profile Page (Member Roster): Clicks to Company Website'),
    t('Number of clicks on the Website button from the member page.'),
    t('Content: Pageviews'),
    t('Solutions Directory Products: Pageviews'),
    t('Number of pageviews of member related content pages.'),
    t('Content ID'),
    t('Content: Request Quote'),
    t('Solutions Directory Products: Request Quote clicks'),
    t('Number of clicks on the Request Quote button from the content page.'),
    t('Content: Contact Intel clicks'),
    t('Solutions Directory Products: Contact Intel clicks'),
    t('Number of clicks on the Contact Intel button from the content page.'),
    t('Content: Linked Resources clicks'),
    t('Solutions Directory Products: Linked Resources clicks'),
    t('Number of clicks on the Datasheet link from the content page.'),
  );
  $export['google_analytics_reports'] = $view;

  $view = new view();
  $view->name = 'member_roster';
  $view->description = 'The Member Roster companies listed by membership type.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_companies';
  $view->human_name = 'Member Roster';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Intel® Technology Provider Gold Partner';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Indexed Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => '',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';

  /* Display: Affiliate */
  $handler = $view->new_display('panel_pane', 'Affiliate', 'affiliate');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel® IoT Solutions Alliance Affiliate Member';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'segment_product_images_179x135',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_company_node_eb_status']['group'] = 1;
  /* Filter criterion: node entity referenced from field_company: Pre-Release (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['id'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['field'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['group'] = 1;
  /* Filter criterion: Indexed Content: Membership Tier */
  $handler->display->display_options['filters']['field_membership_tier']['id'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_tier']['field'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['value'] = array(
    1326 => '1326',
  );

  /* Display: Associate */
  $handler = $view->new_display('panel_pane', 'Associate', 'associate');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel® IoT Solutions Alliance Associate Member';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'segment_product_images_179x135',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_company_node_eb_status']['group'] = 1;
  /* Filter criterion: node entity referenced from field_company: Pre-Release (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['id'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['field'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['group'] = 1;
  /* Filter criterion: Indexed Content: Membership Tier */
  $handler->display->display_options['filters']['field_membership_tier']['id'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_tier']['field'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['value'] = array(
    1325 => '1325',
  );

  /* Display: General */
  $handler = $view->new_display('panel_pane', 'General', 'general');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel® IoT Solutions Alliance General Member';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'segment_product_images_179x135',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_company_node_eb_status']['group'] = 1;
  /* Filter criterion: node entity referenced from field_company: Pre-Release (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['id'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['field'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['group'] = 1;
  /* Filter criterion: Indexed Content: Membership Tier */
  $handler->display->display_options['filters']['field_membership_tier']['id'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_tier']['field'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['value'] = array(
    1327 => '1327',
  );

  /* Display: Premier */
  $handler = $view->new_display('panel_pane', 'Premier', 'premier');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel® IoT Solutions Alliance Premier Member';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'segment_product_images_179x135',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_company_node_eb_status']['group'] = 1;
  /* Filter criterion: node entity referenced from field_company: Pre-Release (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['id'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['field'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['group'] = 1;
  /* Filter criterion: Indexed Content: Membership Tier */
  $handler->display->display_options['filters']['field_membership_tier']['id'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_tier']['field'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['value'] = array(
    1324 => '1324',
  );

  /* Display: Member Roster Facets */
  $handler = $view->new_display('search_api_views_facets_block', 'Member Roster Facets', 'member_roster_facets');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_company_node_eb_status']['group'] = 1;
  /* Filter criterion: node entity referenced from field_company: Pre-Release (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['id'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['field'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['group'] = 1;
  /* Filter criterion: Indexed Content: Membership Tier */
  $handler->display->display_options['filters']['field_membership_tier']['id'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_tier']['field'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['value'] = array(
    1323 => '1323',
    1328 => '1328',
    1329 => '1329',
    1330 => '1330',
    1322 => '1322',
    1324 => '1324',
    1325 => '1325',
    1326 => '1326',
    1327 => '1327',
  );
  $handler->display->display_options['linked_path'] = 'member-roster';
  $handler->display->display_options['facet_field'] = 'nid';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Printable */
  $handler = $view->new_display('page', 'Printable', 'printable');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel Solutions Directory Listing';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_membership_type',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_membership_type' => 'field_membership_type',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_membership_type' => array(
      'sortable' => 0,
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
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Indexed Content: Current Membership Type */
  $handler->display->display_options['relationships']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['relationships']['field_membership_type']['table'] = 'search_api_index_companies';
  $handler->display->display_options['relationships']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Current Membership Type */
  $handler->display->display_options['fields']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['label'] = '';
  $handler->display->display_options['fields']['field_membership_type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_membership_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_membership_type']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_membership_type']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_membership_type']['view_mode'] = 'full';
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Content: Current Membership Type */
  $handler->display->display_options['sorts']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['sorts']['field_membership_type']['table'] = 'search_api_index_companies';
  $handler->display->display_options['sorts']['field_membership_type']['field'] = 'field_membership_type';
  /* Sort criterion: Indexed Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Content: Current Membership Type */
  $handler->display->display_options['filters']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['filters']['field_membership_type']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['filters']['field_membership_type']['value'] = array(
    557 => '557',
    558 => '558',
    559 => '559',
    560 => '560',
  );
  $handler->display->display_options['filters']['field_membership_type']['group'] = 1;
  $handler->display->display_options['path'] = 'member-roster/print';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'description' => '',
        'language' => '',
        'category' => '',
        'image' => '',
        'copyright' => '',
        'managingEditor' => '',
        'webMaster' => '',
        'generator' => '',
        'docs' => '',
        'cloud' => '',
        'ttl' => '',
        'skipHours' => '',
        'skipDays' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['item'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'title',
        'link' => 'url',
        'description' => 'body',
        'author' => '',
        'category' => '',
        'comments' => '',
        'enclosure' => 'field_image',
        'guid' => '',
        'pubDate' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['feed_settings'] = array(
    'absolute_paths' => 1,
    'feed_in_links' => 0,
  );
  $handler->display->display_options['path'] = 'member-roster/feed';

  /* Display: ITP Platinum */
  $handler = $view->new_display('panel_pane', 'ITP Platinum', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel® Technology Provider Platinum Partner';
  $handler->display->display_options['display_description'] = 'Companies belonging to the Intel® Technology Provider Platinum Partner membership tier.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'segment_product_images_179x135',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: node entity referenced from field_company: Pre-Release (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['id'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['field'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Indexed Content: Membership Tier */
  $handler->display->display_options['filters']['field_membership_tier']['id'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_tier']['field'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['value'] = array(
    1328 => '1328',
  );

  /* Display: ITP Gold */
  $handler = $view->new_display('panel_pane', 'ITP Gold', 'panel_pane_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel® Technology Provider Gold Partner';
  $handler->display->display_options['display_description'] = 'Companies belonging to the Intel® Technology Provider Gold Partner membership tier.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'segment_product_images_179x135',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: node entity referenced from field_company: Pre-Release (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['id'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['field'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Indexed Content: Membership Tier */
  $handler->display->display_options['filters']['field_membership_tier']['id'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_tier']['field'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['value'] = array(
    1329 => '1329',
  );

  /* Display: ITP Registered */
  $handler = $view->new_display('panel_pane', 'ITP Registered', 'panel_pane_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Intel® Technology Provider Registered Partner';
  $handler->display->display_options['display_description'] = 'Companies belonging to the Intel® Technology Provider Registered Partner membership tier.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Logo */
  $handler->display->display_options['fields']['field_logo']['id'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['field_logo']['field'] = 'field_logo';
  $handler->display->display_options['fields']['field_logo']['label'] = '';
  $handler->display->display_options['fields']['field_logo']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_logo']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_logo']['settings'] = array(
    'image_style' => 'segment_product_images_179x135',
    'image_link' => 'content',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_companies';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 1;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: node entity referenced from field_company: Status (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_status']['id'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_status']['field'] = 'field_company_node_eb_status';
  $handler->display->display_options['filters']['field_company_node_eb_status']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: node entity referenced from field_company: Pre-Release (indexed) */
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['id'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['field'] = 'field_company_node_eb_field_pre_release';
  $handler->display->display_options['filters']['field_company_node_eb_field_pre_release']['value'] = array(
    0 => '0',
  );
  /* Filter criterion: Indexed Content: Membership Tier */
  $handler->display->display_options['filters']['field_membership_tier']['id'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['table'] = 'search_api_index_companies';
  $handler->display->display_options['filters']['field_membership_tier']['field'] = 'field_membership_tier';
  $handler->display->display_options['filters']['field_membership_tier']['value'] = array(
    1330 => '1330',
  );
  $translatables['member_roster'] = array(
    t('Master'),
    t('Intel® Technology Provider Gold Partner'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Title'),
    t('Affiliate'),
    t('Intel® IoT Solutions Alliance Affiliate Member'),
    t('View panes'),
    t('Associate'),
    t('Intel® IoT Solutions Alliance Associate Member'),
    t('General'),
    t('Intel® IoT Solutions Alliance General Member'),
    t('Premier'),
    t('Intel® IoT Solutions Alliance Premier Member'),
    t('Member Roster Facets'),
    t('Printable'),
    t('Intel Solutions Directory Listing'),
    t('Current Membership Type'),
    t('Feed'),
    t('ITP Platinum'),
    t('Intel® Technology Provider Platinum Partner'),
    t('Companies belonging to the Intel® Technology Provider Platinum Partner membership tier.'),
    t('ITP Gold'),
    t('Companies belonging to the Intel® Technology Provider Gold Partner membership tier.'),
    t('ITP Registered'),
    t('Intel® Technology Provider Registered Partner'),
    t('Companies belonging to the Intel® Technology Provider Registered Partner membership tier.'),
  );
  $export['member_roster'] = $view;

  $view = new view();
  $view->name = 'membership_renewal_submissions';
  $view->description = 'A list of all entityforms submissions';
  $view->tag = 'entityforms';
  $view->base_table = 'entityform';
  $view->human_name = 'Membership Renewal Submissions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'List';
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view any entityform';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'view_user' => 'view_user',
    'field_company' => 'field_company',
    'field_mra_future_membership' => 'field_mra_future_membership',
    'label_1' => 'label_1',
    'created' => 'created',
    'changed' => 'changed',
    'link_entityform' => 'link_entityform',
    'edit_entityform' => 'edit_entityform',
    'delete_entityform' => 'delete_entityform',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_company' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_mra_future_membership' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_entityform' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'edit_entityform' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delete_entityform' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['label'] = 'Empty ';
  $handler->display->display_options['empty']['area']['content'] = 'No entityforms have been created yet';
  /* Relationship: Entityform: Uid */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'entityform';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'uid';
  $handler->display->display_options['fields']['view_user']['label'] = 'Submitter';
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: Field: Company */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_company']['label'] = 'Company Name';
  $handler->display->display_options['fields']['field_company']['settings'] = array(
    'link' => 1,
  );
  /* Field: Entityform: Membership */
  $handler->display->display_options['fields']['field_mra_future_membership']['id'] = 'field_mra_future_membership';
  $handler->display->display_options['fields']['field_mra_future_membership']['table'] = 'field_data_field_mra_future_membership';
  $handler->display->display_options['fields']['field_mra_future_membership']['field'] = 'field_mra_future_membership';
  /* Field: Entityform Type: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'entityform_type';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = 'Form Type';
  /* Field: Entityform: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Entityform: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entityform';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  /* Field: Entityform: Link */
  $handler->display->display_options['fields']['link_entityform']['id'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['link_entityform']['field'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['label'] = 'View submission';
  /* Field: Entityform: Edit Link */
  $handler->display->display_options['fields']['edit_entityform']['id'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['edit_entityform']['field'] = 'edit_entityform';
  $handler->display->display_options['fields']['edit_entityform']['label'] = 'Edit submission';
  /* Field: Entityform: Delete Link */
  $handler->display->display_options['fields']['delete_entityform']['id'] = 'delete_entityform';
  $handler->display->display_options['fields']['delete_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['delete_entityform']['field'] = 'delete_entityform';
  $handler->display->display_options['fields']['delete_entityform']['label'] = 'Delete submission';
  $handler->display->display_options['fields']['delete_entityform']['hide_alter_empty'] = FALSE;
  /* Sort criterion: Entityform: Date submitted */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'entityform';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Contextual filter: Entityform: Entityform Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'entityform';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['type']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['type']['title'] = 'Submissions for %1';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  /* Filter criterion: Entityform: Entityform Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'entityform';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'membership_renewal_application' => 'membership_renewal_application',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Entityform: Date submitted */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'entityform';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['operator'] = '>';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Date submitted';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  /* Filter criterion: Entityform: Draft */
  $handler->display->display_options['filters']['draft']['id'] = 'draft';
  $handler->display->display_options['filters']['draft']['table'] = 'entityform';
  $handler->display->display_options['filters']['draft']['field'] = 'draft';
  $handler->display->display_options['filters']['draft']['operator'] = '!=';
  $handler->display->display_options['filters']['draft']['value']['value'] = '1';
  $handler->display->display_options['filters']['draft']['group'] = 1;

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'entityforms_admin_page');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'entityform-submissions/submissions/%/list';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'List';
  $handler->display->display_options['menu']['description'] = 'View Submissions for all Entityforms';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Submissions';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: XML Data export */
  $handler = $view->new_display('views_data_export', 'XML Data export', 'autofields_xml');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_xml';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%1-title_submissions_%timestamp-full.xml';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['transform'] = 1;
  $handler->display->display_options['style_options']['root_node'] = 'entityforms';
  $handler->display->display_options['style_options']['item_node'] = 'entityform';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Submitter';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Entityform Type: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'entityform_type';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = 'Form Type';
  /* Field: Entityform: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Entityform: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entityform';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Entityform: Entityform Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'entityform';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['type']['title'] = 'entityform_submissions_%1';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['path'] = 'entityform-submissions/downloads/%/xml';
  $handler->display->display_options['displays'] = array(
    'entityforms_admin_page' => 'entityforms_admin_page',
    'autofields_table' => 'autofields_table',
    'block_1' => 'block_1',
    'default' => 0,
  );

  /* Display: CSV Data export */
  $handler = $view->new_display('views_data_export', 'CSV Data export', 'autofields_csv');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = 'submission_%1-title.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['encoding'] = 'ASCII';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['name']['label'] = 'Submitter';
  $handler->display->display_options['fields']['name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['name']['alter']['text'] = '[field_first_name] [field_last_name]';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Entityform Type: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'entityform_type';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = 'Form Type';
  /* Field: Entityform: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Entityform: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entityform';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Entityform: Entityform Type */
  $handler->display->display_options['arguments']['type']['id'] = 'type';
  $handler->display->display_options['arguments']['type']['table'] = 'entityform';
  $handler->display->display_options['arguments']['type']['field'] = 'type';
  $handler->display->display_options['arguments']['type']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['type']['title'] = 'entityform_submissions_%1';
  $handler->display->display_options['arguments']['type']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['type']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['type']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['type']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['type']['limit'] = '0';
  $handler->display->display_options['path'] = 'entityform-submissions/downloads/%/csv';
  $handler->display->display_options['displays'] = array(
    'entityforms_admin_page' => 'entityforms_admin_page',
    'autofields_table' => 'autofields_table',
    'default' => 0,
  );

  /* Display: Table */
  $handler = $view->new_display('page', 'Table', 'autofields_table');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_first_name' => 'field_first_name',
    'field_last_name' => 'field_last_name',
    'view_user' => 'view_user',
    'link_entityform' => 'link_entityform',
    'label_1' => 'label_1',
    'created' => 'created',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_first_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'view_user' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'link_entityform' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'label_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_first_name']['label'] = '';
  $handler->display->display_options['fields']['field_first_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'uid';
  $handler->display->display_options['fields']['field_last_name']['label'] = '';
  $handler->display->display_options['fields']['field_last_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['relationship'] = 'uid';
  $handler->display->display_options['fields']['view_user']['label'] = 'Submitter';
  $handler->display->display_options['fields']['view_user']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['view_user']['alter']['text'] = '[field_first_name] [field_last_name]';
  /* Field: Entityform: Link */
  $handler->display->display_options['fields']['link_entityform']['id'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['table'] = 'entityform';
  $handler->display->display_options['fields']['link_entityform']['field'] = 'link_entityform';
  $handler->display->display_options['fields']['link_entityform']['label'] = 'View submission';
  /* Field: Entityform Type: Label */
  $handler->display->display_options['fields']['label_1']['id'] = 'label_1';
  $handler->display->display_options['fields']['label_1']['table'] = 'entityform_type';
  $handler->display->display_options['fields']['label_1']['field'] = 'label';
  $handler->display->display_options['fields']['label_1']['label'] = 'Form Type';
  /* Field: Entityform: Date submitted */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'entityform';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'medium';
  /* Field: Entityform: Date changed */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'entityform';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['path'] = 'entityform-submissions/submissions/%/table';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Table';
  $handler->display->display_options['menu']['description'] = 'View Submissions for all Entityforms';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['tab_options']['weight'] = '0';
  $translatables['membership_renewal_submissions'] = array(
    t('Master'),
    t('List'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Empty '),
    t('No entityforms have been created yet'),
    t('User Submitting'),
    t('Submitter'),
    t('[field_first_name] [field_last_name]'),
    t('Company Name'),
    t('Membership'),
    t('Form Type'),
    t('Date submitted'),
    t('Date changed'),
    t('View submission'),
    t('Edit submission'),
    t('Delete submission'),
    t('All'),
    t('Submissions for %1'),
    t('Page'),
    t('XML Data export'),
    t('entityform_submissions_%1'),
    t('CSV Data export'),
    t('Table'),
  );
  $export['membership_renewal_submissions'] = $view;

  $view = new view();
  $view->name = 'notifications';
  $view->description = 'MRC Notifications shown by the user\'s membership type and role.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Notifications';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Notifications';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation']['label'] = 'Default language';
  $handler->display->display_options['relationships']['translation']['language'] = 'default';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_1']['id'] = 'translation_1';
  $handler->display->display_options['relationships']['translation_1']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_1']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_1']['label'] = 'Current language';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'translation';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['empty'] = '[title]';
  $handler->display->display_options['fields']['title_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title_1']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_2']['id'] = 'title_2';
  $handler->display->display_options['fields']['title_2']['table'] = 'node';
  $handler->display->display_options['fields']['title_2']['field'] = 'title';
  $handler->display->display_options['fields']['title_2']['relationship'] = 'translation_1';
  $handler->display->display_options['fields']['title_2']['label'] = '';
  $handler->display->display_options['fields']['title_2']['element_class'] = 'notifications-block-title';
  $handler->display->display_options['fields']['title_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_2']['empty'] = '[title_1]';
  $handler->display->display_options['fields']['title_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title_2']['empty_zero'] = TRUE;
  $handler->display->display_options['fields']['title_2']['link_to_node'] = FALSE;
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = '';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body']['hide_empty'] = TRUE;
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body_1']['id'] = 'body_1';
  $handler->display->display_options['fields']['body_1']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_1']['field'] = 'body';
  $handler->display->display_options['fields']['body_1']['relationship'] = 'translation';
  $handler->display->display_options['fields']['body_1']['label'] = '';
  $handler->display->display_options['fields']['body_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['body_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_1']['empty'] = '[body]';
  $handler->display->display_options['fields']['body_1']['hide_empty'] = TRUE;
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body_2']['id'] = 'body_2';
  $handler->display->display_options['fields']['body_2']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body_2']['field'] = 'body';
  $handler->display->display_options['fields']['body_2']['relationship'] = 'translation_1';
  $handler->display->display_options['fields']['body_2']['label'] = '';
  $handler->display->display_options['fields']['body_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['body_2']['empty'] = '[body_1]';
  $handler->display->display_options['fields']['body_2']['hide_empty'] = TRUE;
  /* Field: Content: Notification Link */
  $handler->display->display_options['fields']['field_notification_link']['id'] = 'field_notification_link';
  $handler->display->display_options['fields']['field_notification_link']['table'] = 'field_data_field_notification_link';
  $handler->display->display_options['fields']['field_notification_link']['field'] = 'field_notification_link';
  $handler->display->display_options['fields']['field_notification_link']['label'] = '';
  $handler->display->display_options['fields']['field_notification_link']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_notification_link']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_notification_link']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_notification_link']['click_sort_column'] = 'url';
  /* Field: Content: Notification Link */
  $handler->display->display_options['fields']['field_notification_link_1']['id'] = 'field_notification_link_1';
  $handler->display->display_options['fields']['field_notification_link_1']['table'] = 'field_data_field_notification_link';
  $handler->display->display_options['fields']['field_notification_link_1']['field'] = 'field_notification_link';
  $handler->display->display_options['fields']['field_notification_link_1']['relationship'] = 'translation';
  $handler->display->display_options['fields']['field_notification_link_1']['label'] = '';
  $handler->display->display_options['fields']['field_notification_link_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_notification_link_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_notification_link_1']['empty'] = '[field_notification_link]';
  $handler->display->display_options['fields']['field_notification_link_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_notification_link_1']['click_sort_column'] = 'url';
  /* Field: Content: Notification Link */
  $handler->display->display_options['fields']['field_notification_link_2']['id'] = 'field_notification_link_2';
  $handler->display->display_options['fields']['field_notification_link_2']['table'] = 'field_data_field_notification_link';
  $handler->display->display_options['fields']['field_notification_link_2']['field'] = 'field_notification_link';
  $handler->display->display_options['fields']['field_notification_link_2']['relationship'] = 'translation_1';
  $handler->display->display_options['fields']['field_notification_link_2']['label'] = '';
  $handler->display->display_options['fields']['field_notification_link_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_notification_link_2']['element_wrapper_class'] = 'notification-link';
  $handler->display->display_options['fields']['field_notification_link_2']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_notification_link_2']['empty'] = '[field_notification_link_1]';
  $handler->display->display_options['fields']['field_notification_link_2']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_notification_link_2']['click_sort_column'] = 'url';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content translation: Source translation */
  $handler->display->display_options['filters']['source_translation']['id'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['table'] = 'node';
  $handler->display->display_options['filters']['source_translation']['field'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['operator'] = '1';
  $handler->display->display_options['filters']['source_translation']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'notification' => 'notification',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter']['id'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter']['operator'] = '<=';
  $handler->display->display_options['filters']['date_filter']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['date_filter']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter']['date_fields'] = array(
    'field_data_field_date_range.field_date_range_value' => 'field_data_field_date_range.field_date_range_value',
  );
  /* Filter criterion: Date: Date (node) */
  $handler->display->display_options['filters']['date_filter_1']['id'] = 'date_filter_1';
  $handler->display->display_options['filters']['date_filter_1']['table'] = 'node';
  $handler->display->display_options['filters']['date_filter_1']['field'] = 'date_filter';
  $handler->display->display_options['filters']['date_filter_1']['operator'] = '>=';
  $handler->display->display_options['filters']['date_filter_1']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['date_filter_1']['default_date'] = 'now';
  $handler->display->display_options['filters']['date_filter_1']['date_fields'] = array(
    'field_data_field_date_range.field_date_range_value2' => 'field_data_field_date_range.field_date_range_value2',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['access'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $translatables['notifications'] = array(
    t('Master'),
    t('Notifications'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Default language'),
    t('Current language'),
    t('[title]'),
    t('[title_1]'),
    t('[body]'),
    t('[body_1]'),
    t('[field_notification_link]'),
    t('[field_notification_link_1]'),
    t('Content pane'),
    t('View panes'),
  );
  $export['notifications'] = $view;

  $view = new view();
  $view->name = 'opportunity_group_images';
  $view->description = 'Co-Marketing Tool opportunity group images.';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Opportunity Group Images';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_image_unlimited' => 0,
    'field_image_unlimited_1' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_image_unlimited_1' => 'field_image_unlimited_1',
    'field_image_unlimited' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '700';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 0;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 0;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Taxonomy term: Opportunity Group Image */
  $handler->display->display_options['fields']['field_image_unlimited']['id'] = 'field_image_unlimited';
  $handler->display->display_options['fields']['field_image_unlimited']['table'] = 'field_data_field_image_unlimited';
  $handler->display->display_options['fields']['field_image_unlimited']['field'] = 'field_image_unlimited';
  $handler->display->display_options['fields']['field_image_unlimited']['label'] = '';
  $handler->display->display_options['fields']['field_image_unlimited']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_unlimited']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_unlimited']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_unlimited']['settings'] = array(
    'image_style' => '220x165',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_unlimited']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_image_unlimited']['delta_offset'] = '0';
  /* Field: Taxonomy term: Opportunity Group Image */
  $handler->display->display_options['fields']['field_image_unlimited_1']['id'] = 'field_image_unlimited_1';
  $handler->display->display_options['fields']['field_image_unlimited_1']['table'] = 'field_data_field_image_unlimited';
  $handler->display->display_options['fields']['field_image_unlimited_1']['field'] = 'field_image_unlimited';
  $handler->display->display_options['fields']['field_image_unlimited_1']['label'] = '';
  $handler->display->display_options['fields']['field_image_unlimited_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_image_unlimited_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image_unlimited_1']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_image_unlimited_1']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image_unlimited_1']['settings'] = array(
    'image_style' => '52x39',
    'image_link' => '',
  );
  $handler->display->display_options['fields']['field_image_unlimited_1']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_image_unlimited_1']['delta_offset'] = '0';
  /* Contextual filter: Taxonomy term: Term ID */
  $handler->display->display_options['arguments']['tid']['id'] = 'tid';
  $handler->display->display_options['arguments']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['arguments']['tid']['field'] = 'tid';
  $handler->display->display_options['arguments']['tid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['tid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['tid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['tid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['tid']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['tid']['validate_options']['vocabularies'] = array(
    'opportunity_group' => 'opportunity_group',
  );
  $handler->display->display_options['arguments']['tid']['validate_options']['type'] = 'convert';
  $handler->display->display_options['arguments']['tid']['validate_options']['transform'] = TRUE;
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'opportunity_group' => 'opportunity_group',
  );
  $translatables['opportunity_group_images'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
  );
  $export['opportunity_group_images'] = $view;

  $view = new view();
  $view->name = 'opportunity_group_opportunities';
  $view->description = 'Co-Marketing Tool opportunity group opportunities.';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_co_marketing_center';
  $view->human_name = 'Opportunity Group Opportunities';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Market Development Funds';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'opp_list';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['empty'] = TRUE;
  $handler->display->display_options['header']['view']['view_to_insert'] = 'opportunity_group_opportunities:sticky';
  $handler->display->display_options['header']['view']['inherit_arguments'] = TRUE;
  /* Sort criterion: Indexed Content: Delta of taxonomy_term entity referenced from field_opportunities (sort) */
  $handler->display->display_options['sorts']['search_api_aggregation_2']['id'] = 'search_api_aggregation_2';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['field'] = 'search_api_aggregation_2';
  /* Contextual filter: Indexed Content:  taxonomy_term entity referenced from field_opportunities (aggregated) */
  $handler->display->display_options['arguments']['search_api_aggregation_4']['id'] = 'search_api_aggregation_4';
  $handler->display->display_options['arguments']['search_api_aggregation_4']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['arguments']['search_api_aggregation_4']['field'] = 'search_api_aggregation_4';
  $handler->display->display_options['arguments']['search_api_aggregation_4']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['search_api_aggregation_4']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['search_api_aggregation_4']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['search_api_aggregation_4']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['search_api_aggregation_4']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['search_api_aggregation_4']['validate_options']['vocabularies'] = array(
    'opportunity_group' => 'opportunity_group',
  );
  $handler->display->display_options['arguments']['search_api_aggregation_4']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['search_api_aggregation_4']['not'] = 0;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Content: Sticky in lists */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '0';

  /* Display: Non-sticky */
  $handler = $view->new_display('panel_pane', 'Non-sticky', 'non_sticky');
  $handler->display->display_options['argument_input'] = array(
    'search_api_aggregation_4' => array(
      'type' => 'panel',
      'context' => 'entity:search_api_autocomplete_search.enabled',
      'context_optional' => 0,
      'panel' => '0',
      'fixed' => '',
      'label' => 'Indexed Content:  taxonomy_term entity referenced from field_opportunities (aggregated)',
    ),
  );

  /* Display: Sticky */
  $handler = $view->new_display('panel_pane', 'Sticky', 'sticky');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '2';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'opp_list_sticky';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Content: Sticky in lists */
  $handler->display->display_options['filters']['sticky']['id'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['filters']['sticky']['field'] = 'sticky';
  $handler->display->display_options['filters']['sticky']['value'] = '1';
  $translatables['opportunity_group_opportunities'] = array(
    t('Master'),
    t('Market Development Funds'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Non-sticky'),
    t('View panes'),
    t('Sticky'),
  );
  $export['opportunity_group_opportunities'] = $view;

  $view = new view();
  $view->name = 'opportunity_groups';
  $view->description = 'Display a list of all nodes in queue \'Opportunity Groups\'';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_co_marketing_center';
  $view->human_name = 'Opportunity Groups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Eligible Opportunities';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_opportunities_taxonomy_term_eb_name',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Translation source node » taxonomy_term entity referenced from field_opportunities: URL (indexed) */
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_url']['id'] = 'source_field_opportunities_taxonomy_term_eb_url';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_url']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_url']['field'] = 'source_field_opportunities_taxonomy_term_eb_url';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_url']['label'] = '';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_url']['link_to_entity'] = 0;
  /* Field: taxonomy_term entity referenced from field_opportunities: URL (indexed) */
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['id'] = 'field_opportunities_taxonomy_term_eb_url';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['field'] = 'field_opportunities_taxonomy_term_eb_url';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['label'] = '';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['empty'] = '[source_field_opportunities_taxonomy_term_eb_url]';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_url']['link_to_entity'] = 0;
  /* Field: Translation source node » taxonomy_term entity referenced from field_opportunities: Name (indexed) */
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['id'] = 'source_field_opportunities_taxonomy_term_eb_name';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['field'] = 'source_field_opportunities_taxonomy_term_eb_name';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['label'] = '';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['alter']['path'] = '[field_opportunities_taxonomy_term_eb_url]';
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['source_field_opportunities_taxonomy_term_eb_name']['link_to_entity'] = 0;
  /* Field: taxonomy_term entity referenced from field_opportunities: Name (indexed) */
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['id'] = 'field_opportunities_taxonomy_term_eb_name';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['field'] = 'field_opportunities_taxonomy_term_eb_name';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['label'] = '';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['alter']['path'] = '[field_opportunities_taxonomy_term_eb_url]';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['empty'] = '[source_field_opportunities_taxonomy_term_eb_name]';
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_opportunities_taxonomy_term_eb_name']['link_to_entity'] = 0;
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Sort criterion: Indexed Content: taxonomy_term entity referenced from field_opportunities » Weight (sort) */
  $handler->display->display_options['sorts']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['sorts']['search_api_aggregation_1']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['sorts']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  /* Sort criterion: Indexed Content: Sticky in lists */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Indexed Content: Delta of taxonomy_term entity referenced from field_opportunities (sort) */
  $handler->display->display_options['sorts']['search_api_aggregation_2']['id'] = 'search_api_aggregation_2';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['sorts']['search_api_aggregation_2']['field'] = 'search_api_aggregation_2';
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Content:  taxonomy_term entity referenced from field_opportunities (aggregated) */
  $handler->display->display_options['filters']['search_api_aggregation_4']['id'] = 'search_api_aggregation_4';
  $handler->display->display_options['filters']['search_api_aggregation_4']['table'] = 'search_api_index_co_marketing_center';
  $handler->display->display_options['filters']['search_api_aggregation_4']['field'] = 'search_api_aggregation_4';
  $handler->display->display_options['filters']['search_api_aggregation_4']['operator'] = 'not empty';
  $translatables['opportunity_groups'] = array(
    t('Master'),
    t('Eligible Opportunities'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('[source_field_opportunities_taxonomy_term_eb_url]'),
    t('[source_field_opportunities_taxonomy_term_eb_name]'),
  );
  $export['opportunity_groups'] = $view;

  $view = new view();
  $view->name = 'opportunity_resources';
  $view->description = 'Co-Marketing Tool opportunity resources.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Opportunity Resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Resources';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Opportunity Resource */
  $handler->display->display_options['fields']['field_opportunity_resource']['id'] = 'field_opportunity_resource';
  $handler->display->display_options['fields']['field_opportunity_resource']['table'] = 'field_data_field_opportunity_resource';
  $handler->display->display_options['fields']['field_opportunity_resource']['field'] = 'field_opportunity_resource';
  $handler->display->display_options['fields']['field_opportunity_resource']['label'] = '';
  $handler->display->display_options['fields']['field_opportunity_resource']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_opportunity_resource']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_opportunity_resource']['settings'] = array(
    'edit' => '',
    'delete' => '',
    'add' => '',
    'description' => 0,
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_opportunity_resource']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_opportunity_resource']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'opportunity' => 'opportunity',
  );
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
    'opportunity' => 'opportunity',
  );
  $translatables['opportunity_resources'] = array(
    t('Master'),
    t('Resources'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
  );
  $export['opportunity_resources'] = $view;

  $view = new view();
  $view->name = 'reports_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reports: Content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    9 => '9',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_1' => 'title_1',
    'title' => 'title',
  );
  $handler->display->display_options['style_options']['default'] = 'title_1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_account_managers_target_id']['id'] = 'field_account_managers_target_id';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['table'] = 'field_data_field_account_managers';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['field'] = 'field_account_managers_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_marketing_expert_node']['id'] = 'reverse_field_marketing_expert_node';
  $handler->display->display_options['relationships']['reverse_field_marketing_expert_node']['table'] = 'users';
  $handler->display->display_options['relationships']['reverse_field_marketing_expert_node']['field'] = 'reverse_field_marketing_expert_node';
  $handler->display->display_options['relationships']['reverse_field_marketing_expert_node']['relationship'] = 'field_account_managers_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Company Name */
  $handler->display->display_options['fields']['field_component_company_name']['id'] = 'field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['table'] = 'field_data_field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['field'] = 'field_component_company_name';
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  /* Filter criterion: Content: Title */
  $handler->display->display_options['filters']['title']['id'] = 'title';
  $handler->display->display_options['filters']['title']['table'] = 'node';
  $handler->display->display_options['filters']['title']['field'] = 'title';
  $handler->display->display_options['filters']['title']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['title']['operator'] = 'not empty';

  /* Display: Companies */
  $handler = $view->new_display('page', 'Companies', 'companies');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Companies';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'field_membership_type' => 'field_membership_type',
    'created' => 'created',
    'field_agreement_date' => 'field_agreement_date',
  );
  $handler->display->display_options['style_options']['default'] = 'title';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_membership_type' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'created' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_agreement_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Company';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Current Membership Type */
  $handler->display->display_options['fields']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['label'] = 'Membership Tier';
  $handler->display->display_options['fields']['field_membership_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_membership_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'Membership Start Date';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  /* Field: Content: Expiration Date of Current Agreement */
  $handler->display->display_options['fields']['field_agreement_date']['id'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['table'] = 'field_data_field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['field'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['label'] = 'Membership expiration date';
  $handler->display->display_options['fields']['field_agreement_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agreement_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_node] [edit_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by Name';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'en' => 'en',
    'ja' => 'ja',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Current Agreement (field_agreement_identifier) */
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['id'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['table'] = 'field_data_field_agreement_identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['field'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['operator_id'] = 'field_agreement_identifier_tid_op';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['label'] = 'Agreement Identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['operator'] = 'field_agreement_identifier_tid_op';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['identifier'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['vocabulary'] = 'membership_segments';
  /* Filter criterion: Content: Programs (field_programs) */
  $handler->display->display_options['filters']['field_programs_tid']['id'] = 'field_programs_tid';
  $handler->display->display_options['filters']['field_programs_tid']['table'] = 'field_data_field_programs';
  $handler->display->display_options['filters']['field_programs_tid']['field'] = 'field_programs_tid';
  $handler->display->display_options['filters']['field_programs_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programs_tid']['expose']['operator_id'] = 'field_programs_tid_op';
  $handler->display->display_options['filters']['field_programs_tid']['expose']['label'] = 'Programs';
  $handler->display->display_options['filters']['field_programs_tid']['expose']['operator'] = 'field_programs_tid_op';
  $handler->display->display_options['filters']['field_programs_tid']['expose']['identifier'] = 'field_programs_tid';
  $handler->display->display_options['filters']['field_programs_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    7 => 0,
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
  );
  $handler->display->display_options['filters']['field_programs_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_programs_tid']['vocabulary'] = 'programs';
  $handler->display->display_options['path'] = 'member-resource-center/reports/companies';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Companies';
  $handler->display->display_options['menu']['weight'] = '-48';
  $handler->display->display_options['menu']['name'] = 'menu-reports';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Companies Export */
  $handler = $view->new_display('views_data_export', 'Companies Export', 'companies_export');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_account_managers_target_id']['id'] = 'field_account_managers_target_id';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['table'] = 'field_data_field_account_managers';
  $handler->display->display_options['relationships']['field_account_managers_target_id']['field'] = 'field_account_managers_target_id';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['id'] = 'field_marketing_expert_target_id';
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['table'] = 'field_data_field_marketing_expert';
  $handler->display->display_options['relationships']['field_marketing_expert_target_id']['field'] = 'field_marketing_expert_target_id';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Current Agreement */
  $handler->display->display_options['fields']['field_agreement_identifier']['id'] = 'field_agreement_identifier';
  $handler->display->display_options['fields']['field_agreement_identifier']['table'] = 'field_data_field_agreement_identifier';
  $handler->display->display_options['fields']['field_agreement_identifier']['field'] = 'field_agreement_identifier';
  $handler->display->display_options['fields']['field_agreement_identifier']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agreement_identifier']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Current Membership Type */
  $handler->display->display_options['fields']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_membership_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Intel Account Managers */
  $handler->display->display_options['fields']['field_account_managers']['id'] = 'field_account_managers';
  $handler->display->display_options['fields']['field_account_managers']['table'] = 'field_data_field_account_managers';
  $handler->display->display_options['fields']['field_account_managers']['field'] = 'field_account_managers';
  $handler->display->display_options['fields']['field_account_managers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_account_managers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_account_managers']['delta_offset'] = '0';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['relationship'] = 'field_account_managers_target_id';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['relationship'] = 'field_account_managers_target_id';
  /* Field: Content: Alliance Marketing Expert */
  $handler->display->display_options['fields']['field_marketing_expert']['id'] = 'field_marketing_expert';
  $handler->display->display_options['fields']['field_marketing_expert']['table'] = 'field_data_field_marketing_expert';
  $handler->display->display_options['fields']['field_marketing_expert']['field'] = 'field_marketing_expert';
  $handler->display->display_options['fields']['field_marketing_expert']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_marketing_expert']['delta_offset'] = '0';
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name_1']['id'] = 'field_first_name_1';
  $handler->display->display_options['fields']['field_first_name_1']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name_1']['relationship'] = 'field_marketing_expert_target_id';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name_1']['id'] = 'field_last_name_1';
  $handler->display->display_options['fields']['field_last_name_1']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name_1']['relationship'] = 'field_marketing_expert_target_id';
  /* Field: Content: Intel Sponsoring Business Units */
  $handler->display->display_options['fields']['field_sponsoring_business_units']['id'] = 'field_sponsoring_business_units';
  $handler->display->display_options['fields']['field_sponsoring_business_units']['table'] = 'field_data_field_sponsoring_business_units';
  $handler->display->display_options['fields']['field_sponsoring_business_units']['field'] = 'field_sponsoring_business_units';
  $handler->display->display_options['fields']['field_sponsoring_business_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sponsoring_business_units']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_sponsoring_business_units']['delta_offset'] = '0';
  /* Field: Content: Expiration Date of Current Agreement */
  $handler->display->display_options['fields']['field_agreement_date']['id'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['table'] = 'field_data_field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['field'] = 'field_agreement_date';
  $handler->display->display_options['fields']['field_agreement_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_agreement_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Geographic Headquarters */
  $handler->display->display_options['fields']['field_geographic_region']['id'] = 'field_geographic_region';
  $handler->display->display_options['fields']['field_geographic_region']['table'] = 'field_data_field_geographic_region';
  $handler->display->display_options['fields']['field_geographic_region']['field'] = 'field_geographic_region';
  $handler->display->display_options['fields']['field_geographic_region']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_region']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_region']['delta_offset'] = '0';
  /* Field: Content: Acceptable Domains */
  $handler->display->display_options['fields']['field_acceptable_domains']['id'] = 'field_acceptable_domains';
  $handler->display->display_options['fields']['field_acceptable_domains']['table'] = 'field_data_field_acceptable_domains';
  $handler->display->display_options['fields']['field_acceptable_domains']['field'] = 'field_acceptable_domains';
  $handler->display->display_options['fields']['field_acceptable_domains']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_acceptable_domains']['delta_offset'] = '0';
  /* Field: Content: Additional Resources URL */
  $handler->display->display_options['fields']['field_additional_resources']['id'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['table'] = 'field_data_field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['field'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_additional_resources']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_additional_resources']['type'] = 'link_plain';
  /* Field: Content: Agreed to Participation Criteria */
  $handler->display->display_options['fields']['field_agreed']['id'] = 'field_agreed';
  $handler->display->display_options['fields']['field_agreed']['table'] = 'field_data_field_agreed';
  $handler->display->display_options['fields']['field_agreed']['field'] = 'field_agreed';
  $handler->display->display_options['fields']['field_agreed']['element_label_colon'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: CNDA Number */
  $handler->display->display_options['fields']['field_cnda']['id'] = 'field_cnda';
  $handler->display->display_options['fields']['field_cnda']['table'] = 'field_data_field_cnda';
  $handler->display->display_options['fields']['field_cnda']['field'] = 'field_cnda';
  $handler->display->display_options['fields']['field_cnda']['element_label_colon'] = FALSE;
  /* Field: Content: Community Tag */
  $handler->display->display_options['fields']['field_community_tag']['id'] = 'field_community_tag';
  $handler->display->display_options['fields']['field_community_tag']['table'] = 'field_data_field_community_tag';
  $handler->display->display_options['fields']['field_community_tag']['field'] = 'field_community_tag';
  $handler->display->display_options['fields']['field_community_tag']['element_label_colon'] = FALSE;
  /* Field: Content: Company Type */
  $handler->display->display_options['fields']['field_company_type']['id'] = 'field_company_type';
  $handler->display->display_options['fields']['field_company_type']['table'] = 'field_data_field_company_type';
  $handler->display->display_options['fields']['field_company_type']['field'] = 'field_company_type';
  $handler->display->display_options['fields']['field_company_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_company_type']['delta_offset'] = '0';
  /* Field: Content: Datasheet */
  $handler->display->display_options['fields']['field_datasheet']['id'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['table'] = 'field_data_field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['field'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datasheet']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_datasheet']['type'] = 'link_plain';
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['element_label_colon'] = FALSE;
  /* Field: Content: Future Agreement */
  $handler->display->display_options['fields']['field_future_membership']['id'] = 'field_future_membership';
  $handler->display->display_options['fields']['field_future_membership']['table'] = 'field_data_field_future_membership';
  $handler->display->display_options['fields']['field_future_membership']['field'] = 'field_future_membership';
  $handler->display->display_options['fields']['field_future_membership']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_future_membership']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Geographic Coverage */
  $handler->display->display_options['fields']['field_geographic_coverage']['id'] = 'field_geographic_coverage';
  $handler->display->display_options['fields']['field_geographic_coverage']['table'] = 'field_data_field_geographic_coverage';
  $handler->display->display_options['fields']['field_geographic_coverage']['field'] = 'field_geographic_coverage';
  $handler->display->display_options['fields']['field_geographic_coverage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_coverage']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_coverage']['delta_offset'] = '0';
  /* Field: Content: Intel Field Applications Engineers */
  $handler->display->display_options['fields']['field_applications_engineers']['id'] = 'field_applications_engineers';
  $handler->display->display_options['fields']['field_applications_engineers']['table'] = 'field_data_field_applications_engineers';
  $handler->display->display_options['fields']['field_applications_engineers']['field'] = 'field_applications_engineers';
  $handler->display->display_options['fields']['field_applications_engineers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_applications_engineers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_applications_engineers']['delta_offset'] = '0';
  /* Field: Content: Intel Field Sales Engineers */
  $handler->display->display_options['fields']['field_sales_engineers']['id'] = 'field_sales_engineers';
  $handler->display->display_options['fields']['field_sales_engineers']['table'] = 'field_data_field_sales_engineers';
  $handler->display->display_options['fields']['field_sales_engineers']['field'] = 'field_sales_engineers';
  $handler->display->display_options['fields']['field_sales_engineers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_sales_engineers']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_sales_engineers']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_plain';
  /* Field: Content: Promoted to front page */
  $handler->display->display_options['fields']['promote']['id'] = 'promote';
  $handler->display->display_options['fields']['promote']['table'] = 'node';
  $handler->display->display_options['fields']['promote']['field'] = 'promote';
  $handler->display->display_options['fields']['promote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['promote']['not'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Renewal Signee */
  $handler->display->display_options['fields']['field_renewal_signee']['id'] = 'field_renewal_signee';
  $handler->display->display_options['fields']['field_renewal_signee']['table'] = 'field_data_field_renewal_signee';
  $handler->display->display_options['fields']['field_renewal_signee']['field'] = 'field_renewal_signee';
  $handler->display->display_options['fields']['field_renewal_signee']['element_label_colon'] = FALSE;
  /* Field: Content: Solutions Directory ID */
  $handler->display->display_options['fields']['field_solutions_directiory_id']['id'] = 'field_solutions_directiory_id';
  $handler->display->display_options['fields']['field_solutions_directiory_id']['table'] = 'field_data_field_solutions_directiory_id';
  $handler->display->display_options['fields']['field_solutions_directiory_id']['field'] = 'field_solutions_directiory_id';
  $handler->display->display_options['fields']['field_solutions_directiory_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_solutions_directiory_id']['settings'] = array(
    'thousand_separator' => '',
    'prefix_suffix' => 1,
  );
  /* Field: Content: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'node';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Field: Content: Sticky */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sticky']['not'] = 0;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Company */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/y';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = 'Post time';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'H:i';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_1']['id'] = 'changed_1';
  $handler->display->display_options['fields']['changed_1']['table'] = 'node';
  $handler->display->display_options['fields']['changed_1']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_1']['custom_date_format'] = 'm/d/y';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_2']['id'] = 'changed_2';
  $handler->display->display_options['fields']['changed_2']['table'] = 'node';
  $handler->display->display_options['fields']['changed_2']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_2']['label'] = 'Updated time';
  $handler->display->display_options['fields']['changed_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed_2']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_2']['custom_date_format'] = 'H:i';
  /* Field: Content: Programs */
  $handler->display->display_options['fields']['field_programs']['id'] = 'field_programs';
  $handler->display->display_options['fields']['field_programs']['table'] = 'field_data_field_programs';
  $handler->display->display_options['fields']['field_programs']['field'] = 'field_programs';
  $handler->display->display_options['fields']['field_programs']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_programs']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by Name';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    14 => 0,
    23 => 0,
    15 => 0,
    22 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'en' => 'en',
    'ja' => 'ja',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    14 => 0,
    23 => 0,
    15 => 0,
    22 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Current Agreement (field_agreement_identifier) */
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['id'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['table'] = 'field_data_field_agreement_identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['field'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['operator_id'] = 'field_agreement_identifier_tid_op';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['label'] = 'Agreement Identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['operator'] = 'field_agreement_identifier_tid_op';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['identifier'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['remember_roles'] = array(
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
    14 => 0,
    23 => 0,
    15 => 0,
    22 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['vocabulary'] = 'membership_segments';
  /* Filter criterion: Content: Programs (field_programs) */
  $handler->display->display_options['filters']['field_programs_tid']['id'] = 'field_programs_tid';
  $handler->display->display_options['filters']['field_programs_tid']['table'] = 'field_data_field_programs';
  $handler->display->display_options['filters']['field_programs_tid']['field'] = 'field_programs_tid';
  $handler->display->display_options['filters']['field_programs_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_programs_tid']['expose']['operator_id'] = 'field_programs_tid_op';
  $handler->display->display_options['filters']['field_programs_tid']['expose']['label'] = 'Programs (field_programs)';
  $handler->display->display_options['filters']['field_programs_tid']['expose']['operator'] = 'field_programs_tid_op';
  $handler->display->display_options['filters']['field_programs_tid']['expose']['identifier'] = 'field_programs_tid';
  $handler->display->display_options['filters']['field_programs_tid']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['filters']['field_programs_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_programs_tid']['vocabulary'] = 'programs';
  $handler->display->display_options['path'] = 'member-resource-center/reports/companies/export';
  $handler->display->display_options['displays'] = array(
    'companies' => 'companies',
    'default' => 0,
    'solutions' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: Solutions */
  $handler = $view->new_display('page', 'Solutions', 'solutions');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Solutions';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_1' => 'title_1',
    'title' => 'title',
    'field_categories' => 'field_categories',
    'status' => 'status',
    'changed' => 'changed',
  );
  $handler->display->display_options['style_options']['default'] = 'changed';
  $handler->display->display_options['style_options']['info'] = array(
    'title_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
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
    'field_categories' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'changed' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = 'Company';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_1']['link_to_node'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'Solution';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['label'] = 'Status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['type'] = 'published-notpublished';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'Last Modified';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'short';
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['exclude'] = TRUE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['exclude'] = TRUE;
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['exclude'] = TRUE;
  /* Field: Content: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_node] [edit_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by Name or Description';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_end_user_description' => 'field_end_user_description',
  );
  /* Filter criterion: Field: Company (field_company) */
  $handler->display->display_options['filters']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['filters']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_company_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator_id'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['identifier'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'en' => 'en',
    'ja' => 'ja',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Pre-Release (field_pre_release) */
  $handler->display->display_options['filters']['field_pre_release_value']['id'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['filters']['field_pre_release_value']['field'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['group'] = 1;
  $handler->display->display_options['filters']['field_pre_release_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator_id'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['label'] = 'Pre-Release';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['identifier'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['path'] = 'member-resource-center/reports/solutions';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Solutions';
  $handler->display->display_options['menu']['weight'] = '-47';
  $handler->display->display_options['menu']['name'] = 'menu-reports';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Solutions Export */
  $handler = $view->new_display('views_data_export', 'Solutions Export', 'solutions_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Field: Company */
  $handler->display->display_options['fields']['field_company_1']['id'] = 'field_company_1';
  $handler->display->display_options['fields']['field_company_1']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company_1']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: ERPM Company Number */
  $handler->display->display_options['fields']['field_erpm_company_number']['id'] = 'field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['table'] = 'field_data_field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['field'] = 'field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['field_erpm_company_number']['label'] = 'Business ID (ERPM Company Number)';
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['element_label_colon'] = FALSE;
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_url';
  /* Field: Content: Datasheet */
  $handler->display->display_options['fields']['field_datasheet']['id'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['table'] = 'field_data_field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['field'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datasheet']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_datasheet']['type'] = 'link_url';
  /* Field: Content: Product Brief */
  $handler->display->display_options['fields']['field_brief']['id'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief']['table'] = 'field_data_field_brief';
  $handler->display->display_options['fields']['field_brief']['field'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brief']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_brief']['type'] = 'link_url';
  /* Field: Content: Additional Resources URL */
  $handler->display->display_options['fields']['field_additional_resources']['id'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['table'] = 'field_data_field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['field'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_additional_resources']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_additional_resources']['type'] = 'link_url';
  /* Field: Content: Price per unit */
  $handler->display->display_options['fields']['field_price_per_unit']['id'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['table'] = 'field_data_field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['field'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_unit']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price per 100 Units */
  $handler->display->display_options['fields']['field_price_per_100_units']['id'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['table'] = 'field_data_field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['field'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_100_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price per 1000 Units */
  $handler->display->display_options['fields']['field_price_per_1000_units']['id'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['table'] = 'field_data_field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['field'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_1000_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Pre-Release */
  $handler->display->display_options['fields']['field_pre_release']['id'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['field'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pre_release']['type'] = 'list_key';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Chipsets */
  $handler->display->display_options['fields']['field_chipsets']['id'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['table'] = 'field_data_field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['field'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chipsets']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chipsets']['delta_offset'] = '0';
  /* Field: Content: Number of independent displays */
  $handler->display->display_options['fields']['field_display_independent']['id'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['table'] = 'field_data_field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['field'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_independent']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of Display Ports/EDP Ports */
  $handler->display->display_options['fields']['field_display_port_edp']['id'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['table'] = 'field_data_field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['field'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_port_edp']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of HDMI ports */
  $handler->display->display_options['fields']['field_display_hdmi']['id'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['table'] = 'field_data_field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['field'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_hdmi']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of LVDS ports */
  $handler->display->display_options['fields']['field_display_lvds']['id'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['table'] = 'field_data_field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['field'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_lvds']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of Other ports */
  $handler->display->display_options['fields']['field_display_other']['id'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['table'] = 'field_data_field_display_other';
  $handler->display->display_options['fields']['field_display_other']['field'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_other']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of VGA ports */
  $handler->display->display_options['fields']['field_display_vga']['id'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['table'] = 'field_data_field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['field'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_vga']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Total number of ports */
  $handler->display->display_options['fields']['field_display_total']['id'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['table'] = 'field_data_field_display_total';
  $handler->display->display_options['fields']['field_display_total']['field'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_total']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Display Size */
  $handler->display->display_options['fields']['field_display_size']['id'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['table'] = 'field_data_field_display_size';
  $handler->display->display_options['fields']['field_display_size']['field'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_size']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_display_size']['delta_offset'] = '0';
  /* Field: Content: PCIe x16 Graphics Slot */
  $handler->display->display_options['fields']['field_display_pcie_x16']['id'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['table'] = 'field_data_field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['field'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_pcie_x16']['type'] = 'list_key';
  /* Field: Content: Application */
  $handler->display->display_options['fields']['field_application']['id'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['table'] = 'field_data_field_application';
  $handler->display->display_options['fields']['field_application']['field'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_application']['delta_offset'] = '0';
  /* Field: Content: Ethernet Controllers */
  $handler->display->display_options['fields']['field_ethernet_controllers']['id'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['table'] = 'field_data_field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['field'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ethernet_controllers']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ethernet_controllers']['delta_offset'] = '0';
  /* Field: Content: Geographic Location (product or service available in:) */
  $handler->display->display_options['fields']['field_geographic_location']['id'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['table'] = 'field_data_field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['field'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['label'] = 'Geographic Location';
  $handler->display->display_options['fields']['field_geographic_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_location']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_location']['delta_offset'] = '0';
  /* Field: Content: Intel® Technologies */
  $handler->display->display_options['fields']['field_intel_technologies']['id'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['table'] = 'field_data_field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['field'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intel_technologies']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_intel_technologies']['delta_offset'] = '0';
  /* Field: Content: Intel® Wireless */
  $handler->display->display_options['fields']['field_intel_wireless']['id'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['table'] = 'field_data_field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['field'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intel_wireless']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_intel_wireless']['delta_offset'] = '0';
  /* Field: Content: Market Segments */
  $handler->display->display_options['fields']['field_market_segments']['id'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['table'] = 'field_data_field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['field'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_market_segments']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_market_segments']['delta_offset'] = '0';
  /* Field: Content: ECC */
  $handler->display->display_options['fields']['field_memory_ecc']['id'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['table'] = 'field_data_field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['field'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['label'] = 'Memory - ECC';
  $handler->display->display_options['fields']['field_memory_ecc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_ecc']['type'] = 'list_key';
  /* Field: Content: Maximum Size (per processor) GB */
  $handler->display->display_options['fields']['field_memory_max']['id'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['table'] = 'field_data_field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['field'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['label'] = 'Memory - Maximum Size (per processor) GB';
  $handler->display->display_options['fields']['field_memory_max']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_max']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_memory_type']['id'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['table'] = 'field_data_field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['field'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['label'] = 'Memory - Type';
  $handler->display->display_options['fields']['field_memory_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_memory_type']['delta_offset'] = '0';
  /* Field: Content: Power */
  $handler->display->display_options['fields']['field_power']['id'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['table'] = 'field_data_field_power';
  $handler->display->display_options['fields']['field_power']['field'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_power']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_power']['delta_offset'] = '0';
  /* Field: Content: Number of processors/sockets */
  $handler->display->display_options['fields']['field_processors_count']['id'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['table'] = 'field_data_field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['field'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_processors_count']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Processor socketed */
  $handler->display->display_options['fields']['field_stds_processor_socketed']['id'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['table'] = 'field_data_field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['field'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_processor_socketed']['type'] = 'list_key';
  /* Field: Content: Processors */
  $handler->display->display_options['fields']['field_processors_list']['id'] = 'field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['table'] = 'field_data_field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['field'] = 'field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_processors_list']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_processors_list']['delta_offset'] = '0';
  /* Field: Content: Software Solutions */
  $handler->display->display_options['fields']['field_software_solutions']['id'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['table'] = 'field_data_field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['field'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_software_solutions']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_software_solutions']['delta_offset'] = '0';
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_stds_audio']['id'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['table'] = 'field_data_field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['field'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_audio']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_audio']['delta_offset'] = '0';
  /* Field: Content: Standards */
  $handler->display->display_options['fields']['field_stds_eth']['id'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['table'] = 'field_data_field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['field'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['label'] = 'Ethernet - Standards';
  $handler->display->display_options['fields']['field_stds_eth']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_eth']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_eth']['delta_offset'] = '0';
  /* Field: Content: Number of ports */
  $handler->display->display_options['fields']['field_stds_eth_ports']['id'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['table'] = 'field_data_field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['field'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['label'] = 'Ethernet - Number of ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_eth_ports']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: GPS */
  $handler->display->display_options['fields']['field_stds_gps']['id'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['table'] = 'field_data_field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['field'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_gps']['type'] = 'list_key';
  /* Field: Content: Camera Interface */
  $handler->display->display_options['fields']['field_stds_camera']['id'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['table'] = 'field_data_field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['field'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_camera']['type'] = 'list_key';
  /* Field: Content: CSIX */
  $handler->display->display_options['fields']['field_stds_csix']['id'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['table'] = 'field_data_field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['field'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_csix']['type'] = 'list_key';
  /* Field: Content: PC/104 */
  $handler->display->display_options['fields']['field_stds_pc_104']['id'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['table'] = 'field_data_field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['field'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pc_104']['type'] = 'list_key';
  /* Field: Content: Mini PCI Express */
  $handler->display->display_options['fields']['field_stds_pcie_mini']['id'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['table'] = 'field_data_field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['field'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_mini']['type'] = 'list_key';
  /* Field: Content: PCIe revision */
  $handler->display->display_options['fields']['field_stds_pcie_rev']['id'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['table'] = 'field_data_field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['field'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_rev']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['delta_offset'] = '0';
  /* Field: Content: x1 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x1']['id'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['table'] = 'field_data_field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['field'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['label'] = 'PCI Express - x1 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x2 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x2']['id'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['table'] = 'field_data_field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['field'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['label'] = 'PCI Express - x2 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x2']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x4 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x4']['id'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['table'] = 'field_data_field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['field'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['label'] = 'PCI Express - x4 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x4']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x8 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x8']['id'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['table'] = 'field_data_field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['field'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['label'] = 'PCI Express - x8 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x8']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x16 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x16']['id'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['table'] = 'field_data_field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['field'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['label'] = 'PCI Express - x16 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x16']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: PCI Express AS */
  $handler->display->display_options['fields']['field_stds_pcie_as']['id'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['table'] = 'field_data_field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['field'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_as']['type'] = 'list_key';
  /* Field: Content: SD, SDIO or eMMC */
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['id'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['table'] = 'field_data_field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['field'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['type'] = 'list_key';
  /* Field: Content: SIM socket */
  $handler->display->display_options['fields']['field_stds_sim']['id'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['table'] = 'field_data_field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['field'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_sim']['type'] = 'list_key';
  /* Field: Content: SPI */
  $handler->display->display_options['fields']['field_stds_spi']['id'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['table'] = 'field_data_field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['field'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_spi']['type'] = 'list_key';
  /* Field: Content: On the Go */
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['id'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['table'] = 'field_data_field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['field'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['label'] = 'USB - On the Go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['type'] = 'list_key';
  /* Field: Content: USB1 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb1']['id'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['table'] = 'field_data_field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['field'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USB2 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb2']['id'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['table'] = 'field_data_field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['field'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb2']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USB3 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb3']['id'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['table'] = 'field_data_field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['field'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb3']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of CFST Ports (Compact Flash) */
  $handler->display->display_options['fields']['field_stds_storage_cfst']['id'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['table'] = 'field_data_field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['field'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_cfst']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of IDE Ports */
  $handler->display->display_options['fields']['field_stds_storage_ide']['id'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['table'] = 'field_data_field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['field'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_ide']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of SATA Ports */
  $handler->display->display_options['fields']['field_stds_storage_sata']['id'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['table'] = 'field_data_field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['field'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_sata']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: SATA RAID support */
  $handler->display->display_options['fields']['field_stds_storage_raid']['id'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['table'] = 'field_data_field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['field'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_raid']['type'] = 'list_key';
  /* Field: Content: SSD size in GB */
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['id'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['table'] = 'field_data_field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['field'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Systems */
  $handler->display->display_options['fields']['field_stds_systems']['id'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['table'] = 'field_data_field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['field'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_systems']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_systems']['delta_offset'] = '0';
  /* Field: Content: WLAN (WiFi) */
  $handler->display->display_options['fields']['field_stds_wlan']['id'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['table'] = 'field_data_field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['field'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wlan']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_wlan']['delta_offset'] = '0';
  /* Field: Content: WPAN (Bluetooth) */
  $handler->display->display_options['fields']['field_stds_wpan']['id'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['table'] = 'field_data_field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['field'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wpan']['type'] = 'list_key';
  /* Field: Content: WWAN (Cellular) */
  $handler->display->display_options['fields']['field_stds_wwan']['id'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['table'] = 'field_data_field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['field'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wwan']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_wwan']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Promoted to front page */
  $handler->display->display_options['fields']['promote']['id'] = 'promote';
  $handler->display->display_options['fields']['promote']['table'] = 'node';
  $handler->display->display_options['fields']['promote']['field'] = 'promote';
  $handler->display->display_options['fields']['promote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['promote']['not'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'node';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Field: Content: Sticky */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sticky']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/y';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = 'Posted time';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'H:i';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/y';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_1']['id'] = 'changed_1';
  $handler->display->display_options['fields']['changed_1']['table'] = 'node';
  $handler->display->display_options['fields']['changed_1']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_1']['label'] = 'Updated time';
  $handler->display->display_options['fields']['changed_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_1']['custom_date_format'] = 'H:i';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by Name or Description';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_end_user_description' => 'field_end_user_description',
  );
  /* Filter criterion: Field: Company (field_company) */
  $handler->display->display_options['filters']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['filters']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator_id'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['identifier'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'en' => 'en',
    'ja' => 'ja',
  );
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Pre-Release (field_pre_release) */
  $handler->display->display_options['filters']['field_pre_release_value']['id'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['filters']['field_pre_release_value']['field'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator_id'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['label'] = 'Pre-Release';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['identifier'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['path'] = 'member-resource-center/reports/solutions/export';
  $handler->display->display_options['displays'] = array(
    'solutions' => 'solutions',
    'default' => 0,
    'companies' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: Solutions Export */
  $handler = $view->new_display('views_data_export', 'Solutions Export', 'views_data_export_1');
  $handler->display->display_options['defaults']['group_by'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['group_type'] = 'count';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  /* Field: Field: Company */
  $handler->display->display_options['fields']['field_company_1']['id'] = 'field_company_1';
  $handler->display->display_options['fields']['field_company_1']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company_1']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['element_label_colon'] = FALSE;
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_url';
  /* Field: Content: Datasheet */
  $handler->display->display_options['fields']['field_datasheet']['id'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['table'] = 'field_data_field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['field'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datasheet']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_datasheet']['type'] = 'link_url';
  /* Field: Content: Product Brief */
  $handler->display->display_options['fields']['field_brief']['id'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief']['table'] = 'field_data_field_brief';
  $handler->display->display_options['fields']['field_brief']['field'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brief']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_brief']['type'] = 'link_url';
  /* Field: Content: Additional Resources URL */
  $handler->display->display_options['fields']['field_additional_resources']['id'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['table'] = 'field_data_field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['field'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_additional_resources']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_additional_resources']['type'] = 'link_url';
  /* Field: Content: Price per unit */
  $handler->display->display_options['fields']['field_price_per_unit']['id'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['table'] = 'field_data_field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['field'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_unit']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price per 100 Units */
  $handler->display->display_options['fields']['field_price_per_100_units']['id'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['table'] = 'field_data_field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['field'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_100_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price per 1000 Units */
  $handler->display->display_options['fields']['field_price_per_1000_units']['id'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['table'] = 'field_data_field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['field'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_1000_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Pre-Release */
  $handler->display->display_options['fields']['field_pre_release']['id'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['field'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pre_release']['type'] = 'list_key';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Chipsets */
  $handler->display->display_options['fields']['field_chipsets']['id'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['table'] = 'field_data_field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['field'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chipsets']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chipsets']['delta_offset'] = '0';
  /* Field: Content: Number of independent displays */
  $handler->display->display_options['fields']['field_display_independent']['id'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['table'] = 'field_data_field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['field'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_independent']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of Display Ports/EDP Ports */
  $handler->display->display_options['fields']['field_display_port_edp']['id'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['table'] = 'field_data_field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['field'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_port_edp']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of HDMI ports */
  $handler->display->display_options['fields']['field_display_hdmi']['id'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['table'] = 'field_data_field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['field'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_hdmi']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of LVDS ports */
  $handler->display->display_options['fields']['field_display_lvds']['id'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['table'] = 'field_data_field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['field'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_lvds']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of Other ports */
  $handler->display->display_options['fields']['field_display_other']['id'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['table'] = 'field_data_field_display_other';
  $handler->display->display_options['fields']['field_display_other']['field'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_other']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of VGA ports */
  $handler->display->display_options['fields']['field_display_vga']['id'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['table'] = 'field_data_field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['field'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_vga']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Total number of ports */
  $handler->display->display_options['fields']['field_display_total']['id'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['table'] = 'field_data_field_display_total';
  $handler->display->display_options['fields']['field_display_total']['field'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_total']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Display Size */
  $handler->display->display_options['fields']['field_display_size']['id'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['table'] = 'field_data_field_display_size';
  $handler->display->display_options['fields']['field_display_size']['field'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_size']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_display_size']['delta_offset'] = '0';
  /* Field: Content: PCIe x16 Graphics Slot */
  $handler->display->display_options['fields']['field_display_pcie_x16']['id'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['table'] = 'field_data_field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['field'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_pcie_x16']['type'] = 'list_key';
  /* Field: Content: Application */
  $handler->display->display_options['fields']['field_application']['id'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['table'] = 'field_data_field_application';
  $handler->display->display_options['fields']['field_application']['field'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_application']['delta_offset'] = '0';
  /* Field: Content: Ethernet Controllers */
  $handler->display->display_options['fields']['field_ethernet_controllers']['id'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['table'] = 'field_data_field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['field'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ethernet_controllers']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ethernet_controllers']['delta_offset'] = '0';
  /* Field: Content: Geographic Location (product or service available in:) */
  $handler->display->display_options['fields']['field_geographic_location']['id'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['table'] = 'field_data_field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['field'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['label'] = 'Geographic Location';
  $handler->display->display_options['fields']['field_geographic_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_location']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_location']['delta_offset'] = '0';
  /* Field: Content: Intel® Technologies */
  $handler->display->display_options['fields']['field_intel_technologies']['id'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['table'] = 'field_data_field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['field'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intel_technologies']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_intel_technologies']['delta_offset'] = '0';
  /* Field: Content: Intel® Wireless */
  $handler->display->display_options['fields']['field_intel_wireless']['id'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['table'] = 'field_data_field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['field'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intel_wireless']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_intel_wireless']['delta_offset'] = '0';
  /* Field: Content: Market Segments */
  $handler->display->display_options['fields']['field_market_segments']['id'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['table'] = 'field_data_field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['field'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_market_segments']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_market_segments']['delta_offset'] = '0';
  /* Field: Content: ECC */
  $handler->display->display_options['fields']['field_memory_ecc']['id'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['table'] = 'field_data_field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['field'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['label'] = 'Memory - ECC';
  $handler->display->display_options['fields']['field_memory_ecc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_ecc']['type'] = 'list_key';
  /* Field: Content: Maximum Size (per processor) GB */
  $handler->display->display_options['fields']['field_memory_max']['id'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['table'] = 'field_data_field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['field'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['label'] = 'Memory - Maximum Size (per processor) GB';
  $handler->display->display_options['fields']['field_memory_max']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_max']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_memory_type']['id'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['table'] = 'field_data_field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['field'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['label'] = 'Memory - Type';
  $handler->display->display_options['fields']['field_memory_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_memory_type']['delta_offset'] = '0';
  /* Field: Content: Power */
  $handler->display->display_options['fields']['field_power']['id'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['table'] = 'field_data_field_power';
  $handler->display->display_options['fields']['field_power']['field'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_power']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_power']['delta_offset'] = '0';
  /* Field: Content: Number of processors/sockets */
  $handler->display->display_options['fields']['field_processors_count']['id'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['table'] = 'field_data_field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['field'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_processors_count']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Processor socketed */
  $handler->display->display_options['fields']['field_stds_processor_socketed']['id'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['table'] = 'field_data_field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['field'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_processor_socketed']['type'] = 'list_key';
  /* Field: Content: Processors */
  $handler->display->display_options['fields']['field_processors_list']['id'] = 'field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['table'] = 'field_data_field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['field'] = 'field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_processors_list']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_processors_list']['delta_offset'] = '0';
  /* Field: Content: Software Solutions */
  $handler->display->display_options['fields']['field_software_solutions']['id'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['table'] = 'field_data_field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['field'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_software_solutions']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_software_solutions']['delta_offset'] = '0';
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_stds_audio']['id'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['table'] = 'field_data_field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['field'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_audio']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_audio']['delta_offset'] = '0';
  /* Field: Content: Standards */
  $handler->display->display_options['fields']['field_stds_eth']['id'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['table'] = 'field_data_field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['field'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['label'] = 'Ethernet - Standards';
  $handler->display->display_options['fields']['field_stds_eth']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_eth']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_eth']['delta_offset'] = '0';
  /* Field: Content: Number of ports */
  $handler->display->display_options['fields']['field_stds_eth_ports']['id'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['table'] = 'field_data_field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['field'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['label'] = 'Ethernet - Number of ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_eth_ports']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: GPS */
  $handler->display->display_options['fields']['field_stds_gps']['id'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['table'] = 'field_data_field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['field'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_gps']['type'] = 'list_key';
  /* Field: Content: Camera Interface */
  $handler->display->display_options['fields']['field_stds_camera']['id'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['table'] = 'field_data_field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['field'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_camera']['type'] = 'list_key';
  /* Field: Content: CSIX */
  $handler->display->display_options['fields']['field_stds_csix']['id'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['table'] = 'field_data_field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['field'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_csix']['type'] = 'list_key';
  /* Field: Content: PC/104 */
  $handler->display->display_options['fields']['field_stds_pc_104']['id'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['table'] = 'field_data_field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['field'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pc_104']['type'] = 'list_key';
  /* Field: Content: Mini PCI Express */
  $handler->display->display_options['fields']['field_stds_pcie_mini']['id'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['table'] = 'field_data_field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['field'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_mini']['type'] = 'list_key';
  /* Field: Content: PCIe revision */
  $handler->display->display_options['fields']['field_stds_pcie_rev']['id'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['table'] = 'field_data_field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['field'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_rev']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['delta_offset'] = '0';
  /* Field: Content: x1 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x1']['id'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['table'] = 'field_data_field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['field'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['label'] = 'PCI Express - x1 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x2 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x2']['id'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['table'] = 'field_data_field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['field'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['label'] = 'PCI Express - x2 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x2']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x4 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x4']['id'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['table'] = 'field_data_field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['field'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['label'] = 'PCI Express - x4 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x4']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x8 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x8']['id'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['table'] = 'field_data_field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['field'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['label'] = 'PCI Express - x8 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x8']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x16 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x16']['id'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['table'] = 'field_data_field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['field'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['label'] = 'PCI Express - x16 Quantity';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x16']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: PCI Express AS */
  $handler->display->display_options['fields']['field_stds_pcie_as']['id'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['table'] = 'field_data_field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['field'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_as']['type'] = 'list_key';
  /* Field: Content: SD, SDIO or eMMC */
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['id'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['table'] = 'field_data_field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['field'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['type'] = 'list_key';
  /* Field: Content: SIM socket */
  $handler->display->display_options['fields']['field_stds_sim']['id'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['table'] = 'field_data_field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['field'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_sim']['type'] = 'list_key';
  /* Field: Content: SPI */
  $handler->display->display_options['fields']['field_stds_spi']['id'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['table'] = 'field_data_field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['field'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_spi']['type'] = 'list_key';
  /* Field: Content: On the Go */
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['id'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['table'] = 'field_data_field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['field'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['label'] = 'USB - On the Go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['type'] = 'list_key';
  /* Field: Content: USB1 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb1']['id'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['table'] = 'field_data_field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['field'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USB2 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb2']['id'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['table'] = 'field_data_field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['field'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb2']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USB3 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb3']['id'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['table'] = 'field_data_field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['field'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb3']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of CFST Ports (Compact Flash) */
  $handler->display->display_options['fields']['field_stds_storage_cfst']['id'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['table'] = 'field_data_field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['field'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_cfst']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of IDE Ports */
  $handler->display->display_options['fields']['field_stds_storage_ide']['id'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['table'] = 'field_data_field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['field'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_ide']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of SATA Ports */
  $handler->display->display_options['fields']['field_stds_storage_sata']['id'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['table'] = 'field_data_field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['field'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_sata']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: SATA RAID support */
  $handler->display->display_options['fields']['field_stds_storage_raid']['id'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['table'] = 'field_data_field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['field'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_raid']['type'] = 'list_key';
  /* Field: Content: SSD size in GB */
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['id'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['table'] = 'field_data_field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['field'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Systems */
  $handler->display->display_options['fields']['field_stds_systems']['id'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['table'] = 'field_data_field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['field'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_systems']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_systems']['delta_offset'] = '0';
  /* Field: Content: WLAN (WiFi) */
  $handler->display->display_options['fields']['field_stds_wlan']['id'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['table'] = 'field_data_field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['field'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wlan']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_wlan']['delta_offset'] = '0';
  /* Field: Content: WPAN (Bluetooth) */
  $handler->display->display_options['fields']['field_stds_wpan']['id'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['table'] = 'field_data_field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['field'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wpan']['type'] = 'list_key';
  /* Field: Content: WWAN (Cellular) */
  $handler->display->display_options['fields']['field_stds_wwan']['id'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['table'] = 'field_data_field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['field'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wwan']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_wwan']['delta_offset'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Promoted to front page */
  $handler->display->display_options['fields']['promote']['id'] = 'promote';
  $handler->display->display_options['fields']['promote']['table'] = 'node';
  $handler->display->display_options['fields']['promote']['field'] = 'promote';
  $handler->display->display_options['fields']['promote']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['promote']['not'] = 0;
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'node';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['element_label_colon'] = FALSE;
  /* Field: Content: Sticky */
  $handler->display->display_options['fields']['sticky']['id'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['table'] = 'node';
  $handler->display->display_options['fields']['sticky']['field'] = 'sticky';
  $handler->display->display_options['fields']['sticky']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['sticky']['not'] = 0;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/y';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'node';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = 'Posted time';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'H:i';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'm/d/y';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed_1']['id'] = 'changed_1';
  $handler->display->display_options['fields']['changed_1']['table'] = 'node';
  $handler->display->display_options['fields']['changed_1']['field'] = 'changed';
  $handler->display->display_options['fields']['changed_1']['label'] = 'Updated time';
  $handler->display->display_options['fields']['changed_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed_1']['custom_date_format'] = 'H:i';
  /* Field: Content: ERPM Company Number */
  $handler->display->display_options['fields']['field_erpm_company_number']['id'] = 'field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['table'] = 'field_data_field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['field'] = 'field_erpm_company_number';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by Name or Description';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
    'body' => 'body',
    'field_end_user_description' => 'field_end_user_description',
  );
  /* Filter criterion: Field: Company (field_company) */
  $handler->display->display_options['filters']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['filters']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator_id'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['identifier'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'en' => 'en',
    'ja' => 'ja',
  );
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Pre-Release (field_pre_release) */
  $handler->display->display_options['filters']['field_pre_release_value']['id'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['filters']['field_pre_release_value']['field'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator_id'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['label'] = 'Pre-Release';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['operator'] = 'field_pre_release_value_op';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['identifier'] = 'field_pre_release_value';
  $handler->display->display_options['filters']['field_pre_release_value']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['path'] = 'member-resource-center/reports/solutions/export';
  $handler->display->display_options['displays'] = array(
    'solutions' => 'solutions',
    'default' => 0,
    'companies' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: UPIC Company Export */
  $handler = $view->new_display('views_data_export', 'UPIC Company Export', 'upic_company_export');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Logo (field_logo:fid) */
  $handler->display->display_options['relationships']['field_logo_fid']['id'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['table'] = 'field_data_field_logo';
  $handler->display->display_options['relationships']['field_logo_fid']['field'] = 'field_logo_fid';
  $handler->display->display_options['relationships']['field_logo_fid']['label'] = 'Logo';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: ERPM Company Number */
  $handler->display->display_options['fields']['field_erpm_company_number']['id'] = 'field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['table'] = 'field_data_field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['field'] = 'field_erpm_company_number';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'language';
  $handler->display->display_options['fields']['language']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['label'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['element_label_colon'] = FALSE;
  /* Field: Content: Company Type */
  $handler->display->display_options['fields']['field_company_type']['id'] = 'field_company_type';
  $handler->display->display_options['fields']['field_company_type']['table'] = 'field_data_field_company_type';
  $handler->display->display_options['fields']['field_company_type']['field'] = 'field_company_type';
  $handler->display->display_options['fields']['field_company_type']['label'] = 'field_company_type';
  $handler->display->display_options['fields']['field_company_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_company_type']['alter']['text'] = '[field_company_type-tid]';
  $handler->display->display_options['fields']['field_company_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_company_type']['delta_offset'] = '0';
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = 'website_url';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_absolute';
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_website_1']['id'] = 'field_website_1';
  $handler->display->display_options['fields']['field_website_1']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website_1']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website_1']['label'] = 'website_title';
  $handler->display->display_options['fields']['field_website_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website_1']['type'] = 'link_title_plain';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_logo_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'logo_url';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: File: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'field_logo_fid';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'logo_alt';
  /* Field: File: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'field_logo_fid';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'logo_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_file_image_title_text']['type'] = 'text_plain';
  /* Field: Content: Geographic Headquarters */
  $handler->display->display_options['fields']['field_geographic_region']['id'] = 'field_geographic_region';
  $handler->display->display_options['fields']['field_geographic_region']['table'] = 'field_data_field_geographic_region';
  $handler->display->display_options['fields']['field_geographic_region']['field'] = 'field_geographic_region';
  $handler->display->display_options['fields']['field_geographic_region']['label'] = 'field_geographic_region';
  $handler->display->display_options['fields']['field_geographic_region']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_geographic_region']['alter']['text'] = '[field_geographic_region-tid]';
  $handler->display->display_options['fields']['field_geographic_region']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_region']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_region']['delta_offset'] = '0';
  /* Field: Content: Geographic Coverage */
  $handler->display->display_options['fields']['field_geographic_coverage']['id'] = 'field_geographic_coverage';
  $handler->display->display_options['fields']['field_geographic_coverage']['table'] = 'field_data_field_geographic_coverage';
  $handler->display->display_options['fields']['field_geographic_coverage']['field'] = 'field_geographic_coverage';
  $handler->display->display_options['fields']['field_geographic_coverage']['label'] = 'field_geographic_coverage';
  $handler->display->display_options['fields']['field_geographic_coverage']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_geographic_coverage']['alter']['text'] = '[field_geographic_coverage-tid]';
  $handler->display->display_options['fields']['field_geographic_coverage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_coverage']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_coverage']['delta_offset'] = '0';
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['label'] = 'field_address_country';
  $handler->display->display_options['fields']['field_address']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address']['alter']['text'] = '[field_address-country]';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_1']['id'] = 'field_address_1';
  $handler->display->display_options['fields']['field_address_1']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_1']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_1']['label'] = 'field_address_administrative_area';
  $handler->display->display_options['fields']['field_address_1']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_1']['alter']['text'] = '[field_address_1-administrative_area]';
  $handler->display->display_options['fields']['field_address_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_1']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_1']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_2']['id'] = 'field_address_2';
  $handler->display->display_options['fields']['field_address_2']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_2']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_2']['label'] = 'field_address_sub_administrative_area';
  $handler->display->display_options['fields']['field_address_2']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_2']['alter']['text'] = '[field_address_2-sub_administrative_area]';
  $handler->display->display_options['fields']['field_address_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_2']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_2']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_3']['id'] = 'field_address_3';
  $handler->display->display_options['fields']['field_address_3']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_3']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_3']['label'] = 'field_address_locality';
  $handler->display->display_options['fields']['field_address_3']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_3']['alter']['text'] = '[field_address_3-locality]';
  $handler->display->display_options['fields']['field_address_3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_3']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_3']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_4']['id'] = 'field_address_4';
  $handler->display->display_options['fields']['field_address_4']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_4']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_4']['label'] = 'field_address_dependent_locality';
  $handler->display->display_options['fields']['field_address_4']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_4']['alter']['text'] = '[field_address_4-dependent_locality]';
  $handler->display->display_options['fields']['field_address_4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_4']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_4']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_5']['id'] = 'field_address_5';
  $handler->display->display_options['fields']['field_address_5']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_5']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_5']['label'] = 'field_address_postal_code';
  $handler->display->display_options['fields']['field_address_5']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_5']['alter']['text'] = '[field_address_5-postal_code]';
  $handler->display->display_options['fields']['field_address_5']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_5']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_5']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_6']['id'] = 'field_address_6';
  $handler->display->display_options['fields']['field_address_6']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_6']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_6']['label'] = 'field_address_thoroughfare';
  $handler->display->display_options['fields']['field_address_6']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_6']['alter']['text'] = '[field_address_6-thoroughfare]';
  $handler->display->display_options['fields']['field_address_6']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_6']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_6']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_7']['id'] = 'field_address_7';
  $handler->display->display_options['fields']['field_address_7']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_7']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_7']['label'] = 'field_address_premise';
  $handler->display->display_options['fields']['field_address_7']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_7']['alter']['text'] = '[field_address_7-premise]';
  $handler->display->display_options['fields']['field_address_7']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_7']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_7']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_8']['id'] = 'field_address_8';
  $handler->display->display_options['fields']['field_address_8']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_8']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_8']['label'] = 'field_address_sub_premise';
  $handler->display->display_options['fields']['field_address_8']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_8']['alter']['text'] = '[field_address_8-sub_premise]';
  $handler->display->display_options['fields']['field_address_8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_8']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_8']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address_9']['id'] = 'field_address_9';
  $handler->display->display_options['fields']['field_address_9']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address_9']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address_9']['label'] = 'field_address_name';
  $handler->display->display_options['fields']['field_address_9']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_address_9']['alter']['text'] = '[field_address_9-name_line]';
  $handler->display->display_options['fields']['field_address_9']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address_9']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address_9']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Content: Current Membership Type */
  $handler->display->display_options['fields']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['label'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_membership_type']['alter']['text'] = '[field_membership_type-tid]';
  $handler->display->display_options['fields']['field_membership_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_membership_type']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'company' => 'company',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['language']['group'] = 1;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['path'] = 'member-resource-center/reports/upic/export/companies';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'companies' => 0,
    'solutions' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: UPIC Solution Export */
  $handler = $view->new_display('views_data_export', 'UPIC Solution Export', 'upic_solution_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Image (field_image:fid) */
  $handler->display->display_options['relationships']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['relationships']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['label'] = 'Image';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: ERPM Company Number */
  $handler->display->display_options['fields']['field_erpm_company_number']['id'] = 'field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['table'] = 'field_data_field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['field'] = 'field_erpm_company_number';
  $handler->display->display_options['fields']['field_erpm_company_number']['label'] = 'Business ID (ERPM Company Number)';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['label'] = 'path';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'language';
  $handler->display->display_options['fields']['language']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Field: Company */
  $handler->display->display_options['fields']['field_company_1']['id'] = 'field_company_1';
  $handler->display->display_options['fields']['field_company_1']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company_1']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company_1']['label'] = 'field_company';
  $handler->display->display_options['fields']['field_company_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_1']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_company_1']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['label'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['element_label_colon'] = FALSE;
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_website_1']['id'] = 'field_website_1';
  $handler->display->display_options['fields']['field_website_1']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website_1']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website_1']['label'] = 'field_website_url';
  $handler->display->display_options['fields']['field_website_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website_1']['type'] = 'link_absolute';
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = 'field_website_title';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_website']['type'] = 'link_title_plain';
  /* Field: Content: Datasheet */
  $handler->display->display_options['fields']['field_datasheet_1']['id'] = 'field_datasheet_1';
  $handler->display->display_options['fields']['field_datasheet_1']['table'] = 'field_data_field_datasheet';
  $handler->display->display_options['fields']['field_datasheet_1']['field'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet_1']['label'] = 'field_datasheet_url';
  $handler->display->display_options['fields']['field_datasheet_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datasheet_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_datasheet_1']['type'] = 'link_absolute';
  /* Field: Content: Datasheet */
  $handler->display->display_options['fields']['field_datasheet']['id'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['table'] = 'field_data_field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['field'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['label'] = 'field_datasheet_title';
  $handler->display->display_options['fields']['field_datasheet']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datasheet']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_datasheet']['type'] = 'link_title_plain';
  /* Field: Content: Product Brief */
  $handler->display->display_options['fields']['field_brief_1']['id'] = 'field_brief_1';
  $handler->display->display_options['fields']['field_brief_1']['table'] = 'field_data_field_brief';
  $handler->display->display_options['fields']['field_brief_1']['field'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief_1']['label'] = 'field_brief_url';
  $handler->display->display_options['fields']['field_brief_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brief_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_brief_1']['type'] = 'link_absolute';
  /* Field: Content: Product Brief */
  $handler->display->display_options['fields']['field_brief']['id'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief']['table'] = 'field_data_field_brief';
  $handler->display->display_options['fields']['field_brief']['field'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief']['label'] = 'field_brief_title';
  $handler->display->display_options['fields']['field_brief']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brief']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_brief']['type'] = 'link_title_plain';
  /* Field: Content: Additional Resources URL */
  $handler->display->display_options['fields']['field_additional_resources_1']['id'] = 'field_additional_resources_1';
  $handler->display->display_options['fields']['field_additional_resources_1']['table'] = 'field_data_field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources_1']['field'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources_1']['label'] = 'field_additional_resources_url';
  $handler->display->display_options['fields']['field_additional_resources_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_additional_resources_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_additional_resources_1']['type'] = 'link_absolute';
  /* Field: Content: Additional Resources URL */
  $handler->display->display_options['fields']['field_additional_resources']['id'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['table'] = 'field_data_field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['field'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['label'] = 'field_additional_resources_title';
  $handler->display->display_options['fields']['field_additional_resources']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_additional_resources']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_additional_resources']['type'] = 'link_title_plain';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'field_image_url';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: File: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'field_image_alt';
  $handler->display->display_options['fields']['field_file_image_alt_text']['element_label_colon'] = FALSE;
  /* Field: File: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'field_image_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['element_label_colon'] = FALSE;
  /* Field: Content: Price per unit */
  $handler->display->display_options['fields']['field_price_per_unit']['id'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['table'] = 'field_data_field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['field'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['label'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_unit']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price per 100 Units */
  $handler->display->display_options['fields']['field_price_per_100_units']['id'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['table'] = 'field_data_field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['field'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['label'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_100_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price per 1000 Units */
  $handler->display->display_options['fields']['field_price_per_1000_units']['id'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['table'] = 'field_data_field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['field'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['label'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_1000_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Order Button URL */
  $handler->display->display_options['fields']['field_order_button_url']['id'] = 'field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url']['table'] = 'field_data_field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url']['field'] = 'field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url']['label'] = 'field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_order_button_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_order_button_url']['type'] = 'link_absolute';
  /* Field: Content: Order Button URL */
  $handler->display->display_options['fields']['field_order_button_url_1']['id'] = 'field_order_button_url_1';
  $handler->display->display_options['fields']['field_order_button_url_1']['table'] = 'field_data_field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url_1']['field'] = 'field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url_1']['label'] = 'field_order_button_title';
  $handler->display->display_options['fields']['field_order_button_url_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_order_button_url_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_order_button_url_1']['type'] = 'link_title_plain';
  /* Field: Content: Pre-Release */
  $handler->display->display_options['fields']['field_pre_release']['id'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['field'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['label'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pre_release']['type'] = 'list_key';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_categories']['alter']['text'] = '[field_categories-tid]';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Chipsets */
  $handler->display->display_options['fields']['field_chipsets']['id'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['table'] = 'field_data_field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['field'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['label'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_chipsets']['alter']['text'] = '[field_chipsets-tid]';
  $handler->display->display_options['fields']['field_chipsets']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chipsets']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chipsets']['delta_offset'] = '0';
  /* Field: Content: Number of independent displays */
  $handler->display->display_options['fields']['field_display_independent']['id'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['table'] = 'field_data_field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['field'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['label'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_independent']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of Display Ports/EDP Ports */
  $handler->display->display_options['fields']['field_display_port_edp']['id'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['table'] = 'field_data_field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['field'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['label'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_port_edp']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of HDMI ports */
  $handler->display->display_options['fields']['field_display_hdmi']['id'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['table'] = 'field_data_field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['field'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['label'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_hdmi']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of LVDS ports */
  $handler->display->display_options['fields']['field_display_lvds']['id'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['table'] = 'field_data_field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['field'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['label'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_lvds']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of Other ports */
  $handler->display->display_options['fields']['field_display_other']['id'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['table'] = 'field_data_field_display_other';
  $handler->display->display_options['fields']['field_display_other']['field'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['label'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_other']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of VGA ports */
  $handler->display->display_options['fields']['field_display_vga']['id'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['table'] = 'field_data_field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['field'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['label'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_vga']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Total number of ports */
  $handler->display->display_options['fields']['field_display_total']['id'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['table'] = 'field_data_field_display_total';
  $handler->display->display_options['fields']['field_display_total']['field'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['label'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_total']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Display Size */
  $handler->display->display_options['fields']['field_display_size']['id'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['table'] = 'field_data_field_display_size';
  $handler->display->display_options['fields']['field_display_size']['field'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['label'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_display_size']['alter']['text'] = '[field_display_size-tid]';
  $handler->display->display_options['fields']['field_display_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_size']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_display_size']['delta_offset'] = '0';
  /* Field: Content: PCIe x16 Graphics Slot */
  $handler->display->display_options['fields']['field_display_pcie_x16']['id'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['table'] = 'field_data_field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['field'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['label'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_pcie_x16']['type'] = 'list_key';
  /* Field: Content: Application */
  $handler->display->display_options['fields']['field_application']['id'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['table'] = 'field_data_field_application';
  $handler->display->display_options['fields']['field_application']['field'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['label'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_application']['alter']['text'] = '[field_application-tid]';
  $handler->display->display_options['fields']['field_application']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_application']['delta_offset'] = '0';
  /* Field: Content: Ethernet Controllers */
  $handler->display->display_options['fields']['field_ethernet_controllers']['id'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['table'] = 'field_data_field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['field'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['label'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ethernet_controllers']['alter']['text'] = '[field_ethernet_controllers-tid]';
  $handler->display->display_options['fields']['field_ethernet_controllers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ethernet_controllers']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ethernet_controllers']['delta_offset'] = '0';
  /* Field: Content: Geographic Location (product or service available in:) */
  $handler->display->display_options['fields']['field_geographic_location']['id'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['table'] = 'field_data_field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['field'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['label'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_geographic_location']['alter']['text'] = '[field_geographic_location-tid]';
  $handler->display->display_options['fields']['field_geographic_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_location']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_location']['delta_offset'] = '0';
  /* Field: Content: Intel® Technologies */
  $handler->display->display_options['fields']['field_intel_technologies']['id'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['table'] = 'field_data_field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['field'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['label'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_intel_technologies']['alter']['text'] = '[field_intel_technologies-tid]';
  $handler->display->display_options['fields']['field_intel_technologies']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intel_technologies']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_intel_technologies']['delta_offset'] = '0';
  /* Field: Content: Intel® Wireless */
  $handler->display->display_options['fields']['field_intel_wireless']['id'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['table'] = 'field_data_field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['field'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['label'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_intel_wireless']['alter']['text'] = '[field_intel_wireless-tid]';
  $handler->display->display_options['fields']['field_intel_wireless']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intel_wireless']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_intel_wireless']['delta_offset'] = '0';
  /* Field: Content: Market Segments */
  $handler->display->display_options['fields']['field_market_segments']['id'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['table'] = 'field_data_field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['field'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['label'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_market_segments']['alter']['text'] = '[field_market_segments-tid]';
  $handler->display->display_options['fields']['field_market_segments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_market_segments']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_market_segments']['delta_offset'] = '0';
  /* Field: Content: ECC */
  $handler->display->display_options['fields']['field_memory_ecc']['id'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['table'] = 'field_data_field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['field'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['label'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_ecc']['type'] = 'list_key';
  /* Field: Content: Maximum Size (per processor) GB */
  $handler->display->display_options['fields']['field_memory_max']['id'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['table'] = 'field_data_field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['field'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['label'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_max']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_memory_type']['id'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['table'] = 'field_data_field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['field'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['label'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_memory_type']['alter']['text'] = '[field_memory_type-tid]';
  $handler->display->display_options['fields']['field_memory_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_memory_type']['delta_offset'] = '0';
  /* Field: Content: Power */
  $handler->display->display_options['fields']['field_power']['id'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['table'] = 'field_data_field_power';
  $handler->display->display_options['fields']['field_power']['field'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['label'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_power']['alter']['text'] = '[field_power-tid]';
  $handler->display->display_options['fields']['field_power']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_power']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_power']['delta_offset'] = '0';
  /* Field: Content: Number of processors/sockets */
  $handler->display->display_options['fields']['field_processors_count']['id'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['table'] = 'field_data_field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['field'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['label'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_processors_count']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Processor socketed */
  $handler->display->display_options['fields']['field_stds_processor_socketed']['id'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['table'] = 'field_data_field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['field'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['label'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_processor_socketed']['type'] = 'list_key';
  /* Field: Content: Processors */
  $handler->display->display_options['fields']['field_processors_list']['id'] = 'field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['table'] = 'field_data_field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['field'] = 'field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['label'] = 'field_processor_list';
  $handler->display->display_options['fields']['field_processors_list']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_processors_list']['alter']['text'] = '[field_processors_list-tid]';
  $handler->display->display_options['fields']['field_processors_list']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_processors_list']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_processors_list']['delta_offset'] = '0';
  /* Field: Content: Software Solutions */
  $handler->display->display_options['fields']['field_software_solutions']['id'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['table'] = 'field_data_field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['field'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['label'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_software_solutions']['alter']['text'] = '[field_software_solutions-tid]';
  $handler->display->display_options['fields']['field_software_solutions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_software_solutions']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_software_solutions']['delta_offset'] = '0';
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_stds_audio']['id'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['table'] = 'field_data_field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['field'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['label'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_audio']['alter']['text'] = '[field_stds_audio-tid]';
  $handler->display->display_options['fields']['field_stds_audio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_audio']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_audio']['delta_offset'] = '0';
  /* Field: Content: Standards */
  $handler->display->display_options['fields']['field_stds_eth']['id'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['table'] = 'field_data_field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['field'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['label'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_eth']['alter']['text'] = '[field_stds_eth-tid]';
  $handler->display->display_options['fields']['field_stds_eth']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_eth']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_eth']['delta_offset'] = '0';
  /* Field: Content: Number of ports */
  $handler->display->display_options['fields']['field_stds_eth_ports']['id'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['table'] = 'field_data_field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['field'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['label'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_eth_ports']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: GPS */
  $handler->display->display_options['fields']['field_stds_gps']['id'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['table'] = 'field_data_field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['field'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['label'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_gps']['type'] = 'list_key';
  /* Field: Content: Camera Interface */
  $handler->display->display_options['fields']['field_stds_camera']['id'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['table'] = 'field_data_field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['field'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['label'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_camera']['type'] = 'list_key';
  /* Field: Content: CSIX */
  $handler->display->display_options['fields']['field_stds_csix']['id'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['table'] = 'field_data_field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['field'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['label'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_csix']['type'] = 'list_key';
  /* Field: Content: PC/104 */
  $handler->display->display_options['fields']['field_stds_pc_104']['id'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['table'] = 'field_data_field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['field'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['label'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pc_104']['type'] = 'list_key';
  /* Field: Content: Mini PCI Express */
  $handler->display->display_options['fields']['field_stds_pcie_mini']['id'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['table'] = 'field_data_field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['field'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['label'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_mini']['type'] = 'list_key';
  /* Field: Content: PCIe revision */
  $handler->display->display_options['fields']['field_stds_pcie_rev']['id'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['table'] = 'field_data_field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['field'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['label'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_pcie_rev']['alter']['text'] = '[field_stds_pcie_rev-tid]';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_rev']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['delta_offset'] = '0';
  /* Field: Content: x1 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x1']['id'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['table'] = 'field_data_field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['field'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['label'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x2 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x2']['id'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['table'] = 'field_data_field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['field'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['label'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x2']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x4 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x4']['id'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['table'] = 'field_data_field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['field'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['label'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x4']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x8 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x8']['id'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['table'] = 'field_data_field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['field'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['label'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x8']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x16 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x16']['id'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['table'] = 'field_data_field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['field'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['label'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x16']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: PCI Express AS */
  $handler->display->display_options['fields']['field_stds_pcie_as']['id'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['table'] = 'field_data_field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['field'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['label'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_as']['type'] = 'list_key';
  /* Field: Content: SD, SDIO or eMMC */
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['id'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['table'] = 'field_data_field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['field'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['label'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['type'] = 'list_key';
  /* Field: Content: SIM socket */
  $handler->display->display_options['fields']['field_stds_sim']['id'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['table'] = 'field_data_field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['field'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['label'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_sim']['type'] = 'list_key';
  /* Field: Content: SPI */
  $handler->display->display_options['fields']['field_stds_spi']['id'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['table'] = 'field_data_field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['field'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['label'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_spi']['type'] = 'list_key';
  /* Field: Content: On the Go */
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['id'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['table'] = 'field_data_field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['field'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['label'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['type'] = 'list_key';
  /* Field: Content: USB1 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb1']['id'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['table'] = 'field_data_field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['field'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['label'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USB2 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb2']['id'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['table'] = 'field_data_field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['field'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['label'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb2']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USB3 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb3']['id'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['table'] = 'field_data_field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['field'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['label'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb3']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of CFST Ports (Compact Flash) */
  $handler->display->display_options['fields']['field_stds_storage_cfst']['id'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['table'] = 'field_data_field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['field'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['label'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_cfst']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of IDE Ports */
  $handler->display->display_options['fields']['field_stds_storage_ide']['id'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['table'] = 'field_data_field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['field'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['label'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_ide']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of SATA Ports */
  $handler->display->display_options['fields']['field_stds_storage_sata']['id'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['table'] = 'field_data_field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['field'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['label'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_sata']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: SATA RAID support */
  $handler->display->display_options['fields']['field_stds_storage_raid']['id'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['table'] = 'field_data_field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['field'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['label'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_raid']['type'] = 'list_key';
  /* Field: Content: SSD size in GB */
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['id'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['table'] = 'field_data_field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['field'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['label'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Systems */
  $handler->display->display_options['fields']['field_stds_systems']['id'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['table'] = 'field_data_field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['field'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['label'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_systems']['alter']['text'] = '[field_stds_systems-tid]';
  $handler->display->display_options['fields']['field_stds_systems']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_systems']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_systems']['delta_offset'] = '0';
  /* Field: Content: WLAN (WiFi) */
  $handler->display->display_options['fields']['field_stds_wlan']['id'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['table'] = 'field_data_field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['field'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['label'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_wlan']['alter']['text'] = '[field_stds_wlan-tid]';
  $handler->display->display_options['fields']['field_stds_wlan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wlan']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_wlan']['delta_offset'] = '0';
  /* Field: Content: WPAN (Bluetooth) */
  $handler->display->display_options['fields']['field_stds_wpan']['id'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['table'] = 'field_data_field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['field'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['label'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wpan']['type'] = 'list_key';
  /* Field: Content: WWAN (Cellular) */
  $handler->display->display_options['fields']['field_stds_wwan']['id'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['table'] = 'field_data_field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['field'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['label'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_wwan']['alter']['text'] = '[field_stds_wwan-tid]';
  $handler->display->display_options['fields']['field_stds_wwan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wwan']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_wwan']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'solution' => 'solution',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'member-resource-center/reports/upic/export/solutions';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'companies' => 0,
    'solutions' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: UPIC Component Export */
  $handler = $view->new_display('views_data_export', 'UPIC Component Export', 'upic_component_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Image (field_image:fid) */
  $handler->display->display_options['relationships']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['relationships']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['label'] = 'Image';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'language';
  $handler->display->display_options['fields']['language']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'field_image_url';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: File: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'field_image_alt';
  $handler->display->display_options['fields']['field_file_image_alt_text']['element_label_colon'] = FALSE;
  /* Field: File: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'field_image_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['element_label_colon'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Content: Company Name */
  $handler->display->display_options['fields']['field_component_company_name']['id'] = 'field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['table'] = 'field_data_field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['field'] = 'field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['label'] = 'field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['element_label_colon'] = FALSE;
  /* Field: Content: Component Webpage */
  $handler->display->display_options['fields']['field_component_webpage']['id'] = 'field_component_webpage';
  $handler->display->display_options['fields']['field_component_webpage']['table'] = 'field_data_field_component_webpage';
  $handler->display->display_options['fields']['field_component_webpage']['field'] = 'field_component_webpage';
  $handler->display->display_options['fields']['field_component_webpage']['label'] = 'field_component_webpage_url';
  $handler->display->display_options['fields']['field_component_webpage']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_webpage']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_component_webpage']['type'] = 'link_absolute';
  /* Field: Content: Component Webpage */
  $handler->display->display_options['fields']['field_component_webpage_1']['id'] = 'field_component_webpage_1';
  $handler->display->display_options['fields']['field_component_webpage_1']['table'] = 'field_data_field_component_webpage';
  $handler->display->display_options['fields']['field_component_webpage_1']['field'] = 'field_component_webpage';
  $handler->display->display_options['fields']['field_component_webpage_1']['label'] = 'field_component_webpage_title';
  $handler->display->display_options['fields']['field_component_webpage_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_webpage_1']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_component_webpage_1']['type'] = 'link_title_plain';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_categories']['alter']['text'] = '[field_categories-tid]';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  /* Field: Content: Chipsets */
  $handler->display->display_options['fields']['field_chipsets']['id'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['table'] = 'field_data_field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['field'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['label'] = 'field_chipsets';
  $handler->display->display_options['fields']['field_chipsets']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_chipsets']['alter']['text'] = '[field_chipsets-tid]';
  $handler->display->display_options['fields']['field_chipsets']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_chipsets']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_chipsets']['delta_offset'] = '0';
  /* Field: Content: Number of independent displays */
  $handler->display->display_options['fields']['field_display_independent']['id'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['table'] = 'field_data_field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['field'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['label'] = 'field_display_independent';
  $handler->display->display_options['fields']['field_display_independent']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_independent']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of Display Ports/EDP Ports */
  $handler->display->display_options['fields']['field_display_port_edp']['id'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['table'] = 'field_data_field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['field'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['label'] = 'field_display_port_edp';
  $handler->display->display_options['fields']['field_display_port_edp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_port_edp']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of HDMI ports */
  $handler->display->display_options['fields']['field_display_hdmi']['id'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['table'] = 'field_data_field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['field'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['label'] = 'field_display_hdmi';
  $handler->display->display_options['fields']['field_display_hdmi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_hdmi']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of LVDS ports */
  $handler->display->display_options['fields']['field_display_lvds']['id'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['table'] = 'field_data_field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['field'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['label'] = 'field_display_lvds';
  $handler->display->display_options['fields']['field_display_lvds']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_lvds']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of Other ports */
  $handler->display->display_options['fields']['field_display_other']['id'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['table'] = 'field_data_field_display_other';
  $handler->display->display_options['fields']['field_display_other']['field'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['label'] = 'field_display_other';
  $handler->display->display_options['fields']['field_display_other']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_other']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of VGA ports */
  $handler->display->display_options['fields']['field_display_vga']['id'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['table'] = 'field_data_field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['field'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['label'] = 'field_display_vga';
  $handler->display->display_options['fields']['field_display_vga']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_vga']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Total number of ports */
  $handler->display->display_options['fields']['field_display_total']['id'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['table'] = 'field_data_field_display_total';
  $handler->display->display_options['fields']['field_display_total']['field'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['label'] = 'field_display_total';
  $handler->display->display_options['fields']['field_display_total']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_total']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Display Size */
  $handler->display->display_options['fields']['field_display_size']['id'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['table'] = 'field_data_field_display_size';
  $handler->display->display_options['fields']['field_display_size']['field'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['label'] = 'field_display_size';
  $handler->display->display_options['fields']['field_display_size']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_display_size']['alter']['text'] = '[field_display_size-tid]';
  $handler->display->display_options['fields']['field_display_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_size']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_display_size']['delta_offset'] = '0';
  /* Field: Content: PCIe x16 Graphics Slot */
  $handler->display->display_options['fields']['field_display_pcie_x16']['id'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['table'] = 'field_data_field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['field'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['label'] = 'field_display_pcie_x16';
  $handler->display->display_options['fields']['field_display_pcie_x16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_display_pcie_x16']['type'] = 'list_key';
  /* Field: Content: Application */
  $handler->display->display_options['fields']['field_application']['id'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['table'] = 'field_data_field_application';
  $handler->display->display_options['fields']['field_application']['field'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['label'] = 'field_application';
  $handler->display->display_options['fields']['field_application']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_application']['alter']['text'] = '[field_application-tid]';
  $handler->display->display_options['fields']['field_application']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_application']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_application']['delta_offset'] = '0';
  /* Field: Content: Ethernet Controllers */
  $handler->display->display_options['fields']['field_ethernet_controllers']['id'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['table'] = 'field_data_field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['field'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['label'] = 'field_ethernet_controllers';
  $handler->display->display_options['fields']['field_ethernet_controllers']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_ethernet_controllers']['alter']['text'] = '[field_ethernet_controllers-tid]';
  $handler->display->display_options['fields']['field_ethernet_controllers']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_ethernet_controllers']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_ethernet_controllers']['delta_offset'] = '0';
  /* Field: Content: Geographic Location (product or service available in:) */
  $handler->display->display_options['fields']['field_geographic_location']['id'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['table'] = 'field_data_field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['field'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['label'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_geographic_location']['alter']['text'] = '[field_geographic_location-tid]';
  $handler->display->display_options['fields']['field_geographic_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_location']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_location']['delta_offset'] = '0';
  /* Field: Content: Intel® Technologies */
  $handler->display->display_options['fields']['field_intel_technologies']['id'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['table'] = 'field_data_field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['field'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['label'] = 'field_intel_technologies';
  $handler->display->display_options['fields']['field_intel_technologies']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_intel_technologies']['alter']['text'] = '[field_intel_technologies-tid]';
  $handler->display->display_options['fields']['field_intel_technologies']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intel_technologies']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_intel_technologies']['delta_offset'] = '0';
  /* Field: Content: Intel® Wireless */
  $handler->display->display_options['fields']['field_intel_wireless']['id'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['table'] = 'field_data_field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['field'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['label'] = 'field_intel_wireless';
  $handler->display->display_options['fields']['field_intel_wireless']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_intel_wireless']['alter']['text'] = '[field_intel_wireless-tid]';
  $handler->display->display_options['fields']['field_intel_wireless']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_intel_wireless']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_intel_wireless']['delta_offset'] = '0';
  /* Field: Content: Market Segments */
  $handler->display->display_options['fields']['field_market_segments']['id'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['table'] = 'field_data_field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['field'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['label'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_market_segments']['alter']['text'] = '[field_market_segments-tid]';
  $handler->display->display_options['fields']['field_market_segments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_market_segments']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_market_segments']['delta_offset'] = '0';
  /* Field: Content: ECC */
  $handler->display->display_options['fields']['field_memory_ecc']['id'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['table'] = 'field_data_field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['field'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['label'] = 'field_memory_ecc';
  $handler->display->display_options['fields']['field_memory_ecc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_ecc']['type'] = 'list_key';
  /* Field: Content: Maximum Size (per processor) GB */
  $handler->display->display_options['fields']['field_memory_max']['id'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['table'] = 'field_data_field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['field'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['label'] = 'field_memory_max';
  $handler->display->display_options['fields']['field_memory_max']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_max']['settings'] = array(
    'thousand_separator' => ',',
    'decimal_separator' => '.',
    'scale' => '2',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Type */
  $handler->display->display_options['fields']['field_memory_type']['id'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['table'] = 'field_data_field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['field'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['label'] = 'field_memory_type';
  $handler->display->display_options['fields']['field_memory_type']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_memory_type']['alter']['text'] = '[field_memory_type-tid]';
  $handler->display->display_options['fields']['field_memory_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_memory_type']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_memory_type']['delta_offset'] = '0';
  /* Field: Content: Power */
  $handler->display->display_options['fields']['field_power']['id'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['table'] = 'field_data_field_power';
  $handler->display->display_options['fields']['field_power']['field'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['label'] = 'field_power';
  $handler->display->display_options['fields']['field_power']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_power']['alter']['text'] = '[field_power-tid]';
  $handler->display->display_options['fields']['field_power']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_power']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_power']['delta_offset'] = '0';
  /* Field: Content: Number of processors/sockets */
  $handler->display->display_options['fields']['field_processors_count']['id'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['table'] = 'field_data_field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['field'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['label'] = 'field_processors_count';
  $handler->display->display_options['fields']['field_processors_count']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_processors_count']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Processor socketed */
  $handler->display->display_options['fields']['field_stds_processor_socketed']['id'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['table'] = 'field_data_field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['field'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['label'] = 'field_stds_processor_socketed';
  $handler->display->display_options['fields']['field_stds_processor_socketed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_processor_socketed']['type'] = 'list_key';
  /* Field: Content: Processors */
  $handler->display->display_options['fields']['field_processors_list']['id'] = 'field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['table'] = 'field_data_field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['field'] = 'field_processors_list';
  $handler->display->display_options['fields']['field_processors_list']['label'] = 'field_processor_list';
  $handler->display->display_options['fields']['field_processors_list']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_processors_list']['alter']['text'] = '[field_processors_list-tid]';
  $handler->display->display_options['fields']['field_processors_list']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_processors_list']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_processors_list']['delta_offset'] = '0';
  /* Field: Content: Software Solutions */
  $handler->display->display_options['fields']['field_software_solutions']['id'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['table'] = 'field_data_field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['field'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['label'] = 'field_software_solutions';
  $handler->display->display_options['fields']['field_software_solutions']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_software_solutions']['alter']['text'] = '[field_software_solutions-tid]';
  $handler->display->display_options['fields']['field_software_solutions']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_software_solutions']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_software_solutions']['delta_offset'] = '0';
  /* Field: Content: Audio */
  $handler->display->display_options['fields']['field_stds_audio']['id'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['table'] = 'field_data_field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['field'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['label'] = 'field_stds_audio';
  $handler->display->display_options['fields']['field_stds_audio']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_audio']['alter']['text'] = '[field_stds_audio-tid]';
  $handler->display->display_options['fields']['field_stds_audio']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_audio']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_audio']['delta_offset'] = '0';
  /* Field: Content: Standards */
  $handler->display->display_options['fields']['field_stds_eth']['id'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['table'] = 'field_data_field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['field'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['label'] = 'field_stds_eth';
  $handler->display->display_options['fields']['field_stds_eth']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_eth']['alter']['text'] = '[field_stds_eth-tid]';
  $handler->display->display_options['fields']['field_stds_eth']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_eth']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_eth']['delta_offset'] = '0';
  /* Field: Content: Number of ports */
  $handler->display->display_options['fields']['field_stds_eth_ports']['id'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['table'] = 'field_data_field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['field'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['label'] = 'field_stds_eth_ports';
  $handler->display->display_options['fields']['field_stds_eth_ports']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_eth_ports']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: GPS */
  $handler->display->display_options['fields']['field_stds_gps']['id'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['table'] = 'field_data_field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['field'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['label'] = 'field_stds_gps';
  $handler->display->display_options['fields']['field_stds_gps']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_gps']['type'] = 'list_key';
  /* Field: Content: Camera Interface */
  $handler->display->display_options['fields']['field_stds_camera']['id'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['table'] = 'field_data_field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['field'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['label'] = 'field_stds_camera';
  $handler->display->display_options['fields']['field_stds_camera']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_camera']['type'] = 'list_key';
  /* Field: Content: CSIX */
  $handler->display->display_options['fields']['field_stds_csix']['id'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['table'] = 'field_data_field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['field'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['label'] = 'field_stds_csix';
  $handler->display->display_options['fields']['field_stds_csix']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_csix']['type'] = 'list_key';
  /* Field: Content: PC/104 */
  $handler->display->display_options['fields']['field_stds_pc_104']['id'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['table'] = 'field_data_field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['field'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['label'] = 'field_stds_pc_104';
  $handler->display->display_options['fields']['field_stds_pc_104']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pc_104']['type'] = 'list_key';
  /* Field: Content: Mini PCI Express */
  $handler->display->display_options['fields']['field_stds_pcie_mini']['id'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['table'] = 'field_data_field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['field'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['label'] = 'field_stds_pcie_mini';
  $handler->display->display_options['fields']['field_stds_pcie_mini']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_mini']['type'] = 'list_key';
  /* Field: Content: PCIe revision */
  $handler->display->display_options['fields']['field_stds_pcie_rev']['id'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['table'] = 'field_data_field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['field'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['label'] = 'field_stds_pcie_rev';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_pcie_rev']['alter']['text'] = '[field_stds_pcie_rev-tid]';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_rev']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_pcie_rev']['delta_offset'] = '0';
  /* Field: Content: x1 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x1']['id'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['table'] = 'field_data_field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['field'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['label'] = 'field_stds_pcie_x1';
  $handler->display->display_options['fields']['field_stds_pcie_x1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x2 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x2']['id'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['table'] = 'field_data_field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['field'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['label'] = 'field_stds_pcie_x2';
  $handler->display->display_options['fields']['field_stds_pcie_x2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x2']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x4 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x4']['id'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['table'] = 'field_data_field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['field'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['label'] = 'field_stds_pcie_x4';
  $handler->display->display_options['fields']['field_stds_pcie_x4']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x4']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x8 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x8']['id'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['table'] = 'field_data_field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['field'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['label'] = 'field_stds_pcie_x8';
  $handler->display->display_options['fields']['field_stds_pcie_x8']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x8']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: x16 Quantity */
  $handler->display->display_options['fields']['field_stds_pcie_x16']['id'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['table'] = 'field_data_field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['field'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['label'] = 'field_stds_pcie_x16';
  $handler->display->display_options['fields']['field_stds_pcie_x16']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_x16']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: PCI Express AS */
  $handler->display->display_options['fields']['field_stds_pcie_as']['id'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['table'] = 'field_data_field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['field'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['label'] = 'field_stds_pcie_as';
  $handler->display->display_options['fields']['field_stds_pcie_as']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_pcie_as']['type'] = 'list_key';
  /* Field: Content: SD, SDIO or eMMC */
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['id'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['table'] = 'field_data_field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['field'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['label'] = 'field_stds_sd_sdio_emmc';
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_sd_sdio_emmc']['type'] = 'list_key';
  /* Field: Content: SIM socket */
  $handler->display->display_options['fields']['field_stds_sim']['id'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['table'] = 'field_data_field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['field'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['label'] = 'field_stds_sim';
  $handler->display->display_options['fields']['field_stds_sim']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_sim']['type'] = 'list_key';
  /* Field: Content: SPI */
  $handler->display->display_options['fields']['field_stds_spi']['id'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['table'] = 'field_data_field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['field'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['label'] = 'field_stds_spi';
  $handler->display->display_options['fields']['field_stds_spi']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_spi']['type'] = 'list_key';
  /* Field: Content: On the Go */
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['id'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['table'] = 'field_data_field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['field'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['label'] = 'field_stds_usb_on_the_go';
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_on_the_go']['type'] = 'list_key';
  /* Field: Content: USB1 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb1']['id'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['table'] = 'field_data_field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['field'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['label'] = 'field_stds_usb_usb1';
  $handler->display->display_options['fields']['field_stds_usb_usb1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb1']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USB2 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb2']['id'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['table'] = 'field_data_field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['field'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['label'] = 'field_stds_usb_usb2';
  $handler->display->display_options['fields']['field_stds_usb_usb2']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb2']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: USB3 Quantity */
  $handler->display->display_options['fields']['field_stds_usb_usb3']['id'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['table'] = 'field_data_field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['field'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['label'] = 'field_stds_usb_usb3';
  $handler->display->display_options['fields']['field_stds_usb_usb3']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_usb_usb3']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of CFST Ports (Compact Flash) */
  $handler->display->display_options['fields']['field_stds_storage_cfst']['id'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['table'] = 'field_data_field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['field'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['label'] = 'field_stds_storage_cfst';
  $handler->display->display_options['fields']['field_stds_storage_cfst']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_cfst']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of IDE Ports */
  $handler->display->display_options['fields']['field_stds_storage_ide']['id'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['table'] = 'field_data_field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['field'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['label'] = 'field_stds_storage_ide';
  $handler->display->display_options['fields']['field_stds_storage_ide']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_ide']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Number of SATA Ports */
  $handler->display->display_options['fields']['field_stds_storage_sata']['id'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['table'] = 'field_data_field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['field'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['label'] = 'field_stds_storage_sata';
  $handler->display->display_options['fields']['field_stds_storage_sata']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_sata']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: SATA RAID support */
  $handler->display->display_options['fields']['field_stds_storage_raid']['id'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['table'] = 'field_data_field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['field'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['label'] = 'field_stds_storage_raid';
  $handler->display->display_options['fields']['field_stds_storage_raid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_raid']['type'] = 'list_key';
  /* Field: Content: SSD size in GB */
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['id'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['table'] = 'field_data_field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['field'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['label'] = 'field_stds_storage_ssd_size';
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_storage_ssd_size']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Systems */
  $handler->display->display_options['fields']['field_stds_systems']['id'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['table'] = 'field_data_field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['field'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['label'] = 'field_stds_systems';
  $handler->display->display_options['fields']['field_stds_systems']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_systems']['alter']['text'] = '[field_stds_systems-tid]';
  $handler->display->display_options['fields']['field_stds_systems']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_systems']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_systems']['delta_offset'] = '0';
  /* Field: Content: WLAN (WiFi) */
  $handler->display->display_options['fields']['field_stds_wlan']['id'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['table'] = 'field_data_field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['field'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['label'] = 'field_stds_wlan';
  $handler->display->display_options['fields']['field_stds_wlan']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_wlan']['alter']['text'] = '[field_stds_wlan-tid]';
  $handler->display->display_options['fields']['field_stds_wlan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wlan']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_wlan']['delta_offset'] = '0';
  /* Field: Content: WPAN (Bluetooth) */
  $handler->display->display_options['fields']['field_stds_wpan']['id'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['table'] = 'field_data_field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['field'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['label'] = 'field_stds_wpan';
  $handler->display->display_options['fields']['field_stds_wpan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wpan']['type'] = 'list_key';
  /* Field: Content: WWAN (Cellular) */
  $handler->display->display_options['fields']['field_stds_wwan']['id'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['table'] = 'field_data_field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['field'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['label'] = 'field_stds_wwan';
  $handler->display->display_options['fields']['field_stds_wwan']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_stds_wwan']['alter']['text'] = '[field_stds_wwan-tid]';
  $handler->display->display_options['fields']['field_stds_wwan']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_stds_wwan']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_stds_wwan']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'component' => 'component',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'member-resource-center/reports/upic/export/components';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'companies' => 0,
    'solutions' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: UPIC Formula Export */
  $handler = $view->new_display('views_data_export', 'UPIC Formula Export', 'upic_formula_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Field: Image (field_image:fid) */
  $handler->display->display_options['relationships']['field_image_fid']['id'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['table'] = 'field_data_field_image';
  $handler->display->display_options['relationships']['field_image_fid']['field'] = 'field_image_fid';
  $handler->display->display_options['relationships']['field_image_fid']['label'] = 'Image';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['label'] = 'language';
  $handler->display->display_options['fields']['language']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['label'] = 'changed';
  $handler->display->display_options['fields']['changed']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['changed']['date_format'] = 'custom';
  $handler->display->display_options['fields']['changed']['custom_date_format'] = 'Y-m-d H:i:s';
  /* Field: Content: Pre-Release */
  $handler->display->display_options['fields']['field_pre_release']['id'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['table'] = 'field_data_field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['field'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['label'] = 'field_pre_release';
  $handler->display->display_options['fields']['field_pre_release']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_pre_release']['type'] = 'list_key';
  /* Field: File: Path */
  $handler->display->display_options['fields']['uri']['id'] = 'uri';
  $handler->display->display_options['fields']['uri']['table'] = 'file_managed';
  $handler->display->display_options['fields']['uri']['field'] = 'uri';
  $handler->display->display_options['fields']['uri']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['uri']['label'] = 'field_image_url';
  $handler->display->display_options['fields']['uri']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uri']['file_download_path'] = TRUE;
  /* Field: File: Alt Text */
  $handler->display->display_options['fields']['field_file_image_alt_text']['id'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['table'] = 'field_data_field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['field'] = 'field_file_image_alt_text';
  $handler->display->display_options['fields']['field_file_image_alt_text']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_file_image_alt_text']['label'] = 'field_image_alt';
  $handler->display->display_options['fields']['field_file_image_alt_text']['element_label_colon'] = FALSE;
  /* Field: File: Title Text */
  $handler->display->display_options['fields']['field_file_image_title_text']['id'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['table'] = 'field_data_field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['field'] = 'field_file_image_title_text';
  $handler->display->display_options['fields']['field_file_image_title_text']['relationship'] = 'field_image_fid';
  $handler->display->display_options['fields']['field_file_image_title_text']['label'] = 'field_image_title';
  $handler->display->display_options['fields']['field_file_image_title_text']['element_label_colon'] = FALSE;
  /* Field: Field: Company */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['label'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_company']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Components */
  $handler->display->display_options['fields']['field_component_group']['id'] = 'field_component_group';
  $handler->display->display_options['fields']['field_component_group']['table'] = 'field_data_field_component_group';
  $handler->display->display_options['fields']['field_component_group']['field'] = 'field_component_group';
  $handler->display->display_options['fields']['field_component_group']['label'] = 'field_component_group';
  $handler->display->display_options['fields']['field_component_group']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_component_group']['alter']['text'] = '[field_component_group-value]';
  $handler->display->display_options['fields']['field_component_group']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_group']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_component_group']['delta_offset'] = '0';
  /* Field: Content: Developer Description */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'field_data_body';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['label'] = 'body';
  $handler->display->display_options['fields']['body']['element_label_colon'] = FALSE;
  /* Field: Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'field_data_field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['label'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['element_label_colon'] = FALSE;
  /* Field: Content: System Integrators */
  $handler->display->display_options['fields']['field_system_integrators']['id'] = 'field_system_integrators';
  $handler->display->display_options['fields']['field_system_integrators']['table'] = 'field_data_field_system_integrators';
  $handler->display->display_options['fields']['field_system_integrators']['field'] = 'field_system_integrators';
  $handler->display->display_options['fields']['field_system_integrators']['label'] = 'field_system_integrators';
  $handler->display->display_options['fields']['field_system_integrators']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_system_integrators']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_system_integrators']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_system_integrators']['delta_offset'] = '0';
  /* Field: Content: Geographic Location (product or service available in:) */
  $handler->display->display_options['fields']['field_geographic_location']['id'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['table'] = 'field_data_field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['field'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['label'] = 'field_geographic_location';
  $handler->display->display_options['fields']['field_geographic_location']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_geographic_location']['alter']['text'] = '[field_geographic_location-tid]';
  $handler->display->display_options['fields']['field_geographic_location']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_location']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_location']['delta_offset'] = '0';
  /* Field: Content: Bill of Materials */
  $handler->display->display_options['fields']['field_bill_of_materials']['id'] = 'field_bill_of_materials';
  $handler->display->display_options['fields']['field_bill_of_materials']['table'] = 'field_data_field_bill_of_materials';
  $handler->display->display_options['fields']['field_bill_of_materials']['field'] = 'field_bill_of_materials';
  $handler->display->display_options['fields']['field_bill_of_materials']['label'] = 'field_bill_of_materials';
  $handler->display->display_options['fields']['field_bill_of_materials']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_bill_of_materials']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_bill_of_materials']['type'] = 'file_url_plain';
  /* Field: Content: Market Segments */
  $handler->display->display_options['fields']['field_market_segments']['id'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['table'] = 'field_data_field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['field'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['label'] = 'field_market_segments';
  $handler->display->display_options['fields']['field_market_segments']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_market_segments']['alter']['text'] = '[field_market_segments-tid]';
  $handler->display->display_options['fields']['field_market_segments']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_market_segments']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_market_segments']['delta_offset'] = '0';
  /* Field: Content: Formula Resources */
  $handler->display->display_options['fields']['field_formula_resources']['id'] = 'field_formula_resources';
  $handler->display->display_options['fields']['field_formula_resources']['table'] = 'field_data_field_formula_resources';
  $handler->display->display_options['fields']['field_formula_resources']['field'] = 'field_formula_resources';
  $handler->display->display_options['fields']['field_formula_resources']['label'] = 'field_formula_resources';
  $handler->display->display_options['fields']['field_formula_resources']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_formula_resources']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_formula_resources']['type'] = 'link_absolute';
  $handler->display->display_options['fields']['field_formula_resources']['delta_offset'] = '0';
  /* Field: Content: Categories */
  $handler->display->display_options['fields']['field_categories']['id'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['table'] = 'field_data_field_categories';
  $handler->display->display_options['fields']['field_categories']['field'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['label'] = 'field_categories';
  $handler->display->display_options['fields']['field_categories']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_categories']['alter']['text'] = '[field_categories-tid]';
  $handler->display->display_options['fields']['field_categories']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_categories']['type'] = 'i18n_taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_categories']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'formula' => 'formula',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'member-resource-center/reports/upic/export/formulas';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'companies' => 0,
    'solutions' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';

  /* Display: UPIC Component Group Export */
  $handler = $view->new_display('views_data_export', 'UPIC Component Group Export', 'upic_component_group_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Content: Components (field_component_group) */
  $handler->display->display_options['relationships']['field_component_group_value']['id'] = 'field_component_group_value';
  $handler->display->display_options['relationships']['field_component_group_value']['table'] = 'field_data_field_component_group';
  $handler->display->display_options['relationships']['field_component_group_value']['field'] = 'field_component_group_value';
  $handler->display->display_options['relationships']['field_component_group_value']['label'] = 'Component Group';
  $handler->display->display_options['relationships']['field_component_group_value']['delta'] = '-1';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field collection item: Field collection item ID */
  $handler->display->display_options['fields']['item_id']['id'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['table'] = 'field_collection_item';
  $handler->display->display_options['fields']['item_id']['field'] = 'item_id';
  $handler->display->display_options['fields']['item_id']['relationship'] = 'field_component_group_value';
  $handler->display->display_options['fields']['item_id']['label'] = 'id';
  $handler->display->display_options['fields']['item_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['item_id']['separator'] = '';
  /* Field: Field collection item: Component Type */
  $handler->display->display_options['fields']['field_component_type']['id'] = 'field_component_type';
  $handler->display->display_options['fields']['field_component_type']['table'] = 'field_data_field_component_type';
  $handler->display->display_options['fields']['field_component_type']['field'] = 'field_component_type';
  $handler->display->display_options['fields']['field_component_type']['relationship'] = 'field_component_group_value';
  $handler->display->display_options['fields']['field_component_type']['label'] = 'field_component_type';
  $handler->display->display_options['fields']['field_component_type']['element_label_colon'] = FALSE;
  /* Field: Field collection item: Component Options */
  $handler->display->display_options['fields']['field_component_options']['id'] = 'field_component_options';
  $handler->display->display_options['fields']['field_component_options']['table'] = 'field_data_field_component_options';
  $handler->display->display_options['fields']['field_component_options']['field'] = 'field_component_options';
  $handler->display->display_options['fields']['field_component_options']['relationship'] = 'field_component_group_value';
  $handler->display->display_options['fields']['field_component_options']['label'] = 'field_component_options';
  $handler->display->display_options['fields']['field_component_options']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_component_options']['type'] = 'entityreference_entity_id';
  $handler->display->display_options['fields']['field_component_options']['settings'] = array(
    'link' => 0,
  );
  $handler->display->display_options['fields']['field_component_options']['delta_offset'] = '0';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'formula' => 'formula',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'en' => 'en',
  );
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    23 => 0,
    22 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    24 => 0,
    25 => 0,
    26 => 0,
    27 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['path'] = 'member-resource-center/reports/upic/export/component-groups';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'companies' => 0,
    'solutions' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $translatables['reports_content'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Displaying @start - @end of @total'),
    t('User entity referenced from field_account_managers'),
    t('Content referencing User from field_marketing_expert'),
    t('Company Name'),
    t('Companies'),
    t('Company'),
    t('Membership Tier'),
    t('Membership Start Date'),
    t('Membership expiration date'),
    t('Link'),
    t('Edit link'),
    t('Operations'),
    t('[view_node] [edit_node]'),
    t('Search'),
    t('Search by Name'),
    t('Language'),
    t('Status'),
    t('Agreement Identifier'),
    t('Programs'),
    t('Companies Export'),
    t('User entity referenced from field_marketing_expert'),
    t('Title'),
    t('Current Agreement'),
    t('Current Membership Type'),
    t('Intel Account Managers'),
    t('First Name'),
    t('Last Name'),
    t('Alliance Marketing Expert'),
    t('Intel Sponsoring Business Units'),
    t('Expiration Date of Current Agreement'),
    t('Geographic Headquarters'),
    t('Acceptable Domains'),
    t('Additional Resources URL'),
    t('Agreed to Participation Criteria'),
    t('Categories'),
    t('CNDA Number'),
    t('Community Tag'),
    t('Company Type'),
    t('Datasheet'),
    t('Developer Description'),
    t('Business User Description – Optional'),
    t('Future Agreement'),
    t('Geographic Coverage'),
    t('Intel Field Applications Engineers'),
    t('Intel Field Sales Engineers'),
    t('Path'),
    t('Website URL'),
    t('Promoted to front page'),
    t('Published'),
    t('Renewal Signee'),
    t('Solutions Directory ID'),
    t('State'),
    t('Sticky'),
    t('Address'),
    t('Post date'),
    t('Post time'),
    t('Updated date'),
    t('Updated time'),
    t('Programs (field_programs)'),
    t('Solutions'),
    t('Solution'),
    t('Last Modified'),
    t('Search by Name or Description'),
    t('Pre-Release'),
    t('Solutions Export'),
    t('Product Brief'),
    t('Price per unit'),
    t('Price per 100 Units'),
    t('Price per 1000 Units'),
    t('Chipsets'),
    t('Number of independent displays'),
    t('Number of Display Ports/EDP Ports'),
    t('Number of HDMI ports'),
    t('Number of LVDS ports'),
    t('Number of Other ports'),
    t('Number of VGA ports'),
    t('Total number of ports'),
    t('Display Size'),
    t('PCIe x16 Graphics Slot'),
    t('Application'),
    t('Ethernet Controllers'),
    t('Geographic Location'),
    t('Intel® Technologies'),
    t('Intel® Wireless'),
    t('Market Segments'),
    t('Memory - ECC'),
    t('Memory - Maximum Size (per processor) GB'),
    t('Memory - Type'),
    t('Power'),
    t('Number of processors/sockets'),
    t('Processor socketed'),
    t('Processors'),
    t('Software Solutions'),
    t('Audio'),
    t('Ethernet - Standards'),
    t('Ethernet - Number of ports'),
    t('GPS'),
    t('Camera Interface'),
    t('CSIX'),
    t('PC/104'),
    t('Mini PCI Express'),
    t('PCIe revision'),
    t('PCI Express - x1 Quantity'),
    t('PCI Express - x2 Quantity'),
    t('PCI Express - x4 Quantity'),
    t('PCI Express - x8 Quantity'),
    t('PCI Express - x16 Quantity'),
    t('PCI Express AS'),
    t('SD, SDIO or eMMC'),
    t('SIM socket'),
    t('SPI'),
    t('USB - On the Go'),
    t('USB1 Quantity'),
    t('USB2 Quantity'),
    t('USB3 Quantity'),
    t('Number of CFST Ports (Compact Flash)'),
    t('Number of IDE Ports'),
    t('Number of SATA Ports'),
    t('SATA RAID support'),
    t('SSD size in GB'),
    t('Systems'),
    t('WLAN (WiFi)'),
    t('WPAN (Bluetooth)'),
    t('WWAN (Cellular)'),
    t('Posted time'),
    t('UPIC Company Export'),
    t('Logo'),
    t('nid'),
    t('path'),
    t('language'),
    t('title'),
    t('created'),
    t('changed'),
    t('body'),
    t('field_end_user_description'),
    t('field_company_type'),
    t('[field_company_type-tid]'),
    t('website_url'),
    t('website_title'),
    t('logo_url'),
    t('logo_alt'),
    t('logo_title'),
    t('field_geographic_region'),
    t('[field_geographic_region-tid]'),
    t('field_geographic_coverage'),
    t('[field_geographic_coverage-tid]'),
    t('field_address_country'),
    t('[field_address-country]'),
    t('field_address_administrative_area'),
    t('[field_address_1-administrative_area]'),
    t('field_address_sub_administrative_area'),
    t('[field_address_2-sub_administrative_area]'),
    t('field_address_locality'),
    t('[field_address_3-locality]'),
    t('field_address_dependent_locality'),
    t('[field_address_4-dependent_locality]'),
    t('field_address_postal_code'),
    t('[field_address_5-postal_code]'),
    t('field_address_thoroughfare'),
    t('[field_address_6-thoroughfare]'),
    t('field_address_premise'),
    t('[field_address_7-premise]'),
    t('field_address_sub_premise'),
    t('[field_address_8-sub_premise]'),
    t('field_address_name'),
    t('[field_address_9-name_line]'),
    t('field_membership_type'),
    t('[field_membership_type-tid]'),
    t('UPIC Solution Export'),
    t('Image'),
    t('field_company'),
    t('field_website_url'),
    t('field_website_title'),
    t('field_datasheet_url'),
    t('field_datasheet_title'),
    t('field_brief_url'),
    t('field_brief_title'),
    t('field_additional_resources_url'),
    t('field_additional_resources_title'),
    t('field_image_url'),
    t('field_image_alt'),
    t('field_image_title'),
    t('field_price_per_unit'),
    t('field_price_per_100_units'),
    t('field_price_per_1000_units'),
    t('field_order_button_url'),
    t('field_order_button_title'),
    t('field_pre_release'),
    t('field_categories'),
    t('[field_categories-tid]'),
    t('field_chipsets'),
    t('[field_chipsets-tid]'),
    t('field_display_independent'),
    t('field_display_port_edp'),
    t('field_display_hdmi'),
    t('field_display_lvds'),
    t('field_display_other'),
    t('field_display_vga'),
    t('field_display_total'),
    t('field_display_size'),
    t('[field_display_size-tid]'),
    t('field_display_pcie_x16'),
    t('field_application'),
    t('[field_application-tid]'),
    t('field_ethernet_controllers'),
    t('[field_ethernet_controllers-tid]'),
    t('field_geographic_location'),
    t('[field_geographic_location-tid]'),
    t('field_intel_technologies'),
    t('[field_intel_technologies-tid]'),
    t('field_intel_wireless'),
    t('[field_intel_wireless-tid]'),
    t('field_market_segments'),
    t('[field_market_segments-tid]'),
    t('field_memory_ecc'),
    t('field_memory_max'),
    t('field_memory_type'),
    t('[field_memory_type-tid]'),
    t('field_power'),
    t('[field_power-tid]'),
    t('field_processors_count'),
    t('field_stds_processor_socketed'),
    t('field_processor_list'),
    t('[field_processors_list-tid]'),
    t('field_software_solutions'),
    t('[field_software_solutions-tid]'),
    t('field_stds_audio'),
    t('[field_stds_audio-tid]'),
    t('field_stds_eth'),
    t('[field_stds_eth-tid]'),
    t('field_stds_eth_ports'),
    t('field_stds_gps'),
    t('field_stds_camera'),
    t('field_stds_csix'),
    t('field_stds_pc_104'),
    t('field_stds_pcie_mini'),
    t('field_stds_pcie_rev'),
    t('[field_stds_pcie_rev-tid]'),
    t('field_stds_pcie_x1'),
    t('field_stds_pcie_x2'),
    t('field_stds_pcie_x4'),
    t('field_stds_pcie_x8'),
    t('field_stds_pcie_x16'),
    t('field_stds_pcie_as'),
    t('field_stds_sd_sdio_emmc'),
    t('field_stds_sim'),
    t('field_stds_spi'),
    t('field_stds_usb_on_the_go'),
    t('field_stds_usb_usb1'),
    t('field_stds_usb_usb2'),
    t('field_stds_usb_usb3'),
    t('field_stds_storage_cfst'),
    t('field_stds_storage_ide'),
    t('field_stds_storage_sata'),
    t('field_stds_storage_raid'),
    t('field_stds_storage_ssd_size'),
    t('field_stds_systems'),
    t('[field_stds_systems-tid]'),
    t('field_stds_wlan'),
    t('[field_stds_wlan-tid]'),
    t('field_stds_wpan'),
    t('field_stds_wwan'),
    t('[field_stds_wwan-tid]'),
    t('UPIC Component Export'),
    t('field_component_company_name'),
    t('field_component_webpage_url'),
    t('field_component_webpage_title'),
    t('UPIC Formula Export'),
    t('field_component_group'),
    t('[field_component_group-value]'),
    t('field_system_integrators'),
    t('field_bill_of_materials'),
    t('field_formula_resources'),
    t('UPIC Component Group Export'),
    t('Component Group'),
    t('id'),
    t('.'),
    t('field_component_type'),
    t('field_component_options'),
  );
  $export['reports_content'] = $view;

  $view = new view();
  $view->name = 'reports_content_revisions';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node_revision';
  $view->human_name = 'Reports: Content Revisions';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Content Revisions';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'view revisions';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'tnid',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
    1 => array(
      'field' => 'language',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'tnid' => 'tnid',
    'nid' => 'nid',
    'language' => 'language',
    'vid' => 'vid',
    'title' => 'title',
    'state' => 'state',
    'timestamp' => 'timestamp',
    'log' => 'log',
    'name' => 'name',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'tnid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'vid' => array(
      'sortable' => 0,
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
    'state' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'log' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'name' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Content revision: Content */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['label'] = 'Node';
  /* Relationship: Content translation: Source translation */
  $handler->display->display_options['relationships']['tnid']['id'] = 'tnid';
  $handler->display->display_options['relationships']['tnid']['table'] = 'node';
  $handler->display->display_options['relationships']['tnid']['field'] = 'tnid';
  $handler->display->display_options['relationships']['tnid']['relationship'] = 'nid';
  /* Relationship: Content revision: User */
  $handler->display->display_options['relationships']['uid']['id'] = 'uid';
  $handler->display->display_options['relationships']['uid']['table'] = 'node_revision';
  $handler->display->display_options['relationships']['uid']['field'] = 'uid';
  $handler->display->display_options['relationships']['uid']['label'] = 'Revision User';
  /* Field: Content translation: Translation set node ID */
  $handler->display->display_options['fields']['tnid']['id'] = 'tnid';
  $handler->display->display_options['fields']['tnid']['table'] = 'node';
  $handler->display->display_options['fields']['tnid']['field'] = 'tnid';
  $handler->display->display_options['fields']['tnid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['tnid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['tnid']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['tnid']['alter']['path'] = 'admin/content/revisions/[tnid]';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'nid';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['relationship'] = 'nid';
  $handler->display->display_options['fields']['language']['exclude'] = TRUE;
  $handler->display->display_options['fields']['language']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['language']['alter']['text'] = '[language] - nid: [nid]';
  /* Field: Content revision: Vid */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'node_revision';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  /* Field: Content revision: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node_revision';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node_revision'] = TRUE;
  /* Field: Content revision: State */
  $handler->display->display_options['fields']['state']['id'] = 'state';
  $handler->display->display_options['fields']['state']['table'] = 'node_revision';
  $handler->display->display_options['fields']['state']['field'] = 'state';
  $handler->display->display_options['fields']['state']['label'] = 'Status';
  /* Field: Content revision: Updated date */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'node_revision';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['alter']['ellipsis'] = FALSE;
  /* Field: Content revision: Log message */
  $handler->display->display_options['fields']['log']['id'] = 'log';
  $handler->display->display_options['fields']['log']['table'] = 'node_revision';
  $handler->display->display_options['fields']['log']['field'] = 'log';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'uid';
  /* Sort criterion: Content translation: Translation set node ID */
  $handler->display->display_options['sorts']['tnid']['id'] = 'tnid';
  $handler->display->display_options['sorts']['tnid']['table'] = 'node';
  $handler->display->display_options['sorts']['tnid']['field'] = 'tnid';
  $handler->display->display_options['sorts']['tnid']['relationship'] = 'nid';
  /* Contextual filter: Content translation: Translation set node ID */
  $handler->display->display_options['arguments']['tnid']['id'] = 'tnid';
  $handler->display->display_options['arguments']['tnid']['table'] = 'node';
  $handler->display->display_options['arguments']['tnid']['field'] = 'tnid';
  $handler->display->display_options['arguments']['tnid']['relationship'] = 'nid';
  $handler->display->display_options['arguments']['tnid']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['tnid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['tnid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['tnid']['summary_options']['count'] = FALSE;
  $handler->display->display_options['arguments']['tnid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Seach by content revision title';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'title' => 'title',
  );
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['group'] = 1;
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['description'] = 'Filter by content type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: State */
  $handler->display->display_options['filters']['state']['id'] = 'state';
  $handler->display->display_options['filters']['state']['table'] = 'node';
  $handler->display->display_options['filters']['state']['field'] = 'state';
  $handler->display->display_options['filters']['state']['relationship'] = 'nid';
  $handler->display->display_options['filters']['state']['group'] = 1;
  $handler->display->display_options['filters']['state']['exposed'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['operator_id'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['label'] = 'State';
  $handler->display->display_options['filters']['state']['expose']['description'] = 'Filter by content status';
  $handler->display->display_options['filters']['state']['expose']['operator'] = 'state_op';
  $handler->display->display_options['filters']['state']['expose']['identifier'] = 'state';
  $handler->display->display_options['filters']['state']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['state']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/revisions';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Revisions';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'tab';
  $handler->display->display_options['tab_options']['title'] = 'Node';
  $handler->display->display_options['tab_options']['weight'] = '-10';
  $translatables['reports_content_revisions'] = array(
    t('Master'),
    t('Content Revisions'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Node'),
    t('Source translation'),
    t('Revision User'),
    t('Translation set node ID'),
    t('Nid'),
    t('Language'),
    t('[language] - nid: [nid]'),
    t('Vid'),
    t('Title'),
    t('Status'),
    t('Updated date'),
    t('Log message'),
    t('Name'),
    t('All'),
    t('Search'),
    t('Seach by content revision title'),
    t('Type'),
    t('Filter by content type'),
    t('State'),
    t('Filter by content status'),
    t('Page'),
  );
  $export['reports_content_revisions'] = $view;

  $view = new view();
  $view->name = 'reports_terms';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Reports: Terms';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    21 => '21',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Parent term */
  $handler->display->display_options['relationships']['parent']['id'] = 'parent';
  $handler->display->display_options['relationships']['parent']['table'] = 'taxonomy_term_hierarchy';
  $handler->display->display_options['relationships']['parent']['field'] = 'parent';
  /* Field: Taxonomy vocabulary: Vocabulary ID */
  $handler->display->display_options['fields']['vid']['id'] = 'vid';
  $handler->display->display_options['fields']['vid']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['vid']['field'] = 'vid';
  $handler->display->display_options['fields']['vid']['label'] = 'vid';
  $handler->display->display_options['fields']['vid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['vid']['separator'] = '';
  /* Field: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['fields']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['fields']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['fields']['machine_name']['label'] = 'vocabulary';
  $handler->display->display_options['fields']['machine_name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid']['id'] = 'tid';
  $handler->display->display_options['fields']['tid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid']['field'] = 'tid';
  $handler->display->display_options['fields']['tid']['label'] = 'tid';
  $handler->display->display_options['fields']['tid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid']['separator'] = '';
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['label'] = 'term';
  $handler->display->display_options['fields']['name']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['name']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  /* Field: Taxonomy term: Term ID */
  $handler->display->display_options['fields']['tid_1']['id'] = 'tid_1';
  $handler->display->display_options['fields']['tid_1']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['fields']['tid_1']['field'] = 'tid';
  $handler->display->display_options['fields']['tid_1']['relationship'] = 'parent';
  $handler->display->display_options['fields']['tid_1']['label'] = 'parent_tid';
  $handler->display->display_options['fields']['tid_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['tid_1']['separator'] = '';
  /* Sort criterion: Taxonomy vocabulary: Name */
  $handler->display->display_options['sorts']['name_1']['id'] = 'name_1';
  $handler->display->display_options['sorts']['name_1']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['sorts']['name_1']['field'] = 'name';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  /* Filter criterion: Taxonomy term: Vocabulary */
  $handler->display->display_options['filters']['vid']['id'] = 'vid';
  $handler->display->display_options['filters']['vid']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['filters']['vid']['field'] = 'vid';
  $handler->display->display_options['filters']['vid']['value'] = array(
    4 => '4',
    14 => '14',
    1 => '1',
    2 => '2',
    23 => '23',
    3 => '3',
    27 => '27',
    5 => '5',
    15 => '15',
    22 => '22',
    24 => '24',
    6 => '6',
    7 => '7',
    8 => '8',
    9 => '9',
    21 => '21',
    10 => '10',
    17 => '17',
    11 => '11',
    12 => '12',
    13 => '13',
    18 => '18',
    19 => '19',
    20 => '20',
  );

  /* Display: UPIC Term Export */
  $handler = $view->new_display('views_data_export', 'UPIC Term Export', 'upic_term_export');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view-%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 0;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['path'] = 'member-resource-center/reports/upic/export/terms';
  $handler->display->display_options['use_batch'] = 'batch';
  $translatables['reports_terms'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Parent'),
    t('vid'),
    t('.'),
    t('vocabulary'),
    t('tid'),
    t('term'),
    t('parent_tid'),
    t('UPIC Term Export'),
  );
  $export['reports_terms'] = $view;

  $view = new view();
  $view->name = 'reports_translations';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Reports: Translations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_ajax'] = TRUE;
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    9 => '9',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'type' => 'type',
    'title' => 'title',
    'status' => 'status',
    'language' => 'language',
    'nid' => 'nid',
    'nid_1' => 'nid_1',
    'nid_2' => 'nid_2',
    'nid_3' => 'nid_3',
    'nid_4' => 'nid_4',
    'nid_5' => 'nid_5',
    'nid_6' => 'nid_6',
    'nid_7' => 'nid_7',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'type' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
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
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'language' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_2' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_3' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_4' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_5' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_6' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nid_7' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['sticky'] = TRUE;
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation']['id'] = 'translation';
  $handler->display->display_options['relationships']['translation']['table'] = 'node';
  $handler->display->display_options['relationships']['translation']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation']['label'] = 'Chinese, Simplified';
  $handler->display->display_options['relationships']['translation']['language'] = 'zh-hans';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_1']['id'] = 'translation_1';
  $handler->display->display_options['relationships']['translation_1']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_1']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_1']['label'] = 'Chinese, Traditional';
  $handler->display->display_options['relationships']['translation_1']['language'] = 'zh-hant';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_2']['id'] = 'translation_2';
  $handler->display->display_options['relationships']['translation_2']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_2']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_2']['label'] = 'English';
  $handler->display->display_options['relationships']['translation_2']['language'] = 'en';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_3']['id'] = 'translation_3';
  $handler->display->display_options['relationships']['translation_3']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_3']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_3']['label'] = 'Japanese';
  $handler->display->display_options['relationships']['translation_3']['language'] = 'ja';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_4']['id'] = 'translation_4';
  $handler->display->display_options['relationships']['translation_4']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_4']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_4']['label'] = 'Korean';
  $handler->display->display_options['relationships']['translation_4']['language'] = 'ko';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_5']['id'] = 'translation_5';
  $handler->display->display_options['relationships']['translation_5']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_5']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_5']['label'] = 'Portuguese, Brazil';
  $handler->display->display_options['relationships']['translation_5']['language'] = 'pt-br';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_6']['id'] = 'translation_6';
  $handler->display->display_options['relationships']['translation_6']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_6']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_6']['label'] = 'Russian';
  $handler->display->display_options['relationships']['translation_6']['language'] = 'ru';
  /* Relationship: Content translation: Translations */
  $handler->display->display_options['relationships']['translation_7']['id'] = 'translation_7';
  $handler->display->display_options['relationships']['translation_7']['table'] = 'node';
  $handler->display->display_options['relationships']['translation_7']['field'] = 'translation';
  $handler->display->display_options['relationships']['translation_7']['label'] = 'Spanish';
  $handler->display->display_options['relationships']['translation_7']['language'] = 'es';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'node';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  /* Field: Content: Published */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'node';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: Content: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'node';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'translation';
  $handler->display->display_options['fields']['nid']['label'] = 'Chinese, Simplified';
  $handler->display->display_options['fields']['nid']['link_to_node'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_1']['id'] = 'nid_1';
  $handler->display->display_options['fields']['nid_1']['table'] = 'node';
  $handler->display->display_options['fields']['nid_1']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_1']['relationship'] = 'translation_1';
  $handler->display->display_options['fields']['nid_1']['label'] = 'Chinese, Traditional';
  $handler->display->display_options['fields']['nid_1']['link_to_node'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_2']['id'] = 'nid_2';
  $handler->display->display_options['fields']['nid_2']['table'] = 'node';
  $handler->display->display_options['fields']['nid_2']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_2']['relationship'] = 'translation_2';
  $handler->display->display_options['fields']['nid_2']['label'] = 'English';
  $handler->display->display_options['fields']['nid_2']['link_to_node'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_3']['id'] = 'nid_3';
  $handler->display->display_options['fields']['nid_3']['table'] = 'node';
  $handler->display->display_options['fields']['nid_3']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_3']['relationship'] = 'translation_3';
  $handler->display->display_options['fields']['nid_3']['label'] = 'Japanese';
  $handler->display->display_options['fields']['nid_3']['link_to_node'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_4']['id'] = 'nid_4';
  $handler->display->display_options['fields']['nid_4']['table'] = 'node';
  $handler->display->display_options['fields']['nid_4']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_4']['relationship'] = 'translation_4';
  $handler->display->display_options['fields']['nid_4']['label'] = 'Korean';
  $handler->display->display_options['fields']['nid_4']['link_to_node'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_5']['id'] = 'nid_5';
  $handler->display->display_options['fields']['nid_5']['table'] = 'node';
  $handler->display->display_options['fields']['nid_5']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_5']['relationship'] = 'translation_5';
  $handler->display->display_options['fields']['nid_5']['label'] = 'Portuguese, Brazil';
  $handler->display->display_options['fields']['nid_5']['link_to_node'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_6']['id'] = 'nid_6';
  $handler->display->display_options['fields']['nid_6']['table'] = 'node';
  $handler->display->display_options['fields']['nid_6']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_6']['relationship'] = 'translation_6';
  $handler->display->display_options['fields']['nid_6']['label'] = 'Russian';
  $handler->display->display_options['fields']['nid_6']['link_to_node'] = TRUE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid_7']['id'] = 'nid_7';
  $handler->display->display_options['fields']['nid_7']['table'] = 'node';
  $handler->display->display_options['fields']['nid_7']['field'] = 'nid';
  $handler->display->display_options['fields']['nid_7']['relationship'] = 'translation_7';
  $handler->display->display_options['fields']['nid_7']['label'] = 'Spanish';
  $handler->display->display_options['fields']['nid_7']['link_to_node'] = TRUE;
  /* Sort criterion: Content: Type */
  $handler->display->display_options['sorts']['type']['id'] = 'type';
  $handler->display->display_options['sorts']['type']['table'] = 'node';
  $handler->display->display_options['sorts']['type']['field'] = 'type';
  /* Sort criterion: Content translation: Translation set node ID */
  $handler->display->display_options['sorts']['tnid']['id'] = 'tnid';
  $handler->display->display_options['sorts']['tnid']['table'] = 'node';
  $handler->display->display_options['sorts']['tnid']['field'] = 'tnid';
  /* Filter criterion: Content translation: Source translation */
  $handler->display->display_options['filters']['source_translation']['id'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['table'] = 'node';
  $handler->display->display_options['filters']['source_translation']['field'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['operator'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'all' => 'all',
    'company' => 'company',
    'notification' => 'notification',
    'opportunity' => 'opportunity',
    'page' => 'page',
    'solution' => 'solution',
  );
  $handler->display->display_options['filters']['type']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['operator_id'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['label'] = 'Type';
  $handler->display->display_options['filters']['type']['expose']['operator'] = 'type_op';
  $handler->display->display_options['filters']['type']['expose']['identifier'] = 'type';
  $handler->display->display_options['filters']['type']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['type']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['type']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Status';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    'zh-hans' => 'zh-hans',
    'zh-hant' => 'zh-hant',
    'en' => 'en',
    'ja' => 'ja',
    'ko' => 'ko',
    'pt-br' => 'pt-br',
    'ru' => 'ru',
    'es' => 'es',
  );
  $handler->display->display_options['filters']['language']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['operator_id'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['label'] = 'Source Language';
  $handler->display->display_options['filters']['language']['expose']['operator'] = 'language_op';
  $handler->display->display_options['filters']['language']['expose']['identifier'] = 'language';
  $handler->display->display_options['filters']['language']['expose']['multiple'] = TRUE;
  $handler->display->display_options['filters']['language']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language']['expose']['reduce'] = TRUE;
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_1']['id'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['table'] = 'node';
  $handler->display->display_options['filters']['language_1']['field'] = 'language';
  $handler->display->display_options['filters']['language_1']['relationship'] = 'translation';
  $handler->display->display_options['filters']['language_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language_1']['expose']['operator_id'] = 'language_1_op';
  $handler->display->display_options['filters']['language_1']['expose']['label'] = 'Chinese, Simplified';
  $handler->display->display_options['filters']['language_1']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['language_1']['expose']['operator'] = 'language_1_op';
  $handler->display->display_options['filters']['language_1']['expose']['identifier'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['language_1']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['language_1']['group_info']['label'] = 'Chinese, Simplified';
  $handler->display->display_options['filters']['language_1']['group_info']['identifier'] = 'language_1';
  $handler->display->display_options['filters']['language_1']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Translated',
      'operator' => 'not empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
    2 => array(
      'title' => 'Not translated',
      'operator' => 'empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_2']['id'] = 'language_2';
  $handler->display->display_options['filters']['language_2']['table'] = 'node';
  $handler->display->display_options['filters']['language_2']['field'] = 'language';
  $handler->display->display_options['filters']['language_2']['relationship'] = 'translation_1';
  $handler->display->display_options['filters']['language_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language_2']['expose']['operator_id'] = 'language_2_op';
  $handler->display->display_options['filters']['language_2']['expose']['label'] = 'Chinese, Traditional';
  $handler->display->display_options['filters']['language_2']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['language_2']['expose']['operator'] = 'language_2_op';
  $handler->display->display_options['filters']['language_2']['expose']['identifier'] = 'language_2';
  $handler->display->display_options['filters']['language_2']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language_2']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['language_2']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['language_2']['group_info']['label'] = 'Chinese, Traditional';
  $handler->display->display_options['filters']['language_2']['group_info']['identifier'] = 'language_2';
  $handler->display->display_options['filters']['language_2']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Translated',
      'operator' => 'not empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
    2 => array(
      'title' => 'Not translated',
      'operator' => 'empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_3']['id'] = 'language_3';
  $handler->display->display_options['filters']['language_3']['table'] = 'node';
  $handler->display->display_options['filters']['language_3']['field'] = 'language';
  $handler->display->display_options['filters']['language_3']['relationship'] = 'translation_2';
  $handler->display->display_options['filters']['language_3']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language_3']['expose']['operator_id'] = 'language_3_op';
  $handler->display->display_options['filters']['language_3']['expose']['label'] = 'English';
  $handler->display->display_options['filters']['language_3']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['language_3']['expose']['operator'] = 'language_3_op';
  $handler->display->display_options['filters']['language_3']['expose']['identifier'] = 'language_3';
  $handler->display->display_options['filters']['language_3']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language_3']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['language_3']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['language_3']['group_info']['label'] = 'English';
  $handler->display->display_options['filters']['language_3']['group_info']['identifier'] = 'language_3';
  $handler->display->display_options['filters']['language_3']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Translated',
      'operator' => 'not empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
    2 => array(
      'title' => 'Not translated',
      'operator' => 'empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_4']['id'] = 'language_4';
  $handler->display->display_options['filters']['language_4']['table'] = 'node';
  $handler->display->display_options['filters']['language_4']['field'] = 'language';
  $handler->display->display_options['filters']['language_4']['relationship'] = 'translation_3';
  $handler->display->display_options['filters']['language_4']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language_4']['expose']['operator_id'] = 'language_4_op';
  $handler->display->display_options['filters']['language_4']['expose']['label'] = 'Japanese';
  $handler->display->display_options['filters']['language_4']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['language_4']['expose']['operator'] = 'language_4_op';
  $handler->display->display_options['filters']['language_4']['expose']['identifier'] = 'language_4';
  $handler->display->display_options['filters']['language_4']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language_4']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['language_4']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['language_4']['group_info']['label'] = 'Japanese';
  $handler->display->display_options['filters']['language_4']['group_info']['identifier'] = 'language_4';
  $handler->display->display_options['filters']['language_4']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Translated',
      'operator' => 'not empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
    2 => array(
      'title' => 'Not translated',
      'operator' => 'empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_5']['id'] = 'language_5';
  $handler->display->display_options['filters']['language_5']['table'] = 'node';
  $handler->display->display_options['filters']['language_5']['field'] = 'language';
  $handler->display->display_options['filters']['language_5']['relationship'] = 'translation_4';
  $handler->display->display_options['filters']['language_5']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language_5']['expose']['operator_id'] = 'language_5_op';
  $handler->display->display_options['filters']['language_5']['expose']['label'] = 'Korean';
  $handler->display->display_options['filters']['language_5']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['language_5']['expose']['operator'] = 'language_5_op';
  $handler->display->display_options['filters']['language_5']['expose']['identifier'] = 'language_5';
  $handler->display->display_options['filters']['language_5']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language_5']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['language_5']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['language_5']['group_info']['label'] = 'Korean';
  $handler->display->display_options['filters']['language_5']['group_info']['identifier'] = 'language_5';
  $handler->display->display_options['filters']['language_5']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Translated',
      'operator' => 'not empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
    2 => array(
      'title' => 'Not translated',
      'operator' => 'empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_6']['id'] = 'language_6';
  $handler->display->display_options['filters']['language_6']['table'] = 'node';
  $handler->display->display_options['filters']['language_6']['field'] = 'language';
  $handler->display->display_options['filters']['language_6']['relationship'] = 'translation_5';
  $handler->display->display_options['filters']['language_6']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language_6']['expose']['operator_id'] = 'language_6_op';
  $handler->display->display_options['filters']['language_6']['expose']['label'] = 'Portuguese, Brazil';
  $handler->display->display_options['filters']['language_6']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['language_6']['expose']['operator'] = 'language_6_op';
  $handler->display->display_options['filters']['language_6']['expose']['identifier'] = 'language_6';
  $handler->display->display_options['filters']['language_6']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language_6']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['language_6']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['language_6']['group_info']['label'] = 'Portuguese, Brazil';
  $handler->display->display_options['filters']['language_6']['group_info']['identifier'] = 'language_6';
  $handler->display->display_options['filters']['language_6']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Translated',
      'operator' => 'not empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
    2 => array(
      'title' => 'Not translated',
      'operator' => 'empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_7']['id'] = 'language_7';
  $handler->display->display_options['filters']['language_7']['table'] = 'node';
  $handler->display->display_options['filters']['language_7']['field'] = 'language';
  $handler->display->display_options['filters']['language_7']['relationship'] = 'translation_6';
  $handler->display->display_options['filters']['language_7']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language_7']['expose']['operator_id'] = 'language_7_op';
  $handler->display->display_options['filters']['language_7']['expose']['label'] = 'Russian';
  $handler->display->display_options['filters']['language_7']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['language_7']['expose']['operator'] = 'language_7_op';
  $handler->display->display_options['filters']['language_7']['expose']['identifier'] = 'language_7';
  $handler->display->display_options['filters']['language_7']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['language_7']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['language_7']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['language_7']['group_info']['label'] = 'Russian';
  $handler->display->display_options['filters']['language_7']['group_info']['identifier'] = 'language_7';
  $handler->display->display_options['filters']['language_7']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Translated',
      'operator' => 'not empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
    2 => array(
      'title' => 'Not translated',
      'operator' => 'empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language_8']['id'] = 'language_8';
  $handler->display->display_options['filters']['language_8']['table'] = 'node';
  $handler->display->display_options['filters']['language_8']['field'] = 'language';
  $handler->display->display_options['filters']['language_8']['relationship'] = 'translation_7';
  $handler->display->display_options['filters']['language_8']['exposed'] = TRUE;
  $handler->display->display_options['filters']['language_8']['expose']['operator_id'] = 'language_8_op';
  $handler->display->display_options['filters']['language_8']['expose']['label'] = 'Language';
  $handler->display->display_options['filters']['language_8']['expose']['operator'] = 'language_8_op';
  $handler->display->display_options['filters']['language_8']['expose']['identifier'] = 'language_8';
  $handler->display->display_options['filters']['language_8']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['language_8']['group_info']['label'] = 'Spanish';
  $handler->display->display_options['filters']['language_8']['group_info']['identifier'] = 'language_8';
  $handler->display->display_options['filters']['language_8']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Translated',
      'operator' => 'not empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
    2 => array(
      'title' => 'Not translated',
      'operator' => 'empty',
      'value' => array(
        'all' => 0,
        '***CURRENT_LANGUAGE***' => 0,
        '***DEFAULT_LANGUAGE***' => 0,
        'und' => 0,
        'zh-hans' => 0,
        'zh-hant' => 0,
        'en' => 0,
        'ja' => 0,
        'ko' => 0,
        'pt-br' => 0,
        'ru' => 0,
        'es' => 0,
      ),
    ),
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page_1');
  $handler->display->display_options['path'] = 'admin/content/translations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Translations';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['reports_translations'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Chinese, Simplified'),
    t('Chinese, Traditional'),
    t('English'),
    t('Japanese'),
    t('Korean'),
    t('Portuguese, Brazil'),
    t('Russian'),
    t('Spanish'),
    t('Title'),
    t('Type'),
    t('Published'),
    t('Language'),
    t('Status'),
    t('Source Language'),
    t('Page'),
  );
  $export['reports_translations'] = $view;

  $view = new view();
  $view->name = 'reports_users';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'users';
  $view->human_name = 'Reports: Users';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Users';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
    4 => '4',
    9 => '9',
    13 => '13',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_company' => 'field_company',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'field_work_phone' => 'field_work_phone',
    'mail' => 'mail',
    'rid' => 'rid',
    'login' => 'login',
    'status' => 'status',
  );
  $handler->display->display_options['style_options']['default'] = 'field_last_name';
  $handler->display->display_options['style_options']['info'] = array(
    'field_company' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_last_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_first_name' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_work_phone' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'mail' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'rid' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'login' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'status' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['exclude'] = TRUE;
  /* Field: Field: Company */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company']['settings'] = array(
    'link' => 0,
  );
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Work Phone Number */
  $handler->display->display_options['fields']['field_work_phone']['id'] = 'field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['table'] = 'field_data_field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['field'] = 'field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['label'] = 'Phone';
  $handler->display->display_options['fields']['field_work_phone']['element_label_colon'] = FALSE;
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  /* Field: User: Last login */
  $handler->display->display_options['fields']['login']['id'] = 'login';
  $handler->display->display_options['fields']['login']['table'] = 'users';
  $handler->display->display_options['fields']['login']['field'] = 'login';
  $handler->display->display_options['fields']['login']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['login']['date_format'] = 'short';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Link */
  $handler->display->display_options['fields']['view_user']['id'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['table'] = 'users';
  $handler->display->display_options['fields']['view_user']['field'] = 'view_user';
  $handler->display->display_options['fields']['view_user']['exclude'] = TRUE;
  /* Field: User: Edit link */
  $handler->display->display_options['fields']['edit_node']['id'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['table'] = 'users';
  $handler->display->display_options['fields']['edit_node']['field'] = 'edit_node';
  $handler->display->display_options['fields']['edit_node']['exclude'] = TRUE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[view_user] [edit_node]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '1';
  $handler->display->display_options['filters']['uid_raw']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'contains';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by company name, first name, last name, username or email address';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'mail' => 'mail',
  );
  /* Filter criterion: Field: Company (field_company) */
  $handler->display->display_options['filters']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['filters']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_company_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator_id'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['identifier'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Role';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Current Agreement (field_agreement_identifier) */
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['id'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['table'] = 'field_data_field_agreement_identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['field'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['operator_id'] = 'field_agreement_identifier_tid_op';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['label'] = 'Agreement Identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['operator'] = 'field_agreement_identifier_tid_op';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['identifier'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['vocabulary'] = 'membership_segments';

  /* Display: Users */
  $handler = $view->new_display('page', 'Users', 'users');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['relationships']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['relationships']['field_company_target_id']['label'] = 'Company';
  $handler->display->display_options['relationships']['field_company_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: User: The user ID */
  $handler->display->display_options['filters']['uid_raw']['id'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['table'] = 'users';
  $handler->display->display_options['filters']['uid_raw']['field'] = 'uid_raw';
  $handler->display->display_options['filters']['uid_raw']['operator'] = '>';
  $handler->display->display_options['filters']['uid_raw']['value']['value'] = '0';
  $handler->display->display_options['filters']['uid_raw']['group'] = 1;
  /* Filter criterion: Global: Combine fields filter */
  $handler->display->display_options['filters']['combine']['id'] = 'combine';
  $handler->display->display_options['filters']['combine']['table'] = 'views';
  $handler->display->display_options['filters']['combine']['field'] = 'combine';
  $handler->display->display_options['filters']['combine']['operator'] = 'allwords';
  $handler->display->display_options['filters']['combine']['group'] = 1;
  $handler->display->display_options['filters']['combine']['exposed'] = TRUE;
  $handler->display->display_options['filters']['combine']['expose']['operator_id'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['combine']['expose']['description'] = 'Search by first name, last name, username or email address';
  $handler->display->display_options['filters']['combine']['expose']['operator'] = 'combine_op';
  $handler->display->display_options['filters']['combine']['expose']['identifier'] = 'combine';
  $handler->display->display_options['filters']['combine']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['combine']['fields'] = array(
    'name' => 'name',
    'field_last_name' => 'field_last_name',
    'field_first_name' => 'field_first_name',
    'mail' => 'mail',
  );
  /* Filter criterion: Field: Company (field_company) */
  $handler->display->display_options['filters']['field_company_target_id']['id'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['table'] = 'field_data_field_company';
  $handler->display->display_options['filters']['field_company_target_id']['field'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_company_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator_id'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['label'] = 'Company';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['operator'] = 'field_company_target_id_op';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['identifier'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_company_target_id']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: User: Active */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'users';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 'All';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['exposed'] = TRUE;
  $handler->display->display_options['filters']['status']['expose']['operator_id'] = '';
  $handler->display->display_options['filters']['status']['expose']['label'] = 'Active';
  $handler->display->display_options['filters']['status']['expose']['operator'] = 'status_op';
  $handler->display->display_options['filters']['status']['expose']['identifier'] = 'status';
  $handler->display->display_options['filters']['status']['expose']['remember_roles'] = array(
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
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Role';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  /* Filter criterion: Content: Current Agreement (field_agreement_identifier) */
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['id'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['table'] = 'field_data_field_agreement_identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['field'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['operator_id'] = 'field_agreement_identifier_tid_op';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['label'] = 'Agreement Identifier';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['operator'] = 'field_agreement_identifier_tid_op';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['identifier'] = 'field_agreement_identifier_tid';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_agreement_identifier_tid']['vocabulary'] = 'membership_segments';
  $handler->display->display_options['path'] = 'member-resource-center/reports/users';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Users';
  $handler->display->display_options['menu']['weight'] = '-49';
  $handler->display->display_options['menu']['name'] = 'menu-reports';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: Export */
  $handler = $view->new_display('views_data_export', 'Export', 'export');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['attach_text'] = 'Download CSV';
  $handler->display->display_options['style_options']['provide_file'] = 1;
  $handler->display->display_options['style_options']['filename'] = '%view_%display.csv';
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: User: Uid */
  $handler->display->display_options['fields']['uid']['id'] = 'uid';
  $handler->display->display_options['fields']['uid']['table'] = 'users';
  $handler->display->display_options['fields']['uid']['field'] = 'uid';
  $handler->display->display_options['fields']['uid']['label'] = 'User ID';
  $handler->display->display_options['fields']['uid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['uid']['link_to_user'] = FALSE;
  /* Field: Field: Address */
  $handler->display->display_options['fields']['field_address']['id'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['table'] = 'field_data_field_address';
  $handler->display->display_options['fields']['field_address']['field'] = 'field_address';
  $handler->display->display_options['fields']['field_address']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_address']['click_sort_column'] = 'country';
  $handler->display->display_options['fields']['field_address']['settings'] = array(
    'use_widget_handlers' => 1,
    'format_handlers' => array(
      'address' => 'address',
    ),
  );
  /* Field: Field: Company */
  $handler->display->display_options['fields']['field_company']['id'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['table'] = 'field_data_field_company';
  $handler->display->display_options['fields']['field_company']['field'] = 'field_company';
  $handler->display->display_options['fields']['field_company']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company']['settings'] = array(
    'link' => 0,
  );
  /* Field: Content: Current Membership Type */
  $handler->display->display_options['fields']['field_membership_type']['id'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['table'] = 'field_data_field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['field'] = 'field_membership_type';
  $handler->display->display_options['fields']['field_membership_type']['relationship'] = 'field_company_target_id';
  $handler->display->display_options['fields']['field_membership_type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_membership_type']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Active */
  $handler->display->display_options['fields']['status']['id'] = 'status';
  $handler->display->display_options['fields']['status']['table'] = 'users';
  $handler->display->display_options['fields']['status']['field'] = 'status';
  $handler->display->display_options['fields']['status']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['status']['not'] = 0;
  /* Field: User: Company Role */
  $handler->display->display_options['fields']['field_company_role']['id'] = 'field_company_role';
  $handler->display->display_options['fields']['field_company_role']['table'] = 'field_data_field_company_role';
  $handler->display->display_options['fields']['field_company_role']['field'] = 'field_company_role';
  $handler->display->display_options['fields']['field_company_role']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_company_role']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_company_role']['delta_offset'] = '0';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'users';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'm/d/y';
  /* Field: User: Created date */
  $handler->display->display_options['fields']['created_1']['id'] = 'created_1';
  $handler->display->display_options['fields']['created_1']['table'] = 'users';
  $handler->display->display_options['fields']['created_1']['field'] = 'created';
  $handler->display->display_options['fields']['created_1']['label'] = 'Created time';
  $handler->display->display_options['fields']['created_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created_1']['custom_date_format'] = 'H:i';
  /* Field: User: E-mail */
  $handler->display->display_options['fields']['mail']['id'] = 'mail';
  $handler->display->display_options['fields']['mail']['table'] = 'users';
  $handler->display->display_options['fields']['mail']['field'] = 'mail';
  $handler->display->display_options['fields']['mail']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mail']['link_to_user'] = '0';
  /* Field: User: Fax Number */
  $handler->display->display_options['fields']['field_fax_phone']['id'] = 'field_fax_phone';
  $handler->display->display_options['fields']['field_fax_phone']['table'] = 'field_data_field_fax_phone';
  $handler->display->display_options['fields']['field_fax_phone']['field'] = 'field_fax_phone';
  $handler->display->display_options['fields']['field_fax_phone']['element_label_colon'] = FALSE;
  /* Field: User: First Name */
  $handler->display->display_options['fields']['field_first_name']['id'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['table'] = 'field_data_field_first_name';
  $handler->display->display_options['fields']['field_first_name']['field'] = 'field_first_name';
  $handler->display->display_options['fields']['field_first_name']['element_label_colon'] = FALSE;
  /* Field: User: Geographic Responsibilities */
  $handler->display->display_options['fields']['field_geographic_responsibilitie']['id'] = 'field_geographic_responsibilitie';
  $handler->display->display_options['fields']['field_geographic_responsibilitie']['table'] = 'field_data_field_geographic_responsibilitie';
  $handler->display->display_options['fields']['field_geographic_responsibilitie']['field'] = 'field_geographic_responsibilitie';
  $handler->display->display_options['fields']['field_geographic_responsibilitie']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_geographic_responsibilitie']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_geographic_responsibilitie']['delta_offset'] = '0';
  /* Field: User: Language */
  $handler->display->display_options['fields']['language']['id'] = 'language';
  $handler->display->display_options['fields']['language']['table'] = 'users';
  $handler->display->display_options['fields']['language']['field'] = 'language';
  $handler->display->display_options['fields']['language']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['language']['link_to_user'] = FALSE;
  /* Field: User: Last access */
  $handler->display->display_options['fields']['access']['id'] = 'access';
  $handler->display->display_options['fields']['access']['table'] = 'users';
  $handler->display->display_options['fields']['access']['field'] = 'access';
  $handler->display->display_options['fields']['access']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['access']['date_format'] = 'short';
  /* Field: User: Last Name */
  $handler->display->display_options['fields']['field_last_name']['id'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['table'] = 'field_data_field_last_name';
  $handler->display->display_options['fields']['field_last_name']['field'] = 'field_last_name';
  $handler->display->display_options['fields']['field_last_name']['element_label_colon'] = FALSE;
  /* Field: User: Mobile Number */
  $handler->display->display_options['fields']['field_mobile_phone']['id'] = 'field_mobile_phone';
  $handler->display->display_options['fields']['field_mobile_phone']['table'] = 'field_data_field_mobile_phone';
  $handler->display->display_options['fields']['field_mobile_phone']['field'] = 'field_mobile_phone';
  $handler->display->display_options['fields']['field_mobile_phone']['element_label_colon'] = FALSE;
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: User: Receive Members Email */
  $handler->display->display_options['fields']['field_receive_members_email']['id'] = 'field_receive_members_email';
  $handler->display->display_options['fields']['field_receive_members_email']['table'] = 'field_data_field_receive_members_email';
  $handler->display->display_options['fields']['field_receive_members_email']['field'] = 'field_receive_members_email';
  $handler->display->display_options['fields']['field_receive_members_email']['element_label_colon'] = FALSE;
  /* Field: User: Roles */
  $handler->display->display_options['fields']['rid']['id'] = 'rid';
  $handler->display->display_options['fields']['rid']['table'] = 'users_roles';
  $handler->display->display_options['fields']['rid']['field'] = 'rid';
  $handler->display->display_options['fields']['rid']['element_label_colon'] = FALSE;
  /* Field: User: Salutation */
  $handler->display->display_options['fields']['field_salutation']['id'] = 'field_salutation';
  $handler->display->display_options['fields']['field_salutation']['table'] = 'field_data_field_salutation';
  $handler->display->display_options['fields']['field_salutation']['field'] = 'field_salutation';
  $handler->display->display_options['fields']['field_salutation']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_salutation']['type'] = 'taxonomy_term_reference_plain';
  /* Field: User: Job Title */
  $handler->display->display_options['fields']['field_title']['id'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['table'] = 'field_data_field_title';
  $handler->display->display_options['fields']['field_title']['field'] = 'field_title';
  $handler->display->display_options['fields']['field_title']['element_label_colon'] = FALSE;
  /* Field: User: Work Phone Number */
  $handler->display->display_options['fields']['field_work_phone']['id'] = 'field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['table'] = 'field_data_field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['field'] = 'field_work_phone';
  $handler->display->display_options['fields']['field_work_phone']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'member-resource-center/reports/users/export';
  $handler->display->display_options['displays'] = array(
    'users' => 'users',
    'default' => 0,
  );
  $handler->display->display_options['use_batch'] = 'batch';
  $translatables['reports_users'] = array(
    t('Master'),
    t('Users'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Company'),
    t('Name'),
    t('Last Name'),
    t('First Name'),
    t('Phone'),
    t('E-mail'),
    t('Roles'),
    t('Last login'),
    t('Active'),
    t('Link'),
    t('Edit link'),
    t('Operations'),
    t('[view_user] [edit_node]'),
    t('Search'),
    t('Search by company name, first name, last name, username or email address'),
    t('Role'),
    t('Agreement Identifier'),
    t('Search by first name, last name, username or email address'),
    t('Export'),
    t('User ID'),
    t('Address'),
    t('Current Membership Type'),
    t('Company Role'),
    t('Created date'),
    t('Created time'),
    t('Fax Number'),
    t('Geographic Responsibilities'),
    t('Language'),
    t('Last access'),
    t('Mobile Number'),
    t('Receive Members Email'),
    t('Salutation'),
    t('Job Title'),
    t('Work Phone Number'),
  );
  $export['reports_users'] = $view;

  $view = new view();
  $view->name = 'solution_pricing_information';
  $view->description = 'A solution\'s pricing information.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solution Pricing Information';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Pricing Information';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Price per unit */
  $handler->display->display_options['fields']['field_price_per_unit']['id'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['table'] = 'field_data_field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['field'] = 'field_price_per_unit';
  $handler->display->display_options['fields']['field_price_per_unit']['label'] = '';
  $handler->display->display_options['fields']['field_price_per_unit']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_unit']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_price_per_unit']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price per 100 Units */
  $handler->display->display_options['fields']['field_price_per_100_units']['id'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['table'] = 'field_data_field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['field'] = 'field_price_per_100_units';
  $handler->display->display_options['fields']['field_price_per_100_units']['label'] = '';
  $handler->display->display_options['fields']['field_price_per_100_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_100_units']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_price_per_100_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Price per 1000 Units */
  $handler->display->display_options['fields']['field_price_per_1000_units']['id'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['table'] = 'field_data_field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['field'] = 'field_price_per_1000_units';
  $handler->display->display_options['fields']['field_price_per_1000_units']['label'] = '';
  $handler->display->display_options['fields']['field_price_per_1000_units']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_price_per_1000_units']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_price_per_1000_units']['settings'] = array(
    'thousand_separator' => ',',
    'prefix_suffix' => 1,
  );
  /* Field: Content: Order Button URL */
  $handler->display->display_options['fields']['field_order_button_url']['id'] = 'field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url']['table'] = 'field_data_field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url']['field'] = 'field_order_button_url';
  $handler->display->display_options['fields']['field_order_button_url']['label'] = '';
  $handler->display->display_options['fields']['field_order_button_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_order_button_url']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_order_button_url']['click_sort_column'] = 'url';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'solution' => 'solution',
  );
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
    'solution' => 'solution',
  );

  /* Display: Pricing Information */
  $handler = $view->new_display('panel_pane', 'Pricing Information', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['solution_pricing_information'] = array(
    t('Master'),
    t('Pricing Information'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('View panes'),
  );
  $export['solution_pricing_information'] = $view;

  $view = new view();
  $view->name = 'solution_resources';
  $view->description = 'Solution Directory solution resources.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Solution Resources';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Resources';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Website URL */
  $handler->display->display_options['fields']['field_website']['id'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['table'] = 'field_data_field_website';
  $handler->display->display_options['fields']['field_website']['field'] = 'field_website';
  $handler->display->display_options['fields']['field_website']['label'] = '';
  $handler->display->display_options['fields']['field_website']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_website']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_website']['click_sort_column'] = 'url';
  /* Field: Content: Datasheet */
  $handler->display->display_options['fields']['field_datasheet']['id'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['table'] = 'field_data_field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['field'] = 'field_datasheet';
  $handler->display->display_options['fields']['field_datasheet']['label'] = '';
  $handler->display->display_options['fields']['field_datasheet']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_datasheet']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_datasheet']['click_sort_column'] = 'url';
  /* Field: Content: Product Brief */
  $handler->display->display_options['fields']['field_brief']['id'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief']['table'] = 'field_data_field_brief';
  $handler->display->display_options['fields']['field_brief']['field'] = 'field_brief';
  $handler->display->display_options['fields']['field_brief']['label'] = '';
  $handler->display->display_options['fields']['field_brief']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_brief']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_brief']['click_sort_column'] = 'url';
  /* Field: Content: Additional Resources URL */
  $handler->display->display_options['fields']['field_additional_resources']['id'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['table'] = 'field_data_field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['field'] = 'field_additional_resources';
  $handler->display->display_options['fields']['field_additional_resources']['label'] = '';
  $handler->display->display_options['fields']['field_additional_resources']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_additional_resources']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_additional_resources']['click_sort_column'] = 'url';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'solution' => 'solution',
  );
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
    'solution' => 'solution',
  );

  /* Display: Content pane */
  $handler = $view->new_display('panel_pane', 'Content pane', 'panel_pane_1');
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $translatables['solution_resources'] = array(
    t('Master'),
    t('Resources'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Content pane'),
    t('View panes'),
  );
  $export['solution_resources'] = $view;

  $view = new view();
  $view->name = 'solutions_directory';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_solutions';
  $view->human_name = 'Solutions Directory';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Solutions Directory';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = '<none>';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '7';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = '<none>';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '15, 16, 30, 60, 120, 180';
  $handler->display->display_options['pager']['options']['tags']['first'] = 'First';
  $handler->display->display_options['pager']['options']['tags']['previous'] = 'Previous';
  $handler->display->display_options['pager']['options']['tags']['next'] = 'Next';
  $handler->display->display_options['pager']['options']['tags']['last'] = 'Last';
  $handler->display->display_options['style_plugin'] = 'grid';
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'solution_list';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Showing @total results';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results matched your search.';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Indexed Content: Image */
  $handler->display->display_options['fields']['field_image']['id'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['field_image']['field'] = 'field_image';
  $handler->display->display_options['fields']['field_image']['label'] = '';
  $handler->display->display_options['fields']['field_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_image']['settings'] = array(
    'image_style' => '',
    'image_link' => '',
  );
  /* Field: Indexed Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['link_to_entity'] = 0;
  /* Field: Indexed Content: Company Name */
  $handler->display->display_options['fields']['field_component_company_name']['id'] = 'field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['field_component_company_name']['field'] = 'field_component_company_name';
  $handler->display->display_options['fields']['field_component_company_name']['label'] = '';
  $handler->display->display_options['fields']['field_component_company_name']['element_label_colon'] = FALSE;
  /* Field: Indexed Content: Business User Description – Optional */
  $handler->display->display_options['fields']['field_end_user_description']['id'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['field_end_user_description']['field'] = 'field_end_user_description';
  $handler->display->display_options['fields']['field_end_user_description']['exclude'] = TRUE;
  /* Field: Indexed Content: The main body text */
  $handler->display->display_options['fields']['body']['id'] = 'body';
  $handler->display->display_options['fields']['body']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['body']['field'] = 'body';
  $handler->display->display_options['fields']['body']['empty'] = '[field_end_user_description]';
  /* Field: Indexed Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['created']['expose']['label'] = 'Most recent';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  $handler->display->display_options['sorts']['search_api_relevance']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['search_api_relevance']['expose']['label'] = 'Relevance';
  /* Sort criterion: Company » Current Membership Type: Weight (indexed) */
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['id'] = 'field_company_field_membership_type_weight';
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['field'] = 'field_company_field_membership_type_weight';
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['exposed'] = TRUE;
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['expose']['label'] = 'Membership level';
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
  $handler->display->display_options['sorts']['created_1']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['created_1']['field'] = 'created';
  $handler->display->display_options['sorts']['created_1']['order'] = 'DESC';
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Content: Pre-Release */
  $handler->display->display_options['filters']['field_pre_release']['id'] = 'field_pre_release';
  $handler->display->display_options['filters']['field_pre_release']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['field_pre_release']['field'] = 'field_pre_release';
  $handler->display->display_options['filters']['field_pre_release']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_pre_release']['group'] = 1;

  /* Display: Featured Products */
  $handler = $view->new_display('panel_pane', 'Featured Products', 'featured_products');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Featured Products';
  $handler->display->display_options['display_description'] = 'Solutions that have been flagged as "Promoted to frontpage".';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_simple_pager';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['hide_on_single_slide'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_simple_pager';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '2';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollHorz';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '500';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause_when_hidden'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '3';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 1;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entity';
  $handler->display->display_options['row_options']['view_mode'] = 'solution_list';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Company » Current Membership Type: Weight (indexed) */
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['id'] = 'field_company_field_membership_type_weight';
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['field_company_field_membership_type_weight']['field'] = 'field_company_field_membership_type_weight';
  /* Sort criterion: Indexed Content: Date created */
  $handler->display->display_options['sorts']['created_1']['id'] = 'created_1';
  $handler->display->display_options['sorts']['created_1']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['sorts']['created_1']['field'] = 'created';
  $handler->display->display_options['sorts']['created_1']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Content: Promoted to frontpage */
  $handler->display->display_options['filters']['promote']['id'] = 'promote';
  $handler->display->display_options['filters']['promote']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['promote']['field'] = 'promote';
  $handler->display->display_options['filters']['promote']['value'] = '1';
  $handler->display->display_options['filters']['promote']['group'] = 1;
  /* Filter criterion: Indexed Content: Pre-Release */
  $handler->display->display_options['filters']['field_pre_release']['id'] = 'field_pre_release';
  $handler->display->display_options['filters']['field_pre_release']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['field_pre_release']['field'] = 'field_pre_release';
  $handler->display->display_options['filters']['field_pre_release']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_pre_release']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Search Results */
  $handler = $view->new_display('panel_pane', 'Search Results', 'search_results');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Solutions that have not been flagged as "Promoted to frontpage".';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Content: Pre-Release */
  $handler->display->display_options['filters']['field_pre_release']['id'] = 'field_pre_release';
  $handler->display->display_options['filters']['field_pre_release']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['field_pre_release']['field'] = 'field_pre_release';
  $handler->display->display_options['filters']['field_pre_release']['value'] = array(
    0 => '0',
  );
  $handler->display->display_options['filters']['field_pre_release']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Solution Facets */
  $handler = $view->new_display('search_api_views_facets_block', 'Solution Facets', 'solution_facets');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Content: Node ID */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'formula' => 'formula',
    'solution' => 'solution',
  );
  $handler->display->display_options['arguments']['nid']['break_phrase'] = 0;
  $handler->display->display_options['arguments']['nid']['not'] = 0;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  $handler->display->display_options['linked_path'] = 'solutions-directory';
  $handler->display->display_options['facet_field'] = 'nid';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Company Facets */
  $handler = $view->new_display('search_api_views_facets_block', 'Company Facets', 'company_facets');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['empty'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Content: Node ID */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = '';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nid']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['nid']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['nid']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Indexed Content: Company */
  $handler->display->display_options['arguments']['field_company']['id'] = 'field_company';
  $handler->display->display_options['arguments']['field_company']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['arguments']['field_company']['field'] = 'field_company';
  $handler->display->display_options['arguments']['field_company']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_company']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_company']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_company']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['field_company']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['field_company']['validate_options']['types'] = array(
    'company' => 'company',
  );
  $handler->display->display_options['arguments']['field_company']['break_phrase'] = 0;
  $handler->display->display_options['linked_path'] = 'solutions-directory';
  $handler->display->display_options['facet_field'] = 'field_company';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Prerelease Search Results */
  $handler = $view->new_display('panel_pane', 'Prerelease Search Results', 'panel_pane_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['display_description'] = 'Solutions that have not been flagged as "Promoted to frontpage".';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Search: Fulltext search */
  $handler->display->display_options['filters']['search_api_views_fulltext']['id'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['table'] = 'search_api_index_solutions';
  $handler->display->display_options['filters']['search_api_views_fulltext']['field'] = 'search_api_views_fulltext';
  $handler->display->display_options['filters']['search_api_views_fulltext']['group'] = 1;
  $handler->display->display_options['filters']['search_api_views_fulltext']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator_id'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['operator'] = 'search_api_views_fulltext_op';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_views_fulltext']['expose']['remember_roles'] = array(
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
    14 => 0,
    15 => 0,
    5 => 0,
    16 => 0,
    6 => 0,
    17 => 0,
    18 => 0,
    19 => 0,
    20 => 0,
    21 => 0,
  );
  $handler->display->display_options['allow']['use_pager'] = 0;
  $handler->display->display_options['allow']['items_per_page'] = 0;
  $handler->display->display_options['allow']['offset'] = 0;
  $handler->display->display_options['allow']['link_to_view'] = 0;
  $handler->display->display_options['allow']['more_link'] = 0;
  $handler->display->display_options['allow']['path_override'] = 'path_override';
  $handler->display->display_options['allow']['title_override'] = 0;
  $handler->display->display_options['allow']['exposed_form'] = 0;
  $handler->display->display_options['allow']['fields_override'] = 0;
  $handler->display->display_options['inherit_panels_path'] = '1';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '15';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss_fields';
  $handler->display->display_options['style_options']['channel'] = array(
    'core' => array(
      'views_rss_core' => array(
        'description' => '',
        'language' => '',
        'category' => '',
        'image' => '',
        'copyright' => '',
        'managingEditor' => '',
        'webMaster' => '',
        'generator' => '',
        'docs' => '',
        'cloud' => '',
        'ttl' => '',
        'skipHours' => '',
        'skipDays' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['item'] = array(
    'core' => array(
      'views_rss_core' => array(
        'title' => 'title',
        'link' => 'url',
        'description' => 'body',
        'author' => '',
        'category' => '',
        'comments' => '',
        'enclosure' => 'field_image',
        'guid' => '',
        'pubDate' => '',
      ),
    ),
  );
  $handler->display->display_options['style_options']['feed_settings'] = array(
    'absolute_paths' => 1,
    'feed_in_links' => 0,
  );
  $handler->display->display_options['path'] = 'solutions-directory/feed';
  $translatables['solutions_directory'] = array(
    t('Master'),
    t('Solutions Directory'),
    t('more'),
    t('Search'),
    t('Reset'),
    t('<none>'),
    t('Asc'),
    t('Desc'),
    t('- All -'),
    t('Offset'),
    t('First'),
    t('Previous'),
    t('Next'),
    t('Last'),
    t('Showing @total results'),
    t('No results matched your search.'),
    t('Node ID'),
    t('.'),
    t(','),
    t('Title'),
    t('Business User Description – Optional'),
    t('The main body text'),
    t('[field_end_user_description]'),
    t('URL'),
    t('Most recent'),
    t('Relevance'),
    t('Membership level'),
    t('Featured Products'),
    t('Solutions that have been flagged as "Promoted to frontpage".'),
    t('View panes'),
    t('Search Results'),
    t('Solutions that have not been flagged as "Promoted to frontpage".'),
    t('Solution Facets'),
    t('All'),
    t('Company Facets'),
    t('Prerelease Search Results'),
    t('Feed'),
  );
  $export['solutions_directory'] = $view;

  $view = new view();
  $view->name = 'training_section_slides';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Training Section Slides';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Explore Our Programs';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_simple_pager';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_simple_pager';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollHorz';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '500';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause_when_hidden'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 1;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['view_mode'] = 'training_section_slide';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_training_section_target_id']['id'] = 'field_training_section_target_id';
  $handler->display->display_options['relationships']['field_training_section_target_id']['table'] = 'field_data_field_training_section';
  $handler->display->display_options['relationships']['field_training_section_target_id']['field'] = 'field_training_section_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Sub-Section Order (field_sub_section_order) */
  $handler->display->display_options['sorts']['field_sub_section_order_value']['id'] = 'field_sub_section_order_value';
  $handler->display->display_options['sorts']['field_sub_section_order_value']['table'] = 'field_data_field_sub_section_order';
  $handler->display->display_options['sorts']['field_sub_section_order_value']['field'] = 'field_sub_section_order_value';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['relationship'] = 'field_training_section_target_id';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'training_section' => 'training_section',
  );
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
    'training_sub_section' => 'training_sub_section',
  );

  /* Display: Slideshow */
  $handler = $view->new_display('panel_pane', 'Slideshow', 'slideshow');
  $translatables['training_section_slides'] = array(
    t('Master'),
    t('Explore Our Programs'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_training_section'),
    t('All'),
    t('Slideshow'),
    t('View panes'),
  );
  $export['training_section_slides'] = $view;

  $view = new view();
  $view->name = 'training_sections';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Training Sections';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Sort criterion: Content: Title */
  $handler->display->display_options['sorts']['title']['id'] = 'title';
  $handler->display->display_options['sorts']['title']['table'] = 'node';
  $handler->display->display_options['sorts']['title']['field'] = 'title';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'training_section' => 'training_section',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;

  /* Display: Entity Reference */
  $handler = $view->new_display('entityreference', 'Entity Reference', 'entityreference_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'entityreference_style';
  $handler->display->display_options['style_options']['search_fields'] = array(
    'title' => 'title',
  );
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'entityreference_fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'training_section' => 'training_section',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content translation: Source translation */
  $handler->display->display_options['filters']['source_translation']['id'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['table'] = 'node';
  $handler->display->display_options['filters']['source_translation']['field'] = 'source_translation';
  $handler->display->display_options['filters']['source_translation']['operator'] = '1';
  $handler->display->display_options['filters']['source_translation']['group'] = 1;
  $translatables['training_sections'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Entity Reference'),
  );
  $export['training_sections'] = $view;

  $view = new view();
  $view->name = 'training_sub_section_slides';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Training Sub-Section Slides';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Next Steps';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_next_step_slide' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'field_next_step_slide' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollHorz';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '500';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause_when_hidden'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: View area */
  $handler->display->display_options['header']['view']['id'] = 'view';
  $handler->display->display_options['header']['view']['table'] = 'views';
  $handler->display->display_options['header']['view']['field'] = 'view';
  $handler->display->display_options['header']['view']['view_to_insert'] = 'training_sub_section_slides:description';
  /* Field: Global: View result counter */
  $handler->display->display_options['fields']['counter']['id'] = 'counter';
  $handler->display->display_options['fields']['counter']['table'] = 'views';
  $handler->display->display_options['fields']['counter']['field'] = 'counter';
  $handler->display->display_options['fields']['counter']['label'] = '';
  $handler->display->display_options['fields']['counter']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['counter']['counter_start'] = '1';
  /* Field: Content: Next Step Slide */
  $handler->display->display_options['fields']['field_next_step_slide']['id'] = 'field_next_step_slide';
  $handler->display->display_options['fields']['field_next_step_slide']['table'] = 'field_data_field_next_step_slide';
  $handler->display->display_options['fields']['field_next_step_slide']['field'] = 'field_next_step_slide';
  $handler->display->display_options['fields']['field_next_step_slide']['label'] = '';
  $handler->display->display_options['fields']['field_next_step_slide']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_next_step_slide']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_next_step_slide']['settings'] = array(
    'view_mode' => 'full',
  );
  $handler->display->display_options['fields']['field_next_step_slide']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_next_step_slide']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'training_sub_section' => 'training_sub_section',
  );
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
    'training_sub_section' => 'training_sub_section',
  );

  /* Display: Slideshow */
  $handler = $view->new_display('panel_pane', 'Slideshow', 'slideshow');

  /* Display: Description */
  $handler = $view->new_display('panel_pane', 'Description', 'description');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_description']['id'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['table'] = 'field_data_field_description';
  $handler->display->display_options['fields']['field_description']['field'] = 'field_description';
  $handler->display->display_options['fields']['field_description']['label'] = '';
  $handler->display->display_options['fields']['field_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_description']['hide_empty'] = TRUE;
  $translatables['training_sub_section_slides'] = array(
    t('Master'),
    t('Next Steps'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Slideshow'),
    t('View panes'),
    t('Description'),
  );
  $export['training_sub_section_slides'] = $view;

  $view = new view();
  $view->name = 'training_sub_section_videos';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Training Sub-Section Videos';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    2 => '2',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'slideshow';
  $handler->display->display_options['style_options']['slideshow_type'] = 'views_slideshow_cycle';
  $handler->display->display_options['style_options']['slideshow_skin'] = 'default';
  $handler->display->display_options['style_options']['skin_info'] = array(
    'class' => 'default',
    'name' => 'Default',
    'module' => 'views_slideshow',
    'path' => '',
    'stylesheets' => array(),
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['top']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['type'] = 'views_slideshow_pager_fields';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_pager']['views_slideshow_pager_fields_fields'] = array(
    'title' => 0,
  );
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['enable'] = 1;
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['weight'] = '1';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_controls']['type'] = 'views_slideshow_controls_text';
  $handler->display->display_options['style_options']['widgets']['bottom']['views_slideshow_slide_counter']['weight'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['effect'] = 'scrollHorz';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['transition_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['timeout'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['speed'] = '500';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['delay'] = '0';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['action_advanced'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['start_paused'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['remember_slide_days'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['pause_when_hidden'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['items_per_slide'] = '1';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['wait_for_image_load_timeout'] = '3000';
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartype'] = 1;
  $handler->display->display_options['style_options']['views_slideshow_cycle']['cleartypenobg'] = 1;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['hide_empty'] = TRUE;
  /* Field: Content: Webinar Video */
  $handler->display->display_options['fields']['field_webinar_video']['id'] = 'field_webinar_video';
  $handler->display->display_options['fields']['field_webinar_video']['table'] = 'field_data_field_webinar_video';
  $handler->display->display_options['fields']['field_webinar_video']['field'] = 'field_webinar_video';
  $handler->display->display_options['fields']['field_webinar_video']['label'] = '';
  $handler->display->display_options['fields']['field_webinar_video']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_webinar_video']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['field_webinar_video']['click_sort_column'] = 'video_url';
  $handler->display->display_options['fields']['field_webinar_video']['settings'] = array(
    'video_style' => 'full',
  );
  $handler->display->display_options['fields']['field_webinar_video']['group_rows'] = FALSE;
  $handler->display->display_options['fields']['field_webinar_video']['delta_offset'] = '0';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['exception']['value'] = '';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['nid']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['nid']['validate']['type'] = 'node';
  $handler->display->display_options['arguments']['nid']['validate_options']['types'] = array(
    'training_sub_section' => 'training_sub_section',
  );
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
    'training_sub_section' => 'training_sub_section',
  );

  /* Display: Slideshow */
  $handler = $view->new_display('panel_pane', 'Slideshow', 'slideshow');
  $translatables['training_sub_section_videos'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('All'),
    t('Slideshow'),
    t('View panes'),
  );
  $export['training_sub_section_videos'] = $view;

  return $export;
}
