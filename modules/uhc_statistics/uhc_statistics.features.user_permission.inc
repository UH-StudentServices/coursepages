<?php
/**
 * @file
 * uhc_statistics.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_statistics_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access utilisation statistics'.
  $permissions['access utilisation statistics'] = array(
    'name' => 'access utilisation statistics',
    'roles' => array(
      'administrator' => 'administrator',
      'restricted administrator' => 'restricted administrator',
    ),
    'module' => 'uhc_statistics',
  );

  return $permissions;
}
