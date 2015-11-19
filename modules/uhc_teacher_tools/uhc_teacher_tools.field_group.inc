<?php
/**
 * @file
 * uhc_teacher_tools.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_teacher_tools_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_moodle|node|course_implementation|form';
  $field_group->group_name = 'group_imp_moodle';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Moodle',
    'weight' => '0',
    'children' => array(
      0 => 'field_moodle_key',
      1 => 'field_moodle_url',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Moodle',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-moodle field-group-tab',
        'description' => 'When you provide the Moodle URL, the system will automatically generate an informative text about Moodle being used in this course.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_imp_moodle|node|course_implementation|form'] = $field_group;

  return $export;
}
