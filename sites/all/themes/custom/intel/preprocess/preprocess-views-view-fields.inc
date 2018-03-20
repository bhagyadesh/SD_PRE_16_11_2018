<?php

/**
 * @file
 * Views view field level preprocess functions.
 */

/**
 * Preprocess theme function to print a single record from a row, with fields
 */
function intel_alpha_preprocess_views_view_fields(&$vars) {
  if ($vars['view']->name == 'training_sub_section_slides' && $vars['view']->current_display == 'slideshow') {
    $stripped = strip_tags($vars['fields']['counter']->content);
    $vars['fields']['counter']->content = '<span class="field-content">' . str_pad($stripped, 2, '0', STR_PAD_LEFT) . '</span>';
  }
}
