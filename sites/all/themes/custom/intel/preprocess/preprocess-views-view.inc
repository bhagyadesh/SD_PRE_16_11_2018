<?php

/**
 * @file
 * Views level preprocess functions.
 */

/**
 * Modify the 'more link' to append the company (nid) and category (tid).
 * Be sure to pull in the correct tid because facets are sorted by English.
 */
function intel_alpha_preprocess_views_view(&$vars) {
  if ($vars['view']->name == 'company_solutions') {
    $node = menu_get_object();
    if($node->tnid == 0) {
      $company = $node->nid;
    } else {
      $company = $node->tnid;
    }
    switch ($vars['view']->query->pager->display->display_options['title']) {
      case 'Products & Components':
        $term_obj = taxonomy_get_term_by_name('Products & Components');
        foreach ($term_obj as $tid => $obj) {
          $category_tid = $obj->tid;
          $category_name = str_replace(' & ', '-', strtolower($obj->name));
        }
        $vars['more']  = '<div class="more-link">';
        $vars['more'] .= l(t('View All'), "solutions-directory/categories/$category_tid/company/$company");
        $vars['more'] .= '</div>';
        break;
      case 'Services':
        $term_obj = taxonomy_get_term_by_name('Services');
        foreach ($term_obj as $tid => $obj) {
          $category_tid = $obj->tid;
          $category_name = strtolower($obj->name);
        }
        $vars['more']  = '<div class="more-link">';
        $vars['more'] .= l(t('View All'), "solutions-directory/categories/$category_tid/company/$company");
        $vars['more'] .= '</div>';
        break;
      case 'Systems':
        $term_obj = taxonomy_get_term_by_name('Systems');
        foreach ($term_obj as $tid => $obj) {
          $category_tid = $obj->tid;
          $category_name = strtolower($obj->name);
        }
        $vars['more']  = '<div class="more-link">';
        $vars['more'] .= l(t('View All'), "solutions-directory/categories/$category_tid/company/$company");
        $vars['more'] .= '</div>';
        break;
    }
  }
}
