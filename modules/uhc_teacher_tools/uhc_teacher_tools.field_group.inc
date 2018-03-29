<?php
/**
 * @file
 * uhc_teacher_tools.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_teacher_tools_field_group_info() {
  $field_groups = array();

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
    'weight' => '2',
    'children' => array(
      0 => 'group_moodle_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Moodle',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-moodle field-group-tab',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_moodle|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_moodle_link|node|course_implementation|form';
  $field_group->group_name = 'group_moodle_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_imp_moodle';
  $field_group->data = array(
    'label' => 'Link an existing Moodle course area',
    'weight' => '57',
    'children' => array(
      0 => 'field_moodle_key',
      1 => 'field_moodle_url',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Link an existing Moodle course area',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Add the URL for the Moodle course area as well as the enrolment key. The URL will be added as a button to the course page. The URL will be also visible in My Studies and My Teaching pages. The enrolment key is only displayed for students who are registered in WebOodi.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_moodle_link|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_wiki|node|course_implementation|form';
  $field_group->group_name = 'group_wiki';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Wiki',
    'weight' => '3',
    'children' => array(
      0 => 'field_wiki_url',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Wiki',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-wiki field-group-tab',
        'description' => 'When you provide the Wiki URL, the system will automatically generate an informative text about Wiki being used in this course.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_wiki|node|course_implementation|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Link an existing Moodle course area');
  t('Moodle');
  t('Wiki');

  return $field_groups;
}
