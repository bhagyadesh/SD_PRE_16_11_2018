<?php

/**
 * @file
 *
 * Page and block callbuck functions will be placed in here for organization.
 */

/**
 * Generates an XML list of companies for consumption by Aprimo.
 *
 * Includes all active, English companies that have a membership type of
 * Premier, Associate, Affiliate, General or Intel.
 */
function _intel_ea_module_aprimo_companies_xml() {
  drupal_add_http_header('Content-Type', 'text/xml: utf-8');

  // Membership types for mapping tids.
  $membership_types = array(
    557 => 'Premier',
    558 => 'Associate',
    559 => 'Affiliate',
    560 => 'General',
    562 => 'Intel',
  );

  // Grab all active company records.
  $query = new EntityFieldQuery();
  $result = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'company')
    ->propertyCondition('language', 'en', '=')
    ->propertyCondition('status', 1)
    ->fieldCondition('field_membership_type', 'tid', array_keys($membership_types), 'IN')
    ->propertyOrderBy('title', 'ASC')
    ->execute();

  $companies = node_load_multiple(array_keys($result['node']));

  // Create a new DOM object.
  $dom = new DOMDocument('1.0', 'utf-8');
  $dom->formatOutput = TRUE;

  // Setup the root element.
  $ea_companies_element = $dom->createElement('ea_companies');
  $ea_companies = $dom->appendChild($ea_companies_element);

  // Setup each child node.
  foreach ($companies as $company) {
    $ea_company_element = $dom->createElement('ea_company');
    $ea_company = $ea_companies->appendChild($ea_company_element);

    $name_element = $dom->createElement('name');
    $name = $ea_company->appendChild($name_element);
    $name->appendChild($dom->createCDATASection($company->title));

    $ea_id_element = $dom->createElement('ea_id', $company->nid);
    $ea_company->appendChild($ea_id_element);

    $company_type_element = $dom->createElement('company_type', $membership_types[$company->field_membership_type[LANGUAGE_NONE][0]['tid']]);
    $ea_company->appendChild($company_type_element);

    $display_name_element = $dom->createElement('display_name');
    $display_name = $ea_company->appendChild($display_name_element);
    $display_name->appendChild($dom->createCDATASection($company->title));

    $conversion_point_element = $dom->createElement('conversion_point');
    $conversion_point = $ea_company->appendChild($conversion_point_element);
    $conversion_point->appendChild($dom->createCDATASection('EA - ' . $company->title));
  }

  // Print the XML.
  print $dom->saveXML();

  // We want to return NULL so that the Drupal page doesn't render.
  return NULL;
}


/**
 * Routes a user to their company feed if one exists, or to create one.
 */
function _intel_ea_module_manage_feed() {
  global $user;

  try {
    $wrapper = entity_metadata_wrapper('user', $user);

    // See if the user's company already has a feed associated with it.
    $query = db_select('node', 'n');
    $query->addField('n', 'nid');
    $query->join('field_data_field_company', 'fc', 'n.nid = fc.entity_id');
    $query->condition('n.type', 'feed');
    $query->condition('fc.field_company_target_id', $wrapper->field_company->nid->value());
    $result = $query->execute()->fetchField();

    if ($result) {
      // Redirect the user to their associated feed if one already exists.
      $url = "node/$result/edit";
    }
    else {
      $url = "node/add/feed";
    }

    drupal_goto($url, array('query' => array('destination' => 'member-resource-center')));
  }
  catch (exception $e) {
    watchdog_exception('intel_ea_module', $e);
  }
}


/**
 * @defgroup user_callback User callback functions
 * @{
 * Callback functions for user processes.
 */

/**
 * User view access callback.
 *
 * @param $account
 *   Can either be a full user object or a $uid.
 */
function _intel_ea_module_user_view_access($account) {
  $uid = is_object($account) ? $account->uid : (int) $account;

  if (user_view_access($uid)) {
    // Admins can view all, users can view own profiles at all times.
    if ($GLOBALS['user']->uid == $uid || user_access('administer any user')) {
      return TRUE;
    }
    elseif (user_access('administer associated user')) {
      // Load the viewed accounts object.
      if (!is_object($account)) {
        $account = user_load($uid);
      }

      return _intel_ea_module_coworker($account);
    }
  }

  return FALSE;
}

/**
 * Menu access callback; limit access to account cancellation pages.
 *
 * Limit access to users with the 'cancel account' permission or administrative
 * users, and prevent the anonymous user from cancelling the account.
 */
function _intel_ea_module_user_cancel_access($account) {
  if (user_cancel_access($account)) {
    // Admins can cancel all, users can cancel own with permission.
    if (((($GLOBALS['user']->uid == $account->uid) && user_access('cancel account')) || user_access('administer any user')) && $account->uid > 0) {
      return TRUE;
    }
    elseif (user_access('administer associated user')) {
      // Load the canceled account object.
      $account = user_load($account->uid);

      return _intel_ea_module_coworker($account);
    }
  }

  return FALSE;
}

/**
 * Access callback for user account editing.
 */
function _intel_ea_module_user_edit_access($account) {
  if (user_edit_access($account)) {
    // Admins can edit all, users can edit own.
    if ((($GLOBALS['user']->uid == $account->uid) || user_access('administer any user')) && $account->uid > 0) {
      return TRUE;
    }
    elseif (user_access('administer associated user')) {
      return _intel_ea_module_coworker($account);
    }
  }

  return FALSE;
}

/**
 * Returns true if the account is associated with the current users company.
 */
function _intel_ea_module_coworker($account) {
  global $user;
  $user = user_load($user->uid);

  return ($user->field_company['und'][0]['target_id'] == $account->field_company['und'][0]['target_id']);
}

/**
 * Saves a user from the intel_ea_module_user_save queue.
 *
 * @param int $uid
 *   A user ID.
 */
function _intel_ea_module_user_save($uid) {
  $account = user_load($uid);
  user_save($account);
}

/**
 * Helper menu_access callback that checks core node access & is alliance member.
 */
function intel_ea_module_alliance_view_access_check() {
  return (intel_ea_module_is_user_alliance_member()) ? true : false;
}

/**
 * @} End of "defgroup user_callback".
 */
