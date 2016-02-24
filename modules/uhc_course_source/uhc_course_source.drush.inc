<?php
/**
 * @file
 * Drush integration file.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_drush_command().
 */
function uhc_course_source_drush_command() {
  $items = array();
  $items['uhc-course-link-courseless'] = array(
    'description' => 'Detects courseless implementations and links them to courses.',
    'options' => array(
      'limit' => 'Set a limit on how many items to process. Default = 0 (all)',
    ),
    'callback' => 'uhc_course_source_link_courseless',
  );
  return $items;
}

/**
 * Drush command callback for detecting courseless implementations and linking
 * them to course implementations.
 */
function uhc_course_source_link_courseless() {

  // Detect courseless implementations by querying nodes that have no reference
  // to courses. Create course stubs and update path aliases to get proper URLs
  // (such as /A12345/76789010).
  $processed = 0;
  $skipped_unresolved = 0;
  $skipped_duplicates = 0;
  $migrate_stubs = variable_get('uhc_course_source_migrate_stubs', array());

  // Query all nodes that are missing reference to courses.
  $query = db_select('node', 'n')->fields('n')->fields('r', array('entity_id'));
  $query->leftJoin("field_data_field_imp_reference_to_courses", "r", "(r.entity_type = 'node' AND r.bundle = 'course_implementation' AND r.entity_id = n.nid)");
  $query->condition('n.type', 'course_implementation');
  $query->isNull('r.entity_id');
  $query = $query->execute();
  while ($item = $query->fetchAssoc()) {
    _uhc_course_source_link_courseless_handle($item['nid'], $skipped_unresolved, $skipped_duplicates, $processed, $migrate_stubs);
  }

  // Query all nodes that are refering to non-existing courses.
  $query = db_select('field_data_field_imp_reference_to_courses', 'r')->fields('r')->fields('n', array('nid'));
  $query->leftJoin("node", "n", "(r.entity_type = 'node' AND r.bundle = 'course_implementation' AND n.nid = r.field_imp_reference_to_courses_target_id)");
  $query->isNull('n.nid');
  $query = $query->execute();
  while ($item = $query->fetchAssoc()) {
    _uhc_course_source_link_courseless_handle($item['entity_id'], $skipped_unresolved, $skipped_duplicates, $processed, $migrate_stubs);
  }

  // Save potentially modified $migrate_stubs.
  variable_set('uhc_course_source_migrate_stubs', $migrate_stubs);

  // Output the amount of processed items.
  $total = ($processed + $skipped_unresolved + $skipped_duplicates);
  drush_print(sprintf('Processed %d items in total (success %d, unresolved %d and duplicates %d).', $total, $processed, $skipped_unresolved, $skipped_duplicates));

}

/**
 * Helper function for handling item that needs to link given course
 * implementation to an course.
 *
 * @param $course_imp_nid
 *   Course implementation NID value that needs handling.
 * @param $skipped_unresolved
 *   Number of unresolved items that gets updated during the handling process.
 * @param $skipped_duplicates
 *   Number of duplicates items that gets updated during the handling process.
 * @param $processed
 *   Number of processed items that gets updated during the handling process.
 * @param $migrate_stubs
 *   List of migratable stubs that gets appended during the handling process.
 * @throws Exception
 */
function _uhc_course_source_link_courseless_handle($course_imp_nid, &$skipped_unresolved, &$skipped_duplicates, &$processed, &$migrate_stubs) {

  // Resolve course number using course implementation ID.
  $course_imp_node = node_load($course_imp_nid);
  if (empty($course_imp_node->field_imp_id[LANGUAGE_NONE][0]['value'])) {
    $skipped_unresolved++;
    drush_print($course_imp_nid . ' was handled as unresolved due to missing imp id');
    return;
  }
  $course_number = _uhc_sources_resolve_course_number($course_imp_node->field_imp_id[LANGUAGE_NONE][0]['value']);
  if (!$course_number) {
    drush_print($course_imp_nid . ' was handled as unresolved due to missing course number');
    $skipped_unresolved++;
    return;
  }

  // Ensure that we create proper reference to given course node.
  $course_node = _uhc_course_source_get($course_number);
  if (!empty($course_node->nid)) {
    // Update course implementation node, so that it has reference to recently
    // created course node.
    $course_imp_node->field_imp_reference_to_courses[LANGUAGE_NONE][0] = array('target_id' => $course_node->nid);
    node_save($course_imp_node);

    // Append nid to the list and prevent adding existing source_ids to the
    // list. Some course nodes might have been migrated already, but that's OK
    // to add it anyways. Lets not bother now to separate those and decide
    // which are added to stub list and which not.
    $stub_nids[] = $course_node->nid;
    if (!in_array($course_number, $migrate_stubs)) {
      $migrate_stubs[] = $course_number;
      drush_print($course_imp_nid . ' was handled as processed with course number "' . $course_number . '" => ' . $course_node->nid);
      $processed++;
    }
    else {
      drush_print($course_imp_nid . ' was handled as duplicate due to course number "' . $course_number . '" already been handled => ' . $course_node->nid);
      $skipped_duplicates++;
    }
  }
}

/**
 * Returns course node for given course number. If it doesn't exist, it creates
 * an stub.
 *
 * @param $course_number
 * @return bool
 */
function _uhc_course_source_get($course_number) {
  // Try to find local course node from given course number
  $resolved_nid = _uhc_course_source_resolve_nid($course_number);
  if (!is_null($resolved_nid)) {
    return node_load($resolved_nid);
  }
  else {
    return uhc_sources_create_stub_node($course_number, 'course');
  }
}
