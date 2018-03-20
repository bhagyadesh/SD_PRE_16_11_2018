<?php
// intel_ea_web_service.inc

/**
 * Callback for retrieving note resources.
 *
 * @param int $id
 * @return object
 */
function get_erpm_user_details($userid) {
	watchdog('intel_erpm_web_service', t('ERPM user function triggered. user name: @', array('@' =>$userid['UserInfo']['Login_Id'] )));
	$loginid = $userid['UserInfo']['Login_Id'];
	$header = getallheaders();
	if($header['Authorization'] == "Basic c2VydmljZTpQQDU1d29yZA=="){
		/* pre ERPM */
		$user_endpoint = 'https://crpmws-rest.intel.com/erpm-r-ws/Common.svc/GetAttributesJson';
		$endpoint_params = '?loginId=' . $loginid. '&clientName=test&enggCode=ITP&attribute=USERCOREPROFILE,USERENGAGEMENTS,USERCONTACTINFO,ACCOUNTPROFILE,ACCOUNTCONTACTINFO';
		/*$un = 'ED\crpm_test';
		$pw = 'sX)&*#TvN!LqubuB';*/
		$un = 'ED\sys_prmerpmuser';
		$pw = 'dredaqEtu2uVaf8u';
		/* FMT0 ERPM */
		/*$user_endpoint = 'https://fmt0cpmngws.cps.intel.com/erpm-r-ws/Common.svc/GetAttributesJson';
		$endpoint_params = '?loginId=' . $loginid. '&clientName=test&enggCode=ITP&attribute=USERCOREPROFILE,USERENGAGEMENTS,USERCONTACTINFO,ACCOUNTPROFILE,ACCOUNTCONTACTINFO';
		$un = 'ED\crpm_test';
		$pw = 'sX)&*#TvN!LqubuB';*/
		$user_data = get_user_ERPM_query($user_endpoint . $endpoint_params, $un, $pw);
		//echo '<pre>';print_r($user_data);exit;
		if (!empty($user_data['Person'])) {
			$loginid = $user_data['Person']['UserDetail']['LoginID'];
			$emailid = $user_data['Person']['UserDetail']['EmailID'];
			$userids = db_query("select distinct entity_id from field_data_field_erpm_login_id where entity_type = 'user'and field_erpm_login_id_value = '$loginid'")->fetchCol();
			$userid = $userids[0];
			$emails = db_query("select distinct uid from users WHERE name = '$emailid'")->fetchCol();
			$email = $emails[0];
			if (isset($userid)) {
				$userobj = user_load($userid);
				$wrapped_user = entity_metadata_wrapper('user', $userobj);
				populate_user_details($wrapped_user,$user_data);
				echo 'user updated with login id!';
				watchdog('intel_erpm_web_service', t('user updated with login id. user name: @', array('@' =>$user_data['Person']['UserDetail']['LoginID'] )));
			} else {
				if (isset($email)) {
					$userobj = user_load($email);
					$wrapped_user = entity_metadata_wrapper('user', $email);
					populate_user_details($wrapped_user,$user_data);
					echo 'user updated with email id!';
					watchdog('intel_erpm_web_service', t('user updated with email id. user name: @', array('@' =>$user_data['Person']['UserDetail']['LoginID'] )));
				}
				$wrapped_user = entity_create('user', array());
				$wrapped_user = entity_metadata_wrapper('user', $wrapped_user);
				populate_user_details($wrapped_user,$user_data);
				echo 'user created!';
				watchdog('intel_erpm_web_service', t('user created. user name: @', array('@' =>$user_data['Person']['UserDetail']['LoginID'] )));
			}
		} else {
			echo 'user not found in ERPM';
			watchdog('intel_erpm_web_service', t('user not found in ERPM, Loginid : @', array('@' =>$loginid)));
		}
	} else {
		echo 'Authentication required for user update!';
		watchdog('intel_erpm_web_service', t('Authentication required!'));
	}
}
function get_user_ERPM_query($request_url, $un, $pw) {
	$result = drupal_http_request($request_url, array(
    'headers' => array(
      'Authorization' => 'Basic ' . base64_encode("$un:$pw"),
    ),
    'method' => 'GET',
    'timeout' => 360,
	));
	$user_data = drupal_json_decode($result->data);
    return $user_data;
}
function update_erpm_company_details($company_data) {
	//echo '<pre>';print_r($company_data);exit;
	watchdog('intel_erpm_web_service', t('ERPM company function triggered. company id: @', array('@' =>$company_data['org_acct_nbr'] )));
	$header = getallheaders();
	if($header['Authorization'] == "Basic c2VydmljZTpQQDU1d29yZA=="){
		$erpm_id = $company_data['org_acct_nbr'];
		$company_node = get_company_from_erpm_id($erpm_id);
		if (!empty($company_node)) {
			update_company_details($company_node,$company_data);
			echo 'company details updated';
		} else {
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
			$node->field_erpm_company_number[LANGUAGE_NONE][]['value'] = trim($company_data['org_acct_nbr']);

			// Populate fields values.
			populate_company_node_fields($node, $company_data);

			// Submit and save the node.
			$node = node_submit($node);
			node_save($node);
			watchdog('intel_erpm_web_service', t('new company created. Company name: @', array('@' =>$node->title )));
			echo 'company details added';
		}
	} else {
		echo 'Authentication Required for company update!';
		watchdog('intel_erpm_web_service', t('Authentication required!'));
	}
}
function intel_erpm_web_service_services_access()
{
	return TRUE;
}
function populate_user_details($wrapped_user,$user_data) {
	//echo 'user_data<pre>';print_r($user_data);
	$wrapped_user->field_first_name->set($user_data['Person']['UserDetail']['FirstName']);
    $wrapped_user->field_last_name->set($user_data['Person']['UserDetail']['LastName']);
    $wrapped_user->field_sso_enterprise_id->set($user_data['Person']['UserDetail']['EnterpriseID']);
	$wrapped_user->field_erpm_login_id->set($user_data['Person']['UserDetail']['LoginID']);
	$wrapped_user->name = $user_data['Person']['UserDetail']['EmailID'];
	$wrapped_user->mail = $user_data['Person']['UserDetail']['EmailID'];
	$user_contact_details = $user_data['Person']['PersonElectronicAdresses']['PersonElectronicAdress'];
	if(!isset($user_contact_details['0'])) {
     $user_phone_details[0] = $user_contact_details;
    }
    else {
     $user_phone_details = $user_contact_details;
    }
	foreach ($user_phone_details as $user_phone_detail) {
		$phone_flag = $user_phone_detail['ElectronicAddressType'];
		$phone_no = $user_phone_detail['ElectronicAddressText'];
		if (isset($phone_flag) && $phone_flag = "PHONE") {
			if (isset($phone_no)) {
				$wrapped_user->field_work_phone->set($phone_no);
			}
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
	$company_node[] = get_company_from_erpm_id($user_data['Person']['Accounts']['Account']['AccountDetail']['AccountNumber']);
	if (!empty($company_node)) {
	  $company_node_id = $company_node[0]->nid;
	  if (isset($company_node_id)) {
		  $wrapped_user->field_company = $company_node_id;
	  }
    }
	$erpm_user_accounts = $user_data['Person']['Accounts']['Account'];
	if(!isset($erpm_user_accounts['0'])) {
     $users_accounts_data[0] = $erpm_user_accounts;
    }
    else {
     $users_accounts_data = $erpm_user_accounts;
    }
	
	foreach($users_accounts_data as $user_account_data) {
	  $memberships = $user_account_data['AccountMemberships']['AccountMembership'];
	  if(!isset($memberships['0'])) {
     $user_memberships[0] = $memberships;
    }
    else {
     $user_memberships = $memberships;
    }
	  foreach($user_memberships as $membership) {
		  $itp_role = array();
        if($membership['EngagementCode'] == 'ITP') {
			$eng_type[] = 'ITP';
			$itp_user_roles = $user_account_data['Relationships']['Relationship'];
			foreach ($itp_user_roles as $itp_user_role) {
			  $itp_role[] = $itp_user_role['RelationshipCode'];
		    }
		}
		$isa_role = array();
		if ($membership['EngagementCode'] == 'ISA') {
		  $eng_type[] = 'ISA';
		  $author_id = $user_data['Person']['UserDetail']['LoginID'];
	      $user_endpoint = 'https://crpmws-rest.intel.com/erpm-r-ws/Common.svc/GetAttributesJson';
	      $endpoint_params = '?loginId=' . $author_id. '&clientName=test&enggCode=ISA&attribute=USERPROFILE,USERCOREPROFILE,USERENGAGEMENTS,USERCONTACTINFO,USERRESPONSE,ACCOUNTPROFILE,ACCOUNTCOREPROFILE,ACCOUNTENGAGEMENTS,ACCOUNTCONTACTINFO,ACCOUNTRESPONSES,ACCOUNTBENEFITINFO';
	      $un = 'ED\crpm_test';
	      $pw = 'sX)&*#TvN!LqubuB';
	      $isa_user_data = intel_ea_sso_erpm_query_api($user_endpoint . $endpoint_params, $un, $pw);
	      $isa_user_roles = $isa_user_data['Person']['Accounts']['Account']['Relationships']['Relationship'];
		  foreach ($isa_user_roles as $isa_user_role) {
			  $isa_role[] = $isa_user_role['RelationshipCode'];
		  }
		}
		$odm_role = array();
        if($membership['EngagementCode'] == 'ODM-LOEM') {
		  $eng_type[] = 'ODM-LOEM';
		  $author_id = $user_data['Person']['UserDetail']['LoginID'];
	      $user_endpoint = 'https://crpmws-rest.intel.com/erpm-r-ws/Common.svc/GetAttributesJson';
	      $endpoint_params = '?loginId=' . $author_id. '&clientName=test&enggCode=ODM-LOEM&attribute=USERPROFILE,USERCOREPROFILE,USERENGAGEMENTS,USERCONTACTINFO,USERRESPONSE,ACCOUNTPROFILE,ACCOUNTCOREPROFILE,ACCOUNTENGAGEMENTS,ACCOUNTCONTACTINFO,ACCOUNTRESPONSES,ACCOUNTBENEFITINFO';
	      $un = 'ED\crpm_test';
	      $pw = 'sX)&*#TvN!LqubuB';
	      $odm_user_data = intel_ea_sso_erpm_query_api($user_endpoint . $endpoint_params, $un, $pw);
	      $odm_user_roles = $odm_user_data['Person']['Accounts']['Account']['Relationships']['Relationship'];
		  foreach ($odm_user_roles as $odm_user_role) {
			  $odm_role[] = $odm_user_role['RelationshipCode'];
		  }
		}			
	  }
	  $final_roles = array_unique(array_filter(array_merge(($itp_role),($isa_role),($odm_role))));
	  foreach($final_roles as $final_role) {
        if($final_role == 'RELTNSLNED') {
          // Make sure user has solutions directory editor role.
          $solutions_directory_editor = user_role_load_by_name('Solutions Directory Editor');
          // If the user doesn't have solutions directory editor role, add it now.
          if(!in_array($solutions_directory_editor->rid, $wrapped_user->roles->value())){
            $wrapped_user->roles[] = $solutions_directory_editor->rid;
		  }
		}
		if($final_role == 'RELTNWRKFR') {
          // Make sure user has solutions directory editor role.
          $employee = user_role_load_by_name('Employee');
          // If the user doesn't have solutions directory editor role, add it now.
          if(!in_array($employee->rid, $wrapped_user->roles->value())){
            $wrapped_user->roles[] = $employee->rid;
		  }
		}
	  }
	  //$wrapped_user->field_engagement_type = $eng_type;
	}
	$wrapped_user->save();
	//echo '<pre>';print_r($wrapped_user);
}
function update_company_details($company_node, $company_data){
  // Update title if necessary.
  $company_node->title = $company_data['CompanyNm'];
  $company_node->field_partner_role[LANGUAGE_NONE] = array();
  $company_node->field_client_fae[LANGUAGE_NONE] = array();
  $company_node->field_server_fae[LANGUAGE_NONE] = array();
  $company_node->field_eiot_fae[LANGUAGE_NONE] = array();
  $company_node->field_client_fse[LANGUAGE_NONE] = array();
  $company_node->field_server_fse[LANGUAGE_NONE] = array();
  $company_node->field_eiot_fse[LANGUAGE_NONE] = array();
  $company_node->field_geographic_region[LANGUAGE_NONE] = array();
  $company_node->field_geographic_coverage[LANGUAGE_NONE] = array();
  $company_node->field_membership_tier[LANGUAGE_NONE] = array();

  // Populate fields values.
  populate_company_node_fields($company_node, $company_data);

  // Save the node
  node_save($company_node);
  watchdog('intel_erpm_web_service', t('company updated. Company name: @', array('@' =>$company_node->title )));
}
function populate_company_node_fields($company_node, $company_data) {
	//echo 'company_data<pre>';print_r($company_data);
	//echo 'company_node<pre>';print_r($company_node);
	
	// Populate the address field.
  $company_node->field_address[LANGUAGE_NONE][0] = array(
    'organisation_name' => $company_data['CompanyNm'],
    'country' => strtoupper($company_data['CountryCd']),
    'thoroughfare' => $company_data['Addr_line1'],
    'premise' => $company_data['Addr_line2'],
    'locality' => $company_data['City_Nm'],
    'administrative_area' => $company_data['CountrySubdivisionCd'],
    'postal_code' => $company_data['post_cd'],
  );
  
  // Populate the company website.
  $company_node->field_website[LANGUAGE_NONE][0]['url'] = $company_data['WebSiteNm'];
  /* Membership Tier */
  unset($company_node->field_membership_tier[LANGUAGE_NONE]);
  $isa_parent_tid = key(taxonomy_get_term_by_name('Intel® IoT Solutions Alliance', 'membership_tier'));
  $itp_parent_tid = key(taxonomy_get_term_by_name('Intel® Technology Provider', 'membership_tier'));
  $odm_parent_tid = key(taxonomy_get_term_by_name('ODM-LOEM', 'membership_tier'));
  foreach ($company_data['Engagements'] as $engagement) {
	  /* Membership tier for ISA */
	  if ($engagement['engg-code'] == 'ISA') {
		  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $isa_parent_tid;
		  $engagement['tier-code'] = strtolower(trim($engagement['tier-code']));
		  switch($engagement['tier-code']){
			case 'premier':
			  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Premier', 'membership_tier'));
			  break;
			case 'associate':
			  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Associate', 'membership_tier'));
			  break;
			case 'affiliate':
			  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Affiliate', 'membership_tier'));
			  break;
			case 'general':
			  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('General', 'membership_tier'));
			  break;
			case 'undetermnd':
			  // This actually means the company should be unpublished!
			  $company_node->status = 0;
			  break;
			default:
				drupal_set_message(t('There was an issue updating company NID @, membership level % unknown.',array('@' => $company_node->nid, '%' => $engagement['tier-code'])));
				break;
		  }
	  }
	  /* Membership tier for ITP */
	  if ($engagement['engg-code'] == 'ITP') {
		  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $itp_parent_tid;
		  $engagement['tier-code'] = strtolower(trim($engagement['tier-code']));
		  switch($engagement['tier-code']){
			case 'registered':
			  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Registered', 'membership_tier'));
			  break; 
			case 'gold':
			  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Gold', 'membership_tier'));
			  break; 
			case 'platinum':
			  $company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = key(taxonomy_get_term_by_name('Platinum', 'membership_tier'));
			  break; 
			case 'undetermnd':
			  // This actually means the company should be unpublished!
			  $company_node->status = 0;
			  break;
			default:
				drupal_set_message(t('There was an issue updating company NID @, membership level % unknown.',array('@' => $company_node->nid, '%' => $engagement['tier-code'])));
				break;			  
		  }  
	  }
	  /* Membership tier for ODM */
	  if ($engagement['engg-code'] == 'ODM-LOEM') {
		$company_node->field_membership_tier[LANGUAGE_NONE][]['tid'] = $odm_parent_tid;
	  }		  
  }
  /* Geographical Region - Headquarters */
  foreach ($company_data['AccountResponses'] as $responses) {
	  /* Geographical Region - Headquarters */
	 if ($responses['question-code'] == 'ISA_Geographic_Region') {
		 switch ($responses['response-value-text']) {
			case 'South America':
				$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 593;
				break;
			case 'North America':
				$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 592;
				break;
			case 'Australia':
				$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 596;
				break;
			case 'Asia (APAC)':
				$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 595;
				break;
			case 'China (PRC)':
				$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 966;
				break;
			case 'Europe':
				$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 594;
				break;
			case 'Middle East':
				$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 598;
				break;
			case 'Africa':
				$company_node->field_geographic_region[LANGUAGE_NONE][]['tid'] = 597;
				break;
		 }
	 }
	 /* Geographical Coverage */
	  if ($responses['question-code'] == 'ISA_Geographic_Coverage') {
		 switch ($responses['response-value-text']) {
			case 'Taiwan':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 570;
				break;
			case 'South West Asia':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 569;
				break;
			case 'South East Asia':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 568;
				break;
			case 'Europe':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 572;
				break;
			case 'China':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 566;
				break;
			case 'Australia & New Zealand':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 565;
				break;
			case 'Japan':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 573;
				break;
			case 'Korea':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 567;
				break;
			case 'North America':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 564;
				break;
			case 'Latin and South America':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 563;
				break;
			case 'Africa and the Middle East':
				$company_node->field_geographic_coverage[LANGUAGE_NONE][]['tid'] = 571;
				break;
		 }
	 }
	 if ($responses['question-code'] == 'PartMatchRole') {
		switch ($responses['response-value-text']) {
			case 'Builder':
					$company_node->field_partner_role[LANGUAGE_NONE][]['rid'] = 33;
					break;
			case 'Buyer':
					$company_node->field_partner_role[LANGUAGE_NONE][]['rid'] = 34;
					break;
			case 'Supply Chain':
					$company_node->field_partner_role[LANGUAGE_NONE][]['rid'] = 35;
					break;
		}
	 }
	 if ($responses['question-code'] == 'Client_FAE_Name') {
		 $cfae_name = $responses['response-value-text'];
		 $company_node->field_client_fae_name[LANGUAGE_NONE][0]['value'] = $cfae_name;
	 }
	 if ($responses['question-code'] == 'Client_FAE_Email') {
		 $cfae_email = $responses['response-value-text'];
		 $cfae_uids = db_query("SELECT uid FROM users WHERE mail='$cfae_email'")->fetchCol();
		 $cfae_uid = $cfae_uids[0];
		 if (!empty($cfae_uid)) {
		   $existing_uids = $company_node->field_client_fae[LANGUAGE_NONE];
		   foreach ($existing_uids as $existing_uid) {
			   $ex_uid[] = $existing_uid['target_id'];
		   }
		   if (!in_array($cfae_uid,$ex_uid)) {
			   $company_node->field_client_fae[LANGUAGE_NONE][]['target_id'] = $cfae_uid;
		   }
		 }  
	 }
	 if ($responses['question-code'] == 'Server_FAE_Email') {
		 $sfae_email = $responses['response-value-text'];
		 $sfae_uids = db_query("SELECT uid FROM users WHERE mail='$sfae_email'")->fetchCol();
		 $sfae_uid = $sfae_uids[0];
		 if (!empty($sfae_uid)) {
		   $existing_uids = $company_node->field_server_fae[LANGUAGE_NONE];
		   foreach ($existing_uids as $existing_uid) {
			   $ex_uid[] = $existing_uid['target_id'];
		   }
		   if (!in_array($sfae_uid,$ex_uid)) {
			   $company_node->field_server_fae[LANGUAGE_NONE][]['target_id'] = $sfae_uid;
		   }
		 }  
	 }
	 if ($responses['question-code'] == 'Embedded_IoT_FAE_Email') {
		 $efae_email = $responses['response-value-text'];
		 $efae_uids = db_query("SELECT uid FROM users WHERE mail='$efae_email'")->fetchCol();
		 $efae_uid = $efae_uids[0];
		 if (!empty($efae_uid)) {
		   $existing_uids = $company_node->field_eiot_fae[LANGUAGE_NONE];
		   foreach ($existing_uids as $existing_uid) {
			   $ex_uid[] = $existing_uid['target_id'];
		   }
		   if (!in_array($efae_uid,$ex_uid)) {
			   $company_node->field_eiot_fae[LANGUAGE_NONE][]['target_id'] = $efae_uid;
		   }
		 }  
	 }
	 if ($responses['question-code'] == 'Client_FSE_Name') {
		 $cfse_name = $responses['response-value-text'];
		 $company_node->field_client_fse_name[LANGUAGE_NONE][0]['value'] = $cfse_name;
	 }
	 if ($responses['question-code'] == 'Client_FSE_Email') {
		 $cfse_email = $responses['response-value-text'];
		 $cfse_uids = db_query("SELECT uid FROM users WHERE mail='$cfse_email'")->fetchCol();
		 $cfse_uid = $cfse_uids[0];
		 if (!empty($cfse_uid)) {
		   $existing_uids = $company_node->field_client_fse[LANGUAGE_NONE];
		   foreach ($existing_uids as $existing_uid) {
			   $ex_uid[] = $existing_uid['target_id'];
		   }
		   if (!in_array($cfse_uid,$ex_uid)) {
			   $company_node->field_client_fse[LANGUAGE_NONE][]['target_id'] = $cfse_uid;
		   }
		   
		 }  
	 }
	 if ($responses['question-code'] == 'Server_FSE_Email') {
		 $sfse_email = $responses['response-value-text'];
		 $sfse_uids = db_query("SELECT uid FROM users WHERE mail='$sfse_email'")->fetchCol();
		 $sfse_uid = $sfse_uids[0];
		 if (!empty($sfse_uid)) {
		   $existing_uids = $company_node->field_server_fse[LANGUAGE_NONE];
		   foreach ($existing_uids as $existing_uid) {
			   $ex_uid[] = $existing_uid['target_id'];
		   }
		   if (!in_array($sfse_uid,$ex_uid)) {
			   $company_node->field_server_fse[LANGUAGE_NONE][]['target_id'] = $sfse_uid;
		   }
		 }  
	 }
	 if ($responses['question-code'] == 'Embedded_IoT_FSE_Email') {
		 $efse_email = $responses['response-value-text'];
		 $efse_uids = db_query("SELECT uid FROM users WHERE mail='$efse_email'")->fetchCol();
		 $efse_uid = $efse_uids[0];
		 if (!empty($efse_uid)) {
		   $existing_uids = $company_node->field_eiot_fse[LANGUAGE_NONE];
		   foreach ($existing_uids as $existing_uid) {
			   $ex_uid[] = $existing_uid['target_id'];
		   }
		   if (!in_array($efse_uid,$ex_uid)) {
			   $company_node->field_eiot_fse[LANGUAGE_NONE][]['target_id'] = $efse_uid;
		   }
		 }  
	 }
	 
  }
  //echo 'company_nodeafter<pre>';print_r($company_node);
}
function get_company_from_erpm_id($comp_erpm_num){
	if (isset($comp_erpm_num)) {
	$result = db_query("SELECT DISTINCT(n.nid) AS nid FROM node n,field_data_field_erpm_company_number fecn WHERE n.type = 'company' AND n.nid=fecn.entity_id AND fecn.field_erpm_company_number_value=$comp_erpm_num");
	}
	if (!empty($result)) {
		foreach ($result as $record) {
			$existing_comp_node_id = $record->nid;
		}
		if (isset($existing_comp_node_id)) {
		$company_node = node_load($existing_comp_node_id);
	}
	return $company_node;
	}
	else {
		return FALSE;
	}
}
?>