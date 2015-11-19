<?php
/**
 * @file
 * uhc_course_collaboration.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_course_collaboration_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
