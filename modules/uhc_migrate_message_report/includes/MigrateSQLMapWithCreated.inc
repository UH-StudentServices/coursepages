<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Extended class that main priority is to support created timestamp while
 * performing mapping for migrations.
 */
class MigrateSQLMapWithCreated extends MigrateSQLMap {

  /**
   * Extends saveMessage method by using one field more when inserting message.
   *
   * @param array $source_key
   * @param string $message
   * @param int $level
   *
   * @throws \Exception
   */
  public function saveMessage($source_key, $message, $level = Migration::MESSAGE_ERROR) {
    // Source IDs as arguments
    $count = 1;
    if (is_array($source_key)) {
      foreach ($source_key as $key_value) {
        $fields['sourceid' . $count++] = $key_value;
        // If any key value is not set, we can't save - print out and abort
        if (!isset($key_value)) {
          print($message);
          return;
        }
      }
      $fields['level'] = $level;
      $fields['message'] = $message;

      // This is the addition to original method!
      $fields['created'] = REQUEST_TIME;

      $this->connection->insert($this->messageTable)
        ->fields($fields)
        ->execute();
    }
    else {
      // TODO: What else can we do?
      Migration::displayMessage($message);
    }
  }

}
