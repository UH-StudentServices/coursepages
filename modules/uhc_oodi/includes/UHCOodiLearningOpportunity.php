<?php

/**
 * Class UHCOodiLearningOpportunity
 */
class UHCOodiLearningOpportunity {

  /**
   * @var \UHCOodiConnection
   *   The gateway to Oodi.
   */
  protected $connection;

  /**
   * @var \UHCOodiCache
   */
  protected $cache;

  /**
   * @var int
   *   How many seconds we set our expire for caching?
   */
  protected $expireAddition = 600;

  /**
   * @var array
   *   Contains configuration for translating description names into IDs.
   */
  protected $descriptionConfig;

  /**
   * @var object
   */
  protected $learningopportunity;

  /**
   * UHCOodiLearningOpportunity constructor.
   *
   * @param \UHCOodiConnection $connection
   *   Connection
   * @param \UHCOodiCache $cache
   *   Cache interface that for setting and getting values.
   */
  public function __construct(UHCOodiConnection $connection, UHCOodiCache $cache) {
    $this->connection = $connection;
    $this->cache = $cache;
  }

  /**
   * @param array $descriptionConfig
   */
  public function setConfigDescription(array $descriptionConfig) {
    $this->descriptionConfig = $descriptionConfig;
  }

  /**
   * Loads the learning opportunity.
   *
   * @param $id
   *   ID of the learning opportunity.
   * @return $this
   */
  public function loadById($id) {
    $cached_data = $this->cache->get($id);
    if (!$cached_data) {
      $response = $this->connection->getLearningOpportunity($id);
      $cached_data = $this->parseResponse($response);
      $this->cache->expire(REQUEST_TIME + $this->expireAddition)->set($id, $cached_data);
    }
    $this->learningopportunity = $cached_data;
    return $this;
  }

  /**
   * @param string $property
   *
   * @return null|string
   */
  public function getValue($property) {
    if (is_null($this->learningopportunity)) {
      watchdog('uhc_oodi', 'Tried getting value "@property" while learning opportunity is not loaded.', array('@property' => $property), WATCHDOG_WARNING);
      return '';
    }

    // Return the value
    return !empty($this->learningopportunity['data'][$property]) ? $this->learningopportunity['data'][$property] : NULL;
  }

  /**
   * @param $descriptionName
   *
   * @return array
   */
  public function getDescription($descriptionName) {
    if (is_null($this->learningopportunity)) {
      watchdog('uhc_oodi', 'Tried getting description "@description" while learning opportunity is not loaded.', array('@description' => $descriptionName), WATCHDOG_WARNING);
      return array();
    }

    /*
     * Example of JSON description should look like this:
     *
     * "descriptions": [
     *   {
     *     "texts": [
     *       {
     *         "langcode": "fi",
     *         "text": "<p>Tavoite. Lukuvuosi 2016-17.<\/p>"
     *       }
     *     ],
     *     "id": "1"
     *   },
     * ],
     */
    foreach ($this->descriptionConfig as $id => $name) {
      // If we find the name from the configuration
      if ($name == $descriptionName) {
        // And we got value for that ID
        $descriptions = $this->getValue('descriptions');
        if (!empty($descriptions) && is_array($descriptions)) {
          foreach ($descriptions as $value) {
            if ($value['id'] == $id) {
              return !empty($value['texts']) ? $value['texts'] : array();
            }
          }
        }
        break;
      }
    }

    return array();
  }

  /**
   * Parses given response and returns decoded JSON response.
   *
   * @param \stdClass $response
   *
   * @return mixed
   * @throws \Exception
   */
  protected function parseResponse(stdClass $response) {
    // Validate HTTP status
    if ($response->code != 200) {
      throw new Exception('Got unexpected HTTP status "' . $response->code . '" while requesting learning opportunity.');
    }

    // Response should be JSON, so parse it
    $decoded_json = drupal_json_decode($response->data);
    if (json_last_error()) {
      throw new Exception('Failed to parse JSON from response while requesting learning opportunity.');
    }

    // Validate JSON status
    if (empty($decoded_json['status']) || $decoded_json['status'] != 200) {
      throw new Exception('Failed to confirm JSON data status while requesting learning opportunity.');
    }

    return $decoded_json;
  }

}
