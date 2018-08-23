/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_tour_accordion = {
    attach: function (context) {
      $('.joyride-tip-guide').each(function() {

        // Store the next accordion item as a class on every joyride step.
        var nextAccordionItem = $(this).attr('class').split(' ').pop();
        $(this).find('.joyride-next-tip').click(function() {

          // When next is clicked on the joyride step, close the current active accordion item.
          $('.is-active').children('a').trigger('click');

          // ...and open the next accordion item.
          $('.' + nextAccordionItem).prev().children('a').trigger('click');
        });
      });      

      // Whitespace removal.
      $('#joyride-tips-content').css('display', 'none');

      // Positioning adjustments.
      $('.joyride-tip-guide.moodle-url').css('margin-top', '-10px');

      $('.joyride-tip-guide.joyride-edit-link').css({
        'margin-left': '-280px'
      });

      $('.joyride-nub', '.joyride-tip-guide.joyride-edit-link').css({
        'right' : '19px',
        'left' : 'initial',
      });

      $('.joyride-tip-guide.joyride-logout-link').css({
        'margin-left': '-260px'
      });

      $('.joyride-nub', '.joyride-tip-guide.joyride-logout-link').css({
        'right' : '19px',
        'left' : 'initial',
      });
    }
  }
})(jQuery);
