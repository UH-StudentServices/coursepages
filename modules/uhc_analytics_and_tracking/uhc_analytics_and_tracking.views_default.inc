<?php
/**
 * @file
 * uhc_analytics_and_tracking.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_analytics_and_tracking_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uhc_google_analytics_reports_page';
  $view->description = 'Display statistic information about website pages from Google Analytics.';
  $view->tag = 'Google Analytics Reports';
  $view->base_table = 'google_analytics';
  $view->human_name = 'UHC Google Analytics Reports Page';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Google Analytics Reports Page';
  $handler->display->display_options['css_class'] = 'google-analytics-reports-pages course-search';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access google analytics reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'table';
  $handler->display->display_options['style_options']['columns'] = array(
    'pageviews' => 'pageviews',
    'uniquePageviews' => 'uniquePageviews',
    'avgTimeOnPage' => 'avgTimeOnPage',
  );
  $handler->display->display_options['style_options']['default'] = '-1';
  $handler->display->display_options['style_options']['info'] = array(
    'pageviews' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'uniquePageviews' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
    'avgTimeOnPage' => array(
      'sortable' => 0,
      'default_sort_order' => 'asc',
      'align' => '',
      'separator' => '',
      'empty_column' => 0,
    ),
  );
  /* Field: Page tracking calculated metrics: Avg. Time on Page */
  $handler->display->display_options['fields']['avgTimeOnPage']['id'] = 'avgTimeOnPage';
  $handler->display->display_options['fields']['avgTimeOnPage']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['avgTimeOnPage']['field'] = 'avgTimeOnPage';
  $handler->display->display_options['fields']['avgTimeOnPage']['date_format'] = 'long';
  $handler->display->display_options['fields']['avgTimeOnPage']['second_date_format'] = 'long';
  /* Contextual filter: Page tracking dimensions: Page */
  $handler->display->display_options['arguments']['pagePath']['id'] = 'pagePath';
  $handler->display->display_options['arguments']['pagePath']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['pagePath']['field'] = 'pagePath';
  $handler->display->display_options['arguments']['pagePath']['default_action'] = 'default';
  $handler->display->display_options['arguments']['pagePath']['title_enable'] = TRUE;
  $handler->display->display_options['arguments']['pagePath']['title'] = 'Google Analytics details for "%1" page';
  $handler->display->display_options['arguments']['pagePath']['default_argument_type'] = 'fixed';
  $handler->display->display_options['arguments']['pagePath']['default_argument_options']['argument'] = '/';
  $handler->display->display_options['arguments']['pagePath']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['pagePath']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['pagePath']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Google Analytics: Start date of report */
  $handler->display->display_options['filters']['start_date']['id'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['start_date']['field'] = 'start_date';
  $handler->display->display_options['filters']['start_date']['value']['value'] = '-8 day';
  $handler->display->display_options['filters']['start_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['start_date']['group'] = 1;
  /* Filter criterion: Google Analytics: End date of report */
  $handler->display->display_options['filters']['end_date']['id'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['table'] = 'google_analytics';
  $handler->display->display_options['filters']['end_date']['field'] = 'end_date';
  $handler->display->display_options['filters']['end_date']['value']['value'] = '-1 day';
  $handler->display->display_options['filters']['end_date']['value']['type'] = 'offset';
  $handler->display->display_options['filters']['end_date']['group'] = 1;

  /* Display: Block: Page tracking metrics */
  $handler = $view->new_display('block', 'Block: Page tracking metrics', 'block');
  $handler->display->display_options['defaults']['title'] = FALSE;
  $handler->display->display_options['title'] = 'Page traffic over the past 7 days';
  $handler->display->display_options['defaults']['use_more'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['defaults']['use_more_always'] = FALSE;
  $handler->display->display_options['use_more_always'] = TRUE;
  $handler->display->display_options['defaults']['use_more_text'] = FALSE;
  $handler->display->display_options['use_more_text'] = 'Full report for this page';
  $handler->display->display_options['defaults']['link_display'] = FALSE;
  $handler->display->display_options['link_display'] = 'custom_url';
  $handler->display->display_options['link_url'] = 'admin/reports/google-analytics-reports/page!1';
  $handler->display->display_options['defaults']['empty'] = FALSE;
  /* No results behavior: Global: Unfiltered text */
  $handler->display->display_options['empty']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['empty']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['empty']['area_text_custom']['label'] = 'Page doesn\'t have any statistics.';
  $handler->display->display_options['empty']['area_text_custom']['empty'] = TRUE;
  $handler->display->display_options['empty']['area_text_custom']['content'] = 'Page doesn\'t have any statistics.';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Page tracking metrics: Pageviews */
  $handler->display->display_options['fields']['pageviews']['id'] = 'pageviews';
  $handler->display->display_options['fields']['pageviews']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['pageviews']['field'] = 'pageviews';
  $handler->display->display_options['fields']['pageviews']['precision'] = '0';
  $handler->display->display_options['fields']['pageviews']['separator'] = '';
  /* Field: Page tracking metrics: Unique Pageviews */
  $handler->display->display_options['fields']['uniquePageviews']['id'] = 'uniquePageviews';
  $handler->display->display_options['fields']['uniquePageviews']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['uniquePageviews']['field'] = 'uniquePageviews';
  $handler->display->display_options['fields']['uniquePageviews']['label'] = 'Unique pageviews';
  $handler->display->display_options['fields']['uniquePageviews']['precision'] = '0';
  $handler->display->display_options['fields']['uniquePageviews']['separator'] = '';
  /* Field: Page tracking calculated metrics: Avg. Time on Page */
  $handler->display->display_options['fields']['avgTimeOnPage']['id'] = 'avgTimeOnPage';
  $handler->display->display_options['fields']['avgTimeOnPage']['table'] = 'google_analytics';
  $handler->display->display_options['fields']['avgTimeOnPage']['field'] = 'avgTimeOnPage';
  $handler->display->display_options['fields']['avgTimeOnPage']['label'] = 'Average time on page';
  $handler->display->display_options['fields']['avgTimeOnPage']['date_format'] = 'custom';
  $handler->display->display_options['fields']['avgTimeOnPage']['custom_date_format'] = 'i:s';
  $handler->display->display_options['fields']['avgTimeOnPage']['second_date_format'] = 'long';
  $handler->display->display_options['defaults']['arguments'] = FALSE;
  /* Contextual filter: Page tracking dimensions: Page */
  $handler->display->display_options['arguments']['pagePath']['id'] = 'pagePath';
  $handler->display->display_options['arguments']['pagePath']['table'] = 'google_analytics';
  $handler->display->display_options['arguments']['pagePath']['field'] = 'pagePath';
  $handler->display->display_options['arguments']['pagePath']['default_action'] = 'default';
  $handler->display->display_options['arguments']['pagePath']['default_argument_type'] = 'uhc_google_analytics_reports_path';
  $handler->display->display_options['arguments']['pagePath']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['pagePath']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['pagePath']['summary_options']['items_per_page'] = '25';
  $handler->display->display_options['block_description'] = 'UHC Google Analytics Reports Page Block';
  $translatables['uhc_google_analytics_reports_page'] = array(
    t('Master'),
    t('Google Analytics Reports Page'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Avg. Time on Page'),
    t('All'),
    t('Google Analytics details for "%1" page'),
    t('Block: Page tracking metrics'),
    t('Page traffic over the past 7 days'),
    t('Full report for this page'),
    t('Page doesn\'t have any statistics.'),
    t('Pageviews'),
    t('.'),
    t('Unique pageviews'),
    t('Average time on page'),
    t('UHC Google Analytics Reports Page Block'),
  );
  $export['uhc_google_analytics_reports_page'] = $view;

  return $export;
}
