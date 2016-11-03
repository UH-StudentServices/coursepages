<?php
/**
 * @file
 * uhc_statistics.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_statistics_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uhc_statistics_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_default_message_type().
 */
function uhc_statistics_default_message_type() {
  $items = array();
  $items['course_implementation_analytics_view'] = entity_import('message_type', '{
    "name" : "course_implementation_analytics_view",
    "description" : "Course implementation - Analytics view",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : "",
    "send_mece_notification" : "0",
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003E.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_queue'] = entity_import('message_type', '{
    "name" : "course_implementation_queue",
    "description" : "Course implementation - Queue",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : "",
    "send_mece_notification" : "0",
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003E.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_update_statistics'] = entity_import('message_type', '{
    "name" : "course_implementation_update_statistics",
    "description" : "Course Implementation Update statistics",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : "",
    "send_mece_notification" : "0",
    "message_text" : { "en" : [
        {
          "value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
