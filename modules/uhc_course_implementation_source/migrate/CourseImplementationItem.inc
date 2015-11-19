<?php
/**
 * @file
 * Implements class for migration which takes care of requesting the item's JSON
 * object and constructing it for migration.
 */

class CourseImplementationItem extends PortalItemBase {

  /**
   * Implementation of MigrateItem::getItem($id).
   *
   * In this context we need to process quite alot because of following
   * constraints:
   *   - We need to actually fetch from multiple URLs (each one for a language)
   *   - We need to convert some properties into field mappable structure
   *   - We need to convert some values into multilingual values
   *
   * In case of error on loading the JSON, an empty stdClass is returned. This
   * will cause this item to be ignored by the migration, but allow the
   * migration to continue with the next item.
   *
   * @param mixed $id
   * @return object|stdClass JSON object on success, empty stdClass on error.
   */
  public function getItem($id) {
    $migration = Migration::currentMigration();

    /*
     * Phase 1:
     *   In this phase we ensure that we have the source JSON available.
     */

    // Use given JSON object if exists
    if (!is_null($this->json)) {
      $json = $this->json;
    }
    else {
      // Or else, load it from internet
      try {
        $json = $this->loadAggregatedMultilingualJSON($id);
      }
      catch (Exception $e) {
        $migration->getMap()->saveMessage(array($id), $e->getMessage(), MigrationBase::MESSAGE_ERROR);
        return new stdClass();
      }
    }

    /*
     * Phase 2:
     *   If we want to simulate failure, we do it here now
     */
    $simulate_fail_item = variable_get('uhc_sources_simulate_failure');
    if (!is_null($simulate_fail_item) && $id == $simulate_fail_item) {
      $this->uhcLogMessage($id, 'Failed getting item due to simulated failure in "@id"', array('@id' => $id));
      return new stdClass();
    }

    /*
     * Phase 3:
     *   In this phase we convert source JSONs into working JSON which is
     *   applicable for Migrate mapping in multilingual context.
     */

    // Create draft object from finnish. We need this specifically from finnish
    // because we have keywords in descriptions which we need in finnish.
    $draft_json = $json->fi->data;

    // Create copy of English realisation_name for $node->title, which is not
    // multilingual. Fallback to Finnish realisation name.
    if (!empty($json->en->data->realisation_name)) {
      $draft_json->title = $json->en->data->realisation_name;
    }
    else {
      $draft_json->title = $json->fi->data->realisation_name;
    }

    // Make the realisation_name a multilingual value
    $draft_realisation_name = array();
    foreach (PortalMigrationBase::getSupportedLanguages() as $lang) {
      $draft_realisation_name[$lang] = $json->$lang->data->realisation_name;
    }
    $draft_json->realisation_name = $draft_realisation_name;

    // Flatten couple object properties, so that objects like
    // $draft_json->objX[]->name is moved to root object as: $draft_json->objX[]
    $draft_json->languages = $this->flattenPropertyCollections($json, 'languages', 'langcode', FALSE, TRUE);
    $draft_json->instruction_locality = $this->flattenPropertyCollections($json, 'instruction_locality', 'locality', FALSE);
    $draft_json->providing_locality = $this->flattenPropertyCollections($json, 'providing_locality', 'locality');
    $draft_json->providing_organisation = $this->flattenPropertyCollections($json, 'providing_organisation', 'organisation');

    // Process descriptions
    foreach ($this->processDescriptions($json) as $key => $value) {
      $draft_json->$key = $value;
    }

    /*
     * Phase 4: And finally hand it over
     */
    return $draft_json;
  }

  /**
   * Helper method for loading aggregated multilingual JSON.
   *
   * @param $id
   * @return array
   * @throws Exception
   */
  protected function loadAggregatedMultilingualJSON($id) {
    // Load the JSON. Construct the URL and load the JSON in each language
    $aggregatedJSON = new StdClass();
    $languages = PortalMigrationBase::getSupportedLanguages();
    foreach ($languages as $lang) {

      $item_url = $this->constructItemUrl($id, $lang);
      $response = $this->loadJSONUrl($item_url);

      // If failed loading JSON
      if (!$response) {
        $message =  t('Loading of !objecturl failed', array('!objecturl' => $item_url));
        throw new Exception($message);
      }

      // If backend responded with an exception
      if (isset($response->exception)) {
        $message =  t('Backend responded with exception "!exception" in !objecturl', array('!exception' => $response->exception->message, '!objecturl' => $item_url));
        throw new Exception($message);
      }

      // Append this response
      $aggregatedJSON->{$lang} = $response;
    }
    return $aggregatedJSON;
  }

  /**
   * Method for constructing an URL from given ID and language code. By default
   * migrate supports only ID, but we have extended that to support optional
   * :lang parameter.
   *
   * @param mixed $id
   * @param bool|FALSE $lang
   * @return mixed
   */
  protected function constructItemUrl($id, $lang = FALSE) {
    $itemUrl = $this->itemUrl;

    // Construct ID
    $itemUrl = preg_replace(array_fill(0, count($id), '/:id/'), $id, $itemUrl, 1);

    // If language given in string, then construct language
    if (is_string($lang)) {
      $itemUrl = preg_replace(array_fill(0, count($lang), '/:lang/'), $lang, $itemUrl, 1);
    }

    return $itemUrl;
  }

  /**
   * Helper method for flattening objects, so that it fits to migrate.module
   * flat mapping.
   *
   * If you have objects like: $obj->propertyX[]->name and you want it to be
   * like: $obj->propertyXname[], then this is your method to use to convert
   * that.
   *
   * This supports only for single depth.
   *
   * @param $json
   * @param $property
   * @param $property_value
   * @param $multilingual
   * @param $multivalue
   * @return array|string|NULL
   */
  protected function flattenPropertyCollections($json, $property, $property_value, $multilingual = TRUE, $multivalue = FALSE) {
    $languages = $multilingual === TRUE ? PortalMigrationBase::getSupportedLanguages() : array(LANGUAGE_NONE);
    $return = NULL;
    foreach ($languages as $lang) {

      // Depending on the source language, we fetch the data object from certain
      // property.
      if ($lang === LANGUAGE_NONE) {
        if (!isset($json->fi->data)) {
          // Oh no, we're missing this data. Break the loop and report to
          // watchdog.
          watchdog('uhc_course_implementation_source', 'Missing language neutral data when flattening property collection.', array(), WATCHDOG_ERROR);
          break;
        }
        $source = $json->fi->data;
      }
      else {
        if (!isset($json->{$lang}->data)) {
          // Oh no, we're missing this data. Break the loop and report to
          // watchdog.
          watchdog('uhc_course_implementation_source', 'Missing language @lang data when flattening property collection.', array('@lang' => $lang), WATCHDOG_ERROR);
          break;
        }
        $source = $json->{$lang}->data;
      }

      // Always have an value in multilingual context, so the multilingual field
      // mapping does not get offset. For proper field rendering, see how they
      // get cleaned in destination's prepare method:
      // @see \CourseImplementationDestinationNode::prepare()
      // @see \PortalDestinationNode::cleanupEmptyTextFields()
      if ($lang !== LANGUAGE_NONE) {
        $return[$lang] = '';
      }

      // If the property exists (which we're looking for), then loop its values
      // through and depending on the type of information (whether it's
      // multilingual and/or multivalue), set the values into $return variable.
      if (isset($source->$property)) {
        foreach ($source->$property as $key => $property_object) {
          if ($lang === LANGUAGE_NONE) {
            if ($multivalue === TRUE) {
              // Example: $return[0] = 'value';
              $return[$key] = $property_object->$property_value;
            }
            else {
              // Example: $return = 'value';
              $return = $property_object->$property_value;
            }
          }
          else {
            if ($multivalue === TRUE) {
              // Example: $return['en'][0] = 'value';
              $return[$lang][$key] = $property_object->$property_value;
            }
            else {
              // Example: $return['en'] = 'value';
              $return[$lang] = $property_object->$property_value;
            }
          }
        }
      }
    }
    return $return;
  }

  /**
   * This is very challenging to explain in english/text, but if I just show how
   * we want to object to be converted, you'll get the idea.
   *
   * We want from this model:
   *   $object->fi->data->descriptions: [
   *    {
   *      "element_id": 21,
   *      "description": "<p>Opintojakson suoritettuaan opiskelija hallitsee.</p>"
   *    },
   *    {
   *     "element_id": 22,
   *     "description": "<p>Opintojaksossa perehdytään sukupuolen merkitykseen\nerityisesti populaarikulttuurin kautta.</p>"
   *    },
   *  ]
   *  $object->en->data->descriptions: [
   *    {
   *      "element_id": 21,
   *      "description": "<p>After this course something.</p>"
   *    },
   *    {
   *     "element_id": 22,
   *     "description": "<p>In this course we go deep into.</p>"
   *    },
   *  ]
   *
   * To be converted into this model:
   *   $object->objective: [
   *     "fi" => "<p>Opintojakson suoritettuaan opiskelija hallitsee.</p>";
   *     "en" => "<p>After this course something.</p>",
   *   ]
   *   $object->contents: [
   *     "fi" => "<p>Opintojaksossa perehdytään sukupuolen merkitykseen\nerityisesti populaarikulttuurin kautta.</p>";
   *     "en" => "<p>In this course we go deep into.",
   *   ]
   *
   * @param $json
   * @return array
   * @throws Exception
   */
  protected function processDescriptions($json) {
    $elements = variable_get('uhc_course_implementation_source_predefined_description_names', array());
    $return = array();
    foreach (PortalMigrationBase::getSupportedLanguages() as $lang) {
      foreach ($elements as $element_id => $element) {

        // At least make empty value. This is important to ensure that we
        // collect the value multilingually *IN THE RIGHT ORDER*. The
        // order of which PortalMigrationBase::getSupportedLanguages()
        // returns should be used.
        $return[$element][$lang] = NULL;

        // This loop will loop descriptions until it finds values for each
        // element/language.
        if (!empty($json->$lang->data->descriptions)) {
          foreach ($json->$lang->data->descriptions as $json_description) {
            if ($json_description->element_id == $element_id) {
              $return[$element][$lang] = $json_description->description;
              break;
            }
          }
        }

      }
    }
    return $return;
  }
}
