<?php
/**
 * @file
 * Default theme implementation for field collection items.
 *
 * Available variables:
 * - $content: An array of comment items. Use render($content) to print them all, or
 *   print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $title: The (sanitized) field collection item label.
 * - $url: Direct url of the current entity if specified.
 * - $page: Flag for the full page state.
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. By default the following classes are available, where
 *   the parts enclosed by {} are replaced by the appropriate values:
 *   - entity-field-collection-item
 *   - field-collection-item-{field_name}
 *
 * Other variables:
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 *
 * @see template_preprocess()
 * @see template_preprocess_entity()
 * @see template_process()
 */
?>
<div class="<?php print $classes; ?> clearfix"<?php print $attributes; ?>>
    <div class="content"<?php print $content_attributes; ?>>
        <div><?php print render($content['field_volume']); ?></div>   
        <table class="table">
            <tr><td><?php print render($content['field_product_description']); ?></td></tr>
			<tr><td><?php print render($content['field_estimated_time_of_delivery']); ?></td></tr>
			<tr><td><?php print render($content['field_categories']); ?></td></tr>

        </table>

        <?php
        hide($content['field_volume']);
        hide($content['field_product_description']);
        hide($content['field_estimated_time_of_delivery']);
        hide($content['field_match_builder']);
        hide($content['field_manual_builder']);
        hide($content['field_recommended_builder']);
        hide($content['field_categories']);
        hide($content['field_chipsets']);
        hide($content['field_display_technology']);
        hide($content['field_display_independent']);
        hide($content['field_display_port_edp']);
        hide($content['field_display_hdmi']);
        hide($content['field_display_lvds']);
        hide($content['field_display_other']);
        hide($content['field_display_vga']);
        hide($content['field_display_total']);
        hide($content['field_number_of_dvi_ports']);
        hide($content['field_display_size']);
        hide($content['field_display_pcie_x16']);
        hide($content['field_application']);
        hide($content['field_ethernet_controllers']);
        hide($content['field_geographic_location']);
        hide($content['field_intel_technologies']);
        hide($content['field_intel_wireless']);
        hide($content['field_market_segments']);
        hide($content['field_memory_ecc']);
        hide($content['field_memory_max']);
        hide($content['field_memory_type']);
        hide($content['field_power']);
        hide($content['field_processors_count']);
        hide($content['field_stds_processor_socketed']);
        hide($content['field_processors_list']);
        hide($content['field_software_solutions']);
        hide($content['field_stds_audio']);
        hide($content['field_stds_gps']);
        hide($content['field_number_of_serial_ports']);
        hide($content['field_stds_camera']);
        hide($content['field_stds_csix']);
        hide($content['field_stds_pc_104']);
        hide($content['field_keyboard_and_mouse']);
        hide($content['field_stds_pcie_mini']);
        hide($content['field_stds_pcie_rev']);
        hide($content['field_stds_pcie_x1']);
        hide($content['field_stds_pcie_x2']);
        hide($content['field_stds_pcie_x4']);
        hide($content['field_stds_pcie_x8']);
        hide($content['field_stds_pcie_x16']);
        hide($content['field_stds_pcie_as']);
        hide($content['field_stds_sd_sdio_emmc']);
        hide($content['field_stds_sim']);
        hide($content['field_stds_spi']);
        hide($content['field_stds_usb_on_the_go']);
        hide($content['field_stds_usb_usb1']);
        hide($content['field_stds_usb_usb2']);
        hide($content['field_stds_usb_usb3']);
        hide($content['field_stds_eth']);
        hide($content['field_stds_eth_ports']);
        hide($content['field_stds_wwan']);
        hide($content['field_stds_storage_cfst']);
        hide($content['field_stds_storage_ide']);
        hide($content['field_stds_storage_sata']);
        hide($content['field_stds_storage_raid']);
        hide($content['field_stds_storage_ssd_size']);
        hide($content['field_stds_systems']);
        hide($content['field_stds_wlan']);
        hide($content['field_stds_wpan']);
        hide($content['field_categories_hidden']);
		
       //hide($content['field_stds_storage_raid']); 


        $field_lists = array();
/* 		if ($content['field_categories']['#items']) {
         $field_lists_category = $content['field_categories'];
        } */

        if ($content['field_chipsets']['#items']) {
          $field_lists[] = $content['field_chipsets'];
        }
        if ($content['field_display_technology']['#items']) {
          $field_lists[] = $content['field_display_technology'];
        }

        if ($content['field_display_independent']['#items']) {
          $field_lists[] = $content['field_display_independent'];
        }
        if ($content['field_display_port_edp']['#items']) {
          $field_lists[] = $content['field_display_port_edp'];
        }
        if ($content['field_display_hdmi']['#items']) {
          $field_lists[] = $content['field_display_hdmi'];
        }
        if ($content['field_display_lvds']['#items']) {
          $field_lists[] = $content['field_display_lvds'];
        }
        if ($content['field_display_other']['#items']) {
          $field_lists[] = $content['field_display_other'];
        }
        if ($content['field_display_vga']['#items']) {
          $field_lists[] = $content['field_display_vga'];
        }
        if ($content['field_display_total']['#items']) {
          $field_lists[] = $content['field_display_total'];
        }
        if ($content['field_number_of_dvi_ports']['#items']) {
          $field_lists[] = $content['field_number_of_dvi_ports'];
        }
        if ($content['field_display_size']['#items']) {
          $field_lists[] = $content['field_display_size'];
        }
        if ($content['field_display_pcie_x16']['#items'] && $content['field_display_pcie_x16']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_display_pcie_x16'];
        }
        if ($content['field_application']['#items']) {
          $field_lists[] = $content['field_application'];
        }
        if ($content['field_ethernet_controllers']['#items']) {
          $field_lists[] = $content['field_ethernet_controllers'];
        }
        if ($content['field_geographic_location']['#items']) {
          $field_lists[] = $content['field_geographic_location'];
        }
        if ($content['field_intel_technologies']['#items']) {
          $field_lists[] = $content['field_intel_technologies'];
        }
        if ($content['field_intel_wireless']['#items']) {
          $field_lists[] = $content['field_intel_wireless'];
        }
        if ($content['field_market_segments']['#items']) {
          $field_lists[] = $content['field_market_segments'];
        }

        if ($content['field_memory_ecc']['#items'] && $content['field_memory_ecc']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_memory_ecc'];
        }
        if ($content['field_memory_max']['#items']) {
          $field_lists[] = $content['field_memory_max'];
        }
        if ($content['field_memory_type']['#items']) {
          $field_lists[] = $content['field_memory_type'];
        }
        if ($content['field_power']['#items']) {
          $field_lists[] = $content['field_power'];
        }
        if ($content['field_processors_count']['#items']) {
          $field_lists[] = $content['field_processors_count'];
        }
        if ($content['field_stds_processor_socketed']['#items'] && $content['field_stds_processor_socketed']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_processor_socketed'];
        }
        if ($content['field_processors_list']['#items']) {
          $field_lists[] = $content['field_processors_list'];
        }
        if ($content['field_software_solutions']['#items']) {
          $field_lists[] = $content['field_software_solutions'];
        }
        if ($content['field_stds_audio']['#items']) {
          $field_lists[] = $content['field_stds_audio'];
        }
        if ($content['field_stds_gps']['#items'] && $content['field_stds_gps']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_gps'];
        }
        if ($content['field_number_of_serial_ports']['#items']) {
          $field_lists[] = $content['field_number_of_serial_ports'];
        }
        if ($content['field_stds_camera']['#items'] && $content['field_stds_camera']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_camera'];
        }
        if ($content['field_stds_csix']['#items'] && $content['field_stds_csix']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_csix'];
        }
        if ($content['field_stds_pc_104']['#items'] && $content['field_stds_pc_104']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_pc_104'];
        }
        if ($content['field_keyboard_and_mouse']['#items'] && $content['field_keyboard_and_mouse']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_keyboard_and_mouse'];
        }
        if ($content['field_stds_pcie_mini']['#items'] && $content['field_stds_pcie_mini']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_pcie_mini'];
        }
        if ($content['field_stds_pcie_rev']['#items']) {
          $field_lists[] = $content['field_stds_pcie_rev'];
        }
        if ($content['field_stds_pcie_x1']['#items']) {
          $field_lists[] = $content['field_stds_pcie_x1'];
        }
        if ($content['field_stds_pcie_x2']['#items']) {
          $field_lists[] = $content['field_stds_pcie_x2'];
        }
        if ($content['field_stds_pcie_x4']['#items']) {
          $field_lists[] = $content['field_stds_pcie_x4'];
        }
        if ($content['field_stds_pcie_x8']['#items']) {
          $field_lists[] = $content['field_stds_pcie_x8'];
        }
        if ($content['field_stds_pcie_x16']['#items']) {
          $field_lists[] = $content['field_stds_pcie_x16'];
        }
        if ($content['field_stds_pcie_as']['#items'] && $content['field_stds_pcie_as']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_pcie_as'];
        }
        if ($content['field_stds_sd_sdio_emmc']['#items'] && $content['field_stds_sd_sdio_emmc']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_sd_sdio_emmc'];
        }
        if ($content['field_stds_sim']['#items'] && $content['field_stds_sim']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_sim'];
        }
        if ($content['field_stds_spi']['#items'] && $content['field_stds_spi']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_spi'];
        }
        if ($content['field_stds_usb_on_the_go']['#items'] && $content['field_stds_usb_on_the_go']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_usb_on_the_go'];
        }
        if ($content['field_stds_usb_usb1']['#items']) {
          $field_lists[] = $content['field_stds_usb_usb1'];
        }
        if ($content['field_stds_usb_usb2']['#items']) {
          $field_lists[] = $content['field_stds_usb_usb2'];
        }
        if ($content['field_stds_usb_usb3']['#items']) {
          $field_lists[] = $content['field_stds_usb_usb3'];
        }
        if ($content['field_stds_eth']['#items']) {
          $field_lists[] = $content['field_stds_eth'];
        }
        if ($content['field_stds_eth_ports']['#items']) {
          $field_lists[] = $content['field_stds_eth_ports'];
        }
        if ($content['field_stds_wwan']['#items']) {
          $field_lists[] = $content['field_stds_wwan'];
        }
        if ($content['field_stds_storage_cfst']['#items']) {
          $field_lists[] = $content['field_stds_storage_cfst'];
        }
        if ($content['field_stds_storage_ide']['#items']) {
          $field_lists[] = $content['field_stds_storage_ide'];
        }
        if ($content['field_stds_storage_sata']['#items']) {
          $field_lists[] = $content['field_stds_storage_sata'];
        }
        if ($content['field_stds_storage_raid']['#items'] && $content['field_stds_storage_raid']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_storage_raid'];
        }
        if ($content['field_stds_storage_ssd_size']['#items']) {
          $field_lists[] = $content['field_stds_storage_ssd_size'];
        }
        if ($content['field_stds_systems']['#items']) {
          $field_lists[] = $content['field_stds_systems'];
        }
        if ($content['field_stds_wlan']['#items']) {
          $field_lists[] = $content['field_stds_wlan'];
        }
        if ($content['field_stds_wpan']['#items'] && $content['field_stds_wpan']['#items'][0]['value'] != 0) {
          $field_lists[] = $content['field_stds_wpan'];
        }
		
		  $grid = "<div class = 'product-info-table'><table>";
      $grid .= "<tr class='rfp-product-info-row'>";
		  $i = 1;
       foreach ($field_lists as $value) {
  
		//$splitted = explode(":", render($value));
		//$grid .= "<td><tr>".render($splitted[0])."</tr><tr>".render($splitted[1])."</tr></td>";
		
		$grid .= "<td>" . render($value) . "</td>";
		        
		
if($i % 4 == 0) 
				   $grid .= "</tr><tr class='rfp-product-info-row'>";     

		$i++;
        }
		      $grid .= "</tr>";

        $grid .= "</table></div>";
		//print $grid;

        //print_r($content);
		print $grid;

        //print_r($content);  
	
	
	
      
		
        print render($content);
        
       
	?>	
		


 <?php
        $ul = '<table  class="table">';
		$ul .="<tr><th width=40%>Builder</th><th width=30%>Proposal Status</th><th width=30%>Proposal State</th></tr>";
		
        $entity_id = explode('/', $url);

        foreach ($content['field_recommended_builder']['#items'] as $key => $value) {

          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'proposal')
              ->fieldCondition('field_requirement', 'value', arg(1), '=')
              ->fieldCondition('field_sub_requirement', 'value', $entity_id[3], '=')
              ->fieldCondition('field_builder', 'value', $value['target_id'], '=')
              ->fieldCondition('field_builder_source', 'value', 1, '=')
              ->addMetaData('account', user_load(1));
          $result = $query->execute();
          //if (node_load(array_keys($result['node'])[0])->workflow_state_name == 'Published')
          if (arg(2) == 'inteladmin') {
			  
			  $prop1 = node_load(array_keys($result['node'])[0]);
              if ($prop1->workflow_state_name == 'Published') {
				
				$items_ap = field_get_items('node', $prop1, 'field_approver');
				 foreach ($items_ap as $item) {
				   $fc = field_collection_field_get_entity($item);
				 }
				 $approval_status = $fc->field_approval_status['und'][0]['value'] ? $fc->field_approval_status['und'][0]['value'] : "NA";
				 
				 //$approval_status = ($approval_status == "Accept" || $approval_status == "Reject") ? $approval_status . "ed" : $approval_status;
				 
				 if($approval_status == "Accept") {
					 $approval_status = "Accepted";
				 } else if($approval_status == "Accept with no proposal") {
					 $approval_status = "Accepted with no proposal";
				 } else if($approval_status == "Reject") {
					 $approval_status = "Rejected";
				 } else if($approval_status == "Need Update") {
					 $approval_status = "Update Required";
				 }
				 
              $ul .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>" . l('Edit Proposal', 'node/' . array_keys($result['node'])[0] . '/edit', array('target' => '_blank', 'class' => 'popup')) . "</td><td width=30%>" . $approval_status . "</td></tr>";
			}
            else {
              $ul .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>Proposal not yet received</td><td width=30%>-</td></tr>";
			}
          }
          else {
            $prop1 = node_load(array_keys($result['node'])[0]);
            if ($prop1->workflow_state_name == 'Published') {
				
				$items_ap = field_get_items('node', $prop1, 'field_approver');
				 foreach ($items_ap as $item) {
				   $fc = field_collection_field_get_entity($item);
				 }
				 $approval_status = $fc->field_approval_status['und'][0]['value'] ? $fc->field_approval_status['und'][0]['value'] : "NA";
				 
				 //$approval_status = ($approval_status == "Accept" || $approval_status == "Reject") ? $approval_status . "ed" : $approval_status;
				 
				 if($approval_status == "Accept") {
					 $approval_status = "Accepted";
				 } else if($approval_status == "Accept with no proposal") {
					 $approval_status = "Accepted with no proposal";
				 } else if($approval_status == "Reject") {
					 $approval_status = "Rejected";
				 } else if($approval_status == "Need Update") {
					 $approval_status = "Update Required";
				 }
				 
              $ul .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>" . l('View Proposal', 'node/' . array_keys($result['node'])[0] . '/edit/buyer', array('target' => '_blank', 'class' => 'popup')) . "</td><td width=30%>" . $approval_status . "</td></tr>";
			}
            else {
              $ul .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>Proposal not yet received</td><td width=30%>-</td></tr>";
			}
          }
        }
        $ul .= "</table>";
        if (arg(0) != 'manageproposal') {
          if ($content['field_recommended_builder']['#items']) {
            print '<div class="field field-label-above"><div class="field-label builder-class">Recommended Builders</div><div class="field-items1" width="100%"><div class="field-item even" property="content:encoded">' . $ul . '</div></div></div>';
          }
        }

		
		
        $ulm = '<table  class="table">';
		$ulm .="<tr><th width=40%>Builder</th><th width=30%>Proposal Status</th><th width=30%>Proposal State</th></tr>";
        foreach ($content['field_match_builder']['#items'] as $key => $value) {
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'proposal')
              ->fieldCondition('field_requirement', 'value', arg(1), '=')
              ->fieldCondition('field_sub_requirement', 'value', $entity_id[3], '=')
              ->fieldCondition('field_builder', 'value', $value['target_id'], '=')
              ->fieldCondition('field_builder_source', 'value', 2, '=')
              ->addMetaData('account', user_load(1));
          $result = $query->execute();

          //if (node_load(array_keys($result['node'])[0])->workflow_state_name == 'Published')
          if (arg(2) == 'inteladmin') {
			$prop1 = node_load(array_keys($result['node'])[0]);
            if ($prop1->workflow_state_name == 'Published') {
				
				$items_ap = field_get_items('node', $prop1, 'field_approver');
				 foreach ($items_ap as $item) {
				   $fc = field_collection_field_get_entity($item);
				 }
				 $approval_status = $fc->field_approval_status['und'][0]['value'] ? $fc->field_approval_status['und'][0]['value'] : "NA";
				 
				 //$approval_status = ($approval_status == "Accept" || $approval_status == "Reject") ? $approval_status . "ed" : $approval_status;
				 
				 if($approval_status == "Accept") {
					 $approval_status = "Accepted";
				 } else if($approval_status == "Accept with no proposal") {
					 $approval_status = "Accepted with no proposal";
				 } else if($approval_status == "Reject") {
					 $approval_status = "Rejected";
				 } else if($approval_status == "Need Update") {
					 $approval_status = "Update Required";
				 }
				 
              $ulm .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>" . l('Edit Proposal', 'node/' . array_keys($result['node'])[0] . '/edit', array('target' => '_blank', 'class' => 'popup')) . "</td><td width=30%>" . $approval_status . "</td></tr>";
			}
            else {
              $ulm .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>Proposal not yet received</td><td width=30%>-</td></tr>";
			}
          }
          else {
			   $prop1 = node_load(array_keys($result['node'])[0]);
               if ($prop1->workflow_state_name == 'Published') {
				 $items_ap = field_get_items('node', $prop1, 'field_approver');
				 /*
				 echo "<pre>";
				 print_r($items_ap);
				 exit;
				 */
				 foreach ($items_ap as $item) {
				   $fc = field_collection_field_get_entity($item);
				 }
				 $approval_status = $fc->field_approval_status['und'][0]['value'] ? $fc->field_approval_status['und'][0]['value'] : "NA";
				 
				 //$approval_status = ($approval_status == "Accept" || $approval_status == "Reject") ? $approval_status . "ed" : $approval_status;
				 
				 if($approval_status == "Accept") {
					 $approval_status = "Accepted";
				 } else if($approval_status == "Accept with no proposal") {
					 $approval_status = "Accepted with no proposal";
				 } else if($approval_status == "Reject") {
					 $approval_status = "Rejected";
				 } else if($approval_status == "Need Update") {
					 $approval_status = "Update Required";
				 }
				 
				 $ulm .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>" . l('View Proposal', 'node/' . array_keys($result['node'])[0] . '/edit/buyer', array('target' => '_blank', 'class' => 'popup')) . "</td><td width=30%>" . $approval_status . "</td></tr>";
			  }
           else
               $ulm .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>Proposal not yet received</td><td width=30%>-</td></tr>";
          }
        }
        $ulm .= "</table>";
        if (arg(0) != 'manageproposal') {
          if ($content['field_match_builder']['#items']) {

            print '<div class="field field-label-above"><div class="field-label builder-class">Matched Builders</div><div class="field-items1" width="100%"><div class="field-item even" property="content:encoded">' . $ulm . '</div></div></div>';
          }
        }


        //Manual builder
        $ulmanual = '<table  class="table">';
		$ulmanual .="<tr><th width=40%>Builder</th><th width=30%>Proposal Status </th><th width=30%>Proposal State</th></tr>";
		//print 99;
		//print_r($content['field_manual_builder']);
        foreach ($content['field_manual_builder']['#items'] as $key => $value) {
          $query = new EntityFieldQuery();
          $query->entityCondition('entity_type', 'node')
              ->entityCondition('bundle', 'proposal')
              ->fieldCondition('field_requirement', 'value', arg(1), '=')
              ->fieldCondition('field_sub_requirement', 'value', $entity_id[3], '=')
              ->fieldCondition('field_builder', 'value', $value['target_id'], '=')
              ->fieldCondition('field_builder_source', 'value', 3, '=')
              ->addMetaData('account', user_load(1));
          $result = $query->execute();

          //if (node_load(array_keys($result['node'])[0])->workflow_state_name == 'Published')
          if (arg(2) == 'inteladmin') {
			  
			  $prop1 = node_load(array_keys($result['node'])[0]);
              if ($prop1->workflow_state_name == 'Published') {
				
				$items_ap = field_get_items('node', $prop1, 'field_approver');
				 foreach ($items_ap as $item) {
				   $fc = field_collection_field_get_entity($item);
				 }
				 $approval_status = $fc->field_approval_status['und'][0]['value'] ? $fc->field_approval_status['und'][0]['value'] : "NA";
				 
				 //$approval_status = ($approval_status == "Accept" || $approval_status == "Reject") ? $approval_status . "ed" : $approval_status;
				 
				 if($approval_status == "Accept") {
					 $approval_status = "Accepted";
				 } else if($approval_status == "Accept with no proposal") {
					 $approval_status = "Accepted with no proposal";
				 } else if($approval_status == "Reject") {
					 $approval_status = "Rejected";
				 } else if($approval_status == "Need Update") {
					 $approval_status = "Update Required";
				 }
				 
				$ulmanual .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>" . l('Edit Proposal', 'node/' . array_keys($result['node'])[0] . '/edit', array('target' => '_blank', 'class' => 'popup')) . "</td><td width=30%>" . $approval_status . "</td></tr>";
			}
            else {
            $ulmanual .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>Proposal not yet received</td><td width=30%>-</td></tr>";
			}
          }
          else {
			  
			  $prop1 = node_load(array_keys($result['node'])[0]);
              if ($prop1->workflow_state_name == 'Published') {
				
				$items_ap = field_get_items('node', $prop1, 'field_approver');
				 foreach ($items_ap as $item) {
				   $fc = field_collection_field_get_entity($item);
				 }
				 $approval_status = $fc->field_approval_status['und'][0]['value'] ? $fc->field_approval_status['und'][0]['value'] : "NA";
				 
				 //$approval_status = ($approval_status == "Accept" || $approval_status == "Reject") ? $approval_status . "ed" : $approval_status;
				 
				 if($approval_status == "Accept") {
					 $approval_status = "Accepted";
				 } else if($approval_status == "Accept with no proposal") {
					 $approval_status = "Accepted with no proposal";
				 } else if($approval_status == "Reject") {
					 $approval_status = "Rejected";
				 } else if($approval_status == "Need Update") {
					 $approval_status = "Update Required";
				 }
				 
				$ulmanual .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>" . l('View Proposal', 'node/' . array_keys($result['node'])[0] . '/edit/buyer', array('target' => '_blank', 'class' => 'popup')) . "</td><td width=30%>" . $approval_status . "</td></tr>";
			}
            else {
            $ulmanual .= "<tr><td width='40%'>" . l($value['entity']->title, 'node/'. $value['target_id']) . " </td><td width=30%>Proposal not yet received</td><td width=30%>-</td></tr>";
			}
          }
        }
        $ulmanual .= "</table>";
        if (arg(0) != 'manageproposal') {
          if ($content['field_manual_builder']['#items']) {
            print '<div class="field field-label-above"><div class="field-label builder-class">Manual Builders</div><div class="field-items1" width="100%"><div class="field-item even" property="content:encoded">' . $ulmanual . '</div></div></div>';
          }
        }
        ?>
    </div>
</div>


