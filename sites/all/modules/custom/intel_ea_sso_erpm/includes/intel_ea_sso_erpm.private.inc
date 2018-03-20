<?php

/**
 * @FILE: Functions that are very specific to the intel_ea_sso_erpm module
 * will be stashed here. These are not setup for general usage outside
 * of this module.
 */


/**
 * Query the provided intel ERPM  URL with proper credentials to get JSON.
 *
 * @param string $request_url
 *   A string form of the URL to hit for the values to get from ERPM.
 *
 * @return bool|mixed
 *   Returns either a JSON array of the values returned or returns FALSE if
 *   there is an issue reaching the API.
 */
function intel_ea_sso_erpm_query_api($request_url, $un, $pw){
// Query API with provided URL and API credentials.

  $result = drupal_http_request($request_url, array(
    'headers' => array(
      'Authorization' => 'Basic ' . base64_encode("$un:$pw"),
    ),
    'method' => 'GET',
    'timeout' => 360,
  ));
  // Make sure results are valid, and if so JSON decode.
  if(!isset($result->error)){
    return drupal_json_decode($result->data);
  }
  else{
    // There was an issue. Watchdog error and return FALSE.
    watchdog('intel_ea_sso_erpm', t('There was an issue querying the ERPM. This was the error: @', array('@' => $result->data)));
    return FALSE;
  }
}

/**
 * Helper function that attempts to load a node based on company ID.
 *
 * @param int $company_id
 * Company ID as stored in ERPM
 *
 * @return mixed
 *   Returns loaded node object if exist, false if not existant.
 */
function intel_ea_sso_erpm_load_company_by_erpm_id($company_id) {
  // Perform entity field query to find a company with corresponding company ID.
  $query = new EntityFieldQuery();
  $query->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'company')
    ->fieldCondition('field_erpm_company_number', 'value', trim($company_id), '=');

  // Get results.
  $result = $query->execute();

  // If the results aren't empty, return loaded node object.
  if(!empty($result)) {
     return node_load(key($result['node']));
  }
  else{
    // No results, no value match in DB.
    return FALSE;
  }

}

/**
 * Helper function to get import companies confirmation form.
 */
function intel_ea_sso_erpm_import_companies_batch_form(){
  return confirm_form(
    array(),
    t('Import all companies from ERPM.'),
    'admin/config/people/simplesamlphp_auth',
    t('Do a fresh import and/or update of all companies from the ERPM database. WARNING: This process can be time consuming and resource intensive.')
  );
}

/**
 * Submission handler for the companies batch process form.
 */
 
function intel_ea_sso_erpm_import_companies_batch_form_submit(){
  // Check that SSO/ERPM is enabled.
  

  if(variable_get('intel_ea_sso_erpm_enabled', FALSE)){
    // Attempt to load companies
	  

   if($companies_data = intel_ea_sso_erpm_get_companies(FALSE)){
    //if($companies_data = intel_ea_sso_erpm_get_companies(TRUE)){

      // Populate batch process company import
      $batch = array(
        'operations' => array(
          array('intel_ea_sso_erpm_import_companies_batch_process', array($companies_data)),
        ),
        'title' => t('Processing ERPM Companies Import'),
        'init_message' => t('Beginning company import from ERPM.'),
        'progress_message' => t('Processed @current out of @total from ERPM.'),
        'error_message' => t('ERPM batch process has encountered an error.'),
      );
      batch_set($batch);
    }
    else{
      // Output text message for error, and output watchdog error to log.
      drupal_set_message(t('ERPM batch import failed. Fetching company data failed.'), 'error');
      watchdog('intel_ea_sso_erpm', t('ERPM batch import failed. Fetching company data failed.'), NULL, WATCHDOG_ERROR);

    }
  }
}

/**
 * Batch process function as called by batch initialization.
 *
 * @param array $company_data
 *   Values as returned from ERPM.
 * @param array $context
 *   Value stored in each segment of the batch process.
 */
function intel_ea_sso_erpm_import_companies_batch_process($company_data, &$context){

  // Check for values intialization, initialize if new.
  if(!isset($context['sandbox']['max'])){
    $context['sandbox']['progress'] = 0;
    $context['sandbox']['max'] = count($company_data);
  }

  // Go through 10 companies per batch loop and either add/update values.
  for ($x = 0; $x < 4 && $context['sandbox']['progress'] < $context['sandbox']['max']; $x++) {
    intel_ea_sso_erpm_populate_company($company_data[$context['sandbox']['progress']]);
    $context['sandbox']['progress']++;
  }

  // Check progress of the batch process.
  if ($context['sandbox']['progress'] < $context['sandbox']['max']) {
    $context['finished'] = $context['sandbox']['progress'] / $context['sandbox']['max'];
  }else{
    // Output a success message.
    drupal_set_message(t('Updated or Created @ Companies.', array('@' => $context['sandbox']['progress'] )));
  }
}

/**
 * Utility function for getting the companies data from the companies endpoint.
 *
 * @param bool $use_timestamp
 *   Whether or not to pass a timestamp to the API based on last access.
 *
 * @return bool|mixed
 *   Returns data from ERPM API or false on failure.
 */
function intel_ea_sso_erpm_get_companies($use_timestamp = FALSE){


  // Set companies endpoint and param values.
  $companies_endpoint = 'https://eip-prm-denodo-proxy.cloudhub.io/companyinfo';
  $endpoint_params = '?format=json'; 

  // Check if the function call wants to use timestamp or not.
  if($use_timestamp){
    // Get last access timestamp for companies ERPM.

    $last_updated_timestamp = variable_get('intel_ea_sso_erpm_last_accessed', intval(0));

    // If this job has run before, include timestamp.
    if ($last_updated_timestamp) {
      $endpoint_params .= '&timestamp=' . $last_updated_timestamp;
      //$endpoint_params .= '&timestamp=1493596800';
    }
  }

  // UN and PW credentials for API endpoint.
  $un = intel_ea_sso_erpm_credentials_decrypt(variable_get('intel_ea_sso_erpm_companies_un'));
  $pw = intel_ea_sso_erpm_credentials_decrypt(variable_get('intel_ea_sso_erpm_companies_pw'));

  // Get data from ERPM for companies data.
  $companies_data = intel_ea_sso_erpm_query_api($companies_endpoint . $endpoint_params, $un, $pw);

  if (!empty($companies_data)) {

    // Set unix timestamp last accessed value. Subtract 5 days to be safe.
    variable_set('intel_ea_sso_erpm_last_accessed', time() - 432000);
	//variable_set('intel_ea_sso_erpm_last_accessed', time() - 15780000);
	
	

    // Return the data that was received.
    return $companies_data['elements'];
  }
  else{
    // There was an error, handle the error!
    return FALSE;
  }
}

/**
checking the erpm number

and sending back the company node

**/

function intel_ea_sso_erpm_check_erpm_id($comp_erpm_num){
	$result = db_query("SELECT DISTINCT(n.nid) AS nid FROM node n,field_data_field_erpm_company_number fecn WHERE n.type = 'company' AND n.nid=fecn.entity_id AND fecn.field_erpm_company_number_value=$comp_erpm_num");
	if (!empty($result)) {
		foreach ($result as $record) {
			$existing_comp_node_id = $record->nid;
		} 
	}
	if (isset($existing_comp_node_id)) {
		$company_node = node_load($existing_comp_node_id);
	}
return $company_node;
}


/**
 * Takes a single company of company data and populates a node from it.
 *
 * @param array $company_data
 *   Array of values for a company as returned by ERPM.
 * @param bool $cron
 *   Whether or not this was called via cron. Affects error outputitng.
 */
 
 /*Checking for any existing node having the same account no
 If it is having any node like that it will send that node back for condition checking
 
 where we are checking the result is empty or not
 
 if not empty we are updating the node */
 
function intel_ea_sso_erpm_populate_company($company_data, $cron){
  // Load company from ERPM ID.
    $company_node=intel_ea_sso_erpm_check_erpm_id($company_data['AccountNbr']);
	//echo $company_node->title;exit;
    if(!empty($company_node)){
		intel_ea_sso_erpm_update_company($company_node, $company_data, $cron);
		watchdog('intel_ea_sso_erpm', t('company found.Going for update.Company name: @', array('@' =>$company_node->title )));
	}

  else {
    // No company yet for company number, check for NID match.
    if(intval($company_data['ISAITPBusIDTxt']) > 0
      && $node = node_load(intval($company_data['ISAITPBusIDTxt']))) {
	   watchdog('intel_ea_sso_erpm', t('checking for the ISAITPBusIDTxt. @', array('@' =>$node->title )));
		watchdog('intel_ea_sso_erpm', t('checking for the ISAITPBusIDTxt.Cron status: @', array('@' =>$cron )));
      intel_ea_sso_erpm_update_company($node, $company_data, $cron);
    }
    else { // No Company ID match, nor NID match, create new company.
	  // If undetermined tier then company is rejected. Dont add to SD.
	  watchdog('intel_ea_sso_erpm', t('ID , NID not matching. So creating company.'));
		watchdog('intel_ea_sso_erpm', t('ID , NID not matching. So creating company.Cron status: @', array('@' =>$cron )));
      if(trim($company_data['TierTxt']) != 'UNDETERMND') {
        // Populate basic node values
        $node = new stdClass();
        $node->title = $company_data['CompanyNm'];
        $node->type = "company";

        //  Do basic preparations on the node.
        node_object_prepare($node);

        // Set some further basic values.
        $node->language = 'en';
        $node->status = 0;
        $node->revision = 1;

        // Add the account number value to the node.
        $node->field_erpm_company_number[LANGUAGE_NONE][]['value'] = trim($company_data['AccountNbr']);

        // Populate fields values.
        intel_ea_sso_erpm_populate_company_node_fields($node, $company_data, $cron);

        // Submit and save the node.
        $node = node_submit($node);
        node_save($node);
		watchdog('intel_ea_sso_erpm', t('new company created. Company name: @', array('@' =>$node->title )));
		watchdog('intel_ea_sso_erpm', t('new company created.Cron status: @', array('@' =>$cron )));
      }		
    }
  }
}

/**
 * Helper function to update any already populated company nodes.
 *
 * @param object $company_node
 *   Fully loaded company node object.
 *
 * @param array $company_data
 *   Array of values as passed from ERPM.
 *
 * @param bool $cron
 *   Determines whether called from cron, as it will affect error output.
 */
function intel_ea_sso_erpm_update_company($company_node, $company_data, $cron){
  // Update title if necessary.
  $company_node->title = $company_data['CompanyNm'];

  // Populate fields values.
  intel_ea_sso_erpm_populate_company_node_fields($company_node, $company_data, $cron);

  // Save the node
  node_save($company_node);
}

/**
 * Helper function for populating field values on company data.
 *
 * @param object $company_node
 *   Fully loaded company node object (All objects passed by reference)
 *
 * @param array $company_data
 *   Array of values as passed from ERPM.
 *
 * @param bool $cron
 *   Determines whether called from cron, as it will affect error output.
 */
function intel_ea_sso_erpm_populate_company_node_fields($company_node, $company_data, $cron){
  // Populate the body content if it is not NULL IE: '*'
  // @TODO: Requested removed per 9/8 meeting until ERPM description field sorted.
  //  if($company_data['ISACompanyDsc'] != '*'){
  //    $company_node->body[LANGUAGE_NONE][0]= array(
  //      'value' => $company_data['ISACompanyDsc'],
  //      'summary' => text_summary($company_data['ISACompanyDsc']),
  //      'format' => 'plain_text'
  //    );
  //  }

  // Populate the address field.
  $company_node->field_address[LANGUAGE_NONE][0] = array(
    'organisation_name' => $company_data['CompanyNm'],
    'country' => strtoupper($company_data['CountryCd']),
    'thoroughfare' => $company_data['AddressLine1Txt'],
    'premise' => $company_data['AddressLine2Txt'],
    'locality' => $company_data['CityNm'],
    'administrative_area' => $company_data['CountrySubdivisionCd'],
    'postal_code' => $company_data['PostalCd'],
  );

  // Clear membership tier for company, set ISA & ITP parent values.
  unset($company_node->field_membership_tier[LANGUAGE_NONE]);
  $isa_parent_tid = key(taxonomy_get_term_by_name('Intel® IoT Solutions Alliance', 'membership_tier'));
  $itp_parent_tid = key(taxonomy_get_term_by_name('Intel® Technology Provider', 'membership_tier'));

  // Clean up company data tier value.
  $company_data['TierTxt'] = strtolower(trim($company_data['TierTxt']));

  // Assign membership tier of the company.
  switch($company_data['TierTxt']){
    case 'premier':
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $isa_parent_tid;
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Premier', 'membership_tier'));
      break;
    case 'associate':
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $isa_parent_tid;
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Associate', 'membership_tier'));
      break;
    case 'affiliate':
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $isa_parent_tid;
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Affiliate', 'membership_tier'));
      break;
    case 'general':
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $isa_parent_tid;
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('General', 'membership_tier'));
      break;
	// Added to pull in ITP companies as well from ERPM.  
    case 'registered':
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $itp_parent_tid;
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Registered', 'membership_tier'));
      break; 
    case 'gold':
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $itp_parent_tid;
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Gold', 'membership_tier'));
      break; 
    case 'platinum':
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $itp_parent_tid;
      $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Platinum', 'membership_tier'));
      break;  
    case 'undetermnd':
      // This actually means the company should be unpublished!
      $company_node->status = 0;
      break;

    // No match, report an error.
    default:
      if($cron){
        watchdog('intel_ea_sso_erpm', t('There was an issue updating company NID @, membership level % unknown.',array('@' => $company_node->nid, '%' => $company_data['TierTxt'])), NULL, WATCHDOG_ERROR);
      }else{
        drupal_set_message(t('There was an issue updating company NID @, membership level % unknown.',array('@' => $company_node->nid, '%' => $company_data['TierTxt'])));
      }
      break;
  }

  // Populate the company website.
  $company_node->field_website[LANGUAGE_NONE][0]['url'] = $company_data['WebSiteNm'];

  // field_geographic_coverage mappings.
  unset($company_node->field_geographic_coverage[LANGUAGE_NONE]);
  if($company_data['ISAGeoCoverageNARInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 564;}
  if($company_data['ISAGeoCoverageLSAInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 563;}
  if($company_data['ISAGeoCoverageANZInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 565;}
  if($company_data['ISAGeoCoverageSWAInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 569;}
  if($company_data['ISAGeoCoverageAMEInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 571;}
  if($company_data['ISAGeoCoverageJapanInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 573;}
  if($company_data['ISAGeoCoverageTaiwanInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 570;}
  if($company_data['ISAGeoCoverageKoreaInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 567;}
  if($company_data['ISAGeoCoverageEuropeInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 572;}
  if($company_data['ISAGeoCoverageSEAInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 568;}
  if($company_data['ISAGeoCoverageChinaInd'] == 'Y'){$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 566;}

  // field_geographic_region
  unset($company_node->field_geographic_region[LANGUAGE_NONE]);
  if($company_data['ISAGeoRegionNARInd'] == 'Y'){$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 592;}
  if($company_data['ISAGeoRegionSAMRInd'] == 'Y'){$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 593;}
  if($company_data['ISAGeoRegionMiddleEastInd'] == 'Y'){$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 598;}
  if($company_data['ISAGeoRegionChinaInd'] == 'Y'){$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 966;}
  if($company_data['ISAGeoRegionEuropeInd'] == 'Y'){$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 594;}
  if($company_data['ISAGeoRegionAfricaInd'] == 'Y'){$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 597;}
  if($company_data['ISAGeoRegionAsiaInd'] == 'Y'){$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 595;}
  if($company_data['ISAGeoRegionAustraliaInd'] == 'Y'){$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 596;}
}

/**
 * Function to get ERPM api user data. Can take either a UID or full user object.
 *
 * @param mixed $user
 *   Provided as either a wrapped user or a UID.
 *
 * @return bool
 *   Returns FALSE if an incorrect value was passed.
 */
function intel_ea_sso_erpm_get_erpm_user_data($user){
  // Attempt to load wrapped user if INT passed, if not int check if object.
  if(is_int($user)){
    $user = entity_metadata_wrapper('user', user_load($user));
  }elseif(!is_object($user)){
    watchdog('intel_ea_sso_erpm', t('ERPM get user data passed neither an INT or a wrapped user.'), NULL, WATCHDOG_ERROR);
    return FALSE;
  }

  // Get user email for ERPM lookup.
  $email = $user->mail->value();
  
  // checking for intel users
  
  $domains = array('intel.com');
  $pattern = "/^[a-z0-9._%+-]+@[a-z0-9.-]*(" . implode('|', $domains) . ")$/i";
  if (preg_match($pattern, $email) !== 0) {
        $user_type = 'INTEL_ONLY_USER';
		
/* Giving intel employee role to users having intel.com in their mail */
		
		 // Make sure user has intel employee role.

		 $intel_employee = user_role_load_by_name('Intel Employee');

                          // If the user doesn't have intel employee role, add it now.
                          if(!in_array($intel_employee->rid, $user->roles->value())){

                                $user->roles[] = $intel_employee->rid;
                        
								$user->save();

                          }

  } else {
        $user_type = 'LOGGED_IN_USER';
        } 
		
	  //Get login id for ERPM lookup
  
  $login_id = $user->field_erpm_login_id->value();
  //echo $login_id;exit;
  
  //if intel user appending mad in login id
  
  if($user_type == 'INTEL_ONLY_USER'){
	 
	$login_id = "mad\\".$login_id;
	
  }
  
    /*if($email!=$login_id){
	  
	  $json_param =$login_id;
	 
  } */
  
  

  // Endpoint URL construction.
  $user_endpoint = 'https://crpmws-rest.intel.com/erpm-r-ws/Common.svc/GetAttributesJson';
  $endpoint_params = '?loginId=' . $login_id. '&clientName=test&enggCode=ITP&attribute=USERCOREPROFILE,USERENGAGEMENTS,USERCONTACTINFO,ACCOUNTPROFILE,ACCOUNTCONTACTINFO';

  // Get stored encrypted ERPM credentials.
  /*$un = intel_ea_sso_erpm_credentials_decrypt(variable_get('intel_ea_sso_erpm_people_un'));
  $pw = intel_ea_sso_erpm_credentials_decrypt(variable_get('intel_ea_sso_erpm_people_pw'));*/

  $un = 'ED\sys_prmerpmuser';
  $pw = 'dredaqEtu2uVaf8u';
  // Get users data from the ERPM.
  $user_data = intel_ea_sso_erpm_query_api($user_endpoint . $endpoint_params, $un, $pw);
  
  //echo '<pre>'; print_r($user_data);exit;

  // If the user data is not Null, sync data on user profile.
  if(!empty($user_data) && is_object($user)) {
    intel_ea_sso_erpm_user_profile_sync($user_data, $user);
  }
  else{
    // User is null. Error handling may be desired.
    // Current functionality is site informs user they are not associated with any company, contact admin.
    // @TODO: Add error handling as there is something wrong bringing us here.
  }
}

/**
 * Helper function to take provided user data and map a user.
 *
 * @param array $user_data
 *   User data as returned from the ERPM api.
 *
 * @param object $wrapped_user
 *   Entity metadata wrapped user object.
 */
/*function intel_ea_sso_erpm_user_profile_sync($user_data, $wrapped_user){
  // @TODO: Set user language based on user value.
  // $user_data['Person']['UserDetail']['LanguageCode']);
  // $drupal_languages = language_list();
  //$wrapped_user->language->set();

  // Associate user with a company if company association is passed in details.
  if(isset($user_data['Person']['Accounts']['Account']['AccountDetail']['AccountNumber'])){
    if($company_nid = intel_ea_sso_erpm_load_company_by_erpm_id($user_data['Person']['Accounts']['Account']['AccountDetail']['AccountNumber'])){
      $wrapped_user->field_company->set($company_nid);
    }
  }else{
    // @TODO: Add handling here if this is a situation that should never exist in production environment.
  }

  // Set the users job title.
  $wrapped_user->field_title->set($user_data['Person']['UserDetail']['JobFunction']);

  // Load solutions directory editor role for adding/removing to users.
  $solutions_directory_editor = user_role_load_by_name('Solutions Directory Editor');
  // Create boolean based on user having solutions directory editor role or not.
  $user_is_currently_solutions_editor = in_array($solutions_directory_editor->rid, $wrapped_user->roles->value());

  // Check if ERPM user data even exists and has roles.
  if(isset($user_data['Person']['Accounts']['Account']['Relationships']['Relationship'])){
    $erpm_should_be_solutions_editor = intel_ea_sso_erpm_is_user_solutions_editor($user_data['Person']['Accounts']['Account']['Relationships']['Relationship']);
    // Check if user should have role.
    if ($erpm_should_be_solutions_editor) {
      // Check that user doesn't already have the role, if so add it.
      if(!$user_is_currently_solutions_editor){
        $wrapped_user->roles[] = $solutions_directory_editor->rid;
      }
      // No else, user only gets here if they have role and should have role.
    }
    else{
      // User shouldn't have the role, and if they have it remove it.
      if(in_array($solutions_directory_editor->rid, $wrapped_user->roles->value())){
        // Get array key of solutions director RID value and unset.
        $solutions_editor_rid_key = array_search ($solutions_directory_editor->rid, $wrapped_user->roles->value());
        unset($wrapped_user->roles[$solutions_editor_rid_key]);
      }
    }
  }else{
    // User shouldn't have the role due to no relationship at all, and if they have it remove it.
    if($user_is_currently_solutions_editor){
      // Get array key of solutions director RID value and unset.
      $solutions_editor_rid_key = array_search ($solutions_directory_editor->rid, $wrapped_user->roles->value());
      unset($wrapped_user->roles[$solutions_editor_rid_key]);
    }
  }


  // Save the wrapped user.
  $wrapped_user->save();
} */
function intel_ea_sso_erpm_user_profile_sync($user_data, $wrapped_user){
  // @TODO: Set user language based on user value.
  // $user_data['Person']['UserDetail']['LanguageCode']);
  // $drupal_languages = language_list();
  //$wrapped_user->language->set();

  // Set the user phone number.
  $phone_flag = $user_data['Person']['PersonElectronicAdresses']['PersonElectronicAdress']['ElectronicAddressType'];
  $phone_no = $user_data['Person']['PersonElectronicAdresses']['PersonElectronicAdress']['ElectronicAddressText'];
  if (isset($phone_flag) && $phone_flag = "PHONE") {
	  if (isset($phone_no)) {
	  $wrapped_user->field_work_phone->set($phone_no);
	  }
  }
 // Set the user job title
  $job_title = $user_data['Person']['UserDetail']['JobFunction'];
  if (isset($job_title)) {
	$wrapped_user->field_title->set($job_title);
  }
  // Set the user company role
  $company_role_id = key(taxonomy_get_term_by_name($user_data['Person']['UserDetail']['JobFunction']));
  if (isset($company_role_id)) {
	$company_role = entity_metadata_wrapper('taxonomy_term', $company_role_id);
	if (!empty($company_role)) {
			$wrapped_user->field_company_role[0] = $company_role->tid->value();
	  }
  }
  // Set Associate user with correct company.
  $company_node[] = intel_ea_sso_erpm_load_company_by_erpm_id($user_data['Person']['Accounts']['Account']['AccountDetail']['AccountNumber']);
  if (!empty($company_node)) {
	  $company_node_id = $company_node[0]->nid;
	  if (isset($company_node_id)) {
		  $wrapped_user->field_company = $company_node_id;
	  }
  }
  watchdog('intel_ea_sso_erpm', t('User details fetched from ERPM to SD'), NULL, WATCHDOG_INFO);
  // Set User status
  
  $wrapped_user->status->set('1');
  /*$erpm_status = $user_data['Person']['UserDetail']['UserStatus'];
  if (isset($erpm_status) && $erpm_status = "A") {
	$wrapped_user->status->set('1');
  } else {
	$wrapped_user->status->set('0');
  }*/
  //$wrapped_user->field_company->set(intel_ea_sso_erpm_load_company_by_erpm_id($user_data['Person']['Accounts']['Account']['AccountDetail']['AccountNumber']));
  $role_assigned = 'No';
  // Check for account membership if its ISA.
  $erpm_user_accounts = $user_data['Person']['Accounts']['Account'];
   if(!isset($erpm_user_accounts['0'])) {
     $users_accounts_data[0] = $erpm_user_accounts;
   }
   else {
     $users_accounts_data = $erpm_user_accounts;
  }

  foreach($users_accounts_data as $user_account_data) {
    if($role_assigned == 'No') {
      // Check user roles from erpm.
      $user_roles = array();
      $erpm_user_role = $user_account_data['Relationships']['Relationship'];
      if(!isset($erpm_user_role[0])) {
        $user_roles[0] = $erpm_user_role;
      }
      else {
        $user_roles = $erpm_user_role;
      }
	 $user_memberships = array();
	  $memberships = $user_account_data['AccountMemberships']['AccountMembership'];
	  if(!isset($memberships[0])){
		  //watchdog('intel_ea_sso_erpm', t('mulitple array if isset'), NULL, WATCHDOG_INFO);
		  $user_memberships[0] = $memberships;
	  }
	  else {
		  //watchdog('intel_ea_sso_erpm', t('single array else isset'), NULL, WATCHDOG_INFO);
		  $user_memberships = $memberships;
	  }
      foreach($user_memberships as $membership) {
		  //watchdog('intel_ea_sso_erpm', t('for each'), NULL, WATCHDOG_INFO);
        if($membership['EngagementCode'] == 'ISA' || $membership['EngagementCode'] == 'ITP' || $membership['EngagementCode'] == 'ODM-LOEM') {
          // Associate user with correct company.
		  //watchdog('intel_ea_sso_erpm', t('inside if , engagement code check'), NULL, WATCHDOG_INFO);
          //$wrapped_user->field_company->set(intel_ea_sso_erpm_load_company_by_erpm_id($user_account_data['AccountDetail']['AccountNumber']));
		  
          if(isset($user_roles) && !empty($user_roles)) {
			  //watchdog('intel_ea_sso_erpm', t('inside if  , user_roles'), NULL, WATCHDOG_INFO);
            foreach($user_roles as $user_role) {
				//watchdog('intel_ea_sso_erpm', t('inside if , user_role'), NULL, WATCHDOG_INFO);
              if($user_role['RelationshipCode'] == 'RELTNSLNED') {
				  //watchdog('intel_ea_sso_erpm', t('inside if , relationship code check'), NULL, WATCHDOG_INFO);
                // Make sure user has solutions directory editor role.
                $solutions_directory_editor = user_role_load_by_name('Solutions Directory Editor');
                // If the user doesn't have solutions directory editor role, add it now.
                if(!in_array($solutions_directory_editor->rid, $wrapped_user->roles->value())){
                  $wrapped_user->roles[] = $solutions_directory_editor->rid;
                  $role_assigned = 'Yes';
                }
              }
            }
          }
        }
	  }
    }
  }

  // Save the wrapped user.
  $wrapped_user->save();
}

/**
 * Helper function for comparing countries from intel to Drupal values.
 *
 * @return bool
 *   Returns FALSE if DEVEL is not enabled.
 */
function intel_ea_sso_erpm_country_code_compare(){
  // Check if DEVEL is enabled as it is needed for this.
  if(module_exists('devel')){

    // Load drupal countries list for comparison.
    $drupal_countries = country_get_list();

    // Initialize Intel codes array.
    $intel_geo_codes = array();

    // Load intel GEO codes CSV file, parse into array.
    $filename = DRUPAL_ROOT . '/' . drupal_get_path('module', 'intel_ea_sso_erpm') . '/test_values/intel-geo-codes.csv';
    $handle = fopen($filename, "r");
    if ($handle) {
      while (($row = fgetcsv($handle, filesize($filename))) !== false) {
        $intel_geo_codes[$row[0]] = $row[1];
      }
      fclose($handle);
    }

    // Compute array differences.
    $intel_unique_values = array_diff($intel_geo_codes, $drupal_countries);
    $drupal_different_values = array_diff($drupal_countries, $intel_geo_codes);

    dpm($intel_unique_values);
    dpm($drupal_different_values);
  }
  else{
    // @TODO: Add error handling if desired. This is probably not needed.
    return FALSE;
  }
}

/**
 * Helper function to encrypt ERPM credentials.
 *
 * @param string $value
 *   Accepts a string for hashing and storing to the DB.
 * @return string
 *   Returns a hashed string.
 */
function intel_ea_sso_erpm_credentials_encrypt($value){
  if($encryption_salt = variable_get('intel_ea_sso_erpm_credentials_salt', FALSE)){
    return openssl_encrypt($value, 'AES-256-OFB', variable_get('intel_ea_sso_erpm_credentials_salt'));
  }
  else{
    // @TODO: Error handling may be useful.
    return FALSE;
  }

}

/**
 * Helper function to decrypt ERPM credentials.
 *
 * @param string $value
 *   Accepts a hashed string for unhashing and storing to the DB.
 * @return string
 *   Returns unhashed string.
 */
function intel_ea_sso_erpm_credentials_decrypt($value){
  // Make sure an encryption salt is even available.
  if($encryption_salt = variable_get('intel_ea_sso_erpm_credentials_salt', FALSE)){
    return openssl_decrypt($value, 'AES-256-OFB', variable_get('intel_ea_sso_erpm_credentials_salt'));
  }
  else{
    // @TODO: Error handling may be useful.
    return FALSE;
  }
}

/**
 * Helper function to determine if user data from ERPM indicates should be a solutions editor.
 * @param array $user_relationships
 *   Pass all of the user relationships from the ERPM values.
 *
 * @return bool
 *   TRUE if should be solutions editor, FALSE if not.
 */
function intel_ea_sso_erpm_is_user_solutions_editor($user_relationships){
  foreach($user_relationships as $relationship){
    if(in_array('RELTNSLNED', $relationship)){
      return TRUE;
    }
  }
  return FALSE;
}
