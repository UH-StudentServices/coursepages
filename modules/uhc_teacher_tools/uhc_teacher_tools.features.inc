<?php
/**
 * @file
 * uhc_teacher_tools.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_teacher_tools_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
