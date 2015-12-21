<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Page callback to 'node/%node/sync-status' as LOCAL_TASK, so privileged users
 * may see quick status of synchronization status. User may perform an manual
 * synchronization from this page.
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function uhc_sources_sync_status_form($form, &$form_state) {

  // Figure out the migration source and course implementation ID
  $form_state['build_info']['args']['field_imp_id'] = '';
  if (isset($form_state['build_info']['args'][0])) {
    // Specify what is the course implementation ID
    $node = $form_state['build_info']['args'][0];
    $field_imp_id = field_get_items('node', $node, 'field_imp_id');
    if (isset($field_imp_id[0]['value'])) {
      $form_state['build_info']['args']['field_imp_id'] = $field_imp_id[0]['value'];
    }
  }

  // Setup the informal description with "Sync" button
  return array(
    'submit' => array(
      '#type' => 'submit',
      '#value' => t('Synchronize now'),
    ),
    'description' => array(
      '#markup' => '<div class="description">' . t('This item has been previously updated at <strong><em>@time</em></strong>.', array('@time' => format_date($node->changed, 'short'))) . '</div>',
    ),
  );
}

/**
 * Form submission callback for processing the form. In this form we only
 * perform manual synchronizations.
 *
 * @param $form
 * @param $form_state
 */
function uhc_sources_sync_status_form_submit($form, &$form_state) {
  $access = (user_access('access administration pages')
    || uhc_course_collaboration_is_current_user_course_teacher()
    || uhc_course_collaboration_is_current_user_course_administrator()
  );

  if ($access &&
      $form_state['triggering_element']['#value'] == t('Synchronize now') &&
      isset($form_state['build_info']['args']['field_imp_id'])) {

    // Synchronize this page
    if ($node = uhc_sources_sync_for_page($form_state['build_info']['args']['field_imp_id'])) {
      drupal_set_message(t('This page has been synchronized.'));
      $form_state['redirect'] = array('node/' . $node->nid);
    }
    else {
      drupal_set_message(t('Could not synchronize the page. Please see more information from logs.'), 'error');
    }

  }
}
