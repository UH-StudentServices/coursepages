<?php
/**
 * @file
 * Class implementation file for requesting Oodi through ESB/ActiveMQ.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCOodi extends UHCESB {

  /**
   * Requests an method from Oodi system.
   *
   * Known methods are reported by Hannu-Pekka Rajaniemi (05.06.2015):
   *   "doo.kurssisivu.course.changes.all”
   *     - headerit: since_date (ISO 8601 formaatti yyyy-mm-ddThh:mm:ss.000Z)
   *   "doo.kurssisivu.course.changes.ids”
   *     - headerit: since_date
   *   "doo.kurssisivu.course”
   *     - headerit: course_id jakso_code
   *
   * @param $method
   * @param $attributes
   * @return \FuseSource\Stomp\Frame
   */
  public function requestMethod($method, $attributes) {
    $properties = $attributes;
    $properties['method'] = 'doo.kurssisivu.' . $method;
    return $this->request($properties);
  }

}
