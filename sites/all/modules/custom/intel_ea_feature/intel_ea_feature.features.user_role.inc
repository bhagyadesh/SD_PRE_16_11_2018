<?php
/**
 * @file
 * intel_ea_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function intel_ea_feature_user_default_roles() {
  $roles = array();

  // Exported role: Administrator.
  $roles['Administrator'] = array(
    'name' => 'Administrator',
    'weight' => '26',
  );

  // Exported role: Alliance Marketing Expert.
  $roles['Alliance Marketing Expert'] = array(
    'name' => 'Alliance Marketing Expert',
    'weight' => '11',
  );

  // Exported role: Alliance Staff Admin.
  $roles['Alliance Staff Admin'] = array(
    'name' => 'Alliance Staff Admin',
    'weight' => '2',
  );

  // Exported role: Alliance Staff Employee.
  $roles['Alliance Staff Employee'] = array(
    'name' => 'Alliance Staff Employee',
    'weight' => '3',
  );

  // Exported role: Co-Marketing (MDF) Contact.
  $roles['Co-Marketing (MDF) Contact'] = array(
    'name' => 'Co-Marketing (MDF) Contact',
    'weight' => '16',
  );

  // Exported role: Co-Marketing Affiliate.
  $roles['Co-Marketing Affiliate'] = array(
    'name' => 'Co-Marketing Affiliate',
    'weight' => '19',
  );

  // Exported role: Co-Marketing Associate.
  $roles['Co-Marketing Associate'] = array(
    'name' => 'Co-Marketing Associate',
    'weight' => '18',
  );

  // Exported role: Co-Marketing Distributor.
  $roles['Co-Marketing Distributor'] = array(
    'name' => 'Co-Marketing Distributor',
    'weight' => '21',
  );

  // Exported role: Co-Marketing General.
  $roles['Co-Marketing General'] = array(
    'name' => 'Co-Marketing General',
    'weight' => '20',
  );

  // Exported role: Co-Marketing Premier.
  $roles['Co-Marketing Premier'] = array(
    'name' => 'Co-Marketing Premier',
    'weight' => '17',
  );

  // Exported role: Executive.
  $roles['Executive'] = array(
    'name' => 'Executive',
    'weight' => '5',
  );

  // Exported role: Intel Admin.
  $roles['Intel Admin'] = array(
    'name' => 'Intel Admin',
    'weight' => '6',
  );

  // Exported role: Intel Employee.
  $roles['Intel Employee'] = array(
    'name' => 'Intel Employee',
    'weight' => '7',
  );

  // Exported role: Intel Field Applications Engineer.
  $roles['Intel Field Applications Engineer'] = array(
    'name' => 'Intel Field Applications Engineer',
    'weight' => '8',
  );

  // Exported role: Intel Field Sales Engineer.
  $roles['Intel Field Sales Engineer'] = array(
    'name' => 'Intel Field Sales Engineer',
    'weight' => '9',
  );

  // Exported role: Intel Market Development Manager.
  $roles['Intel Market Development Manager'] = array(
    'name' => 'Intel Market Development Manager',
    'weight' => '10',
  );

  // Exported role: Leads Contact.
  $roles['Leads Contact'] = array(
    'name' => 'Leads Contact',
    'weight' => '14',
  );

  // Exported role: Non-Alliance Employee.
  $roles['Non-Alliance Employee'] = array(
    'name' => 'Non-Alliance Employee',
    'weight' => '28',
  );

  // Exported role: Primary Admin Contact.
  $roles['Primary Admin Contact'] = array(
    'name' => 'Primary Admin Contact',
    'weight' => '12',
  );

  // Exported role: Primary Co-Marketing (MDF) Contact.
  $roles['Primary Co-Marketing (MDF) Contact'] = array(
    'name' => 'Primary Co-Marketing (MDF) Contact',
    'weight' => '15',
  );

  // Exported role: Primary Contact.
  $roles['Primary Contact'] = array(
    'name' => 'Primary Contact',
    'weight' => '22',
  );

  // Exported role: Primary Leads Contact.
  $roles['Primary Leads Contact'] = array(
    'name' => 'Primary Leads Contact',
    'weight' => '13',
  );

  // Exported role: Primary Marketing Contact.
  $roles['Primary Marketing Contact'] = array(
    'name' => 'Primary Marketing Contact',
    'weight' => '23',
  );

  // Exported role: Primary Sales Contact.
  $roles['Primary Sales Contact'] = array(
    'name' => 'Primary Sales Contact',
    'weight' => '24',
  );

  // Exported role: Solutions Directory Editor.
  $roles['Solutions Directory Editor'] = array(
    'name' => 'Solutions Directory Editor',
    'weight' => '25',
  );

  return $roles;
}
