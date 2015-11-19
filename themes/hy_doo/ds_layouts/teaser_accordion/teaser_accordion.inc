<?php
function ds_teaser_accordion() {
  return array(
    'label' => t('HY simple accordion teaser template'),
    'regions' => array(
      'teaser_accordion_title' => t('Accordion title'),
      'teaser_accordion_content' => t('Accordion content'),
    ),
    // Default image for preview
    'image' => TRUE,
  );
}
