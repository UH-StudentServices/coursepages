<?php
/**
 * @file
 * Views Plugin implementation for filtering results by semester.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCSearchPortalFeatureViewsHandlerFilterSemester extends SearchApiViewsHandlerFilterDate {

  /**
   * Add this filter to the query.
   */
  public function query() {
    $this->processSemesterDateStrToTime();
    parent::query();
  }

  /**
   * Helper method for compiling custom strtotime() string "current semester".
   */
  function processSemesterDateStrToTime() {
    if (trim(drupal_strtolower($this->value)) == 'current semester') {
      $this->value = $this->getCurrentSemester();
    }
  }

  /**
   * Helper method for returning last august.
   *
   * @param $timestamp
   * @return int
   * @see _uhc_course_implementation_inherited_fields_get_academic_year_end_date()
   */
  function getCurrentSemester($timestamp = NULL) {
    $timestamp = !is_int($timestamp) ? time() : $timestamp;

    $previous_august = strtotime("previous year 1st august", $timestamp);
    $this_august = strtotime("1st august", $timestamp);

    // If we're past to this year's august, return this august. Otherwise return
    // previous august.
    return $timestamp > $this_august ? $this_august : $previous_august;
  }

}
