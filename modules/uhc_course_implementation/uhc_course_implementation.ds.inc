<?php
/**
 * @file
 * uhc_course_implementation.ds.inc
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_ds_custom_fields_info().
 */
function uhc_course_implementation_ds_custom_fields_info() {
  $export = array();

  $ds_field = new stdClass();
  $ds_field->api_version = 1;
  $ds_field->field = 'course_implementation_material';
  $ds_field->label = 'Course implementation material';
  $ds_field->field_type = 6;
  $ds_field->entities = array(
    'node' => 'node',
  );
  $ds_field->ui_limit = '';
  $ds_field->properties = array(
    'block' => 'views|08d941d2cde351c90a36aeb274b9adac',
    'block_render' => '3',
  );
  $export['course_implementation_material'] = $ds_field;

  return $export;
}
