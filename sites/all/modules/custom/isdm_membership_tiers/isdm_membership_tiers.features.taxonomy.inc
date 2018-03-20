<?php
/**
 * @file
 * isdm_membership_tiers.features.taxonomy.inc
 */

/**
 * Implements hook_taxonomy_default_vocabularies().
 */
function isdm_membership_tiers_taxonomy_default_vocabularies() {
  return array(
    'membership_tier' => array(
      'name' => 'Membership Tier',
      'machine_name' => 'membership_tier',
      'description' => 'Intel Partner Membership Tiers',
      'hierarchy' => '0',
      'module' => 'taxonomy',
      'weight' => '0',
      'language' => 'und',
      'i18n_mode' => '0',
      'rdf_mapping' => array(
        'rdftype' => array(
          0 => 'skos:ConceptScheme',
        ),
        'name' => array(
          'predicates' => array(
            0 => 'dc:title',
          ),
        ),
        'description' => array(
          'predicates' => array(
            0 => 'rdfs:comment',
          ),
        ),
      ),
      'checkbox_radio_tree_cardinality' => '-1',
    ),
  );
}
