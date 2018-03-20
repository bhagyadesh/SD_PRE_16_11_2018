<?php

/**
 * Plugin definition.
 */
$plugin = array(
  'title' => t('Three Column 3-3-3 grid'),
  'category' => t('Intel: 12 Column Grid'),
  'icon' => 'intel_12_threecol_3_3_3_grid.png',
  'theme' => 'intel_12_threecol_3_3_3_grid',
  'admin css' => '../intel_panels_admin_12.css',
  'regions' => array(
    'left_top' => t('Left top'),
    'center_top' => t('Center top'),
    'right_top' => t('Right top'),
    'left_bottom' => t('Left bottom'),
    'right_bottom' => t('Right bottom'),
  ),
);
