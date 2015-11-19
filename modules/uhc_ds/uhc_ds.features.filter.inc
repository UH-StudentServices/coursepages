<?php
/**
 * @file
 * uhc_ds.features.filter.inc
 */

/**
 * Implements hook_filter_default_formats().
 */
function uhc_ds_filter_default_formats() {
  $formats = array();

  // Exported format: Display Suite code.
  $formats['ds_code'] = array(
    'format' => 'ds_code',
    'name' => 'Display Suite code',
    'cache' => 1,
    'status' => 1,
    'weight' => 12,
    'filters' => array(),
  );

  // Exported format: Embed code.
  $formats['embed_code'] = array(
    'format' => 'embed_code',
    'name' => 'Embed code',
    'cache' => 1,
    'status' => 1,
    'weight' => 1,
    'filters' => array(),
  );

  return $formats;
}
