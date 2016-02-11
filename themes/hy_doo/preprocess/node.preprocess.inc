<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_preprocess_node()
 *
 * Custom display templates will be called with node--[type]--[viewmode].tpl.php
 *
 * @param $variables
 */

function hy_doo_preprocess_node(&$variables) {

  // Course implementation
  if ($variables['type'] == 'course_implementation') {

    /**
     * TODO: DEPRECATED! THIS WHOLE BLOCK WILL BE REMOVED AS DISPLAY SUITE WILL
     * TAKE OVER. SEE hy_course_ds_fields_info()!
     */

    // If there's reference to course(s) set, load the first item's course
    // number and pre-requisites.
    $course_node = NULL;
    if (isset($variables['field_imp_reference_to_courses'][LANGUAGE_NONE])) {
      foreach ($variables['field_imp_reference_to_courses'][LANGUAGE_NONE] as $item) {
        if (isset($item['target_id'])) {
          $course_node = node_load($item['target_id']);
          break;
        }
      }
    }

    // Embed the field rendering of referenced course.
    $variables['field_course_course_number'] = '';
    $variables['field_req_prerequisites'] = '';
    $accordion = array();
    if (!is_null($course_node) &&
        isset($course_node->field_course_course_number) &&
        isset($course_node->field_req_prerequisites)) {

      // Embed the renderable field values
      $langcode = function_exists('i18n_langcode') ? i18n_langcode() : LANGUAGE_NONE;
      $display_options = array('label' => 'hidden');
      $variables['field_course_course_number'] = field_view_field('node', $course_node, 'field_course_course_number', $display_options, $langcode);
      $variables['field_req_prerequisites'] = field_view_field('node', $course_node, 'field_req_prerequisites', $display_options, $langcode);

      // Gather up accordion items
      $accordion = array();
      // Required pre-requisites
      if (isset($variables['field_req_prerequisites']['#items'][0]) &&
          !text_field_is_empty($variables['field_req_prerequisites']['#items'][0], $variables['field_req_prerequisites'])) {
        $accordion[t('Course description')] = '<h4>' . t('Required pre-requisites') . '</h4>';
        $accordion[t('Course description')] .= render($variables['field_req_prerequisites']);
      }

    }
    $variables['accordion'] = $accordion;
  }

  if ($variables['type'] == 'course_implementation' || $variables['type'] == 'course') {
    // we add some js to open accordion items when we get an url-parameter (material)
    drupal_add_js(drupal_get_path('theme', 'hy_doo') . '/js/accordion_trigger.js', array('scope' => 'footer'));
  }

}
