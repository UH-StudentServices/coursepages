<?php
/**
 * @file
 * uhc_sources.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_sources_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_integration|node|course|form';
  $field_group->group_name = 'group_course_integration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Integration',
    'weight' => '1',
    'children' => array(
      0 => 'field_course_course_number',
      1 => 'field_course_course_tags',
      2 => 'field_req_prerequisites',
      3 => 'field_course_theme',
      4 => 'field_course_type_of_teaching',
      5 => 'title_field',
      6 => 'field_contents',
      7 => 'field_evaluation',
      8 => 'field_objective',
      9 => 'field_target_group',
      10 => 'field_timing',
      11 => 'field_study_credit',
      12 => 'field_conduct',
      13 => 'field_additional_info',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-integration field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_course_integration|node|course|form'] = $field_group;

  return $export;
}
