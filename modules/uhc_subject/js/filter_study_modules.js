/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {
  Drupal.behaviors.uhc_subject_filter_study_modules = {
    attach: function (context, settings) {

      var select_element = Drupal.settings.uhc_subject_filter_study_modules.select_element;
      var nodes_to_filter = Drupal.settings.uhc_subject_filter_study_modules.nodes_to_filter;
      var fields_to_filter = Drupal.settings.uhc_subject_filter_study_modules.fields_to_filter;
      var container = Drupal.settings.uhc_subject_filter_study_modules.container;

      // Create select lists
      $.each(fields_to_filter, function(key, value) {
        populate_select_list(value);
      });

      // Function for creating and populating select lists
      function populate_select_list(filter_field) {
        var field_name = filter_field['field_name'];
        var field_title = filter_field['field_title'];
        var placeholder = filter_field['placeholder'];

        // Add select element
        $('.' + container).prepend('<select multiple data-filter="' + field_name + '" class="' + field_name + ' ' + select_element + '"></select>');
        var element = $('select.' + field_name);

        // fetch available options, avoid duplicates
        var options = [];
        $('.' + nodes_to_filter).each(function(key, value) {

          // add data attribute as option if it exists
          if ($(this).data(field_name)) {
            var item = {};
            item.value = '<option>' + $(this).data(field_name) + '</option>';
          } else {
            return;
          }

          // add timestamp for begin date for easier sorting
          if(field_name == 'field_imp_begin_date') {
            item.timestamp = $(this).data('timestamp');
          }

          // remove duplicates
          var duplicate = false;
          $.each(options, function(key, option) {
            if (option.value == item.value) {
              duplicate = true;
              return;
            }
          });
          if (!duplicate) {
            options.push(item);
          }
        });

        // sort options
        if (field_name == 'field_imp_begin_date') {
          options.sort(function(a,b){
            return b.timestamp - a.timestamp ;
          });
        } else {
          options.sort(function(a,b){
            return a.value > b.value;
          });
        }

        // Add options to select
        $.each(options, function(key, value) {
          element.append(value.value);
        });

        // enable chosen
        element.chosen({
          display_selected_options: false,
          inherit_select_classes: true,
          placeholder_text_multiple: placeholder,
        });

        // add titles and make them open the chosen drop
        if (element.next('.chosen-container').length) {
          element.next('.chosen-container').prepend('<h2 class="block__title">' + field_title + '</h2>').click(function() {
            $(this).prev(element).trigger('chosen:updated');
          });
        } else {
          // if we don't have chosen (mobile devices), just add the title before select
          element.before('<h2 class="study-module-select-title">' + field_title + '</h2>');
        }
      }

      // Actual filtering. all filters are rerun when changing a single value
      $('select.' + select_element).chosen().change(function() {
        var enabled_filters = {};

        // Get all filter values
        $('select.' + select_element).each(function() {
          var filter_value = $(this).chosen().val();
          var field_to_filter = $(this).data('filter');
          enabled_filters[field_to_filter] = filter_value;
        });

        // loop through all nodes subject to filtering
        $('.' + nodes_to_filter).each(function() {
          var node_to_filter = $(this);

          // show node by default
          node_to_filter.show().addClass('visible');

          // Check each filter, if any of them returns no match, hide node
          $.each(enabled_filters, function(field_to_filter, filter_values) {
            if (!filter_match(node_to_filter, field_to_filter, filter_values)) {
              node_to_filter.hide().removeClass('visible');
              return;
            }
          });
        });

        // hide course if all it's implementations are hidden
        hide_empty_courses();
      });

      // compare filter values against data attributes in node to filter
      function filter_match(node_to_filter, field_to_filter, filter_values) {
        // if filter has no values, return true
        var filter_match = true;

        if (filter_values && filter_values.length) {
          // if filter has any values, default as false
          filter_match = false;

          // loop through all values and return true if a match is found
          if ($.inArray(node_to_filter.data(field_to_filter), filter_values) !== -1) {
            filter_match = true;
          }
        }
        return filter_match;
      }

      // hide course if all it's implementations are hidden
      function hide_empty_courses() {
        // loop each course
        $('.field-collection-item-field-study-module > .field-group-accordion-item', '.' + container).each(function() {
          // lets check if we have any non hidden imps in this course
          if ($('.' + nodes_to_filter, this).hasClass('visible')) {
            // show accordion only if it's open
            if ($(this).prev('h3.ds-teaser-accordion--title').hasClass('is-active')) {
              $(this).show();
            }
            // show accordion title
            $(this).prev('h3.ds-teaser-accordion--title').show().addClass('visible');
          } else {
            // hide accordion
            $(this).hide();
            // hide accordion title
            $(this).prev('h3.ds-teaser-accordion--title').hide().removeClass('visible');
          }
        });

        //Hide study module title if all study modules are hidden
        $('.field-collection-item-field-study-module', '.' + container).each(function() {
          if ($(this).children('h3.ds-teaser-accordion--title').hasClass('visible')) {
            $(this).children('.accordion-item-title').show();
          } else {
            $(this).children('.accordion-item-title').hide();
          }
        });
      }
    },
    weight: 999
  }
})(jQuery);
