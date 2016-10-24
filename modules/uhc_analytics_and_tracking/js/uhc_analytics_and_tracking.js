/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
Drupal.behaviors.uhcGoogleAnalyticsEventTracking = {
  attach: function (context) {
    jQuery(context).ready(function(){
      if (typeof(Drupal.settings.uhcGoogleAnalyticsEventTracking) != 'undefined' &&
        typeof(Drupal.settings.uhcGoogleAnalyticsEventTracking.events) != 'undefined' &&
        typeof(ga) != 'undefined') {
        for (var i=0; Drupal.settings.uhcGoogleAnalyticsEventTracking.events.length > i; i++) {

          var category  = Drupal.settings.uhcGoogleAnalyticsEventTracking.events[i].category;
          var action    = Drupal.settings.uhcGoogleAnalyticsEventTracking.events[i].action;
          var opt_label = Drupal.settings.uhcGoogleAnalyticsEventTracking.events[i].opt_label;

          ga('send', {
            'hitType': 'event',
            'eventCategory': String(category),
            'eventAction': String(action),
            'eventLabel': String(opt_label),
            'eventValue': 0,
            'nonInteraction': false
          });
        }
      }
    });
  }
};
