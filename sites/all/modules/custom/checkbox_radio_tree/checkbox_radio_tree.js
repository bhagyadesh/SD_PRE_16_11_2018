(function($) {
  Drupal.behaviors.checkboxRadioTree = {
    attach: function(context, settings) {
	$(".page-node-edit .node-solution-form .vertical-tabs ul.vertical-tabs-list li:nth-child(4) a").click(function() {
					updateCharateristicsTree();
				});
	 //console.log("Loading Categories mapping Data for all characteristics....");
	
	var myJson = '';
	var data = {
	  "action": "get_taxonomy_relationship"
	};	
	//form_data = $(this).serialize() + "&" + $.param(data);	
	$.ajax({
			  type: "POST",
			  //url: 'get_taxonomyrelationship.php',
			  url: '/tax/gettaxonomyrelationship',
			  data:  data,
			  success: 'success',
			  dataType: "text",
			  //contentType: "application/json",
			  
			  success: function(data) {				
					//console.log(data);
					myJson = JSON.parse(data);
					//console.log(myJson);
				  },
			  error: function(XMLHttpRequest, textStatus, errorThrown) { 
					alert("Status: " + textStatus); alert("Error: " + errorThrown); 
				 }
				 
			});
	
	
	//console.log("Loading Content type mapping data for all CATEGORIES....");
	
	var category_contenttypeJson = '';
	var category_contenttypedata = {
	  "action": "get_category_contenttype_data"
	};	
	
	$.ajax({
			  type: "POST",
			  url: '/getcategorycontenttypedata',
			  data:  category_contenttypedata,
			  success: 'success',
			  dataType: "text",
			  
			  success: function(data) {				
					//console.log(data);
					category_contenttypeJson = JSON.parse(data);
					//console.log(category_contenttypeJson);
				  },
					error: function(XMLHttpRequest, textStatus, errorThrown) { 
					alert("Status: " + textStatus); alert("Error: " + errorThrown); 
				 }
				 
			});
	
	
	//console.log("Loading  Content type mapping data for all characteristics....");
	
	var contenttypeJson = '';
	var contenttypedata = {
	  "action": "get_contenttype_data"
	};	
	//form_data = $(this).serialize() + "&" + $.param(data);	
	$.ajax({
			  type: "POST",
			  url: '/tax/getcontenttypedata',
			  data:  contenttypedata,
			  success: 'success',
			  dataType: "text",
			  //contentType: "application/json",
			  
			  success: function(data) {				
					//console.log(data);
					contenttypeJson = JSON.parse(data);
					//console.log(contenttypeJson);
				  },
					error: function(XMLHttpRequest, textStatus, errorThrown) { 
					alert("Status: " + textStatus); alert("Error: " + errorThrown); 
				 }
				 
			});
	
		 
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
		var checkedInputElement = $(this).attr('id');
		
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
		
		//console.log("new entry...");
		if(checkedInputElement.indexOf('categories') >= 0)
			updateCharateristicsTree();
		
      });
	  
function updateCharateristicsTree(){
			  
		// Get all the Selected Categories
		var selected = [];			
		//$(".checkbox-radio-tree input:checked").each(function(){
		$("div[id*='edit-field-categories-und'] input:checked").each(function(){
				if( $(this).val() != '_none'){
				selected.push($(this).val());
				//console.log($(this).attr('id'));
				}
		});
		
		//console.log(selected);
		
		// Get selected Category ID
		var dataCaregory = selected[selected.length - 1];
		//console.log(dataCaregory);
		
		// Get selected content Types
		var ctype_selected = [];
		$("div[id*='edit-field-solution-type-und'] input:checked").each(function(){
			ctype_selected.push($(this).val());
		});

		// Reset all characteristics to show		
		for (var key1 in myJson) {
			
			if( key1 == "processors" ) { key1 = "processors-list"; }
			if( key1 == "intel_iot_market_ready_solutions" ) { key1 = "intel-iot-market-ready-sol"; }
			
			var mainContainerKey = '#edit-field-'+key1.split('_').join('-')+'-und';
	
			$(mainContainerKey+' label').show();
		
		}
		
		
		
		for (var key1 in myJson) {   
	
				 console.log("Characteristics Under Vacabulary ORG KEY "+key1);
				
					//for(var key2 in myJson[key1]){
					//for (i = 0; i < myJson[key1].length; i++) { 
						
						temp_key = key1.split('_').join('-');
					    												
						if( temp_key == "processors" ) { temp_key = "processors-list"; }
						if( temp_key == "intel-iot-market-ready-solutions" ) { temp_key = "intel-iot-market-ready-sol"; }
						
						console.log("Characteristics Under Vacabulary TEMP KEY "+temp_key);
						
						$('#edit-field-'+temp_key+'-und input').each(function() {
					
							var char_id = $(this).val();
							 console.log('ID : '+ $(this).val());
							
							if( myJson[key1][char_id] !== undefined ) { // checking is valid Array
								
								var match_count=0;
								for (cnt = 0; cnt < selected.length; cnt++) { 
								
									if(myJson[key1][char_id].indexOf(selected[cnt]) != -1)
									{  
									   // element found
									   match_count++;
									}
									
								}
							
								//console.log('matchcount : '+ match_count+ ' length :' + selected.length );
								
								var temp_1 = category_contenttypeJson[dataCaregory].toString();
								var temp_2 = contenttypeJson[char_id].toString();
								var temp_3 = ctype_selected.toString();

								console.log(' Content type selected : ' + temp_3 );
								console.log(' Category content types for : ' + dataCaregory + ' : ' + temp_1 );
								console.log(' Char content types for : ' + char_id + ' : ' + temp_2 );
								

								
								// Check if content types of Char is equal to (OR) subset of selected category content type

								var isCharSubsetOfCategory = false;
								var isCharSubsetOfCategory_rev = false;
								if( contenttypeJson[char_id] !== undefined ) {
									isCharSubsetOfCategory = ctype_selected.every(function(val) { return contenttypeJson[char_id].indexOf(val) >= 0; });
									isCharSubsetOfCategory_rev = contenttypeJson[char_id].every(function(val) { return ctype_selected.indexOf(val) >= 0; });
								}
								
								if( isCharSubsetOfCategory || isCharSubsetOfCategory_rev ){									
									//console.log(" Show this " + char_id); // true								
								} else {
									//console.log(" Hide this" + char_id); // true
								}
								
								// && isCharSubsetOfCategory
								if( ( match_count == selected.length ) && ( isCharSubsetOfCategory || isCharSubsetOfCategory_rev )  ){																		
									// enable the characteristics
									$(this).parent().prev('span').show(); // Show the Expand , collapse Tree
																		
								} else {
									// console.log('Hiding : '+ char_id);
									$(this).parent().hide(); // disable the characteristics
									$(this).parent().prev('span').hide(); // Hide the Expand , collapse Tree
									
									// hide helping text for "Intel® IoT Market Ready Solutions"
									if ( temp_key == "intel-iot-market-ready-sol") {
										$("#edit-field-intel-iot-market-ready-sol .description").hide();
									}
									
								}
								
							} else {
								
								// console.log('No Array data , so Hiding : '+ char_id);
								$(this).parent().hide(); // disable the characteristics							
								$(this).parent().prev('span').hide();  // Hide the Expand , collapse Tree
							
							}
							   
						});
						
					//}

		}
		
	  }
	    
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