<?php

class UHCApiCourseImplementationFormatter {

  const IMAGE_STYLE = 'liftup_322_x_190';

  /** @var string */
  private $languageCode;

  /** @var UHCApiEventFormatter */
  private $uhcApiEventFormatter;

  public function __construct(UHCApiEventFormatter $uhcApiEventFormatter, $languageCode) {
    $this->languageCode = $languageCode;
    $this->uhcApiEventFormatter = $uhcApiEventFormatter;
  }

  public function format($entityMetadataWrapper) {
    $courseImplementation = new stdClass();
    $courseImplementation->courseImplementationId = $this->getCourseImplementationId($entityMetadataWrapper);
    $courseImplementation->events = $this->getEvents($entityMetadataWrapper);
    $courseImplementation->hasMaterial = $this->hasMaterial($entityMetadataWrapper);
    $courseImplementation->headerHeadline = $this->getHeaderHeadline($entityMetadataWrapper);
    $courseImplementation->headerImageAttribution = $this->getHeaderImageAttribution($entityMetadataWrapper);
    $courseImplementation->headerImageUrl = $this->getHeaderImageUrl($entityMetadataWrapper);
    $courseImplementation->headerText = $this->getHeaderText($entityMetadataWrapper);
    $courseImplementation->moodleUrl = $this->getMoodleUrl($entityMetadataWrapper);
    $courseImplementation->nid = $this->getNid($entityMetadataWrapper);
    $courseImplementation->title = $this->getTitle($entityMetadataWrapper);
    $courseImplementation->url = $this->getUrl($entityMetadataWrapper);
    $courseImplementation->wikiUrl = $this->getWikiUrl($entityMetadataWrapper);

    return $courseImplementation;
  }

  private function getCourseImplementationId($entityMetadataWrapper) {
    return (int) $entityMetadataWrapper->field_imp_id->value();
  }

  private function getEvents($entityMetadataWrapper) {
    $events = array();
    $eventNodes = $entityMetadataWrapper->field_imp_reference_to_events->value();

    foreach ($eventNodes as $eventNode) {
      if ($eventNode->status == NODE_PUBLISHED) {
        $events[] = $this->uhcApiEventFormatter->format($eventNode);
      }
    }

    return $events;
  }

  private function getHeaderHeadline($entityMetadataWrapper) {
    return $entityMetadataWrapper->field_imp_header_headline->value()['value'];
  }

  private function getHeaderImageAttribution($entityMetadataWrapper) {
    return $entityMetadataWrapper->field_imp_header_image_caption->value()['value'];
  }

  private function getHeaderImageUrl($entityMetadataWrapper) {
    $image = $entityMetadataWrapper->field_imp_header_image->value();

    return image_style_url(self::IMAGE_STYLE, $image['uri']);
  }

  private function getHeaderText($entityMetadataWrapper) {
    return $entityMetadataWrapper->field_imp_header_text->value()['value'];
  }

  protected function hasMaterial($entityMetadataWrapper) {
    return uhc_course_implementation_has_material($entityMetadataWrapper->raw());
  }

  private function getMoodleUrl($entityMetadataWrapper) {
    return $entityMetadataWrapper->field_moodle_url->value()['url'];
  }

  private function getNid($entityMetadataWrapper) {
    return (int) $entityMetadataWrapper->getIdentifier();
  }

  private function getTitle($entityMetadataWrapper) {
    return $entityMetadataWrapper->label();
  }

  protected function getUrl($entityMetadataWrapper) {
    $path_alias =  drupal_get_path_alias("node/{$entityMetadataWrapper->getIdentifier()}");

    return $GLOBALS['base_url'] . '/' . $this->languageCode . '/' . $path_alias;
  }

  private function getWikiUrl($entityMetadataWrapper) {
    return $entityMetadataWrapper->field_wiki_url->value()['url'];
  }
}