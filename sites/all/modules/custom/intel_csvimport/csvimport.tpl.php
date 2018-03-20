<?php 
//dsm($result['message']);
$output = '';
foreach($result['message'] as $nid_key => $nid_action){
	 $output .= '-- # Solution ID: '.$nid_key.PHP_EOL;
	 foreach($nid_action as $data_index => $data_key){
		if (array_key_exists('h_tanaslation', $nid_action)) {
			$output .= '/* '.$nid_action['h_tanaslation'][0].' */'.PHP_EOL;
			unset($nid_action['h_tanaslation']);
		}
		if($data_index == 'insert')
		 {
			//drupal_set_message('/* Insert Queries */');
			$output .= '/* Insert Queries */'.PHP_EOL;
			 foreach($data_key as $data => $value){
				   foreach($value as $data1 => $value1){
						//drupal_set_message($value1.';');
						$output .= $value1.';'.PHP_EOL;
					}
			 }
		 }
		 if($data_index == 'delete')
		 {
			//drupal_set_message('/* DELETE Queries */');
			$output .= '/* DELETE Queries */'.PHP_EOL;
			 foreach($data_key as $data => $value){
				   foreach($value as $data1 => $value1){
						//drupal_set_message($value1.';');
						$output .= $value1.';'.PHP_EOL;
					}
			 }
		 }
		 if($data_index == 'skip')
		 {
			//drupal_set_message('/* Skipping Queries */');
			$output .= '/* Skipping Queries */'.PHP_EOL;
			 foreach($data_key as $data => $value){
				   foreach($value as $data1 => $value1){
						//drupal_set_message('-- '.$value1);
						$output .= '-- '.$value1.PHP_EOL;
					}
			 }
		 }
		  if($data_index == 'update')
		 {
			$output .= '/* Update Query */'.PHP_EOL;
			 foreach($data_key as $data => $value){
				   foreach($value as $data1 => $value1){
						//drupal_set_message('-- '.$value1);
						$output .= $value1.';'.PHP_EOL;
					}
			 }
		 }
		   if($data_index == 'no-nid')
		 {
			$output .= '/* NO NID IN THE DB */'.PHP_EOL;
			 foreach($data_key as $data => $value){
				   foreach($value as $data1 => $value1){
						//drupal_set_message('-- '.$value1);
						$output .= $value1.';'.PHP_EOL;
					}
			 }
		 }
		 
	}
}

unset($result);
//$result_file_name = 'delta_result.'.date('m-d-Y_h.i.s.a').'.txt';
$result_file_name = 'delta_result.txt';
$file = file_save_data($output,'public://' .$result_file_name);
drupal_set_message('Script have been generated and can access through file <b>'.file_create_url($file->uri).'</b>');
 ?>