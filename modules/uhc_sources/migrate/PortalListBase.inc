<?php
/**
 * @file
 * Implementation for listing items from portal backend.
 */

class PortalListBase extends MigrateListJSON {

  protected $idField;

  public function __construct($idField, $list_url, $http_options = array()) {
    parent::__construct($list_url, $http_options);
    $this->idField = $idField;
  }

  /**
   * All portal data is not in the top level in the JSON object. It's under
   * "data" property and therefore we need to override ID identification.
   *
   * @param array $data
   * @return array
   */
  protected function getIDsFromJSON(array $data) {
    $ids = array();
    // If data missing, make a log entry about this.
    if (!isset($data['data'])) {
      watchdog('uhc_sources', 'Unable to parse IDs from JSON when requesting %url', array('%url' => $this->listUrl), WATCHDOG_ERROR);
    }
    foreach ($data['data'] as $item) {
      $ids[] = $item[$this->idField];
    }
    return $ids;
  }

  /**
   * Our count must be calculated from ['data'] items.
   */
  public function computeCount() {
    $count = 0;
    if (empty($this->httpOptions)) {
      $json = file_get_contents($this->listUrl);
    }
    else {
      $response = drupal_http_request($this->listUrl, $this->httpOptions);
      $json = $response->data;
    }
    if ($json) {
      $data = drupal_json_decode($json);
      if (!empty($data['data'])) {
        $count = count($data['data']);
      }
    }
    return $count;
  }

}
