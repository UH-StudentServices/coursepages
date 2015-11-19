<?php
/**
 * @file
 * Variable integration.
 */

/**
 * Implements hook_variable_info().
 */
function uhc_open_university_variable_info($options) {
  $variables = array(
    'uhc_open_university_contactblock' => array(
      'type' => 'string',
      'title' => t('HY - Open university contact block content', array(), $options),
      'localize' => TRUE,
    ),
  );
  return $variables;
}
