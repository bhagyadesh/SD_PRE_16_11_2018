(function ($) {
    $(document).ready(function () {

        $(".page-member-resource-center .region-sidebar-first section > ul.menu").each(function () {

            if ($(this).css('display') == 'block') {

                $(this).parent().find('h2.block-title').prepend('<span class="minus toggleFacet" aria-hidden="true"></span>');
            }
            if ($(this).css('display') == 'none') {
				
				$(this).parent().find('h2.block-title').prepend('<span class="plus toggleFacet" aria-hidden="true"></span>');
                

            }
        });

        $('.page-member-resource-center .region-sidebar-first section .toggleFacet').click(function (event) {
            if ($(this).is(".plus")) {
                $(this).removeClass('plus');
                $(this).addClass('minus');
                $(this).parent().parent().find('> ul.menu').css('display', 'block');
                return;
            }
            if ($(this).is(".minus")) {
                $(this).removeClass('minus');
                $(this).addClass('plus');
				   $(this).parent().parent().find('> ul.menu').css('display', 'none');
               // $(this).parent().next().next().css('display', 'none');
                return;
            }
        });
	
    });
})(jQuery);
