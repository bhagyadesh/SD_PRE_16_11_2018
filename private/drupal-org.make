; Drupal drush make file
; ----------------------

; The Drush Make API version.
api = 2

; The version of Drupal core to use.
core = 7.x

; Core project
; ------------

; Include the definition for how to build Drupal core.
includes[] = drupal-org-core.make

; Libraries
; ---------

libraries[ckeditor][download][type] = file
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor 4.5.1/ckeditor_4.5.1_standard.tar.gz"
libraries[jquery-bigTarget][download][type] = file
libraries[jquery-bigTarget][download][url] = "https://github.com/leevigraham/jquery-bigTarget.js/archive/2.0.0.tar.gz"
libraries[jquery.cycle][download][type] = file
libraries[jquery.cycle][download][url] = "http://malsup.github.com/jquery.cycle.all.js"
libraries[spyc][download][type] = file
libraries[spyc][download][url] = "https://github.com/mustangostang/spyc/archive/0.5.1.tar.gz"
libraries[wvega-timepicker][download][type] = file
libraries[wvega-timepicker][download][url] = "https://github.com/wvega/timepicker/archive/1.3.2.zip"

; Projects
; --------

; Set the default sub-directory for projects.
defaults[projects][subdir] = contrib

; Add contrib modules.
projects[acl][version] = 1.1
projects[addressfield][version] = 1.1
;projects[addressfield][patch][] = "https://www.drupal.org/files/addressfield-configurable_empty_fields-1263316-60.patch"
projects[admin_menu][version] = 3.0-rc5
projects[admin_views][version] = 1.5
projects[ajax_links_api][version] = 1.83
projects[apc][version] = 1.0-beta6
; @todo Use dev until a release newer than 1.0-beta1 exists.
projects[better_formats][version] = 1.x
projects[charts][version] = 2.0-rc1
; @todo Use dev until a release newer than 1.0-alpha1 exists.
projects[ckeditor_styles][version] = 1.x
projects[colorbox][version] = 2.9
projects[conditional_fields][version] = 3.0-alpha1
projects[content_access][version] = 1.2-beta2
projects[context][version] = 3.6
projects[context][patch][] = "https://www.drupal.org/files/1271324-taxonomy-term-handler.patch"
projects[cors][version] = 1.3
projects[ctools][version] = 1.9
projects[custom_formatters][version] = 2.4
projects[date][version] = 2.9-rc1
projects[delta][version] = 3.0-beta11
projects[diff][version] = 3.2
projects[easy_breadcrumb][version] = 2.12
; @todo Use dev until a release newer than 2.1 exists.
projects[elysia_cron][version] = 2.x
projects[email][version] = 1.3
projects[entity][version] = 1.6
projects[entity][patch][] = "https://www.drupal.org/files/issues/entity-stop-assuming-you-may-find-array-1414428-14_0.patch"
projects[entitycache][version] = 1.2
projects[entityform][version] = 1.4
projects[entityreference][version] = 1.1
projects[entityreference_backreference][version] = 1.0-beta3
projects[entityreference_backreference][patch][] = "https://www.drupal.org/files/issues/entityreference_backreference-deltas-2417713-4.patch"
projects[expanding_formatter][version] = 1.0
projects[expire][version] = 2.0-rc4
projects[extlink][version] = 1.18
projects[facetapi][version] = 1.5
projects[facetapi_pretty_paths][version] = 1.4
projects[facetapi_taxonomy_sort][version] = 1.0-beta1
projects[features][version] = 1.0
projects[feeds][version] = 2.0-beta1
; @todo Use patch until issues is resolved and included in a new release.
projects[feeds][patch][] = "https://www.drupal.org/files/issues/feeds-feeds_importer_load_all-2537290-7.patch"
projects[field_collection][version] = 1.0-beta8
projects[field_group][version] = 1.4
projects[field_group][patch][] = "https://www.drupal.org/files/issues/field_group-multipage-scroll-to-top-1341996-10.patch"
projects[field_permissions][version] = 1.0-beta2
projects[field_validation][version] = 2.6
projects[file_entity][version] = 2.0-beta2
projects[flag][version] = 3.6
; @todo Use dev until a release exists.
projects[flag_service][version] = 3.x
projects[google_analytics][version] = 1.4
projects[google_analytics_reports][version] = 3.0-beta2
projects[inline_entity_form][version] = 1.6
projects[i18n][version] = 1.13
projects[i18n][patch][] = "https://www.drupal.org/files/issues/i18n_menu-link-node-association-2533366-1.patch"
; @todo Remove git information once project is not a sandbox project.
projects[i18n_field_group][type] = "module"
projects[i18n_field_group][download][type] = "git"
projects[i18n_field_group][download][url] = "http://git.drupal.org/sandbox/webflo/1413404.git"
projects[i18n_field_group][download][branch] = "7.x-1.x"
projects[job_scheduler][version] = 2.0-alpha3
projects[lang_dropdown][version] = 1.5
projects[libraries][version] = 2.2
projects[link][version] = 1.3
projects[link][patch][] = "patches/link-remove-title-validation.patch"
; @todo Use git until issues are resolved and included in a new release.
projects[linkchecker][download][type] = "git"
projects[linkchecker][download][url] = "https://git.drupal.org/project/linkchecker.git"
projects[linkchecker][download][branch] = "7.x-1.x"
projects[linkchecker][patch][] = "https://www.drupal.org/files/issues/linkchecker-views-integration-965720-95.patch"
projects[linkit][version] = 3.3
projects[l10n_update][version] = 1.1
projects[masquerade][version] = 1.0-rc7
projects[maxlength][version] = 3.2
; @todo Use dev until issues is resolved and included in a new release.
projects[media][version] = 2.x
projects[media][patch][] = "https://www.drupal.org/files/issues/media-2631934-media-element-wysiwyg-false-3.patch"
projects[menu_admin_per_menu][version] = 1.0
projects[menu_token][version] = 1.0-beta5
projects[metatag][version] = 1.7
projects[module_filter][version] = 2.0
projects[node_compare][version] = 1.7
projects[oauth][version] = 3.2
projects[omega][version] = 3.1
projects[panels][version] = 3.5
; @todo Remove patch once a release newer than 3.5 exists.
projects[panels][patch][] = "https://www.drupal.org/files/issues/1391450-21-hide-empty-mini-panel.patch"
; @todo Remove patch once a release newer than 3.5 exists.
projects[panels][patch][] = "https://www.drupal.org/files/issues/panels-css-keywords-1441218-65.patch"
projects[path_breadcrumbs][version] = 3.3
projects[pathauto][version] = 1.2
projects[pathologic][version] = 2.12
projects[phone][version] = 1.0-beta1
projects[redirect][version] = 1.0-rc3
projects[revisioning][version] = 1.9
projects[revisioning][patch][] = "https://www.drupal.org/files/issues/revisioning-publish-reset-cache-2382331-1.patch"
projects[revisioning][patch][] = "https://www.drupal.org/files/issues/revisioning-router_node_view-1567880-12.patch"
projects[role_delegation][version] = 1.1
projects[rules][version] = 2.9
projects[rules][patch][] = "https://www.drupal.org/files/issues/2094879-column_owner_not_created-28.patch"
projects[search_api][version] = 1.16
projects[search_api][patch][] = "https://www.drupal.org/files/issues/search_api-language-fallback-1960684-7.patch"
projects[search_api][patch][] = "https://www.drupal.org/files/issues/search_api_facetapi_adapter_base_path.patch"
projects[search_api][patch][] = "https://www.drupal.org/files/issues/search_api-facetapi-block-override-path-2169909-4.patch"
projects[search_api_autocomplete][version] = 1.4
projects[search_api_solr][version] = 1.9
projects[services][version] = 3.12
; @todo Remove git information once project is not a sandbox project.
projects[services_field_collection][type] = "module"
projects[services_field_collection][download][type] = "git"
projects[services_field_collection][download][url] = "http://git.drupal.org/sandbox/Graber/2141747.git"
projects[services_field_collection][download][branch] = "master"
; @todo Do we still need services views?
projects[services_views][version] = 1.0
projects[services_views][patch][] = "https://www.drupal.org/files/issues/services_views-reference-column-support-2289431-4.patch"
projects[special_menu_items][version] = 2.0
projects[strongarm][version] = 2.0
projects[taxonomy_manager][version] = 1.0
;projects[tng_drupal_7_feature][version] = 1.2
projects[token][version] = 1.6
projects[token_filter][version] = 1.1
projects[variable][version] = 2.5
; @todo Use dev until a release newer than 1.0-alpha1 exists.
projects[variable_email][version] = 1.x
projects[video_embed_field][version] = 2.0-beta10
projects[viewfield][version] = 2.0
; @todo Use dev until a release newer than 3.13 exists.
projects[views][version] = 3.x
projects[views][patch][] = "https://www.drupal.org/files/issues/views.1222204-22.patch"
projects[views][patch][] = "https://www.drupal.org/files/issues/views-comment-link-errors-2542798-1.patch"
projects[views][patch][] = "https://www.drupal.org/files/issues/views-content-translations-tnid-zero-2638220-1.patch"
projects[views_aggregator][version] = 1.4
projects[views_bulk_operations][version] = 3.3
projects[views_data_export][version] = 3.0-beta8
projects[views_rss][version] = 2.0-rc4
projects[views_slideshow][version] = 3.1
projects[wysiwyg][version] = 2.x
projects[xmlsitemap][version] = 2.2
projects[xmlsitemap][patch][] = "https://www.drupal.org/files/xmlsitemap-safe-bundle-names-1821268-5.patch"
