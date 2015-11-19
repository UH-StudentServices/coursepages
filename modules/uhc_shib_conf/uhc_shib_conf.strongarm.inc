<?php
/**
 * @file
 * uhc_shib_conf.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uhc_shib_conf_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_account_linking';
  $strongarm->value = 0;
  $export['shib_auth_account_linking'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_account_linking_text';
  $strongarm->value = 'Link this account with another identity';
  $export['shib_auth_account_linking_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_allow_shared_emails';
  $strongarm->value = 1;
  $export['shib_auth_allow_shared_emails'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_auto_destroy_session';
  $strongarm->value = 0;
  $export['shib_auth_auto_destroy_session'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_debug_state';
  $strongarm->value = 0;
  $export['shib_auth_debug_state'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_debug_url';
  $strongarm->value = '';
  $export['shib_auth_debug_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_define_username';
  $strongarm->value = 0;
  $export['shib_auth_define_username'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_email_variable';
  $strongarm->value = 'HTTP_MAIL';
  $export['shib_auth_email_variable'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_enable_custom_mail';
  $strongarm->value = 0;
  $export['shib_auth_enable_custom_mail'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_forceauthn';
  $strongarm->value = 0;
  $export['shib_auth_forceauthn'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_force_https';
  $strongarm->value = 1;
  $export['shib_auth_force_https'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_full_handler_url';
  $strongarm->value = 'http://local.student.helsinki.fi/Shibboleth.sso/HYLogin';
  $export['shib_auth_full_handler_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_full_logout_url';
  $strongarm->value = 'http://local.student.helsinki.fi/Shibboleth.sso/Logout';
  $export['shib_auth_full_logout_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_is_passive';
  $strongarm->value = 0;
  $export['shib_auth_is_passive'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_link_text';
  $strongarm->value = 'Login';
  $export['shib_auth_link_text'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_login_url';
  $strongarm->value = '';
  $export['shib_auth_login_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_logout_url';
  $strongarm->value = 'https://login.helsinki.fi/idp/logout.jsp?return=https://beta.courses.helsinki.fi';
  $export['shib_auth_logout_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_terms_accept';
  $strongarm->value = 0;
  $export['shib_auth_terms_accept'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_terms_url';
  $strongarm->value = '/';
  $export['shib_auth_terms_url'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_terms_ver';
  $strongarm->value = '';
  $export['shib_auth_terms_ver'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'shib_auth_username_variable';
  $strongarm->value = 'HTTP_EPPN';
  $export['shib_auth_username_variable'] = $strongarm;

  return $export;
}
