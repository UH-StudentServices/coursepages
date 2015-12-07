<?php

/**
 * @file
 * Display Suite custom one column template for Helsinging yliopisto.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-grid-container <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>
  <div class="ds-material-block">
    <<?php print $event_material_content_wrapper; ?> class="ds-material-block--content<?php print $event_material_content_classes; ?>">
      <?php print $event_material_content; ?>
    </<?php print $event_material_content_wrapper ?>>
    <?php if (!empty($event_material_attachements)): ?>
      <<?php print $event_material_attachements_wrapper; ?> class="ds-material-block--attachements<?php print $event_material_attachements_classes; ?>">
        <?php print $event_material_attachements; ?>
      </<?php print $event_material_attachements_wrapper ?>>
    <?php endif; ?>
  </div>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
