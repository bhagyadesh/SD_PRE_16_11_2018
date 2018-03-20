(function($) {
	 Drupal.behaviors.custom = {
		attach: function(context, settings) {
			$('.ervw-add-items').bind('mousedown', function() {
            if($('#modal-hidden-selected-entityid-box').length == 1) {
                                               $('#modal-hidden-selected-entityid-box').val('');
                                }
        });
		if($('#modal-hidden-selected-entityid-box').length == 0) {
			$('<input>').attr({
				type: 'hidden',
				id: 'modal-hidden-selected-entityid-box',
				name: 'modal-hidden-selected-entityid'
			}).appendTo('.field-type-entityreference');
		}
		
		if (settings.entityReferenceViewWidget) {
				var ervwSetttings = settings.entityReferenceViewWidget.settings;
				var selector = '#' + ervwSetttings.table_id + ' input[type=checkbox]:not(:checked)';
				var selected_unchecked_ids = '';
				
				$(selector).each(function() {
				 selected_unchecked_ids += $(this).val() + ';';
				});
				if (selected_unchecked_ids.length > 0) {
				 $('input[name="selected_all_old_unchecked_entity_ids"]').val(selected_unchecked_ids.substring(0, selected_unchecked_ids.length - 1)).trigger('change');
				}

				
		 }

		var selected_entity_ids = [{"id":""}];
		//var jsonObj = $.parseJSON($("#modal-hidden-selected-entityid-box").val());
		var selected_new_entity_ids = '';
		var selected_old_entity_unchecked_ids = [];
		var selected_old_entity_unchecked_ids_val = $('input[name="selected_all_old_unchecked_entity_ids"]').val();
		var selected_old_entity_ids = [];
		var selected_old_entity_ids_val = $('input[name="selected_entity_ids"]').val();
		
		if(selected_old_entity_unchecked_ids_val !==undefined){
			var selected_old_entity_unchecked_ids = selected_old_entity_unchecked_ids_val.split(';');
		}
		
		if(selected_old_entity_ids_val !==undefined){
			var selected_old_entity_ids = selected_old_entity_ids_val.split(';');
		}
		
		
			$.each(selected_old_entity_unchecked_ids, function(i, value) {
					//console.log(i + ':h ' + value);
					if(value !='')
						$("#modal-content input.entity-reference-view-widget-select[type=checkbox][value="+value+"]").removeAttr('checked');
					
			});
		
		
		
			$.each(selected_old_entity_ids, function(i, value) {
				//console.log(i + ':rr ' + value);
				if(value !='')
					$("#modal-content input.entity-reference-view-widget-select[type=checkbox][value="+value+"]").attr("checked","true").attr("disabled","true");
				//$("#modal-content input.entity-reference-view-widget-select[type=checkbox][value="+value+"]").attr("checked","true");
				
			});
		
		
			
		
		
		
		$.fn.get_new_entity_ids = function () {
			var jsonObj = '';
			var hidden_selected_entity_box = $("#modal-hidden-selected-entityid-box").val();
			if(hidden_selected_entity_box != '' && typeof hidden_selected_entity_box !== 'undefined'){	
				//console.log($("#modal-hidden-selected-entityid-box").val());
				jsonObj = $.parseJSON(hidden_selected_entity_box);
				var selected_new_entity_ids = '';
				
				if(jsonObj != null){
					$.each(jsonObj, function(i, item) {
						//console.log('here'+item.id);
						if(item.id != ''){
							$("#modal-content input.entity-reference-view-widget-select[type=checkbox][value="+item.id+"]").attr("checked","true");
							selected_new_entity_ids += item.id + ';';
						}
					});
					//if($('input[name="selected_entity_ids"]').val() == ''){}
					$('input[name="selected_new_entity_ids"]').val(selected_new_entity_ids.substring(0, selected_new_entity_ids.length - 1));
				}
			}
		};

		$('body').get_new_entity_ids(); 

		$("#modal-content input.entity-reference-view-widget-select").change(function(){
			var jsonObj = '';
			var hidden_selected_entity_box = $("#modal-hidden-selected-entityid-box").val();
			//console.log('hide'+hidden_selected_entity_box);
			if(hidden_selected_entity_box == '' || typeof hidden_selected_entity_box === 'undefined'){
				//console.log('undefined');
				jsonObj = '{"id" : ""}';	
			}else{
				jsonObj = $.parseJSON(hidden_selected_entity_box);
			}
			//console.log('obj'+$("#modal-hidden-selected-entityid-box").val());
			if($("#modal-hidden-selected-entityid-box").val() !=''){
				//console.log('empn')
				selected_entity_ids = jsonObj;
			}
			 var thisvalue = $(this).val();
			 //selected_entity_ids = $("#modal-hidden-selected-entityid-box").val();
				if($(this).is(":checked")){
					 if(selected_entity_ids !=''){        	
						selected_entity_ids = $.grep(selected_entity_ids, function(n, i){
							return (n !== "" && n != null);
						});
						selected_entity_ids = $.grep(selected_entity_ids, function(n, i){
							return n.id !=  thisvalue;
						});
						
						selected_entity_ids.push({"id":thisvalue});
						
					 }
					
					 
				  }else{
					
						selected_entity_ids = $.grep(selected_entity_ids, function(item, i) {
						return item.id !=  thisvalue;
					});
					
				  }
			$("#modal-hidden-selected-entityid-box").val(JSON.stringify(selected_entity_ids));
				  //console.log('json'+JSON.stringify(selected_entity_ids));
			$('body').get_new_entity_ids();
        });
		
		
 }
 };
	})(jQuery); 