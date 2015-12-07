<?php
/**
 * @file
 * Implementation for migrating pre-defined course themes.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
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

