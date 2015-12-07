<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

function ds_link_list() {
  return array(
    'label' => t('HY simple link list template'),
    'regions' => array(
      'link_list_title' => t('List title'),
      'link_list_content' => t('List content'),
    ),
    // Default image for preview
    'image' => FALSE,
  );
}