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
    'name' => 'image_100pxauto',
    'label' => 'Image 100% x auto',
    'effects' => array(
      2 => array(
        'label' => 'Scale',
        'help' => 'Scaling will maintain the aspect-ratio of the original image. If only a single dimension is specified, the other dimension will be calculated.',
        'effect callback' => 'image_scale_effect',
        'dimensions callback' => 'image_scale_dimensions',
        'form callback' => 'image_scale_form',
        'summary theme' => 'image_scale_summary',
        'module' => 'image',
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
    'name' => 'image_250x250',
    'label' => 'Image 250 x 250',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'image_259_x_180',
    'label' => 'Liftup 259 x 180',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'image_400x234',
    'label' => 'Image 400 x 234',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
        'name' => 'image_scale_and_crop',
        'data' => array(
          'width' => 400,
          'height' => 234,
        ),
        'weight' => 2,
      ),
    ),
  );

  // Exported image style: liftup_322_x_190.
  $styles['liftup_322_x_190'] = array(
    'name' => 'liftup_322_x_190',
    'label' => 'Liftup 322 x 190',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'liftup_large_720_x_507',
    'label' => 'Liftup large 720 x 507',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'liftup_large_743_x_438',
    'label' => 'Liftup large 743 x 438',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'profile_picture',
    'label' => 'Profile picture',
    'effects' => array(
      1 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
    'name' => 'profile_picture_small',
    'label' => 'Profile picture small',
    'effects' => array(
      3 => array(
        'label' => 'Scale and crop',
        'help' => 'Scale and crop will maintain the aspect-ratio of the original image, then crop the larger dimension. This is most useful for creating perfectly square thumbnails without stretching the image.',
        'effect callback' => 'image_scale_and_crop_effect',
        'dimensions callback' => 'image_resize_dimensions',
        'form callback' => 'image_resize_form',
        'summary theme' => 'image_resize_summary',
        'module' => 'image',
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
