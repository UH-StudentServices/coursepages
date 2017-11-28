<?php
/**
 * @file
 * Integration file for drush command line tool.
 */

/**
 * Implements hook_drush_command().
 */
function uhc_course_collaboration_drush_command() {
  $items = array();
  $items['uhc-course-collaboration-cleanup-inactive-memberships'] = array(
    'description' => 'Cleans up all OG memberships of courses for inactive users.',
    'aliases' => array('uhc-cccim'),
    'options' => array(
      'threshold_days' => dt('Number of days, how new membership it requires for being accepted for removal. Default 14 days.'),
      'limit' => dt('How many memberships are removed in this run? Default 50.'),
    ),
    'callback' => 'uhc_course_collaboration_cleanup_inactive_memberships',
  );
  return $items;
}

/**
 * Drush command callback for cleaning up all inactive users's memberships. All
 * user memberships are automatically set during login process anyway.
 */
function uhc_course_collaboration_cleanup_inactive_memberships() {

  // Query top 50 oldest memberships that are created before two weeks ago.
  $limit = (int) drush_get_option('limit', 50);
  $threshold_days = (int) drush_get_option('threshold_days', 14);

  // Deleting each membership, should delete their grants as well.
  $count = 0;
  foreach (uhc_course_collaboration_get_cleanable_membership_ids($threshold_days, $limit) as $id) {
    og_membership_delete($id);
    drush_print('Deleted membership ID ' . $id);
    $count++;
  }
  drush_print('Deleted ' . $count . ' memberships.');

}
