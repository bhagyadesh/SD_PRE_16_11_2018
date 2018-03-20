<?php
/**
 * @file
 * The primary PHP file for this theme.
 */

module_load_include('inc', 'facetapi', 'facetapi.theme');

function intel_isdm_bootstrap_preprocess_html(&$vars) {
    drupal_add_library('system', 'ui');
}

/**
 * Implements template_preprocess_panels_pane().
 */
function intel_isdm_bootstrap_preprocess_panels_pane(&$vars) {
    global $language;
    $language_code = in_array($language->language, array('en', 'ja', 'zh-hans')) ? $language->language : 'en';

    // If the panels pane is the node's pre-release flag.
    if ($vars['pane']->type == 'entity_field' && $vars['pane']->subtype == 'node:field_pre_release') {
        // If the node is flagged as pre-release show the 'pre-release' badge.
        if ($vars['content'][0]['#markup'] == 'True') {
            $theme_path = drupal_get_path('theme', 'intel_isdm_bootstrap');
            $vars['content'] = theme('image', array('path' => "$theme_path/images/badge-pre-release-$language_code.png", 'alt' => t('Pre-Release')));
        }
        // Otherwise, output no content.
        else {
            $vars['content'] = '';
        }
    }
}

/**
 * @TODO: Document what/why and place proper comments.
 */
function intel_isdm_bootstrap_preprocess_page(&$vars) {
  global $user;
  $user_fields = user_load($user->uid);

  // If user has a first name, stash it for usage as a template variable.
  if($user_fields->field_first_name){
    $vars['first_name'] = $user_fields->field_first_name['und'][0]['safe_value'];
  }
    
  if ($user->uid != 0) {
      // Code for the account and logout button
      $vars['primary_links'] = "<a href='/user/logout'>" . t('Sign Out') . "</a>";
  }
  else {
    // Only SSO Login at this time.
    $vars['primary_links'] =  "<a href='/saml_login'>" . t('Login') . "</a>";
  }

  //Add search box to pages that do not contain member roster or are full nodes.

  // initialize values.
  $render_search = FALSE;
  $search_box = '';

  // Make sure that the path isn't member roster or if so it's a company.
  if(strpos(request_uri(), 'member-roster') === FALSE ){
    $render_search = TRUE;
  }
  else{
    // Check for menu object to determine if it's a company node type.
    $menu_object = menu_get_object();
    if (isset($menu_object->type) && $menu_object->type == 'company') {
      $render_search = TRUE;
    }
  }

  // Check if render search ha been marked as true.
  if($render_search){
    // Get search box form item for rendering.
    $search_form = drupal_get_form('intel_isdm_module_site_search_form');
    $search_box = drupal_render($search_form);
  }

  // Render search box.
  $vars['search_box'] = $search_box;
}

/*
 * Returns values to quote button for individual solutions in the solutions
 * directory. Evaluates user type to figure out which form to send you to
 */
function intel_isdm_bootstrap_company_quote_link() {
  $output = '';
  global $base_url;
  $aprimo_base = 'http://edc.intel.com/get-help/solutions-directory/';

    // The URL of the solution.
    $current_path = current_path();
    $current_path_alias = drupal_get_path_alias($current_path);
    $return_url = $base_url . '/' . $current_path_alias;

    // Load the object for the current page.
    $node = menu_get_object();

  // Get title of product being viewed
  $product_title = $node->title;

    $company = node_load($node->field_company['und'][0]['target_id']);

    // The title of the company associated with the solution.
    $company_name = $company->title;

    // retrieves tier information, which is returned as an array per tier
    $company_tiers = $company->field_membership_tier['und'];

    // Load taxonomy, get tree
    $vocabulary = taxonomy_vocabulary_machine_name_load('membership_tier');
    $terms = taxonomy_get_tree($vocabulary->vid);

    // count number of arrays to get a number to use as x in for loop
    $count_arrays = count($company_tiers);

    // Iterate through membership tier arrays to get compare info
   for ($x = 0; $x <= $count_arrays; $x++) {
      $show_terms[] = $company->field_membership_tier['und'][$x]['tid'];
   }

    // iterate through terms and arrays to create an array of terms that are specific
    // to the company being viewed
    foreach($terms as $term) {
      foreach($show_terms as $show_term) {
        if($term->tid == $show_term) {
          $get_tiers[] = $term->name;
        }
      }
    }

    // Setup a couple of comparison arrays
    // TODO: Build these arrays by programatically extracting from $vocabulary/$terms
    $itp = array("ITP", "Platinum", "Gold", "Registered");
    $isa = array("ISA", "Premier", "Associate", "Affiliate", "General");

    // Loop through $membership_items, setup bool values
    $is_itp = array_intersect($get_tiers, $itp) ? TRUE : FALSE;
    $is_isa = array_intersect($get_tiers, $isa) ? TRUE : FALSE;

    // compare bool vals to determine which form to send user to
    if (($is_itp) && (!$is_isa)) {
      $itp_base = 'https://techprovider.intel.com/solutions-directory';
      // array to build up url and return values for button text and button
      // class
	$output ='<div class="req">';
      $output .= l(t('Request Quote'), $itp_base, array(
        'attributes' => array(
          'class' => array('btn-primary', 'btn'),
        )));
	$output .='</div>';
      return $output;
    }
    else {
      // array to build up url and return values for button text and button class
	$output ='<div class="req">';
      $output .= l(t('Request Quote'), $aprimo_base, array('query' => array(
        'q' => $product_title,
        'cp' => strtolower('EA - ' . $company_name),
        'returnurl' => $return_url,
      ), 'attributes' => array(
          'class' => array('btn', 'btn-primary'),
      )));
	$output .='</div>';
      return $output;
    }
}

/*
 * Returns values to 'Contact Intel' button for individual solutions in
 * the solutions directory.
 */
function intel_isdm_bootstrap_contact_intel_link() {
  global $base_url;
  $aprimo_base = 'http://edc.intel.com/get-help/solutions-directory/';

  // Load the object for the current page.
  $node = menu_get_object();

  // The URL of the solution.
  $current_path = current_path();
  $current_path_alias = drupal_get_path_alias($current_path);
  $return_url = $base_url . '/' . $current_path_alias;

  // The name of the product
  $product_title = $node->title;

  // Load node representing company
  $company = node_load($node->field_company['und'][0]['target_id']);

  // The title of the company associated with the solution.
  $company_name = $company->title;

  // retrieves tier information, which is returned as an array per tier
  $company_tiers = $company->field_membership_tier['und'];

  // Load taxonomy, get tree
  $vocabulary = taxonomy_vocabulary_machine_name_load('membership_tier');
  $terms = taxonomy_get_tree($vocabulary->vid);

  // count number of arrays to get a number to use as x in for loop
  $count_arrays = count($company_tiers);

  // Iterate through membership tier arrays to get compare info
  for ($x = 0; $x <= $count_arrays; $x++) {
    $show_terms[] = $company->field_membership_tier['und'][$x]['tid'];
  }

  // iterate through terms and arrays to create an array of terms that are specific
  // to the company being viewed
  foreach($terms as $term) {
    foreach($show_terms as $show_term) {
      if($term->tid == $show_term) {
        $get_tiers[] = $term->name;
      }
    }
  }
  // Setup a couple of comparison arrays
  // TODO: Build these arrays by programatically extracting from $vocabulary/$terms
  $itp = array("ITP", "Platinum", "Gold", "Registered");
  $isa = array("ISA", "Premier", "Associate", "Affiliate", "General");

  // Loop through $membership_items, setup bool values
  $is_itp = array_intersect($get_tiers, $itp) ? TRUE : FALSE;
  $is_isa = array_intersect($get_tiers, $isa) ? TRUE : FALSE;

  // compare bool vals to determine which form to send user to
  // If company is ITP only, do not return a 'Contact Intel' button
  if (($is_itp) && (!$is_isa)) {
    $output = "";
    return $output;
  }
  // if company is ISA, return a 'Contact Intel' button
  else {
    // Array to build up URL for aprimo system
$output ='<div class="contact-intel">';
    $output .= l(t('Contact Intel'), $aprimo_base, array(
      'query' => array(
        'q' => $product_title,
        'cp' => strtolower('EA - Intel Corporation'),
        'returnurl' => $return_url,
      ),
      'attributes' => array(
        'class' => array('lbl'),
      )
    ));
$output .='</div>';
    return $output;
  }
}

//Theme hook suggestions to add new templates for solutions
function intel_isdm_bootstrap_preprocess_node(&$vars) {
    global $base_url;
    $theme_path = drupal_get_path('theme', 'intel_isdm_bootstrap');

    global $language;
    $language_code = in_array($language->language, array('en', 'ja', 'zh-hans')) ? $language->language : 'en';

    if($vars['view_mode'] == 'individual_solution') {
        $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__individual_solution';
        drupal_add_js(path_to_theme('intel_isdm_bootstrap') . '/js/solution-expander.js');
    } elseif($vars['view_mode'] == 'solution_list') {
        $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__solution_list';

        // If the node is flagged as pre-release show the
        // 'pre-release' badge just before the product image.
        if (isset($vars['field_pre_release'][0]['value']) && $vars['field_pre_release'][0]['value'] == 1) {
            $vars['content']['field_pre_release_badge'] = array(
                '#type' => 'html_tag',
                '#tag' => 'div',
                '#value' => theme('image', array('path' => "$theme_path/images/badge-pre-release-$language_code.png", 'alt' => t('Pre-Release'))),
                '#attributes' => array(
                    'class' => 'field-name-field-pre-release-badge',
                ),
                '#weight' => $vars['content']['field_image']['#weight'] - .1,
            );
        }

    }
}


//Help function to render blocks programmatically in templates
function block_render($module, $block_id) {
    $block = block_load($module, $block_id);
    $block_content = _block_render_blocks(array($block));
    $build = _block_get_renderable_array($block_content);
    $block_rendered = drupal_render($build);
    return $block_rendered;
}


//Fix facet labels on member roster
function intel_isdm_bootstrap_facetapi_link_active(&$variables) {
    $variables['text']=str_replace("node entity referenced from field_company » Market Segments","Market Segments",$variables['text']);
    $variables['text']=str_replace("node entity referenced from field_company » Geographic Location (product or service available in:)","Geographic Location",$variables['text']);
    $variables['text']=str_replace("node entity referenced from field_company » Categories","Categories",$variables['text']);
    $variables['text']=str_replace("node entity referenced from field_company » Processors","Processors",$variables['text']);


    // Sanitizes the link text if necessary.
    $sanitize = empty($variables['options']['html']);
    $link_text = ($sanitize) ? check_plain($variables['text']) : $variables['text'];

    $accessible_vars = array(
        'text' => $variables['text'],
        'active' => TRUE,
    );

    // Builds link, passes through t() which gives us the ability to change the
    // position of the widget on a per-language basis.
    $replacements = array(
        '!facetapi_deactivate_widget' => theme('facetapi_deactivate_widget', $variables),
        '!facetapi_accessible_markup' => theme('facetapi_accessible_markup', $accessible_vars),
    );
    $variables['text'] = t('!facetapi_deactivate_widget !facetapi_accessible_markup', $replacements);
    $variables['options']['html'] = TRUE;
    return theme_link($variables) . $link_text;
}
