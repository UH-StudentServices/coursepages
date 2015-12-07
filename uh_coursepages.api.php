<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Allows modules to introduce staff roles. Should return array list of role
 * ids.
 */
function hook_uh_coursepages_staff_roles() {
  $staff_roles[] = user_role_load_by_name('editor-in-chief of communications')->rid;
  return $staff_roles;
}
