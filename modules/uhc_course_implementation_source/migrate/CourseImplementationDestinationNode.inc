<?php
/**
 * @file
 * Implements class for migration which prepares the entity for multilingualism.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class CourseImplementationDestinationNode extends PortalDestinationNode {

  /**
   * Prepare entity by setting up translations.
   *
   * @param $entity
   * @param stdClass $source_row
   */
  public function prepare($entity, stdClass $source_row) {
    parent::prepare($entity, $source_row);

    // All these fields should be text fields which *MAY* contain empty values.
    // Go through these multilingual values and detect whether they're empty or
    // not, so that system will store them correctly.
    $potentially_empty_fields = array(
      'title_field',
      'field_imp_teacher',
      'field_imp_teacher_number',
      'field_imp_fee',
      'field_imp_locality',
      'field_imp_giver_locality',
      'field_imp_course_organiser',
      'field_working_methods',
      'field_timing',
      'field_evaluation',
      'field_req_prerequisites',
      'field_target_group',
      'field_additional_info',
      'field_study_materials',
      'field_contents',
      'field_conduct',
      'field_objective',
      'field_responsible_person',
      'field_rel_to_other_study_units',
      'field_open_uni_registration',
      'field_imp_events_json',
    );
    $entity = $this->cleanupEmptyTextFields($entity, $potentially_empty_fields);
  }

  /**
   * Helper method for resolving node id from given course number.
   *
   * @param $course_implementation_id
   * @return mixed|null
   */
  static function resolveNid($course_implementation_id) {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'course_implementation')
      ->fieldCondition('field_imp_id', 'value', $course_implementation_id)
      ->execute();
    return !empty($result['node']) ? reset(array_keys($result['node'])) : NULL;
  }

  /**
   * Overrides complete() for logging purposes.
   *
   * @param $entity
   * @param stdClass $source_row
   */
  public function complete($entity, stdClass $source_row) {
    parent::complete($entity, $source_row);
    $this->log($entity);
  }

  /**
   * Displays course implementation number as a migration status message.
   *
   * @param $entity
   */
  public function log($entity) {
    $implementation_id = !empty($entity->field_imp_id[LANGUAGE_NONE][0]['value']) ? $entity->field_imp_id[LANGUAGE_NONE][0]['value'] : '';

    if (!empty($implementation_id)) {
      $message = t('Migrated course implementation @implementation_id.', array('@implementation_id' => $implementation_id));
      MigrationBase::displayMessage($message, 'status');
    }
  }
}
