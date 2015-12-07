<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

function ds_simple_page() {
  return array(
    'label' => t('HY simple page template'),
    'regions' => array(
      'simple_page_metadata' => t('Top area, info section'),
      'simple_page_banner' => t('Page promotion'),
      'simple_page_content' => t('Page content'),
    ),
    // Default image for preview
    'image' => TRUE,
  );
}