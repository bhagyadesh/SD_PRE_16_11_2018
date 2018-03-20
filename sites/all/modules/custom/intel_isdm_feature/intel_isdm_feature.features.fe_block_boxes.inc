<?php
/**
 * @file
 * intel_isdm_feature.features.fe_block_boxes.inc
 */

/**
 * Implements hook_default_fe_block_boxes().
 */
function intel_isdm_feature_default_fe_block_boxes() {
  $export = array();

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Homepage bottom block';
  $fe_block_boxes->format = 'wysiwyg_basic';
  $fe_block_boxes->machine_name = 'isdm__homepage_block_bottom';
  $fe_block_boxes->body = '<h2 class="pane-title">Harness the Power of Intel® Architecture</h2>
<p>The Solutions Directory is your one stop for industry-leading solutions featuring the latest technology from Intel. Whether you need foundational components to create and speed products to market, or ready-to-go systems and services to help businesses deploy technology solutions, use this directory to find and build your own innovative solutions.</p>';

  $export['isdm__homepage_block_bottom'] = $fe_block_boxes;

  $fe_block_boxes = new stdClass();
  $fe_block_boxes->info = 'Homepage banner block';
  $fe_block_boxes->format = 'wysiwyg_advanced';
  $fe_block_boxes->machine_name = 'isdm__homepage_block_top';
  $fe_block_boxes->body = '<h2 class="pane-title">Support Across the Value Chain</h2><p>Intel is at the center of a vibrant ecosystem of organizations that are speeding connectivity and performance in industries and applications everywhere. Learn more about our featured partner programs and how they are enabling the next generation of Intel&reg;-based products and solutions.</p><p>&nbsp;</p><p><a href="http://www.intel.com/content/www/us/en/intelligent-systems/alliance-overview.html" target="_blank"><img class="iot-logo" src="/sites/all/themes/custom/intel_isdm_bootstrap/images/iot-solutions-alliance.png" /></a><a href="http://www.intel.com/technologyprovider" target="_blank"><img class="itp-logo" src="/sites/all/themes/custom/intel_isdm_bootstrap/images/technology-provider.png" /></a><a href="http://www.altera.com/dsn" target="_blank"><img longdesc="fpga-logo" src="/sites/all/themes/custom/intel_isdm_bootstrap/images/Intel-fdsn.png" /></a></p>';

  $export['isdm__homepage_block_top'] = $fe_block_boxes;

  return $export;
}
