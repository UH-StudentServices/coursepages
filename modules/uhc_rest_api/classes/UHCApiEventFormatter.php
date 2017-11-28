<?php

class UHCApiEventFormatter {

  const DATE_TIME_FORMAT = 'Y-m-d\TH:i:s\Z';

  public function format($eventNode) {
    $event = new stdClass();
    $eventNodeWrapper = entity_metadata_wrapper('node', $eventNode);
    $event->begin = $this->getBegin($eventNodeWrapper);
    $event->end = $this->getEnd($eventNodeWrapper);
    $event->exam = $this->isExam($eventNodeWrapper);
    $event->title = $eventNodeWrapper->label();
    $event->where = $this->getWhere($eventNodeWrapper);

    return $event;
  }

  private function getBegin($eventNodeWrapper) {
    $beginDateTimestamp = $eventNodeWrapper->field_event_begin_date->value();

    return !is_null($beginDateTimestamp) ? $this->formatTimestamp($beginDateTimestamp) : NULL;
  }

  private function getEnd($eventNodeWrapper) {
    $duration = $eventNodeWrapper->field_event_duration->value();
    if (is_null($duration)) {
      // If no duration has been set, we return NULL as end value.
      return NULL;
    }
    $durationParts = explode(':', $duration);
    $durationHours = $durationParts[0];
    $durationMinutes = $durationParts[1];
    $beginDateTimestamp = $eventNodeWrapper->field_event_begin_date->value();
    if (is_null($beginDateTimestamp)) {
      // If no begin date given, we return NULL as end value.
      return NULL;
    }
    $beginDateTime = new DateTime();
    $beginDateTime->setTimestamp($beginDateTimestamp);
    $modify = "+ $durationHours hours $durationMinutes minutes";
    $endDateTime = $beginDateTime->modify($modify);

    return $this->formatTimestamp($endDateTime->getTimestamp());
  }

  private function getWhere($eventNodeWrapper) {
    return $eventNodeWrapper->field_event_loc_name->value();
  }

  private function isExam($eventNodeWrapper) {
    return $eventNodeWrapper->field_event_is_exam->value();
  }

  private function formatTimestamp($timestamp) {
    return gmdate(self::DATE_TIME_FORMAT, $timestamp);
  }
}
