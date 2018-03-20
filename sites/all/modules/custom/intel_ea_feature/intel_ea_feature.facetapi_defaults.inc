<?php
/**
 * @file
 * intel_ea_feature.facetapi_defaults.inc
 */

/**
 * Implements hook_facetapi_default_facet_settings().
 */
function intel_ea_feature_facetapi_default_facet_settings() {
  $export = array();

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies::field_company_node_eb:field_categories';
  $facet->searcher = 'search_api@companies';
  $facet->realm = '';
  $facet->facet = 'field_company_node_eb:field_categories';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'field_company_node_eb:field_categories',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'categories',
  );
  $export['search_api@companies::field_company_node_eb:field_categories'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies::field_company_node_eb:field_geographic_location';
  $facet->searcher = 'search_api@companies';
  $facet->realm = '';
  $facet->facet = 'field_company_node_eb:field_geographic_location';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'field_company_node_eb:field_geographic_location',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'geographic_location',
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'exclude' => 0,
  );
  $export['search_api@companies::field_company_node_eb:field_geographic_location'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies::field_company_node_eb:field_market_segments';
  $facet->searcher = 'search_api@companies';
  $facet->realm = '';
  $facet->facet = 'field_company_node_eb:field_market_segments';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'field_company_node_eb:field_market_segments',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'market_segments',
    'individual_parent' => '0',
    'limit_active_items' => 0,
    'exclude' => 0,
  );
  $export['search_api@companies::field_company_node_eb:field_market_segments'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies::field_company_node_eb:field_processors_list';
  $facet->searcher = 'search_api@companies';
  $facet->realm = '';
  $facet->facet = 'field_company_node_eb:field_processors_list';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'and',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'field_company_node_eb:field_processors_list',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'processors',
  );
  $export['search_api@companies::field_company_node_eb:field_processors_list'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies::field_membership_tier';
  $facet->searcher = 'search_api@companies';
  $facet->realm = '';
  $facet->facet = 'field_membership_tier';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'individual_parent' => '0',
    'query_type' => 'term',
    'limit_active_items' => 0,
    'default_true' => '1',
    'facet_search_ids' => array(),
    'exclude' => 0,
    'pretty_paths_alias' => 'field_membership_tier',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'membership_tier',
  );
  $export['search_api@companies::field_membership_tier'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies:block:field_company_node_eb:field_categories';
  $facet->searcher = 'search_api@companies';
  $facet->realm = 'block';
  $facet->facet = 'field_company_node_eb:field_categories';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'label_override' => 0,
    'label' => 'node entity referenced from field_company » Categories',
  );
  $export['search_api@companies:block:field_company_node_eb:field_categories'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies:block:field_company_node_eb:field_geographic_location';
  $facet->searcher = 'search_api@companies';
  $facet->realm = 'block';
  $facet->facet = 'field_company_node_eb:field_geographic_location';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'label_override' => 1,
    'label' => 'Geographic Location',
  );
  $export['search_api@companies:block:field_company_node_eb:field_geographic_location'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies:block:field_company_node_eb:field_market_segments';
  $facet->searcher = 'search_api@companies';
  $facet->realm = 'block';
  $facet->facet = 'field_company_node_eb:field_market_segments';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'label_override' => 1,
    'label' => 'Market Segments',
  );
  $export['search_api@companies:block:field_company_node_eb:field_market_segments'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies:block:field_company_node_eb:field_processors_list';
  $facet->searcher = 'search_api@companies';
  $facet->realm = 'block';
  $facet->facet = 'field_company_node_eb:field_processors_list';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'label_override' => 0,
    'label' => 'node entity referenced from field_company » Processors',
  );
  $export['search_api@companies:block:field_company_node_eb:field_processors_list'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@companies:block:field_membership_tier';
  $facet->searcher = 'search_api@companies';
  $facet->realm = 'block';
  $facet->facet = 'field_membership_tier';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-47',
      'taxonomy_weight' => '-48',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'taxonomy_weight' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
    'label_override' => 1,
    'label' => 'Membership Tier',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
  );
  $export['search_api@companies:block:field_membership_tier'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_application';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_application';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'application',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'application',
  );
  $export['search_api@solutions::field_application'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_categories';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_categories';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'roles' => array(
        1 => 0,
        2 => 0,
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
      ),
      'bundle' => 'none',
      'bundle_selected' => array(
        'company' => 0,
        'opportunity' => 0,
        'solution' => 0,
      ),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'categories',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'categories',
  );
  $export['search_api@solutions::field_categories'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_chipsets';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_chipsets';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'chipsets',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'chipsets',
  );
  $export['search_api@solutions::field_chipsets'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_company';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_company';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'company',
  );
  $export['search_api@solutions::field_company'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_hdmi';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_hdmi';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_hdmi',
  );
  $export['search_api@solutions::field_display_hdmi'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_independent';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_independent';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_independent',
  );
  $export['search_api@solutions::field_display_independent'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_lvds';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_lvds';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_lvds',
  );
  $export['search_api@solutions::field_display_lvds'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_other';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_other';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_other',
  );
  $export['search_api@solutions::field_display_other'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_pcie_x16';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_pcie_x16';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_pcie_x16',
  );
  $export['search_api@solutions::field_display_pcie_x16'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_port_edp';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_port_edp';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_port_edp',
  );
  $export['search_api@solutions::field_display_port_edp'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_size';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_size';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_size',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'display_size',
  );
  $export['search_api@solutions::field_display_size'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_total';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_total';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_total',
  );
  $export['search_api@solutions::field_display_total'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_display_vga';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_display_vga';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'display_vga',
  );
  $export['search_api@solutions::field_display_vga'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_ethernet_controllers';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_ethernet_controllers';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'ethernet_controllers',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'ethernet_controllers',
  );
  $export['search_api@solutions::field_ethernet_controllers'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_geographic_location';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_geographic_location';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'geographic_location',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'geographic_location',
  );
  $export['search_api@solutions::field_geographic_location'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_intel_technologies';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_intel_technologies';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'intel_technologies',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'intel_technologies',
  );
  $export['search_api@solutions::field_intel_technologies'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_intel_wireless';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_intel_wireless';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'intel_wireless',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'intel_wireless',
  );
  $export['search_api@solutions::field_intel_wireless'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_market_segments';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_market_segments';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'market_segments',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'market_segments',
  );
  $export['search_api@solutions::field_market_segments'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_memory_ecc';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_memory_ecc';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'memory_ecc',
  );
  $export['search_api@solutions::field_memory_ecc'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_memory_max';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_memory_max';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'memory_max',
  );
  $export['search_api@solutions::field_memory_max'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_memory_type';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_memory_type';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'memory_type',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'memory_type',
  );
  $export['search_api@solutions::field_memory_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_power';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_power';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'power',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'power',
  );
  $export['search_api@solutions::field_power'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_processors_count';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_processors_count';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'processors_count',
  );
  $export['search_api@solutions::field_processors_count'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_processors_list';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_processors_list';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'processors_list',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'processors',
  );
  $export['search_api@solutions::field_processors_list'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_software_solutions';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_software_solutions';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'software_solutions',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'software_solutions',
  );
  $export['search_api@solutions::field_software_solutions'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_audio';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_audio';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_audio',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'audio_standards',
  );
  $export['search_api@solutions::field_stds_audio'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_camera';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_camera';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_camera',
  );
  $export['search_api@solutions::field_stds_camera'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_csix';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_csix';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_csix',
  );
  $export['search_api@solutions::field_stds_csix'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_eth';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_eth';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_eth',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'ethernet_standards',
  );
  $export['search_api@solutions::field_stds_eth'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_eth_ports';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_eth_ports';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_eth_ports',
  );
  $export['search_api@solutions::field_stds_eth_ports'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_gps';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_gps';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_gps',
  );
  $export['search_api@solutions::field_stds_gps'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pc_104';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pc_104';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pc_104',
  );
  $export['search_api@solutions::field_stds_pc_104'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pcie_as';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pcie_as';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pcie_as',
  );
  $export['search_api@solutions::field_stds_pcie_as'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pcie_mini';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pcie_mini';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pcie_mini',
  );
  $export['search_api@solutions::field_stds_pcie_mini'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pcie_rev';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pcie_rev';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pcie_rev',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'pcie_revisions',
  );
  $export['search_api@solutions::field_stds_pcie_rev'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pcie_x1';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pcie_x1';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pcie_x1',
  );
  $export['search_api@solutions::field_stds_pcie_x1'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pcie_x16';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pcie_x16';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pcie_x16',
  );
  $export['search_api@solutions::field_stds_pcie_x16'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pcie_x2';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pcie_x2';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pcie_x2',
  );
  $export['search_api@solutions::field_stds_pcie_x2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pcie_x4';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pcie_x4';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pcie_x4',
  );
  $export['search_api@solutions::field_stds_pcie_x4'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_pcie_x8';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_pcie_x8';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_pcie_x8',
  );
  $export['search_api@solutions::field_stds_pcie_x8'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_processor_socketed';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_processor_socketed';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_processor_socketed',
  );
  $export['search_api@solutions::field_stds_processor_socketed'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_sd_sdio_emmc';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_sd_sdio_emmc';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_sd_sdio_emmc',
  );
  $export['search_api@solutions::field_stds_sd_sdio_emmc'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_sim';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_sim';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_sim',
  );
  $export['search_api@solutions::field_stds_sim'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_spi';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_spi';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_spi',
  );
  $export['search_api@solutions::field_stds_spi'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_storage_cfst';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_storage_cfst';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_storage_cfst',
  );
  $export['search_api@solutions::field_stds_storage_cfst'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_storage_ide';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_storage_ide';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_storage_ide',
  );
  $export['search_api@solutions::field_stds_storage_ide'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_storage_raid';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_storage_raid';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_storage_raid',
  );
  $export['search_api@solutions::field_stds_storage_raid'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_storage_sata';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_storage_sata';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_storage_sata',
  );
  $export['search_api@solutions::field_stds_storage_sata'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_storage_ssd_size';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_storage_ssd_size';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_storage_ssd_size',
  );
  $export['search_api@solutions::field_stds_storage_ssd_size'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_systems';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_systems';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_systems',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'systems_standards',
  );
  $export['search_api@solutions::field_stds_systems'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_usb_on_the_go';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_usb_on_the_go';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_usb_on_the_go',
  );
  $export['search_api@solutions::field_stds_usb_on_the_go'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_usb_usb1';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_usb_usb1';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_usb_usb1',
  );
  $export['search_api@solutions::field_stds_usb_usb1'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_usb_usb2';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_usb_usb2';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_usb_usb2',
  );
  $export['search_api@solutions::field_stds_usb_usb2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_usb_usb3';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_usb_usb3';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_usb_usb3',
  );
  $export['search_api@solutions::field_stds_usb_usb3'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_wlan';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_wlan';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_wlan',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'wlan',
  );
  $export['search_api@solutions::field_stds_wlan'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_wpan';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_wpan';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => 0,
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_wpan',
  );
  $export['search_api@solutions::field_stds_wpan'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions::field_stds_wwan';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = '';
  $facet->facet = 'field_stds_wwan';
  $facet->enabled = FALSE;
  $facet->settings = array(
    'operator' => 'or',
    'hard_limit' => '-1',
    'dependencies' => array(
      'bundle' => 'none',
      'bundle_selected' => array(),
      'roles' => array(),
    ),
    'facet_mincount' => '1',
    'facet_missing' => '0',
    'flatten' => '0',
    'query_type' => 'term',
    'default_true' => '1',
    'facet_search_ids' => array(),
    'pretty_paths_alias' => 'stds_wwan',
    'pretty_paths_taxonomy_pathauto' => 0,
    'pretty_paths_taxonomy_pathauto_vocabulary' => 'wwan',
  );
  $export['search_api@solutions::field_stds_wwan'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_application';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_application';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_application'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_categories';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_categories';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_categories'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_chipsets';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_chipsets';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_chipsets'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_company';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_company';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_company'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_hdmi';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_hdmi';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_hdmi'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_independent';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_independent';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_independent'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_lvds';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_lvds';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_lvds'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_other';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_other';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_other'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_pcie_x16';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_pcie_x16';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_pcie_x16'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_port_edp';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_port_edp';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_port_edp'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_size';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_size';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_size'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_total';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_total';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_total'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_display_vga';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_display_vga';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_display_vga'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_ethernet_controllers';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_ethernet_controllers';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_ethernet_controllers'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_geographic_location';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_geographic_location';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_geographic_location'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_intel_technologies';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_intel_technologies';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_intel_technologies'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_intel_wireless';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_intel_wireless';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_intel_wireless'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_market_segments';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_market_segments';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_market_segments'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_memory_ecc';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_memory_ecc';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_memory_ecc'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_memory_max';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_memory_max';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_memory_max'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_memory_type';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_memory_type';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_memory_type'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_power';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_power';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_power'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_processors_count';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_processors_count';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_processors_count'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_processors_list';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_processors_list';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_processors_list'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_software_solutions';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_software_solutions';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_software_solutions'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_audio';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_audio';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_audio'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_camera';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_camera';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_camera'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_csix';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_csix';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_csix'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_eth';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_eth';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_eth'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_eth_ports';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_eth_ports';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_eth_ports'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_gps';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_gps';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_gps'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pc_104';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pc_104';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pc_104'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pcie_as';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pcie_as';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pcie_as'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pcie_mini';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pcie_mini';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pcie_mini'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pcie_rev';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pcie_rev';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pcie_rev'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pcie_x1';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pcie_x1';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pcie_x1'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pcie_x16';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pcie_x16';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pcie_x16'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pcie_x2';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pcie_x2';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pcie_x2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pcie_x4';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pcie_x4';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pcie_x4'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_pcie_x8';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_pcie_x8';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_pcie_x8'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_processor_socketed';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_processor_socketed';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_processor_socketed'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_sd_sdio_emmc';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_sd_sdio_emmc';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_sd_sdio_emmc'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_sim';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_sim';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_sim'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_spi';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_spi';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_spi'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_storage_cfst';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_storage_cfst';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_storage_cfst'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_storage_ide';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_storage_ide';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_storage_ide'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_storage_raid';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_storage_raid';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_storage_raid'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_storage_sata';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_storage_sata';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_storage_sata'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_storage_ssd_size';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_storage_ssd_size';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_storage_ssd_size'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_systems';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_systems';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_systems'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_usb_on_the_go';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_usb_on_the_go';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_usb_on_the_go'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_usb_usb1';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_usb_usb1';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_usb_usb1'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_usb_usb2';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_usb_usb2';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_usb_usb2'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_usb_usb3';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_usb_usb3';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'indexed' => 'indexed',
      'active' => 0,
      'count' => 0,
      'display' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_usb_usb3'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_wlan';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_wlan';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_wlan'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_wpan';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_wpan';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
    ),
    'active_sorts' => array(
      'active' => 0,
      'count' => 0,
      'display' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'display' => '-48',
      'indexed' => '0',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 0,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_wpan'] = $facet;

  $facet = new stdClass();
  $facet->disabled = FALSE; /* Edit this to true to make a default facet disabled initially */
  $facet->api_version = 1;
  $facet->name = 'search_api@solutions:block:field_stds_wwan';
  $facet->searcher = 'search_api@solutions';
  $facet->realm = 'block';
  $facet->facet = 'field_stds_wwan';
  $facet->enabled = TRUE;
  $facet->settings = array(
    'weight' => 0,
    'widget' => 'facetapi_checkbox_links',
    'filters' => array(
      'active_items' => array(
        'status' => 0,
        'weight' => '-50',
      ),
      'intel_ea_module' => array(
        'status' => 1,
        'weight' => '-49',
      ),
      'current_depth' => array(
        'status' => 0,
        'weight' => '-48',
      ),
    ),
    'active_sorts' => array(
      'taxonomy_weight' => 'taxonomy_weight',
      'display' => 'display',
      'active' => 0,
      'count' => 0,
      'indexed' => 0,
    ),
    'sort_weight' => array(
      'active' => '-50',
      'count' => '-49',
      'taxonomy_weight' => '-48',
      'display' => '-47',
      'indexed' => '-46',
    ),
    'sort_order' => array(
      'active' => '3',
      'count' => '3',
      'taxonomy_weight' => '4',
      'display' => '4',
      'indexed' => '4',
    ),
    'empty_behavior' => 'none',
    'soft_limit' => '0',
    'nofollow' => 0,
    'show_expanded' => 1,
    'empty_text' => array(
      'value' => '',
      'format' => 'wysiwyg_basic',
    ),
    'submit_realm' => 'Save and go back to realm settings',
    'facet_more_text' => 'Show more',
    'facet_fewer_text' => 'Show fewer',
  );
  $export['search_api@solutions:block:field_stds_wwan'] = $facet;

  return $export;
}
