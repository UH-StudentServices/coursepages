<?php
/**
 * @file
 * Drush integration for the module.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_drush_command().
 */
function uhc_course_implementation_drush_command() {
  $items['uhc-course-implementation-cleanup-header-images'] = array(
    'description' => 'Cleans up all header images from given image file ids.',
    'arguments' => array(
      'fids' => dt('File IDs separated by comma.'),
    ),
    'callback' => 'uhc_course_implementation_cleanup_header_images',
    'aliases' => array('uhc-cichi'),
  );
  return $items;
}

/**
 * Drush callback for cleaning up header images.
 *
 * @param string $fids
 */
function uhc_course_implementation_cleanup_header_images($fids = '') {
  $fids = explode(',', $fids);
  if (empty($fids)) {
    drush_print('No image headers to process.');
    return;
  }

  // Query all nodes that have given header images
  $query = db_select('field_data_field_imp_header_image', 'image');
  $query->fields('image', array('entity_id'));
  $query->condition('image.field_imp_header_image_fid', $fids, 'IN');
  $results = $query->execute();

  // Load each node and clear its header image
  while ($result = $results->fetchAssoc()) {
    $node_ids[] = $result['entity_id'];
    $node = node_load($result['entity_id']);
    $node->field_imp_header_image = array();
    node_save($node);
    drush_print('Cleaned up header image out from node ' . $result['entity_id']);
    watchdog('uhc_course_implementation', 'Cleaned up header image out from node @nid', array('@nid' => $result['entity_id']), WATCHDOG_INFO);
  }
}
