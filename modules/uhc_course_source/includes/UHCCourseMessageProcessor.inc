<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCCourseMessageProcessor extends UHCMessageQueueProcessorBase {

  /**
   * Validate the item by checking its type. If it is "base" then we should be
   * dealing with right data.
   */
  public function validate() {
    return $this->getType() == 'base' ? self::VALIDATE_PASS : self::VALIDATE_FAIL;
  }

  public function process() {
    $id = $this->getId();
    $item = $this->getJSONBody();
    /** @var $migration CourseNodeMigration */
    $migration = Migration::getInstance('CourseNode', 'CourseNodeMigration', array('predefined_ids' => $id, 'predefined_item' => $item));
    $migration->prepareUpdate();
    $result = $migration->processImport();
    return $result == Migration::RESULT_COMPLETED ? UHCMessageQueueProcessorInterface::PROCESS_PROCESSED : NULL;
  }

  protected function getId() {
    $item = $this->getJSONBody();
    return $item->data[0]->TUNNISTE;
  }

}
