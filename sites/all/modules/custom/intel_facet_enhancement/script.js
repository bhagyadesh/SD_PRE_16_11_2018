(function ($) {
    $(document).ready(function () {

        $(".facetapi-facetapi-checkbox-links li.expanded ul").each(function () {
			
            if ($(this).css('display') == 'block') {
               
                $(this).before('<span class="minus toggleFacet" aria-hidden="true"></span>');
            }
            if ($(this).css('display') == 'none') {
                if ($(this).prev().prev().prop('checked')) {
            
                    $(this).before('<span class="minus toggleFacet" aria-hidden="true"></span>');
                } else {
               
                    $(this).before('<span class="plus toggleFacet" aria-hidden="true"></span>');
                }

            }
        });
//top level only one to be make visible

        $("#facetapi-facet-search-apisolutions-block-field-categories > li").each(function () {
            if ($(this).find(" > input:checked").length == 1) {
                $("#facetapi-facet-search-apisolutions-block-field-categories > li").each(function () {
                    $(this).css('display', 'none');
                });
                $(this).css('display', 'block');
				
                return;
            }
        });
	
//top level only one to be make visible

        $("#facetapi-facet-search-apicompanies-block-field-company-node-ebfield-categories > li").each(function () {
            if ($(this).find(" > input:checked").length == 1) {
                $("#facetapi-facet-search-apicompanies-block-field-company-node-ebfield-categories > li").each(function () {
                    $(this).css('display', 'none');
					
                });
                $(this).css('display', 'block');
                return;
            }
        });

		
		

        $('#mini-panel-sd_characteristics_filters .toggleFacet, #facetapi-facet-search-apisolutions-block-field-categories .toggleFacet, #facetapi-facet-search-apicompanies-block-field-company-node-ebfield-categories .toggleFacet, #facetapi-facet-search-apicompanies-block-field-membership-tier .toggleFacet, #mini-panel-mr_characteristics_filters  .toggleFacet').click(function (event) {
            if ($(this).is(".plus")) {
                $(this).removeClass('plus');
                $(this).addClass('minus');
                $(this).next().css('display', 'block');
                $(this).prev().find('a').css('font-weight', 'bold');
                return;
            }
            if ($(this).is(".minus")) {
                $(this).removeClass('minus');
                $(this).addClass('plus');
                $(this).next().css('display', 'none');
                $(this).prev().find('a').css('font-weight', 'normal');
                return;
            }
        });

        $('#mini-panel-sd_companies_filters .toggleFacet').click(function (event) {
            if ($(this).is(".plus")) {
                $(this).removeClass('plus');
                $(this).addClass('minus');
                $(this).next().css('display', 'none');
                return;
            }
            if ($(this).is(".minus")) {
                $(this).removeClass('minus');
                $(this).addClass('plus');
                $(this).next().css('display', 'block');
                return;
            }
        });
        $('#mini-panel-sd_companies_filters li.expanded').click(function (event) {

            if ($(this).find(' > ul').css('display') == 'block') {
                $(this).find(' > span.toggleFacet').removeClass('minus');
                $(this).find(' > span.toggleFacet').addClass('plus');
                $(this).css('font-weight', 'normal');
            }
            if ($(this).find(' > ul').css('display') == 'none') {
                $(this).find(' > span.toggleFacet').addClass('minus');
                $(this).find(' > span.toggleFacet').removeClass('plus');
				                $(this).css('font-weight', 'bold');
            }

        });

        $('#mini-panel-sd_companies_filters li.expanded').each(function (event) {

            if ($(this).find(' > ul').css('display') == 'block') {
                   $(this).css('font-weight', 'bold');
            }
            if ($(this).find(' > ul').css('display') == 'none') {
  				                $(this).css('font-weight', 'normal');
            }

        });		

        $("#mini-panel-sd_filters_group li.leaf, #mini-panel-mr_filters_group  li.leaf").each(function () {
            if ($(this).find(" > input:checked").length == 1) {
                console.log($(this).parent().attr('style'));
                if (typeof $(this).parent().attr('style') == 'undefined')
                    $(this).css({'font-weight': 'bold', 'font-size': '16px'});
                else
                    $(this).css({'font-weight': 'bold', 'font-size': '14px'});
            }
        });
        $("#mini-panel-sd_characteristics_filters .pane-content, #mini-panel-mr_characteristics_filters .pane-content").each(function () {
            if ($(this).css('display') == 'block') {
                $(this).parent().css('background', '#f0f0f0 url(/sites/all/themes/custom/intel_isdm_bootstrap/images/icons/sidebar-children-minus.png) no-repeat 3% 11px');

            }
        });
		
    });
})(jQuery);
