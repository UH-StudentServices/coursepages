/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.hy_portal_user_menu = {
    attach: function (context) {
      $(function() {
        var infoLink = '.info-link',
            userMenu = '.block--system-user-menu';

        // close when clicking outside menu
    	  $(document).click(function(event) {
          if (!$(event.target).closest(infoLink, userMenu).length && $(infoLink, userMenu).next('ul.menu').hasClass('collapsed')) {
            $(infoLink, userMenu).next('ul.menu').removeClass('collapsed');
          }
        });

      $(infoLink, userMenu).click(function(e) {
          e.preventDefault();
          $(this).next('ul.menu').toggleClass('collapsed');
        });
      });
    }
  }
})(jQuery);
