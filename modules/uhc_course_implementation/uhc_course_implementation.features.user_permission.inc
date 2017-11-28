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

  // Exported permission: 'create field_default_header_image'.
  $permissions['create field_default_header_image'] = array(
    'name' => 'create field_default_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_default_header_image_capti'.
  $permissions['create field_default_header_image_capti'] = array(
    'name' => 'create field_default_header_image_capti',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_extra_organisation'.
  $permissions['create field_imp_extra_organisation'] = array(
    'name' => 'create field_imp_extra_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_flexible_start'.
  $permissions['create field_imp_flexible_start'] = array(
    'name' => 'create field_imp_flexible_start',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

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

  // Exported permission: 'create field_imp_timetable_additional'.
  $permissions['create field_imp_timetable_additional'] = array(
    'name' => 'create field_imp_timetable_additional',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_default_header_image'.
  $permissions['edit field_default_header_image'] = array(
    'name' => 'edit field_default_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_default_header_image_capti'.
  $permissions['edit field_default_header_image_capti'] = array(
    'name' => 'edit field_default_header_image_capti',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_extra_organisation'.
  $permissions['edit field_imp_extra_organisation'] = array(
    'name' => 'edit field_imp_extra_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_flexible_start'.
  $permissions['edit field_imp_flexible_start'] = array(
    'name' => 'edit field_imp_flexible_start',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
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

  // Exported permission: 'edit field_imp_timetable_additional'.
  $permissions['edit field_imp_timetable_additional'] = array(
    'name' => 'edit field_imp_timetable_additional',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_default_header_image'.
  $permissions['edit own field_default_header_image'] = array(
    'name' => 'edit own field_default_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_default_header_image_capti'.
  $permissions['edit own field_default_header_image_capti'] = array(
    'name' => 'edit own field_default_header_image_capti',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_extra_organisation'.
  $permissions['edit own field_imp_extra_organisation'] = array(
    'name' => 'edit own field_imp_extra_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_flexible_start'.
  $permissions['edit own field_imp_flexible_start'] = array(
    'name' => 'edit own field_imp_flexible_start',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
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

  // Exported permission: 'edit own field_imp_timetable_additional'.
  $permissions['edit own field_imp_timetable_additional'] = array(
    'name' => 'edit own field_imp_timetable_additional',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_default_header_image'.
  $permissions['view field_default_header_image'] = array(
    'name' => 'view field_default_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_default_header_image_capti'.
  $permissions['view field_default_header_image_capti'] = array(
    'name' => 'view field_default_header_image_capti',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_extra_organisation'.
  $permissions['view field_imp_extra_organisation'] = array(
    'name' => 'view field_imp_extra_organisation',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_flexible_start'.
  $permissions['view field_imp_flexible_start'] = array(
    'name' => 'view field_imp_flexible_start',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'view field_imp_timetable_additional'.
  $permissions['view field_imp_timetable_additional'] = array(
    'name' => 'view field_imp_timetable_additional',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_default_header_image'.
  $permissions['view own field_default_header_image'] = array(
    'name' => 'view own field_default_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_default_header_image_capti'.
  $permissions['view own field_default_header_image_capti'] = array(
    'name' => 'view own field_default_header_image_capti',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_extra_organisation'.
  $permissions['view own field_imp_extra_organisation'] = array(
    'name' => 'view own field_imp_extra_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_flexible_start'.
  $permissions['view own field_imp_flexible_start'] = array(
    'name' => 'view own field_imp_flexible_start',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
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

  // Exported permission: 'view own field_imp_timetable_additional'.
  $permissions['view own field_imp_timetable_additional'] = array(
    'name' => 'view own field_imp_timetable_additional',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view uhc_course_implementation_enrollment_button on node'.
  $permissions['view uhc_course_implementation_enrollment_button on node'] = array(
    'name' => 'view uhc_course_implementation_enrollment_button on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  return $permissions;
}
