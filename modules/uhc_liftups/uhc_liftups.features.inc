<?php
/**
 * @file
 * uhc_liftups.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_liftups_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_views_api().
 */
function uhc_liftups_views_api($module = NULL, $api = NULL) {
  return array("api" => "3.0");
}

/**
 * Implements hook_image_default_styles().
 */
function uhc_liftups_image_default_styles() {
  $styles = array();

  // Exported image style: portal_main_liftup.
  $styles['portal_main_liftup'] = array(
    'label' => 'Portal main liftup',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 300,
          'height' => 260,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}

/**
 * Implements hook_node_info().
 */
function uhc_liftups_node_info() {
  $items = array(
    'course_liftup' => array(
      'name' => t('Course liftup'),
      'base' => 'node_content',
      'description' => t('Course liftups are used to promote some course implementations in portal\'s landing page.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
    'liftup' => array(
      'name' => t('Liftup'),
      'base' => 'node_content',
      'description' => t('Liftups are displayed one at the time in portal\'s landing page.'),
      'has_title' => '1',
      'title_label' => t('Headline'),
      'help' => '',
    ),
  );
  drupal_alter('node_info', $items);
  return $items;
}
