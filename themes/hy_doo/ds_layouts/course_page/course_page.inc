<?php
function ds_course_page() {
  return array(
    'label' => t('HY course page template'),
    'regions' => array(
      'course_metadata' => t('Top area, info section'),
      'course_banner' => t('Course promotion'),
      'course_content' => t('Course content'),
      'course_sidebar' => t('Sidebar, additional information'),
    ),
    // Default image for preview
    'image' => TRUE,
  );
}