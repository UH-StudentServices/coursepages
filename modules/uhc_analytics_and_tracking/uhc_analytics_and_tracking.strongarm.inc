<?php
/**
 * @file
 * uhc_analytics_and_tracking.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uhc_analytics_and_tracking_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'googleanalytics_pages';
  $strongarm->value = 'admin
admin/*
batch
node/add*
user/*/*';
  $export['googleanalytics_pages'] = $strongarm;

  return $export;
}
