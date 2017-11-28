<?php
/**
 * @file
 * uhc_search_front_page.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_search_front_page_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uhc_portal_search_front_page_';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_uhc_portal';
  $view->human_name = 'UHC Portal search (front page)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'course-search front-page-search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'desktop';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'input_required';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Show results';
  $handler->display->display_options['exposed_form']['options']['reset_button'] = TRUE;
  $handler->display->display_options['exposed_form']['options']['reset_button_label'] = 'Clear selections  x';
  $handler->display->display_options['exposed_form']['options']['exposed_sorts_label'] = 'Sorting:';
  $handler->display->display_options['exposed_form']['options']['expose_sort_order'] = FALSE;
  $handler->display->display_options['exposed_form']['options']['text_input_required'] = '';
  $handler->display->display_options['exposed_form']['options']['text_input_required_format'] = 'filtered_html';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '16';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'url' => 'url',
    'title_field' => 'title_field',
    'field_study_credit' => 'field_study_credit',
    'field_imp_method_of_study' => 'field_imp_method_of_study',
    'field_imp_locality' => 'field_imp_locality',
    'field_imp_begin_date' => 'field_imp_begin_date',
  );
  $handler->display->display_options['style_options']['default'] = 'title_field';
  $handler->display->display_options['style_options']['info'] = array(
    'url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'title_field' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_study_credit' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_method_of_study' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_locality' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_begin_date' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2>Results (@total)</h2>';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_3']['id'] = 'block_3';
  $handler->display->display_options['header']['block_3']['table'] = 'views';
  $handler->display->display_options['header']['block_3']['field'] = 'block';
  $handler->display->display_options['header']['block_3']['label'] = 'Organisation';
  $handler->display->display_options['header']['block_3']['block_to_insert'] = 'facetapi:UHyOu2m5IufOONBzgYtqiXaxReuk8K7e';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block']['id'] = 'block';
  $handler->display->display_options['header']['block']['table'] = 'views';
  $handler->display->display_options['header']['block']['field'] = 'block';
  $handler->display->display_options['header']['block']['label'] = 'Method of study';
  $handler->display->display_options['header']['block']['block_to_insert'] = 'facetapi:do4BdKvyCgpZP4td6B6GmQ8iCUJ40HBx';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_1']['id'] = 'block_1';
  $handler->display->display_options['header']['block_1']['table'] = 'views';
  $handler->display->display_options['header']['block_1']['field'] = 'block';
  $handler->display->display_options['header']['block_1']['label'] = 'Start month';
  $handler->display->display_options['header']['block_1']['block_to_insert'] = 'facetapi:cEQesYoZJTu7ITT2OD5RXHP0T0bqniOh';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_4']['id'] = 'block_4';
  $handler->display->display_options['header']['block_4']['table'] = 'views';
  $handler->display->display_options['header']['block_4']['field'] = 'block';
  $handler->display->display_options['header']['block_4']['label'] = 'Teaching language';
  $handler->display->display_options['header']['block_4']['block_to_insert'] = 'facetapi:as918Au1kK03VaWu2iPYsRfNZ1iJWE7X';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_2']['id'] = 'block_2';
  $handler->display->display_options['header']['block_2']['table'] = 'views';
  $handler->display->display_options['header']['block_2']['field'] = 'block';
  $handler->display->display_options['header']['block_2']['label'] = 'Type of teaching';
  $handler->display->display_options['header']['block_2']['block_to_insert'] = 'facetapi:ebLMT1Egl05afck7AKCq6EMM2B4VuGer';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Reference to course(s): Course number (indexed) */
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['id'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['field'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['label'] = 'ID';
  /* Field: Indexed Multilingual Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Name';
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '<a href="[field_imp_reference_to_courses_url]">[title_field]</a>';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[url]';
  /* Field: Indexed Multilingual Content: Type of teaching */
  $handler->display->display_options['fields']['field_course_type_of_teaching']['id'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['field'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['link_to_entity'] = 1;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_imp_method_of_study']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_imp_method_of_study']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Locality */
  $handler->display->display_options['fields']['field_imp_locality']['id'] = 'field_imp_locality';
  $handler->display->display_options['fields']['field_imp_locality']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_locality']['field'] = 'field_imp_locality';
  $handler->display->display_options['fields']['field_imp_locality']['label'] = 'Location';
  /* Field: Indexed Multilingual Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Indexed Multilingual Content: Academic year */
  $handler->display->display_options['filters']['academic_year']['id'] = 'academic_year';
  $handler->display->display_options['filters']['academic_year']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['academic_year']['field'] = 'academic_year';
  $handler->display->display_options['filters']['academic_year']['group'] = 1;
  $handler->display->display_options['filters']['academic_year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['academic_year']['expose']['operator_id'] = 'academic_year_op';
  $handler->display->display_options['filters']['academic_year']['expose']['label'] = 'Academic year';
  $handler->display->display_options['filters']['academic_year']['expose']['operator'] = 'academic_year_op';
  $handler->display->display_options['filters']['academic_year']['expose']['identifier'] = 'academic_year';
  $handler->display->display_options['filters']['academic_year']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['academic_year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['academic_year']['group_info']['label'] = 'Academic year';
  $handler->display->display_options['filters']['academic_year']['group_info']['identifier'] = 'academic_year';
  $handler->display->display_options['filters']['academic_year']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['academic_year']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Indexed Multilingual Content: Combined fulltext */
  $handler->display->display_options['filters']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['group'] = 1;
  $handler->display->display_options['filters']['search_api_aggregation_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator_id'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['description'] = 'If you want to see all the courses, leave the search field empty.';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Indexed Multilingual Content: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Hierarchy position */
  $handler->display->display_options['filters']['field_hierarchy_position']['id'] = 'field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['field_hierarchy_position']['field'] = 'field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position']['value'] = 'root';
  $handler->display->display_options['filters']['field_hierarchy_position']['group'] = 1;

  /* Display: Desktop */
  $handler = $view->new_display('page', 'Desktop', 'desktop');
  $handler->display->display_options['display_description'] = 'Table';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2>Results (max 100)</h2>';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_3']['id'] = 'block_3';
  $handler->display->display_options['header']['block_3']['table'] = 'views';
  $handler->display->display_options['header']['block_3']['field'] = 'block';
  $handler->display->display_options['header']['block_3']['label'] = 'Organisation';
  $handler->display->display_options['header']['block_3']['block_to_insert'] = 'facetapi:UHyOu2m5IufOONBzgYtqiXaxReuk8K7e';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block']['id'] = 'block';
  $handler->display->display_options['header']['block']['table'] = 'views';
  $handler->display->display_options['header']['block']['field'] = 'block';
  $handler->display->display_options['header']['block']['label'] = 'Method of study';
  $handler->display->display_options['header']['block']['block_to_insert'] = 'facetapi:do4BdKvyCgpZP4td6B6GmQ8iCUJ40HBx';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_1']['id'] = 'block_1';
  $handler->display->display_options['header']['block_1']['table'] = 'views';
  $handler->display->display_options['header']['block_1']['field'] = 'block';
  $handler->display->display_options['header']['block_1']['label'] = 'Start month';
  $handler->display->display_options['header']['block_1']['block_to_insert'] = 'facetapi:cEQesYoZJTu7ITT2OD5RXHP0T0bqniOh';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_4']['id'] = 'block_4';
  $handler->display->display_options['header']['block_4']['table'] = 'views';
  $handler->display->display_options['header']['block_4']['field'] = 'block';
  $handler->display->display_options['header']['block_4']['label'] = 'Teaching language';
  $handler->display->display_options['header']['block_4']['block_to_insert'] = 'facetapi:as918Au1kK03VaWu2iPYsRfNZ1iJWE7X';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_2']['id'] = 'block_2';
  $handler->display->display_options['header']['block_2']['table'] = 'views';
  $handler->display->display_options['header']['block_2']['field'] = 'block';
  $handler->display->display_options['header']['block_2']['label'] = 'Type of teaching';
  $handler->display->display_options['header']['block_2']['block_to_insert'] = 'facetapi:ebLMT1Egl05afck7AKCq6EMM2B4VuGer';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Reference to course(s): Course number (indexed) */
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['id'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['field'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['label'] = 'ID';
  /* Field: Indexed Multilingual Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Name';
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '<a href="[field_imp_reference_to_courses_url]">[title_field]</a>';
  $handler->display->display_options['fields']['title_field']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[url]';
  /* Field: Reference to course(s): Type of teaching (indexed) */
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['id'] = 'field_imp_reference_to_courses_field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['field'] = 'field_imp_reference_to_courses_field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['label'] = 'Type of teaching';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_imp_method_of_study']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_imp_method_of_study']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Indexed Multilingual Content: Teacher */
  $handler->display->display_options['fields']['field_imp_teacher']['id'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_teacher']['field'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['label'] = 'Teacher(s)';
  /* Field: Content: Favorite widget */
  $handler->display->display_options['fields']['favorite_widget']['id'] = 'favorite_widget';
  $handler->display->display_options['fields']['favorite_widget']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['favorite_widget']['field'] = 'favorite_widget';
  $handler->display->display_options['fields']['favorite_widget']['label'] = 'Favorites';
  $handler->display->display_options['fields']['favorite_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['favorite_widget']['link_to_entity'] = 0;
  $handler->display->display_options['path'] = 'search/results';

  /* Display: Facets block */
  $handler = $view->new_display('search_api_views_facets_block', 'Facets block', 'search_api_views_facets_block_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['block_description'] = 'Front page search facets';
  $handler->display->display_options['linked_path'] = 'search/results';
  $handler->display->display_options['facet_field'] = 'nid';
  $handler->display->display_options['hide_block'] = 1;

  /* Display: Feed */
  $handler = $view->new_display('feed', 'Feed', 'feed_1');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Course Search';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Top 100 hits for given course search.';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title_field';
  $handler->display->display_options['row_options']['link_field'] = 'url';
  $handler->display->display_options['row_options']['description_field'] = 'nothing_1';
  $handler->display->display_options['row_options']['creator_field'] = 'nothing';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'url',
    'guid_field_is_permalink' => 1,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '<a href="[field_imp_reference_to_courses_url]">[title_field]</a>';
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Indexed Multilingual Node: Date created (RFC 2822 format) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'Indexed Multilingual Node: Date created (RFC 2822 format)';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s O';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Static creator text (Helsinki University) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Static creator text (Helsinki University)';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Helsinki University';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Reference to course(s): Course number (indexed) */
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['id'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['field'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['label'] = '';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: Type of teaching */
  $handler->display->display_options['fields']['field_course_type_of_teaching']['id'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['field'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['label'] = '';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['alter']['text'] = ', [field_course_type_of_teaching]';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['label'] = '';
  $handler->display->display_options['fields']['field_imp_method_of_study']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['alter']['text'] = ', [field_imp_method_of_study]';
  $handler->display->display_options['fields']['field_imp_method_of_study']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_imp_method_of_study']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_imp_method_of_study']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['label'] = '';
  $handler->display->display_options['fields']['field_imp_begin_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['alter']['text'] = ', [field_imp_begin_date]';
  $handler->display->display_options['fields']['field_imp_begin_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Indexed Multilingual Content: Teacher */
  $handler->display->display_options['fields']['field_imp_teacher']['id'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_teacher']['field'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['label'] = '';
  $handler->display->display_options['fields']['field_imp_teacher']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_teacher']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_imp_teacher']['alter']['text'] = ', [field_imp_teacher]';
  $handler->display->display_options['fields']['field_imp_teacher']['element_label_colon'] = FALSE;
  /* Field: Description */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Description';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_imp_reference_to_courses_field_course_course_number][field_course_type_of_teaching][field_imp_method_of_study][field_imp_begin_date][field_imp_teacher]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['path'] = 'search/results/rss';
  $handler->display->display_options['displays'] = array(
    'desktop' => 'desktop',
    'default' => 0,
    'search_api_views_facets_block_1' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;

  /* Display: Feed (Library) */
  $handler = $view->new_display('feed', 'Feed (Library)', 'feed_2');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Course Search';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '100';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'rss';
  $handler->display->display_options['style_options']['description'] = 'Top 100 hits for given course search.';
  $handler->display->display_options['row_plugin'] = 'rss_fields';
  $handler->display->display_options['row_options']['title_field'] = 'title_field';
  $handler->display->display_options['row_options']['link_field'] = 'url';
  $handler->display->display_options['row_options']['description_field'] = 'nothing_1';
  $handler->display->display_options['row_options']['creator_field'] = 'nothing';
  $handler->display->display_options['row_options']['date_field'] = 'created';
  $handler->display->display_options['row_options']['guid_field_options'] = array(
    'guid_field' => 'url',
    'guid_field_is_permalink' => 1,
  );
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = '';
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '<a href="[field_imp_reference_to_courses_url]">[title_field]</a>';
  $handler->display->display_options['fields']['title_field']['alter']['path'] = '[url]';
  $handler->display->display_options['fields']['title_field']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title_field']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title_field']['type'] = 'text_plain';
  $handler->display->display_options['fields']['title_field']['settings'] = array(
    'trim_length' => '600',
  );
  /* Field: Indexed Multilingual Node: Date created (RFC 2822 format) */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['ui_name'] = 'Indexed Multilingual Node: Date created (RFC 2822 format)';
  $handler->display->display_options['fields']['created']['label'] = '';
  $handler->display->display_options['fields']['created']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['created']['date_format'] = 'custom';
  $handler->display->display_options['fields']['created']['custom_date_format'] = 'D, d M Y H:i:s O';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  $handler->display->display_options['fields']['created']['link_to_entity'] = 0;
  /* Field: Static creator text (Helsinki University) */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['ui_name'] = 'Static creator text (Helsinki University)';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = 'Helsinki University';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  /* Field: Reference to course(s): Course number (indexed) */
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['id'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['field'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['label'] = '';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['element_label_colon'] = FALSE;
  /* Field: Indexed Multilingual Content: Type of teaching */
  $handler->display->display_options['fields']['field_course_type_of_teaching']['id'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['field'] = 'field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['label'] = '';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['alter']['text'] = ', [field_course_type_of_teaching]';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_course_type_of_teaching']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_course_type_of_teaching']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['label'] = '';
  $handler->display->display_options['fields']['field_imp_method_of_study']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['alter']['text'] = ', [field_imp_method_of_study]';
  $handler->display->display_options['fields']['field_imp_method_of_study']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_method_of_study']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_imp_method_of_study']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_imp_method_of_study']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['label'] = '';
  $handler->display->display_options['fields']['field_imp_begin_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['alter']['text'] = ', [field_imp_begin_date]';
  $handler->display->display_options['fields']['field_imp_begin_date']['alter']['strip_tags'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Indexed Multilingual Content: Teacher */
  $handler->display->display_options['fields']['field_imp_teacher']['id'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_teacher']['field'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['label'] = '';
  $handler->display->display_options['fields']['field_imp_teacher']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_teacher']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_imp_teacher']['alter']['text'] = ', [field_imp_teacher]';
  $handler->display->display_options['fields']['field_imp_teacher']['element_label_colon'] = FALSE;
  /* Field: Description */
  $handler->display->display_options['fields']['nothing_1']['id'] = 'nothing_1';
  $handler->display->display_options['fields']['nothing_1']['table'] = 'views';
  $handler->display->display_options['fields']['nothing_1']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing_1']['ui_name'] = 'Description';
  $handler->display->display_options['fields']['nothing_1']['label'] = '';
  $handler->display->display_options['fields']['nothing_1']['alter']['text'] = '[field_imp_reference_to_courses_field_course_course_number][field_course_type_of_teaching][field_imp_method_of_study][field_imp_begin_date][field_imp_teacher]';
  $handler->display->display_options['fields']['nothing_1']['element_label_colon'] = FALSE;
  $handler->display->display_options['defaults']['sorts'] = FALSE;
  /* Sort criterion: Indexed Multilingual Content: Begin date */
  $handler->display->display_options['sorts']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['sorts']['field_imp_begin_date']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['sorts']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Indexed Multilingual Content: Academic year */
  $handler->display->display_options['filters']['academic_year']['id'] = 'academic_year';
  $handler->display->display_options['filters']['academic_year']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['academic_year']['field'] = 'academic_year';
  $handler->display->display_options['filters']['academic_year']['group'] = 1;
  $handler->display->display_options['filters']['academic_year']['exposed'] = TRUE;
  $handler->display->display_options['filters']['academic_year']['expose']['operator_id'] = 'academic_year_op';
  $handler->display->display_options['filters']['academic_year']['expose']['label'] = 'Academic year';
  $handler->display->display_options['filters']['academic_year']['expose']['operator'] = 'academic_year_op';
  $handler->display->display_options['filters']['academic_year']['expose']['identifier'] = 'academic_year';
  $handler->display->display_options['filters']['academic_year']['expose']['required'] = TRUE;
  $handler->display->display_options['filters']['academic_year']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  $handler->display->display_options['filters']['academic_year']['group_info']['label'] = 'Academic year';
  $handler->display->display_options['filters']['academic_year']['group_info']['identifier'] = 'academic_year';
  $handler->display->display_options['filters']['academic_year']['group_info']['remember'] = FALSE;
  $handler->display->display_options['filters']['academic_year']['group_info']['group_items'] = array(
    1 => array(),
    2 => array(),
    3 => array(),
  );
  /* Filter criterion: Indexed Multilingual Content: Combined fulltext */
  $handler->display->display_options['filters']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['group'] = 1;
  $handler->display->display_options['filters']['search_api_aggregation_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator_id'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['label'] = 'Search';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['description'] = 'If you want to see all the courses, leave the search field empty.';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['identifier'] = 'search';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Indexed Multilingual Content: Hierarchy position */
  $handler->display->display_options['filters']['field_hierarchy_position']['id'] = 'field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['field_hierarchy_position']['field'] = 'field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position']['value'] = 'studygroup';
  $handler->display->display_options['filters']['field_hierarchy_position']['group'] = 1;
  $handler->display->display_options['path'] = 'search/results/rss/library';
  $handler->display->display_options['displays'] = array(
    'default' => 0,
    'desktop' => 0,
    'search_api_views_facets_block_1' => 0,
  );
  $handler->display->display_options['sitename_title'] = 0;
  $translatables['uhc_portal_search_front_page_'] = array(
    t('Master'),
    t('more'),
    t('Show results'),
    t('Clear selections  x'),
    t('Sorting:'),
    t('Asc'),
    t('Desc'),
    t('Items per page'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('<h2>Results (@total)</h2>'),
    t('Organisation'),
    t('Method of study'),
    t('Start month'),
    t('Teaching language'),
    t('Type of teaching'),
    t('No results'),
    t('ID'),
    t('Name'),
    t('<a href="[field_imp_reference_to_courses_url]">[title_field]</a>'),
    t('Location'),
    t('Begin date'),
    t('Academic year'),
    t('Search'),
    t('If you want to see all the courses, leave the search field empty.'),
    t('Desktop'),
    t('Table'),
    t('<h2>Results (max 100)</h2>'),
    t('Teacher(s)'),
    t('Favorites'),
    t('Facets block'),
    t('Front page search facets'),
    t('Feed'),
    t('Course Search'),
    t('Helsinki University'),
    t(', [field_course_type_of_teaching]'),
    t(', [field_imp_method_of_study]'),
    t(', [field_imp_begin_date]'),
    t(', [field_imp_teacher]'),
    t('[field_imp_reference_to_courses_field_course_course_number][field_course_type_of_teaching][field_imp_method_of_study][field_imp_begin_date][field_imp_teacher]'),
    t('Feed (Library)'),
  );
  $export['uhc_portal_search_front_page_'] = $view;

  return $export;
}
