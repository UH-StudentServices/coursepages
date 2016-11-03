<?php
/**
 * @file
 * uhc_course_implementation_activity.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_course_implementation_activity_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'course_implementation_activity';
  $view->description = '';
  $view->tag = 'uhc_course_implementation_activity';
  $view->base_table = 'message';
  $view->human_name = 'Course implementation activity';
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
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['row_class'] = '[type]';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<div class="activity-toggle"></div><div class="count"></div>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Relationship: Message: User uid */
  $handler->display->display_options['relationships']['user']['id'] = 'user';
  $handler->display->display_options['relationships']['user']['table'] = 'message';
  $handler->display->display_options['relationships']['user']['field'] = 'user';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid']['id'] = 'mid';
  $handler->display->display_options['fields']['mid']['table'] = 'message';
  $handler->display->display_options['fields']['mid']['field'] = 'mid';
  $handler->display->display_options['fields']['mid']['label'] = '';
  $handler->display->display_options['fields']['mid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['mid']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['mid']['separator'] = '';
  /* Field: User: Picture */
  $handler->display->display_options['fields']['picture']['id'] = 'picture';
  $handler->display->display_options['fields']['picture']['table'] = 'users';
  $handler->display->display_options['fields']['picture']['field'] = 'picture';
  $handler->display->display_options['fields']['picture']['relationship'] = 'user';
  $handler->display->display_options['fields']['picture']['label'] = '';
  $handler->display->display_options['fields']['picture']['element_type'] = 'div';
  $handler->display->display_options['fields']['picture']['element_class'] = 'user-picture';
  $handler->display->display_options['fields']['picture']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['picture']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['picture']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['picture']['hide_alter_empty'] = FALSE;
  $handler->display->display_options['fields']['picture']['link_photo_to_profile'] = FALSE;
  $handler->display->display_options['fields']['picture']['image_style'] = 'profile_picture';
  /* Field: Timestamp as data-attribute */
  $handler->display->display_options['fields']['timestamp_1']['id'] = 'timestamp_1';
  $handler->display->display_options['fields']['timestamp_1']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp_1']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp_1']['ui_name'] = 'Timestamp as data-attribute';
  $handler->display->display_options['fields']['timestamp_1']['label'] = '';
  $handler->display->display_options['fields']['timestamp_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp_1']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp_1']['custom_date_format'] = 'U';
  $handler->display->display_options['fields']['timestamp_1']['second_date_format'] = 'short_date_only';
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = '';
  $handler->display->display_options['fields']['type']['exclude'] = TRUE;
  $handler->display->display_options['fields']['type']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['type']['machine_name'] = TRUE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = '';
  $handler->display->display_options['fields']['timestamp']['exclude'] = TRUE;
  $handler->display->display_options['fields']['timestamp']['element_type'] = '0';
  $handler->display->display_options['fields']['timestamp']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['timestamp']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'time ago';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'long';
  /* Field: Message: Render message (Get text) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['label'] = '';
  $handler->display->display_options['fields']['message_render']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['message_render']['alter']['text'] = '[message_render]
<span class="message-date" data-mid="[mid]" data-timestamp="[timestamp_1]">[timestamp]</span>';
  $handler->display->display_options['fields']['message_render']['element_type'] = 'div';
  $handler->display->display_options['fields']['message_render']['element_class'] = 'message';
  $handler->display->display_options['fields']['message_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['message_render']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['message_render']['partials'] = 0;
  $handler->display->display_options['fields']['message_render']['partials_delta'] = '0';
  /* Sort criterion: Message: Timestamp */
  $handler->display->display_options['sorts']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['table'] = 'message';
  $handler->display->display_options['sorts']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['sorts']['timestamp']['order'] = 'DESC';
  /* Contextual filter: Message: Reference to course implementation (field_message_ref_to_course_imp) */
  $handler->display->display_options['arguments']['field_message_ref_to_course_imp_target_id']['id'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['arguments']['field_message_ref_to_course_imp_target_id']['table'] = 'field_data_field_message_ref_to_course_imp';
  $handler->display->display_options['arguments']['field_message_ref_to_course_imp_target_id']['field'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['arguments']['field_message_ref_to_course_imp_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_message_ref_to_course_imp_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_message_ref_to_course_imp_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_message_ref_to_course_imp_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_message_ref_to_course_imp_target_id']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Message: Timestamp */
  $handler->display->display_options['filters']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['table'] = 'message';
  $handler->display->display_options['filters']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['filters']['timestamp']['operator'] = '>';
  $handler->display->display_options['filters']['timestamp']['value']['value'] = '-7 day';
  $handler->display->display_options['filters']['timestamp']['value']['type'] = 'offset';
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'message';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['operator'] = 'not in';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_implementation_private_statistics' => 'course_implementation_private_statistics',
    'course_implementation_update_statistics' => 'course_implementation_update_statistics',
    'course_implementation_analytics_view' => 'course_implementation_analytics_view',
    'course_implementation_moodle_course_area_create' => 'course_implementation_moodle_course_area_create',
    'course_implementation_queue' => 'course_implementation_queue',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block_1');
  $translatables['course_implementation_activity'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<div class="activity-toggle"></div><div class="count"></div>'),
    t('User'),
    t('.'),
    t('[message_render]
<span class="message-date" data-mid="[mid]" data-timestamp="[timestamp_1]">[timestamp]</span>'),
    t('All'),
    t('Block'),
  );
  $export['course_implementation_activity'] = $view;

  $view = new view();
  $view->name = 'rss_course_implementation_activity';
  $view->description = '';
  $view->tag = 'uhc_course_implementation_activity';
  $view->base_table = 'message';
  $view->human_name = 'RSS: Course implementation activity';
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
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'short_date_only';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'short_date_only';
  /* Field: Message: Type */
  $handler->display->display_options['fields']['type']['id'] = 'type';
  $handler->display->display_options['fields']['type']['table'] = 'message';
  $handler->display->display_options['fields']['type']['field'] = 'type';
  $handler->display->display_options['fields']['type']['label'] = 'type';
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

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title_field';
  $handler->display->display_options['row_options']['link_field'] = 'nid';
  $handler->display->display_options['row_options']['description_field'] = 'message_render';
  $handler->display->display_options['row_options']['creator_field'] = 'name';
  $handler->display->display_options['row_options']['date_field'] = 'timestamp';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'mid_1',
    'guid_field_is_permalink' => 0,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Nid */
  $handler->display->display_options['fields']['nid']['id'] = 'nid';
  $handler->display->display_options['fields']['nid']['table'] = 'node';
  $handler->display->display_options['fields']['nid']['field'] = 'nid';
  $handler->display->display_options['fields']['nid']['relationship'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['fields']['nid']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['nid']['alter']['text'] = 'node/[nid]';
  /* Field: Message: Message ID */
  $handler->display->display_options['fields']['mid_1']['id'] = 'mid_1';
  $handler->display->display_options['fields']['mid_1']['table'] = 'message';
  $handler->display->display_options['fields']['mid_1']['field'] = 'mid';
  $handler->display->display_options['fields']['mid_1']['label'] = 'id';
  $handler->display->display_options['fields']['mid_1']['separator'] = '';
  /* Field: User: Name */
  $handler->display->display_options['fields']['name']['id'] = 'name';
  $handler->display->display_options['fields']['name']['table'] = 'users';
  $handler->display->display_options['fields']['name']['field'] = 'name';
  $handler->display->display_options['fields']['name']['relationship'] = 'user';
  $handler->display->display_options['fields']['name']['label'] = '';
  $handler->display->display_options['fields']['name']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['name']['link_to_user'] = FALSE;
  /* Field: Message: Timestamp */
  $handler->display->display_options['fields']['timestamp']['id'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['table'] = 'message';
  $handler->display->display_options['fields']['timestamp']['field'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['label'] = 'timestamp';
  $handler->display->display_options['fields']['timestamp']['date_format'] = 'custom';
  $handler->display->display_options['fields']['timestamp']['custom_date_format'] = 'D, d M y H:i:s O';
  $handler->display->display_options['fields']['timestamp']['second_date_format'] = 'short_date_only';
  /* Field: Message: Render message (Get text) */
  $handler->display->display_options['fields']['message_render']['id'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['table'] = 'message';
  $handler->display->display_options['fields']['message_render']['field'] = 'message_render';
  $handler->display->display_options['fields']['message_render']['label'] = '';
  $handler->display->display_options['fields']['message_render']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['message_render']['partials'] = 0;
  $handler->display->display_options['fields']['message_render']['partials_delta'] = '0';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: ID (field_imp_id) */
  $handler->display->display_options['arguments']['field_imp_id_value']['id'] = 'field_imp_id_value';
  $handler->display->display_options['arguments']['field_imp_id_value']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['arguments']['field_imp_id_value']['field'] = 'field_imp_id_value';
  $handler->display->display_options['arguments']['field_imp_id_value']['relationship'] = 'field_message_ref_to_course_imp_target_id';
  $handler->display->display_options['arguments']['field_imp_id_value']['default_action'] = 'empty';
  $handler->display->display_options['arguments']['field_imp_id_value']['default_argument_type'] = 'php';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_imp_id_value']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_imp_id_value']['limit'] = '0';
  $handler->display->display_options['arguments']['field_imp_id_value']['break_phrase'] = TRUE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Message: Type */
  $handler->display->display_options['filters']['type_1']['id'] = 'type_1';
  $handler->display->display_options['filters']['type_1']['table'] = 'message';
  $handler->display->display_options['filters']['type_1']['field'] = 'type';
  $handler->display->display_options['filters']['type_1']['operator'] = 'not in';
  $handler->display->display_options['filters']['type_1']['value'] = array(
    'course_implementation_private_statistics' => 'course_implementation_private_statistics',
    'course_implementation_update_statistics' => 'course_implementation_update_statistics',
  );
  $handler->display->display_options['path'] = 'course_implementation_activity/rss/%';
  $translatables['rss_course_implementation_activity'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_message_ref_to_course_imp'),
    t('User'),
    t('id'),
    t('.'),
    t('course_imp_id'),
    t('message'),
    t('user'),
    t('oodi_uid'),
    t('timestamp'),
    t('type'),
    t('All'),
    t('Timestamp'),
    t('Feed'),
    t('Nid'),
    t('node/[nid]'),
  );
  $export['rss_course_implementation_activity'] = $view;

  return $export;
}
