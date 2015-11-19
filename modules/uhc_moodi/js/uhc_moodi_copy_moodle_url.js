(function ($) {
  Drupal.behaviors.uhc_moodi_copy_moodle_url = {
    attach: function (context) {
      $(function() {
        $('#edit-uhc-moodi-copy-url-link a').click(function(e) {
          e.preventDefault();
          var moodi_moodle_url = $('input[name=moodi_moodle_url]').val();

          if (moodi_moodle_url) {
            $('#edit-field-moodle-url-und-0-url').val(moodi_moodle_url);
          }
        });
      });
    }
  }
})(jQuery);
