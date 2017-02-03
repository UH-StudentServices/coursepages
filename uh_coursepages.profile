<?php
/**
 * @file
 * Enables modules and site configuration for a helsinki university portal site
 * installation.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */

/**
 * Implements hook_form_FORM_ID_alter().
 */
function uh_coursepages_form_install_configure_form_alter(&$form, $form_state) {
  // Pre-populate the site name with the server name.
  $form['site_information']['site_name']['#default_value'] = "University of Helsinki Coursepages";
  $form['site_information']['site_mail']['#default_value'] = "admin@example.com";
  $form['admin_account']['account']['name']['#default_value'] = "admin";
  $form['admin_account']['account']['mail']['#default_value'] = $form['site_information']['site_mail']['#default_value'];
  $form['server_settings']['site_default_country']['#default_value'] = "FI";
}

/**
 * Implements hook_install_tasks().
 */
function uh_coursepages_install_tasks() {
  return array(

    // Add batch process installing selected additional languages.
    'uh_coursepages_import_translations' => array(
      'display_name' => st('Import translations'),
      'type' => 'batch',
    ),

    // Import content
    'import_content' => array(
      'display_name' => st('Import content'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'function' => 'uh_coursepages_migrate_batch',
    ),

    // Apply configurations
    'apply_configurations' => array(
      'display_name' => st('Apply configuration'),
      'display' => TRUE,
      'type' => 'batch',
      'run' => INSTALL_TASK_RUN_IF_NOT_COMPLETED,
      'function' => 'uh_coursepages_apply_configuration',
    ),

  );
}

/**
 * Callback for adding languages and importing translations.
 */
function uh_coursepages_import_translations() {

  // Ensure we have everytyig we need
  include_once DRUPAL_ROOT . '/includes/locale.inc';
  module_load_include('check.inc', 'l10n_update');
  module_load_include('batch.inc', 'l10n_update');

  // TODO: You may optionally make this configurable through install task form
  $translations = array(
    'fi' => array(FALSE, 'fi'),
    'sv' => array(FALSE, 'sv'),
  );

  // Prepare batch process to enable languages and download translations.
  $operations = array();
  foreach ($translations as $translation => $params) {
    list($default, $prefix) = $params;
    locale_add_language($translation, NULL, NULL, LANGUAGE_LTR, '', $prefix, TRUE, $default);

    // Build batch with l10n_update module.
    $history = l10n_update_get_history();
    $available = l10n_update_available_releases();
    $updates = l10n_update_build_updates($history, $available);

    $operations = array_merge($operations, _l10n_update_prepare_updates($updates, NULL, array()));
  }

  // Translate strings to finnish
  variable_set('i18n_string_translate_langcode_fi', TRUE);

  $batch = l10n_update_batch_multiple($operations, LOCALE_IMPORT_KEEP);

  // Set the default language
  $langs = language_list();
  $langcode = 'en';
  variable_set('language_default', $langs[$langcode]);

  return $batch;

}

/**
 * Callback for installation task of importing content.
 */
function uh_coursepages_migrate_batch() {
  $operations = array();

  // Run all available migrations.
  $migrations = migrate_migrations();
  foreach ($migrations as $machine_name => $migration) {
    $operations[] = array('_uh_coursepages_import', array($machine_name, t('Importing content.')));
  }

  $batch = array(
    'title' => t('Importing content'),
    'operations' => $operations,
  );

  return $batch;
}

/**
 * Callback operation for importing a migration in a batch.
 */
function _uh_coursepages_import($operation, $type, &$context) {

  $context['message'] = t('@operation', array('@operation' => $type));
  $migration =  Migration::getInstance($operation);
  $migration->processImport();
}

/**
 * Callback for finalizing configuration after installations, translations and
 * imports.
 */
function uh_coursepages_apply_configuration() {

  // Configure Image toolkit. WYSIWYG requires ImageMagick which makes whole
  // Drupal use that instead, which we dont' want to because we have version of
  // ImageMagick which causes issues with scandinavian characters. See DOO-117.
  variable_set('image_toolkit', 'gd');

  // Create a default role for site administrators, with all available permissions assigned.
  $admin_role = new stdClass();
  $admin_role->name = 'administrator';
  $admin_role->weight = 2;
  user_role_save($admin_role);
  user_role_grant_permissions($admin_role->rid, array_keys(module_invoke_all('permission')));
  // Set this as the administrator role.
  variable_set('user_admin_role', $admin_role->rid);

  // Assign user 1 the "administrator" role.
  db_insert('users_roles')
    ->fields(array('uid' => 1, 'rid' => $admin_role->rid))
    ->execute();

  // Create a editor-in-chief of communications role
  $editor_role = new stdClass();
  $editor_role->name = 'editor-in-chief of communications';
  $editor_role->weight = 3;
  user_role_save($editor_role);

  // Grant permissions for editors to view the administration theme
  user_role_grant_permissions($editor_role->rid, array('view the administration theme'));

  // Revert features
  features_revert(array('hy_course_implementation' => array('user_permission')));
  features_revert(array('hy_search_portal_feature' => array('search_api_server', 'search_api_index')));
  features_revert(array('hy_portal_content_administration_feature' => array('user_permission')));

  // Clear caches
  cache_clear_all();

}

/**
 * Implements hook_menu().
 *
 * Adds external home links for students and teachers in og-menu-single menu.
 */
function uh_coursepages_menu() {
  $items["student"] = array(
    'menu_name' => 'og-menu-single',
    'type' => MENU_NORMAL_ITEM,
    'title' => 'Home',
    'access callback' => 'uh_coursepages_student_menu_item_access',
    'page callback' => 'drupal_goto',
    'page arguments' => array(variable_get('uhc_student_home_url', 'https://student.helsinki.fi/opintoni')),
    'options' => array('attributes' => array('class' => 'home-link')),
    'weight' => -50
  );

  $items["teacher"] = array(
    'menu_name' => 'og-menu-single',
    'type' => MENU_NORMAL_ITEM,
    'title' => 'Home',
    'access callback' => 'uh_coursepages_teacher_menu_item_access',
    'page callback' => 'drupal_goto',
    'page arguments' => array(variable_get('uhc_teacher_home_url', 'https://teacher.helsinki.fi/opetukseni')),
    'options' => array('attributes' => array('class' => 'home-link')),
    'weight' => -49
  );

  return $items;
}

/**
 * @return bool TRUE if the user has access to student menu item, otherwise FALSE.
 */
function uh_coursepages_student_menu_item_access() {
  return uh_coursepages_user_has_role('administrator') || !uh_coursepages_user_has_role('teacher');
}

/**
 * @return bool TRUE if the user has access to teacher menu item, otherwise FALSE.
 */
function uh_coursepages_teacher_menu_item_access() {
  return uh_coursepages_user_has_role('administrator') || uh_coursepages_user_has_role('teacher');
}

/**
 * @param $role string Role name.
 * @return bool TRUE if the user has the given role, otherwise FALSE.
 */
function uh_coursepages_user_has_role($role) {
  return in_array($role, array_values($GLOBALS['user']->roles));
}

/**
 * Implements hook_menu_alter().
 */
function uh_coursepages_menu_alter(&$items) {
  $items['node/add/course']['access callback'] = 'user_access';
  $items['node/add/course']['access arguments'] = array('administer content');
}

/**
 * Implements hook_form_FORM_ID_alter().
 *
 * Tweaks the node edit form. There are some fields that are allowed to be
 * edited from existing content by editors...
 */
function uh_coursepages_form_course_implementation_node_form_alter(&$form, &$form_state) {
  // Title is handled by migrate/integration
  $form['title_field']['#access'] = user_access('administer content');
  // Translations and deletions are handled by migrate/integration
  $form['actions']['delete_translation']['#access'] = FALSE;
}

/**
 * Helper function for determine are we currently in the node page of given
 * $node object.
 *
 * @param $node
 * @param $view_mode
 * @return bool
 */
function uh_coursepages_is_node_page($node, $view_mode) {
  // View mode must be full and node page URL should be as expected with nodes.
  if ($view_mode == 'full') {
    $url_args = arg();
    return $url_args[0] == 'node' && $url_args[1] == $node->nid;
  }
  return FALSE;
}

/**
 * Implements hook_uh_coursepages_staff_roles().
 */
function uh_coursepages_uh_coursepages_staff_roles() {
  $staff_roles[] = user_role_load_by_name('editor-in-chief of communications')->rid;
  $staff_roles[] = user_role_load_by_name('administrator')->rid;
  return $staff_roles;
}

/**
 * Helper function for determining whether account belongs to staff role.
 */
function uh_coursepages_has_staff_role() {
  $rids = module_invoke_all('uh_coursepages_staff_roles');
  foreach ($rids as $rid) {
    if (user_has_role($rid)) {
      return TRUE;
    }
  }
  return FALSE;
}

/**
 * Implements hook_username_alter().
 *
 * HY Shibboleth Metadata fetches real name information for us, but it does not
 * take care of showing it as display name. Lets do it here.
 */
function uh_coursepages_username_alter(&$name, $account) {
  // Load the user account just in case if it doesn't pass it fully loaded.
  if (isset($account->uid)) {
    $user = user_load($account->uid);
    // Display the user's uid instead of name.
    if (isset($user->field_user_real_name[LANGUAGE_NONE][0]['value'])) {
      $name = $user->field_user_real_name[LANGUAGE_NONE][0]['value'];
    }
  }
}

/**
 * This mimics drupal_set_message, except that it doesn't kill cachability
 */
function uh_coursepages_set_message($message = NULL, $type = 'status', $repeat = TRUE) {
  if ($message) {
    if (!isset($_SESSION ['messages'][$type])) {
      $_SESSION ['messages'][$type] = array();
    }

    if ($repeat || !in_array($message, $_SESSION ['messages'][$type])) {
      $_SESSION ['messages'][$type][] = $message;
    }
  }

  // Messages not set when DB connection fails.
  return isset($_SESSION ['messages']) ? $_SESSION ['messages'] : NULL;
}

/**
 * Create Multilingual taxonomy terms
 */
function uh_coursepages_create_terms($terms, $vocabulary_name) {
  $vocabulary = taxonomy_vocabulary_machine_name_load($vocabulary_name);

  // add terms
  foreach ($terms as $term) {
    $term = (object) array(
      'name' => $term['en'],
      'weight' =>  $term['weight'] ?: 1,
      'vid' => $vocabulary->vid,
    );
    taxonomy_term_save($term);
  }

  $languages = language_list();
  $terms_source_language = taxonomy_get_tree($vocabulary->vid);

  // add translations
  foreach ($terms_source_language as $term_source_language) {
    $termloaded = taxonomy_term_load($term_source_language->tid);
    foreach ($terms as $term) {
      if ($term['en'] == $termloaded->name) {
        foreach ($languages as $language) {
          if ($language->language != 'en') {

            $handler = entity_translation_get_handler('taxonomy_term', $termloaded, TRUE);
            $values['name_field'][$language->language]['0']['value'] = $term[$language->language];

            $translation = array(
              'translate' => 0,
              'status' => 1,
              'language' => $language->language,
              'source' => 'en',
            );

            $handler->setTranslation($translation, $values);
            taxonomy_term_save($termloaded);
          }
        }
      }
    }
  }
}

/**
 * Setup variables
 */
function uh_coursepages_setup_variables() {

  // Configure multilinguality
  variable_set('l10n_update_download_store', 'profiles/uh_coursepages/translations');

  // footer contact block content
  $hy_contact_config = array(
    'uhc_contact_logo_block_form_content' => array(
      'en' => array(
        'value' => '<div class="logo-block">
      <div class="logo-block__logo">
        <a class="logo theme-big" href="https://www.helsinki.fi/en"></a>
      </div>
      <div class="logo-block__content">
        <h4>University of Helsinki</h4>
        <p>P.O. Box 3 (Fabianinkatu 33)<br>00014 University of Helsinki</p>
        <p>Switchboard: <a class="is-tel" href="tel:+3582941911">+358 (0) 2941 911</a></p>
      </div></div>',
        'format' => 'filtered_html',
      ),
      'fi' => array(
        'value' => '<div class="logo-block">
      <div class="logo-block__logo">
        <a class="logo theme-big" href="https://www.helsinki.fi/fi"></a>
      </div>
      <div class="logo-block__content">
        <h4>Helsingin Yliopisto</h4>
        <p>PL 3 (Fabianinkatu 33)<br>00014 Helsingin yliopisto</p>
        <p>Puhelinvaihde: <a class="is-tel" href="tel:+3582941911">+358 (0) 2941 911</a></p>
      </div></div>',
        'format' => 'filtered_html',
      ),
      'sv' => array(
        'value' => '<div class="logo-block">
      <div class="logo-block__logo">
        <a class="logo theme-big" href="https://www.helsinki.fi/sv"></a>
      </div>
      <div class="logo-block__content">
        <h4>Helsingfors universitet</h4>
        <p>PB 3 (Fabiansgatan 33)<br>00014 Helsingfors universitet</p>
        <p>Växel: <a class="is-tel" href="tel:+3582941911">+358 (0) 2941 911</a></p>
      </div></div>',
        'format' => 'filtered_html',
      )
    ),
  );
  foreach ($hy_contact_config as $name => $languages) {
    foreach ($languages as $lang => $value) {
      variable_realm_set('language', $lang, $name, $value);
    }
  }
}

/**
 * Implements hook_block_info().
 */
function uh_coursepages_block_info() {
  $blocks = array();
  $blocks['uhc_logo_block'] = array(
    'info' => t('UHC Logo Block'),
  );
  $blocks['uhc_contact_logo_block'] = array(
    'info' => t('HY Logo block with contact information'),
  );
  return $blocks;
}

/**
 * Implements hook_block_view().
 */
function uh_coursepages_block_view($delta = '') {
  $block = array();

  switch ($delta) {
    case 'uhc_logo_block':
      $contexts = context_active_contexts();
      $open_university_home_paths = array(
        'fi' => 'fi/avoin-yliopisto',
        'en' => 'en/open-university',
        'sv' => 'sv/oppna-universitetet'
      );
      global $language;

      // Open university
      if (array_key_exists('open_university_header_and_footer', $contexts) && isset($open_university_home_paths[$language->language])) {
        $href = 'https://www.helsinki.fi/' . $open_university_home_paths[$language->language];
        $text = t("Open University");
      }
      else {
        $href = 'https://www.helsinki.fi/' . check_plain($language->language);
        $text = t('University of Helsinki');
      }
      $block['content'] = '<a class="logo" href="' . $href . '">
        <h1 class="logo__sitename">' . $text . '</h2>
        </a>';
      $block['css_class'] = 'logo-block';
      break;

    case 'uhc_contact_logo_block':
      // Markup for footer contact logo block
      $title = uh_coursepages_contact_data('title', $delta);
      $block['subject_array'] = $title;
      $block['subject'] = reset($title);
      $block['content'] = uh_coursepages_contact_data('content', $delta);
      $block['css_class'] = uh_coursepages_contact_data('css_class', $delta);
      break;
  }
  return $block;
}

/**
 * Implements hook_block_view_alter().
 *
 * When we make a block with hook_block_view(), the subject won't transfer to
 * block title by default. In a lot of different blocks we need want to use
 * <none> title to erase title from dom. Instead of making couple of extra steps
 * by applying block title to each block in their admin page; let's copy the
 * title (<none>) from configuration form to block settings.
 */
function uh_coursepages_block_view_alter(&$data, $block) {
  $block->title = (isset($data['subject'])) ? ($data['subject'] == '<none>') ? '<none>' : $block->title : '';
}

/**
 * Provides block content.
 * @return array
 *    A renderable, translated array containing the markup retrieved from the variable table
 */
function uh_coursepages_contact_data($field, $block) {
  global $language;
  $realm = 'language';
  $realm_key = $language->language;
  $content = array('#markup' => '');

  // Fetch either the title or the body from the variable table, depending on provided argument.
  switch ($field) {
    case 'title':
      $data = variable_store_get($realm, $realm_key, $block . '_form_title');
      $content = array('#markup' => $data);
      break;
    case 'content':
      $data = variable_store_get($realm, $realm_key, $block . '_form_content');
      // Create the renderable array.
      $content = array('#markup' => $data['value'], '#format' => $data['format']);
      break;
    case 'css_class':
      $content = variable_get($block . '_form_css_class', 'css-class');
      break;

  }
  return $content;
}

/**
 * Get value of given $field_name from given $node in language that has a
 * specified logic by DOO-1922 ticket.
 *
 * @param string $node
 * @param string $field_name
 * @return NULL|string
 * @see https://jira.it.helsinki.fi/browse/DOO-1922
 */
function uh_coursepages_render_field_value($node, $field_name) {
  // Ensure that we have given field available
  if (empty($node->{$field_name})) {
    return NULL;
  }

  // Resolve teaching languages and enabled languages
  $teaching_languages = _uhc_course_implementation_get_teaching_languages($node);
  $enabled_languages = array_values(locale_language_list('language'));

  // Calculate that in which order languages should be checked for value. Origin
  // of the logic is found in ticket description: DOO-1922
  $languages = array_merge(array(i18n_langcode()), $teaching_languages, $enabled_languages);
  $languages = array_unique($languages);

  // Loop languages array and return first hit
  foreach ($languages as $langcode) {
    $values = field_get_items('node', $node, $field_name, $langcode);
    // If values found, then render and return
    if (!empty($values[0])) {
      $value = field_view_value('node', $node, $field_name, $values[0]);
      return render($value);
    }
  }
  return NULL;
}

/**
 * Helper function for renaming fields by migrating its values without
 * triggering whole entity save process (and its hooks). Very efficient and
 * works with fields that have no hacky structures.
 *
 * @param $deprecated_field_name
 * @param $new_field_name
 * @return bool
 */
function uh_field_migrate_values($deprecated_field_name, $new_field_name) {

  // Ensure that we find the field information we need
  $deprecated_field_info = field_info_field($deprecated_field_name);
  if (is_null($deprecated_field_info)) {
    watchdog('uh_coursepages', 'Could not gather field information for field @field_name', array('@field_name' => $deprecated_field_name), WATCHDOG_ERROR);
    return FALSE;
  }
  $new_field_info = field_info_field($new_field_name);
  if (is_null($new_field_info)) {
    watchdog('uh_coursepages', 'Could not gather field information for field @field_name', array('@field_name' => $new_field_name), WATCHDOG_ERROR);
    return FALSE;
  }

  // Gather columns and ensure that they match.
  $deprecated_columns = $deprecated_field_info['columns'];
  $new_columns = $deprecated_field_info['columns'];
  if ($deprecated_columns != $new_columns) {
    watchdog('uh_coursepages', 'Columns of fields did not match!', array(), WATCHDOG_ERROR);
    return FALSE;
  }

  // Ensure field storage types
  if ($deprecated_field_info['storage']['type'] != 'field_sql_storage' || !isset($deprecated_field_info['storage']['details']['sql'])) {
    watchdog('uh_coursepages', 'Unsupported field storage type @field_storage_type for deprecated field', array('@field_storage_type' => $deprecated_field_info['storage']['type']), WATCHDOG_ERROR);
    return FALSE;
  }
  if ($new_field_info['storage']['type'] != 'field_sql_storage' || !isset($new_field_info['storage']['details']['sql'])) {
    watchdog('uh_coursepages', 'Unsupported field storage type @field_storage_type for new field', array('@field_storage_type' => $new_field_info['storage']['type']), WATCHDOG_ERROR);
    return FALSE;
  }

  // Now we trust that fields are compatible for SQL migration. Column value
  // migration should work for fields that:
  //   - have no funky alterations to field info structure
  //   - have hacks messing up with field column or revision table naming
  //   - have multiple tables for storing field value
  //   - have no equal columns for current and revision tables
  // ...so it's not fully compatible with everything, but for most cases.
  $columns = array_keys(reset($deprecated_field_info['storage']['details']['sql'][FIELD_LOAD_CURRENT]));
  $source_columns = array();
  $dest_columns = array();
  foreach($columns as $key => $value) {
    $source_columns[] = $deprecated_field_name . '_' . $value;
    $dest_columns[] = $new_field_name . '_' . $value;
  }

  // Specify sql table entity property fields that are in all field tables.
  $default_entity_property_fields = array('entity_type', 'bundle', 'deleted', 'entity_id', 'revision_id', 'language', 'delta');
  $source_fields = array_merge($default_entity_property_fields, $source_columns);
  $destination_fields = array_merge($default_entity_property_fields, $dest_columns);

  // Data table
  $data_query = db_select('field_data_' . $deprecated_field_name, 't')->fields('t', $source_fields)->execute();
  $insert_data_query = db_insert('field_data_' . $new_field_name);
  while ($item = $data_query->fetchAssoc()) {
    $insert_data_query->fields($destination_fields)->values(array_values($item));
  }
  $data_result = $insert_data_query->execute();

  // Revision table
  $revision_query = db_select('field_revision_' . $deprecated_field_name, 't')->fields('t', $source_fields)->execute();
  $insert_revision_query = db_insert('field_revision_' . $new_field_name);
  while ($item = $revision_query->fetchAssoc()) {
    $insert_revision_query->fields($destination_fields)->values(array_values($item));
  }
  $revision_result = $insert_revision_query->execute();

  // Clear field caches
  field_cache_clear();

  return $data_result && $revision_result;
}

/**
 * Gets the $node object that is used in system ajax calls when editing nodes.
 *
 * @see ajax_form_callback()
 * @see ajax_get_form()
 */
function uh_coursepages_ajax_get_node() {
  $node = NULL;

  // Try to parse the AJAX request almost like it would be parsed in
  //ajax_form_callback() callback.
  $state_defaults = form_state_defaults();
  if (!empty($_POST['form_build_id']) && form_get_cache($_POST['form_build_id'], $state_defaults)) {
    list(, $form_state) = ajax_get_form();
    // We're interested in possible $node object that is used in the callback
    if (!empty($form_state['node'])) {
      $node = $form_state['node'];
    }
  }

  return $node;
}
