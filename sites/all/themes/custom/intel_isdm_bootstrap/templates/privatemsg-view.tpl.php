<?php
// Each file loads it's own styles because we cant predict which file will be
// loaded.
drupal_add_css(drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.base.css');
drupal_add_css(drupal_get_path('module', 'privatemsg') . '/styles/privatemsg-view.theme.css');
?>

<?php global $user; 
		$author =  db_select('pm_message', 'pm')
				->fields('pm', array('author'))
				->condition('mid', $mid)
				->execute()->fetchField();
				$class_append = ($user->uid == $author) ? " self_msg" : " other_msg";
				$author_class = ($user->uid == $author) ? " self_author" : " other_author"; 
				$clone_class = ($user->uid == $author) ? " self_clone" : " other_clone"; ?>
<?php
print $anchors; ?>
<div <?php if ( !empty($message_classes)) { ?>class="<?php echo implode(' ', $message_classes); ?>" <?php } ?> id="privatemsg-mid-<?php print $mid; ?>">
  <div class="privatemsg-author-avatar">
    <?php print $author_picture; ?>
  </div>
  <div class="privatemsg-message-column">
    <?php if (isset($new)): ?>
      <span class="new privatemsg-message-new"><?php print $new ?></span>
    <?php endif ?>
      <div class="privatemsg-message-information<?php echo $author_class;?>">
        <span class="privatemsg-author-name"><?php print $author_name_link; ?></span> <span class="privatemsg-message-date"><?php print $message_timestamp; ?></span>
        <?php if (isset($message_actions)): ?><span class="<?php echo $clone_class; ?>"><?php
print l('Clone this Message!', 'messages/clone/' . $mid);?></span>
          <?php print $message_actions ?>
        <?php endif ?>
      </div>
    <div class="privatemsg-message-body<?php echo $class_append;?>">
	
      <?php print $message_body; ?>
	  <?php $recipients =  db_select('pm_index', 'pi')
				->fields('pi', array('recipient'))
				->condition('mid', $mid)
				->execute()->fetchAll();
				$author_id = $user->uid;
				foreach ($recipients as $recipient) {
					if ($recipient->recipient == $author_id) {
						unset($recipient);
					}
					$msg_recipient[] = $recipient;
				}
				$recipient_count = count(array_filter($msg_recipient));
				if ($recipient_count > 1) { 
				global $base_url;
				$img_path = $base_url.'/'.drupal_get_path('module', 'intel_ea_customizations').'/group_icon.jpg';
	  ?>
					<div class="privatemsg-group-icon">
					<img src="<?php echo $img_path; ?>" alt="Group Message" title="Group Message!">
					</div>
				<?php }?>
    </div>
  </div>
  <div class="clearfix"></div>
</div>
