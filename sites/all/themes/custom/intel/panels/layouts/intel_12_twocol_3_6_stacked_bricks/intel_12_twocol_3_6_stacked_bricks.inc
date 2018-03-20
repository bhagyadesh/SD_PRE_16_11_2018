<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Two Column 3-6 stacked bricks'),
  'category' => t('Intel: 12 Column Grid'),
  'icon' => 'intel_12_twocol_3_6_stacked_bricks.png',
  'theme' => 'intel_12_twocol_3_6_stacked_bricks',
  'admin css' => '../intel_panels_admin_12.css',
  'regions' => array(
    'left_top' => t('Left top'),
    'right_top' => t('Right top'),
    'bottom' => t('Bottom'),
  ),
);
