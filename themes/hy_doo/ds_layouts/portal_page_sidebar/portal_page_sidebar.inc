<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

function ds_portal_page_sidebar() {
  return array(
    'label' => t('HY portal page sidebar template'),
    'regions' => array(
      'portal_page_content' => t('Content'),
      'portal_page_sidebar' => t('Sidebar'),
      'portal_page_promotion' => t('Promotion'),
    ),
    // Default image for preview
    'image' => TRUE,
  );
}
