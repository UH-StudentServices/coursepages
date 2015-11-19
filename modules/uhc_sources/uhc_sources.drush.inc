<?php
/**
 * @file
 * Drush integration file.
 */

/**
 * Implements hook_drush_command().
 */
function uhc_sources_drush_command() {
  $items = array();

  $items['uhc-sync'] = array(
    'description' => 'Creates or updates course implementation page with given course implementation id.',
    'arguments' => array(
      'course-implementation-id' => dt('Required course implementation id. Usually digit number.'),
    ),
    'options' => array(
      'source' => 'One of following source systems: "rest" or "esb-oodi". By default "rest".',
      'course_number' => 'Course number to be updated along with course implementation. Required when using "esb-oodi" as source system.',
    ),
    'required-arguments' => TRUE,
    'examples' => array(
      'drush uhc-sync 107694052' => dt('Synchronizes course implementation 107694052 using REST. Creates it if does not exist.'),
      'drush uhc-sync 107694052 --course_number="590155" --source="esb-oodi"' => dt('Synchronizes course implementation 107694052 using esb-oodi. Creates it if does not exist.'),
    ),
  );

  return $items;
}

/**
 * Callback for command "drush uhc-sync".
 *
 * @param $course_implementation_id
 */
function drush_uhc_sources_uhc_sync($course_implementation_id) {

  // Ensure that we have proper source system defined
  $source_system = drush_get_option('source', 'rest');
  if (!in_array($source_system, array(UHC_SOURCE_REST, UHC_SOURCE_ESB_OODI))) {
    drush_set_error('Source system "' . $source_system . '" is not allowed.');
    exit(1);
  }

  // Synchronize the page with given source system
  $course_number = drush_get_option('course_number', NULL);
  if ($node = uhc_sources_sync_for_page($course_implementation_id, $course_number, $source_system)) {
    $uri = entity_uri('node', $node);
    $url = url($uri['path'], array('absolute' => TRUE));
    drush_print(dt('Synchronized course page to @url', array('@url' => $url)));
  }
  else {
    drush_set_error('Could not synchronize. See logs for more information.');
  }
}
