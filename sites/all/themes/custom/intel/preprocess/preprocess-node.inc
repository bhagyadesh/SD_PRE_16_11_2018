<?php

/**
 * @file
 * Node level preprocess functions.
 */

/**
 * Implements template_preprocess_node();
 */
function intel_alpha_preprocess_node(&$vars) {
  // Add the display mode as a class to nodes so theme can change based
  // on the display. (Stolen from Display Suite)

  if ($vars['view_mode'] != 'teaser') {
    $view_mode = str_replace('_', '-', $vars['view_mode']);
    $vars['attributes_array']['class'][] = 'node-' . $view_mode;
  }

  // Check each field collection to see which view mode to set.
  if ($vars['type'] == 'formula' && !empty($vars['field_component_group'])) {
    intel_preprocess_node__formula__multiple_component($vars);
  }

  if ($vars['view_mode'] == 'training_center_tile') {
    intel_preprocess_node__training_center_tile($vars);
  }
  if ($vars['view_mode'] == 'training_section_tab') {
    intel_preprocess_node__training_section_tab($vars);
  }
  if ($vars['view_mode'] == 'training_section_slide') {
    intel_preprocess_node__training_section_slide($vars);
  }
  if ($vars['view_mode'] == 'formula_list') {
    intel_preprocess_node__formula_list($vars);
  }
  if ($vars['view_mode'] == 'formula_teaser') {
    intel_preprocess_node__formula_teaser($vars);
  }
  if ($vars['view_mode'] == 'solution_list') {
    intel_preprocess_node__solution_list($vars);
  }
  if ($vars['view_mode'] == 'solution_list_quickview') {
    intel_preprocess_node__solution_list_quickview($vars);
  }
  if ($vars['view_mode'] == 'opp_list_sticky') {
    intel_preprocess_node__opp_list_sticky($vars);
  }
  if ($vars['view_mode'] == 'opp_list') {
    intel_preprocess_node__opp_list($vars);
  }
  if ($vars['view_mode'] == 'roster_list_premier') {
    intel_preprocess_node__roster_list_premier($vars);
  }
  if ($vars['view_mode'] == 'roster_list') {
    intel_preprocess_node__roster_list($vars);
  }
}

/**
 * Preprocess variables for multiple components displayed in formulas.
 */
function intel_preprocess_node__formula__multiple_component(&$vars) {
  foreach ($vars['field_component_group'][LANGUAGE_NONE] as $entity_uri) {
    $collection_item = entity_load('field_collection_item', $entity_uri);
    foreach ($collection_item as $collection_item_object) {
      if (count($collection_item_object->field_component_options[LANGUAGE_NONE]) > 1) {
        foreach ($collection_item_object->field_component_options[LANGUAGE_NONE] as $target) {
          $GLOBALS['multi_display'][] = $target['target_id'];
        }
      }
    }
  }
}

/**
 * Preprocess variables for nodes displayed as Training Center Tile.
 */
function intel_preprocess_node__training_center_tile(&$vars) {
  // Add theme/template suggestions for the training_center_tile display.
  $vars['theme_hook_suggestions'][] = 'node__training_center_tile';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__training_center_tile';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__training_center_tile';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Training Section nodes displayed as Training Center Tile.
 */
function intel_preprocess_node__training_section__training_center_tile(&$vars) {
  global $base_url;

  // Direct teaser slides to english.
  if ($vars['language'] != 'en' && ! empty($vars['tnid'])) {
    $vars['node_url'] = url('node/' . $vars['tnid']);
  }
  // Add the linked node title just after the icon.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title'] . (!empty($vars['field_sub_title']) ? ' ' . $vars['field_sub_title'][LANGUAGE_NONE][0]['safe_value'] : '')), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_icon']['#weight'] + .1,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for nodes displayed as Training Section Tab.
 */
function intel_preprocess_node__training_section_tab(&$vars) {
  // Add theme/template suggestions for the training_section_tab display.
  $vars['theme_hook_suggestions'][] = 'node__training_section_tab';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__training_section_tab';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__training_section_tab';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Training Sub-Section nodes displayed as Training Section Tab.
 */
function intel_preprocess_node__training_sub_section__training_section_tab(&$vars) {
  $current_path = current_path();
  $current_path_parts = explode('/', $current_path);
  if (in_array($vars['nid'], $current_path_parts)) {
    $vars['title_attributes_array']['class'][] = 'active';
  }

  $training_section = node_load($vars['field_training_section'][LANGUAGE_NONE][0]['target_id']);
  if ($training_section->field_ajax_section[LANGUAGE_NONE][0]['value'] == '1') {
    $vars['title_attributes_array']['class'][] = 'ajax-link';
  }
}

/**
 * Preprocess variables for nodes displayed as Training Section Slide.
 */
function intel_preprocess_node__training_section_slide(&$vars) {
  // Add theme/template suggestions for the training_section_slide display.
  $vars['theme_hook_suggestions'][] = 'node__training_section_slide';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__training_section_slide';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__training_section_slide';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Training Sub-Section nodes displayed as Training Section Slide.
 */
function intel_preprocess_node__training_sub_section__training_section_slide(&$vars) {
  global $base_url;

  // Add the linked node title just after the icon.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_icon']['#weight'] + .1,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for nodes displayed as Formula List.
 */
function intel_preprocess_node__formula_list(&$vars) {
  // Add theme/template suggestions for the formula_list display.
  $vars['theme_hook_suggestions'][] = 'node__formula_list';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__formula_list';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__formula_list';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Solution nodes displayed as Formula List.
 */
function intel_preprocess_node__solution__formula_list(&$vars) {
  global $base_url;

  // Add a badge for member solutions.
  $vars['content']['field_alliance_member'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => t('Alliance Member'),
    '#attributes' => array(
      'class' => 'field-name-field-alliance-member',
    ),
    '#weight' => $vars['content']['field_image']['#weight'] + .1,
  );

  // Add the linked company name & node title just after the solution member badge.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['field_company'][LANGUAGE_NONE][0]['entity']->title . ' - ' . $vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_alliance_member']['#weight'] + .1,
  );

  // Add an Aprimo link just after the node title.
  $vars['content']['field_aprimo_link'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => _intel_ea_module_aprimo_btn_contents('field_company', $vars['field_company'][LANGUAGE_NONE][0]['entity']->title, $vars['field_company'][LANGUAGE_NONE][0]['entity']->nid),
    '#attributes' => array(
      'class' => 'field-name-field-aprimo-link',
    ),
    '#weight' => $vars['content']['title']['#weight'] + .1,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for Component nodes displayed as Formula List.
 */
function intel_preprocess_node__component__formula_list(&$vars) {
  // Link the image field to the component webpage.
  $vars['content']['field_image'][0]['#path']['path'] = $vars['field_component_webpage'][LANGUAGE_NONE][0]['url'];

  // Add the company name & node title linked to the component webpage.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['field_component_company_name'][LANGUAGE_NONE][0]['safe_value'] . ' - ' . $vars['title']), $vars['field_component_webpage'][LANGUAGE_NONE][0]['url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_image']['#weight'] + .1,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for nodes displayed as Formula Teaser.
 */
function intel_preprocess_node__formula_teaser(&$vars) {
  // Add theme/template suggestions for the formula_teaser display.
  $vars['theme_hook_suggestions'][] = 'node__formula_teaser';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__formula_teaser';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__formula_teaser';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Solution nodes displayed as Formula Teaser.
 */
function intel_preprocess_node__solution__formula_teaser(&$vars) {
  global $base_url;

  // Add the linked node title just after the product image.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_image']['#weight'] + .1,
  );

  // Add a badge for member solutions.
  $vars['content']['field_alliance_member'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => t('Alliance Member'),
    '#attributes' => array(
      'class' => 'field-name-field-alliance-member',
    ),
    '#weight' => $vars['content']['field_company']['#weight'] + .1,
  );

  // Add an Aprimo link just after the solution member badge.
  $vars['content']['field_aprimo_link'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => _intel_ea_module_aprimo_btn_contents('field_company', $vars['field_company'][0]['entity']->title, $vars['field_company'][0]['entity']->nid),
    '#attributes' => array(
      'class' => 'field-name-field-aprimo-link',
    ),
    '#weight' => $vars['content']['field_alliance_member']['#weight'] + .1,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for Component nodes displayed as Formula Teaser.
 */
function intel_preprocess_node__component__formula_teaser(&$vars) {
  // Link the image field to the component webpage.
  $vars['content']['field_image'][0]['#path']['path'] = $vars['field_component_webpage'][LANGUAGE_NONE][0]['url'];

  // Add the node title linked to the component webpage.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $vars['field_component_webpage'][LANGUAGE_NONE][0]['url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_image']['#weight'] + .1,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for nodes displayed as Solution List.
 */
function intel_preprocess_node__solution_list(&$vars) {
  // Add theme/template suggestions for the solution_list display.
  $vars['theme_hook_suggestions'][] = 'node__solution_list';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__solution_list';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__solution_list';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Company nodes displayed as Solution List.
 */
function intel_preprocess_node__company__solution_list(&$vars) {

}

/**
 * Preprocess variables for Solution nodes displayed as Solution List.
 */
function intel_preprocess_node__solution__solution_list(&$vars) {
  global $base_url;
  $theme_path = drupal_get_path('theme', 'intel');

  global $language;
  $language_code = in_array($language->language, array('en', 'ja', 'zh-hans')) ? $language->language : 'en';

  // If the node was created less than two weeks ago
  // show the 'new' badge just before the product image.
  if ((time() - $vars['created']) < 1209600) {
    $vars['content']['field_new_badge'] = array(
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#value' => theme('image', array('path' => "$theme_path/images/badge-new-$language_code.png", 'alt' => t('New'))),
      '#attributes' => array(
        'class' => 'field-name-field-new-badge',
      ),
      '#weight' => $vars['content']['field_image']['#weight'] - .2,
    );
  }

  // If the node is flagged as pre-release show the
  // 'pre-release' badge just before the product image.
  if (isset($vars['field_pre_release']['und'][0]['value']) && $vars['field_pre_release']['und'][0]['value'] == '1') {
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

  // Add a link to open a ctools modal with more info.
  $vars['content']['field_quickview_link'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => ctools_modal_text_button(t('Quickview'), 'solutions-directory/nojs/' . $vars['nid'], 'More Info', 'ctools-modal-intel-ea-sd-modal-style white-button'),
    '#attributes' => array(
      'class' => 'field-name-field-quickview-link',
    ),
    '#weight' => $vars['content']['field_image']['#weight'] + .1,

  );

  // Add the linked node title just after the product image.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_image']['#weight'] + .2,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for Formula nodes displayed as Solution List.
 */
function intel_preprocess_node__formula__solution_list(&$vars) {
  global $base_url;
  $theme_path = drupal_get_path('theme', 'intel');

  global $language;
  $language_code = in_array($language->language, array('en', 'ja', 'zh-hans')) ? $language->language : 'en';

  // If the node was created less than two weeks ago
  // show the 'new' badge just before the product image.
  if ((time() - $vars['created']) < 1209600) {
    $vars['content']['field_new_badge'] = array(
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#value' => theme('image', array('path' => "$theme_path/images/badge-new-$language_code.png", 'alt' => t('New'))),
      '#attributes' => array(
        'class' => 'field-name-field-new-badge',
      ),
      '#weight' => $vars['content']['field_image']['#weight'] - .2,
    );
  }

  // If the node is flagged as pre-release show the
  // 'pre-release' badge just before the product image.
  if (isset($vars['field_pre_release'][LANGUAGE_NONE][0]['value']) && $vars['field_pre_release'][LANGUAGE_NONE][0]['value'] == '1') {
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

  // Add a link to open a ctools modal with more info.
  $vars['content']['field_quickview_link'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => ctools_modal_text_button(t('Quickview'), 'solutions-directory/nojs/' . $vars['nid'], 'More Info', 'ctools-modal-intel-ea-sd-modal-style white-button'),
    '#attributes' => array(
      'class' => 'field-name-field-quickview-link',
    ),
    '#weight' => $vars['content']['field_image']['#weight'] + .1,

  );

  // Add the linked node title just after the product image.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_image']['#weight'] + .2,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for nodes displayed as Solution List Quickview.
 */
function intel_preprocess_node__solution_list_quickview(&$vars) {

  // Add theme/template suggestions for the solution_list_quickview display.
  $vars['theme_hook_suggestions'][] = 'node__solution_list_quickview';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__solution_list_quickview';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__solution_list_quickview';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Company nodes displayed as Solution List Quickview.
 */
function intel_preprocess_node__company__solution_list_quickview(&$vars) {
  // If there is no logo, add the linked node title just after the membership type.
  if (!isset($vars['content']['field_logo'])) {
    global $base_url;

    $vars['content']['title'] = array(
      '#type' => 'html_tag',
      '#tag' => 'h2',
      '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
      '#attributes' => $vars['title_attributes_array'],
      '#weight' => $vars['content']['field_membership_type']['#weight'] + .1,
    );
  }
  // Otherwise add the node title as the logo's alt tag.
  else {
    $vars['content']['field_logo'][0]['#item']['alt'] = decode_entities($vars['title']);
  }

  // Remove the title because we've already displayed it.1
  $vars['title'] = '';
}

/**
 * Preprocess variables for Solution nodes displayed as Solution List Quickview.
 */
function intel_preprocess_node__solution__solution_list_quickview(&$vars) {
  global $base_url;

  // Add the linked node title just after the company info.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_company']['#weight'] + .1,
  );

  // Add the node created date just after the body.
  $vars['content']['field_created'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => format_date($vars['created'], 'eu_short'),
    '#attributes' => array(
      'class' => 'field-name-field-created',
    ),
    '#weight' => $vars['content']['body']['#weight'] + .1,
  );

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for Formula nodes displayed as Solution List Quickview.
 */
function intel_preprocess_node__formula__solution_list_quickview(&$vars) {
  global $base_url;

  // Add the linked node title just after the company info.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_company']['#weight'] + .1,
  );

  // Add the node created date just after the body.
  $vars['content']['field_created'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => format_date($vars['created'], 'eu_short'),
    '#attributes' => array(
      'class' => 'field-name-field-created',
    ),
    '#weight' => $vars['content']['body']['#weight'] + .1,
  );

  // Add a link to comments of there are any.
  if ($vars['comment_count'] != 0) {
    $comment_count = format_plural($vars['comment_count'], '1 comment', '@count comments');
    $vars['content']['field_comment_link'] = array(
      '#type' => 'html_tag',
      '#tag' => 'div',
      '#value' => l($comment_count, 'node/' . $vars['nid'], array('fragment' => 'comment-1')),
      '#attributes' => array(
        'class' => 'field-name-field-comment-link',
      ),
      '#weight' => $vars['content']['body']['#weight'] + 1.1,
      '#prefix' => '<footer class="clearfix">',
      '#suffix' => '</footer>',
    );
  }

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for nodes displayed as Opportunity List Sticky.
 */
function intel_preprocess_node__opp_list_sticky(&$vars) {
  // Add theme/template suggestions for the opp_list_sticky display.
  $vars['theme_hook_suggestions'][] = 'node__opp_list_sticky';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__opp_list_sticky';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__opp_list_sticky';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Opportunity nodes displayed as Opportunity List Sticky.
 */
function intel_preprocess_node__opportunity__opp_list_sticky(&$vars) {
  // Add a label to the expiration date.
  if (!empty($vars['content']['field_expiration_date'])) {
    $vars['content']['field_expiration_date'][0]['#markup'] = '<span>Expires: </span>' . $vars['content']['field_expiration_date'][0]['#markup'];
  }

  // Add a link to the node just after the expiration date.
  $vars['content']['field_learn_more'] = array(
    '#type' => 'html_tag',
    '#tag' => 'div',
    '#value' => l(t('Learn More'), "node/{$vars['nid']}", array('attributes' => array('title' => t('Learn More')))),
    '#attributes' => array(
      'class' => 'field-name-field-learn-more',
    ),
    '#weight' => $vars['content']['field_expiration_date']['#weight'] + .1,
  );
}

/**
 * Preprocess variables for nodes displayed as Opportunity List.
 */
function intel_preprocess_node__opp_list(&$vars) {
  // Add theme/template suggestions for the opp_list display.
  $vars['theme_hook_suggestions'][] = 'node__opp_list';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__opp_list';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__opp_list';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Opportunity nodes displayed as Opportunity List.
 */
function intel_preprocess_node__opportunity__opp_list(&$vars) {
  // Edit the class attribute on the call to action link.
  $vars['content']['field_call_to_action'][0]['#element']['attributes']['class'] = 'white-button';

  // Add a label to the expiration date.
  //$vars['content']['field_expiration_date'][0]['#markup'] = '<span>Expires: </span>' . $vars['content']['field_expiration_date'][0]['#markup'];
}

/**
 * Preprocess variables for nodes displayed as Member Roster List Premier.
 */
function intel_preprocess_node__roster_list_premier(&$vars) {
  // Add theme/template suggestions for the roster_list_premier display.
  $vars['theme_hook_suggestions'][] = 'node__roster_list_premier';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__roster_list_premier';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__roster_list_premier';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Company nodes displayed as Member Roster List Premier.
 */
function intel_preprocess_node__company__roster_list_premier(&$vars) {
  global $base_url;

  // Add the linked node title just after the logo.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => $vars['content']['field_logo']['#weight'] + .1,
  );

  // Add the solutions directory link just after the title.
  $vars['content']['field_solutions_link'] = array(
    '#markup' => '<div class="field-name-field-solutions-link">' . l(t('View Solutions'), 'solutions-directory/company/' . $vars['nid']) . '</div>',
    '#weight' => $vars['content']['title']['#weight'] + .1,
  );

  // If a community_tag exists, display link to articles and whitepapers.
  if (!empty($vars['field_community_tag']['und'][0]['safe_value'])) {
    // Add the articles link just after the solutions directory link.
    $articles_link = _intel_ea_community_assets_links('articles', 'community', $vars['field_community_tag']['und'][0]['safe_value'], t('View Articles'));
    $vars['content']['field_articles_link'] = array(
      '#markup' => '<div class="field-name-field-articles-link">' . $articles_link . '</div>',
      '#weight' => $vars['content']['field_solutions_link']['#weight'] + .1,
    );

    // Add the whitepapers link just after the solutions directory link.
    $whitepapers_link = _intel_ea_community_assets_links('whitepapers', 'community', $vars['field_community_tag']['und'][0]['safe_value'], t('View White Papers'));
    $vars['content']['field_whitepapers_link'] = array(
      '#markup' => '<div class="field-name-field-whitepapers-link">' . $whitepapers_link . '</div>',
      '#weight' => $vars['content']['field_articles_link']['#weight'] + .1,
    );
  }

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}

/**
 * Preprocess variables for nodes displayed as Member Roster List.
 */
function intel_preprocess_node__roster_list(&$vars) {
  // Add theme/template suggestions for the roster_list display.
  $vars['theme_hook_suggestions'][] = 'node__roster_list';
  $vars['theme_hook_suggestions'][] = 'node__' . $vars['type'] . '__roster_list';

  $function = 'intel_preprocess_node__' . $vars['type'] . '__roster_list';
  if (function_exists($function)) {
    $function($vars);
  }
}

/**
 * Preprocess variables for Company nodes displayed as Member Roster List.
 */
function intel_preprocess_node__company__roster_list(&$vars) {
  global $base_url;

  // Add the linked node title.
  $vars['content']['title'] = array(
    '#type' => 'html_tag',
    '#tag' => 'h2',
    '#value' => l(decode_entities($vars['title']), $base_url . $vars['node_url']),
    '#attributes' => $vars['title_attributes_array'],
    '#weight' => 0,
  );

  // Add the solutions directory link just after the title.
  $vars['content']['field_solutions_link'] = array(
    '#markup' => '<div class="field-name-field-solutions-link">' . l(t('View Solutions'), 'solutions-directory/company/' . $vars['nid']) . '</div>',
    '#weight' => $vars['content']['title']['#weight'] + .1,
  );

  // If a community_tag exists, display link to articles and whitepapers.
  if (!empty($vars['field_community_tag']['und'][0]['safe_value'])) {
    // Add the articles link just after the solutions directory link.
    $articles_link = _intel_ea_community_assets_links('articles', 'community', $vars['field_community_tag']['und'][0]['safe_value'], t('View Articles'));
    $vars['content']['field_articles_link'] = array(
      '#markup' => '<div class="field-name-field-articles-link">' . $articles_link . '</div>',
      '#weight' => $vars['content']['field_solutions_link']['#weight'] + .1,
    );

    // Add the whitepapers link just after the solutions directory link.
    $whitepapers_link = _intel_ea_community_assets_links('whitepapers', 'community', $vars['field_community_tag']['und'][0]['safe_value'], t('View White Papers'));
    $vars['content']['field_whitepapers_link'] = array(
      '#markup' => '<div class="field-name-field-whitepapers-link">' . $whitepapers_link . '</div>',
      '#weight' => $vars['content']['field_articles_link']['#weight'] + .1,
    );
  }

  // Remove the title because we've already displayed it.
  $vars['title'] = '';
}
