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
   //return "";
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
	  else
		  return "invlaid company id 1"; 
	 
		// var_dump($company_node);
		// var_dump($company_nid);
	 
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
	 $query1 = new EntityFieldQuery();
	 
	 $query1->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'solution')
      ->propertyOrderBy('created', 'DESC')
	  ->propertyCondition('status', NODE_PUBLISHED)
      ->fieldCondition('field_company', 'target_id', $company_nid, '=')
      ->addMetaData('account', user_load(1)); // Run the query as user 1.
   
     $result1 = $query1->execute();
      $nodes = $result['node'];
	  $nodes1 = $result1['node'];
	  
      $dataSet['solutionsPosted'] = count($nodes);

      $totalPageviews = 0;

      // Determine total views for said solutions.
	  $pagePaths=array();
      foreach($nodes1 as $node)
	  {
        // Get statistics on node views for each company solution, add to total count.
        $stats = statistics_get($node->nid);
		$alias = drupal_get_path_alias('node/'.$node->nid);
		$pagePaths[]=$alias;
		
        /*
		if(!empty($stats)){
          $totalPageviews += intval($stats['totalcount']);
        }
		*/
      }

      // Add total count to dash count.
      // $dataSet['totalPageviews'] = $totalPageviews;
	}
	//print count($pagePaths);
	$dataSet['totalPageviews'] = statisticsReporting($pagePaths);
	
	header('Access-Control-Allow-Origin: https://devfm1aempdts03.amr.corp.intel.com,https://utcqcontent.cps.intel.com,https://cqpreview-ssl.intel.com, https://cqcontent.intel.com, https://www-ssl.intel.com');
	
	
	//header('Access-Control-Allow-Origin: *');
	header('Access-Control-Allow-Methods: GET, POST');  
	
	return $dataSet;
  
}

function intel_ea_web_service_services_access()
{
	return TRUE;
}

function statisticsReporting($pagePaths)
{
	/*
	For more information read this patch
	
	https://www.drupal.org/files/issues/google_analytics_reports-oauth_charts-2488754-32.patch
	
		var_dump( variable_get('google_analytics_reports_api_profile_id') );
		
		Multiple page paths
		filters=ga:pagePath==/firstURI,ga:pagePath==/secondURI
	*/
	
	/*
		array(2) {
		  [130235264]=>
		  string(32) "www.solutionsdirectory.intel.com"
		  [68641325]=>
		  string(41) "Archived - iotsolutionsalliance.intel.com"
		}
	*/
	
	$profile_id = '130235264';
	$filters="";
	
	$totalSolutionPageViews=0;
	
	foreach($pagePaths as $path)
	{
		$filters ="ga:pagePath==/".$path;
		
			$request = array(
			  'profile_id' =>$profile_id,
			  'metrics' => array('ga:pageviews'),
			  //'filters' => $filters,
			  'filters' => $filters,
			  'start_date' => strtotime('-30 days'),
			  'end_date' => strtotime('-1 day'),
			  'max_results' => 10,
			);
			
			$queryResponse = google_analytics_reports_api_report_data($request);

			$result = json_decode( $queryResponse->response->data);
			
			$pageViews = (int)$result->rows[0][0];
			
			//echo"<br>Path :: ",$filters;
			//echo"<br>PageViews :: ", $pageViews;
			
			$totalSolutionPageViews = $totalSolutionPageViews + $pageViews;
	}
	
	return $totalSolutionPageViews;
}
?>