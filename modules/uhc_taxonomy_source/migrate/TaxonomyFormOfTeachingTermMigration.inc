<?php

module_load_include('inc', 'uhc_taxonomy_source', 'migrate/TaxonomyTermMigration');

class TaxonomyFormOfTeachingTermMigration extends TaxonomyTermMigration {

  function __construct() {
    $list_url = variable_get('uhc_taxonomy_source_taxonomy_form_of_teaching_term_source_url', '');
    $list_url = PortalMigrationBase::prependHostIfMissing($list_url);
    parent::__construct($list_url, 'code', 'method_of_study');
  }

}
