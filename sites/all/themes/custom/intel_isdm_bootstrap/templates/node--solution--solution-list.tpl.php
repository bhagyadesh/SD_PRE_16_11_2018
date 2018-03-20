<?php
/**
 * @file
 * Default theme implementation to display a node.
 *
 * Available variables:
 * - $title: the (sanitized) title of the node.
 * - $content: An array of node items. Use render($content) to print them all,
 *   or print a subset such as render($content['field_example']). Use
 *   hide($content['field_example']) to temporarily suppress the printing of a
 *   given element.
 * - $user_picture: The node author's picture from user-picture.tpl.php.
 * - $date: Formatted creation date. Preprocess functions can reformat it by
 *   calling format_date() with the desired parameters on the $created variable.
 * - $name: Themed username of node author output from theme_username().
 * - $node_url: Direct URL of the current node.
 * - $display_submitted: Whether submission information should be displayed.
 * - $submitted: Submission information created from $name and $date during
 *   template_preprocess_node().
 * - $classes: String of classes that can be used to style contextually through
 *   CSS. It can be manipulated through the variable $classes_array from
 *   preprocess functions. The default values can be one or more of the
 *   following:
 *   - node: The current template type; for example, "theming hook".
 *   - node-[type]: The current node type. For example, if the node is a
 *     "Blog entry" it would result in "node-blog". Note that the machine
 *     name will often be in a short form of the human readable label.
 *   - node-teaser: Nodes in teaser form.
 *   - node-preview: Nodes in preview mode.
 *   The following are controlled through the node publishing options.
 *   - node-promoted: Nodes promoted to the front page.
 *   - node-sticky: Nodes ordered above other non-sticky nodes in teaser
 *     listings.
 *   - node-unpublished: Unpublished nodes visible only to administrators.
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 *
 * Other variables:
 * - $node: Full node object. Contains data that may not be safe.
 * - $type: Node type; for example, story, page, blog, etc.
 * - $comment_count: Number of comments attached to the node.
 * - $uid: User ID of the node author.
 * - $created: Time the node was published formatted in Unix timestamp.
 * - $classes_array: Array of html class attribute values. It is flattened
 *   into a string within the variable $classes.
 * - $zebra: Outputs either "even" or "odd". Useful for zebra striping in
 *   teaser listings.
 * - $id: Position of the node. Increments each time it's output.
 *
 * Node status variables:
 * - $view_mode: View mode; for example, "full", "teaser".
 * - $teaser: Flag for the teaser state (shortcut for $view_mode == 'teaser').
 * - $page: Flag for the full page state.
 * - $promote: Flag for front page promotion state.
 * - $sticky: Flags for sticky post setting.
 * - $status: Flag for published status.
 * - $comment: State of comment settings for the node.
 * - $readmore: Flags true if the teaser content of the node cannot hold the
 *   main body content.
 * - $is_front: Flags true when presented in the front page.
 * - $logged_in: Flags true when the current user is a logged-in member.
 * - $is_admin: Flags true when the current user is an administrator.
 *
 * Field variables: for each field instance attached to the node a corresponding
 * variable is defined; for example, $node->body becomes $body. When needing to
 * access a field's raw values, developers/themers are strongly encouraged to
 * use these variables. Otherwise they will have to explicitly specify the
 * desired field language; for example, $node->body['en'], thus overriding any
 * language negotiation rule that was previously applied.
 *
 * @see template_preprocess()
 * @see template_preprocess_node()
 * @see template_process()
 *
 * @ingroup templates
 */ 

global $language_base_url;
?>
<article id="node-<?php print $node->nid; ?>" class="<?php print $classes; ?> clearfix productcompareTop"<?php print $attributes; ?>>
  <?php
  // Hide comments, tags, and links now so that we can render them later.
  hide($content['comments']);
  hide($content['links']);
  hide($content['field_tags']);
  ?>
  <?php 
  //Start of implementation for RFQ link display
  global $user;
  
  //new condition RFQ 
  
  $user_compid = user_load($user->uid)->field_company['und']['0']['target_id'];
  $node_det = node_load($node->nid);
  $node_view_option = $node_det->field_access['und']['0']['value'];
  ctools_include('modal');
  ctools_modal_add_js();
  // To get the p2 MM type of a company and use it for RFQ
  $company_id = $content['field_company']['#object']->field_company['und']['0']['target_id'];
  $company_node = node_load ($company_id);
  $p2pmmtype = $company_node->field_p2pmmtype['und']['0']['value'];
 // print_r($company_id);
 // print_r('hi');
 // print_r($user_compid);

  // End of implementation for RFQ link display.

  /* $pre_release = $content['field_image']['#object']->field_pre_release['und']['0']['value']; 
    if($pre_release){
        echo '<img typeof="foaf:Image" class="pre-release" src="/sites/all/themes/custom/intel_isdm_bootstrap/images/badge-pre-release-en.png" alt="Pre-Release">';
    } */
	
	$access = $content['field_image']['#object']->field_access['und']['0']['value'];
		//$access_formula = $content['field_image']['#object']->field_access_formula['und']['0']['value']
    if($access == 2){
        echo '<img typeof="foaf:Image" class="pre-release" src="/sites/all/themes/custom/intel_isdm_bootstrap/images/restricted_products.png" alt="Pre-Release">';
	}
  ?> 
  <?php print render($content['field_image']); ?>
  <h2><a href="<?php echo $language_base_url . '/' . drupal_get_path_alias('node/'.$node->nid); ?>"><?php echo $node->title; ?></a></h2>
  <?php print render($content['field_company']); ?>
  </article>

  <div class="productcompareBottom">
	 <label>
    <?php echo $content['links']['flag']['#links']['flag-product_comparison']['title'];?>
	 </label>

   <?php 
   //Checking the P2P MM type and showing RFQ icons only for desired users. Except Intel Employee
   if (($p2pmmtype == 'RFP or RFQ') and  user_is_logged_in() ){
     if (array_key_exists(10, $user->roles) ) { 
      //checks if intel employee , further check if intel admin, odm admin or admin to show the icons else no show
      if (array_key_exists(9, $user->roles) or array_key_exists(36, $user->roles) or array_key_exists(21, $user->roles) ) {
  print '<div id="request-for-quote-link" href="#" data-toggle="tooltip" title="Request for Quotation" data-placement="top">'
   . l('RFQ', 'rfq/nojs/'.$node->nid, array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';  
  print '  '.'<div id="ask-for-features-link" href="#" data-toggle="tooltip" title="Ask for Features" data-placement="top">'
   . l('aff', 'aff/nojs/'.$node->nid, array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';  //Ask for samples
  print '  '.'<div id="request-for-sample-link" href="#" data-toggle="tooltip" title="Request for Samples" data-placement="top">' . l('rfs', 'rfs/nojs/'.$node->nid, 
    array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';  
}

}
//builders conditions &&  ($node_view_option != 0)
else if( (array_key_exists(33, $user->roles)) && (array_key_exists(20, $user->roles))  ) { 

   if (  ($user_compid != $company_id) && ($node_view_option != 0)  ) {
  
  print '<div id="request-for-quote-link" href="#" data-toggle="tooltip" title="Request for Quotation" data-placement="top">'
   . l('RFQ', 'rfq/nojs/'.$node->nid, array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';  
  print '  '.'<div id="ask-for-features-link" href="#" data-toggle="tooltip" title="Ask for Features" data-placement="top">'
   . l('aff', 'aff/nojs/'.$node->nid, array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';  //Ask for samples
  print '  '.'<div id="request-for-sample-link" href="#" data-toggle="tooltip" title="Request for Samples" data-placement="top">' . l('rfs', 'rfs/nojs/'.$node->nid, 
    array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';
    
  }  
}

else{ 
  //For all other users who are logged in , show the icons
  print '<div id="request-for-quote-link" href="#" data-toggle="tooltip" title="Request for Quotation" data-placement="top">'
   . l('RFQ', 'rfq/nojs/'.$node->nid, array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';  
  print '  '.'<div id="ask-for-features-link" href="#" data-toggle="tooltip" title="Ask for Features" data-placement="top">'
   . l('aff', 'aff/nojs/'.$node->nid, array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';  //Ask for samples
  print '  '.'<div id="request-for-sample-link" href="#" data-toggle="tooltip" title="Request for Samples" data-placement="top">' . l('rfs', 'rfs/nojs/'.$node->nid, 
    array('attributes' => array('class' => 'ctools-use-modal'))) .  '</div>';

}

}
?>
  </div>
	<script>
  $(document).ready(function(){
    $('[data-toggle="tooltip"]').tooltip(); 
  });
</script>