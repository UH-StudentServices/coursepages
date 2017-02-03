(function($) {
  Drupal.behaviors.uhc_favorites = {
    attach: function(context) {

      // Gather list items
      var favorites = $.cookie('favoritewidget');
      if (!favorites) {
        favorites = [];
      }
      else {
        favorites = favorites.split(',');

        // Workaround for first potential empty value, at least in
        // jQuery.favoriteswidget v1.0.0
        if (favorites[0] == '') {
          favorites = favorites.splice(1);
        }
      }

      // Create list and "clear list" action link
      if (favorites.length > 0) {

        // Create a list and "Clear list" item
        $('.favorites-list--list', context).append('<ul class="list-of-links"></ul>');
        var clear = $('<a href="#" class="button">' + Drupal.settings.clearlist_label + '</a>').bind('click', function(e) {
          e.preventDefault();
          Drupal.behaviors.uhc_favorites.clearItems();
        });
        $('.favorites-list--clear', context).append(clear);

        // Add urls items to the list
        $('#favorites-list-items', context).once('favorites-list', function() {
          var self = this;
          var classes = 'list-of-links__link button--action icon--arrow-right theme-transparent';
          var path = Drupal.settings.basePath + Drupal.settings.pathPrefix + 'favorites/urls';
          var request = $.ajax({
            url: path,
            type: 'post',
            data: { favorites: favorites }
          });

          request.done(function (response, textStatus, jqXHR){
            $.each(response, function(key, value) {
              $(self).children('.list-of-links').append('<li class="' + classes + '"><a href="' + value.uri + '">' + value.label + '</a></li>');
            })
          });
        });

        // Add favorites to hidden input, so form submission can resolve the
        // urls for the email
        $('input[name=nids]', context).val(favorites.join(','));

      }
      else {
        // Remove list if we don't have any
        $('.favorites-list--list', context).remove();
      }
    },
    resolveItems: function(favorites) {
      // @TODO Resolve each URL
      return favorites;
    },
    clearItems: function() {
      $.cookie('favoritewidget', null, { path: '/' });
      $('.favorites-list').remove();
      $('input[name=nids]').val('');
    }
  };
})(jQuery);