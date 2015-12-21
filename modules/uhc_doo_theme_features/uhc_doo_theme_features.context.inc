<?php
/**
 * @file
 * uhc_doo_theme_features.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uhc_doo_theme_features_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'logged_in';
  $context->description = '';
  $context->tag = 'User Authenticated';
  $context->conditions = array(
    'user' => array(
      'values' => array(
        'administrator' => 'administrator',
        'authenticated user' => 'authenticated user',
        'course administrator' => 'course administrator',
        'editor-in-chief of communications' => 'editor-in-chief of communications',
        'teacher' => 'teacher',
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'uhc_avatar-avatar_block' => array(
          'module' => 'uhc_avatar',
          'delta' => 'avatar_block',
          'region' => 'menu_bar',
          'weight' => '-99',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('User Authenticated');
  $export['logged_in'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'sitewide';
  $context->description = 'Context triggered sitewide';
  $context->tag = 'Sitewide';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'system-main' => array(
          'module' => 'system',
          'delta' => 'main',
          'region' => 'content',
          'weight' => '-9',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Context triggered sitewide');
  t('Sitewide');
  $export['sitewide'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'theme_footer';
  $context->description = 'Provides theme footer blocks';
  $context->tag = 'Theme';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'hy_content_suffix-hy_content_suffix_last_updated' => array(
          'module' => 'hy_content_suffix',
          'delta' => 'hy_content_suffix_last_updated',
          'region' => 'action_footer',
          'weight' => '-10',
        ),
        'hy_content_suffix-hy_content_suffix_up_anchor' => array(
          'module' => 'hy_content_suffix',
          'delta' => 'hy_content_suffix_up_anchor',
          'region' => 'action_footer',
          'weight' => '0',
        ),
        'hy_contact-hy_contact_logo_block' => array(
          'module' => 'hy_contact',
          'delta' => 'hy_contact_logo_block',
          'region' => 'footer',
          'weight' => '-8',
        ),
        'hy_links-hy_links_link_block' => array(
          'module' => 'hy_links',
          'delta' => 'hy_links_link_block',
          'region' => 'footer',
          'weight' => '-10',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provides theme footer blocks');
  t('Theme');
  $export['theme_footer'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'theme_header';
  $context->description = 'Provides theme header blocks';
  $context->tag = 'Theme';
  $context->conditions = array(
    'sitewide' => array(
      'values' => array(
        1 => 1,
      ),
    ),
  );
  $context->reactions = array(
    'block' => array(
      'blocks' => array(
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'top_bar',
          'weight' => '-10',
        ),
        'uh_coursepages-uhc_logo_block' => array(
          'module' => 'uh_coursepages',
          'delta' => 'uhc_logo_block',
          'region' => 'top_bar',
          'weight' => '-9',
        ),
        'menu-menu-header-links' => array(
          'module' => 'menu',
          'delta' => 'menu-header-links',
          'region' => 'top_bar',
          'weight' => '-8',
        ),
      ),
    ),
  );
  $context->condition_mode = 0;

  // Translatables
  // Included for use with string extractors like potx.
  t('Provides theme header blocks');
  t('Theme');
  $export['theme_header'] = $context;

  return $export;
}
