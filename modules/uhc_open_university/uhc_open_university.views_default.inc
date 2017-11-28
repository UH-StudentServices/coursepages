<?php
/**
 * @file
 * uhc_open_university.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_open_university_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uhc_search_open_university';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'search_api_index_uhc_portal';
  $view->human_name = 'UHC search (open university)';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'course-search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['link_display'] = 'desktop';
  $handler->display->display_options['access']['type'] = 'none';
  $handler->display->display_options['cache']['type'] = 'search_api_views_cache';
  $handler->display->display_options['cache']['results_lifespan'] = '300';
  $handler->display->display_options['cache']['results_lifespan_custom'] = '0';
  $handler->display->display_options['cache']['output_lifespan'] = '300';
  $handler->display->display_options['cache']['output_lifespan_custom'] = '0';
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
      'sortable' => 0,
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
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_begin_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_3']['id'] = 'block_3';
  $handler->display->display_options['header']['block_3']['table'] = 'views';
  $handler->display->display_options['header']['block_3']['field'] = 'block';
  $handler->display->display_options['header']['block_3']['label'] = 'Topic';
  $handler->display->display_options['header']['block_3']['block_to_insert'] = 'facetapi:hJ4IV71A4mz2cwcDDKqg90v7Q1luMlbX';
  $handler->display->display_options['header']['block_3']['title'] = 'Topic';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_8']['id'] = 'block_8';
  $handler->display->display_options['header']['block_8']['table'] = 'views';
  $handler->display->display_options['header']['block_8']['field'] = 'block';
  $handler->display->display_options['header']['block_8']['label'] = 'Degree programme';
  $handler->display->display_options['header']['block_8']['block_to_insert'] = 'facetapi:Dh4O3zt1eZPs8x4ZWjslzbxniYwSMXme';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_1']['id'] = 'block_1';
  $handler->display->display_options['header']['block_1']['table'] = 'views';
  $handler->display->display_options['header']['block_1']['field'] = 'block';
  $handler->display->display_options['header']['block_1']['label'] = 'Faculty';
  $handler->display->display_options['header']['block_1']['block_to_insert'] = 'facetapi:R1BRVcBSjxhf1KDt3dthdTfNu1qhp5en';
  $handler->display->display_options['header']['block_1']['title'] = 'Faculty';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_7']['id'] = 'block_7';
  $handler->display->display_options['header']['block_7']['table'] = 'views';
  $handler->display->display_options['header']['block_7']['field'] = 'block';
  $handler->display->display_options['header']['block_7']['label'] = 'Type of teaching';
  $handler->display->display_options['header']['block_7']['block_to_insert'] = 'facetapi:ebLMT1Egl05afck7AKCq6EMM2B4VuGer';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_4']['id'] = 'block_4';
  $handler->display->display_options['header']['block_4']['table'] = 'views';
  $handler->display->display_options['header']['block_4']['field'] = 'block';
  $handler->display->display_options['header']['block_4']['label'] = 'Start month';
  $handler->display->display_options['header']['block_4']['block_to_insert'] = 'facetapi:cEQesYoZJTu7ITT2OD5RXHP0T0bqniOh';
  $handler->display->display_options['header']['block_4']['title'] = 'Start month';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_2']['id'] = 'block_2';
  $handler->display->display_options['header']['block_2']['table'] = 'views';
  $handler->display->display_options['header']['block_2']['field'] = 'block';
  $handler->display->display_options['header']['block_2']['label'] = 'Method of study';
  $handler->display->display_options['header']['block_2']['empty'] = TRUE;
  $handler->display->display_options['header']['block_2']['block_to_insert'] = 'facetapi:do4BdKvyCgpZP4td6B6GmQ8iCUJ40HBx';
  $handler->display->display_options['header']['block_2']['title'] = 'Method of study';
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block']['id'] = 'block';
  $handler->display->display_options['header']['block']['table'] = 'views';
  $handler->display->display_options['header']['block']['field'] = 'block';
  $handler->display->display_options['header']['block']['label'] = 'Location';
  $handler->display->display_options['header']['block']['block_to_insert'] = 'facetapi:u1d1Lx0rPaqN5rZzf9O8SX4IxIGxkUQG';
  $handler->display->display_options['header']['block']['title'] = 'Location';
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
  /* Header: Global: Block area */
  $handler->display->display_options['header']['block_6']['id'] = 'block_6';
  $handler->display->display_options['header']['block_6']['table'] = 'views';
  $handler->display->display_options['header']['block_6']['field'] = 'block';
  /* No results behavior: Global: Text area */
  $handler->display->display_options['empty']['area']['id'] = 'area';
  $handler->display->display_options['empty']['area']['table'] = 'views';
  $handler->display->display_options['empty']['area']['field'] = 'area';
  $handler->display->display_options['empty']['area']['empty'] = TRUE;
  $handler->display->display_options['empty']['area']['content'] = 'No results';
  $handler->display->display_options['empty']['area']['format'] = 'plain_text';
  /* Field: Indexed Multilingual Content: Cancelled */
  $handler->display->display_options['fields']['field_cancelled']['id'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_cancelled']['field'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['label'] = '';
  $handler->display->display_options['fields']['field_cancelled']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cancelled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cancelled']['type'] = 'cancelled';
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
  $handler->display->display_options['fields']['title_field']['alter']['prefix'] = '[field_cancelled]';
  /* Field: Indexed Multilingual Content: Credit */
  $handler->display->display_options['fields']['field_study_credit']['id'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_study_credit']['field'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['label'] = 'Cr';
  $handler->display->display_options['fields']['field_study_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_study_credit']['alter']['text'] = '[field_study_credit-value]  <span class="show-only-in-mobile">Cr</span>';
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
  /* Field: Content: Favorite widget */
  $handler->display->display_options['fields']['favorite_widget']['id'] = 'favorite_widget';
  $handler->display->display_options['fields']['favorite_widget']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['favorite_widget']['field'] = 'favorite_widget';
  $handler->display->display_options['fields']['favorite_widget']['label'] = '';
  $handler->display->display_options['fields']['favorite_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['favorite_widget']['link_to_entity'] = 0;
  /* Sort criterion: Search: Relevance */
  $handler->display->display_options['sorts']['search_api_relevance']['id'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['sorts']['search_api_relevance']['field'] = 'search_api_relevance';
  $handler->display->display_options['sorts']['search_api_relevance']['order'] = 'DESC';
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
  /* Filter criterion: Indexed Multilingual Content: End date */
  $handler->display->display_options['filters']['field_imp_end_date']['id'] = 'field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['field_imp_end_date']['field'] = 'field_imp_end_date';
  $handler->display->display_options['filters']['field_imp_end_date']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_end_date']['value'] = 'today';
  $handler->display->display_options['filters']['field_imp_end_date']['group'] = 1;
  /* Filter criterion: Indexed Multilingual Content: Begin date */
  $handler->display->display_options['filters']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['filters']['field_imp_begin_date']['operator'] = '>=';
  $handler->display->display_options['filters']['field_imp_begin_date']['value'] = 'now -1 day';
  $handler->display->display_options['filters']['field_imp_begin_date']['group'] = 1;
  /* Filter criterion: Organisation: Code (indexed) */
  $handler->display->display_options['filters']['field_imp_organisation_field_ouh_code']['id'] = 'field_imp_organisation_field_ouh_code';
  $handler->display->display_options['filters']['field_imp_organisation_field_ouh_code']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['field_imp_organisation_field_ouh_code']['field'] = 'field_imp_organisation_field_ouh_code';
  $handler->display->display_options['filters']['field_imp_organisation_field_ouh_code']['value'] = 'H930';
  /* Filter criterion: Indexed Multilingual Content: Hierarchy position */
  $handler->display->display_options['filters']['field_hierarchy_position']['id'] = 'field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['filters']['field_hierarchy_position']['field'] = 'field_hierarchy_position';
  $handler->display->display_options['filters']['field_hierarchy_position']['value'] = 'root';

  /* Display: Desktop */
  $handler = $view->new_display('page', 'Desktop', 'desktop');
  $handler->display->display_options['display_description'] = 'Table';
  $handler->display->display_options['defaults']['style_plugin'] = FALSE;
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'field_cancelled' => 'field_cancelled',
    'url' => 'url',
    'title_field' => 'title_field',
    'field_study_credit' => 'field_study_credit',
    'field_imp_method_of_study' => 'field_imp_method_of_study',
    'field_imp_locality' => 'field_imp_locality',
    'field_imp_begin_date' => 'field_imp_begin_date',
    'favorite_widget' => 'favorite_widget',
    'field_imp_flexible_start' => 'title_field',
  );
  $handler->display->display_options['style_options']['default'] = 'title_field';
  $handler->display->display_options['style_options']['info'] = array(
    'field_cancelled' => array(
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
      'sortable' => 0,
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
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_begin_date' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'favorite_widget' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'field_imp_flexible_start' => array(
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  $handler->display->display_options['style_options']['override'] = FALSE;
  $handler->display->display_options['defaults']['style_options'] = FALSE;
  $handler->display->display_options['defaults']['row_plugin'] = FALSE;
  $handler->display->display_options['defaults']['row_options'] = FALSE;
  $handler->display->display_options['exposed_block'] = TRUE;
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Indexed Multilingual Content: Cancelled */
  $handler->display->display_options['fields']['field_cancelled']['id'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_cancelled']['field'] = 'field_cancelled';
  $handler->display->display_options['fields']['field_cancelled']['label'] = '';
  $handler->display->display_options['fields']['field_cancelled']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_cancelled']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_cancelled']['type'] = 'cancelled';
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
  $handler->display->display_options['fields']['title_field']['alter']['prefix'] = '[field_cancelled]';
  /* Field: Indexed Multilingual Content: Credit */
  $handler->display->display_options['fields']['field_study_credit']['id'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_study_credit']['field'] = 'field_study_credit';
  $handler->display->display_options['fields']['field_study_credit']['label'] = 'Cr';
  $handler->display->display_options['fields']['field_study_credit']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['field_study_credit']['alter']['text'] = '[field_study_credit-value]  <span class="show-only-in-mobile">Cr</span>';
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
  /* Field: Content: Favorite widget */
  $handler->display->display_options['fields']['favorite_widget']['id'] = 'favorite_widget';
  $handler->display->display_options['fields']['favorite_widget']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['favorite_widget']['field'] = 'favorite_widget';
  $handler->display->display_options['fields']['favorite_widget']['label'] = 'Favorites';
  $handler->display->display_options['fields']['favorite_widget']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['favorite_widget']['link_to_entity'] = 0;
  /* Field: Indexed Multilingual Content: Flexible start */
  $handler->display->display_options['fields']['field_imp_flexible_start']['id'] = 'field_imp_flexible_start';
  $handler->display->display_options['fields']['field_imp_flexible_start']['table'] = 'search_api_index_uhc_portal';
  $handler->display->display_options['fields']['field_imp_flexible_start']['field'] = 'field_imp_flexible_start';
  $handler->display->display_options['fields']['field_imp_flexible_start']['type'] = 'flexible_start';
  $handler->display->display_options['fields']['field_imp_flexible_start']['settings'] = array(
    'format_type' => 'long',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
    'show_remaining_days' => 0,
  );
  $handler->display->display_options['path'] = 'open-university/search';

  /* Display: Facets block */
  $handler = $view->new_display('search_api_views_facets_block', 'Facets block', 'search_api_views_facets_block_1');
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['block_description'] = 'Open university search facets';
  $handler->display->display_options['linked_path'] = 'open-university/search';
  $handler->display->display_options['facet_field'] = 'nid';
  $handler->display->display_options['hide_block'] = 1;
  $translatables['uhc_search_open_university'] = array(
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
    t('Topic'),
    t('Degree programme'),
    t('Faculty'),
    t('Type of teaching'),
    t('Start month'),
    t('Method of study'),
    t('Location'),
    t('Teaching language'),
    t('<h2>Results (@total)</h2>'),
    t('No results'),
    t('Name'),
    t('<a href="[field_imp_reference_to_courses_url]">[title_field]</a>'),
    t('[field_cancelled]'),
    t('Cr'),
    t('[field_study_credit-value]  <span class="show-only-in-mobile">Cr</span>'),
    t('Begin date'),
    t('Search'),
    t('If you want to see all the courses, leave the search field empty.'),
    t('Desktop'),
    t('Table'),
    t('Favorites'),
    t('Flexible start'),
    t('Facets block'),
    t('Open university search facets'),
  );
  $export['uhc_search_open_university'] = $view;

  return $export;
}
