/**
 * @file
 * Add classes to feedback block.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_feedback = {
    attach: function (context) {
      var $block = '#block-feedback-form';
      var trackEvents = typeof _gaq != 'undefined';
      $('body').once().delegate("#block-feedback-form:not('.open')", 'mousedown', function () {
        if (trackEvents) {
          _gaq.push(['_trackEvent', 'Feedback form', 'open', 'Feedback form', 0, false]);
        }
      });
      $('.feedback-link', $block).once().click(function () {
        $($block).toggleClass('open');
      });
      $('#feedback-submit').once().mousedown(function () {
        if (trackEvents) {
          _gaq.push(['_trackEvent', 'Feedback form', 'submit', 'Submit', 0, false]);
        }
      });
      $('#feedback-submit', $block).once().click(function () {
        $($block).toggleClass('open');
      });
    }
  };
})(jQuery);
