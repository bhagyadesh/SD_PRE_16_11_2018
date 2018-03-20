<?php
/**
 * @file
 * Stores intel_ea_module_module resource rendering function(s)
 *
 * @IMPORTANT: All paths to reach these resources set in UI here:
 * admin/structure/services/list/solutions_directory/resources
 *
 */

/**
 * API endpoint for returning info for a UID to intel dashboard.
 *
 * test @ /api/1.0/int-dash-comp/....
 *
 * @param string $filter_type
 *   Takes either 'BID' or 'NID' strings to filter on those values.
 * @param int $filter_value
 *  Takes an integer value to find company NID or BID from.
 * @param int $solutions_count
 *  Amount of solutions desired to be returned.
 * @param string $language
 *  Desired language to be returned.
 *
 * @return mixed
 *   Returns FALSE if an issue, otherwise returns array for intel dash.
 */
function intel_ea_module_get_company_dash_info($filter_type, $filter_value, $solutions_count = 4, $language = 'EN') {

  // @TODO: Remove this jank. Intel wanted it to avoid having to redeploy their dash.
  $filter_type = 'nid';

  // Force uppercase on filter type.
  $filter_type = strtoupper($filter_type);
  // Param defaults often null. Force default values.
  if(!$solutions_count){
    $solutions_count = 4;
  }
  if(!$language){
    $language = 'EN';
  }

  // Make sure a user ID or email was passed in.
  if(isset($filter_type) && $filter_type == 'BID' || $filter_type == 'NID'){

    // Generate cache ID for use in getting/setting cache.
    $cache_cid = 'intel_ea_module_get_company_dash_info_' . $filter_type . '_' . $filter_value . '_' . $solutions_count . '_' . $language;

    // Attempt to load cached values first.
    if($cached_data = cache_get($cache_cid)){
      if(REQUEST_TIME <= $cached_data->expire){
        return $cached_data->data;
      }
      else{
        cache_clear_all($cache_cid, 'cache');
      }
    }


    // Check if we were passed BID.
    if($filter_type == 'BID'){
      // @TODO: BID functionality to later be developed.
      return FALSE;
    }
    elseif($filter_type == 'NID'){
      // Double check NID loads a company
      if($company_node = node_load($filter_value)){
        // Check that the NID is actually a company.
        if($company_node->type == 'company'){
          // Accept NID
          $company_nid = $company_node->nid;
        }
        else{
          // Not actually a company.
          return FALSE;
        }

      }else{
        // No Node for that param. Return FALSE.
        return FALSE;
      }
    }
    else{
      // Somehow we got past the first check but filter type was not BID or NID?
      return FALSE;
    }

    // Populate the query.
    $query = new EntityFieldQuery();

    // Initialize dash values to return.
    $dash_values = array();

    // Get all solutions for a company.
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'solution')
      ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyOrderBy('created', 'DESC')
      ->propertyCondition('language', $language, '=')
      ->fieldCondition('field_company', 'target_id', $company_nid, '=')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.
    $result = $query->execute();

    // Check to make sure that there were solutions for said company.
    if(!empty($result)) {
      // Get node values from results
      $nodes = $result['node'];

      // Determine total solutions for a company.
      $dash_values['count'] = count($nodes);

      // Set total count to zero. Used to find total views of solutions.
      $total_count = 0;

      // Determine total views for said solutions.
      foreach($nodes as $node){
        // Get statistics on node views for each company solution, add to total count.
        $stats = statistics_get($node->nid);
        if(!empty($stats)){
          $total_count += intval($stats['totalcount']);
        }
      }

      // Add total count to dash count.
      $dash_values['view_count'] = $total_count;

      // Determine 4 most recent solutions and append to dash values.
      $query->range(0, $solutions_count);
      $four_latest_result = $query->execute();
      $four_latest_solutions = $four_latest_result['node'];
      $dash_values['recent_solutions'] = array();

      // Loop through all of the requested latest solutions.
      foreach($four_latest_solutions as $solution_node){
        // Wrap the solution for ease of accessing data values.
        $wrapped_solution = entity_metadata_wrapper('node', node_load($solution_node->nid));
        // Create a URL for the image file.
        $image = $wrapped_solution->field_image->value();
        // Stash description value so we can get at safe value.
        $description = $wrapped_solution->body->value() ;

        // Stash node values in the dash values array.
        $dash_values['recent_solutions'][$solution_node->nid] = array(
          'url' => $wrapped_solution->url->value(),
          'title' => $wrapped_solution->title->value(),
          'description' => $description['safe_value'],
          'image' => file_create_url($image['uri']),
        );
      }
    }
    // Cache the current values for 2 hours.
    cache_set($cache_cid, $dash_values, 'cache', REQUEST_TIME + (60*60*2));
    // Return all of the collected values.
    return $dash_values;
  }
  else{
    // Not BID or NID, exit and return no values.
    return FALSE;
  }
}
