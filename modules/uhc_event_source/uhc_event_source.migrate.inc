<?php
/**
 * @file
 * Integrates with migrate module.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
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
