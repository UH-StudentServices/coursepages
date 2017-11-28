# UHC Oodi module

This module provides an API for interacting with Oodi.

#### Caching
This data is cached in its own cache bin `cache_uhc_oodi` and you may clear
that cache using drush:
```
$ drush cc uhc_oodi
```

Caches expire in 10 minutes.

Examples of API usage:

#### Print type code of learning opportunity "A406000"
```
$endpoint = 'https://example.com:1234/oodi';
$connection = new UHCOodiConnection($endpoint);
$learningopportunity = new UHCOodiLearningOpportunity($connection, new UHCOodiCache());
print $learningopportunity->loadById('A406000')->getValue('learningopportunity_type_code');
# Prints out "12"
```

#### Print description "Objective" (id 1)
```
$endpoint = 'https://example.com:1234/oodi';
$connection = new UHCOodiConnection($endpoint);
$learningopportunity = new UHCOodiLearningOpportunity($connection, new UHCOodiCache());
$learningopportunity->setConfigDescription(array('1' => 'objective'));
$translations = $learningopportunity->loadById('A406000')->getDescription('objective');
print_r($translations);
# Prints out:
# Array
# (
#     [0] => Array
#         (
#             [langcode] => fi
#             [text] => <p>Tavoite. Lukuvuosi 2016-17.</p>
#         )
#     [1] => Array
#         (
#             [langcode] => en
#             [text] => <p>Objective. Academic year 2016-17.</p>
#         )
# )
#
# Now print only in english:
$objective = new UHCOodiMultilingualValue($translations);
print $objective->language('en')->getValue();
```
