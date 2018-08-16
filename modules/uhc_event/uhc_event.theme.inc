<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Default preprocessing callback for structured schedule.
 *
 * @param $variables
 */
function template_preprocess_uhc_event_structured_teaching_schedule(&$variables) {
  $variables['title'] = '';
  $variables['prefix'] = '<div>';
  $variables['suffix'] = '</div>';

  // Set title and prefix
  if(uhc_event_has_events_from_both_sources($variables['node'])) {
    $variables['title'] = '<h2 class="accordion-item__light ds-teaser-accordion--title">' . t('Teaching schedule') . '</h2>';
    $variables['prefix'] = '<div class="event-list table-three-columns field-group-accordion-item">';
  }
  else {
    $variables['prefix'] = '<div class="event-list table-three-columns tube--large">';
  }
}

/**
 * Default callback for rendering teaching schedule from structured events in
 * given node.
 * @param $variables
 * @return string
 */
function theme_uhc_event_structured_teaching_schedule(&$variables) {
  $title = $variables['title'];
  $content = $variables['prefix'];
  $node = $variables['node'];

  // Generate content out from JSON
  $field_imp_events_json = field_get_items('node', $node, 'field_imp_events_json');
  if (!empty($field_imp_events_json[0]['value'])) {
    $events = json_decode($field_imp_events_json[0]['value']);
    if (json_last_error() == JSON_ERROR_NONE) {

      $events = _uhc_event_structured_teaching_schedule_aggregate($events);
      $has_optime_extra_information = _uhc_event_has_optime_extra_information($events);
      $event_column_class = $has_optime_extra_information ? 'event-column' : 'event-column-initial-width';

      // Table header.
      $content .= '<span class="event-list-header">';
      $content .= '<span class="event-column"><span class="field accordion-content-item--label event-date">' . t('Date') . '</span><span class="field accordion-content-item--label event-time">' . t('Time') . '</span></span>';
      $content .= '<span class="event-column"><span class="field remove-styles accordion-content-item--label event-location">' . t('Location', array(), array('context' => 'event')) . '</span></span>';

      if ($has_optime_extra_information) {
        $content .= '<span class="event-column"><span class="field remove-styles accordion-content-item--label event-optime-extras">' . t('Info', array(), array('context' => 'event')) . '</span></span>';
      }

      $content .= '</span>';

      // Table contents.
      foreach ($events as $event) {
        $content .= '<div class="event">';
        $content .= '<div class="event-column"><div class="field event-date">' . $event['date'] . '</div><div class="field event-time">' . $event['time'] . '</div></div>';
        $content .= '<div class="' . $event_column_class . '"><div class="field remove-styles event-location">' . theme('item_list', array('items' => $event['locations'])) . '</div></div>';

        if ($has_optime_extra_information) {
          $staff_notes = !empty($event['optime_extra_information']->staffNotes) ? $event['optime_extra_information']->staffNotes : '';
          $room_notes = !empty($event['optime_extra_information']->roomNotes) ? $event['optime_extra_information']->roomNotes : '';
          $other_notes = !empty($event['optime_extra_information']->otherNotes) ? $event['optime_extra_information']->otherNotes : '';

          $content .= '<div class="event-column"><div class="field remove-styles event-optime-extras">'
            . '<span class="event-optime-extras-staff-notes">' . $staff_notes . '</span>'
            . '<span class="event-optime-extras-room-notes">' . $room_notes . '</span>'
            . '<span class="event-optime-extras-other-notes">' . $other_notes . '</span>'
            . '</div></div>';
        }

        $content .= '</div>';
      }

      $content .= $variables['suffix'];

      return $title . $content;
    }
  }
  return '';
}

function _uhc_event_has_optime_extra_information($events) {
  foreach ($events as $event) {
    if (!empty($event['optime_extra_information']->staffNotes)
      || !empty($event['optime_extra_information']->roomNotes)
      || !empty($event['optime_extra_information']->otherNotes)) {
      return TRUE;
    }
  }

  return FALSE;
}

/**
 * Aggregate all events by grouping them by date and time.
 *
 * @param array $events
 * @return array
 */
function _uhc_event_structured_teaching_schedule_aggregate($events) {
  $aggregated_events = array();

  foreach ($events as $event) {

    // JSON events datetimes are provided as Zulu timezone but we want to
    // convert them to local timezone.
    $from_timezone = new DateTimeZone('Etc/Zulu');
    $to_timzone = new DateTimeZone('Europe/Helsinki');

    // Create date objects out from start/end dates
    $begin_date = new DateTime($event->start_date, $from_timezone);
    $begin_date->setTimezone($to_timzone);

    $date = format_date($begin_date->getTimestamp(), 'custom', 'D j.n.Y');
    $time = $begin_date->format('H:i');
    if ($event->event_duration > 0) {
      $end_date = new DateTime($event->start_date, $from_timezone);
      $end_date->setTimezone($to_timzone);
      $end_date->modify('+' . $event->event_duration . ' minutes');
      $time = $begin_date->format('H:i') . ' - ' . $end_date->format('H:i');
    }

    // Location is an combination of building name and street address link
    $location = '';
    if (!empty($event->room_name_short)) {
      $location = check_plain($event->room_name_short);
    }

    // Build the maps link
    if (!empty($event->building_address1)) {
      $path = 'https://www.google.fi/maps/place/' . $event->building_address1;
      if (!empty($event->building_zipcode)) {
        $path .= ', ' . $event->building_zipcode;
      }
      $location .= ', ' . l($event->building_address1, $path);
    }

    // Build Optime extra information.
    $optime_extra_information = '';
    if (!empty($event->optimeExtras)) {
      $optime_extra_information = $event->optimeExtras;
    }

    // Append item.
    $key = sprintf('%sT%s', $date, $time);
    $aggregated_events[$key]['date'] = $date;
    $aggregated_events[$key]['time'] = $time;
    $aggregated_events[$key]['locations'][] = $location;
    $aggregated_events[$key]['optime_extra_information'] = $optime_extra_information;
  }

  return $aggregated_events;
}

/**
 * Default preprocessing callback for structured schedule.
 *
 * @param $variables
 */
function template_preprocess_uhc_event_unstructured_teaching_schedule(&$variables) {
  $variables['title'] = '';
  $variables['prefix'] = '<div>';
  $variables['suffix'] = '</div>';

  // Set title and prefix
  if(uhc_event_has_events_from_both_sources($variables['node'])) {
    $variables['title'] = '<h2 class="accordion-item__light ds-teaser-accordion--title">' . t('Teaching schedule') . '</h2>';
    $variables['prefix'] = '<div class="event-list table-three-columns field-group-accordion-item">';
  }
  else {
    $variables['prefix'] = '<div class="event-list table-three-columns tube--large">';
  }
}

/**
 * Default callback for rendering teaching schedule from unstructured events in
 * given node.
 * @param $variables
 * @return string
 */
function theme_uhc_event_unstructured_teaching_schedule(&$variables) {
  $node = $variables['node'];
  if ($node) {
    $title = $variables['title'];
    $content = $variables['prefix'];
    $field_imp_events_raw = field_get_items('node', $node, 'field_imp_events_raw');
    if (!empty($field_imp_events_raw[0]['safe_value'])) {
      $content .= $field_imp_events_raw[0]['safe_value'];
      $content .= $variables['suffix'];
    }
    return $title . $content;
  }
  return '';
}
