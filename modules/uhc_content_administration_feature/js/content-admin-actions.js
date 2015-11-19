/* This script snippet will hide Show/hide row weights, as regular people do not
 * understand what it means (people without Drupal knowledge).
 */
(function ($) {

  /* Lets hide "Show row weights" / "Hide row weights" links as non-Drupal
     people find it unfamiliar term. See DOO-779. */
  Drupal.behaviors.uhcPortalContentAdminHideShowRowWeights = {
    attach: function(context) {
      $('.tabledrag-toggle-weight').hide();
    }
  }

  /* Fix issue of overlapping headlines and labels when rendering field inside
     vertical tab inside inline entity form inside field collection inside
     another vertical tab. I didn't bother to found an sub admin theme for one
     CSS styling and form alteration did not worked out well. */
  Drupal.behaviors.uhcPortalContentAdminHideMaterialGroupLabel = {
    attach: function(context) {
      $('#edit-group_mat_link legend, #edit-group_mat_file legend').hide();
    }
  }

})(jQuery);
