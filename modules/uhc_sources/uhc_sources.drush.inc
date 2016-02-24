<?php
/**
 * @file
 * Drush integration file.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
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
  $items['uhc-sources-handle-stubs'] = array(
    'description' => 'Imports all known created course stubs.',
    'callback' => 'uhc_sources_handle_stubs',
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

/**
 * Callback for handling course and course implementation stubs.
 *
 * @param int $calls
 *   Number of calls for self-protecting for infinite recursion.
 */
function uhc_sources_handle_stubs($calls = 0) {
  // Always increase number of calls.
  $calls++;

  // Construct collections for holding specified types of items
  $items = array(
    'learningopportunity' => array(),
    'courseunitrealisation' => array(),
  );

  // Specify migration attribute for each type of items
  $migration_attributes = array(
    'learningopportunity' => array(
      'machine_name' => 'CourseNode',
      'class_name' => 'CourseNodeMigration',
    ),
    'courseunitrealisation' => array(
      'machine_name' => 'CourseImplementationNode',
      'class_name' => 'CourseImplementationNodeMigration',
    ),
  );

  // Ensure that all migrations are available
  foreach ($migration_attributes as $type => $attributes) {
    /** @var Migration $migration */
    $migration = Migration::getInstance($attributes['machine_name'], $attributes['class_name']);
    if ($migration->getStatus() != MigrationBase::STATUS_IDLE) {
      drush_set_error($attributes['machine_name'] . ' was not available for handling stubs');
      return;
    }
  }

  // Get stub handling queue, so we can loop them through and aggregate them
  /** @var DrupalReliableQueueInterface $queue */
  $queue = DrupalQueue::get('uhc_sources_stub_handling', TRUE);

  // Aggregate items and ensure they're valid
  while ($item = $queue->claimItem(300)) {

    // Ensure that we're expecting certain types of items
    if (!isset($items[$item->data['type']])) {
      watchdog('uhc_sources', 'Unknown type of item for stub handling. @item', array('@item' => print_r($item, 1)), WATCHDOG_WARNING);
      continue;
    }

    // If does not exist or is empty, then leave log entry
    if (empty($item->data['id'])) {
      watchdog('uhc_sources', 'No ID found for item on stub handling. @item', array('@item' => print_r($item, 1)), WATCHDOG_WARNING);
      continue;
    }

    // Add item to the collection if it's not already there
    $found = FALSE;
    foreach ($items[$item->data['type']] as $aggregated_item) {
      if ($aggregated_item->data['type'] == $item->data['type'] &&
        $aggregated_item->data['id'] == $item->data['id']) {
        $found = TRUE;
        break;
      }
    }
    if (!$found) {
      $items[$item->data['type']][] = $item;
    }

  }

  // Migrate aggregated items/ids
  $count = 0;
  foreach ($migration_attributes as $type => $attributes) {
    /** @var Migration $migration */
    $ids = array();
    foreach ($items[$type] as $item) {
      $ids[] = $item->data['id'];
    }
    $migration = Migration::getInstance($attributes['machine_name'], $attributes['class_name'], array('predefined_ids' => $ids));
    $status = $migration->processImport(array('idlist' => implode(',', $ids), 'force' => TRUE));
    if ($status == MigrationBase::RESULT_COMPLETED) {
      // Delete items from queue after we confirmed that batch is completed.
      foreach ($items[$type] as $item) {
        $count++;
        $queue->deleteItem($item);
      }
    }
    else {
      watchdog('uhc_sources', 'Was not able to migrate handled stubs for type @type. Got migration status @status', array('@type' => $type, '@status' => $status), WATCHDOG_WARNING);
    }
  }

  // Just some output to know how many items were processed
  drush_print('Processed ' . $count . ' items');

  // Do extra round looking for potentially added stubs until we don't have no
  // items processed or we have called ourself more than five times.
  if ($count != 0 && $calls <= 5) {
    uhc_sources_handle_stubs($calls);
  }
}
