<?php

module_load_include('inc', 'uhc_taxonomy_source', 'migrate/TaxonomyTermMigration');

class TaxonomyTypeOfTeachingTermMigration extends TaxonomyTermMigration {

  function __construct() {
    $list_url = variable_get('uhc_taxonomy_source_taxonomy_type_of_teaching_term_source_url', '');
    $list_url = PortalMigrationBase::prependHostIfMissing($list_url);
    parent::__construct($list_url, 'type_code', 'type_of_teaching', 'description');
  }

}
