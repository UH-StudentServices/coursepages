<?php
/**
 * @file
 * uhc_course_tasks_and_material.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_course_tasks_and_material_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create course_task content'.
  $permissions['create course_task content'] = array(
    'name' => 'create course_task content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_task content'.
  $permissions['delete any course_task content'] = array(
    'name' => 'delete any course_task content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_task content'.
  $permissions['delete own course_task content'] = array(
    'name' => 'delete own course_task content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_task content'.
  $permissions['edit any course_task content'] = array(
    'name' => 'edit any course_task content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own course_task content'.
  $permissions['edit own course_task content'] = array(
    'name' => 'edit own course_task content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  return $permissions;
}
