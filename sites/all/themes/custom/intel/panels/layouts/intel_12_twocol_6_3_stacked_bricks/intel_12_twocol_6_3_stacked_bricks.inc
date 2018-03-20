<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Two Column 6-3 stacked bricks'),
  'category' => t('Intel: 12 Column Grid'),
  'icon' => 'intel_12_twocol_6_3_stacked_bricks.png',
  'theme' => 'intel_12_twocol_6_3_stacked_bricks',
  'admin css' => '../intel_panels_admin_12.css',
  'regions' => array(
    'left_top' => t('Left top'),
    'right_top' => t('Right top'),
    'bottom' => t('Bottom'),
  ),
);
