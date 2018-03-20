(function ($) {  
	Drupal.behaviors.intel_isdm_bootstrap_config = {
    attach: function (context, settings) {   

    	//Add dropdown menu functionality on hover
    	$('.navbar-nav li.dropdown').hover (
        function() {
          $(this).addClass('open');
        }, function() {
          $(this).removeClass('open');
        }
		  );

    	//Add No Search Result Class to <body>
    	if ($(".empty-search").find('.view-empty').length) {
    		$('body').addClass('no-search-result');
    	}

    	//Hide blank tds
    	var list_classes =  'body.page-member-roster table tr td, body.node-type-company table tr td';
      $(list_classes).each(function () {
            if($(this).text().trim() === "") {
              $(this).hide();
            }
      });

      //Disable Tooltip
      $('input.form-control').removeAttr( "data-toggle");

      //Add clear div for browse by type
      $('<div class="clearboth"></div>').insertAfter('.page-browse-by-type .view-browse-by-type-solutions .views-row:nth-child(5n)');

      //Add Browse By Type class to main menu
      $('.tb-megamenu-nav li').eq(1).addClass('browse-by-type');

      //Solutions directory and Member roster insert filter div on top of main when not logged in
      $('body.not-logged-in .region-content #block-current-search-solutions-directory, body.not-logged-in .region-content #block-current-search-partner-companies').insertBefore('#block-system-main');

      //View Alphabet
      $('#mini-panel-sd_companies_filters').find('.parent-children-category').show();

		}//end drupal attach function
	};
})(jQuery);