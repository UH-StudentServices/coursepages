<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

module_load_include('inc', 'uhc_taxonomy_source', 'migrate/TaxonomyTermMigration');

class TaxonomyFormOfTeachingTermMigration extends TaxonomyTermMigration {

  function __construct($arguments = array()) {
    $list_url = variable_get('uhc_taxonomy_source_taxonomy_form_of_teaching_term_source_url', '');
    $list_url = PortalMigrationBase::prependHostIfMissing($list_url);
    parent::__construct($arguments, $list_url, 'code', 'method_of_study');
  }

}
