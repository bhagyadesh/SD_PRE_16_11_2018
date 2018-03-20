<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Three Column 3-3-3 stacked bricks'),
  'category' => t('Intel: 12 Column Grid'),
  'icon' => 'intel_12_threecol_3_3_3_stacked_bricks.png',
  'theme' => 'intel_12_threecol_3_3_3_stacked_bricks',
  'admin css' => '../intel_panels_admin_12.css',
  'regions' => array(
    'left_top' => t('Left top'),
    'center_top' => t('Center top'),
    'right_top' => t('Right top'),
    'bottom' => t('Bottom'),
  ),
);
