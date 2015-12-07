<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

function ds_accordion_container() {
  return array(
    'label' => t('HY parent level accordion template'),
    'regions' => array(
      'accordion_title' => t('Accordion title'),
      'accordion_content' => t('Accordion content'),
    ),
    // Default image for preview
    'image' => TRUE,
  );
}
