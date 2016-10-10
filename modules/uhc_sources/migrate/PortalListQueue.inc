<?php
/**
 * @file
 * Implementation for migrate module providing list of items to import.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class PortalListQueue extends MigrateList {

  protected $action;
  protected $type;
  protected $idList;

  public function __construct($action, $type) {
    $this->action = $action;
    $this->type = $type;
    $this->loadIdList();
  }

  protected function loadIdList() {
    $queue = new UHOodiPrioritisedQueue();
    $this->idList = array();
    $items = array();
    while ($item = $queue->claimItem()) {
      $items[] = $item;
      if ($item->isAction($this->action) && $item->isType($this->type)) {
        $this->idList[] = $item->getId();
      }
    }

    // After looping items, we need to release them back to queue
    foreach ($items as $item) {
      $queue->releaseItem($item);
    }

  }

  /**
   * @return string
   */
  public function __toString() {
    return 'UHOodiPrioritisedQueue for types "' . $this->type . '" having action "' . $this->action . '"';
  }

  /**
   * @return Mixed, iterator or array
   */
  public function getIdList() {
    return $this->idList;
  }

  /**
   * @return int
   */
  public function computeCount() {
    return count($this->getIdList());
  }

}
