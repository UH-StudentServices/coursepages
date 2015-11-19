<?php
/**
 * @file
 * uhc_liftups.views_default.inc
 */

/**
 * Implements hook_views_default_views().
 */
function uhc_liftups_views_default_views() {
  $export = array();

  $view = new view();
  $view->name = 'uhc_course_liftups';
  $view->description = 'Lists three latest course liftups.';
  $view->tag = 'uhc_liftups';
  $view->base_table = 'node';
  $view->human_name = 'UHC Course liftups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['title'] = 'Highlights of upcoming courses';
  $handler->display->display_options['css_class'] = 'gridder-container-3 course-liftups';
  $handler->display->display_options['use_more_always'] = FALSE;
  $handler->display->display_options['access']['type'] = 'perm';
  $handler->display->display_options['cache']['type'] = 'none';
  $handler->display->display_options['query']['type'] = 'views_query';
  $handler->display->display_options['exposed_form']['type'] = 'basic';
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '3';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['style_plugin'] = 'default';
  $handler->display->display_options['style_options']['row_class'] = 'gridder-box';
  $handler->display->display_options['style_options']['default_row_class'] = FALSE;
  $handler->display->display_options['style_options']['row_class_special'] = FALSE;
  $handler->display->display_options['row_plugin'] = 'fields';
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_courseliftup_courseimp_target_id']['id'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['relationships']['field_courseliftup_courseimp_target_id']['table'] = 'field_data_field_courseliftup_courseimp';
  $handler->display->display_options['relationships']['field_courseliftup_courseimp_target_id']['field'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['relationships']['field_courseliftup_courseimp_target_id']['label'] = 'Course implementation';
  $handler->display->display_options['relationships']['field_courseliftup_courseimp_target_id']['required'] = TRUE;
  /* Relationship: Entity Reference: Referenced Entity */
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['id'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['table'] = 'field_data_field_imp_reference_to_courses';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['field'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['relationships']['field_imp_reference_to_courses_target_id']['label'] = 'Course';
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_courseliftup_image']['id'] = 'field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['table'] = 'field_data_field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['field'] = 'field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['label'] = '';
  $handler->display->display_options['fields']['field_courseliftup_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_courseliftup_image']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_image']['element_wrapper_class'] = 'box-story__image';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_courseliftup_image']['settings'] = array(
    'image_style' => 'liftup_322_x_190',
    'image_link' => '',
  );
  /* Field: Content: Theme */
  $handler->display->display_options['fields']['field_course_theme']['id'] = 'field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['table'] = 'field_data_field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['field'] = 'field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_theme']['label'] = '';
  $handler->display->display_options['fields']['field_course_theme']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_theme']['element_type'] = '0';
  $handler->display->display_options['fields']['field_course_theme']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_theme']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_course_theme']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_course_theme']['empty'] = 'Genetics';
  $handler->display->display_options['fields']['field_course_theme']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_course_theme']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_course_theme']['delta_offset'] = '0';
  /* Field: Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['field_imp_begin_date']['label'] = '';
  $handler->display->display_options['fields']['field_imp_begin_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_imp_begin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_imp_begin_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="box-story__date">[field_imp_begin_date]</span><span class="box-story__tag">[field_course_theme]</span>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'box-story__topical';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_imp_canonical_url]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'box-story__title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_courseliftup_descripion']['id'] = 'field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['table'] = 'field_data_field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['field'] = 'field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['label'] = '';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_class'] = 'box-story__content';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_descripion']['settings'] = array(
    'trim_length' => '120',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'more-link';
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'course_liftup' => 'course_liftup',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );

  /* Display: Latest genetics */
  $handler = $view->new_display('block', 'Latest genetics', 'latest');
  $handler->display->display_options['display_description'] = 'Three lifted courses';
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
    'course_liftup' => 'course_liftup',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );
  /* Filter criterion: Content: Liftup section (field_liftup_section) */
  $handler->display->display_options['filters']['field_liftup_section_value']['id'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['table'] = 'field_data_field_liftup_section';
  $handler->display->display_options['filters']['field_liftup_section_value']['field'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['value'] = array(
    'genetics' => 'genetics',
  );

  /* Display: Latest open university */
  $handler = $view->new_display('block', 'Latest open university', 'block_1');
  $handler->display->display_options['display_description'] = 'Three lifted courses';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_courseliftup_image']['id'] = 'field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['table'] = 'field_data_field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['field'] = 'field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['label'] = '';
  $handler->display->display_options['fields']['field_courseliftup_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_courseliftup_image']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_image']['element_wrapper_class'] = 'box-story__image';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_courseliftup_image']['settings'] = array(
    'image_style' => 'liftup_322_x_190',
    'image_link' => '',
  );
  /* Field: Content: Theme */
  $handler->display->display_options['fields']['field_course_theme']['id'] = 'field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['table'] = 'field_data_field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['field'] = 'field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_theme']['label'] = '';
  $handler->display->display_options['fields']['field_course_theme']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_theme']['element_type'] = '0';
  $handler->display->display_options['fields']['field_course_theme']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_theme']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_course_theme']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_course_theme']['empty'] = 'Open University';
  $handler->display->display_options['fields']['field_course_theme']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_course_theme']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_course_theme']['delta_offset'] = '0';
  /* Field: Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['field_imp_begin_date']['label'] = '';
  $handler->display->display_options['fields']['field_imp_begin_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_imp_begin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_imp_begin_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="box-story__date">[field_imp_begin_date]</span><span class="box-story__tag">[field_course_theme]</span>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'box-story__topical';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_imp_canonical_url]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'box-story__title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_courseliftup_descripion']['id'] = 'field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['table'] = 'field_data_field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['field'] = 'field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['label'] = '';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_class'] = 'box-story__content';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_descripion']['settings'] = array(
    'trim_length' => '120',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'more-link';
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
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
    'course_liftup' => 'course_liftup',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );
  /* Filter criterion: Content: Liftup section (field_liftup_section) */
  $handler->display->display_options['filters']['field_liftup_section_value']['id'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['table'] = 'field_data_field_liftup_section';
  $handler->display->display_options['filters']['field_liftup_section_value']['field'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['value'] = array(
    'openuniversity' => 'openuniversity',
  );

  /* Display: Latest biosciences */
  $handler = $view->new_display('block', 'Latest biosciences', 'block_2');
  $handler->display->display_options['display_description'] = 'Three lifted courses';
  $handler->display->display_options['defaults']['fields'] = FALSE;
  /* Field: Content: Path */
  $handler->display->display_options['fields']['path']['id'] = 'path';
  $handler->display->display_options['fields']['path']['table'] = 'node';
  $handler->display->display_options['fields']['path']['field'] = 'path';
  $handler->display->display_options['fields']['path']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['path']['label'] = '';
  $handler->display->display_options['fields']['path']['exclude'] = TRUE;
  $handler->display->display_options['fields']['path']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['path']['absolute'] = TRUE;
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_courseliftup_image']['id'] = 'field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['table'] = 'field_data_field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['field'] = 'field_courseliftup_image';
  $handler->display->display_options['fields']['field_courseliftup_image']['label'] = '';
  $handler->display->display_options['fields']['field_courseliftup_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_courseliftup_image']['alter']['path'] = '[path]';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_type'] = '0';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_image']['element_wrapper_class'] = 'box-story__image';
  $handler->display->display_options['fields']['field_courseliftup_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_courseliftup_image']['settings'] = array(
    'image_style' => 'liftup_322_x_190',
    'image_link' => '',
  );
  /* Field: Content: Theme */
  $handler->display->display_options['fields']['field_course_theme']['id'] = 'field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['table'] = 'field_data_field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['field'] = 'field_course_theme';
  $handler->display->display_options['fields']['field_course_theme']['relationship'] = 'field_imp_reference_to_courses_target_id';
  $handler->display->display_options['fields']['field_course_theme']['label'] = '';
  $handler->display->display_options['fields']['field_course_theme']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_course_theme']['element_type'] = '0';
  $handler->display->display_options['fields']['field_course_theme']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_course_theme']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_course_theme']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_course_theme']['empty'] = 'Molecular Biosciences';
  $handler->display->display_options['fields']['field_course_theme']['type'] = 'taxonomy_term_reference_plain';
  $handler->display->display_options['fields']['field_course_theme']['settings'] = array(
    'field_multiple_limit' => '-1',
    'field_multiple_limit_offset' => '0',
  );
  $handler->display->display_options['fields']['field_course_theme']['delta_offset'] = '0';
  /* Field: Content: Begin date */
  $handler->display->display_options['fields']['field_imp_begin_date']['id'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['table'] = 'field_data_field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['field'] = 'field_imp_begin_date';
  $handler->display->display_options['fields']['field_imp_begin_date']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['field_imp_begin_date']['label'] = '';
  $handler->display->display_options['fields']['field_imp_begin_date']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_type'] = '0';
  $handler->display->display_options['fields']['field_imp_begin_date']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_imp_begin_date']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_imp_begin_date']['settings'] = array(
    'format_type' => 'short_date_only',
    'fromto' => 'both',
    'multiple_number' => '',
    'multiple_from' => '',
    'multiple_to' => '',
  );
  /* Field: Global: Custom text */
  $handler->display->display_options['fields']['nothing']['id'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['table'] = 'views';
  $handler->display->display_options['fields']['nothing']['field'] = 'nothing';
  $handler->display->display_options['fields']['nothing']['label'] = '';
  $handler->display->display_options['fields']['nothing']['alter']['text'] = '<span class="box-story__date">[field_imp_begin_date]</span><span class="box-story__tag">[field_course_theme]</span>';
  $handler->display->display_options['fields']['nothing']['element_type'] = '0';
  $handler->display->display_options['fields']['nothing']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['nothing']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['nothing']['element_wrapper_class'] = 'box-story__topical';
  $handler->display->display_options['fields']['nothing']['element_default_classes'] = FALSE;
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_imp_canonical_url]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h4';
  $handler->display->display_options['fields']['title']['element_class'] = 'box-story__title';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_courseliftup_descripion']['id'] = 'field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['table'] = 'field_data_field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['field'] = 'field_courseliftup_descripion';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['label'] = '';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_class'] = 'box-story__content';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_wrapper_type'] = '0';
  $handler->display->display_options['fields']['field_courseliftup_descripion']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_courseliftup_descripion']['settings'] = array(
    'trim_length' => '120',
  );
  /* Field: Content: Link */
  $handler->display->display_options['fields']['view_node']['id'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['table'] = 'views_entity_node';
  $handler->display->display_options['fields']['view_node']['field'] = 'view_node';
  $handler->display->display_options['fields']['view_node']['relationship'] = 'field_courseliftup_courseimp_target_id';
  $handler->display->display_options['fields']['view_node']['label'] = '';
  $handler->display->display_options['fields']['view_node']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['view_node']['element_wrapper_class'] = 'more-link';
  $handler->display->display_options['fields']['view_node']['text'] = 'Read more';
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
    'course_liftup' => 'course_liftup',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );
  /* Filter criterion: Content: Liftup section (field_liftup_section) */
  $handler->display->display_options['filters']['field_liftup_section_value']['id'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['table'] = 'field_data_field_liftup_section';
  $handler->display->display_options['filters']['field_liftup_section_value']['field'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['value'] = array(
    'biosciences' => 'biosciences',
  );
  $translatables['uhc_course_liftups'] = array(
    t('Master'),
    t('Highlights of upcoming courses'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('Course implementation'),
    t('Course'),
    t('Genetics'),
    t('<span class="box-story__date">[field_imp_begin_date]</span><span class="box-story__tag">[field_course_theme]</span>'),
    t('Read more'),
    t('Latest genetics'),
    t('Three lifted courses'),
    t('Latest open university'),
    t('Open University'),
    t('Latest biosciences'),
    t('Molecular Biosciences'),
  );
  $export['uhc_course_liftups'] = $view;

  $view = new view();
  $view->name = 'uhc_liftups';
  $view->description = 'Provides views for showing different types of liftups.';
  $view->tag = 'uhc_liftups';
  $view->base_table = 'node';
  $view->human_name = 'UHC liftups';
  $view->core = 7;
  $view->api_version = '3.0';
  $view->disabled = FALSE; /* Edit this to true to make a default view disabled initially */

  /* Display: Master */
  $handler = $view->new_display('default', 'Master', 'default');
  $handler->display->display_options['css_class'] = 'parade-liftup';
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
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'h1 title';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h1>Courses in genetics</h1>';
  /* Field: Content: Link to */
  $handler->display->display_options['fields']['field_liftup_link_to']['id'] = 'field_liftup_link_to';
  $handler->display->display_options['fields']['field_liftup_link_to']['table'] = 'field_data_field_liftup_link_to';
  $handler->display->display_options['fields']['field_liftup_link_to']['field'] = 'field_liftup_link_to';
  $handler->display->display_options['fields']['field_liftup_link_to']['label'] = '';
  $handler->display->display_options['fields']['field_liftup_link_to']['exclude'] = TRUE;
  $handler->display->display_options['fields']['field_liftup_link_to']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_liftup_link_to']['click_sort_column'] = 'url';
  $handler->display->display_options['fields']['field_liftup_link_to']['type'] = 'link_plain';
  /* Field: Content: Image */
  $handler->display->display_options['fields']['field_liftup_image']['id'] = 'field_liftup_image';
  $handler->display->display_options['fields']['field_liftup_image']['table'] = 'field_data_field_liftup_image';
  $handler->display->display_options['fields']['field_liftup_image']['field'] = 'field_liftup_image';
  $handler->display->display_options['fields']['field_liftup_image']['label'] = '';
  $handler->display->display_options['fields']['field_liftup_image']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['field_liftup_image']['alter']['path'] = '[field_liftup_link_to]';
  $handler->display->display_options['fields']['field_liftup_image']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_liftup_image']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_liftup_image']['element_wrapper_type'] = 'div';
  $handler->display->display_options['fields']['field_liftup_image']['element_wrapper_class'] = 'liftup-main-image';
  $handler->display->display_options['fields']['field_liftup_image']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['field_liftup_image']['click_sort_column'] = 'fid';
  $handler->display->display_options['fields']['field_liftup_image']['settings'] = array(
    'image_style' => 'portal_main_liftup',
    'image_link' => '',
  );
  /* Field: Content: Title */
  $handler->display->display_options['fields']['title']['id'] = 'title';
  $handler->display->display_options['fields']['title']['table'] = 'node';
  $handler->display->display_options['fields']['title']['field'] = 'title';
  $handler->display->display_options['fields']['title']['label'] = '';
  $handler->display->display_options['fields']['title']['alter']['make_link'] = TRUE;
  $handler->display->display_options['fields']['title']['alter']['path'] = '[field_liftup_link_to]';
  $handler->display->display_options['fields']['title']['alter']['word_boundary'] = FALSE;
  $handler->display->display_options['fields']['title']['alter']['ellipsis'] = FALSE;
  $handler->display->display_options['fields']['title']['element_type'] = 'h2';
  $handler->display->display_options['fields']['title']['element_class'] = 'liftup-title';
  $handler->display->display_options['fields']['title']['element_label_type'] = '0';
  $handler->display->display_options['fields']['title']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['title']['element_default_classes'] = FALSE;
  $handler->display->display_options['fields']['title']['link_to_node'] = FALSE;
  /* Field: Content: Description */
  $handler->display->display_options['fields']['field_liftup_description']['id'] = 'field_liftup_description';
  $handler->display->display_options['fields']['field_liftup_description']['table'] = 'field_data_field_liftup_description';
  $handler->display->display_options['fields']['field_liftup_description']['field'] = 'field_liftup_description';
  $handler->display->display_options['fields']['field_liftup_description']['label'] = '';
  $handler->display->display_options['fields']['field_liftup_description']['alter']['path'] = '[field_liftup_link_to]';
  $handler->display->display_options['fields']['field_liftup_description']['element_type'] = 'div';
  $handler->display->display_options['fields']['field_liftup_description']['element_class'] = 'description body-text';
  $handler->display->display_options['fields']['field_liftup_description']['element_label_type'] = '0';
  $handler->display->display_options['fields']['field_liftup_description']['element_label_colon'] = FALSE;
  $handler->display->display_options['fields']['field_liftup_description']['element_default_classes'] = FALSE;
  /* Sort criterion: Content: Sticky */
  $handler->display->display_options['sorts']['sticky']['id'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['table'] = 'node';
  $handler->display->display_options['sorts']['sticky']['field'] = 'sticky';
  $handler->display->display_options['sorts']['sticky']['order'] = 'DESC';
  /* Sort criterion: Content: Post date */
  $handler->display->display_options['sorts']['created']['id'] = 'created';
  $handler->display->display_options['sorts']['created']['table'] = 'node';
  $handler->display->display_options['sorts']['created']['field'] = 'created';
  $handler->display->display_options['sorts']['created']['order'] = 'DESC';
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
    'liftup' => 'liftup',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );

  /* Display: Genetics parade liftup */
  $handler = $view->new_display('block', 'Genetics parade liftup', 'main');
  $handler->display->display_options['display_description'] = 'Used in landingpage\'s primary liftup (only one).';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
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
    'liftup' => 'liftup',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );
  /* Filter criterion: Content: Liftup section (field_liftup_section) */
  $handler->display->display_options['filters']['field_liftup_section_value']['id'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['table'] = 'field_data_field_liftup_section';
  $handler->display->display_options['filters']['field_liftup_section_value']['field'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['value'] = array(
    'genetics' => 'genetics',
  );

  /* Display: Open university parade liftup */
  $handler = $view->new_display('block', 'Open university parade liftup', 'block_1');
  $handler->display->display_options['display_description'] = 'Used in landingpage\'s primary liftup (only one).';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'h1 title';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h1>Open University course search</h1>';
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
    'liftup' => 'liftup',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );
  /* Filter criterion: Content: Liftup section (field_liftup_section) */
  $handler->display->display_options['filters']['field_liftup_section_value']['id'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['table'] = 'field_data_field_liftup_section';
  $handler->display->display_options['filters']['field_liftup_section_value']['field'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['value'] = array(
    'openuniversity' => 'openuniversity',
  );

  /* Display: Biosciences parade liftup */
  $handler = $view->new_display('block', 'Biosciences parade liftup', 'block_2');
  $handler->display->display_options['display_description'] = 'Used in landingpage\'s primary liftup (only one).';
  $handler->display->display_options['defaults']['pager'] = FALSE;
  $handler->display->display_options['pager']['type'] = 'some';
  $handler->display->display_options['pager']['options']['items_per_page'] = '1';
  $handler->display->display_options['pager']['options']['offset'] = '0';
  $handler->display->display_options['defaults']['header'] = FALSE;
  /* Header: Global: Unfiltered text */
  $handler->display->display_options['header']['area_text_custom']['id'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['table'] = 'views';
  $handler->display->display_options['header']['area_text_custom']['field'] = 'area_text_custom';
  $handler->display->display_options['header']['area_text_custom']['label'] = 'h1 title';
  $handler->display->display_options['header']['area_text_custom']['content'] = '<h1>Courses in Molecular Biosciences</h1>';
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
    'liftup' => 'liftup',
  );
  /* Filter criterion: Content: Language */
  $handler->display->display_options['filters']['language']['id'] = 'language';
  $handler->display->display_options['filters']['language']['table'] = 'node';
  $handler->display->display_options['filters']['language']['field'] = 'language';
  $handler->display->display_options['filters']['language']['value'] = array(
    '***CURRENT_LANGUAGE***' => '***CURRENT_LANGUAGE***',
    'und' => 'und',
  );
  /* Filter criterion: Content: Liftup section (field_liftup_section) */
  $handler->display->display_options['filters']['field_liftup_section_value']['id'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['table'] = 'field_data_field_liftup_section';
  $handler->display->display_options['filters']['field_liftup_section_value']['field'] = 'field_liftup_section_value';
  $handler->display->display_options['filters']['field_liftup_section_value']['value'] = array(
    'biosciences' => 'biosciences',
  );
  $translatables['uhc_liftups'] = array(
    t('Master'),
    t('more'),
    t('Apply'),
    t('Reset'),
    t('Sort by'),
    t('Asc'),
    t('Desc'),
    t('h1 title'),
    t('<h1>Courses in genetics</h1>'),
    t('Genetics parade liftup'),
    t('Used in landingpage\'s primary liftup (only one).'),
    t('Open university parade liftup'),
    t('<h1>Open University course search</h1>'),
    t('Biosciences parade liftup'),
    t('<h1>Courses in Molecular Biosciences</h1>'),
  );
  $export['uhc_liftups'] = $view;

  return $export;
}
