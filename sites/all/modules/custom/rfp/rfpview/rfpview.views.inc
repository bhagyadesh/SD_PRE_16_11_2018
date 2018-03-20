<?php

function rfpview_views_query_alter(&$view, &$query) {

  if($view->name == 'matchedbuilder') {

    //dpm($query);
    //at this point find the right part to alter and adapt following line
    //$query->where[0]['type'] = 'OR';

  }
}