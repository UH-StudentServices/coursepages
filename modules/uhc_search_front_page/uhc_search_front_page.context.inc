<?php
/**
 * @file
 * uhc_search_front_page.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uhc_search_front_page_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portal_search_results_front_page';
  $context->description = 'Portal search results page (front page)';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'search' => 'search',
        'search/*' => 'search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-0580398bf6a2f9d60b32760e9900b13c' => array(
          'module' => 'views',
          'delta' => '0580398bf6a2f9d60b32760e9900b13c',
          'region' => 'content_prefix',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Portal search results page (front page)');
  t('section');
  $export['portal_search_results_front_page'] = $context;

  return $export;
}
