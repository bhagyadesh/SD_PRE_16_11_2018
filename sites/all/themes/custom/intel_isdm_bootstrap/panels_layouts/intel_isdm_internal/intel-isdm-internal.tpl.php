<?php
/**
 * Available regions:
 *
 * $content['panel_title']
 * $content['top_blue']
 * $content['bottom_main']
 *
 */
?>
<div class="" id="<?php if (!empty($css_id)){print $css_id;} ?>">
    <?php if(isset($content['top_blue']) && strlen($content['top_blue']) > 0) { ?>
        <div class="top_blue">
            <div class="container">
                <div class="row">
                    <div class="col-12">
                        <?php
                            print $content['panel_title'];
                            print $content['top_blue'];
                        ?>
                    </div>
                </div>
            </div>
        </div>
    <?php } else {
    // Print title outside the blue content area.
    print $content['panel_title'];
    } ?>
    <div class="container">
        <div class="row">
            <div class="col-12">
                <?php print $content['bottom_main'];?>
            </div>
        </div>
    </div>
</div>