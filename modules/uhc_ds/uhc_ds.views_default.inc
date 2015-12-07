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
  $handler->display->display_options['css_class'] = 'ds-teaser-accordion--content--indented event-list';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['view_mode'] = 'teaser_accordion';
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'node|created';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser_accordion';
  $handler->display->display_options['row_options']['switch_fieldset']['switch'] = TRUE;
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="ds-material-block--content event-list-header"><span class="event-column"><span class="field accordion-content-item--label event-date">Date</span><span class="field accordion-content-item--label event-time">Time</span></span><span class="event-column"><span class="field hide-from-three-column-tables accordion-content-item--label event-title">Title</span><span class="field remove-styles accordion-content-item--label event-location">Location</span></span></span>';
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

  /* Display: Events imported from WebOodi */
  $handler = $view->new_display('block', 'Events imported from WebOodi', 'block_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Teaching schedule';
  $handler->display->display_options['display_description'] = 'A list of repeating events (reverse entity references)';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['relationship'] = 'field_imp_ref_to_events_oodi_target_id';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_event_begin_date|field_event_begin_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  $handler->display->display_options['row_options']['switch_fieldset']['switch'] = TRUE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: System message */
  $handler->display->display_options['header']['system_message']['id'] = 'system_message';
  $handler->display->display_options['header']['system_message']['table'] = 'views';
  $handler->display->display_options['header']['system_message']['field'] = 'system_message';
  $handler->display->display_options['header']['system_message']['label'] = 'Repeating events coming from Oodi';
  $handler->display->display_options['header']['system_message']['class'] = 'alternative';
  $handler->display->display_options['header']['system_message']['text'] = 'These events are imported from WebOodi';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="ds-material-block--content event-list-header"><span class="event-column"><span class="field accordion-content-item--label event-date">Date</span><span class="field accordion-content-item--label event-time">Time</span></span><span class="event-column"><span class="field hide-from-three-column-tables accordion-content-item--label event-title">Title</span><span class="field remove-styles accordion-content-item--label event-location">Location</span></span></span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  $handler->display->display_options['header']['area']['tokenize'] = TRUE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_ref_to_events_oodi_target_id']['id'] = 'field_imp_ref_to_events_oodi_target_id';
  $handler->display->display_options['relationships']['field_imp_ref_to_events_oodi_target_id']['table'] = 'field_data_field_imp_ref_to_events_oodi';
  $handler->display->display_options['relationships']['field_imp_ref_to_events_oodi_target_id']['field'] = 'field_imp_ref_to_events_oodi_target_id';
  $handler->display->display_options['relationships']['field_imp_ref_to_events_oodi_target_id']['required'] = TRUE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Content: Event begin date (field_event_begin_date) */
  $handler->display->display_options['sorts']['field_event_begin_date_value_1']['id'] = 'field_event_begin_date_value_1';
  $handler->display->display_options['sorts']['field_event_begin_date_value_1']['table'] = 'field_data_field_event_begin_date';
  $handler->display->display_options['sorts']['field_event_begin_date_value_1']['field'] = 'field_event_begin_date_value';
  $handler->display->display_options['sorts']['field_event_begin_date_value_1']['relationship'] = 'field_imp_ref_to_events_oodi_target_id';
  $handler->display->display_options['sorts']['field_event_begin_date_value_1']['expose']['label'] = 'Event begin date (field_event_begin_date)';
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
  $handler->display->display_options['filters']['status']['relationship'] = 'field_imp_ref_to_events_oodi_target_id';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  $translatables['course_event_references'] = array(
    t('Master'),
    t('Events'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<span class="ds-material-block--content event-list-header"><span class="event-column"><span class="field accordion-content-item--label event-date">Date</span><span class="field accordion-content-item--label event-time">Time</span></span><span class="event-column"><span class="field hide-from-three-column-tables accordion-content-item--label event-title">Title</span><span class="field remove-styles accordion-content-item--label event-location">Location</span></span></span>'),
    t('Events added in course page'),
    t('Other events'),
    t('A list of events (reverse entity references)'),
    t('Content entity referenced from field_imp_reference_to_events'),
    t('All'),
    t('Event material list'),
    t('A list of event related material'),
    t('Events imported from WebOodi'),
    t('Teaching schedule'),
    t('A list of repeating events (reverse entity references)'),
    t('Repeating events coming from Oodi'),
    t('These events are imported from WebOodi'),
    t('Content entity referenced from field_imp_ref_to_events_oodi'),
    t('Event begin date (field_event_begin_date)'),
  );
  $export['course_event_references'] = $view;

  $view = new view();
  $view->name = 'course_event_references_light';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course event references - light';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'event-list table-three-columns content light';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'ds';
  $handler->display->display_options['row_options']['load_comments'] = 0;
  $handler->display->display_options['row_options']['grouping'] = 0;
  $handler->display->display_options['row_options']['advanced'] = 0;
  $handler->display->display_options['row_options']['delta_fieldset']['delta_fields'] = array();
  $handler->display->display_options['row_options']['grouping_fieldset']['group_field'] = 'field_data_field_event_begin_date|field_event_begin_date_value';
  $handler->display->display_options['row_options']['default_fieldset']['view_mode'] = 'teaser';
  /* Header: Global: Text area */
  $handler->display->display_options['header']['area']['id'] = 'area';
  $handler->display->display_options['header']['area']['table'] = 'views';
  $handler->display->display_options['header']['area']['field'] = 'area';
  $handler->display->display_options['header']['area']['content'] = '<span class="ds-material-block--content event-list-header"><span class="event-column"><span class="field accordion-content-item--label event-date">Date</span><span class="field accordion-content-item--label event-time">Time</span></span><span class="event-column"><span class="field hide-from-three-column-tables accordion-content-item--label event-title">Title</span><span class="field remove-styles accordion-content-item--label event-location">Location</span></span></span>';
  $handler->display->display_options['header']['area']['format'] = 'full_html';
  /* Field: Content: Event location name */
  $handler->display->display_options['fields']['field_event_loc_name']['id'] = 'field_event_loc_name';
  $handler->display->display_options['fields']['field_event_loc_name']['table'] = 'field_data_field_event_loc_name';
  $handler->display->display_options['fields']['field_event_loc_name']['field'] = 'field_event_loc_name';
  $handler->display->display_options['fields']['field_event_loc_name']['label'] = '';
  $handler->display->display_options['fields']['field_event_loc_name']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_event_loc_name']['alter']['text'] = ', [field_event_loc_name]';
  $handler->display->display_options['fields']['field_event_loc_name']['element_label_colon'] = FALSE;
  /* Sort criterion: Content: Event begin date (field_event_begin_date) */
  $handler->display->display_options['sorts']['field_event_begin_date_value']['id'] = 'field_event_begin_date_value';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['table'] = 'field_data_field_event_begin_date';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['field'] = 'field_event_begin_date_value';
  $handler->display->display_options['sorts']['field_event_begin_date_value']['relationship'] = 'field_imp_reference_to_events_target_id';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['relationship'] = 'reverse_field_imp_reference_to_courses_node';
  $handler->display->display_options['filters']['status']['value'] = '1';
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;

  /* Display: Event list */
  $handler = $view->new_display('block', 'Event list', 'block');
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
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['defaults']['relationships'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['id'] = 'field_imp_reference_to_events_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['table'] = 'field_data_field_imp_reference_to_events';
  $handler->display->display_options['relationships']['field_imp_reference_to_events_target_id']['field'] = 'field_imp_reference_to_events_target_id';
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
  $translatables['course_event_references_light'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('<span class="ds-material-block--content event-list-header"><span class="event-column"><span class="field accordion-content-item--label event-date">Date</span><span class="field accordion-content-item--label event-time">Time</span></span><span class="event-column"><span class="field hide-from-three-column-tables accordion-content-item--label event-title">Title</span><span class="field remove-styles accordion-content-item--label event-location">Location</span></span></span>'),
    t(', [field_event_loc_name]'),
    t('Event list'),
    t('A list of events (reverse entity references)'),
    t('Content entity referenced from field_imp_reference_to_events'),
    t('All'),
  );
  $export['course_event_references_light'] = $view;

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
  $handler->display->display_options['row_options']['switch_fieldset']['switch'] = TRUE;
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

  return $export;
}
