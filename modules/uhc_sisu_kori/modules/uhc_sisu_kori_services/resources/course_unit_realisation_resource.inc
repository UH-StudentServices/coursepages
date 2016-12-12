<?php
/**
 * @file
 * Handles services calls for course unit realisation.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Updates an course unit realisation entity.
 *
 * @param $otm_id
 * @param $course_unit_realisation
 * @return object
 */
function _course_unit_realisation_resource_update($otm_id, $course_unit_realisation) {
  $entities = entity_load('course_unit_realisation', array($otm_id));
  if (empty($entities)) {
    // Create new
    $new_entity = (object) array(
      'is_new' => TRUE,
      'otm_id' => $otm_id,
      'data' => serialize($course_unit_realisation),
    );
    entity_save('course_unit_realisation', $new_entity);
  }
  else {
    // Update existing
    $entity = reset($entities);
    $entity->data = serialize($course_unit_realisation);
    entity_save('course_unit_realisation', $entity);
  }
  return reset(entity_load('course_unit_realisation', array($otm_id)));
}

/**
 * Access callback for updating course unit realisations.
 * @throws ServicesArgumentException
 * @param $otm_id
 * @param $course_unit_realisation
 * @return bool
 */
function _course_unit_realisation_resource_update_access($otm_id, $course_unit_realisation) {
  // If identifier does not match with the object´s identifier, then throw an
  // argument exception
  if ($otm_id != $course_unit_realisation['otm_id']) {
    throw new ServicesArgumentException('Identifier did not match with the body object.', 'otm_id', 406, $course_unit_realisation);
  }

  // Update callback can either create new or update an existing entity
  return user_access('create course_unit_realisation') && user_access('edit course_unit_realisation');
}
