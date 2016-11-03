/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_doo_show_past_imps = {
    attach: function (context) {
      $(function() {

        // These are added, because for mysterious reason Drupal.t() does not
        // appear to work in unknown conditions. We have tested different
        // scenarios and validated whether issue #2182265 is the case, but so
        // far we think its not related to that. Ticket description has tested
        // scenarios described in the comments.
        // See: https://jira.it.helsinki.fi/browse/DOO-1405
        var showMoreText = Drupal.settings.show_past_imps.show_past_text,
            showLessText = Drupal.settings.show_past_imps.hide_past_text;

        $('.course-node-references-past').once('uhc_doo_show_past_imps', function() {
          $(this).before('<a href="#" class="show-past-imps">' + showMoreText + '</a>');
          $(this).prev('.show-past-imps').click(function(event){
            event.preventDefault();
            $(this).next().slideToggle('slow');
            ($(this).text() == showLessText) ? $(this).text(showMoreText) : $(this).text(showLessText);
          });
        });

        // Google Analytics Event Tracking.
        var trackEvents = typeof ga != 'undefined';

        if (trackEvents) {
          // Show past implementations on course page.
          $('.node-type-course a.show-past-imps').once('uhc_doo_show_past_imps_on_course_page_ga_event', function () {
            $(this).click(function (event) {
              if ($(this).text() === showLessText) {
                ga('send', {
                  'hitType': 'event',
                  'eventCategory': 'Show past implementations on course page',
                  'eventAction': 'click',
                  'eventLabel': 'Show past implementations',
                  'eventValue': 0,
                  'nonInteraction': false
                });
              }
            });
          });

          // Show past implementations on subject page.
          $('.node-type-subject a.show-past-imps').once('uhc_doo_show_past_imps_on_subject_page_ga_event', function () {
            $(this).click(function (event) {
              if ($(this).text() === showLessText) {
                ga('send', {
                  'hitType': 'event',
                  'eventCategory': 'Show past implementations on subject page',
                  'eventAction': 'click',
                  'eventLabel': 'Show past implementations',
                  'eventValue': 0,
                  'nonInteraction': false
                });
              }
            });
          });
        }
      });
    }
  }
})(jQuery);
