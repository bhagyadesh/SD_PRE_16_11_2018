<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
    'title' => t('Solution'),
    'category' => t('Intel ISDM'),
    'icon' => 'intel_isdm_solution.png',
    'theme' => 'intel_isdm_solution',

    'regions' => array(
        'info_column_one' => t('Product Info First Column'),
        'info_column_two' => t('Product Info Second Column'),
        'middle' => t('Middle Content Area.'),
        'tab_first' => t('First Tab'),
        'tab_second' => t('Second Tab'),
        'sidebar_top' => t('Sidebar Top'),
        'sidebar_bottom' => t('Sidebar Bottom')
    )
);
