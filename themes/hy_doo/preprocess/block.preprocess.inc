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

  switch ($variables['block_html_id']) {
    case 'block-locale-language':
      $variables['classes_array'] = array();
      $variables['classes_array'][] = 'l-top-bar__subright';
      $variables['title_attributes_array']['class'][] = 'is-hidden';
      break;
    case 'block-menu-menu-header-links':
      $variables['classes_array'] = array();
      $variables['classes_array'][] = 'l-top-bar__subleft';
      break;
    case 'block-uh-coursepages-uhc-logo-block':
      $variables['classes_array'] = array();
      break;
    case 'block-uh-coursepages-uhc-contact-logo-block':
      $variables['classes_array'] = array();
      $variables['classes_array'][] = 'l-footer__column';
      $variables['classes_array'][] = 'theme-sub';
      break;
  }

}
