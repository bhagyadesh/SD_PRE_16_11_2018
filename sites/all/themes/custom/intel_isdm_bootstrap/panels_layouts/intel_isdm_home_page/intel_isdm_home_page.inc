<?php

/**
 * Implements hook_panels_layouts().
 */

$plugin = array(
    'title' => t('Home Page'),
    'category' => t('Intel ISDM'),
    'icon' => 'intel_isdm_home_page.png',
    'theme' => 'intel_isdm_home_page',

    'regions' => array(
        'top_left' => t('Top Left'),
        'top_right' => t('Top Right'),
        'banner_top' => t('Banner Top'),
        'middle_left' => t('Market Segment'),
        'middle_right' => t('Middle Right'),
        'middle_right2' => t('Middle Right2'),
        'banner_bottom' => t('Banner Bottom'),
		'fpga' => t('fpga'),
		'partners_market_segment' => t('Partners By Market Segment'),
		'partners_location' => t('Partners By Location'),
        'view_partners' => t('View Partners'),
		'client_market_segments' => t('Client Market Segments'),
		'server_market_segments' => t('Server Market Segments'),
		'eiot_market_segments' => t('Embedded IoT Market Segments'),
		'client_categories' => t('Client Browse by Type'),
		'server_categories' => t('Server Browse by Type'),
		'eiot_categories' => t('Embedded IoT Browse by Type'),		
		'client_explore' => t('Explore for Client'),
		'server_explore' => t('Explore for Server'),    
    )
);
