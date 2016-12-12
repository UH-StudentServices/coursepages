<?php
/**
 * @file
 * Handles services calls for study events.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Updates an course unit realisation entity.
 *
 * @param $otm_id
 * @param $study_event
 * @return object
 */
function _study_event_resource_update($otm_id, $study_event) {
  $entities = entity_load('study_event', array($otm_id));
  if (empty($entities)) {
    // Create new
    $new_entity = (object) array(
      'is_new' => TRUE,
      'otm_id' => $otm_id,
      'data' => serialize($study_event),
    );
    entity_save('study_event', $new_entity);
  }
  else {
    // Update existing
    $entity = reset($entities);
    $entity->data = serialize($study_event);
    entity_save('study_event', $entity);
  }
  return reset(entity_load('study_event', array($otm_id)));
}

/**
 * Access callback for updating study events.
 * @throws ServicesArgumentException
 * @param $otm_id
 * @param $study_event
 * @return bool
 */
function _study_event_resource_update_access($otm_id, $study_event) {
  // If identifier does not match with the object´s identifier, then throw an
  // argument exception
  if ($otm_id != $study_event['otm_id']) {
    throw new ServicesArgumentException('Identifier did not match with the body object.', 'otm_id', 406, $study_event);
  }

  // Update callback can either create new or update an existing entity
  return user_access('create study_event') && user_access('edit study_event');
}
