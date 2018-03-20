jQuery(document).ready(function($) {
	
	// Make all terms Collaped when form loads...
	jQuery("div[id*='characteristic_']").each(function(){
		jQuery("div[id*='characteristic_']").find("table").attr('style','display: none');
	});
	
	expandRow = function(rowid) {
			jQuery("#characteristic_"+rowid).find("table").attr('style','display: block');
      }
	
	collapseRow = function(rowid) {
			jQuery("#characteristic_"+rowid).find("table").attr('style','display: none');
      }
	
	/*	
	checkAll = function(term_id,flcid) { 
			flcid = term_id+'_'+flcid;
			if(jQuery("#flc_"+flcid).is(':checked')){ 
				jQuery("[id*='slc_"+flcid+"']").prop('checked', true);				
			} else {
				jQuery("[id*='slc_"+flcid+"']").prop('checked', false);
			}		
      }
	
	checkEveryCategories = function (termid) { 
		 $("#characteristic_"+termid).find('input[type=checkbox]').each(function () {
             this.checked = true;
        });
	
	}
	
	UncheckEveryCategories = function (termid) {
		 $("#characteristic_"+termid).find('input[type=checkbox]').each(function () {
             this.checked = false;
        });
	
	}
	
	
	checkParent = function (term_id,flcid) {
		if(jQuery("#flc_"+term_id+"_"+flcid).not(':checked')){
		   jQuery("#flc_"+term_id+"_"+flcid).prop('checked', true);	
		}	
	}	
	*/
	
	// Disable bulk save button, to avoid content type & Characteristics value change
	// $("#taxonomy-overview-terms #edit-submit").hide();
	// $("#taxonomy-overview-terms #edit-reset-alphabetical").hide();
	  
});