<?php
/**
 * @file
 * uhc_course_implementation_inherited_fields.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_course_implementation_inherited_fields_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "field_group" && $api == "field_group") {
    return array("version" => "1");
  }
}
