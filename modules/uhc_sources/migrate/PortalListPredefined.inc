<?php

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
