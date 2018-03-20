(function ($) {

Drupal.behaviors.intel_ea_partner_upload = {
	attach: function(context,settings) {
	
	function is_valid_url(url) {
    return /^http(s)?:\/\/(www\.)?[a-z0-9]+([\-\.]{1}[a-z0-9]+)*\.[a-z]{2,5}(:[0-9]{1,5})?(\/.*)?$/.test(url);
	}

/*********************** Hide the Vertical tabs on hierarchy in solution **********************************/

// All the tabs will be disabled when page loads
//jQuery('div.hide-show-tabs li.selected').nextAll().css('pointer-events', 'none');

if($('.page-node-add-solution input#edit-field-solution-type-und-client, .page-node-add-solution input#edit-field-solution-type-und-server, .page-node-add-solution input#edit-field-solution-type-und-embedded-iot').is(':checked') && ($('.page-node-add-solution input#edit-title').val() != '') && $('#edit-field-company-und').val() != '_none') { //  Solution Informaion Tab

 var desc = jQuery('div#edit-body div.form-item-body-und-0-value').find('iframe').contents().find('p').html();
		if($('.vertical-tabs-active-tab').val() == 'edit-group_solution_information'){
				$('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');
				
				////// Disable the 'Intel Review' tab when the solution is PUBLISHED 
				/*if($('#solution-workflow-state').val() == 'Publish'){ //alert('am in  else if 2');
					$('div.hide-show-tabs').find('li.last').css('pointer-events', 'none');
				}*/
				
		} else if(($('#edit-field-access-und-1').is(':checked')  || $('#edit-field-website-und-0-url').val() != '') &&  $('.file-size').html() != '' && desc != '<br>') { //  Solution Details Tab				
				if($('.vertical-tabs-active-tab').val() == 'edit-group_solution_details'){
						$('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');
				} else if($('div.checkbox-radio-tree input:radio').is(':checked')){
						$('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');
				}	
		} else { //alert('am in else');
			$('div.hide-show-tabs li.selected').nextAll().css('pointer-events', 'none');
		}
	
}/*else if($('div#edit-field-categories-und input:radio').is(':checked')) { //Categories Tab,
	$('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');
} else if ($('div#edit-field-geographic-location input:checkbox').is(':checked') && $('.node-type-solution div#edit-field-market-segments input:checkbox').is(':checked')){	 // Characteristics Tab
	
	$('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');
} */  else { 
//alert('am in final else');
	$('.page-node-add-solution div.hide-show-tabs li.selected').nextAll().css('pointer-events', 'none');
	$('.page-node-add-solution #edit-submit').prop('disabled', true);
}	



//jQuery('div.hide-show-tabs li.first').nextAll().css('pointer-events', 'none');
var sol_info_length;
var sol_info_selector = jQuery('.solution_information').find('div.fieldset-wrapper');
sol_info_length = sol_info_selector.find('input:text, select, textarea, fieldset').size();

var fill;

// Solution information Tab For Admin Theme
 
jQuery('.solution_information div.fieldset-wrapper input#edit-field-solution-type-und-client, input#edit-field-solution-type-und-server, input#edit-field-solution-type-und-embedded-iot, #edit-title, #edit-field-company-und').blur(function(e){

	if(($('#edit-title').val() == '' || $('#edit-title').val() == undefined) || ($('#edit-field-company-und').val() == '_none') || ($('#edit-field-solution-type-und-client, input#edit-field-solution-type-und-server, input#edit-field-solution-type-und-embedded-iot').is(':checked') == false)){
	/*********************** Biz-036 - I thought the field was highlighted in the current release ************************/
		if($('#edit-title').val() == '' || $('#edit-title').val() == undefined){
			$('#edit-title').addClass('error');
		} else {
			$('#edit-title').removeClass('error');
		}
		if($('#edit-field-company-und').val() == '_none'){
			$('#edit-field-company-und').addClass('error');
		} else {
			$('#edit-field-company-und').removeClass('error');
		}	
		
		if($('#edit-field-solution-type-und-client, input#edit-field-solution-type-und-server, input#edit-field-solution-type-und-embedded-iot').is(':checked') == false){
			$('#edit-field-solution-type-und-client').addClass('error');
			$('#edit-field-solution-type-und-server').addClass('error');
			$('#edit-field-solution-type-und-embedded-iot').addClass('error');
		} else {
			$('#edit-field-solution-type-und-client').removeClass('error');
			$('#edit-field-solution-type-und-server').removeClass('error');
			$('#edit-field-solution-type-und-embedded-iot').removeClass('error');
		}
		
		/*********************** Biz-036 - I thought the field was highlighted in the current release ************************/
		
			fill = 0; 
			
	} else {
			fill = 1;
			$('#edit-title').removeClass('error');
			$('#edit-field-company-und').removeClass('error');
			$('#edit-field-solution-type-und-client').removeClass('error');
			$('#edit-field-solution-type-und-server').removeClass('error');
			$('#edit-field-solution-type-und-embedded-iot').removeClass('error');
	}
	//  console.log('fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
		
	} 
});


// Solution information Tab For Partner Theme
 
 var sol_partner_info_selector = jQuery('.solution_information').find('div.panel-body');
 
jQuery('.solution_information div.panel-body input#edit-field-solution-type-und-client, input#edit-field-solution-type-und-server, input#edit-field-solution-type-und-embedded-iot, #edit-title, #edit-field-company-und').blur(function(){
	if(($('#edit-title').val() == '' || $('#edit-title').val() == undefined) || ($('#edit-field-company-und').val() == '_none') || ($('#edit-field-solution-type-und-client, input#edit-field-solution-type-und-server, input#edit-field-solution-type-und-embedded-iot').is(':checked') == false)){
		/*********************** Biz-036 - I thought the field was highlighted in the current release ************************/
		if($('#edit-title').val() == '' || $('#edit-title').val() == undefined){
			$('#edit-title').addClass('error');
		} else {
			$('#edit-title').removeClass('error');
		}
		if($('#edit-field-company-und').val() == '_none'){
			$('#edit-field-company-und').addClass('error');
		} else {
			$('#edit-field-company-und').removeClass('error');
		}	
		
		if($('#edit-field-solution-type-und-client, input#edit-field-solution-type-und-server, input#edit-field-solution-type-und-embedded-iot').is(':checked') == false){
			$('#edit-field-solution-type-und-client').addClass('error');
			$('#edit-field-solution-type-und-server').addClass('error');
			$('#edit-field-solution-type-und-embedded-iot').addClass('error');
		} else {
			$('#edit-field-solution-type-und-client').removeClass('error');
			$('#edit-field-solution-type-und-server').removeClass('error');
			$('#edit-field-solution-type-und-embedded-iot').removeClass('error');
		}
		
		/*********************** Biz-036 - I thought the field was highlighted in the current release ************************/
			fill = 0;
	} else {
			$('#edit-title').removeClass('error');
			$('#edit-field-company-und').removeClass('error');
			$('#edit-field-solution-type-und-client').removeClass('error');
			$('#edit-field-solution-type-und-server').removeClass('error');
			$('#edit-field-solution-type-und-embedded-iot').removeClass('error');
			
			fill = 1;
	}
	//  console.log('fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
	} 
});


// Solution Details Tab for Admin Theme

var sol_detail_selector =  jQuery('.solution_details').find('div.fieldset-wrapper');

jQuery('input#edit-field-website-und-0-url, input.form-file').blur(function(){
	var desc = jQuery('div#edit-body div.form-item-body-und-0-value').find('iframe').contents().find('p').html();
	   if(($('#edit-field-website-und-0-url').val() == '' && $('#edit-field-access-und-1').is(':checked') == false)|| ($('.file-size').html() == '' || $('.file-size').html() == undefined) || desc == '<br>'){
	   
	   /*********************** Biz-036 - I thought the field was highlighted in the current release ************************/
				if($('#edit-field-access-und-1').is(':checked') == false ){
					$('#edit-field-website-und-0-url').addClass('error');
				} else if(is_valid_url($('#edit-field-website-und-0-url').val())){						
						$('#edit-field-website-und-0-url').removeClass('error');
				} else {						
						/* $('#edit-field-website-und-0-url').addClass('error'); */
				}
				
				
			  if($('.file-size').html() == '' || $('.file-size').html() == undefined)	{
				$('#edit-field-image-und-0-upload').addClass('error');
		   
			   } else {
					$('#edit-field-image-und-0-upload').removeClass('error');
			   }
		   
			   if(desc == '<br>'){
					$('#cke_edit-body-und-0-value').addClass('error');
			   } else {
					$('#cke_edit-body-und-0-value').removeClass('error');
			   }
		   /*********************** Biz-036 - I thought the field was highlighted in the current release ************************/
			fill = 0;
	   } else {
			
			$('#edit-field-website-und-0-url').removeClass('error');
			$('#edit-field-image-und-0-upload').removeClass('error');
			$('#cke_edit-body-und-0-value').removeClass('error');
			
			fill = 1;
	   }
	//  console.log('fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
	} 
});

if(navigator.userAgent.indexOf("Firefox") != -1){
    jQuery('div#edit-body div.form-item-body-und-0-value').find('iframe').contents().bind('blur', function(){ // Blur function
	var desc = jQuery('div#edit-body div.form-item-body-und-0-value').find('iframe').contents().find('p').html();
		 if(($('#edit-field-website-und-0-url').val() == '' && $('#edit-field-access-und-1').is(':checked') == false)|| ($('.file-size').html() == '' || $('.file-size').html() == undefined) || desc == '<br>'){
			fill = 0;
	   } else {
			fill = 1;
	   }
	 // console.log('fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
	} 
	
	});
    
}else{
    jQuery('div#edit-body div.form-item-body-und-0-value').find('iframe').contents().find("body").blur(function(){ // Blur functions 
	var desc = jQuery('div#edit-body div.form-item-body-und-0-value').find('iframe').contents().find('p').html();
	  if(($('#edit-field-website-und-0-url').val() == '' && $('#edit-field-access-und-1').is(':checked') == false) || ($('.file-size').html() == '' || $('.file-size').html() == undefined) || desc == '<br>'){
			fill = 0;
	   } else {
			fill = 1;
	   }
	//  console.log('fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
	} 
	});
    
}



// Solution Details Tab for Partner Theme

var sol_detail_partner_selector =  jQuery('.solution_details').find('div.panel-body');

jQuery('.solution_details div.panel-body input#edit-field-website-und-0-url, input.form-file').blur(function(){
	 var desc = jQuery('div#edit-body div.form-item-body-und-0-value').find('iframe').contents().find('p').html();
	   if(($('#edit-field-website-und-0-url').val() == '' && $('#edit-field-access-und-1').is(':checked') == false)|| ($('.file-size').html() == '' || $('.file-size').html() == undefined) || desc == '<br>'){
	   
	   /*********************** Biz-036 - I thought the field was highlighted in the current release ************************/
			if($('#edit-field-access-und-1').is(':checked') == false){
					$('#edit-field-website-und-0-url').addClass('error');
				} else if(is_valid_url($('#edit-field-website-und-0-url').val())){						
						$('#edit-field-website-und-0-url').removeClass('error');
				} else {						
						/* $('#edit-field-website-und-0-url').addClass('error'); */
				}
				
				
			  if($('.file-size').html() == '' || $('.file-size').html() == undefined)	{
				$('#edit-field-image-und-0-upload').addClass('error');
		   
			   } else {
					$('#edit-field-image-und-0-upload').removeClass('error');
			   }
		   
			   if(desc == '<br>'){
					$('#cke_edit-body-und-0-value').addClass('error');
			   } else {
					$('#cke_edit-body-und-0-value').removeClass('error');
			   }
		   
	   /*********************** Biz-036 - I thought the field was highlighted in the current release ************************/
			fill = 0;
	   } else {
	   
			/* $('#edit-field-website-und-0-url').removeClass('error'); */
			$('#edit-field-image-und-0-upload').removeClass('error');
			$('#cke_edit-body-und-0-value').removeClass('error');
			fill = 1;
	   }
	//  console.log('fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
	} 
});

// Solution Categories Tab for Admin Theme

var sol_cat_selector =  jQuery('.solution_categories').find('div.fieldset-wrapper');

jQuery('div.form-item-field-categories-und').click(function(){
	 sol_cat_selector.find('input:checked').each(function() {
	   var element = jQuery(this);
	   console.log(element.val());
	   if (element.val()  == '' || element.val() == undefined || element.val() == 0) {
		   fill= 0;
	   } else {
		 fill= 1;
	   }
	});
	  //console.log('admin_fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
	} 
});


// Solution Categories Tab for Partner Theme

var sol_cat_partner_selector =  jQuery('.solution_categories').find('div.panel-body');

jQuery('.solution_categories div.panel-body div.checkbox-radio-tree').click(function(){
	 sol_cat_partner_selector.find('input:checked').each(function() {
	   var element = jQuery(this);
	 
	   if (element.val()  == '' || element.val() == undefined || element.val() == 0) {
		   fill= 0;
	   } else {
		 fill= fill + 1;
	   }
	});
	// console.log('SD_fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
	} 
});

 // Solution Characteristics Tab for Admin theme
 
 var sol_char_partner_selector =  jQuery('.solution_characters').find('div.fieldset-wrapper');

jQuery('div#edit-field-geographic-location, div#edit-field-market-segments').click(function(){
	if($('div#edit-field-geographic-location input:checkbox').is(':checked') == false || $('div#edit-field-market-segments input:checkbox').is(':checked') == false){				
			fill= 0;
	  } else {
			 fill= 1;
	  }

	//  console.log('fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
		$('#edit-submit').prop('disabled', false);
	} 
});


 // Solution Characteristics Tab for Partner theme
 
 var sol_char_partner_selector =  jQuery('.solution_characters').find('div.panel-body');

jQuery('.solution_characters div.panel-body div#edit-field-geographic-location, div#edit-field-market-segments').click(function(){
	if($('div#edit-field-geographic-location input:checkbox').is(':checked') == false || $('div#edit-field-market-segments input:checkbox').is(':checked') == false){
			fill= 0;
	  } else {
			 fill= 1;
	  }

	//  console.log('fill='+fill);
	if(fill > 0){
	//alert('am here');
		jQuery('div.hide-show-tabs li.selected').next('li').css('pointer-events', 'visible');	
		$('#edit-submit').prop('disabled', false);
	} 
});


}
}

})(jQuery);
