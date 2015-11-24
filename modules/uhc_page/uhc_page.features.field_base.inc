<?php
/**
 * @file
 * uhc_page.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function uhc_page_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_portal_page_image'
  $field_bases['field_portal_page_image'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_portal_page_image',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(
      'fid' => array(
        'columns' => array(
          'fid' => 'fid',
        ),
        'table' => 'file_managed',
      ),
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
    'translatable' => 0,
    'type' => 'image',
  );

  // Exported field_base: 'field_view_attachment'
  $field_bases['field_view_attachment'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_view_attachment',
    'field_permissions' => array(
      'type' => 0,
    ),
    'foreign keys' => array(),
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
        'admin_views_comment:system_1' => 0,
        'admin_views_comment:system_2' => 0,
        'admin_views_node:system_1' => 0,
        'admin_views_taxonomy_term:system_1' => 0,
        'admin_views_user:system_1' => 0,
        'archive:block' => 0,
        'archive:page' => 0,
        'backlinks:block' => 0,
        'backlinks:page' => 0,
        'comments_recent:block' => 0,
        'comments_recent:page' => 0,
        'course_event_references:block' => 0,
        'course_event_references:block_1' => 0,
        'course_event_references:block_2' => 0,
        'course_event_references_light:block' => 0,
        'course_implementation_activity:block_1' => 0,
        'course_node_references:block' => 0,
        'feedback_messages:attachment_1' => 0,
        'feedback_messages:page_1' => 0,
        'frontpage:feed' => 0,
        'frontpage:page' => 0,
        'glossary:attachment' => 0,
        'glossary:page' => 0,
        'message:page_1' => 0,
        'og_members:block_1' => 0,
        'rest_api_v1_course_implementation_activity:services_1' => 0,
        'rest_api_v1_course_implementations:services_1' => 0,
        'rest_api_v1_events:services_1' => 0,
        'subjects_by_category:block' => 'subjects_by_category:block',
        'taxonomy_term:feed' => 0,
        'taxonomy_term:page' => 0,
        'tracker:page' => 0,
        'uhc_course_liftups:latest' => 0,
        'uhc_liftups:main' => 0,
        'uhc_search:desktop' => 0,
        'uhc_search_open_university:desktop' => 0,
      ),
      'skip_default' => 1,
      'skip_empty' => 0,
    ),
    'translatable' => 0,
    'type' => 'viewreference',
  );

  return $field_bases;
}
