<?php
/**
 * @file
 * uhc_taxonomy.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_taxonomy_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'taxonomy_term';
  $view->description = 'A view to emulate Drupal core\'s handling of taxonomy/term.';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Taxonomy term';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'time';
  $handler->display->display_options['cache']['results_lifespan'] = '3600';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '21600';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['query']['options']['query_comment'] = FALSE;
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'mini';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['row_plugin'] = 'node';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['label'] = 'Course';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['required'] = TRUE;
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'r';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Content: URL */
  $handler->display->display_options['fields']['field_moodle_url']['id'] = 'field_moodle_url';
  $handler->display->display_options['fields']['field_moodle_url']['table'] = 'field_data_field_moodle_url';
  $handler->display->display_options['fields']['field_moodle_url']['field'] = 'field_moodle_url';
  $handler->display->display_options['fields']['field_moodle_url']['label'] = '';
  $handler->display->display_options['fields']['field_moodle_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_moodle_url']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_moodle_url']['type'] = 'link_absolute';
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Description */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Description';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_imp_reference_to_courses_field_course_course_number][field_course_type_of_teaching][field_imp_method_of_study][field_imp_begin_date][field_imp_teacher]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
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
  /* Field: Content: Course number */
  $handler->display->display_options['fields']['field_course_course_number']['id'] = 'field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['table'] = 'field_data_field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['field'] = 'field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_course_number']['label'] = '';
  $handler->display->display_options['fields']['field_course_course_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_course_number']['type'] = 'text_plain';
  /* Field: Content: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'field_data_field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['label'] = '';
  $handler->display->display_options['fields']['field_imp_method_of_study']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Teacher */
  $handler->display->display_options['fields']['field_imp_teacher']['id'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['table'] = 'field_data_field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['field'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['label'] = '';
  $handler->display->display_options['fields']['field_imp_teacher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_teacher']['type'] = 'text_plain';
  /* Field: Content: Type of teaching */
  $handler->display->display_options['fields']['field_course_type_of_teaching']['id'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['table'] = 'field_data_field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['field'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['label'] = '';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['type'] = 'taxonomy_term_reference_plain';
  /* Sort criterion: Content: Begin date (field_imp_begin_date) */
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['id'] = 'field_imp_begin_date_value';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['sorts']['field_imp_begin_date_value']['field'] = 'field_imp_begin_date_value';
  /* Contextual filter: Content: Has taxonomy term ID (with depth) */
  $handler->display->display_options['arguments']['term_node_tid_depth']['id'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth']['field'] = 'term_node_tid_depth';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_action'] = 'not found';
  $handler->display->display_options['arguments']['term_node_tid_depth']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['title'] = '%1';
  $handler->display->display_options['arguments']['term_node_tid_depth']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth']['specify_validation'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth']['validate']['type'] = 'taxonomy_term';
  $handler->display->display_options['arguments']['term_node_tid_depth']['depth'] = '0';
  $handler->display->display_options['arguments']['term_node_tid_depth']['break_phrase'] = TRUE;
  /* Contextual filter: Content: Has taxonomy term ID depth modifier */
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['id'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['table'] = 'node';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['field'] = 'term_node_tid_depth_modifier';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['exception']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['term_node_tid_depth_modifier']['specify_validation'] = TRUE;
  /* Filter criterion: Content: Published or admin */
  $handler->display->display_options['filters']['status_extra']['id'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['table'] = 'node';
  $handler->display->display_options['filters']['status_extra']['field'] = 'status_extra';
  $handler->display->display_options['filters']['status_extra']['group'] = 0;
  $handler->display->display_options['filters']['status_extra']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: End date (field_imp_end_date) */
  $handler->display->display_options['filters']['field_imp_end_date_value']['id'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['table'] = 'field_data_field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date_value']['field'] = 'field_imp_end_date_value';
  $handler->display->display_options['filters']['field_imp_end_date_value']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_end_date_value']['default_date'] = 'now';
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_implementation' => 'course_implementation',
  );
  /* Filter criterion: Content: Hierarchy position (field_hierarchy_position) */
  $handler->display->display_options['filters']['field_hierarchy_position_value']['id'] = 'field_hierarchy_position_value';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['table'] = 'field_data_field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['field'] = 'field_hierarchy_position_value';
  $handler->display->display_options['filters']['field_hierarchy_position_value']['value'] = 'studygroup';

  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'taxonomy/term/%';

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Next 100 upcoming courses.';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title_field';
  $handler->display->display_options['row_options']['link_field'] = 'nothing_2';
  $handler->display->display_options['row_options']['description_field'] = 'nothing';
  $handler->display->display_options['row_options']['creator_field'] = 'nothing_1';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'nothing_2',
    'guid_field_is_permalink' => 1,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Field: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'field_data_title_field';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['link_to_entity'] = 0;
  /* Field: Content: Course number */
  $handler->display->display_options['fields']['field_course_course_number']['id'] = 'field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['table'] = 'field_data_field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['field'] = 'field_course_course_number';
  $handler->display->display_options['fields']['field_course_course_number']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_course_number']['label'] = '';
  $handler->display->display_options['fields']['field_course_course_number']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_course_number']['type'] = 'text_plain';
  /* Field: Content: ID */
  $handler->display->display_options['fields']['field_imp_id']['id'] = 'field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['table'] = 'field_data_field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['field'] = 'field_imp_id';
  $handler->display->display_options['fields']['field_imp_id']['label'] = '';
  $handler->display->display_options['fields']['field_imp_id']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_id']['type'] = 'text_plain';
  /* Field: Content: Type of teaching */
  $handler->display->display_options['fields']['field_course_type_of_teaching']['id'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['table'] = 'field_data_field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['field'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['label'] = '';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['alter']['text'] = '[field_course_type_of_teaching], ';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'field_data_field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['label'] = '';
  $handler->display->display_options['fields']['field_imp_method_of_study']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['alter']['text'] = '[field_imp_method_of_study], ';
  $handler->display->display_options['fields']['field_imp_method_of_study']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['type'] = 'taxonomy_term_reference_plain';
  /* Field: Content: Teacher */
  $handler->display->display_options['fields']['field_imp_teacher']['id'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['table'] = 'field_data_field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['field'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['label'] = '';
  $handler->display->display_options['fields']['field_imp_teacher']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_teacher']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_teacher']['type'] = 'text_plain';
  /* Field: Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['label'] = '';
  $handler->display->display_options['fields']['field_imp_begin_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => '',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  /* Field: Content: Post date */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'node';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['created']['alter']['text'] = '[field_imp_begin_date]';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'r';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Description */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Description';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '[field_course_course_number], [field_course_type_of_teaching][field_imp_method_of_study][field_imp_teacher], [field_imp_begin_date]';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Static creator text */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Static creator text';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['exclude'] = TRUE;
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = 'Helsinki University';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  /* Field: Relative URL */
  $handler->display->display_options['fields']['nothing_2']['id'] = 'nothing_2';
  $handler->display->display_options['fields']['nothing_2']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_2']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_2']['ui_name'] = 'Relative URL';
  $handler->display->display_options['fields']['nothing_2']['label'] = '';
  $handler->display->display_options['fields']['nothing_2']['alter']['text'] = '[field_course_course_number]/[field_imp_id]';
  $handler->display->display_options['fields']['nothing_2']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'taxonomy/term/%/%/feed';
  $handler->display->display_options['displays'] = array(
    'page' => 'page',
    'default' => 0,
  );
  $translatables['taxonomy_term'] = array(
    t('Master'),
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
    t('[field_imp_reference_to_courses_field_course_course_number][field_course_type_of_teaching][field_imp_method_of_study][field_imp_begin_date][field_imp_teacher]'),
    t('All'),
    t('%1'),
    t('Page'),
    t('Feed'),
    t('[field_course_type_of_teaching], '),
    t('[field_imp_method_of_study], '),
    t('[field_imp_begin_date]'),
    t('[field_course_course_number], [field_course_type_of_teaching][field_imp_method_of_study][field_imp_teacher], [field_imp_begin_date]'),
    t('Helsinki University'),
    t('[field_course_course_number]/[field_imp_id]'),
  );
  $export['taxonomy_term'] = $view;

  return $export;
}
