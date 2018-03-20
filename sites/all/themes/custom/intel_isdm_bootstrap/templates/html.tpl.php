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
 <meta http-equiv="X-UA-Compatible" content="IE=edge">
 <?php /* <meta name="viewport" content="width=device-width, initial-scale=1.0">*/ ?>
  <?php print $head; ?>
  <title><?php print $head_title; ?></title>
  <link rel="stylesheet" href="/sites/all/themes/custom/intel_isdm_bootstrap/css/bootstrap.min.css" />
  <?php print $styles; ?>
  <!-- HTML5 element support for IE6-8 -->
  <!--[if lt IE 9]>
    <script src="https://oss.maxcdn.com/libs/html5shiv/3.7.0/html5shiv.js"></script> 
  <![endif]-->
 
<script src="https://code.jquery.com/jquery-1.12.4.js"></script>
  <script src="https://code.jquery.com/ui/1.12.1/jquery-ui.js"></script>
  <script>
  $( function() {
    $( "#tabssd" ).tabs();
  } );
  </script>
 <?php print $scripts; ?>

</head>
<body<?php print $body_attributes; ?>>

<!--
Start of DoubleClick Floodlight Tag: Please do not remove
Activity name of this tag: solutionsdirectory.intel.com_contact
URL of the webpage where the tag is expected to be placed: https://solutionsdirectory.intel.com
This tag must be placed between the <body> and </body> tags, as close as possible to the opening tag.
Creation Date: 03/02/2017
-->
<script type=""text/javascript"">
var axel = Math.random() + """";
var a = axel * 10000000000000;
document.write('<iframe src=""https://5969203.fls.doubleclick.net/activityi;src=5969203;type=soldir;cat=sdcont;dc_lat=;dc_rdid=;tag_for_child_directed_treatment=;ord=1;num=' + a + '?"" width=""1"" height=""1"" frameborder=""0"" style=""display:none""></iframe>');
</script>
<noscript>
<iframe src=""https://5969203.fls.doubleclick.net/activityi;src=5969203;type=soldir;cat=sdcont;dc_lat=;dc_rdid=;tag_for_child_directed_treatment=;ord=1;num=1?"" width=""1"" height=""1"" frameborder=""0"" style=""display:none""></iframe>
</noscript>
<!-- End of DoubleClick Floodlight Tag: Please do not remove -->
 
<!--
Start of DoubleClick Floodlight Tag: Please do not remove
Activity name of this tag: solutionsdirectory.intel.com_quote
URL of the webpage where the tag is expected to be placed: https://solutionsdirectory.intel.com
This tag must be placed between the <body> and </body> tags, as close as possible to the opening tag.
Creation Date: 03/02/2017
-->
<script type=""text/javascript"">
var axel = Math.random() + """";
var a = axel * 10000000000000;
document.write('<iframe src=""https://5969203.fls.doubleclick.net/activityi;src=5969203;type=soldir;cat=sdquot;dc_lat=;dc_rdid=;tag_for_child_directed_treatment=;ord=1;num=' + a + '?"" width=""1"" height=""1"" frameborder=""0"" style=""display:none""></iframe>');
</script>
<noscript>
<iframe src=""https://5969203.fls.doubleclick.net/activityi;src=5969203;type=soldir;cat=sdquot;dc_lat=;dc_rdid=;tag_for_child_directed_treatment=;ord=1;num=1?"" width=""1"" height=""1"" frameborder=""0"" style=""display:none""></iframe>
</noscript>
<!-- End of DoubleClick Floodlight Tag: Please do not remove -->

 <div id="skip-link">
    <a href="#main-content" class="element-invisible element-focusable"><?php print t('Skip to main content'); ?></a>
  </div>

  <?php print $page_top; ?>
  <?php print $page; ?>
  <?php include('footer.tpl.php'); ?>
  <?php print $page_bottom; ?>

</body>
</html>