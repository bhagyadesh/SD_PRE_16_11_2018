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
    if ($vars['pane']->type == 'entity_field' && ($vars['pane']->subtype == 'node:field_access' || $vars['pane']->subtype == 'node:field_access_formula')) {
			
		if ($vars['content']['#object']->field_access['und'][0]['value'] == 2 || $vars['content']['#object']->field_access_formula['und'][0]['value'] == 2) {
			/* $theme_path = drupal_get_path('theme', 'intel_isdm_bootstrap');
			$vars['content']['#object']->field_pre_release['und'][0]['value'] = "$theme_path/images/restricted_products.png"; */
			// If the node is flagged as pre-release show the 'pre-release' badge.
		   if ($vars['content'][0]['#markup'] !== 'True') {
				$theme_path = drupal_get_path('theme', 'intel_isdm_bootstrap');
				$vars['content'] = theme('image', array('path' => "$theme_path/images/restricted_products.png", 'alt' => t('Resricted Content'),'#weight' => $vars['content']['field_image']['#weight'] - .1));
			}
			// Otherwise, output no content.
			else {
				$vars['content'] = '';
			}
		}
		else{
			$vars['content'] = '';
		}
    }
	if ($vars['pane']->type == 'entity_field' && $vars['pane']->subtype == 'node:field_pre_release') {
		$var['content'] = '';
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
  if (!empty($vars['node']) && arg(2) == 'edit') {
    $vars['theme_hook_suggestions'][] = 'page__node__' . $vars['node']->type .'__edit';
  }
  /**
  
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

  **/
  
  // Add search box in all the places
  $render_search = TRUE;
  $search_box = '';
  
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
function intel_isdm_bootstrap_company_quote_link($current_node) {
  $output = '';
  global $base_url;
  $aprimo_base = 'http://edc.intel.com/get-help/solutions-directory/';

    // The URL of the solution.
    $current_path = current_path();
    $current_path_alias = drupal_get_path_alias($current_path);
    $return_url = $base_url . '/' . $current_path_alias;

    // Load the object for the current page.
    if (!isset($current_node)) {
    $node = menu_get_object();
    $return_url = $base_url . '/' . $current_path_alias;
  }
  else
  {
    $node = node_load($current_node);
    $current_path_alias = drupal_get_path_alias('node/'.$node->nid);
    $return_url = $base_url . '/' . $current_path_alias;
  }

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
	//Handling the incoming source reference for tracking.
	  if ($_COOKIE['source_data']){

	  $output ='<div class="req">';

      $output .= l(t('Request Quote'), $aprimo_base, array('query' => array(
        'q' => $product_title,
        'cp' => strtolower('EA - ' . $company_name),
        'returnurl' => $return_url,
		'src'=> $_COOKIE['source_data'],
      ), 'attributes' => array(
          'class' => array('btn', 'btn-primary'),
      )));
	$output .='</div>';
	}
	else {
	$output ='<div class="req">';

      $output .= l(t('Request Quote'), $aprimo_base, array('query' => array(
        'q' => $product_title,
        'cp' => strtolower('EA - ' . $company_name),
        'returnurl' => $return_url,
      ), 'attributes' => array(
          'class' => array('btn', 'btn-primary'),
      )));
	$output .='</div>';
	}
      return $output;
    }
}

/*
 * Returns values to 'Contact Intel' button for individual solutions in
 * the solutions directory.
 */
function intel_isdm_bootstrap_contact_intel_link($current_node) {
  global $base_url;
  $aprimo_base = 'http://edc.intel.com/get-help/solutions-directory/';

  // Load the object for the current page.
  //$node = menu_get_object(); -- Commented and added after checking the current node

  // The URL of the solution.
  $current_path = current_path();
  $current_path_alias = drupal_get_path_alias($current_path);
  $return_url = $base_url . '/' . $current_path_alias;
  //To load the contact intel link in product compare view
  // Load the object for the current page.
  if (!isset($current_node)) {
    $node = menu_get_object();
    $return_url = $base_url . '/' . $current_path_alias;
  }
  else
  {
    $node = node_load($current_node);
    $current_path_alias = drupal_get_path_alias('node/'.$node->nid);
    $return_url = $base_url . '/' . $current_path_alias;
  }
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
//Adding soruce cookie data for traffic out flow
	if ($_COOKIE['source_data']){
$output ='<div class="contact-intel">';
    $output .= l(t('Contact Intel'), $aprimo_base, array(
      'query' => array(
        'q' => $product_title,
        'cp' => strtolower('EA - Intel Corporation'),
        'returnurl' => $return_url,
		'src'=> $_COOKIE['source_data'],
      ),
      'attributes' => array(
        'class' => array('lbl'),
      )
    ));
	$output .='</div>';
	}
	else {
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
	}
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
        if ($vars['field_access_formula']['und'][0]['value'] == 2) {
		//if($flag_the_solution){
            $vars['content']['field_pre_release_badge'] = array(
                '#type' => 'html_tag',
                '#tag' => 'div',
                //'#value' => theme('image', array('path' => "$theme_path/images/badge-pre-release-$language_code.png", 'alt' => t('Pre-Release'))),
				'#value' => theme('image', array('path' => "$theme_path/images/restricted_products.png", 'alt' => t('Restricted Content'))),
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

/* Fix for market-segment breadcrumb */
function intel_isdm_bootstrap_breadcrumb($variables) {
$breadcrumbs = $variables['breadcrumb'];
  if (!empty($breadcrumbs)) {

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';

    // Hide breadcrumb navigation if it contains only one element.
    $hide_single_breadcrumb = variable_get('path_breadcrumbs_hide_single_breadcrumb', 0);
    if ($hide_single_breadcrumb && count($breadcrumbs) == 1) {
      return FALSE;
    }

    // Bootstrap 3 compatibility. See: https://drupal.org/node/2178565
    if (is_array($breadcrumbs[count($breadcrumbs) - 1])) {
      array_pop($breadcrumbs);
    }

    // Add options for rich snippets.
    $elem_tag = 'span';
    $elem_property = '';
    $root_property = '';
    $options = array('html' => TRUE);
    $snippet = variable_get('path_breadcrumbs_rich_snippets', PATH_BREADCRUMBS_RICH_SNIPPETS_DISABLED);
    if ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_RDFA) {

      // Add link options for RDFa support.
      $options['attributes'] = array('rel' => 'v:url', 'property' => 'v:title');
      $options['absolute'] = TRUE;

      // Set correct properties for RDFa support.
      $elem_property = ' typeof="v:Breadcrumb"';
      $root_property = ' xmlns:v="http://rdf.data-vocabulary.org/#"';
    }
    elseif ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_MICRODATA) {

      // Add link options for microdata support.
      $options['attributes'] = array('itemprop' => 'url');
      $options['absolute'] = TRUE;

      // Set correct properties for microdata support.
      $elem_property = ' itemscope itemtype="http://schema.org/Thing"';
      $elem_tag = 'div';

      // Add style that will display breadcrumbs wrapped in <div> inline.
      drupal_add_css(drupal_get_path('module', 'path_breadcrumbs') . '/css/path_breadcrumbs.css');
    }

    foreach ($breadcrumbs as $key => $breadcrumb) {
      // Build classes for the breadcrumbs.
      $classes = array('inline');
      $classes[] = $key % 2 ? 'even' : 'odd';
      if ($key == 0) {
        $classes[] = 'first';
      }
      if (count($breadcrumbs) == $key + 1) {
        $classes[] = 'last';
      }

      // For rich snippets support all links should be processed in the same way,
      // even if they are provided not by Path Breadcrumbs module. So I have to
      // parse html code and create links again with new properties.
      preg_match('/href="([^"]+?)"/', $breadcrumb, $matches);

      // Remove base path from href.
      $href = '';
      if (!empty($matches[1])) {
        global $base_path;
        global $language_url;

        $base_string = rtrim($base_path, "/");

        // Append additional params to base string if clean urls are disabled.
        if (!variable_get('clean_url', 0)) {
          $base_string .= '?q=';
        }

        // Append additional params to base string for multilingual sites.
        // @note: Only core URL detection method supported.
        $enabled_negotiation_types = variable_get("language_negotiation_language", array());
        if (!empty($enabled_negotiation_types['locale-url']) && !empty($language_url->prefix)) {
          $base_string .= '/' . $language_url->prefix;
        }

        // Means that this is href to the frontpage.
        if ($matches[1] == $base_string || $matches[1] == '' || $matches[1] == '/') {
          $href = '';
        }
        // All hrefs exept frontpage.
        elseif (stripos($matches[1], "$base_string/") === 0) {
          $href = drupal_substr($matches[1], drupal_strlen("$base_string/"));
		    
        }
        // Other cases.
        else {
          // HREF param can't starts with '/'.
          $href = stripos($matches[1], '/') === 0 ? drupal_substr($matches[1], 1) : $matches[1];
		  
        }

        // If HREF param is empty it should be linked to a front page.
        $href = empty($href) ? '<front>' : $href;
      }
	  

      // Get breadcrumb title from a link like "<a href = "/path">title</a>".
      $title = trim(strip_tags($breadcrumb));

      // Wrap title in additional element for microdata support.
      if ($snippet == PATH_BREADCRUMBS_RICH_SNIPPETS_MICRODATA) {
        $title = '<span itemprop="name">' . $title . '</span>';
      }

      // Support title attribute.
      if (preg_match('/<a\s.*?title="([^"]+)"[^>]*>/i', $breadcrumb, $attr_matches)) {
        $options['attributes']['title'] = $attr_matches[1];
      }
      else {
        unset($options['attributes']['title']);
      }

      // Decode url to prevent double encoding in l().
      //$href = rawurldecode($href);
      // Move query params from $href to $options.
      $href = _path_breadcrumbs_clean_url($href, $options, 'none');

      // Build new text or link breadcrumb.
	  // Fixing market-segment issue (changed market-segments to market-segment)
	  $href_path = explode('/',$href);
	  if ($href_path[0] == "market-segments") {
		  $title_url = strtolower(str_replace(' ','-',$title));
		  $newhref = 'market-segment/'.$title_url;
	  } else {
		  $newhref  = $href;
	  }
      $new_breadcrumb = !empty($newhref) ? l(t($title), $newhref, $options) : t($title);
      // Replace old breadcrumb link with a new one.
      $breadcrumbs[$key] = '<' . $elem_tag . ' class="' . implode(' ', $classes) . '"' . $elem_property . '>' . $new_breadcrumb . '</' . $elem_tag . '>';
    }

    // Get breadcrumb delimiter and wrap it into <span> for customization.
    $delimiter = variable_get('path_breadcrumbs_delimiter', '»');
    $delimiter = '<span class="delimiter">' . trim($delimiter) . '</span>';

    $classes = array('breadcrumb');

    // Show contextual link if it is Path Breadcrumbs variant.
    $prefix = '';
    $path_breadcrumbs_data = path_breadcrumbs_load_variant(current_path());
    if (user_access('administer path breadcrumbs') && $path_breadcrumbs_data && isset($path_breadcrumbs_data->variant)) {
      $contextual_links = array(
        '#type' => 'contextual_links',
        '#contextual_links' => array('path_breadcrumbs' => array('admin/structure/path-breadcrumbs/edit', array($path_breadcrumbs_data->variant->machine_name))),
      );
      $prefix = drupal_render($contextual_links);
      $classes[] = 'contextual-links-region';
    }

    // Build final version of breadcrumb's HTML output.
    $output .= '<div class="' . implode(' ', $classes) . '"' . $root_property . '>' . $prefix . implode(" $delimiter ", $breadcrumbs) . '</div>';

    return $output;
	 }

  // Return false if no breadcrumbs.
  return FALSE;
}
/* refine by - qualified intel iot group by market segments */
/*function intel_isdm_bootstrap_preprocess_views_view(&$vars) {
	$view = $vars['view'];
	$new_array = array();
	//check the view
	if($view->name == 'intel_qualified_iot_solutions' && $view->current_display == 'block') {
			$results = &$view->result;
			foreach ($results as $key => $result) {
				foreach ($result->_field_data['nid']['entity']->field_market_segments['und'] as $k=>$v) {
					$market_segment[] = $v['tid'];
				}
			}
			$market_segment = array_unique($market_segment);
			foreach($market_segment as $k=>$v) {
				$new_array[$v] = array();
				foreach ($results as $k1 => $v1) {
					$ms = array();
					foreach ($v1->_field_data['nid']['entity']->field_market_segments['und'] as $k2=>$v2) {
						$ms[] = $v2['tid'];
					}
					$ms = array_unique($ms);
					if (in_array($v,$ms)) {
						$img_url = file_create_url($v1->_field_data['nid']['entity']->field_image['und'][0]['uri']);
						$company_title = node_load($v1->_field_data['nid']['entity']->field_company['und'][0]['target_id'])->title;
						$nodeurl = url('node/'. $v1->_field_data['nid']['entity']->nid);
						$new_entity = array("nid"=>$v1->_field_data['nid']['entity']->nid,"title"=>$v1->_field_data['nid']['entity']->title,"node_url"=>$nodeurl,"img_url"=>$img_url,"company_title"=>$company_title);
						$new_array[$v][] = $new_entity;
					}
				}
			}
			$output = '';
			foreach ($new_array as $key=>$value) {
				$count = count($value);
				$market_segment_term = taxonomy_term_load($key);
				$market_segment_name = $market_segment_term->name;
				$output .= '<div class="market_segment_group"><div class="market-segment-title"><span>'.$market_segment_name.'</span></div>';
				foreach ($value as $k=>$v) {
					if(($k+1) < 7) {
					$output .= "<div class='views-row views-row-".($k+1)."'>";
					$output .= '<div class="views-field views-field-field-image"><div class="field-content"><img typeof="foaf:Image" class="img-responsive" src="'.$v['img_url'].'" width="128" height="96" alt=""></div></div>';
					$output .= '<div class="views-field views-field-name-i18n"><span class="field-content"><a href="'.$v['node_url'].'">'.$v['title'].'</a></span></div>';
					$output .= '<div class="views-field views-field-description-i18n"><div class="field-content">'.$v['company_title'].'</div></div>';
					$output .= "</div>";
					}
					if(($k+1) > 6) {
						$iot_tid = key(taxonomy_get_term_by_name('Intel® IoT Market Ready Solutions'));
						$output .= "<a class='view_all_market_segment' href='/solutions-directory/field_intel_iot_market_ready_sol/$iot_tid/market_segments/$key'>View All</a>";
					}
				}
				$output .= "</div>";
			}
			$vars['rows'] = (!empty($view->result) || $view->style_plugin->even_empty()) ? $output : '';
		}		
}*/
/* privatemsg */
function intel_isdm_bootstrap_privatemsg_new_block($count) {
  $count = $count['count'];
  if ($count == 0) {
    $text = t('<img src="/sites/default/files/download-message.png"/>');
  }
  else {
    $text = format_plural($count, '<img src="/sites/default/files/download-message.png"/><div class="msg-count">@count</div>',
                        '<img src="/sites/default/files/download-message.png"/><div class="msg-count">@count</div>',
                        array('@count' => $count));
  }
  return l($text, 'messages', array('attributes' => array('id' => 'privatemsg-new-link'), 'html' => TRUE));
}
function intel_isdm_bootstrap_menu_local_action($variables) {
  $link = $variables['element']['#link'];
  if($link['href'] == 'messages/new') {
  $output = '<li>';
  if (isset($link['href'])) {
    $output .= "<a href='/messages/new' id='privatemsg-new-icon' class='active'><img src='/sites/default/files/download-message.png'></a>";
  }
  elseif (!empty($link['localized_options']['html'])) {
    $output .= 'New message';
  }
  else {
    $output .= check_plain($link['title']);
  }
  $output .= "</li>\n";
  }
  return $output;
}