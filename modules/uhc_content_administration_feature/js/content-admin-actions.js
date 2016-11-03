/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
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

})(jQuery);
