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
  // Add font awesome
  drupal_add_css('//netdna.bootstrapcdn.com/font-awesome/4.1.0/css/font-awesome.min.css', array('type' => 'external'));
  drupal_add_css('//fonts.googleapis.com/css?family=Open+Sans:300,400,600,700', array('type' => 'external'));

  // Load the fallback.css for Internet Explorer 8 and lower.
  $path = drupal_get_path('theme', 'hy_doo');
  drupal_add_css("$path/css/hy_doo.fallback.css", array(
    'browsers' => array(
      '!IE' => FALSE,
      'IE' => 'lte IE 8',
    ),
    'group' => CSS_THEME,
    'weight' => 1000,
  ));

  // Check for favicons from registry and add them to head after a thorough checkup
  $registry = theme_get_registry(FALSE);

  if (!empty($registry['html']['mobile-favicons'])) {
    favicon_get_meta_information($registry['html']['mobile-favicons']);
  }

  // Page title alterations
  if (!empty($variables['page']['content']['system_main']['nodes'])) {
    $nodes = $variables['page']['content']['system_main']['nodes'];
    if (count($nodes) != 2) {
      return;
    }

    // Get rid of the unneeded variable so we can reliably pop out the node at whatever index it is
    unset($nodes['#sorted']);
    $node = reset($nodes);
    $node = $node['#node'];

    // Alter the site name when on an open university course or course_imp page
    $altered_title = explode(' | ', $variables['head_title']);
    if (uhc_open_university_is_open_university_course_or_implementation($node)) {
      $altered_title[1] = t('The University of Helsinki Open University');
    }

    // Add subject(s) and add them to the title. If this is a course imp node, fetch course first.
    if ($node->type == 'course_implementation') {
      if ($course_id = field_get_items('node', $node, 'field_imp_reference_to_courses')[0]['target_id']) {
        $node = node_load($course_id);
      }
    }
    if (!empty($node->field_course_subject)) {
      // Add subject(s) between the node title and site name
      $altered_title[2] = $altered_title[1];
      $course_subjects = field_get_items('node', $node, 'field_course_subject');
      if (!empty($course_subjects)) {
        $subjects = array();
        foreach ($course_subjects as $course_subject) {
          $subjects[] = $course_subject['value'];
        }
        $altered_title[1] = implode(', ', $subjects);
      }
    }
    $variables['head_title'] = implode(' | ', $altered_title);
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