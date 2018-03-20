<?php
/**
 * @file
 * intel_isdm_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function intel_isdm_feature_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "current_search" && $api == "current_search") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "page_manager" && $api == "pages_default") {
    return array("version" => "1");
  }
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_entityqueue_api().
 */
function intel_isdm_feature_entityqueue_api() {
  list($module, $api) = func_get_args();
  if ($module == "entityqueue" && $api == "entityqueue_default") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function intel_isdm_feature_views_api() {
  return array("version" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function intel_isdm_feature_image_default_styles() {
  $styles = array();

  // Exported image style: segment_icons.
  $styles['segment_icons'] = array(
    'name' => 'segment_icons',
    'label' => 'segment_icons',
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
          'width' => '128',
          'height' => '96',
        ),
        'weight' => '1',
      ),
    ),
  );

  // Exported image style: segment_product_images_179x135.
  $styles['segment_product_images_179x135'] = array(
    'name' => 'segment_product_images_179x135',
    'label' => 'segment_product_images_179x135',
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
          'width' => '179',
          'height' => '135',
          'upscale' => 0,
        ),
        'weight' => '1',
      ),
    ),
  );

  return $styles;
}
