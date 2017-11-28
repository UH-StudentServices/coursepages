<?php

class UHCCourseImplementationApi {

  /** @var int[] */
  private $courseImplementationIds;

  /** @var EntityMetadataWrapper[] */
  private $entityMetadataWrappers;

  /** @var UHCApiCache */
  private $uhcApiCache;

  /** @var UHCApiCourseImplementationFormatter */
  private $uhcApiCourseImplementationFormatter;

  /** @var string */
  private $languageCode;

  public function __construct(
    array $courseImplementationIds,
    $languageCode,
    UHCApiCourseImplementationFormatter $uhcApiCourseImplementationFormatter,
    UHCApiCache $uhcApiCache) {

    $this->courseImplementationIds = $this->limitIds($courseImplementationIds);
    $this->languageCode = $languageCode;
    $this->uhcApiCache = $uhcApiCache;
    $this->uhcApiCourseImplementationFormatter = $uhcApiCourseImplementationFormatter;
  }

  protected function limitIds($ids, $length = 10) {
    return array_slice($ids, 0, $length);
  }

  public function get() {
    $cachedResponse = $this->getCachedResponse();

    if (!empty($cachedResponse)) {
      return $cachedResponse;
    }

    $response = array();
    $this->entityMetadataWrappers = $this->getCourseImplementationNodeWrappers();

    foreach ($this->entityMetadataWrappers as $entityMetadataWrapper) {
      $response[] = $this->uhcApiCourseImplementationFormatter->format($entityMetadataWrapper);
    }

    $this->cacheResponse($response);

    return $response;
  }

  protected function getCachedResponse() {
    return $this->uhcApiCache->get($this->getCacheId());
  }

  private function getCacheId() {
    return 'uhc-course-implementation-api-' . implode('-', $this->courseImplementationIds) . $this->languageCode;
  }

  protected function cacheResponse($response) {
    $this->uhcApiCache->set($this->getCacheId(), $response);
  }

  protected function getCourseImplementationNodeWrappers() {
    $nodeWrappers = array();

    foreach ($this->courseImplementationIds as $courseImplementationId) {
      $node = uhc_course_implementation_load_by_id($courseImplementationId);

      if (isset($node) && $node->status == NODE_PUBLISHED) {
        $nodeWrappers[] = entity_metadata_wrapper('node', $node)->language($this->languageCode);
      }
    }

    return $nodeWrappers;
  }


}
