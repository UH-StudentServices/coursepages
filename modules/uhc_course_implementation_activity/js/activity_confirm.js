/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.course_implementation_activity = {
    attach: function (context, settings) {

      // accordion items to open for each message type
      var sections = Drupal.settings.uhc_course_implementation_activity.sections;

      // lets link each message type to the correct accordion item when clicked
      $.each(sections, function(index, section) {
        if (section.targetAccordion) {
          $('.activity li.' + section.messageType).click(function(){
            if (!$(section.targetAccordion).prev().hasClass('is-active')) {
              $(section.targetAccordion).prev().children('a').click();
            }
            var offset = $(section.targetAccordion).offset();
            if (offset != null) {
              $('html, body').animate({
                scrollTop: offset.top - 55
              }, 500);
            }
          });
        }
      });

      $('.activity').click(function(){
        $('.activity .item-list').toggleClass('collapsed');

        if (Drupal.settings.uhc_course_implementation_activity.is_logged_in) {
          //set the cookie and update recent activity again to remove classes from new messages.

          // if we have a lang prefix in path, lets remove it first for easier handling
          var path = window.location.pathname;
          if (Drupal.settings.pathPrefix) {
            path = path.replace(Drupal.settings.pathPrefix, '');
          }

          // now lets add cookies for all prefixes
          var lang_prefixes = ['', '/fi', '/sv'];
          $(lang_prefixes).each(function(index, value) {
            $.cookie('uhc_activity_last_visited', Drupal.settings.uhc_course_implementation_activity.time, { expires: 7, path: value + path });
          });

          // if cookie is not set for some reason like IE11 if path is set, add cookie for this language version only, better than nothing
          if (!$.cookie('uhc_activity_last_visited') || $.cookie('uhc_activity_last_visited') < Drupal.settings.uhc_course_implementation_activity.time) {
            $.cookie('uhc_activity_last_visited', Drupal.settings.uhc_course_implementation_activity.time, { expires: 7 });
          }
          updateActivityCount();
        }
      });

      $('.activity .item-list li').click(function(){
        if (Drupal.settings.uhc_course_implementation_activity.is_logged_in) {
          $(this).removeClass('new');
          // store mid in localstorage, see markAsUnread()
          localStorage.setItem($(this).find('.message-date').data('mid'), Drupal.settings.uhc_course_implementation_activity.time);
        }
      });

      // hide when clicking outside event list
      $(document).bind('touchstart click', function(event) {
        if (!$(event.target).closest('.activity').length &&  $('.activity .item-list').hasClass('collapsed')) {
          $('.activity .item-list').removeClass('collapsed');
        }
      });

      // counts total new activites
      function updateActivityCount() {
        var ActivityCount = '';
        var LastVisitedTime = $.cookie('uhc_activity_last_visited');
        $('.activity .item-list li').each(function() {
          // We have the message time stored as a data-attribute, lets compare that to the cookie time
          var MessageTime = $(this).find('.message-date').data('timestamp');
          if (MessageTime > LastVisitedTime) {
            ActivityCount ++;
          }
        });
        $('.count').text(ActivityCount);
      }

      // marks activity messages as new
      function markAsUnread() {
        $('.activity .item-list li').each(function() {
          // the message is considered new if mid is not found in local storage
          var MessageTime = localStorage.getItem($(this).find('.message-date').data('mid'));
          if (MessageTime == null) {
            $(this).addClass('new');
          }
        });
      }

      if (Drupal.settings.uhc_course_implementation_activity.is_logged_in) {
        updateActivityCount();
        markAsUnread();
      }
    }
  }
})(jQuery);
