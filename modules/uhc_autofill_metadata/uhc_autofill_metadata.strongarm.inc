<?php
/**
 * @file
 * uhc_autofill_metadata.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uhc_autofill_metadata_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uhc_shibboleth_metadata_debug_mode';
  $strongarm->value = 0;
  $export['uhc_shibboleth_metadata_debug_mode'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uhc_shibboleth_metadata_ou';
  $strongarm->value = 'HTTP_OU';
  $export['uhc_shibboleth_metadata_ou'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'uhc_shibboleth_metadata_realname';
  $strongarm->value = 'HTTP_CN';
  $export['uhc_shibboleth_metadata_realname'] = $strongarm;

  return $export;
}
