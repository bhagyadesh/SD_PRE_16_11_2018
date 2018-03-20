<?php

/**
 * @file
 * Page level preprocess functions.
 */

/**
 * Implements template_preprocess_page();
 */
function intel_alpha_preprocess_page(&$vars) {
  header('X-UA-Compatible: IE=edge');

  // Setup IE meta tag to force IE rendering mode
  $meta_ie_render_engine = array(
    '#type' => 'html_tag',
    '#tag' => 'meta',
    '#attributes' => array(
      'content' =>  'IE=edge,chrome=1',
      'http-equiv' => 'X-UA-Compatible',
    ),
    '#weight' => '-99999',
  );

  // Add header meta tag for IE to head
  drupal_add_html_head($meta_ie_render_engine, 'meta_ie_render_engine');

  // Add jQuery UI Accordion library to Company node pages.
  if (isset($vars['node'])) {
    if ($vars['node']->type == 'company') {
      drupal_add_library('system', 'ui.accordion');
    }
  }

  if(drupal_is_front_page()){
    drupal_add_library('system', 'ui.accordion');
  }
}
