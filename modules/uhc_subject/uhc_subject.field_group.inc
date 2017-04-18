<?php
/**
 * @file
 * uhc_subject.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_subject_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_information|node|subject|form';
  $field_group->group_name = 'group_contact_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subject';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact information',
    'weight' => '7',
    'children' => array(
      0 => 'field_subject_contact_reference',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-contact-information field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_contact_information|node|subject|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header_promotion|node|subject|form';
  $field_group->group_name = 'group_header_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subject';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promotion',
    'weight' => '3',
    'children' => array(
      0 => 'field_imp_header_headline',
      1 => 'field_subject_description',
      2 => 'field_subject_image',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-promotion field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_header_promotion|node|subject|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_liftups|node|subject|form';
  $field_group->group_name = 'group_liftups';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subject';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Liftups',
    'weight' => '6',
    'children' => array(
      0 => 'field_sidebar_liftups',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-liftups field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_liftups|node|subject|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_related_content|node|subject|form';
  $field_group->group_name = 'group_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subject';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '5',
    'children' => array(
      0 => 'field_related_content_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-related-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_related_content|node|subject|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_modules|node|subject|form';
  $field_group->group_name = 'group_study_modules';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'subject';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Study modules',
    'weight' => '4',
    'children' => array(
      0 => 'field_study_modules_description',
      1 => 'field_study_modules_title',
      2 => 'field_study_module',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Study modules',
      'instance_settings' => array(
        'required_fields' => 0,
        'classes' => 'group-study-modules field-group-tab',
        'description' => '',
      ),
      'formatter' => 'closed',
    ),
  );
  $field_groups['group_study_modules|node|subject|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Contact information');
  t('Liftups');
  t('Promotion');
  t('Related content');
  t('Study modules');

  return $field_groups;
}
