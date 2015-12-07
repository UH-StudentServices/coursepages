<?php
/**
 * @file
 * uhc_analytics_and_tracking.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_analytics_and_tracking_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
