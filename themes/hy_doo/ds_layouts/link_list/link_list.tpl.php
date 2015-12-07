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

<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-node-link-list <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

  <div class="ds-node-link-list__section">
    <<?php print $link_list_title_wrapper ?> class="ds-node-link-list__section-title <?php print $link_list_title_classes; ?>">
      <?php print $link_list_title; ?>
    </<?php print $link_list_title_wrapper ?>>

    <<?php print $link_list_content_wrapper ?> class="ds-node-link-list__section-content <?php print $link_list_content_classes; ?>">
      <?php print $link_list_content; ?>
    </<?php print $link_list_content_wrapper ?>>
  </div>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>