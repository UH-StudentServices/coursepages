<?php
/**
 * @file
 * uhc_dev_feature.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_dev_feature_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'admin_courseless_implementations';
  $view->description = 'Tool for identifying courseless implementations.';
  $view->tag = 'uhc_dev_feature';
  $view->base_table = 'node';
  $view->human_name = 'Courseless implementations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Courseless implementations';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_course_course_number' => 'field_course_course_number',
    'title_1' => 'title_1',
    'title' => 'title',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_course_course_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'All course implementations seems to have courses in Drupal.';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['label'] = 'Course';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_imp_id']['id'] = 'field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['field'] = 'field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['label'] = 'Course implementation ID';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'long';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'long';
  /* Field: Content: Updated date */
  $handler->display->display_options['fields']['changed']['id'] = 'changed';
  $handler->display->display_options['fields']['changed']['table'] = 'node';
  $handler->display->display_options['fields']['changed']['field'] = 'changed';
  $handler->display->display_options['fields']['changed']['date_format'] = 'long';
  $handler->display->display_options['fields']['changed']['second_date_format'] = 'long';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_implementation' => 'course_implementation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Course number (field_course_course_number) */
  $handler->display->display_options['filters']['field_course_course_number_value']['id'] = 'field_course_course_number_value';
  $handler->display->display_options['filters']['field_course_course_number_value']['table'] = 'field_data_field_course_course_number';
  $handler->display->display_options['filters']['field_course_course_number_value']['field'] = 'field_course_course_number_value';
  $handler->display->display_options['filters']['field_course_course_number_value']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['filters']['field_course_course_number_value']['operator'] = 'empty';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/courseless-implementations';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Courseless';
  $handler->display->display_options['menu']['weight'] = '1';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['admin_courseless_implementations'] = array(
    t('Master'),
    t('Courseless implementations'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('All course implementations seems to have courses in Drupal.'),
    t('Course'),
    t('Title'),
    t('Course implementation ID'),
    t('Nid'),
    t('Post date'),
    t('Updated date'),
    t('Page'),
  );
  $export['admin_courseless_implementations'] = $view;

  $view = new view();
  $view->name = 'admin_courses';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Admin courses';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Admin courses';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'administer nodes';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '20';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'nothing',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['columns'] = array(
    'field_course_course_number' => 'field_course_course_number',
    'title_1' => 'title_1',
    'title' => 'title',
    'nothing' => 'nothing',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_course_course_number' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_1' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'nothing' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['label'] = 'Course';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['required'] = TRUE;
  /* Field: Content: Course number */
  $handler->display->display_options['fields']['field_course_course_number']['id'] = 'field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['table'] = 'field_data_field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['field'] = 'field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_course_number']['label'] = '';
  $handler->display->display_options['fields']['field_course_course_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_course_number']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title_1']['id'] = 'title_1';
  $handler->display->display_options['fields']['title_1']['table'] = 'node';
  $handler->display->display_options['fields']['title_1']['field'] = 'title';
  $handler->display->display_options['fields']['title_1']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['title_1']['label'] = '';
  $handler->display->display_options['fields']['title_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_1']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_course_course_number] - [title_1]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_implementation' => 'course_implementation',
  );
  $handler->display->display_options['filters']['type']['group'] = 1;
  /* Filter criterion: Content: Keywords (field_imp_keywords) */
  $handler->display->display_options['filters']['field_imp_keywords_value']['id'] = 'field_imp_keywords_value';
  $handler->display->display_options['filters']['field_imp_keywords_value']['table'] = 'field_data_field_imp_keywords';
  $handler->display->display_options['filters']['field_imp_keywords_value']['field'] = 'field_imp_keywords_value';
  $handler->display->display_options['filters']['field_imp_keywords_value']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_keywords_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_keywords_value']['expose']['operator_id'] = 'field_imp_keywords_value_op';
  $handler->display->display_options['filters']['field_imp_keywords_value']['expose']['label'] = 'Keywords (field_imp_keywords)';
  $handler->display->display_options['filters']['field_imp_keywords_value']['expose']['operator'] = 'field_imp_keywords_value_op';
  $handler->display->display_options['filters']['field_imp_keywords_value']['expose']['identifier'] = 'field_imp_keywords_value';
  $handler->display->display_options['filters']['field_imp_keywords_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_imp_keywords_value']['group_info']['label'] = 'Keyword';
  $handler->display->display_options['filters']['field_imp_keywords_value']['group_info']['identifier'] = 'field_imp_keywords_value';
  $handler->display->display_options['filters']['field_imp_keywords_value']['group_info']['group_items'] = array(
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: Organisation (field_imp_organisation) */
  $handler->display->display_options['filters']['field_imp_organisation_tid']['id'] = 'field_imp_organisation_tid';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['table'] = 'field_data_field_imp_organisation';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['field'] = 'field_imp_organisation_tid';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_organisation_tid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_organisation_tid']['expose']['operator_id'] = 'field_imp_organisation_tid_op';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['expose']['operator'] = 'field_imp_organisation_tid_op';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['expose']['identifier'] = 'field_imp_organisation_tid';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['field_imp_organisation_tid']['group_info']['label'] = 'Organisation (field_imp_organisation)';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['group_info']['identifier'] = 'field_imp_organisation_tid';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['field_imp_organisation_tid']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  $handler->display->display_options['filters']['field_imp_organisation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: ID (field_imp_id) */
  $handler->display->display_options['filters']['field_imp_id_value']['id'] = 'field_imp_id_value';
  $handler->display->display_options['filters']['field_imp_id_value']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['filters']['field_imp_id_value']['field'] = 'field_imp_id_value';
  $handler->display->display_options['filters']['field_imp_id_value']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['filters']['field_imp_id_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['field_imp_id_value']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['operator_id'] = 'field_imp_id_value_op';
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['label'] = 'Course ID';
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['operator'] = 'field_imp_id_value_op';
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['identifier'] = 'field_imp_id_value';
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value']['id'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value']['expose']['operator_id'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['label'] = 'Course name';
  $handler->display->display_options['filters']['title_field_value']['expose']['operator'] = 'title_field_value_op';
  $handler->display->display_options['filters']['title_field_value']['expose']['identifier'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );
  /* Filter criterion: Field: Title (title_field) */
  $handler->display->display_options['filters']['title_field_value_1']['id'] = 'title_field_value_1';
  $handler->display->display_options['filters']['title_field_value_1']['table'] = 'field_data_title_field';
  $handler->display->display_options['filters']['title_field_value_1']['field'] = 'title_field_value';
  $handler->display->display_options['filters']['title_field_value_1']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['filters']['title_field_value_1']['operator'] = 'contains';
  $handler->display->display_options['filters']['title_field_value_1']['group'] = 1;
  $handler->display->display_options['filters']['title_field_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['title_field_value_1']['expose']['operator_id'] = 'title_field_value_1_op';
  $handler->display->display_options['filters']['title_field_value_1']['expose']['label'] = 'Course name';
  $handler->display->display_options['filters']['title_field_value_1']['expose']['operator'] = 'title_field_value_1_op';
  $handler->display->display_options['filters']['title_field_value_1']['expose']['identifier'] = 'title_field_value_1';
  $handler->display->display_options['filters']['title_field_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
  );

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/content/courses';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Courses';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['admin_courses'] = array(
    t('Master'),
    t('Admin courses'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Course'),
    t('Title'),
    t('[field_course_course_number] - [title_1]'),
    t('Begin date'),
    t('Keywords (field_imp_keywords)'),
    t('Keyword'),
    t('Organisation'),
    t('Organisation (field_imp_organisation)'),
    t('Course ID'),
    t('Course name'),
    t('Page'),
  );
  $export['admin_courses'] = $view;

  return $export;
}
