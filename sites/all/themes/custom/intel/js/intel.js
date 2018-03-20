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

  Drupal.behaviors.intel = {
    attach: function (context, settings) {

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
        // Add an X to current search terms
        //
        var search = $('.current-search-item-active .first a').text()
        if ( search ) {
        } else {
          var list = $('.current-search-item-active .first')
          search = list.text()
          if(search == '[all items]') {
          } else {
            var url = removeParameter(document.URL, 'search' );
            list.prepend('<a href="' + url + '"><img src="/sites/all/themes/custom/intel/images/search-term-close.png" typeof="foaf:Image"></a> ');

          }
        }

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
          $(this).parents('li.expanded').css('background', 'transparent url(/sites/all/themes/custom/intel/images/filters-collapse.png) no-repeat right 7px');
           // Set a collapsed background image for all .panel-pane parents
           // except for the last one.
          $(this).parents('.panel-pane').not(':last').css('background', 'transparent url(/sites/all/themes/custom/intel/images/filters-collapse.png) no-repeat right 17px');
          // Display this items children.
          $(this).siblings('.item-list').show();
        });

        // Handle category click for NESTED PANELS.
        $(filterGroups).find('.panel-pane > h2', context).click(function(e) {
          var parent = $(this).parent();

          if ($('> div.pane-content', parent).is(':visible')) {
            $(parent).css('background', 'transparent url(/sites/all/themes/custom/intel/images/filters-expand.png) no-repeat right 17px');
            $(parent).css('border-bottom', 'solid 1px #055ea4');
            $('> div.pane-content', parent).hide();
          }
          else {
            $(parent).css('background', 'transparent url(/sites/all/themes/custom/intel/images/filters-collapse.png) no-repeat right 17px');
            $(parent).css('border', 'none');
            $('> div.pane-content', parent).show();
          }

          e.stopPropogation();
        });

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
          e.stopPropagation();
        });

        // Prevent clicks on child elements of a facet from propogating.
        $(filterGroups).find('.block-inner li.expanded', context).children().click(function(e) {
          e.stopPropagation();
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

        Drupal.behaviors.intel.loaded = true;
      }
    }
  };

})(jQuery);
