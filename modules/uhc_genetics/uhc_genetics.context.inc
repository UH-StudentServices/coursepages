<?php
/**
 * @file
 * uhc_genetics.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uhc_genetics_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portal_main';
  $context->description = 'Portal main page';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'genetics' => 'genetics',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-uhc_liftups-main' => array(
          'module' => 'views',
          'delta' => 'uhc_liftups-main',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views--exp-uhc_search-desktop' => array(
          'module' => 'views',
          'delta' => '-exp-uhc_search-desktop',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-uhc_course_liftups-latest' => array(
          'module' => 'views',
          'delta' => 'uhc_course_liftups-latest',
          'region' => 'content_suffix',
          'weight' => '-19',
        ),
      ),
    ),
    'theme_html' => array(
      'class' => 'search-main-page',
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Portal main page');
  t('section');
  $export['portal_main'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portal_search_results';
  $context->description = 'Portal search results page';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'genetics/search' => 'genetics/search',
        'genetics/search/*' => 'genetics/search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views--exp-uhc_search-desktop' => array(
          'module' => 'views',
          'delta' => '-exp-uhc_search-desktop',
          'region' => 'content',
          'weight' => '-24',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Portal search results page');
  t('section');
  $export['portal_search_results'] = $context;

  return $export;
}
