<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCGradesService {

  /** @var string */
  private $baseUrl;

  /** @var string */
  private $basePath;

  /** @var string */
  private $contentType;

  /** @var float */
  private $timeoutSeconds;

  /**
   * @param $baseUrl string Grades API base URL.
   * @param $timeoutSeconds float Timeout seconds.
   */
  public function __construct($baseUrl, $timeoutSeconds = 3.0) {
    $this->baseUrl = $baseUrl;
    $this->basePath = 'courseunitrealisations';
    $this->contentType = 'application/json';
    $this->timeoutSeconds = $timeoutSeconds;
  }

  /**
   * Gets information regarding the given realisation identified by ID.
   *
   * @param $realisationId int Realisation ID.
   * @return object Response object (@see drupal_http_request()).
   */
  public function get($realisationId) {
    $url = $this->baseUrl . $this->basePath . '/' . $realisationId . '/grades';

    return $this->request($url);
  }

  /**
   * Executes a request and returns the response.
   *
   * @param $url string URL.
   * @return object Response object.
   */
  private function request($url) {
    $options = $this->getRequestOptions();
    $response = drupal_http_request($url, $options);

    return $this->handleResponse($response);
  }

  /**
   * Constructs and returns request options.
   *
   * @return array Request options.
   */
  private function getRequestOptions() {
    $options = array(
      'headers' => array(
        'Content-Type' => $this->contentType,
      ),
      'method' => 'GET',
      'timeout' => $this->timeoutSeconds,
    );

    return $options;
  }

  /**
   * Handles the response.
   *
   * @param $response object Response object.
   * @return object The response object.
   */
  private function handleResponse($response) {
    $this->logResponse($response);

    return $response;
  }

  /**
   * Logs the response object on error response.
   *
   * @param $response object Response object.
   */
  private function logResponse($response) {
    if ($response->code !== 200) {
      $this->log('Response: @response', array('@response' => print_r($response, TRUE)), WATCHDOG_WARNING);
    }
  }

  /**
   * @see watchdog()
   */
  private function log($message, $variables = array(), $severity = WATCHDOG_NOTICE) {
    watchdog(get_class($this), $message, $variables, $severity);
  }
}
