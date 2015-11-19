<div class="l-page">
  <?php if ($page['top_bar']): ?>
    <div class="l-top-bar-wrapper">
      <div class="l-top-bar">
        <?php print render($page['top_bar']); ?>
      </div>
    </div>
  <?php endif; ?>

  <div
    class="l-menu-bar<?php if ($page['top_bar']): ?> with-top-bar<?php endif; ?>">
    <?php print render($page['menu_bar']); ?>
  </div>
  <?php if ($messages): ?>
    <?php print $messages; ?>
  <?php endif; ?>
  <div class="l-main-wrapper">
    <div class="l-main">

      <?php if ($page['navigation']): ?>
        <div class="l-navigation">
          <?php print render($page['navigation']); ?>
        </div>
      <?php endif; ?>

      <div class="l-content-wrapper">
        <a id="main-content"></a>

        <?php if ($page['content_prefix']): ?>
          <div class="l-content-prefix">
            <?php print render($page['content_prefix']); ?>
          </div>
        <?php endif; ?>

        <?php print render($title_prefix); ?>
        <?php if ($title): ?>
          <h1 class="page-title"><?php print $title; ?></h1>
        <?php endif; ?>
        <?php print render($title_suffix); ?>
        <?php print render($tabs); ?>
        <?php if ($action_links): ?>
          <ul class="action-links"><?php print render($action_links); ?></ul>
        <?php endif; ?>

        <?php if ($page['content_sidebar_left']): ?>
          <div class="l-content-sidebar-left">
            <?php if ($title): ?>
              <h1 class="page-title--small"><?php print $title; ?></h1>
            <?php endif; ?>
            <?php print render($page['content_sidebar_left']); ?>
          </div>
        <?php endif; ?>

        <?php if ($page['content_sidebar_right']): ?>
          <div class="l-content-sidebar-right">
            <?php print render($page['content_sidebar_right']); ?>
          </div>
        <?php endif; ?>

        <div class="l-content" role="main">
          <?php print render($page['content']); ?>
          <?php print $feed_icons; ?>
        </div>
      </div>
    </div>
  </div>

  <?php if ($page['content_suffix']): ?>
    <div class="l-content-suffix-wrapper">
      <div class="l-content-suffix">
        <?php print render($page['content_suffix']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($page['after_content']): ?>
    <?php print render($page['after_content']); ?>
  <?php endif; ?>

  <?php if ($page['action_footer']): ?>
    <div class="l-action-footer-wrapper">
      <div class="l-action-footer">
        <?php print render($page['action_footer']); ?>
      </div>
    </div>
  <?php endif; ?>

  <?php if ($page['info_footer']): ?>
    <div class="l-info-footer-wrapper">
      <div class="l-info-footer">
        <?php print render($page['info_footer']); ?>
      </div>
    </div>
  <?php endif; ?>

  <footer class="l-footer" role="contentinfo">
    <?php print render($page['footer']); ?>

    <div class="copyright">
      <p>
        <?php print '&copy; ' . t('University of Helsinki @year', array('@year' => date('Y'))); ?>
      </p>
    </div>
  </footer>
</div>
