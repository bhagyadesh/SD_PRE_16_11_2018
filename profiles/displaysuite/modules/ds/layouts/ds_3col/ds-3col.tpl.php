<?php
// $Id: ds-3col.tpl.php,v 1.1.2.8 2011/02/01 13:47:47 jyve Exp $

/**
 * @file
 * Display Suite 3 column 25/50/25 template.
 */
?>
<div class="<?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <?php if ($left): ?>
    <div class="group-left<?php print $left_classes;?>">
      <?php print $left; ?>
    </div>
  <?php endif; ?>

  <?php if ($middle): ?>
    <div class="group-middle<?php print $middle_classes;?>">
      <?php print $middle; ?>
    </div>
  <?php endif; ?>

  <?php if ($right): ?>
    <div class="group-right<?php print $right_classes;?>">
      <?php print $right; ?>
    </div>
  <?php endif; ?>
</div>