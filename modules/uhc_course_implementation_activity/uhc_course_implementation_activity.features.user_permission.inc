<?php
/**
 * @file
 * uhc_course_implementation_activity.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_course_implementation_activity_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'view rss_activity_feed_link on node'.
  $permissions['view rss_activity_feed_link on node'] = array(
    'name' => 'view rss_activity_feed_link on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  return $permissions;
}
