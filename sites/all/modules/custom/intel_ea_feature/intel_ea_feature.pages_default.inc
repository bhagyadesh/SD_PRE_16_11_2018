<?php
/**
 * @file
 * intel_ea_feature.pages_default.inc
 */

/**
 * Implements hook_default_page_manager_handlers().
 */
function intel_ea_feature_default_page_manager_handlers() {
  $export = array();

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Opportunity',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'opportunity' => 'opportunity',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_12_twocol_6_3_stacked_bricks';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left_top' => NULL,
      'right_top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'e3b7dcbc-bb4e-3ed4-81d6-07e1162a40d5';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-48fd21a7-74fc-4094-d9a4-3990276a87e6';
    $pane->panel = 'bottom';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_opportunity_resource_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'viewfield_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Resources',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '48fd21a7-74fc-4094-d9a4-3990276a87e6';
    $display->content['new-48fd21a7-74fc-4094-d9a4-3990276a87e6'] = $pane;
    $display->panels['bottom'][0] = 'new-48fd21a7-74fc-4094-d9a4-3990276a87e6';
    $pane = new stdClass();
    $pane->pid = 'new-92eb0f5f-9528-f2c4-fdc0-e96234e5257b';
    $pane->panel = 'left_top';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '<none>',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '92eb0f5f-9528-f2c4-fdc0-e96234e5257b';
    $display->content['new-92eb0f5f-9528-f2c4-fdc0-e96234e5257b'] = $pane;
    $display->panels['left_top'][0] = 'new-92eb0f5f-9528-f2c4-fdc0-e96234e5257b';
    $pane = new stdClass();
    $pane->pid = 'new-ee613388-aa59-9e64-e9e7-ca61578caa39';
    $pane->panel = 'right_top';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-mdf_opp_login';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ee613388-aa59-9e64-e9e7-ca61578caa39';
    $display->content['new-ee613388-aa59-9e64-e9e7-ca61578caa39'] = $pane;
    $display->panels['right_top'][0] = 'new-ee613388-aa59-9e64-e9e7-ca61578caa39';
    $pane = new stdClass();
    $pane->pid = 'new-f47327bc-4abb-09c4-110a-679988ae9d42';
    $pane->panel = 'right_top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_call_to_action';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f47327bc-4abb-09c4-110a-679988ae9d42';
    $display->content['new-f47327bc-4abb-09c4-110a-679988ae9d42'] = $pane;
    $display->panels['right_top'][1] = 'new-f47327bc-4abb-09c4-110a-679988ae9d42';
    $pane = new stdClass();
    $pane->pid = 'new-6371a548-4b42-3174-3966-dc8953e07fd0';
    $pane->panel = 'right_top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_opportunity_calendar_item';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'field_collection_view',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => '',
        'delete' => '',
        'add' => '',
        'description' => 0,
        'view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'MDF Funding Calendar',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6371a548-4b42-3174-3966-dc8953e07fd0';
    $display->content['new-6371a548-4b42-3174-3966-dc8953e07fd0'] = $pane;
    $display->panels['right_top'][2] = 'new-6371a548-4b42-3174-3966-dc8953e07fd0';
    $pane = new stdClass();
    $pane->pid = 'new-18c3fc96-836b-88b4-dd6f-2e62e743010d';
    $pane->panel = 'right_top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_opportunity_calendar_link';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '18c3fc96-836b-88b4-dd6f-2e62e743010d';
    $display->content['new-18c3fc96-836b-88b4-dd6f-2e62e743010d'] = $pane;
    $display->panels['right_top'][3] = 'new-18c3fc96-836b-88b4-dd6f-2e62e743010d';
    $pane = new stdClass();
    $pane->pid = 'new-3e5e87ec-e875-ea24-dde2-0ed7d89875c4';
    $pane->panel = 'right_top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_opportunity_calendar_text';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '3e5e87ec-e875-ea24-dde2-0ed7d89875c4';
    $display->content['new-3e5e87ec-e875-ea24-dde2-0ed7d89875c4'] = $pane;
    $display->panels['right_top'][4] = 'new-3e5e87ec-e875-ea24-dde2-0ed7d89875c4';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_2';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Company',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'company' => 'company',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_isdm_company';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left_top' => NULL,
      'right_top' => NULL,
      'bottom' => NULL,
      'general_info' => NULL,
      'company_sidebar' => NULL,
      'partners_sidebar' => NULL,
      'articles_sidebar' => NULL,
      'view_one' => NULL,
      'view_two' => NULL,
      'view_three' => NULL,
      'view_four' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '2d1ec5d3-904b-aa24-891f-6740dfa066d9';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-54e640ca-bf0c-4c48-bc59-a4fefe5c258d';
    $pane->panel = 'articles_sidebar';
    $pane->type = 'views_panes';
    $pane->subtype = 'company_stories-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '54e640ca-bf0c-4c48-bc59-a4fefe5c258d';
    $display->content['new-54e640ca-bf0c-4c48-bc59-a4fefe5c258d'] = $pane;
    $display->panels['articles_sidebar'][0] = 'new-54e640ca-bf0c-4c48-bc59-a4fefe5c258d';
    $pane = new stdClass();
    $pane->pid = 'new-c8509e3c-ae3e-4f77-959d-9429d27d26d9';
    $pane->panel = 'articles_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_community-company_articles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c8509e3c-ae3e-4f77-959d-9429d27d26d9';
    $display->content['new-c8509e3c-ae3e-4f77-959d-9429d27d26d9'] = $pane;
    $display->panels['articles_sidebar'][1] = 'new-c8509e3c-ae3e-4f77-959d-9429d27d26d9';
    $pane = new stdClass();
    $pane->pid = 'new-ba566720-5815-47b9-b032-051f92a1aaf3';
    $pane->panel = 'articles_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_community-company_whitepapers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'ba566720-5815-47b9-b032-051f92a1aaf3';
    $display->content['new-ba566720-5815-47b9-b032-051f92a1aaf3'] = $pane;
    $display->panels['articles_sidebar'][2] = 'new-ba566720-5815-47b9-b032-051f92a1aaf3';
    $pane = new stdClass();
    $pane->pid = 'new-0b29ac48-0a0b-4b86-8612-50e14cd1fb28';
    $pane->panel = 'company_sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_logo';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => 'company_logo_for_solution_no_upscaling',
        'image_link' => 'content',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0b29ac48-0a0b-4b86-8612-50e14cd1fb28';
    $display->content['new-0b29ac48-0a0b-4b86-8612-50e14cd1fb28'] = $pane;
    $display->panels['company_sidebar'][0] = 'new-0b29ac48-0a0b-4b86-8612-50e14cd1fb28';
    $pane = new stdClass();
    $pane->pid = 'new-3dfaf572-0a6f-4774-a2a2-f23b0fdef170';
    $pane->panel = 'company_sidebar';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-aprimo_company_contact_member';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '3dfaf572-0a6f-4774-a2a2-f23b0fdef170';
    $display->content['new-3dfaf572-0a6f-4774-a2a2-f23b0fdef170'] = $pane;
    $display->panels['company_sidebar'][1] = 'new-3dfaf572-0a6f-4774-a2a2-f23b0fdef170';
    $pane = new stdClass();
    $pane->pid = 'new-bdb195cd-f2fe-4cfb-b260-0bf201b58a7d';
    $pane->panel = 'company_sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_membership_tier';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'taxonomy_term_reference_plain',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bdb195cd-f2fe-4cfb-b260-0bf201b58a7d';
    $display->content['new-bdb195cd-f2fe-4cfb-b260-0bf201b58a7d'] = $pane;
    $display->panels['company_sidebar'][2] = 'new-bdb195cd-f2fe-4cfb-b260-0bf201b58a7d';
    $pane = new stdClass();
    $pane->pid = 'new-a76ef852-455a-4278-9a6f-e96e9eba026d';
    $pane->panel = 'company_sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_website';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'link_url',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a76ef852-455a-4278-9a6f-e96e9eba026d';
    $display->content['new-a76ef852-455a-4278-9a6f-e96e9eba026d'] = $pane;
    $display->panels['company_sidebar'][3] = 'new-a76ef852-455a-4278-9a6f-e96e9eba026d';
    $pane = new stdClass();
    $pane->pid = 'new-34a344c8-f5d1-4e5c-882e-074a55c862b1';
    $pane->panel = 'company_sidebar';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_address';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'addressfield_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'use_widget_handlers' => 1,
        'format_handlers' => array(
          'address' => 'address',
        ),
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '34a344c8-f5d1-4e5c-882e-074a55c862b1';
    $display->content['new-34a344c8-f5d1-4e5c-882e-074a55c862b1'] = $pane;
    $display->panels['company_sidebar'][4] = 'new-34a344c8-f5d1-4e5c-882e-074a55c862b1';
    $pane = new stdClass();
    $pane->pid = 'new-b8cd9bc0-f6ca-45fe-92f4-6b19a3fc9680';
    $pane->panel = 'general_info';
    $pane->type = 'node_title';
    $pane->subtype = 'node_title';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'link' => 1,
      'markup' => 'h2',
      'id' => '',
      'class' => '',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b8cd9bc0-f6ca-45fe-92f4-6b19a3fc9680';
    $display->content['new-b8cd9bc0-f6ca-45fe-92f4-6b19a3fc9680'] = $pane;
    $display->panels['general_info'][0] = 'new-b8cd9bc0-f6ca-45fe-92f4-6b19a3fc9680';
    $pane = new stdClass();
    $pane->pid = 'new-976708f7-27cf-454f-b4d2-731cf1434b2f';
    $pane->panel = 'general_info';
    $pane->type = 'node_body';
    $pane->subtype = 'node_body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '976708f7-27cf-454f-b4d2-731cf1434b2f';
    $display->content['new-976708f7-27cf-454f-b4d2-731cf1434b2f'] = $pane;
    $display->panels['general_info'][1] = 'new-976708f7-27cf-454f-b4d2-731cf1434b2f';
    $pane = new stdClass();
    $pane->pid = 'new-e08af22c-19c0-4455-98a3-fff18d3fdf9b';
    $pane->panel = 'view_one';
    $pane->type = 'views_panes';
    $pane->subtype = 'company_solutions-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'e08af22c-19c0-4455-98a3-fff18d3fdf9b';
    $display->content['new-e08af22c-19c0-4455-98a3-fff18d3fdf9b'] = $pane;
    $display->panels['view_one'][0] = 'new-e08af22c-19c0-4455-98a3-fff18d3fdf9b';
    $pane = new stdClass();
    $pane->pid = 'new-57f1b1a2-ad62-4d3f-989c-a82a1f6165f1';
    $pane->panel = 'view_three';
    $pane->type = 'views_panes';
    $pane->subtype = 'company_solutions-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '57f1b1a2-ad62-4d3f-989c-a82a1f6165f1';
    $display->content['new-57f1b1a2-ad62-4d3f-989c-a82a1f6165f1'] = $pane;
    $display->panels['view_three'][0] = 'new-57f1b1a2-ad62-4d3f-989c-a82a1f6165f1';
    $pane = new stdClass();
    $pane->pid = 'new-2705690c-f4a6-4b1d-b302-d607c06e7ff7';
    $pane->panel = 'view_two';
    $pane->type = 'views_panes';
    $pane->subtype = 'company_solutions-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '2705690c-f4a6-4b1d-b302-d607c06e7ff7';
    $display->content['new-2705690c-f4a6-4b1d-b302-d607c06e7ff7'] = $pane;
    $display->panels['view_two'][0] = 'new-2705690c-f4a6-4b1d-b302-d607c06e7ff7';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_2'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_3';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 2;
  $handler->conf = array(
    'title' => 'Solution',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'solution' => 'solution',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_isdm_solution';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left_top' => NULL,
      'right_top' => NULL,
      'bottom' => NULL,
      'center_top' => NULL,
      'info_column_one' => NULL,
      'info_column_two' => NULL,
      'tab_first' => NULL,
      'tab_second' => NULL,
      'sidebar_top' => NULL,
      'sidebar_bottom' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f61c2c89-6cb5-7334-996f-61b936db0f4c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-d385527e-fd53-47d1-bb3c-d7129fe45829';
    $pane->panel = 'info_column_one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:body';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'trim_length' => '600',
        'trim_ellipsis' => 0,
        'effect' => 'slide',
        'trigger_expanded_label' => 'Show more',
        'trigger_collapsed_label' => '',
        'trigger_classes' => 'button',
        'inline' => 1,
        'css3' => 1,
        'js_duration' => '500',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd385527e-fd53-47d1-bb3c-d7129fe45829';
    $display->content['new-d385527e-fd53-47d1-bb3c-d7129fe45829'] = $pane;
    $display->panels['info_column_one'][0] = 'new-d385527e-fd53-47d1-bb3c-d7129fe45829';
    $pane = new stdClass();
    $pane->pid = 'new-df83a631-35af-40df-a88f-9b398b741b55';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'colorbox_node_style' => '',
        'colorbox_node_style_first' => '',
        'colorbox_image_style' => '',
        'colorbox_gallery' => 'post',
        'colorbox_gallery_custom' => '',
        'colorbox_caption' => 'auto',
        'colorbox_caption_custom' => '',
        'image_style' => 'medium',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'df83a631-35af-40df-a88f-9b398b741b55';
    $display->content['new-df83a631-35af-40df-a88f-9b398b741b55'] = $pane;
    $display->panels['info_column_two'][0] = 'new-df83a631-35af-40df-a88f-9b398b741b55';
    $pane = new stdClass();
    $pane->pid = 'new-1dc3f5ca-f330-406b-a271-76510ec59161';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_pre_release';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'i18n_list_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1dc3f5ca-f330-406b-a271-76510ec59161';
    $display->content['new-1dc3f5ca-f330-406b-a271-76510ec59161'] = $pane;
    $display->panels['info_column_two'][1] = 'new-1dc3f5ca-f330-406b-a271-76510ec59161';
    $pane = new stdClass();
    $pane->pid = 'new-0ba7b702-3bf7-4529-9345-9774b1b7203d';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_website';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Resources',
      'override_title_heading' => 'h3',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0ba7b702-3bf7-4529-9345-9774b1b7203d';
    $display->content['new-0ba7b702-3bf7-4529-9345-9774b1b7203d'] = $pane;
    $display->panels['info_column_two'][2] = 'new-0ba7b702-3bf7-4529-9345-9774b1b7203d';
    $pane = new stdClass();
    $pane->pid = 'new-6978857a-be24-44a7-8b55-1e5ed891a5e0';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_datasheet';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '6978857a-be24-44a7-8b55-1e5ed891a5e0';
    $display->content['new-6978857a-be24-44a7-8b55-1e5ed891a5e0'] = $pane;
    $display->panels['info_column_two'][3] = 'new-6978857a-be24-44a7-8b55-1e5ed891a5e0';
    $pane = new stdClass();
    $pane->pid = 'new-13e5531d-174b-4a9a-a3f2-2e789ccff985';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_brief';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_label',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '13e5531d-174b-4a9a-a3f2-2e789ccff985';
    $display->content['new-13e5531d-174b-4a9a-a3f2-2e789ccff985'] = $pane;
    $display->panels['info_column_two'][4] = 'new-13e5531d-174b-4a9a-a3f2-2e789ccff985';
    $pane = new stdClass();
    $pane->pid = 'new-2a1d2acd-6164-45f0-9599-5de8b9101dc0';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_additional_resources';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '2a1d2acd-6164-45f0-9599-5de8b9101dc0';
    $display->content['new-2a1d2acd-6164-45f0-9599-5de8b9101dc0'] = $pane;
    $display->panels['info_column_two'][5] = 'new-2a1d2acd-6164-45f0-9599-5de8b9101dc0';
    $pane = new stdClass();
    $pane->pid = 'new-0066efb3-7166-4559-a0b0-cfa8c7a005f9';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_price_per_unit';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
        'empty_fields_handler' => 'EmptyFieldText',
        'empty_fields_emptyfieldtext_empty_text' => 'Contact Member for Pricing',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Pricing',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = '0066efb3-7166-4559-a0b0-cfa8c7a005f9';
    $display->content['new-0066efb3-7166-4559-a0b0-cfa8c7a005f9'] = $pane;
    $display->panels['info_column_two'][6] = 'new-0066efb3-7166-4559-a0b0-cfa8c7a005f9';
    $pane = new stdClass();
    $pane->pid = 'new-e886496f-46b4-4a95-825a-5e6f3377ec71';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_price_per_100_units';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
        'empty_fields_handler' => 'EmptyFieldText',
        'empty_fields_emptyfieldtext_empty_text' => 'Contact Member for Pricing',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Pricing',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'e886496f-46b4-4a95-825a-5e6f3377ec71';
    $display->content['new-e886496f-46b4-4a95-825a-5e6f3377ec71'] = $pane;
    $display->panels['info_column_two'][7] = 'new-e886496f-46b4-4a95-825a-5e6f3377ec71';
    $pane = new stdClass();
    $pane->pid = 'new-e2804a54-1b92-46d8-bb0f-b4fd6028f0f4';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_price_per_1000_units';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'number_integer',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
        'empty_fields_handler' => 'EmptyFieldText',
        'empty_fields_emptyfieldtext_empty_text' => 'Contact Member for Pricing',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => 'Pricing',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'e2804a54-1b92-46d8-bb0f-b4fd6028f0f4';
    $display->content['new-e2804a54-1b92-46d8-bb0f-b4fd6028f0f4'] = $pane;
    $display->panels['info_column_two'][8] = 'new-e2804a54-1b92-46d8-bb0f-b4fd6028f0f4';
    $pane = new stdClass();
    $pane->pid = 'new-e2114385-73de-4e3e-9c64-04af93b9d5c2';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_order_button_url';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'link_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = 'e2114385-73de-4e3e-9c64-04af93b9d5c2';
    $display->content['new-e2114385-73de-4e3e-9c64-04af93b9d5c2'] = $pane;
    $display->panels['info_column_two'][9] = 'new-e2114385-73de-4e3e-9c64-04af93b9d5c2';
    $pane = new stdClass();
    $pane->pid = 'new-4bf17eb3-b871-43db-9db9-6602489fd81b';
    $pane->panel = 'sidebar_bottom';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_community-company_articles';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Articles',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4bf17eb3-b871-43db-9db9-6602489fd81b';
    $display->content['new-4bf17eb3-b871-43db-9db9-6602489fd81b'] = $pane;
    $display->panels['sidebar_bottom'][0] = 'new-4bf17eb3-b871-43db-9db9-6602489fd81b';
    $pane = new stdClass();
    $pane->pid = 'new-b527b737-b492-43d8-b132-187d63f46286';
    $pane->panel = 'sidebar_bottom';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_community-company_whitepapers';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'White Papers',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b527b737-b492-43d8-b132-187d63f46286';
    $display->content['new-b527b737-b492-43d8-b132-187d63f46286'] = $pane;
    $display->panels['sidebar_bottom'][1] = 'new-b527b737-b492-43d8-b132-187d63f46286';
    $pane = new stdClass();
    $pane->pid = 'new-d9e65948-6c56-494f-ac95-4c3f99ef5165';
    $pane->panel = 'sidebar_top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_company';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'individual_solution',
        'links' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd9e65948-6c56-494f-ac95-4c3f99ef5165';
    $display->content['new-d9e65948-6c56-494f-ac95-4c3f99ef5165'] = $pane;
    $display->panels['sidebar_top'][0] = 'new-d9e65948-6c56-494f-ac95-4c3f99ef5165';
    $pane = new stdClass();
    $pane->pid = 'new-0f6ac72b-50b2-4b34-be14-54c51cb698f8';
    $pane->panel = 'tab_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_market_segments';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'solutions_directory_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '0f6ac72b-50b2-4b34-be14-54c51cb698f8';
    $display->content['new-0f6ac72b-50b2-4b34-be14-54c51cb698f8'] = $pane;
    $display->panels['tab_first'][0] = 'new-0f6ac72b-50b2-4b34-be14-54c51cb698f8';
    $pane = new stdClass();
    $pane->pid = 'new-e3d230b6-785a-4c72-9585-106f5b11da5d';
    $pane->panel = 'tab_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_geographic_location';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'solutions_directory_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'e3d230b6-785a-4c72-9585-106f5b11da5d';
    $display->content['new-e3d230b6-785a-4c72-9585-106f5b11da5d'] = $pane;
    $display->panels['tab_first'][1] = 'new-e3d230b6-785a-4c72-9585-106f5b11da5d';
    $pane = new stdClass();
    $pane->pid = 'new-6779d48f-8696-4640-ac59-49373efe84e4';
    $pane->panel = 'tab_first';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_application';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'solutions_directory_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '6779d48f-8696-4640-ac59-49373efe84e4';
    $display->content['new-6779d48f-8696-4640-ac59-49373efe84e4'] = $pane;
    $display->panels['tab_first'][2] = 'new-6779d48f-8696-4640-ac59-49373efe84e4';
    $pane = new stdClass();
    $pane->pid = 'new-29029a92-84ba-421f-a0b8-0eadd93f0a98';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_processors_list';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'solutions_directory_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '29029a92-84ba-421f-a0b8-0eadd93f0a98';
    $display->content['new-29029a92-84ba-421f-a0b8-0eadd93f0a98'] = $pane;
    $display->panels['tab_second'][0] = 'new-29029a92-84ba-421f-a0b8-0eadd93f0a98';
    $pane = new stdClass();
    $pane->pid = 'new-00e7aa16-46c7-4259-8689-a714be40dd48';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_intel_technologies';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'solutions_directory_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '00e7aa16-46c7-4259-8689-a714be40dd48';
    $display->content['new-00e7aa16-46c7-4259-8689-a714be40dd48'] = $pane;
    $display->panels['tab_second'][1] = 'new-00e7aa16-46c7-4259-8689-a714be40dd48';
    $pane = new stdClass();
    $pane->pid = 'new-bdb8fe1c-3327-40d8-ad3b-2f2b6498653b';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_memory_max';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'number_decimal',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'decimal_separator' => '.',
        'scale' => '2',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Memory',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'bdb8fe1c-3327-40d8-ad3b-2f2b6498653b';
    $display->content['new-bdb8fe1c-3327-40d8-ad3b-2f2b6498653b'] = $pane;
    $display->panels['tab_second'][2] = 'new-bdb8fe1c-3327-40d8-ad3b-2f2b6498653b';
    $pane = new stdClass();
    $pane->pid = 'new-b2ebd6f6-da20-4f20-8a92-1463e3260c1d';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_memory_type';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'solutions_directory_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'b2ebd6f6-da20-4f20-8a92-1463e3260c1d';
    $display->content['new-b2ebd6f6-da20-4f20-8a92-1463e3260c1d'] = $pane;
    $display->panels['tab_second'][3] = 'new-b2ebd6f6-da20-4f20-8a92-1463e3260c1d';
    $pane = new stdClass();
    $pane->pid = 'new-9a02fdde-e642-4702-88dc-14985c615052';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_stds_eth';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'solutions_directory_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '9a02fdde-e642-4702-88dc-14985c615052';
    $display->content['new-9a02fdde-e642-4702-88dc-14985c615052'] = $pane;
    $display->panels['tab_second'][4] = 'new-9a02fdde-e642-4702-88dc-14985c615052';
    $pane = new stdClass();
    $pane->pid = 'new-4760a3ac-9054-41cf-b657-b1b84c8af529';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_software_solutions';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'above',
      'formatter' => 'solutions_directory_formatter',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '4760a3ac-9054-41cf-b657-b1b84c8af529';
    $display->content['new-4760a3ac-9054-41cf-b657-b1b84c8af529'] = $pane;
    $display->panels['tab_second'][5] = 'new-4760a3ac-9054-41cf-b657-b1b84c8af529';
    $pane = new stdClass();
    $pane->pid = 'new-dd0e5fa4-efa8-4436-9a69-30e30fc10f5b';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_display_independent';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'number_integer',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Displays',
      'override_title_heading' => 'h4',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'dd0e5fa4-efa8-4436-9a69-30e30fc10f5b';
    $display->content['new-dd0e5fa4-efa8-4436-9a69-30e30fc10f5b'] = $pane;
    $display->panels['tab_second'][6] = 'new-dd0e5fa4-efa8-4436-9a69-30e30fc10f5b';
    $pane = new stdClass();
    $pane->pid = 'new-3bb61fec-4401-4032-94bc-cc47ca151454';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_display_port_edp';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'number_integer',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = '3bb61fec-4401-4032-94bc-cc47ca151454';
    $display->content['new-3bb61fec-4401-4032-94bc-cc47ca151454'] = $pane;
    $display->panels['tab_second'][7] = 'new-3bb61fec-4401-4032-94bc-cc47ca151454';
    $pane = new stdClass();
    $pane->pid = 'new-0e64fcd5-059d-4743-a191-f8c9959c2189';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_display_lvds';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'number_integer',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = '0e64fcd5-059d-4743-a191-f8c9959c2189';
    $display->content['new-0e64fcd5-059d-4743-a191-f8c9959c2189'] = $pane;
    $display->panels['tab_second'][8] = 'new-0e64fcd5-059d-4743-a191-f8c9959c2189';
    $pane = new stdClass();
    $pane->pid = 'new-4acfed5b-3996-4c3a-8817-71be3ab7cc97';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_display_vga';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'number_integer',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 9;
    $pane->locks = array();
    $pane->uuid = '4acfed5b-3996-4c3a-8817-71be3ab7cc97';
    $display->content['new-4acfed5b-3996-4c3a-8817-71be3ab7cc97'] = $pane;
    $display->panels['tab_second'][9] = 'new-4acfed5b-3996-4c3a-8817-71be3ab7cc97';
    $pane = new stdClass();
    $pane->pid = 'new-cbc60977-93e2-4872-b72f-eb5f45559fd0';
    $pane->panel = 'tab_second';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_stds_eth_ports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'inline',
      'formatter' => 'number_integer',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'thousand_separator' => ' ',
        'prefix_suffix' => 1,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 10;
    $pane->locks = array();
    $pane->uuid = 'cbc60977-93e2-4872-b72f-eb5f45559fd0';
    $display->content['new-cbc60977-93e2-4872-b72f-eb5f45559fd0'] = $pane;
    $display->panels['tab_second'][10] = 'new-cbc60977-93e2-4872-b72f-eb5f45559fd0';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_3'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_4';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 3;
  $handler->conf = array(
    'title' => 'Formula',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'formula' => 'formula',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_isdm_solution';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => array(),
      'right_top' => NULL,
      'bottom' => NULL,
      'center_top' => NULL,
      'right' => array(),
      'left' => NULL,
      'left_top' => NULL,
      'left_bottom' => NULL,
      'right_bottom' => NULL,
      'info_column_one' => NULL,
      'info_column_two' => NULL,
      'tab_first' => NULL,
      'tab_second' => NULL,
      'sidebar_top' => NULL,
      'sidebar_bottom' => NULL,
      'Middle' => NULL,
      'middle' => NULL,
    ),
    'style' => 'default',
    'left' => array(
      'style' => 'default',
    ),
    'right' => array(
      'style' => 'default',
    ),
    'left_top' => array(
      'style' => 'default',
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = 'f61c2c89-6cb5-7334-996f-61b936db0f4c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-1ae48c23-9c05-8624-8519-f68e20296e2d';
    $pane->panel = 'info_column_one';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'short',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Added',
      'override_title_heading' => 'span',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '1ae48c23-9c05-8624-8519-f68e20296e2d';
    $display->content['new-1ae48c23-9c05-8624-8519-f68e20296e2d'] = $pane;
    $display->panels['info_column_one'][0] = 'new-1ae48c23-9c05-8624-8519-f68e20296e2d';
    $pane = new stdClass();
    $pane->pid = 'new-18501839-bbf1-acf4-95e1-db561aa55beb';
    $pane->panel = 'info_column_one';
    $pane->type = 'node_content';
    $pane->subtype = 'node_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'links' => 0,
      'no_extras' => 0,
      'override_title' => 1,
      'override_title_text' => '<none>',
      'identifier' => '',
      'link' => 0,
      'leave_node_title' => 0,
      'build_mode' => 'full',
      'context' => 'argument_entity_id:node_1',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '18501839-bbf1-acf4-95e1-db561aa55beb';
    $display->content['new-18501839-bbf1-acf4-95e1-db561aa55beb'] = $pane;
    $display->panels['info_column_one'][1] = 'new-18501839-bbf1-acf4-95e1-db561aa55beb';
    $pane = new stdClass();
    $pane->pid = 'new-b8c8925f-1dda-e564-7194-38feac6a16a1';
    $pane->panel = 'info_column_one';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_pre_release';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'list_key',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'b8c8925f-1dda-e564-7194-38feac6a16a1';
    $display->content['new-b8c8925f-1dda-e564-7194-38feac6a16a1'] = $pane;
    $display->panels['info_column_one'][2] = 'new-b8c8925f-1dda-e564-7194-38feac6a16a1';
    $pane = new stdClass();
    $pane->pid = 'new-0fa06e14-38af-a104-016d-c4fa0c3738e8';
    $pane->panel = 'info_column_one';
    $pane->type = 'node_created';
    $pane->subtype = 'node_created';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'format' => 'eu_short',
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Added:',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0fa06e14-38af-a104-016d-c4fa0c3738e8';
    $display->content['new-0fa06e14-38af-a104-016d-c4fa0c3738e8'] = $pane;
    $display->panels['info_column_one'][3] = 'new-0fa06e14-38af-a104-016d-c4fa0c3738e8';
    $pane = new stdClass();
    $pane->pid = 'new-ce4e0b5b-89d9-64d4-7d3e-4329e9660d58';
    $pane->panel = 'info_column_two';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_image';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'image',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'image_style' => '200w',
        'image_link' => '',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ce4e0b5b-89d9-64d4-7d3e-4329e9660d58';
    $display->content['new-ce4e0b5b-89d9-64d4-7d3e-4329e9660d58'] = $pane;
    $display->panels['info_column_two'][0] = 'new-ce4e0b5b-89d9-64d4-7d3e-4329e9660d58';
    $pane = new stdClass();
    $pane->pid = 'new-9e146512-f872-0a64-6947-397488e55b3b';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_component_group';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'field_collection_fields',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(
        'edit' => '',
        'delete' => '',
        'add' => '',
        'description' => 0,
        'view_mode' => 'single',
        'name' => 'field_collection_view',
        'display_id' => 'default',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Components',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '9e146512-f872-0a64-6947-397488e55b3b';
    $display->content['new-9e146512-f872-0a64-6947-397488e55b3b'] = $pane;
    $display->panels['middle'][0] = 'new-9e146512-f872-0a64-6947-397488e55b3b';
    $pane = new stdClass();
    $pane->pid = 'new-f61aeefe-0609-18b4-ed0f-6643fbeba9b9';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_bill_of_materials';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'file_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'file_view_mode' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => 'Bill of Materials',
      'admin_title' => '',
      'title' => 'Bill of Materials',
      'body' => '<p>Download the bill of materials for this formula:</p>',
      'format' => 'wysiwyg_basic',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'f61aeefe-0609-18b4-ed0f-6643fbeba9b9';
    $display->content['new-f61aeefe-0609-18b4-ed0f-6643fbeba9b9'] = $pane;
    $display->panels['middle'][1] = 'new-f61aeefe-0609-18b4-ed0f-6643fbeba9b9';
    $pane = new stdClass();
    $pane->pid = 'new-0e9f31d1-ffbb-2604-2d7f-738fb2da2dfb';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_formula_resources';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'title',
      'formatter' => 'link_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '0e9f31d1-ffbb-2604-2d7f-738fb2da2dfb';
    $display->content['new-0e9f31d1-ffbb-2604-2d7f-738fb2da2dfb'] = $pane;
    $display->panels['middle'][2] = 'new-0e9f31d1-ffbb-2604-2d7f-738fb2da2dfb';
    $pane = new stdClass();
    $pane->pid = 'new-8beb9122-6ce0-6f04-1dd4-59e4f9893a12';
    $pane->panel = 'sidebar_bottom';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-aprimo_solution_company_btn';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '8beb9122-6ce0-6f04-1dd4-59e4f9893a12';
    $display->content['new-8beb9122-6ce0-6f04-1dd4-59e4f9893a12'] = $pane;
    $display->panels['sidebar_bottom'][0] = 'new-8beb9122-6ce0-6f04-1dd4-59e4f9893a12';
    $pane = new stdClass();
    $pane->pid = 'new-14cf916a-9e14-dc74-55a9-78c8b7792bd2';
    $pane->panel = 'sidebar_bottom';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-aprimo_solution_intel_btn';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '14cf916a-9e14-dc74-55a9-78c8b7792bd2';
    $display->content['new-14cf916a-9e14-dc74-55a9-78c8b7792bd2'] = $pane;
    $display->panels['sidebar_bottom'][1] = 'new-14cf916a-9e14-dc74-55a9-78c8b7792bd2';
    $pane = new stdClass();
    $pane->pid = 'new-807b6770-4f22-61f4-d1e7-604e0b9d369f';
    $pane->panel = 'sidebar_bottom';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-aprimo_formula_integrator_links';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'System Integrator(s)',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '807b6770-4f22-61f4-d1e7-604e0b9d369f';
    $display->content['new-807b6770-4f22-61f4-d1e7-604e0b9d369f'] = $pane;
    $display->panels['sidebar_bottom'][2] = 'new-807b6770-4f22-61f4-d1e7-604e0b9d369f';
    $pane = new stdClass();
    $pane->pid = 'new-d9d875c0-84ca-be74-51e5-b15a8167f41d';
    $pane->panel = 'sidebar_top';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_company';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'entityreference_entity_view',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'view_mode' => 'solution_list_quickview',
        'links' => 0,
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'd9d875c0-84ca-be74-51e5-b15a8167f41d';
    $display->content['new-d9d875c0-84ca-be74-51e5-b15a8167f41d'] = $pane;
    $display->panels['sidebar_top'][0] = 'new-d9d875c0-84ca-be74-51e5-b15a8167f41d';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_4'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_5';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 4;
  $handler->conf = array(
    'title' => 'Training Section',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'training-section-%node:field-section-order',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'training_section' => 'training_section',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:training_section:field_ajax_section',
          'settings' => array(
            'field_ajax_section' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_ajax_section_value' => '1',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_12_onecol_12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title %node:field-sub-title';
  $display->uuid = 'f3586fb8-e59d-2854-9990-120eecb6525c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b578a31a-62a0-18d4-7540-5422f22e0452';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'training_section_content_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b578a31a-62a0-18d4-7540-5422f22e0452';
    $display->content['new-b578a31a-62a0-18d4-7540-5422f22e0452'] = $pane;
    $display->panels['middle'][0] = 'new-b578a31a-62a0-18d4-7540-5422f22e0452';
    $pane = new stdClass();
    $pane->pid = 'new-a6a6452b-c235-0974-e15d-314b17147271';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_video';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:training_section:field_persistent_introduction',
          'settings' => array(
            'field_persistent_introduction' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_persistent_introduction_value' => '1',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'video_embed_field',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(
        'video_style' => 'full',
      ),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a6a6452b-c235-0974-e15d-314b17147271';
    $display->content['new-a6a6452b-c235-0974-e15d-314b17147271'] = $pane;
    $display->panels['middle'][1] = 'new-a6a6452b-c235-0974-e15d-314b17147271';
    $pane = new stdClass();
    $pane->pid = 'new-5997056a-85dc-8f44-81ab-018f856e2d96';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'training_section_tabs_pdf';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '5997056a-85dc-8f44-81ab-018f856e2d96';
    $display->content['new-5997056a-85dc-8f44-81ab-018f856e2d96'] = $pane;
    $display->panels['middle'][2] = 'new-5997056a-85dc-8f44-81ab-018f856e2d96';
    $pane = new stdClass();
    $pane->pid = 'new-459d4101-974f-7444-5993-1c622e4165b2';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_content_blocks';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '459d4101-974f-7444-5993-1c622e4165b2';
    $display->content['new-459d4101-974f-7444-5993-1c622e4165b2'] = $pane;
    $display->panels['middle'][3] = 'new-459d4101-974f-7444-5993-1c622e4165b2';
    $pane = new stdClass();
    $pane->pid = 'new-a5c02671-d007-b064-956e-a54a890dc7c9';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'training_section_slides-slideshow';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:training_section:field_section_order',
          'settings' => array(
            'field_section_order' => array(
              'und' => array(
                0 => array(
                  'value' => 'A',
                ),
              ),
            ),
            'field_section_order_value' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
            'field_section_order_format' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'a5c02671-d007-b064-956e-a54a890dc7c9';
    $display->content['new-a5c02671-d007-b064-956e-a54a890dc7c9'] = $pane;
    $display->panels['middle'][4] = 'new-a5c02671-d007-b064-956e-a54a890dc7c9';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_5'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_6';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 5;
  $handler->conf = array(
    'title' => 'Training Sub-Section',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'training-section-%node_2:field-section-order',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(
      0 => array(
        'identifier' => 'Content from Content (on Content: Training Section [field_training_section])',
        'keyword' => 'node_2',
        'name' => 'entity_from_field:field_training_section-node-node',
        'delta' => 0,
        'context' => 'argument_entity_id:node_1',
        'id' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'training_sub_section' => 'training_sub_section',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_12_onecol_12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title';
  $display->uuid = '51e95290-e5ce-d434-459b-70d5295bff8d';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-6597470c-3624-5a44-9976-cb4bb949254f';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'training_sub_section_tabs_pdf';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:training_section:field_section_order',
          'settings' => array(
            'field_section_order' => array(
              'und' => array(
                0 => array(
                  'value' => 'A',
                ),
              ),
            ),
            'field_section_order_value' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
            'field_section_order_format' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
          ),
          'context' => 'relationship_entity_from_field:field_training_section-node-node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'relationship_entity_from_field:field_training_section-node-node_1',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '6597470c-3624-5a44-9976-cb4bb949254f';
    $display->content['new-6597470c-3624-5a44-9976-cb4bb949254f'] = $pane;
    $display->panels['middle'][0] = 'new-6597470c-3624-5a44-9976-cb4bb949254f';
    $pane = new stdClass();
    $pane->pid = 'new-1dff5c8b-b03e-9ef4-b937-2cd305b9a63d';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'training_sub_section_header';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:training_section:field_section_order',
          'settings' => array(
            'field_section_order' => array(
              'und' => array(
                0 => array(
                  'value' => 'A',
                ),
              ),
            ),
            'field_section_order_value' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
            'field_section_order_format' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
          ),
          'context' => 'relationship_entity_from_field:field_training_section-node-node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '1dff5c8b-b03e-9ef4-b937-2cd305b9a63d';
    $display->content['new-1dff5c8b-b03e-9ef4-b937-2cd305b9a63d'] = $pane;
    $display->panels['middle'][1] = 'new-1dff5c8b-b03e-9ef4-b937-2cd305b9a63d';
    $pane = new stdClass();
    $pane->pid = 'new-f5e51607-82c7-9c94-c5ea-45ea0a80f365';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'training_sub_section_videos-slideshow';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:training_section:field_section_order',
          'settings' => array(
            'field_section_order' => array(
              'und' => array(
                0 => array(
                  'value' => 'A',
                ),
              ),
            ),
            'field_section_order_value' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
            'field_section_order_format' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
          ),
          'context' => 'relationship_entity_from_field:field_training_section-node-node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'f5e51607-82c7-9c94-c5ea-45ea0a80f365';
    $display->content['new-f5e51607-82c7-9c94-c5ea-45ea0a80f365'] = $pane;
    $display->panels['middle'][2] = 'new-f5e51607-82c7-9c94-c5ea-45ea0a80f365';
    $pane = new stdClass();
    $pane->pid = 'new-a5107814-1cdf-0314-b132-8c0242484e73';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_content_blocks';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => '0',
      'delta_offset' => '0',
      'delta_reversed' => 0,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'a5107814-1cdf-0314-b132-8c0242484e73';
    $display->content['new-a5107814-1cdf-0314-b132-8c0242484e73'] = $pane;
    $display->panels['middle'][3] = 'new-a5107814-1cdf-0314-b132-8c0242484e73';
    $pane = new stdClass();
    $pane->pid = 'new-486d6e9a-a3e6-ced4-d108-0d38eba8c0e1';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_training_center-approved_nouns';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:training_section:field_section_order',
          'settings' => array(
            'field_section_order' => array(
              'und' => array(
                0 => array(
                  'value' => 'D',
                ),
              ),
            ),
            'field_section_order_value' => array(
              0 => array(
                'value' => 'D',
              ),
            ),
            'field_section_order_format' => array(
              0 => array(
                'value' => 'D',
              ),
            ),
          ),
          'context' => 'relationship_entity_from_field:field_training_section-node-node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:training_sub_section:field_sub_section_order',
          'settings' => array(
            'field_sub_section_order' => array(
              'und' => array(
                0 => array(
                  'value' => '1',
                ),
              ),
            ),
            'field_sub_section_order_value' => array(
              0 => array(
                'value' => '1',
              ),
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '486d6e9a-a3e6-ced4-d108-0d38eba8c0e1';
    $display->content['new-486d6e9a-a3e6-ced4-d108-0d38eba8c0e1'] = $pane;
    $display->panels['middle'][4] = 'new-486d6e9a-a3e6-ced4-d108-0d38eba8c0e1';
    $pane = new stdClass();
    $pane->pid = 'new-30e6ac8e-3984-8e54-4d69-e8f6541e7fcb';
    $pane->panel = 'middle';
    $pane->type = 'views_panes';
    $pane->subtype = 'training_sub_section_slides-slideshow';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:training_section:field_section_order',
          'settings' => array(
            'field_section_order' => array(
              'und' => array(
                0 => array(
                  'value' => 'A',
                ),
              ),
            ),
            'field_section_order_value' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
            'field_section_order_format' => array(
              0 => array(
                'value' => 'A',
              ),
            ),
          ),
          'context' => 'relationship_entity_from_field:field_training_section-node-node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '30e6ac8e-3984-8e54-4d69-e8f6541e7fcb';
    $display->content['new-30e6ac8e-3984-8e54-4d69-e8f6541e7fcb'] = $pane;
    $display->panels['middle'][5] = 'new-30e6ac8e-3984-8e54-4d69-e8f6541e7fcb';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_6'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'node_view_panel_context_7';
  $handler->task = 'node_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 6;
  $handler->conf = array(
    'title' => 'Training Section (Ajax)',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => 'training-section-%node:field-section-order',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'training_section' => 'training_section',
            ),
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_field_value:node:training_section:field_ajax_section',
          'settings' => array(
            'field_ajax_section' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_ajax_section_value' => '1',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_12_onecol_12';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%node:title %node:field-sub-title';
  $display->uuid = 'f3586fb8-e59d-2854-9990-120eecb6525c';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b578a31a-62a0-18d4-7540-5422f22e0452';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'training_section_content_header';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b578a31a-62a0-18d4-7540-5422f22e0452';
    $display->content['new-b578a31a-62a0-18d4-7540-5422f22e0452'] = $pane;
    $display->panels['middle'][0] = 'new-b578a31a-62a0-18d4-7540-5422f22e0452';
    $pane = new stdClass();
    $pane->pid = 'new-7277cc8f-0889-3ad4-613c-30bc2ee0ba9a';
    $pane->panel = 'middle';
    $pane->type = 'entity_field';
    $pane->subtype = 'node:field_introduction_content';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_field_value:node:training_section:field_persistent_introduction',
          'settings' => array(
            'field_persistent_introduction' => array(
              'und' => array(
                0 => array(
                  'value' => 1,
                ),
              ),
            ),
            'field_persistent_introduction_value' => '1',
          ),
          'context' => 'argument_entity_id:node_1',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'text_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_entity_id:node_1',
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7277cc8f-0889-3ad4-613c-30bc2ee0ba9a';
    $display->content['new-7277cc8f-0889-3ad4-613c-30bc2ee0ba9a'] = $pane;
    $display->panels['middle'][1] = 'new-7277cc8f-0889-3ad4-613c-30bc2ee0ba9a';
    $pane = new stdClass();
    $pane->pid = 'new-e117520c-8a97-8f64-4902-7dfd29149616';
    $pane->panel = 'middle';
    $pane->type = 'panels_mini';
    $pane->subtype = 'training_section_tabs_pdf';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'context' => array(
        0 => 'argument_entity_id:node_1',
      ),
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'e117520c-8a97-8f64-4902-7dfd29149616';
    $display->content['new-e117520c-8a97-8f64-4902-7dfd29149616'] = $pane;
    $display->panels['middle'][2] = 'new-e117520c-8a97-8f64-4902-7dfd29149616';
    $pane = new stdClass();
    $pane->pid = 'new-ab9e04b6-57ed-a914-bd84-ad1efe8fee34';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_training_center-training_section_tabs_content';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'ab9e04b6-57ed-a914-bd84-ad1efe8fee34';
    $display->content['new-ab9e04b6-57ed-a914-bd84-ad1efe8fee34'] = $pane;
    $display->panels['middle'][3] = 'new-ab9e04b6-57ed-a914-bd84-ad1efe8fee34';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['node_view_panel_context_7'] = $handler;

  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'term_view_panel_context';
  $handler->task = 'term_view';
  $handler->subtask = '';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Opportunity Group',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'vids' => array(
              31 => '31',
            ),
          ),
          'context' => 'argument_term_1',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_12_twocol_3_6_stacked_bricks';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'left_top' => NULL,
      'right_top' => NULL,
      'bottom' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '%term:i18n-name';
  $display->uuid = 'e1696e4e-6d2d-f644-0d99-0f3310d064b2';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-aacc2c9f-9708-1974-81d8-5eb84f8bec6a';
    $pane->panel = 'bottom';
    $pane->type = 'views_panes';
    $pane->subtype = 'opportunity_group_opportunities-non_sticky';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => 'Market Development Funds',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aacc2c9f-9708-1974-81d8-5eb84f8bec6a';
    $display->content['new-aacc2c9f-9708-1974-81d8-5eb84f8bec6a'] = $pane;
    $display->panels['bottom'][0] = 'new-aacc2c9f-9708-1974-81d8-5eb84f8bec6a';
    $pane = new stdClass();
    $pane->pid = 'new-51a7f4f9-e2ce-e6f4-fdb1-aedd8f661055';
    $pane->panel = 'left_top';
    $pane->type = 'entity_field';
    $pane->subtype = 'taxonomy_term:field_image_unlimited_view';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'label' => 'hidden',
      'formatter' => 'viewfield_default',
      'delta_limit' => 0,
      'delta_offset' => '0',
      'delta_reversed' => FALSE,
      'formatter_settings' => array(),
      'context' => 'argument_term_1',
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '51a7f4f9-e2ce-e6f4-fdb1-aedd8f661055';
    $display->content['new-51a7f4f9-e2ce-e6f4-fdb1-aedd8f661055'] = $pane;
    $display->panels['left_top'][0] = 'new-51a7f4f9-e2ce-e6f4-fdb1-aedd8f661055';
    $pane = new stdClass();
    $pane->pid = 'new-aa289175-425a-4e42-ae31-f02d287decc5';
    $pane->panel = 'right_top';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '%term:i18n-description',
      'format' => 'wysiwyg_basic',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'aa289175-425a-4e42-ae31-f02d287decc5';
    $display->content['new-aa289175-425a-4e42-ae31-f02d287decc5'] = $pane;
    $display->panels['right_top'][0] = 'new-aa289175-425a-4e42-ae31-f02d287decc5';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $export['term_view_panel_context'] = $handler;

  return $export;
}

/**
 * Implements hook_default_page_manager_pages().
 */
function intel_ea_feature_default_page_manager_pages() {
  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'co_marketing_tool_landing';
  $page->task = 'page';
  $page->admin_title = 'Co-Marketing Tool Landing';
  $page->admin_description = 'The Co-Marketing Tool landing page with eligible opportunities listed by opportunity group.';
  $page->path = 'co-marketing-tool';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 4,
            2 => 9,
            3 => 10,
            4 => 11,
            5 => 13,
            6 => 14,
            7 => 16,
            8 => 6,
            9 => 17,
            10 => 18,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_co_marketing_tool_landing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'co_marketing_tool_landing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'intel_12_onecol_9';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '66736c4f-8c2e-69f4-1d2b-26e7ba897db4';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b10c09d8-f545-4030-bac0-8c226b4aa4ad';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'block-9';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b10c09d8-f545-4030-bac0-8c226b4aa4ad';
    $display->content['new-b10c09d8-f545-4030-bac0-8c226b4aa4ad'] = $pane;
    $display->panels['middle'][0] = 'new-b10c09d8-f545-4030-bac0-8c226b4aa4ad';
    $pane = new stdClass();
    $pane->pid = 'new-c0d40c5b-cf11-bde4-ed54-f0663b131f3f';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'opportunity_groups';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'default',
      'override_title' => 1,
      'override_title_text' => 'Eligible Opportunities',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'c0d40c5b-cf11-bde4-ed54-f0663b131f3f';
    $display->content['new-c0d40c5b-cf11-bde4-ed54-f0663b131f3f'] = $pane;
    $display->panels['middle'][1] = 'new-c0d40c5b-cf11-bde4-ed54-f0663b131f3f';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = 'new-c0d40c5b-cf11-bde4-ed54-f0663b131f3f';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['co_marketing_tool_landing'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'member_resource_center';
  $page->task = 'page';
  $page->admin_title = 'Member Resource Center';
  $page->admin_description = '';
  $page->path = 'member-resource-center';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 2,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Members Resource Center',
    'name' => 'menu-site-navigation',
    'weight' => '-46',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_member_resource_center_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'member_resource_center';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel (members)',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
              1 => 4,
              2 => 8,
              3 => 9,
              4 => 10,
              5 => 11,
              6 => 12,
              7 => 13,
              8 => 28,
              9 => 14,
              10 => 15,
              11 => 5,
              12 => 16,
              13 => 6,
              14 => 27,
              15 => 25,
              16 => 24,
              17 => 26,
              18 => 29,
              19 => 17,
              20 => 18,
              21 => 19,
              22 => 20,
              23 => 21,
              24 => 30,
              25 => 31,
              26 => 32,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $display = new panels_display();
  $display->layout = 'intel_isdm_internal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left_top' => NULL,
      'right_top' => NULL,
      'bottom' => NULL,
      'panel_title' => NULL,
      'top_blue' => NULL,
      'bottom_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Members Resource Center';
  $display->uuid = '59857b08-c7df-de34-09bd-258a80b69afe';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4dff7ca7-0b3f-471b-a593-f59c13a65f66';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'block-10';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => 'Members Resource Center at a Glance',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4dff7ca7-0b3f-471b-a593-f59c13a65f66';
    $display->content['new-4dff7ca7-0b3f-471b-a593-f59c13a65f66'] = $pane;
    $display->panels['bottom_main'][0] = 'new-4dff7ca7-0b3f-471b-a593-f59c13a65f66';
    $pane = new stdClass();
    $pane->pid = 'new-b9fbeab2-1493-cd44-c9d5-05811ff10096';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-mrc_program_newsletters';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b9fbeab2-1493-cd44-c9d5-05811ff10096';
    $display->content['new-b9fbeab2-1493-cd44-c9d5-05811ff10096'] = $pane;
    $display->panels['bottom_main'][1] = 'new-b9fbeab2-1493-cd44-c9d5-05811ff10096';
    $pane = new stdClass();
    $pane->pid = 'new-d5bcf963-7bfa-f644-45f0-bee9cec1d800';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-mrc_member_trainings_events';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd5bcf963-7bfa-f644-45f0-bee9cec1d800';
    $display->content['new-d5bcf963-7bfa-f644-45f0-bee9cec1d800'] = $pane;
    $display->panels['bottom_main'][2] = 'new-d5bcf963-7bfa-f644-45f0-bee9cec1d800';
    $pane = new stdClass();
    $pane->pid = 'new-53b029ac-caee-6cd4-9dc0-89a754e15e21';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'block-4';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '53b029ac-caee-6cd4-9dc0-89a754e15e21';
    $display->content['new-53b029ac-caee-6cd4-9dc0-89a754e15e21'] = $pane;
    $display->panels['bottom_main'][3] = 'new-53b029ac-caee-6cd4-9dc0-89a754e15e21';
    $pane = new stdClass();
    $pane->pid = 'new-a1dba4ac-81bb-5af4-79f9-8f89cec519d9';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-mrc_brand_programs';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'a1dba4ac-81bb-5af4-79f9-8f89cec519d9';
    $display->content['new-a1dba4ac-81bb-5af4-79f9-8f89cec519d9'] = $pane;
    $display->panels['bottom_main'][4] = 'new-a1dba4ac-81bb-5af4-79f9-8f89cec519d9';
    $pane = new stdClass();
    $pane->pid = 'new-9cb4949c-e757-4aba-bd38-96468936b5b9';
    $pane->panel = 'bottom_main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Welcome To Your Solution Directory Management Interface',
      'body' => '<p>This is your area to review, add and modify your current postings using the menu options in the left hand navigation.</p><p><strong>Advertise Your Solutions</strong><br />Make the most of every Solutions Directory entry so developers, engineers, and business and IT professionals&mdash;as well as Intel Sales&mdash;see the full potential of your products, services and solutions.</p><p><strong>Target Market Segments</strong><br />Update existing entries to reach more of your targeted market segments.</p><p><strong>Add New Solutions</strong><br />Make new entries and review current postings to improve them with more descriptive titles and copy. Add entries for each of your product offerings including focuses for hardware, software, systems, services and end-to-end solutions or formulas.</p><p><strong>Assign Editors</strong><br />Make sure all the right people in your organization have the right access to enter and edit solution entries in the directory. Set up access and permissions now.</p><p><a href="http://www.intel.com/solutionsalliance" target=_blank">Go to Alliance Member Resource Center</a><br /><a href="http://www.intel.com/technologyprovider" target=_blank">Go to Intel® Technology Provider website</a></p>',
      'format' => 'wysiwyg_basic',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '9cb4949c-e757-4aba-bd38-96468936b5b9';
    $display->content['new-9cb4949c-e757-4aba-bd38-96468936b5b9'] = $pane;
    $display->panels['bottom_main'][5] = 'new-9cb4949c-e757-4aba-bd38-96468936b5b9';
    $pane = new stdClass();
    $pane->pid = 'new-c26c46aa-5eb0-2fe4-89e7-79581714a52e';
    $pane->panel = 'top_blue';
    $pane->type = 'panels_mini';
    $pane->subtype = 'mrc_company';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c26c46aa-5eb0-2fe4-89e7-79581714a52e';
    $display->content['new-c26c46aa-5eb0-2fe4-89e7-79581714a52e'] = $pane;
    $display->panels['top_blue'][0] = 'new-c26c46aa-5eb0-2fe4-89e7-79581714a52e';
    $pane = new stdClass();
    $pane->pid = 'new-30f72119-73c3-c244-2d6c-31f833d7162d';
    $pane->panel = 'top_blue';
    $pane->type = 'panels_mini';
    $pane->subtype = 'mrc_notifications';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '30f72119-73c3-c244-2d6c-31f833d7162d';
    $display->content['new-30f72119-73c3-c244-2d6c-31f833d7162d'] = $pane;
    $display->panels['top_blue'][1] = 'new-30f72119-73c3-c244-2d6c-31f833d7162d';
    $pane = new stdClass();
    $pane->pid = 'new-dd74932c-2af0-a824-3949-ec20d0cc778c';
    $pane->panel = 'top_blue';
    $pane->type = 'panels_mini';
    $pane->subtype = 'mrc_resources_middle';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'dd74932c-2af0-a824-3949-ec20d0cc778c';
    $display->content['new-dd74932c-2af0-a824-3949-ec20d0cc778c'] = $pane;
    $display->panels['top_blue'][2] = 'new-dd74932c-2af0-a824-3949-ec20d0cc778c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_member_resource_center__users-with-no-company-association';
  $handler->task = 'page';
  $handler->subtask = 'member_resource_center';
  $handler->handler = 'panel_context';
  $handler->weight = 1;
  $handler->conf = array(
    'title' => 'Users with no company association',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
    'name' => 'users-with-no-company-association',
  );
  $display = new panels_display();
  $display->layout = 'intel_isdm_internal';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'left_top' => NULL,
      'right_top' => NULL,
      'bottom' => NULL,
      'panel_title' => NULL,
      'top_blue' => NULL,
      'bottom_main' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Members Resource Center';
  $display->uuid = '59857b08-c7df-de34-09bd-258a80b69afe';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-4dff7ca7-0b3f-471b-a593-f59c13a65f66';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'block-10';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => 'Members Resource Center at a Glance',
      'override_title_heading' => 'h2',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = '4dff7ca7-0b3f-471b-a593-f59c13a65f66';
    $display->content['new-4dff7ca7-0b3f-471b-a593-f59c13a65f66'] = $pane;
    $display->panels['bottom_main'][0] = 'new-4dff7ca7-0b3f-471b-a593-f59c13a65f66';
    $pane = new stdClass();
    $pane->pid = 'new-b9fbeab2-1493-cd44-c9d5-05811ff10096';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-mrc_program_newsletters';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'b9fbeab2-1493-cd44-c9d5-05811ff10096';
    $display->content['new-b9fbeab2-1493-cd44-c9d5-05811ff10096'] = $pane;
    $display->panels['bottom_main'][1] = 'new-b9fbeab2-1493-cd44-c9d5-05811ff10096';
    $pane = new stdClass();
    $pane->pid = 'new-d5bcf963-7bfa-f644-45f0-bee9cec1d800';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-mrc_member_trainings_events';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'd5bcf963-7bfa-f644-45f0-bee9cec1d800';
    $display->content['new-d5bcf963-7bfa-f644-45f0-bee9cec1d800'] = $pane;
    $display->panels['bottom_main'][2] = 'new-d5bcf963-7bfa-f644-45f0-bee9cec1d800';
    $pane = new stdClass();
    $pane->pid = 'new-53b029ac-caee-6cd4-9dc0-89a754e15e21';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'block-4';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '53b029ac-caee-6cd4-9dc0-89a754e15e21';
    $display->content['new-53b029ac-caee-6cd4-9dc0-89a754e15e21'] = $pane;
    $display->panels['bottom_main'][3] = 'new-53b029ac-caee-6cd4-9dc0-89a754e15e21';
    $pane = new stdClass();
    $pane->pid = 'new-a1dba4ac-81bb-5af4-79f9-8f89cec519d9';
    $pane->panel = 'bottom_main';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-mrc_brand_programs';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = 'a1dba4ac-81bb-5af4-79f9-8f89cec519d9';
    $display->content['new-a1dba4ac-81bb-5af4-79f9-8f89cec519d9'] = $pane;
    $display->panels['bottom_main'][4] = 'new-a1dba4ac-81bb-5af4-79f9-8f89cec519d9';
    $pane = new stdClass();
    $pane->pid = 'new-6065e979-67f7-4576-9917-683fa8279539';
    $pane->panel = 'bottom_main';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => 'Welcome To The Solution Directory Management Interface',
      'body' => '<p>Thank you for your interest in the Intel Solution Directory. If you would like to post a solution, please request access by <a href="mailto:inteltechnologyprovider_iot@intel.com">emailing us</a> with the following information:</p><p>First and Last Name<br />Email Address<br />Company Name<br />Company Website Address</p><p>Your access will be enabled, and you will receive a confirmation email within the next 3-5 business days.</p>',
      'format' => 'wysiwyg_basic_w_links',
      'substitute' => TRUE,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = '6065e979-67f7-4576-9917-683fa8279539';
    $display->content['new-6065e979-67f7-4576-9917-683fa8279539'] = $pane;
    $display->panels['bottom_main'][5] = 'new-6065e979-67f7-4576-9917-683fa8279539';
    $pane = new stdClass();
    $pane->pid = 'new-c26c46aa-5eb0-2fe4-89e7-79581714a52e';
    $pane->panel = 'top_blue';
    $pane->type = 'panels_mini';
    $pane->subtype = 'mrc_company';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'c26c46aa-5eb0-2fe4-89e7-79581714a52e';
    $display->content['new-c26c46aa-5eb0-2fe4-89e7-79581714a52e'] = $pane;
    $display->panels['top_blue'][0] = 'new-c26c46aa-5eb0-2fe4-89e7-79581714a52e';
    $pane = new stdClass();
    $pane->pid = 'new-30f72119-73c3-c244-2d6c-31f833d7162d';
    $pane->panel = 'top_blue';
    $pane->type = 'panels_mini';
    $pane->subtype = 'mrc_notifications';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 1,
      'override_title_text' => '<none>',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '30f72119-73c3-c244-2d6c-31f833d7162d';
    $display->content['new-30f72119-73c3-c244-2d6c-31f833d7162d'] = $pane;
    $display->panels['top_blue'][1] = 'new-30f72119-73c3-c244-2d6c-31f833d7162d';
    $pane = new stdClass();
    $pane->pid = 'new-dd74932c-2af0-a824-3949-ec20d0cc778c';
    $pane->panel = 'top_blue';
    $pane->type = 'panels_mini';
    $pane->subtype = 'mrc_resources_middle';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = 'dd74932c-2af0-a824-3949-ec20d0cc778c';
    $display->content['new-dd74932c-2af0-a824-3949-ec20d0cc778c'] = $pane;
    $display->panels['top_blue'][2] = 'new-dd74932c-2af0-a824-3949-ec20d0cc778c';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['member_resource_center'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'member_roster_landing';
  $page->task = 'page';
  $page->admin_title = 'Member Roster Landing';
  $page->admin_description = 'The Member Roster landing page with companies listed by membership type.';
  $page->path = 'member-roster';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Partner Companies',
    'name' => 'menu-site-navigation',
    'weight' => '-47',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_member_roster_landing_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'member_roster_landing';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'intel_isdm_directories';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'panel_title' => NULL,
      'top_blue' => NULL,
      'bottom_main' => NULL,
      'sidebar_top' => NULL,
      'sidebar_bottom' => NULL,
      'main_content' => NULL,
      'filters' => NULL,
      'pagination' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Partner Companies';
  $display->uuid = '66bc778b-6c32-1c64-ad41-5ade735f5ecd';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-b3a03399-d2e1-c604-4117-1f1f3cc41f55';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'member_roster-premier';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array(
      'css_id' => '',
      'css_class' => 'pane-member-roster-premier',
    );
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'b3a03399-d2e1-c604-4117-1f1f3cc41f55';
    $display->content['new-b3a03399-d2e1-c604-4117-1f1f3cc41f55'] = $pane;
    $display->panels['main_content'][0] = 'new-b3a03399-d2e1-c604-4117-1f1f3cc41f55';
    $pane = new stdClass();
    $pane->pid = 'new-9a4b262a-9df0-475c-9060-a059435784c7';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'member_roster-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '9a4b262a-9df0-475c-9060-a059435784c7';
    $display->content['new-9a4b262a-9df0-475c-9060-a059435784c7'] = $pane;
    $display->panels['main_content'][1] = 'new-9a4b262a-9df0-475c-9060-a059435784c7';
    $pane = new stdClass();
    $pane->pid = 'new-38923c82-39f2-6be4-c992-bb54009aaba8';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'member_roster-associate';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '38923c82-39f2-6be4-c992-bb54009aaba8';
    $display->content['new-38923c82-39f2-6be4-c992-bb54009aaba8'] = $pane;
    $display->panels['main_content'][2] = 'new-38923c82-39f2-6be4-c992-bb54009aaba8';
    $pane = new stdClass();
    $pane->pid = 'new-4a828232-12a9-446e-bdf6-814913322a6b';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'member_roster-panel_pane_2';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '4a828232-12a9-446e-bdf6-814913322a6b';
    $display->content['new-4a828232-12a9-446e-bdf6-814913322a6b'] = $pane;
    $display->panels['main_content'][3] = 'new-4a828232-12a9-446e-bdf6-814913322a6b';
    $pane = new stdClass();
    $pane->pid = 'new-078b014d-45b4-a6a4-29ae-d0e36504a25d';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'member_roster-affiliate';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '078b014d-45b4-a6a4-29ae-d0e36504a25d';
    $display->content['new-078b014d-45b4-a6a4-29ae-d0e36504a25d'] = $pane;
    $display->panels['main_content'][4] = 'new-078b014d-45b4-a6a4-29ae-d0e36504a25d';
    $pane = new stdClass();
    $pane->pid = 'new-aa28693c-626f-4a2a-9124-deb5ad6d5a74';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'member_roster-panel_pane_3';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'aa28693c-626f-4a2a-9124-deb5ad6d5a74';
    $display->content['new-aa28693c-626f-4a2a-9124-deb5ad6d5a74'] = $pane;
    $display->panels['main_content'][5] = 'new-aa28693c-626f-4a2a-9124-deb5ad6d5a74';
    $pane = new stdClass();
    $pane->pid = 'new-d6679091-9bee-73b4-95a0-89bdd7d06070';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'member_roster-general';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array();
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'd6679091-9bee-73b4-95a0-89bdd7d06070';
    $display->content['new-d6679091-9bee-73b4-95a0-89bdd7d06070'] = $pane;
    $display->panels['main_content'][6] = 'new-d6679091-9bee-73b4-95a0-89bdd7d06070';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['member_roster_landing'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'reports';
  $page->task = 'page';
  $page->admin_title = 'Reports';
  $page->admin_description = '';
  $page->path = 'member-resource-center/reports';
  $page->access = array(
    'logic' => 'and',
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 4,
            2 => 9,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'type' => 'none',
    'settings' => NULL,
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Summary Statistics',
    'name' => 'menu-reports',
    'weight' => '-50',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_reports_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'reports';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'center' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Reports';
  $display->uuid = '94f7c674-56a3-a634-a953-7257c62171a0';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-fb267cd2-f73a-8bb4-25dc-dc718162d329';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-user_statistics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'fb267cd2-f73a-8bb4-25dc-dc718162d329';
    $display->content['new-fb267cd2-f73a-8bb4-25dc-dc718162d329'] = $pane;
    $display->panels['middle'][0] = 'new-fb267cd2-f73a-8bb4-25dc-dc718162d329';
    $pane = new stdClass();
    $pane->pid = 'new-7a85d426-a1db-9254-512e-4a7fcf8560b1';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-company_statistics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '7a85d426-a1db-9254-512e-4a7fcf8560b1';
    $display->content['new-7a85d426-a1db-9254-512e-4a7fcf8560b1'] = $pane;
    $display->panels['middle'][1] = 'new-7a85d426-a1db-9254-512e-4a7fcf8560b1';
    $pane = new stdClass();
    $pane->pid = 'new-8a42b918-4377-e404-016d-1ef34770c055';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-company_memberships';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '8a42b918-4377-e404-016d-1ef34770c055';
    $display->content['new-8a42b918-4377-e404-016d-1ef34770c055'] = $pane;
    $display->panels['middle'][2] = 'new-8a42b918-4377-e404-016d-1ef34770c055';
    $pane = new stdClass();
    $pane->pid = 'new-0d9b47de-c1b6-d864-3526-447f86c6b4ef';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-solution_statistics';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = '0d9b47de-c1b6-d864-3526-447f86c6b4ef';
    $display->content['new-0d9b47de-c1b6-d864-3526-447f86c6b4ef'] = $pane;
    $display->panels['middle'][3] = 'new-0d9b47de-c1b6-d864-3526-447f86c6b4ef';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = 'new-fb267cd2-f73a-8bb4-25dc-dc718162d329';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['reports'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'solutions_directory';
  $page->task = 'page';
  $page->admin_title = 'Solutions Directory';
  $page->admin_description = '';
  $page->path = 'solutions-directory';
  $page->access = array(
    'type' => 'none',
    'settings' => NULL,
    'plugins' => array(),
    'logic' => 'and',
  );
  $page->menu = array();
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_solutions_directory_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'solutions_directory';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'intel_isdm_directories';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
      'main_content' => NULL,
      'filters' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = '';
  $display->uuid = '9c9ca25c-8de0-1ea4-f5a5-349637b6588b';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-da29eeaf-adf3-f3c4-e199-461563823a63';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'solutions_directory-featured_products';
    $pane->shown = FALSE;
    $pane->access = array();
    $pane->configuration = array(
      'path' => 'solutions-directory',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'da29eeaf-adf3-f3c4-e199-461563823a63';
    $display->content['new-da29eeaf-adf3-f3c4-e199-461563823a63'] = $pane;
    $display->panels['main_content'][0] = 'new-da29eeaf-adf3-f3c4-e199-461563823a63';
    $pane = new stdClass();
    $pane->pid = 'new-a2ff1f6a-8d22-9a14-3dcd-ad6862507a56';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'solutions_directory-search_results';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
              1 => 4,
              2 => 9,
              3 => 10,
              4 => 11,
              5 => 12,
              6 => 13,
              7 => 21,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => TRUE,
        ),
      ),
    );
    $pane->configuration = array(
      'path' => 'solutions-directory',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = 'a2ff1f6a-8d22-9a14-3dcd-ad6862507a56';
    $display->content['new-a2ff1f6a-8d22-9a14-3dcd-ad6862507a56'] = $pane;
    $display->panels['main_content'][1] = 'new-a2ff1f6a-8d22-9a14-3dcd-ad6862507a56';
    $pane = new stdClass();
    $pane->pid = 'new-777b3b3a-cdbb-6fa4-2130-1a7bdd478c48';
    $pane->panel = 'main_content';
    $pane->type = 'views_panes';
    $pane->subtype = 'solutions_directory-panel_pane_1';
    $pane->shown = TRUE;
    $pane->access = array(
      'plugins' => array(
        0 => array(
          'name' => 'role',
          'settings' => array(
            'rids' => array(
              0 => 3,
              1 => 4,
              2 => 9,
              3 => 10,
              4 => 11,
              5 => 12,
              6 => 13,
              7 => 21,
            ),
          ),
          'context' => 'logged-in-user',
          'not' => FALSE,
        ),
      ),
    );
    $pane->configuration = array(
      'path' => 'solutions-directory',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '777b3b3a-cdbb-6fa4-2130-1a7bdd478c48';
    $display->content['new-777b3b3a-cdbb-6fa4-2130-1a7bdd478c48'] = $pane;
    $display->panels['main_content'][2] = 'new-777b3b3a-cdbb-6fa4-2130-1a7bdd478c48';
  $display->hide_title = PANELS_TITLE_NONE;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['solutions_directory'] = $page;

  $page = new stdClass();
  $page->disabled = FALSE; /* Edit this to true to make a default page disabled initially */
  $page->api_version = 1;
  $page->name = 'web_analytics_reports';
  $page->task = 'page';
  $page->admin_title = 'Web Analytics Reports';
  $page->admin_description = '';
  $page->path = 'member-resource-center/reports/web-analytics';
  $page->access = array(
    'plugins' => array(
      0 => array(
        'name' => 'role',
        'settings' => array(
          'rids' => array(
            0 => 3,
            1 => 9,
            2 => 13,
            3 => 28,
            4 => 14,
          ),
        ),
        'context' => 'logged-in-user',
        'not' => FALSE,
      ),
    ),
    'logic' => 'and',
  );
  $page->menu = array(
    'type' => 'normal',
    'title' => 'Web Analtyics',
    'name' => 'menu-reports',
    'weight' => '0',
    'parent' => array(
      'type' => 'none',
      'title' => '',
      'name' => 'navigation',
      'weight' => '0',
    ),
  );
  $page->arguments = array();
  $page->conf = array(
    'admin_paths' => FALSE,
  );
  $page->default_handlers = array();
  $handler = new stdClass();
  $handler->disabled = FALSE; /* Edit this to true to make a default handler disabled initially */
  $handler->api_version = 1;
  $handler->name = 'page_web_analytics_reports_panel_context';
  $handler->task = 'page';
  $handler->subtask = 'web_analytics_reports';
  $handler->handler = 'panel_context';
  $handler->weight = 0;
  $handler->conf = array(
    'title' => 'Panel',
    'no_blocks' => 0,
    'pipeline' => 'standard',
    'body_classes_to_remove' => '',
    'body_classes_to_add' => '',
    'css_id' => '',
    'css' => '',
    'contexts' => array(),
    'relationships' => array(),
  );
  $display = new panels_display();
  $display->layout = 'onecol';
  $display->layout_settings = array();
  $display->panel_settings = array(
    'style_settings' => array(
      'default' => NULL,
      'middle' => NULL,
    ),
  );
  $display->cache = array();
  $display->title = 'Web Analytics';
  $display->uuid = 'b4851d9a-4f56-b294-519a-c0752ea2c87e';
  $display->content = array();
  $display->panels = array();
    $pane = new stdClass();
    $pane->pid = 'new-ecac2d95-f8a2-c9e4-890f-8c306c126459';
    $pane->panel = 'middle';
    $pane->type = 'custom';
    $pane->subtype = 'custom';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'admin_title' => '',
      'title' => '',
      'body' => '<p><em><strong><font face="Arial" size="1"><span style="font-size:12px;font-variant:normal;">Analytics available beginning June 1, 2013.</span></font></strong></em></p>',
      'format' => 'wysiwyg_basic',
      'substitute' => 1,
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 0;
    $pane->locks = array();
    $pane->uuid = 'ecac2d95-f8a2-c9e4-890f-8c306c126459';
    $display->content['new-ecac2d95-f8a2-c9e4-890f-8c306c126459'] = $pane;
    $display->panels['middle'][0] = 'new-ecac2d95-f8a2-c9e4-890f-8c306c126459';
    $pane = new stdClass();
    $pane->pid = 'new-5342cd72-45a2-b2e4-d106-7137596dbfba';
    $pane->panel = 'middle';
    $pane->type = 'block';
    $pane->subtype = 'intel_ea_module-google_analytics_filter_form';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_title' => 0,
      'override_title_text' => '',
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 1;
    $pane->locks = array();
    $pane->uuid = '5342cd72-45a2-b2e4-d106-7137596dbfba';
    $display->content['new-5342cd72-45a2-b2e4-d106-7137596dbfba'] = $pane;
    $display->panels['middle'][1] = 'new-5342cd72-45a2-b2e4-d106-7137596dbfba';
    $pane = new stdClass();
    $pane->pid = 'new-2a0cae86-19b0-d4f4-4d28-c04a54d1342f';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'google_analytics_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'member',
      'override_title' => 0,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_string_1.html_safe',
        1 => 'argument_string_2.html_safe',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 2;
    $pane->locks = array();
    $pane->uuid = '2a0cae86-19b0-d4f4-4d28-c04a54d1342f';
    $display->content['new-2a0cae86-19b0-d4f4-4d28-c04a54d1342f'] = $pane;
    $display->panels['middle'][2] = 'new-2a0cae86-19b0-d4f4-4d28-c04a54d1342f';
    $pane = new stdClass();
    $pane->pid = 'new-e8cf7cae-f9b1-5554-91ae-2cc1f926c22e';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'google_analytics_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'member_request_quote',
      'override_title' => 0,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_string_1.html_safe',
        1 => 'argument_string_2.html_safe',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 3;
    $pane->locks = array();
    $pane->uuid = 'e8cf7cae-f9b1-5554-91ae-2cc1f926c22e';
    $display->content['new-e8cf7cae-f9b1-5554-91ae-2cc1f926c22e'] = $pane;
    $display->panels['middle'][3] = 'new-e8cf7cae-f9b1-5554-91ae-2cc1f926c22e';
    $pane = new stdClass();
    $pane->pid = 'new-2c7cabd5-9aba-9fb4-8947-6c0352f14b8c';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'google_analytics_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'member_website',
      'override_title' => 0,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_string_1.html_safe',
        1 => 'argument_string_2.html_safe',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 4;
    $pane->locks = array();
    $pane->uuid = '2c7cabd5-9aba-9fb4-8947-6c0352f14b8c';
    $display->content['new-2c7cabd5-9aba-9fb4-8947-6c0352f14b8c'] = $pane;
    $display->panels['middle'][4] = 'new-2c7cabd5-9aba-9fb4-8947-6c0352f14b8c';
    $pane = new stdClass();
    $pane->pid = 'new-db2cc235-fbf1-f324-e1e5-7684cc3fc4b0';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'google_analytics_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'content',
      'override_title' => 0,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_string_1.html_safe',
        1 => 'argument_string_2.html_safe',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 5;
    $pane->locks = array();
    $pane->uuid = 'db2cc235-fbf1-f324-e1e5-7684cc3fc4b0';
    $display->content['new-db2cc235-fbf1-f324-e1e5-7684cc3fc4b0'] = $pane;
    $display->panels['middle'][5] = 'new-db2cc235-fbf1-f324-e1e5-7684cc3fc4b0';
    $pane = new stdClass();
    $pane->pid = 'new-e59e0081-1a86-dc74-31bd-aef13729d518';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'google_analytics_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'content_request_quote',
      'override_title' => 0,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_string_1.html_safe',
        1 => 'argument_string_2.html_safe',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 6;
    $pane->locks = array();
    $pane->uuid = 'e59e0081-1a86-dc74-31bd-aef13729d518';
    $display->content['new-e59e0081-1a86-dc74-31bd-aef13729d518'] = $pane;
    $display->panels['middle'][6] = 'new-e59e0081-1a86-dc74-31bd-aef13729d518';
    $pane = new stdClass();
    $pane->pid = 'new-b5d37539-47f6-df04-fdc0-80a39023e358';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'google_analytics_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'content_contact_intel',
      'override_title' => 0,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_string_1.html_safe',
        1 => 'argument_string_2.html_safe',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 7;
    $pane->locks = array();
    $pane->uuid = 'b5d37539-47f6-df04-fdc0-80a39023e358';
    $display->content['new-b5d37539-47f6-df04-fdc0-80a39023e358'] = $pane;
    $display->panels['middle'][7] = 'new-b5d37539-47f6-df04-fdc0-80a39023e358';
    $pane = new stdClass();
    $pane->pid = 'new-f46d36f9-b668-c304-11bf-c963a73a3a8b';
    $pane->panel = 'middle';
    $pane->type = 'views';
    $pane->subtype = 'google_analytics_reports';
    $pane->shown = TRUE;
    $pane->access = array();
    $pane->configuration = array(
      'override_pager_settings' => 0,
      'use_pager' => 0,
      'nodes_per_page' => '0',
      'pager_id' => '0',
      'offset' => '0',
      'more_link' => 0,
      'feed_icons' => 0,
      'panel_args' => 0,
      'link_to_view' => 0,
      'args' => '',
      'url' => '',
      'display' => 'content_datasheet',
      'override_title' => 0,
      'override_title_text' => '',
      'context' => array(
        0 => 'argument_string_1.html_safe',
        1 => 'argument_string_2.html_safe',
      ),
    );
    $pane->cache = array();
    $pane->style = array(
      'settings' => NULL,
    );
    $pane->css = array();
    $pane->extras = array();
    $pane->position = 8;
    $pane->locks = array();
    $pane->uuid = 'f46d36f9-b668-c304-11bf-c963a73a3a8b';
    $display->content['new-f46d36f9-b668-c304-11bf-c963a73a3a8b'] = $pane;
    $display->panels['middle'][8] = 'new-f46d36f9-b668-c304-11bf-c963a73a3a8b';
  $display->hide_title = PANELS_TITLE_FIXED;
  $display->title_pane = '0';
  $handler->conf['display'] = $display;
  $page->default_handlers[$handler->name] = $handler;
  $pages['web_analytics_reports'] = $page;

  return $pages;

}
