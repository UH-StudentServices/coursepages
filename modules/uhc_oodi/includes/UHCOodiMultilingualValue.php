<?php

class UHCOodiMultilingualValue {

  /**
   * @var array
   *   Contains preferred order of language.
   *
   * @todo: Could this be from Drupal configuration?
   */
  protected $preferredOrderOfLanguage = array('fi', 'en', 'sv');

  /**
   * @var array
   *   Contains all translated values.
   */
  protected $translations;

  /**
   * @var string
   *   Contains the primary language we want to render the value as.
   */
  protected $language = LANGUAGE_NONE;

  /**
   * UHCOodiMultilingualValue constructor.
   *
   * @param array $translations
   */
  public function __construct(array $translations) {
    $this->translations = $translations;
  }

  /**
   * @param $language
   *   Set the language we want to return value as.
   *
   * @return $this
   */
  public function language($language) {
    $this->language = $language;
    return $this;
  }

  /**
   * Returns the value of given translation.
   *
   * @return mixed|null
   */
  public function getValue() {

    // When we don't have specified language...
    if ($this->language == LANGUAGE_NONE) {
      foreach ($this->preferredOrderOfLanguage as $preferredLanguage) {
        foreach ($this->translations as $translation) {
          if ($translation['langcode'] == $preferredLanguage) {
            return $translation['text'];
          }
        }
      }
    }
    else {
      // Or else get the value of specified language
      foreach ($this->translations as $translation) {
        if ($translation['langcode'] == $this->language) {
          return $translation['text'];
        }
      }
    }

    // Return NULL if values not found on preferred or specified languages.
    return NULL;
  }
}
