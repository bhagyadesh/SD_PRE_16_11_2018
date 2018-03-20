<?php

/**
 * @file
 * Contains basic utility functions that can be used both inside of this module
 * and beyond. Functionality here is meant to be portable in
 * nature and should have utility purposes.
 */

/**
 * Utility to determine if User/uid is associated with alliance member company.
 *
 * @param int $uid
 *   A UID integer. Defaults to current user.
 *
 * @return bool
 *   TRUE if company is an alliance member, FALSE if not an alliance member.
 */
function intel_ea_module_is_user_alliance_member($uid = NULL) {
  // Initialize array of all alliance membership TID's.
  $alliance_member_roles = array(
    557,
    558,
    559,
    560,
    556,
    562,
  );

  // Return TRUE / FALSE if the users company is an alliance member.
  return in_array(intel_ea_module_get_user_company_tid($uid), $alliance_member_roles) ? TRUE : FALSE;
}



/**
 * Return company TID for current User or UID.
 *
 * @param int $uid
 *   UID or NULL to use global $user.
 *
 * @return int
 *   Returns TID of user company. FALSE if company has no TID.
 */
function intel_ea_module_get_wrapped_user_company($uid = NULL) {
  try {
    // Get full user object ($account) of UID -OR- user global if not provided.
    if ($uid) {
      $account = user_load($uid);
    }
    else {
      global $user;
      $account = user_load($user->uid);
    }

    // Load account using entity metadata wrapper.
    $wrapped_account = entity_metadata_wrapper('user', $account);

    // Get TID of company membership type.
    $user_company = $wrapped_account->field_company;

    return $user_company;
  }
  catch (exception $e) {
    watchdog_exception('intel_ea_module', $e);
    return FALSE;
  }
}

/**
 * Return company TID for current User or UID.
 *
 * @param int $uid
 *   UID or NULL to use global $user.
 *
 * @return int
 *   Returns TID of user company. FALSE if company has no TID.
 */
function intel_ea_module_get_user_company_tid($uid = NULL) {
  try {
    // Get full user object ($account) of UID -OR- user global if not provided.
    if ($uid) {
      $account = user_load($uid);
    }
    else {
      global $user;
      $account = user_load($user->uid);
    }

    // Load account using entity metadata wrapper.
    $wrapped_account = entity_metadata_wrapper('user', $account);
    // Check if the user has a company with a set membership type.
    if($wrapped_account->field_company->__isset('field_membership_type') && !is_null($wrapped_account->field_company->field_membership_type->tid->value())){
      // Return TID of company membership type.
      return $wrapped_account->field_company->field_membership_type->value()->tid;
    }
    else{
      // No company field membership type.
      return FALSE;
    }
  }
  catch (exception $e) {
    watchdog_exception('intel_ea_module', $e);
    return FALSE;
  }
}

/**
 * Utility function to get a users program.
 *
 * @param int $uid
 *   Pass in a user ID to load the user account, or null to user current.
 *
 * @return mixed
 *   Returns array of program terms if any, or FALSE if none.
 */
function intel_ea_module_get_user_program($uid = NULL){
  try {
    if ($uid) {
      $account = user_load($uid);
    }
    else {
      global $user;
      $account = user_load($user->uid);
    }

    // Load account using entity metadata wrapper.
    $wrapped_account = entity_metadata_wrapper('user', $account);
    // Load user programs.
    $user_programs = $wrapped_account->field_company->field_programs->value();

    // Check if the user's company even has programs.
    if (!empty($user_programs)) {
      return $user_programs;
    }
    else{
      return FALSE;
    }
  }
  catch (exception $e) {
    watchdog_exception('intel_ea_module', $e);
    return FALSE;
  }
}

/**
 * @defgroup membership_type_utility Membership Type utility functions
 * @{
 * Utility functions assisting with membership types.
 */

/**
 * Returns which membership group a membership type is associated with.
 *
 * @param int $tid
 *   The tid of the membership type.
 */
function _intel_ea_module_get_membership_type_group($tid) {
  $membership_group = '';

  // Determine the membership group the tid is associated with.
  switch ($tid) {
    // Alliance.
    case 557: // Premier Member.
    case 558: // Associate Member.
    case 559: // Affiliate Member.
    case 560: // General Member.
      $membership_group = 'alliance';
      break;

    // Non-Alliance Member.
    case 1154:
      $membership_group = 'non_alliance';
      break;

    // Intel Member.
    case 562:
      $membership_group = 'intel';
      break;

    // Alliance Staff Member.
    case 556:
      $membership_group = 'staff';
      break;
  }

  return $membership_group;
}

/**
 * @} End of "defgroup translation_utility".
 */


/**
 * Returns allowed roles for a company.
 *
 * Takes a complete list roles and filters them down to the allowed roles for
 * the company type.
 *
 * @param object $company
 *   A company node.
 * @param array $roles
 *  Associative array of all role names keyed by role ID.
 *
 * @return mixed
 *   Returns a filtered roles array or FALSE if no array intersection.
 */
function _intel_ea_module_company_roles($company, $roles) {

    $solutions_rid = array_search('Intel Solutions Admin', user_roles());

  // If the company membership type has been set.
  if (isset($company->field_membership_type) && !empty($company->field_membership_type)) {
    $intel_roles = array(
      9 => 'Intel Admin',
      10 => 'Intel Employee',
      11 => 'Intel Field Applications Engineer',
      12 => 'Intel Field Sales Engineer',
      13 => 'Intel Market Development Manager',
      28 => 'Alliance Marketing Expert',
      $solutions_rid => 'Intel Solutions Admin',
    );
    $alliance_staff_roles = array(
      3 => 'Alliance Staff Admin',
      4 => 'Alliance Staff Employee',
      21 => 'Administrator',
      28 => 'Alliance Marketing Expert',
      $solutions_rid => 'Intel Solutions Admin',
    );
    $member_roles = array(
      20 => 'Solutions Directory Editor',
      30 => 'Member Admin',
      $solutions_rid => 'Intel Solutions Admin'
    );

    // @TODO: Review. Unused?
    $general_roles = array(
      7 => 'Employee',
      8 => 'Executive',
      14 => 'Primary Admin Contact',
      15 => 'Primary Leads Contact',
      5 => 'Leads Contact',
      16 => 'Primary Co-Marketing (MDF) Contact',
      6 => 'Co-Marketing (MDF) Contact',
      27 => 'Co-Marketing Premier',
      25 => 'Co-Marketing Associate',
      24 => 'Co-Marketing Affiliate',
      26 => 'Co-Marketing General',
      29 => 'Co-Marketing Distributor',
      17 => 'Primary Contact',
      18 => 'Primary Marketing Contact',
      19 => 'Primary Sales Contact',
      $solutions_rid => 'Intel Solutions Admin',
    );
    $non_alliance_roles = array(
      31 => 'Non-Alliance Employee',
      $solutions_rid => 'Intel Solutions Admin',
    );

    // Set the available roles based on the company type.
    switch ($company->field_membership_type['und'][0]['tid']) {
      // Intel Member.
      case 562:
        return array_intersect_key($intel_roles, $roles);

      // Alliance Staff Member.
      case 556:
        return array_intersect_key($alliance_staff_roles, $roles);

      // Distributor Member.
      case 561:
        return array_diff_key($roles, $intel_roles, $alliance_staff_roles, $member_roles, $non_alliance_roles);

      // Non-Alliance Member.
      case 1154:
        return array_diff_key($roles, $intel_roles, $alliance_staff_roles, $member_roles);

      default:
        return array_diff_key($roles, $intel_roles, $alliance_staff_roles, $non_alliance_roles);
    }
  }

  return FALSE;
}

/**
 * Ensures an array of role ids contains all companion roles.
 *
 * @param array $rids
 *   An associative array of role ids keyed by role id.
 *
 * @return array
 *   Returns an associative array of role ids keyed by role id.
 */
function _intel_ea_module_companion_roles($rids) {
  // Get a list of all roles.
  $roles = user_roles();

  // Create a list of companion roles.
  $companion_roles = array(
    // Primary Admin Contact.
    14 => array(
      30,  // Member Admin.
    ),
    // Primary Contact.
    17 => array(
      14,  // Primary Admin Contact.
      20,  //Solutions Directory Editor.
      30,  // Member Admin.
    ),
    // Primary Marketing Contact.
    18 => array(
      20,  // Solutions Directory Editor.
    ),
  );

  // Loop through the role ids checking for missing companion roles.
  foreach ($rids as $rid) {
    if (isset($companion_roles[$rid])) {
      // Calculate any missing companion roles.
      $missing_roles = array_diff($companion_roles[$rid], $rids);

      // If companion roles are missing.
      if (!empty($missing_roles)) {
        $rids += drupal_map_assoc($missing_roles);

        $role = $roles[$rid];
        $missing_roles = array_intersect_key($roles, drupal_map_assoc($missing_roles));
        $missing_roles = join(' and ', array_filter(array_merge(array(join(', ', array_slice($missing_roles, 0, -1))), array_slice($missing_roles, -1)), 'strlen'));
        drupal_set_message(t('The !role role is meant to be accompanied by the !missing_roles role(s) which have been added.', array('!role' => $role, '!missing_roles' => $missing_roles)), 'warning');
      }
    }
  }

  return $rids;
}

/**
 * Returns a list of fields that are single value for solutions/components.
 */
function _intel_ea_module_single_value_fields() {
  return array(
    'field_display_independent',
    'field_display_hdmi',
    'field_display_lvds',
    'field_display_other',
    'field_display_pcie_x16',
    'field_display_port_edp',
    'field_display_total',
    'field_display_vga',
    'field_memory_ecc',
    'field_memory_max',
    'field_processors_count',
    'field_stds_camera',
    'field_stds_csix',
    'field_stds_eth_ports',
    'field_stds_gps',
    'field_stds_pcie_as',
    'field_stds_pcie_mini',
    'field_stds_pcie_x1',
    'field_stds_pcie_x16',
    'field_stds_pcie_x2',
    'field_stds_pcie_x4',
    'field_stds_pcie_x8',
    'field_stds_pc_104',
    'field_stds_processor_socketed',
    'field_stds_sd_sdio_emmc',
    'field_stds_sim',
    'field_stds_spi',
    'field_stds_storage_cfst',
    'field_stds_storage_ide',
    'field_stds_storage_raid',
    'field_stds_storage_sata',
    'field_stds_storage_ssd_size',
    'field_stds_usb_on_the_go',
    'field_stds_usb_usb1',
    'field_stds_usb_usb2',
    'field_stds_usb_usb3',
    'field_stds_wpan',
  );
}


/**
 * @defgroup translation_utility Translation utility functions
 * @{
 * Utility functions assisting with translations.
 */

/**
 * Returns TRUE if a node is the source of its translation set.
 *
 * @param EntityDrupalWrapper $node
 */
function _intel_ea_module_node_is_source($node) {
  // Source is always set, so we check for an empty value.
  return empty($node->source->value()) || $node->nid->value() == $node->source->nid->value();
}

/**
 * @} End of "defgroup translation_utility".
 */


/**
 * @defgroup revision_utility Revisioning utility functions
 * @{
 * Utility functions assisting with revisions.
 */

/**
 * Returns TRUE if a revision is being moderated.
 *
 * @param object $node
 */
function _intel_ea_module_node_is_moderated($node) {
  return isset($node->revision_operation) && $node->revision_operation == REVISIONING_NEW_REVISION_WITH_MODERATION;
}

/**
 * @} End of "defgroup revision_utility".
 */

/**
 * Utility function to determine if a user is a co-marketing user.
 *
 * @param int $uid
 *   OPTIONAL user id. Users current logged in user if none provided.
 *
 * @return bool
 *   Returns TRUE/FALSE based on if user is a co-marketing role.
 */
function _intel_ea_module_is_user_co_marketing($uid = NULL) {
  // Get full user object ($account) of UID -OR- user global if not provided.
  if ($uid) {
    $account = user_load($uid);
  }
  else {
    global $user;
    $account = user_load($user->uid);
  }

  // Initialize array of co marketing roles.
  $co_marketing_roles = array(
    6,
    24,
    25,
    26,
    27,
    29,
  );

  // Return TRUE if array intersection is not empty (IE: match) False if empty.
  return !empty(array_intersect(array_flip($account->roles), $co_marketing_roles)) ? TRUE : FALSE;
}

/*
 * Helper function, retrieves roles for user. Evaluates whether or not they are
 * "Administrator","Intel Admin", "Alliance Staff Admin". Returns 'True' if they
 * are one of these roles, 'False' otherwise.
 *
 * This is called on by a component of the 'intel_ea_module_menu_alter' function
 * to help determine eligibility to view things specific to this group of users
 *
 * @return bool
 *  Returns TRUE/FALSE if user is of type
 *  "Administrator","Intel Admin", "Alliance Staff Admin"
 */
function _intelea_module_is_user_role_admin() {
  global $user;

  // Array of roles
  $allowed_roles = array("Administrator","Intel Admin", "Alliance Staff Admin",);

  // Get current users roles
  $roles = $user->roles;

  // Test to see if any of the current users roles are in the
  // $allowed_roles array.
  $compare = array_intersect($roles, $allowed_roles) ? TRUE : FALSE;
  return $compare;
}

/**
 * Helper function to determine if a company is an ISA member or not.
 *
 * @param mixed $node
 *   Pass either an integer to load a node by NID, or a fully loaded node.
 *
 * @return bool
 *   Returns TRUE if company is ISA, or FALSE if not.
 */
function intel_ea_module_is_company_isa($node){
  // Load node if it came in as an integer.
  if(is_int($node)){
    $node = node_load($node);
  }
  // Make sure we're dealing with a company.
  if($node->type == 'company'){
    // Wrap the company node for superior semantics.
    $wrapped_node = entity_metadata_wrapper('node', $node);
    // Loop through all membership tier values to try and find ISA TID.
    foreach ($wrapped_node->field_membership_tier->value() as $member_tier){
      // TID For Intel® IoT Solutions Alliance
      if($member_tier->tid == 1322){
        return TRUE;
      }
    }
    // Only makes it here if ISA was not found above. Return false if so.
    return FALSE;
  }else{
    // Not a company, so whatever was passed can't be ISA.
    return FALSE;
    // @TODO: Optionally add error handling here.
  }
}

//function to check Solution editor has company or not
function _intel_ea_module_solution_editor_access(){

global $user;
  
  
  $user_obj = user_load($user->uid);
  
  $company = $user_obj->field_company['und'][0]['target_id'];
  $user_roles = $user->roles;
  
  $se_role = array("Solutions Directory Editor");
  $compare = array_intersect($user_roles, $se_role) ? TRUE : FALSE;
  
  
  if ($company==null && $compare ==TRUE) { // user is logged in
    
	return FALSE;
  } 
  else{
    return TRUE;
  }
  
}

//function for checking intel employee role
function _intel_ea_module_intel_employee_access(){

global $user; 
$user_roles = $user->roles;
$role_count= count($user_roles);
$intel_employee = array("Intel Employee");
$compare = array_intersect($user_roles, $intel_employee) ? TRUE : FALSE;

if($compare==TRUE && $role_count<=2){
	
	return FALSE;
}
else{
	return TRUE;
}
}


function _intel_ea_module_isa_partner_menu_access(){

global $user; 
$user_roles = $user->roles;
$role_count= count($user_roles);
$se_isa = array("Solutions Directory Editor");
$compare = array_intersect($user_roles, $se_isa) ? TRUE : FALSE;

if($compare==TRUE && $role_count<=2){
	
	return FALSE;
}
else{
	return TRUE;
}
}

function _intel_ea_module_hide_messages(){
global $user; 
if(privatemsg_is_disabled($user) == false){
return TRUE;}
else{
return FALSE;}
}
//function for checking buyer+emp role

function _intel_ea_module_buyer_emp(){
	
	global $user; 
//echo "<pre>";print_r($user);exit;
$user_roles = $user->roles;
$role_count= count($user_roles);
$buyer = array("Buyer");
$employee =array("Employee");
$compare_buyer = array_intersect($user_roles, $buyer) ? TRUE : FALSE;
$compare_emloyee = array_intersect($user_roles, $employee) ? TRUE : FALSE;
$compare_sc = array_intersect($user_roles, $employee) ? TRUE : FALSE;

if(($compare_buyer==TRUE && $compare_emloyee==TRUE && $role_count<=3) ||($compare_sc==TRUE && $compare_emloyee==TRUE && $role_count<=3)){
	
	return TRUE;
}
else{
	return FAlSE;
}
	
}