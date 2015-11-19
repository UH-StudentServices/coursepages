<?php
/**
 * @file
 * API examples of hooks that this module invokes.
 */

/**
 * @param $row
 *   Contains the source row given originally in Migration::prepareRow().
 * @return bool
 *   Return TRUE if you want to allow given course implementation source row.
 *   Other values will be interpreted as no-go for importing.
 */
function hook_uhc_course_implementation_source_allow_source_row($row) {
  // Returns TRUE if $row has "genetiikka" string in the $row->keywords property
  return in_array('genetiikka', $row->keywords);
}
