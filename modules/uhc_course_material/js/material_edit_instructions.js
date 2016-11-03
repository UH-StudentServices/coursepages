/**
 * @file
 * Add message with material edit instructions
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_course_material_edit_instructions = {
    attach: function (context, settings) {
      var materialEditMessage = Drupal.settings.uhc_course_material.material_edit_instructions;
      Drupal.ajax.prototype.commands.materialEditInstructions = function(ajax, response, status) {
        $('table#ief-entity-table-edit-field-section-material-und-entities').before(materialEditMessage);
      }
    }
  }
})(jQuery);
