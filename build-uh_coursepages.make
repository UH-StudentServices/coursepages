; Drush Make File
; ----------------

core = 7.0
api = 2

projects[drupal][type] = core
projects[drupal][version] = 7.56

; Patch: Text field (textarea) with "Default" formatter does not retain newlines
projects[drupal][patch][1152216] = https://www.drupal.org/files/text-plain-1152216-24.patch

defaults[projects][subdir] = "contrib"

; Contrib
; ----------------

projects[admin_menu][download][branch] = 7.x-3.x
projects[admin_menu][download][revision] = 67abd3a
projects[admin_menu][patch][1981308] = https://www.drupal.org/files/issues/admin_menu-js-module-compatibility-1981308-9.patch
projects[admin_menu][patch]["https://www.drupal.org/node/2502695"] = "https://www.drupal.org/files/issues/admin_menu-issetmapfix-2502695-3.patch"
projects[admin_views][version] = "1.6"
projects[advagg][version] = "2.19"
projects[behavior_weights][version] = "1.0"
projects[block_class][version] = "2.3"
projects[cache_warmer][version] = "4.1"
projects[cache_warmer][patch]["https://www.drupal.org/node/2448147"] = "https://www.drupal.org/files/issues/cache_warmer_call_to_undefined-2448147-2.patch"
projects[chosen][version] = "2.1"
projects[ckeditor][version] = "1.17"
projects[context][version] = "3.7"
projects[context_omega][version] = "1.1"
projects[ctools][version] = "1.12"
projects[date][version] = "2.9"
projects[diff][version] = "3.2"
projects[email][version] = "1.3"
projects[entity][version] = "1.8"
projects[entitycache][version] = "1.2"
projects[entity_translation][version] = "1.0-beta5"
projects[entity_translation][patch]["https://www.drupal.org/node/2777995"] = https://www.drupal.org/files/issues/entity-translation_title-overriding-fix-2777995-1_0.patch
projects[entityreference][version] = "1.5"
projects[entityreference][patch]["https://www.drupal.org/node/1368386"] = https://www.drupal.org/files/issues/entityreference-1368386-99.patch
projects[favoritewidget][download][type] = git
projects[favoritewidget][download][url] = http://git.drupal.org/project/favoritewidget.git
projects[favoritewidget][download][revision] = d4284050bf6e4664214459fbad3b2be0fa6f3cfb
projects[features][version] = "2.10"
projects[feedback][version] = "2.0-beta1"
projects[feedback][patch]["https://www.drupal.org/node/2545708"] = "https://www.drupal.org/files/issues/feedback-honeypot_0.patch"
projects[field_collection][download][type] = git
projects[field_collection][download][url] = http://git.drupal.org/project/field_collection.git
projects[field_collection][download][revision] = 280de245ccf15f297c7dbaa909407372d4a6f1ee
projects[field_collection_fieldset][version] = "2.6"
projects[field_formatter_settings][version] = "1.1"
projects[field_group][version] = "1.5"
projects[field_group][patch]["https://www.drupal.org/node/1482958"] = "https://www.drupal.org/files/issues/empty-config-1482958-27.patch"
projects[field_multiple_limit][version] = "1.0-alpha5"
projects[field_multiple_limit][patch]["https://www.drupal.org/node/2807079"] = "https://www.drupal.org/files/issues/Avoid_php_warnings-2807079-2.patch"
projects[field_permissions][version] = "1.0"
projects[filefield_paths][version] = "1.0"
projects[form_error_logging][version] = "1.0-rc1"

; Support for field mapping on migrate
projects[languagefield][version] = "1.3"
projects[languagefield][patch]["https://www.drupal.org/node/2217385"] = "https://www.drupal.org/files/issues/2217385-languagefield_migrate_handler-4.patch"

projects[google_analytics][version] = "2.3"
projects[google_analytics_et][version] = "1.3"
projects[google_analytics_et][patch]["remove console log"] = "http://cgit.drupalcode.org/google_analytics_et/patch/?id=89cdc6201ef844b07e4f8606c774f6e72002d040"
projects[google_analytics_reports][version] = "3.1"
projects[honeypot][version] = "1.22"
projects[i18n][version] = "1.13"
projects[imagemagick][version] = "1.0"
projects[joyride][version] = "1.0-alpha3"
projects[joyride][patch]["https://www.drupal.org/node/2411447"] = https://www.drupal.org/files/issues/joyride-makefile-core-and-api-version.diff
projects[l10n_update][version] = "1.1"
projects[libraries][version] = "2.3"
projects[link][version] = "1.4"
projects[linkit][version] = "3.5"
projects[location][version] = "3.7"
projects[logging_alerts][version] = "2.2"
projects[manualcrop][version] = "1.6"
projects[maxlength][version] = "3.2"
projects[memcache][version] = "1.5"
projects[mb][download][type] = git
projects[mb][download][url] = http://git.drupal.org/project/mb.git
projects[mb][download][revision] = cf380cf23801c41bc6a3712b0775483ab553c920
projects[menu_attributes][version] = "1.0"
projects[menu_block][version] = "2.7"
projects[migrate][version] = "2.8"
projects[module_filter][version] = "2.1"

projects[node_edit_protection][download][type] = git
projects[node_edit_protection][download][url] = http://git.drupal.org/project/node_edit_protection.git
; Latest dev commit from 2016-01-07 06:43:46 (GMT) since the stable is quite old.
projects[node_edit_protection][download][revision] = e17dc41f5891689c517b228391b56aa56d391d65

; OG is used for providing node/course specific permissions, patch is used for
; fixing issue where in some cases we end up with PDOException, see DOO-2175
projects[og][version] = "2.9"
projects[og][patch]["https://www.drupal.org/node/2272583"] = https://www.drupal.org/files/issues/og-roles_for_blocked_users-2272583-3.patch

projects[comment_og][version] = "1.0"
projects[pathauto][version] = "1.3"
; Patch: adds drush commands for deleting & updating aliases
projects[pathauto][patch]["https://www.drupal.org/node/867578"] = https://www.drupal.org/files/pathauto-add-drush-support-867578-42.patch

; Search

; drush make does not know where to place this by default
projects[search_api][version] = "1.20"
projects[search_api][subdir] = "contrib"
projects[search_api_autocomplete][version] = "1.4"
; Temporary fix for download not working for facetapi
; projects[facetapi][version] = "1.5"
projects[facetapi][download][type] = file
projects[facetapi][download][url] = http://ftp.drupal.org/files/projects/facetapi-7.x-1.5.tar.gz
projects[facetapi_bonus][download][type] = git
projects[facetapi_bonus][download][url] = git://git.drupal.org/project/facetapi_bonus.git
projects[facetapi_bonus][download][branch] = 7.x-1.x
projects[facetapi_bonus][download][revision] = 1f2e72012ee14bc0a63b2bd241067ecc184070c1
projects[facetapi_bonus][patch]["https://www.drupal.org/node/2056099"] = https://www.drupal.org/files/issues/facetapi_bonus-add_a_filter_plugin_to-2056099-16.patch
projects[facetapi_select][download][url] = http://git.drupal.org/project/facetapi_select.git
projects[facetapi_select][download][revision] = "c960e18"
projects[facetapi_pretty_paths][version] = "1.1"
projects[facetapi_taxonomy_sort][version] = "1.0-beta1"
projects[search_api_db][version] = "1.4"
projects[search_api_et][version] = "2.0-alpha7"
projects[search_api_solr][version] = "1.11"
projects[search_api_et_solr][download][type] = git
projects[search_api_et_solr][download][url] = http://git.drupal.org/project/search_api_et_solr.git
projects[search_api_et_solr][download][revision] = fb5e8a5

; Others

projects[shs][version] = "1.6"
; Patch: Prevent PHP fatal error. Not all terms have parents.
projects[shs][patch]["https://www.drupal.org/node/1960182"] = https://www.drupal.org/files/issues/checkifparentset-1960182-08-D7.patch

projects[smart_trim][version] = "1.5"
projects[special_menu_items][version] = "2.0"
projects[stringoverrides][version] = "1.8"
projects[strongarm][version] = "2.0"
projects[taxonomy_access_fix][version] = "2.3"
projects[timeago][version] = "2.3"
projects[title][version] = "1.0-alpha9"
projects[token][version] = "1.6"
projects[token][patch]["https://www.drupal.org/node/2474403"] = https://www.drupal.org/files/issues/token-field_description_overwritten-2474403-12-D7.patch
projects[url_alias_permissions][version] = "1.0"
projects[variable][version] = "2.5"
projects[varnish][version] = "1.4"
projects[views][version] = "3.17"
projects[views][patch]["https://www.drupal.org/node/477984"] = https://www.drupal.org/files/issues/views-n477984-95.patch
projects[views_bulk_operations][version] = "3.4"
projects[views_block_area][version] = "1.2"
projects[views_data_export][version] = "3.2"
projects[viewreference][version] = "3.5"
projects[view_unpublished][version] = "1.2"
projects[override_node_options][version] = "1.13"

projects[shib_auth][version] = 4.3
projects[shib_auth][patch]["https://www.drupal.org/node/2350239"] = https://www.drupal.org/files/issues/email_already_used-2350239-7.patch
projects[shib_auth][patch]["https://www.drupal.org/node/2389383"] = https://www.drupal.org/files/issues/2389383-shib-redirect.patch
projects[shib_auth][patch]["https://www.drupal.org/node/2416637"] = https://www.drupal.org/files/issues/shib_auth-bad_url-2416637-4.patch

; We need to be able to edit accounts with used email addresses while patched
; shibboleth module allows multiple accounts with shared emails.
projects[sharedemail][version] = 1.0

projects[inline_entity_form][version] = "1.8"

projects[pathologic][version] = 2.12

projects[embed_views][version] = 1.2

; Display suite
projects[ds][version] = "2.14"
projects[ds][subdir] = "contrib"
;# Patch for text in resilts view see: https://www.drupal.org/node/2345387
;projects[ds][patch][rename-total-results] = "https://www.drupal.org/files/issues/ds-rename_total_results_output-2345387-1.patch"

; Allows us to put comments into descending sorting (we do not use comment
; threading, so it should be safe).
projects[sort_comments][download][type] = git
projects[sort_comments][download][url] = http://git.drupal.org/project/sort_comments.git
projects[sort_comments][download][revision] = 8618531420aa88c4dd196faf0f2a9c74ae853378

; Allows editors to embed videos using CKEditor
projects[video_filter][download][type] = git
projects[video_filter][download][url] = http://git.drupal.org/project/video_filter.git
projects[video_filter][download][revision] = 9e6fe9b6f42af9634fbe4558c484c39e5036e01d

; We want to flag course implementations where privileged user may hide
; optionally repeating events.
projects[flag] = 3.9

; For showing some system messages within Views, we need this module to provide
; the handler. See DOO-706
projects[views_system_message] = 1.0

; As we're managing our accounts through Shibboleth, we want to disable password
; reset functionality. Especially when having multiple accounts with same email.
projects[noreqnewpass] = 1.2

; Too much of help texts around makes the form too fuzzy
projects[better_formats][version] = 1.0-beta2
projects[better_formats][patch]["https://www.drupal.org/node/2471589"] = "https://www.drupal.org/files/issues/empty-format-wrapper-div-2471589-1.patch"

; With these modules we can provide course information in JSON format for
; external clients like Opintoni project.
projects[services][version] = 3.20
projects[services_views][version] = 1.1
projects[image_url_formatter][version] = 1.4

; With message module, we can track down course activity.
projects[message][version] = 1.12

; Optional supported (themed) module for providing site status messages
projects[site_status_message][version] = 1.0

; Optional module for gathering more information about PHP exceptions
projects[past][version] = 1.0-alpha3
projects[rules][version] = 2.9

projects[conditional_fields][version] = 3.0-alpha2

projects[field_extrawidgets][version] = 1.1

projects[page_memory_limit][version] = 1.2

projects[vertical_tabs_content_marker][type] = module
projects[vertical_tabs_content_marker][download][type] = git
projects[vertical_tabs_content_marker][download][branch] = "7.x-1.x"
projects[vertical_tabs_content_marker][download][url] = http://git.drupal.org/sandbox/lviit/2827780.git
projects[vertical_tabs_content_marker][download][revision] = bb50539daf5cecca3dfe1367737fbefc752bda29

projects[view_reference_tabs_formatter][type] = module
projects[view_reference_tabs_formatter][download][type] = git
projects[view_reference_tabs_formatter][download][branch] = "7.x-1.x"
projects[view_reference_tabs_formatter][download][url] = http://git.drupal.org/sandbox/lviit/2862420.git
projects[view_reference_tabs_formatter][download][revision] = 70ff6106c11e9598c585202ee859d379d79914d6

projects[xmlsitemap][version] = "2.3"

; Themes

projects[omega][subdir] = "omega"
projects[omega][version] = "4.4"
; Fix PHP notice related to incorrect language direction detection.
projects[omega][patch][2762793] = "https://www.drupal.org/files/issues/omega-modules-listed-as-missing-themes-2762793-13.patch"
projects[adminimal_theme][subdir] = "adminimal_theme"
projects[adminimal_theme][version] = "1.22"

; Libraries

libraries[jquery][directory_name] = jquery
libraries[jquery][download][type] = file
libraries[jquery][download][url] = https://github.com/jquery/jquery/archive/2.2.4.tar.gz

libraries[masonry][directory_name] = masonry
libraries[masonry][download][type] = file
libraries[masonry][download][url] = https://github.com/desandro/masonry/archive/v4.1.1.tar.gz

libraries[matchmedia][directory_name] = matchmedia
libraries[matchmedia][download][type] = file
libraries[matchmedia][download][url] = https://github.com/paulirish/matchMedia.js/archive/0.3.0.tar.gz

libraries[jquery-hoverintent][directory_name] = jquery-hoverintent
libraries[jquery-hoverintent][download][type] = file
libraries[jquery-hoverintent][download][url] = https://github.com/briancherne/jquery-hoverIntent/archive/v1.8.1.tar.gz

libraries[chosenjs][directory_name] = chosen
libraries[chosenjs][download][type] = file
libraries[chosenjs][download][url] = https://github.com/harvesthq/chosen/releases/download/v1.6.2/chosen_v1.6.2.zip

libraries[ckeditor][directory_name] = ckeditor
libraries[ckeditor][download][type] = file
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.7/ckeditor_4.4.7_standard.zip"

libraries[dropzone][download][type] = file
libraries[dropzone][download][url] = https://raw.github.com/enyo/dropzone/master/dist/dropzone.js
libraries[dropzone][directory_name] = "dropzone"

libraries[jquery.imagesloaded][download][type] = file
libraries[jquery.imagesloaded][download][url] = https://github.com/desandro/imagesloaded/archive/v2.1.2.tar.gz
libraries[jquery.imagesloaded][directory_name] = "jquery.imagesloaded"

libraries[jquery.imgareaselect][download][type] = file
libraries[jquery.imgareaselect][download][url] = https://github.com/odyniec/imgareaselect/archive/v0.9.11-rc.1.tar.gz
libraries[jquery.imgareaselect][download][subtree] = imgareaselect-0.9.11-rc.1

libraries[wvega-timepicker][download][type] = file
libraries[wvega-timepicker][download][url] = https://github.com/wvega/timepicker/archive/master.zip
libraries[wvega-timepicker][directory_name] = "wvega-timepicker"

libraries[timeago][download][type] = file
libraries[timeago][download][url] = https://github.com/rmm5t/jquery-timeago/archive/v1.4.1.zip
libraries[timeago][directory_name] = "timeago"

libraries[stomp_php][download][type] = "get"
libraries[stomp_php][download][url] = "https://github.com/dejanb/stomp-php/archive/2.1.1.zip"
libraries[stomp_php][directory_name] = "stomp_php"
libraries[stomp_php][destination] = "libraries"

; Project contribs
projects[uh_taxonomy_organisations][type] = module
projects[uh_taxonomy_organisations][download][type] = git
projects[uh_taxonomy_organisations][download][url] = "git://github.com/UH-StudentServices/uh_taxonomy_organisations.git"
projects[uh_taxonomy_organisations][download][branch] = 7.x-1.x
projects[uh_taxonomy_organisations][download][revision] = 26c91c9b9621bacf5d4baaaa1d3e48e43c0da61e

projects[uh_mece][type] = module
projects[uh_mece][download][type] = git
projects[uh_mece][download][url] = "git://github.com/UH-StudentServices/uh-mece.git"
projects[uh_mece][download][branch] = 7.x-1.x
projects[uh_mece][download][revision] = 209b8017a5d9d44c7bf2fec0049c36701a147438

projects[uh_oodi_queue][type] = module
projects[uh_oodi_queue][download][type] = git
projects[uh_oodi_queue][download][url] = "git://github.com/UH-StudentServices/uh_oodi_queue.git"
projects[uh_oodi_queue][download][branch] = 7.x-1.x
projects[uh_oodi_queue][download][revision] = a9b8d2cb1be3c67b05a437963792aa097397dd6f

projects[hy_cookie_consent][type] = module
projects[hy_cookie_consent][download][type] = git
projects[hy_cookie_consent][download][url] = "git://github.com/UniversityofHelsinki/hy_cookie_consent.git"
projects[hy_cookie_consent][download][branch] = 7.x-1.x
projects[hy_cookie_consent][download][revision] = 909f20821c323240142962df38fb4095b6b3b681
