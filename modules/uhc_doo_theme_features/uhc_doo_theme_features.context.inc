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
        'uhc_doo_theme_features-last_updated' => array(
          'module' => 'uhc_doo_theme_features',
          'delta' => 'last_updated',
          'region' => 'action_footer',
          'weight' => '-10',
        ),
        'uhc_doo_theme_features-up_anchor' => array(
          'module' => 'uhc_doo_theme_features',
          'delta' => 'up_anchor',
          'region' => 'action_footer',
          'weight' => '0',
        ),
        'uh_coursepages-uhc_contact_logo_block' => array(
          'module' => 'uh_coursepages',
          'delta' => 'uhc_contact_logo_block',
          'region' => 'footer',
          'weight' => '-8',
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
        'uh_coursepages-uhc_logo_block' => array(
          'module' => 'uh_coursepages',
          'delta' => 'uhc_logo_block',
          'region' => 'top_bar_main',
          'weight' => '-10',
        ),
        'menu-menu-header-links' => array(
          'module' => 'menu',
          'delta' => 'menu-header-links',
          'region' => 'top_bar_sub',
          'weight' => '-10',
        ),
        'locale-language' => array(
          'module' => 'locale',
          'delta' => 'language',
          'region' => 'top_bar_sub',
          'weight' => '-8',
        ),
        'uhc_avatar-avatar_block' => array(
          'module' => 'uhc_avatar',
          'delta' => 'avatar_block',
          'region' => 'menu_bar',
          'weight' => '-36',
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
