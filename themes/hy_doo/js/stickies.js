/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.hy_doo_stickies = {
    attach: function (context) {
      var stickyElements = $('.messages__sticky, .tabs-wrapper');
      var adminMenuHeight = $('body').hasClass('admin-menu') ? 21 : 0;

      $.stickyElement = function(element, index) {
        var sticky = this;

        var init = function() {
          sticky.index = index;
          sticky.el = element;
          sticky.height = element[0].getBoundingClientRect().height - 1;
          sticky.offsetTop = element.offset().top;
          sticky.offsetFixed = 0;
          sticky.calcOffsetFixed();
          // placeholder is needed to preserve height when sticky position is changed to fixed
          element.before('<div class="sticky-placeholder"></div>');
        }

        sticky.calcOffsetFixed = function() {
          // Calculate the height of all stickies that should be on top of this one.
          for (var index in stickies) {
            if (index < sticky.index) {
              sticky.offsetFixed = sticky.offsetFixed + stickies[index].height; 
            }
          }
          sticky.offsetFixed = sticky.offsetFixed + adminMenuHeight;
        }

        sticky.checkSticky = function() {
          if (sticky.offsetTop < $(window).scrollTop() + sticky.offsetFixed) {
            element.css({
              'position': 'fixed',
              'top': sticky.offsetFixed,
            });
            element.prev('.sticky-placeholder').css({
              'height': sticky.height,
            });
          } else {
            element.css({
              'position': 'relative',
              'top': 0,
            });
            element.prev('.sticky-placeholder').css({
              'height': 0,
            });
          }
        }
        init();
      }

      var stickies = [];
      stickyElements.once().each(function(index, value){
        stickies[index] = new $.stickyElement($(value), index);
      });

      for (var index in stickies) {
        stickies[index].checkSticky();
      }
      $(window).scroll(function() {
        for (var index in stickies) {
          stickies[index].checkSticky();
        }
      });

    }
  }
})(jQuery);

