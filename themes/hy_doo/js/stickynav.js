/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.hy_doo_stickynav = {
    attach: function (context) {
      var StickyNavs = '.tabs-wrapper';

      $(StickyNavs).once('stickynav', function () {

        var nav = $(this),
            offset = $(this).offset().top,
            adminMenuHeight = $('body').hasClass('admin-menu') ? 20 : 0;

        // placeholder is needed to preserve height when nav position is changed to fixed
        nav.before('<div class="nav-placeholder"></div>');

        function checkSticky() {
          if (offset < $(window).scrollTop() + adminMenuHeight) {
            nav.css({
              'position': 'fixed',
              'top': adminMenuHeight,
            });
            nav.prev('.nav-placeholder').css({
              'height': nav.height(),
            });
          } else {
            nav.css({
              'position': 'relative',
              'top': 0,
            });
            nav.prev('.nav-placeholder').css({
              'height': 0,
            });
          }       
        }

        checkSticky();
        $(window).scroll(function() {
          checkSticky();
        });

      });
    }
  }
})(jQuery);

