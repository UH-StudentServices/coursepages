/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.premiseSearch = {
    attach: function(context, settings) {

      // Make sure this happens only once
      $('.views-exposed-widgets').once('uhc-filters', function() {
        // Submit form when sort select is changed, only visible in mobile
        $('#edit-sort-by').change( function() {
          $(this).closest('form').trigger('submit');
          /* or:
          $('#formElementId').trigger('submit');
            or:
          $('#formElementId').submit();
          */
        });
        // Moving views widget description to input placeholder
        var placeholder = $("#edit-search-wrapper .description").text();
        $("#edit-search").attr("placeholder", $.trim(placeholder));
      });

      // Faux multiselect dropdown for checkboxes
      $('.block__content', '.block--facetapi').after('<ul class="chosen-choices"></ul>');

      $('.facetapi-active', '.block--facetapi').each(function() {
        $(this).closest('.block__content').siblings('.chosen-choices').append('<li class="search-choice">' + $(this).parent().contents(":not(a, label, input)").text() + '</span>');
      });

      $('.block__title', '.block--facetapi').click(function() {
        $(this).siblings('.block__content').toggleClass('collapsed');
      });

      $('.search-choice', '.block--facetapi').click(function() {
        var title = $(this).text();
        $(this).closest('.block--facetapi').find('.facetapi-active').each(function() {
          if ($(this).parent().contents(":not(a, label, input)").text() == title) {
            $(this).siblings('input').click();
          }
        });
      });

      // close dropdown when clicking outside it
      $(document).click(function(event) {
        if (!$(event.target).closest('.block__title', '.block--facetapi').length && $('.block__title', '.block--facetapi').siblings('.block__content').hasClass('collapsed')) {
          $('.block__content', '.block--facetapi').removeClass('collapsed');
        }
      });

      // Alter facets to include typed but not yet submitted text in the fulltext search field
      $('#edit-search').change(function(event) {
        $('.block--facetapi a.facetapi-checkbox').each(function (i, elem) {
          $(elem).attr('href', $(elem).attr('href').replace(/(\?search=)([\w%]*)/, '$1' + event.currentTarget.value));
        });
      });

    }
  };

})(jQuery, Drupal, this, this.document);
