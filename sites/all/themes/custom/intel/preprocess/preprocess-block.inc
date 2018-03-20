<?php

/**
 * @file
 * Block level preprocess functions.
 */

/**
 * Implements template_preprocess_block();
 */
function intel_alpha_preprocess_block(&$vars) {
  if ($vars['elements']['#block']->module == 'delta_blocks' && $vars['elements']['#block']->delta == 'breadcrumb') {
    $data = array(
      '#theme' => 'breadcrumb',
      '#breadcrumb' => drupal_get_breadcrumb(),
    );
    $breadcrumb = render($data);
    $vars['content'] = $breadcrumb;
  }
}
