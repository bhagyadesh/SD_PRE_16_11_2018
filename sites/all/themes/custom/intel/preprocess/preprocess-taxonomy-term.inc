<?php

/**
 * @file
 * Taxonomy Term level preprocess functions.
 */

/**
 * Implements template_preprocess_taxonomy_term();
 */
function intel_alpha_preprocess_taxonomy_term(&$vars) {
  if ($vars['view_mode'] == 'opp_resource_list') {
    intel_preprocess_taxonomy_term__opp_resource_list($vars);
  }
  if ($vars['view_mode'] == 'approved_nouns_grid') {
    intel_preprocess_taxonomy_term__approved_nouns_grid($vars);
  }
  if ($vars['view_mode'] == 'approved_nouns_list') {
    intel_preprocess_taxonomy_term__approved_nouns_list($vars);
  }
}

/**
 * Preprocess variables for taxonomy terms displayed as Opportunity Resource List.
 */
function intel_preprocess_taxonomy_term__opp_resource_list(&$vars) {
  // Add theme/template suggestions for the opp_resource_list display.
  $vars['theme_hook_suggestions'][] = 'taxonomy_term__opp_resource_list';
  $vars['theme_hook_suggestions'][] = 'taxonomy_term__' . $vars['vocabulary_machine_name'] . '__opp_resource_list';

  $function = 'intel_preprocess_taxonomy_term__' . $vars['vocabulary_machine_name'] . '__opp_resource_list';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Opportunity Resource Type taxonomy terms displayed as Opportunity Resource List.
 */
function intel_preprocess_taxonomy_term__opportunity_resource_type__opp_resource_list(&$vars) {
  // Remove the title because we don't want to display it.
  $vars['term_url'] = '';
  $vars['term_name'] = '';
}

/**
 * Preprocess variables for taxonomy terms displayed as Approved Nouns Grid.
 */
function intel_preprocess_taxonomy_term__approved_nouns_grid(&$vars) {
  // Add theme/template suggestions for the approved_nouns_grid display.
  $vars['theme_hook_suggestions'][] = 'taxonomy_term__approved_nouns_grid';
  $vars['theme_hook_suggestions'][] = 'taxonomy_term__' . $vars['vocabulary_machine_name'] . '__approved_nouns_grid';

  $function = 'intel_preprocess_taxonomy_term__' . $vars['vocabulary_machine_name'] . '__approved_nouns_grid';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Approved Nouns taxonomy terms displayed as Approved Nouns Grid.
 */
function intel_preprocess_taxonomy_term__approved_nouns__approved_nouns_grid(&$vars) {
  // Include the necessary ctools APIs for ctools modal.
  ctools_include('ajax');
  ctools_include('modal');

  $vars['classes_array'][] = 'clearfix';

  // Add the term name linked to open a ctools modal just before the image.
  $vars['content']['term_name'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => ctools_modal_text_button(decode_entities($vars['term_name']), 'training-center/approved-nouns/nojs/' . $vars['tid'], '', 'ctools-modal-intel-ea-training-center-style'),
    '#weight' => $vars['content']['field_image']['#weight'] - .1,
  );

  // Remove the title because we already displayed it.
  $vars['term_url'] = '';
  $vars['term_name'] = '';
}

/**
 * Preprocess variables for taxonomy terms displayed as Approved Nouns List.
 */
function intel_preprocess_taxonomy_term__approved_nouns_list(&$vars) {
  // Add theme/template suggestions for the approved_nouns_list display.
  $vars['theme_hook_suggestions'][] = 'taxonomy_term__approved_nouns_list';
  $vars['theme_hook_suggestions'][] = 'taxonomy_term__' . $vars['vocabulary_machine_name'] . '__approved_nouns_list';

  $function = 'intel_preprocess_taxonomy_term__' . $vars['vocabulary_machine_name'] . '__approved_nouns_list';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Approved Nouns taxonomy terms displayed as Approved Nouns List.
 */
function intel_preprocess_taxonomy_term__approved_nouns__approved_nouns_list(&$vars) {
  // Add a term label.
  $vars['content']['term_label'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => t('Approved Nouns List'),
    '#attributes' => array(
      'class' => 'term-label',
    ),
    '#weight' => $vars['content']['field_approved_nouns_list']['#weight'] - .2,
  );

  // Add the term name just before the approved nouns list.
  $vars['content']['term_name'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => decode_entities($vars['term_name']),
    '#attributes' => array(
      'class' => 'term-name',
    ),
    '#weight' => $vars['content']['field_approved_nouns_list']['#weight'] - .1,
  );

  // Remove the title because we already displayed it.
  $vars['term_url'] = '';
  $vars['term_name'] = '';
}
