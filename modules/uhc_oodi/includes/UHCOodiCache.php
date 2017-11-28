<?php

/**
 * Class UHCOodiCache
 */
class UHCOodiCache {

  /**
   * @var string
   *   Cache bin that is used for all cache handlings.
   *
   * @see uhc_oodi_flush_caches()
   */
  protected $cacheBin = 'cache_uhc_oodi';

  /**
   * @var string
   *   When looking up from static cache, this is the prefix.
   */
  protected $staticPrefix = 'uhc_oodi_static_';

  /**
   * @var int
   *   The expire that is used during cache set. Can be set through
   *   UHCOodiCache->expire($expire).
   */
  protected $expire = CACHE_PERMANENT;

  /**
   * @param $expire
   *
   * @return $this
   */
  public function expire($expire) {
    $this->expire = $expire;
    return $this;
  }

  /**
   * @param $cid
   * @param $data
   *
   * @return mixed
   */
  public function set($cid, $data) {
    return cache_set($cid, $data, $this->cacheBin, $this->expire);
  }

  /**
   * @param $cid
   *
   * @return mixed
   */
  public function get($cid) {
    if ($static = &drupal_static($this->staticPrefix . $cid)) {
      return $static;
    }
    if ($cache_lookup = cache_get($cid, $this->cacheBin)) {
      return $static = $cache_lookup->data;
    }
    return FALSE;
  }

}
