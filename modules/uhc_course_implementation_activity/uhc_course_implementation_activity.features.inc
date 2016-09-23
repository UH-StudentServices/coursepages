<?php
/**
 * @file
 * uhc_course_implementation_activity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_course_implementation_activity_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "ds" && $api == "ds") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uhc_course_implementation_activity_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_flag_default_flags().
 */
function uhc_course_implementation_activity_flag_default_flags() {
  $flags = array();
  // Exported flag: "Generate Activity Message".
  $flags['generate_activity_message'] = array(
    'entity_type' => 'node',
    'title' => 'Generate Activity Message',
    'global' => 1,
    'types' => array(
      0 => 'course_material',
      1 => 'event',
    ),
    'flag_short' => 'Flag this item',
    'flag_long' => '',
    'flag_message' => '',
    'unflag_short' => 'Unflag this item',
    'unflag_long' => '',
    'unflag_message' => '',
    'unflag_denied_text' => '',
    'link_type' => 'toggle',
    'weight' => 0,
    'show_in_links' => array(
      'full' => 0,
      'teaser' => 0,
      'rss' => 0,
      'search_index' => 0,
      'search_result' => 0,
      'diff_standard' => 0,
      'teaser_images' => 0,
      'content_suffix' => 0,
      'sidebar' => 0,
      'token' => 0,
      'material_block' => 0,
      'meta_information' => 0,
      'teaser_accordion' => 0,
      'revision' => 0,
    ),
    'show_as_field' => 0,
    'show_on_form' => 0,
    'access_author' => '',
    'show_contextual_link' => 0,
    'i18n' => 0,
    'module' => 'uhc_course_implementation_activity',
    'locked' => array(
      0 => 'name',
    ),
    'api_version' => 3,
  );
  return $flags;

}

/**
 * Implements hook_default_message_type().
 */
function uhc_course_implementation_activity_default_message_type() {
  $items = array();
  $items['course_implementation_comment_create'] = entity_import('message_type', '{
    "name" : "course_implementation_comment_create",
    "description" : "Course implementation - Comment create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-messages",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E @comment_body\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E @comment_body\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E @comment_body",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E @comment_body\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E @comment_body",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E @comment_body\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_comment_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_comment_remove",
    "description" : "Course implementation - Comment remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-messages",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed a message",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed a message\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti viestin",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti viestin\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade ett meddelande",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade ett meddelande\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_comment_update'] = entity_import('message_type', '{
    "name" : "course_implementation_comment_update",
    "description" : "Course implementation - Comment update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-messages",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated a message",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated a message\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti viesti\\u00e4",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti viesti\\u00e4\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade ett meddelande",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade ett meddelande\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_course_conduct_create'] = entity_import('message_type', '{
    "name" : "course_implementation_course_conduct_create",
    "description" : "Course implementation - Course conduct create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-conduct-of-course",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has added conduct of the course",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has added conduct of the course\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E lis\\u00e4si kurssin suorittamistiedot",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E lis\\u00e4si kurssin suorittamistiedot\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har tillagt kursbeskrivningen",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har tillagt kursbeskrivningen\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_course_conduct_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_course_conduct_remove",
    "description" : "Course implementation - Course conduct remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-conduct-of-course",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed conduct of the course",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed conduct of the course\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti kurssin suorittamistiedot",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti kurssin suorittamistiedot\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har raderat kursbeskrivningen",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har raderat kursbeskrivningen\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_course_conduct_update'] = entity_import('message_type', '{
    "name" : "course_implementation_course_conduct_update",
    "description" : "Course implementation - Course conduct update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-conduct-of-course",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated conduct of the course",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated conduct of the course\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti kurssin suorittamistietoja",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti kurssin suorittamistietoja\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har uppdaterat kursbeskrivningen",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har uppdaterat kursbeskrivningen\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_course_overview_accordion_target'] = entity_import('message_type', '{
    "name" : "course_implementation_course_overview_accordion_target",
    "description" : "Course implementation - Course overview accordion target",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-description-objectives",
    "send_mece_notification" : "0",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_event_create'] = entity_import('message_type', '{
    "name" : "course_implementation_event_create",
    "description" : "Course implementation - Event create",
    "argument_keys" : [ "@event_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-timetable",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has created one-off event \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has created one-off event \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E lis\\u00e4si kertaluonteisen tapahtuman \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E lis\\u00e4si kertaluonteisen tapahtuman \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E skapade en eng\\u00e5ngsh\\u00e4ndelse \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E skapade en eng\\u00e5ngsh\\u00e4ndelse \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_event_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_event_remove",
    "description" : "Course implementation - Event remove",
    "argument_keys" : [ "@event_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-timetable",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed an one-off event \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed an one-off event \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti kertaluonteisen tapahtuman \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti kertaluonteisen tapahtuman \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade en eng\\u00e5ngsh\\u00e4ndelse \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade en eng\\u00e5ngsh\\u00e4ndelse \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_event_update'] = entity_import('message_type', '{
    "name" : "course_implementation_event_update",
    "description" : "Course implementation - Event update",
    "argument_keys" : [ "@event_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-timetable",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated an event \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated an event \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti tapahtumaa \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti tapahtumaa \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade en eng\\u00e5ngsh\\u00e4ndelse \\u0022@event_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade en eng\\u00e5ngsh\\u00e4ndelse \\u0022@event_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_fee_accordion_target'] = entity_import('message_type', '{
    "name" : "course_implementation_fee_accordion_target",
    "description" : "Course implementation - Fee accordion target",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-fee",
    "send_mece_notification" : "0",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E-\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_feedback_create'] = entity_import('message_type', '{
    "name" : "course_implementation_feedback_create",
    "description" : "Course implementation - Feedback create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-feedback",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] added\\u0026nbsp;information on feedback.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] added\\u00a0information on feedback.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name]\\u0026nbsp;lis\\u00e4si tietoa palautteen antamisesta.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name]\\u00a0lis\\u00e4si tietoa palautteen antamisesta.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] tillade information om feedback.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] tillade information om feedback.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_feedback_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_feedback_remove",
    "description" : "Course implementation - Feedback remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-feedback",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] removed information on feedback.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] removed information on feedback.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] poisti tiedot palautteen antamisesta.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] poisti tiedot palautteen antamisesta.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] raderade information om feedback.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] raderade information om feedback.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_feedback_update'] = entity_import('message_type', '{
    "name" : "course_implementation_feedback_update",
    "description" : "Course implementation - Feedback update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-feedback",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] updated information on feedback.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] updated information on feedback.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti tietoja palautteen antamisesta.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti tietoja palautteen antamisesta.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] uppdaterade information om feedback.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] uppdaterade information om feedback.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_interaction_create'] = entity_import('message_type', '{
    "name" : "course_implementation_interaction_create",
    "description" : "Course implementation - Interaction create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-interaction",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] added information on interaction.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] added information on interaction.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name]\\u0026nbsp;lis\\u00e4si tietoa vuorovaikutuksesta.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name]\\u00a0lis\\u00e4si tietoa vuorovaikutuksesta.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] tillade information om interaktion.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] tillade information om interaktion.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_interaction_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_interaction_remove",
    "description" : "Course implementation - Interaction remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-interaction",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] removed information on interaction.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] removed information on interaction.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] poisti tiedot vuorovaikutuksesta.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] poisti tiedot vuorovaikutuksesta.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] raderade information om interaktion.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] raderade information om interaktion.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_interaction_update'] = entity_import('message_type', '{
    "name" : "course_implementation_interaction_update",
    "description" : "Course implementation - Interaction update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-interaction",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] updated information on interaction.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] updated information on interaction.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti tietoja vuorovaikutuksesta.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti tietoja vuorovaikutuksesta.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] uppdaterade information om interaktion.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] uppdaterade information om interaktion.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_introduction_create'] = entity_import('message_type', '{
    "name" : "course_implementation_introduction_create",
    "description" : "Course implementation - Introduction create",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] added introduction text.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] added introduction text.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name]\\u0026nbsp;lis\\u00e4si esittelytekstin.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name]\\u00a0lis\\u00e4si esittelytekstin.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] tillade introduktion text.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] tillade introduktion text.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_introduction_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_introduction_remove",
    "description" : "Course implementation - Introduction remove",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] removed introduction text.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] removed introduction text.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] poisti esittelytekstin.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] poisti esittelytekstin.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] raderade introduktion text.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] raderade introduktion text.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_introduction_update'] = entity_import('message_type', '{
    "name" : "course_implementation_introduction_update",
    "description" : "Course implementation - Introduction update ",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] updated introduction text.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] updated introduction text.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti esittelyteksti\\u00e4.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti esittelyteksti\\u00e4.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] uppdaterade introduktion text.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] uppdaterade introduktion text.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_json_event_change'] = entity_import('message_type', '{
    "name" : "course_implementation_json_event_change",
    "description" : "Course implementation - JSON Event change",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-timetable",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003ECourse schedule has changed\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003ECourse schedule has changed\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003EKurssin aikataulu on muuttunut\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003EKurssin aikataulu on muuttunut\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003ETidschema har f\\u00f6r\\u00e4ndrats\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003ETidschema har f\\u00f6r\\u00e4ndrats\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_material_create'] = entity_import('message_type', '{
    "name" : "course_implementation_material_create",
    "description" : "Course implementation - Material create",
    "argument_keys" : [ "@material_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has attached a material \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has attached a material \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E on liitt\\u00e4nyt materiaalin \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E on liitt\\u00e4nyt materiaalin \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har f\\u00e4stat ett material \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har f\\u00e4stat ett material \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_material_description_update'] = entity_import('message_type', '{
    "name" : "course_implementation_material_description_update",
    "description" : "Course implementation - Material description update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated material main description",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated material main description\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti materiaalien yleiskuvausta",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti materiaalien yleiskuvausta\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade \\u00f6versiktet \\u00f6ver materialet",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade \\u00f6versiktet \\u00f6ver materialet\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_material_manually_sorted'] = entity_import('message_type', '{
    "name" : "course_implementation_material_manually_sorted",
    "description" : "Course implementation - Material manually sorted",
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
  $items['course_implementation_material_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_material_remove",
    "description" : "Course implementation - Material remove",
    "argument_keys" : [ "@material_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed an attached material \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed an attached material \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti liitetyn materiaalin \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti liitetyn materiaalin \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade materialet \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade materialet \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_material_update'] = entity_import('message_type', '{
    "name" : "course_implementation_material_update",
    "description" : "Course implementation - Material update",
    "argument_keys" : [ "@material_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated material \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated material \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti materiaalia \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti materiaalia \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade materialet \\u0022@material_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade materialet \\u0022@material_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_moodle_course_area_create'] = entity_import('message_type', '{
    "name" : "course_implementation_moodle_course_area_create",
    "description" : "Course implementation - Moodle course area create",
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
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] created a Moodle course area.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] created a Moodle course area.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name]\\u0026nbsp;created a Moodle course area.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name]\\u00a0created a Moodle course area.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] created a Moodle course area.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] created a Moodle course area.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_moodle_key_create'] = entity_import('message_type', '{
    "name" : "course_implementation_moodle_key_create",
    "description" : "Course implementation - Moodle key create",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] added Moodle key.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] added Moodle key.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name]\\u0026nbsp;lis\\u00e4si Moodle-kurssiavaimen.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name]\\u00a0lis\\u00e4si Moodle-kurssiavaimen.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] tillade Moodle kursnyckel.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] tillade Moodle kursnyckel.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_moodle_key_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_moodle_key_remove",
    "description" : "Course implementation - Moodle key remove",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] removed Moodle key.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] removed Moodle key.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] poisti Moodle-kurssiavaimen.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] poisti Moodle-kurssiavaimen.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] raderade Moodle kursnyckel.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] raderade Moodle kursnyckel.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_moodle_key_update'] = entity_import('message_type', '{
    "name" : "course_implementation_moodle_key_update",
    "description" : "Course implementation - Moodle key update",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] updated Moodle key.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] updated Moodle key.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti Moodle-kurssiavainta.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti Moodle-kurssiavainta.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] uppdaterade Moodle kursnyckel.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] uppdaterade Moodle kursnyckel.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_moodle_link_create'] = entity_import('message_type', '{
    "name" : "course_implementation_moodle_link_create",
    "description" : "Course implementation - Moodle link create",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] added Moodle link.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] added Moodle link.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name]\\u0026nbsp;lis\\u00e4si Moodle-linkin.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name]\\u00a0lis\\u00e4si Moodle-linkin.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] tillade Moodle l\\u00e4nk.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] tillade Moodle l\\u00e4nk.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_moodle_link_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_moodle_link_remove",
    "description" : "Course implementation - Moodle link remove",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] removed Moodle link.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] removed Moodle link.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] poisti Moodle-linkityksen.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] poisti Moodle-linkityksen.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] raderade Moodle l\\u00e4nk.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] raderade Moodle l\\u00e4nk.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_moodle_link_update'] = entity_import('message_type', '{
    "name" : "course_implementation_moodle_link_update",
    "description" : "Course implementation - Moodle link update",
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
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] updated Moodle link.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] updated Moodle link.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti Moodle-linkki\\u00e4.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti Moodle-linkki\\u00e4.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] uppdaterade Moodle l\\u00e4nk.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] uppdaterade Moodle l\\u00e4nk.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_private_comment_create'] = entity_import('message_type', '{
    "name" : "course_implementation_private_comment_create",
    "description" : "Course implementation - Private comment create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-messages",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E wrote a message to students",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E wrote a message to students\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E kirjoitti viestin kurssin opiskelijoille",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E kirjoitti viestin kurssin opiskelijoille\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E skrev ett meddelande till studerande",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E skrev ett meddelande till studerande\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_private_comment_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_private_comment_remove",
    "description" : "Course implementation - Private comment remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-messages",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E removed a message",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E removed a message\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti viestin",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti viestin\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade ett meddelande",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade ett meddelande\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_private_comment_update'] = entity_import('message_type', '{
    "name" : "course_implementation_private_comment_update",
    "description" : "Course implementation - Private comment update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-messages",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E updated a message to students",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E updated a message to students\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti viesti\\u00e4 kurssin opiskelijoille",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti viesti\\u00e4 kurssin opiskelijoille\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E uppdaterade ett meddelande till studerande",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E uppdaterade ett meddelande till studerande\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_private_material_create'] = entity_import('message_type', '{
    "name" : "course_implementation_private_material_create",
    "description" : "Course implementation - Private material create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] has attached a private material\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] has attached a private material\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] on liitt\\u00e4nyt yksityisen materiaalin\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] on liitt\\u00e4nyt yksityisen materiaalin\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] har f\\u00e4stat ett privat\\u0026nbsp;material\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] har f\\u00e4stat ett privat\\u00a0material\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_private_material_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_private_material_remove",
    "description" : "Course implementation - Private material remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] has removed a private material\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] has removed a private material\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] poisti yksityisen materiaalin\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] poisti yksityisen materiaalin\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] raderade ett privat\\u0026nbsp;material\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] raderade ett privat\\u00a0material\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_private_material_update'] = entity_import('message_type', '{
    "name" : "course_implementation_private_material_update",
    "description" : "Course implementation - Private material update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] has updated private material\\u003C\\/p\\u003E\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] has updated private material\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti yksityist\\u00e4 materiaalia\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti yksityist\\u00e4 materiaalia\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] redigerade ett privat material\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] redigerade ett privat material\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_task_create'] = entity_import('message_type', '{
    "name" : "course_implementation_task_create",
    "description" : "Course implementation - Task create",
    "argument_keys" : [ "@task_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-task-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has given an task \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has given an task \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E antoi teht\\u00e4v\\u00e4n \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E antoi teht\\u00e4v\\u00e4n \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E gav en uppgift \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E gav en uppgift \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_task_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_task_remove",
    "description" : "Course implementation - Task remove",
    "argument_keys" : [ "@task_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-task-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed a task \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed a task \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti teht\\u00e4v\\u00e4n \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti teht\\u00e4v\\u00e4n \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade en uppgift \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade en uppgift \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_task_update'] = entity_import('message_type', '{
    "name" : "course_implementation_task_update",
    "description" : "Course implementation - Task update",
    "argument_keys" : [ "@task_title" ],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-course-task-material",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated task \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated task \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti teht\\u00e4v\\u00e4n \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti teht\\u00e4v\\u00e4n \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade uppgiften \\u0022@task_title\\u0022",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade uppgiften \\u0022@task_title\\u0022\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_teacher_section_create'] = entity_import('message_type', '{
    "name" : "course_implementation_teacher_section_create",
    "description" : "Course implementation - Teacher section create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-manual-content",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has added @field_imp_teachersection_label\\u003C\\/p\\u003E\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has added @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E lis\\u00e4si @field_imp_teachersection_label\\u003C\\/p\\u003E\\n\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E lis\\u00e4si @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har tillagt @field_imp_teachersection_label\\u003C\\/p\\u003E\\r\\n\\r\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har tillagt @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_teacher_section_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_teacher_section_remove",
    "description" : "Course implementation - Teacher section remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-manual-content",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed @field_imp_teachersection_label",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti @field_imp_teachersection_label",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har raderat @field_imp_teachersection_label",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har raderat @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_teacher_section_update'] = entity_import('message_type', '{
    "name" : "course_implementation_teacher_section_update",
    "description" : "Course implementation - Teacher section update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-manual-content",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated @field_imp_teachersection_label\\u003C\\/p\\u003E\\n\\n",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti @field_imp_teachersection_label\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har uppdaterat @field_imp_teachersection_label\\u003C\\/p\\u003E",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E har uppdaterat @field_imp_teachersection_label\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_video_create'] = entity_import('message_type', '{
    "name" : "course_implementation_video_create",
    "description" : "Course implementation - Video create",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-video",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] added the video section.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] added the video section.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name]\\u0026nbsp;lis\\u00e4si video-osion.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name]\\u00a0lis\\u00e4si video-osion.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] tillade video sektionen.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] tillade video sektionen.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_video_remove'] = entity_import('message_type', '{
    "name" : "course_implementation_video_remove",
    "description" : "Course implementation - Video remove",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-video",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] removed\\u0026nbsp;the video section.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] removed\\u00a0the video section.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] poisti video-osion.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] poisti video-osion.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] raderade video sektionen.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] raderade video sektionen.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  $items['course_implementation_video_update'] = entity_import('message_type', '{
    "name" : "course_implementation_video_update",
    "description" : "Course implementation - Video update",
    "argument_keys" : [],
    "argument" : [],
    "category" : "message_type",
    "data" : {
      "token options" : { "clear" : 0 },
      "purge" : { "override" : 0, "enabled" : 0, "quota" : "", "days" : "" }
    },
    "language" : "en",
    "arguments" : null,
    "target_accordion_class" : ".group-imp-video",
    "send_mece_notification" : "1",
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] updated\\u0026nbsp;the video section.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] updated\\u00a0the video section.\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti video-osiota.\\u003C\\/p\\u003E\\r\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] p\\u00e4ivitti video-osiota.\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E[message:user:name] uppdaterade video sektionen.\\u003C\\/p\\u003E\\n",
          "format" : "filtered_html",
          "safe_value" : "\\u003Cp\\u003E[message:user:name] uppdaterade video sektionen.\\u003C\\/p\\u003E\\n"
        }
      ]
    },
    "rdf_mapping" : []
  }');
  return $items;
}
