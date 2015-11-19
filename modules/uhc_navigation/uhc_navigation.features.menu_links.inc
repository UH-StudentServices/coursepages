<?php
/**
 * @file
 * uhc_navigation.features.menu_links.inc
 */

/**
 * Implements hook_menu_default_menu_links().
 */
function uhc_navigation_menu_default_menu_links() {
  $menu_links = array();

  // Exported menu link: og-menu-single:http://www.helsinki.fi/fakta/
  $menu_links['og-menu-single:http://www.helsinki.fi/fakta/'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/fakta/',
    'router_path' => '',
    'link_title' => 'Universitet',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -39,
    'language' => 'sv',
    'customized' => 1,
  );
  // Exported menu link: og-menu-single:http://www.helsinki.fi/fonder/index.html
  $menu_links['og-menu-single:http://www.helsinki.fi/fonder/index.html'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/fonder/index.html',
    'router_path' => '',
    'link_title' => 'Service',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -42,
    'language' => 'sv',
    'customized' => 1,
  );
  // Exported menu link: og-menu-single:http://www.helsinki.fi/forskning/
  $menu_links['og-menu-single:http://www.helsinki.fi/forskning/'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/forskning/',
    'router_path' => '',
    'link_title' => 'Forskning',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -45,
    'language' => 'sv',
    'customized' => 1,
  );
  // Exported menu link: og-menu-single:http://www.helsinki.fi/funds/index.html
  $menu_links['og-menu-single:http://www.helsinki.fi/funds/index.html'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/funds/index.html',
    'router_path' => '',
    'link_title' => 'Services',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -44,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: og-menu-single:http://www.helsinki.fi/inbrief/
  $menu_links['og-menu-single:http://www.helsinki.fi/inbrief/'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/inbrief/',
    'router_path' => '',
    'link_title' => 'University',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -41,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: og-menu-single:http://www.helsinki.fi/lyhyesti/index.html
  $menu_links['og-menu-single:http://www.helsinki.fi/lyhyesti/index.html'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/lyhyesti/index.html',
    'router_path' => '',
    'link_title' => 'Yliopisto',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -40,
    'language' => 'fi',
    'customized' => 1,
  );
  // Exported menu link: og-menu-single:http://www.helsinki.fi/yritykset/index.html
  $menu_links['og-menu-single:http://www.helsinki.fi/yritykset/index.html'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/yritykset/index.html',
    'router_path' => '',
    'link_title' => 'Palvelut',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -43,
    'language' => 'fi',
    'customized' => 1,
  );
  // Exported menu link: og-menu-single:http://www.helsinki.fi/research/
  $menu_links['og-menu-single:http://www.helsinki.fi/research/'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/research/',
    'router_path' => '',
    'link_title' => 'Research',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -47,
    'language' => 'en',
    'customized' => 1,
  );
  // Exported menu link: og-menu-single:http://www.helsinki.fi/tutkimus/
  $menu_links['og-menu-single:http://www.helsinki.fi/tutkimus/'] = array(
    'menu_name' => 'og-menu-single',
    'link_path' => 'http://www.helsinki.fi/tutkimus/',
    'router_path' => '',
    'link_title' => 'Tutkimus',
    'options' => array(
      'attributes' => array(
        'title' => '',
      ),
      'alter' => TRUE,
    ),
    'module' => 'menu',
    'hidden' => 0,
    'external' => 1,
    'has_children' => 0,
    'expanded' => 0,
    'weight' => -46,
    'language' => 'fi',
    'customized' => 1,
  );
  // Translatables
  // Included for use with string extractors like potx.
  t('Forskning');
  t('Palvelut');
  t('Research');
  t('Service');
  t('Services');
  t('Tutkimus');
  t('Universitet');
  t('University');
  t('Yliopisto');


  return $menu_links;
}
