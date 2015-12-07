/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_tour_tabs = {
    attach: function (context) {
      $('.joyride-tip-guide').each(function() {
        //we store the next tab pane as a class on every joyride step
        var NextAccordionItem = $(this).attr('class').split(' ').pop();
        $(this).find('.joyride-next-tip').click(function() {
          // Lets get the index of the next tab pane...
          tabIndex = $('.vertical-tabs-panes .vertical-tabs-pane').index($('.vertical-tabs-panes #' + NextAccordionItem));
          // And then click the tab button with the according index
          $('.vertical-tabs-list .vertical-tab-button').eq(tabIndex).children('a').trigger('click');
        });
      });
    }
  }
})(jQuery);
