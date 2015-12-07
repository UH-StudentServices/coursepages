<?php
/**
 * @file
 * uhc_course_collaboration_private.features.field_instance.inc
 */

/**
 * Implements hook_field_default_field_instances().
 */
function uhc_course_collaboration_private_field_default_field_instances() {
  $field_instances = array();

  // Exported field_instance: 'comment-comment_node_course_implementation-field_private'
  $field_instances['comment-comment_node_course_implementation-field_private'] = array(
    'bundle' => 'comment_node_course_implementation',
    'default_value' => array(
      0 => array(
        'value' => 0,
      ),
    ),
    'deleted' => 0,
    'description' => '',
    'display' => array(
      'default' => array(
        'label' => 'above',
        'module' => 'list',
        'settings' => array(
          'field_multiple_limit' => -1,
          'field_multiple_limit_offset' => 0,
        ),
        'type' => 'list_default',
        'weight' => 3,
      ),
      'full' => array(
        'label' => 'above',
        'settings' => array(),
        'type' => 'hidden',
        'weight' => 0,
      ),
    ),
    'ds_extras_field_template' => '',
    'entity_type' => 'comment',
    'field_name' => 'field_private',
    'label' => 'Restricted to course’s participants only',
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
      'weight' => 1,
    ),
  );

  // Translatables
  // Included for use with string extractors like potx.
  t('Restricted to course’s participants only');

  return $field_instances;
}
