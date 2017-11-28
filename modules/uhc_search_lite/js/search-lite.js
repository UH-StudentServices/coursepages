/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($, Drupal, window, document, undefined) {
  Drupal.behaviors.uhc_search_lite = {
    getResultsTable: function (docs) {
      var rowClass = 'odd';
      var output = '<div class="view view-uhc-portal-search-front-page- view-id-uhc_portal_search_front_page_ view-display-id-desktop course-search front-page-search view-dom-id-5f1334c8dfecfea453d2030b97fe8fd8">';
      output += '<table class="views-table cols-4">';
      output += '<thead>';
      output += '<th class="views-field views-field-field-imp-reference-to-courses-field-course-course-number">' + Drupal.t('ID') + '</th>';
      output += '<th class="views-field views-field-title-field">' + Drupal.t('Name') + '</th>';
      output += '<th class="views-field views-field-field-imp-begin-date">' + Drupal.t('Begin date') + '</th>';
      output += '<th class="views-field views-field-field-imp-teacher">' + Drupal.t('Teacher(s)') + '</td>';
      output += '</tr>';
      output += '</thead>';
      output += '<tbody>';
      for (var i = 0; i<docs.length; i++) {
        var beginDate = new Date(docs[i].ds_field_imp_begin_date);
        output += '<tr class="' + rowClass + '">';
        output += '<td class="views-field views-field-field-imp-reference-to-courses-field-course-course-number">' + docs[i].ss_field_imp_reference_to_courses$field_course_course_number + '</td>';
        output += '<td class="views-field views-field-title-field"><a href="' + docs[i].ss_url + '">' + docs[i].ss_title_field + '</a></td>';
        output += '<td class="views-field views-field-field-imp-begin-date">' + beginDate.getDate() + '.' + (beginDate.getMonth()+1) + '.' + beginDate.getFullYear() + '</td>';
        output += '<td class="views-field views-field-field-imp-teacher">' + (docs[i].ss_field_imp_teacher ? docs[i].ss_field_imp_teacher : '') + '</td>';
        output += '</tr>';
        if (rowClass == 'odd') {
          rowClass = 'even';
        }
        else {
          rowClass = 'odd';
        }
      }
      output += '</tbody>';
      output += '</table>';
      output += '</div>';
      return output;
    },
    searchTimeout: null,
    performSearch: function() {
      clearTimeout(this.searchTimeout);
      $('.search-lite--loader').html('<span class="icon-2x icon--spinner icon-spin"></span>');
      var keyword = $('#search-lite input.search-lite--keyword').val();
      this.searchTimeout= setTimeout(function() {
        if (keyword.length > 0) {
          this.searchParameters = [
            'fq=ss_search_api_language%3A' + Drupal.settings.uhc_search_lite.language,
            'fq=ss_field_hierarchy_position%3A' + Drupal.settings.uhc_search_lite.hierarchy_position,
            'fq=index_id%3A' + Drupal.settings.uhc_search_lite.index_id,
            'fq=tm_search_api_aggregation_1%3A' + keyword,
            // TODO: Use variable!
            'fq=ss_academic_year%3A%22' + Drupal.settings.uhc_search_lite.academic_year + '%22',
            'fq=hash%3A' + Drupal.settings.uhc_search_lite.hash,
            'fl=ss_field_imp_reference_to_courses%24field_course_course_number%2Cis_nid%2Css_url%2Css_title_field%2Css_field_imp_teacher%2Css_search_api_language%2Cds_field_imp_begin_date%2Cds_field_imp_end_date',
            'wt=json',
            'indent=true',
            'start=0',
            'rows=100'
          ];
          $.get(Drupal.settings.uhc_search_lite.baseUrl, this.searchParameters.join('&'), function (data) {
            $('.search-lite--loader').html('');
            if (data.response.numFound > 0) {
              $('.search-lite--results').html(Drupal.t('<h2>Results (@total)</h2>', {'@total': data.response.numFound}) + '</h2>' + Drupal.behaviors.uhc_search_lite.getResultsTable(data.response.docs));
            }
            else {
              $('.search-lite--results').html(Drupal.t('No results'));
            }
          }, 'json');
        }
        else {
          $('.search-lite--loader').html('');
        }
      }, 500);
    },
    attach: function (context, settings) {
      $('#search-lite input.search-lite--keyword', context).keyup(this.performSearch);
      $('#search-lite input.search-form__submit', context).click(function(e) { Drupal.behaviors.uhc_search_lite.performSearch(); e.preventDefault(); });
    }
  };
})(jQuery, Drupal, this, this.document);
