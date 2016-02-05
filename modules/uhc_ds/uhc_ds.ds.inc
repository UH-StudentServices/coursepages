<?php
/**
 * @file
 * uhc_ds.ds.inc
 */

/**
 * Implements hook_ds_field_settings_info().
 */
function uhc_ds_ds_field_settings_info() {
  $export = array();

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_course_implementation|default';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_course_implementation';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'comment_post_date' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'links' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'ds_picture_image_100pxauto',
      'formatter_settings' => array(
        'ft' => array(
          'lbw' => 1,
        ),
      ),
    ),
    'comment_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field field-name-comment-body body-text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_private' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['comment|comment_node_course_implementation|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'comment|comment_node_course_implementation|full';
  $ds_fieldsetting->entity_type = 'comment';
  $ds_fieldsetting->bundle = 'comment_node_course_implementation';
  $ds_fieldsetting->view_mode = 'full';
  $ds_fieldsetting->settings = array(
    'message_header' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'message-header',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'links' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'ds_user_picture' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'ds_picture_profile_picture',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'user-picture',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'comment_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'field field-name-comment-body body-text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['comment|comment_node_course_implementation|full'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_content_collection|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_content_collection';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_body' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'body-text body-text--small',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_content_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'tube',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_link_multiple' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'list-of-links--light tube--large columns-2',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_related_content' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'list-of-links--dark tube',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'a',
          'fis-cl' => '',
          'fis-at' => 'name=\'[field_collection_item:title_field]\'',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_related_content_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_content_collection|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_imp_attached_material_sec|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_imp_attached_material_sec';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_section_label' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'label',
          'fi-cl' => 'accordion-content--label',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_section_material' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'material-block--container',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
  );
  $export['field_collection_item|field_imp_attached_material_sec|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_imp_teachersection|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_imp_teachersection';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_imp_teachersection_content' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
    'field_imp_teachersection_label' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<a href="#">',
          'suffix' => '</a>',
        ),
      ),
    ),
  );
  $export['field_collection_item|field_imp_teachersection|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_liftup_collection|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_liftup_collection';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'is-center',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_intro' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'p',
          'fi-cl' => 'is-center intro-text',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_promotions' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'gridder-container-4 clearfix',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'gridder-box',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['field_collection_item|field_liftup_collection|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_related_content_section|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_related_content_section';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_related_content' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'list-of-links--dark',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['field_collection_item|field_related_content_section|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'field_collection_item|field_study_module|default';
  $ds_fieldsetting->entity_type = 'field_collection_item';
  $ds_fieldsetting->bundle = 'field_study_module';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_study_module_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'accordion-item-title',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_subject_ref_to_courses' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'none',
        ),
      ),
    ),
    'field_subject_ref_study_module' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-item-title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['field_collection_item|field_study_module|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|contact_card|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'contact_card';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => '',
        'class' => '',
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'contact-title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_contact_email' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'contact-mail',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_contact_phone' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'tel.',
          'lb-el' => 'span',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'contact-tel',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_contant_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'contact-name',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_contact_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'contact-link',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|contact_card|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course_implementation|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course_implementation';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'course_implementation_material' => array(
      'weight' => '44',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'course_imp_activity' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'activity',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'course_implementation_timepsan' => array(
      'weight' => '4',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'suffix' => '</span>',
        ),
      ),
    ),
    'event_reference_block' => array(
      'weight' => '6',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'my_enrollments' => array(
      'weight' => '29',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'repeating_event_reference_block' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'scope' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ', ',
        ),
      ),
    ),
    'comments' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'uhc_ds_course_number' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<span class="course-info">',
          'suffix' => ',  ',
        ),
      ),
    ),
    'uhc_ds_additional_info' => array(
      'weight' => '31',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Additional information',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'label',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_req_prerequisites' => array(
      'weight' => '24',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Required pre-requisites',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'label',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_contents' => array(
      'weight' => '27',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Contents',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'label',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_evaluation' => array(
      'weight' => '30',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Evaluation',
          'lb-el' => 'label',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--lcontent',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_objective' => array(
      'weight' => '25',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Objective',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'label',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_target_group' => array(
      'weight' => '23',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Target group',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'label',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_study_materials' => array(
      'weight' => '29',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Study materials and literature',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_conduct' => array(
      'weight' => '28',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Conduct',
          'lb-el' => 'label',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--lcontent',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_timing' => array(
      'weight' => '26',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Timing',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_responsible_person' => array(
      'weight' => '33',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Responsible person',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_rel_to_other_study_units' => array(
      'weight' => '34',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Relation to other study units',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'uhc_ds_enrollment_period' => array(
      'weight' => '15',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'enrollment-period',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'uhc_content_administration_from_oodi' => array(
      'weight' => '22',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="accordion-content-item clean">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_imp_canonical_url' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_imp_header_headline' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-cl' => 'content-header-promotion--title',
          'lb-col' => TRUE,
          'prefix' => '<h2>',
          'suffix' => '</h2>',
        ),
      ),
    ),
    'field_imp_header_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'figure',
          'lb-cl' => 'field--name-field-imp-header-image',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_imp_header_image_caption' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'on',
          'lb-col' => TRUE,
          'prefix' => '<span>',
          'suffix' => '</span>',
        ),
      ),
    ),
    'field_imp_header_text' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'long-text body-text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => '',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_imp_teacher' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ', ',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_imp_course_organiser' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<br/>',
        ),
      ),
    ),
    'field_imp_fee' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'label',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--lcontent',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_imp_locality' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => ', ',
        ),
      ),
    ),
    'field_imp_material_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'prefix' => '<div class="accordion-content-item body-text">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_imp_method_of_study' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'suffix' => ', ',
        ),
      ),
    ),
    'field_imp_teacher_se_content' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="accordion-content-item body-text">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_imp_teachersection' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'body-text',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_imp_teaching_language' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'label',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'span',
          'ow-cl' => 'teaching-languages',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_reference_to_course_tasks' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_moodle_key' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'label',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'moodle-key',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_moodle_url' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Learning environments',
          'lb-el' => 'h3',
          'lb-cl' => 'heading-light',
        ),
      ),
    ),
    'field_field_imp_header_intro_tex' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'p',
          'ow-cl' => 'intro-text body-text',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_feedback_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'list-of-links--light',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_imp_interaction_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fis' => TRUE,
          'fis-el' => 'ul',
          'fis-cl' => 'list-of-links--light',
          'fis-at' => '',
          'fis-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'li',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_imp_interactiondescription' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="accordion-content-item body-text">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_feedback_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="accordion-content-item body-text">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_imp_working_methods' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Realisation and working methods',
          'lb-el' => 'label',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content-item--label',
          'prefix' => '<div class="accordion-content-item">',
          'suffix' => '</div>',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item--lcontent',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_imp_video' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<div class="accordion-content-item body-text">',
          'suffix' => '</div>',
        ),
      ),
    ),
    'field_cancelled' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|course_implementation|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course_implementation|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course_implementation';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'location_and_time' => array(
      'weight' => '2',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'title_and_credit_linked' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(),
      ),
    ),
  );
  $export['node|course_implementation|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course_implementation|teaser_accordion';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course_implementation';
  $ds_fieldsetting->view_mode = 'teaser_accordion';
  $ds_fieldsetting->settings = array(
    'course_overview_link' => array(
      'weight' => '7',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'uhc_ds_imp_status_org_location_date' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'accordion-item__alternative ds-teaser-accordion--title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_additional_info' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'accordion-content-item',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_conduct' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Conduct',
          'lb-el' => 'div',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'accordion-content-item',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_imp_fee' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'accordion-content-item',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_imp_teacher_se_content' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'prefix' => '<div class="content remove-styles">',
          'suffix' => '</div>',
        ),
      ),
    ),
  );
  $export['node|course_implementation|teaser_accordion'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course_material|material_block';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course_material';
  $ds_fieldsetting->view_mode = 'material_block';
  $ds_fieldsetting->settings = array(
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'prefix' => '<label class="material-block--title">',
          'suffix' => '</label>',
        ),
      ),
    ),
  );
  $export['node|course_material|material_block'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course_material|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course_material';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'node_title_with_content_link' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'lbw-el' => 'label',
          'lbw-cl' => 'accordion-content-label',
        ),
      ),
    ),
    'field_material_author' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_material_pub_info' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|course_material|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course_task|teaser_accordion';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course_task';
  $ds_fieldsetting->view_mode = 'teaser_accordion';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => 'ds-teaser-accordion--title',
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_course_task_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Task description',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content--label',
        ),
      ),
    ),
    'field_event_ref_to_material' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Task material',
          'lb-col' => TRUE,
          'lbw' => 1,
          'lbw-el' => 'div',
          'lbw-cl' => 'accordion-content--label',
        ),
      ),
    ),
  );
  $export['node|course_task|teaser_accordion'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'course_reference_block' => array(
      'weight' => '0',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Teaching',
          'lb-el' => 'h2',
          'lb-cl' => 'heading-size-3',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'course_reference_block_past' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'accordion-content-item',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'scope' => array(
      'weight' => '1',
      'label' => 'inline',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Scope',
          'lb-el' => 'label',
          'lb-cl' => 'strong',
          'lb-col' => TRUE,
          'prefix' => ', ',
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'strong',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_course_course_number' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'fi' => TRUE,
          'fi-el' => 'span',
          'fi-cl' => 'strong',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|course|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|course|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'course';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'uhc_ds_course_reference_accordion' => array(
      'weight' => '5',
      'label' => 'hidden',
      'format' => 'default',
    ),
    'uhc_ds_title_and_credit' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h3',
          'fi-cl' => 'accordion-item__alternative ds-teaser-accordion--title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_objective' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'body-text',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_req_prerequisites' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'lb-cl' => 'accordion-content-label',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|course|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_event_begin_date' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|event|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|meta_information';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'meta_information';
  $ds_fieldsetting->settings = array(
    'event_meta_information' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|event|meta_information'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'event_information_row' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
        ),
      ),
    ),
  );
  $export['node|event|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|event|teaser_accordion';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'event';
  $ds_fieldsetting->view_mode = 'teaser_accordion';
  $ds_fieldsetting->settings = array(
    'timespan' => array(
      'weight' => '0',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'ds-teaser-accordion--title_timespan',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h3',
        'class' => 'ds-teaser-accordion--title',
        'ft' => array(),
      ),
    ),
    'field_event_loc_name' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
        ),
      ),
    ),
  );
  $export['node|event|teaser_accordion'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|liftup|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'liftup';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'field_liftup_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'box-story__content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_liftup_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'box-story__image',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_liftup_link_to' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'box-story__link',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'title_field' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h4',
          'fi-cl' => 'box-story__title',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|liftup|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|online_service|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'online_service';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => 'box-story__title',
        'ft' => array(),
      ),
    ),
    'field_liftup_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'box-story__content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_liftup_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'box-story__image',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'box-story__link button--action icon--next theme-transparent',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|online_service|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|portal_page|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'portal_page';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_portal_page_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'body-text',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_promotions' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'gridder-container-3  clearfix tube',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'gridder-box',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => TRUE,
        ),
      ),
    ),
    'field_view_attachment' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Course selection',
          'lb-el' => 'h2',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_portal_promotions_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'float-left',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_promotions_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'float-right',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|portal_page|default'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|portal_page|search_block_embedded';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'portal_page';
  $ds_fieldsetting->view_mode = 'search_block_embedded';
  $ds_fieldsetting->settings = array(
    'front_page_search_exposed_form' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'ds-grid-16 front-page-search-exposed-form',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_portal_promotions' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'gridder-container-3  clearfix tube',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'gridder-box',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_promotions_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'float-right',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_promotions_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'float-left',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|portal_page|search_block_embedded'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|portal_page|sidebar';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'portal_page';
  $ds_fieldsetting->view_mode = 'sidebar';
  $ds_fieldsetting->settings = array(
    'uhc_ds_table_of_contents' => array(
      'weight' => '3',
      'label' => 'above',
      'format' => 'default',
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Table of contents',
          'lb-el' => 'h3',
          'lb-cl' => 'heading-light',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'tube--large clearfix',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
        ),
      ),
    ),
    'field_portal_page_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'body-text',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_promotions' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'gridder-container-3 clearfix tube',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'gridder-box',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_page_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'box-ingress__image',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_view_attachment' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Course selection',
          'lb-el' => 'h2',
          'lb-col' => TRUE,
        ),
      ),
    ),
    'field_related_content_section' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'related-content-section',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_subject_contact_reference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'sidebar-contact',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'contact-card',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_liftup_collection' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_sidebar_liftups' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_content_collection' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_portal_promotions_link' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'float-right',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_promotions_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => 'float-left',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
  );
  $export['node|portal_page|sidebar'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|portal_page|teaser';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'portal_page';
  $ds_fieldsetting->view_mode = 'teaser';
  $ds_fieldsetting->settings = array(
    'title' => array(
      'weight' => '1',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link' => '0',
        'wrapper' => 'h4',
        'class' => 'box-story__title',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'node_link' => array(
      'weight' => '3',
      'label' => 'hidden',
      'format' => 'default',
      'formatter_settings' => array(
        'link text' => 'Read more',
        'wrapper' => 'div',
        'class' => 'box-story__link button--action icon--next theme-transparent',
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
    'field_portal_page_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'box-story__content',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_portal_page_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb-el' => 'div',
          'lb-cl' => 'box-story__image',
        ),
      ),
    ),
  );
  $export['node|portal_page|teaser'] = $ds_fieldsetting;

  $ds_fieldsetting = new stdClass();
  $ds_fieldsetting->api_version = 1;
  $ds_fieldsetting->id = 'node|subject|default';
  $ds_fieldsetting->entity_type = 'node';
  $ds_fieldsetting->bundle = 'subject';
  $ds_fieldsetting->view_mode = 'default';
  $ds_fieldsetting->settings = array(
    'field_imp_header_headline' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'prefix' => '<h2>',
          'suffix' => '</h2>',
        ),
      ),
    ),
    'field_subject_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'body-text',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_subject_image' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_minimal',
        ),
      ),
    ),
    'field_study_modules_description' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fis' => TRUE,
          'fis-el' => 'div',
          'fis-cl' => 'body-text',
          'fis-at' => '',
          'fis-def-at' => FALSE,
        ),
      ),
    ),
    'field_study_modules_title' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'h2',
          'fi-cl' => '',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_subject_contact_reference' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'lb' => 'Contact',
          'lb-col' => TRUE,
          'ow' => TRUE,
          'ow-el' => 'div',
          'ow-cl' => 'sidebar-contact',
          'ow-def-cl' => FALSE,
          'ow-at' => '',
          'ow-def-at' => FALSE,
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'contact-card',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_related_content_section' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_expert',
          'fi' => TRUE,
          'fi-el' => 'div',
          'fi-cl' => 'related-content-section',
          'fi-at' => '',
          'fi-def-at' => FALSE,
          'fi-odd-even' => FALSE,
        ),
      ),
    ),
    'field_sidebar_liftups' => array(
      'formatter_settings' => array(
        'ft' => array(
          'func' => 'theme_ds_field_reset',
        ),
      ),
    ),
  );
  $export['node|subject|default'] = $ds_fieldsetting;

  return $export;
}

/**
 * Implements hook_ds_custom_fields_info().
 */
function uhc_ds_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_imp_activity';
  $ds_field->label = 'Course implementation activity';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|168d59556da4b1c5672cfd491295ec1b',
    'block_render' => '3',
  );
  $export['course_imp_activity'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_implementation_timepsan';
  $ds_field->label = 'Course implementation timespan';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-imp-begin-date:custom:d.m.Y] - [node:field-imp-end-date:custom:d.m.Y]',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['course_implementation_timepsan'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_overview_link';
  $ds_field->label = 'Course overview link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a class="button" href="[node:url:absolute]"><?php print t(\'Course programme\') ?></a>
',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['course_overview_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_reference_block';
  $ds_field->label = 'Course reference block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|course_node_references-block',
    'block_render' => '3',
  );
  $export['course_reference_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_reference_block_past';
  $ds_field->label = 'Course reference block - past';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|course_node_references-block_1',
    'block_render' => '3',
  );
  $export['course_reference_block_past'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_information_row';
  $ds_field->label = 'Event information row';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '*|teaser';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="event-column">
<div class="field event-date">[node:field-event-begin-date:custom:D j.n.Y]</div>
<div class="field event-time">
<?php
if (!empty($entity->field_event_begin_date[\'und\'][0][\'value\'])) {
  $begin_date = new DateTime($entity->field_event_begin_date[\'und\'][0][\'value\']);
  $end_date = new DateTime($entity->field_event_begin_date[\'und\'][0][\'value\']);
  if (empty($entity->field_event_duration) || $entity->field_event_duration[\'und\'][0][\'value\'] == \'00:00\'){
    print $begin_date->format(\'H:i\');
  }
  else {
   $duration = explode(":", $entity->field_event_duration[\'und\'][0][\'value\']);
   $duration = "+" . $duration[0] . " hours " . $duration[1] . " minutes";
   $end_date = $end_date->modify($duration);
   print $begin_date->format(\'H:i\') . " - " . $end_date->format(\'H:i\');
  }  
}
?>
</div>
</div>
<div class="event-column">
<div class="field hide-from-three-column-tables event-title">[node:title]</div>
<div class="field remove-styles event-location">
<?php
if (empty($entity->field_event_link)) {
  if (!empty($entity->field_event_location[LANGUAGE_NONE][0][\'street\']) && !empty($entity->field_event_location[LANGUAGE_NONE][0][\'name\'])) {
    $street = $entity->field_event_location[LANGUAGE_NONE][0][\'street\'];
    $name = $entity->field_event_location[LANGUAGE_NONE][0][\'name\'];
    print $name . \', \' . "<a href=\'https://www.google.fi/maps/place/$street\' target=\'_blank\'>" . $street . \'</a>\';
  }
  else {
    print \'[node:field_event_loc_name]\';
  }
}
else {
print "<a href=\'[node:field-event-link:url]\' target=\'_blank\'>[node:field_event_loc_name]</a>";
}
?>
</div>
</div class="event-column">',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['event_information_row'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_material';
  $ds_field->label = 'Event material';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|course_event_references-block_1',
    'block_render' => '3',
  );
  $export['event_material'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_meta_information';
  $ds_field->label = 'Event meta information';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<div class="meta-information"><div>[node:field-event-begin-date:custom:D j.n.Y] [node:field-event-begin-date:custom:H:i] - [node:field-event-end-date:custom:H:i],&nbsp;</div><div class="remove-styles">[node:field-event-loc-name:value]</div></div>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['event_meta_information'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_reference__light_view_blok';
  $ds_field->label = 'Event reference - light view block';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$view_result = views_get_view_result(\'course_event_references_light\', \'block\', $entity->nid);

if (count($view_result) > 0) {
  print views_embed_view(\'course_event_references_light\', \'block\', $entity->nid);
}
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['event_reference__light_view_blok'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'event_reference_block';
  $ds_field->label = 'One-off events reference block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|course_event_references-block',
    'block_render' => '1',
  );
  $export['event_reference_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'location_and_time';
  $ds_field->label = 'Location and time';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-imp-locality] [node:field-imp-begin-date:custom:j.n.Y] - [node:field-imp-end-date:custom:j.n.Y]',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['location_and_time'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'message_header';
  $ds_field->label = 'Message header';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'comment' => 'comment',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<h2 class="message-author">[comment:author:name]</h2><span>[comment:field-private], [comment:created:custom:j.n.Y] <?php print t(\'at\'); ?> [comment:created:custom:G:i]</span>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['message_header'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'my_enrollments';
  $ds_field->label = 'My enrollments';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'uhc_autofill_metadata|enrollments_block',
    'block_render' => '1',
  );
  $export['my_enrollments'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'node_title_with_content_link';
  $ds_field->label = 'Material node title with content link';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '*|teaser';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<?php
$node_title = "[node:title]";
$attachment_link = "[node:field-material-link:url]";
if (!empty($entity->field_material_file)) {
  $attachment_file = file_create_url($entity->field_material_file[LANGUAGE_NONE][0][\'uri\']);
}
if (!empty($entity->field_material_link)){
  print \'<a href="\' . $attachment_link . \'" title="\' . $node_title . \'" class="accordion-content-label field">\' . $node_title . \'</a>\';
}
else if (!empty($entity->field_material_file)){
  print \'<a href="\' . $attachment_file . \'" title="\' . $node_title . \'" class="accordion-content-label field">\' . $node_title . \'</a>\';
}
else {
  print \'<label class="accordion-content-label field">\' . $node_title . \'</label>\';
}
?>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['node_title_with_content_link'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'repeating_event_reference_block';
  $ds_field->label = 'Repeating events reference block';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|course_event_references-block_2',
    'block_render' => '1',
  );
  $export['repeating_event_reference_block'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'scope';
  $ds_field->label = 'Scope';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field_study_credit] <?php print t("cr"); ?>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['scope'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'timespan';
  $ds_field->label = 'Timespan';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '[node:field-event-begin-date:custom:d.m.Y] <?php print t(\'at\');?> [node:field-event-begin-date:custom:H:i] - [node:field-event-end-date:custom:H:i]',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['timespan'] = $ds_field;

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'title_and_credit_linked';
  $ds_field->label = 'Title and credit linked';
  $ds_field->field_type = 5;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'code' => array(
      'value' => '<a href="[node:url]">[node:title_field], [node:field_study_credit] <?php print t("cr"); ?></a>',
      'format' => 'ds_code',
    ),
    'use_token' => 1,
  );
  $export['title_and_credit_linked'] = $ds_field;

  return $export;
}

/**
 * Implements hook_ds_layout_settings_info().
 */
function uhc_ds_ds_layout_settings_info() {
  $export = array();

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_course_implementation|default';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_course_implementation';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'ds_user_picture',
        1 => 'field_private',
        2 => 'comment_post_date',
        3 => 'comment_body',
        4 => 'links',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'ds_content',
      'field_private' => 'ds_content',
      'comment_post_date' => 'ds_content',
      'comment_body' => 'ds_content',
      'links' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'hide-content-title' => 'hide-content-title',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_course_implementation|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_course_implementation|form';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_course_implementation';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'comment_body',
      ),
      'hidden' => array(
        1 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'comment_body' => 'ds_content',
      '_add_existing_field' => 'hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        'hide-content-title' => 'hide-content-title',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_course_implementation|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'comment|comment_node_course_implementation|full';
  $ds_layout->entity_type = 'comment';
  $ds_layout->bundle = 'comment_node_course_implementation';
  $ds_layout->view_mode = 'full';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'ds_user_picture',
        1 => 'message_header',
        2 => 'group_message_wrapper',
        3 => 'comment_body',
        4 => 'links',
      ),
    ),
    'fields' => array(
      'ds_user_picture' => 'ds_content',
      'message_header' => 'ds_content',
      'group_message_wrapper' => 'ds_content',
      'comment_body' => 'ds_content',
      'links' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['comment|comment_node_course_implementation|full'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_content_collection|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_content_collection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_content_collection_left',
        1 => 'group_content_collection_right',
        2 => 'title_field',
        3 => 'field_content_image',
        4 => 'field_related_content_title',
        5 => 'field_body',
        6 => 'field_link_multiple',
        7 => 'field_related_content',
      ),
    ),
    'fields' => array(
      'group_content_collection_left' => 'ds_content',
      'group_content_collection_right' => 'ds_content',
      'title_field' => 'ds_content',
      'field_content_image' => 'ds_content',
      'field_related_content_title' => 'ds_content',
      'field_body' => 'ds_content',
      'field_link_multiple' => 'ds_content',
      'field_related_content' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'regional-rule-top' => 'regional-rule-top',
        'spacer-top-4' => 'spacer-top-4',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => 'tokens',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_content_collection|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_content_collection|form';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_content_collection';
  $ds_layout->view_mode = 'form';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_field',
        1 => 'field_content_image',
        2 => 'field_body',
        3 => 'field_related_content_title',
        4 => 'field_related_content',
        5 => 'field_link_multiple',
        6 => '_add_existing_field',
      ),
    ),
    'fields' => array(
      'title_field' => 'ds_content',
      'field_content_image' => 'ds_content',
      'field_body' => 'ds_content',
      'field_related_content_title' => 'ds_content',
      'field_related_content' => 'ds_content',
      'field_link_multiple' => 'ds_content',
      '_add_existing_field' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_content_collection|form'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_imp_attached_material_sec|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_imp_attached_material_sec';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_section_label',
        1 => 'field_section_material',
      ),
    ),
    'fields' => array(
      'field_section_label' => 'ds_content',
      'field_section_material' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_imp_attached_material_sec|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_imp_teachersection|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_imp_teachersection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'accordion_container';
  $ds_layout->settings = array(
    'regions' => array(
      'accordion_title' => array(
        0 => 'field_imp_teachersection_label',
      ),
      'accordion_content' => array(
        1 => 'field_imp_teachersection_content',
      ),
    ),
    'fields' => array(
      'field_imp_teachersection_label' => 'accordion_title',
      'field_imp_teachersection_content' => 'accordion_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'accordion_content' => array(
        'group-custom-section' => 'group-custom-section',
      ),
    ),
    'wrappers' => array(
      'accordion_title' => 'div',
      'accordion_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_imp_teachersection|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_liftup_collection|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_liftup_collection';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'group_liftup_colletion_header',
        1 => 'title_field',
        2 => 'field_intro',
        3 => 'field_portal_promotions',
      ),
    ),
    'fields' => array(
      'group_liftup_colletion_header' => 'ds_content',
      'title_field' => 'ds_content',
      'field_intro' => 'ds_content',
      'field_portal_promotions' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'regional-rule-top' => 'regional-rule-top',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_liftup_collection|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_related_content_section|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_related_content_section';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_related_content_title',
        1 => 'field_related_content',
      ),
    ),
    'fields' => array(
      'field_related_content_title' => 'ds_content',
      'field_related_content' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_related_content_section|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'field_collection_item|field_study_module|default';
  $ds_layout->entity_type = 'field_collection_item';
  $ds_layout->bundle = 'field_study_module';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_study_module_title',
        1 => 'field_subject_ref_study_module',
        2 => 'field_subject_ref_to_courses',
      ),
    ),
    'fields' => array(
      'field_study_module_title' => 'ds_content',
      'field_subject_ref_study_module' => 'ds_content',
      'field_subject_ref_to_courses' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
  );
  $export['field_collection_item|field_study_module|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|contact_card|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'contact_card';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title',
        1 => 'field_contant_name',
        2 => 'field_contact_phone',
        3 => 'field_contact_email',
        4 => 'field_contact_link',
      ),
    ),
    'fields' => array(
      'title' => 'ds_content',
      'field_contant_name' => 'ds_content',
      'field_contact_phone' => 'ds_content',
      'field_contact_email' => 'ds_content',
      'field_contact_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|contact_card|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course_implementation|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course_implementation';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'course_page';
  $ds_layout->settings = array(
    'regions' => array(
      'course_content' => array(
        0 => 'comments',
        4 => 'field_reference_to_course_tasks',
        8 => 'repeating_event_reference_block',
        9 => 'event_reference_block',
        18 => 'field_imp_canonical_url',
        19 => 'uhc_ds_enrollment_period',
        20 => 'group_imp_moodle',
        21 => 'group_course_messages',
        22 => 'group_imp_interaction',
        23 => 'group_timetable',
        24 => 'field_imp_teacher_se_content',
        25 => 'group_imp_material',
        26 => 'group_imp_video',
        27 => 'group_course_task_material',
        28 => 'uhc_content_administration_from_oodi',
        29 => 'field_imp_teachersection',
        30 => 'uhc_ds_target_group',
        31 => 'uhc_ds_req_prerequisites',
        32 => 'group_conduct_of_course',
        33 => 'uhc_ds_objective',
        34 => 'group_imp_feedback',
        35 => 'field_moodle_url',
        36 => 'group_imp_fee',
        37 => 'uhc_ds_timing',
        38 => 'group_description_objectives',
        39 => 'field_moodle_key',
        40 => 'uhc_ds_contents',
        41 => 'uhc_ds_conduct',
        42 => 'group_additional_information',
        43 => 'uhc_ds_study_materials',
        45 => 'field_imp_fee',
        46 => 'uhc_ds_evaluation',
        47 => 'uhc_ds_additional_info',
        48 => 'field_imp_working_methods',
        49 => 'uhc_ds_responsible_person',
        50 => 'uhc_ds_rel_to_other_study_units',
        51 => 'field_imp_material_description',
        52 => 'course_implementation_material',
        53 => 'field_imp_interactiondescription',
        54 => 'field_imp_interaction_link',
        55 => 'field_imp_video',
        56 => 'field_feedback_description',
        57 => 'field_feedback_link',
      ),
      'course_metadata' => array(
        1 => 'uhc_ds_course_number',
        2 => 'field_imp_method_of_study',
        3 => 'scope',
        5 => 'field_imp_teacher',
        6 => 'course_implementation_timepsan',
        7 => 'field_imp_course_organiser',
        10 => 'field_imp_locality',
        11 => 'course_imp_activity',
        12 => 'field_imp_teaching_language',
      ),
      'course_banner' => array(
        13 => 'field_imp_header_image',
        14 => 'field_imp_header_image_caption',
        15 => 'field_imp_header_headline',
        16 => 'field_field_imp_header_intro_tex',
        17 => 'field_imp_header_text',
      ),
      'course_sidebar' => array(
        44 => 'my_enrollments',
      ),
      'ds_hidden' => array(
        58 => 'field_cancelled',
      ),
    ),
    'fields' => array(
      'comments' => 'course_content',
      'uhc_ds_course_number' => 'course_metadata',
      'field_imp_method_of_study' => 'course_metadata',
      'scope' => 'course_metadata',
      'field_reference_to_course_tasks' => 'course_content',
      'field_imp_teacher' => 'course_metadata',
      'course_implementation_timepsan' => 'course_metadata',
      'field_imp_course_organiser' => 'course_metadata',
      'repeating_event_reference_block' => 'course_content',
      'event_reference_block' => 'course_content',
      'field_imp_locality' => 'course_metadata',
      'course_imp_activity' => 'course_metadata',
      'field_imp_teaching_language' => 'course_metadata',
      'field_imp_header_image' => 'course_banner',
      'field_imp_header_image_caption' => 'course_banner',
      'field_imp_header_headline' => 'course_banner',
      'field_field_imp_header_intro_tex' => 'course_banner',
      'field_imp_header_text' => 'course_banner',
      'field_imp_canonical_url' => 'course_content',
      'uhc_ds_enrollment_period' => 'course_content',
      'group_imp_moodle' => 'course_content',
      'group_course_messages' => 'course_content',
      'group_imp_interaction' => 'course_content',
      'group_timetable' => 'course_content',
      'field_imp_teacher_se_content' => 'course_content',
      'group_imp_material' => 'course_content',
      'group_imp_video' => 'course_content',
      'group_course_task_material' => 'course_content',
      'uhc_content_administration_from_oodi' => 'course_content',
      'field_imp_teachersection' => 'course_content',
      'uhc_ds_target_group' => 'course_content',
      'uhc_ds_req_prerequisites' => 'course_content',
      'group_conduct_of_course' => 'course_content',
      'uhc_ds_objective' => 'course_content',
      'group_imp_feedback' => 'course_content',
      'field_moodle_url' => 'course_content',
      'group_imp_fee' => 'course_content',
      'uhc_ds_timing' => 'course_content',
      'group_description_objectives' => 'course_content',
      'field_moodle_key' => 'course_content',
      'uhc_ds_contents' => 'course_content',
      'uhc_ds_conduct' => 'course_content',
      'group_additional_information' => 'course_content',
      'uhc_ds_study_materials' => 'course_content',
      'my_enrollments' => 'course_sidebar',
      'field_imp_fee' => 'course_content',
      'uhc_ds_evaluation' => 'course_content',
      'uhc_ds_additional_info' => 'course_content',
      'field_imp_working_methods' => 'course_content',
      'uhc_ds_responsible_person' => 'course_content',
      'uhc_ds_rel_to_other_study_units' => 'course_content',
      'field_imp_material_description' => 'course_content',
      'course_implementation_material' => 'course_content',
      'field_imp_interactiondescription' => 'course_content',
      'field_imp_interaction_link' => 'course_content',
      'field_imp_video' => 'course_content',
      'field_feedback_description' => 'course_content',
      'field_feedback_link' => 'course_content',
      'field_cancelled' => 'ds_hidden',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'course_metadata' => array(
        'ds-node-metadata' => 'ds-node-metadata',
      ),
      'course_banner' => array(
        'ds-node-banner' => 'ds-node-banner',
      ),
      'course_content' => array(
        'ds-node-content' => 'ds-node-content',
      ),
      'course_sidebar' => array(
        'ds-node-sidebar' => 'ds-node-sidebar',
      ),
    ),
    'wrappers' => array(
      'course_metadata' => 'div',
      'course_banner' => 'div',
      'course_content' => 'div',
      'course_sidebar' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|course_implementation|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course_implementation|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course_implementation';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'title_and_credit_linked',
        1 => 'location_and_time',
      ),
    ),
    'fields' => array(
      'title_and_credit_linked' => 'ds_content',
      'location_and_time' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'button-internal' => 'button-internal',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|course_implementation|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course_implementation|teaser_accordion';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course_implementation';
  $ds_layout->view_mode = 'teaser_accordion';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'uhc_ds_imp_status_org_location_date',
        1 => 'group_accordion_content',
        2 => 'field_conduct',
        4 => 'field_imp_fee',
        5 => 'field_additional_info',
        6 => 'course_overview_link',
      ),
      'ds_hidden' => array(
        3 => 'field_imp_teacher_se_content',
      ),
    ),
    'fields' => array(
      'uhc_ds_imp_status_org_location_date' => 'ds_content',
      'group_accordion_content' => 'ds_content',
      'field_conduct' => 'ds_content',
      'field_imp_teacher_se_content' => 'ds_hidden',
      'field_imp_fee' => 'ds_content',
      'field_additional_info' => 'ds_content',
      'course_overview_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|course_implementation|teaser_accordion'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course_material|material_block';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course_material';
  $ds_layout->view_mode = 'material_block';
  $ds_layout->layout = 'event_material';
  $ds_layout->settings = array(
    'regions' => array(
      'event_material_content' => array(
        0 => 'title_field',
        1 => 'field_material_description',
      ),
      'event_material_attachements' => array(
        2 => 'field_material_link',
        3 => 'field_material_file',
      ),
    ),
    'fields' => array(
      'title_field' => 'event_material_content',
      'field_material_description' => 'event_material_content',
      'field_material_link' => 'event_material_attachements',
      'field_material_file' => 'event_material_attachements',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'event_material_content' => 'div',
      'event_material_attachements' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '1',
    'page_option_title' => '',
  );
  $export['node|course_material|material_block'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course_material|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course_material';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'event_material';
  $ds_layout->settings = array(
    'regions' => array(
      'event_material_content' => array(
        0 => 'node_title_with_content_link',
        1 => 'field_material_author',
        2 => 'field_material_pub_info',
      ),
    ),
    'fields' => array(
      'node_title_with_content_link' => 'event_material_content',
      'field_material_author' => 'event_material_content',
      'field_material_pub_info' => 'event_material_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'event_material_content' => 'div',
      'event_material_attachements' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|course_material|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course_task|teaser_accordion';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course_task';
  $ds_layout->view_mode = 'teaser_accordion';
  $ds_layout->layout = 'teaser_accordion';
  $ds_layout->settings = array(
    'regions' => array(
      'teaser_accordion_title' => array(
        0 => 'title',
      ),
      'teaser_accordion_content' => array(
        1 => 'field_course_task_description',
        2 => 'field_event_ref_to_material',
      ),
    ),
    'fields' => array(
      'title' => 'teaser_accordion_title',
      'field_course_task_description' => 'teaser_accordion_content',
      'field_event_ref_to_material' => 'teaser_accordion_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'accordion-style-clean' => 'accordion-style-clean',
      ),
    ),
    'wrappers' => array(
      'teaser_accordion_title' => 'div',
      'teaser_accordion_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|course_task|teaser_accordion'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'course_page';
  $ds_layout->settings = array(
    'regions' => array(
      'course_content' => array(
        0 => 'course_reference_block',
        3 => 'course_reference_block_past',
      ),
      'course_metadata' => array(
        1 => 'field_course_course_number',
        2 => 'scope',
      ),
    ),
    'fields' => array(
      'course_reference_block' => 'course_content',
      'field_course_course_number' => 'course_metadata',
      'scope' => 'course_metadata',
      'course_reference_block_past' => 'course_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'course_metadata' => array(
        'ds-node-metadata' => 'ds-node-metadata',
      ),
      'course_banner' => array(
        'ds-node-banner' => 'ds-node-banner',
      ),
      'course_content' => array(
        'ds-node-content' => 'ds-node-content',
      ),
    ),
    'wrappers' => array(
      'course_metadata' => 'div',
      'course_banner' => 'div',
      'course_content' => 'div',
      'course_sidebar' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|course|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|course|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'course';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_reset';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'uhc_ds_title_and_credit',
        1 => 'group_accordion_content',
        2 => 'field_objective',
        3 => 'field_req_prerequisites',
        4 => 'uhc_ds_course_reference_accordion',
      ),
    ),
    'fields' => array(
      'uhc_ds_title_and_credit' => 'ds_content',
      'group_accordion_content' => 'ds_content',
      'field_objective' => 'ds_content',
      'field_req_prerequisites' => 'ds_content',
      'uhc_ds_course_reference_accordion' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => TRUE,
    'layout_link_attribute' => FALSE,
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|course|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'course_page';
  $ds_layout->settings = array(
    'regions' => array(
      'course_metadata' => array(
        0 => 'field_event_begin_date',
        1 => 'field_event_loc_name',
      ),
    ),
    'fields' => array(
      'field_event_begin_date' => 'course_metadata',
      'field_event_loc_name' => 'course_metadata',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'course_metadata' => 'div',
      'course_banner' => 'div',
      'course_content' => 'div',
      'course_sidebar' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|event|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|meta_information';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'meta_information';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'event_meta_information',
      ),
    ),
    'fields' => array(
      'event_meta_information' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|event|meta_information'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'event_material';
  $ds_layout->settings = array(
    'regions' => array(
      'event_material_content' => array(
        0 => 'event_information_row',
      ),
    ),
    'fields' => array(
      'event_information_row' => 'event_material_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'event_material_content' => 'div',
      'event_material_attachements' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|event|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|event|teaser_accordion';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'event';
  $ds_layout->view_mode = 'teaser_accordion';
  $ds_layout->layout = 'teaser_accordion';
  $ds_layout->settings = array(
    'regions' => array(
      'teaser_accordion_title' => array(
        0 => 'timespan',
        1 => 'title',
        2 => 'field_event_loc_name',
      ),
      'teaser_accordion_content' => array(
        3 => 'field_event_ref_to_material',
      ),
    ),
    'fields' => array(
      'timespan' => 'teaser_accordion_title',
      'title' => 'teaser_accordion_title',
      'field_event_loc_name' => 'teaser_accordion_title',
      'field_event_ref_to_material' => 'teaser_accordion_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'teaser_accordion_title' => array(
        'accordion-style-clean' => 'accordion-style-clean',
        'icon-placement-right' => 'icon-placement-right',
      ),
      'teaser_accordion_content' => array(
        '' => '',
        'accordion-style-clean' => 'accordion-style-clean',
      ),
    ),
    'wrappers' => array(
      'teaser_accordion_title' => 'div',
      'teaser_accordion_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|event|teaser_accordion'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|liftup|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'liftup';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_liftup_image',
        1 => 'title_field',
        2 => 'field_liftup_description',
        3 => 'field_liftup_link_to',
      ),
    ),
    'fields' => array(
      'field_liftup_image' => 'ds_content',
      'title_field' => 'ds_content',
      'field_liftup_description' => 'ds_content',
      'field_liftup_link_to' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'box-story' => 'box-story',
        'tube' => 'tube',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => 'tokens',
    'layout_link_custom' => '[node:field-liftup-link-to:url]',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|liftup|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|online_service|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'online_service';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_liftup_image',
        1 => 'title',
        2 => 'field_liftup_description',
        3 => 'field_link',
      ),
    ),
    'fields' => array(
      'field_liftup_image' => 'ds_content',
      'title' => 'ds_content',
      'field_liftup_description' => 'ds_content',
      'field_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'box-story' => 'box-story',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 0,
    'layout_link_attribute' => 'tokens',
    'layout_link_custom' => '[node:field-link:url]',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|online_service|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|portal_page|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'portal_page';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'simple_page_metadata' => 'div',
      'simple_page_banner' => 'div',
      'simple_page_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
    'regions' => array(
      'ds_content' => array(
        0 => 'field_portal_page_description',
        1 => 'group_portal_page_promotion',
        2 => 'field_portal_promotions_title',
        3 => 'field_portal_promotions_link',
        4 => 'field_portal_promotions',
        5 => 'field_view_attachment',
      ),
    ),
    'fields' => array(
      'field_portal_page_description' => 'ds_content',
      'group_portal_page_promotion' => 'ds_content',
      'field_portal_promotions_title' => 'ds_content',
      'field_portal_promotions_link' => 'ds_content',
      'field_portal_promotions' => 'ds_content',
      'field_view_attachment' => 'ds_content',
    ),
  );
  $export['node|portal_page|default'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|portal_page|search_block_embedded';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'portal_page';
  $ds_layout->view_mode = 'search_block_embedded';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_portal_page_description',
        1 => 'front_page_search_exposed_form',
        2 => 'group_portal_page_promotion',
        3 => 'field_portal_promotions_title',
        4 => 'field_portal_promotions_link',
        5 => 'field_portal_promotions',
        6 => 'field_view_attachment',
      ),
    ),
    'fields' => array(
      'field_portal_page_description' => 'ds_content',
      'front_page_search_exposed_form' => 'ds_content',
      'group_portal_page_promotion' => 'ds_content',
      'field_portal_promotions_title' => 'ds_content',
      'field_portal_promotions_link' => 'ds_content',
      'field_portal_promotions' => 'ds_content',
      'field_view_attachment' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|portal_page|search_block_embedded'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|portal_page|sidebar';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'portal_page';
  $ds_layout->view_mode = 'sidebar';
  $ds_layout->layout = 'portal_page_sidebar';
  $ds_layout->settings = array(
    'regions' => array(
      'portal_page_content' => array(
        0 => 'field_portal_page_image',
        1 => 'field_portal_page_description',
        2 => 'field_view_attachment',
        3 => 'uhc_ds_table_of_contents',
      ),
      'portal_page_sidebar' => array(
        4 => 'field_related_content_section',
        5 => 'field_sidebar_liftups',
        6 => 'field_subject_contact_reference',
      ),
      'portal_page_promotion' => array(
        7 => 'field_content_collection',
        8 => 'field_portal_promotions_title',
        9 => 'group_portal_page_promotion',
        10 => 'field_portal_promotions_link',
        11 => 'field_liftup_collection',
        12 => 'field_portal_promotions',
      ),
    ),
    'fields' => array(
      'field_portal_page_image' => 'portal_page_content',
      'field_portal_page_description' => 'portal_page_content',
      'field_view_attachment' => 'portal_page_content',
      'uhc_ds_table_of_contents' => 'portal_page_content',
      'field_related_content_section' => 'portal_page_sidebar',
      'field_sidebar_liftups' => 'portal_page_sidebar',
      'field_subject_contact_reference' => 'portal_page_sidebar',
      'field_content_collection' => 'portal_page_promotion',
      'field_portal_promotions_title' => 'portal_page_promotion',
      'group_portal_page_promotion' => 'portal_page_promotion',
      'field_portal_promotions_link' => 'portal_page_promotion',
      'field_liftup_collection' => 'portal_page_promotion',
      'field_portal_promotions' => 'portal_page_promotion',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
    ),
    'wrappers' => array(
      'portal_page_content' => 'div',
      'portal_page_sidebar' => 'div',
      'portal_page_promotion' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|portal_page|sidebar'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|portal_page|teaser';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'portal_page';
  $ds_layout->view_mode = 'teaser';
  $ds_layout->layout = 'ds_1col';
  $ds_layout->settings = array(
    'regions' => array(
      'ds_content' => array(
        0 => 'field_portal_page_image',
        1 => 'title',
        2 => 'field_portal_page_description',
        3 => 'node_link',
      ),
    ),
    'fields' => array(
      'field_portal_page_image' => 'ds_content',
      'title' => 'ds_content',
      'field_portal_page_description' => 'ds_content',
      'node_link' => 'ds_content',
    ),
    'classes' => array(
      'layout_class' => array(
        'box-story' => 'box-story',
      ),
    ),
    'wrappers' => array(
      'ds_content' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => 'content',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|portal_page|teaser'] = $ds_layout;

  $ds_layout = new stdClass();
  $ds_layout->api_version = 1;
  $ds_layout->id = 'node|subject|default';
  $ds_layout->entity_type = 'node';
  $ds_layout->bundle = 'subject';
  $ds_layout->view_mode = 'default';
  $ds_layout->layout = 'course_page';
  $ds_layout->settings = array(
    'regions' => array(
      'course_banner' => array(
        0 => 'field_subject_image',
        1 => 'field_imp_header_headline',
        2 => 'field_subject_description',
      ),
      'course_content' => array(
        3 => 'field_study_modules_title',
        4 => 'field_study_modules_description',
        5 => 'field_study_module',
      ),
      'course_sidebar' => array(
        6 => 'field_related_content_section',
        7 => 'field_sidebar_liftups',
        8 => 'field_subject_contact_reference',
      ),
    ),
    'fields' => array(
      'field_subject_image' => 'course_banner',
      'field_imp_header_headline' => 'course_banner',
      'field_subject_description' => 'course_banner',
      'field_study_modules_title' => 'course_content',
      'field_study_modules_description' => 'course_content',
      'field_study_module' => 'course_content',
      'field_related_content_section' => 'course_sidebar',
      'field_sidebar_liftups' => 'course_sidebar',
      'field_subject_contact_reference' => 'course_sidebar',
    ),
    'classes' => array(
      'layout_class' => array(
        '' => '',
      ),
      'course_banner' => array(
        'ds-node-banner' => 'ds-node-banner',
      ),
      'course_content' => array(
        'ds-node-content' => 'ds-node-content',
        'horizontal-rule-top' => 'horizontal-rule-top',
      ),
      'course_sidebar' => array(
        'ds-node-sidebar' => 'ds-node-sidebar',
      ),
    ),
    'wrappers' => array(
      'course_metadata' => 'div',
      'course_banner' => 'div',
      'course_content' => 'div',
      'course_sidebar' => 'div',
      'ds_hidden' => 'div',
    ),
    'layout_wrapper' => 'div',
    'layout_attributes' => '',
    'layout_attributes_merge' => 1,
    'layout_link_attribute' => '',
    'layout_link_custom' => '',
    'hide_page_title' => '0',
    'page_option_title' => '',
  );
  $export['node|subject|default'] = $ds_layout;

  return $export;
}

/**
 * Implements hook_ds_view_modes_info().
 */
function uhc_ds_ds_view_modes_info() {
  $export = array();

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'material_block';
  $ds_view_mode->label = 'Material block';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['material_block'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'meta_information';
  $ds_view_mode->label = 'Meta information';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['meta_information'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'search_block_embedded';
  $ds_view_mode->label = 'Search block embedded';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['search_block_embedded'] = $ds_view_mode;

  $ds_view_mode = new stdClass();
  $ds_view_mode->api_version = 1;
  $ds_view_mode->view_mode = 'teaser_accordion';
  $ds_view_mode->label = 'Teaser accordion';
  $ds_view_mode->entities = array(
    'node' => 'node',
  );
  $export['teaser_accordion'] = $ds_view_mode;

  return $export;
}
