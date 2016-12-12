<?php
/**
 * @file
 * uhc_tour.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_tour_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_tour|node|course_implementation|form';
  $field_group->group_name = 'group_tour';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tour',
    'weight' => '17',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Tour',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_tour|node|course_implementation|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Tour');

  return $field_groups;
}
