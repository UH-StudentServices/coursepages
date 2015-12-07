/**
 * @file
 * In some cases we get unnecessary messages, so we remove them here.
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_hide_logged_in_message = {
    attach: function (context, settings) {
      var message = Drupal.settings.uhc_course_implementation.private_content_message;
      $('.messages p:contains(' + message + ')').parent('.messages').remove();
    },
    weight: 100
  }
})(jQuery);
