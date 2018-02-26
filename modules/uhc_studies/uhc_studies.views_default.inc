<?php
/**
 * @file
 * uhc_studies.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_studies_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'course_implementations_by_course_degree_programme';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course implementations by course degree programme';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'By degree programme';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_field',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'list-of-links accordion-content-item field-group-accordion-item';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['required'] = TRUE;
  /* Relationship: Content: Degree programme (field_course_degree_programme) */
  $handler->display->display_options['relationships']['field_course_degree_programme_tid']['id'] = 'field_course_degree_programme_tid';
  $handler->display->display_options['relationships']['field_course_degree_programme_tid']['table'] = 'field_data_field_course_degree_programme';
  $handler->display->display_options['relationships']['field_course_degree_programme_tid']['field'] = 'field_course_degree_programme_tid';
  $handler->display->display_options['relationships']['field_course_degree_programme_tid']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_course_degree_programme_tid']['required'] = TRUE;
  /* Field: Content: Credit */
  $handler->display->display_options['fields']['field_study_credit']['id'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['table'] = 'field_data_field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['field'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['label'] = '';
  $handler->display->display_options['fields']['field_study_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_study_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_study_credit']['alter']['text'] = '[field_study_credit] cr';
  $handler->display->display_options['fields']['field_study_credit']['element_label_colon'] = FALSE;
  /* Field: Content: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'field_data_field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['label'] = '';
  $handler->display->display_options['fields']['field_imp_method_of_study']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title], [field_imp_method_of_study], [field_study_credit]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'list-of-links__link button--action icon--arrow-right theme-transparent';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['relationship'] = 'field_course_degree_programme_tid';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Sort criterion: Taxonomy term: Name (name_field) */
  $handler->display->display_options['sorts']['name_field_value']['id'] = 'name_field_value';
  $handler->display->display_options['sorts']['name_field_value']['table'] = 'field_data_name_field';
  $handler->display->display_options['sorts']['name_field_value']['field'] = 'name_field_value';
  $handler->display->display_options['sorts']['name_field_value']['relationship'] = 'field_course_degree_programme_tid';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_implementation' => 'course_implementation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Providing organisation code (field_imp_providing_org_code) */
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['id'] = 'field_imp_providing_org_code_value';
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['table'] = 'field_data_field_imp_providing_org_code';
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['field'] = 'field_imp_providing_org_code_value';
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['value'] = '93012';
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['course_implementations_by_course_degree_programme'] = array(
    t('Master'),
    t('By degree programme'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_imp_reference_to_courses'),
    t('term from field_course_degree_programme'),
    t('[field_study_credit] cr'),
    t('[title], [field_imp_method_of_study], [field_study_credit]'),
    t('Block'),
  );
  $export['course_implementations_by_course_degree_programme'] = $view;

  $view = new view();
  $view->name = 'course_implementations_by_course_subject';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course implementations by course subject';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'By topic';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_course_subject',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'list-of-links accordion-content-item field-group-accordion-item';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['required'] = TRUE;
  /* Field: Content: Credit */
  $handler->display->display_options['fields']['field_study_credit']['id'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['table'] = 'field_data_field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['field'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['label'] = '';
  $handler->display->display_options['fields']['field_study_credit']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_study_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_study_credit']['alter']['text'] = '[field_study_credit] cr';
  $handler->display->display_options['fields']['field_study_credit']['element_label_colon'] = FALSE;
  /* Field: Content: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'field_data_field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['label'] = '';
  $handler->display->display_options['fields']['field_imp_method_of_study']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['text'] = '[title], [field_imp_method_of_study], [field_study_credit]';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title']['alter']['link_class'] = 'list-of-links__link button--action icon--arrow-right theme-transparent';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  /* Field: Content: Subject */
  $handler->display->display_options['fields']['field_course_subject']['id'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['field'] = 'field_course_subject';
  $handler->display->display_options['fields']['field_course_subject']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_subject']['label'] = '';
  $handler->display->display_options['fields']['field_course_subject']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_subject']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_subject']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
    'field_multiple_limit_order' => '0',
  );
  $handler->display->display_options['fields']['field_course_subject']['delta_offset'] = '0';
  /* Sort criterion: Content: Subject (field_course_subject) */
  $handler->display->display_options['sorts']['field_course_subject_value']['id'] = 'field_course_subject_value';
  $handler->display->display_options['sorts']['field_course_subject_value']['table'] = 'field_data_field_course_subject';
  $handler->display->display_options['sorts']['field_course_subject_value']['field'] = 'field_course_subject_value';
  $handler->display->display_options['sorts']['field_course_subject_value']['relationship'] = 'field_imp_reference_to_courses_target_id';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_implementation' => 'course_implementation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Providing organisation code (field_imp_providing_org_code) */
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['id'] = 'field_imp_providing_org_code_value';
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['table'] = 'field_data_field_imp_providing_org_code';
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['field'] = 'field_imp_providing_org_code_value';
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['value'] = '93012';
  $handler->display->display_options['filters']['field_imp_providing_org_code_value']['group'] = 1;
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['granularity'] = 'year';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_text';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['default_date'] = 'now';

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['course_implementations_by_course_subject'] = array(
    t('Master'),
    t('By topic'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_imp_reference_to_courses'),
    t('[field_study_credit] cr'),
    t('[title], [field_imp_method_of_study], [field_study_credit]'),
    t('Block'),
  );
  $export['course_implementations_by_course_subject'] = $view;

  $view = new view();
  $view->name = 'studies_by_category';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'taxonomy_term_data';
  $view->human_name = 'Studies by category';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'By topic';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['distinct'] = TRUE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'name_field',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['class'] = 'list-of-links accordion-content-item field-group-accordion-item';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Taxonomy term: Content with term */
  $handler->display->display_options['relationships']['nid']['id'] = 'nid';
  $handler->display->display_options['relationships']['nid']['table'] = 'taxonomy_index';
  $handler->display->display_options['relationships']['nid']['field'] = 'nid';
  $handler->display->display_options['relationships']['nid']['required'] = TRUE;
  /* Field: Taxonomy term: Name */
  $handler->display->display_options['fields']['name_field']['id'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['table'] = 'field_data_name_field';
  $handler->display->display_options['fields']['name_field']['field'] = 'name_field';
  $handler->display->display_options['fields']['name_field']['label'] = '';
  $handler->display->display_options['fields']['name_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['name_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['name_field']['link_to_entity'] = 0;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'nid';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'nid';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title_field']['alter']['link_class'] = 'list-of-links__link button--action icon--arrow-right theme-transparent';
  $handler->display->display_options['fields']['title_field']['element_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'title_style' => '_none',
    'title_link' => 'content',
    'title_class' => '',
  );
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Sort criterion: Field: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['relationship'] = 'nid';
  /* Filter criterion: Taxonomy vocabulary: Machine name */
  $handler->display->display_options['filters']['machine_name']['id'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['table'] = 'taxonomy_vocabulary';
  $handler->display->display_options['filters']['machine_name']['field'] = 'machine_name';
  $handler->display->display_options['filters']['machine_name']['value'] = array(
    'subject_category' => 'subject_category',
  );
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'nid';
  $handler->display->display_options['filters']['status']['value'] = '1';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['relationship'] = 'nid';
  $handler->display->display_options['filters']['type']['value'] = array(
    'studies' => 'studies',
    'subject' => 'subject',
  );
  /* Filter criterion: Field: Title (title_field:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['relationship'] = 'nid';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['studies_by_category'] = array(
    t('Master'),
    t('By topic'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('node'),
    t('Block'),
  );
  $export['studies_by_category'] = $view;

  $view = new view();
  $view->name = 'studies_by_degree_programme';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Studies by degree programme';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'By degree programme';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['class'] = 'list-of-links';
  $handler->display->display_options['style_options']['wrapper_class'] = '';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['title_field']['alter']['link_class'] = 'list-of-links__link button--action icon--arrow-right theme-transparent';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Sort criterion: Field: Title (title_field) */
  $handler->display->display_options['sorts']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['sorts']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['sorts']['title_field_value']['field'] = 'title_field_value';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'studies' => 'studies',
  );
  /* Filter criterion: Content: This page is a degree programme (field_stuides_is_degree_programm) */
  $handler->display->display_options['filters']['field_stuides_is_degree_programm_value']['id'] = 'field_stuides_is_degree_programm_value';
  $handler->display->display_options['filters']['field_stuides_is_degree_programm_value']['table'] = 'field_data_field_stuides_is_degree_programm';
  $handler->display->display_options['filters']['field_stuides_is_degree_programm_value']['field'] = 'field_stuides_is_degree_programm_value';
  $handler->display->display_options['filters']['field_stuides_is_degree_programm_value']['value'] = array(
    1 => '1',
  );
  /* Filter criterion: Field: Title (title_field:language) */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $translatables['studies_by_degree_programme'] = array(
    t('Master'),
    t('By degree programme'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Block'),
  );
  $export['studies_by_degree_programme'] = $view;

  return $export;
}
