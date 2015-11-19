<?php
/**
 * @file
 * uhc_course_implementation.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_course_implementation_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'course_implementation_material';
  $view->description = '';
  $view->tag = 'default';
  $view->base_table = 'node';
  $view->human_name = 'Course implementation material';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'accordion-content-item course-material';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'none';
  $handler->display->display_options['style_plugin'] = 'list';
  $handler->display->display_options['style_options']['grouping'] = array(
    0 => array(
      'field' => 'field_material_section',
      'rendered' => 1,
      'rendered_strip' => 0,
    ),
  );
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['style_options']['uses_fields'] = TRUE;
  $handler->display->display_options['row_plugin'] = 'node';
  $handler->display->display_options['row_options']['relationship'] = 'field_section_material_target_id';
  $handler->display->display_options['row_options']['links'] = FALSE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_section_material_target_id']['id'] = 'field_section_material_target_id';
  $handler->display->display_options['relationships']['field_section_material_target_id']['table'] = 'field_data_field_section_material';
  $handler->display->display_options['relationships']['field_section_material_target_id']['field'] = 'field_section_material_target_id';
  $handler->display->display_options['relationships']['field_section_material_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_material_section_target_id']['id'] = 'field_material_section_target_id';
  $handler->display->display_options['relationships']['field_material_section_target_id']['table'] = 'field_data_field_material_section';
  $handler->display->display_options['relationships']['field_material_section_target_id']['field'] = 'field_material_section_target_id';
  $handler->display->display_options['relationships']['field_material_section_target_id']['relationship'] = 'field_section_material_target_id';
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  /* Field: Content: Material section */
  $handler->display->display_options['fields']['field_material_section']['id'] = 'field_material_section';
  $handler->display->display_options['fields']['field_material_section']['table'] = 'field_data_field_material_section';
  $handler->display->display_options['fields']['field_material_section']['field'] = 'field_material_section';
  $handler->display->display_options['fields']['field_material_section']['relationship'] = 'field_section_material_target_id';
  $handler->display->display_options['fields']['field_material_section']['label'] = '';
  $handler->display->display_options['fields']['field_material_section']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_material_section']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_material_section']['settings'] = array(
    'link' => 0,
  );
  /* Sort criterion: Taxonomy term: Name */
  $handler->display->display_options['sorts']['name']['id'] = 'name';
  $handler->display->display_options['sorts']['name']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['name']['field'] = 'name';
  $handler->display->display_options['sorts']['name']['relationship'] = 'field_material_section_target_id';
  $handler->display->display_options['sorts']['name']['order'] = 'DESC';
  /* Sort criterion: Taxonomy term: Weight */
  $handler->display->display_options['sorts']['weight']['id'] = 'weight';
  $handler->display->display_options['sorts']['weight']['table'] = 'taxonomy_term_data';
  $handler->display->display_options['sorts']['weight']['field'] = 'weight';
  $handler->display->display_options['sorts']['weight']['relationship'] = 'field_material_section_target_id';
  /* Sort criterion: Content: Material section (field_material_section) */
  $handler->display->display_options['sorts']['field_material_section_target_id']['id'] = 'field_material_section_target_id';
  $handler->display->display_options['sorts']['field_material_section_target_id']['table'] = 'field_data_field_material_section';
  $handler->display->display_options['sorts']['field_material_section_target_id']['field'] = 'field_material_section_target_id';
  $handler->display->display_options['sorts']['field_material_section_target_id']['relationship'] = 'field_section_material_target_id';
  $handler->display->display_options['sorts']['field_material_section_target_id']['order'] = 'DESC';
  /* Sort criterion: Content: Section material (field_section_material:delta) */
  $handler->display->display_options['sorts']['delta']['id'] = 'delta';
  $handler->display->display_options['sorts']['delta']['table'] = 'field_data_field_section_material';
  $handler->display->display_options['sorts']['delta']['field'] = 'delta';
  /* Contextual filter: Content: Nid */
  $handler->display->display_options['arguments']['nid']['id'] = 'nid';
  $handler->display->display_options['arguments']['nid']['table'] = 'node';
  $handler->display->display_options['arguments']['nid']['field'] = 'nid';
  $handler->display->display_options['arguments']['nid']['default_action'] = 'default';
  $handler->display->display_options['arguments']['nid']['default_argument_type'] = 'node';
  $handler->display->display_options['arguments']['nid']['summary']['number_of_records'] = '0';
  $handler->display->display_options['arguments']['nid']['summary']['format'] = 'default_summary';
  $handler->display->display_options['arguments']['nid']['summary_options']['items_per_page'] = '25';
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_implementation' => 'course_implementation',
  );

  /* Display: Block */
  $handler = $view->new_display('block', 'Block', 'block');
  $handler->display->display_options['defaults']['footer'] = FALSE;
  $handler->display->display_options['defaults']['filter_groups'] = FALSE;
  $handler->display->display_options['defaults']['filters'] = FALSE;
  /* Filter criterion: Content: Published */
  $handler->display->display_options['filters']['status']['id'] = 'status';
  $handler->display->display_options['filters']['status']['table'] = 'node';
  $handler->display->display_options['filters']['status']['field'] = 'status';
  $handler->display->display_options['filters']['status']['value'] = 1;
  $handler->display->display_options['filters']['status']['group'] = 1;
  $handler->display->display_options['filters']['status']['expose']['operator'] = FALSE;
  /* Filter criterion: Content: Type */
  $handler->display->display_options['filters']['type']['id'] = 'type';
  $handler->display->display_options['filters']['type']['table'] = 'node';
  $handler->display->display_options['filters']['type']['field'] = 'type';
  $handler->display->display_options['filters']['type']['value'] = array(
    'course_implementation' => 'course_implementation',
  );
  $translatables['course_implementation_material'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Content entity referenced from field_section_material'),
    t('Taxonomy term entity referenced from field_material_section'),
    t('All'),
    t('Block'),
  );
  $export['course_implementation_material'] = $view;

  return $export;
}
