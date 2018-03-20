<?php
/**
 * Available regions:
 *
 * $content['top_left']
 * $content['top_right']
 * $content['middle_left']
 * $content['middle_right']
 * $content['bottom_left']
 * $content['bottom_right']
 *
 */
?>

    <!-- Our content goes here -->
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id='$css_id'"; } ?>>

    <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>

    <section class="main-content">

        <div class="row">
            <div class="product-info">
                <?php print $content['info_column_one']; ?>
            </div>

            <div class="product-resources">
                <?php print $content['info_column_two']; ?>
            </div>
        </div>

      <?php if($content['middle']):?>
        <div class="row middle">
          <?php print $content['middle'];?>
        </div>
      <?php endif;?>

        <?php if($content['tab_first'] ||  $content['tab_second'] ):?>
        <div class="row">
            <div class="tab-container">
                <ul class="nav nav-tabs">
					<li> <a href="#1" data-toggle="tab">Market Info</a> </li>
                    <li  class="active"> 
					<a href="#2" data-toggle="tab">Tech Specs</a></li>
                </ul>

                <div class="tab-content">
                    <div class="tab-pane active" id="2">
                        <?php print $content['tab_second']; ?>
                    </div>
					
                    <div class="tab-pane" id="1">
                        <?php print $content['tab_first']; ?>
                    </div>
                </div>
            </div>
        </div>
      <?php endif;?>

    </section>

    <?php if($content['sidebar_top'] || $content['sidebar_bottom']):?>
    <aside class="sidebar-right">
        <div class="company-info">
            <?php print $content['sidebar_top']; ?>
        </div>

        <div class="related-content">
            <?php print $content['sidebar_bottom']; ?>
        </div>
    </aside>
    <?php endif;?>


</div>
