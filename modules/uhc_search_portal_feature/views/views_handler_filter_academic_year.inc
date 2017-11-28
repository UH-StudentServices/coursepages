<?php
/**
 * @file
 * Code for the UHC Course implementation feature.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class ViewsHandlerFilterAcademicYear extends SearchApiViewsHandlerFilter {
  /**
   * Provide a form for setting the filter value.
   */
  public function value_form(&$form, &$form_state) {
    while (is_array($this->value) && count($this->value) < 2) {
      $this->value = $this->value ? reset($this->value) : NULL;
    }
    $form['value'] = array(
      '#type' => 'select',
      '#title' => empty($form_state['exposed']) ? t('Value') : '',
      '#options' => $this->get_options(),
      '#default_value' => !empty($this->value) ? $this->value : $this->getSemester(),
    );

    // Hide the value box if the operator is 'empty' or 'not empty'.
    // Radios share the same selector so we have to add some dummy selector.
    if (empty($form_state['exposed'])) {
      $form['value']['#states']['visible'] = array(
        ':input[name="options[operator]"],dummy-empty' => array('!value' => 'empty'),
        ':input[name="options[operator]"],dummy-not-empty' => array('!value' => 'not empty'),
      );
    }
    elseif (!empty($this->options['expose']['use_operator'])) {
      $name = $this->options['expose']['operator_id'];
      $form['value']['#states']['visible'] = array(
        ':input[name="' . $name . '"],dummy-empty' => array('!value' => 'empty'),
        ':input[name="' . $name . '"],dummy-not-empty' => array('!value' => 'not empty'),
      );
    }
  }

  /**
   * Provide list of options that can be selected.
   * @return array
   */
  protected function get_options() {
    $options = array();
    $current_year = date('Y');

    for ($year = $current_year + 1; $year >= 2015; $year--) {
      $option = $year . ' - ' . ($year + 1);
      $options[$option] = $option;
    }

    return $options;
  }

  public function getSemester($timestamp = NULL) {
    $timestamp = !is_int($timestamp) ? time() : $timestamp;

    $previous_august = strtotime("previous year 1st august", $timestamp);
    $this_august = strtotime("1st august", $timestamp);

    $begin_timestamp = $timestamp > $this_august ? $this_august : $previous_august;
    $starting_year = (int) date('Y', $begin_timestamp);
    $ending_year = $starting_year + 1;
    return sprintf("%d - %d", $starting_year, $ending_year);
  }
}
