<?php
/**
 * @file
 * uhc_course_implementation.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_course_implementation_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_imp_hide_sign_up_button'.
  $permissions['create field_imp_hide_sign_up_button'] = array(
    'name' => 'create field_imp_hide_sign_up_button',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_hide_sign_up_button'.
  $permissions['edit field_imp_hide_sign_up_button'] = array(
    'name' => 'edit field_imp_hide_sign_up_button',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_hide_sign_up_button'.
  $permissions['edit own field_imp_hide_sign_up_button'] = array(
    'name' => 'edit own field_imp_hide_sign_up_button',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_hide_sign_up_button'.
  $permissions['view field_imp_hide_sign_up_button'] = array(
    'name' => 'view field_imp_hide_sign_up_button',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_hide_sign_up_button'.
  $permissions['view own field_imp_hide_sign_up_button'] = array(
    'name' => 'view own field_imp_hide_sign_up_button',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  return $permissions;
}
