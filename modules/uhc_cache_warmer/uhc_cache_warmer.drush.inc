<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_drush_command().
 */
function uhc_cache_warmer_drush_command() {
  $items = array();

  $items['uhc-cache-warmer-create-hub-pages-file'] = array(
    'description' => 'Create a hub pages file for the cache_warmer module.',
    'aliases' => array('uhc-cwchpf'),
    'arguments' => array(
      'filepath' => dt('Filepath where list of paths will be generated to'),
      'limit' => dt('Limit the amount of page paths in the hub pages file'),
    ),
  );

  return $items;
}

/**
 * Callback for creating the hub pages file for the cache_warmer module. The
 * file is written outside of the docroot.
 */
function drush_uhc_cache_warmer_create_hub_pages_file($filepath = NULL, $limit = 10) {
  if (is_null($filepath)) {
    drush_set_error('File path was invalid or missing');
    exit;
  }
  if (!is_writable($filepath)) {
    drush_set_error('Given file path is not writable');
    exit;
  }
  $data = implode("\n", uhc_cache_warmer_get_page_paths($limit));
  @file_put_contents($filepath, $data);
}

/**
 * @param int $limit The max amount of page paths to return.
 * @return array Paths to published subject nodes ("fi/node/123").
 */
function uhc_cache_warmer_get_page_paths($limit) {
  $results = db_query(
    'select nid from {node} where type = :type and status = :status',
    array(':type' => 'subject', ':status' => 1)
  );

  $page_paths = array();

  foreach ($results as $result) {
    $page_paths[] = "fi/node/$result->nid";
  }

  return array_rand(array_flip($page_paths), $limit);
}
