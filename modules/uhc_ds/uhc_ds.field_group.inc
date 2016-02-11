<?php
/**
 * @file
 * uhc_ds.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_ds_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_additional_information|node|course_implementation|default';
  $field_group->group_name = 'group_additional_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Additional information',
    'weight' => '28',
    'children' => array(),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-additional-information field-group-accordion-item',
      ),
    ),
  );
  $export['group_additional_information|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_collection_left|field_collection_item|field_content_collection|default';
  $field_group->group_name = 'group_content_collection_left';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_content_collection';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content collection left',
    'weight' => '0',
    'children' => array(
      0 => 'field_content_image',
      1 => 'field_related_content',
      2 => 'title_field',
      3 => 'field_related_content_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content collection left',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'ds-grid-8',
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
  $export['group_content_collection_left|field_collection_item|field_content_collection|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_content_collection_right|field_collection_item|field_content_collection|default';
  $field_group->group_name = 'group_content_collection_right';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_content_collection';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content collection right',
    'weight' => '1',
    'children' => array(
      0 => 'field_body',
      1 => 'field_link_multiple',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content collection right',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'ds-grid-14 ds-grid-last',
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
  $export['group_content_collection_right|field_collection_item|field_content_collection|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_messages|node|course_implementation|default';
  $field_group->group_name = 'group_course_messages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Messages',
    'weight' => '17',
    'children' => array(
      0 => 'comments',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Messages',
      'instance_settings' => array(
        'classes' => 'group-course-messages field-group-accordion-item',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_course_messages|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_task_material|node|course_implementation|default';
  $field_group->group_name = 'group_course_task_material';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tasks',
    'weight' => '22',
    'children' => array(
      0 => 'field_reference_to_course_tasks',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Tasks',
      'instance_settings' => array(
        'classes' => 'group-course-task-material field-group-accordion-item',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_course_task_material|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description_objectives|node|course_implementation|default';
  $field_group->group_name = 'group_description_objectives';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course overview',
    'weight' => '27',
    'children' => array(
      0 => 'field_imp_working_methods',
      1 => 'uhc_ds_additional_info',
      2 => 'uhc_ds_req_prerequisites',
      3 => 'uhc_ds_contents',
      4 => 'uhc_ds_evaluation',
      5 => 'uhc_ds_objective',
      6 => 'uhc_ds_target_group',
      7 => 'uhc_ds_study_materials',
      8 => 'uhc_ds_conduct',
      9 => 'uhc_ds_timing',
      10 => 'uhc_ds_responsible_person',
      11 => 'uhc_ds_rel_to_other_study_units',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Course overview',
      'instance_settings' => array(
        'classes' => 'group-description-objectives field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_description_objectives|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_material|node|course_implementation|default';
  $field_group->group_name = 'group_imp_material';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Material',
    'weight' => '20',
    'children' => array(
      0 => 'field_imp_material_description',
      1 => 'course_implementation_material',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Material',
      'instance_settings' => array(
        'classes' => 'group-imp-material field-group-accordion-item',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_imp_material|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_message_wrapper|comment|comment_node_course_implementation|full';
  $field_group->group_name = 'group_message_wrapper';
  $field_group->entity_type = 'comment';
  $field_group->bundle = 'comment_node_course_implementation';
  $field_group->mode = 'full';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Message wrapper',
    'weight' => '1',
    'children' => array(
      0 => 'comment_body',
      1 => 'message_header',
      2 => 'links',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Message wrapper',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'message-wrapper',
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
  $export['group_message_wrapper|comment|comment_node_course_implementation|full'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_timetable|node|course_implementation|default';
  $field_group->group_name = 'group_timetable';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Timetable',
    'weight' => '19',
    'children' => array(
      0 => 'event_reference_block',
      1 => 'repeating_event_reference_block',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-timetable field-group-accordion-item',
      ),
    ),
  );
  $export['group_timetable|node|course_implementation|default'] = $field_group;

  return $export;
}
