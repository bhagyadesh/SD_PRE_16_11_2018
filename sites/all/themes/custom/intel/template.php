<?php

/**
 * @file
 * This file is empty by default because the base theme chain (Alpha & Omega) provides
 * all the basic functionality. However, in case you wish to customize the output that Drupal
 * generates through Alpha & Omega this file is a good place to do so.
 *
 * Alpha comes with a neat solution for keeping this file as clean as possible while the code
 * for your subtheme grows. Please read the README.txt in the /preprocess and /process subfolders
 * for more information on this topic.
 */

/**
 * Theme function overrides.
 */

/**
 * Returns HTML for a link to a file.
 *
 * @param $variables
 *   An associative array containing:
 *   - file: A file object to which the link will be created.
 *   - icon_directory: (optional) A path to a directory of icons to be used for
 *     files. Defaults to the value of the "file_icon_directory" variable.
 *
 * @ingroup themeable
 */
function intel_file_link($variables) {
  $file = $variables['file'];

  $url = file_create_url($file->uri);

  // Set options as per anchor format described at
  // http://microformats.org/wiki/file-format-examples
  $options = array(
    'attributes' => array(
      'type' => $file->filemime . '; length=' . $file->filesize,
    ),
  );

  // Use the description as the link text if available.
  if (empty($file->description)) {
    $link_text = $file->filename;
  }
  else {
    $link_text = $file->description;
    $options['attributes']['title'] = check_plain($file->filename);
  }

  return '<span class="file">' . l($link_text, $url, $options) . '</span>';
}

/**
 * Returns HTML for the deactivation widget.
 *
 * @param $variables
 *   An associative array containing the keys 'text', 'path', and 'options'. See
 *   the l() function for information about these variables.
 *
 * @see l()
 * @see theme_facetapi_link_active()
 *
 * @ingroup themable
 */
function intel_facetapi_deactivate_widget($variables) {
  $image_path = drupal_get_path('theme', 'intel') . '/images/search-term-close.png';
  return theme('image', array('path' => $image_path, 'width' => NULL, 'height' => NULL, 'alt' => '(-)'));
}

/**
 * Helper function to swap out table header arrow images with custom images
 */
function intel_tablesort_indicator($variables) {
  $theme_path = drupal_get_path('theme', 'intel');
  if ($variables['style'] == "asc") {
    return theme('image', array('path' => $theme_path . '/images/arrow-down.png', 'width' => 8, 'height' => 7, 'alt' => t('sort ascending'), 'title' => t('sort ascending')));
    }
  else {
    return theme('image', array('path' => $theme_path . '/images/arrow-up.png', 'width' => 8, 'height' => 7, 'alt' => t('sort descending'), 'title' => t('sort descending')));
  }
}

/**
 * Theme a feed link.
 *
 * This theme function uses the theme pattern system to allow it to be
 * overidden in a more specific manner. The options for overiding this include
 * providing per display id; per type; per display id and per type.
 *
 * e.g.
 * For the view "export_test" with the display "page_1" and the type "csv" you
 * would have the following options.
 *   views_data_export_feed_icon__export_test__page_1__csv
 *   views_data_export_feed_icon__export_test__page_1
 *   views_data_export_feed_icon__export_test__csv
 *   views_data_export_feed_icon__page_1__csv
 *   views_data_export_feed_icon__page_1
 *   views_data_export_feed_icon__csv
 *   views_data_export_feed_icon
 *
 * @ingroup themeable
 */
function intel_views_data_export_feed_icon($variables) {
  extract($variables, EXTR_SKIP);
  $url_options = array('attributes' => array('class' => array('white-button', drupal_html_class($text))));
  if ($query) {
    $url_options['query'] = $query;
  }

  return l($text, $url, $url_options);
}

/**
 * Implements THEME_menu_link()
 *
 * Hide a link in the MRC sidebar. If you are not an admin
 *
 */
function intel_menu_link( $variables ) {

  if($variables['element']['#title'] == 'Quarterly Web Analytic Reports') {
    global $user;
    if (!(isset($user->roles[3]) || isset($user->roles[9]))) {

      return;
    }
  }
  $element = $variables['element'];
  $sub_menu = '';

  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}

/**
 *  Implements hook_item_list().
 */
function intel_item_list($vars) {
  static $count = 0; // added

  $items = $vars['items'];
  $title = $vars['title'];
  $type = $vars['type'];
  $attributes = $vars['attributes'];

  $output = '<div class="item-list">';
  if (isset($title)) {
    $output .= '<h3>' . $title . '</h3>';
  }

  if (!empty($items)) {
    $output .= "<$type" . drupal_attributes($attributes) . '>';
    $num_items = count($items);

    foreach ($items as $i => $item) {
      $zebra = ($count % 2) ? 'even' : 'odd'; // added
      $count++; // added
      $attributes = array();
      $children = array();
      if (is_array($item)) {
        foreach ($item as $key => $value) {
          if ($key == 'data') {
            $data = $value;
          }
          elseif ($key == 'children') {
            $children = $value;
          }
          else {
            $attributes[$key] = $value;
          }
        }
      }
      else {
        $data = $item;
      }

      if (count($children) > 0) {
        // Render nested list.
        $data .= theme_item_list(array('items' => $children, 'title' => NULL, 'type' => $type, 'attributes' => $attributes));
      }

      if ($i == 0) {
        $attributes['class'][] = 'first';
      }

      if ($i == $num_items - 1) {
        $attributes['class'][] = 'last';
      }

      $attributes['class'][] = $zebra; // added

      $output .= '<li' . drupal_attributes($attributes) . '>' . $data . "</li>";
    }

    $output .= "</$type>";
  }

  $output .= '</div>';

  return $output;
}
