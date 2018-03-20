/**
 * @file
 *
 * Intel EA Training Center JS.
 */

(function($) {
  // Define objects for Drupal.
  Drupal.intelEATrainingCenter = Drupal.intelEATrainingCenter || {};

  // Define behaviors for Drupal.
  Drupal.behaviors.intelEATrainingCenter = {
    attach: function(context, settings) {

      // Run slideTiles on the Training Center homepage,
      // beginning with the first Training Section.
      $('.context-training-center ul.training-section-a').cycle({
        fx: 'scrollLeft',
        delay: -4000,
        sync: true,
        timeout: 6000
      });

      $('.context-training-center ul.training-section-b').cycle({
        fx: 'scrollLeft',
        delay: -3000,
        sync: true,
        timeout: 6000
      });

      $('.context-training-center ul.training-section-c').cycle({
        fx: 'scrollLeft',
        delay: -2000,
        sync: true,
        timeout: 6000
      });

      $('.context-training-center ul.training-section-d').cycle({
        fx: 'scrollLeft',
        delay: -1000,
        sync: true,
        timeout: 6000
      });

      $('.context-training-center ul.training-section-e').cycle({
        fx: 'scrollLeft',
        delay: 0,
        sync: true,
        timeout: 6000
      });
      $('.context-training-center ul.training-section-f').cycle({
        fx: 'scrollLeft',
        delay: 1000,
        sync: true,
        timeout: 6000
      });

      // Animate ajax-links to scroll to the top of the ajax tabs.
      $('.context-training-center h2.ajax-link a').click(function() {
        var scrollOffset = $('.context-training-center .pane-training-section-tabs-pdf').offset().top - 30;
        $(document).ajaxComplete(function () {
          $('html, body').animate({
            scrollTop: scrollOffset
          }, {
            'duration': 'fast',
            'easing': 'easeInCubic',
            'queue': false // prevent multiple ajax calls from stacking animations
          });
        });
      });

      // Setup jQuery bigTarget for the Training Center tiles.
      $('.page-training-center .training-section li.first h2.node-title a').each(function(index) {
        $(this).bigTarget({
          clickZone: '.training-section',
          copyTitleToClickZone: true
        });
      });

      // Setup jQuery bigTarget for Training Section slides.
      $('.node-type-training-section .view-training-section-slides .node-training-sub-section h2.node-title a').each(function(index) {
        $(this).bigTarget({
          // clickZone: '.views-slideshow-cycle-main-frame-row',
          clickZone: '.views-slideshow-cycle-main-frame-row-item',
          copyTitleToClickZone: true
        });
      });
    }
  };
})(jQuery);
