<?php
function ds_event_material() {
  return array(
    'label' => t('HY material block'),
    'regions' => array(
      'event_material_content' => t('Material content'),
      'event_material_attachements' => t('Attachements'),
    ),
    // Default image for preview
    'image' => TRUE,
  );
}
