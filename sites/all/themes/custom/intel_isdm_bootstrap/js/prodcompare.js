
(function ($) {
    Drupal.behaviors.prodcompare = {
        attach: function (context, settings) {

            if ($('.productcompareTop h2 > a') != 0) {
                $('.productcompareTop h2 > a').text(function (i, text) {
                    var t = $.trim(text);
                    if (t.length > 35) {
                        return $.trim(t).substring(0, 35) + "...";
                    }
                    return t;
                });
            }

            /*$(".flag-product-comparison").on("click", function(event){
             //event.preventDefault();
             location.reload(); 
             
             }); 
             
             $(".comparecheckbox").on("change", function(){
             
             $(this).next().find('a').click();
             
             });              
             
             /* $(".comparelistbutton").on("click", function(event){
             event.preventDefault();
             location.reload(); 
             
             }); */




        }}
})(jQuery);
