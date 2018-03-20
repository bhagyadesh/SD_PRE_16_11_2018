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

// Loads static variable to hide title. Can be set in various panels.
$hide_title = &drupal_static('isdm_hide_page_title');
?>
<footer class="global">
    <div class="container component" data-component-id="1" data-component="footer">
        <div class="row">
            <div class="col-3">
                <h4><?php print t('About');?></h4>
                <ul>
                    <li><a href="http://www.intel.com/content/www/us/en/company-overview/company-overview.html"><?php print t('Company Information');?></a></li>
                    <li><a href="http://www.intc.com/"><?php print t('Investor Relations');?></a></li>
                    <li><a href="http://www.intel.com/content/www/us/en/company-overview/contact-us.html"><?php print t('Contact Us');?></a></li>
                    <li><a href="http://newsroom.intel.com/"><?php print t('Newsroom');?></a></li>
                    <li><a href="http://www.intel.com/content/www/us/en/siteindex.html"><?php print t('Site Map');?></a></li>
                    <li><a href="http://www.intel.com/content/www/us/en/jobs/jobs-at-intel.html"><?php print t('Jobs');?></a></li>
                </ul>
            </div>
            <div class="col-3">
                <h4><?php print t('Support');?></h4>
                <ul>
                    <li><a href="http://www.intel.com/p/en_US/support/"><?php print t('Support Home');?></a></li>
                    <li><a href="https://downloadcenter.intel.com/"><?php print t('Download Center');?></a></li>
                    <li><a href="http://ark.intel.com/"><?php print t('Product Specifications (ARK)');?></a></li>
                </ul>
            </div>
            <div class="clearfix visible-xs"></div>
            <div class="col-3">
                <h4><?php print t('Legal');?></h4>
                <ul>
                    <li><a href="http://www.intel.com/content/www/us/en/legal/terms-of-use.html"><?php print t('Terms of Use');?></a></li>
                    <li><a href="http://www.intel.com/content/www/us/en/legal/trademarks.html"><?php print t('Trademarks');?></a></li>
                    <li><a href="http://www.intel.com/content/www/us/en/privacy/intel-privacy-notice.html"><?php print t('Privacy');?></a></li>
                    <li><a href="http://www.intel.com/content/www/us/en/privacy/intel-cookie-notice.html"><?php print t('Cookies</a>');?></li>
                    <li><a href="http://www.intel.com/content/www/us/en/policy/policy-human-trafficking-and-slavery.html"><?php print t('Supply Chain Transparency');?></a></li>
                </ul>
            </div>
            <div class="col-3">
                <h4><?php print t('Social');?></h4>
                <ul>
                    <li><a href="http://www.intel.com/content/www/us/en/blogs-communities-social.html" data-wap="{&quot;linktype&quot;:&quot;footersocial&quot;}">
                        <div class="imgLnk" style="background:url('https://solutionsdirectory.intel.com/sites/all/themes/custom/intel_isdm_bootstrap/images/social_sprite_smushed.png') 0 -70px;" data-offset-hover="-70px"></div><?php print t('Intel Communities');?></a></li>
                    <li><a href="https://twitter.com/intel" target="_blank" data-wap="{&quot;linktype&quot;:&quot;footersocial&quot;}">
                        <div class="imgLnk" style="background:url('https://solutionsdirectory.intel.com/sites/all/themes/custom/intel_isdm_bootstrap/images/social_sprite_smushed.png') 0 -700px;" data-offset-hover="-700px"></div><?php print t('Intel on Twitter');?></a></li>
                    <li><a href="https://www.facebook.com/Intel" target="_blank" data-wap="{&quot;linktype&quot;:&quot;footersocial&quot;}">
                        <div class="imgLnk" style="background:url('https://solutionsdirectory.intel.com/sites/all/themes/custom/intel_isdm_bootstrap/images/social_sprite_smushed.png') 0 -280px;" data-offset-hover="-280px"></div><?php print t('Intel on Facebook');?></a></li>
                    <li><a href="https://www.linkedin.com/company/intel-corporation" target="_blank" data-wap="{&quot;linktype&quot;:&quot;footersocial&quot;}">
                        <div class="imgLnk" style="background:url('https://solutionsdirectory.intel.com/sites/all/themes/custom/intel_isdm_bootstrap/images/social_sprite_smushed.png') 0 -420px;" data-offset-hover="-420px"></div><?php print t('Intel on LinkedIn');?></a></li>
                    <li><a href="http://www.instagram.com/intel" target="_blank" data-wap="{&quot;linktype&quot;:&quot;footersocial&quot;}">
                        <div class="imgLnk" style="background:url('https://solutionsdirectory.intel.com/sites/all/themes/custom/intel_isdm_bootstrap/images/social_sprite_smushed.png') 0 -350px;" data-offset-hover="-350px"></div><?php print t('Intel on Instagram');?></a></li>
                    <li><a href="https://www.youtube.com/user/channelintel?sub_confirmation=1" target="_blank" data-wap="{&quot;linktype&quot;:&quot;footersocial&quot;}">
                        <div class="imgLnk" style="background:url('https://solutionsdirectory.intel.com/sites/all/themes/custom/intel_isdm_bootstrap/images/social_sprite_smushed.png') 0 -840px;" data-offset-hover="-840px"></div><?php print t('Intel on YouTube');?></a></li>
                </ul> 
            </div>
        </div>
        <div class="row">
            <div id="legal-footer-copy" class="col-12">
                <figure class="brand"></figure>
                <span>&copy; <?php print t('Intel Corporation');?></span>
            </div>
        </div>
    </div>
</footer>
