<?php
/**
 * @file
 * uhc_event.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_event_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_event_ref_to_material'.
  $permissions['create field_event_ref_to_material'] = array(
    'name' => 'create field_event_ref_to_material',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_events_json'.
  $permissions['create field_imp_events_json'] = array(
    'name' => 'create field_imp_events_json',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_event_ref_to_material'.
  $permissions['edit field_event_ref_to_material'] = array(
    'name' => 'edit field_event_ref_to_material',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_events_json'.
  $permissions['edit field_imp_events_json'] = array(
    'name' => 'edit field_imp_events_json',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_event_ref_to_material'.
  $permissions['edit own field_event_ref_to_material'] = array(
    'name' => 'edit own field_event_ref_to_material',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_events_json'.
  $permissions['edit own field_imp_events_json'] = array(
    'name' => 'edit own field_imp_events_json',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_event_ref_to_material'.
  $permissions['view field_event_ref_to_material'] = array(
    'name' => 'view field_event_ref_to_material',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_events_json'.
  $permissions['view field_imp_events_json'] = array(
    'name' => 'view field_imp_events_json',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_event_ref_to_material'.
  $permissions['view own field_event_ref_to_material'] = array(
    'name' => 'view own field_event_ref_to_material',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_events_json'.
  $permissions['view own field_imp_events_json'] = array(
    'name' => 'view own field_imp_events_json',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
