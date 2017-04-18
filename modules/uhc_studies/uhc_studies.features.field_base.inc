<?php
/**
 * @file
 * uhc_studies.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function uhc_studies_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_studies_contact_card'.
  $field_bases['field_studies_contact_card'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_contact_card',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'dereference_on_delete' => 0,
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'contact_card' => 'contact_card',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 1,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_studies_description'.
  $field_bases['field_studies_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_description',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_studies_image'.
  $field_bases['field_studies_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 1,
    'type' => 'image',
  );

  // Exported field_base: 'field_studies_lp_description'.
  $field_bases['field_studies_lp_description'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_lp_description',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_studies_lp_image'.
  $field_bases['field_studies_lp_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_lp_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'fid' => array(
        0 => 'fid',
      ),
    ),
    'locked' => 0,
    'module' => 'image',
    'settings' => array(
      'default_image' => 0,
      'entity_translation_sync' => array(
        0 => 'fid',
      ),
      'uri_scheme' => 'public',
    ),
    'translatable' => 1,
    'type' => 'image',
  );

  // Exported field_base: 'field_studies_lp_view_attachment'.
  $field_bases['field_studies_lp_view_attachment'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_lp_view_attachment',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'view_id' => array(
        0 => 'view_id',
      ),
    ),
    'locked' => 0,
    'module' => 'viewreference',
    'settings' => array(
      'append_id' => 0,
      'arguments' => array(
        'delimiter' => '/',
        'dsv_arguments' => 0,
        'label' => '!field_label arguments',
        'php_arguments' => 0,
        'rows' => 1,
      ),
      'entity_translation_sync' => FALSE,
      'referenceable_tags' => array(
        'allow' => '',
        'deny' => '',
      ),
      'referenceable_views' => array(
        'admin_courseless_implementations:default' => 0,
        'admin_courseless_implementations:page' => 0,
        'admin_courses:default' => 0,
        'admin_courses:page' => 0,
        'admin_views_comment:default' => 0,
        'admin_views_comment:system_1' => 0,
        'admin_views_comment:system_2' => 0,
        'admin_views_node:default' => 0,
        'admin_views_node:system_1' => 0,
        'admin_views_taxonomy_term:default' => 0,
        'admin_views_taxonomy_term:system_1' => 0,
        'admin_views_user:default' => 0,
        'admin_views_user:system_1' => 0,
        'administration_nodes_open_university_editor:default' => 0,
        'administration_nodes_open_university_editor:page_1' => 0,
        'archive:block' => 0,
        'archive:default' => 0,
        'archive:page' => 0,
        'comments_recent:block' => 0,
        'comments_recent:default' => 0,
        'comments_recent:page' => 0,
        'course_event_references:block' => 0,
        'course_event_references:block_1' => 0,
        'course_event_references:default' => 0,
        'course_implementation_activity:block_1' => 0,
        'course_implementation_activity:default' => 0,
        'course_implementation_material:block' => 0,
        'course_implementation_material:default' => 0,
        'course_node_references:block' => 0,
        'course_node_references:block_1' => 0,
        'course_node_references:default' => 0,
        'courses_by_course_number:default' => 0,
        'courses_by_course_number:entityreference_1' => 0,
        'courses_implementations_by_course_number:default' => 0,
        'courses_implementations_by_course_number:entityreference_1' => 0,
        'feedback_messages:attachment_1' => 0,
        'feedback_messages:default' => 0,
        'feedback_messages:page_1' => 0,
        'frontpage:default' => 0,
        'frontpage:feed' => 0,
        'frontpage:page' => 0,
        'glossary:attachment' => 0,
        'glossary:default' => 0,
        'glossary:page' => 0,
        'google_analytics_reports_page:attachment_top_keywords' => 0,
        'google_analytics_reports_page:attachment_top_referrals' => 0,
        'google_analytics_reports_page:block' => 0,
        'google_analytics_reports_page:default' => 0,
        'google_analytics_reports_page:page' => 0,
        'google_analytics_reports_page:page_front' => 0,
        'google_analytics_reports_summary:attachment_top_keywords' => 0,
        'google_analytics_reports_summary:attachment_top_pages' => 0,
        'google_analytics_reports_summary:attachment_top_sources' => 0,
        'google_analytics_reports_summary:block' => 0,
        'google_analytics_reports_summary:default' => 0,
        'google_analytics_reports_summary:page' => 0,
        'location_directory:default' => 0,
        'location_directory:page_1' => 0,
        'location_table:default' => 0,
        'location_table:page_1' => 0,
        'message:default' => 0,
        'message:page_1' => 0,
        'notification_messages:default' => 0,
        'notification_messages:page' => 0,
        'og_all_user_group_content:default' => 0,
        'og_members:block_1' => 0,
        'og_members:default' => 0,
        'og_members_admin:default' => 0,
        'og_nodes:default' => 0,
        'og_user_groups:default' => 0,
        'rest_api_v1_course_implementation_activity:default' => 0,
        'rest_api_v1_course_implementation_activity:services_1' => 0,
        'rest_api_v1_course_implementations:default' => 0,
        'rest_api_v1_course_implementations:services_1' => 0,
        'rest_api_v1_events:default' => 0,
        'rest_api_v1_events:services_1' => 0,
        'rss_course_implementation_activity:default' => 0,
        'rss_course_implementation_activity:feed_1' => 0,
        'statistics_activity:default' => 0,
        'statistics_activity:page_3' => 0,
        'statistics_activity:views_data_export_1' => 0,
        'statistics_content:default' => 0,
        'statistics_content:page_1' => 0,
        'statistics_content:views_data_export_1' => 0,
        'statistics_created:default' => 0,
        'statistics_created:page' => 0,
        'statistics_created:views_data_export_1' => 0,
        'studies_by_category:block' => 'studies_by_category:block',
        'studies_by_category:default' => 0,
        'studies_by_degree_programme:block' => 'studies_by_degree_programme:block',
        'studies_by_degree_programme:default' => 0,
        'subjects_by_category:block' => 0,
        'subjects_by_category:default' => 0,
        'taxonomy_term:default' => 0,
        'taxonomy_term:feed' => 0,
        'taxonomy_term:page' => 0,
        'tracker:default' => 0,
        'tracker:page' => 0,
        'uhc_course_liftups:block_1' => 0,
        'uhc_course_liftups:block_2' => 0,
        'uhc_course_liftups:default' => 0,
        'uhc_course_liftups:latest' => 0,
        'uhc_google_analytics_reports_page:block' => 0,
        'uhc_google_analytics_reports_page:default' => 0,
        'uhc_liftups:block_1' => 0,
        'uhc_liftups:block_2' => 0,
        'uhc_liftups:default' => 0,
        'uhc_liftups:main' => 0,
        'uhc_portal_search_front_page_:default' => 0,
        'uhc_portal_search_front_page_:desktop' => 0,
        'uhc_portal_search_front_page_:feed_1' => 0,
        'uhc_portal_search_front_page_:feed_2' => 0,
        'uhc_portal_search_front_page_:search_api_views_facets_block_1' => 0,
        'uhc_search:default' => 0,
        'uhc_search:desktop' => 0,
        'uhc_search:search_api_views_facets_block_1' => 0,
        'uhc_search_biosciences:default' => 0,
        'uhc_search_biosciences:desktop' => 0,
        'uhc_search_biosciences:search_api_views_facets_block_1' => 0,
        'uhc_search_open_university:default' => 0,
        'uhc_search_open_university:desktop' => 0,
        'uhc_search_open_university:search_api_views_facets_block_1' => 0,
        'user_location_table:default' => 0,
        'user_location_table:page_1' => 0,
      ),
      'skip_default' => 1,
      'skip_disabled' => 0,
      'skip_empty' => 0,
      'sort_views' => 1,
    ),
    'translatable' => 0,
    'type' => 'viewreference',
  );

  // Exported field_base: 'field_studies_sidebar_liftups'.
  $field_bases['field_studies_sidebar_liftups'] = array(
    'active' => 1,
    'cardinality' => -1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_sidebar_liftups',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'target_id' => array(
        0 => 'target_id',
      ),
    ),
    'locked' => 0,
    'module' => 'entityreference',
    'settings' => array(
      'dereference_on_delete' => 0,
      'entity_translation_sync' => FALSE,
      'handler' => 'base',
      'handler_settings' => array(
        'behaviors' => array(
          'views-select-list' => array(
            'status' => 0,
          ),
        ),
        'sort' => array(
          'type' => 'none',
        ),
        'target_bundles' => array(
          'liftup' => 'liftup',
        ),
      ),
      'target_type' => 'node',
    ),
    'translatable' => 1,
    'type' => 'entityreference',
  );

  // Exported field_base: 'field_studies_study_modules_desc'.
  $field_bases['field_studies_study_modules_desc'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_study_modules_desc',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 1,
    'type' => 'text_long',
  );

  // Exported field_base: 'field_studies_study_modules_titl'.
  $field_bases['field_studies_study_modules_titl'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_studies_study_modules_titl',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'format' => array(
        0 => 'format',
      ),
    ),
    'locked' => 0,
    'module' => 'text',
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'max_length' => 255,
    ),
    'translatable' => 1,
    'type' => 'text',
  );

  // Exported field_base: 'field_stuides_is_degree_programm'.
  $field_bases['field_stuides_is_degree_programm'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_stuides_is_degree_programm',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
