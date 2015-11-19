<?php
/**
 * @file
 * uhc_open_university.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uhc_open_university_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_animate_2';
  $strongarm->value = '1';
  $export['responsive_navigation_animate_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_depth_2';
  $strongarm->value = '-1';
  $export['responsive_navigation_depth_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_insert_2';
  $strongarm->value = 'before';
  $export['responsive_navigation_insert_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_jsclass_2';
  $strongarm->value = 'js-enabled';
  $export['responsive_navigation_jsclass_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_label_2';
  $strongarm->value = 'Menu';
  $export['responsive_navigation_label_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_menu_2';
  $strongarm->value = 'menu-open-university-navigation:0';
  $export['responsive_navigation_menu_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_name_2';
  $strongarm->value = 'Responsive Navigation Open University';
  $export['responsive_navigation_name_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_number';
  $strongarm->value = '2';
  $export['responsive_navigation_number'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_openpos_2';
  $strongarm->value = 'relative';
  $export['responsive_navigation_openpos_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_respect_expand_2';
  $strongarm->value = '1';
  $export['responsive_navigation_respect_expand_2'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_transition_2';
  $strongarm->value = '400';
  $export['responsive_navigation_transition_2'] = $strongarm;

  return $export;
}
