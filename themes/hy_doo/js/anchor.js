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

