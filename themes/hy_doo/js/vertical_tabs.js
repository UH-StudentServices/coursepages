/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.hy_doo_vertical_tabs = {
    attach: function (context) {

      $('.vertical-tabs-list').once('vertical_tabs', function () {
        var list = this;

        // add header
        var header = $(list).before('<div class="vertical-tabs-header"></div>').siblings('.vertical-tabs-header');
        update_header(list, header);

        // open menu when clicking header
        $(header).click(function(){
          $(header).toggleClass('collapsed');
          $(list).toggleClass('collapsed');
        });
        // update header and close menu when clicking an item
        $('.vertical-tab-button a', list).click(function(){
          update_header(list, header);
          if ($(list).hasClass('collapsed')) {
            $(header).removeClass('collapsed');
            $(list).removeClass('collapsed');
          }
        });
      });

      // close any open vertical tabs when clicking outside menu
      $(document).click(function(event) {
        var header = '.vertical-tabs-header';
        var list = '.vertical-tabs-list';
        if (!$(event.target).closest(header).length && $(header).next(list).hasClass('collapsed')) {
          $(list + ',' + header).removeClass('collapsed');
        }
      });

      // update header with selected tab
      function update_header(list, header) {
        var selected = $('.selected strong', list).text();
        $(header).text(selected);
      }

    }
  }
})(jQuery);
