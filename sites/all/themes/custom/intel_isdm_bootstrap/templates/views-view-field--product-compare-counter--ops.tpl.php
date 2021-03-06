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

//print_r($row);

$entity_id = $row->{$field->aliases['entity_id']};
    $is_flagged = $row->{$field->aliases['is_flagged']};
    // this is the secret, the field handler implements a get_flag() method
    $flag = $field->get_flag();
    //$flag->flag_short = t('A NEW TEXT FOR THE LINK');
    $flag->unflag_short = t('Remove');
    //print_r($is_flagged);
    //print_r($entity_id);
    // finally, render the output
    //$vars['output'] = 
    $out = $flag->theme($is_flagged ? 'unflag' : 'flag', $entity_id);
print_r($out);
//print $output; 

?>