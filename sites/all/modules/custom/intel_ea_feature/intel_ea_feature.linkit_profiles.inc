<?php
/**
 * @file
 * intel_ea_feature.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function intel_ea_feature_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'editor_default';
  $linkit_profile->admin_title = 'Editor Default';
  $linkit_profile->admin_description = 'The default Linkit profile for WYSIWYG editors.';
  $linkit_profile->profile_type = '1';
  $linkit_profile->data = array(
    'text_formats' => array(
      'wysiwyg_basic' => 0,
      'wysiwyg_advanced' => 0,
      'plain_text' => 0,
    ),
    'search_plugins' => array(
      'entity:entityform' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:field_collection_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:entityform' => array(
      'result_description' => '',
      'bundles' => array(
        'membership_renewal_application' => 0,
        'general_membership_application' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:field_collection_item' => array(
      'result_description' => '',
      'bundles' => array(
        'field_opportunity_calendar_item' => 0,
        'field_opportunity_resource' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'company' => 0,
        'notification' => 0,
        'opportunity' => 0,
        'page' => 0,
        'solution' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
      'include_unpublished' => 0,
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
      'include_unpublished' => 0,
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
      'include_unpublished' => 0,
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'audio' => 0,
        'document' => 0,
        'image' => 0,
        'video' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'categories' => 0,
        'chipsets' => 0,
        'display_size' => 0,
        'application' => 0,
        'ethernet_controllers' => 0,
        'geographic_location' => 0,
        'intel_technologies' => 0,
        'intel_wireless' => 0,
        'market_segments' => 0,
        'memory_type' => 0,
        'power' => 0,
        'processors' => 0,
        'software_solutions' => 0,
        'audio_standards' => 0,
        'ethernet_standards' => 0,
        'pcie_revisions' => 0,
        'systems_standards' => 0,
        'wlan' => 0,
        'wwan' => 0,
        'membership_type' => 0,
        'geographic_coverage' => 0,
        'company_type' => 0,
        'geographic_region' => 0,
        'intel_sponsoring_business_units' => 0,
        'membership_segments' => 0,
        'embedded_ia_processor_support' => 0,
        'salutations' => 0,
        'company_roles' => 0,
        'opportunity_group' => 0,
        'opportunity_resource_type' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'menu_eligible_opportunities' => 0,
        'menu_general_resources' => 0,
        'main_menu' => 0,
        'management' => 0,
        'menu_reports' => 0,
        'menu_member_roster_navigation' => 0,
        'menu_administration' => 0,
        'menu_membership' => 0,
        'navigation' => 0,
        'menu_site_navigation' => 0,
        'user_menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'url_method' => '3',
    ),
    'attribute_plugins' => array(
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['editor_default'] = $linkit_profile;

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'field_default';
  $linkit_profile->admin_title = 'Field Default';
  $linkit_profile->admin_description = 'The default Linkit profile for fields.';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:entityform' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:file' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:field_collection_item' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:menu_link' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:entityform' => array(
      'result_description' => '',
      'bundles' => array(
        'membership_renewal_application' => 0,
        'general_membership_application' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:field_collection_item' => array(
      'result_description' => '',
      'bundles' => array(
        'field_opportunity_calendar_item' => 0,
        'field_opportunity_resource' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:node' => array(
      'result_description' => '',
      'bundles' => array(
        'company' => 0,
        'notification' => 0,
        'opportunity' => 0,
        'page' => 0,
        'solution' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
      'include_unpublished' => 0,
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
      'include_unpublished' => 0,
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
      'include_unpublished' => 0,
    ),
    'entity:file' => array(
      'result_description' => '',
      'bundles' => array(
        'audio' => 0,
        'document' => 0,
        'image' => 0,
        'video' => 0,
      ),
      'group_by_bundle' => 0,
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'categories' => 0,
        'chipsets' => 0,
        'display_size' => 0,
        'application' => 0,
        'ethernet_controllers' => 0,
        'geographic_location' => 0,
        'intel_technologies' => 0,
        'intel_wireless' => 0,
        'market_segments' => 0,
        'memory_type' => 0,
        'power' => 0,
        'processors' => 0,
        'software_solutions' => 0,
        'audio_standards' => 0,
        'ethernet_standards' => 0,
        'pcie_revisions' => 0,
        'systems_standards' => 0,
        'wlan' => 0,
        'wwan' => 0,
        'membership_type' => 0,
        'geographic_coverage' => 0,
        'company_type' => 0,
        'geographic_region' => 0,
        'intel_sponsoring_business_units' => 0,
        'membership_segments' => 0,
        'embedded_ia_processor_support' => 0,
        'salutations' => 0,
        'company_roles' => 0,
        'opportunity_group' => 0,
        'opportunity_resource_type' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'entity:menu_link' => array(
      'result_description' => '',
      'bundles' => array(
        'menu_eligible_opportunities' => 0,
        'menu_general_resources' => 0,
        'main_menu' => 0,
        'management' => 0,
        'menu_reports' => 0,
        'menu_member_roster_navigation' => 0,
        'menu_administration' => 0,
        'menu_membership' => 0,
        'navigation' => 0,
        'menu_site_navigation' => 0,
        'user_menu' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'insert_plugin' => array(
      'plugin' => 'raw_url',
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '10000',
    ),
  );
  $export['field_default'] = $linkit_profile;

  return $export;
}
