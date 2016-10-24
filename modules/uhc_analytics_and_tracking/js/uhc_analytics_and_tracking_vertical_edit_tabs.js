/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhcGoogleAnalyticsEventTrackingVerticalEditTabs = {
    attach: function (context) {
      $(context).ready(function () {
        if (typeof ga != 'undefined') {
          $('.page-node-edit .vertical-tab-button a').once().click(function (e) {
            var category = 'Teacher edit links (vertical tabs)';
            var action = 'click';
            var label = $(this).find('strong').text();
            ga('send', {
              'hitType': 'event',
              'eventCategory': String(category),
              'eventAction': String(action),
              'eventLabel': String(label),
              'eventValue': 0,
              'nonInteraction': false
            });
          });
        }
      })
    }
  };
})(jQuery);
