/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.hy_doo_mobile_menu = {
    attach: function (context) {

      var selectors = ['#block-menu-menu-header-links', '.main-menu', '.course-hierarchy', '#block-system-user-menu'];
      var mobileMenuElements = [];

      // get parents for selectors to store their original location
      $.each(selectors, function(key, value){
        mobileMenuElements.push({
          'selector': value,
          'parent': $(value).parent()
        });
      });

      // place mobile menu container
      var mobileMenuContainer = 'mobile-menu-container';
      $('.logo-block').before('<div class="' + mobileMenuContainer + '"></div>');

      // place mobile nav toggle
      var mobileMenuToggle = 'mobile-menu-toggle';
      $('.l-page').prepend('<div class="' + mobileMenuToggle + '"><span></span><span></span><span></span><span></span></div>');

      //Get current CSS breakpoint
      var breakpoint = {};
      breakpoint.refreshValue = function () {
        this.value = window.getComputedStyle(document.querySelector('body'), ':before').getPropertyValue('content').replace(/\"/g, '');
      };

      // check when breakpoint changes and move menus if needed
      $(window).resize(function () {
        var oldValue = breakpoint.value;
        breakpoint.refreshValue();

        // check for breakpoint change
        if (breakpoint.value == 'mobile' && oldValue !== 'mobile') {
          // move menus to mobile menu container
          $.each(mobileMenuElements, function(key, element) {
            $('.' + mobileMenuContainer).append($(element.selector));
          });
        }
        if (oldValue == 'mobile' && breakpoint.value !== 'mobile') {
          // move menus back to their desktop locations
          $.each(mobileMenuElements, function(key, element) {
            $(element.parent).append($(element.selector));
          });

          $('.overlay').remove();
        }
      }).resize();

      // Mobile menu toggle
      $('.' + mobileMenuToggle).click(function(){
        $(this).toggleClass('collapsed');
        $('.' + mobileMenuContainer).toggleClass('collapsed');

        // add overlay
        if($('.overlay').length == 0) {
          $('body').prepend('<div class="overlay"></div>');
          $('.overlay').height($(document).height());
          $('.overlay').fadeTo('fast', 0.5);
        } else {
          $('.overlay').fadeTo('fast', 0, function() {
            $('.overlay').remove();
          });
        }

      });

      // expand mobile menu items when clicking triangle
      $('.expanded .triangle', '.main-menu').once('mobile_menu', function () {
        $(this).click(function () {
          console.log($(this).parent('li'));
          $(this).parent('li').toggleClass('m-active');
          
          var active = $(this).siblings('ul:hidden').length;
          console.log(active);
        });
      });

    }
  }
})(jQuery);
