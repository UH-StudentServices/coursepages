/**
 * @file
 * In some cases we get unnecessary messages, so we remove them here.
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_help_widgets = {
    attach: function (context, settings) {
      $('.node-form .description').once('uhc_help_widgets', function () {

        // try to find corresponding label and move description after it
        if ($(this).siblings('label').length) {
          $(this).siblings('label').append(this);
        } else if ($(this).siblings('.form-item').children('label').length) {
          $(this).siblings('.form-item').children('label').append(this);
        } else {
          $(this).siblings('table.field-multiple-table').find('th.field-label label').append(this);
        }

        // add toggle as wrapper
        $(this).wrap('<div class="description-toggle"></div>');

        // toggle collapsed description, close others
        $(this).parent('.description-toggle').click(function (event) {
          event.preventDefault();
          $('.description').removeClass('collapsed');
          $(this).children('.description').toggleClass('collapsed');
        });

      });

      // close description when clicking outside
      $(document).click(function(event) {
        if (!$(event.target).closest('.description-toggle').length) {
          $('.description').removeClass('collapsed');
        }
      });

    }
  }
})(jQuery);