; Drupal core drush make file
; ---------------------------

; The Drush Make API version.
api = 2

; The version of Drupal core to use.
core = 7.x

; Core project
; ------------

projects[drupal][version] = 7.38
projects[drupal][patch][] = "https://www.drupal.org/files/1029298-by-joachim-axel.rutz-casey-Added-Pass-default-value.patch"
projects[drupal][patch][] = "https://www.drupal.org/files/fapi-radio-checkbox-error-highlighting-222380-30.patch"
projects[drupal][patch][] = "https://www.drupal.org/files/issues/drupal-comment_access-validate-comment-2558435-1.patch"
projects[drupal][patch][] = "https://www.drupal.org/files/issues/node_access_for_left_joins_d7-1349080-282.patch"
