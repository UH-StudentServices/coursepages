<?php
/**
 * @file
 * uhc_css_js_aggregation.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_css_js_aggregation_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
