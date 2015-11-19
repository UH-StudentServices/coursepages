<?php
/**
 * @file
 * uhc_navigation.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uhc_navigation_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'navigation';
  $context->description = 'Provides menu blocks';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'context' => array(
      'values' => array(
        '~open_university_header_and_footer' => '~open_university_header_and_footer',
      ),
    ),
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'responsive_navigation-1' => array(
          'module' => 'responsive_navigation',
          'delta' => '1',
          'region' => 'menu_bar',
          'weight' => '-10',
        ),
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'menu_bar',
          'weight' => '-98',
        ),
      ),
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provides menu blocks');
  t('Sitewide');
  $export['navigation'] = $context;

  return $export;
}
