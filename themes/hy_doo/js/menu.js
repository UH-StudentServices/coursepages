/**
 * This file has been copied over from
 * https://github.com/UniversityofHelsinki/julkiset-sivut project and modified
 * target classes to be more generic.
 */
(function ($) {
  "use strict";

  Drupal.behaviors.hyFatmenu = {
    attach: function (context, settings) {
      var fatmenuWidth        = Drupal.settings.omega.mediaQueries['layout-small'],
          menubar             = $('.l-menu-bar'),
          responsiveNav       = $('.responsive-navigation'),
          navToggle           = $('#nav-toggle'),
          fatmenu             = $('.fatmenu'),
          mainmenu            = $('.main-menu'),
          masonryWidth        = $('.level-2').width(),
          hoverIntentSettings = {
            sensitivity: 1,         // number = sensitivity threshold (must be 1 or higher)
            interval: 80,           // number = milliseconds of polling interval
            over: hoverIntentOver,  // function = onMouseOver callback (required)
            timeout: 0,             // number = milliseconds delay before onMouseOut function call
            out: hoverIntentOut     // function = onMouseOut callback (required)
          };

      // Media Queries Matching
      if (typeof matchMedia !== 'undefined') {
        var mq = window.matchMedia(fatmenuWidth);
        mq.addListener(widthChangeFatMenu);
        widthChangeFatMenu(mq);
      }

      /**
       * Function widthChangeFatMenu()
       *
       * Detect width change according to mediaqueries set in html.preprocess.inc
       */
      function widthChangeFatMenu(mq) {
        // Check if mobile device is used
        if ($.browser.mobile === true) {
          if (mq.media == fatmenuWidth && mq.matches === true) {
            // Hide burger, responsive navigation and responsive navigation fontawesome arrow
            navToggle.hide();
            responsiveNav.find('.level-2').hide();
            responsiveNav.find('.menuparent .triangle').addClass('hidden');

            // Set menu height 0px to fix mobile->desktop behavior
            // and hide second level ul from prying eyes
            fatmenu.find('.menu-block-wrapper').css('height', '0px');
            responsiveNav.find('.level-1 ul').hide();

            // Make the exit button and bind it.
            exitButton();

            // Prevent user from following href
            preventDefaultBehavior('.l-menu-bar .main-menu li a');

            // Masonrize fatmenu items
            fatmenu.find('.level-1 > .menu').masonry({
              itemSelector: '.level-2',
              columnWidth: masonryWidth,
              isResizable: true,
              gutter: 10
            });

            fatmenu.find('.level-1:last > .menu').masonry();
          } else if (mq.matches === true) {
            // Media Query matches to handheld tablet client.

            // Hide fatmenu, responsive menu toggle button
            // and second level of the main menu from prying eyes
            navToggle.hide();
            responsiveNav.find('.level-2').hide();
            fatmenu.hide();
          } else {
            // Media Query matches to mobile client.

            // Hide level-2 ul
            $('li.level-1').find('ul').hide();
            navToggle.show();
          }

        } else if ($.browser.desktop === true) {
          if (mq.matches === true) {
            // Media Query matches to desktop client.

            // Set menu height 0px to fix mobile->desktop behavior
            // and hide second level ul from prying eyes
            fatmenu.find('.menu-block-wrapper').css('height', '0px');
            responsiveNav.find('.level-1 ul').hide();

            // Make the exit button and bind it.
            exitButton();

            // Add hoverIntent to mainmenu list items
            responsiveNav.children('li').hoverIntent(hoverIntentSettings);

            // Masonrize fatmenu items
            fatmenu.find('.level-1 > .menu').masonry({
              itemSelector: '.level-2',
              columnWidth: masonryWidth,
              isResizable: true,
              gutter: 10
            });

            fatmenu.find('.level-1:last > .menu').masonry();
          }
        }
      }

      /**
       * Function exitButton()
       *
       * Create "Close" button and bind it to close fatmenu
       */
      function exitButton() {
        if (!fatmenu.children('div p').hasClass('exit')) {
          fatmenu.children('div').not('.contextual-links-wrapper').append('<p class="exit">' + Drupal.t('Close') + '</p>');
          fatmenu.find('.exit').click(function () {
            $(this).toggle();
            closeMobileFatMenu();
          });
        }
      }

      /**
       * Function hoverIntentOver()
       *
       * Run when hovering main-menu link
       */
      function hoverIntentOver(clickedItem, choice) {
        // If 'choice' is undefined,
        // we're obviously using this function as a hoverintent
        if (choice === undefined) {
          clickedItem = $(this);
        }

        var currItemParents = '.l-menu-bar .fatmenu .menu .',
            currElement     = $(clickedItem).attr('class').split(' ')[0].split('-')[1],
            currItem        = 'menu-mlid-' + currElement,
            fatmenu         = $('.fatmenu');

        // Get current item from fatmenu and add class is-open
        // and make sure the child menu is not hidden
        $(currItemParents + currItem).addClass('is-open');
        $(currItemParents + currItem).children('.menu').css('display', 'block');
        fatmenu.find('.level-1 > .menu').masonry();

        // Remove is-open from the rest of "li" tags
        fatmenu.find('.menu li').not('.' + currItem).removeClass('is-open');

        var $this = $(clickedItem);

        // Check if navigation item has children. If none are found, animate the fatmenu to 0px.
        var currHeight = (fatmenu.find('.fatmenu .menu .is-open').height() == 0) ? 0 : fatmenu.find('.menu .is-open').height() + 30;
        // If 'choice' is undefined, check for menu item children and animate to 0px.
        // Otherwise show title in fatmenu

        
        if (choice === undefined) {
          currHeight = ($this.find('.level-2').length != 0) ? currHeight : 0;
        } else {
          $('.layout-mobile-active .l-menu-bar .fatmenu').show();
        }
        
        
        animateFatMenu(currHeight, currElement);
      }

      /**
       * Function hoverIntentOut()
       *
       * Do nothing when hovering out. ( http://api.jquery.com/jQuery.noop )
       * jquery.hoverIntent requires noop when used like the way it is used.
       * ( http://cherne.net/brian/resources/jquery.hoverIntent.html )
       */
      function hoverIntentOut() {
        $.noop();
      }

      /**
       * Function animateFatMenu()
       *
       * Animation for fatmenu when hovering main-menu link
       */
      function animateFatMenu(fatmenuHeight, currentItem) {
        // Unbind closing button and remove it from dom
        mainmenu.find('li').removeClass('is-open');

        if (fatmenuHeight === 0 && currentItem === undefined) {
          fatmenu.find('.exit').hide();
          fatmenu.find('.menu li').removeClass('is-open');
          fatmenu.removeClass('is-open');
        }

        currentItem = '.menu-' + currentItem;

        fatmenu.children('div').animate({
          height: fatmenuHeight,
          opacity: 1
        }, {
          duration: 200,
          queue: false
        });

        // If fatmenu is open, do the magic for fatmenu.
        if (fatmenuHeight != 0) {
          menubar.mouseleave(function () { animateFatMenu(0); });
          fatmenu.find('.exit').show();
          fatmenu.addClass('is-open');
          $(currentItem, context).addClass('is-open');
          mainmenu.find('.close-fatmenu').bind("click tap", function () {
            animateFatMenu(0);
          });
        }
      }

      /**
       * Function mobileFatmenuItemClicked()
       *
       * Run when menu item has been clicked in mobile device
       */
      function mobileFatmenuItemClicked(clickedItem) {
        var currItemParents = '.fatmenu .menu .',
            currElement = $(clickedItem).attr('class').split(' ')[0].split('-')[1],
            currItem = 'menu-mlid-' + currElement,
            fatmenuCloseButton = mainmenu.find('.close-fatmenu');

        preventDefaultBehavior('.l-menu-bar .main-menu li a');

        mainmenu.find('.menu-' + currElement + ' a').unbind('click');
        fatmenuCloseButton.remove();

        // Get current item from fatmenu and add class is-open
        // and make sure the child menu is not hidden
        $(currItemParents + currItem).addClass('is-open');
        $(currItemParents + currItem).children('.menu').css('display', 'block');
        fatmenu.find('.level-1 > .menu').masonry();

        mainmenu.find('.menu-' + currElement, context).append('<span class="close-fatmenu"></span>');
        fatmenuCloseButton.click(function () {
          closeMobileFatMenu();
        });

        // Remove is-open from the rest of "li" tags
        fatmenu.find('.menu li').not('.' + currItem).removeClass('is-open');

        var $this = $(clickedItem);

        // Check if navigation item has children. If none are found, animate the fatmenu to 0px.
        var currHeight = fatmenu.find('.menu .is-open').height();
        if (currHeight > 45) {
          openMobileFatMenu(currHeight + 30, currElement);
        } else {
          closeMobileFatMenu();
        }
      }

      /**
       * Function openMobileFatMenu()
       *
       * Animation for fatmenu when hovering main-menu link
       */
      function openMobileFatMenu(fatmenuHeight, currentItem) {
        fatmenu.children('div').animate({
          height: fatmenuHeight,
          opacity: 1
        }, {
          duration: 200,
          queue: false
        });

        fatmenu.find('.exit').show();
        fatmenu.addClass('is-open');
      }

      /**
       * Function closeMobileFatMenu()
       *
       * Animation for fatmenu when closing it
       */
      function closeMobileFatMenu() {
        preventDefaultBehavior('.l-menu-bar .main-menu li a');
        mainmenu.find('.close-fatmenu').remove();
        fatmenu.find('.exit').hide();
        fatmenu.find('.menu li').removeClass('is-open');
        fatmenu.removeClass('is-open');
        fatmenu.children('div').animate({
          height: 0,
          opacity: 1
        }, {
          duration: 200,
          queue: false
        });
      }

      /**
       * Function preventDefaultBehavior()
       *
       * Helper function to prevent user from followeing href
       * @param element
       */
      function preventDefaultBehavior(element) {
        // Prevent user from following href and call mobileFatmenuItemClicked
        $(element).unbind('click');
        $(element).click(function (e) {
          var currElement = $(this).parent().attr('class').split(' ')[0].split('-')[1],
              currItem = $('.fatmenu .menu-mlid-' + currElement + ' ul.menu').length;
          if (currItem > 1) {
            e.preventDefault();
            mobileFatmenuItemClicked($(this).parent());
          }
        });
      }
    }
  };

  Drupal.behaviors.hyMobilemenu = {
    attach: function (context, settings) {
      // var mobile_width = Drupal.settings.omega.mediaQueries['layout-mobile'];
      var mobile_width        = "screen and (max-width: 767px)",
          responsiveNav       = $('.responsive-navigation'),
          navToggle           = $('#nav-toggle'),
          fatmenu             = $('.fatmenu');

      // Media Queries Matching
      if (typeof matchMedia != 'undefined') {
        var mobileMediaQuery = window.matchMedia(mobile_width);
        mobileMediaQuery.addListener(widthChangeMobileMenu);
        widthChangeMobileMenu(mobileMediaQuery);
      }

      /**
       * Function widthChangeMobileMenu()
       *
       * Detect width change according to mediaqueries set in html.preprocess.inc
       */
      function widthChangeMobileMenu(mobileMediaQuery) {
        if (mobileMediaQuery.matches === true) {
          // Make home icon clickable.
          var homelink = responsiveNav.find('.menu-path-front a').attr('href');
          responsiveNav.find('.menu-path-front .triangle').click(function(){
            window.location = homelink;
          });

          // Remove hidden class from responsive-navigation items
          responsiveNav.find('.menuparent .triangle').removeClass('hidden');

          // If navigation button is clicked, change class for it
          navToggle.click(function () {
            $(this).toggleClass('active');
          });

          // Check if list element has active-trail class and add m-active to anchor tags
          if (responsiveNav.find('li').hasClass('active-trail')) {
            $('li.active-trail').addClass('m-active');

            // If mobile menu is viewed on desktop browser, show active-trail again.
            responsiveNav.find('li.active-trail > ul').css('display', 'block');
          }

          // Remove .border anchor background if there are no sublinks
          $.each(responsiveNav.find('.triangle'), function () {
            if (($(this).siblings('ul').size() == 0) && (!$(this).parent('li').is('.level-3, .first.menu-path-front'))) {
              $(this).children('a').css('background', 'none');
            }
          });

          // If .triangle is clicked, remove/add m-active/m-inactive classes
          responsiveNav.find('.triangle', context).once('helsingin_yliopisto_mobileMenu', function () {
            $(this).click(function () {

              // When active-trail class is among us, check for anchor classes and give anchor
              // class m-active/m-inactive and vice versa.
              var parentLi = $(this).parent('li');

              if (!parentLi.hasClass('menu-path-front')) {
                if (parentLi.hasClass('active-trail')) {
                  if (parentLi.hasClass('m-inactive')) {
                    parentLi.removeClass('m-inactive').addClass('m-active');
                  }
                  else {
                    parentLi.removeClass('m-active').addClass('m-inactive');
                  }
                }
                else {
                  if (parentLi.hasClass('m-active')) {
                    parentLi.removeClass('m-active').addClass('m-inactive');
                  }
                  else {
                    parentLi.removeClass('m-inactive').addClass('m-active');
                  }
                }
              }
              $(this).siblings('ul').slideToggle({duration: 100});
            });
          });
          $('li.active-trail a.active').siblings('.triangle').toggleClass('active-triangle');
        }
      }
    }
  };

  Drupal.behaviors.hyRemoveAttrStyle = {
    attach: function (context, settings) {
      var id = $('.block--responsive-navigation');
      var attr = id.attr('style');
      (attr !== undefined) ? id.once('remove-attr-style').removeAttr('style') : '';

      var fatmenuBlock = $('nav.fatmenu .menu-block-wrapper');
      (fatmenuBlock.attr('style') !== undefined) ? fatmenuBlock.once('remove-fatmenu-style').removeAttr('style') : '';
    }
  };

  // Some how ie 11 is not adding ie class to body.
  Drupal.behaviors.addIeClass = {
    attach: function (context, settings) {
      if ($.browser.msie) {
        $('body').addClass('ie');
      }
    }
  }
})(jQuery);
