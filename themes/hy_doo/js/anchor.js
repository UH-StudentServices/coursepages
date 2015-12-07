/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.helsingin_yliopisto_anchor = {
    attach: function (context) {
      // Cache html and body instead of loading them on every click
      var $root = $('html, body');
      $("a#up-anchor").click(function () {
        $root.animate({ scrollTop: 0 }, "slow");
        return false;
      });
    }
  };

})(jQuery);

