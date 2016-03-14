<?php
/**
 * @file
 * uhc_content_administration_feature.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_content_administration_feature_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'Use Moodi button'.
  $permissions['Use Moodi button'] = array(
    'name' => 'Use Moodi button',
    'roles' => array(
      'Moodle integrator' => 'Moodle integrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'uhc_moodi',
  );

  // Exported permission: 'access administration menu'.
  $permissions['access administration menu'] = array(
    'name' => 'access administration menu',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'admin_menu',
  );

  // Exported permission: 'access administration pages'.
  $permissions['access administration pages'] = array(
    'name' => 'access administration pages',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'system',
  );

  // Exported permission: 'access content overview'.
  $permissions['access content overview'] = array(
    'name' => 'access content overview',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'access contextual links'.
  $permissions['access contextual links'] = array(
    'name' => 'access contextual links',
    'roles' => array(),
    'module' => 'contextual',
  );

  // Exported permission: 'access google analytics reports'.
  $permissions['access google analytics reports'] = array(
    'name' => 'access google analytics reports',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'google_analytics_reports',
  );

  // Exported permission: 'access sync status page'.
  $permissions['access sync status page'] = array(
    'name' => 'access sync status page',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'uhc_sources',
  );

  // Exported permission: 'add terms in course_theme'.
  $permissions['add terms in course_theme'] = array(
    'name' => 'add terms in course_theme',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'add terms in months'.
  $permissions['add terms in months'] = array(
    'name' => 'add terms in months',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'taxonomy_access_fix',
  );

  // Exported permission: 'administer contexts'.
  $permissions['administer contexts'] = array(
    'name' => 'administer contexts',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'administer menu'.
  $permissions['administer menu'] = array(
    'name' => 'administer menu',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'menu',
  );

  // Exported permission: 'context ajax block access'.
  $permissions['context ajax block access'] = array(
    'name' => 'context ajax block access',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'context_ui',
  );

  // Exported permission: 'create contact_card content'.
  $permissions['create contact_card content'] = array(
    'name' => 'create contact_card content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create course content'.
  $permissions['create course content'] = array(
    'name' => 'create course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create course_implementation content'.
  $permissions['create course_implementation content'] = array(
    'name' => 'create course_implementation content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create course_liftup content'.
  $permissions['create course_liftup content'] = array(
    'name' => 'create course_liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create course_material content'.
  $permissions['create course_material content'] = array(
    'name' => 'create course_material content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create event content'.
  $permissions['create event content'] = array(
    'name' => 'create event content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create field_additional_info'.
  $permissions['create field_additional_info'] = array(
    'name' => 'create field_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_cancelled'.
  $permissions['create field_cancelled'] = array(
    'name' => 'create field_cancelled',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_conduct'.
  $permissions['create field_conduct'] = array(
    'name' => 'create field_conduct',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_contents'.
  $permissions['create field_contents'] = array(
    'name' => 'create field_contents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_course_number'.
  $permissions['create field_course_course_number'] = array(
    'name' => 'create field_course_course_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_course_tags'.
  $permissions['create field_course_course_tags'] = array(
    'name' => 'create field_course_course_tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_faculty'.
  $permissions['create field_course_faculty'] = array(
    'name' => 'create field_course_faculty',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_subject'.
  $permissions['create field_course_subject'] = array(
    'name' => 'create field_course_subject',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_theme'.
  $permissions['create field_course_theme'] = array(
    'name' => 'create field_course_theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_course_type_of_teaching'.
  $permissions['create field_course_type_of_teaching'] = array(
    'name' => 'create field_course_type_of_teaching',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_evaluation'.
  $permissions['create field_evaluation'] = array(
    'name' => 'create field_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_feedback_description'.
  $permissions['create field_feedback_description'] = array(
    'name' => 'create field_feedback_description',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_feedback_link'.
  $permissions['create field_feedback_link'] = array(
    'name' => 'create field_feedback_link',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_administrator_number'.
  $permissions['create field_imp_administrator_number'] = array(
    'name' => 'create field_imp_administrator_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_begin_date'.
  $permissions['create field_imp_begin_date'] = array(
    'name' => 'create field_imp_begin_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_canonical_url'.
  $permissions['create field_imp_canonical_url'] = array(
    'name' => 'create field_imp_canonical_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_course_organiser'.
  $permissions['create field_imp_course_organiser'] = array(
    'name' => 'create field_imp_course_organiser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_end_date'.
  $permissions['create field_imp_end_date'] = array(
    'name' => 'create field_imp_end_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_fee'.
  $permissions['create field_imp_fee'] = array(
    'name' => 'create field_imp_fee',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_giver_locality'.
  $permissions['create field_imp_giver_locality'] = array(
    'name' => 'create field_imp_giver_locality',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_header_headline'.
  $permissions['create field_imp_header_headline'] = array(
    'name' => 'create field_imp_header_headline',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_header_image'.
  $permissions['create field_imp_header_image'] = array(
    'name' => 'create field_imp_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_header_image_caption'.
  $permissions['create field_imp_header_image_caption'] = array(
    'name' => 'create field_imp_header_image_caption',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_header_text'.
  $permissions['create field_imp_header_text'] = array(
    'name' => 'create field_imp_header_text',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_id'.
  $permissions['create field_imp_id'] = array(
    'name' => 'create field_imp_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_interaction_link'.
  $permissions['create field_imp_interaction_link'] = array(
    'name' => 'create field_imp_interaction_link',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_interactiondescription'.
  $permissions['create field_imp_interactiondescription'] = array(
    'name' => 'create field_imp_interactiondescription',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_keywords'.
  $permissions['create field_imp_keywords'] = array(
    'name' => 'create field_imp_keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_locality'.
  $permissions['create field_imp_locality'] = array(
    'name' => 'create field_imp_locality',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_method_of_study'.
  $permissions['create field_imp_method_of_study'] = array(
    'name' => 'create field_imp_method_of_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_organisation'.
  $permissions['create field_imp_organisation'] = array(
    'name' => 'create field_imp_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_reference_to_courses'.
  $permissions['create field_imp_reference_to_courses'] = array(
    'name' => 'create field_imp_reference_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_start_month'.
  $permissions['create field_imp_start_month'] = array(
    'name' => 'create field_imp_start_month',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_teacher'.
  $permissions['create field_imp_teacher'] = array(
    'name' => 'create field_imp_teacher',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_teacher_number'.
  $permissions['create field_imp_teacher_number'] = array(
    'name' => 'create field_imp_teacher_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_teachersection'.
  $permissions['create field_imp_teachersection'] = array(
    'name' => 'create field_imp_teachersection',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_imp_teaching_language'.
  $permissions['create field_imp_teaching_language'] = array(
    'name' => 'create field_imp_teaching_language',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_material_file'.
  $permissions['create field_material_file'] = array(
    'name' => 'create field_material_file',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_objective'.
  $permissions['create field_objective'] = array(
    'name' => 'create field_objective',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_open_uni_registration'.
  $permissions['create field_open_uni_registration'] = array(
    'name' => 'create field_open_uni_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_rel_to_other_study_units'.
  $permissions['create field_rel_to_other_study_units'] = array(
    'name' => 'create field_rel_to_other_study_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_req_prerequisites'.
  $permissions['create field_req_prerequisites'] = array(
    'name' => 'create field_req_prerequisites',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_responsible_person'.
  $permissions['create field_responsible_person'] = array(
    'name' => 'create field_responsible_person',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_study_credit'.
  $permissions['create field_study_credit'] = array(
    'name' => 'create field_study_credit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_study_materials'.
  $permissions['create field_study_materials'] = array(
    'name' => 'create field_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_study_module'.
  $permissions['create field_study_module'] = array(
    'name' => 'create field_study_module',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_study_module_title'.
  $permissions['create field_study_module_title'] = array(
    'name' => 'create field_study_module_title',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_subject_ref_to_courses'.
  $permissions['create field_subject_ref_to_courses'] = array(
    'name' => 'create field_subject_ref_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_target_group'.
  $permissions['create field_target_group'] = array(
    'name' => 'create field_target_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_timing'.
  $permissions['create field_timing'] = array(
    'name' => 'create field_timing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create field_working_methods'.
  $permissions['create field_working_methods'] = array(
    'name' => 'create field_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'create liftup content'.
  $permissions['create liftup content'] = array(
    'name' => 'create liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create subject content'.
  $permissions['create subject content'] = array(
    'name' => 'create subject content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any contact_card content'.
  $permissions['delete any contact_card content'] = array(
    'name' => 'delete any contact_card content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course content'.
  $permissions['delete any course content'] = array(
    'name' => 'delete any course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_implementation content'.
  $permissions['delete any course_implementation content'] = array(
    'name' => 'delete any course_implementation content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_liftup content'.
  $permissions['delete any course_liftup content'] = array(
    'name' => 'delete any course_liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any course_material content'.
  $permissions['delete any course_material content'] = array(
    'name' => 'delete any course_material content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any event content'.
  $permissions['delete any event content'] = array(
    'name' => 'delete any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any liftup content'.
  $permissions['delete any liftup content'] = array(
    'name' => 'delete any liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any subject content'.
  $permissions['delete any subject content'] = array(
    'name' => 'delete any subject content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own contact_card content'.
  $permissions['delete own contact_card content'] = array(
    'name' => 'delete own contact_card content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course content'.
  $permissions['delete own course content'] = array(
    'name' => 'delete own course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_implementation content'.
  $permissions['delete own course_implementation content'] = array(
    'name' => 'delete own course_implementation content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_liftup content'.
  $permissions['delete own course_liftup content'] = array(
    'name' => 'delete own course_liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own course_material content'.
  $permissions['delete own course_material content'] = array(
    'name' => 'delete own course_material content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own event content'.
  $permissions['delete own event content'] = array(
    'name' => 'delete own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own liftup content'.
  $permissions['delete own liftup content'] = array(
    'name' => 'delete own liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own subject content'.
  $permissions['delete own subject content'] = array(
    'name' => 'delete own subject content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete terms in course_theme'.
  $permissions['delete terms in course_theme'] = array(
    'name' => 'delete terms in course_theme',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'delete terms in months'.
  $permissions['delete terms in months'] = array(
    'name' => 'delete terms in months',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit any contact_card content'.
  $permissions['edit any contact_card content'] = array(
    'name' => 'edit any contact_card content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course content'.
  $permissions['edit any course content'] = array(
    'name' => 'edit any course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_implementation content'.
  $permissions['edit any course_implementation content'] = array(
    'name' => 'edit any course_implementation content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_liftup content'.
  $permissions['edit any course_liftup content'] = array(
    'name' => 'edit any course_liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any course_material content'.
  $permissions['edit any course_material content'] = array(
    'name' => 'edit any course_material content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any event content'.
  $permissions['edit any event content'] = array(
    'name' => 'edit any event content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any liftup content'.
  $permissions['edit any liftup content'] = array(
    'name' => 'edit any liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any subject content'.
  $permissions['edit any subject content'] = array(
    'name' => 'edit any subject content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit field_additional_info'.
  $permissions['edit field_additional_info'] = array(
    'name' => 'edit field_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_cancelled'.
  $permissions['edit field_cancelled'] = array(
    'name' => 'edit field_cancelled',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_conduct'.
  $permissions['edit field_conduct'] = array(
    'name' => 'edit field_conduct',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_contents'.
  $permissions['edit field_contents'] = array(
    'name' => 'edit field_contents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_course_number'.
  $permissions['edit field_course_course_number'] = array(
    'name' => 'edit field_course_course_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_course_tags'.
  $permissions['edit field_course_course_tags'] = array(
    'name' => 'edit field_course_course_tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_faculty'.
  $permissions['edit field_course_faculty'] = array(
    'name' => 'edit field_course_faculty',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_subject'.
  $permissions['edit field_course_subject'] = array(
    'name' => 'edit field_course_subject',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_theme'.
  $permissions['edit field_course_theme'] = array(
    'name' => 'edit field_course_theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_course_type_of_teaching'.
  $permissions['edit field_course_type_of_teaching'] = array(
    'name' => 'edit field_course_type_of_teaching',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_evaluation'.
  $permissions['edit field_evaluation'] = array(
    'name' => 'edit field_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_feedback_description'.
  $permissions['edit field_feedback_description'] = array(
    'name' => 'edit field_feedback_description',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_feedback_link'.
  $permissions['edit field_feedback_link'] = array(
    'name' => 'edit field_feedback_link',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_administrator_number'.
  $permissions['edit field_imp_administrator_number'] = array(
    'name' => 'edit field_imp_administrator_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_begin_date'.
  $permissions['edit field_imp_begin_date'] = array(
    'name' => 'edit field_imp_begin_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_canonical_url'.
  $permissions['edit field_imp_canonical_url'] = array(
    'name' => 'edit field_imp_canonical_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_course_organiser'.
  $permissions['edit field_imp_course_organiser'] = array(
    'name' => 'edit field_imp_course_organiser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_end_date'.
  $permissions['edit field_imp_end_date'] = array(
    'name' => 'edit field_imp_end_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_fee'.
  $permissions['edit field_imp_fee'] = array(
    'name' => 'edit field_imp_fee',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_giver_locality'.
  $permissions['edit field_imp_giver_locality'] = array(
    'name' => 'edit field_imp_giver_locality',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_header_headline'.
  $permissions['edit field_imp_header_headline'] = array(
    'name' => 'edit field_imp_header_headline',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_header_image'.
  $permissions['edit field_imp_header_image'] = array(
    'name' => 'edit field_imp_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_header_image_caption'.
  $permissions['edit field_imp_header_image_caption'] = array(
    'name' => 'edit field_imp_header_image_caption',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_header_text'.
  $permissions['edit field_imp_header_text'] = array(
    'name' => 'edit field_imp_header_text',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_id'.
  $permissions['edit field_imp_id'] = array(
    'name' => 'edit field_imp_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_interaction_link'.
  $permissions['edit field_imp_interaction_link'] = array(
    'name' => 'edit field_imp_interaction_link',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_interactiondescription'.
  $permissions['edit field_imp_interactiondescription'] = array(
    'name' => 'edit field_imp_interactiondescription',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_keywords'.
  $permissions['edit field_imp_keywords'] = array(
    'name' => 'edit field_imp_keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_locality'.
  $permissions['edit field_imp_locality'] = array(
    'name' => 'edit field_imp_locality',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_method_of_study'.
  $permissions['edit field_imp_method_of_study'] = array(
    'name' => 'edit field_imp_method_of_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_organisation'.
  $permissions['edit field_imp_organisation'] = array(
    'name' => 'edit field_imp_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_reference_to_courses'.
  $permissions['edit field_imp_reference_to_courses'] = array(
    'name' => 'edit field_imp_reference_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_start_month'.
  $permissions['edit field_imp_start_month'] = array(
    'name' => 'edit field_imp_start_month',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_teacher'.
  $permissions['edit field_imp_teacher'] = array(
    'name' => 'edit field_imp_teacher',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_teacher_number'.
  $permissions['edit field_imp_teacher_number'] = array(
    'name' => 'edit field_imp_teacher_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_teachersection'.
  $permissions['edit field_imp_teachersection'] = array(
    'name' => 'edit field_imp_teachersection',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_imp_teaching_language'.
  $permissions['edit field_imp_teaching_language'] = array(
    'name' => 'edit field_imp_teaching_language',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_material_file'.
  $permissions['edit field_material_file'] = array(
    'name' => 'edit field_material_file',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_objective'.
  $permissions['edit field_objective'] = array(
    'name' => 'edit field_objective',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_open_uni_registration'.
  $permissions['edit field_open_uni_registration'] = array(
    'name' => 'edit field_open_uni_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_rel_to_other_study_units'.
  $permissions['edit field_rel_to_other_study_units'] = array(
    'name' => 'edit field_rel_to_other_study_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_req_prerequisites'.
  $permissions['edit field_req_prerequisites'] = array(
    'name' => 'edit field_req_prerequisites',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_responsible_person'.
  $permissions['edit field_responsible_person'] = array(
    'name' => 'edit field_responsible_person',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_study_credit'.
  $permissions['edit field_study_credit'] = array(
    'name' => 'edit field_study_credit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_study_materials'.
  $permissions['edit field_study_materials'] = array(
    'name' => 'edit field_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_study_module'.
  $permissions['edit field_study_module'] = array(
    'name' => 'edit field_study_module',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_study_module_title'.
  $permissions['edit field_study_module_title'] = array(
    'name' => 'edit field_study_module_title',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_subject_ref_to_courses'.
  $permissions['edit field_subject_ref_to_courses'] = array(
    'name' => 'edit field_subject_ref_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_target_group'.
  $permissions['edit field_target_group'] = array(
    'name' => 'edit field_target_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_timing'.
  $permissions['edit field_timing'] = array(
    'name' => 'edit field_timing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit field_working_methods'.
  $permissions['edit field_working_methods'] = array(
    'name' => 'edit field_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own contact_card content'.
  $permissions['edit own contact_card content'] = array(
    'name' => 'edit own contact_card content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own course content'.
  $permissions['edit own course content'] = array(
    'name' => 'edit own course content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own course_implementation content'.
  $permissions['edit own course_implementation content'] = array(
    'name' => 'edit own course_implementation content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own course_liftup content'.
  $permissions['edit own course_liftup content'] = array(
    'name' => 'edit own course_liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own course_material content'.
  $permissions['edit own course_material content'] = array(
    'name' => 'edit own course_material content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own event content'.
  $permissions['edit own event content'] = array(
    'name' => 'edit own event content',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own field_additional_info'.
  $permissions['edit own field_additional_info'] = array(
    'name' => 'edit own field_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_cancelled'.
  $permissions['edit own field_cancelled'] = array(
    'name' => 'edit own field_cancelled',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_conduct'.
  $permissions['edit own field_conduct'] = array(
    'name' => 'edit own field_conduct',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_contents'.
  $permissions['edit own field_contents'] = array(
    'name' => 'edit own field_contents',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_course_number'.
  $permissions['edit own field_course_course_number'] = array(
    'name' => 'edit own field_course_course_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_course_tags'.
  $permissions['edit own field_course_course_tags'] = array(
    'name' => 'edit own field_course_course_tags',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_faculty'.
  $permissions['edit own field_course_faculty'] = array(
    'name' => 'edit own field_course_faculty',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_subject'.
  $permissions['edit own field_course_subject'] = array(
    'name' => 'edit own field_course_subject',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_theme'.
  $permissions['edit own field_course_theme'] = array(
    'name' => 'edit own field_course_theme',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_course_type_of_teaching'.
  $permissions['edit own field_course_type_of_teaching'] = array(
    'name' => 'edit own field_course_type_of_teaching',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_evaluation'.
  $permissions['edit own field_evaluation'] = array(
    'name' => 'edit own field_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_feedback_description'.
  $permissions['edit own field_feedback_description'] = array(
    'name' => 'edit own field_feedback_description',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_feedback_link'.
  $permissions['edit own field_feedback_link'] = array(
    'name' => 'edit own field_feedback_link',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_administrator_number'.
  $permissions['edit own field_imp_administrator_number'] = array(
    'name' => 'edit own field_imp_administrator_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_begin_date'.
  $permissions['edit own field_imp_begin_date'] = array(
    'name' => 'edit own field_imp_begin_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_canonical_url'.
  $permissions['edit own field_imp_canonical_url'] = array(
    'name' => 'edit own field_imp_canonical_url',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_course_organiser'.
  $permissions['edit own field_imp_course_organiser'] = array(
    'name' => 'edit own field_imp_course_organiser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_end_date'.
  $permissions['edit own field_imp_end_date'] = array(
    'name' => 'edit own field_imp_end_date',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_fee'.
  $permissions['edit own field_imp_fee'] = array(
    'name' => 'edit own field_imp_fee',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_giver_locality'.
  $permissions['edit own field_imp_giver_locality'] = array(
    'name' => 'edit own field_imp_giver_locality',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_header_headline'.
  $permissions['edit own field_imp_header_headline'] = array(
    'name' => 'edit own field_imp_header_headline',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_header_image'.
  $permissions['edit own field_imp_header_image'] = array(
    'name' => 'edit own field_imp_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_header_image_caption'.
  $permissions['edit own field_imp_header_image_caption'] = array(
    'name' => 'edit own field_imp_header_image_caption',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_header_text'.
  $permissions['edit own field_imp_header_text'] = array(
    'name' => 'edit own field_imp_header_text',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_id'.
  $permissions['edit own field_imp_id'] = array(
    'name' => 'edit own field_imp_id',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_interaction_link'.
  $permissions['edit own field_imp_interaction_link'] = array(
    'name' => 'edit own field_imp_interaction_link',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_interactiondescription'.
  $permissions['edit own field_imp_interactiondescription'] = array(
    'name' => 'edit own field_imp_interactiondescription',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_keywords'.
  $permissions['edit own field_imp_keywords'] = array(
    'name' => 'edit own field_imp_keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_locality'.
  $permissions['edit own field_imp_locality'] = array(
    'name' => 'edit own field_imp_locality',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_method_of_study'.
  $permissions['edit own field_imp_method_of_study'] = array(
    'name' => 'edit own field_imp_method_of_study',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_organisation'.
  $permissions['edit own field_imp_organisation'] = array(
    'name' => 'edit own field_imp_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_reference_to_courses'.
  $permissions['edit own field_imp_reference_to_courses'] = array(
    'name' => 'edit own field_imp_reference_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_start_month'.
  $permissions['edit own field_imp_start_month'] = array(
    'name' => 'edit own field_imp_start_month',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_teacher'.
  $permissions['edit own field_imp_teacher'] = array(
    'name' => 'edit own field_imp_teacher',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_teacher_number'.
  $permissions['edit own field_imp_teacher_number'] = array(
    'name' => 'edit own field_imp_teacher_number',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_teachersection'.
  $permissions['edit own field_imp_teachersection'] = array(
    'name' => 'edit own field_imp_teachersection',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_imp_teaching_language'.
  $permissions['edit own field_imp_teaching_language'] = array(
    'name' => 'edit own field_imp_teaching_language',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_material_file'.
  $permissions['edit own field_material_file'] = array(
    'name' => 'edit own field_material_file',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_objective'.
  $permissions['edit own field_objective'] = array(
    'name' => 'edit own field_objective',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_open_uni_registration'.
  $permissions['edit own field_open_uni_registration'] = array(
    'name' => 'edit own field_open_uni_registration',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_rel_to_other_study_units'.
  $permissions['edit own field_rel_to_other_study_units'] = array(
    'name' => 'edit own field_rel_to_other_study_units',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_req_prerequisites'.
  $permissions['edit own field_req_prerequisites'] = array(
    'name' => 'edit own field_req_prerequisites',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_responsible_person'.
  $permissions['edit own field_responsible_person'] = array(
    'name' => 'edit own field_responsible_person',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_study_credit'.
  $permissions['edit own field_study_credit'] = array(
    'name' => 'edit own field_study_credit',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_study_materials'.
  $permissions['edit own field_study_materials'] = array(
    'name' => 'edit own field_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_study_module'.
  $permissions['edit own field_study_module'] = array(
    'name' => 'edit own field_study_module',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_study_module_title'.
  $permissions['edit own field_study_module_title'] = array(
    'name' => 'edit own field_study_module_title',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_subject_ref_to_courses'.
  $permissions['edit own field_subject_ref_to_courses'] = array(
    'name' => 'edit own field_subject_ref_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_target_group'.
  $permissions['edit own field_target_group'] = array(
    'name' => 'edit own field_target_group',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_timing'.
  $permissions['edit own field_timing'] = array(
    'name' => 'edit own field_timing',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own field_working_methods'.
  $permissions['edit own field_working_methods'] = array(
    'name' => 'edit own field_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'edit own liftup content'.
  $permissions['edit own liftup content'] = array(
    'name' => 'edit own liftup content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own subject content'.
  $permissions['edit own subject content'] = array(
    'name' => 'edit own subject content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit terms in course_theme'.
  $permissions['edit terms in course_theme'] = array(
    'name' => 'edit terms in course_theme',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in faculty'.
  $permissions['edit terms in faculty'] = array(
    'name' => 'edit terms in faculty',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'edit terms in months'.
  $permissions['edit terms in months'] = array(
    'name' => 'edit terms in months',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'taxonomy',
  );

  // Exported permission: 'flag generate_activity_message'.
  $permissions['flag generate_activity_message'] = array(
    'name' => 'flag generate_activity_message',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'override course_implementation published option'.
  $permissions['override course_implementation published option'] = array(
    'name' => 'override course_implementation published option',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override portal_page promote to front page option'.
  $permissions['override portal_page promote to front page option'] = array(
    'name' => 'override portal_page promote to front page option',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'translate interface'.
  $permissions['translate interface'] = array(
    'name' => 'translate interface',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'locale',
  );

  // Exported permission: 'translate node entities'.
  $permissions['translate node entities'] = array(
    'name' => 'translate node entities',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'entity_translation',
  );

  // Exported permission: 'unflag generate_activity_message'.
  $permissions['unflag generate_activity_message'] = array(
    'name' => 'unflag generate_activity_message',
    'roles' => array(
      'administrator' => 'administrator',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'flag',
  );

  // Exported permission: 'use search_api_autocomplete for search_api_views_uhc_search_open_university'.
  $permissions['use search_api_autocomplete for search_api_views_uhc_search_open_university'] = array(
    'name' => 'use search_api_autocomplete for search_api_views_uhc_search_open_university',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'search_api_autocomplete',
  );

  // Exported permission: 'view any unpublished course_implementation content'.
  $permissions['view any unpublished course_implementation content'] = array(
    'name' => 'view any unpublished course_implementation content',
    'roles' => array(
      'administrator' => 'administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished subject content'.
  $permissions['view any unpublished subject content'] = array(
    'name' => 'view any unpublished subject content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view field_additional_info'.
  $permissions['view field_additional_info'] = array(
    'name' => 'view field_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_cancelled'.
  $permissions['view field_cancelled'] = array(
    'name' => 'view field_cancelled',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_conduct'.
  $permissions['view field_conduct'] = array(
    'name' => 'view field_conduct',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_contents'.
  $permissions['view field_contents'] = array(
    'name' => 'view field_contents',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_course_number'.
  $permissions['view field_course_course_number'] = array(
    'name' => 'view field_course_course_number',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_course_tags'.
  $permissions['view field_course_course_tags'] = array(
    'name' => 'view field_course_course_tags',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_faculty'.
  $permissions['view field_course_faculty'] = array(
    'name' => 'view field_course_faculty',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_subject'.
  $permissions['view field_course_subject'] = array(
    'name' => 'view field_course_subject',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_theme'.
  $permissions['view field_course_theme'] = array(
    'name' => 'view field_course_theme',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_course_type_of_teaching'.
  $permissions['view field_course_type_of_teaching'] = array(
    'name' => 'view field_course_type_of_teaching',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_evaluation'.
  $permissions['view field_evaluation'] = array(
    'name' => 'view field_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_feedback_description'.
  $permissions['view field_feedback_description'] = array(
    'name' => 'view field_feedback_description',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_feedback_link'.
  $permissions['view field_feedback_link'] = array(
    'name' => 'view field_feedback_link',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_administrator_number'.
  $permissions['view field_imp_administrator_number'] = array(
    'name' => 'view field_imp_administrator_number',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_begin_date'.
  $permissions['view field_imp_begin_date'] = array(
    'name' => 'view field_imp_begin_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_canonical_url'.
  $permissions['view field_imp_canonical_url'] = array(
    'name' => 'view field_imp_canonical_url',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_course_organiser'.
  $permissions['view field_imp_course_organiser'] = array(
    'name' => 'view field_imp_course_organiser',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_end_date'.
  $permissions['view field_imp_end_date'] = array(
    'name' => 'view field_imp_end_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_fee'.
  $permissions['view field_imp_fee'] = array(
    'name' => 'view field_imp_fee',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_giver_locality'.
  $permissions['view field_imp_giver_locality'] = array(
    'name' => 'view field_imp_giver_locality',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_header_headline'.
  $permissions['view field_imp_header_headline'] = array(
    'name' => 'view field_imp_header_headline',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_header_image'.
  $permissions['view field_imp_header_image'] = array(
    'name' => 'view field_imp_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_header_image_caption'.
  $permissions['view field_imp_header_image_caption'] = array(
    'name' => 'view field_imp_header_image_caption',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_header_text'.
  $permissions['view field_imp_header_text'] = array(
    'name' => 'view field_imp_header_text',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_id'.
  $permissions['view field_imp_id'] = array(
    'name' => 'view field_imp_id',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_interaction_link'.
  $permissions['view field_imp_interaction_link'] = array(
    'name' => 'view field_imp_interaction_link',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_interactiondescription'.
  $permissions['view field_imp_interactiondescription'] = array(
    'name' => 'view field_imp_interactiondescription',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_keywords'.
  $permissions['view field_imp_keywords'] = array(
    'name' => 'view field_imp_keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_locality'.
  $permissions['view field_imp_locality'] = array(
    'name' => 'view field_imp_locality',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_method_of_study'.
  $permissions['view field_imp_method_of_study'] = array(
    'name' => 'view field_imp_method_of_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_organisation'.
  $permissions['view field_imp_organisation'] = array(
    'name' => 'view field_imp_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_reference_to_courses'.
  $permissions['view field_imp_reference_to_courses'] = array(
    'name' => 'view field_imp_reference_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_start_month'.
  $permissions['view field_imp_start_month'] = array(
    'name' => 'view field_imp_start_month',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_teacher'.
  $permissions['view field_imp_teacher'] = array(
    'name' => 'view field_imp_teacher',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_teacher_number'.
  $permissions['view field_imp_teacher_number'] = array(
    'name' => 'view field_imp_teacher_number',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_teachersection'.
  $permissions['view field_imp_teachersection'] = array(
    'name' => 'view field_imp_teachersection',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_imp_teaching_language'.
  $permissions['view field_imp_teaching_language'] = array(
    'name' => 'view field_imp_teaching_language',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_material_file'.
  $permissions['view field_material_file'] = array(
    'name' => 'view field_material_file',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_objective'.
  $permissions['view field_objective'] = array(
    'name' => 'view field_objective',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_open_uni_registration'.
  $permissions['view field_open_uni_registration'] = array(
    'name' => 'view field_open_uni_registration',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_rel_to_other_study_units'.
  $permissions['view field_rel_to_other_study_units'] = array(
    'name' => 'view field_rel_to_other_study_units',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_req_prerequisites'.
  $permissions['view field_req_prerequisites'] = array(
    'name' => 'view field_req_prerequisites',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_responsible_person'.
  $permissions['view field_responsible_person'] = array(
    'name' => 'view field_responsible_person',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_study_credit'.
  $permissions['view field_study_credit'] = array(
    'name' => 'view field_study_credit',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_study_materials'.
  $permissions['view field_study_materials'] = array(
    'name' => 'view field_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_study_module'.
  $permissions['view field_study_module'] = array(
    'name' => 'view field_study_module',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_study_module_title'.
  $permissions['view field_study_module_title'] = array(
    'name' => 'view field_study_module_title',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_subject_ref_to_courses'.
  $permissions['view field_subject_ref_to_courses'] = array(
    'name' => 'view field_subject_ref_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_target_group'.
  $permissions['view field_target_group'] = array(
    'name' => 'view field_target_group',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_timing'.
  $permissions['view field_timing'] = array(
    'name' => 'view field_timing',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view field_working_methods'.
  $permissions['view field_working_methods'] = array(
    'name' => 'view field_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_additional_info'.
  $permissions['view own field_additional_info'] = array(
    'name' => 'view own field_additional_info',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_cancelled'.
  $permissions['view own field_cancelled'] = array(
    'name' => 'view own field_cancelled',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_conduct'.
  $permissions['view own field_conduct'] = array(
    'name' => 'view own field_conduct',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_contents'.
  $permissions['view own field_contents'] = array(
    'name' => 'view own field_contents',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_course_number'.
  $permissions['view own field_course_course_number'] = array(
    'name' => 'view own field_course_course_number',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_course_tags'.
  $permissions['view own field_course_course_tags'] = array(
    'name' => 'view own field_course_course_tags',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_faculty'.
  $permissions['view own field_course_faculty'] = array(
    'name' => 'view own field_course_faculty',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_subject'.
  $permissions['view own field_course_subject'] = array(
    'name' => 'view own field_course_subject',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_theme'.
  $permissions['view own field_course_theme'] = array(
    'name' => 'view own field_course_theme',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_course_type_of_teaching'.
  $permissions['view own field_course_type_of_teaching'] = array(
    'name' => 'view own field_course_type_of_teaching',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_evaluation'.
  $permissions['view own field_evaluation'] = array(
    'name' => 'view own field_evaluation',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_feedback_description'.
  $permissions['view own field_feedback_description'] = array(
    'name' => 'view own field_feedback_description',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'course administrator' => 'course administrator',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'teacher' => 'teacher',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_feedback_link'.
  $permissions['view own field_feedback_link'] = array(
    'name' => 'view own field_feedback_link',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_administrator_number'.
  $permissions['view own field_imp_administrator_number'] = array(
    'name' => 'view own field_imp_administrator_number',
    'roles' => array(
      'administrator' => 'administrator',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_begin_date'.
  $permissions['view own field_imp_begin_date'] = array(
    'name' => 'view own field_imp_begin_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_canonical_url'.
  $permissions['view own field_imp_canonical_url'] = array(
    'name' => 'view own field_imp_canonical_url',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_course_organiser'.
  $permissions['view own field_imp_course_organiser'] = array(
    'name' => 'view own field_imp_course_organiser',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_end_date'.
  $permissions['view own field_imp_end_date'] = array(
    'name' => 'view own field_imp_end_date',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_fee'.
  $permissions['view own field_imp_fee'] = array(
    'name' => 'view own field_imp_fee',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_giver_locality'.
  $permissions['view own field_imp_giver_locality'] = array(
    'name' => 'view own field_imp_giver_locality',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_header_headline'.
  $permissions['view own field_imp_header_headline'] = array(
    'name' => 'view own field_imp_header_headline',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_header_image'.
  $permissions['view own field_imp_header_image'] = array(
    'name' => 'view own field_imp_header_image',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_header_image_caption'.
  $permissions['view own field_imp_header_image_caption'] = array(
    'name' => 'view own field_imp_header_image_caption',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_header_text'.
  $permissions['view own field_imp_header_text'] = array(
    'name' => 'view own field_imp_header_text',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_id'.
  $permissions['view own field_imp_id'] = array(
    'name' => 'view own field_imp_id',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_interaction_link'.
  $permissions['view own field_imp_interaction_link'] = array(
    'name' => 'view own field_imp_interaction_link',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_interactiondescription'.
  $permissions['view own field_imp_interactiondescription'] = array(
    'name' => 'view own field_imp_interactiondescription',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_keywords'.
  $permissions['view own field_imp_keywords'] = array(
    'name' => 'view own field_imp_keywords',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_locality'.
  $permissions['view own field_imp_locality'] = array(
    'name' => 'view own field_imp_locality',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_method_of_study'.
  $permissions['view own field_imp_method_of_study'] = array(
    'name' => 'view own field_imp_method_of_study',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_organisation'.
  $permissions['view own field_imp_organisation'] = array(
    'name' => 'view own field_imp_organisation',
    'roles' => array(
      'administrator' => 'administrator',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_reference_to_courses'.
  $permissions['view own field_imp_reference_to_courses'] = array(
    'name' => 'view own field_imp_reference_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_start_month'.
  $permissions['view own field_imp_start_month'] = array(
    'name' => 'view own field_imp_start_month',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_teacher'.
  $permissions['view own field_imp_teacher'] = array(
    'name' => 'view own field_imp_teacher',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_teacher_number'.
  $permissions['view own field_imp_teacher_number'] = array(
    'name' => 'view own field_imp_teacher_number',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_teachersection'.
  $permissions['view own field_imp_teachersection'] = array(
    'name' => 'view own field_imp_teachersection',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_imp_teaching_language'.
  $permissions['view own field_imp_teaching_language'] = array(
    'name' => 'view own field_imp_teaching_language',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_material_file'.
  $permissions['view own field_material_file'] = array(
    'name' => 'view own field_material_file',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_objective'.
  $permissions['view own field_objective'] = array(
    'name' => 'view own field_objective',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_open_uni_registration'.
  $permissions['view own field_open_uni_registration'] = array(
    'name' => 'view own field_open_uni_registration',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_rel_to_other_study_units'.
  $permissions['view own field_rel_to_other_study_units'] = array(
    'name' => 'view own field_rel_to_other_study_units',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_req_prerequisites'.
  $permissions['view own field_req_prerequisites'] = array(
    'name' => 'view own field_req_prerequisites',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_responsible_person'.
  $permissions['view own field_responsible_person'] = array(
    'name' => 'view own field_responsible_person',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_study_credit'.
  $permissions['view own field_study_credit'] = array(
    'name' => 'view own field_study_credit',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_study_materials'.
  $permissions['view own field_study_materials'] = array(
    'name' => 'view own field_study_materials',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_study_module'.
  $permissions['view own field_study_module'] = array(
    'name' => 'view own field_study_module',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_study_module_title'.
  $permissions['view own field_study_module_title'] = array(
    'name' => 'view own field_study_module_title',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_subject_ref_to_courses'.
  $permissions['view own field_subject_ref_to_courses'] = array(
    'name' => 'view own field_subject_ref_to_courses',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_target_group'.
  $permissions['view own field_target_group'] = array(
    'name' => 'view own field_target_group',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_timing'.
  $permissions['view own field_timing'] = array(
    'name' => 'view own field_timing',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view own field_working_methods'.
  $permissions['view own field_working_methods'] = array(
    'name' => 'view own field_working_methods',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'field_permissions',
  );

  // Exported permission: 'view title_and_credit_linked on node'.
  $permissions['view title_and_credit_linked on node'] = array(
    'name' => 'view title_and_credit_linked on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_course_hierarchy on node'.
  $permissions['view uhc_ds_course_hierarchy on node'] = array(
    'name' => 'view uhc_ds_course_hierarchy on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_course_reference_accordion on node'.
  $permissions['view uhc_ds_course_reference_accordion on node'] = array(
    'name' => 'view uhc_ds_course_reference_accordion on node',
    'roles' => array(
      'administrator' => 'administrator',
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
      'teacher' => 'teacher',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_enrollment_period on node'.
  $permissions['view uhc_ds_enrollment_period on node'] = array(
    'name' => 'view uhc_ds_enrollment_period on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_fee on node'.
  $permissions['view uhc_ds_fee on node'] = array(
    'name' => 'view uhc_ds_fee on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_finna_link on node'.
  $permissions['view uhc_ds_finna_link on node'] = array(
    'name' => 'view uhc_ds_finna_link on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_imp_status_org_location_date on node'.
  $permissions['view uhc_ds_imp_status_org_location_date on node'] = array(
    'name' => 'view uhc_ds_imp_status_org_location_date on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_moodle_key_or_login on node'.
  $permissions['view uhc_ds_moodle_key_or_login on node'] = array(
    'name' => 'view uhc_ds_moodle_key_or_login on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_open_uni_registration on node'.
  $permissions['view uhc_ds_open_uni_registration on node'] = array(
    'name' => 'view uhc_ds_open_uni_registration on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_rel_to_other_study_units on node'.
  $permissions['view uhc_ds_rel_to_other_study_units on node'] = array(
    'name' => 'view uhc_ds_rel_to_other_study_units on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_responsible_person on node'.
  $permissions['view uhc_ds_responsible_person on node'] = array(
    'name' => 'view uhc_ds_responsible_person on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_table_of_contents on node'.
  $permissions['view uhc_ds_table_of_contents on node'] = array(
    'name' => 'view uhc_ds_table_of_contents on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_timing on node'.
  $permissions['view uhc_ds_timing on node'] = array(
    'name' => 'view uhc_ds_timing on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_title_and_credit on node'.
  $permissions['view uhc_ds_title_and_credit on node'] = array(
    'name' => 'view uhc_ds_title_and_credit on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  // Exported permission: 'view uhc_ds_working_methods on node'.
  $permissions['view uhc_ds_working_methods on node'] = array(
    'name' => 'view uhc_ds_working_methods on node',
    'roles' => array(
      'anonymous user' => 'anonymous user',
      'authenticated user' => 'authenticated user',
    ),
    'module' => 'ds_extras',
  );

  return $permissions;
}
