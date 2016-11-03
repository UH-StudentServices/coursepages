/**
 * @file
 * Sort material alphabetically with tabledrag and inline entity form
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.behaviors.uhc_course_material_sort = {
    attach: function (context, settings) {
      var base = 'ief-entity-table-edit-field-section-material-und-entities';
      var tableDrag = Drupal.tableDrag[base];
      var materialSections = Drupal.settings.uhc_course_material_sort.material_sections;

      // reorder on load
      if (typeof ReorderedOnLoad === 'undefined' && typeof tableDrag != 'undefined') {
        window.ReorderedOnLoad = true;
        checkAutoSort();
      }

      // Add "order alphabetically" link before the table.
      $('#' + base, context).once(function() {
        $(this).siblings('[id*=field-section-material-und-actions]')
          .append('<input type="submit" class="tabledrag-order form-submit" value="' + Drupal.t('Order alphabetically') + '">');
      });

      // sort alphabetically when clicking the link
      $('.tabledrag-order').unbind().click(function(event) {
        event.preventDefault();
        reorderTable(true);
      });

      if (Drupal.tableDrag != undefined) {
        // we need to mark the table as "altered by user" so we can disable automatic alphabetical sorting.
        // as we aleady use swap and drop programmatically, the only way we can (sortof) detect this is onDrag.   
        Drupal.tableDrag.prototype.onDrag = function () {
          $("input[name='material_table_auto_sort']").val(0);
        };

        // reorder table by sections on every drop, except the ones created by reorderTable();
        Drupal.tableDrag.prototype.onDrop = function () {
          reorderTable(false);
        };
      }

      // when material is added, we trigger sorting
      Drupal.ajax.prototype.commands.autoOrderMaterialAlphabetically = function(ajax, response, status) {
        checkAutoSort();
      }

      // check if the user has done a bit of sorting him/herself, and if not, sort alphabetically.
      function checkAutoSort() {
        var canSort = $("input[name='material_table_auto_sort']").val();
        if (canSort == 1) {
          reorderTable(true);
        } else {
          reorderTable(false);
        }
      };

      // function to reorder table by section. alphabetical order added if needed.
      function reorderTable(sortAlphabetically) {

        // Loop sections, add corresponding rows alphabetically
        $.each(materialSections, function() {
          // Lets add rows belonging to each section
          this.rows = $('> tr.draggable, > tbody > tr.draggable', $('#' + base))
            .find('.field--name-field-material-section:contains(' + this.section + ')')
            .closest('.ief-row-entity.draggable');

          if(this.section == undefined) {
            this.rows = $('> tr.draggable, > tbody > tr.draggable', $('#' + base))
              .find('.inline-entity-form-node-field_material_section:empty')
              .closest('.ief-row-entity.draggable');
          }

          // Lets reorder the rows alphabetically if needed
          if (sortAlphabetically == true) {
            this.rows.sort(function(a, b) {
              a = $(a).find('.inline-entity-form-node-field_material_title').text().toLowerCase().trim();
              b = $(b).find('.inline-entity-form-node-field_material_title').text().toLowerCase().trim();
              if (a < b) return -1;
              if (a > b) return 1;
              return 0;
            });
          }
          // rebuild the table
          this.rows.each(function() {
            tableDrag.rowObject = new tableDrag.row(this, 'mouse', tableDrag.indentEnabled, tableDrag.maxDepth, true);
            var lastRow = $(this).siblings(":last");
            tableDrag.rowObject.swap('after', lastRow);
          });
          tableDrag.restripeTable();
        });
        addSectionTitles(materialSections);
      };

      // adds section titles to the table
      function addSectionTitles(sections) {
        // first remove old titles
        $('#' + base).find('label.section-title').remove();
        $.each(sections, function() {
          // add section title
          $('> tr.draggable, > tbody > tr.draggable', $('#' + base))
            .find('.field--name-field-material-section .field__item:contains(' + this.section + ')')
            .first()
            .closest('.ief-row-entity.draggable')
            .before('<label class="section-title">' + this.title + '</label>');

          // 'Other' section
          if(this.section == undefined) {
            $('> tr.draggable, > tbody > tr.draggable', $('#' + base))
              .find('.inline-entity-form-node-field_material_section:empty')
              .first()
              .closest('.ief-row-entity.draggable')
              .before('<label class="section-title">' + this.title + '</label>');
          }
        });
      };

    },
    weight: 100
  }
})(jQuery);
