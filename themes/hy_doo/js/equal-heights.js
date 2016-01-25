/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_search_portal_feature_equal_heights = {
    attach: function (context) {

      equalheight = function(container){
        var currentTallest = 0,
           currentRowStart = 0,
           rowDivs = new Array(),
           $el,
           topPosition = 0;
       $(container).each(function() {

         $el = $(this);
         $($el).height('auto')
         topPostion = $el.position().top;

         if (currentRowStart != topPostion) {
           for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
             rowDivs[currentDiv].height(currentTallest);
           }
           rowDivs.length = 0; // empty the array
           currentRowStart = topPostion;
           currentTallest = $el.height();
           rowDivs.push($el);
         } else {
           rowDivs.push($el);
           currentTallest = (currentTallest < $el.height()) ? ($el.height()) : (currentTallest);
        }
         for (currentDiv = 0 ; currentDiv < rowDivs.length ; currentDiv++) {
           rowDivs[currentDiv].height(currentTallest);
         }
       });
      }

      equalheight('.block--facetapi');
      equalheight('.gridder-box');

    },
    weight: 100
  }

  // trigger equal heights on these events
  var events = ['resize', 'load'];

  events.forEach(function(eventlistener) {
    window.addEventListener(eventlistener, function() {
      equalheight('.block--facetapi');
      equalheight('.gridder-box');
    });
  });

})(jQuery);
