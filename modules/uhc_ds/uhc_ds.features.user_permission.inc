<?php
/**
 * @file
 * uhc_ds.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_ds_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'admin_classes'.
  $permissions['admin_classes'] = array(
    'name' => 'admin_classes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_display_suite'.
  $permissions['admin_display_suite'] = array(
    'name' => 'admin_display_suite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds',
  );

  // Exported permission: 'admin_fields'.
  $permissions['admin_fields'] = array(
    'name' => 'admin_fields',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'admin_view_modes'.
  $permissions['admin_view_modes'] = array(
    'name' => 'admin_view_modes',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_ui',
  );

  // Exported permission: 'ds_switch course'.
  $permissions['ds_switch course'] = array(
    'name' => 'ds_switch course',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'ds_switch course_implementation'.
  $permissions['ds_switch course_implementation'] = array(
    'name' => 'ds_switch course_implementation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'ds_switch course_liftup'.
  $permissions['ds_switch course_liftup'] = array(
    'name' => 'ds_switch course_liftup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'ds_switch course_material'.
  $permissions['ds_switch course_material'] = array(
    'name' => 'ds_switch course_material',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'ds_switch course_task'.
  $permissions['ds_switch course_task'] = array(
    'name' => 'ds_switch course_task',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'ds_switch event'.
  $permissions['ds_switch event'] = array(
    'name' => 'ds_switch event',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'ds_switch liftup'.
  $permissions['ds_switch liftup'] = array(
    'name' => 'ds_switch liftup',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'ds_switch subject'.
  $permissions['ds_switch subject'] = array(
    'name' => 'ds_switch subject',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'use text format ds_code'.
  $permissions['use text format ds_code'] = array(
    'name' => 'use text format ds_code',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'filter',
  );

  // Exported permission: 'view author on comment'.
  $permissions['view author on comment'] = array(
    'name' => 'view author on comment',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view author on node'.
  $permissions['view author on node'] = array(
    'name' => 'view author on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view changed_date on node'.
  $permissions['view changed_date on node'] = array(
    'name' => 'view changed_date on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view comments on node'.
  $permissions['view comments on node'] = array(
    'name' => 'view comments on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view course_imp_activity on node'.
  $permissions['view course_imp_activity on node'] = array(
    'name' => 'view course_imp_activity on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view course_implementation_material on node'.
  $permissions['view course_implementation_material on node'] = array(
    'name' => 'view course_implementation_material on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view course_implementation_timepsan on node'.
  $permissions['view course_implementation_timepsan on node'] = array(
    'name' => 'view course_implementation_timepsan on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view course_overview_link on node'.
  $permissions['view course_overview_link on node'] = array(
    'name' => 'view course_overview_link on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view course_reference_block on node'.
  $permissions['view course_reference_block on node'] = array(
    'name' => 'view course_reference_block on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view course_reference_block_past on node'.
  $permissions['view course_reference_block_past on node'] = array(
    'name' => 'view course_reference_block_past on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view ds_switch_field on node'.
  $permissions['view ds_switch_field on node'] = array(
    'name' => 'view ds_switch_field on node',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view ds_user_picture on comment'.
  $permissions['view ds_user_picture on comment'] = array(
    'name' => 'view ds_user_picture on comment',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view ds_user_picture on node'.
  $permissions['view ds_user_picture on node'] = array(
    'name' => 'view ds_user_picture on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view ds_user_picture on user'.
  $permissions['view ds_user_picture on user'] = array(
    'name' => 'view ds_user_picture on user',
    'roles' => array(),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view event_information_row on node'.
  $permissions['view event_information_row on node'] = array(
    'name' => 'view event_information_row on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view event_material on node'.
  $permissions['view event_material on node'] = array(
    'name' => 'view event_material on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view event_meta_information on node'.
  $permissions['view event_meta_information on node'] = array(
    'name' => 'view event_meta_information on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view event_reference__light_view_blok on node'.
  $permissions['view event_reference__light_view_blok on node'] = array(
    'name' => 'view event_reference__light_view_blok on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view event_reference_block on node'.
  $permissions['view event_reference_block on node'] = array(
    'name' => 'view event_reference_block on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view front_page_search_exposed_form on node'.
  $permissions['view front_page_search_exposed_form on node'] = array(
    'name' => 'view front_page_search_exposed_form on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view links on comment'.
  $permissions['view links on comment'] = array(
    'name' => 'view links on comment',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view links on node'.
  $permissions['view links on node'] = array(
    'name' => 'view links on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view location_and_time on node'.
  $permissions['view location_and_time on node'] = array(
    'name' => 'view location_and_time on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view message_header on comment'.
  $permissions['view message_header on comment'] = array(
    'name' => 'view message_header on comment',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view more_link on taxonomy_term'.
  $permissions['view more_link on taxonomy_term'] = array(
    'name' => 'view more_link on taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view my_enrollments on node'.
  $permissions['view my_enrollments on node'] = array(
    'name' => 'view my_enrollments on node',
    'roles' => array(
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view name on user'.
  $permissions['view name on user'] = array(
    'name' => 'view name on user',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view node_link on node'.
  $permissions['view node_link on node'] = array(
    'name' => 'view node_link on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view node_title_with_content_link on node'.
  $permissions['view node_title_with_content_link on node'] = array(
    'name' => 'view node_title_with_content_link on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view permalink on comment'.
  $permissions['view permalink on comment'] = array(
    'name' => 'view permalink on comment',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view post_date on comment'.
  $permissions['view post_date on comment'] = array(
    'name' => 'view post_date on comment',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view post_date on node'.
  $permissions['view post_date on node'] = array(
    'name' => 'view post_date on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view repeating_event_reference_block on node'.
  $permissions['view repeating_event_reference_block on node'] = array(
    'name' => 'view repeating_event_reference_block on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view scope on node'.
  $permissions['view scope on node'] = array(
    'name' => 'view scope on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view submitted on comment'.
  $permissions['view submitted on comment'] = array(
    'name' => 'view submitted on comment',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view submitted_by on node'.
  $permissions['view submitted_by on node'] = array(
    'name' => 'view submitted_by on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view timespan on node'.
  $permissions['view timespan on node'] = array(
    'name' => 'view timespan on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view title on comment'.
  $permissions['view title on comment'] = array(
    'name' => 'view title on comment',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view title on node'.
  $permissions['view title on node'] = array(
    'name' => 'view title on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view title on taxonomy_term'.
  $permissions['view title on taxonomy_term'] = array(
    'name' => 'view title on taxonomy_term',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_additional_info on node'.
  $permissions['view uhc_ds_additional_info on node'] = array(
    'name' => 'view uhc_ds_additional_info on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_conduct on node'.
  $permissions['view uhc_ds_conduct on node'] = array(
    'name' => 'view uhc_ds_conduct on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_contents on node'.
  $permissions['view uhc_ds_contents on node'] = array(
    'name' => 'view uhc_ds_contents on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_course_number on node'.
  $permissions['view uhc_ds_course_number on node'] = array(
    'name' => 'view uhc_ds_course_number on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_evaluation on node'.
  $permissions['view uhc_ds_evaluation on node'] = array(
    'name' => 'view uhc_ds_evaluation on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_link_to_related_subjects on node'.
  $permissions['view uhc_ds_link_to_related_subjects on node'] = array(
    'name' => 'view uhc_ds_link_to_related_subjects on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_link_to_subject on node'.
  $permissions['view uhc_ds_link_to_subject on node'] = array(
    'name' => 'view uhc_ds_link_to_subject on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_objective on node'.
  $permissions['view uhc_ds_objective on node'] = array(
    'name' => 'view uhc_ds_objective on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_req_prerequisites on node'.
  $permissions['view uhc_ds_req_prerequisites on node'] = array(
    'name' => 'view uhc_ds_req_prerequisites on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_study_materials on node'.
  $permissions['view uhc_ds_study_materials on node'] = array(
    'name' => 'view uhc_ds_study_materials on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_target_group on node'.
  $permissions['view uhc_ds_target_group on node'] = array(
    'name' => 'view uhc_ds_target_group on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  return $permissions;
}
