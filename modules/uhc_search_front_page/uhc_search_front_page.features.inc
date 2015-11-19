<?php
/**
 * @file
 * uhc_search_front_page.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_search_front_page_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
}

/**
 * Implements hook_views_api().
 */
function uhc_search_front_page_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}
