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
function uhc_sources_drush_command() {
  $items = array();

  $items['uhc-sync'] = array(
    'description' => 'Creates or updates course implementation page with given course implementation id.',
    'arguments' => array(
      'course-implementation-id' => dt('Required course implementation id. Usually digit number.'),
    ),
    'options' => array(
      'source' => 'One of following source systems: "rest" or "esb-oodi". By default "rest".',
      'course_number' => 'Course number to be updated along with course implementation. Required when using "esb-oodi" as source system.',
    ),
    'required-arguments' => TRUE,
    'examples' => array(
      'drush uhc-sync 107694052' => dt('Synchronizes course implementation 107694052 using REST. Creates it if does not exist.'),
      'drush uhc-sync 107694052 --course_number="590155" --source="esb-oodi"' => dt('Synchronizes course implementation 107694052 using esb-oodi. Creates it if does not exist.'),
    ),
  );

  return $items;
}
