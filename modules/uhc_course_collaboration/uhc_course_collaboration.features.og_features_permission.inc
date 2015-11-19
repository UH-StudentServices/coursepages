<?php
/**
 * @file
 * uhc_course_collaboration.features.og_features_permission.inc
 */

/**
 * Implements hook_og_features_default_permissions().
 */
function uhc_course_collaboration_og_features_default_permissions() {
  $permissions = array();

  // Exported og permission: 'node:course_implementation:add user'
  $permissions['node:course_implementation:add user'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:administer group'
  $permissions['node:course_implementation:administer group'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:approve and deny subscription'
  $permissions['node:course_implementation:approve and deny subscription'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:manage members'
  $permissions['node:course_implementation:manage members'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:manage permissions'
  $permissions['node:course_implementation:manage permissions'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:manage roles'
  $permissions['node:course_implementation:manage roles'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:subscribe'
  $permissions['node:course_implementation:subscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:subscribe without approval'
  $permissions['node:course_implementation:subscribe without approval'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:unsubscribe'
  $permissions['node:course_implementation:unsubscribe'] = array(
    'roles' => array(),
  );

  // Exported og permission: 'node:course_implementation:update group'
  $permissions['node:course_implementation:update group'] = array(
    'roles' => array(
      'Course administrator' => 'Course administrator',
      'Teacher' => 'Teacher',
    ),
  );

  return $permissions;
}
