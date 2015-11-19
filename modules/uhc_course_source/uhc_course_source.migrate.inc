<?php
/**
 * @file
 * Integrates with migrate module.
 */

/**
 * Implements hook_migrate_api().
 */
function uhc_course_source_migrate_api() {
  return array(
    'api' => 2,
    'migrations' => array(
      'CourseNode' => array(
        'class_name' => 'CourseNodeMigration',
      ),
      'CourseThemeTerm' => array(
        'class_name' => 'CourseThemeTermMigration',
      ),
    ),
  );
}
