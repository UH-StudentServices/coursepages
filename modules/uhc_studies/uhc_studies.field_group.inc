<?php
/**
 * @file
 * uhc_studies.field_group.inc
 */

/**
 * Implements hook_field_group_info().
 */
function uhc_studies_field_group_info() {
  $field_groups = array();

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_header_promotion|node|studies|form';
  $field_group->group_name = 'group_header_promotion';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Promotion',
    'weight' => '3',
    'children' => array(
      0 => 'field_studies_description',
      1 => 'field_studies_image',
      2 => 'title_field',
      3 => 'field_subject_category',
      4 => 'field_stuides_is_degree_programm',
      5 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-header-promotion field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_header_promotion|node|studies|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_studies_banner|node|studies|default';
  $field_group->group_name = 'group_studies_banner';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies';
  $field_group->mode = 'default';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Banner',
    'weight' => '0',
    'children' => array(
      0 => 'field_studies_description',
      1 => 'field_studies_image',
    ),
    'format_type' => 'div',
    'format_settings' => array(
      'label' => 'Banner',
      'instance_settings' => array(
        'id' => '',
        'classes' => 'ds-node-banner',
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
  $field_groups['group_studies_banner|node|studies|default'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_studies_contact_cards|node|studies|form';
  $field_group->group_name = 'group_studies_contact_cards';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Contact cards',
    'weight' => '8',
    'children' => array(
      0 => 'field_studies_contact_card',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-studies-contact-cards field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_studies_contact_cards|node|studies|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_studies_liftups|node|studies|form';
  $field_group->group_name = 'group_studies_liftups';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Liftups',
    'weight' => '6',
    'children' => array(
      0 => 'field_studies_sidebar_liftups',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-studies-liftups field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_studies_liftups|node|studies|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_studies_lp_content|node|studies_landing_page|form';
  $field_group->group_name = 'group_studies_lp_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies_landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Content',
    'weight' => '0',
    'children' => array(
      0 => 'field_studies_lp_description',
      1 => 'field_studies_lp_image',
      2 => 'field_studies_lp_view_attachment',
      3 => 'title_field',
      4 => 'language',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_studies_lp_content|node|studies_landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_studies_lp_related_content|node|studies_landing_page|form';
  $field_group->group_name = 'group_studies_lp_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies_landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Related content',
    'weight' => '2',
    'children' => array(
      0 => 'field_related_content_section',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-studies-lp-related-content field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_studies_lp_related_content|node|studies_landing_page|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_studies_related_content|node|studies|form';
  $field_group->group_name = 'group_studies_related_content';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies';
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
        'classes' => '',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_studies_related_content|node|studies|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_study_modules|node|studies|form';
  $field_group->group_name = 'group_study_modules';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Study modules',
    'weight' => '4',
    'children' => array(
      0 => 'field_studies_study_modules_desc',
      1 => 'field_studies_study_modules_titl',
      2 => 'field_study_module',
      3 => 'field_study_module_filters',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-study-modules field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_study_modules|node|studies|form'] = $field_group;

  $field_group = new stdClass();
  $field_group->disabled = FALSE; /* Edit this to true to make a default field_group disabled initially */
  $field_group->api_version = 1;
  $field_group->identifier = 'group_summer_courses|node|studies_landing_page|form';
  $field_group->group_name = 'group_summer_courses';
  $field_group->entity_type = 'node';
  $field_group->bundle = 'studies_landing_page';
  $field_group->mode = 'form';
  $field_group->parent_name = '';
  $field_group->data = array(
    'label' => 'Summer courses',
    'weight' => '1',
    'children' => array(
      0 => 'field_studies_lp_summer_view',
      1 => 'field_summer_courses_title',
      2 => 'field_summer_courses_description',
    ),
    'format_type' => 'tab',
    'format_settings' => array(
      'formatter' => 'closed',
      'instance_settings' => array(
        'description' => '',
        'classes' => 'group-summer-courses field-group-tab',
        'required_fields' => 1,
      ),
    ),
  );
  $field_groups['group_summer_courses|node|studies_landing_page|form'] = $field_group;

  // Translatables
  // Included for use with string extractors like potx.
  t('Banner');
  t('Contact cards');
  t('Content');
  t('Liftups');
  t('Promotion');
  t('Related content');
  t('Study modules');
  t('Summer courses');

  return $field_groups;
}
