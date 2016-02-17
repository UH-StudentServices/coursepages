<?php
/**
 * @file
 * Drush integration for the Uhc dev feature.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_drush_command().
 */
function uhc_dev_feature_drush_command() {
  $items['uhc-delete-automatic-aliases'] = array(
    'drupal_dependencies' => array('pathauto'),
    'description' => 'Pathauto can delete all aliases. We want to delete only automatically generated aliases.',
    'callback' => 'uhc_dev_feature_delete_automatic_aliases',
    'aliases' => array('uhc-dam'),
  );
  return $items;
}

/**
 * Callback for deleting automatically generated aliases only.
 */
function uhc_dev_feature_delete_automatic_aliases() {
  $entities_to_preserve = array();

  // get aliases we want to preserve
  $entities = db_select('pathauto_state')
    ->fields('pathauto_state', array('entity_id'))
    ->condition('pathauto', 0)
    ->execute()
    ->fetchCol();

  foreach ($entities as $entity) {
    $entities_to_preserve[] = 'node/' . $entity;
  }

  // delete all except the ones we want to preserve
  if (!empty($entities_to_preserve)) {
    db_delete('url_alias')
      ->condition('source', $entities_to_preserve, 'NOT IN')
      ->execute();
  }
}
