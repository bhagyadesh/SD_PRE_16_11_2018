/**
 * @file
 *
 * Intel EA Module JS.
 */

(function($) {
  Drupal.behaviors.intelEAModule = {
    attach: function(context, settings) {
      // Set Google Analytics tracking events.
      var company_category = 'Member Details';
      var solution_category = 'Product Details';
      var formula_category = 'Formula Details';

      var body_class = $('.page-node').attr('class').match(/page-node-[0-9]+/);
      var nid = body_class[0].match(/[0-9]+/);

      /*
       * Company events
       */
      // Click: Company Webpage
      $('.node-type-company .pane-node-field-website a').click(function() {
        _gaq.push(['_trackEvent', company_category, 'Company Webpage', nid[0]]);
      });
      // Click: Contact Member (company page)
      $('.node-type-company .pane-intel-ea-module-aprimo-company-contact-btn a').click(function() {
        _gaq.push(['_trackEvent', company_category, 'Contact Member', nid[0]]);
      });
	  $('.node-type-company .pane-intel-ea-module-aprimo-company-contact-member a').click(function() {
        _gaq.push(['_trackEvent', company_category, 'Contact Member', nid[0]]);
      });
	  
      /*
       * Solution (product) events
       */
      // Click: Contact Member (solution page) 
      $('.node-type-solution .pane-intel-ea-module-aprimo-solution-company-btn a').click(function() {
        _gaq.push(['_trackEvent', solution_category, 'Contact Member', nid[0]]);
      });
	  //Click: Request Quote(solution page)
		$('.node-type-solution .req a').click(function() {
        _gaq.push(['_trackEvent', solution_category, 'Contact Member', nid[0]]);
      }); 
		 
		 
	  /*$('.node-type-solution .req a').click(function() {
        _gaq.push(['_trackEvent', solution_category, 'Request Quote', nid[0]]);
      });*/
	  
      // Click: Contact Intel (solution page)
      $('.node-type-solution .pane-intel-ea-module-aprimo-solution-intel-btn a').click(function() {
        _gaq.push(['_trackEvent', solution_category, 'Contact Intel', nid[0]]);
      });
	  
	  $('.node-type-solution .contact-intel a').click(function() {
        _gaq.push(['_trackEvent', solution_category, 'Contact Intel', nid[0]]);
      });
      // Click: Datasheet
      $('.node-type-solution .views-field-field-datasheet a').click(function() {
        _gaq.push(['_trackEvent', solution_category, 'Download Datasheet', nid[0]]);
      });
      // Click: Product Webpage
      $('.node-type-solution .views-field-field-website a').click(function() {
        _gaq.push(['_trackEvent', solution_category, 'Product Webpage', nid[0]]);
      });
	  
	  $('.node-type-solution .field-name-field-website a').click(function() {
        _gaq.push(['_trackEvent', solution_category, 'Product Webpage', nid[0]]);
      });

      /*
       * Formula events
       */
      // Click: Contact Member (formula page)
      $('.node-type-formula .pane-intel-ea-module-aprimo-solution-company-btn a'). click(function() {
        _gaq.push(['_trackEvent', formula_category, 'Contact Member', nid[0]]);
      });
      // Click: Contact Intel (formula page)
      $('.node-type-formula .pane-intel-ea-module-aprimo-solution-intel-btn a').click(function() {
        _gaq.push(['_trackEvent', formula_category, 'Contact Intel', nid[0]]);
      });
      // Click: System Integrators Contact
      $('.node-type-formula .pane-intel-ea-module-aprimo-formula-integrator-links a[class^="node-company"]').each(function(index) {
        var int_link_class = $(this).attr('class').match(/node-company-[0-9]+/);
        var int_nid = int_link_class[0].match(/[0-9]+/);
        $(this).click(function() {
          _gaq.push(['_trackEvent', formula_category, 'System Integrators Contact - To', int_nid[0]]);
          _gaq.push(['_trackEvent', formula_category, 'System Integrators Contact - From', nid[0]]);
        });
      });
      // Click: Bill of Materials Download
      $('.node-type-formula .pane-node-field-bill-of-materials a').click(function() {
        _gaq.push(['_trackEvent', formula_category, 'BoM Download', nid[0]]);
      });
      // Click: Resources
      $('.node-type-formula .pane-node-field-formula-resources a').click(function() {
        _gaq.push(['_trackEvent', formula_category, 'External Resource', nid[0]]);
      });
      // Click: Component Link
      $('.node-type-formula .pane-node-field-component-group .node-solution .node-title a').each(function(index) {
        var comp_article_id = $(this).parents('.node-solution').attr('id').match(/node-solution-[0-9]+/);
        var comp_nid = comp_article_id[0].match(/[0-9]+/);
        $(this).click(function() {
          _gaq.push(['_trackEvent', formula_category, 'Component Link - To', comp_nid[0]]);
          _gaq.push(['_trackEvent', formula_category, 'Component Link - From', nid[0]]);
        });
      });
      // Click: Component Contact
      $('.node-type-formula .pane-node-field-component-group .node-solution .field-name-field-aprimo-link a').each(function(index) {
        var field_link_class = $(this).attr('class').match(/node-company-[0-9]+/);
        var field_nid = field_link_class[0].match(/[0-9]+/);
        $(this).click(function() {
          _gaq.push(['_trackEvent', formula_category, 'Component Contact - To', field_nid[0]]);
          _gaq.push(['_trackEvent', formula_category, 'Component Contact - From', nid[0]]);
        });
      });
    }
  };
})(jQuery);
