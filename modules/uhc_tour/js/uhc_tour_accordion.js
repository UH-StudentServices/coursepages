/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_tour_accordion = {
    attach: function (context) {
      $('.joyride-tip-guide').each(function() {
        //we store the next accordion item as a class on every joyride step
        var NextAccordionItem = $(this).attr('class').split(' ').pop();
        $(this).find('.joyride-next-tip').click(function() {
          //when next is clicked on the joyride step,  lets close the current active accordion item...
          $('.is-active').children('a').trigger('click');
          //...and lets open the next accordion item
          $('.' + NextAccordionItem).prev().children('a').trigger('click');
        });
      });      
      // this gets rid of all the extra whitespace when we have joyride enabled
      $('#joyride-tips-content').css('display', 'none');
      //Joyride screws up the positioning of these steps, so lets do some adjustments
      $('.joyride-tip-guide.joyride-moodle').css('margin-top', '-10px');

      $('.joyride-tip-guide.joyride-edit-link').css('margin-left', '-230px');
      $('.joyride-nub', '.joyride-tip-guide.joyride-edit-link').css({
        'right' : '19px',
        'left' : 'initial',
      });

      $('.joyride-tip-guide.joyride-logout-link').css('margin-left', '-260px');
      $('.joyride-nub', '.joyride-tip-guide.joyride-logout-link').css({
        'right' : '19px',
        'left' : 'initial',
      });
    }
  }
})(jQuery);
