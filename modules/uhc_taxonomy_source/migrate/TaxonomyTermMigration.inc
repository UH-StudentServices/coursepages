<?php
/**
 * @file
 * Migration class for course implementation.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

// Include these base classes from dependent module
module_load_include('inc', 'uhc_sources', 'migrate/PortalListBase');
module_load_include('inc', 'uhc_sources', 'migrate/PortalItemBase');
module_load_include('inc', 'uhc_sources', 'migrate/PortalMigrationBase');

class TaxonomyTermMigration extends PortalMigrationBase {

  /**
   * @var string
   *   Holds the name of the field in the source.
   */
  private $sourceLabelFieldName;
  public function getSourceFieldName() {
    return $this->sourceLabelFieldName;
  }

  function __construct($url, $id, $vocabulary, $source_label_field_name = 'name') {
    parent::__construct();

    $this->description = 'Migrates terms from the REST API backend.';
    $this->map = new MigrateSQLMap(
      $this->machineName,
      array(
        $id => array(
          'type' => 'int',
          'unsigned' => TRUE,
          'not null' => TRUE,
          'description' => 'Term Implementation ID',
        )
      ),
      MigrateDestinationTerm::getKeySchema()
    );

    $fields = array(
      $id    => 'Term ID',
      'name' => 'Term name',
    );

    // Set source labels. Name is the language neutral name source and
    // name_translations is the multilingual value.
    $this->sourceLabelFieldName = $source_label_field_name;

    // Setup entity mapping
    $this->source = new MigrateSourceJSON($url, $id, $fields, array('reader_class' => 'UHCMigrateJSONReader'));
    
    // To enable translations to work properly we'll use TaxonomyMigrateDestinationTerm
    // which extends MigrateDestinationTerm
    $this->destination = new TaxonomyMigrateDestinationTerm($vocabulary);

    // This should be set by UHCMigrateJSONReader
    $this->addFieldMapping('name', $source_label_field_name)->callbacks(array($this, 'getEnglishValue'));
    $this->addFieldMapping('name_field', $source_label_field_name);

    // Way of specifying language for multilingual field value
    $this->addFieldMapping('name_field:language', '')->defaultValue(PortalMigrationBase::getSupportedLanguages());

    // Hopefully in the future we can do something like:
    // See e.g. https://www.drupal.org/node/929402
    // $this->addFieldMapping('translate')->defaultValue(true);
    // $this->addFieldMapping('language')->defaultValue('en');

  }

  /**
   * Callback for preparing the row. This implementation converts the names into
   * field mappable format.
   */
  public function prepareRow($row) {
    $row->{$this->getSourceFieldName()} = PortalMigrationBase::convertToMultilingualText($row->{$this->getSourceFieldName()});
    return TRUE;
  }

  /**
   * Gets english value of given multilingual array value.
   *
   * @param array $value
   * @return mixed
   */
  public static function getEnglishValue(array $value) {
    return $value['en'];
  }

}
