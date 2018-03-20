<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Internal (general) Layout'),
  'category' => t('Intel ISDM'),
  'icon' => 'intel_isdm_internal.png',
  'theme' => 'intel_isdm_internal',
  // @TODO: Build universal CSS styles to make these appear right in admin UI.
  //'admin css' => '../intel_panels_admin_12.css',

  // @TODO: Declare additional regions here.
  'regions' => array(
    'panel_title' => t('Segment title section (WARNING: Moves to top of topmost content area).'),
    'top_blue' => t('Top Blue Content Area'),
    'bottom_main' => t('Bottom / Main Content Area'),
  ),
);
