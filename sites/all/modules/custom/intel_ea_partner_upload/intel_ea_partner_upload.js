jQuery(document).ready(function () {

jQuery('.archive_buttn').click(function(event){
	jQuery(this).prop('type','button');	
	alert(jQuery('#workflow-res').val());
	jQuery('#edit-submit-button-1').attr('disabled', true);
	event.preventDefault();
	event.stopPropagation();
	return false;
				
});

jQuery('.se_submit_buttn').click(function(event){
	jQuery(this).prop('type','button');	
	alert(jQuery('#workflow-res-se-edit').val());
	event.preventDefault();
	event.stopPropagation();
	return false;
				
});
if(jQuery('#current-user-role').val() === 'Administrator' || jQuery('#current-user-role').val() === 'ODM Intel Admin' || jQuery('#current-user-role').val() === 'Intel Admin'){

	jQuery('#edit-status').click(function(){
		var state_publish = jQuery('#edit-workflow-7');
		var state_unpublish = jQuery('#edit-workflow-22');
		if(jQuery('#edit-status').is(':checked') == true){
			state_publish.prop('checked', true);
		} 
		if(jQuery('#edit-status').is(':checked') == false){
			state_unpublish.prop('checked', true);
			state_publish.prop('checked', false);
		}
		  
	});

	jQuery('#edit-workflow-7').click(function(){
		var publish_option = jQuery('#edit-status');
		
		if(jQuery('#edit-workflow-7').is(':checked') == true){
			publish_option.prop('checked', true);
		} 
		if(jQuery('#edit-workflow-7').is(':checked') == false){
			
			publish_option.prop('checked', false);
		}
		 jQuery('#edit-workflow-alert').html();
		  jQuery('.form-type-item').html('');
		  jQuery('#edit-submit').attr('disabled', false);
		  jQuery('#edit-submit').removeClass('form-button-disabled');
		  
	});

	jQuery('#edit-workflow-22').click(function(){
		var publish_option = jQuery('#edit-status');
		
		if(jQuery('#edit-workflow-22').is(':checked') == true){
			publish_option.prop('checked', false);
		} 
		if(jQuery('#edit-workflow-22').is(':checked') == false){
			
			publish_option.prop('checked', false);
		}
		
		if(jQuery('#workflow-res').val() != ''){
			 //jQuery('#edit-workflow-alert,.form-type-item').html(jQuery('#workflow-res').val());
		     alert(jQuery('#workflow-res').val()); 
			 //jQuery('fieldset#edit-group_workflow div#edit-workflow-alert1,fieldset#edit-group_workflow div.form-type-item').html(jQuery('#workflow-res').val());
		
			 jQuery('#edit-submit').attr('disabled', true);
	   } else {
			 jQuery('#edit-submit').attr('disabled', false);
	   }
		  
	});
	
	
	jQuery('#edit-workflow-2, #edit-workflow-3, #edit-workflow-4, #edit-workflow-5, #edit-workflow-6, #edit-workflow-22').click(function(){
		var publish_option = jQuery('#edit-status');
		publish_option.prop('checked', false);
		//jQuery('#edit-workflow-alert').html(); 
		//jQuery('.form-type-item').html('');		
		//jQuery('#edit-submit').attr('disabled', false);
		//jQuery('#edit-submit').removeClass('form-button-disabled');
	});
  
}
/*** Display "none" for the Tech Spec Tab in solution view page ##### BIZ -005 ***/

if(jQuery('.tab-content').find('.pane-node-field-display-independent').find('.field-item').html() === "0"){
	jQuery('.tab-content').find('.pane-node-field-display-independent').find('.field-item').text('None');
}

if(jQuery('.tab-content').find('.pane-node-field-display-port-edp').find('.field-item').html() === "0"){
	jQuery('.tab-content').find('.pane-node-field-display-port-edp').find('.field-item').text('None');
}

if(jQuery('.tab-content').find('.pane-node-field-display-lvds').find('.field-item').html() === "0"){
	jQuery('.tab-content').find('.pane-node-field-display-lvds').find('.field-item').text('None');
}

if(jQuery('.tab-content').find('.pane-node-field-display-vga').find('.field-item').html() === "0"){
	jQuery('.tab-content').find('.pane-node-field-display-vga').find('.field-item').text('None');
}

if(jQuery('.tab-content').find('.pane-node-field-stds-eth-ports').find('.field-item').html() === "0"){
	jQuery('.tab-content').find('.pane-node-field-stds-eth-ports').find('.field-item').text('None');
}
/**Hide the N/A from categories tree in formula  and component page***/
jQuery('#edit-field-categories-und-none').parent('label').attr('style','display: none');

/** Display check box for sections without checkbox and radio tree in company for member ship tier **/
	jQuery(".node-type-company fieldset#edit-group_membership").find("div#edit-field-membership-tier input[type='radio']:checked").closest('div.children').attr('style','display: block');
	
	jQuery(".node-type-company fieldset#edit-group_membership").find("div#edit-field-membership-tier input[type='radio']:checked").closest('div.children').prev().prev('span').addClass('minus');


/** show the categories tree expanded on edit/read view ***/
jQuery(".checkbox-radio-tree input[type='radio']:checked").parents('div').attr('style','display: block');
jQuery(".checkbox-radio-tree input[type='checkbox']:checked").parents('div').attr('style','display: block');
jQuery(".checkbox-radio-tree input[type='radio']:checked").parents('div').prev().prev('span').addClass('minus');
jQuery(".checkbox-radio-tree input[type='checkbox']:checked").parents('div').prev().prev('span').addClass('minus');

/** Expand the fieldset on edit/read view for charecteristics  **/

EditPageCall('node-type-solution ,edit-group_characteristics');

/*** Edit call for formula details tab in formula page ***/
	
	EditPageCall('node-type-formula ,edit-group_formula_details');
	
	/*** Edit call for chracteristics tab in Component page ***/
	
	EditPageCall('node-type-component ,edit-group_characteristics');
	

function EditPageCall(sourcePage, pageId){
	jQuery("."+sourcePage+" fieldset#"+pageId+"  div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='radio']:checked").closest('fieldset').removeClass('collapsed');
	
		
	/*** Manage solution Edit page ***/
	
	jQuery("."+sourcePage+" fieldset#"+pageId+"  div.panel-body").find("div.checkbox-radio-tree input[type='checkbox']:checked").closest('div.panel-collapse').addClass('in');
	
	jQuery("."+sourcePage+" fieldset#"+pageId+"  div.panel-body").find("div.checkbox-radio-tree input[type='radio']:checked").closest('div.panel-collapse').addClass('in');
	// collapse the display fieldset on SD theme
		jQuery(".page-node-add-solution fieldset#edit-group_characteristics fieldset").find("div.panel-collapse").attr('style',''); 
	// collapse the display and standards in admin theme ###### IT-054 #######
	jQuery(".page-node-add-solution fieldset#edit-group_characteristics fieldset").find("div.fieldset-wrapper").attr('style',''); 

	/*** End Manage solution Edit page ***/
	
	jQuery("."+sourcePage+" fieldset#"+pageId+"  div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='radio']:checked").parents('div').attr('style','display: block'); 

 /** Display check box for sections without checkbox and radio tree **/
  jQuery("."+sourcePage+" fieldset#"+pageId+"  div").find("div.form-item input[type='checkbox']:checked").closest('fieldset').removeClass('collapsed');
  
   jQuery("."+sourcePage+" fieldset#"+pageId+"  div").find("div.form-item input[type='checkbox']:checked").closest('div.fieldset-wrapper').attr('style','display: block');
   
  /** for Check box radio treee sections ***/
 jQuery("."+sourcePage+" fieldset#"+pageId+"  div").find("div.checkbox-radio-tree input[type='checkbox']:checked").closest('fieldset').removeClass('collapsed');
 
 jQuery("."+sourcePage+" fieldset#"+pageId+"  div").find("div.checkbox-radio-tree input[type='checkbox']:checked").closest('div.fieldset-wrapper').attr('style','display: block');
 
 jQuery("."+sourcePage+" fieldset#"+pageId+"  div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='checkbox']:checked").parents('div').attr('style','display: block');
 /***Manage Solutions page *****/
  jQuery("."+sourcePage+" fieldset#"+pageId+"  div.panel-body").find("div.checkbox-radio-tree input[type='checkbox']:checked").parents('div').attr('style','display: block');
  
 
   jQuery("."+sourcePage+" fieldset#"+pageId+"  div").find("div.checkbox-radio-tree input[type='checkbox']:checked").parents('div').prev().prev('span').addClass('minus');
 
   jQuery("."+sourcePage+" fieldset#"+pageId+"  div").find("div.checkbox-radio-tree input[type='radio']:checked").parents('div').prev().prev('span').addClass('minus');
 
 /***if more than one fieldset for charecteristics **/
 
 jQuery("."+sourcePage+" fieldset#"+pageId+" fieldset fieldset").find("div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='radio']:checked").parents('fieldset').removeClass('collapsed');
 
 jQuery("."+sourcePage+" fieldset#"+pageId+" fieldset fieldset").find("div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='checkbox']:checked").parents('fieldset').removeClass('collapsed');
 
 /*** Manage solution Edit page ***/
 
 jQuery("."+sourcePage+" fieldset#"+pageId+" fieldset fieldset").find("div.panel-collapse input[type='radio']:checked").parents('fieldset').removeClass('collapsed');
 
 jQuery("."+sourcePage+" fieldset#"+pageId+" fieldset fieldset").find("div.panel-collapse input[type='radio']:checked").parents('div.panel-collapse').addClass('in');
 
 /*** End -- Manage solution Edit page ***/
 
 
	jQuery(".admin-menu ."+sourcePage+" fieldset#"+pageId+" fieldset fieldset").find("div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='radio']:checked").parents('div.fieldset-wrapper').attr('style','display: block');
	
		
 }
 
  //#################### An expand all/Collapse All button (implemented) Added by Aasima
   /******* Expand All Collapse all for categories ********/

    jQuery('.expand_all, .formula_expand_all,.component_expand_all').click(function() { 	
			jQuery(".checkbox-radio-tree").find("div").attr('style','display: block');
		
			jQuery(".checkbox-radio-tree span").addClass("minus");
    });
    
	jQuery('.collapse_all, .formula_collapse_all,.component_collapse_all').click(function() { 
			jQuery(".checkbox-radio-tree").find("div").attr('style','display: none');
			jQuery(".checkbox-radio-tree span").removeClass("minus");
    });
	
	
	
	/********Reset for charecteristics in solution ********/
	
	jQuery('.reset_cat').click({ char_id : '#edit-field-search-category' }, function (e) {
        jQuery(e.data.char_id).val("");
        reset_category(e);
    });
	
	/********Reset for charecteristics in Formula  ********/
	jQuery('.formula_reset_cat').click({ char_id : '#edit-field-search-formula-category' }, function (e) {
        jQuery(e.data.char_id).val("");
        reset_category(e);
    });
	
	/********Reset for charecteristics in Component  ********/
	jQuery('.component_reset_cat').click({ char_id : '#edit-field-search-component-category' }, function (e) {
        jQuery(e.data.char_id).val("");
        reset_category(e);
    });
	
	/*** Common function to reset categories **/
	function reset_category(e){
		
		jQuery(".checkbox-radio-tree label").removeClass("highlight");
		jQuery(".checkbox-radio-tree span").removeClass("minus");
		jQuery(".checkbox-radio-tree").find("div").attr('style','display: none');
		jQuery('.checkbox-radio-tree').find('input[type=checkbox]').prop('checked', false);
		jQuery('.checkbox-radio-tree').find('input[type=radio]').prop('checked', false);
	}
	
	
	
	
	
/******* Expand All Collapse all for charecteristics ********/
	
	 jQuery('.expand_all_char').click(function() { 	
	 
		jQuery("fieldset#edit-group_characteristics div").find("div.panel-collapse").attr('style','height: auto');
		
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").removeClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: block');	
		
		/** Manage Solutions**/
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").removeClass("collapsed").find("div.fade").addClass('in');
	
		/** End - Manage Solutions**/
	  
	   jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("div.checkbox-radio-tree").find("div").attr('style','display: block');
       jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("div.checkbox-radio-tree").find('span').addClass('minus');
	
    });
    
	jQuery('.collapse_all_char').click(function() { 
		 jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');	
		/** Manage Solutions**/
		
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
		
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div.panel-collapse").css('display', '');
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div.panel-body").css('display', '');
		
		/** End - Manage Solutions**/
		
	    jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("div.checkbox-radio-tree").find("div").attr('style','display: none');
       jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("div.checkbox-radio-tree").find('span').removeClass('minus');
	   
    });
	
	
	
	
	/********Reset for charecteristics in solution ********/
	
	jQuery('.reset_char').click({ char_id : '#edit-field-search-characteristics' }, function (e) {
        jQuery(e.data.char_id).val("");
        reset_charecteristics(e);
    });
	
	/********Reset for charecteristics in Component ********/
	
	jQuery('.component_reset_char').click({ char_id : '#edit-field-search-component-character' }, function (e) {
        jQuery(e.data.char_id).val("");
        reset_charecteristics(e);
    });
	
	/*** Common function to Reset Charecteristics **/
	function reset_charecteristics(e){
					 
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div label").removeClass("highlight_char");

		
       jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("div.checkbox-radio-tree").find('span').removeClass('minus');
	   
	   jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("div.checkbox-radio-tree").find("div").attr('style','display: none');
					
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');

		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").find('label').removeClass('highlight_char');			
	
		/** Manage Solutions**/
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
		
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div.panel-collapse").css('display', '');
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div.panel-body").css('display', '');
		
		/** End - Manage Solutions**/
		 // Reset the display/memory/standard supported fieldset
		 
		 jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").find('input[type=checkbox]').prop('checked', false);
		 
		 jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").find("fieldset.collapsible").find('input[type=text]').val("0");
		 jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").find('input[type=radio]').prop('checked', false);
		 
		 jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
		
	}
	
		
 // End -- #######################################################################
 
 

 // Function to search in the categories tree
 jQuery.expr[':'].contains = function(a,i,m){
    return jQuery(a).text().toUpperCase().indexOf(m[3].toUpperCase())>=0;
};

/** OnClick for category in Solution ****/
 jQuery('#search_cat').click({ char_id : '#edit-field-search-category' }, function (e) {
        var search_text = jQuery(e.data.char_id).val();
        category_click(search_text,e);
    });

	
	
/** OnClick for category in Solution ****/
 jQuery('#search_cat').click({ char_id : '#edit-field-search-category' }, function (e) {
        var search_text = jQuery(e.data.char_id).val();
        category_click(search_text,e);
    });
/** OnClick for category in Formula ****/	
jQuery('#formula_search_cat').click({ char_id : '#edit-field-search-formula-category' }, function (e) {
        var search_text = jQuery(e.data.char_id).val();
        category_click(search_text,e);
    });
/** OnClick for category in Component ****/	
jQuery('#component_search_cat').click({ char_id : '#edit-field-search-component-category' }, function (e) {
        var search_text = jQuery(e.data.char_id).val();
        category_click(search_text,e);
    });
		
	

/** Common function for category Click  **/
	function category_click(search_text,e){
		
	 if (e.keyCode != 13) {
			
			// Reset the previous selection 
			jQuery(".checkbox-radio-tree label").removeClass("highlight");
					

			jQuery(".checkbox-radio-tree  label:contains(" + search_text + ")").addClass("highlight").parents("div").attr('style','display: block').prev().prev('span').addClass('minus');
		 
			jQuery("html, body").animate({
					scrollTop: jQuery('.checkbox-radio-tree  label.highlight:first').position().top - 100
				  }, 1000);
			   
			  if(search_text == ''){
					
					jQuery(".checkbox-radio-tree").find("div").attr('style','display: none');
					jQuery(".checkbox-radio-tree label").removeClass("highlight");
					jQuery(".checkbox-radio-tree span").removeClass("minus");
			  }
			return false;  
	}
	   
   }
	 
/*** Search  on hit enter for category in solution ***/
	 jQuery('#edit-field-search-category').on('keypress', function(e) {
		var search_text = jQuery('#edit-field-search-category').val();
		category_carriage_return(search_text,e);
	 });

	 /*** Search  on hit enter for category in Formula  ***/
	 jQuery('#edit-field-search-formula-category').on('keypress', function(e) {
		var search_text = jQuery('#edit-field-search-formula-category').val();
		category_carriage_return(search_text,e);
	 });
	 
	 /*** Search  on hit enter for category in Component ***/
	 jQuery('#edit-field-search-component-category').on('keypress', function(e) {
		var search_text = jQuery('#edit-field-search-component-category').val();
		category_carriage_return(search_text,e);
	 });
	 
	 
		 
	 
 function category_carriage_return(search_text,e){
	if (e.keyCode == 13 ) {			
					
			// Reset the previous selection 
			jQuery(".checkbox-radio-tree label").removeClass("highlight");
					

			jQuery(".checkbox-radio-tree  label:contains(" + search_text + ")").addClass("highlight").parents("div").attr('style','display: block').prev().prev('span').addClass('minus');
		 
			jQuery("html, body").animate({
					scrollTop: jQuery('.checkbox-radio-tree  label.highlight:first').position().top - 100
				  }, 1000);
			   
			  if(search_text == ''){
					
					jQuery(".checkbox-radio-tree").find("div").attr('style','display: none');
					jQuery(".checkbox-radio-tree label").removeClass("highlight");
					jQuery(".checkbox-radio-tree span").removeClass("minus");
			  }
				 e.preventDefault(); // Prevent IE form from submitting the form
				return false;	
				
		  }
 
 }
 
  
	
/** OnClick for charateristics in Solution ****/
    jQuery('#search_char').click({ char_id : '#edit-field-search-characteristics' }, function (e) {
        var search_text_char = jQuery(e.data.char_id).val();
        charecteristics_click(search_text_char,e);
    });
	
	/** OnClick for charateristics in Component  ****/
	  jQuery('#component_search_char').click({ char_id : '#edit-field-search-component-character' }, function (e) {
        var search_text_char = jQuery(e.data.char_id).val();
        charecteristics_click(search_text_char,e);
    });
	
	function charecteristics_click(search_text_char,e){
			 /** Over ride the height for bootstrap theme fieldsets **/
	   jQuery("fieldset#edit-group_characteristics div").find("div.panel-collapse").attr('style','height: auto');
	 
		  if (e.keyCode != 13) {
			
			  if(search_text_char == '' || search_text_char == 'undefined'){				
					jQuery("fieldset#edit-group_characteristics div").find("label").removeClass("highlight_char");
						
				 
				jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_characteristics").find("span").next().next('div').attr('style','display: none');
			   jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("div.checkbox-radio-tree").find('span').removeClass('minus');

						
				jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
				
				jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
				
			  } else {
			  
				  // reset the previous selection	 
			  jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("label").removeClass("highlight_char");
				  jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics").find("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
			 
			 /** Manage Solutions Page ***/
			 
			 jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics").find("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
		
				//Search again
				
			//jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div span").addClass("minus");
			
			jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div label:contains(" + search_text_char + ")").addClass("highlight_char");
				
			 jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_characteristics div label:contains(" + search_text_char + ")").parents("fieldset.collapsible").removeClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: block').closest("fieldset.collapsible").removeClass("collapsed");
			 
			 /**Manage Solution - Page**/
		jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div label:contains(" + search_text_char + ")").parents("fieldset.collapsible").removeClass("collapsed").find("div.fade").addClass('in').attr('style','height: auto').closest("fieldset.collapsible").removeClass("collapsed");
				
			jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div.panel-body div  label:contains(" + search_text_char + ")").addClass("highlight_char").parentsUntil("div.checkbox-radio-tree").attr('style','display: block').prev().prev('span').addClass('minus');
			 /** End Manage Solution - Page**/
			
			// Added for Admin menu
			jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_characteristics div  label:contains(" + search_text_char + ")").addClass("highlight_char").parents("div").attr('style','display: block').prev().prev('span').addClass('minus');
			
			
          
				jQuery("html, body").animate({
					scrollTop: jQuery('label.highlight_char:first').offset().top - 100
				  }, 1000);
				  
			  }
				e.preventDefault(); // Prevent IE form from submitting the form
				return false;
		  }
		
	}
	 
	 /*** Search  on hit enter for charecteristics in solution ***/
	 jQuery('#edit-field-search-characteristics').on('keypress', function(e) {
		var search_text_char = jQuery('#edit-field-search-characteristics').val();
		characteristics_carriage_return(search_text_char,e);
	 });
	 
	  /*** Search  on hit enter for charecteristics in Component ***/
	 jQuery('#edit-field-search-component-character').on('keypress', function(e) {
		var search_text_char = jQuery('#edit-field-search-component-character').val();
		characteristics_carriage_return(search_text_char,e);
	 });
	 
	 
	 /**** Common function to search on carriage return for charecteristics in solution and component***/
	 function characteristics_carriage_return(search_text_char,e){
			 jQuery("fieldset#edit-group_characteristics div").find("div.panel-collapse").attr('style','height: auto');
       if (e.keyCode == 13) {
	   
		
		  if(search_text_char == '' || search_text_char == 'undefined'){		//alert('am here');		
				jQuery("fieldset#edit-group_characteristics div").find("label").removeClass("highlight_char");
						
				jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_characteristics").find("span").next().next('div').attr('style','display: none');
			   jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("div.checkbox-radio-tree").find('span').removeClass('minus');

				jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
				
				jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
				

		  } else {
		  
		   // reset the previous selection	 
	     jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics  div").find("label").removeClass("highlight_char");
		  jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics").find("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
	 /** Manage Solutions Page ***/
			 
			 jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics").find("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
		
			//Search again
 
			jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div label:contains(" + search_text_char + ")").addClass("highlight_char");
				
			 jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_characteristics div label:contains(" + search_text_char + ")").parents("fieldset.collapsible").removeClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: block').closest("fieldset.collapsible").removeClass("collapsed");
	
			
		// Added for Admin menu
			jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_characteristics div  label:contains(" + search_text_char + ")").addClass("highlight_char").parents("div").attr('style','display: block').prev().prev('span').addClass('minus');
         			
			 /**Manage Solution - Page**/
			jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div label:contains(" + search_text_char + ")").parents("fieldset.collapsible").removeClass("collapsed").find("div.fade").addClass('in').attr('style','height: auto').closest("fieldset.collapsible").removeClass("collapsed");
			
			jQuery(".vertical-tabs-processed fieldset#edit-group_characteristics div.panel-body div  label:contains(" + search_text_char + ")").addClass("highlight_char").parentsUntil("div.checkbox-radio-tree").attr('style','display: block').prev().prev('span').addClass('minus');
			 /** End Manage Solution - Page**/
			
										
		  
		    jQuery("html, body").animate({
				scrollTop: jQuery('label.highlight_char:first').offset().top - 100
			  }, 1000);
		  
		  
		  }
						
			e.preventDefault();// Prevent IE form from submitting the form
			return false;
			
	  }
		
	 }
	
  
	
	
	
	/** Onclick for category in Formula Details Tab **/
	 jQuery('#formula_details_search').click(function(e){
			 var search_text_char = jQuery('#edit-field-search-formula-details').val();
	  
	    if (e.keyCode != 13) {
			
		  if(search_text_char == '' || search_text_char == 'undefined'){			
				jQuery("fieldset#edit-group_formula_details div.checkbox-radio-tree").find("label").removeClass("highlight_char");
						
				jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_formula_details").find("span").next().next('div').attr('style','display: none');
			   jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("div.checkbox-radio-tree").find('span').removeClass('minus');

				jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
				
				jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
				

		  } else {
		  
		   // reset the previous selection	 
	     jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("label").removeClass("highlight_char");
		  jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details").find("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
	 
			//Search again
 
			jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div label:contains(" + search_text_char + ")").addClass("highlight_char");
				
			 jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_formula_details div label:contains(" + search_text_char + ")").closest("fieldset.collapsible").removeClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: block');
			
			
		// Added for Admin menu
			jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_formula_details div  label:contains(" + search_text_char + ")").addClass("highlight_char").parents("div").attr('style','display: block').prev().prev('span').addClass('minus');
         			
			 /**Manage Solution - Page**/
			jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div label:contains(" + search_text_char + ")").closest("fieldset.collapsible").removeClass("collapsed").find("div.fade").addClass('in');
			
			jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div.panel-body div  label:contains(" + search_text_char + ")").addClass("highlight_char").parent("div.children").attr('style','display: block').prev().prev('span').addClass('minus');
			 /** End Manage Solution - Page**/
			
			  
			var $scroll_val = jQuery('label.highlight_char:first').offset().top - 100;
			
			if($scroll_val < 0 || $scroll_val < 50){
				$scroll_val = $scroll_val + 450;
			} 
		
		    jQuery("html, body").animate({
				scrollTop: $scroll_val
			  }, 1000);
		  
		  
		  }
		e.preventDefault();
		  return false;
		}	
	 
	 });
	 
	 
	 jQuery('#edit-field-search-formula-details').on('keypress', function(e) {
		
			 var search_text_char = jQuery('#edit-field-search-formula-details').val();
	 
		 if (e.keyCode == 13) {
			 if(search_text_char == '' || search_text_char == 'undefined'){		
				jQuery("fieldset#edit-group_formula_details div.checkbox-radio-tree").find("label").removeClass("highlight_char");
						
				jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_formula_details").find("span").next().next('div').attr('style','display: none');
			   jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("div.checkbox-radio-tree").find('span').removeClass('minus');

				jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
				
				jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
				

		  } else {
		  
		   // reset the previous selection	 
	     jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("label").removeClass("highlight_char");
		  jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details").find("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');
		  jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
	 
			//Search again
 
			jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div label:contains(" + search_text_char + ")").addClass("highlight_char");
				
			 jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_formula_details div label:contains(" + search_text_char + ")").closest("fieldset.collapsible").removeClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: block');
			
			
		// Added for Admin menu
			jQuery(".admin-menu .vertical-tabs-processed fieldset#edit-group_formula_details div  label:contains(" + search_text_char + ")").addClass("highlight_char").parents("div").attr('style','display: block').prev().prev('span').addClass('minus');
         			
			 /**Manage Solution - Page**/
			jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div label:contains(" + search_text_char + ")").closest("fieldset.collapsible").removeClass("collapsed").find("div.fade").addClass('in');
			
			jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div.panel-body div  label:contains(" + search_text_char + ")").addClass("highlight_char").parent("div.children").attr('style','display: block').prev().prev('span').addClass('minus');
			
			 /** End Manage Solution - Page**/
			
			var $scroll_val = jQuery('label.highlight_char:first').offset().top - 100;
			
			if($scroll_val < 0 || $scroll_val < 50){
				$scroll_val = $scroll_val + 450;
			} 
		
		    jQuery("html, body").animate({
				scrollTop: $scroll_val
			  }, 1000);
		  
		  
		  }
		e.preventDefault();
		  return false;
		 
		 }
	 });
		
	
	/******* Expand All Collapse all for formula Details  ********/
	
	 jQuery('.expand_all_formula_details').click(function() { 	
		jQuery("fieldset#edit-group_formula_details div").find("div.panel-collapse").attr('style','height: auto');
		
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").removeClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: block');	
		
		/** Manage Solutions**/
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").removeClass("collapsed").find("div.fade").addClass('in');
	
		/** End - Manage Solutions**/
	  
	   jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("div.checkbox-radio-tree").find("div").attr('style','display: block');
       jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("div.checkbox-radio-tree").find('span').addClass('minus');
	
	 });
	
	
	jQuery('.collapse_all_formula_details').click(function() { 
		 jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');	
		/** Manage Solutions**/
		
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
		
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div.panel-collapse").css('display', '');
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div.panel-body").css('display', '');
		
		/** End - Manage Solutions**/
		
	    jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("div.checkbox-radio-tree").find("div").attr('style','display: none');
        jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("div.checkbox-radio-tree").find('span').removeClass('minus');
	   
    });
	
	
	jQuery('.reset_formula_details').click(function() {
		jQuery('#edit-field-search-formula-details').val("");
				 
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div label").removeClass("highlight_char");
		
       jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("div.checkbox-radio-tree").find('span').removeClass('minus');
	   
	   jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details  div").find("div.checkbox-radio-tree").find("div").attr('style','display: none');
					
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").attr('style', 'display: none');

		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fieldset-wrapper").find('label').removeClass('highlight_char');			
	
		/** Manage Solutions**/
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").closest("fieldset.collapsible").addClass("collapsed").find("div.fade").removeClass('in');
		
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div.panel-collapse").css('display', '');
		jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div.panel-body").css('display', '');
		
		/** End - Manage Solutions**/
		
		 jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").find('input[type=checkbox]').prop('checked', false);
		 jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").find('input[type=radio]').prop('checked', false);
		  jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div table").find('input[type=text]').val("");
		  jQuery(".vertical-tabs-processed fieldset#edit-group_formula_details div").find('input[type=file]').val("");
		  
		 
	});
	
	
	
	

});