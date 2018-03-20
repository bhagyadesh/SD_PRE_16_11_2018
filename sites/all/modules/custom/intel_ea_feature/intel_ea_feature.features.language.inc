<?php
/**
 * @file
 * intel_ea_feature.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function intel_ea_feature_locale_default_languages() {
  $languages = array();

  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '0',
    'formula' => '',
    'domain' => '',
    'prefix' => '',
    'weight' => '0',
  );
  // Exported language: es.
  $languages['es'] = array(
    'language' => 'es',
    'name' => 'Spanish',
    'native' => 'Español',
    'direction' => '0',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'es',
    'weight' => '0',
    'enabled' => '0',
  );
  // Exported language: ja.
  $languages['ja'] = array(
    'language' => 'ja',
    'name' => 'Japanese',
    'native' => '日本語',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'ja',
    'weight' => '0',
  );
  // Exported language: ko.
  $languages['ko'] = array(
    'language' => 'ko',
    'name' => 'Korean',
    'native' => '한국어',
    'direction' => '0',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'ko',
    'weight' => '0',
    'enabled' => '0',
  );
  // Exported language: pt-br.
  $languages['pt-br'] = array(
    'language' => 'pt-br',
    'name' => 'Portuguese, Brazil',
    'native' => 'Português',
    'direction' => '0',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'pt-br',
    'weight' => '0',
    'enabled' => '0',
  );
  // Exported language: ru.
  $languages['ru'] = array(
    'language' => 'ru',
    'name' => 'Russian',
    'native' => 'Русский',
    'direction' => '0',
    'plurals' => '3',
    'formula' => '(((($n%10)==1)&&(($n%100)!=11))?(0):((((($n%10)>=2)&&(($n%10)<=4))&&((($n%100)<10)||(($n%100)>=20)))?(1):2))',
    'domain' => '',
    'prefix' => 'ru',
    'weight' => '0',
    'enabled' => '0',
  );
  // Exported language: zh-hans.
  $languages['zh-hans'] = array(
    'language' => 'zh-hans',
    'name' => 'Chinese, Simplified',
    'native' => '简体中文',
    'direction' => '0',
    'enabled' => '1',
    'plurals' => '2',
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'zh-hans',
    'weight' => '0',
  );
  // Exported language: zh-hant.
  $languages['zh-hant'] = array(
    'language' => 'zh-hant',
    'name' => 'Chinese, Traditional',
    'native' => '繁體中文',
    'direction' => '0',
    'plurals' => '2',
    'formula' => '($n>1)',
    'domain' => '',
    'prefix' => 'zh-hant',
    'weight' => '0',
    'enabled' => '0',
  );
  return $languages;
}
