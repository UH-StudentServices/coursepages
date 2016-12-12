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
  $view->name = 'statistics_activity';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Statistics - activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Statistics by activity';
  $handler->display->display_options['css_class'] = 'view-statistics';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'delta' => 'delta',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2>@total results</h2>';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['id'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['field'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['relationships']['reverse_field_message_ref_to_course_imp_message']['required'] = TRUE;
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  $handler->display->display_options['relationships']['user']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
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
  $handler->display->display_options['fields']['timestamp']['label'] = 'Number of activities';
  /* Field: MAX(Message: Timestamp) */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['fields']['timestamp_1']['group_type'] = 'max';
  $handler->display->display_options['fields']['timestamp_1']['label'] = 'Last activity';
  $handler->display->display_options['fields']['timestamp_1']['date_format'] = 'short_date_only';
  $handler->display->display_options['fields']['timestamp_1']['custom_date_format'] = 'Y-m-d';
  $handler->display->display_options['fields']['timestamp_1']['second_date_format'] = 'short_date_only';
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
  /* Filter criterion: Message: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'message';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['filters']['timestamp']['operator'] = 'between';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
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
  $handler->display->display_options['filters']['field_imp_begin_date_value']['group'] = 1;
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
  /* Filter criterion: User: Roles */
  $handler->display->display_options['filters']['rid']['id'] = 'rid';
  $handler->display->display_options['filters']['rid']['table'] = 'users_roles';
  $handler->display->display_options['filters']['rid']['field'] = 'rid';
  $handler->display->display_options['filters']['rid']['relationship'] = 'user';
  $handler->display->display_options['filters']['rid']['value'] = array(
    3 => '3',
    4 => '4',
    5 => '5',
    6 => '6',
  );
  $handler->display->display_options['filters']['rid']['group'] = 1;
  $handler->display->display_options['filters']['rid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['rid']['expose']['operator_id'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['label'] = 'Edited by user role';
  $handler->display->display_options['filters']['rid']['expose']['operator'] = 'rid_op';
  $handler->display->display_options['filters']['rid']['expose']['identifier'] = 'rid';
  $handler->display->display_options['filters']['rid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['rid']['expose']['reduce'] = TRUE;
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'message';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['relationship'] = 'reverse_field_message_ref_to_course_imp_message';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'course_implementation_private_statistics' => 'course_implementation_private_statistics',
    'course_implementation_update_statistics' => 'course_implementation_update_statistics',
    'course_implementation_analytics_view' => 'course_implementation_analytics_view',
    'course_implementation_moodle_course_area_create' => 'course_implementation_moodle_course_area_create',
  );
  $handler->display->display_options['filters']['type_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['type_1']['expose']['operator_id'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['label'] = 'Type of activity';
  $handler->display->display_options['filters']['type_1']['expose']['operator'] = 'type_1_op';
  $handler->display->display_options['filters']['type_1']['expose']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['type_1']['expose']['reduce'] = TRUE;
  $handler->display->display_options['filters']['type_1']['is_grouped'] = TRUE;
  $handler->display->display_options['filters']['type_1']['group_info']['label'] = 'Type of activity';
  $handler->display->display_options['filters']['type_1']['group_info']['identifier'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['group_info']['optional'] = FALSE;
  $handler->display->display_options['filters']['type_1']['group_info']['widget'] = 'radios';
  $handler->display->display_options['filters']['type_1']['group_info']['default_group'] = '2';
  $handler->display->display_options['filters']['type_1']['group_info']['group_items'] = array(
    2 => array(
      'title' => 'Updated',
      'operator' => 'in',
      'value' => array(
        'course_implementation_update_statistics' => 'course_implementation_update_statistics',
        'all' => 0,
        'course_implementation_private_statistics' => 0,
        'course_implementation_analytics_view' => 0,
        'course_implementation_comment_create' => 0,
        'course_implementation_comment_remove' => 0,
        'course_implementation_comment_update' => 0,
        'course_implementation_course_conduct_create' => 0,
        'course_implementation_course_conduct_remove' => 0,
        'course_implementation_course_conduct_update' => 0,
        'course_implementation_course_overview_accordion_target' => 0,
        'course_implementation_event_create' => 0,
        'course_implementation_event_remove' => 0,
        'course_implementation_event_update' => 0,
        'course_implementation_fee_accordion_target' => 0,
        'course_implementation_feedback_create' => 0,
        'course_implementation_feedback_remove' => 0,
        'course_implementation_feedback_update' => 0,
        'course_implementation_interaction_create' => 0,
        'course_implementation_interaction_remove' => 0,
        'course_implementation_interaction_update' => 0,
        'course_implementation_introduction_create' => 0,
        'course_implementation_introduction_remove' => 0,
        'course_implementation_introduction_update' => 0,
        'course_implementation_json_event_change' => 0,
        'course_implementation_material_create' => 0,
        'course_implementation_material_description_update' => 0,
        'course_implementation_material_manually_sorted' => 0,
        'course_implementation_material_remove' => 0,
        'course_implementation_material_update' => 0,
        'course_implementation_moodle_course_area_create' => 0,
        'course_implementation_moodle_key_create' => 0,
        'course_implementation_moodle_key_remove' => 0,
        'course_implementation_moodle_key_update' => 0,
        'course_implementation_moodle_link_create' => 0,
        'course_implementation_moodle_link_remove' => 0,
        'course_implementation_moodle_link_update' => 0,
        'course_implementation_private_comment_create' => 0,
        'course_implementation_private_comment_remove' => 0,
        'course_implementation_private_comment_update' => 0,
        'course_implementation_private_material_create' => 0,
        'course_implementation_private_material_remove' => 0,
        'course_implementation_private_material_update' => 0,
        'course_implementation_task_create' => 0,
        'course_implementation_task_remove' => 0,
        'course_implementation_task_update' => 0,
        'course_implementation_teacher_section_create' => 0,
        'course_implementation_teacher_section_remove' => 0,
        'course_implementation_teacher_section_update' => 0,
        'course_implementation_video_create' => 0,
        'course_implementation_video_remove' => 0,
        'course_implementation_video_update' => 0,
        'course_implementation_queue' => 0,
      ),
    ),
    3 => array(
      'title' => 'Analytics viewed',
      'operator' => 'in',
      'value' => array(
        'course_implementation_analytics_view' => 'course_implementation_analytics_view',
        'all' => 0,
        'course_implementation_private_statistics' => 0,
        'course_implementation_update_statistics' => 0,
        'course_implementation_comment_create' => 0,
        'course_implementation_comment_remove' => 0,
        'course_implementation_comment_update' => 0,
        'course_implementation_course_conduct_create' => 0,
        'course_implementation_course_conduct_remove' => 0,
        'course_implementation_course_conduct_update' => 0,
        'course_implementation_course_overview_accordion_target' => 0,
        'course_implementation_event_create' => 0,
        'course_implementation_event_remove' => 0,
        'course_implementation_event_update' => 0,
        'course_implementation_fee_accordion_target' => 0,
        'course_implementation_feedback_create' => 0,
        'course_implementation_feedback_remove' => 0,
        'course_implementation_feedback_update' => 0,
        'course_implementation_interaction_create' => 0,
        'course_implementation_interaction_remove' => 0,
        'course_implementation_interaction_update' => 0,
        'course_implementation_introduction_create' => 0,
        'course_implementation_introduction_remove' => 0,
        'course_implementation_introduction_update' => 0,
        'course_implementation_json_event_change' => 0,
        'course_implementation_material_create' => 0,
        'course_implementation_material_description_update' => 0,
        'course_implementation_material_manually_sorted' => 0,
        'course_implementation_material_remove' => 0,
        'course_implementation_material_update' => 0,
        'course_implementation_moodle_course_area_create' => 0,
        'course_implementation_moodle_key_create' => 0,
        'course_implementation_moodle_key_remove' => 0,
        'course_implementation_moodle_key_update' => 0,
        'course_implementation_moodle_link_create' => 0,
        'course_implementation_moodle_link_remove' => 0,
        'course_implementation_moodle_link_update' => 0,
        'course_implementation_private_comment_create' => 0,
        'course_implementation_private_comment_remove' => 0,
        'course_implementation_private_comment_update' => 0,
        'course_implementation_private_material_create' => 0,
        'course_implementation_private_material_remove' => 0,
        'course_implementation_private_material_update' => 0,
        'course_implementation_task_create' => 0,
        'course_implementation_task_remove' => 0,
        'course_implementation_task_update' => 0,
        'course_implementation_teacher_section_create' => 0,
        'course_implementation_teacher_section_remove' => 0,
        'course_implementation_teacher_section_update' => 0,
        'course_implementation_video_create' => 0,
        'course_implementation_video_remove' => 0,
        'course_implementation_video_update' => 0,
        'course_implementation_queue' => 0,
      ),
    ),
    4 => array(
      'title' => 'Moodle course area created',
      'operator' => 'in',
      'value' => array(
        'course_implementation_moodle_course_area_create' => 'course_implementation_moodle_course_area_create',
        'all' => 0,
        'course_implementation_private_statistics' => 0,
        'course_implementation_update_statistics' => 0,
        'course_implementation_analytics_view' => 0,
        'course_implementation_comment_create' => 0,
        'course_implementation_comment_remove' => 0,
        'course_implementation_comment_update' => 0,
        'course_implementation_course_conduct_create' => 0,
        'course_implementation_course_conduct_remove' => 0,
        'course_implementation_course_conduct_update' => 0,
        'course_implementation_course_overview_accordion_target' => 0,
        'course_implementation_event_create' => 0,
        'course_implementation_event_remove' => 0,
        'course_implementation_event_update' => 0,
        'course_implementation_fee_accordion_target' => 0,
        'course_implementation_feedback_create' => 0,
        'course_implementation_feedback_remove' => 0,
        'course_implementation_feedback_update' => 0,
        'course_implementation_interaction_create' => 0,
        'course_implementation_interaction_remove' => 0,
        'course_implementation_interaction_update' => 0,
        'course_implementation_introduction_create' => 0,
        'course_implementation_introduction_remove' => 0,
        'course_implementation_introduction_update' => 0,
        'course_implementation_json_event_change' => 0,
        'course_implementation_material_create' => 0,
        'course_implementation_material_description_update' => 0,
        'course_implementation_material_manually_sorted' => 0,
        'course_implementation_material_remove' => 0,
        'course_implementation_material_update' => 0,
        'course_implementation_moodle_key_create' => 0,
        'course_implementation_moodle_key_remove' => 0,
        'course_implementation_moodle_key_update' => 0,
        'course_implementation_moodle_link_create' => 0,
        'course_implementation_moodle_link_remove' => 0,
        'course_implementation_moodle_link_update' => 0,
        'course_implementation_private_comment_create' => 0,
        'course_implementation_private_comment_remove' => 0,
        'course_implementation_private_comment_update' => 0,
        'course_implementation_private_material_create' => 0,
        'course_implementation_private_material_remove' => 0,
        'course_implementation_private_material_update' => 0,
        'course_implementation_task_create' => 0,
        'course_implementation_task_remove' => 0,
        'course_implementation_task_update' => 0,
        'course_implementation_teacher_section_create' => 0,
        'course_implementation_teacher_section_remove' => 0,
        'course_implementation_teacher_section_update' => 0,
        'course_implementation_video_create' => 0,
        'course_implementation_video_remove' => 0,
        'course_implementation_video_update' => 0,
        'course_implementation_queue' => 0,
      ),
    ),
    5 => array(
      'title' => 'Queued for update',
      'operator' => 'in',
      'value' => array(
        'course_implementation_queue' => 'course_implementation_queue',
        'all' => 0,
        'course_implementation_private_statistics' => 0,
        'course_implementation_update_statistics' => 0,
        'course_implementation_analytics_view' => 0,
        'course_implementation_comment_create' => 0,
        'course_implementation_comment_remove' => 0,
        'course_implementation_comment_update' => 0,
        'course_implementation_course_conduct_create' => 0,
        'course_implementation_course_conduct_remove' => 0,
        'course_implementation_course_conduct_update' => 0,
        'course_implementation_course_overview_accordion_target' => 0,
        'course_implementation_event_create' => 0,
        'course_implementation_event_remove' => 0,
        'course_implementation_event_update' => 0,
        'course_implementation_fee_accordion_target' => 0,
        'course_implementation_feedback_create' => 0,
        'course_implementation_feedback_remove' => 0,
        'course_implementation_feedback_update' => 0,
        'course_implementation_interaction_create' => 0,
        'course_implementation_interaction_remove' => 0,
        'course_implementation_interaction_update' => 0,
        'course_implementation_introduction_create' => 0,
        'course_implementation_introduction_remove' => 0,
        'course_implementation_introduction_update' => 0,
        'course_implementation_json_event_change' => 0,
        'course_implementation_material_create' => 0,
        'course_implementation_material_description_update' => 0,
        'course_implementation_material_manually_sorted' => 0,
        'course_implementation_material_remove' => 0,
        'course_implementation_material_update' => 0,
        'course_implementation_moodle_course_area_create' => 0,
        'course_implementation_moodle_key_create' => 0,
        'course_implementation_moodle_key_remove' => 0,
        'course_implementation_moodle_key_update' => 0,
        'course_implementation_moodle_link_create' => 0,
        'course_implementation_moodle_link_remove' => 0,
        'course_implementation_moodle_link_update' => 0,
        'course_implementation_private_comment_create' => 0,
        'course_implementation_private_comment_remove' => 0,
        'course_implementation_private_comment_update' => 0,
        'course_implementation_private_material_create' => 0,
        'course_implementation_private_material_remove' => 0,
        'course_implementation_private_material_update' => 0,
        'course_implementation_task_create' => 0,
        'course_implementation_task_remove' => 0,
        'course_implementation_task_update' => 0,
        'course_implementation_teacher_section_create' => 0,
        'course_implementation_teacher_section_remove' => 0,
        'course_implementation_teacher_section_update' => 0,
        'course_implementation_video_create' => 0,
        'course_implementation_video_remove' => 0,
        'course_implementation_video_update' => 0,
      ),
    ),
  );

  /* Display: Statistics by activity */
  $handler = $view->new_display('page', 'Statistics by activity', 'page_3');
  $handler->display->display_options['path'] = 'admin/statistics/activity';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Statistics by activity';
  $handler->display->display_options['menu']['description'] = 'Statistics by activity';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $handler->display->display_options['tab_options']['type'] = 'normal';
  $handler->display->display_options['tab_options']['title'] = 'Statistics';
  $handler->display->display_options['tab_options']['description'] = 'Statistics';
  $handler->display->display_options['tab_options']['weight'] = '0';
  $handler->display->display_options['tab_options']['name'] = 'management';

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/statistics/activity/export';
  $handler->display->display_options['displays'] = array(
    'page_3' => 'page_3',
    'default' => 0,
  );
  $translatables['statistics_activity'] = array(
    t('Master'),
    t('Statistics by activity'),
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
    t('<h2>@total results</h2>'),
    t('Content entity referenced from field_imp_reference_to_courses'),
    t('Message referencing Content from field_message_ref_to_course_imp'),
    t('User'),
    t('Title'),
    t('Number of activities'),
    t('Last activity'),
    t('Keywords (field_imp_keywords)'),
    t('Keyword'),
    t('Organisation'),
    t('Last updated (between)'),
    t('Begin date (between)'),
    t('Edited by user role'),
    t('Type of activity'),
    t('Data export'),
  );
  $export['statistics_activity'] = $view;

  $view = new view();
  $view->name = 'statistics_content';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Statistics - content';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Statistics by content';
  $handler->display->display_options['css_class'] = 'view-statistics';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'delta' => 'delta',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
    ),
  );
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = 'This statistics view displays the amount of course implementations where the selected field has content. It is best to select a single field only as a filter and have the rest set as "-any-".';
  $handler->display->display_options['header']['area']['format'] = 'filtered_html';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2>@total results</h2>';
  /* Relationship: Comment: Comments of the node */
  $handler->display->display_options['relationships']['cid']['id'] = 'cid';
  $handler->display->display_options['relationships']['cid']['table'] = 'node';
  $handler->display->display_options['relationships']['cid']['field'] = 'cid';
  $handler->display->display_options['relationships']['cid']['label'] = 'Messages';
  /* Relationship: Course material */
  $handler->display->display_options['relationships']['field_section_material_target_id']['id'] = 'field_section_material_target_id';
  $handler->display->display_options['relationships']['field_section_material_target_id']['table'] = 'field_data_field_section_material';
  $handler->display->display_options['relationships']['field_section_material_target_id']['field'] = 'field_section_material_target_id';
  $handler->display->display_options['relationships']['field_section_material_target_id']['ui_name'] = 'Course material';
  $handler->display->display_options['relationships']['field_section_material_target_id']['label'] = 'Course material';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  /* Field: COUNT(DISTINCT Content: Custom section (field_imp_teachersection:delta)) */
  $handler->display->display_options['fields']['delta']['id'] = 'delta';
  $handler->display->display_options['fields']['delta']['table'] = 'field_data_field_imp_teachersection';
  $handler->display->display_options['fields']['delta']['field'] = 'delta';
  $handler->display->display_options['fields']['delta']['group_type'] = 'count_distinct';
  $handler->display->display_options['fields']['delta']['label'] = 'Number of custom sections';
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
  /* Filter criterion: Content: URL (field_moodle_url:url) */
  $handler->display->display_options['filters']['field_moodle_url_url']['id'] = 'field_moodle_url_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['table'] = 'field_data_field_moodle_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['field'] = 'field_moodle_url_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_moodle_url_url']['group'] = 1;
  $handler->display->display_options['filters']['field_moodle_url_url']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_moodle_url_url']['expose']['operator_id'] = 'field_moodle_url_url_op';
  $handler->display->display_options['filters']['field_moodle_url_url']['expose']['label'] = 'Moodle URL';
  $handler->display->display_options['filters']['field_moodle_url_url']['expose']['operator'] = 'field_moodle_url_url_op';
  $handler->display->display_options['filters']['field_moodle_url_url']['expose']['identifier'] = 'field_moodle_url_url';
  $handler->display->display_options['filters']['field_moodle_url_url']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Interaction description */
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['id'] = 'field_imp_interactiondescription_value';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['table'] = 'field_data_field_imp_interactiondescription';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['field'] = 'field_imp_interactiondescription_value';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['ui_name'] = 'Interaction description';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['expose']['operator_id'] = 'field_imp_interactiondescription_value_op';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['expose']['label'] = 'Interaction description';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['expose']['operator'] = 'field_imp_interactiondescription_value_op';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['expose']['identifier'] = 'field_imp_interactiondescription_value';
  $handler->display->display_options['filters']['field_imp_interactiondescription_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Interaction links */
  $handler->display->display_options['filters']['delta']['id'] = 'delta';
  $handler->display->display_options['filters']['delta']['table'] = 'field_data_field_imp_interaction_link';
  $handler->display->display_options['filters']['delta']['field'] = 'delta';
  $handler->display->display_options['filters']['delta']['ui_name'] = 'Interaction links';
  $handler->display->display_options['filters']['delta']['operator'] = 'not empty';
  $handler->display->display_options['filters']['delta']['group'] = 1;
  $handler->display->display_options['filters']['delta']['exposed'] = TRUE;
  $handler->display->display_options['filters']['delta']['expose']['operator_id'] = 'delta_op';
  $handler->display->display_options['filters']['delta']['expose']['label'] = 'Interaction links';
  $handler->display->display_options['filters']['delta']['expose']['operator'] = 'delta_op';
  $handler->display->display_options['filters']['delta']['expose']['identifier'] = 'delta';
  $handler->display->display_options['filters']['delta']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Tasks */
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['id'] = 'field_reference_to_course_tasks_target_id';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['table'] = 'field_data_field_reference_to_course_tasks';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['field'] = 'field_reference_to_course_tasks_target_id';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['ui_name'] = 'Tasks';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['expose']['operator_id'] = 'field_reference_to_course_tasks_target_id_op';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['expose']['label'] = 'Tasks';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['expose']['operator'] = 'field_reference_to_course_tasks_target_id_op';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['expose']['identifier'] = 'field_reference_to_course_tasks_target_id';
  $handler->display->display_options['filters']['field_reference_to_course_tasks_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Intro text */
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['id'] = 'field_field_imp_header_intro_tex_value';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['table'] = 'field_data_field_field_imp_header_intro_tex';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['field'] = 'field_field_imp_header_intro_tex_value';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['ui_name'] = 'Intro text';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['group'] = 1;
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['expose']['operator_id'] = 'field_field_imp_header_intro_tex_value_op';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['expose']['label'] = 'Intro text';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['expose']['operator'] = 'field_field_imp_header_intro_tex_value_op';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['expose']['identifier'] = 'field_field_imp_header_intro_tex_value';
  $handler->display->display_options['filters']['field_field_imp_header_intro_tex_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Headline text */
  $handler->display->display_options['filters']['field_imp_header_headline_value']['id'] = 'field_imp_header_headline_value';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['table'] = 'field_data_field_imp_header_headline';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['field'] = 'field_imp_header_headline_value';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['ui_name'] = 'Headline text';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_header_headline_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_header_headline_value']['expose']['operator_id'] = 'field_imp_header_headline_value_op';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['expose']['label'] = 'Headline text';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['expose']['operator'] = 'field_imp_header_headline_value_op';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['expose']['identifier'] = 'field_imp_header_headline_value';
  $handler->display->display_options['filters']['field_imp_header_headline_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Header text */
  $handler->display->display_options['filters']['field_imp_header_text_value']['id'] = 'field_imp_header_text_value';
  $handler->display->display_options['filters']['field_imp_header_text_value']['table'] = 'field_data_field_imp_header_text';
  $handler->display->display_options['filters']['field_imp_header_text_value']['field'] = 'field_imp_header_text_value';
  $handler->display->display_options['filters']['field_imp_header_text_value']['ui_name'] = 'Header text';
  $handler->display->display_options['filters']['field_imp_header_text_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_imp_header_text_value']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_header_text_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_header_text_value']['expose']['operator_id'] = 'field_imp_header_text_value_op';
  $handler->display->display_options['filters']['field_imp_header_text_value']['expose']['label'] = 'Header text';
  $handler->display->display_options['filters']['field_imp_header_text_value']['expose']['operator'] = 'field_imp_header_text_value_op';
  $handler->display->display_options['filters']['field_imp_header_text_value']['expose']['identifier'] = 'field_imp_header_text_value';
  $handler->display->display_options['filters']['field_imp_header_text_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Feedback description */
  $handler->display->display_options['filters']['field_feedback_description_value']['id'] = 'field_feedback_description_value';
  $handler->display->display_options['filters']['field_feedback_description_value']['table'] = 'field_data_field_feedback_description';
  $handler->display->display_options['filters']['field_feedback_description_value']['field'] = 'field_feedback_description_value';
  $handler->display->display_options['filters']['field_feedback_description_value']['ui_name'] = 'Feedback description';
  $handler->display->display_options['filters']['field_feedback_description_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_feedback_description_value']['group'] = 1;
  $handler->display->display_options['filters']['field_feedback_description_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_feedback_description_value']['expose']['operator_id'] = 'field_feedback_description_value_op';
  $handler->display->display_options['filters']['field_feedback_description_value']['expose']['label'] = 'Feedback description';
  $handler->display->display_options['filters']['field_feedback_description_value']['expose']['operator'] = 'field_feedback_description_value_op';
  $handler->display->display_options['filters']['field_feedback_description_value']['expose']['identifier'] = 'field_feedback_description_value';
  $handler->display->display_options['filters']['field_feedback_description_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Feedback links */
  $handler->display->display_options['filters']['delta_1']['id'] = 'delta_1';
  $handler->display->display_options['filters']['delta_1']['table'] = 'field_data_field_feedback_link';
  $handler->display->display_options['filters']['delta_1']['field'] = 'delta';
  $handler->display->display_options['filters']['delta_1']['ui_name'] = 'Feedback links';
  $handler->display->display_options['filters']['delta_1']['operator'] = 'not empty';
  $handler->display->display_options['filters']['delta_1']['group'] = 1;
  $handler->display->display_options['filters']['delta_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['delta_1']['expose']['operator_id'] = 'delta_1_op';
  $handler->display->display_options['filters']['delta_1']['expose']['label'] = 'Feedback links';
  $handler->display->display_options['filters']['delta_1']['expose']['operator'] = 'delta_1_op';
  $handler->display->display_options['filters']['delta_1']['expose']['identifier'] = 'delta_1';
  $handler->display->display_options['filters']['delta_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Video description */
  $handler->display->display_options['filters']['field_video_description_value']['id'] = 'field_video_description_value';
  $handler->display->display_options['filters']['field_video_description_value']['table'] = 'field_data_field_video_description';
  $handler->display->display_options['filters']['field_video_description_value']['field'] = 'field_video_description_value';
  $handler->display->display_options['filters']['field_video_description_value']['ui_name'] = 'Video description';
  $handler->display->display_options['filters']['field_video_description_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_video_description_value']['group'] = 1;
  $handler->display->display_options['filters']['field_video_description_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_video_description_value']['expose']['operator_id'] = 'field_video_description_value_op';
  $handler->display->display_options['filters']['field_video_description_value']['expose']['label'] = 'Video description';
  $handler->display->display_options['filters']['field_video_description_value']['expose']['operator'] = 'field_video_description_value_op';
  $handler->display->display_options['filters']['field_video_description_value']['expose']['identifier'] = 'field_video_description_value';
  $handler->display->display_options['filters']['field_video_description_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Video embed URL */
  $handler->display->display_options['filters']['field_video_embed_url_value']['id'] = 'field_video_embed_url_value';
  $handler->display->display_options['filters']['field_video_embed_url_value']['table'] = 'field_data_field_video_embed_url';
  $handler->display->display_options['filters']['field_video_embed_url_value']['field'] = 'field_video_embed_url_value';
  $handler->display->display_options['filters']['field_video_embed_url_value']['ui_name'] = 'Video embed URL';
  $handler->display->display_options['filters']['field_video_embed_url_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_video_embed_url_value']['group'] = 1;
  $handler->display->display_options['filters']['field_video_embed_url_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_video_embed_url_value']['expose']['operator_id'] = 'field_video_embed_url_value_op';
  $handler->display->display_options['filters']['field_video_embed_url_value']['expose']['label'] = 'Video embed URL';
  $handler->display->display_options['filters']['field_video_embed_url_value']['expose']['operator'] = 'field_video_embed_url_value_op';
  $handler->display->display_options['filters']['field_video_embed_url_value']['expose']['identifier'] = 'field_video_embed_url_value';
  $handler->display->display_options['filters']['field_video_embed_url_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Video links */
  $handler->display->display_options['filters']['delta_2']['id'] = 'delta_2';
  $handler->display->display_options['filters']['delta_2']['table'] = 'field_data_field_video_link';
  $handler->display->display_options['filters']['delta_2']['field'] = 'delta';
  $handler->display->display_options['filters']['delta_2']['ui_name'] = 'Video links';
  $handler->display->display_options['filters']['delta_2']['operator'] = 'not empty';
  $handler->display->display_options['filters']['delta_2']['group'] = 1;
  $handler->display->display_options['filters']['delta_2']['exposed'] = TRUE;
  $handler->display->display_options['filters']['delta_2']['expose']['operator_id'] = 'delta_2_op';
  $handler->display->display_options['filters']['delta_2']['expose']['label'] = 'Video links';
  $handler->display->display_options['filters']['delta_2']['expose']['operator'] = 'delta_2_op';
  $handler->display->display_options['filters']['delta_2']['expose']['identifier'] = 'delta_2';
  $handler->display->display_options['filters']['delta_2']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Events */
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['id'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['table'] = 'field_data_field_imp_reference_to_events';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['field'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['ui_name'] = 'Events';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['expose']['operator_id'] = 'field_imp_reference_to_events_target_id_op';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['expose']['label'] = 'Events';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['expose']['operator'] = 'field_imp_reference_to_events_target_id_op';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['expose']['identifier'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['filters']['field_imp_reference_to_events_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Wiki URL */
  $handler->display->display_options['filters']['field_wiki_url_url']['id'] = 'field_wiki_url_url';
  $handler->display->display_options['filters']['field_wiki_url_url']['table'] = 'field_data_field_wiki_url';
  $handler->display->display_options['filters']['field_wiki_url_url']['field'] = 'field_wiki_url_url';
  $handler->display->display_options['filters']['field_wiki_url_url']['ui_name'] = 'Wiki URL';
  $handler->display->display_options['filters']['field_wiki_url_url']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_wiki_url_url']['group'] = 1;
  $handler->display->display_options['filters']['field_wiki_url_url']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_wiki_url_url']['expose']['operator_id'] = 'field_wiki_url_url_op';
  $handler->display->display_options['filters']['field_wiki_url_url']['expose']['label'] = 'Wiki URL';
  $handler->display->display_options['filters']['field_wiki_url_url']['expose']['operator'] = 'field_wiki_url_url_op';
  $handler->display->display_options['filters']['field_wiki_url_url']['expose']['identifier'] = 'field_wiki_url_url';
  $handler->display->display_options['filters']['field_wiki_url_url']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Custom section */
  $handler->display->display_options['filters']['field_imp_teachersection_value']['id'] = 'field_imp_teachersection_value';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['table'] = 'field_data_field_imp_teachersection';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['field'] = 'field_imp_teachersection_value';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['ui_name'] = 'Custom section';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_teachersection_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_teachersection_value']['expose']['operator_id'] = 'field_imp_teachersection_value_op';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['expose']['label'] = 'Custom section';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['expose']['operator'] = 'field_imp_teachersection_value_op';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['expose']['identifier'] = 'field_imp_teachersection_value';
  $handler->display->display_options['filters']['field_imp_teachersection_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Hide enrollment */
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['id'] = 'field_imp_hide_sign_up_button_value';
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['table'] = 'field_data_field_imp_hide_sign_up_button';
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['field'] = 'field_imp_hide_sign_up_button_value';
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['ui_name'] = 'Hide enrollment';
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['expose']['operator_id'] = 'field_imp_hide_sign_up_button_value_op';
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['expose']['label'] = 'Hide enrollment';
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['expose']['operator'] = 'field_imp_hide_sign_up_button_value_op';
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['expose']['identifier'] = 'field_imp_hide_sign_up_button_value';
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_imp_hide_sign_up_button_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Course conduct */
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['id'] = 'field_imp_teacher_se_content_value';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['table'] = 'field_data_field_imp_teacher_se_content';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['field'] = 'field_imp_teacher_se_content_value';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['ui_name'] = 'Course conduct';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['group'] = 1;
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['expose']['operator_id'] = 'field_imp_teacher_se_content_value_op';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['expose']['label'] = 'Course conduct';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['expose']['operator'] = 'field_imp_teacher_se_content_value_op';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['expose']['identifier'] = 'field_imp_teacher_se_content_value';
  $handler->display->display_options['filters']['field_imp_teacher_se_content_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Material description (field_imp_material_description) */
  $handler->display->display_options['filters']['field_imp_material_description_value']['id'] = 'field_imp_material_description_value';
  $handler->display->display_options['filters']['field_imp_material_description_value']['table'] = 'field_data_field_imp_material_description';
  $handler->display->display_options['filters']['field_imp_material_description_value']['field'] = 'field_imp_material_description_value';
  $handler->display->display_options['filters']['field_imp_material_description_value']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_imp_material_description_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_material_description_value']['expose']['operator_id'] = 'field_imp_material_description_value_op';
  $handler->display->display_options['filters']['field_imp_material_description_value']['expose']['label'] = 'Material description';
  $handler->display->display_options['filters']['field_imp_material_description_value']['expose']['operator'] = 'field_imp_material_description_value_op';
  $handler->display->display_options['filters']['field_imp_material_description_value']['expose']['identifier'] = 'field_imp_material_description_value';
  $handler->display->display_options['filters']['field_imp_material_description_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Content: Materials (field_section_material) */
  $handler->display->display_options['filters']['field_section_material_target_id']['id'] = 'field_section_material_target_id';
  $handler->display->display_options['filters']['field_section_material_target_id']['table'] = 'field_data_field_section_material';
  $handler->display->display_options['filters']['field_section_material_target_id']['field'] = 'field_section_material_target_id';
  $handler->display->display_options['filters']['field_section_material_target_id']['operator'] = 'not empty';
  $handler->display->display_options['filters']['field_section_material_target_id']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_section_material_target_id']['expose']['operator_id'] = 'field_section_material_target_id_op';
  $handler->display->display_options['filters']['field_section_material_target_id']['expose']['label'] = 'Materials';
  $handler->display->display_options['filters']['field_section_material_target_id']['expose']['operator'] = 'field_section_material_target_id_op';
  $handler->display->display_options['filters']['field_section_material_target_id']['expose']['identifier'] = 'field_section_material_target_id';
  $handler->display->display_options['filters']['field_section_material_target_id']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Comment: ID */
  $handler->display->display_options['filters']['cid']['id'] = 'cid';
  $handler->display->display_options['filters']['cid']['table'] = 'comment';
  $handler->display->display_options['filters']['cid']['field'] = 'cid';
  $handler->display->display_options['filters']['cid']['relationship'] = 'cid';
  $handler->display->display_options['filters']['cid']['operator'] = 'not empty';
  $handler->display->display_options['filters']['cid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['cid']['expose']['operator_id'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['label'] = 'Messages';
  $handler->display->display_options['filters']['cid']['expose']['operator'] = 'cid_op';
  $handler->display->display_options['filters']['cid']['expose']['identifier'] = 'cid';
  $handler->display->display_options['filters']['cid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Field: Restricted to course’s participants only (field_private) */
  $handler->display->display_options['filters']['field_private_value']['id'] = 'field_private_value';
  $handler->display->display_options['filters']['field_private_value']['table'] = 'field_data_field_private';
  $handler->display->display_options['filters']['field_private_value']['field'] = 'field_private_value';
  $handler->display->display_options['filters']['field_private_value']['relationship'] = 'cid';
  $handler->display->display_options['filters']['field_private_value']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_private_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_private_value']['expose']['operator_id'] = 'field_private_value_op';
  $handler->display->display_options['filters']['field_private_value']['expose']['label'] = 'Restricted messages';
  $handler->display->display_options['filters']['field_private_value']['expose']['operator'] = 'field_private_value_op';
  $handler->display->display_options['filters']['field_private_value']['expose']['identifier'] = 'field_private_value';
  $handler->display->display_options['filters']['field_private_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_private_value']['expose']['reduce'] = TRUE;
  /* Filter criterion: Field: Restricted to course’s participants only (field_private) */
  $handler->display->display_options['filters']['field_private_value_1']['id'] = 'field_private_value_1';
  $handler->display->display_options['filters']['field_private_value_1']['table'] = 'field_data_field_private';
  $handler->display->display_options['filters']['field_private_value_1']['field'] = 'field_private_value';
  $handler->display->display_options['filters']['field_private_value_1']['relationship'] = 'field_section_material_target_id';
  $handler->display->display_options['filters']['field_private_value_1']['value'] = array(
    1 => '1',
  );
  $handler->display->display_options['filters']['field_private_value_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_private_value_1']['expose']['operator_id'] = 'field_private_value_1_op';
  $handler->display->display_options['filters']['field_private_value_1']['expose']['label'] = 'Restricted material';
  $handler->display->display_options['filters']['field_private_value_1']['expose']['operator'] = 'field_private_value_1_op';
  $handler->display->display_options['filters']['field_private_value_1']['expose']['identifier'] = 'field_private_value_1';
  $handler->display->display_options['filters']['field_private_value_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['field_private_value_1']['expose']['reduce'] = TRUE;

  /* Display: Statistics by content */
  $handler = $view->new_display('page', 'Statistics by content', 'page_1');
  $handler->display->display_options['path'] = 'admin/statistics/content';
  $handler->display->display_options['menu']['type'] = 'tab';
  $handler->display->display_options['menu']['title'] = 'Statistics by content';
  $handler->display->display_options['menu']['description'] = 'Statistics by content';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/statistics/content/export';
  $handler->display->display_options['displays'] = array(
    'page_1' => 'page_1',
    'default' => 0,
  );
  $translatables['statistics_content'] = array(
    t('Master'),
    t('Statistics by content'),
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
    t('This statistics view displays the amount of course implementations where the selected field has content. It is best to select a single field only as a filter and have the rest set as "-any-".'),
    t('<h2>@total results</h2>'),
    t('Messages'),
    t('Course material'),
    t('Title'),
    t('Number of custom sections'),
    t('.'),
    t(','),
    t('Keywords (field_imp_keywords)'),
    t('Keyword'),
    t('Organisation'),
    t('Begin date (between)'),
    t('Moodle URL'),
    t('Interaction description'),
    t('Interaction links'),
    t('Tasks'),
    t('Intro text'),
    t('Headline text'),
    t('Header text'),
    t('Feedback description'),
    t('Feedback links'),
    t('Video description'),
    t('Video embed URL'),
    t('Video links'),
    t('Events'),
    t('Wiki URL'),
    t('Custom section'),
    t('Hide enrollment'),
    t('Course conduct'),
    t('Material description'),
    t('Materials'),
    t('Restricted messages'),
    t('Restricted material'),
    t('Data export'),
  );
  $export['statistics_content'] = $view;

  $view = new view();
  $view->name = 'statistics_created';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Statistics - created';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Course Implementations Created';
  $handler->display->display_options['css_class'] = 'view-statistics';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
    'delta' => 'delta',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'title' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'delta' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 1,
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

  /* Display: Data export */
  $handler = $view->new_display('views_data_export', 'Data export', 'views_data_export_1');
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'views_data_export_csv';
  $handler->display->display_options['path'] = 'admin/statistics/created/export';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['statistics_created'] = array(
    t('Master'),
    t('Course Implementations Created'),
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
    t('Month Created'),
    t('Keywords (field_imp_keywords)'),
    t('Keyword'),
    t('Organisation'),
    t('Begin date (between)'),
    t('Created'),
    t('Data export'),
  );
  $export['statistics_created'] = $view;

  return $export;
}
