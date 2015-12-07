<?php
/**
 * @file
 * Implementation class for plugin determining when we're at open university
 * context.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class uhc_open_university_context_condition_open_university_section extends context_condition {

  function condition_values() {
    return array(
      'uhc_open_university_context_condition_open_university_section' => t('Check if we are on Open university section (course page, implementation page)')
    );
  }

  /**
   * Callback for executing and matching condition whether we are on Open
   * university section (course page, implementation page).
   */
  function execute($node) {
    if (uhc_open_university_is_open_university_course_or_implementation($node)) {
      foreach ($this->get_contexts() as $context) {
        $this->condition_met($context);
      }
    }
  }
}
