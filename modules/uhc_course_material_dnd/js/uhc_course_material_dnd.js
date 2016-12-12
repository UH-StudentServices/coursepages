/**
 * @file
 * Attaches an implementation for binding and Dropzone element.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.ajax.prototype.commands.dropzoneinit = function(ajax, response, status) {
    var myDropzone = new Dropzone("div#material-dropzone div.material-dropzone", {
      // Custom callback endpoint for creating materials.
      url: "/dragndrop",
      // ParallelUploads are important to be one, because backend can't
      // handle them properly.
      parallelUploads: 1,
      acceptedFiles: Drupal.settings.uhc_course_material_dnd.allowed_extensions,
      maxFilesize: Drupal.settings.uhc_course_material_dnd.max_filesize,
      dictFileTooBig: Drupal.t('Max filesize is @size MB', {'@size': Drupal.settings.uhc_course_material_dnd.max_filesize}),
      dictInvalidFileType: Drupal.t('File extension not allowed. Allowed extensions include @exts', {'@exts': Drupal.settings.uhc_course_material_dnd.allowed_extensions}),

      // Set this, so we can translate the text
      dictDefaultMessage: Drupal.t('Drop files here to upload')
    });
    myDropzone.on("success", function(file, responseText, e) {
      for (var i=0; i<responseText.length; i++) {
        if (responseText[i].command == "invoke" && responseText[i].arguments[0] == "value") {
          var values = $(responseText[i].selector).val().split(" ");
          values.push(responseText[i].arguments[1]);
          $(responseText[i].selector).attr("value", values.join(" "));
          break;
        }
      }
    });
    myDropzone.on("addedfile", function(file) {
      $('.field-name-field-material-file a', '#ief-entity-table-edit-field-section-material-und-entities').each(function(key, elem) {
        if ($(elem).html() == file.name) {
          myDropzone.removeFile(file);
          var duplicateMessage = '<p>' + Drupal.t('The file "@file" already exists and was not uploaded.', {'@file': file.name}) + '</p>';
          $(duplicateMessage).dialog({
            modal: true,
            buttons: {
              OK: function() {
                $( this ).dialog( "close" );
              }
            }
          });
        }
      });
    });
    // Disable attach files button when upload in progress.
    myDropzone.on("processing", function(file) {
      $('#edit-field-section-material-und-form-actions-ief-dnd-save').attr('disabled', 'disabled');
    });

    myDropzone.on("error", function(file, message) {
      alert(message);
    });
    // Enable attach files button when upload is completed.
    myDropzone.on("queuecomplete", function() {
      $('#edit-field-section-material-und-form-actions-ief-dnd-save').removeAttr('disabled');
    });
  }

})(jQuery);
