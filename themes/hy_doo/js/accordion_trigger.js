/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.hy_doo_accordion_trigger = {
    attach: function (context) {
      $(function() {

        // accordion items to open for each url parameter
        var sections = [];
        if (typeof Drupal.settings.uhc_course_implementation_activity != 'undefined' && typeof Drupal.settings.uhc_course_implementation_activity.sections != 'undefined') {
          sections = Drupal.settings.uhc_course_implementation_activity.sections;
        }

        var UrlParam = window.location.search.substring(1);
        var UrlParamParsed = UrlParam.split('section=');
        if (UrlParamParsed[1] === undefined) {
          UrlParam = UrlParamParsed[0];
        } else {
          UrlParam = UrlParamParsed[1];
        }

        $.each(sections, function(index, section) {
          if (UrlParam.length > 0 && section.param != null && section.param.length > 0 && UrlParam.indexOf(section.param) != -1) {
            $(section.targetAccordion).prev().children('a').click();
            $('html, body').animate({
              scrollTop: $(section.targetAccordion).offset().top - 55
            }, 500);
            return false;
          }
        });

        // open accordion items with anchors
        if (window.location.hash.length) {
          var anchorName = window.location.href.split('#')[1];
          var anchorSelector = "a[name*='" + anchorName + "']";
          var anchor = $(anchorSelector);
          anchor.click();
          $('html, body').animate({scrollTop: anchor.offset().top}, 'slow');
        }
      });
    }
  }
})(jQuery);
