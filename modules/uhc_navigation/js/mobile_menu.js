/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.hy_doo_mobile_menu = {
    attach: function (context) {

      var layoutSmall = Drupal.settings.omega.mediaQueries['layout-small'];

      // Media Queries Matching
      if (typeof matchMedia !== 'undefined') {
        var mq = window.matchMedia(layoutSmall);
        mq.addListener(checkMobile);
        checkMobile(mq);
      }

      // Moves user menu to mobilemenu when changing to mobile.
      // Moves course hierarchy before content as an accordion.
      function checkMobile(mq) {

        // User menu.
        $('#block-system-user-menu').each(function () {
          var id = $(this).get(0).id;
          var placeholderId = id + '--placeholder';

          if (mq.matches === true) {
            $('#' + placeholderId).replaceWith($(this));
          }
          else {
            $(this).after('<span id="' + placeholderId + '"></span>');
            $('.main-menu > .menu').append($(this));
          }
        });

        // Course hierarchy.
        $('#course-hierarchy').each(function () {
          var id = $(this).get(0).id;
          var placeholderId = id + '--placeholder';
          var title = $(this).find('a').first().text();
          var accordion = '<h3 id="course-hierarchy-accordion" class="field-group-format-toggler accordion-item">' + title + '</h3>';

          // Large screen: Hierarchy in sidebar. Accordion hidden.
          if (mq.matches === true) {
            $('#course-hierarchy-accordion').hide();
            $(this).show();
            $('#' + placeholderId).replaceWith($(this));
          }
          // Small screen: Hierarchy before content as an accordion.
          else {
            $(this).after('<span id="' + placeholderId + '"></span>');
            $('.l-content').before($(this));
            $(this).hide();

            if (!$('#course-hierarchy-accordion').length) {
              $(this).before(accordion);
            }

            $('#course-hierarchy-accordion').show();

            // Required to activate accordion scripts on browser resize.
            Drupal.behaviors.hy_portal_ds_accordion.attach();
          }
        });
      }
    }
  };
})(jQuery);
