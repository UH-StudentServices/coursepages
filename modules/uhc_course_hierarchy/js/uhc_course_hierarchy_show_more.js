/**
 * @file
 * In some cases we get unnecessary messages, so we remove them here.
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 *
 * In course hierarchy show only my enrollments by default. Clicking
 * 'show more' shows the rest of the courses.
 *
 */
(function ($) {
  Drupal.behaviors.uhc_course_hierarchy_show_more = {
    attach: function (context, settings) {
      var container = '.course-hierarchy ul.root',
          myEnrollment = '.my-enrollment',
          studyGroupSet = '.studygroupset',
          hasMore = $('li:not(' + studyGroupSet + '):not(' + myEnrollment + '):not(.active)', container),
          showMoreLink = '<li class="show-more"><a href="#">' + Drupal.t('Show more...') + '</a></li>',
          showMoreText = Drupal.t('Show more...'),
          showLessText = Drupal.t('Show less...');

      $(container).once('course_hierarchy_show_more', function() {
        // check if we have other than my enrollments
        if (hasMore.length !== 0) {
          // hide all except my enrollments
          hasMore.hide();
          //create show more link
          $(this).append(showMoreLink);

          // show hidden, toggle link title
          $('li.show-more a').click(function() {
            hasMore.slideToggle('fast');
            ($(this).text() == showLessText) ? $(this).text(showMoreText) : $(this).text(showLessText);
          });
        }
      });
    }
  }
})(jQuery);
