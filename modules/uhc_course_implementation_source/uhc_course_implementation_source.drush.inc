<?php
/**
 * @file
 * Drush integration implementation
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_drush_command().
 */
function uhc_course_implementation_source_drush_command() {
  return array(
    'uhc-course-imp-queue-for-delete' => array(
      'description' => 'Utility command for adding course implementation IDs to deletion queue.',
      'callback' => 'uhc_course_implementation_source_queue_delete',
      'arguments' => array(
        'ids' => dt('A comma-separated list of course unit realisation IDs.'),
      ),
      'required-arguments' => TRUE,
      'examples' => array(
        'drush uhc-course-imp-queue-for-delete 12345667,1234567,87645281' => dt('Queues course unit realisations 12345667, 1234567 and 87645281 for deletion.'),
      ),
    ),
  );
}

/**
 * Callback for putting ids to delete queue.
 * @param $ids
 */
function uhc_course_implementation_source_queue_delete($ids) {

  // Process ids argument
  $deleted_ids = explode(',', $ids);

  /** @var DrupalReliableQueueInterface $queue */
  $queue = DrupalQueue::get('uhc_course_implementation_source_delete', TRUE);
  while ($deleted_id = array_shift($deleted_ids)) {
    drush_print('Created item "' . $deleted_id . '" to delete queue');
    $queue->createItem($deleted_id);
  }

}
