<?php
/**
 * @file
 * uhc_open_university.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uhc_open_university_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'open_university_header_and_footer';
  $context->description = '';
  $context->tag = 'Open university';
  $context->conditions = array(
    'uhc_open_university_context_condition_open_university_section' => array(
      'values' => array(
        'uhc_open_university_context_condition_open_university_section' => 'uhc_open_university_context_condition_open_university_section',
      ),
    ),
    'path' => array(
      'values' => array(
        'open-university' => 'open-university',
        'open-university/*' => 'open-university/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'responsive_navigation-2' => array(
          'module' => 'responsive_navigation',
          'delta' => '2',
          'region' => 'menu_bar',
          'weight' => '-9',
        ),
        'menu_block-open-university-nav-level2' => array(
          'module' => 'menu_block',
          'delta' => 'open-university-nav-level2',
          'region' => 'menu_bar',
          'weight' => '-8',
        ),
        'uhc_open_university-uhc_open_university_contactblock' => array(
          'module' => 'uhc_open_university',
          'delta' => 'uhc_open_university_contactblock',
          'region' => 'info_footer',
          'weight' => '-10',
        ),
        'menu-menu-open-university-footer-link' => array(
          'module' => 'menu',
          'delta' => 'menu-open-university-footer-link',
          'region' => 'info_footer',
          'weight' => '-9',
        ),
        'menu-menu-open-university-some-links' => array(
          'module' => 'menu',
          'delta' => 'menu-open-university-some-links',
          'region' => 'info_footer',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Open university');
  $export['open_university_header_and_footer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'open_university_search_facets';
  $context->description = '';
  $context->tag = 'Open university';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'open-university' => 'open-university',
        'open-university/search' => 'open-university/search',
        'open-university/search/*' => 'open-university/search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-c2214b19d79a77c1c1558fab6eb67c87' => array(
          'module' => 'views',
          'delta' => 'c2214b19d79a77c1c1558fab6eb67c87',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Open university');
  $export['open_university_search_facets'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portal_main_open_university';
  $context->description = 'Portal main page (open university)';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'open-university' => 'open-university',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-uhc_liftups-block_1' => array(
          'module' => 'views',
          'delta' => 'uhc_liftups-block_1',
          'region' => 'content',
          'weight' => '-10',
        ),
        'views-6e81312883288ad7f0d23af96a88ead6' => array(
          'module' => 'views',
          'delta' => '6e81312883288ad7f0d23af96a88ead6',
          'region' => 'content',
          'weight' => '-9',
        ),
        'views-uhc_course_liftups-block_1' => array(
          'module' => 'views',
          'delta' => 'uhc_course_liftups-block_1',
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
  t('Portal main page (open university)');
  t('section');
  $export['portal_main_open_university'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'portal_search_results_open_university';
  $context->description = 'Portal search results page (open university)';
  $context->tag = 'section';
  $context->conditions = array(
    'path' => array(
      'values' => array(
        'open-university/search' => 'open-university/search',
        'open-university/search/*' => 'open-university/search/*',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'views-6e81312883288ad7f0d23af96a88ead6' => array(
          'module' => 'views',
          'delta' => '6e81312883288ad7f0d23af96a88ead6',
          'region' => 'content',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Portal search results page (open university)');
  t('section');
  $export['portal_search_results_open_university'] = $context;

  return $export;
}
