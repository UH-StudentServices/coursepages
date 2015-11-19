<?php
/**
 * @file
 * uhc_course_implementation_activity.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_course_implementation_activity_ctools_plugin_api($module = NULL, $api = NULL) {
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
  $items['course_implementation_interaction_accordion_target'] = entity_import('message_type', '{
    "name" : "course_implementation_interaction_accordion_target",
    "description" : "Course implementation - Interaction accordion target",
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
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has written a private message",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has written a private message\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E kirjoitti yksityisviestin",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E kirjoitti yksityisviestin\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E skrev ett privat meddelande",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E skrev ett privat meddelande\\u003C\\/p\\u003E\\n"
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
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed a private message",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has removed a private message\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti yksityisviestin",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E poisti yksityisviestin\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade ett privat meddelande",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E raderade ett privat meddelande\\u003C\\/p\\u003E\\n"
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
    "message_text" : {
      "en" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated a private message",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E has updated a private message\\u003C\\/p\\u003E\\n"
        }
      ],
      "fi" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti yksityisviesti\\u00e4",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E p\\u00e4ivitti yksityisviesti\\u00e4\\u003C\\/p\\u003E\\n"
        }
      ],
      "sv" : [
        {
          "value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade ett privat meddelande",
          "format" : "full_html",
          "safe_value" : "\\u003Cp\\u003E\\u003Cspan class=\\u0022user-name\\u0022\\u003E[message:user:name]\\u003C\\/span\\u003E redigerade ett privat meddelande\\u003C\\/p\\u003E\\n"
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
    "target_accordion_class" : ".group-custom-section",
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
    "target_accordion_class" : ".group-custom-section",
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
    "target_accordion_class" : ".group-custom-section",
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
  return $items;
}
