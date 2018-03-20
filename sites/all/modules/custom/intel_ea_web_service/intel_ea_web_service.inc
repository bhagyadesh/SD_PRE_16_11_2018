<?php
// intel_ea_web_service.inc

/**
 * Callback for retrieving note resources.
 *
 * @param int $id
 * @return object
 */
 
function _profile_statistics_retrieve($id) 
{

	
	return members_get_profile_statistics($id);
}

/** Gets a note object by id.
 *
 * @param int $id
 * @return object
 */

function members_get_profile_statistics($id) 
{
	  $language = 'EN';
	  $dataSet = array();
	  
      if($company_node = node_load($id))
	  {
        if($company_node->type == 'company')
		{
          $company_nid = $company_node->nid;
        }
		else
		{
			return "invalid company id 0";
		}
	  }
	  else {
		  return "invlaid company id 1"; 
	  }	  
	 
    $query = new EntityFieldQuery();

    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'solution')
      ->propertyOrderBy('created', 'DESC')
	  ->propertyCondition('status', NODE_PUBLISHED)
      ->propertyCondition('language', $language, '=')
      ->fieldCondition('field_company', 'target_id', $company_nid, '=')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.
   
     $result = $query->execute();

	 
    if(!empty($result)) 
	{
	  $nodes = $result['node'];
      $dataSet['solutionsPosted'] = count($nodes);
	}
	
	// Get page views;
	
	
	$ga_request = array(
	'profile_id' => '130235264',
	'dimensions' => array('ga:customVarValue4','ga:customVarValue3'),
	'metrics' => array('ga:pageviews'),
    'filters' => 'ga:customVarValue3==' . $company_nid,	
	'sort_metric' => array('-ga:pageviews'),
	'start_date' => strtotime('-30 days'),
	'end_date' => strtotime('-1 day'),
	'max_results' => 1000,
	);
	
	
	$view_res = google_analytics_reports_api_report_data($ga_request);
	$count = 0;
		
	if (!empty($view_res->results->rows)) 
	{     
      foreach ($view_res->results->rows as $row) 
	  {        
		$count = $row['pageviews'] + $count;
      }
	}
	
	/*$_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['company'] = $company_nid;
	$_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['start'] = strtotime('-30 days');
	$_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['end'] = strtotime('-1 day');*/

	
	//$view_res = views_get_view_result('google_analytics_reports', 'content');
	/*$count = 0;
    foreach($view_res as $item) {
	  $count = $item->pageviews + $count;
	} */
	
	$dataSet['totalPageviews'] = $count;
	
	
	
	header('Access-Control-Allow-Origin: https://devfm1aempdts03.amr.corp.intel.com,https://utcqcontent.cps.intel.com,https://cqpreview-ssl.intel.com, https://cqcontent.intel.com, https://www-ssl.intel.com');
	header('Access-Control-Allow-Methods: GET, POST');  	
	return $dataSet;
}

function intel_ea_web_service_services_access()
{
	return TRUE;
}
?>