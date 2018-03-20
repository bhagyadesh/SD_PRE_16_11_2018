<?php
/**
 * @file
 * intel_ea_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function intel_ea_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "ckeditor_styles" && $api == "ckeditor_style_rules") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "custom_formatters" && $api == "custom_formatters") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "delta" && $api == "delta") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "elysia_cron" && $api == "default_elysia_cron_rules") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "feeds" && $api == "feeds_importer_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "field_validation" && $api == "default_field_validation_rules") {
    return array("version" => "2");
  }
  list($module, $api) = func_get_args();
  if ($module == "file_entity" && $api == "file_default_displays") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "linkit" && $api == "linkit_profiles") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "panels_mini" && $api == "panels_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "path_breadcrumbs" && $api == "path_breadcrumbs") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "services" && $api == "services") {
    return array("version" => "3");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "video_embed_field" && $api == "default_video_embed_styles") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function intel_ea_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_default_entityform_type().
 */
function intel_ea_feature_default_entityform_type() {
  $items = array();
  $items['general_membership_application'] = entity_import('entityform_type', '{
    "type" : "general_membership_application",
    "label" : "Apply for General Membership",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "wysiwyg_basic" },
      "submission_rules" : {
        "rules_general_membership_application_email_admin" : "rules_general_membership_application_email_admin",
        "rules_general_membership_application_email_submitter" : "rules_general_membership_application_email_submitter"
      },
      "notification_text" : "",
      "notify_emails" : "embedded.alliance.general.membership@intel.com",
      "validation_rules" : [],
      "submit_button_text" : "Finish",
      "submission_page_title" : "Thank You",
      "submission_text" : {
        "value" : "\\u003Cp\\u003EWe received your application, we will repond within 15 business days.\\u003C\\/p\\u003E",
        "format" : "wysiwyg_basic"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "general_membership_submissions",
      "user_submissions_view" : "",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "1" : "1",
        "31" : "31",
        "2" : 0,
        "3" : 0,
        "4" : 0,
        "7" : 0,
        "8" : 0,
        "9" : 0,
        "10" : 0,
        "11" : 0,
        "12" : 0,
        "13" : 0,
        "28" : 0,
        "14" : 0,
        "15" : 0,
        "5" : 0,
        "16" : 0,
        "6" : 0,
        "27" : 0,
        "25" : 0,
        "24" : 0,
        "26" : 0,
        "29" : 0,
        "17" : 0,
        "18" : 0,
        "19" : 0,
        "20" : 0,
        "21" : 0,
        "30" : 0
      },
      "resubmit_action" : "disallow",
      "access_rules" : [],
      "redirect_path" : "",
      "instruction_pre" : {
        "value" : "\\u003Cp\\u003ETo apply for the Intel\\u0026reg; Internet of Things Solutions Alliance, please provide the following information. Navigate the steps in any order. Click \\u0026#39;Finish\\u0026#39; when you have completed all of the steps.\\u003C\\/p\\u003E\\u003Cp\\u003EYOU CANNOT CLAIM MEMBERSHIP IN THE INTEL\\u0026reg; INTERNET OF THINGS SOLUTIONS ALLIANCE UPON YOUR COMPLETION OF THIS APPLICATION. YOU ARE A MEMBER ONLY WHEN, IN ADDITION TO YOUR ASSENT TO THE TERMS OF THIS AGREEMENT, INTEL HAS NOTIFIED YOU IN WRITING THAT YOU HAVE BEEN ACCEPTED INTO THE PROGRAM.\\u003C\\/p\\u003E\\u003Cp\\u003EYour application for membership will be accepted, denied or we will request additional information within 15 business days upon receipt of the completed application.\\u003C\\/p\\u003E",
        "format" : "wysiwyg_basic"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : {
      "submit" : {
        "source" : "eform\\/submit\\/general-membership-application",
        "alias" : "general-membership-application",
        "language" : "und"
      },
      "confirm" : {
        "source" : "eform\\/general-membership-application\\/confirm",
        "alias" : "general-membership-confirmation",
        "language" : "und"
      }
    }
  }');
  $items['membership_renewal_application'] = entity_import('entityform_type', '{
    "type" : "membership_renewal_application",
    "label" : "Membership Renewal",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "wysiwyg_basic" },
      "submission_rules" : { "rules_membership_renewal_application_email_admin" : "rules_membership_renewal_application_email_admin" },
      "notification_text" : "",
      "notify_emails" : "intel.communications.alliance.admin@intel.com",
      "validation_rules" : [],
      "submit_button_text" : "Submit Membership Renewal",
      "submission_page_title" : "Thank You",
      "submission_text" : {
        "value" : "\\u003Cp\\u003EYour membership is renewed.\\u003C\\/p\\u003E\\u003Cp\\u003EReturn to \\u003Ca href=\\u0022\\/member-resource-center\\u0022\\u003EMembers Resource Center\\u003C\\/a\\u003E.\\u003C\\/p\\u003E",
        "format" : "wysiwyg_basic"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "membership_renewal_submissions",
      "user_submissions_view" : "",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "14" : "14",
        "17" : "17",
        "1" : 0,
        "2" : 0,
        "3" : 0,
        "4" : 0,
        "7" : 0,
        "8" : 0,
        "9" : 0,
        "10" : 0,
        "11" : 0,
        "12" : 0,
        "13" : 0,
        "28" : 0,
        "23" : 0,
        "22" : 0,
        "15" : 0,
        "5" : 0,
        "16" : 0,
        "6" : 0,
        "24" : 0,
        "25" : 0,
        "26" : 0,
        "27" : 0,
        "18" : 0,
        "19" : 0,
        "20" : 0,
        "21" : 0
      },
      "resubmit_action" : "new",
      "access_rules" : [],
      "redirect_path" : "",
      "instruction_pre" : { "value" : "", "format" : "wysiwyg_basic" }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : {
      "submit" : {
        "source" : "eform\\/submit\\/membership-renewal-application",
        "alias" : "member-resource-center\\/membership-renewal-application",
        "language" : "und"
      },
      "confirm" : {
        "source" : "eform\\/membership-renewal-application\\/confirm",
        "alias" : "member-resource-center\\/membership-renewal-confirmation",
        "language" : "und"
      }
    }
  }');
  $items['order_free_intel_iotg_gateway'] = entity_import('entityform_type', '{
    "type" : "order_free_intel_iotg_gateway",
    "label" : "Order a Free Intel IoTG Gateway Kit section ",
    "data" : {
      "draftable" : 0,
      "draft_button_text" : "",
      "draft_save_text" : { "value" : "", "format" : "wysiwyg_basic" },
      "submission_rules" : [],
      "notification_text" : "",
      "notify_emails" : "dan.hascall@intel.com",
      "validation_rules" : [],
      "submit_button_text" : "",
      "submission_page_title" : "Thank You",
      "submission_text" : {
        "value" : "\\u003Cp\\u003EWe received your application, we will repond within 15 business days.\\u003C\\/p\\u003E",
        "format" : "wysiwyg_basic"
      },
      "submission_show_submitted" : 0,
      "submissions_view" : "entityforms",
      "user_submissions_view" : "user_entityforms",
      "form_status" : "ENTITYFORM_OPEN",
      "roles" : {
        "2" : "2",
        "1" : 0,
        "3" : 0,
        "4" : 0,
        "7" : 0,
        "8" : 0,
        "9" : 0,
        "10" : 0,
        "11" : 0,
        "12" : 0,
        "13" : 0,
        "28" : 0,
        "14" : 0,
        "15" : 0,
        "5" : 0,
        "16" : 0,
        "6" : 0,
        "27" : 0,
        "25" : 0,
        "24" : 0,
        "26" : 0,
        "29" : 0,
        "17" : 0,
        "18" : 0,
        "19" : 0,
        "20" : 0,
        "21" : 0,
        "30" : 0,
        "31" : 0
      },
      "resubmit_action" : "disallow",
      "access_rules" : [],
      "redirect_path" : "register-your-hardware-kit",
      "instruction_pre" : {
        "value" : "\\u003Ca id=\\u0022freeGateway\\u0022\\u003E\\u003C\\/a\\u003E\\r\\n\\u003Cp\\u003EIntel would like to assist you in enabling your IOT software solutions using the Intel IoTG Gateway kits. Intel will provide you with one (1) no-charge gateway hardware platform for your use, access to our IOT gateway software stack and a 90-day evaluation license with direct support from Intel while completing your enabling effort.\\u0026nbsp; In order to receive your kit, we need some information from you.\\u003C\\/p\\u003E\\r\\n\\r\\n\\u003Ca id=\\u0022step1\\u0022\\u003E\\u003C\\/a\\u003E\\r\\n\\u003Cp\\u003EFor accessing the kit and the SW package please follow these steps outlined below:\\u003C\\/p\\u003E\\u003Cp\\u003E\\u003Cstrong\\u003ESelect Your Hardware Kit\\u003C\\/strong\\u003E\\u003C\\/p\\u003E\\u003Cp\\u003EIntel will provide you with one (1) no-charge gateway platform for your enabling effort. We are providing two options that you can choose from our solution providers. Please select one of the two platforms listed below and we will ship it directly to the person you listed above for the gateway shipment.\\u003C\\/p\\u003E\\r\\n\\u003Cp\\u003E\\u003Ca id=\\u0022step2\\u0022\\u003E\\u003C\\/a\\u003E\\u003C\\/p\\u003E",
        "format" : "wysiwyg_advanced_w_styles"
      }
    },
    "weight" : "0",
    "rdf_mapping" : [],
    "paths" : []
  }');
  return $items;
}

/**
 * Implements hook_flag_default_flags().
 */
function intel_ea_feature_flag_default_flags() {
  $flags = array();
  // Exported flag: "Displayed - End User".
  $flags['displayed_end_user'] = array(
    'entity_type' => 'taxonomy_term',
    'title' => 'Displayed - End User',
    'global' => '1',
    'types' => array(
      0 => 'market_segments',
    ),
    'flag_short' => 'Displayed - End User',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Displayed - End User',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'diff_standard' => 0,
      'approved_nouns_grid' => 0,
      'approved_nouns_list' => 0,
      'token' => 0,
      'opp_resource_list' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'module' => 'intel_ea_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  // Exported flag: "Promoted - End User".
  $flags['promoted_end_user'] = array(
    'entity_type' => 'node',
    'title' => 'Promoted - End User',
    'global' => '1',
    'types' => array(
      0 => 'feed_item',
      1 => 'formula',
      2 => 'solution',
      3 => 'story',
    ),
    'flag_short' => 'Promoted - End User',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Promoted - End User',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'diff_standard' => 0,
      'training_center_tile' => 0,
      'training_section_tab' => 0,
      'training_section_slide' => 0,
      'token' => 0,
      'formula_list' => 0,
      'formula_teaser' => 0,
      'solution_list' => 0,
      'solution_list_quickview' => 0,
      'opp_list_sticky' => 0,
      'opp_list' => 0,
      'roster_list_premier' => 0,
      'roster_list' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 1,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'intel_ea_feature',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_image_default_styles().
 */
function intel_ea_feature_image_default_styles() {
  $styles = array();

  // Exported image style: 145w.
  $styles['145w'] = array(
    'name' => '145w',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '145',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '145w',
  );

  // Exported image style: 145x80.
  $styles['145x80'] = array(
    'name' => '145x80',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '145',
          'height' => '80',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '145x80',
  );

  // Exported image style: 160w.
  $styles['160w'] = array(
    'name' => '160w',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '160',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '160w',
  );

  // Exported image style: 160x120.
  $styles['160x120'] = array(
    'name' => '160x120',
    'effects' => array(
      4 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '160',
          'height' => '120',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '160x120',
  );

  // Exported image style: 175w.
  $styles['175w'] = array(
    'name' => '175w',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '175',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '175w',
  );

  // Exported image style: 190w.
  $styles['190w'] = array(
    'name' => '190w',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '190',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '190w',
  );

  // Exported image style: 200w.
  $styles['200w'] = array(
    'name' => '200w',
    'effects' => array(
      3 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '200',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '200w',
  );

  // Exported image style: 200x150.
  $styles['200x150'] = array(
    'name' => '200x150',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '200',
          'height' => '150',
        ),
        'weight' => '1',
      ),
    ),
    'label' => '200x150',
  );

  // Exported image style: 210w.
  $styles['210w'] = array(
    'name' => '210w',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '210',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '210w',
  );

  // Exported image style: 220w.
  $styles['220w'] = array(
    'name' => '220w',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '220',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '220w',
  );

  // Exported image style: 220x165.
  $styles['220x165'] = array(
    'name' => '220x165',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '220',
          'height' => '165',
        ),
        'weight' => '1',
      ),
    ),
    'label' => '220x165',
  );

  // Exported image style: 235x115.
  $styles['235x115'] = array(
    'name' => '235x115',
    'label' => '235x115',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '235',
          'height' => '115',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: 52x39.
  $styles['52x39'] = array(
    'name' => '52x39',
    'effects' => array(
      2 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => '52',
          'height' => '39',
        ),
        'weight' => '1',
      ),
    ),
    'label' => '52x39',
  );

  // Exported image style: 85w.
  $styles['85w'] = array(
    'name' => '85w',
    'effects' => array(
      1 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
        'name' => 'image_scale',
        'data' => array(
          'width' => '85',
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
    'label' => '85w',
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function intel_ea_feature_node_info() {
  $items = array(
    'company' => array(
      'name' => t('Company'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'component' => array(
      'name' => t('Component'),
      'base' => 'node_content',
      'description' => t('A component is a non-member solution used in a formula.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => t('A component is a non-member solution used in a formula.'),
    ),
    'feed' => array(
      'name' => t('Feed'),
      'base' => 'node_content',
      'description' => t('Subscribe to RSS or Atom feeds. Creates nodes of the content type "Feed item" from feed content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'feed_item' => array(
      'name' => t('Feed item'),
      'base' => 'node_content',
      'description' => t('This content type is being used for automatically aggregated content from feeds.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'formula' => array(
      'name' => t('Formula'),
      'base' => 'node_content',
      'description' => t('A formula is a grouping of non-member components and member solutions.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'notification' => array(
      'name' => t('Notification'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'opportunity' => array(
      'name' => t('Opportunity'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Name'),
      'help' => '',
    ),
    'page' => array(
      'name' => t('Page'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'solution' => array(
      'name' => t('Solution'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'story' => array(
      'name' => t('Story'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'training_section' => array(
      'name' => t('Training Section'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
    'training_sub_section' => array(
      'name' => t('Training Sub-Section'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function intel_ea_feature_default_search_api_index() {
  $items = array();
  $items['co_marketing_center'] = entity_import('search_api_index', '{
    "name" : "Co Marketing Center",
    "machine_name" : "co_marketing_center",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "opportunity" ] },
      "index_directly" : 1,
      "cron_limit" : "12",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_opportunities_taxonomy_term_eb" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_opportunities_taxonomy_term_eb:name" : { "type" : "list\\u003Cstring\\u003E" },
        "field_opportunities_taxonomy_term_eb:url" : { "type" : "list\\u003Curi\\u003E" },
        "field_opportunities_taxonomy_term_eb:weight" : { "type" : "list\\u003Cstring\\u003E" },
        "field_opportunities_taxonomy_term_eb_delta" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_aggregation_1" : { "type" : "string" },
        "search_api_aggregation_2" : { "type" : "string" },
        "search_api_aggregation_4" : { "type" : "string" },
        "search_api_language" : { "type" : "list\\u003Cstring\\u003E" },
        "source" : { "type" : "integer", "entity_type" : "node" },
        "source:field_opportunities_taxonomy_term_eb" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "source:field_opportunities_taxonomy_term_eb:name" : { "type" : "list\\u003Cstring\\u003E" },
        "source:field_opportunities_taxonomy_term_eb:url" : { "type" : "list\\u003Curi\\u003E" },
        "source:field_opportunities_taxonomy_term_eb:weight" : { "type" : "list\\u003Cstring\\u003E" },
        "source:field_opportunities_taxonomy_term_eb_delta" : { "type" : "list\\u003Cstring\\u003E" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "taxonomy_term entity referenced from field_opportunities \\u00bb Weight (sort)",
                "type" : "first",
                "fields" : [
                  "field_opportunities_taxonomy_term_eb:weight",
                  "source:field_opportunities_taxonomy_term_eb:weight"
                ],
                "description" : "A First aggregation of the following fields: taxonomy_term entity referenced from field_opportunities \\u00bb Weight, Translation source node \\u00bb taxonomy_term entity referenced from field_opportunities \\u00bb Weight."
              },
              "search_api_aggregation_2" : {
                "name" : "Delta of taxonomy_term entity referenced from field_opportunities (sort)",
                "type" : "first",
                "fields" : [
                  "field_opportunities_taxonomy_term_eb_delta",
                  "source:field_opportunities_taxonomy_term_eb_delta"
                ],
                "description" : "A First aggregation of the following fields: Delta of taxonomy_term entity referenced from field_opportunities, Translation source node \\u00bb Delta of taxonomy_term entity referenced from field_opportunities."
              },
              "search_api_aggregation_4" : {
                "name" : " taxonomy_term entity referenced from field_opportunities (aggregated)",
                "type" : "first",
                "fields" : [
                  "field_opportunities_taxonomy_term_eb",
                  "source:field_opportunities_taxonomy_term_eb"
                ],
                "description" : "A First aggregation of the following fields: taxonomy_term entity referenced from field_opportunities, Translation source node \\u00bb taxonomy_term entity referenced from field_opportunities."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['companies'] = entity_import('search_api_index', '{
    "name" : "Companies",
    "machine_name" : "companies",
    "description" : null,
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "company" ] },
      "index_directly" : 1,
      "cron_limit" : "1",
      "data_alter_callbacks" : {
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "-48",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-47", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-46", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-45", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-44", "settings" : [] },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-43", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : [],
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : { "fields" : [], "spaces" : "[^[:alnum:]]", "ignorable" : "[\\u0027]" }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      },
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "field_company_node_eb:field_categories" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_company_node_eb:field_geographic_location" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_company_node_eb:field_market_segments" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_company_node_eb:field_pre_release" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_company_node_eb:field_processors_list" : {
          "type" : "list\\u003Clist\\u003Cinteger\\u003E\\u003E",
          "entity_type" : "taxonomy_term"
        },
        "field_company_node_eb:status" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_membership_tier" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_membership_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "list\\u003Cstring\\u003E" },
        "status" : { "type" : "boolean" },
        "title" : { "type" : "string" }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  $items['solutions'] = entity_import('search_api_index', '{
    "name" : "Solutions Directory",
    "machine_name" : "solutions",
    "description" : "Index of the Solution and Formula content types used for the Solutions Directory landing page.",
    "server" : "solr",
    "item_type" : "node",
    "options" : {
      "datasource" : { "bundles" : [ "formula", "solution" ] },
      "index_directly" : 1,
      "cron_limit" : "20",
      "fields" : {
        "author" : { "type" : "integer", "entity_type" : "user" },
        "body:value" : { "type" : "text" },
        "changed" : { "type" : "date" },
        "created" : { "type" : "date" },
        "field_application" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_application:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_application:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_categories" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_chipsets" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_chipsets:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_chipsets:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_company" : { "type" : "integer", "entity_type" : "node" },
        "field_company:field_membership_type:weight" : { "type" : "integer" },
        "field_company:title" : { "type" : "text" },
        "field_display_hdmi" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_display_independent" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_display_lvds" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_display_other" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_display_pcie_x16" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_display_port_edp" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_display_size" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_display_total" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_display_vga" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_end_user_description:value" : { "type" : "text" },
        "field_ethernet_controllers" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_ethernet_controllers:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_ethernet_controllers:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_geographic_location" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_geographic_location:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_geographic_location:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_geographic_region:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_geographic_region:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_intel_technologies" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_intel_technologies:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_intel_technologies:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_intel_wireless" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_intel_wireless:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_intel_wireless:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_market_segments" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_market_segments:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_market_segments:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_membership_type" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_memory_ecc" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_memory_max" : { "type" : "list\\u003Cdecimal\\u003E" },
        "field_memory_type" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_power" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_power:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_power:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_pre_release" : { "type" : "boolean" },
        "field_processors_count" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_processors_list" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_software_solutions" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_software_solutions:field_synonyms" : { "type" : "list\\u003Clist\\u003Ctext\\u003E\\u003E" },
        "field_software_solutions:name" : { "type" : "list\\u003Ctext\\u003E" },
        "field_stds_audio" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_stds_camera" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_csix" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_eth" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_stds_eth_ports" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_gps" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_pc_104" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_pcie_as" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_pcie_mini" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_pcie_rev" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_stds_pcie_x1" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_pcie_x16" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_pcie_x2" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_pcie_x4" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_pcie_x8" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_processor_socketed" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_sd_sdio_emmc" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_sim" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_spi" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_storage_cfst" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_storage_ide" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_storage_raid" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_storage_sata" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_storage_ssd_size" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_systems" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_stds_usb_on_the_go" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_usb_usb1" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_usb_usb2" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_usb_usb3" : { "type" : "list\\u003Cinteger\\u003E" },
        "field_stds_wlan" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_stds_wpan" : { "type" : "list\\u003Cboolean\\u003E" },
        "field_stds_wwan" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "nid" : { "type" : "integer" },
        "promote" : { "type" : "boolean" },
        "search_api_access_node" : { "type" : "list\\u003Cstring\\u003E" },
        "search_api_language" : { "type" : "list\\u003Cstring\\u003E" },
        "status" : { "type" : "boolean" },
        "sticky" : { "type" : "boolean" },
        "title" : { "type" : "text" },
        "type" : { "type" : "string" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_node_status" : { "status" : 1, "weight" : "-50", "settings" : [] },
        "search_api_alter_add_hierarchy" : { "status" : 0, "weight" : "-48", "settings" : { "fields" : [] } },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "-47", "settings" : { "mode" : "full" } },
        "search_api_alter_add_aggregation" : { "status" : 0, "weight" : "-46", "settings" : [] },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "-45", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 1,
          "weight" : "-44",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_node_access" : { "status" : 1, "weight" : "-43", "settings" : [] },
        "search_api_alter_bundle_filter" : {
          "status" : 0,
          "weight" : "-10",
          "settings" : { "default" : "1", "bundles" : [] }
        }
      },
      "processors" : {
        "search_api_case_ignore" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "fields" : { "title" : true, "body:value" : true } }
        },
        "search_api_html_filter" : {
          "status" : 0,
          "weight" : "10",
          "settings" : {
            "fields" : { "body:value" : true },
            "title" : 1,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 0,
          "weight" : "20",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : { "title" : true, "body:value" : true },
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_server().
 */
function intel_ea_feature_default_search_api_server() {
  $items = array();
  $items['solr'] = entity_import('search_api_server', '{
    "name" : "Solr",
    "machine_name" : "solr",
    "description" : "",
    "class" : "search_api_solr_service",
    "options" : {
      "clean_ids_form" : [],
      "clean_ids" : false,
      "site_hash_form" : [],
      "site_hash" : false,
      "scheme" : "http",
      "host" : "198.58.109.185",
      "port" : "8983",
      "path" : "\\/solr\\/intel_isv_client_prod",
      "http_user" : "admin",
      "http_pass" : "D1ff3r3nt",
      "excerpt" : 0,
      "retrieve_data" : 0,
      "highlight_data" : 0,
      "skip_schema_check" : 0,
      "solr_version" : "",
      "http_method" : "POST",
      "autocorrect_spell" : 1,
      "autocorrect_suggest_words" : 1
    },
    "enabled" : "1",
    "rdf_mapping" : []
  }');
  return $items;
}
