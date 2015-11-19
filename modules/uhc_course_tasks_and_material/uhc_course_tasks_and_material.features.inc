<?php
/**
 * @file
 * uhc_course_tasks_and_material.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_course_tasks_and_material_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uhc_course_tasks_and_material_node_info() {
  $items = array(
    'course_task' => array(
      'name' => t('Course task'),
      'base' => 'node_content',
      'description' => t('Add tasks to a course which can provide additional materials and specifications to the task itself. You will be provided with a text field for your own notes and fields for attached material.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
