<?php
/**
 * @file
 * uhc_doo_theme_features.strongarm.inc
 */

/**
 * Implements hook_strongarm().
 */
function uhc_doo_theme_features_strongarm() {
  $export = array();

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_jpeg_quality';
  $strongarm->value = '100';
  $export['image_jpeg_quality'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'image_toolkit';
  $strongarm->value = 'gd';
  $export['image_toolkit'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'node_admin_theme';
  $strongarm->value = 0;
  $export['node_admin_theme'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_adminimal_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 0,
    'favicon_path' => 'profiles/uh_coursepages/themes/hy_doo/hy_favicon.ico',
    'favicon_upload' => '',
    'style_checkboxes' => 1,
    'display_icons_config' => 1,
    'avoid_custom_font' => 0,
    'use_custom_media_queries' => 0,
    'media_query_mobile' => 'only screen and (max-width: 480px)',
    'media_query_tablet' => 'only screen and (min-width : 481px) and (max-width : 1024px)',
    'custom_css' => 0,
    'adminimal_theme_skin' => 'default',
    'favicon_mimetype' => 'image/vnd.microsoft.icon',
  );
  $export['theme_adminimal_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_default';
  $strongarm->value = 'hy_doo';
  $export['theme_default'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_hy_doo_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'omega_toggle_front_page_content' => 0,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 1,
    'favicon_path' => 'profiles/uh_coursepages/themes/hy_doo/hy_favicon.ico',
    'favicon_upload' => '',
    'omega_enable_warning' => TRUE,
    'omega_toggle_extension_layouts' => 1,
    'omega_layout' => 'hyj-basic',
    'omega_toggle_extension_development' => 0,
    'omega_enable_export_reminder' => NULL,
    'omega_rebuild_theme_registry' => '1',
    'omega_rebuild_aggregates' => '1',
    'omega_browser_width_indicator' => '0',
    'omega_livereload' => '0',
    'omega_livereload_script' => 'http://localhost:35729/livereload.js',
    'omega_livereload_host' => 'localhost',
    'omega_livereload_port' => '35729',
    'omega_demo_regions' => '0',
    'omega_demo_regions_list' => NULL,
    'omega_toggle_extension_compatibility' => 1,
    'omega_conditional_classes_html' => 1,
    'omega_apple_touch' => 0,
    'omega_cleartype' => 1,
    'omega_handheld_friendly' => 1,
    'omega_mobile_optimized' => 1,
    'omega_viewport' => 1,
    'omega_viewport_initial_scale' => '_default',
    'omega_viewport_user_scaleable' => 1,
    'omega_viewport_minimum_scale' => '_default',
    'omega_viewport_maximum_scale' => '_default',
    'omega_chrome_edge' => 1,
    'omega_internet_explorer_support' => '_none',
    'omega_toggle_extension_assets' => 1,
    'omega_js_footer' => array(),
    'omega_css_exclude' => array(
      0 => 'misc/*',
      1 => 'sites/all/modules/contrib/field_group/*',
      2 => 'sites/all/modules/contrib/field_collection/*',
      3 => 'sites/all/modules/contrib/date/date_api/date.css',
      4 => 'sites/all/modules/contrib/link/link.css',
      5 => 'sites/all/modules/contrib/inline_entity_form/theme/inline_entity_form.css',
      6 => 'sites/all/modules/contrib/views/css/views.css',
      7 => 'sites/all/themes/omega/omega/omega/css/modules/system/system.messages.theme.css',
      8 => 'sites/all/themes/omega/omega/omega/css/modules/system/system.menus.theme.css',
      9 => 'sites/all/themes/omega/omega/omega/css/modules/system/system.theme.css',
      10 => 'sites/all/themes/omega/omega/omega/css/modules/filter/filter.theme.css',
      11 => 'sites/all/themes/omega/omega/omega/css/modules/system/system.base.css',
      12 => 'sites/all/themes/omega/omega/omega/css/modules/image/image.theme.css',
    ),
    'omega_js_exclude' => array(
      0 => 'misc/tableheader.js',
    ),
    'omega_libraries' => array(
      'selectivizr' => array(
        'status' => 0,
        'variant' => '_default',
      ),
      'respond' => array(
        'status' => 0,
        'variant' => '_default',
      ),
      'pie' => array(
        'status' => 0,
        'variant' => '_default',
        'selectors' => array(),
      ),
      'html5shiv' => array(
        'status' => 0,
        'variant' => '_default',
      ),
    ),
  );
  $export['theme_hy_doo_settings'] = $strongarm;

  $strongarm = new stdClass();
  $strongarm->disabled = FALSE; /* Edit this to true to make a default strongarm disabled initially */
  $strongarm->api_version = 1;
  $strongarm->name = 'theme_settings';
  $strongarm->value = array(
    'toggle_logo' => 1,
    'toggle_name' => 1,
    'toggle_slogan' => 1,
    'toggle_node_user_picture' => 1,
    'toggle_comment_user_picture' => 1,
    'toggle_comment_user_verification' => 1,
    'toggle_favicon' => 1,
    'toggle_main_menu' => 1,
    'toggle_secondary_menu' => 1,
    'default_logo' => 1,
    'logo_path' => '',
    'logo_upload' => '',
    'default_favicon' => 0,
    'favicon_path' => 'profiles/uh_coursepages/themes/hy_doo/hy_favicon.ico',
    'favicon_upload' => '',
    'favicon_mimetype' => 'image/vnd.microsoft.icon',
  );
  $export['theme_settings'] = $strongarm;

  return $export;
}
