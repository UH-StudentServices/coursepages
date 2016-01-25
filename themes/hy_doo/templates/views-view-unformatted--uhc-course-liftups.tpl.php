<?php

/**
 * @file
 * Default simple view template to display a list of rows.
 * custom template for adding a wrapper for gridder-box class.
 *
 * @ingroup views_templates
 */
?>
<?php if (!empty($title)): ?>
  <h3><?php print $title; ?></h3>
<?php endif; ?>
<?php foreach ($rows as $id => $row): ?>
  <div class="gridder-box">
    <div<?php if ($classes_array[$id]) { print ' class="' . $classes_array[$id] .'"';  } ?>>
      <?php print $row; ?>
    </div>
  </div>
<?php endforeach; ?>