<?php
/**
 * @file
 * uhc_course_material.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_course_material_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uhc_course_material_node_info() {
  $items = array(
    'course_material' => array(
      'name' => t('Course material'),
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
