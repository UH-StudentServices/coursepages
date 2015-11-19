<?php
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