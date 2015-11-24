<?php
/**
 * @file
 * uhc_page.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_page_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_portal_contact_information|node|portal_page|form';
  $field_group->group_name = 'group_portal_contact_information';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact Information',
    'weight' => '11',
    'children' => array(
      0 => 'field_subject_contact_reference',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Contact Information',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-portal-contact-information field-group-tab',
        'description' => 'Contact information is only visible if the sidebar view mode is selected in Display settings.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_portal_contact_information|node|portal_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_portal_promotions|node|portal_page|form';
  $field_group->group_name = 'group_portal_promotions';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promoted content',
    'weight' => '4',
    'children' => array(
      0 => 'field_portal_promotions',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-portal-promotions field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_portal_promotions|node|portal_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_portal_related_content|node|portal_page|form';
  $field_group->group_name = 'group_portal_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '9',
    'children' => array(
      0 => 'field_related_content_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Related content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-portal-related-content field-group-tab',
        'description' => 'Related content is only visible if the sidebar view mode is selected in Display settings.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_portal_related_content|node|portal_page|form'] = $field_group;

  return $export;
}
