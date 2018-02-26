<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCMigrateMessageScannerService {

  protected $table;
  public function __construct($table) {
    $this->table = $table;
  }

  protected $lastLookupTimestamp;
  public function setLastLookupTimestamp(DateTime $timestamp) {
    $this->lastLookupTimestamp = $timestamp;
  }

  public function getCurrentLookupTimestamp() {
    return new DateTime();
  }

  protected $lookupMessages;
  protected $textDelimiter = PHP_EOL;
  public function setLookupMessagesFromText($text) {
    // Make Windows new lines consistent with Unix new lines
    $text = str_replace("\r\n", "\n", $text);
    // Set these messages for lookup
    $this->lookupMessages = explode($this->textDelimiter, $text);
  }

  protected $matches = array();
  protected function appendMatch($text) {
    $this->matches[] = $text;
  }

  public function getMatches() {
    return $this->matches;
  }

  public function performLookup() {
    foreach ($this->lookupMessages as $message) {

      // Setup query and validate it
      $query = db_select($this->table, 'msg')
        ->fields('msg', array('message'))
        ->condition('created', $this->lastLookupTimestamp->getTimestamp(), '>')
        ->condition('message', '%' . db_like($message) . '%', 'LIKE')
        ->execute();
      if (is_null($query)) {
        return FALSE;
      }

      // Append matches if any
      while ($item = $query->fetchAssoc()) {
        $this->appendMatch($item['message']);
      }

    }
    return TRUE;
  }

  public function shouldPerformLookup() {
    $shouldLastTimestamp = new DateTime();
    $shouldLastTimestamp->modify('-3 hours');
    return !empty($this->lookupMessages) && $shouldLastTimestamp > $this->lastLookupTimestamp;
  }

  /**
   * @return bool
   *   TRUE if lookup found matches. FALSE otherwise.
   */
  public function hasMatches() {
    return count($this->matches) > 0;
  }

}
