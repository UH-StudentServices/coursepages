/**
 * @file
 * Open vertical tabs in course implementation node edit form
 * with url parameters
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  $(window).load(function() {

    var sections = [];
    //lets get all vertical tabs and add them to sections
    $('.vertical-tabs-panes .vertical-tabs-pane').each(function() {
      var section = { param: $(this).attr('id'), targetAccordion: '#' + $(this).attr('id') };
      sections.push(section);
    });

    var UrlParam = window.location.search.substring(1);
    var UrlParamParsed = UrlParam.split('section=');
    UrlParam = UrlParamParsed[1];

    $.each(sections, function(index, section) {
      if (UrlParam != undefined && section.param != null && section.param.length > 0 && UrlParam.indexOf(section.param) != -1) {
        tabIndex = $('.vertical-tabs-panes .vertical-tabs-pane').index($('.vertical-tabs-panes ' + section.targetAccordion));
        $('.vertical-tabs-list .vertical-tab-button').eq(tabIndex).children('a').trigger('click');
        $('html, body').animate({
          scrollTop: $(section.targetAccordion).offset().top - 55
        }, 500);
        return false;
      }
    });

    // get the active tab and store it in a hidden field for creating the redirect url
    $('.vertical-tab-button a', '.vertical-tabs-list').click(function() {
      $('.vertical-tabs-panes .vertical-tabs-pane').each(function() {
        if ($(this).css('display') != 'none') {
          var urlParam = $(this).attr('id');
          $("input[name='form_active_tab']").val(urlParam);
        };
      });
    });


  });
})(jQuery);
