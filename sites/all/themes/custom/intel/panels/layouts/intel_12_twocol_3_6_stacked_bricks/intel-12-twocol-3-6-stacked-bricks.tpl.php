<div class="panel-display omega-grid intel-12-twocol-3-6-stacked-bricks" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel grid-9 content-top">
    <div class="inside clearfix">
      <div class="panel-panel grid-3 alpha content-left-top">
        <div class="inside"><?php print $content['left_top']; ?></div>
      </div>
      <div class="panel-panel grid-6 omega content-right-top">
        <div class="inside"><?php print $content['right_top']; ?></div>
      </div>
    </div>
  </div>
  <div class="panel-panel grid-9 content-bottom">
    <div class="inside clearfix"><?php print $content['bottom']; ?></div>
  </div>
</div>
