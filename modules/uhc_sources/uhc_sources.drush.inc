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

  $items['uhc-process-queue'] = array(
    'description' => 'Processes queue items that are up to update/delete learningopportunities or courseunitrealisations.',
    'options' => array(
      'limit-seconds' => 'Set how many seconds we allow this process to run. Must be greated than 10. Be default 300.',
      'batch-size' => 'The size of the batch that triggers one round of migration import while looping through items. By default 25.',
      'action' => 'If set, processing filters items that only matches with this action.',
      'type' => 'If set, processing filters items that only matches with this type.',
    ),
    'examples' => array(
      'drush uhc-process-queue' => dt('Processes all types and actions in 25 batch size until the end of items or 5min of processing time.'),
      'drush uhc-process-queue --action=delete' => dt('Processes all delete actions in 25 batch size until the end of items or 5min of processing time.'),
      'drush uhc-process-queue --type=update' => dt('Processes all update actions in 25 batch size until the end of items or 5min of processing time.'),
      'drush uhc-process-queue --type=delete --batch-size=5' => dt('Processes all delete actions in 5 batch size until the end of items or 5min of processing time.'),
      'drush uhc-process-queue --type=delete --batch-size=100 --limit-seconds=15' => dt('Processes all delete actions in 100 batch size until the end of items or 15 seconds of processing time.'),
      'drush uhc-process-queue --limit-seconds=60' => dt('Processes all actions in 25 batch size until the end of items or 1min of processing time.'),
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

/**
 * Callback for command "drush uhc-process-queue".
 * @see _uhc_course_implementation_source_delete_item()
 */
function drush_uhc_sources_uhc_process_queue() {

  // Limits must be an integer and greater than 10.
  $limit_seconds = (int) drush_get_option('limit-seconds', 300);
  if ($limit_seconds <= 10) {
    drush_set_error('Limit seconds must be greater than 10 seconds.');
    return;
  }

  // Batch size must be an integer and greated than 0
  $batch_size = (int) drush_get_option('batch-size', 25);
  if ($batch_size <= 0) {
    drush_set_error('Batch size must be greater than 0.');
    return;
  }

  // This is the queue we're proessing
  $queue = new UHOodiPrioritisedQueue();

  // Loop until overtime or end of queue
  $release_items = array();
  $batches = array(
    'learningopportunity' => array(
      'items' => array(),
      'update callback' => '_uhc_course_source_process_update_batch',
    ),
    'courseunitrealisation' => array(
      'items' => array(),
      'update callback' => '_uhc_course_implementation_source_process_update_batch',
      'delete callback' => '_uhc_course_implementation_source_delete_item',
    ),
  );
  while (time() < (REQUEST_TIME+$limit_seconds) && $item = $queue->claimItem($limit_seconds)) {

    // Apply filtering
    $action = drush_get_option('action', NULL);
    if (!is_null($action) && !$item->isAction($action)) {
      $release_items[] = $item;
      continue;
    }
    $type = drush_get_option('type', NULL);
    if (!is_null($type) && !$item->isType($type)) {
      $release_items[] = $item;
      continue;
    }

    // After passing all the filters
    switch ($item->getAction()) {
      case 'update':
        if (empty($batches[$item->getType()]['update callback'])) {
          throw new \LogicException('Update callback required in queue processing loop.');
        }
        $function = $batches[$item->getType()]['update callback'];

        // Move to processable list from the queue
        if (isset($batches[$item->getType()])) {
          $batches[$item->getType()]['items'][] = $item;
          $queue->deleteItem($item);
        }

        // Trigger import if batch size exceeded
        if (count($batches[$item->getType()]['items']) >= $batch_size) {
          // Update callback are called with multiple IDs.
          $function($batches[$item->getType()]['items']);
          $batches[$item->getType()]['items'] = array();
        }
        break;
      case 'delete':
        $function = isset($batches[$item->getType()]['delete callback']) ? $batches[$item->getType()]['delete callback'] : '';
        // Delete callback are called with a single ID.
        if (!empty($function) && function_exists($function)) {
          $function($item->getId());
          $queue->deleteItem($item);
        }
        break;
    }
  }

  // Flush loop leftovers
  foreach ($batches as $batch) {
    if (empty($batch['update callback'])) {
      throw new \LogicException('Update callback required in queue processing loop.');
    }
    $function = $batch['update callback'];
    if (count($batch['items']) > 0 && function_exists($function)) {
      $function($batch['items']);
    }
  }

  // Release specified items
  foreach ($release_items as $release_item) {
    $queue->releaseItem($release_item);
  }

}
