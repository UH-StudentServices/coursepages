<?php
/**
 * @file
 * uhc_course_implementation_inherited_fields.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_course_implementation_inherited_fields_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create field_inherited_additional_info'.
  $permissions['create field_inherited_additional_info'] = array(
    'name' => 'create field_inherited_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_conduct'.
  $permissions['create field_inherited_conduct'] = array(
    'name' => 'create field_inherited_conduct',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_contents'.
  $permissions['create field_inherited_contents'] = array(
    'name' => 'create field_inherited_contents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_evaluation'.
  $permissions['create field_inherited_evaluation'] = array(
    'name' => 'create field_inherited_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_objective'.
  $permissions['create field_inherited_objective'] = array(
    'name' => 'create field_inherited_objective',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_rel_to_other_stu'.
  $permissions['create field_inherited_rel_to_other_stu'] = array(
    'name' => 'create field_inherited_rel_to_other_stu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_req_prerequisite'.
  $permissions['create field_inherited_req_prerequisite'] = array(
    'name' => 'create field_inherited_req_prerequisite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_responsible_pers'.
  $permissions['create field_inherited_responsible_pers'] = array(
    'name' => 'create field_inherited_responsible_pers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_study_materials'.
  $permissions['create field_inherited_study_materials'] = array(
    'name' => 'create field_inherited_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_target_group'.
  $permissions['create field_inherited_target_group'] = array(
    'name' => 'create field_inherited_target_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_timing'.
  $permissions['create field_inherited_timing'] = array(
    'name' => 'create field_inherited_timing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_inherited_working_methods'.
  $permissions['create field_inherited_working_methods'] = array(
    'name' => 'create field_inherited_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_additional_info'.
  $permissions['edit field_inherited_additional_info'] = array(
    'name' => 'edit field_inherited_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_conduct'.
  $permissions['edit field_inherited_conduct'] = array(
    'name' => 'edit field_inherited_conduct',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_contents'.
  $permissions['edit field_inherited_contents'] = array(
    'name' => 'edit field_inherited_contents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_evaluation'.
  $permissions['edit field_inherited_evaluation'] = array(
    'name' => 'edit field_inherited_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_objective'.
  $permissions['edit field_inherited_objective'] = array(
    'name' => 'edit field_inherited_objective',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_rel_to_other_stu'.
  $permissions['edit field_inherited_rel_to_other_stu'] = array(
    'name' => 'edit field_inherited_rel_to_other_stu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_req_prerequisite'.
  $permissions['edit field_inherited_req_prerequisite'] = array(
    'name' => 'edit field_inherited_req_prerequisite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_responsible_pers'.
  $permissions['edit field_inherited_responsible_pers'] = array(
    'name' => 'edit field_inherited_responsible_pers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_study_materials'.
  $permissions['edit field_inherited_study_materials'] = array(
    'name' => 'edit field_inherited_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_target_group'.
  $permissions['edit field_inherited_target_group'] = array(
    'name' => 'edit field_inherited_target_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_timing'.
  $permissions['edit field_inherited_timing'] = array(
    'name' => 'edit field_inherited_timing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_inherited_working_methods'.
  $permissions['edit field_inherited_working_methods'] = array(
    'name' => 'edit field_inherited_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_additional_info'.
  $permissions['edit own field_inherited_additional_info'] = array(
    'name' => 'edit own field_inherited_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_conduct'.
  $permissions['edit own field_inherited_conduct'] = array(
    'name' => 'edit own field_inherited_conduct',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_contents'.
  $permissions['edit own field_inherited_contents'] = array(
    'name' => 'edit own field_inherited_contents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_evaluation'.
  $permissions['edit own field_inherited_evaluation'] = array(
    'name' => 'edit own field_inherited_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_objective'.
  $permissions['edit own field_inherited_objective'] = array(
    'name' => 'edit own field_inherited_objective',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_rel_to_other_stu'.
  $permissions['edit own field_inherited_rel_to_other_stu'] = array(
    'name' => 'edit own field_inherited_rel_to_other_stu',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_req_prerequisite'.
  $permissions['edit own field_inherited_req_prerequisite'] = array(
    'name' => 'edit own field_inherited_req_prerequisite',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_responsible_pers'.
  $permissions['edit own field_inherited_responsible_pers'] = array(
    'name' => 'edit own field_inherited_responsible_pers',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_study_materials'.
  $permissions['edit own field_inherited_study_materials'] = array(
    'name' => 'edit own field_inherited_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_target_group'.
  $permissions['edit own field_inherited_target_group'] = array(
    'name' => 'edit own field_inherited_target_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_timing'.
  $permissions['edit own field_inherited_timing'] = array(
    'name' => 'edit own field_inherited_timing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_inherited_working_methods'.
  $permissions['edit own field_inherited_working_methods'] = array(
    'name' => 'edit own field_inherited_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_additional_info'.
  $permissions['view field_inherited_additional_info'] = array(
    'name' => 'view field_inherited_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_conduct'.
  $permissions['view field_inherited_conduct'] = array(
    'name' => 'view field_inherited_conduct',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_contents'.
  $permissions['view field_inherited_contents'] = array(
    'name' => 'view field_inherited_contents',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_evaluation'.
  $permissions['view field_inherited_evaluation'] = array(
    'name' => 'view field_inherited_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_objective'.
  $permissions['view field_inherited_objective'] = array(
    'name' => 'view field_inherited_objective',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_rel_to_other_stu'.
  $permissions['view field_inherited_rel_to_other_stu'] = array(
    'name' => 'view field_inherited_rel_to_other_stu',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_req_prerequisite'.
  $permissions['view field_inherited_req_prerequisite'] = array(
    'name' => 'view field_inherited_req_prerequisite',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_responsible_pers'.
  $permissions['view field_inherited_responsible_pers'] = array(
    'name' => 'view field_inherited_responsible_pers',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_study_materials'.
  $permissions['view field_inherited_study_materials'] = array(
    'name' => 'view field_inherited_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_target_group'.
  $permissions['view field_inherited_target_group'] = array(
    'name' => 'view field_inherited_target_group',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_timing'.
  $permissions['view field_inherited_timing'] = array(
    'name' => 'view field_inherited_timing',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_inherited_working_methods'.
  $permissions['view field_inherited_working_methods'] = array(
    'name' => 'view field_inherited_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_additional_info'.
  $permissions['view own field_inherited_additional_info'] = array(
    'name' => 'view own field_inherited_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_conduct'.
  $permissions['view own field_inherited_conduct'] = array(
    'name' => 'view own field_inherited_conduct',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_contents'.
  $permissions['view own field_inherited_contents'] = array(
    'name' => 'view own field_inherited_contents',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_evaluation'.
  $permissions['view own field_inherited_evaluation'] = array(
    'name' => 'view own field_inherited_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_objective'.
  $permissions['view own field_inherited_objective'] = array(
    'name' => 'view own field_inherited_objective',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_rel_to_other_stu'.
  $permissions['view own field_inherited_rel_to_other_stu'] = array(
    'name' => 'view own field_inherited_rel_to_other_stu',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_req_prerequisite'.
  $permissions['view own field_inherited_req_prerequisite'] = array(
    'name' => 'view own field_inherited_req_prerequisite',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_responsible_pers'.
  $permissions['view own field_inherited_responsible_pers'] = array(
    'name' => 'view own field_inherited_responsible_pers',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_study_materials'.
  $permissions['view own field_inherited_study_materials'] = array(
    'name' => 'view own field_inherited_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_target_group'.
  $permissions['view own field_inherited_target_group'] = array(
    'name' => 'view own field_inherited_target_group',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_timing'.
  $permissions['view own field_inherited_timing'] = array(
    'name' => 'view own field_inherited_timing',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_inherited_working_methods'.
  $permissions['view own field_inherited_working_methods'] = array(
    'name' => 'view own field_inherited_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view uhc_course_implementation_inherited_fields_objective on node'.
  $permissions['view uhc_course_implementation_inherited_fields_objective on node'] = array(
    'name' => 'view uhc_course_implementation_inherited_fields_objective on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_course_implementation_inherited_fields_rel_to_other_study_units on node'.
  $permissions['view uhc_course_implementation_inherited_fields_rel_to_other_study_units on node'] = array(
    'name' => 'view uhc_course_implementation_inherited_fields_rel_to_other_study_units on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_course_implementation_inherited_fields_req_prerequisites on node'.
  $permissions['view uhc_course_implementation_inherited_fields_req_prerequisites on node'] = array(
    'name' => 'view uhc_course_implementation_inherited_fields_req_prerequisites on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_course_implementation_inherited_fields_responsible_person on node'.
  $permissions['view uhc_course_implementation_inherited_fields_responsible_person on node'] = array(
    'name' => 'view uhc_course_implementation_inherited_fields_responsible_person on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_course_implementation_inherited_fields_study_materials on node'.
  $permissions['view uhc_course_implementation_inherited_fields_study_materials on node'] = array(
    'name' => 'view uhc_course_implementation_inherited_fields_study_materials on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_course_implementation_inherited_fields_target_group on node'.
  $permissions['view uhc_course_implementation_inherited_fields_target_group on node'] = array(
    'name' => 'view uhc_course_implementation_inherited_fields_target_group on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_course_implementation_inherited_fields_timing on node'.
  $permissions['view uhc_course_implementation_inherited_fields_timing on node'] = array(
    'name' => 'view uhc_course_implementation_inherited_fields_timing on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_course_implementation_inherited_fields_working_methods on node'.
  $permissions['view uhc_course_implementation_inherited_fields_working_methods on node'] = array(
    'name' => 'view uhc_course_implementation_inherited_fields_working_methods on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  return $permissions;
}
