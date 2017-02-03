<?php
/**
 * @file
 * UHC Favorites module file for pages.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Menu callback function for a page where visitors may see their favorites.
 */
function uhc_favorites_page() {
  $element = array();

  // Include lead text that describes this page
  // @TODO: Make this maintainable?
  $lead_text = t('You can collect interesting courses as favorites and send the list by e-mail. Favorites are stored in the page cookie and remain there for a year. Favorites will be lost if you delete your browser’s cookies.');
  $element['lead_text'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('intro-text')),
    '#children' => '<p>' . $lead_text . '</p>',
  );

  // Include lead text that describes this page
  $element['favorites_list'] = array(
    '#type' => 'container',
    '#attributes' => array('class' => array('favorites-list tube--large')),
    '#children' => '<div id="favorites-list-items" class="favorites-list--list"></div><div class="favorites-list--clear"></div>',
  );

  // Attach form that allows sending the list
  $element['send_by_email'] = drupal_get_form('uhc_favorites_send_by_email_form');

  // Attach JS, so that we can inject favorite content
  $element['#attached']['js'] = array(
    drupal_get_path('module', 'uhc_favorites') .'/uhc_favorites.js',
    array(
      'data' => array('clearlist_label' => t('Clear list')),
      'type' => 'setting'
    ),
  );
  $element['#attached']['library'] = array(
    array('system', 'drupal.ajax')
  );
  return $element;
}

/**
 * Form callback for sending favorites to an given email address.
 * @param $form
 * @param $form_state
 * @return array
 */
function uhc_favorites_send_by_email_form($form, &$form_state) {
  $form['title'] = array('#markup' => '<h2>' . t('Send by email') . '</h2>');
  $form['nids'] = array(
    // This value will be filled up by JS
    '#type' => 'hidden',
  );
  $form['email'] = array(
    '#type' => 'textfield',
    '#title' => t('Email address'),
    '#required' => TRUE,
  );
  $form['submit'] = array(
    '#type' => 'submit',
    '#value' => t('Send'),
  );
  // If honeypot is enabled, use its protection
  if (module_exists('honeypot')) {
    honeypot_add_form_protection($form, $form_state, array('honeypot', 'time_restriction'));
  }
  return $form;
}
/**
 * Form validation callback.
 * @param $form
 * @param $form_state
 */
function uhc_favorites_send_by_email_form_validate($form, &$form_state) {
  // Validate favorites nids
  $nids = _uhc_favorites_get_nid_values($form_state);
  if (empty($nids)) {
    form_set_error('nids', t('Can\'t send empty list of favorites.'));
  }
  // Validate email address
  if (!valid_email_address($form_state['values']['email'])) {
    form_set_error('email', t('The e-mail address %mail is not valid.', array('%mail' => $form_state['values']['email'])));
  }
}

/**
 * Gets nid values from given &$form_state. This processes the value by
 * checking that values aren't empty.
 * @param $form_state
 * @return array
 */
function _uhc_favorites_get_nid_values(&$form_state) {
  $nids = array();
  foreach (explode(',', $form_state['values']['nids']) as $nid) {
    if (!empty($nid)) {
      $nids[] = $nid;
    }
  }
  return $nids;
}

/**
 * Form submission handler callback.
 * @param $form
 * @param $form_state
 */
function uhc_favorites_send_by_email_form_submit($form, &$form_state) {

  // Specify email subject
  $subject = t('Course favorites');

  // Extract nids and create links to the courses
  $links = array();
  $nids = _uhc_favorites_get_nid_values($form_state);
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $access = node_access('view', $node);
    if ($access) {
      $entity_uri = entity_uri('node', $node);
      $links[] = '- ' . entity_label('node', $node) . ': ' . url($entity_uri['path'], array('absolute' => TRUE));
    }
  }

  // Do nothing if no access to any links
  if (empty($links)) {
    return;
  }

  // Set message metadata and content
  global $language;
  $to = check_plain($form_state['values']['email']);
  $params = array(
    'subject' => $subject,
    'message' => implode(PHP_EOL, $links),

  );

  drupal_mail('uhc_favorites', 'favorites', $to, $language, $params);
  drupal_set_message(t('Favorites list has been sent via email.'));
}

/**
 * Implements hook_mail().
 */
function uhc_favorites_mail($key, &$message, $params) {
  if ($key == 'favorites') {
    $message['subject'] = $params['subject'];
    $message['body'][] = $params['message'];
    $message['headers']['Return-Path'] = variable_get('site_mail', '');
  }
}

/**
 * Callback function for ajax request that wants to convert given favorite IDs
 * into link list items.
 */
function uhc_favorites_urls_callback() {
  $nids = !empty($_POST['favorites']) ? $_POST['favorites'] : array();

  $response = array();
  foreach ($nids as $nid) {
    $node = node_load($nid);
    $response[] = array(
      'uri' => url('node/'. $node->nid),
      'label' => entity_label('node', $node)
    );
  }
  drupal_json_output($response);
  drupal_exit();
}
