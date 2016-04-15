<?php
/**
 * @file
 * uhc_course_material.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_course_material_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mat_file|node|course_material|form';
  $field_group->group_name = 'group_mat_file';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_material';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Attach a file',
    'weight' => '4',
    'children' => array(
      0 => 'field_material_file',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_mat_file|node|course_material|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_mat_link|node|course_material|form';
  $field_group->group_name = 'group_mat_link';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_material';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Create a link',
    'weight' => '5',
    'children' => array(
      0 => 'field_material_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_mat_link|node|course_material|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_material_metadata|node|course_material|form';
  $field_group->group_name = 'group_material_metadata';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_material';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '1',
    'children' => array(
      0 => 'field_material_author',
      1 => 'field_material_pub_info',
      2 => 'field_material_publication_year',
      3 => 'field_material_show_finna_link',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-material-metadata field-group-fieldset',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_material_metadata|node|course_material|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_material_title_and_section|node|course_material|form';
  $field_group->group_name = 'group_material_title_and_section';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_material';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => '',
    'weight' => '0',
    'children' => array(
      0 => 'field_material_section',
      1 => 'title',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-material-title-and-section field-group-fieldset ',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_material_title_and_section|node|course_material|form'] = $field_group;

  return $export;
}
