<?php
/**
 * @file
 * uhc_navigation.features.menu_custom.inc
 */

/**
 * Implements hook_menu_default_menu_custom().
 */
function uhc_navigation_menu_default_menu_custom() {
  $menus = array();

  // Exported menu: menu-header-links.
  $menus['menu-header-links'] = array(
    'menu_name' => 'menu-header-links',
    'title' => 'Header links',
    'description' => '',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: og-menu-single.
  $menus['og-menu-single'] = array(
    'menu_name' => 'og-menu-single',
    'title' => 'OG menu',
    'description' => 'Contains all the links for organic groups and their menus',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Exported menu: user-menu.
  $menus['user-menu'] = array(
    'menu_name' => 'user-menu',
    'title' => 'User menu',
    'description' => 'The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.',
    'language' => 'und',
    'i18n_mode' => 5,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Contains all the links for organic groups and their menus');
  t('Header links');
  t('OG menu');
  t('The <em>User</em> menu contains links related to the user\'s account, as well as the \'Log out\' link.');
  t('User menu');

  return $menus;
}
