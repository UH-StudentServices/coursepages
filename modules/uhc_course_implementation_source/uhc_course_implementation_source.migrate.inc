<?php
/**
 * @file
 * Integrates with migrate module by introducing available migrations and their
 * dependencies.
 */

/**
 * Implements hook_migrate_api().
 */
function uhc_course_implementation_source_migrate_api() {
  return array(
    'api' => 2,
    'migrations' => array(
      'CourseImplementationNode' => array(
        'class_name' => 'CourseImplementationNodeMigration',
      ),
    ),
  );
}
