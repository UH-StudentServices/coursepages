<?php

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

  // Load the matchMedia polyfill.
  $path = drupal_get_path('theme', 'hy_doo');
  $options = array('group' => JS_THEME);

  drupal_add_js($path . '/js/matchMedia.js', $options);
  drupal_add_js($path . '/js/matchMedia.addListener.js', $options);

  // Load the mediaquery behavior from Omega. This allows registering media
  // queries via Drupal.settings to automatically print body classes based on
  // whether or not they currently apply.
  $omega = drupal_get_path('theme', 'omega');
  drupal_add_js($omega . '/js/omega.mediaqueries.min.js', $options);

  // Register the media queries. The array keys will be used to compose the body
  // class names and the values are the actual media queries.
  drupal_add_js(array(
    'omega' => array(
      'mediaQueries' => array(
        'layout-mobile' => 'screen and (max-width: 47.99em)',
        'layout-small' => 'screen and (min-width: 48em)',
        'layout-medium' => 'screen and (min-width: 62.5em)',
        'layout-large' => 'screen and (min-width: 75em)',
      )
    )
  ), 'setting');

  // Our own breakpoint behaviors
  //drupal_add_js($path . '/js/hy.videoembedmobile.js', $options);

  // drupal_add_js($path . '/js/jquery.dotdotdot.min.js', array('scope' => 'header', 'group' => JS_THEME));
  // drupal_add_js($path . '/js/dotdotdot.js', $options);

  // Check for favicons from registry and add them to head after a thorough checkup
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