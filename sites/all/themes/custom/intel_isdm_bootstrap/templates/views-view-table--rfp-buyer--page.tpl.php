<table <?php if ($classes) { print 'class="'. $classes . '" '; } ?><?php print $attributes; ?>>
   <?php if (!empty($title) || !empty($caption)) : ?>
     <caption><?php print $caption . $title; ?></caption>
  <?php endif; ?>
  <?php if (!empty($header)) : ?>
    <thead>
      <tr>
        <?php unset($header['nid_1']); foreach ($header as $field => $label): ?>
          <th <?php if ($header_classes[$field]) { print 'class="'. $header_classes[$field] . '" '; } ?> scope="col">
            <?php print $label; ?>
          </th>
        <?php endforeach; ?>
      </tr>
    </thead>
  <?php endif; ?>
  <tbody>
    <?php foreach ($rows as $row_count => $row): ?>
      <tr <?php if ($row_classes[$row_count]) { print 'class="' . implode(' ', $row_classes[$row_count]) .'"';  } ?>>
        <?php $nid = $row['nid_1']; unset($row['nid_1']); foreach ($row as $field => $content): ?>
          <td <?php if ($field_classes[$field][$row_count]) { print 'class="'. $field_classes[$field][$row_count] . '" '; } ?><?php print drupal_attributes($field_attributes[$field][$row_count]); ?>
		  
>

<?php $view_con = views_embed_view('proposalperrfp', 'default', $nid); 
	  $retv = preg_match('/Proposal not yet received/', $view_con, $resv); 
?>
			<?php if($field == 'title' && $retv == 0) {
				print '<span class="glyphicon glyphicon-triangle-right proposalperrfplistdisplay" aria-hidden="true" date-toggle="tooltip" title="View Proposal"></span>'; 
			}
			if($field == 'title' && $retv == 1) {
				print '<span>&nbsp;&nbsp;&nbsp;</span>'; 
			}
			print $content; ?>
          </td>
	          <?php endforeach;  ?>
      </tr>
 <?php //$pro = views_embed_view('proposalperrfp', 'block_1', $nid); if(json_decode($pro, true)): ?>

		<tr class="proposalperrfplist">
		 <td colspan = "5">

		 <?php // print views_embed_view('proposalperrfp', 'default', $nid);
				  print $view_con;
		 ?>
		 </td>
		
		</tr>  <?php // endif;  ?>
    <?php endforeach; ?>
  </tbody>
</table>