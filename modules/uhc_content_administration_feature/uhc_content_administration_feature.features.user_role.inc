<?php
/**
 * @file
 * uhc_content_administration_feature.features.user_role.inc
 */

/**
 * Implements hook_user_default_roles().
 */
function uhc_content_administration_feature_user_default_roles() {
  $roles = array();

  // Exported role: Moodle integrator.
  $roles['Moodle integrator'] = array(
    'name' => 'Moodle integrator',
    'weight' => 6,
  );

  return $roles;
}
