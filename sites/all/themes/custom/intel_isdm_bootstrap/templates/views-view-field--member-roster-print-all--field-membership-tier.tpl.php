<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php
$tier2 = '';
$terms  = explode(',',$output);
if(isset($terms) && !empty($terms)) {
	if($terms['0'] == 'Intel® IoT Solutions Alliance' || $terms['0'] == 'Intel® Technology Provider') {
	  $tier = $terms['0'].' '.$terms['1'];
	}
	else {
	  $tier = $terms['1'].' '.$terms['0'];
	}
        if(isset($terms['2']) && $terms['2'] != '') {
		if(trim($terms['2']) == 'Intel® IoT Solutions Alliance' || trim($terms['2']) == 'Intel® Technology Provider') {	
                  $tier2 = $terms['2'].' '.$terms['3'];
		}
		else {
		  $tier2 = $terms['3'].' '.$terms['2'];
		} 
	}
}
if($tier2 != '') {
  $tiers = $tier.'<br>'.$tier2;
}
else {
  $tiers = $tier;
}
print $tiers; ?>
