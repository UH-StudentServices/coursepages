/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.hy_doo_mobile_menu = {
    attach: function (context) {

      var layoutSmall = Drupal.settings.omega.mediaQueries['layout-small'];
      var mobileMenus = '#course-hierarchy, #block-system-user-menu';

      // Media Queries Matching
      if (typeof matchMedia !== 'undefined') {
        var mq = window.matchMedia(layoutSmall);
        mq.addListener(checkMobile);
        checkMobile(mq);
      }

      // Move menus to mobilemenu when changing to mobile
      function checkMobile(mq) {
        $(mobileMenus).each(function () {
          var id = $(this).get(0).id;
          var placeholderId = id + '--placeholder';

          if (mq.matches === true) {
            $('#' + placeholderId).replaceWith($(this));
          }
          else {
            $(this).after('<span id="' + placeholderId + '"></span>');
            $('.main-menu > .menu').append($(this));
          }
        });

      }
    }
  };
})(jQuery);
