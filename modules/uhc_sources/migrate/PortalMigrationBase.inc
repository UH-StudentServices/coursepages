<?php
/**
 * @file
 * Implementation for migration base of portal backend API.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class PortalMigrationBase extends Migration {

  /**
   * This holds set of ids to be imported either defined through constructor
   * or by predefined idlist when calling MigrationBase::processImport().
   * @var array $predefined_ids
   */
  protected $predefined_ids = array();

  /**
   * Contains all successfully processed source ids.
   * @var array
   */
  protected $processed_source_ids = array();

  /**
   * Sets machine name if provided through arguments.
   *
   * @param array $arguments
   *   Array of arguments. I this class we're interested in:
   *     - machine_name: Given machine name for the migration.
   */
  public function __construct($arguments = array()) {
    parent::__construct($arguments);
    if (!empty($arguments['machine_name'])) {
      $this->machineName = $arguments['machine_name'];
    }
  }

  /**
   * Default implementation for checking whether we should skip the row or not.
   * This gets called from Migration::prepareRow().
   * @param $row
   * @return bool
   * @see CourseNodeMigration::prepareRow()
   * @see CourseImplementationNodeMigration::prepareRow()
   */
  public function shouldRowBeSkipped($row) {
    // By default, we skip the row if it's skippable item.
    if ($row instanceof SkippableItem) {
      return TRUE;
    }
    return FALSE;
  }

  /**
   * Overrides MigrationBase::processImport().
   */
  public function processImport(array $options = array()) {

    // Keep track of ids we're specifically importing and what time we started
    // the process. @see self::postImport()
    if (!empty($options['idlist'])) {
      foreach (explode(',', $options['idlist']) as $id) {
        $id = trim($id);
        if (!empty($id)) {
          $this->predefined_ids[] = $id;
        }
      }
    }

    return parent::processImport($options);
  }

  /**
   * After import this method gets called.
   *
   * Set last reuqested if no errors has occured and if no specific items has
   * been imprted (if we import one item, we don't want to update timestamp for
   * for whole list!).
   *
   * Overrides Migration::postImport()
   */
  protected function postImport() {
    parent::postImport();
    // Sort month terms in chronological order
    uhc_taxonomy_sort_month_terms();
  }

  /**
   * Prepends the host for the URL if it is missing. This allows configuration
   * to have host as an optional. Configuration may have only the path or the
   * full URL.
   *
   * @param $url
   * @return mixed
   */
  public static function prependHostIfMissing($url) {
    // Parse URL for identifying parts of the URL
    $parts = parse_url($url);
    $base_url = variable_get('uhc_sources_base_url', '');
    if (!empty($base_url) && (empty($parts['scheme']) || empty($parts['host']))) {
      return $base_url . $url;
    }
    return $url;
  }

  /**
   * Decodes all HTML entities and gets rid of unnecessary new lines (\n). Takes
   * in an string or array of strings to process it properly.
   *
   * @param mixed $string
   * @return array|null|string
   */
  public static function preprocessString($string) {
    if (is_array($string)) {
      // If value is an array, loop over its items and call recursively.
      foreach ($string as $key => $value) {
        $string[$key] = PortalMigrationBase::preprocessString($value);
      }
      return $string;
    }
    elseif(is_string($string)) {
      $string = str_replace(array("\n", '\\n'), ' ', $string);
      return html_entity_decode($string, null, 'UTF-8');
    }
    return NULL;
  }

  /**
   * Returns supported languages. Can be used for instance when dealing with
   * multilingual fields.
   * @return array
   */
  public static function getSupportedLanguages() {
    return array_values(locale_language_list('language'));
  }

  /**
   * Helper method for changing system of record. This allows Migration to make
   * dynamic system-of-records in cases where we want to import initial items
   * having SOURCE as system-of-record and afterwards being DESTINATION, because
   * some of fields might been edited after initial import (un-migrated fields).
   *
   * See about this topic: https://www.drupal.org/node/1461398
   *
   * @param int $systemOfRecord
   *   Should be one of Migration::SOURCE or Migration::DESTINATION.
   */
  public function setSystemOfRecord($systemOfRecord) {
    switch ($systemOfRecord) {
      case Migration::SOURCE:
      case Migration::DESTINATION:
        $this->systemOfRecord = $systemOfRecord;
        break;
    }
  }

  /**
   * Makes sure that we have a value for every enabled language.
   *
   * @param array $values
   * @return array
   * @throws MigrateException
   */
  public static function ensureValueForAllLanguages(array $values) {

    // Gather all values into this variable that will be returned
    $ensured_values = array();

    // Loop enabled languages in preferred order
    foreach (self::getSupportedLanguages() as $lang) {
      if (isset($values[$lang])) {
        $ensured_values[$lang] = $values[$lang];
      }
      else {
        $ensured_values[$lang] = self::getValueInPreferredLanguageOrder($values);
      }
    }

    return $ensured_values;
  }

  /**
   * Gets an value in preferred language order.
   *
   * @param array $values
   * @return string
   */
  public static function getValueInPreferredLanguageOrder(array $values) {
    $preferred_languages = self::getSupportedLanguages();
    foreach ($preferred_languages as $lang) {
      if (isset($values[$lang])) {
        return $values[$lang];
      }
    }

    // If we end up here, it means that none of values has values in given
    // preferred language.
    watchdog('uhc_sources', 'Could not get value in preferred language order.');
    return '';
  }

  /**
   * Trims Open university prefix from fields. Works with title_field and title.
   * Handles both single language (string) and multilingual (lang => value) arrays.
   * @param $value
   * @return mixed
   */
  public static function trimOpenUniPrefix($value) {
    if (is_array($value)) {
      foreach ($value as $lang => &$title) {
        $title = self::_trimPrefix($title);
      }
    }
    else {
      $value = self::_trimPrefix($value);
    }
    return $value;
  }

  /**
   * Helper for trimOpenUniPrefix().
   * @param $value
   * @return mixed
   */
  private static function _trimPrefix($value) {
    return str_replace(array('Avoin yo: ', 'Open uni: ', 'Öppna uni: '), '', $value);
  }

  /**
   * Converts given list of values into multilingual array utilizing given field
   * name.
   *
   * @param array $values
   * @return array
   */
  public static function convertToMultilingualText(array $values) {
    $multilingual_value = array();
    foreach (PortalMigrationBase::getSupportedLanguages() as $lang) {
      // Set default value
      $multilingual_value[$lang] = NULL;

      // Look out for this specific language value and set it
      foreach ($values as $value) {
        if ($value->langcode == $lang) {
          $multilingual_value[$lang] = $value->text;
          break;
        }
      }
    }

    return $multilingual_value;
  }

  ##############################################################################
  # All following methods are used to prepare the $row and making it field
  # mappable.
  ##############################################################################

  /**
   * Prepares status field which basically is negate from "hidden" property.
   *
   * @param $row
   */
  static public function prepareStatus(&$row) {
    // Compute status from hidden value. Value seems to be "true" or "false" as
    // string, so we compare that and give actual value for "status" indicating
    // whther it should be published or not.
    $row->status = $row->hidden == 'false' ? 1 : 0;
  }

  /**
   * Prepares descriptions into field mappable format. Descriptions are grouped
   * into descriptions -property and they are using element id as identifiers
   * which is a problem for field mapping.
   *
   * Note: This is used also by other function in another module:
   * _uhc_course_implementation_inherited_fields_get_descriptions()
   *
   * @param object &$row
   * @param array $description_elements
   * @see _uhc_course_implementation_inherited_fields_get_descriptions()
   */
  static public function prepareDescriptions(&$row, array $description_elements) {

    // Loop each given description element
    foreach (PortalMigrationBase::getSupportedLanguages() as $lang) {
      foreach ($description_elements as $element_id => $element_name) {

        // At least make empty value. This is important to ensure that we
        // collect the value multilingually *IN THE RIGHT ORDER*. The
        // order of which PortalMigrationBase::getSupportedLanguages()
        // returns should be used.
        $row->{$element_name}[$lang] = NULL;

        // This loop will loop descriptions until it finds values for each
        // element/language.
        foreach ($row->descriptions as $description) {
          if (isset($description->id)) {
            if ($description->id == $element_id) {

              // When element matches, convert it to temporal variable for
              //easier access and set it as property of root object.
              $converted = PortalMigrationBase::convertToMultilingualText($description->texts);
              $row->{$element_name}[$lang] = $converted[$lang];

              break;
            }
          }
          else {
            // Create log entry about not being able to read element
            watchdog('uhc_sources', 'Could not read element id "@description_id" with language "@language"', array('@description_id' => $description->id, '@language' => $lang), WATCHDOG_WARNING);
          }
        }

      }
    }
    unset($row->descriptions);
  }
}
