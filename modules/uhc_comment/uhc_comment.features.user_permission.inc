<?php
/**
 * @file
 * uhc_comment.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_comment_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'access comments'.
  $permissions['access comments'] = array(
    'name' => 'access comments',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'administer comments'.
  $permissions['administer comments'] = array(
    'name' => 'administer comments',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'edit own comments'.
  $permissions['edit own comments'] = array(
    'name' => 'edit own comments',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'post comments'.
  $permissions['post comments'] = array(
    'name' => 'post comments',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'comment',
  );

  // Exported permission: 'skip comment approval'.
  $permissions['skip comment approval'] = array(
    'name' => 'skip comment approval',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'comment',
  );

  return $permissions;
}
