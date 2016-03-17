/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.hy_doo_vertical_tabs = {
    attach: function (context) {
      var header = '.vertical-tabs-header';
      var list = '.vertical-tabs-list';

      $(list).once('vertical_tabs', function () {

        // add header
        $(this).before('<div class="vertical-tabs-header"></div>');
        update_header();

        // open menu when clicking header
        $(header).click(function(){
          $(list + ',' + header).toggleClass('collapsed');
        });

        // update header and close menu when clicking an item
        $('.vertical-tab-button a', list).click(function(){
          update_header();
          if ($(list).hasClass('collapsed')) {
            $(list + ',' + header).removeClass('collapsed');
          }
        });
      });

      // close when clicking outside menu
      $(document).click(function(event) {
        if (!$(event.target).closest(header).length && $(header).next(list).hasClass('collapsed')) {
          $(list + ',' + header).removeClass('collapsed');
        }
      });

      // update header with selected tab
      function update_header() {
        var selected = $('.selected strong', list).text();
        $(header).text(selected);
      }

    }
  }
})(jQuery);
