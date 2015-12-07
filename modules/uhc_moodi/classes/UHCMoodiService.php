<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCMoodiService {

  /** @var string */
  private $baseUrl;

  /** @var string */
  private $basePath;

  /** @var string */
  private $clientId;

  /** @var string */
  private $clientToken;

  /** @var string */
  private $contentType;

  /** @var float */
  private $timeoutSeconds;

  /**
   * @param $baseUrl string Moodi API base URL.
   * @param $clientId string Moodi client ID.
   * @param $clientToken string Moodi client token.
   * @param $timeoutSeconds float Timeout seconds.
   */
  public function __construct($baseUrl, $clientId, $clientToken, $timeoutSeconds = 3.0) {
    $this->baseUrl = $baseUrl;
    $this->basePath = '/api/v1/courses';
    $this->clientId = $clientId;
    $this->clientToken = $clientToken;
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
    $url = $this->baseUrl . $this->basePath . '/' . $realisationId;

    return $this->requestGet($url);
  }

  /**
   * Creates a new course area for the given realisation identified by ID.
   *
   * @param $realisationId int Realisation ID.
   * @return object Response object (@see drupal_http_request()).
   */
  public function create($realisationId) {
    $url = $this->baseUrl . $this->basePath;

    $data = new stdClass();
    $data->realisationId = (int) $realisationId;
    $data = json_encode($data);

    return $this->requestPost($url, $data);
  }

  /**
   * Executes a GET request.
   *
   * @see request()
   */
  private function requestGet($url) {
    return $this->request($url, 'GET');
  }

  /**
   * Executes a POST request.
   *
   * @see request()
   */
  private function requestPost($url, $data) {
    return $this->request($url, 'POST', $data);
  }

  /**
   * Executes a request and returns the response.
   *
   * @param $url string URL.
   * @param $method string Request method.
   * @param $data null|mixed Optional request data.
   * @return object Response object.
   */
  private function request($url, $method, $data = NULL) {
    $options = $this->getRequestOptions($method, $data);
    $response = drupal_http_request($url, $options);

    return $this->handleResponse($response);
  }

  /**
   * Constructs and returns request options.
   *
   * @param $method string Request method.
   * @param $data null|mixed Optional request data.
   * @return array Request options.
   */
  private function getRequestOptions($method, $data) {
    $options = array(
      'headers' => array(
        'client-id' => $this->clientId,
        'client-token' => $this->clientToken,
        'Content-Type' => $this->contentType,
      ),
      'method' => $method,
      'timeout' => $this->timeoutSeconds,
    );

    if (isset($data)) {
      $options['data'] = $data;
    }

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
   * Logs the response object.
   *
   * @param $response object Response object.
   */
  private function logResponse($response) {
    $responseCode = $response->code;
    $responseData = isset($response->data) ? $response->data : NULL;

    if (in_array($responseCode, array(200, 404))) {
      $this->log('Response: @code @data', array('@code' => $responseCode, '@data' => $responseData));
    } else {
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
