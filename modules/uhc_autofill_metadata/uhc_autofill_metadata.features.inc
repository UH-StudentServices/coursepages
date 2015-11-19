<?php
/**
 * @file
 * uhc_autofill_metadata.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_autofill_metadata_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
