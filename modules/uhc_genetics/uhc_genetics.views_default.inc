<?php
/**
 * @file
 * uhc_genetics.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_genetics_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uhc_search';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_uhc_portal';
  $view->human_name = 'UHC search';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'course-search';
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
  $handler->display->display_options['pager']['options']['items_per_page'] = '10';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['pager']['options']['id'] = '0';
  $handler->display->display_options['pager']['options']['quantity'] = '9';
  $handler->display->display_options['pager']['options']['expose']['items_per_page'] = TRUE;
  $handler->display->display_options['pager']['options']['expose']['items_per_page_label'] = 'Show:';
  $handler->display->display_options['pager']['options']['expose']['items_per_page_options'] = '10, 20, 50, 100';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_imp_reference_to_courses_url' => 'field_imp_reference_to_courses_url',
    'field_imp_reference_to_courses_field_course_course_number' => 'field_imp_reference_to_courses_field_course_course_number',
    'url' => 'url',
    'title_field' => 'title_field',
    'field_imp_reference_to_courses_field_course_type_of_teaching' => 'field_imp_reference_to_courses_field_course_type_of_teaching',
    'field_imp_method_of_study' => 'field_imp_method_of_study',
    'field_imp_teacher' => 'field_imp_teacher',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'field_imp_reference_to_courses_url' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_reference_to_courses_field_course_course_number' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
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
    'field_imp_reference_to_courses_field_course_type_of_teaching' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_method_of_study' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_teacher' => array(
      'sortable' => 1,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block']['id'] = 'block';
  $handler->display->display_options['header']['block']['table'] = 'views';
  $handler->display->display_options['header']['block']['field'] = 'block';
  $handler->display->display_options['header']['block']['label'] = 'Theme';
  $handler->display->display_options['header']['block']['block_to_insert'] = 'facetapi:eahZtWygrbd0mW39GxTTrKpmT6NtmJd3';
  $handler->display->display_options['header']['block']['title'] = 'Theme';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_1']['id'] = 'block_1';
  $handler->display->display_options['header']['block_1']['table'] = 'views';
  $handler->display->display_options['header']['block_1']['field'] = 'block';
  $handler->display->display_options['header']['block_1']['label'] = 'Type of teaching';
  $handler->display->display_options['header']['block_1']['block_to_insert'] = 'facetapi:ebLMT1Egl05afck7AKCq6EMM2B4VuGer';
  $handler->display->display_options['header']['block_1']['title'] = 'Type of teaching';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_2']['id'] = 'block_2';
  $handler->display->display_options['header']['block_2']['table'] = 'views';
  $handler->display->display_options['header']['block_2']['field'] = 'block';
  $handler->display->display_options['header']['block_2']['label'] = 'Method of study';
  $handler->display->display_options['header']['block_2']['block_to_insert'] = 'facetapi:do4BdKvyCgpZP4td6B6GmQ8iCUJ40HBx';
  $handler->display->display_options['header']['block_2']['title'] = 'Method of study';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_3']['id'] = 'block_3';
  $handler->display->display_options['header']['block_3']['table'] = 'views';
  $handler->display->display_options['header']['block_3']['field'] = 'block';
  $handler->display->display_options['header']['block_3']['label'] = 'Start month';
  $handler->display->display_options['header']['block_3']['block_to_insert'] = 'facetapi:cEQesYoZJTu7ITT2OD5RXHP0T0bqniOh';
  $handler->display->display_options['header']['block_3']['title'] = 'Start month';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_5']['id'] = 'block_5';
  $handler->display->display_options['header']['block_5']['table'] = 'views';
  $handler->display->display_options['header']['block_5']['field'] = 'block';
  $handler->display->display_options['header']['block_5']['label'] = 'Teaching language';
  $handler->display->display_options['header']['block_5']['block_to_insert'] = 'facetapi:as918Au1kK03VaWu2iPYsRfNZ1iJWE7X';
  $handler->display->display_options['header']['block_5']['title'] = 'Teaching language';
  /* Header: Global: Result summary */
  $handler->display->display_options['header']['result']['id'] = 'result';
  $handler->display->display_options['header']['result']['table'] = 'views';
  $handler->display->display_options['header']['result']['field'] = 'result';
  $handler->display->display_options['header']['result']['content'] = '<h2>Results (@total)</h2>';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Reference to course(s): URL (indexed) */
  $handler->display->display_options['fields']['field_imp_reference_to_courses_url']['id'] = 'field_imp_reference_to_courses_url';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_url']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_url']['field'] = 'field_imp_reference_to_courses_url';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_url']['label'] = '';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_reference_to_courses_url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_reference_to_courses_url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['field_imp_reference_to_courses_url']['link_to_entity'] = 0;
  /* Field: Reference to course(s): Course number (indexed) */
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['id'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['field'] = 'field_imp_reference_to_courses_field_course_course_number';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['label'] = 'ID';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_course_number']['alter']['text'] = '<a href="[field_imp_reference_to_courses_url]">[field_imp_reference_to_courses_field_course_course_number]</a>';
  /* Field: Indexed Multilingual Node: URL */
  $handler->display->display_options['fields']['url']['id'] = 'url';
  $handler->display->display_options['fields']['url']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['url']['field'] = 'url';
  $handler->display->display_options['fields']['url']['label'] = '';
  $handler->display->display_options['fields']['url']['exclude'] = TRUE;
  $handler->display->display_options['fields']['url']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['url']['display_as_link'] = FALSE;
  $handler->display->display_options['fields']['url']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Node: Title */
  $handler->display->display_options['fields']['title_field']['id'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['title_field']['field'] = 'title_field';
  $handler->display->display_options['fields']['title_field']['label'] = 'Name';
  $handler->display->display_options['fields']['title_field']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['title_field']['alter']['text'] = '<a href="[url]">[title_field]</a>';
  /* Field: Reference to course(s): Type of teaching (indexed) */
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['id'] = 'field_imp_reference_to_courses_field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['field'] = 'field_imp_reference_to_courses_field_course_type_of_teaching';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['label'] = 'Type of teaching';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_imp_reference_to_courses_field_course_type_of_teaching']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: Method of study */
  $handler->display->display_options['fields']['field_imp_method_of_study']['id'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_method_of_study']['field'] = 'field_imp_method_of_study';
  $handler->display->display_options['fields']['field_imp_method_of_study']['link_to_entity'] = 0;
  $handler->display->display_options['fields']['field_imp_method_of_study']['view_mode'] = 'full';
  $handler->display->display_options['fields']['field_imp_method_of_study']['bypass_access'] = 0;
  /* Field: Indexed Multilingual Node: Begin date */
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
  /* Field: Indexed Multilingual Node: Teacher */
  $handler->display->display_options['fields']['field_imp_teacher']['id'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_teacher']['field'] = 'field_imp_teacher';
  $handler->display->display_options['fields']['field_imp_teacher']['label'] = 'Teacher(s)';
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
  /* Filter criterion: Indexed Multilingual Node: Academic year */
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
  /* Filter criterion: Indexed Multilingual Node: Combined fulltext */
  $handler->display->display_options['filters']['search_api_aggregation_1']['id'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['search_api_aggregation_1']['field'] = 'search_api_aggregation_1';
  $handler->display->display_options['filters']['search_api_aggregation_1']['group'] = 1;
  $handler->display->display_options['filters']['search_api_aggregation_1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['operator_id'] = 'search_api_aggregation_1_op';
  $handler->display->display_options['filters']['search_api_aggregation_1']['expose']['label'] = 'Search by keyword';
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
  /* Filter criterion: Indexed Multilingual Node: Item language */
  $handler->display->display_options['filters']['search_api_language']['id'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['search_api_language']['field'] = 'search_api_language';
  $handler->display->display_options['filters']['search_api_language']['value'] = array(
    'current' => 'current',
  );
  $handler->display->display_options['filters']['search_api_language']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Node: Keywords */
  $handler->display->display_options['filters']['field_imp_keywords']['id'] = 'field_imp_keywords';
  $handler->display->display_options['filters']['field_imp_keywords']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['field_imp_keywords']['field'] = 'field_imp_keywords';
  $handler->display->display_options['filters']['field_imp_keywords']['value'] = 'genetiikka';
  $handler->display->display_options['filters']['field_imp_keywords']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Node: Hierarchy position */
  $handler->display->display_options['filters']['field_hierarchy_position']['id'] = 'field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['field_hierarchy_position']['field'] = 'field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position']['value'] = 'root';
  $handler->display->display_options['filters']['field_hierarchy_position']['group'] = 1;

  /* Display: Desktop */
  $handler = $view->new_display('page', 'Desktop', 'desktop');
  $handler->display->display_options['display_description'] = 'Table';
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['path'] = 'genetics/search';

  /* Display: Facets block */
  $handler = $view->new_display('search_api_views_facets_block', 'Facets block', 'search_api_views_facets_block_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['block_description'] = 'Genetics search facets';
  $handler->display->display_options['linked_path'] = 'genetics/search';
  $handler->display->display_options['facet_field'] = 'nid';
  $handler->display->display_options['hide_block'] = 1;
  $translatables['uhc_search'] = array(
    t('Master'),
    t('more'),
    t('Show results'),
    t('Clear selections  x'),
    t('Sorting:'),
    t('Asc'),
    t('Desc'),
    t('Show:'),
    t('- All -'),
    t('Offset'),
    t('« first'),
    t('‹ previous'),
    t('next ›'),
    t('last »'),
    t('Theme'),
    t('Type of teaching'),
    t('Method of study'),
    t('Start month'),
    t('Teaching language'),
    t('<h2>Results (@total)</h2>'),
    t('No results'),
    t('ID'),
    t('<a href="[field_imp_reference_to_courses_url]">[field_imp_reference_to_courses_field_course_course_number]</a>'),
    t('Name'),
    t('<a href="[url]">[title_field]</a>'),
    t('Begin date'),
    t('Teacher(s)'),
    t('Academic year'),
    t('Search by keyword'),
    t('If you want to see all the courses, leave the search field empty.'),
    t('Desktop'),
    t('Table'),
    t('Facets block'),
    t('Genetics search facets'),
  );
  $export['uhc_search'] = $view;

  return $export;
}
