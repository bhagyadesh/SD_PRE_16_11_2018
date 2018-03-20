<?php

/*
Implements hook_views_data().
*/
function joinpromoreport_views_data()
{
	$data = array();
 $data['joinpromoreport']['table']['group'] = t('PromotionReport');
  $data['joinpromoreport']['table']['base'] = array(
    'field' => 'joinpromoreport_id', // This is the identifier field for the view.
    'title' => t('Promo Report'),
    'help' => t('Custom table for promotion report.'),
    'weight' => -10,
  );
  
  
  $data['joinpromoreport']['joinpromoreport_id'] = array(
    'title' => t('id'),
    'help' => t('The ID.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   );
  $data['joinpromoreport']['userid'] = array(
   'title' => t('UserId'),
    'help' => t('The User ID.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   );
   
   $data['joinpromoreport']['username'] = array(
   'title' => t('UserName'),
    'help' => t('The User Name.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   );
  $data['joinpromoreport']['promotionid'] = array(
   'title' => t('PromotionId'),
    'help' => t('The Promotion ID.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   );
   
   $data['joinpromoreport']['promotionname'] = array(
   'title' => t('PromotionName'),
    'help' => t('The Promotion Name.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   );
 $data['joinpromoreport']['created'] = array(
   'title' => t('Created Date'),
    'help' => t('The Date User Joined.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   );
  $data['joinpromoreport']['status'] = array(
   'title' => t('Status'),
    'help' => t('The Status Of User joined or Not joined.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   ); 
    $data['joinpromoreport']['subject'] = array(
   'title' => t('Subject'),
    'help' => t('The Subject For Buyer.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   ); 
   
    $data['joinpromoreport']['buyercompid'] = array(
   'title' => t('BuyerCompanyId'),
    'help' => t('The Buyer company ID.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   );
   
   $data['joinpromoreport']['promotiontype'] = array(
   'title' => t('Type to Join or Question'),
    'help' => t('The Type Of User joined or Questioned.'),
	
	//field info
	'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE, // This is use by the table display plugin.
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
   
   ); 
  return $data;
  
}
   
   