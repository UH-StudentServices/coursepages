<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_drush_command().
 *
 * @See drush_parse_command() for a list of recognized keys.
 *
 * @return
 *   An associative array describing your command(s).
 */
function uhc_autofill_metadata_drush_command() {
  $items = array();

  $items['uhc-autofill-metadata-get-enrollments'] = array(
    'description' => 'Get enrollments for the given user identified by personal unique code.',
    'aliases' => array('uhc-ge'),
  );

  return $items;
}

/**
 * Callback for getting enrollments for the given user identified by personal
 * unique code.
 *
 * @param $personal_unique_code

 */
function drush_uhc_autofill_metadata_get_enrollments($personal_unique_code) {
  drush_print_r(uhc_autofill_metadata_get_enrollments($personal_unique_code));
}
