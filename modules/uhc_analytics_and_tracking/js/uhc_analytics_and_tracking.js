Drupal.behaviors.uhcGoogleAnalyticsEventTracking = {
  attach: function (context) {
    jQuery(context).ready(function(){
      if (typeof(Drupal.settings.uhcGoogleAnalyticsEventTracking) != 'undefined' &&
        typeof(Drupal.settings.uhcGoogleAnalyticsEventTracking.events) != 'undefined' &&
        typeof(_gaq) != 'undefined') {
        for (var i=0; Drupal.settings.uhcGoogleAnalyticsEventTracking.events.length > i; i++) {

          var category  = Drupal.settings.uhcGoogleAnalyticsEventTracking.events[i].category;
          var action    = Drupal.settings.uhcGoogleAnalyticsEventTracking.events[i].action;
          var opt_label = Drupal.settings.uhcGoogleAnalyticsEventTracking.events[i].opt_label;

          // console.log(['_trackEvent', String(category), String(action), String(opt_label), 0, false]);
          _gaq.push(['_trackEvent', String(category), String(action), String(opt_label), 0, false]);
        }
      }
    });
  }
};
