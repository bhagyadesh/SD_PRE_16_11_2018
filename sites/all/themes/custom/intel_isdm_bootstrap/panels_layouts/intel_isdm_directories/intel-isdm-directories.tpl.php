<?php
/**
 * Available regions:
 *
 * $content['sidebar_top']
 * $content['sidebar_bottom']
 * $content['main_content']
 * $content['filters']
 * $content['pagination']
 *
 */
?>
<?php /*<div class="container" id="<?php if (!empty($css_id)){print $css_id;} ?>">*/ ?>
    <div class="row">

        <section class="main col-12">

            <div class="directory-filters">
                <?php print $content['filters']; ?>
            </div>

            <div class="directory-content">
                <?php print $content['main_content']; ?>
            </div>

        </section>

    </div>

<?php /*</div>*/ ?>