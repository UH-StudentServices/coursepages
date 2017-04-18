(function($) {
  Drupal.behaviors.uhc_favorites = {
    setFavoritesLink: function() {
      var link = $('.favorites-link'),
          count = $('.favorites-link__count'),
          countText = "(" + Drupal.behaviors.uhc_favorites.getCount() + ")",
          countElement = $('<span>').addClass('favorites-link__count').text(countText);

      if (count.length > 0) {
        count.text(countText);
      }
      else {
        link.append(countElement);
      }
    },
    getFavorites: function() {
      var favorites = $.cookie('favoritewidget');
      if (!favorites) {
        favorites = [];
      }
      else {
        favorites = favorites.split(',');

        // Workaround for first potential empty value, at least in
        // jQuery.favoriteswidget v1.0.0.
        if (favorites[0] == '') {
          favorites = favorites.splice(1);
        }
      }
      return favorites;
    },
    getCount: function() {
      return Drupal.behaviors.uhc_favorites.getFavorites().length;
    },
    attach: function(context) {

      // Init favorites link count.
      Drupal.behaviors.uhc_favorites.setFavoritesLink();

      // When in favorites list.
      if ($('.favorites-list--list', context).length > 0) {
        // Gather list items.
        var favorites = Drupal.behaviors.uhc_favorites.getFavorites();
        Drupal.behaviors.uhc_favorites.setFavoritesLink();

        // Create list and "clear list" action link.
        if (favorites.length > 0) {

          // Create a list and "Clear list" item.
          $('.favorites-list--list', context).append('<ul class="list-of-links"></ul>');
          var clear = $('<a href="#" class="button">' + Drupal.settings.clearlist_label + '</a>').bind('click', function (e) {
            e.preventDefault();
            Drupal.behaviors.uhc_favorites.clearItems();
          });
          $('.favorites-list--clear', context).append(clear);

          // Add URLs items to the list.
          $('#favorites-list-items', context).once('favorites-list', function () {
            var self = this;
            var classes = 'list-of-links__link button--action icon--arrow-right theme-transparent';
            var path = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'favorites/urls';
            var request = $.ajax({
              url: path,
              type: 'post',
              data: {favorites: favorites}
            });

            request.done(function (response, textStatus, jqXHR) {
              $.each(response, function (key, value) {
                $(self).children('.list-of-links').append('<li><a class="' + classes + '" href="' + value.uri + '">' + value.label + '</a></li>');
              })
            });
          });

          // Add favorites to hidden input, so form submission can resolve the
          // URLs for the email.
          $('input[name=nids]', context).val(favorites.join(','));

        }
        else {
          // Remove list if we don't have any.
          $('.favorites-list--list', context).remove();
        }
      }

      // track click events
      $('.favoritewidget--addfav').once().click(function() {
         Drupal.behaviors.uhc_favorites.trackAddFavorites(this);
      });

        // track favorites email send
      $('#uhc-favorites-send-by-email-form input#edit-submit').once().click(function() {
         Drupal.behaviors.uhc_favorites.trackEmailSubmit(this);
      });

    },
    resolveItems: function(favorites) {
      // @TODO Resolve each URL
      return favorites;
    },
    clearItems: function() {
      $.cookie('favoritewidget', null, { path: '/' });
      $('.favorites-list').remove();
      $('input[name=nids]').val('');
      Drupal.behaviors.uhc_favorites.setFavoritesLink();
    },
    // Track filter click.
    trackAddFavorites: function(element) {
      var trackEvents = typeof ga != 'undefined';

      if (trackEvents) {
        var eventCategory = 'Favorites added';

        // Search listing.
        var eventLabel = $(element).parents('td').siblings('td.views-field-field-imp-reference-to-courses-field-course-course-number').text();
        eventLabel = $.trim(eventLabel);

        // Course implementation page.
        if (!eventLabel) {
          eventLabel = location.pathname;
        }

        ga('send', {
          'hitType': 'event',
          'eventCategory': eventCategory,
          'eventAction': 'click',
          'eventLabel': eventLabel,
          'eventValue': 0,
          'nonInteraction': false
        });
      }
    },
    // Track email submit.
    trackEmailSubmit: function(element) {
      var trackEvents = typeof ga != 'undefined';

      if (trackEvents) {
        var eventCategory = 'Favorites list sent by email';
        var eventLabel = eventCategory;

        ga('send', {
          'hitType': 'event',
          'eventCategory': eventCategory,
          'eventAction': 'click',
          'eventLabel': eventLabel,
          'eventValue': 0,
          'nonInteraction': false
        });
      }
    },
  };
})(jQuery);
