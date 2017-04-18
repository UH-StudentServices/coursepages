<?php
/**
 * @file
 * uhc_studies.features.user_permission.inc
 */

/**
 * Implements hook_user_default_permissions().
 */
function uhc_studies_user_default_permissions() {
  $permissions = array();

  // Exported permission: 'create studies content'.
  $permissions['create studies content'] = array(
    'name' => 'create studies content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'open university editor' => 'open university editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'create studies_landing_page content'.
  $permissions['create studies_landing_page content'] = array(
    'name' => 'create studies_landing_page content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any studies content'.
  $permissions['delete any studies content'] = array(
    'name' => 'delete any studies content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'open university editor' => 'open university editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete any studies_landing_page content'.
  $permissions['delete any studies_landing_page content'] = array(
    'name' => 'delete any studies_landing_page content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own studies content'.
  $permissions['delete own studies content'] = array(
    'name' => 'delete own studies content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'open university editor' => 'open university editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'delete own studies_landing_page content'.
  $permissions['delete own studies_landing_page content'] = array(
    'name' => 'delete own studies_landing_page content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any studies content'.
  $permissions['edit any studies content'] = array(
    'name' => 'edit any studies content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'open university editor' => 'open university editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit any studies_landing_page content'.
  $permissions['edit any studies_landing_page content'] = array(
    'name' => 'edit any studies_landing_page content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own studies content'.
  $permissions['edit own studies content'] = array(
    'name' => 'edit own studies content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'open university editor' => 'open university editor',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit own studies_landing_page content'.
  $permissions['edit own studies_landing_page content'] = array(
    'name' => 'edit own studies_landing_page content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'node',
  );

  // Exported permission: 'edit studies_landing_page URL alias'.
  $permissions['edit studies_landing_page URL alias'] = array(
    'name' => 'edit studies_landing_page URL alias',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'url_alias_permissions',
  );

  // Exported permission: 'override studies published option'.
  $permissions['override studies published option'] = array(
    'name' => 'override studies published option',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'open university editor' => 'open university editor',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'override studies_landing_page published option'.
  $permissions['override studies_landing_page published option'] = array(
    'name' => 'override studies_landing_page published option',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'override_node_options',
  );

  // Exported permission: 'view any unpublished studies content'.
  $permissions['view any unpublished studies content'] = array(
    'name' => 'view any unpublished studies content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
      'open university editor' => 'open university editor',
    ),
    'module' => 'view_unpublished',
  );

  // Exported permission: 'view any unpublished studies_landing_page content'.
  $permissions['view any unpublished studies_landing_page content'] = array(
    'name' => 'view any unpublished studies_landing_page content',
    'roles' => array(
      'editor-in-chief of communications' => 'editor-in-chief of communications',
    ),
    'module' => 'view_unpublished',
  );

  return $permissions;
}
