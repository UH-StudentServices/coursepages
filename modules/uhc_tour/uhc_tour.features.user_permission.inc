<?php
/**
 * @file
 * uhc_tour.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_tour_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'administer tour triggering'.
  $permissions['administer tour triggering'] = array(
    'name' => 'administer tour triggering',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'uhc_tour',
  );

  return $permissions;
}
