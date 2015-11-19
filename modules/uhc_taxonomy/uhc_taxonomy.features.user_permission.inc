<?php
/**
 * @file
 * uhc_taxonomy.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_taxonomy_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'add terms in type_of_teaching'.
  $permissions['add terms in type_of_teaching'] = array(
    'name' => 'add terms in type_of_teaching',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'delete terms in type_of_teaching'.
  $permissions['delete terms in type_of_teaching'] = array(
    'name' => 'delete terms in type_of_teaching',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in type_of_teaching'.
  $permissions['edit terms in type_of_teaching'] = array(
    'name' => 'edit terms in type_of_teaching',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'translate taxonomy_term entities'.
  $permissions['translate taxonomy_term entities'] = array(
    'name' => 'translate taxonomy_term entities',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'entity_translation',
  );

  return $permissions;
}
