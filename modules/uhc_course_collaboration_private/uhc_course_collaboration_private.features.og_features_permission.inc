<?php
/**
 * @file
 * uhc_course_collaboration_private.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function uhc_course_collaboration_private_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:course_implementation:approve comment_node_course_implementation'
  $permissions['node:course_implementation:approve comment_node_course_implementation'] = array(
    'roles' => array(
      'Course administrator' => 'Course administrator',
      'Teacher' => 'Teacher',
    ),
  );

  // Exported og permission: 'node:course_implementation:delete comment_node_course_implementation'
  $permissions['node:course_implementation:delete comment_node_course_implementation'] = array(
    'roles' => array(
      'Course administrator' => 'Course administrator',
      'Teacher' => 'Teacher',
    ),
  );

  // Exported og permission: 'node:course_implementation:edit comment_node_course_implementation'
  $permissions['node:course_implementation:edit comment_node_course_implementation'] = array(
    'roles' => array(
      'Course administrator' => 'Course administrator',
      'Teacher' => 'Teacher',
    ),
  );

  // Exported og permission: 'node:course_implementation:edit own comment_node_course_implementation'
  $permissions['node:course_implementation:edit own comment_node_course_implementation'] = array(
    'roles' => array(
      'Course administrator' => 'Course administrator',
      'Teacher' => 'Teacher',
    ),
  );

  // Exported og permission: 'node:course_implementation:post comment_node_course_implementation'
  $permissions['node:course_implementation:post comment_node_course_implementation'] = array(
    'roles' => array(
      'Course administrator' => 'Course administrator',
      'Teacher' => 'Teacher',
    ),
  );

  // Exported og permission: 'node:course_implementation:view private uhc items'
  $permissions['node:course_implementation:view private uhc items'] = array(
    'roles' => array(
      'Course administrator' => 'Course administrator',
      'Student' => 'Student',
      'Teacher' => 'Teacher',
    ),
  );

  return $permissions;
}
