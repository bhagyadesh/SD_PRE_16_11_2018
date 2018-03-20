<?php

/**
 * @file
 * Imlementations of views hooks.
 */

/**
 * Implements hook_views_pre_view().
 */
function intel_ea_module_views_pre_view(&$view, &$display_id, &$args) {
  // Allow view-specific hooks, like hook_views_pre_view_VIEW_NAME().
  $function = __FUNCTION__ . "_$view->name";
  if (function_exists($function)) {
    $function($view, $display_id, $args);
  }
}

/**
 * Implements hook_views_pre_view_VIEW_NAME().
 */
function intel_ea_module_views_pre_view_google_analytics_reports(&$view, &$display_id, &$args) {
  $company = _intel_ea_module_google_analytics_reports_company_get();
  $start = _intel_ea_module_google_analytics_reports_start_get();
  $end = _intel_ea_module_google_analytics_reports_end_get();

  switch ($display_id) {
    case 'member':
    case 'member_request_quote':
    case 'member_website':
      $view->set_arguments(array($company, $start, $end));
      break;

    default:
      $view->set_arguments(array($start, $end));
      break;
  }
}

/**
 * Implements hook_views_pre_view_VIEW_NAME().
 */
function intel_ea_module_views_pre_view_current_user(&$view, &$display_id, &$args) {
  if ($display_id == 'primary_contact') {
    global $user;

    try {
     $wrapper = entity_metadata_wrapper('user', $user);
      $args[] = $wrapper->field_company->value()->tnid;
    }
    catch (exception $e) {
      watchdog_exception('intel_ea_module', $e);
    }
  }
}

/**
 * Implements hook_views_query_alter().
 */
function intel_ea_module_views_query_alter(&$view, &$query) {
  // Run view-specific functions, like hook_views_query_alter_{$view->name}().
  $function = __FUNCTION__ . "_$view->name";
  if (function_exists($function)) {
    $function($view, $query);
  }
}

/**
 * Implements hook_views_query_alter() for the company_solutions view.
 */
function intel_ea_module_views_query_alter_company_solutions(&$view, &$query) {
  $key = key($query->where[0]['conditions'][0]['value']);
  $node = node_load($query->where[0]['conditions'][0]['value'][$key]);
  $tnid = $node->tnid ? $node->tnid : $node->nid;
  $query->where[0]['conditions'][0]['value'][$key] = $tnid;
}

/**
 * Implements hook_views_query_alter() for the current_user view.
 */
function intel_ea_module_views_query_alter_current_user(&$view, &$query) {
  // Run display-specific hook_views_query_alter() functions, like
  // hook_views_query_alter_{$view->name}_{$view->current_display}().
  $function = __FUNCTION__ . "_$view->current_display";
  if (function_exists($function)) {
    $function($view, $query);
  }
}

/**
 * Implements hook_views_query_alter() for the company_users display of the
 * current_user view.
 */
function intel_ea_module_views_query_alter_current_user_company_users(&$view, &$query) {
  $query->table_queue['node_field_data_field_company__field_data_field_company']['join']->extra[] = array(
    'field' => 'entity_type',
    'value' => 'user',
  );
  $query->table_queue['node_field_data_field_company__field_data_field_company']['join']->extra[] = array(
    'field' => 'bundle',
    'value' => 'user',
  );
  $query->table_queue['node_field_data_field_company__field_data_field_company']['join']->extra[] = array(
    'field' => 'deleted',
    'value' => 0,
  );
}

/**
 * Implements hook_views_query_alter() for the company_solutions display of the
 * current_user view.
 */
function intel_ea_module_views_query_alter_current_user_company_solutions(&$view, &$query) {
  $query->table_queue['node_field_data_field_company__field_data_field_company']['join']->extra[] = array(
    'field' => 'entity_type',
    'value' => 'node',
  );
  $query->table_queue['node_field_data_field_company__field_data_field_company']['join']->extra[] = array(
    'field' => 'bundle',
    'value' => 'solution',
  );
  $query->table_queue['node_field_data_field_company__field_data_field_company']['join']->extra[] = array(
    'field' => 'deleted',
    'value' => 0,
  );
}

/**
 * Implements hook_views_post_execute().
 */
function intel_ea_module_views_post_execute(&$view) {
  // Run view-specific preprocess functions, like
  // hook_views_post_execcute_{$view->name}().
  $function = __FUNCTION__ . "_$view->name";
  if (function_exists($function)) {
    $function($view);
  }
}

/**
 * Implements hook_views_post_execute() for the google_analytics_reports view.
 */
function intel_ea_module_views_post_execute_google_analytics_reports(&$view) {
  if ($view->result) {
    // Retrieve all Google Antlaytics results.
    // while (count($view->result >= 10000)) {
    //   Get next set of 10000.
    //   Add it to the results.
    //   $view->result += $view->result;
    // }

    // Run view-specific preprocess functions, like
    // hook_views_post_execcute_{$view->name}_{$view->current_display}().
    $function = __FUNCTION__ . "_$view->current_display";
    if (function_exists($function)) {
      $function($view);
    }
  }
}

/**
 * Implements hook_views_post_execute() for content display of the
 * google_analytics_reports view.
 */
function intel_ea_module_views_post_execute_google_analytics_reports_content(&$view) {
  $view->result = intel_ea_module_google_analytics_filter_member_content('customVarValue4', $view->result);
}

/**
 * Implements hook_views_post_execute() for content_request_quote display of the
 * google_analytics_reports view.
 */
function intel_ea_module_views_post_execute_google_analytics_reports_content_request_quote(&$view) {
  $view->result = intel_ea_module_google_analytics_filter_member_content('eventLabel', $view->result);
}

/**
 * Implements hook_views_post_execute() for the content_contact_intel display of
 * the google_analytics_reports view.
 */
function intel_ea_module_views_post_execute_google_analytics_reports_content_contact_intel (&$view) {
  $view->result = intel_ea_module_google_analytics_filter_member_content('eventLabel', $view->result);
}

/**
 * Implements hook_views_post_execute() for the content_datasheet display of the
 * google_analytics_reports view.
 */
function intel_ea_module_views_post_execute_google_analytics_reports_content_datasheet(&$view) {
  $view->result = intel_ea_module_google_analytics_filter_member_content('eventLabel', $view->result);
}

/**
 * Implements hook_views_post_execute() for the content_webpage display fo the
 * google_analytics_reports view.
 */
function intel_ea_module_views_post_execute_google_analytics_reports_content_webpage(&$view) {
  $view->result = intel_ea_module_google_analytics_filter_member_content('eventLabel', $view->result);
}

/**
 * Filters Google Analytics results by content id.
 */
function intel_ea_module_google_analytics_filter_member_content($filter, $items) {
  $company = _intel_ea_module_google_analytics_reports_company_get();

  // Get a list of Solutions Directory content for the member.
  $types = db_or()
    ->condition('n.type', 'formula')
    ->condition('n.type', 'solution');
  $query = db_select('node', 'n');
  $query->join('field_data_field_company', 'c', "n.nid = c.entity_id AND c.entity_type = 'node'");
  $query
    ->fields('n', array('nid', 'title'))
    ->condition($types)
    ->condition('n.status', 1)
    ->condition('c.field_company_target_id', $company);
  $nodes = $query->execute()->fetchAllAssoc('nid');

  // Filter out Google Analytics data not associated with the member's content.
  $items = array_filter($items, function($item) use($filter, $nodes) {
    return key_exists($item->$filter, $nodes);
  });

  // Use content titles as labels.
  foreach ($items as $item) {
    $item->$filter = check_plain($nodes[$item->$filter]->title);
  }

  return $items;
}

/**
 * Implements hook_views_pre_render().
 */
function intel_ea_module_views_pre_render(&$view) {
  $function = __function__ . "_$view->name";
  if (function_exists($function)) {
    $function($view);
  }
}

/**
 * Implements hook_views_pre_render().
 *
 * For the Current User view.
 */
function intel_ea_module_views_pre_render_current_user(&$view) {
  $function = __function__ . "_$view->current_display";
  if (function_exists($function)) {
    $function($view);
  }
}

/**
 * Implements hook_views_pre_render().
 *
 * For the Primary Contact display of the Current User view.
 */
function intel_ea_module_views_pre_render_current_user_primary_contact(&$view) {
  $nid = $view->args[0];
  $node = node_load($nid);
  $view->build_info['title'] = $node->title . ' ' . $view->build_info['title'];
}

/**
 * Implements hook_views_pre_render().
 *
 * For the Solution Pricing Information view.
 */
function intel_ea_module_views_pre_render_solution_pricing_information(&$view) {
  $asterisk_text = FALSE;

  foreach ($view->result as $result) {
    // Add the asterisk and text boolean for each price per unit field.
    if (!empty($result->field_field_price_per_unit)) {
      $result->field_field_price_per_unit[0]['rendered']['#markup'] .= ' *';
      $asterisk_text = TRUE;
    }
    if (!empty($result->field_field_price_per_100_units)) {
      $result->field_field_price_per_100_units[0]['rendered']['#markup'] .= ' *';
      $asterisk_text = TRUE;
    }
    if (!empty($result->field_field_price_per_1000_units)) {
      $result->field_field_price_per_1000_units[0]['rendered']['#markup'] .= ' *';
      $asterisk_text = TRUE;
    }

    // Populate the asterisk text.
    if ($asterisk_text) {
      $view->attachment_after = '<p>* ' . t('Pricing Subject to Change by the Member Company.') . '</p>';
    }

    // If no price per unit or order button, provide default text.
    if (empty($result->field_field_price_per_unit) && empty($result->field_field_price_per_100_units) && empty($result->field_field_price_per_1000_units) && empty($result->field_field_order_button_url)) {
      $view->attachment_before = '<p>' . t('Contact Member Company for Pricing.') . '</p>';
    }
  }
}

/**
 * Implements hook_views_pre_render().
 *
 * For the Solutions Directory view.
 */
function intel_ea_module_views_pre_render_solutions_directory(&$view) {
  $function = __function__ . "_$view->current_display";
  if (function_exists($function)) {
    $function($view);
  }
}

/**
 * Implements hook_views_pre_render().
 *
 * For the Search Results display of the Solutions Directory view.
 */
function intel_ea_module_views_pre_render_solutions_directory_search_results(&$view) {
  _intel_ea_module_views_pre_render_search_results($view);
}

/**
 * Implements hook_views_pre_render().
 *
 * For the Pre-release Search Results display of the Solutions Directory view.
 */
function intel_ea_module_views_pre_render_solutions_directory_panel_pane_1(&$view) {
  _intel_ea_module_views_pre_render_search_results($view);
}

/**
 * Implements hook_views_pre_render().
 *
 * For the Search Results displays of the Solutions Directory view.
 */
function _intel_ea_module_views_pre_render_search_results(&$view) {
  // Set noindex on search results with facet pages
  $args = arg();
  if (isset($args['1'])) {
    $element = array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'robots',
        'content' => 'noindex',
      ),
    );
    drupal_add_html_head($element, 'facet_noindex');
  }

  // attach the RSS Feed
  $original_uri = request_uri();

  // If there is a query parameter, rebuild the url, inserting feed into the path
  if (strpos($original_uri, '?') !== false) {
    $split_url = explode('?', $original_uri);
    if (strpos($original_uri,'solutions-directory') !== false) {
      $modified_uri =  $split_url[0] . '/feed?';
    }
    else {
      $modified_uri =  $split_url[0] . '/solutions-directory/feed?';
    }
    $query_param = $split_url[1];
    $options = array(
      'attributes' => array('target' => '_blank'),
      'html' => TRUE,
      'absolute' => TRUE,
      'external' => TRUE,
    );

    $view->attachment_after = l(theme('image', array('path' => 'misc/feed.png', 'alt' => t('RSS'))), $modified_uri . $query_param, $options);
  }
  // If we are at the root of the site, we need to send them to solutions-directory/feed, since that is the destination that the feed view "listens" to
  else {
    if (strpos($original_uri, 'solutions-directory') !== false) {
      $p = parse_url($original_uri);
      if (isset($p)) {
        // get the path from the full url and remove the first /
        $stringworker = $p['path'];
        $stringworker = substr($stringworker, 1);
        $pathpieces = explode("/", $stringworker);

        // if the first path segment is not the string 'solutions-directory' assume it is the language and save it (re-attach later)
        if ($pathpieces[0] != 'solutions-directory') {
          $language = $pathpieces[0];
          $directory = $pathpieces[1];
          $pos = strpos($stringworker, $directory);
          $stringworker =  substr($stringworker, $pos);
          $pathpieces = explode("/", $stringworker);
        }
        else {
          $directory = $pathpieces[0];
        }
        $numberofpieces = count($pathpieces);
        $beast = "";
        if (isset($language)) {
          $beast .= "/" . $language;
        }
        $beast .= "/" . $directory. "/feed/";
        $x = 0;
        //skip the directory string and make new beast string with format /feed/directory/termid
        for ($i = 1; $i < $numberofpieces - 1; $i = $i + 2) {
          $directoryterm = $pathpieces[$i];
          $termid = $pathpieces[$i + 1];
          $beast .= $directoryterm . "/" . $termid . "/";
          $x++;
        }
        //remove the last /
        $beast = substr($beast,0,strlen($beast)-1);
      }
      else {
        // should we tell them a path is not set? for now, we remain quiet.
      }
      $modified_uri =  $beast;
    }
    else {
      // else no solution directory in URL
      $p = parse_url($original_uri);
      if (isset($p)) {
        // get the path from the full url and remove the first /
        $stringworker = $p['path'];
        $stringworker = substr($stringworker,1);
        $pathpieces = explode("/", $stringworker);

        if ($pathpieces[0] != 'solutions-directory') {
          $language = $pathpieces[0];
          $directory = $pathpieces[1];
          $pos = strpos($stringworker, $directory);
          $stringworker =  substr($stringworker,$pos);
          $pathpieces = explode("/", $stringworker);
        }
        else {
          $directory = $pathpieces[0];
        }

        $numberofpieces = count($pathpieces);
        $beast = "";
        if (isset($language)) {
          $beast .= "/" . $language;
        }
        $beast .= "/" . $directory. "/feed/";
        $x = 0;

        //skip the directory string and make new beast string with format /feed/directory/termid
        for ($i = 1; $i < $numberofpieces - 1; $i = $i + 2) {
          $directoryterm = $pathpieces[$i];
          $termid = $pathpieces[$i + 1];
          $beast .= $directoryterm . "/" . $termid . "/";
          $x++;
        }

        //remove the last /
        $beast = substr($beast, 0, strlen($beast) - 1);
      }
      else {
        // should we tell them a path is not set? for now, we remain quiet.
      }
      $modified_uri =  $beast;
    }
    $options = array(
      'attributes' => array('target' => '_blank'),
      'html' => TRUE,
      'absolute' => TRUE,
      'external' => TRUE,
    );

    $view->attachment_after = l(theme('image', array('path' => 'misc/feed.png', 'alt' => t('RSS'))), $modified_uri, $options);
  }
}

/**
 * Implements hook_views_pre_render().
 *
 * Implemented hook_views_pre_render() for the Opportunity Groups view.
 */
function intel_ea_module_views_pre_render_opportunity_groups(&$view) {
  global $language;
  $results = &$view->result;
  foreach ($results as $key => $result) {
    $node_wrapper = entity_metadata_wrapper('node', $result->entity);
    $opportunity_group = $node_wrapper->field_opportunities_taxonomy_term_eb->value();
    $opportunity_group = $opportunity_group[0];

    // If the node is not associated with an opportunity group.
    if (empty($opportunity_group)) {
      // Try to get the opportunity group of the source node.
      $tnid = $node_wrapper->value()->tnid;
      // If a source node exists.
      if ($tnid) {
        $source_wrapper = entity_metadata_wrapper('node', $tnid);
        $opportunity_group = $source_wrapper->field_opportunities_taxonomy_term_eb->value();
        $opportunity_group = $opportunity_group[0];
      }
    }

    // If we have an opportunity group.
    if ($opportunity_group) {
      $results[$key]->_entity_properties['field_opportunities_taxonomy_term_eb:name'] = i18n_taxonomy_term_name($opportunity_group, $language->language);
    }
  }
}

/**
 * Implements hook_views_post_render().
 */
function intel_ea_module_views_post_render(&$view, &$output, &$cache) {
  // Fix enclosure on the Solutions Directory RSS feed.
  // @see http://drupal.org/node/2149255.
  if (($view->name == 'solutions_directory' && $view->current_display == 'feed_1') ||
    ($view->name == 'member_roster' && $view->current_display == 'feed_1')) {
    $output = preg_replace_callback(
      '|<enclosure>(.*?)</enclosure>|s',
      function ($matches) {
        return html_entity_decode($matches[1]);
      },
      $output
    );
  }
}
