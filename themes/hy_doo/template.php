<?php
/**
 * @file
 * Template overrides as well as (pre-)process and alter hooks for the
 * Helsingin Yliopisto DOO subtheme.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * @param $variables
 */
function hy_doo_preprocess_select_as_links(&$variables) {
  // Replace the stupid '- Any -' with 'All'
  $variables['element']['#options']['All'] = t('All');
}

/**
 * Implement hook_preprocess_views_view().
 *
 * This will apply certain views template (course search) for the view's which
 * are for searching courses and applying the shared styling.
 */
function hy_doo_preprocess_views_view(&$vars) {
  if (in_array($vars['view']->name, array('uhc_search', 'uhc_search_open_university'))) {

    // Suggest certain theming template for these two views
    $vars['theme_hook_suggestions'][] = 'views_view__course_search';

    // Default formatting for translatable area text is little too orphan
    // looking, so tweak slightly the empty formatting by wrapping it with
    // headline element! \,,/
    if (!empty($vars['empty'])) {
      $vars['empty'] = '<h2>' . strip_tags($vars['empty']) . '</h2>';
    }

  }
}

/**
 * Implement hook_preprocess_views_view_list().
 * Template for views lists with grouping as accordions
 */
function hy_doo_preprocess_views_view_list(&$vars) {
  if (in_array($vars['view']->name, array('subjects_by_category', 'studies_by_category'))) {
    $vars['theme_hook_suggestions'][] = 'views_view_list__group_by_accordion';
  }
}

/**
 * Override theme_status_messages().
 *
 * @param $variables
 * @return string
 */
function hy_doo_status_messages($variables) {
  $display = $variables['display'];
  $output = '';

  $status_heading = array(
    'status' => t('Status message'),
    'error' => t('Error message'),
    'warning' => t('Warning message'),
  );
  foreach (drupal_get_messages($display) as $type => $messages) {
    $output .= '<div class="messages ' . $type . '">';
    if (!empty($status_heading[$type])) {
      $output .= '<h2 class="element-invisible">' . $status_heading[$type] . "</h2>";
    }
    $close = t('Close');
    if (count($messages) > 1) {
      $output .= '<ul>';
      foreach ($messages as $message) {
        $output .= '  <li>' . $message . '</li>';
      }
      $output .= '</ul><a class="close" href="#" title="'.$close.'"></a>';
    }
    else {
      $output .= '<p>' . $messages[0] . '</p><a class="close" href="#" title="'.$close.'"></a>';
    }
    $output .= '</div>';
  }

  return $output;
}

/**
 * Implements hook_extension_EXTENSION_registry_alter().
 *
 * Add favicons and mobile/tablet icons under head tag.
 */
function hy_doo_theme_registry_alter(&$registry) {
  // The regex finds all files following certain naming conventions.
  $mask = '/^(favicon|mstile|browserconfig|apple-touch-icon)(-precomposed)?(-([0-9]+x[0-9]+))?\.(png|ico|xml)$/';

  // Loop over all themes in the trail in reverse (starting with the current
  // theme) and use the touch icons of the first theme we find. The favicon files
  // are found under theme_name/images
  foreach (array_reverse(omega_theme_trail()) as $theme => $name) {
    $path = drupal_get_path('theme', $theme) . '/images/favicons';

    // Scan files from the path and iterate through the files
    if ($files = file_scan_directory($path, $mask, array('recurse' => FALSE))) {
      foreach ($files as $file) {
        $matches = array();

        // Run the filename through the regex once more picking up the
        // sub-matches in order to find out the dimensions and other information
        // of the files.
        preg_match($mask, $file->filename, $matches);

        // Cache the array of apple touch icons.
        $registry['html']['mobile-favicons'][$file->uri] = array(
          'uri' => $file->uri,
          'precomposed' => !empty($matches[2]) ? $matches[2] : FALSE,
          'sizes' => !empty($matches[4]) ? $matches[4] : FALSE,
          'icon-type' => $matches[1],
          'file-type' => $matches[5],
        );
      }

      // Break out of the loop because we found at least one touch icon.
      break;
    }
  }

  // Use custom pager function for pager_lite (class names).
  $registry['pager_lite']['function'] = 'hy_doo_custom_pager_lite';
}

/**
 * Overrides theme_image_url_formatter().
 *
 * Original theming function generates PHP notices about missing 'alt' and
 * 'title' due to poor rendering/processing in services_views module.
 *
 * As a workaround, we sanity check them and set empty strings when needed.
 */
function hy_doo_image_url_formatter($variables) {
  $variables['item']['alt'] = !empty($variables['item']['alt']) ? $variables['item']['alt'] : '';
  $variables['item']['title'] = !empty($variables['item']['title']) ? $variables['item']['title'] : '';
  return theme_image_url_formatter($variables);
}

/**
 * Implements hook_menu_local_tasks_alter().
 *
 * add Class to menu local tasks edit and teach edit links
 */
function hy_doo_menu_local_tasks_alter(&$data, $router_item, $root_path) {
  if (!empty($data['tabs'])) {
    foreach ($data['tabs'][0]['output'] as &$link) {
      if (!empty($link['#link']['description'])) {
        $link['#link']['localized_options']['attributes']['class'][] = t($link['#link']['description']);
      }
      if($link['#link']['path'] == 'node/%/edit') {
        $link['#link']['localized_options']['attributes']['class'][] = 'edit-link';
      }
    }
  }
}

/**
 * Implements hook_form_alter().
 * Add JS for mobile vertical tabs.
 */
function hy_doo_form_alter(&$form, &$form_state, $form_id) {
  $form['#attached']['js'][] = drupal_get_path('theme', 'hy_doo') . '/js/help-widgets.js';
  if (isset($form['#node_edit_form']) && $form['#node_edit_form'] == TRUE) {
    $form['#attached']['js'][] = drupal_get_path('theme', 'hy_doo') . '/js/vertical_tabs.js';
  }
}

/**
 * Override of theme_breadcrumb().
 *
 * Remove trailing slash.
 * @TODO Do this same change to the base theme after it's been tested together
 * with other changes: https://github.com/UH-StudentServices/hy_base_theme
 */
function hy_doo_breadcrumb($variables) {
  $breadcrumb = $variables['breadcrumb'];

  if (!empty($breadcrumb)) {

    // Provide a navigational heading to give context for breadcrumb links to
    // screen-reader users. Make the heading invisible with .element-invisible.
    $output = '<h2 class="element-invisible">' . t('You are here') . '</h2>';
    $output .= '<div class="breadcrumbs">';

    $last = end($breadcrumb);
    foreach ($breadcrumb as $breadcrumb_item) {
      $output .= '<span class="breadcrumbs__item">' . $breadcrumb_item . ' </span>';
      if ($breadcrumb_item != $last) {
        $output .= '<span class="breadcrumbs__divider">/</span>';
      }
    }
    $output .= '</div>';
    return $output;
  }
}

/**
 * Theme callback for 'favorite_widget'.
 * @param $variables
 * @return string
 */
function hy_doo_favorite_widget($variables) {
  $node = $variables['node'];
  $add_to_favorites_label = $variables['add_to_favorites_label'];
  $delete_from_favorites_label = $variables['delete_from_favorites_label'];

  $data = '(function($){
    $(".favorite-widget--nid--' . $node->nid . '")
      .favoriteWidget({
        id: ' . $node->nid . ',
        addToFavLabel: "' . $add_to_favorites_label . '",
        delFromFavLabel: "' . $delete_from_favorites_label . '",
        wrapperClassName: "favoritewidget button__inline",
        inlineElement: "span",
        inlineElementClassName: "button button--info icon--favorites",
        addedCallback: function (event, data) {
          Drupal.behaviors.uhc_favorites.setFavoritesLink();
        },
        removedCallback:function (event, data) {
          Drupal.behaviors.uhc_favorites.setFavoritesLink();
        }
    });
  })(jQuery)
  ';
  $options = array(
    'type' => 'inline',
    'scope' => 'footer',
    'group' => JS_DEFAULT,
    'requires_jquery' => TRUE,
  );
  drupal_add_js($data, $options);
  return '<div class="favorite-widget--nid--' . $node->nid . '"></div>';
}

/**
 * Implements theme_menu_tree_MENU_NAME().
 * Add styleguide classes to header links menu ul.
 */
function hy_doo_menu_tree__menu_header_links($variables) {
  return '<ul class="links">' . $variables['tree'] . '</ul>';
}

/**
 * Implements hook_preprocess_field_collection_view().
 */
function hy_doo_preprocess_field_collection_view(&$variables) {
  if (!isset($variables['element']['entity']['field_collection_item'])) {
    return;
  }

  // Resolve the corresponding $entity, so we can decide whether to add the
  // class or not.
  $key = array_keys($variables['element']['entity']['field_collection_item'])[0];
  $entity = $variables['element']['entity']['field_collection_item'][$key]['#entity'];
  $field_study_module_subheading = field_get_items('field_collection_item', $entity, 'field_study_module_subheading');
  $subheading_value = !empty($field_study_module_subheading[0]['value']) ? TRUE : FALSE;

  // If subheading checkbox has been checked, then add the class
  if ($subheading_value) {
    $variables['element']['#attributes']['class'][] = 'subheading';
  }

}

/**
 * Changes the texts and the class names of previous and next links to match the
 * text conventions and styleguide.
 *
 * "pager-next" -> "pager__next"
 * "pager-previous" -> "pager__previous"
 */
function hy_doo_custom_pager_lite($variables) {
  $tags = $variables['tags'];
  $element = $variables['element'];
  $parameters = $variables['parameters'];
  global $pager_page_array, $pager_total;

  // current is the page we are currently paged to
  $pager_current = $pager_page_array[$element] + 1;


  $li_previous = theme('pager_previous', array('text' => (isset($tags[1]) ? $tags[1] : t('‹ previous')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  if (empty($li_previous)) {
    $li_previous = "&nbsp;";
  }

  $li_next = theme('pager_lite_next', array('text' => (isset($tags[3]) ? $tags[3] : t('next ›')), 'element' => $element, 'interval' => 1, 'parameters' => $parameters));
  if (empty($li_next)) {
    $li_next = "&nbsp;";
  }

  $items[] = array(
    'class' => array('pager__previous'),
    'data' => $li_previous,
  );

  $items[] = array(
    'class' => array('pager-current'),
    'data' => format_plural($pager_current, 'Page 1', 'Page @count'),
  );

  $items[] = array(
    'class' => array('pager__next'),
    'data' => $li_next,
  );
  return theme('item_list', array(
    'items' => $items,
    'title' => NULL,
    'type' => 'ul',
    'attributes' => array('class' => array('pager')),
    )
  );
}