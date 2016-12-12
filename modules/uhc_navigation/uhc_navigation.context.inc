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
    'path' => array(
      'values' => array(
        '~node/*/edit' => '~node/*/edit',
        '~node/add/*' => '~node/add/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-user-menu' => array(
          'module' => 'system',
          'delta' => 'user-menu',
          'region' => 'menu_bar',
          'weight' => '-10',
        ),
        'menu-og-menu-single' => array(
          'module' => 'menu',
          'delta' => 'og-menu-single',
          'region' => 'menu_bar',
          'weight' => '-9',
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
