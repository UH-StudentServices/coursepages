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
      $('.feedback-link', $block).once().click(function () {
        $($block).toggleClass('open');
      });
      $('#feedback-submit', $block).once().click(function () {
        $($block).toggleClass('open');
      });
    }
  };
})(jQuery);
