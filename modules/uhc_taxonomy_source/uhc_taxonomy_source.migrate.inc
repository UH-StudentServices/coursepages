<?php
/**
 * @file
 * Integrates with migrate module.
 */

/**
 * Implements hook_migrate_api().
 */
function uhc_taxonomy_source_migrate_api() {
  return array(
    'api' => 2,
    'migrations' => array(
      'TaxonomyTypeOfTeachingTerm' => array(
        'class_name' => 'TaxonomyTypeOfTeachingTermMigration',
      ),
      'TaxonomyFormOfTeachingTerm' => array(
        'class_name' => 'TaxonomyFormOfTeachingTermMigration',
      ),
    ),
  );
}
