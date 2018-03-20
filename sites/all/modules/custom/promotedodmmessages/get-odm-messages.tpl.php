
<div class = "odm_message_overall_wrapper">
<?php if(count($variable1) > 0):?>
	<?php foreach($variable1 as $message):?>
	<div class = "odm_message_wrapper">
		<div class = "odm_message_subject">
			<div class = "odm_messages_label">Subject: </div><div><?php print $message['subject']; ?></div>
		</div>
		<div class = "odm_message_company">
			<div class = "odm_messages_label">Sender Company: </div><div><?php print $message['send_company_name']; ?></div>
		</div>
		<div class = "odm_message_date">
			<div class = "odm_messages_label">Date: </div><div><?php print $message['send_date']; ?></div>
		</div>
		<div class = "odm_message_participants">
			<div class = "odm_messages_label">Participants: </div><div><?php print $message['participants']; ?></div>
		</div>
		<div class = "odm_message_content">
			<div class = "odm_messages_label">Content:</div><div><?php print $message['content']; ?></div>
		</div>
	</div>
	<?php endforeach; ?>
<?php else:?>
<div><p>There is <b>no odm legacy message</b> to be displayed for this entity.</p></div>
<?php endif;?>
</div>


