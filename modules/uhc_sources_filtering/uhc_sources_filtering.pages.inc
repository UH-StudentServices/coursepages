<?php
/**
 * @file
 * Contains page callbacks of this module.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

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
function uhc_sources_filtering_migrate_method_of_study_settings_form($form, &$form_state) {
  $vocabulary = taxonomy_vocabulary_machine_name_load('method_of_study');
  $options = uhc_sources_get_taxonomy_term_options($vocabulary->vid);
  $default_value = variable_get('uhc_migrate_methods_of_study_marked_as_exam', array_keys($options));

  $description = t('Mark which methods of study are exams. This configuration will affect on migration filtering and schedule display logic in course pages.');

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
