<?php

/**
 * @file
 * Overrides the default view template to display a item in an RSS feed.
 *
 * Only renders the item when the title is not empty.
 *
 * @ingroup views_templates
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
?>
<?php if (!empty($title)): ?>
  <item>
    <title><?php print $title; ?></title>
    <link><?php print $link; ?></link>
    <description><?php print $description; ?></description>
    <?php print $item_elements; ?>
  </item>
<?php endif; ?>
