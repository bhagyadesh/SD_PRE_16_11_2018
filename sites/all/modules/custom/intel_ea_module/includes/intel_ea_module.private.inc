<?php

/**
 * @file
 * Contains functions with key functionality not specifically meant for flexible
 * usage outside of this module.
 */

/**
 * Alters the node resource callback sorting by changed rather than created.
 *
 * @see _node_resource_index()
 */
function _intel_ea_module_node_resource_index($page, $fields, $parameters, $page_size) {
  $node_select = db_select('node', 't')
    ->addTag('node_access')
    ->orderBy('changed', 'DESC');

  services_resource_build_index_query($node_select, $page, $fields, $parameters, $page_size, 'node');

  if (!user_access('administer nodes')) {
    $node_select->condition('status', 1);
  }

  $results = services_resource_execute_index_query($node_select);

  return services_resource_build_index_list($results, 'node', 'nid');
}


/**
 * Get allowed values for Current and Future Membership Type fields.
 */
function _intel_ea_module_company_node_get_membership_type($agreement_identifier) {
  switch ($agreement_identifier) {
    // Premier
    case '615':
      return '557';
      break;

    // Associate
    case '606':
    case '614':
    case '622':
    case '624':
    case '628':
    case '632':
    case '634':
    case '626':
    case '1089':
      return '558';
      break;

    // Affiliate
    case '605':
    case '613':
    case '621':
    case '623':
    case '627':
    case '631':
    case '633':
    case '625':
    case '1088':
      return '559';
      break;

    // General
    case '612':
      return '560';
      break;

    // Alliance Staff
    case '779':
      return '556';
      break;

    // Distributor
    case '611':
      return '561';
      break;

    // Intel
    case '618':
      return '562';
      break;

    // Non-Alliance
    case '1153':
      return '1154';
      break;

    // Default/No value
    case '_none':
    default:
      return '_none';
      break;
  }
}


/**
 * Extends the user_access() function adding more fine grained permissions.
 *
 * @param $privileges
 *   An array of permissions, such as "administer nodes", being checked for.
 * @param $account
 *   (optional) The account to check, if not given use currently logged in user.
 *
 * @return
 *   Boolean TRUE if the current user meets the requirements.
 */
function _intel_ea_module_user_access($privileges, $account = NULL) {
  global $user;

  if (!isset($account)) {
    $account = $user;
  }

  if (user_access('administer users', $account)) {
    if (!is_array($privileges)) {
      $privileges = array($privileges);
    }

    foreach ($privileges as $privilege) {
      if (user_access($privilege, $account)) {
        return TRUE;
      }
    }
  }

  return FALSE;
}

/**
 * Helper function to output the variables for an MDF login form.
 */
function _intel_ea_module_mdf_login_variables() {
  // Set up variables to return.
  $mdf_login_variables = array();

  // Client (Intel).
  $mdf_login_variables['client_name'] = 'Intel';
  // Current user.
  global $user;
  $mdf_login_variables['user_id'] = $user->uid;
  // Ticks of current time.
  $mdf_login_variables['t_time'] = _intel_ea_module_unix_timestamp_to_ticks(strtotime('now'));
  // Private key.
  $private_key = '7ef0db17-63c0-48f7-925f-4184fdc9f0a3';
  // Generate token.
  $mdf_login_variables['token'] = _intel_ea_module_sha1_bytes_to_string($mdf_login_variables['client_name'] . $mdf_login_variables['user_id'] . $mdf_login_variables['t_time'] . $private_key);
  // Form action.
  $mdf_login_variables['form_action'] = url('https://imx.intelreimbursement.com/Client/Intel/SSO/SSOLanding.aspx', array('external' => TRUE));

  return $mdf_login_variables;
}



/**
 * Helper function to output the current time equivalent to C# ticks.
 *
 * @param $unix_timestamp
 *   The unix timestamp for current time.
 * @return string
 *   The current time equivalent to C# ticks.
 *
 * @see http://msdn.microsoft.com/en-us/library/system.datetime.ticks.aspx
 */
function _intel_ea_module_unix_timestamp_to_ticks($unix_timestamp) {
  $unix_epoch_ticks = 621355968000000000;

  return number_format(($unix_timestamp * 10000000) +  $unix_epoch_ticks, 0, '.', '');
}

/**
 * Helper function to output a sha1 hash as bytes to string.
 *
 * @param $string_input
 *   The input string to convert.
 * @return string
 *   The converted output string.
 */
function _intel_ea_module_sha1_bytes_to_string($string_input) {
  $input = sha1($string_input, TRUE);
  $byte_array = unpack('C*', $input);
  $string_output = implode("", $byte_array);

  return $string_output;
}

/**
 * Flags ids of an entity type as needing to be re-indexed across all indexes.
 *
 * @param $entity_type
 *   The entity type of the ids to be flagged.
 * @param array $ids
 *   An array of ids to flag for re-indexing.
 */
function _intel_ea_module_search_api_flag($entity_type, $ids) {
  $conditions = array(
    'enabled' => 1,
    'item_type' => $entity_type,
    'read_only' => 0,
  );

  $indexes = search_api_index_load_multiple(FALSE, $conditions);

  if (!$indexes) {
    return;
  }

  search_api_get_datasource_controller($entity_type)->trackItemChange($ids, $indexes);
}


/**
 * Returns a list of fields that are inherited by formulas.
 */
function _intel_ea_module_formula_inherited_fields() {
  return array(
    'field_application',
    'field_chipsets',
    'field_display_independent',
    'field_display_hdmi',
    'field_display_lvds',
    'field_display_other',
    'field_display_pcie_x16',
    'field_display_port_edp',
    'field_display_size',
    'field_display_total',
    'field_display_vga',
    'field_ethernet_controllers',
    'field_intel_technologies',
    'field_intel_wireless',
    'field_memory_ecc',
    'field_memory_max',
    'field_memory_type',
    'field_power',
    'field_processors_count',
    'field_processors_list',
    'field_software_solutions',
    'field_stds_audio',
    'field_stds_camera',
    'field_stds_csix',
    'field_stds_eth',
    'field_stds_eth_ports',
    'field_stds_gps',
    'field_stds_pcie_as',
    'field_stds_pcie_mini',
    'field_stds_pcie_rev',
    'field_stds_pcie_x1',
    'field_stds_pcie_x16',
    'field_stds_pcie_x2',
    'field_stds_pcie_x4',
    'field_stds_pcie_x8',
    'field_stds_pc_104',
    'field_stds_processor_socketed',
    'field_stds_sd_sdio_emmc',
    'field_stds_sim',
    'field_stds_spi',
    'field_stds_storage_cfst',
    'field_stds_storage_ide',
    'field_stds_storage_raid',
    'field_stds_storage_sata',
    'field_stds_storage_ssd_size',
    'field_stds_systems',
    'field_stds_usb_on_the_go',
    'field_stds_usb_usb1',
    'field_stds_usb_usb2',
    'field_stds_usb_usb3',
    'field_stds_wlan',
    'field_stds_wpan',
    'field_stds_wwan',
  );
}

/**
 * Returns values of inherited fields from solutions/components for formulas.
 */
function intel_ea_module_entity_metadata_field_property_get($data, array $options, $name, $type, $info) {

  try {
    $values = array();

    if ($data->type == 'formula') {
      $wrapper = entity_metadata_wrapper('node', $data);
      if ($component_iterator = $wrapper->field_component_group->getIterator()) {
        foreach ($component_iterator as $delta => $collection_wrapper) {
          foreach ($collection_wrapper->field_component_options->value() as $option) {
            $info['parent'] = entity_metadata_wrapper('node', $option);
            $value = entity_metadata_field_property_get($option, $options, $name, $type, $info);
            if (is_array($value)) {
              $values = array_merge($values, $value);
            }
            else {
              $values = array_merge($values, array($value));
            }
          }
        }
      }
    }
    else {
      $values = entity_metadata_field_property_get($data, $options, $name, $type, $info);
    }

    return $values;
  }
  catch (exception $e) {
    watchdog_exception('intel_ea_module', $e);
  }
}

/**
 * Gets the Google Analytics Reports end date.
 *
 * Retrieves the Google Analytics Reports end date from the user's session if
 * it's set, otherwise defaults to today.
 */
function _intel_ea_module_google_analytics_reports_end_get() {
  if (isset($_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['end'])) {
    $end = $_SESSION['intel_ea_module']['member_resource_center']['reports']['google_analytics']['end'];
  }
  else {
    $end = REQUEST_TIME;
  }
  return $end;
}


/**
 * Alters the output of the facet label to be more user friendly by including
 * the translated field label as needed.
 */
function _intel_ea_module_facetapi_facet_value_callback(array $values, array $options) {
  $map = array();

  if (arg(0) == 'node' && is_numeric(arg(1))) {
    $node = node_load(arg(1));

    // If the node is a formula and the field is inherited.
    if ($node->type == 'formula' && in_array($options['field']['key'], _intel_ea_module_formula_inherited_fields())) {
      $instance = field_info_instance('node', $options['field']['key'], 'solution');
    }
    else {
      $instance = field_info_instance('node', $options['field']['key'], $node->type);
    }

    if (module_exists('i18n_field')) {
      $instance = i18n_string_object_translate('field_instance', $instance);
    }

    if ($instance) {
      switch ($options['field']['type']) {
        case 'list<boolean>':
        case 'boolean':
          foreach ($values as $value) {
            $map[$value] = $value ? $instance['label'] : '';
          }
          break;

        case 'list<integer>':
          if (isset($options['field']['entity_type']) && $options['field']['entity_type'] == 'taxonomy_term') {
            break;
          }

        case 'integer':
        case 'decimal':
          foreach ($values as $value) {
            $map[$value] = $value ? $instance['label'] . ': ' . $value : '';
          }
          break;
      }
    }
  }

  if (empty($map)) {
    $map = _search_api_facetapi_facet_create_label($values, $options);
  }

  return $map;
}
