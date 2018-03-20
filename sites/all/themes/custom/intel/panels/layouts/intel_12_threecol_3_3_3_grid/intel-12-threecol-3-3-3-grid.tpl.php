<div class="panel-display omega-grid intel-12-twocol-6-3-grid" <?php if (!empty($css_id)) { print "id=\"$css_id\""; } ?>>
  <div class="panel-panel grid-9 content-top">
    <div class="inside clearfix">
      <div class="panel-panel grid-3 alpha content-left-top">
        <div class="inside"><?php print $content['left_top']; ?></div>
      </div>
      <div class="panel-panel grid-3 content-center-top">
        <div class="inside"><?php print $content['center_top']; ?></div>
      </div>
      <div class="panel-panel grid-3 omega content-right-top">
        <div class="inside"><?php print $content['right_top']; ?></div>
      </div>
    </div>
  </div>
  <div class="panel-panel grid-9 content-bottom">
    <div class="inside clearfix">
      <div class="panel-panel grid-6 alpha content-left-bottom">
        <div class="inside"><?php print $content['left_bottom']; ?></div>
      </div>
      <div class="panel-panel grid-3 omega content-right-bottom">
        <div class="inside"><?php print $content['right_bottom']; ?></div>
      </div>
    </div>
  </div>
</div>
