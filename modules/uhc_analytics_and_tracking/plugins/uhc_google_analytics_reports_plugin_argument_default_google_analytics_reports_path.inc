<?php

/**
 * @file
 * Contains current page path argument default plugin.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Default argument plugin to use current node path alias as argument.
 *
 * @ingroup views_argument_default_plugins
 */
class uhc_google_analytics_reports_plugin_argument_default_google_analytics_reports_path extends views_plugin_argument_default {

  /**
   * Get argument. Returns the node path alias with a language prefix instead
   * of the internal node path since Google Analytics tracks the path aliases.
   */
  public function get_argument() {
    $argument = check_plain(urldecode(request_uri()));
    $node = menu_get_object();

    if (isset($node)) {
      global $language;
      $argument = '/';

      if (isset($language->language) && $language->language != 'en') {
        $argument .= "$language->language/";
      }
      $argument .= drupal_get_path_alias("node/$node->nid", $language->language);
    }

    return $argument;
  }
}
