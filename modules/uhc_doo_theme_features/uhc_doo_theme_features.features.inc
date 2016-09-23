<?php
/**
 * @file
 * uhc_doo_theme_features.features.inc
 */

/**
 * Implements hook_ctools_plugin_api().
 */
function uhc_doo_theme_features_ctools_plugin_api($module = NULL, $api = NULL) {
  if ($module == "context" && $api == "context") {
    return array("version" => "3");
  }
  if ($module == "strongarm" && $api == "strongarm") {
    return array("version" => "1");
  }
}

/**
 * Implements hook_image_default_styles().
 */
function uhc_doo_theme_features_image_default_styles() {
  $styles = array();

  // Exported image style: image_100pxauto.
  $styles['image_100pxauto'] = array(
    'label' => 'Image 100% x auto',
    'effects' => array(
      2 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 1180,
          'height' => '',
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image_250x250.
  $styles['image_250x250'] = array(
    'label' => 'Image 250 x 250',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 250,
          'height' => 250,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image_259_x_180.
  $styles['image_259_x_180'] = array(
    'label' => 'Liftup 259 x 180',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 259,
          'height' => 180,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: image_400x234.
  $styles['image_400x234'] = array(
    'label' => 'Image 400 x 234',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 234,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: large_with_manualcrop.
  $styles['large_with_manualcrop'] = array(
    'label' => 'Large with manualcrop',
    'effects' => array(
      4 => array(
        'name' => 'manualcrop_auto_reuse',
        'data' => array(
          'style_priority' => array(
            0 => 'liftup_322_x_190',
          ),
          'apply_all_effects' => 0,
          'fallback_style' => '',
        ),
        'weight' => 0,
      ),
      3 => array(
        'name' => 'image_scale',
        'data' => array(
          'width' => 480,
          'height' => 480,
          'upscale' => 0,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: liftup_322_x_190.
  $styles['liftup_322_x_190'] = array(
    'label' => 'Liftup 322 x 190',
    'effects' => array(
      9 => array(
        'name' => 'manualcrop_crop',
        'data' => array(
          'width' => 322,
          'height' => 190,
          'keepproportions' => 1,
          'reuse_crop_style' => '',
          'style_name' => 'liftup_322_x_190',
        ),
        'weight' => 0,
      ),
      8 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 322,
          'height' => 190,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: liftup_large_720_x_507.
  $styles['liftup_large_720_x_507'] = array(
    'label' => 'Liftup large 720 x 507',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 720,
          'height' => 507,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: liftup_large_743_x_438.
  $styles['liftup_large_743_x_438'] = array(
    'label' => 'Liftup large 743 x 438',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 743,
          'height' => 438,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_picture.
  $styles['profile_picture'] = array(
    'label' => 'Profile picture',
    'effects' => array(
      1 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 72,
          'height' => 72,
        ),
        'weight' => 1,
      ),
    ),
  );

  // Exported image style: profile_picture_small.
  $styles['profile_picture_small'] = array(
    'label' => 'Profile picture small',
    'effects' => array(
      3 => array(
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 96,
          'height' => 96,
        ),
        'weight' => 1,
      ),
    ),
  );

  return $styles;
}
