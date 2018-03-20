<?php

/**
 * @FILE: If it's a form and it relates to intel SSO or ERPM, it will be here!
 */

/**
 * SSO Settings administrative form. Allows selecting which env and quickly
 * adjusting settings based on which environment code is placed in.
 */
function intel_ea_sso_erpm_settings_form($form, $form_state){
  // Initialize form.
  $form = array();

  // Enable ERPM integration checkbox.
  $form['erpm_enabled'] = array(
    '#type' => 'checkbox',
    '#title' => t('Enable ERPM integration.'),
    '#description' => t('ERPM may not be ready at time of site deployment. You can enable ERPM integration here. Not having ERPM integration allows SSO to continue functioning but bypasses reaching out to ERPM for users, and for companies on cron.'),
    '#default_value' => variable_get('intel_ea_sso_erpm_enabled', FALSE),
  );

  // Setup environment selector.
  $form['environment'] = array(
    '#type' => 'radios',
    '#title' => t('Environment Selector'),
    '#options' => array(
      'live' => t('Live'),
      'stage' => t('Stage'),
      'dev' => t('Dev'),
    ),
    '#default_value' => variable_get('intel_ea_sso_erpm_environment'),
    '#description' => t('Use this to choose which environment you are currently operating in. Saving will set all appropriate values.'),
    '#required' => TRUE,
  );

  // Add a submit button
  $form['submit'] = array('#type' => 'submit', '#value' => t('Adjust module settings for environment'));

  return $form;
}

/**
 * Administration form submission handler.
 *
 * Changes SimpleSAML variables based on environment selection.
 */
function intel_ea_sso_erpm_settings_form_submit($form, $form_state){
  // Store environment selection passed setting.
  variable_set('intel_ea_sso_erpm_environment', $form_state['values']['environment']);

  // Store ERPM integration variable.
  variable_set('intel_ea_sso_erpm_enabled', $form_state['values']['erpm_enabled']);

  // Take actions based on environment selected.
  switch ($form_state['values']['environment']){
    case 'dev':
      variable_set('simplesamlphp_auth_activate', TRUE);
      variable_set('simplesamlphp_auth_installdir', '/Users/jesse.nicola/Projects/simplesaml');
      variable_set('simplesamlphp_auth_authsource', 'simplesamldev');
      variable_set('simplesamlphp_auth_debug', TRUE);
      break;

    case 'stage':
      variable_set('simplesamlphp_auth_activate', TRUE);
      variable_set('simplesamlphp_auth_installdir', '/home/tngadmin/intel-simplesaml');
      variable_set('simplesamlphp_auth_authsource', 'simplesamlstage');
      variable_set('simplesamlphp_auth_debug', FALSE);
      break;

    case 'live':
      // @ TODO: Add correct values here when provided/available.
      variable_set('simplesamlphp_auth_activate', TRUE);
      variable_set('simplesamlphp_auth_installdir', '/var/intel-simplesaml');
      variable_set('simplesamlphp_auth_authsource', 'simplesamllive');
      variable_set('simplesamlphp_auth_debug', FALSE);
      break;
  }
}

/**
 * SSO Settings administrative form. Allows selecting which env and quickly
 * adjusting settings based on which environment code is placed in.
 */
function intel_ea_sso_erpm_credentials_form($form, $form_state){
  // Initialize form.
  $form = array();

  // Initialize values for whether companies and people are set.
  $companies_set = FALSE;
  $people_set = FALSE;

  // Check if values already stored for companies.
  if(variable_get('intel_ea_sso_erpm_companies_un') && variable_get('intel_ea_sso_erpm_companies_pw')){
    $companies_set = TRUE;
  }
  // Check if values already stored for people.
  if(variable_get('intel_ea_sso_erpm_people_un') && variable_get('intel_ea_sso_erpm_people_pw')){
    $people_set = TRUE;
  }

  //Fieldset for companies.
  $form['description'] = array(
    '#markup' => t('This form is used to store credentials for the ERPM. Updating a field here will update the corresponding stored value. If these are expanded, no credential set has been stored for that particular endpoint.'),
  );

  // Companies PW
  $form['intel_ea_sso_erpm_credentials_salt'] = array(
    '#type' => 'password',
    '#title' => t('Encryption Salt'),
    '#maxlength' => 64,
    '#size' => 15,
  );

  // Let user know if the salt has already been stored.
  if(variable_get('intel_ea_sso_erpm_credentials_salt')){
    $form['intel_ea_sso_erpm_credentials_salt']['#description'] = 'This value is currently already set in the Database.';
  }

  //Fieldset for companies.
  $form['companies'] = array(
    '#type' => 'fieldset',
    '#title' => t('ERPM Companies Endpoint'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );
  // Conditional markup for values being already in place.
  if($companies_set){
    $form['companies']['#collapsed'] =  TRUE;
    $form['companies']['set'] = array(
      '#markup' => t('Credentials stored for ERPM company endpoint'),
      '#attributes' => array('class' => 'warning'),
    );
  }
  // Companies PW
  $form['companies']['intel_ea_sso_erpm_companies_un'] = array(
    '#type' => 'password',
    '#title' => t('Username'),
    '#maxlength' => 64,
    '#size' => 15,
  );
  // Companies PW
  $form['companies']['intel_ea_sso_erpm_companies_pw'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#maxlength' => 64,
    '#size' => 15,
  );

  // People fieldset
  $form['people'] = array(
    '#type' => 'fieldset',
    '#title' => t('ERPM People Endpoint'),
    '#collapsible' => TRUE,
    '#collapsed' => FALSE,
  );

  // Conditional markup for values being already in place.
  if($people_set){
    $form['people']['#collapsed'] =  TRUE;
    $form['people']['set'] = array(
      '#markup' => t('Credentials stored for ERPM people endpoint'),
      '#attributes' => array('class' => 'warning'),
    );
  }

  // People UN.
  $form['people']['intel_ea_sso_erpm_people_un'] = array(
    '#type' => 'password',
    '#title' => t('Username'),
    '#maxlength' => 64,
    '#size' => 15,
  );
  // People PW.
  $form['people']['intel_ea_sso_erpm_people_pw'] = array(
    '#type' => 'password',
    '#title' => t('Password'),
    '#maxlength' => 64,
    '#size' => 15,
  );

  // Add a submit button.
  $form['submit'] = array('#type' => 'submit', '#value' => t('Store/Update API credentials'));

  return $form;
}

/**
 * Process the ERPM credentials form submission
 */
function intel_ea_sso_erpm_credentials_form_submit($form, $form_state){
  // Update/Set encryption salt if provided. Has to be done first and separately.
  if(isset($form_state['values']['intel_ea_sso_erpm_credentials_salt'])
    && !empty($form_state['values']['intel_ea_sso_erpm_credentials_salt'])){
    variable_set('intel_ea_sso_erpm_credentials_salt', $form_state['values']['intel_ea_sso_erpm_credentials_salt']);
    drupal_set_message(t('Updated ERPM credentials SALT'));
    unset($form_state['values']['intel_ea_sso_erpm_credentials_salt']);
  }

  // Loop through all submitted form values.
  foreach($form_state['values'] as $form_item => $value){
    // See if this is an ERPM value field, and if it has value.
    if(strpos($form_item, 'intel_ea_sso_erpm') !== FALSE
      && !empty($value)
    ){
      variable_set($form_item, intel_ea_sso_erpm_credentials_encrypt($value));
      drupal_set_message(t('Updated value for @', array('@'=> $form_item)));
    }
  }
}
