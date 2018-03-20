<?php

/**
 * @file
 * This file contains functions rendering content. This can be block
 * content, forms, anything of that variety.
 */


/**
 * Function to output the content of an MDF login block.
 *
 * @param $block
 *   The name of the block.
 * @return string
 *   The output string.
 *
 * @TODO: Review this as it is highly suspect of not being in use anymore.
 */
function _intel_ea_module_mdf_login_contents($block) {
  switch ($block) {
    case 'mdf_tool_login':
      global $user;
      if (array_intersect($user->roles, array('Alliance Staff Admin', 'Intel Admin', 'Intel Market Development Manager'))) {
        $output = l(t('Intel Login to MDF Tool'), 'https://www.channelconduit.com/', array('attributes' => array('class' => 'blue-button')));
        break;
      }
      else {
        $output = drupal_get_form('_intel_ea_module_mdf_tool_login_form');
        break;
      }
    case 'mdf_opp_login':
      $output = drupal_get_form('_intel_ea_module_mdf_opp_login_form');
      break;
  }

  return $output;
}


/**
 * Helper function to output the content of member_roster_print.
 */
function _intel_ea_module_member_roster_print_contents() {
  $output = l(t('Printable Roster'), 'member-roster/print', array('attributes' => array('class' => array('white-button'), 'target' => '_blank')));

  return $output;
}

/**
 * Helper function to output the content of Aprimo button blocks.
 */
function _intel_ea_module_aprimo_btn_contents($button, $field_company = NULL, $field_company_nid = NULL) {
  $output = '';

  global $base_url;
  $aprimo_base = 'http://edc.intel.com/get-help/solutions-directory-member/';

  // Load the object for the current page.
  $node = menu_get_object();

  // The URL of the solution.
  $current_path = current_path();
  $current_path_alias = drupal_get_path_alias($current_path);
  $return_url = $base_url . '/' . $current_path_alias;

  // Conduct different operations for solutions, formulas and companies.
  switch ($node->type) {
    case 'solution':
      // The title of the solution.
      $product_title = $node->title;

      // The title of the company associated with the solution.
      $company = node_load($node->field_company['und'][0]['target_id']);
      $company_name = $company->title;
      break;
    case 'formula':
      // The title of the formula.
      $product_title = $node->title;

      // The title of the company associated with the formula.
      $company = node_load($node->field_company['und'][0]['target_id']);
      $company_name = $company->title;

      // The names of any companies listed as integrators.
      $system_integrators = array();
      if (!empty($node->field_system_integrators)) {
        foreach ($node->field_system_integrators[LANGUAGE_NONE] as $system_integrator) {
          $integrator = node_load($system_integrator['target_id']);
          $system_integrators[$system_integrator['target_id']] = $integrator->title;
        }
      }
      break;
    case 'company':
      // The name of the company.
      $company_name = $node->title;
      break;
  }

  // Create the output for the button.
  switch ($button) {
    case 'company':
      // If the company is Intel output nothing.
      if ($node->field_company['und'][0]['target_id'] == 145) {
        $output = '';
      }
      else {
        $output = l(t('Request Quote'), $aprimo_base, array('query' => array(
          'q' => $product_title,
          'cp' => strtolower('EA - ' . $company_name),
          'returnurl' => $return_url,
        ), 'attributes' => array(
          'class' => array('white-button btn'),
        )));
      }
      break;
    case 'intel':
      $output = l(t('Contact Intel'), $aprimo_base, array('query' => array(
        'q' => $product_title,
        'cp' => strtolower('EA - Intel Corporation'),
        'returnurl' => $return_url,
      ), 'attributes' => array(
        'class' => array('white-button btn'),
      )));
      break;
    case 'contact':
      $output = l(t('Request Quote'), $aprimo_base, array('query' => array(
        'cp' => strtolower('EA - ' . $company_name),
        'returnurl' => $return_url,
      ), 'attributes' => array(
        'class' => array('white-button btn'),
      )));
      break;
    case 'contact-member':
      // Determine if company is ISA or not.
      //if(intel_ea_module_is_company_isa($node)){
        $output = l(t('Request Information'), $aprimo_base, array('query' => array(
          'cp' => strtolower('EA - ' . $company_name),
          'returnurl' => $return_url,
        ), 'attributes' => array(
          'class' => array('btn-primary btn'),
        )));
      /*The if-else is commented out to make contact-member button appear for all members ISA or ITP
        }
      else{
        $output = '';
      }*/
      break;
    case 'integrator':
      if (!empty($system_integrators)) {
        foreach ($system_integrators as $integrator_nid => $integrator_name) {
          $items[] = l(t('Request Quote ') . $integrator_name . ' >', $aprimo_base, array('query' => array(
            'q' => $product_title,
            'cp' => strtolower('EA - ' . $integrator_name),
            'returnurl' => $return_url,
          ), 'attributes' => array(
            'class' => array('node-company-' . $integrator_nid),
          )));
        }
        $output = theme('item_list', array('items' => $items));
      }
      break;
    case 'field_company':
      $output = l(t('Request Quote >'), $aprimo_base, array('query' => array(
        'q' => $product_title,
        'cp' => strtolower('EA - ' . $field_company),
        'returnurl' => $return_url,
      ), 'attributes' => array(
        'class' => array('node-company-' . $field_company_nid),
      )));
      break;
  }

  return $output;
}
/*
 * Helper function for outputing a conditional title for breadcrumb
 */
function _intel_ea_module_mrc_breadcrumb() {
  if(intel_ea_module_is_user_alliance_member()){
    return '<div class="breadcrumb">Member Resource Center</div>';
  }
  else{
    return '<div class="breadcrumb">Partner Resource Center</div>';
  }
}
/*
 * Helper function for conditionally displaying header graphic
 */
function _intel_ea_module_mrc_header_graphic() {
  if(intel_ea_module_is_user_alliance_member()){
    return '<div class="alliance">Alliance Member Resource Center</div>';
  }
  else{
    return '<div class="nonalliance">Non Alliance Member Resource Center</div>';
  }
}

/**
 * Helper function to output the content of intel_contact_links.
 */
function _intel_ea_module_intel_contact_links() {
  $items = array(
    l(t('-  Primary Contact'), 'mailto:dan.hascall@intel.com'),
    l(t('-  Secondary Contact'), 'mailto:jason.m.burris@intel.com'),
    //l(t('Contact Us'), 'mailto:intel.communications.alliance.admin@intel.com'),
    l(t('-  EDC Support'), 'http://www.intel.com/content/www/us/en/intelligent-systems/embedded-design-center-contact-us.html'),
  );

  return theme('item_list', array('items' => $items));
}

/*
 * Helper function for displaying company programs info into block
 */
function _intel_ea_module_mrc_user_programs_links() {
  // Initialize output variable.
  $output = '';

  // If user's company in a program, add program contact info.
  if ($user_programs = intel_ea_module_get_user_program()){
    // Intialize items array for creating a themed item list.
    $items = array();
    // Loop through all program TID's.
    foreach($user_programs as $program){
      // Handle each possible program contact output as needed.
      switch($program->tid){
        // ISV
        case 1155:
          $key_contact = '<a href="mailto:dan.hascall@intel.com">Dan Hascall</a>';
          $secondary_contact = '<a href="mailto:jason.m.burris@intel.com">Jason Burris</a>';
          break;

        // DISTI program
        case 1156:
          $key_contact = '<a href="mailto:mark.vaiciulis@intel.com">Mark Vaiciulis</a>';
          $secondary_contact = '<a href="mailto:felix@inteliotsolutionsalliance.com">Felix McNulty</a>';
          break;

        // GPM: IOT
        case 1157:
          $key_contact = '<a href="mailto:peggy.mahler@intel.com">Peggy Mahler</a>';
          $secondary_contact = '<a href="mailto:serena@inteliot.partners">Serena Haak</a>';
          break;

        // GPM: Cloud
        case 1158:
          $key_contact = '<a href="mailto:robert.rollinger@intel.com">Robert Rollinger</a>';
          //$secondary_contact = '<a href="mailto://XXX@XXX.com">USER NAME</a>';
          break;
      }
      // Build contact output up, with optional secondary contact.
      $contact_output = '<h2 class="block-title">' . $program->name . '</h2>';
      $contact_output .= '<p>' . t('Key Contact: ') . $key_contact ;
      if ($secondary_contact) {
        $contact_output .= '<br/>' . t('Secondary Contact: ') . $secondary_contact;
      }
      $contact_output .= '</p>';

      // Add contact output to list items array.
      $items[] = $contact_output;
    }
    // Append item list to the information.
    $output .= theme_item_list(array(
      'items' => $items,
      'type' => 'ul',
      'attributes' => array(),
    ));
  }
  return $output;
}
/**
 * Helper function to output the content of mrc_help_links.
 */
function _intel_ea_module_mrc_help_links() {
  // Build output for general contact email.
  // Get user's company program TID.
  $user_membership_type = intel_ea_module_get_user_company_tid();
  // General mail for general Members.
  if ($user_membership_type == 560) {
    $mailto = 'mailto:embedded.alliance.general.membership@intel.com';
  }
  // Email for all "Upper-tier" Ie non-general Members.
  else {
    $mailto = 'mailto:intel.communications.alliance.admin@intel.com';
  }

  // Append contact information to the bottom of output.
  $output = '';
  $output .= '<p>' . t('For help with this website') . ' – ' . l(t('Contact Us >'), $mailto) . '</p>';

  return $output;
}


/**
 * Returns a renderable list of Member Resource Center Membership links.
 */
function _intel_ea_module_mrc_membership() {
  try{
    global $language;
    global $user;
    $account = entity_metadata_wrapper('user', $user);
    $items = array();

    // Add a Membership Benefits and Expectations link.
    if ($benefits_expectations = _intel_ea_module_benefits_expectations($account->field_company->field_membership_type->raw())) {
      $items[] = $benefits_expectations;
    }

    // Add a Participation Criteria link.
    if ($participation_criteria = _intel_ea_module_participation_criteria($account->field_company->field_membership_type->raw(), $account->field_company->field_agreement_identifier->raw())) {
      $items[] = $participation_criteria;
    }

    // Add program Participation Criteria links.
    $items = array_merge($items, _intel_ea_module_user_program_participation_criteria($account->field_company));

    // Add an Business Overview link.
    // Evaluate whether or not user is alliance, render link for alliance only
    if(intel_ea_module_is_user_alliance_member()){
      if ($business_overview = l(t('ISG Business Overview'), 'member-resource-center/business-overview')) {
        $items[] = $business_overview;
      }
    }

    // Add a Terms & Conditions link.
    // Evaluate whether or not user is alliance, render link for alliance only
    if(intel_ea_module_is_user_alliance_member()){
      if ($terms_conditions = _intel_ea_module_membership_terms_conditions($account->field_company->field_membership_type->raw())) {
        $items[] = $terms_conditions;
      }
    }
    // use 'global $language' to determine users language and make a decision on
    // the appropriate file to use
    switch ($language->language) {
      case 'ja':
        $pgmcloudtncs = file_create_url(file_load(14078)->uri);
        $pgmiottncs = file_create_url(file_load(14078)->uri);
        break;

      case 'zh-hans':
        $pgmcloudtncs = file_create_url(file_load(14077)->uri);
        $pgmiottncs = file_create_url(file_load(14077)->uri);
        break;

      case 'en':
      default:
        $pgmcloudtncs = file_create_url(file_load(14021)->uri);
        $pgmiottncs = file_create_url(file_load(14021)->uri);
        break;
    }
    // Add a Terms & Conditions based on users company program[s]
    if ($user_programs = intel_ea_module_get_user_program()) {
      // Loop through all program TID's.
      foreach ($user_programs as $program) {
        // evaluate user program to determine which T&Cs appear in the 'Membership/Partnership Information' block
        // PMG: IOT == 1157
        if ($program->tid == 1157) {
          //this is a 'place holder' file
          $pgmiot_terms_conditions = l(t('Advantage Program Terms & Conditions'), $pgmiottncs);
          $items[] = $pgmiot_terms_conditions;
        }
        // PMG: Cloud == 1158
        if ($program->tid == 1158) {
          //this is a 'place holder' file
          $pgmcloud_terms_conditions = l(t('Advantage Program Terms & Conditions'), $pgmcloudtncs);
          $items[] = $pgmcloud_terms_conditions;
        }
      }
    }
    return array(
      '#items' => $items,
      '#theme' => 'item_list',
    );
  }
  catch (exception $e) {
    watchdog_exception('intel_ea_module', $e);
    return FALSE;
  }
}
/*
 * Returns a renderable list of links for Gateway request and support info
 */
function _intel_ea_module_mrc_request_gateway_kit() {
  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('Order a Free Intel IoTG Gateway Kit'),
  );
  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      l(t('Information on ordering Intel IoTG Gateway Kit'), 'information-ordering-intel-iotg-gateway-kit') . '<br />' .
      l(t('Hardware Demo Kit Request'), 'eform/submit/order-free-intel-iotg-gateway') . '<br />' .
      l(t('Register Hardware Demo Kit'), 'register-your-hardware-kit') . '<br />' .
      l(t('Order Software Kit'), 'http://avnetexpress.avnet.com/store/em/EMController/Intel/IOTGTWY-SK50/_/R-5004473540700/A-5004473540700/An-0?action=part&catalogId=500201&langId=-1&storeId=500201&listIndex=-1&page=1&rank=0') . '<br /><p />' .
      // @TODO: Upload PDF for this link.
      l(t('Intel Launch Update'), 'http://www.intel.com'),
  );
  // Get all programs for a user/company
  if ($user_programs = intel_ea_module_get_user_program()) {
    // Loop through all program TID's.
    foreach ($user_programs as $program) {
      // evaluate user program to determine whether or not to out block
      // looking for 1155, ISV
      if ($program->tid == 1155) {
        return $output;
      }
    }
  }
}
/*
 * Returns content for 'Cloud Service Provider Co-Marketing Track' block
 */
function _intel_ea_module_mrc_cloud_co_marketing_track() {
  global $language;

  // Get user object built for access to entity properties
  global $user;
  $account = user_load($user->uid);
  $wrapped_account = entity_metadata_wrapper('user', $account);
  $user_company = $wrapped_account->field_company->value()->vid;

  // company vids for 'Intel' & 'Intel Partner Advantage Program'
  $intel_company_vids = array(56375, 57326);

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => 'As a Member of our program, your company has the opportunity to participate in a co-marketing initiative to promote your Intel-based Cloud Service to the business audience. View materials below to participate in this program.',
  );
  // Defines fid for appropriate file
  $training_materials_file = file_create_url(file_load(14123)->uri);
  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => l(t('Training Materials'), $training_materials_file),
  );
  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => 'Co-Marketing Resources',
  );

  // use 'global $language' to determine users language and make a decision on
  // the appropriate file to use
  switch ($language->language) {
    case 'ja':
      $reimbursement_policy_id = file_create_url(file_load(14075)->uri);
      break;

    case 'zh-hans':
      $reimbursement_policy_id = file_create_url(file_load(14076)->uri);
      break;

    case 'en':
    default:
      $reimbursement_policy_id = file_create_url(file_load(14074)->uri);
      break;
  }
  // The following variable block defines file fid's to use for links
  // ToDo: When files supporting other languages are available, put variables
  // inside of language switch block
  $comarkteing_program_guidance_file = file_create_url(file_load(14122)->uri);
  $brand_guidelines_file = file_create_url(file_load(14121)->uri);
  $activities_catalog_file = file_create_url(file_load(14120)->uri);
  $intel_logo_usage_guidelines_file = file_create_url(file_load(14073)->uri);

  // build statement of links for Intel/Intel partner advantage program users
  // and regular users. The 'Go To Co-Marketing Tool' redirect is dynamic based
  // on users being Intel/Intel partner advantage program
  if(in_array($user_company, $intel_company_vids)) {
    $output[] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' =>
        l(t('Co-Marketing Program Guidance'), $comarkteing_program_guidance_file) . '<br />' .
        l(t('Brand Guidelines Document'), $brand_guidelines_file) . '<br />' .
        l(t('Activities Catalog'), $activities_catalog_file) . '<br />' .
        l(t('Intel Approved Campaign Portfolio'), '') . '<br />' .
        l(t('Intel Logo & Usage Guidelines'), $intel_logo_usage_guidelines_file) . '<br />' .
        l(t('Reimbursement Policies'), $reimbursement_policy_id) . '<br /><p />' .
        l(t('Go to Co-Marketing Tool'), 'https://www.channelconduit.com/', array('attributes' => array('class' => 'blue-button'))),
    );
  } else {
    $output[] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' =>
        l(t('Co-Marketing Program Guidance'), $comarkteing_program_guidance_file) . '<br />' .
        l(t('Brand Guidelines Document'), $brand_guidelines_file) . '<br />' .
        l(t('Activities Catalog'), $activities_catalog_file) . '<br />' .
        l(t('Intel Approved Campaign Portfolio'), '') . '<br />' .
        l(t('Intel Logo & Usage Guidelines'), $intel_logo_usage_guidelines_file) . '<br />' .
        l(t('Reimbursement Policies'), $reimbursement_policy_id) . '<br /><p />' ,
    );
  }

  // redirect to form if not Intel/Intel partner advantage program users 
  if(!in_array($user_company, $intel_company_vids)) {
    $output[] = drupal_get_form('_intel_ea_module_comarketing_track_login_form');
  }

  // Get all programs for a user/company
  if ($user_programs = intel_ea_module_get_user_program()) {
    // Loop through all program TID's.
    foreach ($user_programs as $program) {
      // evaluate user program to determine whether or not to out block
      // looking for 1157, GPM: IOT
      if ($program->tid == 1158) {
        return $output;
      }
    }
  }
}
/*
 * Returns content for IoT Co-Marketing Track block
 */
function _intel_ea_module_iot_comarketing_track() {
  global $language;

  // Get user object built for access to entity properties
  global $user;
  $account = user_load($user->uid);
  $wrapped_account = entity_metadata_wrapper('user', $account);
  $user_company = $wrapped_account->field_company->value()->vid;

  // company vids for 'Intel' & 'Intel Partner Advantage Program'
  $intel_company_vids = array(56375, 57326);

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('As a Member of our program, your company has the opportunity to participate in a co-marketing initiative to promote your Intel-based IoT end-to-end solution to the business audience. View the materials below to participate in this program.'),
  );
  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      l(t('Training Materials'), file_create_url(file_load(15387)->uri)) . '<br />',
  );
  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('Co-Marketing Resources'),
  );

  // use 'global $language' to determine users language and make a decision on
  // the appropriate file to use
  switch ($language->language) {
    case 'ja':
      $reimbursement_policy_id = file_create_url(file_load(14075)->uri);
      break;

    case 'zh-hans':
      $reimbursement_policy_id = file_create_url(file_load(14076)->uri);
      break;

    case 'en':
    default:
      $reimbursement_policy_id = file_create_url(file_load(14074)->uri);
      break;
  }

  // build statement of links for Intel/Intel partner advantage program users
  // and regular users. The 'Go To Co-Marketing Tool' redirect is dynamic based
  // on users being Intel/Intel partner advantage program
  if(in_array($user_company, $intel_company_vids)) {
    $output[] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' =>
        l(t('Co-Marketing Program Guidance'), '') . '<br />' .
        l(t('Activities Catalogue'), file_create_url(file_load(15362)->uri)) . '<br />' .
        l(t('Media Programs'), '') . '<br />' .
        l(t('Intel Logo & Usage Guidelines'), file_create_url(file_load(14073)->uri)) . '<br />' .
        l(t('Reimbursement Policies'), $reimbursement_policy_id) . '<br /><p />' . '<br />' .
        l(t('Go to Co-Marketing Tool'), 'https://www.channelconduit.com/', array('attributes' => array('class' => 'blue-button'))) ,
    );
  } else {
    $output[] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' =>
        l(t('Co-Marketing Program Guidance'), '') . '<br />' .
        l(t('Activities Catalogue'), file_create_url(file_load(15362)->uri)) . '<br />' .
        l(t('Media Programs'), '') . '<br />' .
        l(t('Intel Logo & Usage Guidelines'), file_create_url(file_load(14073)->uri)) . '<br />' .
        l(t('Reimbursement Policies'), $reimbursement_policy_id) . '<br /><p />' . '<br />' ,
    );
  }

  // redirect to form if not Intel/Intel partner advantage program
  if(!in_array($user_company, $intel_company_vids)) {
    $output[] = drupal_get_form('_intel_ea_module_comarketing_track_login_form');
  }

  // Get all programs for a user/company
  if ($user_programs = intel_ea_module_get_user_program()) {
    // Loop through all program TID's.
    foreach ($user_programs as $program) {
      // evaluate user program to determine whether or not to out block
      // looking for 1157, GPM: IOT
      if ($program->tid == 1157) {
        return $output;
      }
    }
  }
}
/**
 * Returns a renderable list of Member Resource Center Membership links.
 */
function _intel_ea_module_mrc_marketing_programs() {
  global $language;
  global $user;
  $account = user_load($user->uid);
  $company = node_load($account->field_company['und'][0]['target_id']);
  $output = array();

  // Add links based on company membership type.
  switch ($company->field_membership_type['und'][0]['tid']) {
    // Premier Member.
    case 557:
      // Associate Member.
    case 558:
      // Affiliate Member.
    case 559:
      // Intel Member.
    case 562:
      // Alliance Staff Member.
    case 556:
      $presentation_slides = l(t('2015 Presentation Slides'), file_create_url(file_load(13661)->uri)) . '<br />';
      $past_materials = l(t('View Past Marketing Plans of Record'), 'member-resource-center/alliance-marketing-por');
      break;

    // General Member.
    case 560:
      $presentation_slides = l(t('2015 Presentation Slides'), file_create_url(file_load(13661)->uri)) . '<br />';
      $past_materials = l(t('View Past Marketing Plans of Record'), 'member-resource-center/past-alliance-marketing-plans-record');
      break;

    default:
      $presentation_slides = '';
      break;
  }

  // Add links based on language.
  switch ($language->language) {
    case 'ja':
      $am_por_presentation_script = file_create_url(file_load(3249)->uri);
      $business_it_professionals_presentation_script = file_create_url(file_load(9941)->uri);
      $sd_dmr_presentation_script = file_create_url(file_load(3282)->uri);
      $sd_training_manual = file_create_url(file_load(3389)->uri);
      $md_dmr_training_manual = file_create_url(file_load(3748)->uri);
      $presentation_script = file_create_url(file_load(7490)->uri);
      break;

    case 'zh-hans':
      $am_por_presentation_script = file_create_url(file_load(3248)->uri);
      $business_it_professionals_presentation_script = file_create_url(file_load(9940)->uri);
      $sd_dmr_presentation_script = file_create_url(file_load(3281)->uri);
      $sd_training_manual = file_create_url(file_load(3390)->uri);
      $md_dmr_training_manual = file_create_url(file_load(3747)->uri);
      $presentation_script = file_create_url(file_load(7491)->uri);
      break;

    case 'en':
    default:
      $am_por_presentation_script = file_create_url(file_load(3234)->uri);
      $business_it_professionals_presentation_script = file_create_url(file_load(9855)->uri);
      $sd_dmr_presentation_script = file_create_url(file_load(3280)->uri);
      $sd_training_manual = file_create_url(file_load(13098)->uri);
      $md_dmr_training_manual = file_create_url(file_load(13097)->uri);
      $presentation_script = file_create_url(file_load(7489)->uri);
      break;
  }

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('Intel® IoT Solutions Alliance Marketing programs are designed to amplify joint messages to the industry and position Member companies as thought leaders and technology experts. These marketing efforts, made available in multiple languages, drive awareness and over time generate business leads for Members and Intel.'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('Alliance Marketing Plan of Record'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      l(t('Webinar Training Video'), 'member-resource-center/video/1' , array(
          'html' => TRUE,
          'attributes' => array(
            'rel' => array('colorbox-gallery'),
            'class' => array('colorbox')
          )
        )
      ) . '<br />' .
      $presentation_slides .
      l(t('2014 Presentation Script'), $presentation_script) . '<br />' .
      $past_materials,
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('Embedded Innovator'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      l(t('Editorial Calendar'), 'member-resource-center/embedded-innovator-article-opportunities') . '<br />' .
      l(t('Submit an Abstract'), 'mailto:mark@inteliotsolutionsalliance.com') . '<br />' .
      l(t('!year Media Kit', array('!year' => '2016')), file_create_url(file_load(13733)->uri)) . '<br />' .
      l(t('View Past Publications'), 'https://www-ssl.intel.com/content/www/us/en/intelligent-systems/alliance-embedded-innovator-magazine.html'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('Intel® Embedded Community'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      l(t('Register to the Community'), 'http://embedded.communities.intel.com/create-account.jspa') . '<br />' .
      l(t('Request Posting Privileges'), 'mailto:felix@inteliotsolutionsalliance.com?subject=Request Document Posting Privileges on Community') . '<br />' .
      l(t('Community Training'), file_create_url(file_load(2753)->uri)),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('Solutions Directory and Dynamic Member Roster'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      t('Business and Developers View Training Webinar') . '<br />' .
      l(t('Webinar Training Video'), 'member-resource-center/video/5' , array(
          'html' => TRUE,
          'attributes' => array(
            'rel' => array('colorbox-gallery'),
            'class' => array('colorbox'),
          ),
        )
      ) . '<br />' .
      l(t('Webinar Training Slides'), file_create_url(file_load(13662)->uri)) . '<br />' .
      l(t('Presentation Script'), $business_it_professionals_presentation_script) . '<br />'
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      t('Solutions Directory and Dynamic Member Roster Training Webinar') . '<br />' .
      l(t('Webinar Training Video'), 'member-resource-center/video/2' , array(
          'html' => TRUE,
          'attributes' => array(
            'rel' => array('colorbox-gallery'),
            'class' => array('colorbox')
          )
        )
      ) . '<br />' .
      l(t('Webinar Training Slides'), file_create_url(file_load(13663)->uri)) . '<br />' .
      l(t('Presentation Script'), $sd_dmr_presentation_script) . '<br />'
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      l(t('Solutions Directory Training Manual'), $sd_training_manual) . '<br />' .
      l(t('Members Database and Dynamic Member Roster Training Manual'), $md_dmr_training_manual) . '<br />' .
      l(t('Solutions Directory Marketplace Newsletter Archives'), 'solutions-directory/newsletter-archive'),
  );

  return $output;
}

/**
 * Returns a renderable list of Member Resource Center Member Trainings/Events.
 *
 * @TODO: Determine if this is relevant anymore.
 */
function _intel_ea_module_mrc_member_trainings_events() {
  global $user;
  $account = user_load($user->uid);
  $company = node_load($account->field_company['und'][0]['target_id']);
  $cnda = FALSE;
  // Connections Event Presentations
  $preso = FALSE;

  // Add links based on company membership type.
  switch ($company->field_membership_type['und'][0]['tid']) {
    // Premier Member.
    case 557:
      // Associate Member.
    case 558:
      // Affiliate Member.
    case 559:
      // Intel Member.
    case 562:
      // Alliance Staff Member.
    case 556:
      $output[] = array(
        '#theme' => 'html_tag',
        '#tag' => 'p',
        '#value' => t('New training coming soon. See the links below for presentations from previous trainings.') . '<br />',
      );

      // Add link based on user role.
      $preso_roles = array(
        'Executive',
        'Primary Co-Marketing (MDF) Contact',
        'Co-Marketing (MDF) Contact',
        'Primary Contact',
        'Primary Marketing Contact',
        'Primary Sales Contact',
        'Alliance Staff Admin',
        'Alliance Staff Employee',
        'Intel Admin',
        'Intel Employee'
      );
      foreach ($preso_roles as $role) {
        if (in_array($role, $account->roles)) {
          $preso = TRUE;
        }
      }
      $cnda = TRUE;
      break;

    default:
      if (isset($company->field_cnda['und'])) {
        $cnda = TRUE;
      }
  }

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      ($cnda ? l(t('View Archived Trainings'), 'member-resource-center/events/webinars') : l(t('View Archived Trainings'), 'member-resource-center/events/webinars-public')) .
      ($preso ? '<br />' . l(t('View Connections Event Presentations'), 'member-resource-center/business-connections') : ''),
  );

  return $output;
}

/**
 * Returns a renderable list for the Member Resource Center Market Development
 * Fund.
 */
function _intel_ea_module_mrc_co_marketing_programs() {
  global $language;

  // Funding Calendar access.
  $funding_access = '';
  // Co-Marketing access.
  $cmt_access = '';
  $output = array();

  // Add links based on language.
  switch ($language->language) {
    case 'ja':
      $presentation_script = file_create_url(file_load(13703)->uri);
      break;

    case 'zh-hans':
      $presentation_script = file_create_url(file_load(13702)->uri);
      break;

    case 'en':
    default:
      $presentation_script = file_create_url(file_load(13704)->uri);
      break;
  }

  // Add links based on company membership type.
  switch (intel_ea_module_get_user_company_tid()) {
    // Premier Member.
    case 557:
      $funding_access = l(t('Funding Calendar'), 'co-marketing-tool/funding-calendar-mdf-campaign') . '<br />';
      $cmt_access = l(t('Log onto the Co-Marketing Center'), 'co-marketing-tool') . '<br />';
      $training_manual = l(t('Training Manual - English'), file_create_url(file_load('8884')->uri));
      break;

    // Associate Member, intel member, and alliance staff member.
    case 558: case 562: case 556:
    $funding_access = l(t('Funding Calendar'), 'co-marketing-tool/funding-calendar-mdf-activity') . '<br />';
    $cmt_access = l(t('Log onto the Co-Marketing Center'), 'co-marketing-tool') . '<br />';

    switch ($language->language) {
      case 'ja':
        $training_manual_id = 13700;
        break;

      case 'zh-hans':
        $training_manual_id = 13699;
        break;

      case 'en':
      default:
        $training_manual_id = 13701;
        break;
    }
    break;

    // Affiliate Member.
    case 559:
      $funding_access = l(t('Funding Calendar'), 'co-marketing-tool/funding-calendar-mdf-activity') . '<br />';
      $cmt_access = l(t('Log onto the Co-Marketing Center'), 'co-marketing-tool') . '<br />';

      switch ($language->language) {
        case 'ja':
          $training_manual_id = 13698;
          break;

        case 'zh-hans':
          $training_manual_id = 13697;
          break;

        case 'en':
        default:
          $training_manual_id = 13696;
          break;
      }
      break;
  }

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('Market Development Funds are available for Members to request for underwriting of designated Preferred Co-Marketing Activities. Calls-to-participate, submissions and payout are driven by an established Funding Cycle Calendar. For complete guidelines go the Co-Marketing site.'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'h3',
    '#value' => t('Training Materials'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      l(t('Webinar Training Video'), 'member-resource-center/video/3' , array(
          'html' => TRUE,
          'attributes' => array(
            'rel' => array('colorbox-gallery'),
            'class' => array('colorbox')
          )
        )
      ) . '<br />' .
      l(t('Webinar Training Slides'), file_create_url(file_load(13664)->uri)) . '  <br />' .
      l(t('Presentation Script'), $presentation_script) . '<br />' .
      ($training_manual_id ? l(t('Training Manual'), file_create_url(file_load($training_manual_id)->uri)) : $training_manual) . '<br />' .
      $funding_access,
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => $cmt_access,
  );

  return $output;
}

/**
 * Returns a renderable list for the Member Resource Center Market Development
 * Fund.
 *
 * @TODO: Redo all of these variable names to be properly explicit.
 */
function _intel_ea_module_mrc_program_newsletters() {
  global $user;
  $account = user_load($user->uid);
  $general_member = 560;

  $wrapped_account = entity_metadata_wrapper('user', $account);

  // Check that the company has a field membership type.
  if($wrapped_account->field_company->__isset('field_membership_type')){
    // Get User membership TID.
    // @TODO: Fix this variable name to be more explicit.
    $user_tid = $wrapped_account->field_company->field_membership_type->value()->tid;
  }
  else{
    // Assign user manual value of general member.
    $user_tid = 560;
  }


  // this is a set of newsletters that only 'general members' see
  if($user_tid ==  $general_member) {
    $output = array();
    $output[] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' =>
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q1', '!year' => '2016')), 'http://createsend.com/t/r-7A2C03668E68446B2540EF23F30FEDED') . '<br />' .
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q4', '!year' => '2015')), 'http://createsend.com/t/r-A133E38FE49600F12540EF23F30FEDED') . '<br />' .
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q3', '!year' => '2015')), 'http://createsend.com/t/r-D4AE4A91CDA02ADD2540EF23F30FEDED') . '<br />' .
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q2', '!year' => '2015')), 'http://createsend.com/t/r-638A2307E9DE6B702540EF23F30FEDED') . '<br />' .
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q1', '!year' => '2015')), 'http://createsend.com/t/r-656DC5D6F4BA4AC42540EF23F30FEDED') . '<br />' ,
    );
    // Premier, Associate and Affiliate see these newsletters
  } else {
    $output = array();
    $output[] = array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' =>
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q1', '!year' => '2016')), 'http://createsend.com/t/r-A68230240BD9D7F72540EF23F30FEDED') . '<br />' .
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q4', '!year' => '2015')), 'http://createsend.com/t/r-A133E38FE49600F12540EF23F30FEDED') . '<br />' .
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q3', '!year' => '2015')), 'http://createsend.com/t/r-D4AE4A91CDA02ADD2540EF23F30FEDED') . '<br />' .
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q2', '!year' => '2015')), 'http://createsend.com/t/r-638A2307E9DE6B702540EF23F30FEDED') . '<br />' .
        l(t('!quarter !year Member Newsletter', array('!quarter' => 'Q1', '!year' => '2015')), 'http://createsend.com/t/r-656DC5D6F4BA4AC42540EF23F30FEDED') . '<br />' ,
    );
  }
  $output[] = array(
    '#theme' => 'link',
    '#text' => t('Subscribe to Member Newsletter'),
    '#path' => 'user/' . $user->uid . '/edit',
    '#options' => array(
      'attributes' => array(),
      'html' => FALSE,
    ),
    '#prefix' => '<p>',
    '#suffix' => '</p>',
  );

  return $output;
}

/**
 * Returns a renderable list for the Member Resource Center Lead Generation.
 */
function _intel_ea_module_mrc_leads_management_system() {
  $output = array();

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('Aprimo is an easy-to-use online tool for Members to receive, manage and process contacts and leads from Alliance-driven Marketing programs.'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      l(t('FAQs'), file_create_url(file_load(3078)->uri)) . '<br />' .
      l(t('Training Materials'), file_create_url(file_load(3077)->uri)) . '<br />' .
      l(t('Edit Member Contacts for Leads System'), 'member-resource-center/manage-users') . '<br />' .
      l(t('Login to Leads Management System'), 'https://ilms.intel.com'),
  );

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('Technical support, contact') . ':<br />' .
      t('Critical') . ': 1-877-425-3249<br />' .
      t('Non-Critical') . ': IBLAdmin@intel.com<br />',
  );

  return $output;
}

/**
 * Returns a renderable list for the Member Resource Center Brand Programs.
 */
function _intel_ea_module_mrc_brand_programs() {
  global $user;
  $account = user_load($user->uid);
  $company = node_load($account->field_company['und'][0]['target_id']);
  $output = array();

  // Determine if the company is a HW Provider.
  $hw_provider = (isset($company->field_agreement_identifier['und']) && in_array($company->field_agreement_identifier['und'][0]['tid'], array(613, 614, 615))) ? TRUE : FALSE;
  // Determine if the company is an Intel or Alliance Staff member.
  $staff = (in_array($company->field_membership_type['und'][0]['tid'], array(562, 556))) ? TRUE : FALSE;

  if ($hw_provider || $staff) {
    $links = '';

    // Add links based on company membership type.
    $usage_guidelines = _intel_ea_module_usage_guidelines($company->field_membership_type['und'][0]['tid']);

    $links =
      $usage_guidelines . '<br />' .
      l(t('Brand Advantage Program'), 'member-resource-center/intel-brand-advantage-program') . '<br />' .
      l(t('Supports Intel® Atom™ Locked Logo'), 'member-resource-center/supports-intel-atom-locked-logo') . '<br />' .
      l(t('Webinar Training Video'), 'member-resource-center/video/4' , array(
          'html' => TRUE,
          'attributes' => array(
            'rel' => array('colorbox-gallery'),
            'class' => array('colorbox')
          )
        )
      ) . '<br />' .
      l(t('Usage Presentation'), file_create_url(file_load(4626)->uri)) . ' (pdf 520Kb)';

    $output[] =  array(
      '#theme' => 'html_tag',
      '#tag' => 'p',
      '#value' => $links,
    );
  }

  return $output;
}

/**
 * Returns a renderable list for the Member Resource Center Marketing Support
 * Materials.
 */
function _intel_ea_module_mrc_marketing_support_materials() {
  $company_tid = intel_ea_module_get_user_company_tid();
  $output = array();

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' => t('These support materials are designed to assist Members in creating marketing materials and proof points to ensure best presence in outbound marketing efforts.'),
  );

  // Original Press release guidelines.
  //$press_release_guidelines = l(t('Press Release Guidelines'), file_create_url(file_load(3066)->uri));

  // Bring in product launch kit for regular users.
  $product_launch_kits = l(t('Product Launch Kits'), 'member-resource-center/launch-kits');

  // Add member plaque request link if user is alliance member.
  if (intel_ea_module_is_user_alliance_member()) {
    $usage_guidelines = _intel_ea_module_usage_guidelines($company_tid);
    $member_plaque_request = l(t('Member Plaque Order Request'), 'mailto:ei@cmdagency.com?subject=Alliance+Plaque+Order&body=o+Company+Name%3a%0d%0ao+Number+of+Plaques%3a%0d%0ao+Contact+Name%3a%0d%0ao+Shipping+Address%3a%0d%0ao+Phone+Number%3a');
    $press_release_guidelines = l(t('Press Release Guidelines'), file_create_url(file_load(12808)->uri));
  }

  $output[] = array(
    '#theme' => 'html_tag',
    '#tag' => 'p',
    '#value' =>
      (isset($usage_guidelines) ? $usage_guidelines . '<br />' : '') .
      l(t('Intel Trademark & Brand Usage Guidelines'), 'member-resource-center/co-marketing/trademarks') . '<br />' .
      l(t('Intel ARK Product Information'), 'http://ark.intel.com') . '<br />' .
      (isset($product_launch_kits) ? $product_launch_kits . '<br />' : '') .
      (isset($press_release_guidelines) ? $press_release_guidelines . '<br />' : '') .
      (isset($member_plaque_request) ? $member_plaque_request . '<br />' : ''),
  );

  return $output;
}

/**
 * Returns a renderable list of user statistics.
 */
function _intel_ea_module_user_statistics() {
  $items = array();
  $thirty_days_ago = time() - (30 * 24 * 60 * 60);

  // Get the number of active users.
  $query = new EntityFieldQuery();
  $active = $query
    ->entityCondition('entity_type', 'user')
    ->propertyCondition('uid', 1, '>')
    ->propertyCondition('status', 1, '=')
    ->count()
    ->execute();
  $items[]['data'] = t('!active Active', array('!active' => $active));

  // Get the number of inactive users.
  $query = new EntityFieldQuery();
  $inactive = $query
    ->entityCondition('entity_type', 'user')
    ->propertyCondition('uid', 1, '>')
    ->propertyCondition('status', 0, '=')
    ->count()
    ->execute();
  $items[]['data'] = t('!inactive Inactive', array('!inactive' => $inactive));

  // Get the total number of users.
  $items[]['data'] = t('!total Total', array('!total' => $active + $inactive));

  // Get the number of new users in the last 30 days.
  $query = new EntityFieldQuery();
  $new = $query
    ->entityCondition('entity_type', 'user')
    ->propertyCondition('uid', 1, '>')
    ->propertyCondition('created', $thirty_days_ago, '>=')
    ->count()
    ->execute();
  $items[]['data'] = t('!new New in the last 30 days', array('!new' => $new));

  return array(
    '#items' => $items,
    '#theme' => 'item_list',
  );
}

/**
 * Returns a renderable list of company statistics.
 */
function _intel_ea_module_company_statistics() {
  $items = array();
  $thirty_days_ago = time() - (30 * 24 * 60 * 60);

  // Get the number of active companies.
  $query = new EntityFieldQuery();
  $active = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'company')
    ->propertyCondition('status', 1)
    ->count()
    ->execute();
  $items[]['data'] = t('!active Active', array('!active' => $active));

  // Get the number of inactive companies.
  $query = new EntityFieldQuery();
  $inactive = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'company')
    ->propertyCondition('status', 0)
    ->count()
    ->execute();
  $items[]['data'] = t('!inactive Inactive', array('!inactive' => $inactive));

  // Get the total number of companies.
  $items[]['data'] = t('!total Total', array('!total' => $active + $inactive));

  // Get the number of new companies in the last 30 days.
  $query = new EntityFieldQuery();
  $new = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'company')
    ->propertyCondition('created', $thirty_days_ago, '>=')
    ->count()
    ->execute();
  $items[]['data'] = t('!new New in the last 30 days', array('!new' => $new));

  // Get the number of deactivated companies in the last 30 days.
  $query = new EntityFieldQuery();
  $deactivated = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'company')
    ->propertyCondition('status', 0, '=')
    ->propertyCondition('changed', $thirty_days_ago, '>=')
    ->count()
    ->execute();
  $items[]['data'] = t('!deactivated Deactivated in the last 30 days', array('!deactivated' => $deactivated));

  // Get the number of companies pending moderation.
  $pending_moderation = db_query("SELECT COUNT(*) FROM {node} n WHERE n.type = 'company' AND (n.vid < (SELECT MAX(nr.vid) FROM {node_revision} nr WHERE nr.nid = n.nid) OR (n.status = 0 AND (SELECT COUNT(nr.vid) FROM {node_revision} nr WHERE nr.nid = n.nid) = 1))")->fetchField();
  $items[]['data'] = t('!pending Pending Moderation', array('!pending' => $pending_moderation));

  // Get the number of companies pending a start date.
  $query = new EntityFieldQuery();
  $pending_start_date = db_query("SELECT COUNT(*) FROM {node} n LEFT JOIN {field_data_field_agreement_date} fad ON n.type = fad.bundle AND n.nid = fad.entity_id WHERE n.type = 'company' AND fad.field_agreement_date_value IS NULL")->fetchField();
  $items[]['data'] = t('!pending Pending Start Date', array('!pending' => $pending_start_date));

  // Get the number of companies with a current membership.
  $query = new EntityFieldQuery();
  $current = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'company')
    ->fieldCondition('field_agreement_date', 'value', date('Y-m-d H:i:s'), '>')
    ->count()
    ->execute();
  $items[]['data'] = t('!current Current', array('!current' => $current));

  // Get the number of companies with an expired membership.
  $query = new EntityFieldQuery();
  $expired = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'company')
    ->fieldCondition('field_agreement_date', 'value', date('Y-m-d H:i:s'), '<=')
    ->count()
    ->execute();
  $items[]['data'] = t('!expired Expired', array('!expired' => $expired));

  return array(
    '#items' => $items,
    '#theme' => 'item_list',
  );
}

function _intel_ea_module_download_pdf() {
  global $user;
  $account = user_load($user->uid);
  $output = array();

  switch ($account->field_company['und'][0]['target_id']) {
    case 3:
    case 31:
    case 34:
    case 36:
    case 40:
    case 63:
    case 60:
    case 79:
    case 86:
    case 87:
    case 145:
    case 3718:
    case 239:
    case 214:
    case 210:
    case 189:
    case 177:
    case 159:
    case 157:
    case 136:
    case 135:
    case 104:
    case 89:
    case 201:

      $output[] = array(
        '#theme' => 'html_tag',
        '#tag' => 'p',
        '#value' => '<h3><a href="/sites/default/files/DSMS%202014%20Showcase%20Package%20for%20web%20020714-1.pdf">DSMS 2014 Showcase Package.pdf</a></h3>',
      );
      break;
  }

  return $output;
}

/**
 * Returns a renderable list of company membership counts.
 */
function _intel_ea_module_company_memberships() {
  $items = array();

  // Loop through all Membership Segment terms.
  foreach (taxonomy_get_tree(26) as $term) {
    $query = new EntityFieldQuery();
    $count = $query
      ->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'company')
      ->fieldCondition('field_agreement_identifier', 'tid', $term->tid, '=')
      ->count()
      ->execute();
    $items[]['data'] = t('!count @term Memberships', array('!count' => $count, '@term' => $term->name));
  }

  return array(
    '#items' => $items,
    '#theme' => 'item_list',
  );
}

/**
 * Returns a renderable list of solution statistics.
 */
function _intel_ea_module_solution_statistics() {
  $items = array();
  $thirty_days_ago = time() - (30 * 24 * 60 * 60);

  // Get the number of active solutions.
  $query = new EntityFieldQuery();
  $active = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'solution')
    ->propertyCondition('status', 1)
    ->count()
    ->execute();
  $items[]['data'] = t('!active Active', array('!active' => $active));

  // Get the number of inactive solutions.
  $query = new EntityFieldQuery();
  $inactive = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'solution')
    ->propertyCondition('status', 0)
    ->count()
    ->execute();
  $items[]['data'] = t('!inactive Inactive', array('!inactive' => $inactive));

  // Get the total number of solutions.
  $items[]['data'] = t('!total Total', array('!total' => $active + $inactive));

  // Get the number of new solutions in the last 30 days.
  $query = new EntityFieldQuery();
  $new = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'solution')
    ->propertyCondition('created', $thirty_days_ago, '>=')
    ->count()
    ->execute();
  $items[]['data'] = t('!new New in the last 30 days', array('!new' => $new));

  // Get the number of deactivated solutions in the last 30 days.
  $query = new EntityFieldQuery();
  $deactivated = $query
    ->entityCondition('entity_type', 'node')
    ->entityCondition('bundle', 'solution')
    ->propertyCondition('status', 0, '=')
    ->propertyCondition('changed', $thirty_days_ago, '>=')
    ->count()
    ->execute();
  $items[]['data'] = t('!deactivated Deactivated in the last 30 days', array('!deactivated' => $deactivated));

  // Get the number of solutions pending moderation.
  $pending_moderation = db_query("SELECT COUNT(*) FROM {node} n WHERE n.type = 'solution' AND (n.vid < (SELECT MAX(nr.vid) FROM {node_revision} nr WHERE nr.nid = n.nid) OR (n.status = 0 AND (SELECT COUNT(nr.vid) FROM {node_revision} nr WHERE nr.nid = n.nid) = 1))")->fetchField();
  $items[]['data'] = t('!pending Pending Moderation', array('!pending' => $pending_moderation));

  return array(
    '#items' => $items,
    '#theme' => 'item_list',
  );
}

/**
 * Helper function to output a link to a user's Terms & Conditions
 * based on company membership type.
 *
 * @param $membership_type
 *  The membership type of the company related to the user.
 * @return string
 *  The Drupal formatted link as a string.
 */
function _intel_ea_module_membership_terms_conditions($membership_type, $target = null) {
  $fid = NULL;

  switch ($membership_type) {
    // General Member.
    case 560:
      $fid = 4610;
      break;

    // Premier Member.
    case 557:
      // Associate Member.
    case 558:
      // Affiliate Member.
    case 559:
      // Intel Member.
    case 562:
      // Alliance Staff Member.
    case 556:
      $fid = 2752;
      break;
  }

  $attributes = array();
  if ($target) {
    $attributes['target'] = '_blank';
  }

  return l(t('Advantage Program Terms & Conditions'), file_create_url(file_load($fid)->uri), $attributes);
}

/**
 * Returns a link to a user's Benefits & Expectations document.
 *
 * @param $membership_type
 *   The membership type of the user's company.
 */
function _intel_ea_module_benefits_expectations($membership_type) {
  switch ($membership_type) {
    // Premier Member.
    case 557:
      return l(t('Membership Benefits & Expectations'), 'member-resource-center/benefits-expectations/premier');

    // Associate Member.
    case 558:
      return l(t('Membership Benefits & Expectations'), 'member-resource-center/benefits-expectations/associate');

    // Affiliate Member.
    case 559:
      return l(t('Membership Benefits & Expectations'), 'member-resource-center/benefits-expectations/affiliate');

    // General Member.
    case 560:
      return l(t('Membership Benefits & Expectations'), 'member-resource-center/benefits-expectations/general');

    // Intel Member.
    case 562:
      // Alliance Staff Member.
    case 556:
      return l(t('Membership Benefits & Expectations'), 'member-resource-center/benefits-expectations');
  }
}

/**
 * Helper function to output a link to a user's Participation Criteria
 * based on company parameters.
 *
 * @param int $membership_type
 *  The membership type of the company related to the user.
 *
 * @param int $agreement_identifier
 *  The agreement identifier of the company related to the user.
 *
 * @return string
 *  The Drupal formatted link as a string.
 */
function _intel_ea_module_participation_criteria($membership_type, $agreement_identifier) {
  $participation_criteria = null;

  switch ($membership_type) {
    // Premier Member.
    case 557:
      switch ($agreement_identifier) {
        // HW Providers.
        case 615:
          $participation_criteria = 2724;
          break;
      }
      break;

    // Associate Member.
    case 558:
      switch ($agreement_identifier) {
        // HW Providers.
        case 614:
          $participation_criteria = 2723;
          break;

        // Services.
        case 628:
          $participation_criteria = 2726;
          break;

        // SW Provider.
        case 632:
          $participation_criteria = 2728;
          break;

        // SW Provider Retail.
        case 1089:
          $participation_criteria = 11739;
          break;

        // PC ODM.
        case 622:
          $participation_criteria = 9822;
          break;

        // OS BIOS.
        case 624:
          $participation_criteria = 2731;
          break;

        // Systems Integrator.
        case 626:
          $participation_criteria = 2733;
          break;
      }
      break;

    // Affiliate Member.
    case 559:
      switch ($agreement_identifier) {
        // Comp SI.
        case 605:
          $participation_criteria = 2721;
          break;

        // HW Providers.
        case 613:
          $participation_criteria = 2722;
          break;

        // Services.
        case 627:
          $participation_criteria = 2725;
          break;

        // SW Provider.
        case 631:
          $participation_criteria = 2727;
          break;

        // SW Provider Retail.
        case 1088:
          $participation_criteria = 11738;
          break;

        // PC ODM.
        case 621:
          $participation_criteria = 2729;
          break;

        // OS BIOS.
        case 623:
          $participation_criteria = 2730;
          break;

        // Systems Integrator.
        case 625:
          $participation_criteria = 2732;
          break;
      }
      break;

    // Intel Member.
    case 562:
      // Alliance Staff Member.
    case 556:
      $participation_criteria = l(t('Your Participation Criteria'), 'member-resource-center/participation-criteria');
      break;
  }

  // If a participation criteria file ID is set, build a link.
  if (is_int($participation_criteria)) {
    return l(t('Your Participation Criteria'), file_create_url(file_load($participation_criteria)->uri), array('attributes' => array('target' => '_blank')));
  }
  elseif (is_string($participation_criteria)) {
    return $participation_criteria;
  }
}

/**
 * Returns a participation criteria link for a program.
 *
 * @param EntityDrupalWrapper $program
 *   The EntityDrupalWrapper object of a program taxonomy term.
 */
function _intel_ea_module_program_participation_criteria($program) {
  $participation_criteria = null;

  if ($program->field_participation_criteria->value()) {
    $participation_criteria = l(t('!program Participation Criteria', array('!program' => $program->name->value())), file_create_url($program->field_participation_criteria->value()['uri']), array('attributes' => array('target' => '_blank')));
  }

  return $participation_criteria;
}

/**
 * Returns program participation criteria links for a company'.
 *
 * @param EntityDrupalWrapper $company
 *   The EntityDrupalWrapper object of a company.
 */
function _intel_ea_module_user_program_participation_criteria($company) {
  $output = array();

  foreach ($company->field_programs as $program) {
    if ($participation_criteria = _intel_ea_module_program_participation_criteria($program)) {
      $output[] = $participation_criteria;
    }
  }

  return $output;
}

/**
 * Helper function to output a link to a user's Marks & Usage Guidelines
 * based on company membership type.
 *
 * @param $membership_type
 *  The membership type of the company related to the user.
 * @return string
 *  The Drupal formatted link as a string.
 */
function _intel_ea_module_usage_guidelines($membership_type, $file = FALSE, $target = NULL) {
  switch ($membership_type) {
    // Premier Member.
    case 557:
      $usage_guidelines = ($file) ? 12823 : 'member-resource-center/membermark/premier';
      break;

    // Associate Member.
    case 558:
      $usage_guidelines = ($file) ? 12822 : 'member-resource-center/membermark/associate';
      break;

    // Affiliate Member.
    case 559:
      $usage_guidelines = ($file) ? 12821 : 'member-resource-center/membermark/affiliate';
      break;

    // General Member.
    case 560:
      $usage_guidelines = ($file) ? 4632 : 'member-resource-center/membermark/general';
      break;

    // Intel Member OR Alliance Staff Admin.
    case 562:
    case 556:
      $usage_guidelines = 'member-resource-center/membermark';
      break;
  }

  if (is_int($usage_guidelines)) {
    $usage_guidelines = file_create_url(file_load($usage_guidelines)->uri);
  }

  $attributes = array();
  if ($target) {
    $attributes['target'] = '_blank';
  }

  return l(t('Alliance Member Marks & Usage Guidelines'), $usage_guidelines, $attributes);
}
