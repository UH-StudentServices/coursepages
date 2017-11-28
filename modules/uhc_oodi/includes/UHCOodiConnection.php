<?php

/**
 * Class UHCOodiConnection
 */

class UHCOodiConnection {

  /**
   * @var string
   *   Endpoint where all requests are made against.
   */
  protected $endpoint = '';

  /**
   * @var array
   *   Contains all the path patterns used in this class.
   */
  protected $pathPatterns = array(
    'learningopportunity' => '/learningopportunities/:id',
  );

  /**
   * @var array
   *   Stores all options that are used when requesting Oodi. These options are
   *   passed as is to drupal_http_request() function.
   */
  protected $options = array('timeout' => NULL);

  /**
   * UHCOodiConnection constructor.
   *
   * @param string $endpoint
   *   All requests are made against this endpoint.
   * @param array $options
   *   This array options are used as is with drupal_http_request().
   */
  public function __construct($endpoint, array $options = array()) {

    // Normalize $endpoint
    if (!is_string($endpoint)) {
      throw new InvalidArgumentException('Endpoint must be string type.');
    }
    $parts = parse_url($endpoint);
    $this->endpoint = $parts['scheme'] . '://' . $parts['host'];
    if (!empty($parts['port'])) {
      $this->endpoint .= ':' . $parts['port'];
    }
    if (!empty($parts['path'])) {
      $this->endpoint .= $parts['path'];
    }

    $this->options = $options;
  }

  /**
   * @param $id
   *   ID of learning opportunity object.
   *
   * @return object
   *   Returns object that is returned by UHCOodiConnection::request().
   */
  public function getLearningOpportunity($id) {
    return $this->request(str_replace(':id', (string) $id, $this->pathPatterns['learningopportunity']));
  }

  /**
   * @param $path
   *   Path to requested with leading slash included.
   *
   * @return object
   *   Returns object by drupal_http_request().
   */
  public function request($path) {
    return drupal_http_request($this->endpoint . $path, $this->options);
  }

}
