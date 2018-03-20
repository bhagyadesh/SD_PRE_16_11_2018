<?php
/**
 * @file
 * Default theme implementation to display a single Drupal page.
 *
 * The doctype, html, head and body tags are not in this template. Instead they
 * can be found in the html.tpl.php template in this directory.
 *
 * Available variables:
 *
 * General utility variables:
 * - $base_path: The base URL path of the Drupal installation. At the very
 *   least, this will always default to /.
 * - $directory: The directory the template is located in, e.g. modules/system
 *   or themes/bartik.
 * - $is_front: TRUE if the current page is the front page.
 * - $logged_in: TRUE if the user is registered and signed in.
 * - $is_admin: TRUE if the user has permission to access administration pages.
 *
 * Site identity:
 * - $front_page: The URL of the front page. Use this instead of $base_path,
 *   when linking to the front page. This includes the language domain or
 *   prefix.
 * - $logo: The path to the logo image, as defined in theme configuration.
 * - $site_name: The name of the site, empty when display has been disabled
 *   in theme settings.
 * - $site_slogan: The slogan of the site, empty when display has been disabled
 *   in theme settings.
 *
 * Navigation:
 * - $main_menu (array): An array containing the Main menu links for the
 *   site, if they have been configured.
 * - $secondary_menu (array): An array containing the Secondary menu links for
 *   the site, if they have been configured.
 * - $breadcrumb: The breadcrumb trail for the current page.
 *
 * Page content (in order of occurrence in the default page.tpl.php):
 * - $title_prefix (array): An array containing additional output populated by
 *   modules, intended to be displayed in front of the main title tag that
 *   appears in the template.
 * - $title: The page title, for use in the actual HTML content.
 * - $title_suffix (array): An array containing additional output populated by
 *   modules, intended to be displayed after the main title tag that appears in
 *   the template.
 * - $messages: HTML for status and error messages. Should be displayed
 *   prominently.
 * - $tabs (array): Tabs linking to any sub-pages beneath the current page
 *   (e.g., the view and edit tabs when displaying a node).
 * - $action_links (array): Actions local to the page, such as 'Add menu' on the
 *   menu administration interface.
 * - $feed_icons: A string of all feed icons for the current page.
 * - $node: The node object, if there is an automatically-loaded node
 *   associated with the page, and the node ID is the second argument
 *   in the page's path (e.g. node/12345 and node/12345/revisions, but not
 *   comment/reply/12345).
 *
 * Regions:
 * - $page['help']: Dynamic help text, mostly for admin pages.
 * - $page['highlighted']: Items for the highlighted content region.
 * - $page['content']: The main content of the current page.
 * - $page['sidebar_first']: Items for the first sidebar.
 * - $page['sidebar_second']: Items for the second sidebar.
 * - $page['header']: Items for the header region.
 * - $page['footer']: Items for the footer region.
 *
 * @see bootstrap_preprocess_page()
 * @see template_preprocess()
 * @see template_preprocess_page()
 * @see bootstrap_process_page()
 * @see template_process()
 * @see html.tpl.php
 *
 * @ingroup templates
 */

global $language_base_url;

//// Loads static variable to hide title. Can be set in various panels.
//$hide_title = &drupal_static('isdm_hide_page_title');
global $user;
?>

<header id="top-header">
    <div class="container">
        <div class="row">
            <div class="col-12">
                <header role="banner" id="page-navigation">
                    <ul class="user-links">
                      <?php if (isset($first_name)){
                         print '<li>'. t("Welcome") . ' ' . $first_name .'<span>|</span> </li>';
                        }
                      ?>
					  <li>
                      <?php print block_render('privatemsg', 'privatemsg-new'); ?>
                      </li>
                      <?php if(($user->uid > 0) &&((in_array("Solutions Directory Editor",$user->roles)) ||!((in_array("Buyer",$user->roles) &&(in_array("Employee",$user->roles))) ||((in_array("Supply Chain",$user->roles) &&(in_array("Employee",$user->roles))))))){?>
                        <li><a href="<?php print $language_base_url;?>/member-resource-center"><?php print t("Manage Directory Content"); ?></a> <span>|</span> </li>
                      <?php }else{ ?>
                        <li> </li>
                      <?php } ?>
                        <li><?php print $primary_links ;?> </li>
                    </ul>
                    <span class="current-language"><?php global $language; print $language->name; ?></span>
                    <?php print block_render('locale', 'language'); ?>
                    <?php print render($page['navigation']); ?>
					
					
                </header> <!-- /#page-header -->
            </div>
        </div>
    </div>
	<?php if((in_array("Buyer",$user->roles) && in_array("Employee",$user->roles)) ||(in_array("Supply Chain",$user->roles) && in_array("Employee",$user->roles))){?>
<?php $block = block_load('block', '16');
					$output = drupal_render(_block_get_renderable_array(_block_render_blocks(array($block))));
					print $output; ?>
					<?php } ?>
</header>
<nav id="main-navigation">
    <div class="container">
        <div class="row">
            <div class="col-12">
                <section class="topbar">
<!--                    --><?php //print render($page['header']); ?>
<!--                    Megamenu Skeleton-->
                    <nav class="navbar yamm navbar-default " role="navigation">
                        <ul class="nav navbar-nav">
							<!--
                            <li class="dropdown">
                            <a href="< ?php print $language_base_url;?>/solutions-directory" class="dropdown-toggle" data-toggle="dropdown">< ?php print t('Solutions');?></a>
                                <ul class="dropdown-menu">
                                    <li>
                                        <div class="yamm-content">
                                            <div class="row">
                                                < ?php print render($page['header-one']); ?>
						< ?php print render($page['header-two']); ?>
                                            </div>
                                        </div>
                                    </li>
                                </ul>
                            </li>
							-->
							
							<li class="dropdown">
                                <a href="/solutions-directory/field_solution_type/embedded%20iot" class="dropdown-toggle" data-toggle="dropdown"><?php print t('Embedded IoT');?></a>
                                <ul class="dropdown-menu">
                                    <li>
                                        <div class="yamm-content">
                                            <div class="row">
												<div class="region region-header-one">
                                                <?php print render($page['eiot-header-msegments']); ?>
												</div>
												<div class="region region-header-two">
												<?php print render($page['eiot-header-categories']); ?>
												</div>
                                            </div>
                                        </div>
                                    </li>
                                </ul>
                            </li>
							
							<li class="dropdown">
                                <a href="/solutions-directory/field_solution_type/client" class="dropdown-toggle" data-toggle="dropdown"><?php print t('Client');?></a>
                                <ul class="dropdown-menu">
                                    <li>
                                        <div class="yamm-content">
                                            <div class="row">
												<div class="region region-header-one">
                                                <?php print render($page['client-header-msegments']); ?>
												</div>
												<div class="region region-header-two">
												<?php print render($page['client-header-categories']); ?>
												</div>
                                            </div>
                                        </div>
                                    </li>
                                </ul>
                            </li>
							
							<li class="dropdown">
                                <a href="/solutions-directory/field_solution_type/server" class="dropdown-toggle" data-toggle="dropdown"><?php print t('Server');?></a>
                                <ul class="dropdown-menu">
                                    <li>
                                        <div class="yamm-content">
                                            <div class="row">
												<div class="region region-header-one">
                                                <?php print render($page['server-header-msegments']); ?>
												</div>
												<div class="region region-header-two">
												<?php print render($page['server-header-categories']); ?>
												</div>
                                            </div>
                                        </div>
                                    </li>
                                </ul>
                            </li>
							
                            <li class="dropdown">
                                <a href="<?php print $language_base_url;?>/member-roster" class="dropdown-toggle" data-toggle="dropdown"><?php print t('Partners');?></a>
                                <ul class="dropdown-menu">
                                    <li>
                                        <div class="yamm-content">
                                            <div class="row">
                                                <?php print render($page['header-three']); ?> 
                                                <?php print render($page['header-four']); ?>
                                            </div>
                                        </div>
                                    </li>
                                </ul>
                            </li>
							
						<!--
						<li class="dropdown">
                                <a href="https://www.altera.com" class="dropdown-toggle" data-toggle="dropdown">< ?php print t('FPGA Products');?></a>
                                <ul class="dropdown-menu">
                                    <li>
                                        <div class="yamm-content">
                                            <div class="row">
                                                  < ?php print render($page['header-five']); ?>    
                                            </div>
                                        </div>
                                    </li>
                                </ul>
                        </li>
						-->
							
                        </ul>
                    </nav>
                </section>
                <?php print $search_box; ?>
            </div>
        </div>
    </div>
</nav>
