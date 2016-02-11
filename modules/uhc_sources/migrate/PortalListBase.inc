<?php
/**
 * @file
 * Implementation for listing items from portal backend.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
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
      watchdog('uhc_sources', 'Unable to parse IDs from JSON when requesting %url', array('%url' => $this->listUrl), WATCHDOG_WARNING);
    }
    else {
      foreach ($data['data'] as $item) {
        // Important! If item has been deleted, do not include to the list.
        if (!self::isDeleted($item)) {
          $ids[] = $item[$this->idField];
        }
      }
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
        $ids = $this->getIDsFromJSON($data);
        $count = count($ids);
      }
    }
    return $count;
  }

  /**
   * Determines whether list item is deleted or not. If item has property
   * 'deleted' and it's "true", then we consider it as deleted item.
   *
   * @param array $item
   * @return bool
   */
  public static function isDeleted(array $item) {
    return isset($item['deleted']) && $item['deleted'] == 'true';
  }

}
