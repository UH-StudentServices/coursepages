<?php
/**
 * @file
 * uhc_molecular_biosciences.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uhc_molecular_biosciences_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portal_main_biosciences';
  $context->description = 'Portal main page (Biosciences)';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'molecular-biosciences' => 'molecular-biosciences',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-uhc_liftups-block_2' => array(
          'module' => 'views',
          'delta' => 'uhc_liftups-block_2',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-ddc12e0f6574edc3850aacc947821543' => array(
          'module' => 'views',
          'delta' => 'ddc12e0f6574edc3850aacc947821543',
          'region' => 'content',
          'weight' => '-8',
        ),
        'views-uhc_course_liftups-block_2' => array(
          'module' => 'views',
          'delta' => 'uhc_course_liftups-block_2',
          'region' => 'content_suffix',
          'weight' => '-10',
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
  t('Portal main page (Biosciences)');
  t('section');
  $export['portal_main_biosciences'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portal_search_results_biosciences';
  $context->description = 'Portal search results page (biosciences)';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'molecular-biosciences/search' => 'molecular-biosciences/search',
        'molecular-biosciences/search/*' => 'molecular-biosciences/search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-ddc12e0f6574edc3850aacc947821543' => array(
          'module' => 'views',
          'delta' => 'ddc12e0f6574edc3850aacc947821543',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Portal search results page (biosciences)');
  t('section');
  $export['portal_search_results_biosciences'] = $context;

  return $export;
}
