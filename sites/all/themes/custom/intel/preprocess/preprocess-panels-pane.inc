<?php

/**
 * @file
 * Panels Pane level preprocess functions.
 */

/**
 * Implements template_preprocess_panels_pane().
 */
function intel_alpha_preprocess_panels_pane(&$vars) {
  global $language;
  $language_code = in_array($language->language, array('en', 'ja', 'zh-hans')) ? $language->language : 'en';

  // If the panels pane is the created date of the node.
  if ($vars['pane']->panel == 'left_top' && $vars['pane']->type == 'node_created' && $vars['pane']->subtype == 'node_created') {
    // If the node was created less than two weeks ago show the 'new' badge.
    if ((time() - $vars['content']) < 1209600) {
      $theme_path = drupal_get_path('theme', 'intel');
      $vars['content'] = theme('image', array('path' => "$theme_path/images/badge-new-$language_code.png", 'alt' => t('New')));
    }
    // Otherwise, output no content.
    else {
      $vars['content'] = '';
    }
  }

  // If the panels pane is the node's pre-release flag.
  if ($vars['pane']->type == 'entity_field' && $vars['pane']->subtype == 'node:field_pre_release') {
    // If the node is flagged as pre-release show the 'pre-release' badge.
    if ($vars['content'][0]['#markup'] == '1') {
      $theme_path = drupal_get_path('theme', 'intel');
      $vars['content'] = theme('image', array('path' => "$theme_path/images/badge-pre-release-$language_code.png", 'alt' => t('Pre-Release')));
    }
    // Otherwise, output no content.
    else {
      $vars['content'] = '';
    }
  }

  // If the panels pane is the Bill of Materials field.
  if ($vars['pane']->type == 'entity_field' && $vars['pane']->subtype == 'node:field_bill_of_materials') {
    // Override the filename so that the link reads 'Download'.
    $vars['content'][0]['#file']->filename = t('Download');
    // Link to the file with additional text appended.
    $vars['content'] = theme('file_link', array('file' => $vars['content'][0]['#file'])) . t(' the bill of materials for this formula with the selected components.');
  }

  // If the panels pane is the Title of Training Sub-Section.
  if ($vars['pane']->type == 'node_title' && $vars['display']->css_id == 'mini-panel-training_sub_section_header') {
    $stripped = strip_tags($vars['content']);
    $vars['content'] = '<h1>' . t($stripped . ' Webinar') . '</h1>';
  }
}
