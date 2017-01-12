<?php
/**
 * Implements theme_preprocess_HOOK().
 */
function hy_doo_preprocess_links(&$variables) {
  if (isset($variables['attributes']['class']['0']) && $variables['attributes']['class']['0'] == 'language-switcher-locale-url') {
    $variables['attributes']['class'] = array();
    $variables['attributes']['class'][] = 'links';
    foreach ($variables['links'] as $links => &$link) {
      $link['attributes']['class'] = array();
      $link['attributes']['class'][] = 'links__link';
      $link['attributes']['class'][] = 'theme-language';
    }
  }
}
