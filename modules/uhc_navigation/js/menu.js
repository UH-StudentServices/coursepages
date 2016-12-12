(function ($) {
  "use strict";

  Drupal.behaviors.hyFatmenu = {
    attach: function (context, settings) {
      var fatmenuWidth = settings.omega.mediaQueries['layout-small'];
      var mainUl = $('.main-menu > ul');
      var navToggle = $('#menu-toggle');
      var fatmenu = $('.fatmenu');
      var mainmenu = $('.main-menu');
      var mainmenuExpand = mainmenu.find('.main-menu__expand');
      var level_1 = '.is-lvl1';
      var level_2 = '.is-lvl2';
      var level_3 = '.is-lvl3';
      var toggle = 0;
      var currentClickedItem = false;

      // Call sticky navigation function.
      //stickyNavigation();

      // Media Queries Matching
      if (typeof matchMedia !== 'undefined') {
        var mq = window.matchMedia(fatmenuWidth);
        mq.addListener(widthChangeFatMenu);
        widthChangeFatMenu(mq);
      }

      // Hide menu when clicking outside of it.
      $(document).on('click', function (e) {
        if (
          !$(e.target).closest('.main-menu').length &&
          !$(e.target).closest('.fatmenu').length &&
          mq.matches === true
        ) {
          closeFatMenu();
          toggle = 0;
        }
      });

      // Masonrize fatmenu items.
      fatmenu.find(level_1 + ' > .menu').masonry({
        itemSelector: level_2,
        columnWidth: level_2,
        resize: true,
        percentPosition: true,
        gutter: 10,
        transitionDuration: 0
      });

      /**
       * Function widthChangeFatMenu()
       * Detect browser width change according to mediaqueries set in html.preprocess.inc
       * @param {number} mq Media query for desktop.
       */
      function widthChangeFatMenu(mq) {
        if (mq.matches === true) {
          // In case of a visit to mobile menu; reset menu.
          mainmenu.removeClass('is-open').find('li').removeClass('is-open');
          mainmenu.find(level_1 + ' ul.menu').css('display', 'none');
          mainUl.removeClass('is-closed').addClass('is-open');
          fatmenu.removeClass('is-open').find(level_2 + '.is-expandable ul.menu').show();
          fatmenu.find(level_3 + ' ul').hide();

          // We're using mobile device and the resolution of device supports fatmenu.
          // Hide burger and make sure unnecessary bind is unset.
          navToggle.hide();

          // Check if level 1 menu items have children,
          // if not - remove expand-span.
          mainmenu.find(level_1).each(function () {
            if (!$(this).hasClass('expanded')) {
              $(this).children('.main-menu__expand').hide();
            }
          });

          // Make the exit button and bind it.
          exitButton();

          // Call for the mainmenu/fatmenu expansion.
          menuExpansion(false);
        }
        else {
          // Media Query matches to mobile client.
          // Reset menu classes.
          closeFatMenu();
          $(level_1 + ' ul').hide();
          mainUl.addClass('is-closed').removeClass('is-open');

          // If navigation button is clicked, change class for it
          navToggle.show().unbind().click(function (e) {
            e.preventDefault();
            $(this).toggleClass('active');
            mainUl.toggleClass('is-closed').toggleClass('is-open');
          });

          // Hide span.main-menu__expand if there's too many levels.
          $(level_3 + ' .main-menu__expand').hide();

          // Check if list element has active-trail class and add is-open to anchor tags
          if (mainmenu.find('li').hasClass('active-trail')) {
            mainmenu
              .find('li.active-trail')
              .addClass('is-open')
              .find('> ul')
              .css('display', 'block');
          }

          // Call for the mainmenu/fatmenu expansion
          menuExpansion(true);
        }
      }

      /**
       * Function menuExpansion()
       * Handle mainmenu/fatmenu expansion
       */
      function menuExpansion(mobile) {
        mainmenuExpand.unbind().click(function () {
          if (mobile === true) {
            // When active-trail class is among us, check for anchor classes and give anchor
            // class is-open and vice versa.
            var parentLi = $(this).parent('li');

            if (!parentLi.hasClass('menu-path-front')) {
              if (parentLi.hasClass('is-open')) {
                parentLi.removeClass('is-open');
              }
              else {
                parentLi.addClass('is-open');
              }
            }
            $(this).siblings('ul').slideToggle({duration: 100});
          } else {
            var currElement = $(this).parent().attr('data-mlid');
            var currItem = $('.fatmenu [data-mlid="' + currElement + '"] ul.menu li').length;
            if (currItem > 0) {
              if (toggle === 1 && currentClickedItem === currElement && currentClickedItem !== false) {
                closeFatMenu();
                toggle = 0;
              }
              else {
                currentClickedItem = currElement;
                fatmenuItemClicked($(this).parent());
                toggle = 1;
              }
            }
          }
        });
      }

      /**
       * Function stickyNavigation()
       * Create sticky navigation functionality.
       */
      function stickyNavigation() {
        var body = $('body');
        var stickyMenu = $('.l-region--menu-bar').eq(0);

        if (stickyMenu.length) {
          stickyMenu.once('stickynav', function () {
            $(window).scroll(function () {
              if ($(window).scrollTop() > 78) {
                stickyMenu.addClass('stickynav-active');
              }
              else {
                stickyMenu.removeClass('stickynav-active');
              }
            });

            if ($(window).scrollTop() > 78) {
              stickyMenu.addClass('stickynav-active');
            }
            else {
              stickyMenu.removeClass('stickynav-active');
            }
          });
        }
      }

      /**
       * Function exitButton()
       * Create "Close" button and bind it to close fatmenu
       */
      function exitButton() {
        if (!fatmenu.find('.fatmenu__collapse').attr('data-fatmenu-collapse')) {
          fatmenu
            .find('> ul.menu')
            .append('<span data-fatmenu-collapse="true" class="fatmenu__collapse"></p>')
            .click(function () {
              closeFatMenu();
              toggle = 0;
            });
        }
      }

      /**
       * Function fatmenuItemClicked()
       * Run when menu item has been clicked.
       * @param {object} clickedItem Clicked item.
       */
      function fatmenuItemClicked(clickedItem) {
        var currElement = $('.fatmenu [data-mlid="' + $(clickedItem).attr('data-mlid') + '"]');
        var currMainMenuLi = $('.main-menu [data-mlid="' + $(clickedItem).attr('data-mlid') + '"]');

        // Get current item from fatmenu and add class is-open
        // and make sure the child menu is not hidden
        currElement.addClass('is-open').children('.menu').show();

        // Add wrapper to the first link.
        fatmenu.find(level_1 + ' > a').wrap('<h3 class="fatmenu__title"></h3>');

        // Remove is-open from the rest of "li" tags
        fatmenu.find('.menu li').not(currElement).removeClass('is-open');

        // Trigger masonry
        currElement.find('> .menu').masonry();

        // Check if navigation item has children. If none are found, animate the fatmenu to 0px.
        var currHeight = fatmenu.find('> .menu .is-open').height();
        if (currHeight > 15) {
          openFatMenu(currHeight + 30, currElement, currMainMenuLi);
        }
        else {
          closeFatMenu();
        }
      }

      /**
       * Function openFatMenu()
       * Animation for fatmenu when hovering main-menu link
       * @param {number} fatmenuHeight Height of the fatmenu.
       * @param {string} currentItem Current item.
       * @param {string} currMainMenuLi Current list tag.
       */
      function openFatMenu(fatmenuHeight, currentItem, currMainMenuLi) {
        fatmenu.find('> ul.menu').addClass('is-open').css('height',fatmenuHeight);
        $(window).on('resize', function(){
          fatmenu.find('> ul.menu').css('height', $('.fatmenu li.is-lvl1.is-open').height());
        });

        mainmenu.addClass('is-open').find('.menu li').removeClass('is-open');
        fatmenu.find('.fatmenu__collapse').show();
        mainmenu.addClass('is-open');
        fatmenu.addClass('is-open');
        currMainMenuLi.addClass('is-open');
      }

      /**
       * Function closeFatMenu()
       * Animation for fatmenu when closing it
       */
      function closeFatMenu() {
        fatmenu.find('.fatmenu__collapse').hide();
        fatmenu.find('.menu li').removeClass('is-open');
        mainmenu.find('.menu li').removeClass('is-open');
        mainmenu.removeClass('is-open');
        fatmenu.removeClass('is-open');
        fatmenu.find('> ul.menu').removeAttr('style');
      }
    }
  };

  Drupal.behaviors.hyRemoveAttrStyle = {
    attach: function () {
      var id = $('.main-menu');
      var attr = id.attr('style');
      var fatmenuBlock = $('nav.fatmenu > ul.menu');
      if (typeof attr !== "undefined") {
        id.once('remove-attr-style').removeAttr('style');
      }
      if (typeof fatmenuBlock.attr('style') !== "undefined") {
        fatmenuBlock.once('remove-fatmenu-style').removeAttr('style');
      }
    }
  };

  // Some how IE11 is not adding ie class to body.
  /*
  Drupal.behaviors.addIeClass = {
    attach: function () {
      if ($.browser.msie) {
        $('body').addClass('ie');
      }
    }
  }; */
})(jQuery);