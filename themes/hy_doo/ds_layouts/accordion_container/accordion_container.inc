<?php
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
