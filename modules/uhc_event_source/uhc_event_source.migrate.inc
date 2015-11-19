<?php
/**
 * @file
 * Integrates with migrate module.
 */

/**
 * Implements hook_migrate_api().
 */
function uhc_event_source_migrate_api() {
  return array(
    'api' => 2,
    'destination handlers' => array(
      'UHCCourseImplementationNodeHandler',
    ),
  );
}
