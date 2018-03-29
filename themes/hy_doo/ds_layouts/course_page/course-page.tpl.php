<?php

/**
 * @file
 * Display Suite custom column template for Helsinging yliopisto.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
?>

<<?php print $layout_wrapper; print $layout_attributes; ?> class="<?php print $classes;?> clearfix">

  <?php if (isset($title_suffix['contextual_links'])): ?>
  <?php print render($title_suffix['contextual_links']); ?>
  <?php endif; ?>

    <div class="ds-grid-12">
      <div class="ds-node-metadata-wrapper">
        <?php if (!empty($course_metadata_header)): ?>
        <<?php print $course_metadata_header_wrapper ?> class="<?php print $course_metadata_header_classes; ?>">
          <?php print $course_metadata_header; ?>
        </<?php print $course_metadata_header_wrapper ?>>
        <?php endif; ?>
        <<?php print $course_metadata_wrapper ?> class="<?php print $course_metadata_classes; ?>">
          <?php print $course_metadata; ?>
        </<?php print $course_metadata_wrapper ?>>
        <?php if (!empty($course_metadata_footer)): ?>
        <<?php print $course_metadata_footer_wrapper ?> class="<?php print $course_metadata_footer_classes; ?>">
          <?php print $course_metadata_footer; ?>
        </<?php print $course_metadata_footer_wrapper ?>>
        <?php endif; ?>
      </div>

      <<?php print $course_banner_wrapper ?> class="<?php print $course_banner_classes; ?>">
        <?php print $course_banner; ?>
      </<?php print $course_banner_wrapper ?>>

      <<?php print $course_content_wrapper ?> class="<?php print $course_content_classes; ?>">
        <?php print $course_content ?>
      </<?php print $course_content_wrapper ?>>
    </div>

    <<?php print $course_sidebar_wrapper ?> class="ds-grid-4 ds-grid-last <?php print $course_sidebar_classes; ?>">
      <?php print $course_sidebar ?>
    </<?php print $course_sidebar_wrapper ?>>

</<?php print $layout_wrapper ?>>

<?php if (!empty($drupal_render_children)): ?>
  <?php print $drupal_render_children ?>
<?php endif; ?>
