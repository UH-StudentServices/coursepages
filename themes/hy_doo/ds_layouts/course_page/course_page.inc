<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

function ds_course_page() {
  return array(
    'label' => t('HY course page template'),
    'regions' => array(
      'course_metadata_header' => t('Metadata header'),
      'course_metadata' => t('Metadata content'),
      'course_metadata_footer' => t('Metadata footer'),
      'course_banner' => t('Course promotion'),
      'course_content' => t('Course content'),
      'course_sidebar' => t('Sidebar, additional information'),
    ),
    // Default image for preview
    'image' => TRUE,
  );
}