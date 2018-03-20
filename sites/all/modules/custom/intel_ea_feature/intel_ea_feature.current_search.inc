<?php
/**
 * @file
 * intel_ea_feature.current_search.inc
 */

/**
 * Implements hook_current_search_default_items().
 */
function intel_ea_feature_current_search_default_items() {
  $export = array();

  $item = new stdClass();
  $item->disabled = FALSE; /* Edit this to true to make a default item disabled initially */
  $item->api_version = 1;
  $item->name = 'solutions_directory';
  $item->label = 'Solutions Directory';
  $item->settings = array(
    'items' => array(
      'items_label' => array(
        'id' => 'text',
        'label' => 'Items Label',
        'text' => t('Filter Applied:'),
        'plural' => 1,
        'text_plural' => t('Filters Applied: '),
        'plural_condition' => 'facetapi_results:result-count',
        'wrapper' => 1,
        'element' => 'strong',
        'css' => 1,
        'classes' => '',
        'weight' => '-50',
      ),
      'active_items' => array(
        'id' => 'active',
        'label' => 'Active items',
        'pattern' => '[facetapi_active:facet-label]: [facetapi_active:active-value]',
        'keys' => 1,
        'css' => 1,
        'classes' => 'clearfix',
        'nofollow' => 1,
        'weight' => '-49',
      ),
    ),
    'advanced' => array(
      'empty_searches' => '3',
    ),
  );
  $export['solutions_directory'] = $item;

  return $export;
}
