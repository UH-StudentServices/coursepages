(function ($) {

  Drupal.behaviors.hy_portal_ds_accordion = {
    attach: function (context) {
      $(function() {
        $( ".field-group-format-toggler, .ds-teaser-accordion--title" ).click(function(e) {
          e.preventDefault();
          $(this).next().slideToggle(0);
          $(this).toggleClass('is-active');
          return false;
        }).next().hide();
      });
    }
  }
})(jQuery);
