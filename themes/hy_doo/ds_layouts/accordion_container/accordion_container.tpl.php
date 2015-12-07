<?php

/**
 * @file
 * Display Suite custom accordion teaser template for Helsingin yliopisto.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
?>

<?php if (isset($title_suffix['contextual_links'])): ?>
<?php print render($title_suffix['contextual_links']); ?>
<?php endif; ?>

<h3 class="field-group-format-toggler accordion-item <?php print $accordion_title_classes; ?>">
  <?php print $accordion_title; ?>
</h3>

<?php if (!empty($accordion_content)): ?>
  <<?php print $accordion_content_wrapper ?> class="field-group-format-wrapper field-group-accordion-item <?php print $accordion_content_classes; ?>">
    <div class="accordion-content-item">
      <?php print $accordion_content; ?>
    </div>
  </<?php print $accordion_content_wrapper ?>>
<?php endif; ?>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
