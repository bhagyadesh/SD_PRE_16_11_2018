<?php
/**
 * @file
 * Stores any information needed to render services.
 */

/**
 * Function to return data needed to render a service api endpoint.
 *
 * @return array
 */
function intel_ea_module_services_resources() {
  $resources = array(
    // Company NID or BID based services endpoint.
    'intel_ea_module_dashboard_company resources' => array(
      'operations' => array(
        'retrieve' => array(
          'help' => 'Retrieve Intel Request dashboard info for a company NID or BID. Namely company solution count, views for month, and 3 most recent solutions.',
          'file' => array(
            'type' => 'inc',
            'module' => 'intel_ea_module',
            'name' => 'services/intel_ea_module.resource',
          ),
          'callback' => 'intel_ea_module_get_company_dash_info',
          'args' => array(
            //@TODO: All source pathes are adjusted down one for intel.
            array(
              'name' => 'filter_type',
              'optional' => TRUE,
              'source' => array('path' => 0),
              'type' => 'string',
              'description' => 'Pass either NID or BID strings to perform lookup accordingly',
            ),
            array(
              'name' => 'filter_value',
              'optional' => TRUE,
              'source' => array('path' => 0),
              'type' => 'string',
              'description' => 'Pass either NID (int) or bid (int).',
            ),
            array(
              'name' => 'solutions_count',
              'optional' => TRUE,
              'source' => array('path' => 1),
              'type' => 'int',
              'description' => 'The amount of solutions desired. Defaults to 4.',
            ),
            array(
              'name' => 'language',
              'optional' => TRUE,
              'source' => array('path' => 2),
              'type' => 'string',
              'description' => 'The language for a user.',
            ),
          ),
          'access callback' => 'intel_ea_module_services_access',
          'access arguments' => array('view'),
        ),
      ),
    ),
  );
  return $resources;
}

/**
 * Permissions check on the API.
 *
 * Automatically returns true to allow access.
 */
function intel_ea_module_services_access(){
  return TRUE;
}
