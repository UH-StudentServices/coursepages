<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Callback for configuration form.
 */
function uhc_migrate_message_notifications_config_form($form, &$form_state) {
  $last_lookup = variable_get('uhc_migrate_message_notifications_last_lookup', NULL);
  $form['uhc_migrate_message_notifications_email'] = array(
    '#type' => 'textfield',
    '#title' => t('E-mail address'),
    '#description' => t('Type in email address where you want to receive notifications. If this field is empty, no emails are sent.'),
    '#default_value' => variable_get('uhc_migrate_message_notifications_email', ''),
  );
  $form['uhc_migrate_message_notifications_lookup_messages'] = array(
    '#type' => 'textarea',
    '#title' => t('Lookup messages'),
    '#description' => t('Enter phrases to look for and report about. Enter many by separating with new lines.'),
    '#default_value' => variable_get('uhc_migrate_message_notifications_lookup_messages', ''),
  );
  if (!is_null($last_lookup)) {
    $form['uhc_migrate_message_notifications_last_lookup'] = array(
      '#type' => 'item',
      '#markup' => t('Last time, when lookup was performed: <strong>@datetime</strong>', array('@datetime' => $last_lookup->format('d.m.Y H:i:s'))),
    );
  }
  return system_settings_form($form);
}
