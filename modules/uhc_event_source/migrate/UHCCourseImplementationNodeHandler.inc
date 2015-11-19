<?php

class UHCCourseImplementationNodeHandler extends MigrateDestinationHandler {

  /**
   * Construct the class and register this handler for Nodes.
   */
  public function __construct() {
    $this->registerTypes(array('node'));
  }

  /**
   * Implement prepare method for reacting before course implementation entity
   * save by figuring out events of that course implementation and syncing them.
   *
   * @param $entity
   * @param $source_row
   */
  public function prepare($entity, $source_row) {
    if (isset($source_row->events)) {
      if ($this->purgeEvents($entity)) {
        $this->createNewEvents($entity, $source_row);
      }
    }
  }

  /**
   * Clears all events of corresponding course implementation. Returns TRUE when
   * all found events are removed (if any). Returns FALSE if could not be
   * removed properly.
   *
   * @param $entity
   * @return bool
   */
  protected function purgeEvents($entity) {

    // When we don't have is_new value set, we assume it is new because migrate
    // lets that property to be set during node_save() which is not yet called.
    // See more about the process in \MigrateDestinationNode::import()
    if (!isset($entity->is_new) || $entity->is_new) {
      // There should not be any events to purge, as this entity is new!
      return TRUE;
    }

    if ($entity->nid) {
      $old_node = node_load($entity->nid);
      // get all referenced event nodes and delete them
      if (isset($old_node->field_imp_ref_to_events_oodi[LANGUAGE_NONE])) {
        foreach ($old_node->field_imp_ref_to_events_oodi[LANGUAGE_NONE] as $referenced_event) {
          $nids[] = $referenced_event['target_id'];
        }
        node_delete_multiple($nids);
      }
      return TRUE;
    }

    // We should not get here, but if we do. Let logs know about this.
    watchdog('uhc_event_source', 'No events to purge due to missing nid.', array(), WATCHDOG_WARNING);
    return FALSE;
  }

  /**
   * Create event nodes and add their nids to the event reference field.
   * @param $entity
   * @param $source_row
   */
  static public function createNewEvents($entity, $source_row) {
    $events = array();
    if (!empty($source_row->events)) {
      foreach ($source_row->events as $event) {
        $event_entity = entity_create('node', array('type' => 'event', 'comment' => COMMENT_NODE_HIDDEN));
        $mapper = new UHCDrupalFieldMapperEvent($event, $event_entity, $source_row->title);
        $mapper->map();
        node_save($event_entity);
        $entity->field_imp_ref_to_events_oodi[LANGUAGE_NONE][] = array(
          'target_id' => $event_entity->nid
        );
      }
    }
  }

}
