/**
 * @FILE: Solutions finder expander / collapser.
 */

// Wrap jQuery. Also use a document ready to only trigger when appropriate.
(function ($) {
  $(document).ready(function(){

    // Establish some basic vars for usage throughout. Makes adjusting easier.
    parent_selector = 'body.node-type-solution';
    field_selector = '.field-name-body';
    collapsed_px = 320;
    see_more_text = 'See more';
    see_less_text = 'See less';
    expander_class = 'expander-button';
    expander_btn = '.' + expander_class;
    initialHeight = $(field_selector).innerHeight();


    // @TODO: DO NOT DECLARE ANY FIXED VALUES BELOW! PUT THEM ABOVE!
    // @TODO: USE GOOD VARIABLE NAMES SO THIS READS CLEAR AND EASY.
    // @TODO: WRITE CLEAR AND HELPFUL COMMENTS!
    // @TODO: Have CSS begin with the body collapsed via max-height matching collapsed px above.


    // See if solutions item exists to run code against.
    if ($(field_selector, parent_selector).length > 0){
      // Check if height of field is equivelant to collapsed px trigger.
      if($(field_selector, parent_selector).innerHeight() >= collapsed_px){
        // @TODO: Control height of content being display
        $(field_selector).css({'height' : collapsed_px, 'overflow' : 'hidden'});
        // @TODO: Add expander text
        $( '<a class="' + expander_class + '">' + see_more_text + '</a>' ).insertAfter(  $(field_selector) );
        // Listen for click of expander/collapser.
        $(expander_btn).on('click', function() {
          // @TODO: Check if the item is collapsed.
          if(!$(expander_btn).hasClass('collapse-button')){
            // @TODO: Animate expansion, change classes as necessary.
            // @TODO: Change expander collapser text as well.
            $(this).prev().animate({height:initialHeight}, 300);
            $(this).toggleClass('collapse-button').html(see_less_text);
          } else {
            // @TODO: Animate collapse, change classes as necessary.
            $(this).prev().animate({height:collapsed_px}, 300);
            // @TODO: Change expander collapser text as well.
             $(this).toggleClass('collapse-button').html(see_more_text);
          }
        });






      }
    }
  });
})(jQuery);






