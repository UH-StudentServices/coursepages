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

    <div class="ds-grid-item ds-grid-12">
      <<?php print $simple_page_metadata_wrapper ?> class="<?php print $simple_page_metadata_classes; ?>">
        <?php print $simple_page_metadata; ?>
      </<?php print $simple_page_metadata_wrapper ?>>

      <<?php print $simple_page_banner_wrapper ?> class="<?php print $simple_page_banner_classes; ?>">
        <?php print $simple_page_banner; ?>
      </<?php print $simple_page_banner_wrapper ?>>

      <<?php print $simple_page_content_wrapper ?> class="<?php print $simple_page_content_classes; ?>">
        <?php print $simple_page_content ?>
      </<?php print $simple_page_content_wrapper ?>>
    </div>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>