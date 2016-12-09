<?php
/**
 * @file
 * Integration file for variable module.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_variable_info().
 */
function uh_coursepages_variable_info($options) {
  $variables = array(
    'uhc_contact_logo_block_form_title' => array(
      'type' => 'string',
      'title' => t('HY - Contact title', array(), $options),
      'localize' => TRUE,
    ),
    'uhc_contact_logo_block_form_content' => array(
      'type' => 'string',
      'title' => t('HY - Contact content', array(), $options),
      'localize' => TRUE,
    ),
  );
  return $variables;
}
