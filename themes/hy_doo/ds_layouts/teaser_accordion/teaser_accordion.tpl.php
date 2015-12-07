<?php

/**
 * @file
 * Display Suite custom accordion teaser template for Helsinging yliopisto.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-teaser-accordion <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <<?php print $teaser_accordion_title_wrapper ?> class="ds-teaser-accordion--title <?php print $teaser_accordion_title_classes; ?>">
      <?php print $teaser_accordion_title; ?>
    </<?php print $teaser_accordion_title_wrapper ?>>

    <?php if (!empty($teaser_accordion_content)): ?>
      <<?php print $teaser_accordion_content_wrapper ?> class="ds-teaser-accordion--content <?php print $teaser_accordion_content_classes; ?>">
        <?php print $teaser_accordion_content; ?>
      </<?php print $teaser_accordion_content_wrapper ?>>
    <?php endif; ?>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>