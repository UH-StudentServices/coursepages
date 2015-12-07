<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCMigrateJSONReader extends MigrateJSONReader {

  public function next() {

    migrate_instrument_start('MigrateJSONReader::next');

    if (empty($this->data)) {

      // Add a simple caching for the data we fetch (5 mins)
      $cache_time_minutes = 5;
      $cache_key = 'uhc_migrate_cache_' . md5($this->url);
      $cache_object = cache_get($cache_key);
      if ($cache_object) {
        $data = $cache_object->data;
      }
      else {

        // Aggregate into one object (as each language needs to be requested
        // separately).
        $responses = array();
        foreach (PortalMigrationBase::getSupportedLanguages() as $langcode) {
          $url = str_replace(':lang', $langcode, $this->url);
          $response = file_get_contents($url);
          $response_json_decoded = json_decode($response);
          if (!empty($response_json_decoded->data)) {
            $responses[$langcode] = $response_json_decoded->data;
          }
        }

        // Now aggregate all three languages into single item object using
        // english as base.
        $items = $responses['en'];
        $source_field_name = $this->getSourceFieldName($items);
        foreach ($items as $key => $item) {
          $items[$key]->name_translations = $this->aggregateMultilingualFields($item, $source_field_name, $responses);
          $items[$key]->{$source_field_name} = $items[$key]->name_translations['en'];
        }

        // If we have $responses then cache it, otherwise do not cache no
        // results so we can let next request try again.
        if (!empty($items)) {
          $data = $items;
          cache_set($cache_key, $data, 'cache', time() + (60 * $cache_time_minutes));
        }
        else {
          $data = NULL;
        }
      }

      $this->data = $data;
      $this->items = isset($this->data) ? $this->data : array();
    }

    $this->currentId = NULL;

    $this->currentElement = array_shift($this->items);

    if ($this->currentElement) {
      $this->currentId = $this->currentElement->{$this->idField};
    }

    migrate_instrument_stop('MigrateJSONReader::next');

  }

  /**
   * Method for getting source field name. Uses current migration as primarly
   * source, but if it can't determine it, it tries to guess.
   *
   * @param $items
   * @return string
   * @throws Exception
   */
  protected function getSourceFieldName($items) {

    // Primarly lets try to fetch this information from the migration class.
    // This might return NULL, we're performing rewind() within another
    // migration (when parent migration checks its dependency item count).
    $migration = Migration::currentMigration();
    if ($migration !== NULL && method_exists($migration, 'getSourceFieldName')) {
      return $migration->getSourceFieldName();
    }

    // Leave message, this should be rarely happening, so we want leave a note
    watchdog('uhc_taxonomy_source', 'Guessing source field name.', array(), WATCHDOG_WARNING);

    // In case of unknown source field name, lets guess
    $guessed_fields = array('name', 'description');
    foreach ($items as $item) {
      foreach ($guessed_fields as $guessed_field) {
        if (isset($item->$guessed_field)) {
          return $guessed_field;
        }
      }
    }

    // If we end up here, lets throw exception
    throw new Exception('Could not determine source field name.');
  }

  /**
   * Makes single field to be multilingual field using aggregated responses.
   *
   * @param $item
   * @param $field_name
   * @param $aggregated_responses
   * @return array
   */
  protected function aggregateMultilingualFields($item, $field_name, $aggregated_responses) {
    $field = array();
    foreach ($aggregated_responses as $langcode => $aggregated_items) {
      foreach ($aggregated_items as $aggregated_item) {
        if ($aggregated_item->{$this->idField} == $item->{$this->idField}) {
          // When ID identifier value matches
          $field[$langcode] = $aggregated_item->$field_name;
        }
      }
    }
    return $field;
  }

}
