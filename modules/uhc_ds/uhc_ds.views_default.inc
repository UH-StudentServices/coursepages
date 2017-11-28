<?php
/**
 * @file
 * uhc_ds.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_ds_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'course_event_references';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course event references';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Events';
  $handler->display->display_options['css_class'] = 'event-list table-three-columns';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  $handler->display->display_options['row_options']['switch_fieldset']['switch'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="event-list-header"><span class="event-column"><span class="field accordion-content-item--label event-date">Date</span><span class="field accordion-content-item--label event-time">Time</span></span><span class="event-column"><span class="field hide-from-three-column-tables accordion-content-item--label event-title">Title</span><span class="field remove-styles accordion-content-item--label event-location">Location</span></span></span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Events added in course page */
  $handler = $view->new_display('block', 'Events added in course page', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Other events';
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'event-list table-four-columns';
  $handler->display->display_options['display_description'] = 'A list of events (reverse entity references)';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_event_begin_date|field_event_begin_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  $handler->display->display_options['row_options']['switch_fieldset']['switch'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['id'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['table'] = 'field_data_field_imp_reference_to_events';
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['field'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Event begin date (field_event_begin_date) */
  $handler->display->display_options['sorts']['field_event_begin_date_value']['id'] = 'field_event_begin_date_value';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['table'] = 'field_data_field_event_begin_date';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['field'] = 'field_event_begin_date_value';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Event material list */
  $handler = $view->new_display('block', 'Event material list', 'block_1');
  $handler->display->display_options['display_description'] = 'A list of event related material';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'material_block';
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'material_block';
  $handler->display->display_options['row_options']['switch_fieldset']['switch'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_material' => 'course_material',
  );
  $translatables['course_event_references'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<span class="event-list-header"><span class="event-column"><span class="field accordion-content-item--label event-date">Date</span><span class="field accordion-content-item--label event-time">Time</span></span><span class="event-column"><span class="field hide-from-three-column-tables accordion-content-item--label event-title">Title</span><span class="field remove-styles accordion-content-item--label event-location">Location</span></span></span>'),
    t('Events added in course page'),
    t('Other events'),
    t('A list of events (reverse entity references)'),
    t('Content entity referenced from field_imp_reference_to_events'),
    t('All'),
    t('Event material list'),
    t('A list of event related material'),
  );
  $export['course_event_references'] = $view;

  $view = new view();
  $view->name = 'course_node_references';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course node references';
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
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_imp_begin_date|field_imp_begin_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_imp_reference_to_courses_node']['id'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['relationships']['reverse_field_imp_reference_to_courses_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_imp_reference_to_courses_node']['field'] = 'reverse_field_imp_reference_to_courses_node';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Sort criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  /* Contextual filter: Content: Reference to course(s) (field_imp_reference_to_courses) */
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: End date (field_imp_end_date) */
  $handler->display->display_options['filters']['field_imp_end_date_value']['id'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['table'] = 'field_data_field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date_value']['field'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['field_imp_end_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_end_date_value']['default_date'] = 'now -4 months';

  /* Display: Implementation list */
  $handler = $view->new_display('block', 'Implementation list', 'block');
  $handler->display->display_options['display_description'] = 'A list of course implementations (reverse entity references)';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: End date (field_imp_end_date) */
  $handler->display->display_options['filters']['field_imp_end_date_value']['id'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['table'] = 'field_data_field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date_value']['field'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['field_imp_end_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_end_date_value']['default_date'] = 'now';

  /* Display: Implementation list - past */
  $handler = $view->new_display('block', 'Implementation list - past', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'course-node-references-past element-hidden';
  $handler->display->display_options['display_description'] = 'A list of past course implementations (reverse entity references)';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: End date (field_imp_end_date) */
  $handler->display->display_options['filters']['field_imp_end_date_value']['id'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['table'] = 'field_data_field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date_value']['field'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['field_imp_end_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_imp_end_date_value']['default_date'] = 'now';
  $translatables['course_node_references'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_imp_reference_to_courses'),
    t('All'),
    t('Implementation list'),
    t('A list of course implementations (reverse entity references)'),
    t('Implementation list - past'),
    t('A list of past course implementations (reverse entity references)'),
  );
  $export['course_node_references'] = $view;

  $view = new view();
  $view->name = 'list_of_course_imps_in_course_node_view';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'List of course imps in course node view';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'course-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'title' => 'title',
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
  );
  /* Relationship: Entity Reference: Referencing entity */
  $handler->display->display_options['relationships']['reverse_field_imp_reference_to_courses_node']['id'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['relationships']['reverse_field_imp_reference_to_courses_node']['table'] = 'node';
  $handler->display->display_options['relationships']['reverse_field_imp_reference_to_courses_node']['field'] = 'reverse_field_imp_reference_to_courses_node';
  /* Field: Content: Cancelled */
  $handler->display->display_options['fields']['field_cancelled']['id'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['table'] = 'field_data_field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['field'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['fields']['field_cancelled']['label'] = '';
  $handler->display->display_options['fields']['field_cancelled']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cancelled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cancelled']['type'] = 'cancelled';
  /* Field: Content: Flexible start */
  $handler->display->display_options['fields']['field_imp_flexible_start']['id'] = 'field_imp_flexible_start';
  $handler->display->display_options['fields']['field_imp_flexible_start']['table'] = 'field_data_field_imp_flexible_start';
  $handler->display->display_options['fields']['field_imp_flexible_start']['field'] = 'field_imp_flexible_start';
  $handler->display->display_options['fields']['field_imp_flexible_start']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['fields']['field_imp_flexible_start']['label'] = '';
  $handler->display->display_options['fields']['field_imp_flexible_start']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_flexible_start']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_flexible_start']['type'] = 'flexible_start';
  $handler->display->display_options['fields']['field_imp_flexible_start']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['exclude'] = TRUE;
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 1;
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['label'] = 'Name';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_cancelled]  [title_field] [field_imp_flexible_start]';
  $handler->display->display_options['fields']['nothing_1']['element_class'] = 'views-field-title-field';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing_1']['element_default_classes'] = FALSE;
  /* Field: Content: Credit */
  $handler->display->display_options['fields']['field_study_credit']['id'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['table'] = 'field_data_field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['field'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['fields']['field_study_credit']['label'] = 'Cr';
  $handler->display->display_options['fields']['field_study_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_study_credit']['alter']['text'] = '[field_study_credit-value] <span class="show-only-in-mobile">Cr</span>';
  $handler->display->display_options['fields']['field_study_credit']['element_label_colon'] = FALSE;
  /* Field: Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['fields']['field_imp_begin_date']['label'] = '';
  $handler->display->display_options['fields']['field_imp_begin_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: End date */
  $handler->display->display_options['fields']['field_imp_end_date']['id'] = 'field_imp_end_date';
  $handler->display->display_options['fields']['field_imp_end_date']['table'] = 'field_data_field_imp_end_date';
  $handler->display->display_options['fields']['field_imp_end_date']['field'] = 'field_imp_end_date';
  $handler->display->display_options['fields']['field_imp_end_date']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['fields']['field_imp_end_date']['label'] = '';
  $handler->display->display_options['fields']['field_imp_end_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_end_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_end_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = 'Time';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_imp_begin_date] - [field_imp_end_date]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Locality */
  $handler->display->display_options['fields']['field_imp_locality']['id'] = 'field_imp_locality';
  $handler->display->display_options['fields']['field_imp_locality']['table'] = 'field_data_field_imp_locality';
  $handler->display->display_options['fields']['field_imp_locality']['field'] = 'field_imp_locality';
  $handler->display->display_options['fields']['field_imp_locality']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['fields']['field_imp_locality']['label'] = 'Location';
  $handler->display->display_options['fields']['field_imp_locality']['element_label_colon'] = FALSE;
  /* Field: Content: Course organiser */
  $handler->display->display_options['fields']['field_imp_course_organiser']['id'] = 'field_imp_course_organiser';
  $handler->display->display_options['fields']['field_imp_course_organiser']['table'] = 'field_data_field_imp_course_organiser';
  $handler->display->display_options['fields']['field_imp_course_organiser']['field'] = 'field_imp_course_organiser';
  $handler->display->display_options['fields']['field_imp_course_organiser']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['fields']['field_imp_course_organiser']['label'] = 'Organiser';
  $handler->display->display_options['fields']['field_imp_course_organiser']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  /* Contextual filter: Content: Reference to course(s) (field_imp_reference_to_courses) */
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['default_action'] = 'default';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['arguments']['field_imp_reference_to_courses_target_id']['break_phrase'] = TRUE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: End date (field_imp_end_date) */
  $handler->display->display_options['filters']['field_imp_end_date_value']['id'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['table'] = 'field_data_field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date_value']['field'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['field_imp_end_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_end_date_value']['default_date'] = 'now -4 months';

  /* Display: Implementation list */
  $handler = $view->new_display('block', 'Implementation list', 'block');
  $handler->display->display_options['display_description'] = 'A list of course implementations (reverse entity references)';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'Headline';
  $handler->display->display_options['header']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h3>Instruction</h3>';
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: End date (field_imp_end_date) */
  $handler->display->display_options['filters']['field_imp_end_date_value']['id'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['table'] = 'field_data_field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date_value']['field'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['field_imp_end_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_end_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Hierarchy position (field_hierarchy_position) */
  $handler->display->display_options['filters']['field_hierarchy_position_value']['id'] = 'field_hierarchy_position_value';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['table'] = 'field_data_field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['field'] = 'field_hierarchy_position_value';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['value'] = 'root';

  /* Display: Implementation list - past */
  $handler = $view->new_display('block', 'Implementation list - past', 'block_1');
  $handler->display->display_options['defaults']['css_class'] = FALSE;
  $handler->display->display_options['css_class'] = 'course-list course-node-references-past element-hidden';
  $handler->display->display_options['display_description'] = 'A list of past course implementations (reverse entity references)';
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['order'] = 'DESC';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: End date (field_imp_end_date) */
  $handler->display->display_options['filters']['field_imp_end_date_value']['id'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['table'] = 'field_data_field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date_value']['field'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['field_imp_end_date_value']['operator'] = '<';
  $handler->display->display_options['filters']['field_imp_end_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Hierarchy position (field_hierarchy_position) */
  $handler->display->display_options['filters']['field_hierarchy_position_value']['id'] = 'field_hierarchy_position_value';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['table'] = 'field_data_field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['field'] = 'field_hierarchy_position_value';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['value'] = 'root';
  $translatables['list_of_course_imps_in_course_node_view'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content referencing Content from field_imp_reference_to_courses'),
    t('Name'),
    t('[field_cancelled]  [title_field] [field_imp_flexible_start]'),
    t('Cr'),
    t('[field_study_credit-value] <span class="show-only-in-mobile">Cr</span>'),
    t('Time'),
    t('[field_imp_begin_date] - [field_imp_end_date]'),
    t('Location'),
    t('Organiser'),
    t('All'),
    t('Implementation list'),
    t('A list of course implementations (reverse entity references)'),
    t('Headline'),
    t('<h3>Instruction</h3>'),
    t('Implementation list - past'),
    t('A list of past course implementations (reverse entity references)'),
  );
  $export['list_of_course_imps_in_course_node_view'] = $view;

  return $export;
}
