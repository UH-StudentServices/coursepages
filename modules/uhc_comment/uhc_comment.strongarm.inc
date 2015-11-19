<?php
/**
 * @file
 * uhc_comment.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uhc_comment_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_anonymous_course_implementation';
  $strongarm->value = 0;
  $export['comment_anonymous_course_implementation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_course_implementation';
  $strongarm->value = '2';
  $export['comment_course_implementation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_mode_course_implementation';
  $strongarm->value = 0;
  $export['comment_default_mode_course_implementation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_per_page_course_implementation';
  $strongarm->value = '10';
  $export['comment_default_per_page_course_implementation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_default_sorting_course_implementation';
  $strongarm->value = '2';
  $export['comment_default_sorting_course_implementation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_form_location_course_implementation';
  $strongarm->value = 1;
  $export['comment_form_location_course_implementation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_preview_course_implementation';
  $strongarm->value = '0';
  $export['comment_preview_course_implementation'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'comment_subject_field_course_implementation';
  $strongarm->value = 0;
  $export['comment_subject_field_course_implementation'] = $strongarm;

  return $export;
}
