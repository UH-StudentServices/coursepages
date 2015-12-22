; Drush Make File
; ----------------

core = 7.0
api = 2

projects[drupal][type] = core
projects[drupal][version] = 7.41

defaults[projects][subdir] = "contrib"

; Contrib
; ----------------

projects[admin_menu][download][branch] = 7.x-3.x
projects[admin_menu][download][revision] = b07d37b857f48e8e38ca8c31fbb8153184c46932
projects[admin_menu][patch][1981308] = https://www.drupal.org/files/issues/admin_menu-js-module-compatibility-1981308-9.patch
projects[admin_views][version] = "1.5"
projects[behavior_weights][version] = "1.0"
projects[block_class][version] = "2.1"
projects[chosen][version] = "2.0-beta4"
projects[ckeditor][version] = "1.16"
projects[context][version] = "3.6"
projects[context_omega][version] = "1.1"
projects[ctools][version] = "1.7"
projects[date][version] = "2.8"
projects[diff][version] = "3.2"
projects[email][version] = "1.3"
projects[entity][version] = "1.6"
projects[entitycache][version] = "1.2"
projects[entity_translation][version] = "1.0-beta4"
projects[entityreference][version] = "1.1"
projects[entityreference][patch]["https://www.drupal.org/node/1674792"] = https://www.drupal.org/files/issues/entityreference-rendered-entity-is-not-language-aware-1674792-58.patch
projects[features][version] = "2.2"
projects[feedback][download][type] = git
projects[feedback][download][url] = http://git.drupal.org/project/feedback.git
projects[feedback][download][revision] = 5211a265d75c8303902ee584c42b375983170ce3
projects[field_collection][version] = "1.0-beta8"
projects[field_formatter_settings][version] = "1.1"
projects[field_group][version] = "1.4"
projects[field_group][patch]["https://www.drupal.org/node/1482958"] = "https://www.drupal.org/files/issues/empty-config-1482958-26.patch"
projects[field_multiple_limit][version] = "1.0-alpha4"
projects[field_permissions][version] = "1.0-beta2"
projects[filefield_paths][version] = "1.0-rc1"
projects[languagefield][version] = "1.3"

; TODO: Check if google_analytics can be updated to 2.0
; See docs at https://www.drupal.org/project/google_analytics about Universal Analytics
projects[google_analytics][version] = "1.4"

projects[google_analytics_et][version] = "1.2"
projects[i18n][version] = "1.11"
projects[imagemagick][version] = "1.0"
projects[joyride][version] = "1.0-alpha3"
projects[joyride][patch]["https://www.drupal.org/node/2411447"] = https://www.drupal.org/files/issues/joyride-makefile-core-and-api-version.diff
projects[l10n_update][version] = "1.1"
projects[libraries][version] = "2.2"
projects[location][version] = "3.7"
projects[logging_alerts][version] = "2.2"
projects[link][download][type] = git
projects[link][download][url] = http://git.drupal.org/project/link.git
projects[link][download][revision] = 18fc33964f2ad730e9c5ebf28d8e77d4555349e6
projects[linkit][version] = "3.4"
projects[maxlength][version] = "3.2"
projects[memcache][version] = "1.3"
projects[mb][download][type] = git
projects[mb][download][url] = http://git.drupal.org/project/mb.git
projects[mb][download][revision] = cf380cf23801c41bc6a3712b0775483ab553c920
projects[menu_attributes][version] = "1.0-rc3"
projects[menu_block][version] = "2.4"
projects[migrate][version] = "2.5"
projects[module_filter][version] = 2.0-alpha2
projects[og][version] = "2.7"
projects[comment_og][version] = "1.0"
projects[pathauto][version] = "1.2"
projects[responsive_navigation][version] = "1.0"
projects[responsive_navigation][patch]["https://www.drupal.org/node/2018335"] = https://www.drupal.org/files/include-once-2018335-3.patch

; Search

; drush make does not know where to place this by default
projects[search_api][version] = "1.13"
projects[search_api][subdir] = "contrib"
projects[search_api_autocomplete][version] = "1.4"
; Temporary fix for download not working for facetapi
; projects[facetapi][version] = "1.5"
projects[facetapi][download][type] = file
projects[facetapi][download][url] = http://ftp.drupal.org/files/projects/facetapi-7.x-1.5.tar.gz
projects[facetapi_bonus][version] = "1.1"
projects[facetapi_select][download][url] = http://git.drupal.org/project/facetapi_select.git
projects[facetapi_select][download][revision] = "c960e18"
projects[facetapi_pretty_paths][version] = "1.1"
projects[facetapi_taxonomy_sort][version] = "1.0-beta1"
projects[search_api_db][version] = "1.4"
projects[search_api_et][download][type] = git
projects[search_api_et][download][url] = http://git.drupal.org/project/search_api_et.git
projects[search_api_et][download][revision] = a56f527
projects[search_api_solr][version] = "1.6"
projects[search_api_solr][patch]["https://www.drupal.org/node/2343111"] = https://www.drupal.org/files/issues/search_api_solr-2343111-OR-Filters-14.patch
projects[search_api_et_solr][download][type] = git
projects[search_api_et_solr][download][url] = http://git.drupal.org/project/search_api_et_solr.git
projects[search_api_et_solr][download][revision] = a03edb6

; Others

projects[shs][version] = "1.6"
projects[special_menu_items][version] = "2.0"
projects[stringoverrides][version] = "1.8"
projects[strongarm][version] = "2.0"
projects[taxonomy_access_fix][version] = "2.1"
projects[timeago][version] = "2.3"
projects[title][version] = "1.0-alpha7"
projects[title][patch]["https://www.drupal.org/node/1772116"] = https://www.drupal.org/files/title-1772116-auto-menu-title-bug-1772116-3.patch
projects[token][version] = "1.5"
projects[variable][version] = "2.5"
projects[varnish][version] = "1.0-beta3"
; FIX theme call related error on varnish admin page.
projects[varnish][patch]["https://www.drupal.org/node/2371907"] = "https://www.drupal.org/files/issues/varnish-2371907-9.patch"
projects[views][version] = "3.11"
projects[views_bulk_operations][version] = "3.2"
projects[views_block_area][version] = "1.1"
projects[views_data_export][version] = "3.0-beta8"
projects[viewreference][version] = "3.4"
projects[view_unpublished][version] = "1.2"
projects[override_node_options][version] = "1.13"

projects[shib_auth][version] = 4.2
projects[shib_auth][patch]["https://www.drupal.org/node/2350239"] = https://www.drupal.org/files/issues/email_already_used-2350239-7.patch
projects[shib_auth][patch]["https://www.drupal.org/node/2389383"] = https://www.drupal.org/files/issues/2389383-shib-redirect.patch
projects[shib_auth][patch]["https://www.drupal.org/node/2416637"] = https://www.drupal.org/files/issues/shib_auth-bad_url-2416637-4.patch

; We need to be able to edit accounts with used email addresses while patched
; shibboleth module allows multiple accounts with shared emails.
projects[sharedemail][version] = 1.0

projects[inline_entity_form][version] = "1.6"
projects[pathologic][version] = 2.12

projects[embed_views][version] = 1.2

; Display suite
projects[ds][version] = "2.8"
projects[ds][subdir] = "contrib"
projects[ds][patch]["https://www.drupal.org/node/2481557"] = "https://www.drupal.org/files/issues/xss_fix_is_too_strict-2481557-4.patch"
;# Patch for text in resilts view see: https://www.drupal.org/node/2345387
;projects[ds][patch][rename-total-results] = "https://www.drupal.org/files/issues/ds-rename_total_results_output-2345387-1.patch"

; multiple filed issue descovered in build
;# Undefined index: cardinality in field_multiple_limit_field_formatter_settings_summary_alter()
projects[field_multiple_limit][patch]["https://www.drupal.org/node/2345387"] = "https://www.drupal.org/files/field_multiple_limit-ignore_missing_cardinality-1958614-1.patch"

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
projects[flag] = 3.6

; For showing some system messages within Views, we need this module to provide
; the handler. See DOO-706
projects[views_system_message] = 1.0

; As we're managing our accounts through Shibboleth, we want to disable password
; reset functionality. Especially when having multiple accounts with same email.
projects[noreqnewpass] = 1.2

; Too much of help texts around makes the form too fuzzy
projects[better_formats][version] = 1.0-beta1
projects[better_formats][patch]["https://www.drupal.org/node/2471589"] = "https://www.drupal.org/files/issues/empty-format-wrapper-div-2471589-1.patch"

; With these modules we can provide course information in JSON format for
; external clients like Opintoni project.
projects[services][version] = 3.12
projects[services_views][version] = 1.0
projects[image_url_formatter][version] = 1.4

; With message module, we can track down course activity.
projects[message][version] = 1.10

; Optional supported (themed) module for providing site status messages
projects[site_status_message][version] = 1.0

; Themes

projects[omega][subdir] = "omega"
projects[omega][version] = "4.3"
; Fix PHP notice related to incorrect language direction detection.
projects[omega][patch][2364731] = "https://www.drupal.org/files/issues/omega-fix-direction-language-rtl-2364731-7.patch"

projects[hy_base_theme][type] = "theme"
projects[hy_base_theme][subdir] = "hy_base_theme"
projects[hy_base_theme][download][type] = "git"
projects[hy_base_theme][download][url] = "https://github.com/UH-StudentServices/hy_base_theme.git"
projects[hy_base_theme][download][branch] = "7.x-1.x"
projects[hy_base_theme][download][tag] = "7.x-1.0-beta1"
projects[adminimal_theme][subdir] = "adminimal_theme"
projects[adminimal_theme][version] = "1.22"

; Libraries

libraries[chosenjs][directory_name] = chosen
libraries[chosenjs][download][type] = file
libraries[chosenjs][download][url] = https://github.com/harvesthq/chosen/releases/download/v1.1.0/chosen_v1.1.0.zip

libraries[ckeditor][directory_name] = ckeditor
libraries[ckeditor][download][type] = file
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.4.7/ckeditor_4.4.7_standard.zip"

libraries[colorbox][download][type] = file
libraries[colorbox][download][url] = https://github.com/jackmoore/colorbox/archive/1.5.14.zip
libraries[colorbox][directory_name] = "colorbox"

libraries[dropzone][download][type] = file
libraries[dropzone][download][url] = https://raw.github.com/enyo/dropzone/master/dist/dropzone.js
libraries[dropzone][directory_name] = "dropzone"

libraries[flexslider][download][type] = file
libraries[flexslider][download][url] = https://github.com/woothemes/FlexSlider/archive/version/2.2.2.zip
libraries[flexslider][directory_name] = "flexslider"

libraries[wvega-timepicker][download][type] = file
libraries[wvega-timepicker][download][url] = https://github.com/wvega/timepicker/archive/master.zip
libraries[wvega-timepicker][directory_name] = "wvega-timepicker"

libraries[timeago][download][type] = file
libraries[timeago][download][url] = https://github.com/rmm5t/jquery-timeago/archive/v1.4.1.zip
libraries[timeago][directory_name] = "timeago"

libraries[responsive_navigation][download][type] = file
libraries[responsive_navigation][download][url] = https://github.com/viljamis/responsive-nav.js/archive/1.0.20.zip
libraries[responsive_navigation][directory_name] = "responsive_navigation"

libraries[stomp_php][download][type] = "get"
libraries[stomp_php][download][url] = "https://github.com/dejanb/stomp-php/archive/2.1.1.zip"
libraries[stomp_php][directory_name] = "stomp_php"
libraries[stomp_php][destination] = "libraries"

; Project contribs
projects[uh_taxonomy_organisations][type] = module
projects[uh_taxonomy_organisations][download][type] = git
projects[uh_taxonomy_organisations][download][url] = "git://github.com/UH-StudentServices/uh_taxonomy_organisations.git"
projects[uh_taxonomy_organisations][download][branch] = 7.x-1.x
projects[uh_taxonomy_organisations][download][revision] = 6338060ab88805f9110c0d0f13540cbf98f542a8
