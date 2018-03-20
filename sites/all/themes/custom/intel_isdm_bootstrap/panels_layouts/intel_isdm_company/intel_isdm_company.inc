<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
    'title' => t('Company'),
    'category' => t('Intel ISDM'),
    'icon' => 'intel_isdm_company.png',
    'theme' => 'intel_isdm_company',

    'regions' => array(
        'general_info' => t('General Company Info'),
        'company_sidebar' => t('Company Logo and Contact Info'),
        'articles_sidebar' => t('Articles and White Papers'),
        'view_one' => t('View One'),
        'view_two' => t('View Two'),
        'view_three' => t('View Three'),
	'view_four' => t('View Four'),
	'view_five' => t('View Five')
    )
);
