<?php
/**
 * @file
 * uhc_teacher_tools.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function uhc_teacher_tools_user_default_roles() {
  $roles = array();

  // Exported role: course administrator.
  $roles['course administrator'] = array(
    'name' => 'course administrator',
    'weight' => 5,
  );

  // Exported role: teacher.
  $roles['teacher'] = array(
    'name' => 'teacher',
    'weight' => 4,
  );

  return $roles;
}
