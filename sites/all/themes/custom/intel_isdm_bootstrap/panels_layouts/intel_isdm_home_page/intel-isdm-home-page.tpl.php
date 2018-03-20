<?php
/**
 * Available regions:
 *
 * $content['top_left']
 * $content['top_right']
 * $content['middle_left']
 * $content['middle_right']
 * $content['middle_right2']
 * $content['bottom_left']
 * $content['bottom_right']
 *
 */
?>

<!-- Our content goes here -->
<div class="panel-display clearfix" <?php if (!empty($css_id)) { print "id='$css_id'"; } ?>>
    <section id="home-banner">
        <div class="container">
            <div class="panel-panel row clearfix">
                <div class="panel-col-first col-8">
                    <?php print $content['top_left']; ?>
                </div>
                <div class="panel-col-last col-4">
                    <?php print $content['top_right']; ?>
                </div>
            </div>
            <div class="container">
                <div class="row">
                    <div class="panel-panel panel-col-top clearfix">
                        <div class="col-12">
                            <?php print $content['banner_top']; ?>
                        </div>
                    </div>
                </div>
            </div>
        </div>
    </section>

    <div id="browse-by" class="container-fluid">
        <div class="panel-panel row clearfix">
            <div class="container">
		<div class="row" id="tabssd">
		<?php $search_form = drupal_get_form('intel_isdm_module_site_search_form');
    $search_box = drupal_render($search_form); 
	print $search_box;?>
		
		 <ul>
						<li class="frontpage-eIOT-tab"> <a href="#tabs-1">Embedded IoT</a></li>
                        <li class="frontpage-client-tab"> <a href="#tabs-2">Client</a></li>
                        <li class="frontpage-server-tab"> <a href="#tabs-3">Server</a></li>
						<li class="frontpage-partners-tab"> <a href="#tabs-4">Partners</a></li>
	
		 </ul>

		
          <div class="row solutions"  id="tabs-1">
                    <div class="panel-col-first col-4 clearfix">
						<?php
						//echo "<pre>";
						//print_r($content);
						//echo "</pre>";
						?>
                        <?php print $content['eiot_market_segments']; ?>
                    </div>
                    <div class="panel-col-last col-4 clearfix">
                        <?php print $content['eiot_categories']; ?>
                    </div>
                    <div class="panel-col-first col-4 clearfix">
                        <?php print $content['middle_right2']; ?>
                    </div>

                 </div>
                 

				<div class="row partner" id="tabs-2">
                    <div class="panel-col-first col-4 clearfix">
                        <?php print $content['client_market_segments']; ?>
                    </div>
                    <div class="panel-col-last col-4 clearfix">
                        <?php print $content['client_categories']; ?>
                    </div>
                    <div class="panel-col-first col-4 clearfix">
                        <?php print $content['client_explore']; ?>
                    </div> 
				</div>

				<div class="row fpga" id="tabs-3" >
                   <div class="panel-col-first col-4 clearfix">
                        <?php print $content['server_market_segments']; ?>
                    </div>
                    <div class="panel-col-last col-4 clearfix">
                        <?php print $content['server_categories']; ?>
                    </div>
                    <div class="panel-col-first col-4 clearfix">
                        <?php print $content['server_explore']; ?>
                    </div>
                 </div>
				 
				<div class="row test" id="tabs-4" >
					
					<div class="panel-col-first col-6 clearfix">
                        <?php print $content['partners_market_segment']; ?>
                    </div>
                    <div class="panel-col-last col-3 clearfix">
                        <?php print $content['partners_location']; ?>
                    </div>
                    <div class="panel-col-first col-3 clearfix">
                        <?php print $content['view_partners'];  ?>
                    </div>
			
				</div>
				 
		</div>		
            </div>
        </div>
    </div>
    <div id="bottom-content" class="panel-panel">
        <div class="container">
            <div class="row">
                <div class="col-12">
                    <?php print $content['banner_bottom']; ?>
                </div>
            </div>
        </div>
    </div>
</div>
