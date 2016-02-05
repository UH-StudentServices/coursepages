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
  $field_group->identifier = 'group_content_collections|node|portal_page|form';
  $field_group->group_name = 'group_content_collections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content collections',
    'weight' => '3',
    'children' => array(
      0 => 'field_content_collection',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-content-collections field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_content_collections|node|portal_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_liftup_collections|node|portal_page|form';
  $field_group->group_name = 'group_liftup_collections';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Liftup collections',
    'weight' => '2',
    'children' => array(
      0 => 'field_liftup_collection',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Liftup collections',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-liftup-collections field-group-tab',
        'description' => 'Each liftup collection consists of a title, description and an unlimited number of Portal page Liftups. Liftup collections are shown only when Sidebar view mode is chosen.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_liftup_collections|node|portal_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_liftup_colletion_header|field_collection_item|field_liftup_collection|default';
  $field_group->group_name = 'group_liftup_colletion_header';
  $field_group->entity_type = 'field_collection_item';
  $field_group->bundle = 'field_liftup_collection';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Header',
    'weight' => '0',
    'children' => array(
      0 => 'title_field',
      1 => 'field_intro',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Header',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'tube--large',
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
  $export['group_liftup_colletion_header|field_collection_item|field_liftup_collection|default'] = $field_group;

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
    'weight' => '7',
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
  $field_group->identifier = 'group_portal_content|node|portal_page|form';
  $field_group->group_name = 'group_portal_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_portal_page_description',
      1 => 'title_field',
      2 => 'field_portal_page_image',
      3 => 'field_liftup_section',
      4 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-portal-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $export['group_portal_content|node|portal_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_portal_page_promotion|node|portal_page|default';
  $field_group->group_name = 'group_portal_page_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Portal promotion',
    'weight' => '1',
    'children' => array(
      0 => 'field_portal_promotions',
      1 => 'field_portal_promotions_link',
      2 => 'field_portal_promotions_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Portal promotion',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_portal_page_promotion|node|portal_page|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_portal_page_promotion|node|portal_page|search_block_embedded';
  $field_group->group_name = 'group_portal_page_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'search_block_embedded';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Portal promotion',
    'weight' => '2',
    'children' => array(
      0 => 'field_portal_promotions',
      1 => 'field_portal_promotions_link',
      2 => 'field_portal_promotions_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Portal promotion',
      'instance_settings' => array(
        'id' => '',
        'classes' => '',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_portal_page_promotion|node|portal_page|search_block_embedded'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_portal_page_promotion|node|portal_page|sidebar';
  $field_group->group_name = 'group_portal_page_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'sidebar';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Portal promotion',
    'weight' => '8',
    'children' => array(
      0 => 'field_portal_promotions',
      1 => 'field_portal_promotions_link',
      2 => 'field_portal_promotions_title',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Portal promotion',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'regional-rule-top portal-promotions',
        'description' => '',
        'show_label' => '0',
        'label_element' => 'h3',
        'effect' => 'none',
        'speed' => 'fast',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'open',
    ),
  );
  $export['group_portal_page_promotion|node|portal_page|sidebar'] = $field_group;

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
    'weight' => '1',
    'children' => array(
      0 => 'field_portal_promotions',
      1 => 'field_view_attachment',
      2 => 'field_portal_promotions_title',
      3 => 'field_portal_promotions_link',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Promoted content',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-portal-promotions field-group-tab',
        'description' => 'Portal promotions are shown on both Default and Sidebar view modes. Online Service Promotions and Portal Pages can be selected.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
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
    'weight' => '5',
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

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_portal_sidebar_liftups|node|portal_page|form';
  $field_group->group_name = 'group_portal_sidebar_liftups';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'portal_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Sidebar liftups',
    'weight' => '6',
    'children' => array(
      0 => 'field_sidebar_liftups',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'label' => 'Sidebar liftups',
      'instance_settings' => array(
        'required_fields' => 1,
        'classes' => 'group-portal-sidebar-liftups field-group-tab',
        'description' => 'Sidebar liftups are only visible if the sidebar view mode is selected in Display settings.',
        'show_empty_fields' => 0,
      ),
      'formatter' => 'closed',
    ),
  );
  $export['group_portal_sidebar_liftups|node|portal_page|form'] = $field_group;

  return $export;
}
