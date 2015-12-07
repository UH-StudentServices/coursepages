<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */


class UHCMessageQueueProcessorBase implements UHCMessageQueueProcessorInterface {

  protected $queueName;
  protected $stompFrame;
  protected $jsonBody;

  public function __construct($queueName, StompFrame $stompFrame) {
    $this->queueName = $queueName;
    $this->stompFrame = $stompFrame;
    $this->extractBody();
  }

  public function validate() {
    watchdog(__CLASS__, '@queue: Validation item <pre>@item</pre>', array('@queue' => $this->queueName, '@item' => print_r($this->stompFrame,1)), WATCHDOG_DEBUG);
  }

  public function process() {
    watchdog(__CLASS__, '@queue: Processing item <pre>@item</pre>', array('@queue' => $this->queueName, '@item' => print_r($this->stompFrame,1)), WATCHDOG_DEBUG);
  }

  /**
   * This will extract the body by reading message's body and decoding from JSON
   * format.
   */
  protected function extractBody() {
    if (isset($this->stompFrame->body) && !empty($this->stompFrame->body)) {
      if ($jsonBody = json_decode($this->stompFrame->body)) {
        $this->jsonBody = $jsonBody;
      }
    }
  }

  /**
   * This gets you JSON decoded object.
   *
   * @return mixed
   *   JSON decoded object or NULL.
   */
  public function getJSONBody() {
    return $this->jsonBody;
  }

  /**
   * Gets the type of the message, so called may conclude how to process the
   * body.
   *
   * @return mixed
   *   Expected string or NULL.
   */
  public function getType() {
    return $this->getJSONBody()->type;
  }

  /**
   * Static method for logging messages in name of this module.
   *
   * @param $message
   * @param array $variables
   * @param int $severity
   * @param null $link
   */
  static public function log($message, $variables = array(), $severity = WATCHDOG_NOTICE, $link = NULL) {
    watchdog('uhc_activemq_connector', $message, $variables, $severity, $link);
  }

}
