<?php
/**
 * @file
 * uhc_exam_results.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_exam_results_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uhc_exam_results_node_info() {
  $items = array(
    'exam_results' => array(
      'name' => t('Exam results'),
      'base' => 'node_content',
      'description' => '',
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
