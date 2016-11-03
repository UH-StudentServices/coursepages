<?php
/**
 * Implements template_preprocess_block().
 * Add classes to views exposed filter blocks.
 */
function hy_doo_preprocess_block(&$variables) {
  $view_blocks = array(
    '0580398bf6a2f9d60b32760e9900b13c',
    'ddc12e0f6574edc3850aacc947821543',
    '6e81312883288ad7f0d23af96a88ead6',
    '-exp-uhc_search-desktop'
  );

  foreach ($view_blocks as $delta) {
    if ($variables['block']->delta == $delta) {
      $variables['classes_array'][] = 'search-filters';
    }
  }
}
