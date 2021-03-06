/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.hy_portal_ds_accordion = {
    attach: function (context) {
      $(function() {
        $( ".field-group-format-toggler, .ds-teaser-accordion--title" ).once().click(function(e) {
          e.preventDefault();
          $(this).next().slideToggle(0);
          $(this).toggleClass('is-active');
          return false;
        }).next().hide();

        // edit links don't work unless we stop triggering the parent click
        $( ".accordion-edit-link" ).click(function(e) {
          e.stopPropagation();
        });
      });
    }
  }
})(jQuery);
