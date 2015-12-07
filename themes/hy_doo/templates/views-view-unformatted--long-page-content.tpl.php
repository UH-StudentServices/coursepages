<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 *
 * @ingroup views_templates
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="long-page-row-container">
    <div<?php if ($classes_array[$id]) {
      print ' class="' . $classes_array[$id] . '"';
    } ?>>
      <?php print $row; ?>
    </div>
  </div>
<?php endforeach; ?>