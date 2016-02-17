<?php
/**
 * @file
 * uhc_search_portal_feature.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_search_portal_feature_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "facetapi" && $api == "facetapi_defaults") {
    return array("version" => "1");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_default_search_api_autocomplete_search().
 */
function uhc_search_portal_feature_default_search_api_autocomplete_search() {
  $items = array();
  $items['search_api_views_uhc_search_open_university'] = entity_import('search_api_autocomplete_search', '{
    "machine_name" : "search_api_views_uhc_search_open_university",
    "name" : "UHC search (open university)",
    "index_id" : "uhc_portal",
    "suggester_id" : "server",
    "type" : "search_api_views",
    "enabled" : "1",
    "options" : {
      "suggester_configuration" : { "fields" : [ "search_api_aggregation_2" ] },
      "min_length" : "1",
      "results" : 0,
      "custom" : { "display" : "desktop" },
      "submit_button_selector" : ":submit[id^=\\u0022edit-submit\\u0022]",
      "autosubmit" : 1
    },
    "rdf_mapping" : []
  }');
  return $items;
}

/**
 * Implements hook_default_search_api_index().
 */
function uhc_search_portal_feature_default_search_api_index() {
  $items = array();
  $items['uhc_portal'] = entity_import('search_api_index', '{
    "name" : "UHC Portal",
    "machine_name" : "uhc_portal",
    "description" : "Indexes course implementations for portal search.",
    "server" : "solr",
    "item_type" : "search_api_et_node",
    "options" : {
      "index_directly" : 0,
      "cron_limit" : "100",
      "search_api_et" : { "include" : "incomplete", "fallback language" : "fi" },
      "fields" : {
        "field_additional_info:value" : { "type" : "text" },
        "field_conduct:value" : { "type" : "text" },
        "field_contents:value" : { "type" : "text" },
        "field_course_course_tags" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_evaluation:value" : { "type" : "text" },
        "field_imp_begin_date" : { "type" : "date" },
        "field_imp_end_date" : { "type" : "date" },
        "field_imp_fee:value" : { "type" : "text" },
        "field_imp_giver_locality" : { "type" : "string" },
        "field_imp_keywords" : { "type" : "list\\u003Cstring\\u003E" },
        "field_imp_locality" : { "type" : "string" },
        "field_imp_method_of_study" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_imp_organisation:field_ouh_code" : { "type" : "list\\u003Cstring\\u003E" },
        "field_imp_reference_to_courses:field_additional_info:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_conduct:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_contents:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_course_course_number" : { "type" : "string" },
        "field_imp_reference_to_courses:field_course_faculty" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_imp_reference_to_courses:field_course_subject" : { "type" : "list\\u003Cstring\\u003E" },
        "field_imp_reference_to_courses:field_course_theme" : { "type" : "list\\u003Cinteger\\u003E", "entity_type" : "taxonomy_term" },
        "field_imp_reference_to_courses:field_course_type_of_teaching" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_imp_reference_to_courses:field_evaluation:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_imp_fee:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_imp_start_month" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_imp_reference_to_courses:field_objective:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_open_uni_registration:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_rel_to_other_study_units:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_req_prerequisites:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_responsible_person:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_study_materials:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_target_group:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_timing:value" : { "type" : "text" },
        "field_imp_reference_to_courses:field_working_methods:value" : { "type" : "text" },
        "field_imp_reference_to_courses:nid" : { "type" : "integer" },
        "field_imp_reference_to_courses:url" : { "type" : "uri" },
        "field_imp_start_month" : { "type" : "integer", "entity_type" : "taxonomy_term" },
        "field_imp_teacher" : { "type" : "string" },
        "field_imp_teaching_language:value" : { "type" : "list\\u003Cstring\\u003E" },
        "field_objective:value" : { "type" : "text" },
        "field_open_uni_registration:value" : { "type" : "text" },
        "field_rel_to_other_study_units:value" : { "type" : "text" },
        "field_req_prerequisites:value" : { "type" : "text" },
        "field_responsible_person:value" : { "type" : "text" },
        "field_study_credit" : { "type" : "text" },
        "field_study_materials:value" : { "type" : "text" },
        "field_target_group:value" : { "type" : "text" },
        "field_timing:value" : { "type" : "text" },
        "field_working_methods:value" : { "type" : "text" },
        "language" : { "type" : "string" },
        "nid" : { "type" : "integer" },
        "search_api_aggregation_1" : { "type" : "text" },
        "search_api_aggregation_2" : { "type" : "text" },
        "search_api_language" : { "type" : "string" },
        "title_field" : { "type" : "string" },
        "type" : { "type" : "string" },
        "url" : { "type" : "uri" }
      },
      "data_alter_callbacks" : {
        "search_api_alter_bundle_filter" : {
          "status" : 1,
          "weight" : "-10",
          "settings" : {
            "default" : "0",
            "bundles" : { "course_implementation" : "course_implementation" }
          }
        },
        "search_api_alter_node_access" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_node_status" : { "status" : 1, "weight" : "0", "settings" : [] },
        "search_api_alter_language_control" : {
          "status" : 0,
          "weight" : "0",
          "settings" : { "lang_field" : "", "languages" : [] }
        },
        "search_api_alter_add_viewed_entity" : { "status" : 0, "weight" : "0", "settings" : { "mode" : "full" } },
        "search_api_alter_add_url" : { "status" : 0, "weight" : "0", "settings" : [] },
        "search_api_alter_add_aggregation" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : {
              "search_api_aggregation_1" : {
                "name" : "Combined fulltext",
                "type" : "fulltext",
                "fields" : [
                  "title_field",
                  "field_imp_id",
                  "field_imp_teacher",
                  "field_imp_course_organiser",
                  "field_imp_locality",
                  "field_course_subject",
                  "field_imp_reference_to_courses:title",
                  "field_imp_reference_to_courses:title_field",
                  "field_imp_reference_to_courses:field_imp_teacher",
                  "field_imp_reference_to_courses:field_imp_course_organiser",
                  "field_imp_reference_to_courses:field_imp_locality",
                  "field_imp_reference_to_courses:field_course_course_number",
                  "field_imp_reference_to_courses:field_course_theme",
                  "field_imp_reference_to_courses:field_course_subject",
                  "field_additional_info:value",
                  "field_conduct:value",
                  "field_contents:value",
                  "field_evaluation:value",
                  "field_imp_fee:value",
                  "field_objective:value",
                  "field_req_prerequisites:value",
                  "field_study_materials:value",
                  "field_target_group:value",
                  "field_timing:value",
                  "field_rel_to_other_study_units:value",
                  "field_responsible_person:value",
                  "field_open_uni_registration:value",
                  "field_working_methods:value",
                  "field_imp_reference_to_courses:field_additional_info:value",
                  "field_imp_reference_to_courses:field_conduct:value",
                  "field_imp_reference_to_courses:field_contents:value",
                  "field_imp_reference_to_courses:field_evaluation:value",
                  "field_imp_reference_to_courses:field_imp_fee:value",
                  "field_imp_reference_to_courses:field_objective:value",
                  "field_imp_reference_to_courses:field_req_prerequisites:value",
                  "field_imp_reference_to_courses:field_study_materials:value",
                  "field_imp_reference_to_courses:field_target_group:value",
                  "field_imp_reference_to_courses:field_timing:value",
                  "field_imp_reference_to_courses:field_rel_to_other_study_units:value",
                  "field_imp_reference_to_courses:field_responsible_person:value",
                  "field_imp_reference_to_courses:field_open_uni_registration:value",
                  "field_imp_reference_to_courses:field_working_methods:value"
                ],
                "description" : "A Fulltext aggregation of the following fields: Title, ID, Teacher, Course organiser, Locality, Subject, Reference to course(s) \\u00bb Title, Reference to course(s) \\u00bb Title, Reference to course(s) \\u00bb Teacher, Reference to course(s) \\u00bb Course organiser, Reference to course(s) \\u00bb Locality, Reference to course(s) \\u00bb Course number, Reference to course(s) \\u00bb Theme, Reference to course(s) \\u00bb Subject, Additional information \\u00bb Text, Course conduct \\u00bb Text, Contents \\u00bb Text, Evaluation \\u00bb Text, Fee \\u00bb Text, Objective \\u00bb Text, Required prerequisites \\u00bb Text, Course study materials \\u00bb Text, Target group \\u00bb Text, Timing \\u00bb Text, Relations to other study units \\u00bb Text, Responsible person \\u00bb Text, Open university registration \\u00bb Text, Realisation and working methods \\u00bb Text, Reference to course(s) \\u00bb Additional information \\u00bb Text, Reference to course(s) \\u00bb Course conduct \\u00bb Text, Reference to course(s) \\u00bb Contents \\u00bb Text, Reference to course(s) \\u00bb Evaluation \\u00bb Text, Reference to course(s) \\u00bb Fee \\u00bb Text, Reference to course(s) \\u00bb Objective \\u00bb Text, Reference to course(s) \\u00bb Required prerequisites \\u00bb Text, Reference to course(s) \\u00bb Course study materials \\u00bb Text, Reference to course(s) \\u00bb Target group \\u00bb Text, Reference to course(s) \\u00bb Timing \\u00bb Text, Reference to course(s) \\u00bb Relations to other study units \\u00bb Text, Reference to course(s) \\u00bb Responsible person \\u00bb Text, Reference to course(s) \\u00bb Open university registration \\u00bb Text, Reference to course(s) \\u00bb Realisation and working methods \\u00bb Text."
              },
              "search_api_aggregation_2" : {
                "name" : "Autocomplete",
                "type" : "fulltext",
                "fields" : [
                  "title_field",
                  "field_imp_id",
                  "field_imp_teacher",
                  "field_imp_locality",
                  "field_course_subject",
                  "field_imp_reference_to_courses:title_field",
                  "field_imp_reference_to_courses:field_course_course_number",
                  "field_imp_reference_to_courses:field_course_subject",
                  "field_objective:value",
                  "field_imp_reference_to_courses:field_objective:value"
                ],
                "description" : "A Fulltext aggregation of the following fields: Title, ID, Teacher, Locality, Subject, Reference to course(s) \\u00bb Title, Reference to course(s) \\u00bb Course number, Reference to course(s) \\u00bb Subject, Objective \\u00bb Text, Reference to course(s) \\u00bb Objective \\u00bb Text."
              }
            }
          }
        },
        "search_api_alter_add_hierarchy" : {
          "status" : 1,
          "weight" : "0",
          "settings" : { "fields" : { "field_imp_organisation:parents_all" : "field_imp_organisation:parents_all" } }
        }
      },
      "processors" : {
        "search_api_case_ignore" : { "status" : 0, "weight" : "0", "settings" : { "fields" : [] } },
        "search_api_html_filter" : {
          "status" : 1,
          "weight" : "10",
          "settings" : {
            "fields" : { "search_api_aggregation_1" : true, "field_contents:value" : true },
            "title" : 0,
            "alt" : 1,
            "tags" : "h1 = 5\\r\\nh2 = 3\\r\\nh3 = 2\\r\\nstrong = 2\\r\\nb = 2\\r\\nem = 1.5\\r\\nu = 1.5"
          }
        },
        "search_api_tokenizer" : {
          "status" : 1,
          "weight" : "20",
          "settings" : {
            "fields" : { "search_api_aggregation_2" : true },
            "spaces" : "[^[:alnum:]]",
            "ignorable" : "[\\u0027]"
          }
        },
        "search_api_stopwords" : {
          "status" : 0,
          "weight" : "30",
          "settings" : {
            "fields" : [],
            "file" : "",
            "stopwords" : "but\\r\\ndid\\r\\nthe this that those\\r\\netc"
          }
        },
        "search_api_highlighting" : {
          "status" : 0,
          "weight" : "35",
          "settings" : {
            "prefix" : "\\u003Cstrong\\u003E",
            "suffix" : "\\u003C\\/strong\\u003E",
            "excerpt" : 1,
            "excerpt_length" : "256",
            "exclude_fields" : [],
            "highlight" : "always"
          }
        }
      }
    },
    "enabled" : "1",
    "read_only" : "0",
    "rdf_mapping" : []
  }');
  return $items;
}
