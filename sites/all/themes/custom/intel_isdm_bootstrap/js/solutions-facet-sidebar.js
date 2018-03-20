(function ($) {
  Drupal.behaviors.intel_isdm_bootstrap_facets = {
    attach: function (context, settings) {
      $(document).ready(function(){
        // Establish some parent selectors to handle solutions and company pages.
        selected_parent_selectors = [
          'ul#facetapi-facet-search-apisolutions-block-field-categories > li > input:checked',
          'ul.facetapi-facet-field-company-node-ebfield-categories > li > input:checked',
		  'ul#facetapi-facet-search-apisolutions-block-field-solution-type > li > input:checked',
        ];
        not_selected_parent_selectors = [
          'ul#facetapi-facet-search-apisolutions-block-field-categories > li > input:not(:checked)',
          'ul.facetapi-facet-field-company-node-ebfield-categories > li > input:not(:checked)'
        ];
        selected_parent_selectors = selected_parent_selectors.join(", ");
        not_selected_parent_selectors = not_selected_parent_selectors.join(", ");
/**
        // Process all facetapi checkbox link lists, remove direct descendant selectors.
        $(selected_parent_selectors.replace('>', '')).each(function(){
          // Show all sibling UL's of checked items.
          $(this).siblings('ul').css('display','block');
        });
  **/
        /** Added by siva **/
     $("ul#facetapi-facet-search-apisolutions-block-field-categories li > input:checked, ul.facetapi-facet-field-company-node-ebfield-categories  li > input:checked, #facetapi-facet-search-apicompanies-block-field-membership-tier  li > input:checked,ul#facetapi-facet-search-apisolutions-block-field-solution-type li > input:checked").each(function(){
          // Show all sibling UL's of checked items.
          $(this).siblings('ul').css('display','block');
        });
		
		/** End **/
        // Process all refine by facet api items.
        $('.pane-sd-characteristics-filters li > input:checked').each(function(){
          $(this).siblings('ul').css('display','block');
        });

        // Add toggle to companies alphabet.
        $('ul#facetapi-facet-search-apisolutions-block-field-company li').on('click',function(){
          $(this).children('ul').toggle();
        });

        // Hide all non-selected item if a selected parent exists.
        if($(selected_parent_selectors).length > 0){
          $(not_selected_parent_selectors).each(function(){
            $(this).parent('li').css('display','none');
          });
        }
      });
    }//end drupal attach function
  };
})(jQuery);
