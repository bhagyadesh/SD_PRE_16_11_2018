<?php
/**
 * @file
 * intel_ea_feature.default_video_embed_styles.inc
 */

/**
 * Implements hook_default_video_embed_styles().
 */
function intel_ea_feature_default_video_embed_styles() {
  $export = array();

  $video_embed_style = new stdClass();
  $video_embed_style->disabled = FALSE; /* Edit this to true to make a default video_embed_style disabled initially */
  $video_embed_style->api_version = 1;
  $video_embed_style->name = 'full';
  $video_embed_style->title = '';
  $video_embed_style->data = array(
    'youtube' => array(
      'width' => '940px',
      'height' => '530px',
      'theme' => 'light',
      'autoplay' => 0,
      'rel' => 0,
      'showinfo' => 0,
      'modestbranding' => 1,
      'iv_load_policy' => '3',
      'autohide' => '1',
      'vq' => 'hd720',
    ),
    'vimeo' => array(
      'width' => '940px',
      'height' => '530px',
      'color' => 'ffffff',
      'portrait' => 0,
      'title' => 0,
      'byline' => 0,
      'autoplay' => 0,
      'loop' => 0,
    ),
    'data__active_tab' => 'edit-data-vimeo',
  );
  $export['full'] = $video_embed_style;

  return $export;
}
