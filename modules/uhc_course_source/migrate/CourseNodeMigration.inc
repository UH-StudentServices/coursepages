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
        new PortalItemBase($arguments['predefined_item']),
        self::sourceFields()
      );
    }
    else {

      // Construct the URLs for source class
      $list_url = variable_get('uhc_course_source_list_url', '');
      $item_url = variable_get('uhc_course_source_item_url', '');

      // Prepare URLs for hosts and other parameters
      $item_url = PortalMigrationBase::prependHostIfMissing($item_url);
      $list_url = PortalMigrationBase::prependHostIfMissing($list_url);
      $list_url = $this->constructLastRequested($list_url);

      // Construct and specify source class
      $timeout = variable_get('uhc_sources_timeout', ini_get('default_socket_timeout'));
      $this->source = new MigrateSourceList(
        new PortalListBase('learningopportunity_id', $list_url, array('timeout' => $timeout)),
        new PortalItemBase($item_url),
        self::sourceFields()
      );

    }

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

    // Setup simple field mapping
    $this->addFieldMapping('status', 'julkisuus')->defaultValue(1);
    $this->addFieldMapping('title', 'nimi_en')->callbacks(array($this, 'trimOpenUniPrefix'));
    $this->addFieldMapping('field_course_course_number', 'id');
    $this->addFieldMapping('field_study_credit', 'laajuus');

    // Type of teaching is mapped as term reference
    $this->addFieldMapping('field_course_type_of_teaching', 'opetustyyppi_id')
      ->arguments(array('source_type' => 'tid'))
      ->sourceMigration('TaxonomyTypeOfTeachingTerm');

    // Course tags are taken in as multilingual terms
    $this->addFieldMapping('field_course_course_tags', 'avainsanat_all')
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
    $this->addFieldMapping('field_course_theme', 'avainsanat_fi')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'resolveThemeTids'));

    // Handle multilingual field mapping
    $field_arguments = array('language' => $this->getSupportedLanguages(), 'format' => 'filtered_html');

    // Title has been already mapped, but we need to map the multilingual field
    // too
    $this->addFieldMapping('title_field', 'nimi_all')->arguments($field_arguments)
      ->callbacks(array($this, 'trimOpenUniPrefix'));

    $this->addFieldMapping('field_evaluation',  'arviointi_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_req_prerequisites',  'ed_opinnot_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_target_group',  'kohderyhma_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_study_materials',  'oppimateriaali_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_timing',  'ajoitus_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_objective',  'tavoite_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_contents',  'sisalto_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_additional_info',  'lisatiedot_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_conduct',  'suoritustavat_all')
      ->arguments($field_arguments)
      ->callbacks(array($this, 'preprocessString'));

    $this->addFieldMapping('field_course_faculty',  'tiedekunta_all')
      ->arguments(array('source_type' => 'tid'))
      ->callbacks(array($this, 'resolveFacultyTid'));

    $this->addFieldMapping('field_course_subject',  'oppiaineet')
      ->arguments(array('format' => 'filtered_html'));

  }

  /**
   * Returns list of expected source fields.
   * @return array
   */
  static function sourceFields() {
    return array(
      'id'                  => 'Course ID',
      'nimi_en'             => 'Name of course in english',
      'nimi_fi'             => 'Name of course in finnish',
      'nimi_sv'             => 'Name of course in swedish',
      'nimi_all'            => 'Name of course in all languages',
      'opetustyyppi_id'     => 'Form of study',
      'avainsanat_all'      => 'Keywords of course in all languages',
      'arviointi_all'       => 'Evaluation information in all languages',
      'ed_opinnot_all'      => 'Required pre-requisites in all languages',
      'kohderyhma_all'      => 'Target group in all languages',
      'ajoitus_all'         => 'Timing in all languages',
      'tavoite_all'         => 'Objective in all languages',
      'sisalto_all'         => 'Contents in all languages',
      'lisatiedot_all'      => 'Additional information in all languages',
      'tiedekunta_all'      => 'Faculty of course in all languages',
      'oppimateriaali_all'  => 'Study materials in all languages.',
      'suoritustavat_all'   => 'Conduct in all languages',
      'oppiaineet'          => 'List of subjects',
      'laajuus'             => 'Credit',
      'julkisuus'           => 'Published (0 = unpublished, 1 = published)',
      'md5'                 => 'MD5 checksum of the content',
    );
  }

  /**
   * Prepare row by doing following things:
   *   1) Aggregate multilingual fields into _all properties. For example:
   *      nimi_fi, nimi_en, nimi_sv will generate and array nimi_all. This allows
   *      us to use that field for multilingual field mapping.
   *   2) Move all "kurssikuvaus" properties to root, so that we can map them
   *      nicely from the __construct() when setting field mapping.
   */
  public function prepareRow($row) {
    if ($this->shouldRowBeSkipped($row)) {
      return FALSE;
    }

    // These are the languages we want to aggregate
    $languages = $this->getSupportedLanguages();

    // Aggregate all root multilingual fields
    $fields = array('nimi', 'url', 'tiedekunta');
    $row = $this->aggregateMultilingualFields($row, $languages, $fields);

    // Aggregate all course descriptions
    $fields = array('ajoitus', 'arviointi', 'avainsanat', 'ed_opinnot', 'kohderyhma', 'lisatiedot', 'oppimateriaali', 'sisalto', 'suoritustavat', 'tavoite');
    $row->kurssikuvaus = $this->aggregateMultilingualFields($row->kurssikuvaus, $languages, $fields);

    // Aggregate subjects into $row->oppiaineet, so that we can do field mapping
    // with multiple string values (no entity references so far yet). See
    // DOO-1494 comments in JIRA.
    $row->oppiaineet = array();
    if (isset($row->oppiainelista)) {
      $row->oppiaineet = $this->aggregateSubjects($row->oppiainelista);
    }

    // Copy all course descriptions to root
    foreach ($row->kurssikuvaus as $key => $value) {
      if (!isset($row->$key)) {
        $row->$key = $row->kurssikuvaus->$key;
      }
      else {
        // Yes we want to know if this happens!
        throw new Exception('Unexpected property name "'.$key.'" while moving course description values to root.');
      }
    }
    unset($row->kurssikuvaus);

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

    // Which stubs are up for migration?
    $migrate_stubs = variable_get('uhc_course_source_migrate_stubs', array());

    // Format stub nids and loop over each source
    $stub_nids = array();
    foreach ($source_ids as $source_id) {

      // If node was successfully created, add it to $stub_nids for mapping and
      // to $migrate_stubs for post migration.
      $node = _uhc_course_source_create_stub($source_id);
      if (!empty($node->nid)) {
        // Append nid to the list and prevent adding existing source_ids to the
        // list.
        $stub_nids[] = $node->nid;
        if (!in_array($source_id, $migrate_stubs)) {
          $migrate_stubs[] = $source_id;
        }
      }
    }

    // Now save potentially modified $migrate_stubs
    variable_set('uhc_course_source_migrate_stubs', $migrate_stubs);

    // Returns stub nids if any, or else return FALSE
    return !empty($stub_nids) ? $stub_nids : FALSE;
  }

  /**
   * This method takes in an object for loop. It goes through given languages
   * and fields and aggregates properties into arrays as following:
   * nimi_en, nimi_fi, nimi_sv becomes nimi_all => array(nimi_en, nimi_fi,
   * nimi_sv).
   *
   * @param $object
   * @param $languages
   * @param $fields
   * @return mixed
   */
  protected function aggregateMultilingualFields($object, $languages, $fields) {
    // Loop fields and get their multilingual values and aggregate them to
    // suffixed _all.
    foreach ($fields as $field) {
      $all = array();
      foreach ($languages as $lang) {

        // Following two lines will specify where to look the value from using
        // given language and source field.
        $rest_field = $field . '_' . $lang;

        // Now specify the value by storing it to $all variable
        $all[$lang] = is_object($object->$rest_field) ? NULL : $object->$rest_field;
      }

      // Now store the whole aggregated multilingual field
      $all_field_name = $field . '_all';
      $object->$all_field_name = $all;
    }
    return $object;
  }

  /**
   * Method for aggregating subjects (or disciplines) from list of given IDs.
   * @param $resolvable_disciplines
   * @return array
   */
  protected function aggregateSubjects($resolvable_disciplines) {

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
          if ($resolvalbe_discipline->oppiaine_id == $known_discipline->discipline_id) {
            // Append the name to resolved disciplines and continue to next
            // resolvable discipline.
            $resolved_disciplines[] = $known_discipline->discipline_name;
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

    $keywords = array();
    foreach (explode(',', $values) as $value) {
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

    return $return;
  }

  /**
   * Method for resolving taxonomy term id for given faculty.
   * @param $values
   *   An list of values indexed by language code.
   * @return array|mixed|null
   */
  static function resolveFacultyTid($values) {

    // Query these keywords against taxonomy term's name field
    $search_by_language = 'en';
    $query = new EntityFieldQuery();
    $query->entityCondition('entity_type', 'taxonomy_term')
      ->entityCondition('bundle', 'faculty')
      ->fieldCondition('name_field', 'value', $values[$search_by_language])
      ->fieldLanguageCondition('name_field', $search_by_language);
    $results = $query->execute();
    if (isset($results['taxonomy_term']) && count($results['taxonomy_term']) > 0) {
      $return = array_keys($results['taxonomy_term']);
    }
    else {

      // Build new taxonomy term entity object
      $faculty_vocabulary = taxonomy_vocabulary_machine_name_load('faculty');
      $term_values = array(
        'vid' => $faculty_vocabulary->vid,
        'vocabulary_machine_name' => $faculty_vocabulary->machine_name,
        'name' => $values['en'],
        'description_field' => array(),
        'format' => 'plain_text',
        'weight' => 0,
        'name_field' => array(
          'en' => array(array('value' => $values['en'])),
          'fi' => array(array('value' => $values['fi'])),
          'sv' => array(array('value' => $values['sv'])),
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

}
