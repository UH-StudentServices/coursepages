<?php
/**
 * @file
 * Implementation for migration base of portal backend API.
 */

class PortalMigrationBase extends Migration {

  /**
   * This holds set of ids to be imported either defined through constructor
   * or by predefined idlist when calling MigrationBase::processImport().
   * @var array $predefined_ids
   */
  protected $predefined_ids = array();

  /**
   * Sets machine name if provided through arguments.
   *
   * @param array $arguments
   *   Array of arguments. I this class we're interested in:
   *     - machine_name: Given machine name for the migration.
   * @param null $group
   */
  public function __construct($arguments = array(), $group = NULL) {
    parent::__construct($group);
    if (!empty($arguments['machine_name'])) {
      $this->machineName = $arguments['machine_name'];
    }
  }

  /**
   * Sets the timestamp of last requested. This is used for constructing list
   * url when fetching for changes from previous request.
   *
   * @param DateTime|NULL $last_requested
   */
  protected function setLastRequested(DateTime $last_requested = NULL) {
    if (is_null($last_requested)) {
      $last_requested = new DateTime();
    }

    // This is a state variable of this migration. Declare variable name for
    // storing the timestamp.
    variable_set('uhc_sources_last_requested_' . drupal_strtolower($this->getMachineName()), $last_requested->getTimestamp());

  }

  /**
   * Gets the timestamp of when list url has been requested previously. This is
   * used for constructing list url when fetching for changes from previous
   * request.
   *
   * @return DateTime|null
   */
  protected function getLastRequested() {
    $last_requested_timestamp = variable_get('uhc_sources_last_requested_' . drupal_strtolower($this->getMachineName()));
    if (!empty($last_requested_timestamp)) {
      // Convert to DateTime from unix timestamp
      $last_requested = new DateTime();
      $last_requested->setTimestamp($last_requested_timestamp);
    }
    else {
      // No last imported timestamp. Then return default value which is decided
      // to be -1 month from today.
      $last_requested = new DateTime("-1 month");
    }
    return $last_requested;
  }

  /**
   * Constructs the last requested timestamp to the URL. This timestamp is
   * different from last imported by the fact that we keep track this timestamp
   * only if no errors occurs.
   *
   * @param $list_url
   * @return mixed
   */
  protected function constructLastRequested($list_url) {
    $last_requested = $this->getLastRequested();
    $list_url = str_replace(':since_date', $last_requested->format('dmYHis'), $list_url);
    MigrationBase::displayMessage('Requesting using list URL: ' . $list_url, 'status');
    return $list_url;
  }

  /**
   * Overrides MigrationBase::processImport().
   */
  public function processImport(array $options = array()) {

    // Keep track of ids we're specifically importing. @see self::postImport()
    if (!empty($options['idlist'])) {
      foreach (explode(',', $options['idlist']) as $id) {
        $id = trim($id);
        if (!empty($id)) {
          $this->predefined_ids[] = $id;
        }
      }
    }

    return parent::processImport($options);
  }

  /**
   * After import this method gets called.
   *
   * Set last reuqested if no errors has occured and if no specific items has
   * been imprted (if we import one item, we don't want to update timestamp for
   * for whole list!).
   *
   * Overrides Migration::postImport()
   */
  protected function postImport() {
    parent::postImport();
    if (count($this->predefined_ids) == 0 && $this->getMap()->errorCount() == 0) {
      $this->setLastRequested();
    }
  }

  /**
   * Prepends the host for the URL if it is missing. This allows configuration
   * to have host as an optional. Configuration may have only the path or the
   * full URL.
   *
   * @param $url
   * @return mixed
   */
  public static function prependHostIfMissing($url) {
    // Parse URL for identifying parts of the URL
    $parts = parse_url($url);
    $base_url = variable_get('uhc_sources_base_url', '');
    if (!empty($base_url) && (empty($parts['scheme']) || empty($parts['host']))) {
      return $base_url . $url;
    }
    return $url;
  }

  /**
   * Decodes all HTML entities and gets rid of unnecessary new lines (\n). Takes
   * in an string or array of strings to process it properly.
   *
   * @param mixed $string
   * @return array|null|string
   */
  public static function preprocessString($string) {
    if (is_array($string)) {
      // If value is an array, loop over its items and call recursively.
      foreach ($string as $key => $value) {
        $string[$key] = PortalMigrationBase::preprocessString($value);
      }
      return $string;
    }
    elseif(is_string($string)) {
      $string = str_replace(array("\n", '\\n'), ' ', $string);
      return html_entity_decode($string, null, 'UTF-8');
    }
    return NULL;
  }

  /**
   * Returns supported languages. Can be used for instance when dealing with
   * multilingual fields.
   * @return array
   */
  public static function getSupportedLanguages() {
    return array('en', 'fi', 'sv');
  }

  /**
   * Helper method for changing system of record. This allows Migration to make
   * dynamic system-of-records in cases where we want to import initial items
   * having SOURCE as system-of-record and afterwards being DESTINATION, because
   * some of fields might been edited after initial import (un-migrated fields).
   *
   * See about this topic: https://www.drupal.org/node/1461398
   *
   * @param int $systemOfRecord
   *   Should be one of Migration::SOURCE or Migration::DESTINATION.
   */
  public function setSystemOfRecord($systemOfRecord) {
    switch ($systemOfRecord) {
      case Migration::SOURCE:
      case Migration::DESTINATION:
        $this->systemOfRecord = $systemOfRecord;
        break;
    }
  }
}
