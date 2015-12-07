<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

abstract class PortalDestinationNode extends MigrateDestinationNode {

  protected $translation_handler;

  /**
   * See https://www.drupal.org/node/1370740
   *
   * We get empty values and it makes migrate to actually store the value as
   * empty value, which we don't want to. The empty detection technique is
   * broken, so we deal it by post-processing mapped entities afterwards.
   *
   * @param $entity
   * @param $fields
   * @return mixed
   */
  protected function cleanupEmptyTextFields($entity, $fields) {
    foreach ($fields as $field) {
      if (isset($entity->$field)) {
        foreach ($entity->$field as $lang => $items) {
          foreach ($items as $delta => $item) {
            // Trim empty space, so we don't get "fake empties"
            if (isset($item['value'])) {
              $item['value'] = trim($item['value']);
            }
            if (isset($item['summary'])) {
              $item['summary'] = trim($item['summary']);
            }
            if (text_field_is_empty($item, array())) {
              unset($entity->{$field}[$lang][$delta]);
            }
          }
        }
      }
    }
    return $entity;
  }

  /**
   * Override MigrateDestinationNode::import(), so that we can adjust
   * system-of-record value depending on current item.
   *
   * We want to adjust it to be SOURCE for initial import and DESTINATION when
   * it has been already imported previously.
   *
   * See also: https://www.drupal.org/node/1461398
   *
   * @param $node
   *  Node object to build. Prefilled with any fields mapped in the Migration.
   * @param $row
   *  Raw source data object - passed through to prepare/complete handlers.
   * @return array
   *  Array of key fields (nid only in this case) of the node that was saved if
   *  successful. FALSE on failure.
   */
  public function import(stdClass $node, stdClass $row) {

    // Determine the system-of-record
    $system_of_record = Migration::SOURCE;
    if ($this->isContentMigrated($row)) {
      $this->prepareDestination($node, $row);
      $system_of_record = Migration::DESTINATION;
    }
    $migration = Migration::currentMigration();
    $migration->setSystemOfRecord($system_of_record);

    // Now proceed with the import
    return parent::import($node, $row);
  }

  /**
   * Determines whether given $row is already migrated. We determine it by
   * calling resolveNid() method which is supposed to be implemented by sub
   * classes.
   *
   * @param $row
   * @return bool
   */
  protected function isContentMigrated($row) {
    return !is_null($this->resolveNid($row->id));
  }

  /**
   * Prepares the destination node. This gets invoked when content has been
   * identified to be already migrated content and therefore the migration is
   * executed with system of record "DESTINATION".
   *
   * This sets certain assumptions for the $node object, like expecting node id
   * to be set etc.
   *
   * @see PortalDestinationNode::import()
   * @see MigrateDestinationNode::import()
   *
   * @param $node
   * @param $row
   */
  protected function prepareDestination($node, $row) {
    $node->nid = $this->resolveNid($row->id);
    $row->migrate_map_destid1 = $node->nid;
  }

  /**
   * Override MigrateDestinationNode::prepare() to define translations while
   * preparing the entity for entity save.
   *
   * @param $entity
   * @param stdClass $source_row
   */
  public function prepare($entity, stdClass $source_row) {
    parent::prepare($entity, $source_row);

    // When preparing having systemOfRecord as DESTINATION, we do not get node
    // type set (see MigrateDestinationNode::import()), so lets set it here.
    $migration = Migration::currentMigration();
    if ($migration->getSystemOfRecord() == Migration::DESTINATION) {
      $entity->type = $this->bundle;
    }

    // Let field translation know that we have translations from english to
    // finnish and from english to swedish. Fields should be already translated
    // in migration's field mapping.
    $entity->language = 'en';
    $this->translation_handler = entity_translation_get_handler('node', $entity);
    $this->translation_handler->setOriginalLanguage($entity->language);
    foreach (PortalMigrationBase::getSupportedLanguages() as $lang) {

      // Specify our translation
      $translation = array(
        'translate' => 0,
        'status' => 1,
        'language' => $lang,
      );

      // Set the source language of the translation
      if ($entity->language != $lang) {
        $translation['source'] = $entity->language;
      }

      $this->translation_handler->setTranslation($translation, $entity);
    }
  }

  /**
   * Override MigrateDestinationNode::complete(), so that translations gets set
   * during self::prepare(), but the translations should be saved after entity
   * has been saved.
   *
   * @param $entity
   * @param stdClass $source_row
   */
  public function complete($entity, stdClass $source_row) {
    parent::complete($entity, $source_row);
    if (isset($this->translation_handler)) {
      $this->translation_handler->saveTranslations();
    }

    /*
     * Problem:
     *   Some nodes doesn't get path aliases stored in all languages. Instead
     *   they get saved only to source language.
     *
     * Theory:
     *   That's how pathauto is designed. To respect node language and ignore
     *   field/entity translations.
     *
     *   To get quick overview, see:
     *     - https://www.drupal.org/node/1141554
     *     - https://www.drupal.org/node/1399620
     *     - https://www.drupal.org/node/1234924
     *
     * Workaround:
     *   Well, lets still generate path aliases in all languages anyway. Seems
     *   to work just fine :)
     */
    $migration = Migration::currentMigration();
    if (method_exists($migration, 'getSupportedLanguages') && module_exists('pathauto')) {
      foreach ($migration->getSupportedLanguages() as $langcode) {
        // Use "update" operation, as it works for new and existing aliases
        pathauto_node_update_alias($entity, 'update', array('message' => FALSE, 'language' => $langcode));
      }
    }
  }

}
