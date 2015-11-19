<?php
/**
 * @file
 * uhc_contact_card.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_contact_card_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_node_info().
 */
function uhc_contact_card_node_info() {
  $items = array(
    'contact_card' => array(
      'name' => t('Contact card'),
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
