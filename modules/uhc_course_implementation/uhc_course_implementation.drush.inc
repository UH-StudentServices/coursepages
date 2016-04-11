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
  $items['uhc-course-implementation-ensure-titles-in-all-languages'] = array(
    'description' => 'Ensure all course implementations have a title in all supported languages.',
    'arguments' => array(
      'limit' => dt('Limit on how many nodes to process.'),
    ),
    'callback' => 'uhc_course_implementation_ensure_titles_in_all_languages',
    'aliases' => array('uhc-cietial'),
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

/**
 * Drush callback for ensuring all course implementations have a title in all
 * supported languages.
 *
 * @param int $limit Limit on how many nodes to process.
 */
function uhc_course_implementation_ensure_titles_in_all_languages($limit = 500) {
  $query = "SELECT id.entity_id as 'nid'
    FROM {field_data_title_field} tf
    JOIN {field_data_field_imp_id} id ON id.entity_id = tf.entity_id
    WHERE tf.bundle = 'course_implementation'
    GROUP BY tf.entity_id
    HAVING count(tf.entity_id) < 3
    LIMIT " . (int) $limit;

  $result = db_query($query);
  $nids = array();

  foreach ($result as $row) {
    $nids[] = $row->nid;
  }

  // Free memory.
  $row = null;
  unset($row);
  $query = NULL;
  unset($query);
  $result = NULL;
  unset($result);

  $node_count = count($nids);

  foreach ($nids as $index => $nid) {
    $memory_usage = round((memory_get_usage() / 1024 / 1024), 2);
    drush_print("Updating node $index/$node_count. Memory usage: $memory_usage MB");
    $node = node_load($nid);

    // Missing 'fi'.
    if (!isset($node->title_field['fi'])) {
      if (isset($node->title_field['sv'])) {
        $node->title_field['fi'] = $node->title_field['sv'];
      }
      elseif (isset($node->title_field['en'])) {
        $node->title_field['fi'] = $node->title_field['en'];
      }
    }

    // Missing 'sv'.
    if (!isset($node->title_field['sv'])) {
      if (isset($node->title_field['fi'])) {
        $node->title_field['sv'] = $node->title_field['fi'];
      }
      elseif (isset($node->title_field['en'])) {
        $node->title_field['sv'] = $node->title_field['en'];
      }
    }

    // Missing 'en'.
    if (!isset($node->title_field['en'])) {
      if (isset($node->title_field['fi'])) {
        $node->title_field['en'] = $node->title_field['fi'];
      }
      elseif (isset($node->title_field['sv'])) {
        $node->title_field['en'] = $node->title_field['sv'];
      }
    }

    node_save($node);

    // Free memory.
    $index = NULL;
    unset($index);
    $nid = NULL;
    unset($nid);
    $node = NULL;
    unset($node);
    $memory_usage = NULL;
    unset($memory_usage);
  }

  drush_print("Done.");
}
