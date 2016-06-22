<?php
/**
 * @file
 * uhc_open_university.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function uhc_open_university_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-open-university-footer-link.
  $menus['menu-open-university-footer-link'] = array(
    'menu_name' => 'menu-open-university-footer-link',
    'title' => 'Open university footer links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-open-university-navigation.
  $menus['menu-open-university-navigation'] = array(
    'menu_name' => 'menu-open-university-navigation',
    'title' => 'Open university navigation',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: menu-open-university-some-links.
  $menus['menu-open-university-some-links'] = array(
    'menu_name' => 'menu-open-university-some-links',
    'title' => 'Open university some links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 0,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Open university footer links');
  t('Open university navigation');
  t('Open university some links');

  return $menus;
}
