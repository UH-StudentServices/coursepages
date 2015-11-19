<?php

/**
 * @file
 * Display Suite custom column template for Helsinging yliopisto.
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="ds-grid-container <?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <div class="ds-grid-item ds-grid-8">
      <<?php print $course_metadata_wrapper ?> class="<?php print $course_metadata_classes; ?>">
        <?php print $course_metadata; ?>
      </<?php print $course_metadata_wrapper ?>>

      <<?php print $course_banner_wrapper ?> class="<?php print $course_banner_classes; ?>">
        <?php print $course_banner; ?>
      </<?php print $course_banner_wrapper ?>>

      <<?php print $course_content_wrapper ?> class="<?php print $course_content_classes; ?>">
        <?php print $course_content ?>
      </<?php print $course_content_wrapper ?>>
    </div>

    <<?php print $course_sidebar_wrapper ?> class="ds-grid-item ds-grid-3 ds-push-1 <?php print $course_sidebar_classes; ?>">
      <?php print $course_sidebar ?>
    </<?php print $course_sidebar_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
