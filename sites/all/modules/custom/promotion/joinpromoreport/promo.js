
(function ($) {
    Drupal.behaviors.promo = {
        attach: function (context, settings) {
			



if($('#widget_pager_bottom_promotion_banner-block').length){
	
var p = document.getElementById("widget_pager_bottom_promotion_banner-block");	
var style = p.currentStyle || window.getComputedStyle(p);

    var ua = window.navigator.userAgent;
    var msie = ua.indexOf("MSIE ");

if  (msie > 0 || !!navigator.userAgent.match(/Trident.*rv\:11\./)) // If Internet Explorer, return version number
    {
		/*
if(parseInt($('#widget_pager_bottom_promotion_banner-block').css("marginRight")) < 405){
$('#views_slideshow_controls_text_previous_promotion_banner-block').css('margin-left', '15px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css('margin-right', '15px'); 	
}
else if(parseInt($('#widget_pager_bottom_promotion_banner-block').css("marginRight")) > 455) {
	$('#views_slideshow_controls_text_previous_promotion_banner-block').css('margin-left', '231px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css('margin-right', '231px'); 
}
*/
  var numItems = $('.views_slideshow_pager_field_item').length;  
  var left_right_total = 395;
  
  var left = left_right_total - (numItems * 5);
  var right = left_right_total - (numItems * 5);
  
   /**
count  = left_right
1 = 390
2 = 385
3 = 380
**/
if(numItems <= 8){

$('#views_slideshow_controls_text_previous_promotion_banner-block').css('marginLeft', parseInt(left) + 'px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css({'marginRight': parseInt(right) + 'px'}); 

} else if(numItems >= 9 && numItems <= 15){
	
	var sub = (numItems - 7) * 5;
	   
  var left1 = left_right_total - (numItems * 5) - sub + 5;
  var right1 = left_right_total - (numItems * 5) - sub + 5; 
  $('#views_slideshow_controls_text_previous_promotion_banner-block').css('marginLeft', parseInt(left1) + 'px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css({'marginRight': parseInt(right1) + 'px'}); 
 }

   else if(numItems ==16 ){ 
	
	$('#views_slideshow_controls_text_previous_promotion_banner-block').css('marginLeft', parseInt(280) + 'px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css({'marginRight': parseInt(280) + 'px'});
	
   }
   else if(numItems ==17 ){ 
	
	$('#views_slideshow_controls_text_previous_promotion_banner-block').css('marginLeft', parseInt(275) + 'px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css({'marginRight': parseInt(275) + 'px'});
	
   }
   else if(numItems ==21 ){ 
	
	$('#views_slideshow_controls_text_previous_promotion_banner-block').css('marginLeft', parseInt(245) + 'px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css({'marginRight': parseInt(245) + 'px'});
	
   }
	
	
	
	
	
	}
//FF	
else if(navigator.userAgent.indexOf("Firefox") != -1 ) {
	
	var numItems = $('.views_slideshow_pager_field_item').length;  
  var left_right_total = 395;
  
  var left = left_right_total - (numItems * 5);
  var right = left_right_total - (numItems * 5);

if(numItems <= 8){

$('#views_slideshow_controls_text_previous_promotion_banner-block').css('marginLeft', parseInt(left) + 'px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css({'marginRight': parseInt(right) + 'px'}); 

} else if(numItems >= 9){
	
	var sub = (numItems - 7) * 5;
	   
  var left1 = left_right_total - (numItems * 5) - sub + 5;
  var right1 = left_right_total - (numItems * 5) - sub + 5; 
  $('#views_slideshow_controls_text_previous_promotion_banner-block').css('marginLeft', parseInt(left1) + 'px');
$('#views_slideshow_controls_text_next_promotion_banner-block').css({'marginRight': parseInt(right1) + 'px'}); 
	
	
}
}
		
    else  // If another browser, return 0
    {
$('#views_slideshow_controls_text_previous_promotion_banner-block').css('margin-left', parseInt($('#widget_pager_bottom_promotion_banner-block').css("marginLeft")) + 'px');

if(parseInt($('#widget_pager_bottom_promotion_banner-block').css("marginRight")) > 405){
	$('#views_slideshow_controls_text_next_promotion_banner-block').css({'margin-right': (parseInt($('#widget_pager_bottom_promotion_banner-block').css("marginRight"))-25) + 'px', 'left': '-4px'}); 	
}
else 
$('#views_slideshow_controls_text_next_promotion_banner-block').css({'margin-right': parseInt($('#widget_pager_bottom_promotion_banner-block').css("marginRight")) + 'px'}); 	
    }



}

	



			
			if($('#block-superfish-1 #menu-7449-1 ul').children("li").length === 0){
			$('#menu-7449-1').css("display", "none");}
			
			$(".field-name-field-promotion-products  table tbody tr td").each(function (i) {
                    var text = $(this).html();
					if(text == 'No items have been added yet. Click "Add items" to launch the widget.')
					$(this).html('No items have been added yet. Click "Add Solutions" to launch the widget.');
                }); 
				
			$(".field-name-field-select-view-buyer  table tbody tr td").each(function (i) {
                    var text = $(this).html();
					if(text == 'No items have been added yet. Click "Add items" to launch the widget.')
					$(this).html('No items have been added yet. Click "Select Buyers" to launch the widget.');
                }); 	
				
			$('.node-promotion-form .form-item-workflow-comment label').text("Comments");	
			$('.page-promotionmanagement .breadcrumb .inline .last a').text("Manage My Promotion");

            $(".joinbuttonpromo").on("click", function () {
                url = '/promotioncount';
    			var $type = $(this).attr('promotiontype');
                success = function (data) {
                    
						if($type == 'Join')
						{
							if(data.valid == 4){
							
						       alert('Joined Promotion Successfully');
							   }
							   
							 if(data.valid == 2){
							
						       alert('Try again after sometime');
							   }

                             if(data.valid == 3){
							
						       alert('Your company already joined');
							   }							   
						
					    }
					
           
                };
                $.ajax({
                    type: "POST",
                    url: url,
                    data: "param=" + $(this).attr('userid') + "," + $(this).attr('nodeid') + "," + $(this).attr('promotiontype'),
                    success: success,
                    dataType: "json",
                    failure: function (errMsg) {
                        alert(errMsg);
                    }
                });

            });

        }}
})(jQuery);
