<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class PortalListPredefined extends MigrateList {

  protected $idList;

  public function __construct(array $idList) {
    $this->idList = $idList;
  }

  public function __toString() {
    if ($this->getIdList()) {
      return 'IDs: ' . implode(', ', $this->getIdList());
    }
    else {
      return 'No IDs in the list';
    }
  }

  public function getIdList() {
    return $this->idList;
  }

  public function computeCount() {
    return count($this->getIdList());
  }

}
