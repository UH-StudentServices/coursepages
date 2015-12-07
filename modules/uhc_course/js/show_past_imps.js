/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_doo_show_past_imps = {
    attach: function (context) {
      $(function() {
        var view = '.course-node-references-past';
        $(view).after('<a href="#" class="show-past-imps">' + Drupal.t('Show past') + '</a>');
        $('.show-past-imps').click(function(event){
          event.preventDefault();
          $(view).slideToggle('slow');
          ($(this).text() == Drupal.t('Hide past')) ? $(this).text(Drupal.t('Show past')) : $(this).text(Drupal.t('Hide past'));
        });
      });
    }
  }
})(jQuery);
