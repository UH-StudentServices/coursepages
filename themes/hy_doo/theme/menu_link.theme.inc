<?php

function hy_doo_menu_link(array $variables) {
  $element = $variables['element'];

  // let's create shibboleth login / logout urls
  if ($element['#href'] == 'logout') {
    $logout_return_url = shib_auth_config('logout_url') . request_uri();
    $element['#href'] = url(shib_auth_get_handler_base() . '/Logout?return=' . $logout_return_url);
  }
  if ($element['#href'] == 'login') {
    $element['#href'] = shib_auth_generate_login_url();
  }
 
  // needed for fatmenu/mobilemenu/mainmenu
  $sub_menu = '';
  if ($element['#below']) {
    $sub_menu = drupal_render($element['#below']);
  }
  $output = l($element['#title'], $element['#href'], $element['#localized_options']);

  $main_menus = array(
    'open_university_menu_expanded',
  );

  $depth = $element['#original_link']['depth'];

  $element['#attributes']['class'][] = 'is-lvl' . $depth;

  // Add menu link id as an data-mlid attribute
  $element['#attributes']['data-mlid'] = $element['#original_link']['mlid'];

  if (isset($element['#bid']) && in_array($element['#bid']['delta'], $main_menus) && !empty($element['#below']) && $element['#original_link']['depth'] <= 2) {
    return '<li' . drupal_attributes($element['#attributes']) . '>
    <span class="main-menu__expand"></span>' . $output . $sub_menu . "</li>\n";
  }

  return '<li' . drupal_attributes($element['#attributes']) . '>' . $output . $sub_menu . "</li>\n";
}
