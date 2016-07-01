<?php
/**
 * @file
 * Views integration.
 */

/**
 * Implements hook_views_default_views_alter().
 */
function uhc_feedback_views_default_views_alter(&$views) {
  if (isset($views['feedback_messages'])) {
    $handler =& $views['feedback_messages']->display['default']->handler;
    /* Field: Feedback: I would like to get a response to my feedback */
    $handler->display->display_options['fields']['field_feedback_respond']['id'] = 'field_feedback_respond';
    $handler->display->display_options['fields']['field_feedback_respond']['table'] = 'field_data_field_feedback_respond';
    $handler->display->display_options['fields']['field_feedback_respond']['field'] = 'field_feedback_respond';
    $handler->display->display_options['fields']['field_feedback_respond']['label'] = 'Respond to my feedback';
    $handler->display->display_options['fields']['field_feedback_respond']['type'] = 'list_key';
    /* Field: Feedback: Email */
    $handler->display->display_options['fields']['field_feedback_email']['id'] = 'field_feedback_email';
    $handler->display->display_options['fields']['field_feedback_email']['table'] = 'field_data_field_feedback_email';
    $handler->display->display_options['fields']['field_feedback_email']['field'] = 'field_feedback_email';
    $handler->display->display_options['fields']['field_feedback_email']['label'] = 'E-mail';
  }
}
