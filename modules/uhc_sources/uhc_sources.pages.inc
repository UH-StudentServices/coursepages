<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Page callback to 'node/%node/queue-status' as LOCAL_TASK, so privileged users
 * may request for updating corresponding course. Button will queue this item
 * with high priority.
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function uhc_sources_queue_status_form($form, &$form_state) {

  // Figure out the migration source and course implementation ID
  $form_state['build_info']['args']['field_imp_id'] = '';
  if (isset($form_state['build_info']['args'][0])) {
    // Specify what is the course implementation ID
    $node = $form_state['build_info']['args'][0];
    $field_imp_id = _uhc_sources_resolve_course_imp($node->nid);
    if ($field_imp_id) {
      $form_state['build_info']['args']['field_imp_id'] = $field_imp_id;
    }
  }

  // Setup the informal description with "Request for update" button
  return array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Request for update'),
    ),
    'description' => array(
      '#markup' => '<div class="description">' . t('System checks frequently for new Oodi updates. You may specifically request for updating this course during next cycle.') . '</div>',
    ),
  );
}

/**
 * Form submission callback for processing the form. In this form we only queue
 * an item for next update cycle.
 *
 * @param $form
 * @param $form_state
 */
function uhc_sources_queue_status_form_submit($form, &$form_state) {
  if ($form_state['triggering_element']['#value'] == t('Request for update') &&
      isset($form_state['build_info']['args']['field_imp_id'])) {

    $imp_id = $form_state['build_info']['args']['field_imp_id'];
    $node = uhc_course_implementation_load_by_id($imp_id);

    // Queue this course implementation
    if (uhc_sources_queue_imp_id($imp_id)) {
      // create activity message for statistics
      uhc_course_implementation_activity_create_message($node, 'course_implementation_queue');

      drupal_set_message(t('The page will be updated soon (within @expected_duration)', array('@expected_duration' => variable_get('uhc_sources_expected_duration', '10 min'))));
      $form_state['redirect'] = array('node/' . $node->nid);
    }
    else {
      drupal_set_message(t('Could not request for update. Please see more information from logs.'), 'error');
    }

  }
}

/**
 * Callback for queueing an single specified course implementation.
 * @param $imp_id
 * @return bool
 */
function uhc_sources_queue_imp_id($imp_id) {
  $queue = new UHOodiQueue(UHOodiQueue::PRIORITY_HIGH);
  $item = array(
    'action' => 'update',
    'entityType' => 'courseunitrealisation',
    'entityId' => (int) $imp_id,
  );
  return $queue->createItem($item);
}
