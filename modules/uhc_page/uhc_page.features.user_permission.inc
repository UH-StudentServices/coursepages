<?php
/**
 * @file
 * uhc_page.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_page_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create portal_page content'.
  $permissions['create portal_page content'] = array(
    'name' => 'create portal_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any portal_page content'.
  $permissions['delete any portal_page content'] = array(
    'name' => 'delete any portal_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own portal_page content'.
  $permissions['delete own portal_page content'] = array(
    'name' => 'delete own portal_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any portal_page content'.
  $permissions['edit any portal_page content'] = array(
    'name' => 'edit any portal_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own portal_page content'.
  $permissions['edit own portal_page content'] = array(
    'name' => 'edit own portal_page content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  return $permissions;
}
