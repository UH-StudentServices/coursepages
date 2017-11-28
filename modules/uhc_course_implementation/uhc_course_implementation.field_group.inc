<?php
/**
 * @file
 * uhc_course_implementation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_course_implementation_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conduct_of_course|node|course_implementation|default';
  $field_group->group_name = 'group_conduct_of_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Conduct of the course',
    'weight' => '28',
    'children' => array(
      0 => 'field_imp_teacher_se_content',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Conduct of the course',
      'instance_settings' => array(
        'classes' => 'group-conduct-of-course field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_conduct_of_course|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_conduct_of_course|node|course_implementation|form';
  $field_group->group_name = 'group_conduct_of_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Conduct of the course',
    'weight' => '11',
    'children' => array(
      0 => 'field_imp_teacher_se_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Conduct of the course',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-conduct-of-course field-group-tab',
        'description' => 'Specify how the course is conducted and how the learning will be evaluated',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_conduct_of_course|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_task_material|node|course_implementation|form';
  $field_group->group_name = 'group_course_task_material';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tasks',
    'weight' => '9',
    'children' => array(
      0 => 'field_reference_to_course_tasks',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Tasks',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'As a teacher, you can enter course assignments here for students. However, assignments cannot be returned through this service. If you wish students to return their assignments electronically, we recommend using Moodle.',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_course_task_material|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_description_objectives|node|course_implementation|form';
  $field_group->group_name = 'group_description_objectives';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Description',
    'weight' => '14',
    'children' => array(
      0 => 'field_additional_info',
      1 => 'field_conduct',
      2 => 'field_contents',
      3 => 'field_evaluation',
      4 => 'field_imp_fee',
      5 => 'field_objective',
      6 => 'field_req_prerequisites',
      7 => 'field_study_materials',
      8 => 'field_target_group',
      9 => 'field_open_uni_registration',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Description',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-course-overview field-group-tab',
        'description' => 'Course overview texts are imported from Oodi',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_description_objectives|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header_promotion|node|course_implementation|form';
  $field_group->group_name = 'group_header_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Introduction',
    'weight' => '1',
    'children' => array(
      0 => 'field_imp_header_text',
      1 => 'group_headline_and_intro',
      2 => 'group_imp_header_img',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Introduction',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-header-promotion field-group-tab',
        'description' => 'Add an image, headline and text',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_header_promotion|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_headline_and_intro|node|course_implementation|form';
  $field_group->group_name = 'group_headline_and_intro';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header_promotion';
  $field_group->data = array(
    'label' => '',
    'weight' => '22',
    'children' => array(
      0 => 'field_imp_header_headline',
      1 => 'field_field_imp_header_intro_tex',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-headline-and-intro field-group-fieldset',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_headline_and_intro|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_feedback|node|course_implementation|default';
  $field_group->group_name = 'group_imp_feedback';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Feedback',
    'weight' => '30',
    'children' => array(
      0 => 'field_feedback_link',
      1 => 'field_feedback_description',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Feedback',
      'instance_settings' => array(
        'classes' => 'group-imp-feedback field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_feedback|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_feedback|node|course_implementation|form';
  $field_group->group_name = 'group_imp_feedback';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Feedback',
    'weight' => '13',
    'children' => array(
      0 => 'field_feedback_link',
      1 => 'field_feedback_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Feedback',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-imp-feedback field-group-tab',
        'description' => 'Please add the URL address to the form or service used.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_feedback|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_fee|node|course_implementation|default';
  $field_group->group_name = 'group_imp_fee';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Registration and fee',
    'weight' => '31',
    'children' => array(
      0 => 'uhc_ds_fee',
      1 => 'uhc_ds_open_uni_registration',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Registration and fee',
      'instance_settings' => array(
        'classes' => 'group-imp-fee field-group-accordion-item hide-labels',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_fee|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_header_img|node|course_implementation|form';
  $field_group->group_name = 'group_imp_header_img';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = 'group_header_promotion';
  $field_group->data = array(
    'label' => '',
    'weight' => '21',
    'children' => array(
      0 => 'field_imp_header_image',
      1 => 'field_imp_header_image_caption',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => '',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-header-img field-group-fieldset',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_imp_header_img|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_integration|node|course_implementation|form';
  $field_group->group_name = 'group_imp_integration';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Integration',
    'weight' => '15',
    'children' => array(
      0 => 'field_imp_begin_date',
      1 => 'field_imp_end_date',
      2 => 'field_imp_id',
      3 => 'field_imp_reference_to_courses',
      4 => 'field_imp_teacher',
      5 => 'field_imp_teacher_number',
      6 => 'title_field',
      7 => 'field_imp_course_organiser',
      8 => 'field_imp_giver_locality',
      9 => 'field_imp_locality',
      10 => 'field_imp_method_of_study',
      11 => 'field_imp_start_month',
      12 => 'field_imp_teaching_language',
      13 => 'field_study_credit',
      14 => 'field_timing',
      15 => 'field_imp_administrator_number',
      16 => 'field_imp_keywords',
      17 => 'field_imp_organisation',
      18 => 'field_imp_enrollment_begin_date',
      19 => 'field_imp_enrollment_end_date',
      20 => 'field_cancelled',
      21 => 'field_rel_to_other_study_units',
      22 => 'field_responsible_person',
      23 => 'field_working_methods',
      24 => 'field_hierarchy_children',
      25 => 'field_hierarchy_parent_id',
      26 => 'field_hierarchy_position',
      27 => 'field_imp_extra_organisation',
      28 => 'group_from_course',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Integration',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-imp-integration field-group-tab',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_integration|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_interaction|node|course_implementation|default';
  $field_group->group_name = 'group_imp_interaction';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Interaction',
    'weight' => '22',
    'children' => array(
      0 => 'field_imp_interaction_link',
      1 => 'field_imp_interactiondescription',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Interaction',
      'instance_settings' => array(
        'classes' => 'group-imp-interaction field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_interaction|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_interaction|node|course_implementation|form';
  $field_group->group_name = 'group_imp_interaction';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Interaction',
    'weight' => '5',
    'children' => array(
      0 => 'field_imp_interaction_link',
      1 => 'field_imp_interactiondescription',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Interaction',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-imp-interaction field-group-tab',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_interaction|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_material|node|course_implementation|form';
  $field_group->group_name = 'group_imp_material';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Material',
    'weight' => '7',
    'children' => array(
      0 => 'field_imp_material_description',
      1 => 'field_section_material',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Material',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-material field-group-tab',
        'description' => 'Add lecture notes, literature, links etc. It is not advisable to add confidential material because it might be accessible through direct links. Please attach only material which you have sufficient rights to use!',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_material|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_moodle|node|course_implementation|default';
  $field_group->group_name = 'group_imp_moodle';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Learning environments',
    'weight' => '20',
    'children' => array(
      0 => 'field_moodle_url',
      1 => 'field_wiki_url',
      2 => 'uhc_ds_moodle_key_or_login',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Learning environments',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'tube--large horizontal-rule-top',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_imp_moodle|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_results|node|course_implementation|default';
  $field_group->group_name = 'group_imp_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Results',
    'weight' => '29',
    'children' => array(
      0 => 'field_imp_results',
      1 => 'uhc_course_implementation_exam_results_info_text',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Results',
      'instance_settings' => array(
        'classes' => 'group-imp-results field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_results|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_results|node|course_implementation|form';
  $field_group->group_name = 'group_imp_results';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Results',
    'weight' => '12',
    'children' => array(
      0 => 'field_imp_results',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Results',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-results field-group-tab',
        'description' => 'Publish the results preferably in pdf format. Use student numbers, not names of individuals. Results are shown only for students of the course and are available for 6 months. After this, the files are automatically deleted from the system.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_results|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_signup|node|course_implementation|form';
  $field_group->group_name = 'group_imp_signup';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Enrolment',
    'weight' => '16',
    'children' => array(
      0 => 'field_imp_hide_sign_up_button',
      1 => 'field_imp_flexible_start',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-imp-signup field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_imp_signup|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_video|node|course_implementation|default';
  $field_group->group_name = 'group_imp_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '25',
    'children' => array(
      0 => 'field_video_description',
      1 => 'field_video_embed_url',
      2 => 'field_video_link',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Video',
      'instance_settings' => array(
        'classes' => 'group-imp-video field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_video|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_video|node|course_implementation|form';
  $field_group->group_name = 'group_imp_video';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Video',
    'weight' => '8',
    'children' => array(
      0 => 'field_video_description',
      1 => 'field_video_embed_url',
      2 => 'field_video_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Video',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-imp-video field-group-tab',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_imp_video|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_manual_content|field_collection_item|field_imp_teachersection|default';
  $field_group->group_name = 'group_manual_content';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_imp_teachersection';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom section',
    'weight' => '0',
    'children' => array(
      0 => 'field_imp_teachersection_content',
      1 => 'field_imp_teachersection_label',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Custom section',
      'instance_settings' => array(
        'classes' => 'group-manual-content field-group-accordion-item',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $field_groups['group_manual_content|field_collection_item|field_imp_teachersection|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = TRUE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_manual_content|node|course_implementation|default';
  $field_group->group_name = 'group_manual_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom Section',
    'weight' => '24',
    'children' => array(
      0 => 'field_imp_teachersection',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Custom Section',
      'instance_settings' => array(
        'classes' => 'group-manual-content field-group-accordion-item',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_manual_content|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_manual_content|node|course_implementation|form';
  $field_group->group_name = 'group_manual_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Custom section',
    'weight' => '10',
    'children' => array(
      0 => 'field_imp_teachersection',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Custom section',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-manual-content field-group-tab',
        'description' => 'Add your own sections with their own labels.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_manual_content|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_messages|node|course_implementation|form';
  $field_group->group_name = 'group_messages';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Messages',
    'weight' => '4',
    'children' => array(),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Messages',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-messages field-group-tab',
        'description' => 'Add or edit messages in page view mode',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_messages|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_timetable|node|course_implementation|form';
  $field_group->group_name = 'group_timetable';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Timetable',
    'weight' => '6',
    'children' => array(
      0 => 'field_imp_reference_to_events',
      1 => 'field_imp_events_title',
      2 => 'field_imp_timetable_additional',
      3 => 'field_imp_events_json',
      4 => 'field_imp_events_raw',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Timetable',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-timetable field-group-tab',
        'description' => 'The teaching schedule is imported from WebOodi. Therefore all updates to the teaching schedule should be done in WebOodi. Other events are updated here.',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_timetable|node|course_implementation|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Conduct of the course');
  t('Custom Section');
  t('Custom section');
  t('Description');
  t('Enrolment');
  t('Feedback');
  t('Integration');
  t('Interaction');
  t('Introduction');
  t('Learning environments');
  t('Material');
  t('Messages');
  t('Registration and fee');
  t('Results');
  t('Tasks');
  t('Timetable');
  t('Video');

  return $field_groups;
}
