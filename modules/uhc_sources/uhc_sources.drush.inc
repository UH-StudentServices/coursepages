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

        // Move to processable list from the queue
        if (isset($batches[$item->getType()])) {
          $batches[$item->getType()]['items'][] = $item;
        }

        // Trigger import if batch size exceeded
        if (_uhc_sources_uhc_batch_exceeded($batches, $batch_size)) {
          _uhc_sources_uhc_process_batches($batches, $queue);
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
  _uhc_sources_uhc_process_batches($batches, $queue);

  // Release specified items
  foreach ($release_items as $release_item) {
    $queue->releaseItem($release_item);
  }

}

/**
 * Tells if given batches exceeds the given $batch_size.
 * @param $batches
 * @param $batch_size
 * @return bool
 */
function _uhc_sources_uhc_batch_exceeded($batches, $batch_size) {
  $count = 0;
  foreach ($batches as $batch) {
    $count += count($batch['items']);
    if ($count >= $batch_size) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * @param $batches
 * @param UHOodiPrioritisedQueue $queue
 */
function _uhc_sources_uhc_process_batches(&$batches, &$queue) {
  foreach ($batches as $type => &$batch) {
    // Do not bother processing empty items list
    if (!empty($batch['items'])) {
      $function = $batch['update callback'];
      if ($function($batch['items']) === TRUE) {
        foreach ($batch['items'] as $updated_item) {
          $queue->deleteItem($updated_item);
          $batch['items'] = array();
        }
      }
      else {
        // TODO: Decide what to do with the items if update fails? Now, they
        // will be released after default expire...
      }
    }
  }
}
