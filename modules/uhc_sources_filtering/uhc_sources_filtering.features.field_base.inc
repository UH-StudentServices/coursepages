<?php
/**
 * @file
 * uhc_sources_filtering.features.field_base.inc
 */

/**
 * Implements hook_field_default_field_bases().
 */
function uhc_sources_filtering_field_default_field_bases() {
  $field_bases = array();

  // Exported field_base: 'field_migrate_allow'.
  $field_bases['field_migrate_allow'] = array(
    'active' => 1,
    'cardinality' => 1,
    'deleted' => 0,
    'entity_types' => array(),
    'field_name' => 'field_migrate_allow',
    'field_permissions' => array(
      'type' => 0,
    ),
    'indexes' => array(
      'value' => array(
        0 => 'value',
      ),
    ),
    'locked' => 0,
    'module' => 'list',
    'settings' => array(
      'allowed_values' => array(
        0 => '',
        1 => '',
      ),
      'allowed_values_function' => '',
      'entity_translation_sync' => FALSE,
    ),
    'translatable' => 0,
    'type' => 'list_boolean',
  );

  return $field_bases;
}
