<?php

/**
 * @file
 * Provide custom path plugin for UHC Google Analytics reports.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_views_plugins().
 */
function uhc_analytics_and_tracking_views_plugins() {
  return array(
    'argument default' => array(
      'uhc_google_analytics_reports_path' => array(
        'title' => t('Current node path alias (UHC Google Analytics Reports)'),
        'handler' => 'uhc_google_analytics_reports_plugin_argument_default_google_analytics_reports_path',
      ),
    ),
  );
}
