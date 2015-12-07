/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.hy_doo_messages = {
    attach: function (context) {

      // close button for messages
      $('.messages .close').once().click(function(event) {
        event.preventDefault();
        $(this).closest('.messages').addClass('closed');
      });

      // hide status messages automatically after 5 seconds
      setTimeout(function () {
        $('.l-page > .messages.status').addClass('closed');
      }, 8000);
    }
  }
})(jQuery);
