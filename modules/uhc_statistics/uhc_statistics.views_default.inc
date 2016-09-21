<?php
/**
 * @file
 * uhc_statistics.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_statistics_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'statistics';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Statistics';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course Implementations With Moodle';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['group_by'] = TRUE;
  $handler->display->display_options['access']['type'] = 'role';
  $handler->display->display_options['access']['role'] = array(
    3 => '3',
  );
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['autosubmit'] = TRUE;
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title_field' => 'title_field',
    'timestamp' => 'timestamp',
    'timestamp_1' => 'timestamp_1',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'timestamp_1' => array(
      'sortable' => 1,
      'default_sort_order' => 'desc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Has Moodle Url';
  /* Field: MIN(Content: Post date) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['group_type'] = 'min';
  $handler->display->display_options['fields']['created']['label'] = 'Month Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M - Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'short_date_only';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'month';
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
  /* Filter criterion: Content: URL (field_moodle_url:url) */
  $handler->display->display_options['filters']['field_moodle_url_url']['id'] = 'field_moodle_url_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['table'] = 'field_data_field_moodle_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['field'] = 'field_moodle_url_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_moodle_url_url']['group'] = 1;
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
    1 => array(
      'title' => 'Genetics',
      'operator' => '=',
      'value' => 'genetiikka',
    ),
    2 => array(
      'title' => 'Molecular bioscience',
      'operator' => '=',
      'value' => 'molekyylibiotieteet',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth; <em class="placeholder">Simple hierarchical select</em>) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['value'] = 'All';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator_id'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['label'] = 'Begin date (between)';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['identifier'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_popup';

  /* Display: Created */
  $handler = $view->new_display('page', 'Created', 'page');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Course Implementations Created';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Course Implementations Created';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: MIN(Content: Post date) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['group_type'] = 'min';
  $handler->display->display_options['fields']['created']['label'] = 'Month Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M - Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'short_date_only';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    1 => array(
      'title' => 'Genetics',
      'operator' => '=',
      'value' => 'genetiikka',
    ),
    2 => array(
      'title' => 'Molecular bioscience',
      'operator' => '=',
      'value' => 'molekyylibiotieteet',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth; <em class="placeholder">Simple hierarchical select</em>) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['value'] = 'All';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator_id'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['label'] = 'Begin date (between)';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['identifier'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'admin/statistics/created';
  $handler->display->display_options['menu']['type'] = 'default tab';
  $handler->display->display_options['menu']['title'] = 'Course Implementations Created';
  $handler->display->display_options['menu']['description'] = 'Course Implementations Created';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Statistics';
  $handler->display->display_options['tab_options']['description'] = 'Statistics';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Data export - Created */
  $handler = $view->new_display('views_data_export', 'Data export - Created', 'views_data_export_2');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Course Implementations Created';
  $handler->display->display_options['fields']['nid']['separator'] = '';
  /* Field: MIN(Content: Post date) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['group_type'] = 'min';
  $handler->display->display_options['fields']['created']['label'] = 'Month Created';
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'M - Y';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'short_date_only';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    1 => array(
      'title' => 'Genetics',
      'operator' => '=',
      'value' => 'genetiikka',
    ),
    2 => array(
      'title' => 'Molecular bioscience',
      'operator' => '=',
      'value' => 'molekyylibiotieteet',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth; <em class="placeholder">Simple hierarchical select</em>) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['value'] = 'All';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator_id'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['label'] = 'Begin date (between)';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['identifier'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'admin/statistics/created/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
    'page_1' => 0,
    'page_2' => 0,
    'page_3' => 0,
  );

  /* Display: Moodle */
  $handler = $view->new_display('page', 'Moodle', 'page_1');
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Has Moodle Url';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Content: URL (field_moodle_url:url) */
  $handler->display->display_options['filters']['field_moodle_url_url']['id'] = 'field_moodle_url_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['table'] = 'field_data_field_moodle_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['field'] = 'field_moodle_url_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_moodle_url_url']['group'] = 1;
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
    1 => array(
      'title' => 'Genetics',
      'operator' => '=',
      'value' => 'genetiikka',
    ),
    2 => array(
      'title' => 'Molecular bioscience',
      'operator' => '=',
      'value' => 'molekyylibiotieteet',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth; <em class="placeholder">Simple hierarchical select</em>) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['value'] = 'All';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator_id'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['label'] = 'Begin date (between)';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['identifier'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'admin/statistics/moodle';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Course Implementations With Moodle';
  $handler->display->display_options['menu']['description'] = 'Course Implementations With Moodle';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export - Moodle */
  $handler = $view->new_display('views_data_export', 'Data export - Moodle', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['header'] = FALSE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Has Moodle Url';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['path'] = 'admin/statistics/moodle/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
    'page' => 0,
    'page_2' => 0,
    'page_3' => 0,
  );

  /* Display: Restricted */
  $handler = $view->new_display('page', 'Restricted', 'page_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Course Implementations With Restricted Content added';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['id'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['field'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Has Restricted Content';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'message';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'course_implementation_private_statistics' => 'course_implementation_private_statistics',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
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
    1 => array(
      'title' => 'Genetics',
      'operator' => '=',
      'value' => 'genetiikka',
    ),
    2 => array(
      'title' => 'Molecular bioscience',
      'operator' => '=',
      'value' => 'molekyylibiotieteet',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth; <em class="placeholder">Simple hierarchical select</em>) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['value'] = 'All';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator_id'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['label'] = 'Begin date (between)';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['identifier'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'admin/statistics/private';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Course Implementations With Restricted Content';
  $handler->display->display_options['menu']['description'] = 'Course Implementations With Restricted Content';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export - Restricted */
  $handler = $view->new_display('views_data_export', 'Data export - Restricted', 'views_data_export_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Data Export - Restricted';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['id'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['field'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: COUNT(DISTINCT Content: Nid) */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['nid']['label'] = 'Has Restricted Content';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'message';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'course_implementation_private_statistics' => 'course_implementation_private_statistics',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
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
    1 => array(
      'title' => 'Genetics',
      'operator' => '=',
      'value' => 'genetiikka',
    ),
    2 => array(
      'title' => 'Molecular bioscience',
      'operator' => '=',
      'value' => 'molekyylibiotieteet',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Content: Has taxonomy terms (with depth; <em class="placeholder">Simple hierarchical select</em>) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['value'] = 'All';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator_id'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['label'] = 'Begin date (between)';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['identifier'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'admin/statistics/private/export';
  $handler->display->display_options['displays'] = array(
    'page_2' => 'page_2',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
    'page_3' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Edited */
  $handler = $view->new_display('page', 'Edited', 'page_3');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Course Implementation Edited';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = 'Total @total Course implementations edited';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['id'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['field'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: COUNT(DISTINCT Message: Timestamp) */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['fields']['timestamp']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Number of edits';
  /* Field: MAX(Message: Timestamp) */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['fields']['timestamp_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['timestamp_1']['label'] = 'Last updated';
  $handler->display->display_options['fields']['timestamp_1']['date_format'] = 'short_date_only';
  $handler->display->display_options['fields']['timestamp_1']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['timestamp_1']['second_date_format'] = 'short_date_only';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'month';
  /* Sort criterion: COUNT(DISTINCT Message: Timestamp) */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['sorts']['timestamp']['group_type'] = 'count_distinct';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
    1 => array(
      'title' => 'Genetics',
      'operator' => '=',
      'value' => 'genetiikka',
    ),
    2 => array(
      'title' => 'Molecular bioscience',
      'operator' => '=',
      'value' => 'molekyylibiotieteet',
    ),
    3 => array(
      'title' => '',
      'operator' => '=',
      'value' => '',
    ),
  );
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'message';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'course_implementation_update_statistics' => 'course_implementation_update_statistics',
  );
  $handler->display->display_options['filters']['type_1']['group'] = 1;
  /* Filter criterion: Content: Has taxonomy terms (with depth; <em class="placeholder">Simple hierarchical select</em>) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['value'] = 'All';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['group'] = 1;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Message: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'message';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Last updated (between)';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator_id'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['label'] = 'Begin date (between)';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['identifier'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'admin/statistics/edits';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Course Implementations edited';
  $handler->display->display_options['menu']['description'] = 'Course Implementations edited';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Statistics';
  $handler->display->display_options['tab_options']['description'] = 'Statistics';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Data Export - Edited */
  $handler = $view->new_display('views_data_export', 'Data Export - Edited', 'views_data_export_4');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Data Export - Edited';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '0';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['style_options']['provide_file'] = 0;
  $handler->display->display_options['style_options']['parent_sort'] = 1;
  $handler->display->display_options['style_options']['quote'] = 1;
  $handler->display->display_options['style_options']['trim'] = 0;
  $handler->display->display_options['style_options']['replace_newlines'] = 0;
  $handler->display->display_options['style_options']['header'] = 1;
  $handler->display->display_options['style_options']['keep_html'] = 0;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['id'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['field'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['required'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: COUNT(DISTINCT Message: Timestamp) */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['fields']['timestamp']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['timestamp']['label'] = 'Number of edits';
  /* Field: MAX(Message: Timestamp) */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['fields']['timestamp_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['timestamp_1']['label'] = 'Last updated';
  $handler->display->display_options['fields']['timestamp_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp_1']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['timestamp_1']['second_date_format'] = 'short_date_only';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  $handler->display->display_options['sorts']['created']['granularity'] = 'month';
  /* Sort criterion: COUNT(DISTINCT Message: Timestamp) */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['sorts']['timestamp']['group_type'] = 'count_distinct';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
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
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'message';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'course_implementation_update_statistics' => 'course_implementation_update_statistics',
  );
  /* Filter criterion: Content: Keywords (field_imp_keywords) */
  $handler->display->display_options['filters']['field_imp_keywords_value']['id'] = 'field_imp_keywords_value';
  $handler->display->display_options['filters']['field_imp_keywords_value']['table'] = 'field_data_field_imp_keywords';
  $handler->display->display_options['filters']['field_imp_keywords_value']['field'] = 'field_imp_keywords_value';
  $handler->display->display_options['filters']['field_imp_keywords_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_keywords_value']['expose']['operator_id'] = 'field_imp_keywords_value_op';
  $handler->display->display_options['filters']['field_imp_keywords_value']['expose']['label'] = 'Keywords (field_imp_keywords)';
  $handler->display->display_options['filters']['field_imp_keywords_value']['expose']['operator'] = 'field_imp_keywords_value_op';
  $handler->display->display_options['filters']['field_imp_keywords_value']['expose']['identifier'] = 'field_imp_keywords_value';
  $handler->display->display_options['filters']['field_imp_keywords_value']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['field_imp_keywords_value']['group_info']['label'] = 'Keyword';
  $handler->display->display_options['filters']['field_imp_keywords_value']['group_info']['identifier'] = 'field_imp_keywords_value';
  $handler->display->display_options['filters']['field_imp_keywords_value']['group_info']['group_items'] = array(
    1 => array(
      'title' => 'Genetics',
      'operator' => '=',
      'value' => 'genetiikka',
    ),
    2 => array(
      'title' => 'Molecular bioscience',
      'operator' => '=',
      'value' => 'molekyylibiotieteet',
    ),
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
  $handler->display->display_options['filters']['field_imp_organisation_tid']['type'] = 'select';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['field_imp_organisation_tid']['hierarchy'] = 1;
  /* Filter criterion: Content: Has taxonomy terms (with depth; <em class="placeholder">Simple hierarchical select</em>) */
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['id'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['field'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['value'] = 'All';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['exposed'] = TRUE;
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator_id'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['label'] = 'Organisation';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['operator'] = 'shs_term_node_tid_depth_op';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['identifier'] = 'shs_term_node_tid_depth';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['vocabulary'] = 'organisations_of_university_of_helsinki';
  $handler->display->display_options['filters']['shs_term_node_tid_depth']['depth'] = '10';
  /* Filter criterion: Message: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'message';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Last updated (between)';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
  );
  /* Filter criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['filters']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['operator'] = 'between';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator_id'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['label'] = 'Begin date (between)';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['operator'] = 'field_imp_begin_date_value_op';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['identifier'] = 'field_imp_begin_date_value';
  $handler->display->display_options['filters']['field_imp_begin_date_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_begin_date_value']['form_type'] = 'date_popup';
  $handler->display->display_options['path'] = 'admin/statistics/edited/export';
  $handler->display->display_options['displays'] = array(
    'page_3' => 'page_3',
    'default' => 0,
    'page' => 0,
    'page_1' => 0,
    'page_2' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['statistics'] = array(
    t('Master'),
    t('Course Implementations With Moodle'),
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
    t('Content entity referenced from field_imp_reference_to_courses'),
    t('Has Moodle Url'),
    t('Month Created'),
    t('Keywords (field_imp_keywords)'),
    t('Keyword'),
    t('Organisation'),
    t('Begin date (between)'),
    t('Created'),
    t('Course Implementations Created'),
    t('Data export - Created'),
    t('Moodle'),
    t('Data export - Moodle'),
    t('Restricted'),
    t('Course Implementations With Restricted Content added'),
    t('Message referencing Content from field_message_ref_to_course_imp'),
    t('Has Restricted Content'),
    t('Data export - Restricted'),
    t('Data Export - Restricted'),
    t('Edited'),
    t('Course Implementation Edited'),
    t('Total @total Course implementations edited'),
    t('Title'),
    t('Number of edits'),
    t('Last updated'),
    t('Last updated (between)'),
    t('Data Export - Edited'),
  );
  $export['statistics'] = $view;

  return $export;
}
