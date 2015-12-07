<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

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
