(function($) {
  Drupal.behaviors.checkboxRadioTree = {
    attach: function(context, settings) {
      $('.checkbox-radio-tree', context).each(function() {
        // Ensure ancestors of all selected decendants are selected.
        $(this).find('input:checked').each(function() {
          // Ensure this element is still checked.
          if ($(this).is(':checked')) {
            var parent = $(this).parent().parent().prev().children('input');
            if (!parent.is(':checked')) {
              parent.click().trigger('change');
            }
          }
        });
      });

      // When a checkbox status changes.
      $('.checkbox-radio-tree input', context).change(function(event) {
        // Ensure the parent is checked.
        if ($(this).is(':checked')) {
          // Unselect the children of sibling radio elements.
          if ($(this).is('input[type=radio]')) {
            $(this).parent().siblings('.children').not('#' + $(this).attr('id') + '-children').find('input').each(function() {
              $(this).attr('checked', false);
            });
          }

          // Check the parent if it isn't already.
          var parent = $(this).parent().parent().prev().children('input');
          if (!parent.is(':checked')) {
            parent.click().trigger('change');
          }
        }
        // Ensure all children are unchecked.
        else {
          $(this).parent().next('.children').find('input:checked').each(function() {
            $(this).attr('checked', false);
          });
        }
      });
	  
	  
	  
	  	// Expand collapse Tree for Top and Sub level elements which has children
			 $('.expand').click(function (evt) { 				
					 $(this).toggleClass('minus');
					 // Avoid this function from getting called twice 
					  evt.stopImmediatePropagation();
					  $(this).next().next().toggle();
				 });
    
    }
  };
})(jQuery);