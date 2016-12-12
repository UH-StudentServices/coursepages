<?php
/**
 * @file
 * uhc_ds.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_ds_field_group_info() {
  $field_groups = array();

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
    'weight' => '31',
    'children' => array(),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-additional-information field-group-accordion-item',
      ),
    ),
  );
  $field_groups['group_additional_information|node|course_implementation|default'] = $field_group;

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
        'classes' => 'ds-grid-6',
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
  $field_groups['group_content_collection_left|field_collection_item|field_content_collection|default'] = $field_group;

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
        'classes' => 'ds-grid-9 ds-grid-last',
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
  $field_groups['group_content_collection_right|field_collection_item|field_content_collection|default'] = $field_group;

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
    'weight' => '19',
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
  $field_groups['group_course_messages|node|course_implementation|default'] = $field_group;

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
    'weight' => '24',
    'children' => array(
      0 => 'field_reference_to_course_tasks',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Tasks',
      'instance_settings' => array(
        'classes' => 'group-course-task-material field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_course_task_material|node|course_implementation|default'] = $field_group;

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
    'weight' => '30',
    'children' => array(
      0 => 'uhc_course_implementation_inherited_fields_additional_info',
      1 => 'uhc_course_implementation_inherited_fields_conduct',
      2 => 'uhc_course_implementation_inherited_fields_contents',
      3 => 'uhc_course_implementation_inherited_fields_evaluation',
      4 => 'uhc_course_implementation_inherited_fields_objective',
      5 => 'uhc_course_implementation_inherited_fields_rel_to_other_study_units',
      6 => 'uhc_course_implementation_inherited_fields_req_prerequisites',
      7 => 'uhc_course_implementation_inherited_fields_responsible_person',
      8 => 'uhc_course_implementation_inherited_fields_study_materials',
      9 => 'uhc_course_implementation_inherited_fields_target_group',
      10 => 'uhc_course_implementation_inherited_fields_timing',
      11 => 'uhc_course_implementation_inherited_fields_working_methods',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Course overview',
      'instance_settings' => array(
        'classes' => 'group-description-objectives field-group-accordion-item',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_description_objectives|node|course_implementation|default'] = $field_group;

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
    'weight' => '22',
    'children' => array(
      0 => 'field_imp_material_description',
      1 => 'course_implementation_material',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Material',
      'instance_settings' => array(
        'classes' => 'group-imp-material field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_material|node|course_implementation|default'] = $field_group;

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
  $field_groups['group_message_wrapper|comment|comment_node_course_implementation|full'] = $field_group;

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
    'weight' => '21',
    'children' => array(
      0 => 'event_reference_block',
      1 => 'uhc_event_teaching_schedule',
      2 => 'uhc_course_implementation_timetable_help_texts',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Timetable',
      'instance_settings' => array(
        'classes' => 'group-timetable field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_timetable|node|course_implementation|default'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Additional information');
  t('Content collection left');
  t('Content collection right');
  t('Course overview');
  t('Material');
  t('Message wrapper');
  t('Messages');
  t('Tasks');
  t('Timetable');

  return $field_groups;
}
