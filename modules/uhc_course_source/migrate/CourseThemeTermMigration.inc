<?php
/**
 * @file
 * Implementation for migrating pre-defined course themes.
 */


class CourseThemeTermMigration extends TaxonomyTermMigration {

  function __construct() {
    parent::__construct(
      drupal_get_path('module', 'uhc_course_source') . '/migrate/coursethemes.json',
      'id',
      'course_theme',
      'NIMI_'
    );
  }

}

