<?php

/**
 * UHC migrate configuration form for filtering imports by method of study.
 *
 * Lists all the terms from method_of_study vocabulary. Selecting or deselecting
 * these will affect the migration of course implementations. All those course
 * implementations that have a method of study value that is not on the selected
 * whitelist will be skipped from migration.
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function uhc_sources_migrate_method_of_study_settings_form($form, &$form_state) {
  $vocabulary = taxonomy_vocabulary_machine_name_load('method_of_study');
  $options = uhc_sources_get_taxonomy_term_options($vocabulary->vid);
  $default_value = variable_get('uhc_migrate_methods_of_study_marked_as_exam', array_keys($options));

  $description = t('Mark which methods of study are exams. These will be excluded from importing from HY backend systems. NOTE: Open university course implementation import ignores this setting.');

  $form['uhc_migrate_methods_of_study_marked_as_exam'] = array(
    '#type' => 'checkboxes',
    '#title' => t($vocabulary->name),
    '#description' => t($description),
    '#options' => $options,
    '#default_value' => $default_value
  );

  return system_settings_form($form);
}

/**
 * Loads all terms from a given vocabulary and returns an array ready to be used
 * as Form API options.
 *
 * @param $vid int Vocabulary ID.
 * @return array An array of options ready to be used as Form API options.
 */
function uhc_sources_get_taxonomy_term_options($vid){
  $options = array();
  $options_source = taxonomy_get_tree($vid);

  foreach ($options_source as $item) {
    $key = $item->tid;
    $value = $item->name;
    $options[$key] = $value;
  }

  return $options;
}

/**
 * UHC migration settings for filtering imports by organisational units.
 *
 * @param $form
 * @param $form_state
 * @return array
 */
function uhc_sources_migrate_organisational_units_settings_form($form, &$form_state) {
  $vocabulary = taxonomy_vocabulary_machine_name_load('organisational_units');
  $options = uhc_sources_get_taxonomy_term_options($vocabulary->vid);
  $default_value = variable_get('uhc_migrate_selected_organisational_units', array_keys($options));

  $description = t('Only the course implementations having one of the selected organisational units will be imported from HY backend systems.');

  $form['uhc_migrate_selected_organisational_units'] = array(
    '#type' => 'checkboxes',
    '#title' => t($vocabulary->name),
    '#description' => t($description),
    '#options' => array_combine($options, $options),
    '#default_value' => $default_value
  );

  return system_settings_form($form);
}

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
