<?php
/**
 * @file
 * uhc_course_implementation_inherited_fields.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_course_implementation_inherited_fields_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_from_course|node|course_implementation|form';
  $field_group->group_name = 'group_from_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_imp_integration';
  $field_group->data = array(
    'label' => 'Values from course',
    'weight' => '54',
    'children' => array(
      0 => 'field_inherited_additional_info',
      1 => 'field_inherited_conduct',
      2 => 'field_inherited_contents',
      3 => 'field_inherited_evaluation',
      4 => 'field_inherited_objective',
      5 => 'field_inherited_rel_to_other_stu',
      6 => 'field_inherited_req_prerequisite',
      7 => 'field_inherited_responsible_pers',
      8 => 'field_inherited_study_materials',
      9 => 'field_inherited_target_group',
      10 => 'field_inherited_timing',
      11 => 'field_inherited_working_methods',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Values from course',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-from-course field-group-fieldset',
        'description' => 'Fields in this group are copied from referenced course/learning opportunity from the time when this implementation was active.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'collapsed',
    ),
  );
  $field_groups['group_from_course|node|course_implementation|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Values from course');

  return $field_groups;
}
