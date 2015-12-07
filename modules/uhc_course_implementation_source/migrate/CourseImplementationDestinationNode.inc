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

    // Teaching language.
    $entity->field_imp_teaching_language = array();
    if (is_array($source_row->languages)) {
      foreach ($source_row->languages as $value) {
        if (drupal_strlen($value) != 0) {
          $entity->field_imp_teaching_language[LANGUAGE_NONE][] = array('value' => drupal_strtolower($value));
        }
      }
    }

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
      'field_timing',
      'field_evaluation',
      'field_req_prerequisites',
      'field_target_group',
      'field_additional_info',
      'field_study_materials',
      'field_contents',
      'field_conduct',
      'field_objective',
    );
    $entity = $this->cleanupEmptyTextFields($entity, $potentially_empty_fields);

    // Generate URLs for each language/course by using language codes and id
    $lang_codes = array(
      'fi' => '1',
      'sv' => '2',
      'en' => '6',
    );
    $id = $source_row->id;
    foreach (PortalMigrationBase::getSupportedLanguages() as $lang) {
      $lang_code = $lang_codes[$lang];
      $url = 'https://weboodi.helsinki.fi/hy/alkusivu.jsp?Kieli=:langcode&avattavaSivu=opettaptied&OpetTap=:id';
      $url = preg_replace(array_fill(0, count($lang_code), '/:langcode/'), $lang_code, $url, 1);
      $url = preg_replace(array_fill(0, count($id), '/:id/'), $id, $url, 1);
      $entity->field_imp_canonical_url[$lang][0]['url'] = $url;
    }
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
    $implementation_id = !empty($entity->field_imp_id['und'][0]['value']) ? $entity->field_imp_id['und'][0]['value'] : '';

    if (!empty($implementation_id)) {
      $message = t('Migrated course implementation @implementation_id.', array('@implementation_id' => $implementation_id));
      MigrationBase::displayMessage($message, 'status');
    }
  }
}
