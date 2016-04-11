/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_doo_show_past_imps = {
    attach: function (context) {
      $(function() {
        var showMoreText = Drupal.t('Show past'),
            showLessText = Drupal.t('Hide past');

        $('.course-node-references-past').once('uhc_doo_show_past_imps', function() {
          $(this).before('<a href="#" class="show-past-imps">' + showMoreText + '</a>');
          $(this).prev('.show-past-imps').click(function(event){
            event.preventDefault();
            $(this).next().slideToggle('slow');
            ($(this).text() == showLessText) ? $(this).text(showMoreText) : $(this).text(showLessText);
          });
        });
      });
    }
  }
})(jQuery);
