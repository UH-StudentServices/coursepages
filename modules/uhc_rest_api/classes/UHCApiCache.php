<?php

class UHCApiCache {

  const CACHE_BIN = 'cache';
  const CACHE_TIME_SECONDS = 60;

  public function get($cacheId) {
    $cachedData = cache_get($cacheId);

    return isset($cachedData->data) ? $cachedData->data : NULL;
  }

  public function set($cacheId, $data) {
    cache_set($cacheId, $data, self::CACHE_BIN, $this->getExpireTimestamp());
  }

  private function getExpireTimestamp() {
    return REQUEST_TIME + self::CACHE_TIME_SECONDS;
  }
}
