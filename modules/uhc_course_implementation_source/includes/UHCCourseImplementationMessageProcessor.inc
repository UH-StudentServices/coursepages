<?php

class UHCCourseImplementationMessageProcessor extends UHCMessageQueueProcessorBase {

  /**
   * Validate the item by checking its type. If it is "realisation" then we
   * should be dealing with right data.
   */
  public function validate() {
    return $this->getType() == 'realisation' ? self::VALIDATE_PASS : self::VALIDATE_FAIL;
  }

  public function process() {
    $id = $this->getId();
    $item = $this->getJSONBody();
    /** @var $migration CourseImplementationNodeMigration */
    $migration = Migration::getInstance('CourseImplementationNode', 'CourseImplementationNodeMigration', array('predefined_ids' => $id, 'predefined_item' => $item));
    $migration->prepareUpdate();
    $result = $migration->processImport();
    return $result == Migration::RESULT_COMPLETED ? UHCMessageQueueProcessorInterface::PROCESS_PROCESSED : NULL;
  }

  protected function getId() {
    $item = $this->getJSONBody();
    return $item->data->info[0]->TOTEUTUS_ID;
  }

}
