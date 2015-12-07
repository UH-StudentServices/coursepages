<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

class TaxonomyMigrateDestinationTerm extends MigrateDestinationTerm {
  /**
   * Prepare entity by setting up translations.
   *
   * @param $entity
   * @param stdClass $source_row
   */
  public function prepare($entity, stdClass $source_row) {
    parent::prepare($entity, $source_row);

    $entity->language = 'en'; // default

    // TODO: Use translation handlers instead, see how
    // PortalDestinationNode::prepare() creates translation and how
    // PortalDestinationNode::complete() saves the translations

    // Let field translation know that we have translations from english to
    // finnish.
    $entity_id = isset($entity->nid) ? $entity->nid : 0;
    $entity->translations = (object) array(
      'original' => 'en',
      'data' => array(
        'fi' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => $entity_id,
          'language' => 'fi',
          'source' => 'en',
          'uid' => '0',
          'status' => '1',
          'translate' => '0',
        ),
        'sv' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => $entity_id,
          'language' => 'sv',
          'source' => 'en',
          'uid' => '1',
          'status' => '1',
          'translate' => '0',
        ),
        'en' => array(
          'entity_type' => 'taxonomy_term',
          'entity_id' => $entity_id,
          'language' => 'en',
          'source' => '',
          'uid' => '1',
          'status' => '1',
          'translate' => '0',
        ),
      ),
    );

  }
}
