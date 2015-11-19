<?php
/**
 * @file
 * uhc_navigation.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uhc_navigation_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_animate_1';
  $strongarm->value = '1';
  $export['responsive_navigation_animate_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_depth_1';
  $strongarm->value = '-1';
  $export['responsive_navigation_depth_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_insert_1';
  $strongarm->value = 'before';
  $export['responsive_navigation_insert_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_jsclass_1';
  $strongarm->value = 'js-enabled';
  $export['responsive_navigation_jsclass_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_label_1';
  $strongarm->value = 'Menu';
  $export['responsive_navigation_label_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_menu_1';
  $strongarm->value = 'og-menu-single:0';
  $export['responsive_navigation_menu_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_name_1';
  $strongarm->value = 'Responsive Navigation';
  $export['responsive_navigation_name_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_openpos_1';
  $strongarm->value = 'relative';
  $export['responsive_navigation_openpos_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_respect_expand_1';
  $strongarm->value = '1';
  $export['responsive_navigation_respect_expand_1'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'responsive_navigation_transition_1';
  $strongarm->value = '400';
  $export['responsive_navigation_transition_1'] = $strongarm;

  return $export;
}
