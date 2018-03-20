<?php
/**
 * @file
 * Default theme implementation to display the basic html structure of a single
 * Drupal page.
 *
 * Variables:
 * - $css: An array of CSS files for the current page.
 * - $language: (object) The language the site is being displayed in.
 *   $language->language contains its textual representation.
 *   $language->dir contains the language direction. It will either be 'ltr' or
 *   'rtl'.
 * - $html_attributes:  String of attributes for the html element. It can be
 *   manipulated through the variable $html_attributes_array from preprocess
 *   functions.
 * - $html_attributes_array: An array of attribute values for the HTML element.
 *   It is flattened into a string within the variable $html_attributes.
 * - $body_attributes:  String of attributes for the BODY element. It can be
 *   manipulated through the variable $body_attributes_array from preprocess
 *   functions.
 * - $body_attributes_array: An array of attribute values for the BODY element.
 *   It is flattened into a string within the variable $body_attributes.
 * - $rdf_namespaces: All the RDF namespace prefixes used in the HTML document.
 * - $grddl_profile: A GRDDL profile allowing agents to extract the RDF data.
 * - $head_title: A modified version of the page title, for use in the TITLE
 *   tag.
 * - $head_title_array: (array) An associative array containing the string parts
 *   that were used to generate the $head_title variable, already prepared to be
 *   output as TITLE tag. The key/value pairs may contain one or more of the
 *   following, depending on conditions:
 *   - title: The title of the current page, if any.
 *   - name: The name of the site.
 *   - slogan: The slogan of the site, if any, and if there is no title.
 * - $head: Markup for the HEAD section (including meta tags, keyword tags, and
 *   so on).
 * - $styles: Style tags necessary to import all CSS files for the page.
 * - $scripts: Script tags necessary to load the JavaScript files and settings
 *   for the page.
 * - $page_top: Initial markup from any modules that have altered the
 *   page. This variable should always be output first, before all other dynamic
 *   content.
 * - $page: The rendered page content.
 * - $page_bottom: Final closing markup from any modules that have altered the
 *   page. This variable should always be output last, after all other dynamic
 *   content.
 * - $classes String of classes that can be used to style contextually through
 *   CSS.
 *
 * @see bootstrap_preprocess_html()
 * @see template_preprocess()
 * @see template_preprocess_html()
 * @see template_process()
 *
 * @ingroup templates
 */

global $language;
?><!DOCTYPE html>
<html<?php print $html_attributes;?><?php print $rdf_namespaces;?>>
<head>
  <link rel="profile" href="<?php print $grddl_profile; ?>" />
  <meta charset="utf-8">
  <?php /* <meta name="viewport" content="width=device-width, initial-scale=1.0">*/ ?>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <link rel="stylesheet" href="/sites/all/themes/custom/intel_isdm_bootstrap/css/bootstrap.min.css" />
  <?php print $styles; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
  <script src="//html5shiv.googlecode.com/svn/trunk/html5.js"></script>
  <![endif]-->
  <?php print $scripts; ?>
  <script src="//code.jquery.com/ui/1.11.4/jquery-ui.js"></script>
</head>
<body class="maintenance-mode">
    <div id="skip-link">
        <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
    </div>
    <div id="page">
        <header id="top-header">
            <div class="container">
                <div class="row">
                    <div class="col-12">
                        <header role="banner" id="page-navigation">
                            <section id="block-delta-blocks-branding" class="block block-delta-blocks clearfix">
                                <div class="logo-img">
                                  <a href="http://www.intel.com" id="logo" title="<?php print t('Return to the Solutions Directory home page');?>">
                                    <img typeof="foaf:Image" class="img-responsive" src="/sites/all/themes/custom/intel_isdm_bootstrap/logo.png" alt="<?php print t('Solutions Directory');?>">
                                  </a>
                                </div>
                              <hgroup class="site-name-slogan">
                                <h1 class="site-name">
                                  <a href="/" title="<?php print t('Return to the Solutions Directory home page');?>">
                                    <span><?php t('Solutions Directory');?></span>
                                  </a>
                                </h1>
                              </hgroup>
                            </section>
                        </header> <!-- /#page-header -->
                    </div>
                </div>
            </div>
        </header>
        <div id="maintenance-container">
            <div class="container">
                <div id="main" class="text-center">
                    <?php if (!empty($messages)): print $messages; endif; ?>
                    <?php if (!empty($title)): ?><h2 class="title" id="page-title"><?php print t("We’ll be back shortly.");?></h2><?php endif; ?>
                    <?php print $content; ?>
                </div> 
            </div> <!-- /container -->
        </div>
        <?php include('footer.tpl.php'); ?>
    </div> <!-- /page -->
</body>
</html>
