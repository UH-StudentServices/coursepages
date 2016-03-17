/**
 * This file has been copied over from
 * https://github.com/UniversityofHelsinki/julkiset-sivut project and modified
 * target classes to be more generic.
 */
(function ($) {
  Drupal.behaviors.hy_doo_fatmenu = {
    attach: function (context, settings) {
          var mainmenu = $('.main-menu .menu'),
          fatmenu = $('.fatmenu'),
          hoverIntentSettings = {
            sensitivity: 1,        
            interval: 0,
            over: hoverIn,
            timeout: 100,
            out: hoverOut
          },
          masonrySettings = {
            itemSelector: '.level-2',
            columnWidth: $('.level-2').width(),
            transitionDuration: 0,
            gutter: 10
          };

      // Add hoverIntent to mainmenu list items
      mainmenu.children('li').hoverIntent(hoverIntentSettings);
      fatmenu.hoverIntent(hoverIntentSettings);

      //Run when hovering main-menu link
      function hoverIn() {

        if ($(this).hasClass('expanded')) {
          fatmenu.addClass('collapsed');

          // get corresponding menu item from fat menu and set it active
          var menuItemID = $(this).attr('class').match(/\bmenu-mlid-(\d+)\b/)[1];
          $('.level-1', fatmenu).removeClass('is-open');
          fatmenu.find('.menu-mlid-' + menuItemID).addClass('is-open');
          fatmenu.find('.level-1 > .menu').masonry(masonrySettings);
        }
      }

      //Run when hovering outside fatmenu
      function hoverOut(hover) {
        var fatmenuisHovered = $('.fatmenu:hover').length;
        var expandedisHovered = $('.main-menu li.expanded:hover').length;
        if (!fatmenuisHovered && !expandedisHovered) {
          fatmenu.removeClass('collapsed');
        }
      }
    }
  };
})(jQuery);
