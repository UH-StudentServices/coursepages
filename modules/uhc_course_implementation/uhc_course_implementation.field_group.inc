<?php
/**
 * @file
 * uhc_course_implementation.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_course_implementation_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_accordion_content|node|course_implementation|teaser_accordion';
  $field_group->group_name = 'group_accordion_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'teaser_accordion';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course Information',
    'weight' => '1',
    'children' => array(
      0 => 'field_additional_info',
      1 => 'field_conduct',
      2 => 'field_imp_fee',
      3 => 'course_overview_link',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Course Information',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'field-group-accordion-item',
        'description' => '',
        'show_label' => '1',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_accordion_content|node|course_implementation|teaser_accordion'] = $field_group;

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
    'weight' => '24',
    'children' => array(
      0 => 'field_imp_teacher_se_content',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'label' => 'Conduct of the course',
      'instance_settings' => array(
        'classes' => 'group-conduct-of-course field-group-accordion-item',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_conduct_of_course|node|course_implementation|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_course_overview|node|course_implementation|form';
  $field_group->group_name = 'group_course_overview';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course overview',
    'weight' => '12',
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
      'label' => 'Course overview',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-course-overview field-group-tab',
        'description' => 'Course overview texts are imported from Oodi',
        'show_empty_fields' => 1,
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_course_overview|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_feedback|node|course_implementation|form';
  $field_group->group_name = 'group_feedback';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Feedback',
    'weight' => '11',
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
  $export['group_feedback|node|course_implementation|form'] = $field_group;

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
    'label' => 'Promotion',
    'weight' => '1',
    'children' => array(
      0 => 'field_imp_header_text',
      1 => 'group_headline_and_intro',
      2 => 'group_imp_header_img',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Promotion',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-header-promotion field-group-tab',
        'description' => 'Add an image, headline and text',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_header_promotion|node|course_implementation|form'] = $field_group;

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
    'label' => 'Headline and Intro text',
    'weight' => '22',
    'children' => array(
      0 => 'field_imp_header_headline',
      1 => 'field_field_imp_header_intro_tex',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Headline and Intro text',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-headline-and-intro field-group-fieldset',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_headline_and_intro|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_conduct_of_course|node|course_implementation|form';
  $field_group->group_name = 'group_imp_conduct_of_course';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Conduct of the course',
    'weight' => '10',
    'children' => array(
      0 => 'field_imp_teacher_se_content',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Conduct of the course',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-conduct-of-course field-group-tab',
        'description' => 'Specify how the course is conducted and how the students are evaluated',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_imp_conduct_of_course|node|course_implementation|form'] = $field_group;

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
    'weight' => '25',
    'children' => array(
      0 => 'field_feedback_link',
      1 => 'field_feedback_description',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-imp-feedback field-group-accordion-item',
      ),
    ),
  );
  $export['group_imp_feedback|node|course_implementation|default'] = $field_group;

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
    'weight' => '26',
    'children' => array(
      0 => 'field_imp_fee',
      1 => 'field_open_uni_registration',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-imp-fee field-group-accordion-item',
      ),
    ),
  );
  $export['group_imp_fee|node|course_implementation|default'] = $field_group;

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
    'label' => 'Image',
    'weight' => '21',
    'children' => array(
      0 => 'field_imp_header_image',
      1 => 'field_imp_header_image_caption',
    ),
    'format_type' => 'fieldset',
    'format_settings' => array(
      'label' => 'Image',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-imp-header-img field-group-fieldset',
        'description' => '',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_imp_header_img|node|course_implementation|form'] = $field_group;

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
    'weight' => '13',
    'children' => array(
      0 => 'field_imp_begin_date',
      1 => 'field_imp_canonical_url',
      2 => 'field_imp_end_date',
      3 => 'field_imp_id',
      4 => 'field_imp_reference_to_courses',
      5 => 'field_imp_teacher',
      6 => 'field_imp_teacher_number',
      7 => 'title_field',
      8 => 'field_imp_course_organiser',
      9 => 'field_imp_giver_locality',
      10 => 'field_imp_locality',
      11 => 'field_imp_method_of_study',
      12 => 'field_imp_start_month',
      13 => 'field_imp_teaching_language',
      14 => 'field_study_credit',
      15 => 'field_timing',
      16 => 'field_imp_administrator_number',
      17 => 'field_imp_keywords',
      18 => 'field_imp_organisation',
      19 => 'field_imp_enrollment_begin_date',
      20 => 'field_imp_enrollment_end_date',
      21 => 'field_cancelled',
      22 => 'field_rel_to_other_study_units',
      23 => 'field_responsible_person',
      24 => 'field_working_methods',
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
  $export['group_imp_integration|node|course_implementation|form'] = $field_group;

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
    'weight' => '18',
    'children' => array(
      0 => 'field_imp_interaction_link',
      1 => 'field_imp_interactiondescription',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-imp-interaction field-group-accordion-item',
      ),
    ),
  );
  $export['group_imp_interaction|node|course_implementation|default'] = $field_group;

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
    'weight' => '4',
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
  $export['group_imp_interaction|node|course_implementation|form'] = $field_group;

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
    'weight' => '6',
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
        'description' => 'Add lecture notes, literature, links etc. It is not advisable to add private material because it might be accessible through direct links. Please attach only material which you have sufficient rights to use!',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_imp_material|node|course_implementation|form'] = $field_group;

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
    'weight' => '16',
    'children' => array(
      0 => 'field_moodle_url',
      1 => 'uhc_ds_moodle_key_or_login',
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
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_imp_moodle|node|course_implementation|default'] = $field_group;

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
    'weight' => '14',
    'children' => array(
      0 => 'field_imp_hide_sign_up_button',
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
  $export['group_imp_signup|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_tasks|node|course_implementation|form';
  $field_group->group_name = 'group_imp_tasks';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Tasks',
    'weight' => '8',
    'children' => array(
      0 => 'field_reference_to_course_tasks',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Tasks',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => '',
        'description' => 'Add tasks with instructions and material',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_imp_tasks|node|course_implementation|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_imp_teaser_conduct|node|course_implementation|teaser_accordion';
  $field_group->group_name = 'group_imp_teaser_conduct';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'course_implementation';
  $field_group->mode = 'teaser_accordion';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Course conduct',
    'weight' => '43',
    'children' => array(
      0 => 'field_imp_teacher_se_content',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Course conduct',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'ds-teaser-accordion--content-field',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_imp_teaser_conduct|node|course_implementation|teaser_accordion'] = $field_group;

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
    'weight' => '21',
    'children' => array(
      0 => 'field_imp_video',
    ),
    'format_type' => 'accordion-item',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'classes' => 'group-imp-video field-group-accordion-item',
      ),
    ),
  );
  $export['group_imp_video|node|course_implementation|default'] = $field_group;

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
    'weight' => '7',
    'children' => array(
      0 => 'field_imp_video',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-imp-video field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_imp_video|node|course_implementation|form'] = $field_group;

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
    'weight' => '9',
    'children' => array(
      0 => 'field_imp_teachersection',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Custom section',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-manual-content field-group-tab',
        'description' => 'Add your own section with its own label',
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_manual_content|node|course_implementation|form'] = $field_group;

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
    'weight' => '3',
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
  $export['group_messages|node|course_implementation|form'] = $field_group;

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
    'weight' => '5',
    'children' => array(
      0 => 'field_imp_ref_to_events_oodi',
      1 => 'field_imp_reference_to_events',
      2 => 'field_imp_events_title',
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
  $export['group_timetable|node|course_implementation|form'] = $field_group;

  return $export;
}
