/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_doo_add_accordion_target_to_comment_pager_links = {
    attach: function (context) {
      $(function() {
        $('body.node-type-course-implementation .group-course-messages .pager a').each(function(e) {
          var href = $(this).attr('href');

          if (href.indexOf('group-course-messages') == -1) {
            if (href.indexOf('?') == -1) {
              $(this).attr('href', href + '?group-course-messages');
            } else {
              $(this).attr('href', href + '&group-course-messages');
            }
          }
        });
      });
    }
  }
})(jQuery);
