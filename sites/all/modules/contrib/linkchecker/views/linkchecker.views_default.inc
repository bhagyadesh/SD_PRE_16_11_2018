<?php

/**
 * @file
 * Default views for the Linkchecker module.
 */

/**
 * Implements hook_views_default_views().
 */
function linkchecker_views_default_views() {
  $export = array();

  $comment = module_exists('comment');
  $block = module_exists('block');
  $redirect = module_exists('redirect');

  $view = new view();
  $view->name = 'linkchecker_reports';
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
  $handler->display->display_options['access']['type'] = 'linkchecker';
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
  );
  if ($comment) {
    $handler->display->display_options['style_options']['columns'] += array(
      'cid' => 'cid',
      'edit_comment' => 'edit_comment',
    );
  }
  if ($block) {
    $handler->display->display_options['style_options']['columns'] += array(
      'bid' => 'bid',
      'block_edit' => 'block_edit',
    );
  }
  if ($redirect) {
    $handler->display->display_options['style_options']['columns'] += array(
      'redirect_add' => 'redirect_add',
    );
  }
  $handler->display->display_options['style_options']['columns'] += array(
    'nothing' => 'nothing'
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
  );
  if ($comment) {
    $handler->display->display_options['style_options']['info'] += array(
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
    );
  }
  if ($block) {
    $handler->display->display_options['style_options']['info'] += array(
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
    );
  }
  if ($redirect) {
    $handler->display->display_options['style_options']['info'] += array(
      'redirect_add' => array(
        'align' => '',
        'separator' => '',
        'empty_column' => 0,
      ),
    );
  }
  $handler->display->display_options['style_options']['info'] += array(
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
  if ($comment) {
    /* Relationship: Broken links: Comment with link */
    $handler->display->display_options['relationships']['cid']['id'] = 'cid';
    $handler->display->display_options['relationships']['cid']['table'] = 'linkchecker_comment';
    $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  }
  /* Field: Broken links: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['alter']['max_length'] = '40';
  $handler->display->display_options['fields']['url']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['url']['alter']['trim'] = TRUE;
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
  /* Field: Broken links: Edit link settings */
  $handler->display->display_options['fields']['link_edit']['id'] = 'link_edit';
  $handler->display->display_options['fields']['link_edit']['table'] = 'linkchecker_link';
  $handler->display->display_options['fields']['link_edit']['field'] = 'link_edit';
  $handler->display->display_options['fields']['link_edit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['link_edit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['link_edit']['alter']['text'] = '<li>Edit link settings</li>';
  $handler->display->display_options['fields']['link_edit']['hide_empty'] = TRUE;
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
  if ($comment) {
    /* Field: Comment: ID */
    $handler->display->display_options['fields']['cid']['id'] = 'cid';
    $handler->display->display_options['fields']['cid']['table'] = 'comment';
    $handler->display->display_options['fields']['cid']['field'] = 'cid';
    $handler->display->display_options['fields']['cid']['relationship'] = 'cid';
    $handler->display->display_options['fields']['cid']['exclude'] = TRUE;
    $handler->display->display_options['fields']['cid']['link_to_comment'] = FALSE;
    /* Field: Comment: Edit link */
    $handler->display->display_options['fields']['edit_comment']['id'] = 'edit_comment';
    $handler->display->display_options['fields']['edit_comment']['table'] = 'comment';
    $handler->display->display_options['fields']['edit_comment']['field'] = 'edit_comment';
    $handler->display->display_options['fields']['edit_comment']['relationship'] = 'cid';
    $handler->display->display_options['fields']['edit_comment']['exclude'] = TRUE;
    $handler->display->display_options['fields']['edit_comment']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['edit_comment']['alter']['text'] = '<li>Edit comment [cid]</li>';
    $handler->display->display_options['fields']['edit_comment']['hide_empty'] = TRUE;
    $handler->display->display_options['fields']['edit_comment']['destination'] = TRUE;
  }
  if ($block) {
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
  }
  if ($redirect) {
    /* Field: Broken links: Create redirect */
    $handler->display->display_options['fields']['redirect_add']['id'] = 'redirect_add';
    $handler->display->display_options['fields']['redirect_add']['table'] = 'linkchecker_link';
    $handler->display->display_options['fields']['redirect_add']['field'] = 'redirect_add';
    $handler->display->display_options['fields']['redirect_add']['exclude'] = TRUE;
    $handler->display->display_options['fields']['redirect_add']['alter']['alter_text'] = TRUE;
    $handler->display->display_options['fields']['redirect_add']['alter']['text'] = '<li>Create redirect</li>';
    $handler->display->display_options['fields']['redirect_add']['hide_empty'] = TRUE;
  }
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Operations';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<ul>
  [link_edit]
  [edit_node]';
  $handler->display->display_options['fields']['nothing']['alter']['text'] .= $comment ? "\n  [edit_comment]" : '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] .= $block ? "\n  [block_edit]" : '' ;
  $handler->display->display_options['fields']['nothing']['alter']['text'] .= $redirect ? "\n  [redirect_add]" : '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] .= "\n</ul>";
  $nothing_translatable = $handler->display->display_options['fields']['nothing']['alter']['text'];
  $handler->display->display_options['fields']['nothing']['hide_empty'] = TRUE;
  $handler->display->display_options['fields']['nothing']['hide_alter_empty'] = TRUE;
  /* Sort criterion: Broken links: Last checked */
  $handler->display->display_options['sorts']['last_checked']['id'] = 'last_checked';
  $handler->display->display_options['sorts']['last_checked']['table'] = 'linkchecker_link';
  $handler->display->display_options['sorts']['last_checked']['field'] = 'last_checked';
  $handler->display->display_options['sorts']['last_checked']['order'] = 'DESC';
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

  /* Display: Admin Broken links */
  $handler = $view->new_display('page', 'Admin Broken links', 'linkchecker_admin_report_page');
  $handler->display->display_options['display_description'] = 'Shows a list of broken links in content.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['path'] = 'admin/reports/linkchecker2';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Broken links 2';
  $handler->display->display_options['menu']['description'] = 'Shows a list of broken links in content.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;

  /* Display: User Broken links */
  $handler = $view->new_display('page', 'User Broken links', 'linkchecker_user_report_page');
  $handler->display->display_options['display_description'] = 'Shows a list of broken links in authors content.';
  $handler->display->display_options['defaults']['hide_admin_links'] = FALSE;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  $handler->display->display_options['path'] = 'user/%user/linkchecker2';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Broken links 2';
  $handler->display->display_options['menu']['description'] = 'Shows a list of broken links in authors content.';
  $handler->display->display_options['menu']['weight'] = '3';
  $handler->display->display_options['menu']['name'] = 'user-menu';
  $handler->display->display_options['menu']['context'] = 0;
  $translatables['linkchecker_reports'] = array(
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
    t('URL'),
    t('Response'),
    t('.'),
    t('Error'),
    t('Edit link settings'),
    t('<li>Edit link settings</li>'),
    t('Nid'),
    t('Edit node'),
    t('<li>Edit node [nid]</li>'),
    t('Operations'),
    t($nothing_translatable),
    t('Admin Broken links'),
    t('Shows a list of broken links in content.'),
    t('User Broken links'),
    t('Shows a list of broken links in authors content.'),
  );

  if ($comment) {
    $translatables['linkchecker_reports'] += array(
      t('Comment'),
      t('ID'),
      t('Edit link'),
      t('<li>Edit comment [cid]</li>'),
    );
  }
  if ($block) {
    $translatables['linkchecker_reports'] += array(
      t('Block ID'),
      t('Edit block'),
      t('<li>Edit block [bid]</li>'),
    );
  }
  if ($redirect) {
    $translatables['linkchecker_reports'] += array(
      t('Create redirect'),
      t('<li>Create redirect</li>'),
    );
  }

  $export['linkchecker_reports'] = $view;

  return $export;
}
