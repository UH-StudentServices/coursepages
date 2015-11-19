<?php
/**
 * @file
 * Implements an migration class for migrating course implementations from
 * doo-oodi service over HTTP.
 */

class CourseImplementationNodeMigration extends PortalMigrationBase {

  protected $reference_to_courses_migration;

  /**
   * @param $arguments array
   * @param $group
   * @throws Exception
   */
  function __construct($arguments = array(), $group = NULL) {
    parent::__construct($arguments, $group);

    // Determine source for this migration. We have option to use predefined ids
    // and item (when this migration is used for mapping and entity handling
    // purposes only) if we want. If those arguments we decide to go with them,
    // but if they're missing we remain fetching the list and items from
    // doo-oodi service system.
    if (!empty($arguments['predefined_ids']) && !empty($arguments['predefined_item'])) {
      $ids = is_array($arguments['predefined_ids']) ? array() : array($arguments['predefined_ids']);
      // Keep track of ids we're specifically importing. @see self::postImport()
      $this->predefined_ids = $ids;
      $this->source = new MigrateSourceList(
        new PortalListPredefined($ids),
        new CourseImplementationItem($arguments['predefined_item']),
        self::sourceFields()
      );
    }
    else {

      // Construct URLs for source class
      $list_url = variable_get('uhc_course_implementation_source_list_url', '');
      $item_url = variable_get('uhc_course_implementation_source_item_url', '');

      // Prepare URLs for hosts and other parameters
      $item_url = PortalMigrationBase::prependHostIfMissing($item_url);
      $list_url = PortalMigrationBase::prependHostIfMissing($list_url);
      $list_url = $this->constructLastRequested($list_url);

      // Construct source class
      $timeout = variable_get('uhc_sources_timeout', ini_get('default_socket_timeout'));
      $this->source = new MigrateSourceList(
        new PortalListBase('course_id', $list_url, array('timeout' => $timeout)),
        new CourseImplementationItem($item_url),
        self::sourceFields()
      );

    }

    // Set hard dependencies
    $this->dependencies = array('TaxonomyFormOfTeachingTerm');

    // Specify description and mapping
    $this->description = 'Migrates course implementations from REST API backend.';
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
          'description' => 'Course Implementation ID, can be digits or prefixed with alpha letters.',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // This is initial system-of-record which gets changed during import. Not
    // maybe good idea, but we don't wanted to double our importers. See more
    // about this topic: https://www.drupal.org/node/1461398
    $this->systemOfRecord = Migration::DESTINATION;

    // Introduce soft dependency to migration where we get nodes which we refer
    // to in field_imp_reference_to_courses field.
    if (!empty($this->reference_to_courses_migration)) {
      $this->softDependencies = array($this->reference_to_courses_migration);
    }
    $this->destination = new CourseImplementationDestinationNode('course_implementation');

    // These destination field mappings are not migrated!
    $this->addUnmigratedDestinations(array(
      'field_imp_header_image',
      'field_imp_header_image_caption',
      'field_imp_header_headline',
      'field_imp_header_text',
      'field_imp_material_description',
      'field_reference_to_course_tasks',
      'field_imp_teachersection',
      'field_imp_teacher_se_content',
    ));

    // Setup field mapping
    $this->addFieldMapping('status', 'status')->defaultValue(0);
    $this->addFieldMapping('title', 'title');
    $this->addFieldMapping('field_imp_begin_date', 'start_date')
      ->arguments(array('timezone' => 'Europe/Helsinki'))
      ->callbacks(array($this, 'fixTimeZoneIssue'));
    $this->addFieldMapping('field_imp_end_date', 'end_date')
      ->arguments(array('timezone' => 'Europe/Helsinki'))
      ->callbacks(array($this, 'fixTimeZoneIssue'));
    $this->addFieldMapping('field_imp_reference_to_courses', 'learningopportunity_id')->sourceMigration('CourseNode');

    $this->addFieldMapping('field_imp_locality', 'instruction_locality');

    $this->addFieldMapping('field_study_credit', 'credit_points');

    $this->addFieldMapping('field_imp_method_of_study', 'realisation_type_code')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('TaxonomyFormOfTeachingTerm');

    $this->addFieldMapping('field_imp_start_month', 'start_date')
      ->arguments(array('create_term' => TRUE))
      ->callbacks(array($this, 'convertToMonthYearName'));

    $this->addFieldMapping('field_imp_teacher', 'teachers')->callbacks(array($this, 'getTeacherNames'));
    $this->addFieldMapping('field_imp_teacher_number', 'teachers')->callbacks(array($this, 'getTeacherNumbers'));
    $this->addFieldMapping('field_imp_administrator_number', 'officials')->callbacks(array($this, 'getAdministratorNumbers'));
    $this->addFieldMapping('field_imp_id', 'id');

    // These fields determine how we organise our searches
    $this->addFieldMapping('field_imp_organisation_codes', 'organisations')
      ->callbacks(array($this, 'parseOrganisationCodesFromOrganisations'));
    $this->addFieldMapping('field_imp_keywords', 'descriptions')
      ->callbacks(array($this, 'parseKeywordsFromDescriptions'));

    // Handle multilingual field mapping.
    $field_arguments = array('language' => $this->getSupportedLanguages(), 'format' => 'filtered_html');
    $this->addFieldMapping('title_field', 'realisation_name')->arguments($field_arguments);

    $this->addFieldMapping('field_imp_giver_locality', 'providing_locality')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_timing', 'timing')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_evaluation', 'evaluation')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_req_prerequisites', 'previous_studies')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_target_group', 'target_group')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_additional_info', 'other_information')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_study_materials', 'study_materials')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_contents', 'contents')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_conduct', 'completion')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_objective', 'objective')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_imp_fee', 'study_fee')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_imp_course_organiser',  'providing_organisation')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    // Note: Multilingual field mapping is not supported, so
    // field_imp_canonical_url field is handled in
    // CourseImplementationDestinationNode::prepare()
  }

  /**
   * Returns list of expected source fields.
   *
   * @return array
   */
  static function sourceFields() {
    return array(
      'id'                           => 'Course Implementation ID',
      'learningopportunity_id'       => 'Course ID where the implementation belongs to',
      'title'                        => 'Title from finnish realisation name field',
      'courseunitrealisation_status' => 'State of the course implementation (1=planned, 2=confirmed, 3=cancelled, 4=completed)',
      'start_date'                   => 'Starting date of course implementation',
      'end_date'                     => 'Ending date of course implementation',
      'realisation_type_code'        => 'Realisation type code / Form of study',
      'credit_points'                => 'Credit',
      'realisation_name'             => 'Multilingual: Name',
      'evaluation'                   => 'Multilingual: Evaluation',
      'timing'                       => 'Multilingual: Timing',
      'previous_studies'             => 'Multilingual: Previous studies',
      'target_group'                 => 'Multilingual: Target group',
      'other_information'            => 'Multilingual: Other information',
      'study_materials'              => 'Multilingual: Study materials',
      'study_fee'                    => 'Multilingual: Study fee',
      'contents'                     => 'Multilingual: Contents',
      'completion'                   => 'Multilingual: Completion',
      'objective'                    => 'Multilingual: Objective',
      'providing_locality'           => 'Multilingual: City which is giving the course.',
      'instruction_locality'         => 'Multilingual: City where the course is taught',
      'providing_organisation'       => 'Multilingual: Course organiser',
      'languages'                    => 'Teaching languages',
      'teachers'                     => 'Teachers',
      'officials'                    => 'Officials (administrators)',
      'organisations'                => 'Organisations',
      'descriptions'                 => 'Descriptions',
      'visible'                      => 'Whether the course implementation structure should be visible (webjulk).',
      'show_to_student'              => 'Whether the course implementation should be visible to students (näytopis).',
    );
  }

  /**
   * Prepare row by checking whether we should skip this and copying locality if
   * instruction locality is missing.
   */
  public function prepareRow($row) {
    if ($this->shouldRowBeSkipped($row)) {
      return FALSE;
    }

    // Compute status from three source properties. The course implementation
    // is considered published when:
    //   1) State (courseunitrealisation_status) does not equal to "1" (=planned)
    //   2) Show to student (show_to_student) equals to "1"
    //   3) Teaching hiearchy (webjulk) equals to "1"
    $row->status = ($row->courseunitrealisation_status != 1 && $row->visible == 1 && $row->show_to_student == 1);

    // Use providing_locality as instruction_locality if instruction_locality is
    // missing.
    if (empty($row->instruction_locality) && !empty($row->providing_locality['fi'])) {
      $row->instruction_locality = $row->providing_locality['fi'];
    }

    return TRUE;
  }

  /**
   * Converts date/time text to "April 2015" format.
   * @param $value
   *   Example expected inputs:
   *     2015-09-17T00:00:00.000+02:00
   *     2015-12-12T00:00:00.000+02:00
   *
   * @return string
   *   An formatted date format like:
   *     September 2015
   *     December 2015
   */
  static function convertToMonthYearName($value) {
    // Convert expected string input to unixtime, so we can then convert it to
    // our preferred format.
    $unixtime = strtotime($value);
    if ($unixtime) {
      return date('F Y', $unixtime);
    }
    // Fallback to original value, if we couldn't convert it to unix timestamp.
    return $value;
  }

  /**
   * Loops over teacher object and returns a list of teacher names separated by
   * comma.
   * @param $value
   * @return string
   */
  static function getTeacherNames($value) {
    $names = array();
    foreach ($value as $teacher) {
      $names[] = $teacher->calling_name . ' ' . $teacher->last_name;
    }
    return implode(', ', $names);
  }

  /**
   * Loops over teacher object and returns a list of teacher numbers separated
   * by comma.
   * @param $value
   * @return string
   */
  static function getTeacherNumbers($value) {
    $numbers = array();
    foreach ($value as $teacher) {
      $numbers[] = $teacher->teacher_id;
    }
    return implode(', ', $numbers);
  }

  /**
   * Loops over officials object and returns a list of administrator numbers
   * separated by comma.
   * @param $value
   * @return string
   */
  static function getAdministratorNumbers($value) {
    $numbers = array();
    foreach ($value as $official) {
      if (!empty($official->henk_id)) {
        $numbers[] = $official->henk_id;
      }
      else {
        watchdog('uhc_course_implementation_source', "Could not get official's person ID.", array(), WATCHDOG_WARNING);
      }
    }
    return implode(', ', $numbers);
  }

  /**
   * Decides if a row should be skipped (not migrated) based on hook
   * implementations written by another modules.
   *
   * @param $row object The current row to be processed.
   * @return bool TRUE if the row should skip migration, otherwise FALSE.
   */
  public function shouldRowBeSkipped($row) {
    // Invoke "hook_uhc_course_implementation_source_allow_source_row" to see if
    // any of modules wants to allow this course implementation row.
    $returns = module_invoke_all('uhc_course_implementation_source_allow_source_row', $row);
    foreach ($returns as $allow) {
      if ($allow === TRUE) {
        return FALSE;
      }
    }
    return TRUE;
  }

  /**
   * Parses organisation codes out from collection of organisation objects.
   *
   * @param $values
   * @return array
   */
  static public function parseOrganisationCodesFromOrganisations($values) {
    $codes = array();
    if (!empty($values) && is_array($values)) {
      foreach ($values as $value) {
        if (!empty($value->code)) {
          $codes[] = $value->code;
        }
      }
    }
    return $codes;
  }

  /**
   * Parses keywords out from collection of descriptions.
   * @param $values
   * @return array
   */
  static public function parseKeywordsFromDescriptions($values) {
    $keywords = array();
    if (!empty($values) && is_array($values)) {
      // Find from settings which element_ids are for keywords
      $description_names = variable_get('uhc_course_implementation_source_predefined_description_names', array());
      foreach ($description_names as $element_id => $description_name) {
        if ($description_name == 'keywords') {

          // Loop each value until we match with the current element_id
          foreach ($values as $value) {
            if (isset($value->element_id) && $value->element_id == $element_id) {

              // When element_id matches, then strip all tags from the
              // description, slice it into array strings and trim each keyword
              // while converting to lower string.
              $value->description = strip_tags($value->description);
              foreach (explode(',', $value->description) as $keyword) {
                $keyword = trim(drupal_strtolower($keyword));
                if (!empty($keyword)) {
                  $keywords[] = $keyword;
                }
              }

            }
          }

        }
      }
    }
    return $keywords;
  }

  /**
   * Ticket DOO-732 appeared after daylight saving time (DST) has applied and
   * during investigation we concluded that the source system (REST) does not
   * indicate timezone difference correctly for non DST dates.
   *
   * Solution #1 was to fix it there, but as we wanted to save time for the guys
   * who would worked on it to work on ESB integration instead, so we ended up
   * fixing it in our end instead (solution #2).
   *
   * @link https://jira.it.helsinki.fi/browse/DOO-732
   * @param $value
   * @return string
   */
  static public function fixTimeZoneIssue($value) {

    // Example: 2015-03-01T00:00:00.000+03:00
    //                   Replace this: ^^^^^^
    if ($position = strpos($value, '+')) {
      // Take string until the '+' sign and append 'Z' making it as following:
      // 2015-03-01T00:00:00.000Z
      return substr($value, 0, $position) . 'Z';
    }

    // If no plus sign position found, return original value
    return $value;
  }
}
