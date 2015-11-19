<?php
/**
 * @file
 * Drush integration file.
 */

/**
 * Implements hook_drush_command().
 */
function uhc_activemq_connector_drush_command() {
  $items = array();

  $items['uhc-activemq-connector-process-queue'] = array(
    'description' => 'Processes ActiveMQ messages.',
    'aliases' => array('uhc-pq'),
    'arguments' => array(
      'queue-name' => dt('Optional queue name. If omitted, then default queue name will be used.'),
    ),
  );

  $items['uhc-activemq-connector-add-to-queue'] = array(
    'description' => 'Drops into the queue an item using given filepath contents as message body.',
    'aliases' => array('uhc-atq'),
    'arguments' => array(
      'filepath' => dt('The filepath of the message body file.'),
      'queue-name' => dt('Optional queue name. If omitted, then default queue name will be used.'),
    ),
    'examples' => array(
      'drush uhc-atq ./examples/toteutus.json' => dt('Creates an message having toteutus.json file contents as message body.'),
    ),
  );

  $items['uhc-activemq-connector-request-esb'] = array(
    'description' => 'Requests doo.oodi service through ESB with given values.',
    'aliases' => array('uhc-request-esb'),
    'arguments' => array(
      'method' => dt('Method to be called. Example: "doo.oodi.codes.semesters"'),
      'parameters' => dt('Optional parameters for method as an query string. Example: "course_id=12345&organisation=H930"'),
      'body' => dt('Optional body for the request.'),
    ),
    'examples' => array(
      'drush uhc-request-esb doo.oodi.kurssisivu.courseunitrealisations.data jakso_code=590155' => dt('Requests 590155 course data.'),
      'drush uhc-request-esb doo.oodi.kurssisivu.courseunitrealisations.events course_id=103132867&langcode=fi' => dt('Requests events of course realistation 103132867 data in finnish.'),
    ),
  );

  return $items;
}

/**
 * Callback for request through ESB.
 */
function drush_uhc_activemq_connector_request_esb($method, $parameters_str = '', $body = NULL) {

  // Parameters are passed as query string (through commandline), so lets
  // extract them.
  $parameters = array();
  parse_str($parameters_str, $parameters);

  // Request ESB through UHCESB class
  $options = variable_get('uhc_activemq_connector_settings');
  $default_queue_base = variable_get('uhc_activemq_connector_default_queue_base', 'doo.dev.kurssisivu');
  $esb = new UHCESB($options, $default_queue_base);
  $properties = $parameters + array(
    'method' => $method,
  );
  $esb->request($properties, $body);

  drush_print_r($esb->getDebugInfo());
}

/**
 * Callback for processing UHC's queued messages.
 *
 * @param string $queue_name Queue name.
 */
function drush_uhc_activemq_connector_process_queue($queue_name = NULL) {
  // If queue name is not given, lets use default queue name.
  $queue_name = is_null($queue_name) ? variable_get('uhc_activemq_connector_default_queue', 'doo.local1.kurssisivu.in') : $queue_name;
  uhc_activemq_connector_process_queue($queue_name);
}

/**
 * Callback for dropping an message to the queue.
 * @param $filepath
 *   File path containing the message body contents.
 * @param $queue_name
 *   Optional queue name. If omitted, then default queue name will be used.
 */
function drush_uhc_activemq_connector_add_to_queue($filepath, $queue_name = NULL) {

  // If queue name is not given, lets use default queue name.
  $queue_name = is_null($queue_name) ? variable_get('uhc_activemq_connector_default_queue', 'doo.local1.kurssisivu.in') : $queue_name;

  // Prepend print working directory
  if ($_SERVER['PWD']) {
    $filepath = $_SERVER['PWD'] . '/' . $filepath;
  }

  // Ensure that file exist and is readable
  if (!file_exists($filepath) || !is_readable($filepath)) {
    drush_set_error('File ' . $filepath . ' does not exist or is not readable.');
    exit(1);
  }

  // Connect to STOMP
  $stomp = uhc_activemq_connector_get_stomp_instance();

  // Queue an message
  try {
    $stomp->send("/queue/" . $queue_name, file_get_contents($filepath));
  }
  catch (\FuseSource\Stomp\Exception\StompException $e) {
    UHCMessageQueueProcessorBase::log('Error creating queue item: @exception', array('@exception' => $e->getMessage()), WATCHDOG_ERROR);
  }

  // Disconnect from STOMP
  $stomp->disconnect();
}
