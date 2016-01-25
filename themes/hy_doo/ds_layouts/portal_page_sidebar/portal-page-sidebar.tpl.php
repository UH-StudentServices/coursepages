<?php

/**
 * @file
 * Display Suite custom column template for Helsingin yliopisto.
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

    <div class="ds-grid-item ds-grid-8">
      <<?php print $portal_page_content_wrapper ?> class="<?php print $portal_page_content_classes; ?>">
        <?php print $portal_page_content; ?>
      </<?php print $portal_page_content_wrapper ?>>
    </div>

    <<?php print $portal_page_sidebar_wrapper ?> class="ds-grid-item ds-grid-3 ds-push-1 ds-node-sidebar <?php print $portal_page_sidebar_classes; ?>">
      <?php print $portal_page_sidebar ?>
    </<?php print $portal_page_sidebar_wrapper ?>>

    <<?php print $portal_page_promotion_wrapper ?> class="clearfix <?php print $portal_page_promotion_classes; ?>">
      <?php print $portal_page_promotion ?>
    </<?php print $portal_page_promotion_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
