/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.courseSearchDropdowns = {
    attach: function (context, settings) {

      if (!isMobile()) {
        $('.block.block--facetapi').addClass('block--facetapi__desktop');

        $('.block.block--facetapi li.expanded').hoverIntent({
          sensitivity: 1,
          interval: 0,
          over: hoverInMenuItem,
          timeout: 100,
          out: hoverOutMenuItem
        });

        $('.block__content, .item-list', '.block.block--facetapi').hoverIntent({
          sensitivity: 1,
          interval: 0,
          over: hoverInMenuLevel,
          timeout: 100,
          out: hoverOutMenuLevel
        });
      } else {
        $('.block.block--facetapi li.expanded').removeClass('expanded');
      }

      //Run when hovering Menu item
      function hoverInMenuItem() {
        $(this).children('.item-list').addClass('collapsed').moveToViewport();
        $(this).addClass('collapsed');
        $(this).closest('.item-list, .block__content').addClass('active');
      }

      //Run when hovering Menu level
      function hoverInMenuLevel() {
        $(this).addClass('active');
        $(this).parents('.item-list.active, .block__content.active').removeClass('active');
      }

      //Run when hovering outside Menu item
      function hoverOutMenuItem() {
        $(this).children('.item-list').removeClass('collapsed');
        $(this).children('.item-list').css({'bottom': 'auto', 'right': 'auto', 'top': 'auto'});
        $(this).removeClass('collapsed');
      }

      //Run when hovering outside Menu level
      function hoverOutMenuLevel(hover) {
        $(hover.toElement).closest('.item-list, .block__content').addClass('active');
        $(this).removeClass('active');
      }

      $.fn.moveToViewport = function() {

        // by default align the child menu vertically with its parent menu item
        var parentTop = this.parent('li.expanded').position().top + 'px';
        $(this).css('top', parentTop);

        var viewport = {};
        viewport.right = $(window).scrollLeft() + $(window).width();
        viewport.bottom = $(window).scrollTop() + $(window).height();

        var bounds = this.offset();
        bounds.right = bounds.left + this.outerWidth();
        bounds.bottom = bounds.top + this.outerHeight();

        // Move child menu back to viewport if out of bounds
        if (viewport.right < bounds.right) {
          $(this).css('right', function(){
            return (bounds.right) - viewport.right + 'px'
          });
          $(this).css('z-index', '1');
        }
        if (viewport.bottom < bounds.bottom + 60) {
          $(this).css({'top': 'initial', 'bottom': '0'});
        }
      };

      // Make sure this happens only once
      $('.views-exposed-widgets').once('uhc-filters', function () {
        // Submit form when sort select is changed, only visible in mobile
        $('#edit-sort-by').change(function () {
          $(this).closest('form').trigger('submit');
          /* or:
           $('#formElementId').trigger('submit');
           or:
           $('#formElementId').submit();
           */
        });
      });

      // Faux multiselect dropdown for checkboxes
      $('.block__content', '.block--facetapi').after('<ul class="chosen-choices"></ul>');

      // Create buttons outside the dropdown, showing currently active filters
      $('.facetapi-active', '.block--facetapi').each(function () {
        $(this).closest('.block__content').siblings('.chosen-choices').append('<li class="search-choice">' + $(this).parent().contents(":not(a, label, input, div)").text() + '</span>');
      });

      // Handle clicks on the active filter buttons to remove them
      $('.search-choice', '.block--facetapi').click(function () {
        var title = $(this).text();
        $(this).closest('.block--facetapi').find('.facetapi-active').each(function () {
          if ($(this).parent().contents(":not(a, label, input, div)").text() == title) {
            $(this).siblings('input').click();
          }
        });
      });

      // Display sorting and paging controls only when there are search results.
      if ($('.course-search .views-table').length == 0) {
        $('.pager-and-sorting-controls').hide();
      }
    }
  };

  Drupal.behaviors.courseSearchMultiselect = {
    attach: function (context, settings) {

      // Add "buttons" for applying changes and removing all filters
      $('.block__content, .item-list', '.block--facetapi').append('<div class="facet-buttons"></div>');
      $('.facet-buttons').append('<span class="facets-apply button">OK</span>')
        .append('<span class="facets-remove button">' + Drupal.t('Remove selections') + '</span>');
      $('.facets-apply').click(applyChanges);
      $('.facets-remove').click(function() {
        $(this).parent().siblings('ul').find('input[type="checkbox"]:checked').parent().trigger('click');
      });

      // Extract filter keys and values from current path
      var new_path = extractPathElems(window.location.pathname, settings.search_base_path);
      var added_filters = [];
      var removed_filters = {};
      var changes = 0; // Used to check if clicking outside the facet should trigger a redirect
      $('.block--facetapi ul li').each(function(key, elem) {
        elem.addEventListener('click', function(event) {
          // Prevent bubbling up so the click doesnt register on the hierarchy parent also
          event.stopPropagation();
          // Remove existing filter
          if ($(this).children('a').hasClass('facetapi-active')) {
            event.preventDefault();
            if ($(elem).children('input').attr('checked')) {
              var filter_path = ($(elem).children('a').attr('href')).split('?');
              filter_path = extractPathElems(filter_path[0], settings.search_base_path);
              new_path = new_path.filter(function(filter) {
                if (filter_path.indexOf(filter) == -1) {
                  removed_filters[$(elem).children('label').attr('for')] = filter;
                  return false;
                }
                return true;
              });
              $(elem).children('input').removeAttr('checked');
              changes++;
            }
            // Cancel removal
            else {
              var key = $(elem).children('label').attr('for');
              if (removed_filters[key] != undefined) {
                new_path.push(removed_filters[key]);
                delete removed_filters[key];
                $('#' + key).attr('checked', true);
                changes--;
              }
            }
          }
          // Add new filter
          else if ($(this).children('a').hasClass('facetapi-inactive')) {
            event.preventDefault();
            var selected_filter = /.*\/(.*\/[^\?]*)/.exec($(elem).children('a').attr('href'))[1];
            var index = added_filters.indexOf(selected_filter);
            // Not yet added, add
            if (index == -1) {
              added_filters.push(selected_filter);
              $(elem).children('input').attr('checked', true);
              changes++;
            }
            // Already to be added, cancel addition
            else {
              added_filters.splice(index, 1);
              $(elem).children('input').removeAttr('checked');
              changes--;
            }
          }
        });
      });

      $('.block__title', '.block--facetapi').click(function () {
        $(this).parent('.block--facetapi').toggleClass('collapsed');
        //$(this).siblings('.block__content').toggleClass('collapsed');
        if (changes > 0) {
          $('.facets-apply').trigger('click');
        }
      });

      // close dropdown when clicking outside it
      $(document).bind('touchstart click', function(event) {
        var collapsed = $('.block--facetapi.collapsed');
        // Any facets opened?
        if (collapsed.length > 0) {
          // Click outside facet? Close and apply selections.
          if (!$(event.target).closest(['.leaf', '.block__title'], '.block--facetapi').length && !$(event.target).closest('.block--facetapi').hasClass('collapsed')) {
            applyChanges();
          }
          // User has clicked on another facet while the previous one is open. Close and apply selections.
          if (collapsed.length > 1) {
            applyChanges();
          }
        }
      });

      /**
       * Takes a path string and splits it into an array where the first element is the
       * base path specified by base_path and the rest are facet filters in key/value format.
       * Leading and trailing slashes are stripped.
       * For example: ["open-university/search", "key1/value1", "key2/value2"]
       *
       * @param str The path string
       * @param base_path The path prefix belonging to the search page, eg "open-university/search"
       * @returns {Array}
       */
      function extractPathElems(str, base_path) {
        var filter_match = /(?:\/*)([^\/]*\/[^\/]*)(?:\/*)/g;
        var matches = [];

        // If current path doesn't have base_path in it, just return base_path to prevent adding the current path
        // to matches.
        if (str.indexOf(base_path) == -1) {
          matches.push(base_path);
          return matches;
        }

        str = str.replace('/' + base_path, '');
        while (match = filter_match.exec(str)) {
          matches.push(match[1]);
        }
        matches.splice(0, 0, base_path);
        return matches;
      }

      /**
       * The user has clicked something that should update selections. Either the OK button in a facet has been
       * clicked or the user has clicked somewhere outside the facet. This will close the facet and reload the
       * page if any changes have actually been made. Otherwise, just close the facet dropdown.
       */
      function applyChanges() {
        $('.block--facetapi').removeClass('collapsed');
        if (changes > 0) {
          // Use the search term in the fulltext search field but preserve other GET parameters
          var query = window.location.search.split('&');
          query[0] = '?search=' + $('#edit-search').val();
          query = query.join('&');
          window.location.replace(window.location.origin + '/' + new_path.concat(added_filters).join('/') + query);
        }
      }
    }
  };
})(jQuery, Drupal, this, this.document);
