<?php

/**
 * @file
 * Custom Facet API filter for the Intel EA Module module.
 */

/**
 * Plugin that excludes specified facet items.
 */

class FacetapiFilterIntelEAModule extends FacetapiFilter {
  public function execute(array $build) {

    if($this->settings->facet == 'field_company') {
      $character_range = array();
      asort($build);
      foreach ($build as $key => $value) {
        $markup = strtoupper($value['#markup'][0]);
        if (is_numeric($markup) || $markup == 'A') {
          $character_range['# - A'][$value['#indexed_value']] = $value;
        }
        elseif ($markup >= 'B' && $markup <= 'E') {
          $character_range['B - E'][$value['#indexed_value']] = $value;
        }
        elseif ($markup >= 'F' && $markup <= 'H') {
          $character_range['F - H'][$value['#indexed_value']] = $value;
        }
        elseif ($markup >= 'I' && $markup <= 'K') {
          $character_range['I - K'][$value['#indexed_value']] = $value;
        }
        elseif ($markup >= 'L' && $markup <= 'N') {
          $character_range['L - N'][$value['#indexed_value']] = $value;
        }
        elseif ($markup >= 'O' &&  $markup <= 'Q') {
          $character_range['O - Q'][$value['#indexed_value']] = $value;
        }
        elseif ($markup >= 'R' && $markup <= 'S') {
          $character_range['R - S'][$value['#indexed_value']] = $value;
        }
        elseif ($markup >= 'T' && $markup <= 'V') {
          $character_range['T - V'][$value['#indexed_value']] = $value;
        }
        elseif ($markup >= 'W' && $markup <= 'Z') {
          $character_range['W - Z'][$value['#indexed_value']] = $value;
        }
      }
      $build = array();
      foreach ($character_range as $key => $companies) {
        $build[] = array(
          '#markup' => $key,
          '#path' => 'solutions-directory',
          '#html' => FALSE,
          '#count' => count($companies),
          '#active' => 1,
          '#item_children' => $companies,
          '#query' => array(),
        );
      }
    }
    if (arg(0) == 'node' && is_numeric(arg(1))) {
      $node = node_load(arg(1));
      $this->settings->settings['widget'] = 'facetapi_links';

      switch ($this->settings->facet) {
        // Boolean facets.
        case 'field_display_pcie_x16':
        case 'field_memory_ecc':
        case 'field_stds_processor_socketed':
        case 'field_stds_gps':
        case 'field_stds_camera':
        case 'field_stds_csix':
        case 'field_stds_pc_104':
        case 'field_stds_pcie_mini':
        case 'field_stds_pcie_as':
        case 'field_stds_sd_sdio_emmc':
        case 'field_stds_sim':
        case 'field_stds_spi':
        case 'field_stds_usb_on_the_go':
        case 'field_stds_storage_raid':
        case 'field_stds_wpan':
          foreach ($build as $key => $item) {
            if ($item['#indexed_value'] ==  0) {
              unset($build[$key]);
            }
          }
          break;

        // Numeric facets.
        case 'field_display_independent':
        case 'field_display_port_edp':
        case 'field_display_hdmi':
        case 'field_display_lvds':
        case 'field_display_other':
        case 'field_display_vga':
        case 'field_display_total':
        case 'field_memory_max':
        case 'field_processors_count':
        case 'field_stds_eth_ports':
        case 'field_stds_pcie_x1':
        case 'field_stds_pcie_x2':
        case 'field_stds_pcie_x4':
        case 'field_stds_pcie_x8':
        case 'field_stds_pcie_x16':
        case 'field_stds_usb_usb1':
        case 'field_stds_usb_usb2':
        case 'field_stds_usb_usb3':
        case 'field_stds_storage_cfst':
        case 'field_stds_storage_ide':
        case 'field_stds_storage_sata':
        case 'field_stds_storage_ssd_size':
        case 'field_stds_wlan':
        case 'field_stds_wwan':
          foreach ($build as $key => $item) {
            if ($item['#indexed_value'] <=  0) {
              unset($build[$key]);
            }
          }
          break;

        // Taxonomy facets.
        case '':
        case 'field_categories':
		case 'field_fpga':
        case 'field_chipsets':
        case 'field_display_size':
        case 'field_application':
        case 'field_ethernet_controllers':
        case 'field_geographic_location':
        case 'field_intel_technologies':
        case 'field_intel_wireless':
        case 'field_market_segments':
        case 'field_memory_type':
        case 'field_power':
        case 'field_processors_list':
        case 'field_software_solutions':
        case 'field_stds_audio':
        case 'field_stds_eth':
        case 'field_stds_pcie_rev':
        case 'field_stds_systems':
          break;

        // Entity reference facets.
        case 'field_company':
          break;
      }

      // Add the company as a filter on facets displayed on the company page.
      if ($node->type == 'company') {
        foreach ($build as $key => $item) {
          $tnid = $node->tnid ? $node->tnid : $node->nid;
          array_unshift($build[$key]['#query']['f'], 'field_company:' . $tnid);
        }
      }
    }

    return $build;
  }
}
