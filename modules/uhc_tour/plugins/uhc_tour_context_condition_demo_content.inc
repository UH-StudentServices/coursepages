<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class uhc_tour_context_condition_demo_content extends context_condition {

  function condition_values() {
    return array('uhc_tour_context_condition_demo_content' => t('Check if we are viewing demo course implementation content'));
  }

  function condition_form($context) {
    $form = parent::condition_form($context);
    $variable_name = 'uhc_tour_demo_nid';
    $form['#description'] = t('Node ID is set to be "@nid". If you want to change it, please change it through <em>$settings</em> variable or <em>drush variable-set</em>. Variable name is <em><strong>@variable_name</strong></em>', array('@nid' => variable_get('uhc_tour_demo_nid', 0), '@variable_name' => $variable_name));
    return $form;
  }

  /**
   * Callback for executing and matching condition whether we're in an given
   * course implementation demo page.
   */
  function execute($node) {
    if (uhc_tour_is_demo_node($node)) {
      foreach ($this->get_contexts() as $context) {
        $this->condition_met($context);
      }
    }
  }
}
