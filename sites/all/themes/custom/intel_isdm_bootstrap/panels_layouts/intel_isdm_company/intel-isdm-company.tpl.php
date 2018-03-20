<?php
/**
 * Available regions:
 *
 * $content['general_info']
 * $content['company_sidebar']
 * $content['partners_sidebar']
 * $content['articles_sidebar']
 * $content['view_one']
 * $content['view_two']
 * $content['view_three']
 * $content['view_four']
 *
 */
?>

    <!-- Our content goes here -->
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id='$css_id'"; } ?>>

    <?php if (!empty($breadcrumb)): print $breadcrumb; endif;?>

    <section class="main-content">

        <div class="row">
            <div class="company-info">
                <?php print $content['general_info']; ?>
            </div>
        </div>

        <div class="row">
            <div class="related-products">
                <?php print $content['view_one']; ?>
            </div>
        </div>

        <div class="row">
            <div class="related-products">
                <?php print $content['view_two']; ?>
            </div>
        </div>

        <div class="row">
            <div class="related-products">
                <?php print $content['view_three']; ?>
            </div>
        </div>
        
        <div class="row">
            <div class="related-products">
                <?php print $content['view_four']; ?>
            </div>
        </div> 	
	 <div class="row">
            <div class="related-products">
                <?php print $content['view_five']; ?>
            </div>
        </div>

    </section>

    <aside class="sidebar-right">
        <div class="company-info">
            <?php print $content['company_sidebar']; ?>
        </div>

        <div class="related-content">
            <?php print $content['articles_sidebar']; ?>
        </div>
    </aside>


</div>
