<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCMigrateJSONReader implements Iterator {

  /**
   * Value of the JSON file contents. When contens are loaded but not decoded,
   * the value is type of string. If it's decoded, then value is type of object.
   *
   * @var object|string
   */
  protected $fileContents;

  /**
   * Processed object of items that will be consumed during iteration.
   *
   * @var array
   */
  protected $items;

  /**
   * URL of the source JSON file.
   *
   * @var string
   */
  public $url;

  /**
   * Current element object when iterating.
   *
   * @var
   */
  protected $currentElement = NULL;

  /**
   * Value of the ID for the current element when iterating.
   *
   * @var string
   */
  protected $currentId = NULL;

  /**
   * Initialize the members.
   *
   * @param $json_url
   *  URL or filespec of the JSON file to be parsed.
   * @param $id_field
   *  Name of the field within each object containing its unique ID.
   * @throws Exception
   */
  public function __construct($json_url, $id_field) {
    $this->url = $json_url;
    $this->idField = $id_field;
  }

  /**
   * Implementation of Iterator::current().
   *
   * @return null|object
   */
  public function current() {
    return $this->currentElement;
  }

  /**
   * Implementation of Iterator::next().
   *
   * @return null|object
   */
  public function next() {
    migrate_instrument_start('UHCMigrateJSONReader::next');

    // Ensure we have processed contents
    $this->load();
    $this->process();

    $this->currentId = NULL;
    $this->currentElement = array_shift($this->items);
    if ($this->currentElement) {
      $this->currentId = $this->currentElement->{$this->idField};
    }

    migrate_instrument_stop('UHCMigrateJSONReader::next');
  }

  /**
   * Loads the resource.
   *
   * @return bool
   *   Returns TRUE when contents were loaded.
   */
  protected function load() {
    if (!empty($this->url)) {
      $this->fileContents = &drupal_static('UHCMigrateJSONReader_' . md5($this->url));
      if (!is_null($this->fileContents)) {
        // Contents comes from static cache
        return TRUE;
      }
      else {
        // TODO: What if we get non-string or empty string response?
        $this->fileContents = drupal_http_request($this->url)->data;
        return !empty($this->fileContents);
      }
    }
    return FALSE;
  }

  /**
   * Processes the resource.
   *
   * @return bool
   *   Returns TRUE when contents were processed.
   * @throws Exception
   *   Throws an exception when it can't decode file contents.
   */
  protected function process() {

    // When we have contents, we have something to process...
    if (!empty($this->fileContents)) {
      // When $this->items is an array, it means that it has already been
      // processed.
      if (is_array($this->items)) {
        return TRUE;
      }
      else {
        // Process file contents by decoding it and getting its data into
        // $this->items.
        $decoded = json_decode($this->fileContents);
        if (isset($decoded->status) && $decoded->status != 200) {
          watchdog('uhc_sources', 'Decoded response status returned "@status" instead of expected status 200.', array('@status' => $decoded->status), WATCHDOG_ERROR);
          throw new Exception('Response status was not 200');
        }

        if (isset($decoded->data) && is_array($decoded->data)) {
          $this->items = $decoded->data;
          return TRUE;
        }
        else {
          throw new Exception('Could not decode JSON contents.');
        }
      }
    }

    // There is nothing to process
    return FALSE;
  }

  /**
   * Implementation of Iterator::key().
   *
   * @return null|string
   */
  public function key() {
    return $this->currentId;
  }

  /**
   * Implementation of Iterator::valid().
   *
   * @return bool
   */
  public function valid() {
    return !empty($this->currentElement);
  }

  /**
   * Implementation of Iterator::rewind().
   *
   * @return void
   */
  public function rewind() {

    // Either convert object back to string for reprocessing or set it as NULL,
    // so it needs to be loaded again.
    if (is_object($this->fileContents)) {
      $this->fileContents = json_encode($this->fileContents);
    }
    else {
      $this->fileContents = NULL;
    }

    // Load the first element.
    $this->next();

  }

}
