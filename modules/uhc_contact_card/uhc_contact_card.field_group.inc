<?php
/**
 * @file
 * uhc_contact_card.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_contact_card_field_group_info() {
  $export = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_contact_card_content|node|contact_card|default';
  $field_group->group_name = 'group_contact_card_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'contact_card';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '1',
    'children' => array(
      0 => 'field_contact_email',
      1 => 'field_contact_link',
      2 => 'field_contact_phone',
      3 => 'field_contant_name',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Content',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'box-subsection__content',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'none',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_contact_card_content|node|contact_card|default'] = $field_group;

  return $export;
}
