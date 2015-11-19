<?php
/**
 * @file
 * uhc_course_collaboration.features.og_features_role.inc
 */

/**
 * Implements hook_og_features_default_roles().
 */
function uhc_course_collaboration_og_features_default_roles() {
  $roles = array();

  // Exported OG Role: 'node:course_implementation:Course administrator'.
  $roles['node:course_implementation:Course administrator'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'course_implementation',
    'name' => 'Course administrator',
  );

  // Exported OG Role: 'node:course_implementation:Student'.
  $roles['node:course_implementation:Student'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'course_implementation',
    'name' => 'Student',
  );

  // Exported OG Role: 'node:course_implementation:Teacher'.
  $roles['node:course_implementation:Teacher'] = array(
    'gid' => 0,
    'group_type' => 'node',
    'group_bundle' => 'course_implementation',
    'name' => 'Teacher',
  );

  return $roles;
}
