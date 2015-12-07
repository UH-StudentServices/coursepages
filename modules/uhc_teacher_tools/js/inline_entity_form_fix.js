/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.uhc_teacher_tools_fix_inline_entity_form = {
    attach: function (context) {
      // when having one ief entity form open, disable edit/remove buttons from
      // other entities in the same ief widget
      $('.field-widget-inline-entity-form').each(function() {
        if ($('.ief-form', this).length) {
          $('input', this).not('.ief-form input').attr('disabled', 'true');
        } else {
          $('input', this).attr('disabled', '');
        }
      });
    }
  }

})(jQuery);
