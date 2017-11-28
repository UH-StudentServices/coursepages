<?php
/**
 * Implements an migration class for migrating course nodes from doo-oodi
 * service over HTTP.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class CourseNodeMigration extends PortalMigrationBase {

  protected $type_of_teaching;

  /**
   * @param array $arguments
   * @throws MigrateException
   */
  function __construct($arguments = array()) {
    parent::__construct($arguments);

    // Declare the items that we're up to migrate.
    $ids = is_array($arguments['predefined_ids']) && !empty($arguments['predefined_ids']) ? $arguments['predefined_ids'] : array();
    $this->predefined_ids = $ids;

    // Define the item importing class based on predefined_item existance.
    if (!empty($arguments['predefined_item'])) {
      $item_class = new PortalItemBase($arguments['predefined_item']);
    }
    else {
      $item_url = variable_get('uhc_course_source_item_url', '');
      $item_url = PortalMigrationBase::prependHostIfMissing($item_url);
      $item_class = new PortalItemBase($item_url);
    }

    // Setup source
    $this->source = new MigrateSourceList(
      new PortalListPredefined($ids),
      $item_class,
      self::sourceFields(),
      array('track_changes' => TRUE)
    );

    // Set hard dependencies
    $this->dependencies = array('TaxonomyTypeOfTeachingTerm');

    // Specify description and mapping
    $this->description = 'Migrates courses from REST API backend.';
    $this->map = new MigrateSQLMap($this->machineName,
      array(
        'id' => array(
          'type' => 'varchar',
          'length' => 32,
          'not null' => TRUE,
          'description' => 'Course ID, can be digits or prefixed with alpha letters.',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    // This is initial system-of-record which gets changed during import. Not
    // maybe good idea, but we don't wanted to double our importers. See more
    // about this topic: https://www.drupal.org/node/1461398
    $this->systemOfRecord = Migration::DESTINATION;

    // Introduce soft dependency
    $this->softDependencies = array('CourseThemeTerm');

    // Specify destination
    $this->destination = new CourseDestinationNode('course');

    // These destination field mappings are not migrated!
    $this->addUnmigratedDestinations(array(
      'field_imp_header_image',
      'field_imp_header_image_caption',
    ));

    // Specify default field arguments for text fields
    $field_arguments = array('language' => $this->getSupportedLanguages(), 'format' => 'filtered_html');

    ############################################################################

    // Text fields that needs some type of processing during mapping: Language neutral
    $this->addFieldMapping('title', 'title')->callbacks(array($this, 'trimOpenUniPrefix'));
    // Text fields that needs some type of processing during mapping: Multilingual
    $this->addFieldMapping('title_field', 'names')->arguments($field_arguments)
      ->callbacks(array($this, 'ensureValueForAllLanguages'), array($this, 'trimOpenUniPrefix'));

    // Other types of fields that are computed or prepared in prepare phase
    $this->addFieldMapping('status', 'status')->defaultValue(0);

    // Language netural text fields that fits *AS IS* to field mapping
    $this->addFieldMapping('field_course_course_number', 'id');

    // Multilingual text fields that are computed in preprocess
    $this->addFieldMapping('field_course_subject',  'disciplines')
      ->arguments(array('format' => 'filtered_html'));
    $this->addFieldMapping('field_study_credit', 'credit_points');
    // Multilingual text fields that are computed in preprocess: Descriptions
    $this->addFieldMapping('field_objective',  'objective')->arguments($field_arguments);
    $this->addFieldMapping('field_req_prerequisites',  'previous_studies')->arguments($field_arguments);

    // Entity reference fields
    $this->addFieldMapping('field_course_type_of_teaching', 'learningopportunity_type_code')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('TaxonomyTypeOfTeachingTerm');
    $this->addFieldMapping('field_course_course_tags', 'keywords')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'parseCourseTags'));
    /* Themes are same as tags, but we define an preset of tags we want to map
     * into "themes".
     *
     * If we have theme tags "tree, ball, bottle" in Drupal and we have
     * "computer, ball, road" keywords in source then this mapping should map
     * this entity into "ball" term only, because it was created already in
     * Drupal.
     *
     * Note that themes are maintained only through Finnish language.
     */
    $this->addFieldMapping('field_course_theme', 'keywords')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'resolveThemeTids'));

    $this->addFieldMapping('field_course_faculty',  'faculties')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'resolveFacultyTid'));
    $this->addFieldMapping('field_course_degree_programme',  'degree_programme')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'resolveDegreeProgrammeTid'));
  }

  /**
   * Returns list of expected source fields.
   * @return array
   */
  static function sourceFields() {
    return array(
      'id'                              => 'Learning opportunity ID',
      'title'                           => 'Language neutral: Title in finnish',
      'names'                           => 'Multilingual: Title',
      'hidden'                          => 'Indicates whether this course should be hidden or not.',
      'status'                          => 'Indicates whether this course should be published or not.',
      'learningopportunity_type_code'   => 'Learning opportunity type code',
      'objective'                       => 'Multilingual: Objective',
      'contents'                        => 'Multilingual: Contents',
      'study_materials'                 => 'Multilingual: Study materials',
      'responsible_person'              => 'Multilingual: Responsible person',
      'relations_to_other_study_units'  => 'Multilingual: Relations to other study units',
      'timing'                          => 'Multilingual: Timing',
      'target_group'                    => 'Multilingual: Target group',
      'other_information'               => 'Multilingual: Other information',
      'evaluation'                      => 'Multilingual: Evaluation',
      'completion'                      => 'Multilingual: Completion/conduct',
      'previous_studies'                => 'Multilingual: Previous studies',
      'keywords'                        => 'Multilingual: Keywords',
      'disciplines'                     => 'List of subjects/disciplines',
      'credit_points_max'               => 'Maximum credit points',
      'credit_points_min'               => 'Minimum credit points',
      'credit_points'                   => 'Computed scale of credit points',
      'faculties'                       => 'Faculty of course',
      'degree_programme'                => 'Degree programme',
      'realisation_and_working_methods' => 'Multilingual: Realisation and working methods',
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
    $description_elements = variable_get('uhc_course_source_predefined_description_names', array());

    // Make the $row field mappable \o/
    PortalMigrationBase::prepareStatus($row);
    CourseNodeMigration::prepareMultilingualRootTexts($row);
    CourseNodeMigration::prepareTitle($row);
    PortalMigrationBase::prepareDescriptions($row, $description_elements);
    CourseNodeMigration::prepareCreditPoints($row);

    // All these properties may contain problematic string content that needs
    // some processing to make it nicely renderable in Drupal.
    $preprocess_strings = array(
      'objective',
      'contents',
      'study_materials',
      'responsible_person',
      'relations_to_other_study_units',
      'timing',
      'target_group',
      'other_information',
      'evaluation',
      'completion',
      'previous_studies',
      'realisation_and_working_methods',
    );
    foreach ($preprocess_strings as $property) {
      if (!empty($row->$property)) {
        $row->$property = PortalMigrationBase::preprocessString($row->$property);
      }
    }

  }

  /**
   * This method create stub course nodes and keeps booking of created stubs. By
   * creating stub from another migrations, we also take care of finalizing them
   * by tracking the stubs and then migrating them fully after initial migration
   * has been completed.
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
      $node = uhc_sources_create_stub_node($source_id, 'course');
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
        'entityType' => 'learningopportunity',
        'entityId' => $created_stub,
      ), UHOodiQueue::PRIORITY_MEDIUM);
      $queue->createItem($item->exportToQueueItem());
    }

    // Returns stub nids if any, or else return FALSE
    return !empty($stub_nids) ? $stub_nids : FALSE;
  }

  /**
   * Method for resolving disciplines IDs into names.
   *
   * @param $resolvable_disciplines
   * @return array
   */
  public static function resolveDisciplines($resolvable_disciplines) {

    // Constrcut list of all resolved disciplines
    $resolved_disciplines = array();

    // Request list of known disciplines. Response should contain all
    // disciplines with their IDs and names. Response is formatted as JSON.
    $disciplines_url = variable_get('uhc_course_source_disciplines_url', '');
    $disciplines_url = PortalMigrationBase::prependHostIfMissing($disciplines_url);
    $response = drupal_http_request($disciplines_url);
    $decoded_response = json_decode($response->data);

    // When response is decoded and has data
    if ($decoded_response && !empty($decoded_response->data)) {
      $known_disciplines = $decoded_response->data;
      // Loop over resolvable disciplines
      foreach ($resolvable_disciplines as $resolvalbe_discipline) {
        // Loop over known disciplines and look for matching iD
        foreach ($known_disciplines as $known_discipline) {
          // When matching ID
          if ($resolvalbe_discipline->discipline_id == $known_discipline->discipline_id) {
            // Append the name to resolved disciplines and continue to next
            // resolvable discipline.
            $known_discipline->name = PortalMigrationBase::convertToMultilingualText($known_discipline->name);
            $resolved_disciplines[] = $known_discipline->name['fi'];
            continue 2;
          }
        }
      }
    }
    else {
      watchdog('uhc_course_source', 'Could not decode list of disciplines while aggregating subjects. Got following reponse: @response', array('@response' => $response), WATCHDOG_WARNING);
    }

    // Return resolved disciplines
    return $resolved_disciplines;
  }

  /**
   * Method for "parsing" keywords into multivalued preprocessed words.
   *
   * @param array $tags
   * @return array
   */
  static function parseCourseTags($tags) {
    $return = array();

    $vocabulary = taxonomy_vocabulary_machine_name_load('course_tags');

    foreach ($tags as $lang => $values) {
      foreach (explode(',', $values) as $value) {
        $value = strip_tags($value);
        $value = trim($value);
        $value = ucfirst($value);

        $result = db_query("SELECT entity_id FROM {field_data_name_field} WHERE entity_type = 'taxonomy_term' AND bundle = 'course_tags' AND name_field_value = :value", array(':value' => $value));
        $result = $result->fetch();
        if ($result) {
          $return[] = $result->entity_id;
        }
        else {

          $term = new stdClass();
          $term->name = $value;
          $term->description = '';
          $term->format = 'plain_text';
          $term->vid = $vocabulary->vid;
          $term->vocabulary_machine_name = $vocabulary->machine_name;
          $term->tid = NULL;
          $term->weight = 0;
          // if you use source strings, the term must be created with the language none langcode.
          $term->language = LANGUAGE_NONE;
          $term->name_field[$lang][0]['value'] = $value;

          // TODO: Use translation handlers instead, see how
          // PortalDestinationNode::prepare() creates translation and how
          // PortalDestinationNode::complete() saves the translations
          $term->translations = (object)array(
            'original' => $lang,
            'data' => array(
              $lang => array(
                'entity_type' => 'taxonomy_term',
                'entity_id' => 0,
                'language' => $lang,
                'source' => '',
                'uid' => '1',
                'status' => '1',
                'translate' => '0',
              ),
            ),
          );

          taxonomy_term_save($term);

          $return[] = $term->tid;


        }
      }
    }

    return array_unique($return);
  }


  /**
   * Method for resolving taxonomy term IDs out from course keywords.
   *
   * @param string $values
   * @return array
   */
  static function resolveThemeTids($values) {
    $return = array();
    $keywords = array();
    if (isset($values['fi'])) {
      foreach (explode(',', $values['fi']) as $value) {
        // Yes, we sometimes might get <p>keyword</p>
        $value = strip_tags($value);
        // And they might have white space around
        $value = trim($value);
        // And they're listed as keywords, so their capitalization is different to
        // our taxonomy terms.
        $value = drupal_ucfirst($value);
        // Gather the list here
        $keywords[] = $value;
      }

      // Query these keywords against taxonomy term's name field
      $query = new EntityFieldQuery();
      $query->entityCondition('entity_type', 'taxonomy_term')
        ->entityCondition('bundle', 'course_theme')
        ->fieldCondition('name_field', 'value', $keywords)
        ->fieldLanguageCondition('name_field', 'fi');
      $results = $query->execute();
      $return = isset($results['taxonomy_term']) && count($results['taxonomy_term']) > 0 ? array_keys($results['taxonomy_term']) : array();
    }
    return $return;
  }

  /**
   * Method for resolving taxonomy term id for given degree programme.
   *
   * @param $values
   *   An list of values indexed by language code.
   * @param $vocabulary_name
   *   Vocabulary machine name that resolving is limited to.
   *
   * @return array|mixed|null
   */
  static function resolveTid($values, $vocabulary_name) {

    $source_values = array();

    foreach ($values as $value) {
      $source_values[$value->langcode] = $value->text;
    }

    // When no values, don't even bother...
    if (empty($source_values)) {
      return NULL;
    }

    // Query these keywords against taxonomy term's name field
    $search_by_language = 'en';
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', $vocabulary_name)
      ->fieldCondition('name_field', 'value', $source_values[$search_by_language])
      ->fieldLanguageCondition('name_field', $search_by_language);
    $results = $query->execute();
    if (isset($results['taxonomy_term']) && count($results['taxonomy_term']) > 0) {

      // Return taxonomy term ids
      $return = array_keys($results['taxonomy_term']);

      // For each matched term, check translations are up-to-date.
      foreach ($return as $match_tid) {
        $match_term = taxonomy_term_load($match_tid);
        $translation_updated = FALSE;
        if (!empty($match_term->name_field)) {
          foreach ($match_term->name_field as $langcode => $value) {
            if ($langcode != LANGUAGE_NONE) {
              if ($source_values[$langcode] != $value[0]['value']) {
                // Translation has been changed
                $match_term->name_field[$langcode][0]['value'] = $source_values[$langcode];
                $translation_updated = TRUE;
              }
            }
          }
        }

        // If translation has been updated, then save the updates.
        if ($translation_updated) {
          taxonomy_term_save($match_term);
          watchdog('uhc_course_source', 'Updated translations for @vocabulary tid @tid', array('@vocabulary' => $vocabulary_name, '@tid' => $match_tid->tid), WATCHDOG_NOTICE);
        }
      }

    }
    else {

      // Build new taxonomy term entity object
      $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);
      $term_values = array(
        'vid' => $vocabulary->vid,
        'vocabulary_machine_name' => $vocabulary->machine_name,
        'name' => $source_values['en'],
        'description_field' => array(),
        'format' => 'plain_text',
        'weight' => 0,
        'name_field' => array(
          'en' => array(array('value' => $source_values['en'])),
          'fi' => array(array('value' => $source_values['fi'])),
          'sv' => array(array('value' => $source_values['sv'])),
        ),
      );
      $term = entity_create('taxonomy_term', $term_values);

      // Create translation handler for keeping track of translations
      $translation_handler = entity_translation_get_handler('taxonomy_term', $term);
      $translation_handler->setOriginalLanguage('en');

      // And then set the translations
      $translations = array(
        array(
          'translate' => 0,
          'status' => 1,
          'language' => 'en',
        ),
        array(
          'translate' => 0,
          'status' => 1,
          'language' => 'fi',
          'source' => 'en',
        ),
        array(
          'translate' => 0,
          'status' => 1,
          'language' => 'sv',
          'source' => 'en',
        ),
      );
      foreach ($translations as $translation) {
        $translation_handler->setTranslation($translation, $term);
      }

      // Now save the term and translations
      taxonomy_term_save($term);
      $translation_handler->saveTranslations();

      $return = array($term->tid);
    }

    return $return;
  }

  /**
   * Method for resolving taxonomy term id for given faculty.
   * @param $values
   *   An list of values indexed by language code.
   * @return array|mixed|null
   */
  static function resolveFacultyTid($values) {
    return self::resolveTid($values, 'faculty');
  }

  /**
   * Method for resolving taxonomy term id for given degree programme.
   * @param $values
   *   An list of values indexed by language code.
   * @return array|mixed|null
   */
  static function resolveDegreeProgrammeTid($values) {
    return self::resolveTid($values, 'degree_programme');
  }

  ##############################################################################
  # All following methods are used to prepare the $row and making it field
  # mappable.
  ##############################################################################

  /**
   * Prepares all multilingual root texts that are not having special property
   * structure.
   *
   * @param $row
   */
  static public function prepareMultilingualRootTexts(&$row) {
    // Convert these fields as multilingual values
    if (!empty($row->names)) {
      $row->names = PortalMigrationBase::convertToMultilingualText($row->names);
    }

    // Resolve $row->disciplines, so that we can do field mapping with multiple
    // string values (no entity references so far yet). See DOO-1494 comments
    // in JIRA.
    if (isset($row->disciplines)) {
      $resolved_disciplines = CourseNodeMigration::resolveDisciplines($row->disciplines);
      $row->disciplines = $resolved_disciplines;
    }

  }

  /**
   * Prepares title field by using finnish title of names field.
   *
   * Requires CourseNodeMigration::prepareMultilingualRootTexts() to be called
   * prior to this call.
   *
   * @param $row
   * @see CourseNodeMigration::prepareMultilingualRootTexts()
   */
  static public function prepareTitle(&$row) {
    $title = NULL;
    foreach (array('en', 'fi', 'sv') as $lang) {
      if (!empty($row->names[$lang])) {
        $title = $row->names[$lang];
        break;
      }
    }
    $row->title = $title;
  }

  /**
   * Prepares $row->credit_points value by looking out given min and max values.
   *
   * @param $row
   * @return mixed
   */
  static public function prepareCreditPoints(&$row) {
    // When we have both values
    if (isset($row->credit_points_min) && isset($row->credit_points_max)) {
      // If they are the same
      if ($row->credit_points_max == $row->credit_points_min) {
        // Set max value (which is same as min)
        $row->credit_points = $row->credit_points_max;
      }
      else {
        // If they are not the same, then set scale
        $row->credit_points = $row->credit_points_min . '-' . $row->credit_points_max;
      }
    }
    elseif (isset($row->credit_points_max)) {
      // We have max value, set that
      $row->credit_points = $row->credit_points_max;
    }
    elseif (isset($row->credit_points_min)) {
      // We have min value, set that
      $row->credit_points = $row->credit_points_min;
    }
    else {
      // We don't have either min or max value, set NULL
      $row->credit_points = NULL;
    }
  }

}
