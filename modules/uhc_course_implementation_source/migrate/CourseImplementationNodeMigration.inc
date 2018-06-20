<?php
/**
 * @file
 * Implements an migration class for migrating course implementations from
 * doo-oodi service over HTTP.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class CourseImplementationNodeMigration extends PortalMigrationBase {

  protected $reference_to_courses_migration;

  /**
   * @param $arguments array
   * @throws Exception
   */
  function __construct($arguments = array()) {
    parent::__construct($arguments);

    // Declare the items that we're up to migrate.
    $ids = isset($arguments['predefined_ids']) && is_array($arguments['predefined_ids']) && !empty($arguments['predefined_ids']) ? $arguments['predefined_ids'] : array();
    $this->predefined_ids = $ids;

    // Define the item importing class and options based on predefined_item
    // existance.
    $options = array('track_changes' => TRUE);
    if (!empty($arguments['predefined_item'])) {
      $item_class = new PortalItemBase($arguments['predefined_item'], array('method' => 'GET'));
    }
    else {
      $item_url = variable_get('uhc_course_implementation_source_item_url', '');
      $item_url = PortalMigrationBase::prependHostIfMissing($item_url);
      $item_class = new PortalItemBase($item_url, array('method' => 'GET'));
      $options['reader_class'] = 'UHCMigrateJSONReader';
    }

    // Setup source
    $this->source = new MigrateSourceList(
      new PortalListPredefined($ids),
      $item_class,
      self::sourceFields(),
      $options
    );

    // Set hard dependencies
    $this->dependencies = array('TaxonomyFormOfTeachingTerm');

    // Specify description and mapping
    $this->description = 'Migrates course implementations from REST API backend.';

    // See uhc_migrate_message_report module
    $migrate_map_class = class_exists('MigrateSQLMapWithCreated') ? 'MigrateSQLMapWithCreated' : 'MigrateSQLMap';

    $this->map = new $migrate_map_class($this->machineName,
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

    // Specify default field arguments for text fields
    $field_arguments = array('language' => $this->getSupportedLanguages(), 'format' => 'filtered_html');

    // Language neutral text fields that fits *AS IS* to field mapping
    $this->addFieldMapping('field_imp_id', 'id');
    $this->addFieldMapping('field_study_credit', 'credit_points');

    // Hierarchy metadata fields.
    $this->addFieldMapping('field_hierarchy_children', 'child_ids')->sourceMigration('CourseImplementationNode');
    $this->addFieldMapping('field_hierarchy_parent_id', 'parent_id')->sourceMigration('CourseImplementationNode');
    $this->addFieldMapping('field_hierarchy_position', 'position');

    // Text fields that needs some type of processing during mapping: Language neutral
    $this->addFieldMapping('title', 'title')->callbacks(array($this, 'trimOpenUniPrefix'));
    $this->addFieldMapping('field_imp_teacher', 'teachers')->callbacks(array($this, 'getTeacherNames'));
    $this->addFieldMapping('field_imp_teacher_number', 'teachers')->callbacks(array($this, 'getTeacherNumbers'));
    $this->addFieldMapping('field_imp_administrator_number', 'officials')->callbacks(array($this, 'getAdministratorNumbers'));
    // Text fields that needs some type of processing during mapping: Multilingual
    $this->addFieldMapping('title_field', 'realisation_name')->arguments($field_arguments)
      ->callbacks(array($this, 'ensureValueForAllLanguages'), array($this, 'trimOpenUniPrefix'));

    // Language neutral text fields that are computed in preprocess
    $this->addFieldMapping('field_imp_keywords', 'keywords')->callbacks(array($this, 'parseKeywords'));
    if (module_exists('uhc_event')) {
      $this->addFieldMapping('field_imp_events_json', 'events')->callbacks(array($this, 'encodeToJSONIfNotEmpty'));
      $this->addFieldMapping('field_imp_events_raw', 'raw_events')->callbacks(array($this, 'parseEvents'));
    }

    // Multilingual text fields that are computed in preprocess
    $this->addFieldMapping('field_imp_locality', 'instruction_locality')->arguments($field_arguments);
    $this->addFieldMapping('field_imp_giver_locality', 'providing_locality')->arguments($field_arguments);
    $this->addFieldMapping('field_imp_course_organiser',  'providing_organisation')->arguments($field_arguments);
    $this->addFieldMapping('field_imp_teaching_language', 'languages');
    // Multilingual text fields that are computed in preprocess: Descriptions
    $this->addFieldMapping('field_timing', 'timing')->arguments($field_arguments);
    $this->addFieldMapping('field_evaluation', 'evaluation')->arguments($field_arguments);
    $this->addFieldMapping('field_req_prerequisites', 'previous_studies')->arguments($field_arguments);
    $this->addFieldMapping('field_target_group', 'target_group')->arguments($field_arguments);
    $this->addFieldMapping('field_additional_info', 'other_information')->arguments($field_arguments);
    $this->addFieldMapping('field_study_materials', 'study_materials')->arguments($field_arguments);
    $this->addFieldMapping('field_contents', 'contents')->arguments($field_arguments);
    $this->addFieldMapping('field_conduct', 'completion')->arguments($field_arguments);
    $this->addFieldMapping('field_objective', 'objective')->arguments($field_arguments);
    $this->addFieldMapping('field_imp_fee', 'study_fee')->arguments($field_arguments);
    $this->addFieldMapping('field_working_methods', 'realisation_and_working_methods')->arguments($field_arguments);
    $this->addFieldMapping('field_responsible_person', 'responsible_person')->arguments($field_arguments);
    $this->addFieldMapping('field_rel_to_other_study_units', 'relations_to_other_study_units')->arguments($field_arguments);
    $this->addFieldMapping('field_open_uni_registration', 'open_university_registration')->arguments($field_arguments);

    // Other types of fields that are computed or prepared in prepare phase
    $this->addFieldMapping('status', 'status')->defaultValue(0);
    $this->addFieldMapping('field_cancelled', 'cancelled')->defaultValue(0);
    $this->addFieldMapping('field_imp_providing_org_code', 'providing_organisation_code');

    // Date fields
    $this->addFieldMapping('field_imp_begin_date', 'start_date')->arguments(array('timezone' => 'Europe/Helsinki'));
    $this->addFieldMapping('field_imp_end_date', 'end_date')->arguments(array('timezone' => 'Europe/Helsinki'));
    $this->addFieldMapping('field_imp_enrollment_begin_date', 'enroll_start_date')->arguments(array('timezone' => 'Europe/Helsinki'));
    $this->addFieldMapping('field_imp_enrollment_end_date', 'enroll_end_date')->arguments(array('timezone' => 'Europe/Helsinki'));

    // Entity reference fields
    $this->addFieldMapping('field_imp_reference_to_courses', 'learningopportunity_id')
      ->sourceMigration('CourseNode');
    $this->addFieldMapping('field_imp_method_of_study', 'realisation_type_code')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('TaxonomyFormOfTeachingTerm');
    $this->addFieldMapping('field_imp_start_month', 'start_date')
      ->arguments(array('create_term' => TRUE))
      ->callbacks(array($this, 'convertToMonthYearName'));
    $this->addFieldMapping('field_imp_organisation', 'organisations')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'resolveTidFromOrganisations'));
    $this->addFieldMapping('field_imp_extra_organisation', 'courses_extra_organisations')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'resolveTidFromOrganisations'));
  }

  /**
   * Returns list of expected source fields.
   *
   * @return array
   */
  static function sourceFields() {
    return array(
      'id'                             => 'Course Implementation ID',
      'learningopportunity_id'         => 'Course ID where the implementation belongs to',
      'title'                          => 'Title from finnish realisation name field',
      'courseunitrealisation_status'   => 'State of the course implementation (1=planned, 2=confirmed, 3=cancelled, 4=completed)',
      'start_date'                     => 'Starting date of course implementation',
      'end_date'                       => 'Ending date of course implementation',
      'enroll_start_date'              => 'Enroll start date',
      'enroll_end_date'                => 'Enroll end date',
      'realisation_type_code'          => 'Realisation type code / Form of study',
      'credit_points'                  => 'Credit',
      'realisation_name'               => 'Multilingual: Name',
      'evaluation'                     => 'Multilingual: Evaluation',
      'timing'                         => 'Multilingual: Timing',
      'previous_studies'               => 'Multilingual: Previous studies',
      'target_group'                   => 'Multilingual: Target group',
      'other_information'              => 'Multilingual: Other information',
      'study_materials'                => 'Multilingual: Study materials',
      'study_fee'                      => 'Multilingual: Study fee',
      'contents'                       => 'Multilingual: Contents',
      'completion'                     => 'Multilingual: Completion',
      'objective'                      => 'Multilingual: Objective',
      'instruction_locality'           => 'Multilingual: City where the course is taught',
      'providing_locality'             => 'Multilingual: City which is giving the course.',
      'providing_organisation'         => 'Multilingual: Course organiser',
      'realisation_and_working_methods'=> 'Multilingual: Realisation and working methods',
      'keywords'                       => 'Multilingual: Keywords',
      'events'                         => 'Strucuted list of events',
      'raw_events'                     => 'Unstrucuted list of events',
      'languages'                      => 'Teaching languages',
      'teachers'                       => 'Teachers',
      'officials'                      => 'Officials (administrators)',
      'organisations'                  => 'Organisations',
      'courses_extra_organisations'    => 'Extra organisations',
      'descriptions'                   => 'Descriptions',
      'hidden'                         => 'Indicates whether this course should be hidden or not.',
      'status'                         => 'Indicates whether this course should be published or not.',
      'cancelled'                      => 'Indicates whether this course is cancelled or not.',
      'responsible_person'             => 'Multilingual: Responsible person',
      'relations_to_other_study_units' => 'Multilingual: Relations to other study units',
      'open_university_registration'   => 'Multilingual: Open university registration',
      'child_ids'                      => 'Hierarchy: Child IDs',
      'parent_id'                      => 'Hierarchy: Parent ID',
      'position'                       => 'Hierarchy: Position',
    );
  }

  /**
   * Check that should this item be processed and if so, prepare whole row, so
   * that it is field mappable by Migrate.
   */
  public function prepareRow($row) {

    // If this row should be skipped, then return FALSE indicating that we don't
    // process this item
    if ($this->shouldRowBeSkipped($row)) {
      return FALSE;
    }

    // From configuration we get list of elements that contains information
    // about each description name and id. We need that for field proper mapping
    $description_elements = variable_get('uhc_course_implementation_source_predefined_description_names', array());

    // Make the $row field mappable \o/
    PortalMigrationBase::prepareStatus($row);
    CourseImplementationNodeMigration::prepareCancelled($row);
    CourseImplementationNodeMigration::prepareTeachingLanguage($row);
    CourseImplementationNodeMigration::prepareProvidingOrganisationCode($row);
    CourseImplementationNodeMigration::prepareMultilingualRootTexts($row);
    CourseImplementationNodeMigration::prepareTitle($row);
    CourseImplementationNodeMigration::prepareInstructionLocality($row);
    CourseImplementationNodeMigration::prepareDescriptions($row, $description_elements);
    CourseImplementationNodeMigration::prepareHierarchy($row);
    CourseImplementationNodeMigration::prepareOrganisations($row);

    // All these properties may contain problematic string content that needs
    // some processing to make it nicely renderable in Drupal.
    $preprocess_strings = array(
      'timing',
      'evaluation',
      'previous_studies',
      'target_group',
      'other_information',
      'study_materials',
      'contents',
      'completion',
      'objective',
      'study_fee',
      'providing_organisation',
      'realisation_and_working_methods',
      'responsible_person',
      'relations_to_other_study_units',
      'open_university_registration',
    );
    foreach ($preprocess_strings as $property) {
      if (!empty($row->$property)) {
        $row->$property = PortalMigrationBase::preprocessString($row->$property);
      }
    }

    return TRUE;
  }

  /**
   * Decides if a row should be skipped (not migrated) based on hook
   * implementations written by another modules.
   *
   * @param $row object The current row to be processed.
   * @return bool TRUE if the row should skip migration, otherwise FALSE.
   */
  public function shouldRowBeSkipped($row) {
    // Invoke "hook_uhc_course_implementation_source_deny_source_row" to see if
    // any of modules wants to deny this course implementation row.
    $returns = module_invoke_all('uhc_course_implementation_source_deny_source_row', $row);
    foreach ($returns as $return) {
      if ($return instanceof SkippableItem) {
        $this->queueMessage($return->getReason(), MigrationBase::MESSAGE_WARNING);
        return TRUE;
      }
    }
    return FALSE;
  }

  /**
   * This method creates a stub course implementation nodes and keeps book of
   * created stubs. By creating a stub from another migration, we also take
   * care of finalizing them by tracking the stubs and then migrating them fully
   * after initial migration has been completed.
   *
   * @see https://www.drupal.org/node/1013506
   * @param Migration $migration
   * @param array $source_ids
   * @return array|bool
   */
  public function createStub(Migration $migration, array $source_ids) {

    // Keep track of created stubs
    $created_stubs = array();

    // Format stub nids and loop over each source
    $stub_nids = array();
    foreach ($source_ids as $source_id) {

      // If node was successfully created, add it to $stub_nids for mapping and
      // to $migrate_stubs for post migration.
      $node = uhc_sources_create_stub_node($source_id, 'course_implementation');
      if (!empty($node->nid)) {
        // Append nid to the list and prevent adding existing source_ids to the
        // list.
        $stub_nids[] = $node->nid;
        if (!in_array($source_id, $created_stubs)) {
          $created_stubs[] = $source_id;
        }
      }
    }

    // Add each stub into queue
    $queue = new UHOodiPrioritisedQueue();
    foreach ($created_stubs as $created_stub) {
      $item = new UHOodiQueueItem(array(
        'action' => 'update',
        'entityType' => 'courseunitrealisation',
        'entityId' => $created_stub,
      ), UHOodiQueue::PRIORITY_MEDIUM);
      $queue->createItem($item->exportToQueueItem());
    }

    // Returns stub nids if any, or else return FALSE
    return !empty($stub_nids) ? $stub_nids : FALSE;
  }

  ##############################################################################
  # All following methods are used to prepare the $row and making it field
  # mappable.
  ##############################################################################

  /**
   * Prepares cancelled field which basically is boolean property written as
   * string: "true"/"false", instead of 0/1 or true/false.
   *
   * @param $row
   */
  static public function prepareCancelled(&$row) {
    $row->cancelled = $row->cancelled == 'true' ? 1 : 0;
  }

  /**
   * Prepares teaching language values into field mappable structure.
   * @param $row
   */
  static public function prepareTeachingLanguage(&$row) {
    $replacement = array();
    if (is_array($row->languages)) {
      foreach ($row->languages as $value) {
        if (drupal_strlen($value->langcode) != 0) {
          $replacement[] = drupal_strtolower($value->langcode);
        }
      }
    }
    $row->languages = $replacement;
  }

  /**
   * Prepares all multilingual root texts that are not having special property
   * structure.
   *
   * @param $row
   */
  static public function prepareMultilingualRootTexts(&$row) {
    // Convert these fields as multilingual values
    if (!empty($row->realisation_name)) {
      $row->realisation_name = PortalMigrationBase::convertToMultilingualText($row->realisation_name);
    }
    if (!empty($row->providing_organisation)) {

      // Note: We convert object into multilingual array
      $replacement = array();
      foreach ($row->providing_organisation as $organisation) {
        $replacement[] = PortalMigrationBase::convertToMultilingualText($organisation->organisation);
      }

      // If more values was found, source is providing multivalue when we are
      // reading this value as single value only. Leave log an entry and
      // continue processing.
      if (count($replacement) > 1) {
        watchdog('uhc_course_implementation_source', 'Courseunit "@id" has more than one providing organisation', array('@id' => $row->course_id), WATCHDOG_WARNING);
      }
      $row->providing_organisation = $replacement[0];
    }
    if (!empty($row->providing_locality)) {

      // Note: We convert object into multilingual array
      $replacement = array();
      foreach ($row->providing_locality as $locality) {
        $replacement[] = PortalMigrationBase::convertToMultilingualText($locality->locality);
      }

      // If more values was found, source is providing multivalue when we are
      // reading this value as single value only. Leave log an entry and
      // continue processing.
      if (count($replacement) > 1) {
        watchdog('uhc_course_implementation_source', 'Courseunit "@id" has more than one providing locality', array('@id' => $row->course_id), WATCHDOG_WARNING);
      }
      $row->providing_locality = $replacement[0];
    }
    if (!empty($row->instruction_locality)) {

      // Note: We convert object into multilingual array
      $instruction_locality_replacement = array();
      foreach ($row->instruction_locality as $instruction_locality) {
        $instruction_locality_replacement[] = PortalMigrationBase::convertToMultilingualText($instruction_locality->locality);
      }

      // If more values was found, source is providing multivalue when we are
      // reading this value as single value only. Leave log an entry and
      // continue processing.
      if (count($instruction_locality_replacement) > 1) {
        watchdog('uhc_course_implementation_source', 'Courseunit "@id" has more than one instruction locality', array('@id' => $row->course_id), WATCHDOG_WARNING);
      }
      $row->instruction_locality = $instruction_locality_replacement[0];
    }
  }

  /**
   * Prepares title field by using English title of realisation_name field.
   * Fallback to Finnish.
   *
   * Requires CourseImplementationNodeMigration::prepareMultilingualRootTexts()
   * to be called prior to this call.
   *
   * @param $row
   * @see CourseImplementationNodeMigration::prepareMultilingualRootTexts()
   */
  static public function prepareTitle(&$row) {
    if (!empty($row->realisation_name['en'])) {
      $row->title = $row->realisation_name['en'];
    }
    elseif (!empty($row->realisation_name['fi'])) {
      $row->title = $row->realisation_name['fi'];
    }
    else {
      $row->title = NULL;
    }
  }

  /**
   * Prepares instruction locality which has some business logic defined.
   *
   * If no instruction locality is present, then use providing locality if
   * provided. Use the Finnish version of the locality text as English, if the
   * English version does not exist.
   *
   * Requires CourseImplementationNodeMigration::prepareMultilingualRootTexts()
   * to be called prior to this call.
   *
   * @param $row
   * @see CourseImplementationNodeMigration::prepareMultilingualRootTexts()
   */
  static public function prepareInstructionLocality(&$row) {

    // Use providing_locality as instruction_locality if instruction_locality is
    // missing.
    if (empty($row->instruction_locality) && !empty($row->providing_locality)) {
      $row->instruction_locality = $row->providing_locality;
    }

    // Use the Finnish version of the locality text as English, if the English
    // version does not exist.
    if (empty($row->instruction_locality['en']) && !empty($row->instruction_locality['fi'])) {
      $row->instruction_locality['en'] = $row->instruction_locality['fi'];
    }
  }

  ##############################################################################
  # All following methods are used for doing simple convertions during field
  # mapping.
  ##############################################################################

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
      if (!empty($official->teacher_id)) {
        $numbers[] = $official->teacher_id;
      }
      else {
        watchdog('uhc_course_implementation_source', "Could not get official's teacher ID.", array(), WATCHDOG_WARNING);
      }
    }
    return implode(', ', $numbers);
  }

  /**
   * Converts date/time text to "April 2015" format.
   * @param $value
   *   Example expected inputs:
   *     2015-09-17T00:00:00.000Z
   *     2015-12-12T00:00:00.000Z
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
   * Resolves taxonomy term IDs from given organisation objects.
   *
   * @param $values
   * @return array
   */
  static public function resolveTidFromOrganisations($values) {
    $tids = array();
    if (!empty($values) && is_array($values)) {
      foreach ($values as $value) {
        if (!empty($value->code)) {
          if ($term = uh_taxonomy_organisations_load_by_code($value->code)) {
            $tids[] = $term->tid;
          }
        }
      }
    }
    return $tids;
  }

  /**
   * Parses keywords out from multilingual field "keywords".
   * @param $values
   * @return array
   */
  static public function parseKeywords($values) {
    $keywords = array();
    if (!empty($values['fi'])) {
      $values = explode(',', $values['fi']);
      foreach ($values as $value) {
        $value = strip_tags($value);
        $value = trim($value);
        $value = drupal_strtolower($value);
        if (!empty($value)) {
          $keywords[] = $value;
        }
      }
    }
    return $keywords;
  }

  /**
   * Prepares hierarchy information.
   *
   * @param $row
   */
  static public function prepareHierarchy(&$row) {
    if (!empty($row->child_ids)) {
      $course_implementation_ids = array();

      foreach ($row->child_ids as $child_id) {
        $course_implementation_ids[] = $child_id->course_id;
      }

      $row->child_ids = $course_implementation_ids;
    }
  }

  /**
   * Prepares providing organisation code for storing. Only one code is stored,
   * if multiple exist.
   *
   * @param $row
   */
  static public function prepareProvidingOrganisationCode($row) {
    if (!empty($row->providing_organisation)) {
      foreach ($row->providing_organisation as $providing_organisation) {
        if (!empty($providing_organisation->code)) {
          $row->providing_organisation_code = $providing_organisation->code;
        }
      }
    }
  }

  /**
   * Prepares organisation information. Merges extra organisations with
   * organisations. We need to do this to be able to use the extra organisations
   * as organisation facet values in the course search.
   *
   * @param $row
   */
  static public function prepareOrganisations(&$row) {
    if (!empty($row->organisations) && !empty($row->courses_extra_organisations)) {
      $row->organisations = array_merge($row->organisations, $row->courses_extra_organisations);
    }
  }

  /**
   * Encodes value to JSON if it's not empty.
   *
   * @param $value
   * @return string
   */
  static public function encodeToJSONIfNotEmpty($value) {
    return empty($value) ? '' : drupal_json_encode($value);
  }

  /**
   * Parses events value that has a list of objects. Each object having an
   * property called 'event' that is a string.
   *
   * This method will parse the list of objects and return their event values
   * separated by end of line.
   *
   * @param $value
   * @return null|string
   */
  static public function parseEvents($value) {
    if (!empty($value) && is_array($value)) {
      $return = array();
      foreach ($value as $row) {
        if (!empty($row->event)) {
          $return[] = $row->event;
        }
      }
      return implode(PHP_EOL, $return);
    }
    return NULL;
  }
}
