<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class UHCGradesController {

  /** @var UHCGradesService  */
  private $uhcGradesService;

  /**
   * @param $uhcGradesService UHCGradesService
   */
  public function __construct(UHCGradesService $uhcGradesService) {
    $this->uhcGradesService = $uhcGradesService;
  }

  /**
   * Gets grades regarding the given realisation identified by ID.
   *
   * @param $realisationId int Realisation ID.
   * @return object Response object (@see drupal_http_request()).
   */
  public function get($realisationId) {
    return $this->uhcGradesService->get($realisationId);
  }
}
