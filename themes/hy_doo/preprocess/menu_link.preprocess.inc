<?php
/**
 * Implements theme_preprocess_menu_link().
 *
 * Loads the node id array we cached in hook_translated_menu_link_alter()
 * And add 's-hidden' class to menu items that are in wrong language.
 *
 */
function hy_doo_preprocess_menu_link(&$variables) {

  // Front page link class
  $front_page_paths = array('student', 'teacher', 'https://www.helsinki.fi/fi/avoin-yliopisto');
  if (in_array($variables['element']['#original_link']['link_path'], $front_page_paths)) {
    $variables['element']['#attributes']['class'][] = 'main-menu__front';
  }

  // If menu link has children, give class
  if (in_array('expanded', $variables['element']['#attributes']['class'])) {
    $variables['element']['#attributes']['class'][] = 'is-expandable';
  }

  if ($variables['element']['#theme'] == 'menu_link__menu_header_links') {
    $variables['element']['#localized_options']['attributes']['class'][] = 'links__link';
  }
}
