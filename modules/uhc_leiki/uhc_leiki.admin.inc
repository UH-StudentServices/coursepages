<?php

/**
 * Callback for Leiki configuration form.
 */
function uhc_leiki_settings($form, $form_state) {
  $form['uhc_leiki_enabled'] = array(
    '#title' => t('Enabled'),
    '#type' => 'checkbox',
    '#default_value' => variable_get('uhc_leiki_enabled', FALSE),
  );
  $form['uhc_leiki_base_url'] = array(
    '#title' => t('Leiki Base URL'),
    '#type' => 'textfield',
    '#default_value' => variable_get('uhc_leiki_base_url', '//suositukset.student.helsinki.fi/focus'),
  );
  return system_settings_form($form);
}
