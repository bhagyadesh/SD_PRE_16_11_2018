(function ($) {

    Drupal.behaviors.categoryHidden = {
        attach: function (context, settings) {
		
		if($('#block-superfish-1 #menu-7400-1 ul').children("li").length === 0){
			$('#menu-7400-1').css("display", "none");}

        $('.proposalperrfplistdisplay').click(function (event) {
            if ($(this).is(".glyphicon-triangle-right")) {
                $(this).removeClass('glyphicon-triangle-right');
                $(this).addClass('glyphicon-triangle-bottom');
                $(this).parent().parent().next().css('display', 'table-row');
                return;
            }
            if ($(this).is(".glyphicon-triangle-bottom")) {
                $(this).removeClass('glyphicon-triangle-bottom');
                $(this).addClass('glyphicon-triangle-right');
                $(this).parent().parent().next().css('display', 'none');
                return;
            }
        });		

	
				//Select all in ERVW
			
			$('#entityreference-view-widget-select-all-checkbox').unbind().click(function (event) {
			 $('#entityreference-view-widget-select-all').click();
			});		
			
			//Add alert on edit page-node-edit
			
			$('body.node-type-rfp #edit-actions .editrfpsave').unbind().click(function (event) {
				alert("Please make sure that the selected builders are changed accordingly as per the change in categories");
			});
			
            if($(".field-name-field-recommended-builder").length)
             {
             $(".field-name-field-recommended-builder").find('button').each(function (i) {
					$(this).html('Add Recommended Builder');
             });
			 
			$(".field-name-field-recommended-builder  table tbody tr td").each(function (i) {
                    var text = $(this).html();
					if(text == 'No items have been added yet. Click "Add items" to launch the widget.')
					$(this).html('No items have been added yet. Click "Add Recommended Builder" to launch the widget.');
                }); 
				
             }
             

            //  $(".field-name-field-manual-builder").html('Add Manual Builder');


            if ($(".field-name-field-manual-builder").length)

            {
                $(".field-name-field-manual-builder").find('button').each(function (i) {
                    $(this).html('Add Manual Builder');
                });
				
				$(".field-name-field-manual-builder table tbody tr td").each(function (i) {
                    var text = $(this).html();
					if(text == 'No items have been added yet. Click "Add items" to launch the widget.')
						$(this).html('No items have been added yet. Click "Add Manual Builder" to launch the widget.');
					
					//$(this).html(text.replace('No items have been added yet. Click "Add items" to launch the widget.', 'No items have been added yet. Click "Add Manual Builder" to launch the widget.')); 
                }); 

				/*$(".field-name-field-manual-builder").each(function (i) {
                    var text = $(this).text();
					$(this).text('No items have been added yet. Click "Add Manual Builder" to launch the widget.')); 
                }); */
            }
			 if ($(".field-name-field-match-builder").length)

            {

				 $('.matchbutton').html('Add Match Builder');
				
                $(".field-name-field-match-builder").find('button').each(function (i) {
					//console.log($(this));
                    $(this).html('Add Match Builder');
                });

            }
            /*
             $(".field-name-field-manual-builder").find('input').each(function (i) {
             $(this).val('Add manual Builders');
             });
             */

            if ($("#edit-field-recommended-products-und-add-more").length)
            {
                $("#edit-field-recommended-products-und-add-more").html('Add Solutions');
                //console.log($("#edit-field-recommended-products-und-add-more"));
				
 			$(".field-name-field-recommended-products  table tbody tr td").each(function (i) {
                    var text = $(this).html();
					if(text == 'No items have been added yet. Click "Add items" to launch the widget.')
						$(this).html('No items have been added yet. Click "Add Solutions" to launch the widget.');	
					
                }); 
            }

            $('.matchbutton').unbind().click(function (event) {

                var res = $(this).attr('id').split("-");
                var arg = [];
                var category = '';
                var app = '';
                var geo = '';
                var intel_technologies = '';
                var market_segments = '';
                var processors_list = '';
                var software_solutions = '';
                var intel_wireless = '';
                var chipsets = '';
                var display_technology = '';

                event.preventDefault();
                if ("matchbutton-" + res[1] == $(this).attr('id')) {

                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-categories-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            category += $(this).val() + ',';
                        }
                    });
                    if (category !== '')
                        arg.push(category);

                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-application-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            app += $(this).val() + ',';
                        }
                    });
                    if (app !== '')
                        arg.push(app);

                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-geographic-location-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            geo += $(this).val() + ',';
                        }
                    });
                    if (geo !== '')
                        arg.push(geo);


                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-intel-technologies-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            intel_technologies += $(this).val() + ',';
                        }
                    });
                    if (intel_technologies !== '')
                        arg.push(intel_technologies);


                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-market-segments-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            market_segments += $(this).val() + ',';
                        }
                    });
                    if (market_segments !== '')
                        arg.push(market_segments);


                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-processors-list-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            processors_list += $(this).val() + ',';
                        }
                    });
                    if (processors_list !== '')
                        arg.push(processors_list);


                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-software-solutions-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            software_solutions += $(this).val() + ',';
                        }
                    });
                    if (software_solutions !== '')
                        arg.push(software_solutions);


                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-chipsets-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            chipsets += $(this).val() + ',';
                        }
                    });
                    if (chipsets !== '')
                        arg.push(chipsets);

                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-intel-wireless-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            intel_wireless += $(this).val() + ',';
                        }
                    });
                    if (intel_wireless !== '')
                        arg.push(intel_wireless);

                    $(".form-item-field-rfp-product-und-" + res[1] + "-field-display-technology-und").find('input').each(function (i) {
                        if ($(this).is(":checked")) {
                            display_technology += $(this).val() + ',';
                        }
                    });
                    if (display_technology !== '')
                        arg.push(display_technology);


                    var join = arg.join('');
                    var joinedterms = join.substr(0, (join.length - 1));


                    $.ajax({
                        type: 'POST',
                        url: "/auto-match-builder-callback",
                        dataType: 'json',
                        data: "category=" + joinedterms,
                        success: function (data) {
                            //$('#selectId option:gt(0)').remove(); 
                            $(".form-item-field-rfp-product-und-" + res[1] + "-field-match-builder-und select").empty();
                            var builderoption = '';
							console.log(JSON.parse(data.builder));
                            $.each(JSON.parse(data.builder), function (key, value) {
                                $(".form-item-field-rfp-product-und-" + res[1] + "-field-match-builder-und select").append($("<option></option>")
                                        .attr("value", key).text(value));

                                builderoption += key + '=>' + value + "#";
                            });
                            $(".form-item-field-rfp-product-und-" + res[1] + "-field-categories-hidden-und-0-value").find('input').each(function (i) {
                                $(this).val(builderoption.substr(0, (builderoption.length - 1)));
                            });

                        },
                        failure: function (errMsg) {
                            alert(errMsg);
                        }
                    });

                }
            });

        }
    };
})(jQuery);

(function ($) {
    $(document).ajaxSuccess(function (event, xhr, settings) {
        if (typeof settings.extraData != 'undefined') {
            if (settings.extraData._triggering_element_name == "field_rfp_product_add_more") {

                var productCount = $('.matchbutton ').length;

                for (var i = 0; i < productCount; i++) {
                    var optionselected = '';
                    var optionremove = '';
                    var builder = '';
                    var builderOption = new Object();
                    var builderSelected = new Object();
                    $(".form-item-field-rfp-product-und-" + i + "-field-match-builder-und select option:selected").each(function () {
                        builderSelected[ $(this).val()] = $(this).text();
                    });

                    $(".form-item-field-rfp-product-und-" + i + "-field-categories-hidden-und-0-value").find('input').each(function (j) {
                        builder = $(this).val();
                    });

                    builder = builder.toString().split("#");

                    builder.forEach(function (entry) {
                        splittxt = entry.split("=>");
                        builderOption[splittxt[0]] = splittxt[1];
                    });
                    $(".form-item-field-rfp-product-und-" + i + "-field-match-builder-und select").empty();
                    $.each(builderOption, function (key, value) {
                        $(".form-item-field-rfp-product-und-" + i + "-field-match-builder-und select").append($("<option></option>").attr("value", key).text(value));

                    });

                    $.each(builderSelected, function (key, value) {
                        $(".form-item-field-rfp-product-und-" + i + "-field-match-builder-und select option[value=" + key + "]").attr('selected', 'selected')
                    });
                }
            }
        }



    })
//if($('body').is('.page-node-edit') && $('body').is('.node-type-rfp')){

//}

    $(document).ready(function () {
        //if ($("body").hasClass("page-node-edit") && $("body").hasClass("node-type-rfp")) {

        var productCount = $('.matchbutton ').length;

        for (var i = 0; i < productCount; i++) {
            var optionselected = '';
            var optionremove = '';
            var builder = '';
            var builderSelected = new Object();
            var builderOption = new Object();
            $(".form-item-field-rfp-product-und-" + i + "-field-match-builder-und select option:selected").each(function () {
                builderSelected[ $(this).val()] = $(this).text();
            });

            $(".form-item-field-rfp-product-und-" + i + "-field-categories-hidden-und-0-value").find('input').each(function (j) {
                builder = $(this).val();
            });
				console.log(100);
                   console.log(builder);
            builder = builder.toString().split("#");

            builder.forEach(function (entry) {
                splittxt = entry.split("=>");
                builderOption[splittxt[0]] = splittxt[1];
            });
            $(".form-item-field-rfp-product-und-" + i + "-field-match-builder-und select").empty();
            $.each(builderOption, function (key, value) {
                $(".form-item-field-rfp-product-und-" + i + "-field-match-builder-und select").append($("<option></option>").attr("value", key).text(value));

            });

            $.each(builderSelected, function (key, value) {
                $(".form-item-field-rfp-product-und-" + i + "-field-match-builder-und select option[value=" + key + "]").attr('selected', 'selected')
            });
        }
		
		/*
		Add "Create Message" link
		*/
		//page-node-edit
		//page-node-add-rfp
		//$( ".page-node-edit .node-rfp-form" ).prepend( '<div align="right"><a href="/messages/new?subject=Edit RFP "><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png"> Write Message</a></div>' );
		$( ".page-node-add-rfp .node-rfp-form" ).prepend( '<div align="right"><a href="/messages/new?subject=Create RFP"><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png"> Write Message</a></div>' );
		$( ".view-rfp-buyer" ).prepend( '<div align="right"><a href="/messages/new?subject=View RFP"><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png"> Write Message</a></div>' );
		//$( ".node-rfp" ).prepend( '<div align="right"><a href="/messages/new"><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png"> Write Message</a></div>' );
		
		$( ".view-rfp-builder" ).prepend( '<div align="right"><a href="/messages/new?subject=View RFP"><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png?subject=Received RFPs"> Write Message</a></div>' );
		
		$( ".view-rfp-basic" ).prepend( '<div align="right"><a href="/messages/new?subject=Proposal Information"><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png"> Write Message</a></div>' );
		
		
		//$( ".page-node-edit .node-proposal-form" ).prepend( '<div align="right"><a href="/messages/new?subject=Edit Proposal"><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png"> Write Message</a></div>' );
		
		//page-node-edit-buyer
				
		
		$( ".page-rfp-inteladmin-view .tabs--primary" ).append( '<div align="right"><a href="/messages/new?subject=View RFP"><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png?subject=All RFPs"> Write Message</a></div' );
		/*
		$( ".node-type-proposal .tabs--primary" ).append( '<div align="right"><a href="/messages/new"><img style="margin-bottom: 2px;" src="/sites/default/files/download-message2.png"> Write Message</a></div' );
		*/
		 
		
        //}
		
		//expanf rfp charec

	function ExpandSelected (sourcePage, pageId){
	
	
	//$("."+sourcePage+" fieldset  div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='radio']:checked").closest('fieldset').removeClass('collapsed');
	
		
	/*** Manage solution Edit page ***/
	
	$("."+sourcePage+" fieldset  div.panel-body").find("div.checkbox-radio-tree input[type='checkbox']:checked").closest('div.panel-collapse').addClass('in');
	
	$("."+sourcePage+" fieldset  div.panel-body").find("div.checkbox-radio-tree input[type='radio']:checked").closest('div.panel-collapse').addClass('in');
	
		$("."+sourcePage+" fieldset  div.panel-body").find("div.form-item input[type='checkbox']:checked").closest('div.panel-collapse').addClass('in');
	
	$("."+sourcePage+" fieldset  div.panel-body").find("div.form-item input[type='radio']:checked").closest('div.panel-collapse').addClass('in');
	
	/*** End Manage solution Edit page ***/
	
	//$("."+sourcePage+" fieldset  div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='radio']:checked").parents('div').attr('style','display: block'); 

 /** Display check box for sections without checkbox and radio tree **/
  $("."+sourcePage+" fieldset  div").find("div.form-item input[type='checkbox']:checked").closest('fieldset').removeClass('collapsed');
  
  $("."+sourcePage+" fieldset  div").find("div.form-item input[type='checkbox']:checked").closest('div.fieldset-wrapper').attr('style','display: block');
   
  /** for Check box radio treee sections ***/
 $("."+sourcePage+" fieldset  div").find("div.checkbox-radio-tree input[type='checkbox']:checked").closest('fieldset').removeClass('collapsed');
 
 //$("."+sourcePage+" fieldset  div").find("div.checkbox-radio-tree input[type='checkbox']:checked").closest('div.fieldset-wrapper').attr('style','display: block');
 
 //$("."+sourcePage+" fieldset  div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='checkbox']:checked").parents('div').attr('style','display: block');
 /***Manage Solutions page *****/
  $("."+sourcePage+" fieldset  div.panel-body").find("div.checkbox-radio-tree input[type='checkbox']:checked").parents('div').attr('style','display: block');
  
 
   $("."+sourcePage+" fieldset  div").find("div.checkbox-radio-tree input[type='checkbox']:checked").parents('div').prev().prev('span').addClass('minus');
 
   $("."+sourcePage+" fieldset  div").find("div.checkbox-radio-tree input[type='radio']:checked").parents('div').prev().prev('span').addClass('minus');
 
 /***if more than one fieldset for charecteristics **/
 
 //$("."+sourcePage+" fieldset fieldset fieldset").find("div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='radio']:checked").parents('fieldset').removeClass('collapsed');
 
 //$("."+sourcePage+" fieldset fieldset fieldset").find("div.fieldset-wrapper").find("div.checkbox-radio-tree input[type='checkbox']:checked").parents('fieldset').removeClass('collapsed');
 
 /*** Manage solution Edit page ***/
 
 $("."+sourcePage+" fieldset fieldset fieldset").find("div.panel-collapse input[type='radio']:checked").parents('fieldset').removeClass('collapsed');
 
 $("."+sourcePage+" fieldset fieldset fieldset").find("div.panel-collapse input[type='radio']:checked").parents('div.panel-collapse').addClass('in');
 
 /*** End -- Manage solution Edit page ***/
 
	
		
 }
 
 	ExpandSelected('node-type-rfp');
	
$('.node-type-rfp .form-item-workflow-comment label, .page-node-add-rfp .form-item-workflow-comment label, .node-type-proposal .form-item-workflow-comment label').text("Comments");	 	



		
    });

})(jQuery);