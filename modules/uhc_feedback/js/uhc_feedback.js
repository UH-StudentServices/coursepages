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
      var trackEvents = typeof ga != 'undefined';
      $('body').once().delegate("#block-feedback-form:not('.open')", 'mousedown', function () {
        if (trackEvents) {
          ga('send', {
            'hitType': 'event',
            'eventCategory': 'Feedback form',
            'eventAction': 'open',
            'eventLabel': 'Feedback form',
            'eventValue': 0,
            'nonInteraction': false
          });
        }
      });
      $('.feedback-link', $block).once().click(function () {
        $($block).toggleClass('open');
      });
      $('#feedback-submit').once().mousedown(function () {
        if (trackEvents) {
          ga('send', {
            'hitType': 'event',
            'eventCategory': 'Feedback form',
            'eventAction': 'submit',
            'eventLabel': 'Submit',
            'eventValue': 0,
            'nonInteraction': false
          });
        }
      });
      $('#feedback-submit', $block).once().click(function () {
        $($block).toggleClass('open');
      });
    }
  };
})(jQuery);
