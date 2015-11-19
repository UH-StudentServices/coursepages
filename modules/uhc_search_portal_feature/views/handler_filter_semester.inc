<?php
/**
 * @file
 * Views Plugin implementation for filtering results by semester.
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
