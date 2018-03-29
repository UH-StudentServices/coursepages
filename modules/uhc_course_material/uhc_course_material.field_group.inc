<?php
/**
 * @file
 * uhc_course_material.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_course_material_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_material_form_left|node|course_material|form';
  $field_group->group_name = 'group_material_form_left';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_material';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Left',
    'weight' => '3',
    'children' => array(
      0 => 'field_private',
      1 => 'field_material_section',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Left',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-material-form-left',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_material_form_left|node|course_material|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_material_form_right|node|course_material|form';
  $field_group->group_name = 'group_material_form_right';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_material';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Right',
    'weight' => '4',
    'children' => array(
      0 => 'field_material_author',
      1 => 'field_material_pub_info',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Right',
      'instance_settings' => array(
        'required_fields' => 1,
        'id' => '',
        'classes' => 'group-material-form-right',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_material_form_right|node|course_material|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Left');
  t('Right');

  return $field_groups;
}
