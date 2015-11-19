<?php
/**
 * @file
 * Class implementation file for connecting to ActiveMQ and perform
 * request-response types of calls with ESB.
 */

class UHCESB {

  /**
   * Holds STOMP connection for reading responses.
   *
   * @var \FuseSource\Stomp\Stomp
   */
  protected $in;

  /**
   * Holds STOMP connection for sending requests.
   * @var \FuseSource\Stomp\Stomp
   */
  protected $out;

  /**
   * Holds information about performed request and its response.
   * @var array
   */
  protected $debugInfo;

  /**
   * Construct connections with given queue base. Queue base name will determine
   * from which queues messages will be sent to and read from.
   *
   * @param $connectionSettings
   * @param $queueBase
   * @throws \Exception
   */
  public function __construct(array $connectionSettings, $queueBase) {
    if (($library = libraries_load('stomp_php')) && !empty($library['loaded'])) {

      // Construct debugging information
      $this->clearDebug();

      // Set in/out queues
      $this->setQueueIn($queueBase);
      $this->setQueueOut($queueBase);

      // Username and passwords for connecting
      $options = $connectionSettings;
      $user = $options['credentials']['user'];
      $pass = $options['credentials']['pass'];
      $connection = $options['brokers'][0];

      // Create queue consumer where responses are read from.
      $this->in = new \FuseSource\Stomp\Stomp($connection);
      $this->in->connect($user, $pass);

      // Create queue producer where requests are sent to.
      $this->out = new \FuseSource\Stomp\Stomp($connection);
      $this->out->connect($user, $pass);

    }
    else {
      throw new \Exception('Could not load the library.');
    }
  }

  /**
   * Queue in information is the queue name we'll be reading incoming messages.
   */
  protected $queueIn;
  protected function setQueueIn($queue_base) {
    $this->queueIn = $queue_base . '.in';
  }

  /**
   * Queue out information is the queue name we'll be pushing messages out.
   */
  protected $queueOut;
  protected function setQueueOut($queue_base) {
    $this->queueOut = $queue_base . '.out';
  }

  /**
   * Perform and request to ActiveMQ populating the message with proper routing
   * information. This will send out an message using an "out" queue and then
   * reads the response from "in" queue.
   *
   * @param array $properties
   * @param null $body
   * @return \FuseSource\Stomp\Frame
   */
  public function request(array $properties, $body = NULL) {

    // Always ensure we have this header to let ESB route the response correctly
    $properties['esb_reply_to'] = $this->queueIn;

    // Set destination names
    $inQueue = '/queue/' . $this->queueIn;
    $outQueue = '/queue/' . $this->queueOut;

    // Generate random correlation id, and append it to outgoing message
    $generated_correlation_id = md5(uniqid(rand(), true));
    $properties['correlation-id'] = $generated_correlation_id;

    // Keep track of assembled request
    $this->clearDebug();
    $this->debugInfo['request']['properties'] = $properties;
    $this->debugInfo['request']['body'] = $body;

    // Subscribe to incoming messages and send out the request and then read in
    // the response.
    $this->in->subscribe($inQueue);
    $response = NULL;
    if ($this->out->send($outQueue, $body, $properties)) {
      while ($message = $this->in->readFrame()) {
        $this->debugInfo['responses']['all'][] = $message;
        if ($message->headers['correlation-id'] == $generated_correlation_id) {
          $this->in->ack($message);
          $response = $message;
          break;
        }
       }
    }
    $this->in->unsubscribe($inQueue);

    // Keep track of response
    $this->debugInfo['responses']['match'] = $response;

    return $response;
  }

  /**
   * Clears and constructs debugging information.
   */
  public function clearDebug() {
    $this->debugInfo = array(
      'request' => array('properties' => array(), 'body' => NULL),
      'responses' => array('all' => NULL, 'match' => NULL),
    );
  }

  /**
   * Returns debugging information.
   * @return array
   */
  public function getDebugInfo() {
    return $this->debugInfo;
  }

  /**
   * On destruct, disconnect in/out queues.
   */
  public function __destruct() {
    $this->in->disconnect();
    $this->out->disconnect();
  }

}
