<?php
/**
 * @file
 * uhc_date_format.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_date_format_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
