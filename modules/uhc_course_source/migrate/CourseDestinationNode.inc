<?php
/**
 * @file
 * Implements class for migration which prepares the entity for multilingualism.
 */

class CourseDestinationNode extends PortalDestinationNode {

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
      'field_evaluation',
      'field_req_prerequisites',
      'field_target_group',
      'field_timing',
      'field_objective',
      'field_contents',
      'field_additional_info',
      'field_conduct',
      'field_study_materials',
      'field_course_subject',
    );
    $entity = $this->cleanupEmptyTextFields($entity, $potentially_empty_fields);
  }

  /**
   * Helper method for resolving node id from given course number.
   *
   * @param $course_number
   * @return mixed|null
   */
  static function resolveNid($course_number) {
    $query = new EntityFieldQuery();
    $result = $query->entityCondition('entity_type', 'node')
      ->entityCondition('bundle', 'course')
      ->fieldCondition('field_course_course_number', 'value', $course_number)
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
   * Displays course number as a migration status message.
   *
   * @param $entity
   */
  public function log($entity) {
    $course_number = !empty($entity->field_course_course_number['und'][0]['value'])
      ? $entity->field_course_course_number['und'][0]['value']
      : '';

    if (!empty($course_number)) {
      $message = t('Migrated course @course_number.', array('@course_number' => $course_number));
      MigrationBase::displayMessage($message, 'status');
    }
  }
}
