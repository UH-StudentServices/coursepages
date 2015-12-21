<?php
/**
 * @file
 * uhc_sources_filtering.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function uhc_sources_filtering_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'taxonomy_term-organisations_of_university_of_helsinki-field_migrate_allow'
  $field_instances['taxonomy_term-organisations_of_university_of_helsinki-field_migrate_allow'] = array(
    'bundle' => 'organisations_of_university_of_helsinki',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => 'Check this if you want this organisation\'s (and its children) course unit realisations to be imported.',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'list_default',
        'weight' => 4,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'taxonomy_term',
    'field_name' => 'field_migrate_allow',
    'label' => 'Allow on migration',
    'required' => 0,
    'settings' => array(
      'entity_translation_sync' => FALSE,
      'user_register_form' => FALSE,
    ),
    'widget' => array(
      'active' => 1,
      'module' => 'options',
      'settings' => array(
        'display_label' => 1,
      ),
      'type' => 'options_onoff',
      'weight' => 31,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Allow on migration');
  t('Check this if you want this organisation\'s (and its children) course unit realisations to be imported.');

  return $field_instances;
}
