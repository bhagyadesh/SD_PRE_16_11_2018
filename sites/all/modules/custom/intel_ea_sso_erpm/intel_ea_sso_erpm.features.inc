<?php
/**
 * @file
 * intel_ea_sso_erpm.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function intel_ea_sso_erpm_ctools_plugin_api() {
  list($module, $api) = func_get_args();
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
