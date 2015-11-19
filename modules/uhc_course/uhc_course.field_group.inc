<?php
/**
 * @file
 * uhc_course.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_course_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_additional_info|node|course|default';
  $field_group->group_name = 'group_course_additional_info';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional information',
    'weight' => '11',
    'children' => array(
      0 => 'field_additional_info',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-course-additional-info field-group-accordion-item',
      ),
    ),
  );
  $export['group_course_additional_info|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_conduct|node|course|default';
  $field_group->group_name = 'group_course_conduct';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Conduct',
    'weight' => '9',
    'children' => array(
      0 => 'field_conduct',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-course-conduct field-group-accordion-item',
      ),
    ),
  );
  $export['group_course_conduct|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_contents|node|course|default';
  $field_group->group_name = 'group_course_contents';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contents',
    'weight' => '7',
    'children' => array(
      0 => 'field_contents',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-course-contents field-group-accordion-item',
      ),
    ),
  );
  $export['group_course_contents|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_drupal|node|course|form';
  $field_group->group_name = 'group_course_drupal';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Drupal system',
    'weight' => '3',
    'children' => array(
      0 => 'path',
      1 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-drupal field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_course_drupal|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_evaluation|node|course|default';
  $field_group->group_name = 'group_course_evaluation';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Evaluation',
    'weight' => '10',
    'children' => array(
      0 => 'field_evaluation',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-course-evaluation field-group-accordion-item',
      ),
    ),
  );
  $export['group_course_evaluation|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_header_image|node|course|form';
  $field_group->group_name = 'group_course_header_image';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_course_header_promotion';
  $field_group->data = array(
    'label' => 'Image',
    'weight' => '2',
    'children' => array(
      0 => 'field_imp_header_image',
      1 => 'field_imp_header_image_caption',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'formatter' => 'collapsible',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-header-image field-group-fieldset',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_course_header_image|node|course|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_header_promotion|node|course|form';
  $field_group->group_name = 'group_course_header_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promotion',
    'weight' => '0',
    'children' => array(
      0 => 'group_course_header_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-course-promotion field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_course_header_promotion|node|course|form'] = $field_group;

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
      2 => 'field_course_theme',
      3 => 'field_course_type_of_teaching',
      4 => 'title_field',
      5 => 'field_additional_info',
      6 => 'field_conduct',
      7 => 'field_contents',
      8 => 'field_course_faculty',
      9 => 'field_evaluation',
      10 => 'field_objective',
      11 => 'field_req_prerequisites',
      12 => 'field_study_credit',
      13 => 'field_study_materials',
      14 => 'field_target_group',
      15 => 'field_timing',
      16 => 'field_course_subject',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_study_materials|node|course|default';
  $field_group->group_name = 'group_course_study_materials';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Study materials',
    'weight' => '8',
    'children' => array(
      0 => 'field_study_materials',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Study materials',
      'instance_settings' => array(
        'classes' => 'group-course-study-materials field-group-accordion-item',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_course_study_materials|node|course|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_teaching_and_registration|node|course|default';
  $field_group->group_name = 'group_teaching_and_registration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Teaching and registration',
    'weight' => '6',
    'children' => array(
      0 => 'course_reference_block',
      1 => 'course_reference_block_past',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Teaching and registration',
      'instance_settings' => array(
        'classes' => 'group-teaching-and-registration field-group-accordion-item',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_teaching_and_registration|node|course|default'] = $field_group;

  return $export;
}
