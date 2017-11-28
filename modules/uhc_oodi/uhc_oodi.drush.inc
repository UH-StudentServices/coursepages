<?php
/**
 * @file
 *   Drush integration file.
 */

/**
 * Implements hook_drush_cache_clear().
 */
function uhc_oodi_drush_cache_clear(&$types) {
  $types['uhc_oodi'] = 'drush_uhc_oodi_cache_flush';
}

/**
 * Callback for clearing caches.
 */
function drush_uhc_oodi_cache_flush() {
  cache_clear_all('*', 'cache_uhc_oodi', TRUE);
}
