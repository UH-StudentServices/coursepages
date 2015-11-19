<?php

class UHCDrupalFieldMapperEvent {

  protected $source;
  protected $destination;
  protected $event_name;

  /**
   * Constructor, just sets sets properties and declares mapping.
   *
   * @param $source
   * @param $destination
   * @param $event_name
   */
  public function __construct($source, $destination, $event_name = NULL) {
    $this->source = $source;
    $this->destination = $destination;
    $this->event_name = $event_name;
  }

  /**
   * Mapping magic happens here.
   */
  public function map() {
    $source = $this->source;
    $destination = $this->destination;

    // Preprocess start and end date
    $date_format = 'Y-m-d H:i:s';
    $start_date = date($date_format, strtotime($source->start_date));
    $end_date = date($date_format, strtotime($source->end_date));

    // If we don't have given event name, we generate one
    if (!is_string($this->event_name)) {
      // Default name would be "2015-01-01 @ C130, C-talo Latokartanonkaari 5,
      // 1.kerros"
      $this->event_name = $start_date . ' @ ' . $source->locations_abbreviated;
    }
    $destination->title = $this->event_name;

    // Calculate duration
    $begin_date = new DateTime($start_date);
    $end_date = new DateTime($end_date);
    $diff = $begin_date->diff($end_date);
    // @todo: We may use $source->event_duration now?
    $duration = $diff->format('%H:%I');

    if (!empty($start_date)) {
      $destination->field_event_begin_date  = array(LANGUAGE_NONE => array(array('value' => $start_date)));
    }
    if (!empty($duration)) {
      $destination->field_event_duration    = array(LANGUAGE_NONE => array(array('value' => $duration)));
    }
    if (!empty($source->locations_abbreviated)) {
      $destination->field_event_loc_name    = array(LANGUAGE_NONE => array(array('value' => $source->locations_abbreviated)));
    }
    $destination->field_event_location = array(
      LANGUAGE_NONE => array(
        array(
          'name' => !empty($source->locations_abbreviated) ? $source->locations_abbreviated : NULL,
          'street' => !empty($source->building_address1) ? $source->building_address1 : NULL,
          'postal_code' => !empty($source->building_zipcode) ? $source->building_zipcode : NULL,
          'country' => !empty($source->building_country) ? $source->building_country : 'FI',
        ),
      )
    );
    return $destination;
  }

}
