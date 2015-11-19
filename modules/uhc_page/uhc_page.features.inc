<?php
/**
 * @file
 * uhc_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uhc_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_node_info().
 */
function uhc_page_node_info() {
  $items = array(
    'portal_page' => array(
      'name' => t('Portal page'),
      'base' => 'node_content',
      'description' => t('Portal pages are used as section landing pages to gather and promote the section and its content.'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
