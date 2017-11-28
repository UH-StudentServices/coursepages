<?php
/**
 * @file
 * This is implementation file for SkippableItem class.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Class SkippableItem
 *
 * This class is used for returning item which should be skipped and can tell
 * the reason if given.
 */
class SkippableItem extends stdClass {
  private $reason;
  public function __construct($reason = '', array $params = array()) {
    $this->reason = format_string($reason, $params);
  }
  public function getReason() {
    return $this->reason;
  }
}
