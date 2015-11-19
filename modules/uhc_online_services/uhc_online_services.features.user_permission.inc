<?php
/**
 * @file
 * uhc_online_services.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_online_services_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create online_service content'.
  $permissions['create online_service content'] = array(
    'name' => 'create online_service content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any online_service content'.
  $permissions['delete any online_service content'] = array(
    'name' => 'delete any online_service content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own online_service content'.
  $permissions['delete own online_service content'] = array(
    'name' => 'delete own online_service content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any online_service content'.
  $permissions['edit any online_service content'] = array(
    'name' => 'edit any online_service content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own online_service content'.
  $permissions['edit own online_service content'] = array(
    'name' => 'edit own online_service content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  return $permissions;
}
