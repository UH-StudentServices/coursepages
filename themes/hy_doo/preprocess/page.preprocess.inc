<?php

/**
 * Implements hook_preprocess_page().
 */
function hy_doo_preprocess_page(&$variables) {
  // Add burger to top_bar region
  if (isset($variables['page']['top_bar']) && !isset($variables['page']['top_bar']['custom_menu_togle'])) {
    $variables['page']['top_bar']['custom_menu_toggle'] = array(
      '#markup' => l(t('Menu'), '#', array(
        'external' => TRUE,
        'attributes' => array(
          'id' => 'menu-toggle',
          'class' => 'nav-toggle'
        ),
      )),
      '#weight' => '50'
    );
  }
}
