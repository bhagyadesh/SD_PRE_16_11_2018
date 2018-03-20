<?php

/**
 * @file
 *
 * This file contains all custom code relating to forms. From rendering forms,
 * to custom form submission and validation.
 */


/**
 * Implements hook_form_BASE_FORM_ID_alter().
 *
 * Overrides pretty path settings on the facet configuration form.
 */
function intel_ea_module_form_facetapi_facet_display_form_alter(&$form, &$form_state, $form_id) {
  if (user_access('administer facetapi pretty paths') && isset($form['global']['pretty_paths_alias'])) {
    // Add pretty paths alias option to global facet settings.
    $form['global']['pretty_paths_alias']['#description'] .= ' ' . t('IoT Solutions Alliance overrides taxonomy terms to use "@taxonomy_segment" to ensure consistent URLs through taxonomy term name changes.', array('@taxonomy_segment' => '<alias>/<term-id>'));
  }
}


/**
 * Implements hook_form_FORM_ID_alter() for the company_node_form form.
 */
function intel_ea_module_form_company_node_form_alter(&$form, &$form_state, $form_id) {
  $node = $form_state['node'];

  // If this is not a new node and the user cannot edit any company name.
  if (isset($node->nid) && !isset($node->is_new) && !user_access('edit any company name')) {
    // Disable the title field.
    $form['title']['#disabled'] = TRUE;
  }

  // Validate acceptable domains as valid URLs.
  // @TODO: See if this is really essential anymore.
  // $form['field_acceptable_domains']['#element_validate'][] = '_intel_ea_module_domain_validate';

  // Modify the Address' Fullname field label.
  $form['field_address']['und']['0']['name_block']['name_line']['#title'] = t('Contact Name');

  if ($form['field_membership_type']['#access']) {
    // Create a wrapper for the AJAX callback to populate the Membership
    // Types and disable the fields so the values can't be changed by the user.
    $form['field_membership_type']['#prefix'] = '<div id="intel-ea-module-field-membership-type-wrapper">';
    $form['field_membership_type']['#suffix'] = '</div>';
    $form['field_future_membership_type']['#prefix'] = '<div id="intel-ea-module-field-future-membership-type-wrapper">';
    $form['field_future_membership_type']['#suffix'] = '</div>';

    // If we are editing an existing Company or the Agreement Identifier fields
    // already have a value, run the callback to populate the Membership Types.
    if (!empty($form['field_agreement_identifier'][LANGUAGE_NONE]['#default_value']) || isset($form_state['values']['field_agreement_identifier'][LANGUAGE_NONE][0]['target_id'])) {
      $form['field_membership_type'] = _intel_ea_module_company_node_set_current_membership_type($form, $form_state);
    }
    if (!empty($form['field_future_membership'][LANGUAGE_NONE]['#default_value']) || isset($form_state['values']['field_future_membership'][LANGUAGE_NONE][0]['target_id'])) {
      $form['field_future_membership_type'] = _intel_ea_module_company_node_set_future_membership_type($form, $form_state);
    }

    // Create an AJAX callback to determine allowed values for
    // the Current and Future Membership Type fields.
    $form['field_agreement_identifier'][LANGUAGE_NONE]['#ajax'] = array(
      'callback' => '_intel_ea_module_company_node_set_current_membership_type',
      'wrapper' => 'intel-ea-module-field-membership-type-wrapper',
    );
    $form['field_future_membership'][LANGUAGE_NONE]['#ajax'] = array(
      'callback' => '_intel_ea_module_company_node_set_future_membership_type',
      'wrapper' => 'intel-ea-module-field-future-membership-type-wrapper',
    );
  }
}






/**
 * Implements hook_form_FORM_ID_alter() for the solution_node_form form.
 */
function intel_ea_module_form_solution_node_form_alter(&$form, &$form_state, $form_id) {
  global $user;

  // Disable editing of the company for users without the 'edit any solution
  // content' permission.
  if (!user_access('edit any solution content')) {
    if (!in_array('Intel Solutions Admin', $user->roles)){
      _intel_ea_module_form_limit_companies($form, $form_state, $form_id);
    }
  }
}


/**
 * Implements hook_form_FORM_ID_alter() for the formula_node_form form.
 */
function intel_ea_module_form_formula_node_form_alter(&$form, &$form_state, $form_id) {
  // Disable editing of the company for users without the 'edit any formula
  // content' permission.
  if (!user_access('edit any formula content')) {
    _intel_ea_module_form_limit_companies($form, $form_state, $form_id);
  }

  // Relabel the inner submit button
  foreach (  $form['field_component_group']['und'] as $key => $component_form) {
    if (is_int($key)) {
      $form['field_component_group']['und'][$key]['field_component_options']['und']['add_more']['#value'] ="Add another component type";
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for the feed_node_form form.
 */
function intel_ea_module_form_feed_node_form_alter(&$form, &$form_state, $form_id) {
  if (!user_access('edit any feed content')) {
    global $user;

    try {
      if ($user->uid > 0) {
        $wrapper = entity_metadata_wrapper('user', $user);

        // Disable the title field and set the default value to the company title
        // plus ' feed'.
        $form['title']['#disabled'] = TRUE;
        $form['title']['#default_value'] = $wrapper->field_company->title->value() . ' feed';

        // Disable editing of the company for users without the 'edit any feed
        // content' permission.
        _intel_ea_module_form_limit_companies($form, $form_state, $form_id);
      }
    }
    catch (exception $e) {
      watchdog_exception('intel_ea_module', $e);
    }
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for the story_node_form form.
 */
function intel_ea_module_form_story_node_form_alter(&$form, &$form_state, $form_id) {
  // Disable editing of the company for users without the 'edit any story
  // content' permission.
  if (!user_access('edit any story content')) {
    _intel_ea_module_form_limit_companies($form, $form_state, $form_id);
  }
}

/**
 * Implements hook_form_FORM_ID_alter() for the content_access_page form.
 */
function intel_ea_module_form_content_access_page_alter(&$form, &$form_state, $form_id) {
  // Add a submit handler.
  $form['#submit'][] = '_intel_ea_module_content_access_page_submit';
}

/**
 * Implements hook_field_widget_form_alter().
 */
function intel_ea_module_field_widget_form_alter(&$element, &$form_state, $context) {
  // Set the component group remove button text to 'Remove component type'.
  if ($context['field']['field_name'] == 'field_component_group') {
    $element['remove_button']['#value'] = t('Remove component type');
  }
}

/**
 * Implements hook_field_widget_properties_alter().
 */
function intel_ea_module_field_widget_properties_alter(&$widget, &$context) {
  if (isset($context['entity']->type) && ($context['entity']->type == 'component' || $context['entity']->type == 'solution')) {
    if (in_array($context['field']['field_name'], _intel_ea_module_single_value_fields())) {
      $context['field']['cardinality'] = 1;
    }
  }
}

/**
 * Adds an AJAX callback to the user roles field that is triggered on update.
 *
 * The key for the roles field could be 'roles' or 'roles_change' depending on
 * the users permissions. We first determine key for the roles field and then
 * attache our callback function.
 *
 * @param array $form
 *   Nested array of form elements that comprise the form.
 * @param array $form_state
 *   The current state of the form. The arguments that
 *   \Drupal::formBuilder()->getForm() was originally called with are available
 *   in the array $form_state->getBuildInfo()['args'].
 * @param string $form_id
 *   String representing the name of the form itself. Typically this is the name
 *    of the function that generated the form.
 *
 * @see _intel_ea_module_user_form_role_companions_callback()
 *
 * @TODO: Determine if this is important anymore.
// */
//function _intel_ea_module_user_form_role_companions(&$form, &$form_state, $form_id) {
//  // If the user can administer permissions.
//  if (user_access('administer permissions')) {
//    $key = 'roles';
//  }
//  // If the user has role delegation permissions.
//  elseif (isset($form['account']['roles_container']['roles_change'])) {
//    $key = 'roles_change';
//  }
//
//  if (isset($key)) {
//    // Add an ajax callback to the roles field.
//    $form['account']['roles_container'][$key]['#ajax'] = array(
//      'callback' => '_intel_ea_module_user_form_role_companions_callback',
//      'wrapper' => 'intel-ea-module-user-profile-form-roles',
//      'effect' => 'fade',
//    );
//  }
//}

/**
 * Adds custom validation to the company_node_form form.
 */
function _intel_ea_module_node_form_validate($form, &$form_state) {
  // Require either the Technical Description or the End User Description field.
  $node = $form['#node'];
  if (isset($node->body) && isset($node->field_end_user_description)) {
    if (empty($form_state['values']['body'][LANGUAGE_NONE][0]['value']) && empty($form_state['values']['field_end_user_description'][LANGUAGE_NONE][0]['value'])) {
      form_set_error('body', t('You must populate either the Technical Description or the End User Description fields.'));
      form_set_error('field_end_user_description');
    }
  }
}


/**
 * Validates a users email address against their companies acceptable domains.
 *
 * @TODO: See if this is still essential after being disabled for a while.
// */
//function _intel_ea_module_user_form_validate($form, &$form_state) {
//  $valid = FALSE;
//
//  if (isset($form_state['values']['field_company']['und'][0]['target_id'])) {
//    $company = node_load($form_state['values']['field_company']['und'][0]['target_id']);
//
//    foreach ($company->field_acceptable_domains['und'] as $domain) {
//      if (stripos($form_state['values']['mail'], $domain['safe_value']) !== FALSE) {
//        $valid = TRUE;
//        break;
//      }
//    }
//  }
//
//  // If the email address is not valid.
//  if (!$valid) {
//    form_set_error('mail', t('The email address must belong to one of the company\'s acceptable domains.'));
//  }
//}

/**
 * Validates a username and e-mail address and against existing accounts and
 * validates acceptable domains as valid URLs.
 *
 * @see user_account_form_validate in user.module.
 *
 * @TODO: See if this code is still relevant in the future.
// */
//function _intel_ea_module_general_membership_application_validate($form, &$form_state) {
//  // Validate the username, and check if it is taken by an existing user.
//  if (isset($form_state['values']['field_gma_username'][LANGUAGE_NONE][0]['value'])) {
//    if ($error = user_validate_name($form_state['values']['field_gma_username'][LANGUAGE_NONE][0]['value'])) {
//      form_set_error('field_gma_username', $error);
//    }
//    elseif ((bool) db_select('users')->fields('users', array('uid'))->condition('uid', 0, '<>')->condition('name', db_like($form_state['values']['field_gma_username'][LANGUAGE_NONE][0]['value']), 'LIKE')->range(0, 1)->execute()->fetchField()) {
//      form_set_error('field_gma_username', t('The name %name is already taken.', array('%name' => $form_state['values']['field_gma_username'][LANGUAGE_NONE][0]['value'])));
//    }
//  }
//
//  // Validate the e-mail address, and check if it is taken by an existing user.
//  if (isset($form_state['values']['field_gma_email_address'][LANGUAGE_NONE][0]['value'])) {
//    // Trim whitespace from mail, to prevent confusing 'e-mail not valid'
//    // warnings often caused by cutting and pasting.
//    $mail = trim($form_state['values']['field_gma_email_address'][LANGUAGE_NONE][0]['value']);
//    form_set_value($form['field_gma_email_address'], array(LANGUAGE_NONE => array(0 => array('value' => $mail))), $form_state);
//
//    if ($error = user_validate_mail($form_state['values']['field_gma_email_address'][LANGUAGE_NONE][0]['value'])) {
//      form_set_error('field_gma_email_address', $error);
//    }
//    elseif ((bool) db_select('users')->fields('users', array('uid'))->condition('uid', 0, '<>')->condition('mail', db_like($form_state['values']['field_gma_email_address'][LANGUAGE_NONE][0]['value']), 'LIKE')->range(0, 1)->execute()->fetchField()) {
//      form_set_error('field_gma_email_address', t('The e-mail address %email is already taken.', array('%email' => $form_state['values']['field_gma_email_address'][LANGUAGE_NONE][0]['value'])));
//    }
//
//    // Validate the e-mail address against the company's acceptable domains.
//    $valid = FALSE;
//    if (!empty($form_state['values']['field_gma_acceptable_domains'][LANGUAGE_NONE][0]['value'])) {
//      foreach ($form_state['values']['field_gma_acceptable_domains'][LANGUAGE_NONE] as $delta => $domain) {
//        if (is_numeric($delta)) {
//          if (stripos($form_state['values']['field_gma_email_address'][LANGUAGE_NONE][0]['value'], $domain['value']) !== FALSE) {
//            $valid = TRUE;
//            break;
//          }
//        }
//      }
//      if (!$valid) {
//        form_set_error('field_gma_email_address', t('The email address must belong to one of the company\'s acceptable domains.'));
//      }
//    }
//  }
//
//  // Prepend http:// to the website URL if neither http:// or https:// exists.
//  $protocol = preg_match('/^http(s)?:\/\//i', $form_state['values']['field_gma_website'][LANGUAGE_NONE][0]['url']);
//  $form_state['values']['field_gma_website'][LANGUAGE_NONE][0]['url'] = ($protocol) ? $form_state['values']['field_gma_website'][LANGUAGE_NONE][0]['url'] : 'http://' . $form_state['values']['field_gma_website'][LANGUAGE_NONE][0]['url'];
//
//  // Loop through form errors and remove duplicates for username and e-mail.
//  if ($errors = form_get_errors()) {
//    // Clear errors.
//    form_clear_error();
//    // Clear error messages.
//    $error_messages = drupal_get_messages('error');
//    // Initialize an array where removed messages are stored.
//    $removed_messages = array();
//
//    // Remove, but store, the two duplicate error messages.
//    foreach ($errors as $name => $error_message) {
//      if ($name == 'field_gma_username][und][0][value' || $name == 'field_gma_email_address][und][0][value') {
//        $removed_messages[$name] = $error_message;
//        unset($errors[$name]);
//      }
//    }
//
//    // Create an array of the removed errors to loop through.
//    foreach ($errors as $name => $error) {
//      form_set_error($name, $error);
//      $removed_messages[] = $error;
//    }
//
//    // Reapply the messages we didn't remove and show them.
//    foreach (array_diff($error_messages['error'], $removed_messages) as $message) {
//      drupal_set_message($message, 'error');
//    }
//  }
//}

/**
 * Submit handler for Membership Renewal Application to update Company node.
 *
// * @TODO: See if this code is still relevant in the future.
// */
//function _intel_ea_module_membership_renewal_application_updates($form, &$form_state) {
//  try {
//    // Load the company node that we want to change.
//    $company = node_load($form_state['values']['field_mra_company_name'][LANGUAGE_NONE][0]['target_id']);
//    $company_wrapper = entity_metadata_wrapper('node', $company);
//
//    // Set the Renewal Signee to the submitter of the renewal.
//    $submitter_id = $form_state['build_info']['args'][0]->uid;
//    $submitter = user_load($submitter_id);
//    $submitter_name = $submitter->field_first_name[LANGUAGE_NONE][0]['safe_value'] . ' ' . $submitter->field_last_name[LANGUAGE_NONE][0]['safe_value'];
//    $company_wrapper->field_renewal_signee->set($submitter_name);
//
//    // Make sure the Agreed to Participation Criteria checkbox is checked.
//    $company_wrapper->field_agreed->set(1);
//
//    // Update the Acceptance Date of Current Agreement.
//    $acceptance_date = new DateTime(date('Y-m-d 00:00:00'));
//    $company_wrapper->field_acceptance_date->set($acceptance_date->getTimestamp());
//
//    // Update the Current Agreement Identifier.
//    $future_agreement_identifier = $company_wrapper->field_future_membership->value();
//    $company_wrapper->field_agreement_identifier->set($future_agreement_identifier);
//
//    // Update the Current Membership Type.
//    $future_membership_type = $company_wrapper->field_future_membership_type->value();
//    $company_wrapper->field_membership_type->set($future_membership_type);
//
//    // Update the Current Agreement Date.
//    $future_agreement_date = $company_wrapper->field_future_agreement_date->value();
//    $company_wrapper->field_agreement_date->set($future_agreement_date);
//
//    // Update the Future Agreement Date for upper tier members.
//    switch($future_membership_type->tid) {
//      // Premier Member.
//      case 557:
//        // Associate Member.
//      case 558:
//        // Affiliate Member.
//      case 559:
//        $future_agreement_date_incr = strtotime('+15 months', $future_agreement_date);
//        $company_wrapper->field_future_agreement_date->set($future_agreement_date_incr);
//        break;
//    }
//
//    // Save the changes.
//    $company_wrapper->save();
//  }
//  catch (exception $e) {
//    watchdog_exception('intel_ea_module', $e);
//  }
//}

///**
// * Submit handler for General Membership Application to create Primary Contact
// * user and Company node.
// *
// * @TODO: SEe if this code is still relevant in the future.
// */
//function _intel_ea_module_general_membership_application_updates($form, &$form_state) {
//
//  try {
//    // Create the Company node.
//    $node_values = array(
//      'type' => 'company',
//      'uid' => 1,
//      'status' => 0,
//      'language' => 'en',
//    );
//    $node = entity_create('node', $node_values);
//
//    // Set field values.
//    $company_wrapper = entity_metadata_wrapper('node', $node);
//
//    // Set the node title to the GMA Company Name.
//    $company_wrapper->title->set($form_state['values']['field_gma_company_name'][LANGUAGE_NONE][0]['value']);
//
//    // Set the node body to the GMA Company Description.
//    $company_wrapper->body->set(array('value' => $form_state['values']['field_gma_company_description'][LANGUAGE_NONE][0]['value']));
//
//    // Set the Company Type to the GMA Company Type.
//    $company_wrapper->field_company_type->get(0)->set($form_state['values']['field_gma_company_type'][LANGUAGE_NONE][0]['tid']);
//
//    // Set the Website to the GMA Website.
//    $company_wrapper->field_website->url->set($form_state['values']['field_gma_website'][LANGUAGE_NONE][0]['url']);
//
//    // Set the Acceptable Domains to the GMA Acceptable Domains.
//    foreach ($form_state['values']['field_gma_acceptable_domains'][LANGUAGE_NONE] as $delta => $domain) {
//      if (is_numeric($delta)) {
//        $company_wrapper->field_acceptable_domains->get($delta)->set($domain['value']);
//      }
//    }
//
//    // Set the Geographic Region to the GMA Geographic Region.
//    foreach ($form_state['values']['field_gma_geographic_region'][LANGUAGE_NONE] as $delta => $region) {
//      $company_wrapper->field_geographic_region->get($delta)->set($region['tid']);
//    }
//
//    // Set the Geographic Coverage to the GMA Geographic Coverage.
//    foreach ($form_state['values']['field_gma_geographic_coverage'][LANGUAGE_NONE] as $delta => $coverage) {
//      $company_wrapper->field_geographic_coverage->get($delta)->set($coverage['tid']);
//    }
//
//    // Set the Address to the GMA Address.
//    foreach ($form_state['values']['field_gma_address'][LANGUAGE_NONE][0] as $key => $value) {
//      if ($key != 'element_key') {
//        $company_wrapper->field_address->$key->set($value);
//      }
//    }
//
//    // Set the Agreement Identifier and Membership Type (General/General Member)
//    $company_wrapper->field_agreement_identifier->set('612');
//    $company_wrapper->field_membership_type->set('560');
//
//    // Save the company and field values.
//    $company_wrapper->save();
//
//    // Create the Primary Contact user.
//    $user_values = array(
//      'name' => $form_state['values']['field_gma_username'][LANGUAGE_NONE][0]['value'],
//      'mail' => $form_state['values']['field_gma_email_address'][LANGUAGE_NONE][0]['value'],
//      'status' => 0,
//      'init' => $form_state['values']['field_gma_email_address'][LANGUAGE_NONE][0]['value'],
//      'roles' => array(
//        DRUPAL_AUTHENTICATED_RID => DRUPAL_AUTHENTICATED_RID,  // authenticated user.
//        14 => 14,  // Primary Admin Contact.
//        17 => 17,  // Primary Contact.
//        18 => 18,  // Primary Marketing Contact.
//        20 => 20,  // Solutions Directory Editor.
//        30 => 30,  // Member Admin.
//      ),
//    );
//    $account = entity_create('user', $user_values);
//
//    // Set custom field values.
//    $user_wrapper = entity_metadata_wrapper('user', $account);
//
//    // Set the Salutation to the GMA Salutation.
//    $user_wrapper->field_salutation->set($form_state['values']['field_gma_salutation'][LANGUAGE_NONE][0]['tid']);
//
//    // Set the First Name to the GMA First Name.
//    $user_wrapper->field_first_name->set($form_state['values']['field_gma_first_name'][LANGUAGE_NONE][0]['value']);
//
//    // Set the Last Name to the GMA Last Name.
//    $user_wrapper->field_last_name->set($form_state['values']['field_gma_last_name'][LANGUAGE_NONE][0]['value']);
//
//    // Set the Job Title to GMA Job Title.
//    $user_wrapper->field_title->set($form_state['values']['field_gma_title'][LANGUAGE_NONE][0]['value']);
//
//    // Set the Work Phone to GMA Work Phone.
//    $user_wrapper->field_work_phone->set($form_state['values']['field_gma_work_phone'][LANGUAGE_NONE][0]['value']);
//
//    // Set the Fax Phone to GMA Fax Phone.
//    $user_wrapper->field_fax_phone->set($form_state['values']['field_gma_fax_phone'][LANGUAGE_NONE][0]['value']);
//
//    // Set the Mobile Phone to GMA Mobile Phone.
//    $user_wrapper->field_mobile_phone->set($form_state['values']['field_gma_mobile_phone'][LANGUAGE_NONE][0]['value']);
//
//    // Set the Address to GMA User Address.
//    foreach ($form_state['values']['field_gma_user_address'][LANGUAGE_NONE][0] as $key => $value) {
//      if ($key != 'element_key') {
//        $user_wrapper->field_address->$key->set($value);
//      }
//    }
//
//    // Set the Receive Members Email preference to GMA Receive Members Email.
//    $user_wrapper->field_receive_members_email->set($form_state['values']['field_gma_receive_members_email'][LANGUAGE_NONE][0]['value']);
//
//    // Set the Company Role to Primary Contact & Primary Marketing Contact.
//    $user_wrapper->field_company_role->get(0)->set('655');
//    $user_wrapper->field_company_role->get(1)->set('657');
//
//    // Set the Company to the newly created Company record above.
//    if ($node->nid) {
//      $user_wrapper->field_company->set(intval($node->nid));
//    }
//
//    // Save the user and field values.
//    $user_wrapper->save();
//  }
//  catch (exception $e) {
//    watchdog_exception('intel_ea_module', $e);
//  }
//}

/**
 * Returns a Google Analytics filter form.
 */
function intel_ea_module_google_analytics_filter_form($form, &$form_state) 
{
  $company = _intel_ea_module_google_analytics_reports_company_get();
  $start = _intel_ea_module_google_analytics_reports_start_get();
  $end = _intel_ea_module_google_analytics_reports_end_get();
	
 
  $companies = db_select('node', 'n')
    ->fields('n', array('nid', 'title'))
    ->condition('n.status', 1)
    ->condition('n.type', 'company')
    ->where("(n.nid = n.tnid OR n.tnid = 0)")
    ->addTag('node_access')
    ->addMetaData('op', 'update')
    ->execute()
    ->fetchAllKeyed(0, 1);
/*

$form['domain_name'] = array(
  '#title' => t('Select Domain'),
  '#type' => 'select',
  '#description' => 'For past analytics select domain iotsolutionsalliance.com',
  "#default_value" => variable_get("domain_name", "web_property1"),
  '#options' => array(
	"web_property1" => t('solutionsdirectory.intel.com'), 
	"web_property2" => t('iotsolutionsalliance.com')
	),
);	
*/

  $form['start'] = array(
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d',
    '#title' => t('Start'),
    '#default_value' => date('Y-m-d', $start),
    '#required' => TRUE,
  );
  
  $form['end'] = array(
    '#type' => 'date_popup',
    '#date_format' => 'Y-m-d',
    '#title' => t('End'),
    '#default_value' => date('Y-m-d', $end),
    '#required' => TRUE,
  );
  $form['company'] = array(
    '#type' => 'select',
    '#title' => t('Company'),
    '#options' => $companies,
    '#default_value' => $company,
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Apply'),
  );

  return $form;
}

/**
 * Submits the Google Analytics filter form.
 */
function intel_ea_module_google_analytics_filter_form_submit($form, &$form_state) {
  // Store form values.
  _intel_ea_module_google_analytics_reports_company_set($form_state['values']['company']);
  _intel_ea_module_google_analytics_reports_start_set(strtotime($form_state['values']['start']));
  _intel_ea_module_google_analytics_reports_end_set(strtotime($form_state['values']['end']));
}

/**
 * Gets the Google Analytics Reports company id.
 *
 * Retrieves the Google Analytics Reports company id from the user's session if
 * it's set, otherwise defaults to the user's company.
 */
function _intel_ea_module_google_analytics_reports_company_get() {
  if (isset($_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['company'])) {
    $company = $_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['company'];
  }
  else {
    try {
      global $user;
      $account = entity_metadata_wrapper('user', $user);
      $company = $account->field_company->nid->value();
    }
    catch (exception $e) {
      watchdog_exception('intel_ea_module', $e);
    }
  }

  return $company;
}

/**
 * Sets the Google Analytics Reports company id.
 *
 * Stores the Google Analytics Reports company id in the user's session.
 */
function _intel_ea_module_google_analytics_reports_company_set($company) {
  $_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['company'] = $company;
}

/**
 * Gets the Google Analytics Reports start date.
 *
 * Retrieves the Google Analytics Reports start date from the user's session if
 * it's set, otherwise defaults to a year ago.
 */
function _intel_ea_module_google_analytics_reports_start_get() {
  if (isset($_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['start'])) {
    $start = $_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['start'];
  }
  else {
    $start = strtotime('-17 days');
  }

  return $start;
}

/**
 * Sets the Google Analytics Reports start date.
 *
 * Stores the Google Analytics Reports start date in the user's session.
 */
function _intel_ea_module_google_analytics_reports_start_set($start) {
  $_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['start'] = $start;
}


/**
 * Sets the Google Analytics Reports end date.
 *
 * Stores the Google Analytics Reports end date in the user's session.
 */
function _intel_ea_module_google_analytics_reports_end_set($end) {
  $_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['end'] = $end;
}


/**
 * Utility function for field validation on a email domain limitations.
 *
 * Validates acceptable domains as valid URLs.
 *
 * @TODO: Remove if no longer essential.
// */
//function _intel_ea_module_domain_validate($element, &$form_state, $form) {
//  // The only child should be the current locale id.
//  foreach (element_children($element) as $child) {
//    $value =& $element[$child];
//
//    // Loop through all values.
//    foreach (element_children($value) as $delta) {
//      $url =& $value[$delta]['value'];
//
//      if (isset($url['#type']) && $url['#type'] == 'textfield') {
//        if (!empty($url['#value']) && !valid_url($url['#value'])) {
//          form_set_error("{$url['#field_name']}][$child][$delta", t('The domain %domain is not valid.', array('%domain' => $url['#value'])));
//        }
//        elseif (in_array($url['#value'], array('gmail.com', 'yahoo.com'))) {
//          form_set_error("{$url['#field_name']}][$child][$delta", t('The domain %domain is not allowed.', array('%domain' => $url['#value'])));
//        }
//      }
//    }
//  }
//}


/**
 * Implements hook_form_alter().
 */
function intel_ea_module_form_alter(&$form, &$form_state, $form_id) {
  switch ($form_id) {
    // Node forms.
    case 'company_node_form':
    case 'formula_node_form':
    case 'solution_node_form':
      // Add a custom validator to the company_node_form form.
      $form['#validate'][] = '_intel_ea_module_node_form_validate';
      break;

    // User forms.
    case 'user_profile_form':
    case 'user_register_form':
      // Limit the available companies.
      if (!user_access('administer any user')) {
        _intel_ea_module_form_limit_companies($form, $form_state, $form_id);
      }

      // Limit the available roles.
      // @TODO: Remove this if no longer nescessary!
      // _intel_ea_module_user_form_limit_roles($form, $form_state, $form_id);

      // Handle companion roles.
      // @TODO: Remove this if no longer nescessary!
      // _intel_ea_module_user_form_role_companions($form, $form_state, $form_id);

      // Validate the users email address against their company's acceptable
      // domains.
      // @TODO: Remove this if no longer nescessary!
      //$form['#validate'][] = '_intel_ea_module_user_form_validate';
      break;

    // Views exposed form.
    case 'views_exposed_form':
      if ($form['#id'] == 'views-exposed-form-solutions-directory-search-results' || $form['#id'] == 'views-exposed-form-solutions-directory-panel-pane-1') {
        // Add extra attributes to the text box
        $form['search']['#attributes']['onblur'] = "if (this.value == '') {this.value = 'Search Solutions Directory';}";
        $form['search']['#attributes']['onfocus'] = "if (this.value == 'Search Solutions Directory') {this.value = '';}";
        // Prevent user from searching the default text
        $form['#attributes']['onsubmit'] = "if(this.search.value=='Search Solutions Directory'){ alert('Please enter a search'); return false; }";
        // Alternative (HTML5) placeholder attribute instead of using the javascript
        $form['search']['#attributes']['placeholder'] = t('Search Solutions Directory');

        // Combine the 'sort by' and 'sort order' fields.
        if (isset($form['sort_by'])) {
          // Set up the combined 'sort' select menu.
          $form['sort'] = array(
            '#type' => 'select',
            '#id' => 'sort',
            '#title' => t('Sort by'),
          );

          // Populate the select menu with the combined options.
          // We only want to populate with the following three values.
          $sort_values = array('created|DESC', 'search_api_relevance|DESC', 'field_company_field_membership_type_weight|ASC');
          foreach ($form['sort_by']['#options'] as $sort_by_key => $sort_by_name) {
            foreach ($form['sort_order']['#options'] as $sort_order_key => $sort_order_name) {
              $sort_value = $sort_by_key . '|' . $sort_order_key;
              if (in_array($sort_value, $sort_values)) {
                $form['sort']['#options'][$sort_value] = $sort_by_name;
              }
            }
          }

          // Get default value for combined sort.
          $sort_by_keys = array_keys($form['sort_by']['#options']);
          $form['sort']['#default_value'] = $sort_by_keys[0] . '|' . $form['sort_order']['#default_value'];
        }

        // Explode combined sort fields into two values that are appropriate for view.
        if (isset($form_state['input']['sort'])) {
          $sort = explode('|', $form_state['input']['sort']);
          $form_state['input']['sort_by'] = $sort[0];
          $form_state['input']['sort_order'] = $sort[1];
        }

        // Modify the option displays (not values) for items per page.
        foreach ($form['items_per_page']['#options'] as $value => $items) {
          $form['items_per_page']['#title'] = t('Items per page');
          $form['items_per_page']['#options'][$value] = t('Show !items per page', array('!items' => $items));
        }
      }
      break;

    // Add text and images to the entity form.
    case 'order_free_intel_iotg_gateway_entityform_edit_form':
      $form['field_select_hardware_platform']['und']['#options']['dell'] .=
        '<br /><br />
         <ul class="description">
           <li>Segment: Light Industrial and Building Automation</li>
           <li>SoC: Intel Celeron N2807 1.6 GHz dual core processor</li>
           <li>OS Support: Wind River IPD 2.1</li>
           <li>I/O Support :
               <ul class="gateway-li">
                 <li>1x Gbit Ethernet</li>
                 <li>802.11a/b/g/n/ac</li>
                 <li>1x DVI ports</li>
                 <li>1x USB ports</li>
                 <li>1x serial port</li>
               </ul>
           </li>
           <li>Expansion:  0 to 40C (0 to 50C)</li>
           <li>Mount: VESA/Wall</li>
           <li>Power: 12 - 19V DC</li>
           <li>Dimensions: 187mm x 29mm x 117mm</li>
         </ul>';
      $form['field_select_hardware_platform']['und']['#options']['nise'] .=
        '<br /><br />
        <ul class="description">
          <li>Onboard Intel Atom processor E3826 dual core, 1.46GHz</li>
          <li>Dual Independent Display from DVI-I and HDMI</li>
          <li>2 x Intel I120IT LAN ports support WoL, Teaming and PXE</li>
          <li>2 x USB2.0 & 1 X USB3.0</li>
          <li>4 x COM ports (COM1 & COM2 with RS232/422/485, jumper-free setting)</li>
          <li>1 x Optional Interface for optional Wi-Fi/3.5G/Automation Modules</li>
          <li>External TRV battery holder for easy replacement</li>
          <li>Support -20 ~ 70 degree C extended operating terperature</li>
          <li>Support 9-30VDC input</li>
        </ul>';
      break;

    // Membership Renewal Application
    case 'membership_renewal_application_entityform_edit_form':
      global $user;
      $user = user_load($user->uid);
      $company = node_load($user->field_company[LANGUAGE_NONE]['0']['target_id']);

      // Block access to the form if user's company's current expiration date
      // is not within 60 days of today's date or past due,
      // or if any of the three future membership fields have no value.
      if (isset($company->field_agreement_date) && !empty($company->field_agreement_date)) {
        $current_agreement_exp = (strtotime($company->field_agreement_date[LANGUAGE_NONE][0]['value']) < strtotime('now +60 days')) ? TRUE : FALSE;
      }
      else {
        $current_agreement_exp = FALSE;
      }
      $future_agreement_identifier = (isset($company->field_future_membership) && !empty($company->field_future_membership)) ? TRUE : FALSE;
      $future_membership_type = (isset($company->field_future_membership_type) && !empty($company->field_future_membership_type)) ? TRUE : FALSE;
      $future_agreement_date = (isset($company->field_future_agreement_date) && !empty($company->field_future_agreement_date)) ? TRUE : FALSE;
      $renewal_access = ($current_agreement_exp && $future_agreement_identifier && $future_membership_type && $future_agreement_date) ? TRUE : FALSE;
      // Allow access for Intel and Alliance Staff Admin members.
      $admin_access = (in_array($company->field_membership_type[LANGUAGE_NONE][0]['tid'], array(556, 562))) ? TRUE : FALSE;
      if ($renewal_access || $admin_access) {
        // If user is authorized for renewal, make the form alters.
        if ($renewal_access) {
          // Set default value on Company Name.
          $form['field_mra_company_name'][LANGUAGE_NONE]['#default_value'] = $company->nid;
          $form['field_mra_company_name']['#disabled'] = TRUE;

          // Set default value on Future Membership.
          $form['field_mra_future_membership'][LANGUAGE_NONE]['#default_value'] = ($company->field_future_membership) ? $company->field_future_membership[LANGUAGE_NONE]['0']['tid'] : '';
          $form['field_mra_future_membership']['#disabled'] = TRUE;

          // Set help text with links to agreement documents.
          // Terms & Conditions
          $membership_terms_conditions = _intel_ea_module_membership_terms_conditions($company->field_membership_type[LANGUAGE_NONE][0]['tid'], TRUE);
          $form['field_mra_terms_condition'][LANGUAGE_NONE]['#description'] = t('View !membership_terms_conditions.', array('!membership_terms_conditions' => $membership_terms_conditions));

          // Participation Criteria (not General Members) and Usage Guidelines.
          if ($company->field_future_membership && $company->field_future_membership_type) {
            $agreement_identifier = $company->field_future_membership[LANGUAGE_NONE][0]['tid'];
            $membership_tier = $company->field_future_membership_type[LANGUAGE_NONE][0]['tid'];
            // Remove the Participation Criteria agreement checkbox for:
            // - Comp SI Associate
            // - Distributor
            // - General
            // - SW Services Affiliate
            // - SW Services Associate
            if (in_array($agreement_identifier, array('606', '611', '612', '633', '634'))) {
              unset($form['field_mra_participation_criteria']);
            }
            else {
              if ($participation_criteria = _intel_ea_module_participation_criteria($membership_tier, $agreement_identifier)) {
                $form['field_mra_participation_criteria'][LANGUAGE_NONE]['#description'] = t('View !participation_criteria.', array('!participation_criteria' => $participation_criteria));
              }
            }
            $usage_guidelines = _intel_ea_module_usage_guidelines($membership_tier, TRUE, TRUE);
            $form['field_mra_usage_guidelines'][LANGUAGE_NONE]['#description'] = t('View !usage_guidelines.', array('!usage_guidelines' => $usage_guidelines));
          }
          else {
            $agreement_identifier = $company->field_agreement_identifier[LANGUAGE_NONE][0]['tid'];
            $membership_tier = $company->field_membership_type[LANGUAGE_NONE][0]['tid'];

            if ($participation_criteria = _intel_ea_module_participation_criteria($membership_tier, $agreement_identifier)) {
              $form['field_mra_participation_criteria'][LANGUAGE_NONE]['#description'] = t('View !participation_criteria.', array('!participation_criteria' => $participation_criteria));
            }

            $usage_guidelines = _intel_ea_module_usage_guidelines($membership_tier, TRUE, TRUE);
            $form['field_mra_usage_guidelines'][LANGUAGE_NONE]['#description'] = t('View !usage_guidelines.', array('!usage_guidelines' => $usage_guidelines));
          }

          // Cancel and return to MRC
          $form['actions']['cancel'] = array(
            '#markup' => l(t('Cancel'), 'member-resource-center', array('attributes' => array('class' => 'white-button'))),
          );

          // Set up a submit handler to update the Company node.
          $form['#submit'][] = '_intel_ea_module_membership_renewal_application_updates';
          $form['actions']['submit']['#submit'][] = '_intel_ea_module_membership_renewal_application_updates';

          break;
        }
        // If admin user, load the form as is.
        elseif ($admin_access) {
          break;
        }
      }
      else {
        // Give the user a message if they are blocked access.
        drupal_set_message(t('Your membership renewal is not available at this time.'), 'warning');
        drupal_access_denied();
        // Stop the form from rendering unaltered.
        // http://api.drupal.org/comment/43643#comment-43643
        drupal_exit();

        break;
      }
  }
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * For the general_membership_application_entityform_edit_form form.
 *
 * @TODO: See if this form alter is of any significant meaning.
// */
//function intel_ea_module_form_general_membership_application_entityform_edit_form_alter(&$form, &$form_state, $form_id) {
//  global $user;
//  // If the user is authenticated.
//  if ($user->uid != 0) {
//    $account = entity_metadata_wrapper('user', $user);
//
//    // Remove access to fields to hide them as we don't want to allow
//    // information for existing users and companies to be updated.
//    $form['field_gma_username']['#access'] = FALSE;
//    $form['field_gma_username'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->name->value();
//    $form['field_gma_email_address']['#access'] = FALSE;
//    $form['field_gma_email_address'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->mail->value();
//    $form['field_gma_salutation']['#access'] = FALSE;
//    $form['field_gma_salutation'][LANGUAGE_NONE]['#default_value'][0] = $account->field_salutation->raw();
//    $form['field_gma_first_name']['#access'] = FALSE;
//    $form['field_gma_first_name'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->field_first_name->value();
//    $form['field_gma_last_name']['#access'] = FALSE;
//    $form['field_gma_last_name'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->field_last_name->value();
//    $form['field_gma_title']['#access'] = FALSE;
//    $form['field_gma_title'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->field_title->value();
//    $form['field_gma_work_phone']['#access'] = FALSE;
//    $form['field_gma_work_phone'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->field_work_phone->value();
//    $form['field_gma_fax_phone']['#access'] = FALSE;
//    $form['field_gma_fax_phone'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->field_fax_phone->value();
//    $form['field_gma_mobile_phone']['#access'] = FALSE;
//    $form['field_gma_mobile_phone'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->field_mobile_phone->value();
//    $form['field_gma_user_address']['#access'] = FALSE;
//    foreach ($form['field_gma_user_address'][LANGUAGE_NONE][0]['#columns'] as $column) {
//      if (!empty($account->field_address->$column)) {
//        $form['field_gma_user_address'][LANGUAGE_NONE][0]['#address'][$column] = $account->field_address->$column->value();
//      }
//    }
//    $form['field_gma_receive_members_email']['#access'] = FALSE;
//    $form['field_gma_receive_members_email'][LANGUAGE_NONE]['#default_value'] = ($account->field_receive_members_email->value()) ? '1' : '0';
//    $form['field_gma_company_name']['#access'] = FALSE;
//    $form['field_gma_company_name'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->field_company->title->value();
//    $form['field_gma_company_description']['#access'] = FALSE;
//    $form['field_gma_company_description'][LANGUAGE_NONE][0]['value']['#default_value'] = $account->field_company->body->value->value();
//    $form['field_gma_website']['#access'] = FALSE;
//    $form['field_gma_website'][LANGUAGE_NONE][0]['#default_value']['url'] = $account->field_company->field_website->url->value();
//    $form['field_gma_acceptable_domains']['#access'] = FALSE;
//    foreach ($account->field_company->field_acceptable_domains->value() as $delta => $acceptable_domain) {
//      // Add another value to the multivalue field.
//      $new_value = $form['field_gma_acceptable_domains'][LANGUAGE_NONE][$delta + 1] = array(
//        '#delta' => $delta + 1,
//        '#weight' => $delta + 1,
//        'value' => array(
//          '#delta' => $delta + 1,
//          '#weight' => $delta + 1,
//        ),
//      );
//      $form['field_gma_acceptable_domains'][LANGUAGE_NONE][$delta + 1] = array_replace_recursive($form['field_gma_acceptable_domains'][LANGUAGE_NONE][$delta], $new_value);
//      $form['field_gma_acceptable_domains'][LANGUAGE_NONE][$delta]['value']['#default_value'] = $acceptable_domain;
//    }
//    $form['field_gma_address']['#access'] = FALSE;
//    foreach ($form['field_gma_address'][LANGUAGE_NONE][0]['#columns'] as $column) {
//      if (!empty($account->field_company->field_address->$column)) {
//        $form['field_gma_address'][LANGUAGE_NONE][0]['#address'][$column] = $account->field_company->field_address->$column->value();
//      }
//    }
//    $form['field_gma_geographic_region']['#access'] = FALSE;
//    foreach ($account->field_company->field_geographic_region->raw() as $delta => $tid) {
//      $form['field_gma_geographic_region'][LANGUAGE_NONE]['#default_value'][$delta] = $tid;
//    }
//    $form['field_gma_geographic_coverage']['#access'] = FALSE;
//    foreach ($account->field_company->field_geographic_coverage->raw() as $delta => $tid) {
//      $form['field_gma_geographic_coverage'][LANGUAGE_NONE]['#default_value'][$delta] = $tid;
//    }
//    $form['field_gma_company_type']['#access'] = FALSE;
//    $form['field_gma_company_type'][LANGUAGE_NONE]['#default_value'][0] = $account->field_company->field_company_type->raw()[0];
//    $form['field_gma_company_type_unlimited']['#access'] = FALSE;
//    foreach ($account->field_company->field_company_type->raw() as $delta => $tid) {
//      $form['field_gma_company_type_unlimited'][LANGUAGE_NONE]['#default_value'][$delta] = $tid;
//    }
//    $form['field_gma_referral_source']['#access'] = FALSE;
//    $form['field_gma_referral_source'][LANGUAGE_NONE]['#default_value'][0] = 'Other';
//    $form['field_gma_acct_rel_mgr']['#access'] = FALSE;
//    $form['field_gma_other']['#access'] = FALSE;
//    $form['field_gma_other'][LANGUAGE_NONE][0]['value']['#default_value'] = 'Currently a Non-Alliance member';
//  }
//  else {
//    // Modify the Address' Fullname field label.
//    $form['field_gma_address'][LANGUAGE_NONE]['0']['name_block']['name_line']['#title'] = t('Contact Name');
//
//    // Validate acceptable domains as valid URLs.
//    $form['field_gma_acceptable_domains']['#element_validate'][] = '_intel_ea_module_domain_validate';
//
//    // Validate the username and email address and against existing accounts
//    // and validate acceptable domains as valid URLs.
//    $form['#validate'][] = '_intel_ea_module_general_membership_application_validate';
//
//    // Set up a submit handler to create the Primary Contact user and Company node.
//    $form['#submit'][] = '_intel_ea_module_general_membership_application_updates';
//    $form['actions']['submit']['#submit'][] = '_intel_ea_module_general_membership_application_updates';
//  }
//
//  // Set help text with links to agreement documents.
//  // Terms & Conditions (General Members)
//  $membership_terms_conditions = l(t('Membership Terms & Conditions'), file_create_url(file_load(4610)->uri), array('attributes' => array('target' => '_blank')));
//  $form['field_gma_terms_conditions'][LANGUAGE_NONE]['#description'] = t('View !membership_terms_conditions.', array('!membership_terms_conditions' => $membership_terms_conditions));
//
//  // Cancel and return to the Solutions Directory
//  $form['actions']['cancel'] = array(
//    '#markup' => l(t('Cancel Application'), '<front>', array('attributes' => array('class' => 'white-button'))),
//  );
//}

/**
 * Implements hook_preprocess_views_exposed_form().
 */
function intel_ea_module_preprocess_views_exposed_form(&$vars) {
  $form = $vars['form'];

  // Render combined sort field.
  if (isset($form['sort'])) {
    $form['sort']['#printed'] = FALSE;
    $vars['sort'] = drupal_render($form['sort']);

    // Rebuild the submit button.
    $form['submit']['#printed'] = FALSE;
    $vars['button'] = drupal_render_children($form);
  }
}


/**
 * Helper function to create the mdf_tool_login form.
 */
function _intel_ea_module_mdf_tool_login_form($form) {
  // Get variables to build the form.
  $mdf_login_variables = _intel_ea_module_mdf_login_variables();

  // Post the hidden form values to the external Hawkeye SSO.
  $form['#action'] = $mdf_login_variables['form_action'];
  $form['#id'] = 'mdf-tool-login-form';
  $form['#attributes'] = array('target' => '_blank');

  // Pass the static client name.
  $form['ClientName'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['client_name'],
  );

  // Pass the current user's ID.
  $form['UserName'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['user_id'],
  );

  // Pass the current time.
  $form['TimeStamp'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['t_time'],
  );

  // Pass the token request.
  $form['TokenRequest'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['token'],
  );

  // Give the user a button.
  $form['actions'] = array(
    '#type' => 'actions'
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Login to MDF Tool'),
  );

  return $form;
}

/**
 * Helper function to create the mdf_opp_login form.
 */
function _intel_ea_module_mdf_opp_login_form($form) {
  // Get variables to build the form.
  $mdf_login_variables = _intel_ea_module_mdf_login_variables();

  // Post the hidden form values to the external Hawkeye SSO.
  $form['#action'] = $mdf_login_variables['form_action'];
  $form['#id'] = 'mdf-opp-login-form';
  $form['#attributes'] = array('target' => '_blank');

  // Pass the static client name.
  $form['ClientName'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['client_name'],
  );

  // Pass the current user's ID.
  $form['UserName'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['user_id'],
  );

  // Pass the current time.
  $form['TimeStamp'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['t_time'],
  );

  // Pass the token request.
  $form['TokenRequest'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['token'],
  );

  // Give the user a button.
  $form['actions'] = array(
    '#type' => 'actions'
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Submit Application'),
  );

  return $form;
}

/**
 * Helper function to create the login form button for
 *  - cloud comarketing track block
 *  - iot comarketing track block
 */
function _intel_ea_module_comarketing_track_login_form($form) {
  // Get variables to build the form.
  $mdf_login_variables = _intel_ea_module_mdf_login_variables();

  // Post the hidden form values to the external Hawkeye SSO.
  $form['#action'] = $mdf_login_variables['form_action'];
  $form['#id'] = 'mdf-opp-login-form';
  $form['#attributes'] = array('target' => '_blank');

  // Pass the static client name.
  $form['ClientName'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['client_name'],
  );

  // Pass the current user's ID.
  $form['UserName'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['user_id'],
  );

  // Pass the current time.
  $form['TimeStamp'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['t_time'],
  );

  // Pass the token request.
  $form['TokenRequest'] = array(
    '#type' => 'hidden',
    '#value' => $mdf_login_variables['token'],
  );

  // Give the user a button.
  $form['actions'] = array(
    '#type' => 'actions'
  );
  $form['actions']['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Go to Co-Marketing Tool'),
  );

  return $form;
}

/**
 * Sets the appropriate roles based on the company field.
 *
 * @return renderable array
 *
 * @see inte_ea_module_form_alter()
 */
function _intel_ea_module_user_form_available_roles($form, $form_state) {
  if (isset($form['account']['roles_container']['roles'])) {
    $key = 'roles';
  }
  elseif (isset($form['account']['roles_container']['roles_change'])) {
    $key = 'roles_change';
  }

  // Load the selected company.
  if (isset($form_state['values']['field_company']['und'][0]['target_id'])) {
    $company = node_load($form_state['values']['field_company']['und'][0]['target_id']);
  }
  elseif (isset($form['#entity']->field_company['und'][0]['target_id'])) {
    $company = node_load($form['#entity']->field_company['und'][0]['target_id']);
  }

  // If a company was loaded.
  if (isset($company)) {
    // Attempt to restrict options based on current company.
    if ($form['account']['roles_container'][$key]['#options'] = _intel_ea_module_company_roles($company, $form['account']['roles_container']['#options'])) {
      // Loop through all roles returned.
      foreach (element_children($form['account']['roles_container'][$key]) as $option) {
        // Unset all roles not returned as acceptable above.
        if (!isset($form['account']['roles_container'][$key]['#options'][$option])) {
          unset($form['account']['roles_container'][$key][$option]);
        }
      }
    }
    else {
      unset($form['account']['roles_container'][$key]);
      drupal_set_message(t('Membership Type has not been set for !company, therefore user roles cannot be assigned.', array('!company' => $company->title)), 'warning');
      $form['account']['roles_container'][$key]['#markup'] = theme('status_messages', array('display' => 'warning'));
    }
  }

  return $form['account']['roles_container'];
}

/**
 * Limits the available roles on the user register and user edit forms.
 *
 * @see inte_ea_module_form_alter()
 */
function _intel_ea_module_user_form_limit_roles(&$form, &$form_state, $form_id) {
  // If the user can administer permissions.
  if (user_access('administer permissions')) {
    $key = 'roles';
  }
  // If the user has role delegation permissions.
  elseif (isset($form['account']['roles_change'])) {
    $key = 'roles_change';
  }

  if (isset($key)) {
    // Create an ajax container for roles positioned below the company field.
    $form['account']['roles_container'] = array(
      '#options' => $form['account'][$key]['#options'],
      '#weight' => $form['field_company']['#weight'] + .1,
      '#prefix' => '<div id="intel-ea-module-user-profile-form-roles">',
      '#suffix' => '</div>',
    );

    // Move roles into the container.
    $form['account']['roles_container'][$key] = $form['account'][$key];
    unset($form['account'][$key]);

    // If a company is selected.
    if (!empty($form['field_company']['und']['#default_value']) || isset($form_state['values']['field_company']['und'][0]['target_id'])) {
      // Update the roles a user can have based on the selected companies
      // Membership Type.
      $form['account']['roles_container'] = _intel_ea_module_user_form_available_roles($form, $form_state);
    }
    // If a company is not selected.
    else {
      // Remove the ability to alter the users roles.
      unset($form['account']['roles_container'][$key]);
    }

    // Add an ajax callback to the company field.
    $form['field_company']['und']['#ajax'] = array(
      'callback' => '_intel_ea_module_user_form_available_roles',
      'wrapper' => 'intel-ea-module-user-profile-form-roles',
      'effect' => 'fade',
    );

    // Move the company field into the account container.
    $form['account']['field_company'] = $form['field_company'];
    unset($form['field_company']);
  }
}

/**
 * AJAX callback for Current Agreement Identifier field to set
 * allowed values for Current Membership Type field.
 */
function _intel_ea_module_company_node_set_current_membership_type($form, $form_state) {
  if (isset($form_state['values'])) {
    $form['field_membership_type'][LANGUAGE_NONE]['#value'] = _intel_ea_module_company_node_get_membership_type($form_state['values']['field_agreement_identifier'][LANGUAGE_NONE][0]['tid']);
  }
  else {
    $form['field_membership_type'][LANGUAGE_NONE]['#value'] = _intel_ea_module_company_node_get_membership_type($form['field_agreement_identifier'][LANGUAGE_NONE]['#default_value'][0]);
  }

  foreach ($form['field_membership_type'][LANGUAGE_NONE]['#options'] as $tid => $name) {
    if ($tid != $form['field_membership_type'][LANGUAGE_NONE]['#value']) {
      unset($form['field_membership_type'][LANGUAGE_NONE]['#options'][$tid]);
    }
  }

  return $form['field_membership_type'];
}

/**
 * AJAX callback for Future Membership field to set
 * allowed values for Future Membership Type field.
 */
function _intel_ea_module_company_node_set_future_membership_type($form, $form_state) {
  if (isset($form_state['values'])) {
    $form['field_future_membership_type'][LANGUAGE_NONE]['#value'] = _intel_ea_module_company_node_get_membership_type($form_state['values']['field_future_membership'][LANGUAGE_NONE][0]['tid']);
  }
  else {
    $form['field_future_membership_type'][LANGUAGE_NONE]['#value'] = _intel_ea_module_company_node_get_membership_type($form['field_future_membership'][LANGUAGE_NONE]['#default_value'][0]);
  }

  foreach ($form['field_future_membership_type'][LANGUAGE_NONE]['#options'] as $tid => $name) {
    if ($tid != $form['field_future_membership_type'][LANGUAGE_NONE]['#value']) {
      unset($form['field_future_membership_type'][LANGUAGE_NONE]['#options'][$tid]);
    }
  }

  return $form['field_future_membership_type'];
}

/**
 * Handles submission of the content_access_page form.
 */
function _intel_ea_module_content_access_page_submit($form, &$form_state) {
  // Reindex any search indexes the node is indexed in.
  if (!empty($form_state['node']->nid)) {
    search_api_track_item_change('node', array($form_state['node']->nid));
  }
}

/**
 * Enables companion roles when a role is enabled.
 *
 * @TODO: Review for relevance.
 */
//function _intel_ea_module_user_form_role_companions_callback($form, $form_state) {
//  // If the user can administer permissions.
//  if (user_access('administer permissions')) {
//    $key = 'roles';
//  }
//  // If the user has role delegation permissions.
//  elseif (isset($form['account']['roles_container']['roles_change'])) {
//    $key = 'roles_change';
//  }
//
//  if (isset($key)) {
//    // Get the currently selected role ids.
//    $rids = array_filter($form_state['values']['roles']);
//    // Add any missing companion role ids.
//    $updated_rids = _intel_ea_module_companion_roles($rids);
//    // Calculate role ids that were missing/added.
//    $missing_rids = array_diff($updated_rids, $rids);
//
//    // Select roles that were missing.
//    foreach ($missing_rids as $rid) {
//      $form['account']['roles_container'][$key][$rid]['#default_value'] = $rid;
//      $form['account']['roles_container'][$key][$rid]['#value'] = $rid;
//      $form['account']['roles_container'][$key][$rid]['#checked'] = 1;
//    }
//
//    $form['account']['roles_container'][$key]['message'] = array(
//      '#type' => 'markup',
//      '#markup' => theme('status_messages', array('display' => 'warning')),
//      '#weight' => $form['account']['roles_container'][$key]['#weight'] - .1,
//    );
//  }
//
//  return $form['account']['roles_container'];
//}

/**
 * Alter forms limiting available companies to that of the current user.
 */
function _intel_ea_module_form_limit_companies(&$form, &$form_state, $form_id) {
  global $user;

  try {
    if ($user->uid > 0) {
      $wrapper = entity_metadata_wrapper('user', $user);

      $form['field_company']['und']['#disabled'] = TRUE;
      $form['field_company']['und']['#default_value'] = $wrapper->field_company->nid->value();
    }
  }
  catch (exception $e) {
    watchdog_exception('intel_ea_module', $e);
  }
}
