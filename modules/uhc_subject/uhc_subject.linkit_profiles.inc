<?php
/**
 * @file
 * uhc_subject.linkit_profiles.inc
 */

/**
 * Implements hook_default_linkit_profiles().
 */
function uhc_subject_default_linkit_profiles() {
  $export = array();

  $linkit_profile = new LinkitProfile();
  $linkit_profile->disabled = FALSE; /* Edit this to true to make a default linkit_profile disabled initially */
  $linkit_profile->api_version = 1;
  $linkit_profile->name = 'linkit';
  $linkit_profile->admin_title = 'linkit';
  $linkit_profile->admin_description = '';
  $linkit_profile->profile_type = '2';
  $linkit_profile->data = array(
    'search_plugins' => array(
      'entity:file' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_index' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:taxonomy_term' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:node' => array(
        'enabled' => 1,
        'weight' => '-10',
      ),
      'entity:comment' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_autocomplete_search' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:search_api_server' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'entity:user' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'entity:node' => array(
      'result_description' => '[node:url]',
      'bundles' => array(
        'contact_card' => 0,
        'course' => 0,
        'course_implementation' => 0,
        'course_liftup' => 0,
        'course_material' => 0,
        'course_task' => 0,
        'event' => 0,
        'exam_results' => 0,
        'liftup' => 0,
        'online_service' => 0,
        'portal_page' => 0,
        'studies_landing_page' => 0,
        'subject' => 0,
      ),
      'group_by_bundle' => 0,
      'include_unpublished' => 0,
    ),
    'entity:taxonomy_term' => array(
      'result_description' => '',
      'bundles' => array(
        'scald_authors' => 0,
        'scald_tags' => 0,
        'form_of_teaching' => 0,
        'course_tags' => 0,
        'course_theme' => 0,
        'type_of_teaching' => 0,
        'organisational_units' => 0,
        'method_of_study' => 0,
        'months' => 0,
        'subject_category' => 0,
        'faculty' => 0,
        'material_sections' => 0,
        'organisations_of_university_of_helsinki' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:comment' => array(
      'result_description' => '',
      'bundles' => array(
        'comment_node_contact_card' => 0,
        'comment_node_course' => 0,
        'comment_node_course_implementation' => 0,
        'comment_node_course_liftup' => 0,
        'comment_node_course_material' => 0,
        'comment_node_course_task' => 0,
        'comment_node_event' => 0,
        'comment_node_exam_results' => 0,
        'comment_node_liftup' => 0,
        'comment_node_online_service' => 0,
        'comment_node_portal_page' => 0,
        'comment_node_studies_landing_page' => 0,
        'comment_node_subject' => 0,
      ),
      'group_by_bundle' => 0,
    ),
    'entity:search_api_server' => array(
      'result_description' => '',
    ),
    'entity:search_api_index' => array(
      'result_description' => '',
    ),
    'entity:search_api_autocomplete_search' => array(
      'result_description' => '',
    ),
    'entity:file' => array(
      'result_description' => '',
      'show_scheme' => 0,
      'group_by_scheme' => 0,
      'url_type' => 'direct',
      'image_extra_info' => array(
        'thumbnail' => 'thumbnail',
        'dimensions' => 'dimensions',
      ),
    ),
    'entity:user' => array(
      'result_description' => '',
    ),
    'insert_plugin' => array(
      'plugin' => 'raw_url',
      'url_method' => '1',
    ),
    'attribute_plugins' => array(
      'accesskey' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'target' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'class' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'rel' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'id' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
      'title' => array(
        'enabled' => 0,
        'weight' => '-10',
      ),
    ),
    'autocomplete' => array(
      'charLimit' => '3',
      'wait' => '350',
      'remoteTimeout' => '20000',
    ),
  );
  $export['linkit'] = $linkit_profile;

  return $export;
}
