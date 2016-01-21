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
  $items['uhc-course-handle-stubs'] = array(
    'description' => 'Imports all known created course stubs.',
    'callback' => 'uhc_course_source_handle_stubs',
  );
  $items['uhc-course-stubisize-courseless'] = array(
    'description' => 'Detects courseless implementations and creates course stubs for them.',
    'options' => array(
      'limit' => 'Set a limit on how many items to process. Default = 0 (all)',
    ),
    'callback' => 'uhc_course_source_stubisize_courseless',
  );
  return $items;
}

/**
 * Callback for handling course stubs.
 */
function uhc_course_source_handle_stubs() {
  /** @var $migration CourseNodeMigration */
  $migrate_stubs = variable_get('uhc_course_source_migrate_stubs', array());
  if (!empty($migrate_stubs)) {

    // Migrate
    $migration = Migration::getInstance('CourseNode', 'CourseNodeMigration', array('predefined_ids' => $migrate_stubs));
    $migration->processImport(array('idlist' => implode(',', $migrate_stubs), 'force' => TRUE));

    // Identify the stub courses that were handled by querying nodes by course
    // number, not having title 'Untitled course for...'.
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'course')
      // If the following property condition is modified, check the comment in
      // uhc_course_source_create_stub(). The format of the title is important.
      ->propertyCondition('title', 'Untitled course for%', 'NOT LIKE')
      ->fieldCondition('field_course_course_number', 'value', $migrate_stubs);

    // Load each node and remove the course numbers from $migrate_stubs
    $result = $query->execute();
    if (!empty($result['node'])) {
      $nodes = node_load_multiple(array_keys($result['node']));
      foreach ($nodes as $node) {
        if (isset($node->field_course_course_number[LANGUAGE_NONE][0]['value'])) {
          // Remove handled course number from the list. Note that the $key
          // might be "0" properly meaning that the first item of the array is a
          // match, therefore we do strict condition when deciding whether we
          // remove the item from the list.
          $key = array_search($node->field_course_course_number[LANGUAGE_NONE][0]['value'], $migrate_stubs);
          if ($key !== FALSE) {
            unset($migrate_stubs[$key]);
          }
        }
      }
    }

    // Update migrate_stubs variable
    variable_set('uhc_course_source_migrate_stubs', $migrate_stubs);
  }
}

/**
 * Drush command callback for detecting courseless implementations and creating
 * course stubs for them.
 */
function uhc_course_source_stubisize_courseless() {

  // Validate user input (limit -option)
  $limit = (int) drush_get_option('limit', 0);
  if ($limit < 0) {
    drush_set_error(DRUSH_APPLICATION_ERROR, 'Illegal limit option. Must be greater than or equal to 0.');
    exit(1);
  }

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
  if ($limit > 0) {
    $query->range(0, $limit);
  }
  $query = $query->execute();

  // Loop over each item.
  while ($item = $query->fetchAssoc()) {

    // Resolve course number using course implementation ID.
    $course_imp_node = node_load($item['nid']);
    if (empty($course_imp_node->field_imp_id[LANGUAGE_NONE][0]['value'])) {
      $skipped_unresolved++;
      continue;
    }
    $course_number = _uhc_sources_resolve_course_number($course_imp_node->field_imp_id[LANGUAGE_NONE][0]['value']);
    if (!$course_number) {
      $skipped_unresolved++;
      continue;
    }

    // Create a stub and keep track of all created stubs.
    $course_node = _uhc_course_source_create_stub($course_number);
    if (!empty($course_node->nid)) {

      // Update course implementation node, so that it has reference to recently
      // created course node.
      $course_imp_node->field_imp_reference_to_courses[LANGUAGE_NONE][] = array('target_id' => $course_node->nid);

      // Append nid to the list and prevent adding existing source_ids to the
      // list.
      $stub_nids[] = $course_node->nid;
      if (!in_array($course_number, $migrate_stubs)) {
        $migrate_stubs[] = $course_number;
        $processed++;
      }
      else {
        $skipped_duplicates++;
      }

    }

    // Save the course implementation node.
    node_save($course_imp_node);
  }

  // Save potentially modified $migrate_stubs.
  variable_set('uhc_course_source_migrate_stubs', $migrate_stubs);

  // Output the amount of processed items.
  $total = ($processed + $skipped_unresolved + $skipped_duplicates);
  drush_print(sprintf('Processed %d items in total (success %d, unresolved %d and duplicates %d).', $total, $processed, $skipped_unresolved, $skipped_duplicates));

}
