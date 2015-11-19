<?php
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