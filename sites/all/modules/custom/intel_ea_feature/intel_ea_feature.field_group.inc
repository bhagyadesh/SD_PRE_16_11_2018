<?php
/**
 * @file
 * intel_ea_feature.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function intel_ea_feature_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account|user|user|default';
  $field_group->group_name = 'group_account';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_company',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Account Information',
      'instance_settings' => array(
        'classes' => ' group-account field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'user_user_full_group_account',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_account|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_account|user|user|form';
  $field_group->group_name = 'group_account';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Account Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_company',
      1 => 'account',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Account Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-account field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_account|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|node|company|form';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mailing Address',
    'weight' => '1',
    'children' => array(
      0 => 'field_address',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-address field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_address|node|company|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|user|user|default';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mailing Address',
    'weight' => '3',
    'children' => array(
      0 => 'field_address',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Mailing Address',
      'instance_settings' => array(
        'classes' => ' group-address field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'user_user_full_group_address',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_address|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_address|user|user|form';
  $field_group->group_name = 'group_address';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Mailing Address',
    'weight' => '3',
    'children' => array(
      0 => 'field_address',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-address field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_address|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_calendar_items|node|opportunity|form';
  $field_group->group_name = 'group_calendar_items';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opportunity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opportunity Calendar Items',
    'weight' => '3',
    'children' => array(
      0 => 'field_opportunity_calendar_item',
      1 => 'field_opportunity_calendar_link',
      2 => 'field_opportunity_calendar_text',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-calendar-items field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_calendar_items|node|opportunity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|component|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '2',
    'children' => array(
      0 => 'field_categories',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-categories field-group-tab ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_categories|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|formula|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formula';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '3',
    'children' => array(
      0 => 'field_categories',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-categories field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_categories|node|formula|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_categories|node|solution|form';
  $field_group->group_name = 'group_categories';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Categories',
    'weight' => '3',
    'children' => array(
      0 => 'field_categories',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Categories',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-categories field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_categories|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_characteristics|node|component|form';
  $field_group->group_name = 'group_characteristics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Characteristics',
    'weight' => '3',
    'children' => array(
      0 => 'field_application',
      1 => 'field_chipsets',
      2 => 'field_ethernet_controllers',
      3 => 'field_geographic_location',
      4 => 'field_intel_technologies',
      5 => 'field_intel_wireless',
      6 => 'field_market_segments',
      7 => 'field_power',
      8 => 'field_software_solutions',
      9 => 'group_display',
      10 => 'group_memory',
      11 => 'group_processors',
      12 => 'group_standards_supported',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-characteristics field-group-tab ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_characteristics|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_characteristics|node|solution|form';
  $field_group->group_name = 'group_characteristics';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Characteristics',
    'weight' => '4',
    'children' => array(
      0 => 'field_chipsets',
      1 => 'field_application',
      2 => 'field_ethernet_controllers',
      3 => 'field_geographic_location',
      4 => 'field_intel_technologies',
      5 => 'field_intel_wireless',
      6 => 'field_market_segments',
      7 => 'field_power',
      8 => 'field_software_solutions',
      9 => 'group_display',
      10 => 'group_memory',
      11 => 'group_processors',
      12 => 'group_stds',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-characteristics field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_characteristics|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_company|node|company|form';
  $field_group->group_name = 'group_company';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Company Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_website',
      2 => 'field_acceptable_domains',
      3 => 'field_geographic_coverage',
      4 => 'field_company_type',
      5 => 'field_geographic_region',
      6 => 'field_logo',
      7 => 'field_cnda',
      8 => 'field_end_user_description',
      9 => 'language',
      10 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Company Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => ' group-company field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_company|node|company|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_component_group|field_collection_item|field_component_group|form';
  $field_group->group_name = 'group_component_group';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_component_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Component Group',
    'weight' => '0',
    'children' => array(
      0 => 'field_component_type',
      1 => 'group_component_options',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Component Group',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-component-group field-group-div ',
        'description' => 'If you would like to include a component not posted to the Solutions Directory, please contact Alliance Administration <a href="mailto:intel.communications.alliance.admin@intel.com">intel.communications.alliance.admin@intel.com</a> with the component name, company, product URL, and Component Type Category for placement.',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'field_collection_item_field_component_group_form_group_component_group',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_component_group|field_collection_item|field_component_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_component_information|node|component|form';
  $field_group->group_name = 'group_component_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Component Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_component_company_name',
      1 => 'field_component_webpage',
      2 => 'field_image',
      3 => 'language',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-component-information field-group-tab ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_component_information|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_component_options|field_collection_item|field_component_group|form';
  $field_group->group_name = 'group_component_options';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_component_group';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_component_group';
  $field_group->data = array(
    'label' => 'Component Options',
    'weight' => '2',
    'children' => array(
      0 => 'field_component_options',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Component Options',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-component-options field-group-div ',
        'description' => 'To add an Alliance Member Solution as a component to this formula, please begin to type the solution name and then select from the list of available options presented.',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'field_collection_item_field_component_group_form_group_component_options',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_component_options|field_collection_item|field_component_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|user|user|default';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_work_phone',
      1 => 'field_fax_phone',
      2 => 'field_mobile_phone',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'classes' => ' group-contact field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'user_user_full_group_contact',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact|user|user|form';
  $field_group->group_name = 'group_contact';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '2',
    'children' => array(
      0 => 'field_work_phone',
      1 => 'field_fax_phone',
      2 => 'field_mobile_phone',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-contact field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_contact|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_date_action|node|opportunity|form';
  $field_group->group_name = 'group_date_action';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opportunity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opportunity Date & Action',
    'weight' => '2',
    'children' => array(
      0 => 'field_call_to_action',
      1 => 'field_expiration_date',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-date-action field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_date_action|node|opportunity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_display|node|component|form';
  $field_group->group_name = 'group_display';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_characteristics';
  $field_group->data = array(
    'label' => 'Display',
    'weight' => '4',
    'children' => array(
      0 => 'field_display_hdmi',
      1 => 'field_display_independent',
      2 => 'field_display_lvds',
      3 => 'field_display_other',
      4 => 'field_display_pcie_x16',
      5 => 'field_display_port_edp',
      6 => 'field_display_size',
      7 => 'field_display_total',
      8 => 'field_display_vga',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-display field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_display|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_display|node|solution|form';
  $field_group->group_name = 'group_display';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_characteristics';
  $field_group->data = array(
    'label' => 'Display',
    'weight' => '7',
    'children' => array(
      0 => 'field_display_independent',
      1 => 'field_display_port_edp',
      2 => 'field_display_hdmi',
      3 => 'field_display_lvds',
      4 => 'field_display_other',
      5 => 'field_display_vga',
      6 => 'field_display_total',
      7 => 'field_display_size',
      8 => 'field_display_pcie_x16',
      9 => 'field_display_technology',
      10 => 'field_number_of_dvi_ports',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Display',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-display field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_display|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_field_sales_manager|entityform|order_free_intel_iotg_gateway|form';
  $field_group->group_name = 'group_field_sales_manager';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'order_free_intel_iotg_gateway';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Field Sales Manager Contact Info',
    'weight' => '6',
    'children' => array(
      0 => 'field_field_sales_manager_addres',
      1 => 'field_field_sales_manager_email',
      2 => 'field_field_sales_manager_name',
      3 => 'field_field_sales_manager_phone_',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Field Sales Manager Contact Info',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-field-sales-manager field-group-fieldset',
        'description' => 'Please provide the contact information for gateway shipment.  Include:  Name / Title, Address, Phone Number, and Email Address.',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_field_sales_manager|entityform|order_free_intel_iotg_gateway|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_formula_details|node|formula|form';
  $field_group->group_name = 'group_formula_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formula';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Formula Details',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_bill_of_materials',
      2 => 'field_formula_resources',
      3 => 'field_geographic_location',
      4 => 'field_image',
      5 => 'field_market_segments',
      6 => 'field_system_integrators',
      7 => 'field_end_user_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-formula-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_formula_details|node|formula|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_formula_information|node|formula|form';
  $field_group->group_name = 'group_formula_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'formula';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Formula Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_company',
      1 => 'field_component_group',
      2 => 'field_pre_release',
      3 => 'field_end_user_display',
      4 => 'language',
      5 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Formula Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-formula-information field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_formula_information|node|formula|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_account|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_account';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_primary_contact';
  $field_group->data = array(
    'label' => 'Account Information',
    'weight' => '35',
    'children' => array(
      0 => 'field_gma_email_address',
      1 => 'field_gma_username',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Account Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-account',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_account|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_address|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_address';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_company';
  $field_group->data = array(
    'label' => 'Mailing Address',
    'weight' => '41',
    'children' => array(
      0 => 'field_gma_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mailing Address',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-address',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_address|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_company_type|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_company_type';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_profile';
  $field_group->data = array(
    'label' => 'Company Type',
    'weight' => '43',
    'children' => array(
      0 => 'field_gma_company_type',
      1 => 'field_gma_company_type_unlimited',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Company Type',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-company-type',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_company_type|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_company|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_company';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_form';
  $field_group->data = array(
    'label' => 'Company Information',
    'weight' => '3',
    'children' => array(
      0 => 'group_gma_address',
      1 => 'group_gma_general',
      2 => 'group_gma_geographic',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Company Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-gma-company field-group-multipage',
        'description' => '',
      ),
      'formatter' => 'no-start',
    ),
  );
  $export['group_gma_company|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_confirm_accept|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_confirm_accept';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_legal';
  $field_group->data = array(
    'label' => 'Confirm Acceptance of Terms and Conditions',
    'weight' => '60',
    'children' => array(
      0 => 'field_gma_terms_conditions',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Confirm Acceptance of Terms and Conditions',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-gma-confirm-accept field-group-div ',
        'description' => '<p>BY CLICKING ON "CONFIRM ACCEPTANCE" BELOW, YOU:</p>
<ol>
<li>CONFIRM THAT YOU HAVE READ THE TERMS AND CONDITIONS AS SHOWN BELOW; AND</li>
<li>REPRESENT AND WARRANT THAT YOU ARE AN AGENT OR EMPLOYEE OF A LEGAL ENTITY, YOU ARE ACCEPTING THESE TERMS AND CONDITIONS ON THAT ENTITY\'S BEHALF, AND THAT YOU HAVE THE AUTHORITY TO BIND SUCH LEGAL ENTITY TO THESE TERMS AND CONDITIONS.</li>
</ol>',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'entityform_general_membership_application_form_group_gma_confirm_accept',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_confirm_accept|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_contact|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_contact';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_primary_contact';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '37',
    'children' => array(
      0 => 'field_gma_work_phone',
      1 => 'field_gma_fax_phone',
      2 => 'field_gma_mobile_phone',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-contact',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_contact|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_finish|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_finish';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_form';
  $field_group->data = array(
    'label' => 'Finish',
    'weight' => '6',
    'children' => array(
      0 => 'group_gma_legal',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-gma-finish field-group-multipage',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_gma_finish|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_form|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_form';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'General Membership Application',
    'weight' => '0',
    'children' => array(
      0 => 'group_gma_company',
      1 => 'group_gma_finish',
      2 => 'group_gma_primary_contact',
      3 => 'group_gma_profile',
    ),
    'format_type' => 'multipage-group',
    'format_settings' => array(
      'label' => 'General Membership Application',
      'instance_settings' => array(
        'classes' => ' group-gma-form field-group-multipage-group',
        'page_header' => '1',
        'page_counter' => '1',
        'move_button' => '1',
        'move_additional' => '1',
      ),
    ),
  );
  $export['group_gma_form|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_general|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_general';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_company';
  $field_group->data = array(
    'label' => 'General Information',
    'weight' => '36',
    'children' => array(
      0 => 'field_gma_company_name',
      1 => 'field_gma_company_description',
      2 => 'field_gma_website',
      3 => 'field_gma_acceptable_domains',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'General Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-general',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_general|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_geographic|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_geographic';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_company';
  $field_group->data = array(
    'label' => 'Geographic Information',
    'weight' => '42',
    'children' => array(
      0 => 'field_gma_geographic_region',
      1 => 'field_gma_geographic_coverage',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Geographic Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-geographic',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_geographic|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_legal|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_legal';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_finish';
  $field_group->data = array(
    'label' => 'Terms and Conditions',
    'weight' => '52',
    'children' => array(
      0 => 'field_gma_authorized',
      1 => 'group_gma_confirm_accept',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Terms and Conditions',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-legal',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_legal|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_personal|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_personal';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_primary_contact';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '36',
    'children' => array(
      0 => 'field_gma_salutation',
      1 => 'field_gma_first_name',
      2 => 'field_gma_last_name',
      3 => 'field_gma_title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Personal Information',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-personal',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_personal|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_preferences|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_preferences';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_primary_contact';
  $field_group->data = array(
    'label' => 'Preferences',
    'weight' => '39',
    'children' => array(
      0 => 'field_gma_receive_members_email',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Preferences',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-preferences',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_preferences|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_primary_contact|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_primary_contact';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_form';
  $field_group->data = array(
    'label' => 'Primary Contact Information',
    'weight' => '2',
    'children' => array(
      0 => 'group_gma_account',
      1 => 'group_gma_contact',
      2 => 'group_gma_personal',
      3 => 'group_gma_preferences',
      4 => 'group_gma_user_address',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'label' => 'Primary Contact Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-gma-primary-contact field-group-multipage',
        'description' => '',
      ),
      'formatter' => 'start',
    ),
  );
  $export['group_gma_primary_contact|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_products|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_products';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_profile';
  $field_group->data = array(
    'label' => 'Products and Services',
    'weight' => '45',
    'children' => array(
      0 => 'field_gma_product_market',
      1 => 'field_gma_num_products',
      2 => 'field_gma_product_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Products and Services',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-products',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_products|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_profile|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_profile';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_form';
  $field_group->data = array(
    'label' => 'Company Profile',
    'weight' => '4',
    'children' => array(
      0 => 'field_gma_value_prop',
      1 => 'group_gma_company_type',
      2 => 'group_gma_products',
      3 => 'group_gma_referral',
    ),
    'format_type' => 'multipage',
    'format_settings' => array(
      'formatter' => 'no-start',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-gma-profile field-group-multipage',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_gma_profile|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_referral|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_referral';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_profile';
  $field_group->data = array(
    'label' => 'Referral Source',
    'weight' => '44',
    'children' => array(
      0 => 'field_gma_acct_rel_mgr',
      1 => 'field_gma_referral_source',
      2 => 'field_gma_other',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Referral Source',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-referral',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_referral|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_gma_user_address|entityform|general_membership_application|form';
  $field_group->group_name = 'group_gma_user_address';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'general_membership_application';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_gma_primary_contact';
  $field_group->data = array(
    'label' => 'Mailing Address',
    'weight' => '38',
    'children' => array(
      0 => 'field_gma_user_address',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Mailing Address',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'field-group-fieldset group-gma-user-address',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_gma_user_address|entityform|general_membership_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_images|taxonomy_term|opportunity_group|form';
  $field_group->group_name = 'group_images';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'opportunity_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opportunity Group Images',
    'weight' => '1',
    'children' => array(
      0 => 'field_image_unlimited',
      1 => 'field_image_unlimited_view',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-images field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_images|taxonomy_term|opportunity_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_legal|entityform|membership_renewal_application|form';
  $field_group->group_name = 'group_legal';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'membership_renewal_application';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Terms and Conditions',
    'weight' => '2',
    'children' => array(
      0 => 'field_mra_acknowledge_accept',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Terms and Conditions',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-legal field-group-div',
        'description' => '<p>DO NOT CLICK "ACKNOWLEDGE AND ACCEPT" BELOW UNTIL YOU HAVE CAREFULLY READ THE FOLLOWING INTEL® INTERNET OF THINGS SOLUTIONS ALLIANCE AGREEMENT (THE "AGREEMENT").</p>
<p>BY CLICKING ON "ACKNOWLEDGE AND ACCEPT" BELOW, YOU:
<ol>
<li>ACKNOWLEDGE THAT YOU HAVE READ THE AGREEMENT CONSISTING OF THE (3) DOCUMENTS AS SHOWN BELOW;</li>
<li>REPRESENT AND WARRANT THAT YOU ARE AN AGENT OR EMPLOYEE OF A LEGAL ENTITY, YOU ARE ACCEPTING THIS AGREEMENT ON THAT ENTITY\'S BEHALF, AND THAT YOU HAVE THE AUTHORITY TO BIND SUCH LEGAL ENTITY TO THIS AGREEMENT; AND</li>
<li>AGREE TO REPLACE THE PREVIOUS AGREEMENT WITH THE AGREEMENT AS SET FORTH BELOW.</li>
</ol>
</p>',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'entityform_membership_renewal_application_form_group_legal',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_legal|entityform|membership_renewal_application|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_locale|user|user|form';
  $field_group->group_name = 'group_locale';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Locale Settings',
    'weight' => '6',
    'children' => array(
      0 => 'timezone',
      1 => 'locale',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Locale Settings',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-locale field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_locale|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_membership|node|company|form';
  $field_group->group_name = 'group_membership';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'company';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Membership Information',
    'weight' => '3',
    'children' => array(
      0 => 'field_membership_type',
      1 => 'field_sponsoring_business_units',
      2 => 'field_renewal_signee',
      3 => 'field_agreement_identifier',
      4 => 'field_agreed',
      5 => 'field_agreement_date',
      6 => 'field_community_tag',
      7 => 'field_embedded_processor_support',
      8 => 'field_future_membership',
      9 => 'field_account_managers',
      10 => 'field_applications_engineers',
      11 => 'field_sales_engineers',
      12 => 'field_solutions_directiory_id',
      13 => 'field_future_agreement_date',
      14 => 'field_future_membership_type',
      15 => 'field_acceptance_date',
      16 => 'field_marketing_expert',
      17 => 'field_programs',
      18 => 'field_new_itp_company',
      19 => 'field_membership_tier',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-membership field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_membership|node|company|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_memory|node|component|form';
  $field_group->group_name = 'group_memory';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_characteristics';
  $field_group->data = array(
    'label' => 'Memory',
    'weight' => '11',
    'children' => array(
      0 => 'field_memory_ecc',
      1 => 'field_memory_max',
      2 => 'field_memory_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-memory field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_memory|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_memory|node|solution|form';
  $field_group->group_name = 'group_memory';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_characteristics';
  $field_group->data = array(
    'label' => 'Memory',
    'weight' => '14',
    'children' => array(
      0 => 'field_memory_ecc',
      1 => 'field_memory_max',
      2 => 'field_memory_type',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Memory',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-memory field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_memory|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notification_audience|node|notification|form';
  $field_group->group_name = 'group_notification_audience';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'notification';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notification Audience',
    'weight' => '4',
    'children' => array(
      0 => 'field_membership_type_unlimited',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-notification-audience field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_notification_audience|node|notification|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_notification|node|notification|form';
  $field_group->group_name = 'group_notification';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'notification';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Notification Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_date_range',
      2 => 'field_notification_link',
      3 => 'language',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-notification field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_notification|node|notification|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opportunities|taxonomy_term|opportunity_group|form';
  $field_group->group_name = 'group_opportunities';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'opportunity_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opportunities',
    'weight' => '2',
    'children' => array(
      0 => 'field_opportunities',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Opportunities',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-opportunities field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_opportunities|taxonomy_term|opportunity_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opportunity_group|taxonomy_term|opportunity_group|form';
  $field_group->group_name = 'group_opportunity_group';
  $field_group->entity_type = 'taxonomy_term';
  $field_group->bundle = 'opportunity_group';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opportunity Group Information',
    'weight' => '0',
    'children' => array(
      0 => 'name',
      1 => 'description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-opportunity-group field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_opportunity_group|taxonomy_term|opportunity_group|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_opportunity|node|opportunity|form';
  $field_group->group_name = 'group_opportunity';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opportunity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opportunity Information',
    'weight' => '0',
    'children' => array(
      0 => 'body',
      1 => 'field_opportunity_group',
      2 => 'language',
      3 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-opportunity field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_opportunity|node|opportunity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal|user|user|default';
  $field_group->group_name = 'group_personal';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_salutation',
      1 => 'field_first_name',
      2 => 'field_last_name',
      3 => 'field_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Personal Information',
      'instance_settings' => array(
        'classes' => ' group-personal field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'user_user_full_group_personal',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_personal|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_personal|user|user|form';
  $field_group->group_name = 'group_personal';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Personal Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_salutation',
      1 => 'field_first_name',
      2 => 'field_last_name',
      3 => 'field_title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-personal field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_personal|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preferences|user|user|default';
  $field_group->group_name = 'group_preferences';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preferences',
    'weight' => '4',
    'children' => array(
      0 => 'field_receive_members_email',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Preferences',
      'instance_settings' => array(
        'classes' => ' group-preferences field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'user_user_full_group_preferences',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_preferences|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_preferences|user|user|form';
  $field_group->group_name = 'group_preferences';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Preferences',
    'weight' => '4',
    'children' => array(
      0 => 'field_receive_members_email',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-preferences field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_preferences|user|user|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_price|node|solution|form';
  $field_group->group_name = 'group_price';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_solution_details';
  $field_group->data = array(
    'label' => 'Price',
    'weight' => '10',
    'children' => array(
      0 => 'field_price_per_unit',
      1 => 'field_price_per_100_units',
      2 => 'field_price_per_1000_units',
      3 => 'field_order_button_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Price',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-price field-group-fieldset',
        'description' => 'Only specified prices will be displayed. If no prices are specified, a "Contact for pricing" message will be displayed instead.',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_price|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_processors|node|component|form';
  $field_group->group_name = 'group_processors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_characteristics';
  $field_group->data = array(
    'label' => 'Processors',
    'weight' => '13',
    'children' => array(
      0 => 'field_processors_count',
      1 => 'field_processors_list',
      2 => 'field_stds_processor_socketed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-processors field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_processors|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_processors|node|solution|form';
  $field_group->group_name = 'group_processors';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_characteristics';
  $field_group->data = array(
    'label' => 'Processors',
    'weight' => '16',
    'children' => array(
      0 => 'field_processors_count',
      1 => 'field_processors_list',
      2 => 'field_stds_processor_socketed',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Processors',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-processors field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_processors|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_resources|node|opportunity|form';
  $field_group->group_name = 'group_resources';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'opportunity';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Opportunity Resources',
    'weight' => '1',
    'children' => array(
      0 => 'field_opportunity_resource',
      1 => 'field_opportunity_resource_view',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-resources field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_resources|node|opportunity|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_content|node|training_section|form';
  $field_group->group_name = 'group_section_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section Content',
    'weight' => '2',
    'children' => array(
      0 => 'field_content_pdf',
      1 => 'field_content_blocks',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Section Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-section-content field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_section_content|node|training_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_information|node|training_section|form';
  $field_group->group_name = 'group_section_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_icon',
      1 => 'field_sub_title',
      2 => 'field_ajax_section',
      3 => 'field_section_order',
      4 => 'language',
      5 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Section Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-section-information field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_section_information|node|training_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_introduction|node|training_section|form';
  $field_group->group_name = 'group_section_introduction';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section Introduction',
    'weight' => '1',
    'children' => array(
      0 => 'field_persistent_introduction',
      1 => 'field_video',
      2 => 'field_introduction_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Section Introduction',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-section-introduction field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_section_introduction|node|training_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_section_modals|node|training_section|form';
  $field_group->group_name = 'group_section_modals';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Section Modals',
    'weight' => '3',
    'children' => array(
      0 => 'field_modal',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Section Modals',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-section-modals field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_section_modals|node|training_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_shipping_contact_info|entityform|order_free_intel_iotg_gateway|form';
  $field_group->group_name = 'group_shipping_contact_info';
  $field_group->entity_type = 'entityform';
  $field_group->bundle = 'order_free_intel_iotg_gateway';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Shipping Contact Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_contact_email_address',
      1 => 'field_gateway_shipment_address',
      2 => 'field_shipping_contact_number',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-shipping-contact-info field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_shipping_contact_info|entityform|order_free_intel_iotg_gateway|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_solution_details|node|solution|form';
  $field_group->group_name = 'group_solution_details';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Solution Details',
    'weight' => '2',
    'children' => array(
      0 => 'body',
      1 => 'field_additional_resources',
      2 => 'field_datasheet',
      3 => 'field_brief',
      4 => 'field_image',
      5 => 'field_website',
      6 => 'field_end_user_description',
      7 => 'group_price',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-solution-details field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_solution_details|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_solution_information|node|solution|form';
  $field_group->group_name = 'group_solution_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Solution Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_company',
      1 => 'field_pre_release',
      2 => 'field_end_user_display',
      3 => 'language',
      4 => 'title',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Solution Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-solution-information field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_solution_information|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_standards_supported|node|component|form';
  $field_group->group_name = 'group_standards_supported';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_characteristics';
  $field_group->data = array(
    'label' => 'Standards Supported',
    'weight' => '15',
    'children' => array(
      0 => 'field_stds_audio',
      1 => 'field_stds_gps',
      2 => 'group_stds_eth',
      3 => 'group_stds_interconnect',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-standards-supported field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_standards_supported|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_eth|node|component|form';
  $field_group->group_name = 'group_stds_eth';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_standards_supported';
  $field_group->data = array(
    'label' => 'Ethernet',
    'weight' => '28',
    'children' => array(
      0 => 'field_stds_eth',
      1 => 'field_stds_eth_ports',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stds-eth field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stds_eth|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_eth|node|solution|form';
  $field_group->group_name = 'group_stds_eth';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stds';
  $field_group->data = array(
    'label' => 'Ethernet',
    'weight' => '35',
    'children' => array(
      0 => 'field_stds_eth',
      1 => 'field_stds_eth_ports',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Ethernet',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-stds-eth field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_stds_eth|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_interconnect|node|component|form';
  $field_group->group_name = 'group_stds_interconnect';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_standards_supported';
  $field_group->data = array(
    'label' => 'Interconnect',
    'weight' => '30',
    'children' => array(
      0 => 'field_stds_camera',
      1 => 'field_stds_csix',
      2 => 'field_stds_pc_104',
      3 => 'field_stds_sd_sdio_emmc',
      4 => 'field_stds_sim',
      5 => 'field_stds_spi',
      6 => 'field_stds_systems',
      7 => 'field_stds_wlan',
      8 => 'field_stds_wpan',
      9 => 'field_stds_wwan',
      10 => 'group_stds_pcie',
      11 => 'group_stds_storage',
      12 => 'group_stds_usb',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stds-interconnect field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stds_interconnect|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_interconnect|node|solution|form';
  $field_group->group_name = 'group_stds_interconnect';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stds';
  $field_group->data = array(
    'label' => 'Interconnect',
    'weight' => '38',
    'children' => array(
      0 => 'field_stds_camera',
      1 => 'field_stds_csix',
      2 => 'field_stds_pc_104',
      3 => 'field_stds_sd_sdio_emmc',
      4 => 'field_stds_sim',
      5 => 'field_stds_spi',
      6 => 'field_number_of_serial_ports',
      7 => 'field_keyboard_and_mouse',
      8 => 'group_stds_pcie',
      9 => 'group_stds_storage',
      10 => 'group_stds_usb',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Interconnect',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-stds-interconnect field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_stds_interconnect|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_pcie|node|component|form';
  $field_group->group_name = 'group_stds_pcie';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stds_interconnect';
  $field_group->data = array(
    'label' => 'PCI Express',
    'weight' => '34',
    'children' => array(
      0 => 'field_stds_pcie_as',
      1 => 'field_stds_pcie_mini',
      2 => 'field_stds_pcie_rev',
      3 => 'field_stds_pcie_x1',
      4 => 'field_stds_pcie_x16',
      5 => 'field_stds_pcie_x2',
      6 => 'field_stds_pcie_x4',
      7 => 'field_stds_pcie_x8',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stds-pcie field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stds_pcie|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_pcie|node|solution|form';
  $field_group->group_name = 'group_stds_pcie';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stds_interconnect';
  $field_group->data = array(
    'label' => 'PCI Express',
    'weight' => '29',
    'children' => array(
      0 => 'field_stds_pcie_mini',
      1 => 'field_stds_pcie_rev',
      2 => 'field_stds_pcie_x1',
      3 => 'field_stds_pcie_x2',
      4 => 'field_stds_pcie_x4',
      5 => 'field_stds_pcie_x8',
      6 => 'field_stds_pcie_x16',
      7 => 'field_stds_pcie_as',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'PCI Express',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-stds-pcie field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_stds_pcie|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_storage|node|component|form';
  $field_group->group_name = 'group_stds_storage';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stds_interconnect';
  $field_group->data = array(
    'label' => 'Storage',
    'weight' => '39',
    'children' => array(
      0 => 'field_stds_storage_cfst',
      1 => 'field_stds_storage_ide',
      2 => 'field_stds_storage_raid',
      3 => 'field_stds_storage_sata',
      4 => 'field_stds_storage_ssd_size',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stds-storage field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stds_storage|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_storage|node|solution|form';
  $field_group->group_name = 'group_stds_storage';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stds_interconnect';
  $field_group->data = array(
    'label' => 'Storage',
    'weight' => '34',
    'children' => array(
      0 => 'field_stds_storage_cfst',
      1 => 'field_stds_storage_ide',
      2 => 'field_stds_storage_sata',
      3 => 'field_stds_storage_raid',
      4 => 'field_stds_storage_ssd_size',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Storage',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-stds-storage field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_stds_storage|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_usb|node|component|form';
  $field_group->group_name = 'group_stds_usb';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'component';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stds_interconnect';
  $field_group->data = array(
    'label' => 'USB',
    'weight' => '38',
    'children' => array(
      0 => 'field_stds_usb_on_the_go',
      1 => 'field_stds_usb_usb1',
      2 => 'field_stds_usb_usb2',
      3 => 'field_stds_usb_usb3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-stds-usb field-group-fieldset ',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_stds_usb|node|component|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds_usb|node|solution|form';
  $field_group->group_name = 'group_stds_usb';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_stds_interconnect';
  $field_group->data = array(
    'label' => 'USB',
    'weight' => '33',
    'children' => array(
      0 => 'field_stds_usb_on_the_go',
      1 => 'field_stds_usb_usb1',
      2 => 'field_stds_usb_usb2',
      3 => 'field_stds_usb_usb3',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'USB',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-stds-usb field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_stds_usb|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_stds|node|solution|form';
  $field_group->group_name = 'group_stds';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'solution';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_characteristics';
  $field_group->data = array(
    'label' => 'Standards Supported',
    'weight' => '18',
    'children' => array(
      0 => 'field_stds_audio',
      1 => 'field_stds_gps',
      2 => 'field_stds_systems',
      3 => 'field_stds_wlan',
      4 => 'field_stds_wpan',
      5 => 'field_stds_wwan',
      6 => 'group_stds_eth',
      7 => 'group_stds_interconnect',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Standards Supported',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-stds field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'collapsible',
    ),
  );
  $export['group_stds|node|solution|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_section_content|node|training_sub_section|form';
  $field_group->group_name = 'group_sub_section_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_sub_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sub-Section Content',
    'weight' => '3',
    'children' => array(
      0 => 'field_content_blocks',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Sub-Section Content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-sub-section-content field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sub_section_content|node|training_sub_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_section_information|node|training_sub_section|form';
  $field_group->group_name = 'group_sub_section_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_sub_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sub-Section Information',
    'weight' => '0',
    'children' => array(
      0 => 'field_icon',
      1 => 'field_sub_section_order',
      2 => 'language',
      3 => 'title',
      4 => 'group_training_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Sub-Section Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-sub-section-information field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sub_section_information|node|training_sub_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_section_modals|node|training_sub_section|form';
  $field_group->group_name = 'group_sub_section_modals';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_sub_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sub-Section Modals',
    'weight' => '4',
    'children' => array(
      0 => 'field_modal',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Sub-Section Modals',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-sub-section-modals field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sub_section_modals|node|training_sub_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_section_slides|node|training_sub_section|form';
  $field_group->group_name = 'group_sub_section_slides';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_sub_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sub-Section Slides',
    'weight' => '5',
    'children' => array(
      0 => 'field_description',
      1 => 'field_next_step_slide',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Sub-Section Slides',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-sub-section-slides field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sub_section_slides|node|training_sub_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_sub_section_videos|node|training_sub_section|form';
  $field_group->group_name = 'group_sub_section_videos';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_sub_section';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sub-Section Videos',
    'weight' => '1',
    'children' => array(
      0 => 'field_webinar_video',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Sub-Section Videos',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-sub-section-videos field-group-tab',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_sub_section_videos|node|training_sub_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_training_section|node|training_sub_section|form';
  $field_group->group_name = 'group_training_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'training_sub_section';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_sub_section_information';
  $field_group->data = array(
    'label' => 'Training Section',
    'weight' => '15',
    'children' => array(
      0 => 'field_training_section',
      1 => 'field_training_section_slide',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Training Section',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => ' group-training-section field-group-fieldset',
        'description' => '',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_training_section|node|training_sub_section|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work|user|user|default';
  $field_group->group_name = 'group_work';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_geographic_responsibilitie',
      1 => 'field_company_role',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Work Information',
      'instance_settings' => array(
        'classes' => ' group-work field-group-div',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'id' => 'user_user_full_group_work',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_work|user|user|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_work|user|user|form';
  $field_group->group_name = 'group_work';
  $field_group->entity_type = 'user';
  $field_group->bundle = 'user';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Work Information',
    'weight' => '5',
    'children' => array(
      0 => 'field_geographic_responsibilitie',
      1 => 'field_company_role',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => ' group-work field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_work|user|user|form'] = $field_group;

  return $export;
}
