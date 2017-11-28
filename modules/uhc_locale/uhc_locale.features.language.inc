<?php
/**
 * @file
 * uhc_locale.features.language.inc
 */

/**
 * Implements hook_locale_default_languages().
 */
function uhc_locale_locale_default_languages() {
  $languages = array();

  // Exported language: an.
  $languages['an'] = array(
    'language' => 'an',
    'name' => 'Aragonese',
    'native' => 'Aragonese',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'an',
    'weight' => 0,
  );
  // Exported language: en.
  $languages['en'] = array(
    'language' => 'en',
    'name' => 'English',
    'native' => 'English',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'en',
    'weight' => -8,
  );
  // Exported language: fi.
  $languages['fi'] = array(
    'language' => 'fi',
    'name' => 'Finnish',
    'native' => 'Suomi',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'fi',
    'weight' => -10,
  );
  // Exported language: ii.
  $languages['ii'] = array(
    'language' => 'ii',
    'name' => 'Sichuan Yi',
    'native' => 'Sichuan Yi',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'ii',
    'weight' => 0,
  );
  // Exported language: io.
  $languages['io'] = array(
    'language' => 'io',
    'name' => 'Ido',
    'native' => 'Ido',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'io',
    'weight' => 0,
  );
  // Exported language: li.
  $languages['li'] = array(
    'language' => 'li',
    'name' => 'Limburgan',
    'native' => 'Limburgan',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'li',
    'weight' => 0,
  );
  // Exported language: lu.
  $languages['lu'] = array(
    'language' => 'lu',
    'name' => 'Luba-Katanga',
    'native' => 'Luba-Katanga',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'lu',
    'weight' => 0,
  );
  // Exported language: no.
  $languages['no'] = array(
    'language' => 'no',
    'name' => 'Norwegian',
    'native' => 'Norsk',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'no',
    'weight' => -7,
  );
  // Exported language: oj.
  $languages['oj'] = array(
    'language' => 'oj',
    'name' => 'Ojibwa',
    'native' => 'Ojibwa',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'oj',
    'weight' => 0,
  );
  // Exported language: srp.
  $languages['srp'] = array(
    'language' => 'srp',
    'name' => 'Serbian',
    'native' => 'Serbian',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'srp',
    'weight' => 0,
  );
  // Exported language: sv.
  $languages['sv'] = array(
    'language' => 'sv',
    'name' => 'Swedish',
    'native' => 'Svenska',
    'direction' => 0,
    'enabled' => 1,
    'plurals' => 2,
    'formula' => '($n!=1)',
    'domain' => '',
    'prefix' => 'sv',
    'weight' => -9,
  );
  // Exported language: vo.
  $languages['vo'] = array(
    'language' => 'vo',
    'name' => 'Volapük',
    'native' => 'Volapük',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'vo',
    'weight' => 0,
  );
  // Exported language: wa.
  $languages['wa'] = array(
    'language' => 'wa',
    'name' => 'Walloon',
    'native' => 'Walloon',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'wa',
    'weight' => 0,
  );
  // Exported language: zh.
  $languages['zh'] = array(
    'language' => 'zh',
    'name' => 'Chinese',
    'native' => 'Chinese',
    'direction' => 0,
    'enabled' => 0,
    'plurals' => 0,
    'formula' => '',
    'domain' => '',
    'prefix' => 'zh',
    'weight' => 0,
  );
  return $languages;
}
