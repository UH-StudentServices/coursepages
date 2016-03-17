<?php
/**
 * @file
 * uhc_course.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uhc_course_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'field_bundle_settings_node__course';
  $strongarm->value = array(
    'view_modes' => array(
      'teaser' => array(
        'custom_settings' => TRUE,
      ),
      'index' => array(
        'custom_settings' => TRUE,
      ),
      'scald' => array(
        'custom_settings' => TRUE,
      ),
      'full' => array(
        'custom_settings' => FALSE,
      ),
      'rss' => array(
        'custom_settings' => FALSE,
      ),
      'search_index' => array(
        'custom_settings' => FALSE,
      ),
      'search_result' => array(
        'custom_settings' => FALSE,
      ),
      'diff_standard' => array(
        'custom_settings' => FALSE,
      ),
      'token' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_images' => array(
        'custom_settings' => TRUE,
      ),
      'content_suffix' => array(
        'custom_settings' => TRUE,
      ),
      'sidebar' => array(
        'custom_settings' => TRUE,
      ),
      'revision' => array(
        'custom_settings' => FALSE,
      ),
      'teaser_accordion' => array(
        'custom_settings' => FALSE,
      ),
      'material_block' => array(
        'custom_settings' => FALSE,
      ),
      'meta_information' => array(
        'custom_settings' => FALSE,
      ),
    ),
    'extra_fields' => array(
      'form' => array(
        'title' => array(
          'weight' => '1',
        ),
        'path' => array(
          'weight' => '5',
        ),
        'language' => array(
          'weight' => '4',
        ),
        'locations' => array(
          'weight' => '4',
        ),
      ),
      'display' => array(
        'study_cart_link_entity_view_1' => array(
          'default' => array(
            'weight' => '10',
            'visible' => TRUE,
          ),
        ),
        'course_navigation_block_entity_view_1' => array(
          'default' => array(
            'weight' => '3',
            'visible' => TRUE,
          ),
        ),
        'flippy_pager' => array(
          'default' => array(
            'weight' => '4',
            'visible' => TRUE,
          ),
        ),
      ),
    ),
  );
  $export['field_bundle_settings_node__course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'language_content_type_course';
  $strongarm->value = '4';
  $export['language_content_type_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_options_course';
  $strongarm->value = array();
  $export['menu_options_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'menu_parent_course';
  $strongarm->value = 'main-menu:0';
  $export['menu_parent_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_options_course';
  $strongarm->value = array(
    0 => 'status',
  );
  $export['node_options_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_preview_course';
  $strongarm->value = '0';
  $export['node_preview_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_submitted_course';
  $strongarm->value = 0;
  $export['node_submitted_course'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_en_pattern';
  $strongarm->value = '[node:field-course-course-number]';
  $export['pathauto_node_course_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_fi_pattern';
  $strongarm->value = '[node:field-course-course-number]';
  $export['pathauto_node_course_fi_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_implementation_en_pattern';
  $strongarm->value = '[node:field-imp-reference-to-courses:field-course-course-number]/[node:field-imp-id]';
  $export['pathauto_node_course_implementation_en_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_implementation_fi_pattern';
  $strongarm->value = '[node:field-imp-reference-to-courses:field-course-course-number]/[node:field-imp-id]';
  $export['pathauto_node_course_implementation_fi_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_implementation_pattern';
  $strongarm->value = '[node:field-imp-reference-to-courses:field-course-course-number]/[node:field-imp-id]';
  $export['pathauto_node_course_implementation_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_implementation_sv_pattern';
  $strongarm->value = '[node:field-imp-reference-to-courses:field-course-course-number]/[node:field-imp-id]';
  $export['pathauto_node_course_implementation_sv_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_implementation_und_pattern';
  $strongarm->value = '[node:field-imp-reference-to-courses:field-course-course-number]/[node:field-imp-id]';
  $export['pathauto_node_course_implementation_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_pattern';
  $strongarm->value = '[node:field-course-course-number]';
  $export['pathauto_node_course_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_sv_pattern';
  $strongarm->value = '[node:field-course-course-number]';
  $export['pathauto_node_course_sv_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_node_course_und_pattern';
  $strongarm->value = '[node:field-course-course-number]';
  $export['pathauto_node_course_und_pattern'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'pathauto_update_action';
  $strongarm->value = '2';
  $export['pathauto_update_action'] = $strongarm;

  return $export;
}
