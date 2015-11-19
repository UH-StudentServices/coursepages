<?php
/**
 * @file
 * uhc_online_services.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_online_services_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uhc_online_services_node_info() {
  $items = array(
    'online_service' => array(
      'name' => t('Online Service promotion'),
      'base' => 'node_content',
      'description' => t('Will show up on the page that lists development sites so that students can find them more easily'),
      'has_title' => '1',
      'title_label' => t('Title'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
