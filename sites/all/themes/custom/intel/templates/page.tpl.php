<?php
/**
 * @file
 * Alpha's theme implementation to display a single Drupal page.
 */
?>
<div<?php print $attributes; ?>>
  <?php
  // Don't show header if user is Admin (UID=1)
  if ($user->uid != 1) {
  ?>
  <!--header--><!--GAATversion='50recode' date='06/07/2011 15:04:57' version='1':CharacterEncoding:utf8--><script type="text/javascript" src="http://www.intel.com/sites/js/INTEL.js"> </script><script type="text/javascript">
    /*<![CDATA[*/
    document.write('<style type="text/css">#recode50header {height:91px;visibility:hidden;}#smallfootprint-header,#smallfootprint-footer {display:none !important}</style>');
    INTELNAV = window.INTELNAV || {};
    INTELNAV.renderSettings={pageWidth:"w1024",renderMode:"standards",textDirection:"ltr",protocol:"http",culture:"en_US",assetPathRoot:"http://www.intel.com",buildType:"html",OutputId:"gh_logo-only"};
    /*]]>*/</script><div id="smallfootprint-header"><a class="gaat40-logo" href="http://www.intel.com/index.htm" title="Logo - Intel"><img alt="Logo - Intel" height="50" src="http://www.intel.com/sites/sitewide/HAT/50recode/pix/main-logo.png" width="77" /></a><form action="http://search.intel.com/default.aspx" id="user-bar-searchbox-form" method="get" name="user-bar-searchbox-form"><fieldset><legend></legend><label for="input-search">Search</label><input id="input-search" name="q" type="text" /><input id="input-market" name="c" type="hidden" value="en_US" /><input id="input-method" name="method" type="hidden" value="text" /><input id="input-submit" name="input-submit" type="submit" value="Search" /></fieldset></form></div><div id="recode50header">&nbsp;</div><script type="text/javascript" src="http://www.intel.com/sites/sitewide/hat/50recode/js/headerChooser.js"> </script>
  <!--/header-->
  <?php
  }
  ?>
  <?php if (isset($page['header'])) : ?>
    <?php print render($page['header']); ?>
  <?php endif; ?>

  <?php if (isset($page['content'])) : ?>
    <?php print render($page['content']); ?>
  <?php endif; ?>

  <?php if (isset($page['footer'])) : ?>
    <?php print render($page['footer']); ?>
  <?php endif; ?>
  <?php
  // Don't show footer if user is Admin (UID=1)
  if ($user->uid != 1) {
  ?>
  <!--footer-->
    <!--GAATversion='50recode' date='06/07/2011 15:04:57' version='1':CharacterEncoding:utf8-->
    <script type="text/javascript">
    /*<![CDATA[*/
    INTELNAV = window.INTELNAV || {};
    INTELNAV.renderSettingsFooter={OutputId:"gf_default"};
    /*]]>*/</script>
    <div id="smallfootprint-footer"><ul><li>Intel Corporation</li><li><a href="http://www.intel.com/sites/sitewide/en_US/termsofuse.htm">Terms of Use</a></li><li><a href="http://www.intel.com/sites/sitewide/en_US/tradmarx.htm">*Trademarks</a></li><li><a href="http://www.intel.com/sites/sitewide/en_US/privacy/privacy.htm">Privacy</a></li></ul></div>
    <div id="recode50footer"> </div>
  <!--/footer-->
  <?php
  }
  ?>
</div>
