<?php

/**
 * @file
 *
 */

/**
 * Returns HTML for a checkbox_radio_tree element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #children, #attributes, #cardinality.
 *
 * @ingroup themeable
 */
function theme_checkbox_radio_tree($variables) {
  $element = $variables['element'];
  $attributes = array();

  if (isset($element['#id'])) {
    $attributes['id'] = $element['#id'];
  }

  $attributes['class'][] = 'checkbox-radio-tree';
  if (!empty($element['#attributes']['class'])) {
    $attributes['class'] = array_merge($attributes['class'], $element['#attributes']['class']);
  }

  if (isset($element['#attributes']['title'])) {
    $attributes['title'] = $element['#attributes']['title'];
  }

  return '<div' . drupal_attributes($attributes) . '>' . (!empty($element['#children']) ? $element['#children'] : '') . '</div>';
}

/**
 * Returns HTML for a checkbox_radio_tree_item element.
 *
 * @param $variables
 *   An associative array containing:
 *   - element: An associative array containing the properties of the element.
 *     Properties used: #children, #attributes, #cardinality.
 *
 * @ingroup themeable
 */
function theme_checkbox_radio_tree_item($variables) {
  $element = $variables['element'];
  $t = get_t();

  $prefix = isset($element['#field_prefix']) ? '<span class="field-prefix">' . $element['#field_prefix'] . '</span> ' : '';
  $suffix = isset($element['#field_suffix']) ? '<span class="field-suffix">' . $element['#field_suffix'] . '</span>' : '';

  if (isset($element['#title'])) {
    $title = $t('!title', array('!title' => filter_xss_admin($element['#title'])));
  }
  else {
    $title = '';
  }
/*** Add a span element($tree_image) for the expand collapse tree structure.
Added a new class 'checkbox_collapse' which will collapse the tree on page load.
 **/
  if (!empty($element['#children'])) {
    $children = '<div id="' . $element['#id'] . '-children" class="children checkbox_collapse">' . $element['#children'] . '</div>';
	$tree_image = '<span class="expand">&nbsp;</span>';
  }
  else {
    $children = '';
	$tree_image = '';
  }

  if ($element['#cardinality'] == -1) {
    $markup = theme('checkbox', array('element' => $element));
  }
  else {
    $markup = theme('radio', array('element' => $element));
  }
  
/*****Append the Span element before label tag *****/
  return $prefix . $tree_image. '<label>' . $markup . $title . '</label>' . $children . $suffix;
}

/**
 * Returns HTML for the label for the empty value of options that are not
 * required.
 *
 * The default theme will display 'N/A'.
 *
 * @param $variables
 *   An associative array containing:
 *   - instance: An array representing the widget requesting the options.
 *
 * @ingroup themeable
 */
function theme_checkbox_radio_tree_none($variables) {
  return t('N/A');
}