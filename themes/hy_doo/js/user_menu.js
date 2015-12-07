/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.hy_portal_user_menu = {
    attach: function (context) {
      $(function() {

        // close when clicking outside menu
    	  $(document).click(function(event) {
    	  	if (!$(event.target).closest('.nolink', '.block--system-user-menu').length && $('.nolink', '.block--system-user-menu').next('ul.menu').hasClass('collapsed')) {
    	    	$('.nolink', '.block--system-user-menu').next('ul.menu').removeClass('collapsed');
          }
        });

        $('.nolink', '.block--system-user-menu').click(function() {
          $(this).next('ul.menu').toggleClass('collapsed');
        });

      });
    }
  }
})(jQuery);
