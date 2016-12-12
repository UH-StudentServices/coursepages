<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_preprocess_html().
 */
function hy_doo_preprocess_html(&$variables) {
  _hy_doo_preprocess_add_favicon_meta_information();
  _hy_doo_preprocess_generate_head_title($variables);
  _hy_doo_preprocess_add_omega_mediaqueries();
}

/**
 * Add media queries for use in javascript
 */
function _hy_doo_preprocess_add_omega_mediaqueries() {
  drupal_add_js(array(
    'omega' => array(
      'mediaQueries' => array(
        'layout-mobile' => 'screen and (max-width: 48em)',
        'layout-small' => 'screen and (min-width: 48em)',
        'layout-medium' => 'screen and (min-width: 62.5em)',
        'layout-large' => 'screen and (min-width: 75em)',
      )
    )
  ), 'setting');
}

/**
 * Check for favicons from registry and add them to head after a thorough
 * checkup.
 */
function _hy_doo_preprocess_add_favicon_meta_information() {
  $registry = theme_get_registry(FALSE);

  if (!empty($registry['html']['mobile-favicons'])) {
    favicon_get_meta_information($registry['html']['mobile-favicons']);
  }
}

function favicon_get_meta_information($favicons) {
  // Let's start html head item weight from 20
  $weight = 20;

  // Iterate over the array of touch icons and attributes.
  foreach ($favicons as $icon) {
    switch ($icon['file-type']) {
      // Go through file types. In our case png and ico are found.
      case 'png':

        // Go through icon types (names) and set their meta information to meta variable.
        switch ($icon['icon-type']) {
          case 'apple-touch-icon':
            $meta = favicon_insert_meta_information($icon, 'link', 'apple-touch-icon', array(
              'rel',
              'href'
            ));
            break;

          case 'mstile':
            switch ($icon['sizes']) {
              case '144x144':
                $rel = 'msapplication-TileImage' . $icon['sizes'] . 'logo';
                break;
              case '310x150':
                $rel = 'msapplication-wide' . $icon['sizes'] . 'logo';
                break;
              default:
                $rel = 'msapplication-square' . $icon['sizes'] . 'logo';
                break;
            }
            $meta = favicon_insert_meta_information($icon, 'meta', $rel, array(
              'name',
              'content'
            ));

            break;

          case 'favicon':
            $meta = favicon_insert_meta_information($icon, 'link', 'icon');
            $meta['#attributes']['type'] = 'image/png';
            break;
        }
        break;

      case 'ico':
        $meta = favicon_insert_meta_information($icon, 'link', 'shortcut icon');
        break;
    }

    // Check if we should add additional attribute for icon size.
    if (!empty($icon['sizes']) && $icon['icon-type'] != 'mstile' && $icon['file-type'] != 'ico') {
      $meta['#attributes']['sizes'] = $icon['sizes'];
    }

    // Add the touch icon to the html head using a unique key.
    $key = 'mobile-touch-' . (!empty($icon['icon-type']) ? $icon['icon-type'] : '') . (!empty($icon['sizes']) ? '-' . $icon['sizes'] : '') . (!empty($icon['precomposed']) ? '-precomposed' : '');

    if (!empty($meta)) {
      // Add weight to meta information and add the whole array to html head
      $meta['#weight'] = $weight;
      drupal_add_html_head($meta, $key);
      $weight++;
    }
  }

  // We need to add separate base color meta information for MS tiles.
  drupal_add_html_head(
    array(
      '#tag' => 'meta',
      '#attributes' => array(
        'name' => 'msapplication-TileColor',
        'content' => '#ffffff',
      ),
      '#weight' => $weight,
    ),
    'mobile-touch-mstile-color'
  );
}

/**
 * Function to return meta information for different favicon types.
 *
 * @param $icon
 * @return array
 */
function favicon_insert_meta_information($icon, $tag, $rel, $attr = array('rel', 'href')) {
  if (!empty($icon)) {
    $meta = array(
      '#tag' => $tag,
      '#attributes' => array(
        $attr[0] => $rel . (!empty($icon['precomposed']) ? '-precomposed' : ''),
        $attr[1] => file_create_url($icon['uri']),
      ),
    );

    return $meta;
  }
}

/**
 * Generate head title.
 */
function _hy_doo_preprocess_generate_head_title(&$variables) {
  if (!empty($variables['page']['content']['system_main']['nodes'])) {
    $nodes = $variables['page']['content']['system_main']['nodes'];
    if (count($nodes) != 2) {
      return;
    }

    // Get rid of the unneeded variable so we can reliably pop out the node at whatever index it is
    unset($nodes['#sorted']);
    $node = reset($nodes);
    $node = $node['#node'];

    $altered_title = explode(' | ', $variables['head_title']);
    if (uhc_open_university_is_open_university_context($node)) {
      array_splice($altered_title, 1, 0, t('Open University'));
    }

    // Add subject(s) and add them to the title. If this is a course imp node, fetch course first.
    if ($node->type == 'course_implementation') {
      if ($course_id = field_get_items('node', $node, 'field_imp_reference_to_courses')[0]['target_id']) {
        $node = node_load($course_id);
      }
    }
    if (!empty($node->field_course_subject)) {
      // Add subject(s) between the node title and site name
      $course_subjects = field_get_items('node', $node, 'field_course_subject');
      if (!empty($course_subjects)) {
        $subjects = array();
        foreach ($course_subjects as $course_subject) {
          $subjects[] = $course_subject['value'];
        }
        array_splice($altered_title, 1, 0, implode(', ', $subjects));
      }
    }
    $variables['head_title'] = implode(' | ', $altered_title);
  }
  elseif (uhc_open_university_is_open_university_context()) {
    $altered_title = explode(' | ', $variables['head_title']);
    array_splice($altered_title, 1, 0, t('Open University'));
    $variables['head_title'] = implode(' | ', $altered_title);
  }

  if (uhc_open_university_is_open_university_context()) {
    $variables['head_title'] = _hy_doo_preprocess_remove_courses_string_from_title($variables['head_title']);
  }

  if (_hy_doo_preprocess_is_search_page($variables)) {
    $variables['head_title'] = t('Search for courses') . ' | ' . $variables['head_title'];
  }
}

function _hy_doo_preprocess_is_search_page(&$variables) {
  $search_page_classes = array(
    'search-main-page',
    'page-search',
    'page-open-university-search',
    'page-genetics-search',
    'page-molecular-biosciences-search'
  );

  return !empty($variables['classes_array'])
    && count(array_intersect($search_page_classes, $variables['classes_array'])) > 0;
}

function _hy_doo_preprocess_remove_courses_string_from_title($title) {
  $search = array('Courses |', 'Kurssit |', 'Kurser |');

  return str_replace($search, '', $title);
}
