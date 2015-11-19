<?php
/**
 * @file
 * uhc_shib_conf.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_shib_conf_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}
