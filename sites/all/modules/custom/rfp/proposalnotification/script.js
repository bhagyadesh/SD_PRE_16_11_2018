(function ($) {

    Drupal.behaviors.proposalstatus = {
		

        attach: function (context, settings) {
			
		var prostatus = $('.field-name-field-approval-status .field-items .field-item').html();
		if(prostatus == 'Reject')
		$('.field-name-field-approval-status .field-items .field-item').html('Rejected');
			if(prostatus == 'Accept')
		$('.field-name-field-approval-status .field-items .field-item').html('Accepted');	


 $(".view-proposalperrfp > table tbody > views-field-field-approval-status").each(function (i) {
               					
		prostatusview = $(this).html(); 	
		if(prostatusview == 'Reject')
		$(this).html('Rejected');
			if(prostatusview == 'Accept')
		$(this).html('Accepted');	
                });
	
        $('.proposalstatuschange').unbind().click(function (event) {
			//event.prevntDefault();
			//alert($(this).val());
      if($(this).val() == 'Update Required'){
		  	    $("input[value='Need Update']").prop('checked', true);
	  }
	  else
		   $("input[value='" + $(this).val() + "']").prop('checked', true);
	   
       if($(this).val() == 'Accept Proposal'){
	    var po = prompt('I am ready to place PO (Quantity)' );

		if(po != null){
        $("input[value='Accept']").prop('checked', true);		
		$('#edit-field-po-proposal-und-0-value').val(po);
		}
		else {
			 $("#proposal-node-form").submit(function(e){
              e.preventDefault();
             });
			location.reload();
		}
				
        }

        });		
		
		/** change status click **/

        $('.proposalwfstatuschange').unbind().click(function (event) {

			//event.prevntDefault();
			//alert($(this).val());
      if($(this).val() == 'Publish Proposal'){
		  	    $("#edit-workflow-13").prop('checked', true);
	  }
		   
  if($(this).val() == 'Save as Draft'){
	  	$("#edit-workflow-12").prop('checked', true);
  }

        });	
		
        }
    };
	
	
})(jQuery);
