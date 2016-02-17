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
  $field_group->identifier = 'group_accordion_content|node|course|teaser';
  $field_group->group_name = 'group_accordion_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course';
  $field_group->mode = 'teaser';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Accordion content',
    'weight' => '2',
    'children' => array(
      0 => 'field_objective',
      1 => 'field_req_prerequisites',
      2 => 'uhc_ds_course_reference_accordion',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Accordion content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'field-group-accordion-item',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_accordion_content|node|course|teaser'] = $field_group;

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
      8 => 'field_evaluation',
      9 => 'field_objective',
      10 => 'field_req_prerequisites',
      11 => 'field_study_credit',
      12 => 'field_study_materials',
      13 => 'field_target_group',
      14 => 'field_timing',
      15 => 'field_course_subject',
      16 => 'field_course_faculty',
      17 => 'field_rel_to_other_study_units',
      18 => 'field_responsible_person',
      19 => 'field_working_methods',
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
