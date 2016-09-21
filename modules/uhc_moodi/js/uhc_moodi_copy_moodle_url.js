/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  // Function: Get URL parameter value by name. If the parameter exists, but
  // has no value, return true. Otherwise return false.
  var getUrlParameter = function getUrlParameter(parameter) {
    var pageUrl = decodeURIComponent(window.location.search.substring(1));
    var urlParameters = pageUrl.split('&');
    var parameterName;
    var i;

    for (i = 0; i < urlParameters.length; i++) {
      parameterName = urlParameters[i].split('=');

      if (parameterName[0] === parameter) {
        return parameterName[1] === undefined ? true : parameterName[1];
      }
    }

    return false;
  };

  // Saves the Moodle URL to the course implementation, if the URL is present
  // as a hidden form input (set by the Moodi integration) and if the URL
  // parameter indicates a successful completion of Moodi create request.
  Drupal.behaviors.uhc_moodi_save_moodle_url_on_moodi_create = {
    attach: function (context) {
      $(function() {
        var moodi_moodle_url = $('input[name=moodi_moodle_url]').val();

        if (getUrlParameter('moodi_creation_successful') && moodi_moodle_url) {
          $('#edit-field-moodle-url-und-0-url').val(moodi_moodle_url);
          $('#edit-submit2').click();
        }
      });
    }
  }
})(jQuery);
