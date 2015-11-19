<?php
/**
 * @file
 * Implementation for loading individual items from portal backend.
 */

class PortalItemBase extends MigrateItemJSON {

  /**
   * @var object
   *   Holds the item object for cases when caller constructs the PortalItemBase
   *   with an decoded JSON object.
   */
  protected $json;

  /**
   * @param mixed $item
   *   An JSON item URL where to fetch the object. Or an JSON decoded object. If
   *   object is given, then use that directly instead loading JSON.
   * @param array $http_options
   *   Optional when $item is an URL and you want to pass some HTTP options.
   */
  public function __construct($item, $http_options = array()) {

    // When its a string, then we assume it's an URL
    if (is_string($item)) {
      $this->itemUrl = $item;
      $this->httpOptions = $http_options;
    }
    elseif (is_object($item)) {
      // If its an object, then we assume it's already fetched for us an no
      // loading is needed.
      $this->json = $item;
    }

  }

  /**
   * Item's JSON response has the data stored in "data" property. If the request
   * fails, the response includes "exception" attribute. Successful requests
   * include "data" and "md5" attributes. Error responses can be tested by
   * calling GET /error
   */
  public function getItem($id) {

    /*
     * 1. Resolve JSON object
     */
    if (!is_null($this->json)) {
      $json = $this->json;
    }
    else {
      // Load the JSON. Construct the URL and load the JSON
      $item_url = $this->constructItemUrl($id);
      $json = $this->loadJSONUrl($item_url);

      // If failed loading JSON
      if (!$json) {
        $this->uhcLogMessage($id, 'Loading of !objecturl failed', array('!objecturl' => $item_url));
        return NULL;
      }
    }

    /*
     * 2. Make sure, no exceptions are set in the object
     */
    if (isset($json->exception)) {
      $this->uhcLogMessage($id, 'Backend responded with exception "!exception" while fetching @id', array('!exception' => $json->exception->message, '!objecturl' => $id));
      return NULL;
    }

    /*
     * 3. If we want to simulate failure, we do it here now
     */
    $simulate_fail_item = variable_get('uhc_sources_simulate_failure');
    if (!is_null($simulate_fail_item) && $id == $simulate_fail_item) {
      $this->uhcLogMessage($id, 'Failed getting item due to simulated failure in "@id"', array('@id' => $id));
      return NULL;
    }

    /*
     * 4. Perform poor man's object sanity check by ensuring that data property
     *    exists with md5 checksum.
     */
    if (isset($json->data) && isset($json->md5)) {
      $return = $json->data;
      $return->md5 = isset($json->md5) ? $json->md5 : '';
      return $return;
    }

    // We do not expect to end up here
    $this->uhcLogMessage($id, 'Malformed response from REST backend while fetching @id', array('@id' => $id));
    return NULL;

  }

  /**
   * Helper method for logging messages in mapping table and to watchdog.
   * @param $id
   * @param $message
   * @param $params
   */
  protected function uhcLogMessage($id, $message, $params) {

    // Write to watchdog as alert and update message for mapping messages
    watchdog('uhc_sources', $message, $params, WATCHDOG_ALERT);
    $message = t($message, $params);

    // Save as error to mapping messages
    $migration = Migration::currentMigration();
    $migration->getMap()->saveMessage(array($id), $message, MigrationBase::MESSAGE_ERROR);

  }
}
