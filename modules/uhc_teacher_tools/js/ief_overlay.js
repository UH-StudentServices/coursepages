/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.uhc_teacher_tools_ief_overlay = {
    attach: function (context) {

      // add overlay for nested ief forms
      var nested_ief_form = $('.ief-form', '.ief-form');
      var document_height = $(document).height();
      var overlay =  $('body > .overlay');

      if(nested_ief_form.length > 0) { 
        if(overlay.length == 0) {
          $('body').prepend('<div class="overlay"></div>');
        }
        overlay.height(document_height);
        overlay.fadeTo( "slow", 0.5);
      } else {
        overlay.fadeTo( "slow", 0, function() {
          $(this).remove();
        });
      }

    }
  }

})(jQuery);
