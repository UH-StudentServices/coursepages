/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
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
