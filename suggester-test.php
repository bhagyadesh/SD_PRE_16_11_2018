<?php

	ini_set("allow_url_fopen", 1);

	$term = trim($_GET['term']);
	
	$term = str_replace(' ', '+', $term);
	
	$term = strtolower ( trim($term) );	

	// $termQuery ='http://45.79.104.195:8983/solr/intel_isv_dev1/terms?wt=json&terms.fl=spell&terms.limit=10&terms.sort=index&terms.prefix='.$term;

	// $termQuery = 'http://45.79.104.195:8983/solr/intel_isv_dev1/select?facet=true&facet.field=spell&facet.sort=index&facet.prefix=dell%20power&facet.limit=15&fq=sm_search_api_language:en&facet.mincount=1&rows=0&wt=json';
	
	// $termQuery = 'http://45.79.104.195:8983/solr/intel_isv_dev1/select?facet=true&fq=index_id%3A(solutions+OR+companies)&rows=0&facet.field=ss_title&facet.field=tm_title&facet.limit=10&fq=sm_search_api_language:en&facet.prefix=dell&facet.mincount=1&facet.sort=index&wt=json';
	
	// $termQuery = 'http://45.79.104.195:8983/solr/intel_isv_dev1/select?facet.prefix='.$term.'&facet=true&fq=index_id%3Asolutions&rows=0&facet.field=spellb&facet.field=spellc&facet.limit=10&fq=sm_search_api_language:en&facet.mincount=1&facet.sort=index';
	
	// $termQuery ='http://45.79.104.195:8983/solr/intel_isv_dev1/select?facet.prefix='.$term.'&facet=true&fq=index_id%3Asolutions&rows=0&facet.field=spellb&facet.field=spellc&facet.limit=10&fq=sm_search_api_language:en&facet.mincount=1&facet.sort=index&wt=json';
	
	$termQuery = 'http://50.116.5.118:8983/solr/intel_isv_dev1/select?facet.prefix='.$term.'&facet=true&fq=index_id%3Asolutions&rows=0&facet.field=spellb&facet.field=spellc&facet.limit=10&fq=sm_search_api_language:en&facet.mincount=1&facet.sort=index&wt=json';

	$content = file_get_contents($termQuery);
	$json = json_decode($content, true);
	
	
	echo "<pre>";
	//print_r($json['facet_counts']['facet_fields']);
	echo "<b>Companies</b> <br>";
	print_r($json['facet_counts']['facet_fields']['spellb']);
	echo "<hr>";
	echo "<b>Products</b> <br>";	
	print_r($json['facet_counts']['facet_fields']['spellc']); 
	echo "<hr>";
	echo "</pre>";
	// exit;
	
	
	$cnt1=0;
	$cnt2=0;
	$output_array=array();
	
	foreach($json['facet_counts']['facet_fields']['spellb'] as $item) {
		if (($cnt1 % 2) == 0 && $item!='')
			{ 
				//echo $item;
				$output_array[$item] =  $item;
			}
		$cnt1++;
	}
	
	foreach($json['facet_counts']['facet_fields']['spellc'] as $item) {
		if (($cnt2 % 2) == 0 && $item!='')
			{ 
				//echo $item;
				$output_array[$item] =  $item;
			}
		$cnt2++;
	}
	
	echo json_encode($output_array);

?>