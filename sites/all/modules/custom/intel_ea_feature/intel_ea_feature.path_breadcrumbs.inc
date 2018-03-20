<?php
/**
 * @file
 * intel_ea_feature.path_breadcrumbs.inc
 */

/**
 * Implements hook_path_breadcrumbs_settings_info().
 */
function intel_ea_feature_path_breadcrumbs_settings_info() {
  $export = array();

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'alliance_member_company_representative_signup';
  $path_breadcrumb->name = 'Alliance Member Company Representative Signup';
  $path_breadcrumb->path = 'user/register';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Alliance Member Login',
      1 => 'Company Representative Signup',
    ),
    'paths' => array(
      0 => 'user',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['alliance_member_company_representative_signup'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'alliance_member_login';
  $path_breadcrumb->name = 'Alliance Member Login';
  $path_breadcrumb->path = 'user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Alliance Member Login',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['alliance_member_login'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'alliance_member_login_login';
  $path_breadcrumb->name = 'Alliance Member Login';
  $path_breadcrumb->path = 'user/login';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Alliance Member Login',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['alliance_member_login_login'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'alliance_member_request_new_password';
  $path_breadcrumb->name = 'Alliance Member Request New Password';
  $path_breadcrumb->path = 'user/password';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Alliance Member Login',
      1 => 'Request New Password',
    ),
    'paths' => array(
      0 => 'user',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['alliance_member_request_new_password'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'alliance_training_center';
  $path_breadcrumb->name = 'Alliance Training Center';
  $path_breadcrumb->path = 'training-center';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Alliance Training Center',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'training-center',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['alliance_training_center'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'co_marketing_tool';
  $path_breadcrumb->name = 'Co-Marketing Tool';
  $path_breadcrumb->path = 'co-marketing-tool';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Co-Marketing Center',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'co-marketing-tool',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['co_marketing_tool'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'co_marketing_tool_sub_pages';
  $path_breadcrumb->name = 'Co-Marketing Tool Sub-pages';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Co-Marketing Center',
      1 => '%node:title',
    ),
    'paths' => array(
      0 => 'co-marketing-tool',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'co-marketing-tool/*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'page' => 'page',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['co_marketing_tool_sub_pages'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'company';
  $path_breadcrumb->name = 'Company';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Member Roster',
      1 => 'Member Details',
    ),
    'paths' => array(
      0 => 'member-roster',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'company' => 'company',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['company'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'content_add';
  $path_breadcrumb->name = 'Content: Add';
  $path_breadcrumb->path = 'node/add/%type';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'type' => array(
        'position' => 2,
        'argument' => 'node_add',
        'settings' => array(
          'identifier' => 'Node add form: node type',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['content_add'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'content_edit';
  $path_breadcrumb->name = 'Content: Edit';
  $path_breadcrumb->path = 'node/%node/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Edit %node:type: %node:title',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['content_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'content_revisions';
  $path_breadcrumb->name = 'Content: Revisions';
  $path_breadcrumb->path = 'node/%node/revisions';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => '%node:type Revisions: %node:title',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['content_revisions'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'content_view_member_resource_center';
  $path_breadcrumb->name = 'Content: View (Member Resource Center)';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
    ),
    'paths' => array(
      0 => 'member-resource-center',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'member-resource-center*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['content_view_member_resource_center'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'content_view_revision';
  $path_breadcrumb->name = 'Content: View Revision';
  $path_breadcrumb->path = 'node/%node/revisions/%vid/view';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => '%node:title: Revision !vid',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
      'vid' => array(
        'position' => 3,
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['content_view_revision'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'general_membership_application';
  $path_breadcrumb->name = 'General Membership Application';
  $path_breadcrumb->path = 'eform/submit/general-membership-application';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'General Membership Application',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'general-membership-application',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['general_membership_application'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'general_membership_confirmation';
  $path_breadcrumb->name = 'General Membership Confirmation';
  $path_breadcrumb->path = 'eform/general-membership-application/confirm';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Thank You',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'eform/general-membership-application/confirm*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['general_membership_confirmation'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'general_membership_edit';
  $path_breadcrumb->name = 'General Membership: Edit';
  $path_breadcrumb->path = 'entityform/%entityform/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Manage Applications',
      2 => 'Edit Application: %entityform:field-gma-company-name',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => 'admin/structure/entityform_types/manage/general_membership_application/submissions',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'entityform' => array(
        'position' => 1,
        'argument' => 'entity_id:entityform',
        'settings' => array(
          'identifier' => 'Entityform: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:entityform',
          'settings' => array(
            'type' => array(
              'general_membership_application' => 'general_membership_application',
            ),
          ),
          'context' => 'entityform',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['general_membership_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'general_membership_view';
  $path_breadcrumb->name = 'General Membership: View';
  $path_breadcrumb->path = 'entityform/%entityform';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Manage Applications',
      2 => 'View Application: %entityform:field-gma-company-name',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => 'admin/structure/entityform_types/manage/general_membership_application/submissions',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'entityform' => array(
        'position' => 1,
        'argument' => 'entity_id:entityform',
        'settings' => array(
          'identifier' => 'Entityform: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:entityform',
          'settings' => array(
            'type' => array(
              'general_membership_application' => 'general_membership_application',
            ),
          ),
          'context' => 'entityform',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['general_membership_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'marketplace_newsletter_archive';
  $path_breadcrumb->name = 'Marketplace Newsletter Archive';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Solutions Directory',
      1 => 'Marketplace Newsletter Archive',
    ),
    'paths' => array(
      0 => '<front>',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'solutions-directory/newsletter-archive',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['marketplace_newsletter_archive'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'member_resource_center';
  $path_breadcrumb->name = 'Member Resource Center';
  $path_breadcrumb->path = 'member-resource-center';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['member_resource_center'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'member_resource_center_1';
  $path_breadcrumb->name = 'Member Resource Center 1';
  $path_breadcrumb->path = 'member-resource-center/*';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['member_resource_center_1'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'member_resource_center_2';
  $path_breadcrumb->name = 'Member Resource Center 2';
  $path_breadcrumb->path = 'member-resource-center/*/*';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['member_resource_center_2'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'member_resource_center_3';
  $path_breadcrumb->name = 'Member Resource Center 3';
  $path_breadcrumb->path = 'member-resource-center/*/*/*';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => '!page_title',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['member_resource_center_3'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'member_roster';
  $path_breadcrumb->name = 'Member Roster';
  $path_breadcrumb->path = 'member-roster';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Member Roster',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'member-roster',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['member_roster'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'membership_renewal_application';
  $path_breadcrumb->name = 'Membership Renewal Application';
  $path_breadcrumb->path = 'eform/submit/membership-renewal-application';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Membership Renewal',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'member-resource-center/membership-renewal-application',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['membership_renewal_application'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'membership_renewal_confirmation';
  $path_breadcrumb->name = 'Membership Renewal Confirmation';
  $path_breadcrumb->path = 'eform/membership-renewal-application/confirm';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Membership Renewal Confirmation',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => NULL,
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'eform/membership-renewal-application/confirm*',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['membership_renewal_confirmation'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'membership_renewal_edit';
  $path_breadcrumb->name = 'Membership Renewal: Edit';
  $path_breadcrumb->path = 'entityform/%entityform/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Manage Renewals',
      2 => 'Edit Renewal: %entityform:field-mra-company-name',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => 'admin/structure/entityform_types/manage/membership_renewal_application/submissions',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'entityform' => array(
        'position' => 1,
        'argument' => 'entity_id:entityform',
        'settings' => array(
          'identifier' => 'Entityform: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:entityform',
          'settings' => array(
            'type' => array(
              'membership_renewal_application' => 'membership_renewal_application',
            ),
          ),
          'context' => 'entityform',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['membership_renewal_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'membership_renewal_view';
  $path_breadcrumb->name = 'Membership Renewal: View';
  $path_breadcrumb->path = 'entityform/%entityform';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Manage Renewals',
      2 => 'View Renewal: %entityform:field-mra-company-name',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => 'admin/structure/entityform_types/manage/membership_renewal_application/submissions',
      2 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'entityform' => array(
        'position' => 1,
        'argument' => 'entity_id:entityform',
        'settings' => array(
          'identifier' => 'Entityform: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:entityform',
          'settings' => array(
            'type' => array(
              'membership_renewal_application' => 'membership_renewal_application',
            ),
          ),
          'context' => 'entityform',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['membership_renewal_view'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'opportunity';
  $path_breadcrumb->name = 'Opportunity';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Co-Marketing Center',
      1 => 'Market Development Fund',
    ),
    'paths' => array(
      0 => 'co-marketing-tool',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'opportunity' => 'opportunity',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['opportunity'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'opportunity_group';
  $path_breadcrumb->name = 'Opportunity Group';
  $path_breadcrumb->path = 'taxonomy/term/%term';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Co-Marketing Center',
      1 => '%term:i18n-name',
    ),
    'paths' => array(
      0 => 'co-marketing-tool',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'term' => array(
        'position' => 2,
        'argument' => 'term',
        'settings' => array(
          'identifier' => 'Taxonomy term: ID',
          'input_form' => 'tid',
          'vids' => array(
            31 => '31',
            4 => 0,
            14 => 0,
            1 => 0,
            2 => 0,
            29 => 0,
            23 => 0,
            3 => 0,
            27 => 0,
            30 => 0,
            5 => 0,
            15 => 0,
            22 => 0,
            6 => 0,
            24 => 0,
            25 => 0,
            7 => 0,
            8 => 0,
            9 => 0,
            26 => 0,
            21 => 0,
            10 => 0,
            17 => 0,
            11 => 0,
            12 => 0,
            28 => 0,
            13 => 0,
            18 => 0,
            19 => 0,
            20 => 0,
          ),
          'breadcrumb' => 0,
          'transform' => 1,
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'term_vocabulary',
          'settings' => array(
            'vids' => array(
              31 => '31',
            ),
          ),
          'context' => 'term',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['opportunity_group'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'section_and_sub_section';
  $path_breadcrumb->name = 'Training Section and Sub-Section';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Alliance Training Center',
    ),
    'paths' => array(
      0 => 'training-center',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'training_section' => 'training_section',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'node_type',
          'settings' => array(
            'type' => array(
              'training_sub_section' => 'training_sub_section',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['section_and_sub_section'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'solution';
  $path_breadcrumb->name = 'Solution';
  $path_breadcrumb->path = 'node/%node';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Solutions Directory',
      1 => 'Product Details',
    ),
    'paths' => array(
      0 => 'solutions-directory',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'node' => array(
        'position' => 1,
        'argument' => 'entity_id:node',
        'settings' => array(
          'identifier' => 'Content: ID',
        ),
      ),
    ),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'solution' => 'solution',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
        1 => array(
          'name' => 'entity_bundle:node',
          'settings' => array(
            'type' => array(
              'formula' => 'formula',
            ),
          ),
          'context' => 'node',
          'not' => FALSE,
        ),
      ),
      'logic' => 'or',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['solution'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'solutions_directory';
  $path_breadcrumb->name = 'Solutions Directory';
  $path_breadcrumb->path = 'solutions-directory';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => '<none>',
    ),
    'paths' => array(
      0 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(),
    'access' => array(
      'plugins' => array(
        0 => array(
          'name' => 'path_visibility',
          'settings' => array(
            'visibility_setting' => '1',
            'paths' => 'solutions-directory',
          ),
          'context' => 'empty',
          'not' => FALSE,
        ),
      ),
      'logic' => 'and',
    ),
  );
  $path_breadcrumb->weight = 0;
  $export['solutions_directory'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_edit';
  $path_breadcrumb->name = 'User: Edit';
  $path_breadcrumb->path = 'user/%user/edit';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'Edit User: %user:field-first-name %user:field-last-name',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['user_edit'] = $path_breadcrumb;

  $path_breadcrumb = new stdClass();
  $path_breadcrumb->api_version = 1;
  $path_breadcrumb->machine_name = 'user_view';
  $path_breadcrumb->name = 'User: View';
  $path_breadcrumb->path = 'user/%user';
  $path_breadcrumb->data = array(
    'titles' => array(
      0 => 'Members Resource Center',
      1 => 'View User: %user:field-first-name %user:field-last-name',
    ),
    'paths' => array(
      0 => 'member-resource-center',
      1 => '<none>',
    ),
    'home' => 0,
    'translatable' => 1,
    'arguments' => array(
      'user' => array(
        'position' => 1,
        'argument' => 'entity_id:user',
        'settings' => array(
          'identifier' => 'User: ID',
        ),
      ),
    ),
    'access' => array(),
  );
  $path_breadcrumb->weight = 0;
  $export['user_view'] = $path_breadcrumb;

  return $export;
}
