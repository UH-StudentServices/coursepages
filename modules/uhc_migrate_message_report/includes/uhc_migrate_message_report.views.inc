<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_views_data().
 */
function uhc_migrate_message_report_views_data() {
  $data = array();
  $table_name = _uhc_migrate_message_report_get_table_name();
  if (empty($table_name)) {
    return array();
  }
  $data[$table_name]['table']['group'] = t('Migrations');
  $data[$table_name]['table']['base'] = array(
    'field' => 'msgid',
    'title' => t('Migrate messages for course implementations'),
    'help' => t('Contains migration messages of course implementation import.'),
    'weight' => 0,
  );
  $data[$table_name]['msgid'] = array(
    'title' => t('Message ID'),
    'help' => t('ID of message.'),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data[$table_name]['created'] = array(
    'title' => t('Created'),
    'help' => t('Date and time when message was created.'),
    'filter' => array(
      'handler' => 'views_handler_filter_date',
    ),
    'field' => array(
      'handler' => 'views_handler_field_date',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort_date',
    ),
  );
  $data[$table_name]['sourceid1'] = array(
    'title' => t('Source ID'),
    'help' => t('Source ID. Usually same as course implementation ID.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  $data[$table_name]['level'] = array(
    'title' => t('Level (numeric)'),
    'help' => t('Level of the message in numeric format.'),
    'field' => array(
      'handler' => 'views_handler_field_numeric',
      'click sortable' => TRUE,
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_numeric',
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
  );
  $data[$table_name]['message'] = array(
    'title' => t('Message'),
    'help' => t('Message contents.'),
    'field' => array(
      'handler' => 'views_handler_field',
      'click sortable' => TRUE,
    ),
    'sort' => array(
      'handler' => 'views_handler_sort',
    ),
    'filter' => array(
      'handler' => 'views_handler_filter_string',
    ),
    'argument' => array(
      'handler' => 'views_handler_argument_string',
    ),
  );
  return $data;
}

function uhc_migrate_message_report_views_default_views() {
  $view = new view();
  $view->name = 'migrate_messages';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'migrate_message_courseimplementationnode';
  $view->human_name = 'Migrate Messages';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */
  
  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Migrate Messages';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['access']['perm'] = 'access site reports';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['exposed_form']['options']['submit_button'] = 'Search';
  $handler->display->display_options['pager']['type'] = 'full';
  $handler->display->display_options['pager']['options']['items_per_page'] = '50';
  $handler->display->display_options['style_plugin'] = 'table';
  /* Field: Migrations: Message ID */
  $handler->display->display_options['fields']['msgid']['id'] = 'msgid';
  $handler->display->display_options['fields']['msgid']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['fields']['msgid']['field'] = 'msgid';
  /* Field: Migrations: Created */
  $handler->display->display_options['fields']['created']['id'] = 'created';
  $handler->display->display_options['fields']['created']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['fields']['created']['field'] = 'created';
  $handler->display->display_options['fields']['created']['date_format'] = 'short';
  $handler->display->display_options['fields']['created']['second_date_format'] = 'search_api_facetapi_YEAR';
  /* Field: Migrations: Source ID */
  $handler->display->display_options['fields']['sourceid1']['id'] = 'sourceid1';
  $handler->display->display_options['fields']['sourceid1']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['fields']['sourceid1']['field'] = 'sourceid1';
  /* Field: Migrations: Message */
  $handler->display->display_options['fields']['message']['id'] = 'message';
  $handler->display->display_options['fields']['message']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['fields']['message']['field'] = 'message';
  $handler->display->display_options['fields']['message']['alter']['alter_text'] = TRUE;
  $handler->display->display_options['fields']['message']['alter']['text'] = '<small><pre>[message]</pre></small>';
  /* Sort criterion: Migrations: Message ID */
  $handler->display->display_options['sorts']['msgid']['id'] = 'msgid';
  $handler->display->display_options['sorts']['msgid']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['sorts']['msgid']['field'] = 'msgid';
  $handler->display->display_options['sorts']['msgid']['order'] = 'DESC';
  $handler->display->display_options['filter_groups']['groups'] = array(
    1 => 'OR',
  );
  /* Filter criterion: Migrations: Message ID */
  $handler->display->display_options['filters']['msgid']['id'] = 'msgid';
  $handler->display->display_options['filters']['msgid']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['filters']['msgid']['field'] = 'msgid';
  $handler->display->display_options['filters']['msgid']['group'] = 1;
  $handler->display->display_options['filters']['msgid']['exposed'] = TRUE;
  $handler->display->display_options['filters']['msgid']['expose']['operator_id'] = 'msgid_op';
  $handler->display->display_options['filters']['msgid']['expose']['label'] = 'Message ID';
  $handler->display->display_options['filters']['msgid']['expose']['operator'] = 'msgid_op';
  $handler->display->display_options['filters']['msgid']['expose']['identifier'] = 'msgid';
  $handler->display->display_options['filters']['msgid']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Migrations: Created */
  $handler->display->display_options['filters']['created']['id'] = 'created';
  $handler->display->display_options['filters']['created']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['filters']['created']['field'] = 'created';
  $handler->display->display_options['filters']['created']['group'] = 1;
  $handler->display->display_options['filters']['created']['exposed'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator_id'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['label'] = 'Created';
  $handler->display->display_options['filters']['created']['expose']['description'] = 'For example 2018-01-08';
  $handler->display->display_options['filters']['created']['expose']['use_operator'] = TRUE;
  $handler->display->display_options['filters']['created']['expose']['operator'] = 'created_op';
  $handler->display->display_options['filters']['created']['expose']['identifier'] = 'created';
  $handler->display->display_options['filters']['created']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Migrations: Source ID */
  $handler->display->display_options['filters']['sourceid1']['id'] = 'sourceid1';
  $handler->display->display_options['filters']['sourceid1']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['filters']['sourceid1']['field'] = 'sourceid1';
  $handler->display->display_options['filters']['sourceid1']['operator'] = 'contains';
  $handler->display->display_options['filters']['sourceid1']['group'] = 1;
  $handler->display->display_options['filters']['sourceid1']['exposed'] = TRUE;
  $handler->display->display_options['filters']['sourceid1']['expose']['operator_id'] = 'sourceid1_op';
  $handler->display->display_options['filters']['sourceid1']['expose']['label'] = 'Source ID';
  $handler->display->display_options['filters']['sourceid1']['expose']['description'] = 'Search by course implementation ID.';
  $handler->display->display_options['filters']['sourceid1']['expose']['operator'] = 'sourceid1_op';
  $handler->display->display_options['filters']['sourceid1']['expose']['identifier'] = 'sourceid1';
  $handler->display->display_options['filters']['sourceid1']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  /* Filter criterion: Migrations: Message */
  $handler->display->display_options['filters']['message']['id'] = 'message';
  $handler->display->display_options['filters']['message']['table'] = 'migrate_message_courseimplementationnode';
  $handler->display->display_options['filters']['message']['field'] = 'message';
  $handler->display->display_options['filters']['message']['operator'] = 'contains';
  $handler->display->display_options['filters']['message']['group'] = 1;
  $handler->display->display_options['filters']['message']['exposed'] = TRUE;
  $handler->display->display_options['filters']['message']['expose']['operator_id'] = 'message_op';
  $handler->display->display_options['filters']['message']['expose']['label'] = 'Message';
  $handler->display->display_options['filters']['message']['expose']['operator'] = 'message_op';
  $handler->display->display_options['filters']['message']['expose']['identifier'] = 'message';
  $handler->display->display_options['filters']['message']['expose']['remember_roles'] = array(
    2 => '2',
    1 => 0,
    3 => 0,
    4 => 0,
    5 => 0,
    6 => 0,
    7 => 0,
    8 => 0,
  );
  
  /* Display: Page */
  $handler = $view->new_display('page', 'Page', 'page');
  $handler->display->display_options['path'] = 'admin/reports/migrate-messages';
  $handler->display->display_options['menu']['type'] = 'normal';
  $handler->display->display_options['menu']['title'] = 'Migrate messages';
  $handler->display->display_options['menu']['description'] = 'List of migration messages of course implementation imports.';
  $handler->display->display_options['menu']['weight'] = '0';
  $handler->display->display_options['menu']['name'] = 'management';
  $handler->display->display_options['menu']['context'] = 0;
  $handler->display->display_options['menu']['context_only_inline'] = 0;
  $translatables['migrate_messages'] = array(
    t('Master'),
    t('Migrate Messages'),
    t('more'),
    t('Search'),
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
    t('Message ID'),
    t('Created'),
    t('Source ID'),
    t('Message'),
    t('<small><pre>[message]</pre></small>'),
    t('For example 2018-01-08'),
    t('Search by course implementation ID.'),
    t('Page'),
  );
  return array('migrate_messages' => $view);
}
