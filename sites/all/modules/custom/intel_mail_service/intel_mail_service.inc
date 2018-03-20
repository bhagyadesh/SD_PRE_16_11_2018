<?php

// intel_ea_web_service.inc

/**
 * Callback for retrieving note resources.
 *
 * @param int $id
 * @return object
 */
function intel_mail_service_push() {

  drupal_page_is_cacheable(FALSE);
  
  if( !isset($_REQUEST['uid']) && !isset($_REQUEST['pwd']))
  return "Credentials required";
    //return $_REQUEST['username'];
  $uid = user_authenticate($_REQUEST['uid'], $_REQUEST['pwd']);
  if ($uid === false){
  watchdog('intel_mail_service', 'UID = '.$_REQUEST['uid']. ', PWD = '.$_REQUEST['pwd'] );  
    return "Invalid credentials";  

  }

// Read all fields from the dbtng_example table.

  $select = db_select('pm_email_custom', 'mail');
  $select->fields('mail')
  ->condition('pm_email_flag', 'unsent', '=')
         //->condition('pm_email_mid', '99999', '=')
	
		 ->condition('pm_email_to', array('sivasankarx.seenuvasan@intel.com'), 'IN') ;
		 
// Add each field and value as a condition to this query.
  foreach ($select as $field => $value) {
    $select->condition($field, $value);
  }
  return $select->execute()->fetchAll();
}

function intel_mail_service_pull() {
 
  drupal_page_is_cacheable(FALSE);
  
  $uid = user_authenticate($_REQUEST['uid'], $_REQUEST['pwd']);
  if ($uid === false)
    return "Invalid credentials";
  $pm_email_eid = $_REQUEST['pm_email_eid'];
  $data = new stdClass();
  $data->pm_email_eid = $pm_email_eid;
  $data->pm_email_flag = 'sent';
  _intel_mail_service_update($pm_email_eid);
  return "updated";
}

function intel_mail_service_services_access($op) {
  return true;
}

function _intel_mail_service_update($mail) {
  try {
    db_update('pm_email_custom')
        ->fields(array('pm_email_flag' => 'sent'))
        ->condition('pm_email_eid', $mail, '=')
        ->execute();
  }
  catch (Exception $e) {
    watchdog('intel_mail_service', t('db_update failed. Message = %message, query= %query', array('%message' => $e->getMessage(), '%query' => $e->query_string)));
  }
}
