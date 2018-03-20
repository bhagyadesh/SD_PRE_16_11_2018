/*
 * @file
 * Custom Intel theme javascript.
 */

//
// Helper function to remove URL parameters
//
function removeParameter(url, parameter)
{
	var urlparts= url.split('?');

	if (urlparts.length>=2)
	{
		var urlBase=urlparts.shift(); //get first part, and remove from array
		var queryString=urlparts.join("?"); //join it back up

		var prefix = encodeURIComponent(parameter)+'=';
		var pars = queryString.split(/[&;]/g);
		for (var i= pars.length; i-->0;)               //reverse iteration as may be destructive
			if (pars[i].lastIndexOf(prefix, 0)!==-1)   //idiom for string.startsWith
				pars.splice(i, 1);
		url = urlBase+'?'+pars.join('&');
	}
	return url;
}

(function ($) {

	Drupal.behaviors.theming = {
		attach: function(context, settings) {

			//Remove dropdown on click, only on hover
			$('.dropdown-toggle').click(function() {
    			var location = $(this).attr('href');
			    window.location.href = location;
			    return false;
			});

			//Show global language dropdown on click
			$('#block-locale-language').on('click', function () {
				$('.language-switcher-locale-url').toggle();
			});

			// Link logo image to intel.com
			// $(".logo-img > a").attr("href", "http://www.intel.com");

            //Add some useful bootstrap classes to search box in header
			/*$('#intel-isdm-module-site-search-form').addClass('col-3');
			$('#intel-isdm-module-site-search-form').addClass('col-md-offset-3');*/
		}
	};

	Drupal.behaviors.intel = {
		attach: function (context, settings) {
			
			//
			// To hide repeated content type at facet - memberoster page
			//
			$('ul#facetapi-facet-search-apicompanies-block-field-company-node-ebfield-solution-type').each(function(){
				var cnt = 1;
				$(this).find('li a').each(function(){
					var current = $(this);
					phrase = $(this).text();
					var n = phrase.indexOf("(");
					var res = phrase.substring(0, n);
					//alert( res );			
					if ( res.trim() != 'Embedded IoT' && res.trim() != 'Client' && res.trim() != 'Server' ) {
						$("ul#facetapi-facet-search-apicompanies-block-field-company-node-ebfield-solution-type li:nth-child("+cnt+")").hide();
					}
					cnt++;
				});
			});
			
			//
			// To hide Taxonomy ID display under industries and applications filter at Memberroster page
			//
			$('ul#facetapi-facet-search-apicompanies-block-field-company-node-ebfield-market-segments').each(function(){
				var cnt = 1;
				$(this).find('li a').each(function(){
					var current = $(this);
					phrase = $(this).text();
					var n = phrase.indexOf("(");
					var res = phrase.substring(0, n);			
					var a=parseInt(res);
					if(a == a+1-1) { // becomes true only if they are numbers		
					 // alert(res + "its a number, so hide");
					$(this).parent().parent().hide();			
					}
					cnt++;
				});
			});
			
			//
			// To hide Taxonomy ID display under processors filter at Memberroster page
			//
			$('ul#facetapi-facet-search-apicompanies-block-field-company-node-ebfield-processors-list').each(function(){
				var cnt = 1;
				$(this).find('li a').each(function(){
					var current = $(this);
					phrase = $(this).text();
					var n = phrase.indexOf("(");
					var res = phrase.substring(0, n);			
					var a=parseInt(res);
					if(a == a+1-1) { // becomes true only if they are numbers		
					 // alert(res + "its a number, so hide");
					$(this).parent().parent().hide();			
					}
					cnt++;
				});
			});
						
			//
			// Create accordions on the Company Solutions mini-panel
			//
			if (typeof(Drupal.behaviors.intel.loaded) == 'undefined') {
				var mini_panel_company_solutions = $('.page-node.node-type-company #mini-panel-company_solutions', context);
				if (mini_panel_company_solutions.length > 0) {
					mini_panel_company_solutions.accordion({
						active: false,
						collapsible: true,
						header: 'h2.pane-title',
						autoHeight: false,
						icons: {
							'header': 'ui-icon-plus',
							'headerSelected': 'ui-icon-minus'
						}
					});
				}

				//
				// Add an X to current search terms, using search form field only
				//
				if(window.location.href.indexOf("?search") > -1) {
						var search = $('.current-search-item-active .first a').text();
						if ( search ) {
						} else {
							var list = $('.current-search-item-active li');
							search = list.text();
							if(search == '[all items]') {
							} else {
								var url = removeParameter(document.URL, 'search' );
								list.prepend('<a href="' + url + '"><img src="/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/filter-remove.png" typeof="foaf:Image"></a> ');
							}
						}

				}
				//Add an X to work on solutions directory filters
				$('.current-search-item-active a:contains("(-) ")').html('<img src="/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/filter-remove.png" typeof="foaf:Image">');

				//
				// FacetAPI Filters.
				//

				// Couldn't  generate the fake facets without making them active.
				// Removing the extra checkbox now so the rest of the JS works.
				$('#facetapi-facet-search-apisolutions-block-field-company > li > input').remove();

				// Specify the different groups of FacetAPI filter groups to target.
				var filterGroups = '#block-panels-mini-sd-filters-group, #block-panels-mini-mr-filters-group';

				// Collapse all filters.
				$(filterGroups).find('.block-inner li.expanded', context).each(function() {
					$('> div.item-list', this).hide();
				});

				// Collapse all NESTED panels.
				$(filterGroups).find('.panel-pane > .pane-content .panel-pane > h2', context).each(function() {
					var parent = $(this).parent();
					$('> div.pane-content', parent).hide();
				});

				// Find all checked checkboxes and recurse up the tree opening filter
				// sections.
				$(filterGroups).find('.facetapi-checkbox:checked', context).each(function() {
					// Display all parents of this checkbox.
					$(this).parents().show();
					// Set a collapsed background image for all li.expanded parents.
					//$(this).parents('li.expanded').css('background', 'transparent url(/sites/all/themes/custom/intel/images/filters-collapse.png) no-repeat right 7px');
					// Set a collapsed background image for all .panel-pane parents
					// except for the last one.
					//$(this).parents('.panel-pane').not(':last').css('background', '#ebebeb url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-children-down-arrow.png) no-repeat 95% 17px');
					// Display this items children.
					$(this).siblings('.item-list').show();
				});
				//------------- Product Side Bar

				// Refine By Solutions Directory
				// Toggle Product Type and Refine By Up Arrown
				// Refine By Parent Category show children category

				var parents_sidebar = '.pane-facetapi-tipmjn8ap6mm3i2tl5pfqro7emdma8gd h2, .pane-sd-characteristics-filters h2, .pane-sd-companies-filters h2, .pane-facetapi-s7yyglryauf55lz5mwkbdtkx9kgnqz5i h2, .pane-mr-characteristics-filters h2, .pane-facetapi-zgmiubzjd0pg3bib0vhcphpctcxlkdie h2, .pane-facetapi-s7yyglryauf55lz5mwkbdtkx9kgnqz5i h2, .pane-facetapi-zgmiubzjd0pg3bib0vhcphpctcxlkdie h2, .pane-facetapi-wfyk37smvtilegfxu0xebcyvj942g4t1 h2, .pane-facetapi-wfyk37smvtilegfxu0xebcyvj942g4t1 h2, .pane-facetapi-dfusoxoxpcptyicrrp0mtdqseqrpnfwt h2';

                $(filterGroups).find(parents_sidebar).on('click', function () {
                    //Show Parent List
                    $(this).find('+ div.pane-content').toggle();
                    //Toggle between + and - 
                    if ($(this).find('+ div.pane-content').is(':visible')) {
                        $(this).parent().css('background', '#0072c5 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-parent-minus.png) no-repeat 95% 17px');
                        //$(this).parent().css('border-bottom', 'solid 1px #055ea4');
                        $('.pane-menu-menu-view-all-companies').show();
                        $('.pane-facetapi-zgmiubzjd0pg3bib0vhcphpctcxlkdie + div.pane-content ul li').show();
                    } else {
                        $(this).parent().css('background', '#0072c5 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-parent-plus.png) no-repeat 95% 17px');
                        //$(this).parent().css('border-bottom', 'solid 1px #055ea4');
                        $('.pane-menu-menu-view-all-companies').hide();
                        $('.pane-facetapi-zgmiubzjd0pg3bib0vhcphpctcxlkdie + div.pane-content ul li').hide();

                    }
                });
                //Children Category
                $(filterGroups).find('#mini-panel-sd_characteristics_filters .panel-pane h2, #mini-panel-sd_companies_filters .panel-pane h2, #mini-panel-mr_characteristics_filters .panel-pane h2').on('click', function () {
                    //$(this).find('+ div.pane-content').toggle();
                    if ($(this).find('+ div.pane-content').is(':visible')) {
                        $(this).find('+ .pane-content .panel-1col .panel-col .panel-pane h2').css({'padding-left': '42px'});
                        $(this).find('+ .pane-content .panel-1col .panel-col .panel-pane h2 + .pane-content ul').css({'padding-left': '25px', 'background': '#f3f3f3'});
                        $(this).find('+ .pane-content .panel-1col .panel-col .panel-pane h2 + .pane-content ul:nth-child(3)').css({'padding-left': '15px', 'background': '#f3f3f3'});						
                        if ($(this).parent().hasClass("pane-block") && $(this).parent().parent().parent().parent().parent().parent().parent().parent().parent().parent().parent().hasClass("pane-panels-mini")) {
                            $(this).parent().css('background', '#f0f0f0 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-children-minus.png) no-repeat 5% 11px');
                        } else
                            $(this).parent().css('background', '#f0f0f0 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-children-minus.png) no-repeat 3% 11px');
                        $('.pane-menu-menu-view-all-companies').show();
                        $('.pane-facetapi-zgmiubzjd0pg3bib0vhcphpctcxlkdie + div.pane-content ul li').show();
                        $('.pane-facetapi-zgmiubzjd0pg3bib0vhcphpctcxlkdie + div.pane-content ul li').show();
                    } else {
                        if ($(this).parent().hasClass("pane-block") && $(this).parent().parent().parent().parent().parent().parent().parent().parent().parent().parent().parent().hasClass("pane-panels-mini")) {
                            
                             $(this).parent().css('background', '#f0f0f0 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-children-plus.png) no-repeat 5% 11px');
                        } else
                            $(this).parent().css('background', '#f0f0f0 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-children-plus.png) no-repeat 3% 11px');
                        $('.pane-menu-menu-view-all-companies').show();
                        $('.pane-facetapi-zgmiubzjd0pg3bib0vhcphpctcxlkdie + div.pane-content ul li').show();
                    }
                });


				// show minus to checked filter
                var parents_sidebar_head = '.pane-sd-characteristics-filters h2, .pane-mr-characteristics-filters h2,  .pane-facetapi-zgmiubzjd0pg3bib0vhcphpctcxlkdie h2';				

                $(filterGroups).find(parents_sidebar_head).each(function () {
                    if ($(this).find('+ div.pane-content').is(':visible')) {
                        $(this).parent().css('background', '#0072c5 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-parent-minus.png) no-repeat 95% 17px');
                    }
                });
						//, .pane-sd-companies-filters h2		
						
                $(filterGroups).find('.pane-sd-companies-filters > h2').each(function () {
                    if ($(this).find('+ div.pane-content').is(':visible')) {
                        $(this).parent().css('background', '#0072c5 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-parent-minus.png) no-repeat 95% 17px');
                    }
                });		

				//				view alphapet minus implementation
				//pane-facetapi-7umr7tzfr1yj7gph7s1u0wjqfrazokg7
                $(filterGroups).find('.pane-facetapi-7umr7tzfr1yj7gph7s1u0wjqfrazokg7 > h2').each(function () {
                    if ($(this).find('+ div.pane-content').is(':visible')) {
						$(this).parent().css('background', '#f0f0f0 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-children-minus.png) no-repeat 3% 11px');
                    }
                });					
                /** edited by siva **/


		//--------------- end Refine By Solutions Directory


				// Handle subcategory clicks.
				$(filterGroups).find('.block-inner li.expanded', context).click(function(e) {
					if ($('> div.item-list', this).is(':visible')) {
						$(this).css('background', 'transparent url(/sites/all/themes/custom/intel/images/filters-expand.png) no-repeat right 7px');
						$('> div.item-list', this).hide();
					}
					else {
						$(this).css('background', 'transparent url(/sites/all/themes/custom/intel/images/filters-collapse.png) no-repeat right 7px');
						$('> div.item-list', this).show();
					}

					// Prevent the click from applying to parent elements.
					e.stopPropogation();
				});

				// Prevent clicks on child elements of a facet from propogating.
				$(filterGroups).find('.block-inner li.expanded', context).children().click(function(e) {
					e.stopPropogation();
				});

				// Show/hide the 'Quickview' link when hovering over a solution.
				$('.view-solutions-directory .node-solution, .view-solutions-directory .node-formula', context).hover(function() {
					$(this).find('.field-name-field-quickview-link').show();
				}, function() {
					$(this).find('.field-name-field-quickview-link').hide();
				});

				// Solutions detail page
				//
				//
				// Remove (1) count from filter names
				$('#mini-panel-solution_filters_group li.leaf > a, #mini-panel-solution_filters_group li.expanded > a', context).each(function() {
					var link_html = $(this).html();
					var updated_link_html = link_html.replace(/\s[(]1[)]/, "");
					$(this).html(updated_link_html);
				});

				// Company detail page
				//
				//
				// Collapse all filters
				$('.node-type-company .region-sidebar-first .block-panels-mini .block-inner li.expanded > a', context).each(function(){
					var parent = $(this).parent();
					$('> div.item-list', parent).hide();
				});

				// Member roster page
				//
				//
				// Remove (1) count from filter names
				$('#mini-panel-mr_filters_group li.leaf > a, #mini-panel-mr_filters_group li.expanded > a', context).each(function() {
					var link_html = $(this).html();
					var updated_link_html = link_html.replace(/\s[(]1[)]/, "");
					$(this).html(updated_link_html);
				});
								
				/* changing URL in market list in Market Info tab in Solutions page */
				var marketTitle = '';
				var newLink = ''
				$('.node-type-solution .field-name-field-market-segments .field-items .field-item a').each(function() {
					marketTitle = $(this).html();
					marketTitle = marketTitle.replace(/&amp;/g,"%26");
					marketTitle = marketTitle.replace("+","%2B");
					marketTitle = marketTitle.replace(/ /g,"-");
					marketTitle = marketTitle.toLowerCase()
					newLink = '/market-segment/'+marketTitle;
					$(this).attr('href',newLink);
				});
				if($.trim($(".node-type-solution .pane-intel-ea-community-news .view-company-stories").html())=='') {
					$(".node-type-solution .pane-intel-ea-community-news .view-company-stories").closest('.pane-intel-ea-community-news').hide();
				}
				/* privatemsg */
				$(".page-messages #privatemsg-list-form .ajax-processed").on("change", function() {
					$(this).css( "top" , "0px");
					$(this).css( "margin-top" , "-62px"); 
					//edit_operation_count = edit_operation_count + 1;
					$('<input />').attr('type', 'hidden')
					  .attr('id', "action_count")
					  .attr('value', "1")
					  .appendTo('#privatemsg-list');
				});
				$("a[data-target='#edit-filter > .collapse']").html("<img src='/sites/default/files/empty-filter-xxl.png' height='20' width='20'>");
				$(".page-messages a[data-target='#edit-filter > .collapse']").attr('title', 'Filter');
				$(".page-messages a#privatemsg-new-icon").attr('title', 'New Message');
				$(".page-messages .form-item-subject label[for='edit-subject']").append('<span class="form-required" title="This field is required.">*</span>');
				$(".page-node-edit.node-type-proposal #field-proposal-information-add-more-wrapper .field-name-field-rfp-attachment .panel-title").append('<span class="form-required" title="This field is required."> *</span>');
				var block_width = $("#top-header").width();
				$("#block-block-16").css({"width": block_width});
				if ($('.page-home #block-block-16').length > 0) {
				 $('.page-home .region-content').css('margin-top', '40px');
				}
				
				var container_width = $(".container").width();
				var padding = ((block_width - container_width)/2);
				$(".block.block-block#block-block-16").css('padding-right', padding);
				
				var lang = $('html').attr('lang');
				$('#home-banner .views-field-title a, #home-banner .views-field-field-company span, .page-solutions-directory .view-solutions-directory .view-content article a,.view-intel-qualified-iot-solutions .views-field-title a').each(function() {
					var banner_txt= $(this).text();
					if (lang == 'ja' || lang == 'zh-hans' || lang == 'zh-hant') {
						if (banner_txt.length > 30 ) {
							$(this).text(banner_txt.substring(0,30)+'...')
						}
					}
					if (lang == 'en') {
						if (banner_txt.length > 40 ) {
							$(this).text(banner_txt.substring(0,35)+'...')
						}
					}
				});
				
				/* new MRS js code */
				$('.view-intel-qualified-iot-solutions .mrs-view-row .views-field-field-market-segments span.field-content').each(function() {
					var ms_txt= $(this).text();
					if (lang == 'ja' || lang == 'zh-hans' || lang == 'zh-hant') {
						if (ms_txt.length > 90 ) {
							$(this).text(ms_txt.substring(0,90)+'...')
						}
					}
					if (lang == 'en') {
						if (ms_txt.length > 170 ) {
							$(this).text(ms_txt.substring(0,170)+'...')
						}
					}
				});
				
				$('.view-intel-qualified-iot-solutions .views-exposed-form .bef-checkboxes .form-type-bef-checkbox label').each(function() {
					var filter_txt= $(this).text();
					if (lang == 'ja' || lang == 'zh-hans' || lang == 'zh-hant') {
						if (filter_txt.length > 18 ) {
							$(this).text(filter_txt.substring(0,18)+'...')
						}
					}
					if (lang == 'en') {
						if (filter_txt.length > 40 ) {
							$(this).text(filter_txt.substring(0,40)+'...')
						}
					}
				});
				
				$(".view-intel-qualified-iot-solutions .view-filters .views-exposed-form .views-widget-filter-field_market_segments .panel-heading .panel-title").click(function() {
					$(".view-intel-qualified-iot-solutions .views-exposed-form .form-item-field-market-segments .panel-body").toggle();
					$(this).parents(".views-widget-filter-field_market_segments").next(".views-submit-button").toggle();
					$(this).parents(".views-widget-filter-field_market_segments").next().next(".views-reset-button").toggle();
					$(".view-intel-qualified-iot-solutions .views-exposed-form .form-item-field-market-segments .arrow_up").toggle();
					var title_height = $('.view-intel-qualified-iot-solutions .view-filters').height();
					$('.view-intel-qualified-iot-solutions #result_summary_iot').css('top',(title_height-10));
				});
				$(".view-intel-qualified-iot-solutions .views-exposed-form .panel-body").before('<div class="arrow_up"></div>');
				$(".view-intel-qualified-iot-solutions .views-exposed-form .panel-body .form-checkboxes").after('<div class="close_mark">X</div>');
				var close_top = $(".view-intel-qualified-iot-solutions .views-exposed-form .panel-body").height();
				$(".view-intel-qualified-iot-solutions .views-exposed-form .close_mark").css('top',-(close_top-(close_top/3)));
				$(".view-intel-qualified-iot-solutions .views-exposed-form .close_mark").click(function() {
					$(this).parents(".panel-body").toggle();
					$(this).parents(".panel-body").prev(".arrow_up").toggle();
					$(this).parents(".views-widget-filter-field_market_segments").next(".views-submit-button").toggle();
					$(this).parents(".views-widget-filter-field_market_segments").next().next(".views-reset-button").toggle();
					var close_height = $('.view-intel-qualified-iot-solutions .view-filters').height();
					$('.view-intel-qualified-iot-solutions #result_summary_iot').css('top',(close_height-10));
				});
				$(".view-intel-qualified-iot-solutions .views-exposed-form .bef-checkboxes .form-type-bef-checkbox").each(function() {
					$(this).find('label').text( $(this).find('label').text().replace('-', '') );
					$(this).find('input').change(function(){
						if($(this).is(':checked')) {
							$(this).parent('.form-type-bef-checkbox').addClass('selected');
						} else {
							$(this).parent('.form-type-bef-checkbox').removeClass('selected');
						}
					});
					if ($(this).hasClass('highlight')) {
						$(this).parents('.panel-body').show();
						$(this).parents(".views-widget-filter-field_market_segments").next(".views-submit-button").show();
						$(this).parents(".views-widget-filter-field_market_segments").next().next(".views-reset-button").show();
						$(".view-intel-qualified-iot-solutions .views-exposed-form .form-item-field-market-segments .arrow_up").show();
					}
				});
				var filter_height = $('.view-intel-qualified-iot-solutions .view-filters').height();
				$('.view-intel-qualified-iot-solutions #result_summary_iot').css('top',(filter_height-10));
				var filter_width = $('.page-intel-iot-market-ready-solution .view-intel-qualified-iot-solutions .view-filters').width();
				$('.page-intel-iot-market-ready-solution .view-intel-qualified-iot-solutions .view-content').css('width',(filter_width-10));
				Drupal.behaviors.intel.loaded = true;
			}
			$(document).ready(function(){
					if(window.location.href.indexOf('messages/new') !== -1){
						if($('input[name="field__pvt_msg_attach_file[und][0][fid]"]').val() == 0 && $('input[name="field__pvt_msg_attach_file[und][1][fid]"]').val() == 0){
							$('.form-item-field--pvt-msg-attach-file-und-0').remove();
						}
					}
			});
		}
	};

})(jQuery);
