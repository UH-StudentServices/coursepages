<?php
/**
 * @file
 * uhc_comment.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_comment_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
