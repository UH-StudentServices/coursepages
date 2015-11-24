<?php
/**
 * @file
 * Describes the API of this module.
 */

/**
 * Inform your classes which deals with the items.
 *
 * @return array
 *   An array list of worker classes keyed by queue subscription names:
 *     'class_name': Class name which will be instantiated for validation and
 *                   processing.
 *     'implements': Interface name which the class should implement.
 */
function hook_uhc_activemq_connector_message_processor_info() {
  $default_queue_name = variable_get('uhc_activemq_connector_default_queue', 'doo.local1.kurssisivu.in');
  return array(
    $default_queue_name => array(
      array(
        'class_name' => 'MyMessageQueueProcessor',
        'implements' => 'UHCMessageQueueProcessorInterface',
      ),
    ),
  );
}