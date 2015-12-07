<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

interface UHCMessageQueueProcessorInterface {

  /**
   * Returned by {@link UHCMessageQueueProcessorInterface::validate()} indicating
   * that item should specifically be processed.
   *
   * There should be only one class indicating that item should be processed.
   */
  const VALIDATE_PASS = 1;

  /**
   * Returned by {@link UHCMessageQueueProcessorInterface::validate()} indicating
   * that item should specifically *not to be processed*.
   */
  const VALIDATE_FAIL = NULL;

  /**
   * Used for indicate that the item has been processed by
   * {@link UHCMessageQueueProcessorInterface::process()}.
   */
  const PROCESS_PROCESSED = 1;

  /**
   * @param string $queueName
   *   The queue name where we're receiving processable item.
   * @param StompFrame $stompFrame
   *   The processable item.
   */
  public function __construct($queueName, StompFrame $stompFrame);

  /**
   * Validates the StompFrame given in constructor. There should be only one
   * class returning self::VALIDATE_PASS.
   *
   * @return self::VALIDATE_PASS | self::VALIDATE_FAIL
   */
  public function validate();

  /**
   * Processes the item somehow and acknowledge it by returning boolean TRUE.
   *
   * @return bool
   *   Return TRUE for indicating that queue extractor can acknowledge the item
   *   or FALSE, if something went wrong and item should be re-processed next
   *   time again.
   */
  public function process();

}
