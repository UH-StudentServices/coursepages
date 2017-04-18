<?php
/**
 * @file
 * uhc_rest_api.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_rest_api_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'rest_api_v1_course_implementation_activity';
  $view->description = '';
  $view->tag = 'uhc_course_implementation_activity';
  $view->base_table = 'message';
  $view->human_name = 'REST: Course implementation activity';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  $handler->display->display_options['row_options']['default_field_elements'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['label'] = 'Total count';
  $handler->display->display_options['header']['result']['empty'] = TRUE;
  $handler->display->display_options['header']['result']['content'] = '@total';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_message_ref_to_course_imp_target_id']['id'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['relationships']['field_message_ref_to_course_imp_target_id']['table'] = 'field_data_field_message_ref_to_course_imp';
  $handler->display->display_options['relationships']['field_message_ref_to_course_imp_target_id']['field'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['relationships']['field_message_ref_to_course_imp_target_id']['required'] = TRUE;
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid_1']['id'] = 'mid_1';
  $handler->display->display_options['fields']['mid_1']['table'] = 'message';
  $handler->display->display_options['fields']['mid_1']['field'] = 'mid';
  $handler->display->display_options['fields']['mid_1']['label'] = 'id';
  $handler->display->display_options['fields']['mid_1']['separator'] = '';
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_imp_id']['id'] = 'field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['field'] = 'field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['relationship'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['fields']['field_imp_id']['label'] = 'course_imp_id';
  /* Field: Message: Message ID: see uhc_rest_api_services_views_execute_view_alter */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['ui_name'] = 'Message: Message ID: see uhc_rest_api_services_views_execute_view_alter';
  $handler->display->display_options['fields']['mid']['label'] = 'message';
  $handler->display->display_options['fields']['mid']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = 'user';
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  $handler->display->display_options['fields']['name']['format_username'] = FALSE;
  /* Field: User: Oodi UID */
  $handler->display->display_options['fields']['field_oodi_uid']['id'] = 'field_oodi_uid';
  $handler->display->display_options['fields']['field_oodi_uid']['table'] = 'field_data_field_oodi_uid';
  $handler->display->display_options['fields']['field_oodi_uid']['field'] = 'field_oodi_uid';
  $handler->display->display_options['fields']['field_oodi_uid']['relationship'] = 'user';
  $handler->display->display_options['fields']['field_oodi_uid']['label'] = 'oodi_uid';
  /* Field: Message: Timestamp: see uhc_rest_api_services_views_execute_view_alter */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['ui_name'] = 'Message: Timestamp: see uhc_rest_api_services_views_execute_view_alter';
  $handler->display->display_options['fields']['timestamp']['label'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'Y-m-d\\TH:i:s\\Z';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'short_date_only';
  $handler->display->display_options['fields']['timestamp']['timezone'] = 'UTC';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Content: ID (field_imp_id) */
  $handler->display->display_options['arguments']['field_imp_id_value']['id'] = 'field_imp_id_value';
  $handler->display->display_options['arguments']['field_imp_id_value']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['arguments']['field_imp_id_value']['field'] = 'field_imp_id_value';
  $handler->display->display_options['arguments']['field_imp_id_value']['relationship'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['arguments']['field_imp_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_imp_id_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_imp_id_value']['default_argument_options']['code'] = 'return str_replace(",", "+", $_GET[\'course_implementation_id\']);';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_imp_id_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_imp_id_value']['break_phrase'] = TRUE;
  /* Filter criterion: Message: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'message';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = '>=';
  $handler->display->display_options['filters']['timestamp']['value']['value'] = '-7 day';
  $handler->display->display_options['filters']['timestamp']['group'] = 1;
  $handler->display->display_options['filters']['timestamp']['exposed'] = TRUE;
  $handler->display->display_options['filters']['timestamp']['expose']['operator_id'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['label'] = 'Timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['operator'] = 'timestamp_op';
  $handler->display->display_options['filters']['timestamp']['expose']['identifier'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
  );
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'message';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'course_implementation_private_statistics' => 'course_implementation_private_statistics',
    'course_implementation_update_statistics' => 'course_implementation_update_statistics',
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'course_implementation_activity';
  $translatables['rest_api_v1_course_implementation_activity'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Total count'),
    t('@total'),
    t('Content entity referenced from field_message_ref_to_course_imp'),
    t('User'),
    t('id'),
    t('.'),
    t('course_imp_id'),
    t('message'),
    t('user'),
    t('oodi_uid'),
    t('timestamp'),
    t('All'),
    t('Timestamp'),
    t('Services'),
  );
  $export['rest_api_v1_course_implementation_activity'] = $view;

  $view = new view();
  $view->name = 'rest_api_v1_course_implementations';
  $view->description = 'Provides data about course implementations.';
  $view->tag = 'rest';
  $view->base_table = 'node';
  $view->human_name = 'REST: Course implementations';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['label'] = 'nid';
  $handler->display->display_options['fields']['nid']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Header image */
  $handler->display->display_options['fields']['field_imp_header_image']['id'] = 'field_imp_header_image';
  $handler->display->display_options['fields']['field_imp_header_image']['table'] = 'field_data_field_imp_header_image';
  $handler->display->display_options['fields']['field_imp_header_image']['field'] = 'field_imp_header_image';
  $handler->display->display_options['fields']['field_imp_header_image']['label'] = 'header_image_url';
  $handler->display->display_options['fields']['field_imp_header_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_header_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_imp_header_image']['type'] = 'image_url';
  $handler->display->display_options['fields']['field_imp_header_image']['settings'] = array(
    'url_type' => '0',
    'image_style' => 'liftup_322_x_190',
    'image_link' => '',
  );
  /* Field: Content: Header image caption */
  $handler->display->display_options['fields']['field_imp_header_image_caption']['id'] = 'field_imp_header_image_caption';
  $handler->display->display_options['fields']['field_imp_header_image_caption']['table'] = 'field_data_field_imp_header_image_caption';
  $handler->display->display_options['fields']['field_imp_header_image_caption']['field'] = 'field_imp_header_image_caption';
  $handler->display->display_options['fields']['field_imp_header_image_caption']['label'] = 'header_image_attribution';
  $handler->display->display_options['fields']['field_imp_header_image_caption']['type'] = 'text_plain';
  /* Field: Content: Header headline */
  $handler->display->display_options['fields']['field_imp_header_headline']['id'] = 'field_imp_header_headline';
  $handler->display->display_options['fields']['field_imp_header_headline']['table'] = 'field_data_field_imp_header_headline';
  $handler->display->display_options['fields']['field_imp_header_headline']['field'] = 'field_imp_header_headline';
  $handler->display->display_options['fields']['field_imp_header_headline']['label'] = 'header_headline';
  /* Field: Content: Text */
  $handler->display->display_options['fields']['field_imp_header_text']['id'] = 'field_imp_header_text';
  $handler->display->display_options['fields']['field_imp_header_text']['table'] = 'field_data_field_imp_header_text';
  $handler->display->display_options['fields']['field_imp_header_text']['field'] = 'field_imp_header_text';
  $handler->display->display_options['fields']['field_imp_header_text']['label'] = 'header_text';
  $handler->display->display_options['fields']['field_imp_header_text']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_header_text']['type'] = 'text_plain';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: ID (field_imp_id) */
  $handler->display->display_options['filters']['field_imp_id_value']['id'] = 'field_imp_id_value';
  $handler->display->display_options['filters']['field_imp_id_value']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['filters']['field_imp_id_value']['field'] = 'field_imp_id_value';
  $handler->display->display_options['filters']['field_imp_id_value']['exposed'] = TRUE;
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['operator_id'] = 'field_imp_id_value_op';
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['operator'] = 'field_imp_id_value_op';
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['identifier'] = 'course_implementation_id';
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['field_imp_id_value']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
  );

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'course_implementations';
  $translatables['rest_api_v1_course_implementations'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('nid'),
    t('title'),
    t('header_image_url'),
    t('header_image_attribution'),
    t('header_headline'),
    t('header_text'),
    t('Services'),
  );
  $export['rest_api_v1_course_implementations'] = $view;

  $view = new view();
  $view->name = 'rest_api_v1_events';
  $view->description = 'Provides an collection of events created to given course implementations.';
  $view->tag = 'rest';
  $view->base_table = 'node';
  $view->human_name = 'REST: Events';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['id'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['table'] = 'field_data_field_imp_reference_to_events';
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['field'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['required'] = TRUE;
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_imp_id']['id'] = 'field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['field'] = 'field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['label'] = 'course_implementation_id';
  $handler->display->display_options['fields']['field_imp_id']['element_label_colon'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['fields']['title']['label'] = 'title';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Event begin date */
  $handler->display->display_options['fields']['field_event_begin_date']['id'] = 'field_event_begin_date';
  $handler->display->display_options['fields']['field_event_begin_date']['table'] = 'field_data_field_event_begin_date';
  $handler->display->display_options['fields']['field_event_begin_date']['field'] = 'field_event_begin_date';
  $handler->display->display_options['fields']['field_event_begin_date']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['fields']['field_event_begin_date']['label'] = 'begin';
  $handler->display->display_options['fields']['field_event_begin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_event_begin_date']['type'] = 'date_plain';
  $handler->display->display_options['fields']['field_event_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Content: Duration */
  $handler->display->display_options['fields']['field_event_duration']['id'] = 'field_event_duration';
  $handler->display->display_options['fields']['field_event_duration']['table'] = 'field_data_field_event_duration';
  $handler->display->display_options['fields']['field_event_duration']['field'] = 'field_event_duration';
  $handler->display->display_options['fields']['field_event_duration']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['fields']['field_event_duration']['label'] = 'end';
  $handler->display->display_options['fields']['field_event_duration']['element_label_colon'] = FALSE;
  /* Field: Content: Location */
  $handler->display->display_options['fields']['field_event_loc_name']['id'] = 'field_event_loc_name';
  $handler->display->display_options['fields']['field_event_loc_name']['table'] = 'field_data_field_event_loc_name';
  $handler->display->display_options['fields']['field_event_loc_name']['field'] = 'field_event_loc_name';
  $handler->display->display_options['fields']['field_event_loc_name']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['fields']['field_event_loc_name']['label'] = 'where';
  $handler->display->display_options['fields']['field_event_loc_name']['element_label_colon'] = FALSE;
  /* Field: Content: Exam */
  $handler->display->display_options['fields']['field_event_is_exam']['id'] = 'field_event_is_exam';
  $handler->display->display_options['fields']['field_event_is_exam']['table'] = 'field_data_field_event_is_exam';
  $handler->display->display_options['fields']['field_event_is_exam']['field'] = 'field_event_is_exam';
  $handler->display->display_options['fields']['field_event_is_exam']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['fields']['field_event_is_exam']['label'] = 'exam';
  $handler->display->display_options['fields']['field_event_is_exam']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Event begin date (field_event_begin_date) */
  $handler->display->display_options['sorts']['field_event_begin_date_value']['id'] = 'field_event_begin_date_value';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['table'] = 'field_data_field_event_begin_date';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['field'] = 'field_event_begin_date_value';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['relationship'] = 'field_imp_reference_to_events_target_id';
  /* Contextual filter: Content: ID (field_imp_id) */
  $handler->display->display_options['arguments']['field_imp_id_value']['id'] = 'field_imp_id_value';
  $handler->display->display_options['arguments']['field_imp_id_value']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['arguments']['field_imp_id_value']['field'] = 'field_imp_id_value';
  $handler->display->display_options['arguments']['field_imp_id_value']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_imp_id_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_imp_id_value']['default_argument_options']['code'] = 'return str_replace(",", "+", $_GET[\'course_implementation_id\']);';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_imp_id_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_imp_id_value']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status_1']['id'] = 'status_1';
  $handler->display->display_options['filters']['status_1']['table'] = 'node';
  $handler->display->display_options['filters']['status_1']['field'] = 'status';
  $handler->display->display_options['filters']['status_1']['value'] = '1';
  $handler->display->display_options['filters']['status_1']['group'] = 1;

  /* Display: Services */
  $handler = $view->new_display('services', 'Services', 'services_1');
  $handler->display->display_options['path'] = 'events';
  $translatables['rest_api_v1_events'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_imp_reference_to_events'),
    t('course_implementation_id'),
    t('title'),
    t('begin'),
    t('end'),
    t('where'),
    t('exam'),
    t('All'),
    t('Services'),
  );
  $export['rest_api_v1_events'] = $view;

  return $export;
}
