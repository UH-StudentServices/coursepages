/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
(function ($) {

  Drupal.ajax.prototype.commands.timepickerinit = function(ajax, response, status) {
    startTimePicker = $(".field-name-field-event-begin-date input").not("[id*='datepicker']");
    durationPicker = $(".field-name-field-event-duration input");

    var startTimePickerSettings = {
          startTime: new Date(0,0,0,0,0,0),
          dynamic: false,
          interval: 15,
          timeFormat: 'HH:mm',
          minTime: '00:00',
          maxTime: '23:45',
          change: function(time) {
            adjustMaxDuration(time);
          }
        },
        durationPickerSettings = {
          startTime: new Date(0,0,0,0,0,0),
          dynamic: false,
          interval: 15,
          timeFormat: 'HH:mm',
          minTime: '00:00',
          maxTime: '23:45'
        };

    // no dropdown if mobile
    if (isMobile()) {
      durationPickerSettings.dropdown = false;
      startTimePickerSettings.dropdown = false;
    }

    if (startTimePicker.length && durationPicker.length) {
      //start timepicker init
      $(startTimePicker).timepicker(startTimePickerSettings);

      // duration timepicker init
      $(durationPicker).timepicker(durationPickerSettings);

      function adjustMaxDuration(time) {
        // set max duration to end at 23:45 of the same day
        maxHours = 23 - time.getHours();
        maxMinutes = 45 - time.getMinutes();
        maxTime = new Date(0,0,0, maxHours, maxMinutes, 0);
        durationPicker.timepicker('option', 'maxTime', maxTime);
        // selected duration cant be more than max duration
        durationPickerInstance = durationPicker.timepicker();
        if(durationPickerInstance.selectedTime > maxTime && durationPicker.val()) {
          $(durationPicker).timepicker('setTime', maxTime);
        }
      }

      // adjust max duration on init
      startTimePickerInstance = startTimePicker.timepicker();
      $(startTimePicker).timepicker('setTime', startTimePicker.val());
      adjustMaxDuration(startTimePickerInstance.selectedTime);
    }
  }

})(jQuery);
