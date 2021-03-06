<?php
/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
?>
<div class="l-page">
  <header class="l-header">
    <?php if ($page['top_bar_main']): ?>
      <div class="l-top-bar">
        <div class="l-top-bar__subregion">
          <div class="l-top-bar__main">
            <?php print render($page['top_bar_main']); ?>
          </div>
          <?php if ($page['top_bar_sub']): ?>
            <div class="l-top-bar__sub">
              <?php print render($page['top_bar_sub']); ?>
            </div>
          <?php endif; ?>
        </div>
      </div>
    <?php endif; ?>
  </header>

  <div class="menu-wrapper">
    <?php if ($page['menu_bar']): ?>
      <div class="menu-bar">
        <?php print render($page['menu_bar']); ?>
      </div>
    <?php endif; ?>
    <?php if ($page['navigation']): ?>
      <?php print render($page['navigation']); ?>
    <?php endif; ?>
  </div>
  <?php if ($tabs): ?>
    <div class="tabs-wrapper">
      <?php print render($tabs); ?>
    </div>
  <?php endif; ?>
  <?php if ($messages): ?>
    <?php print $messages; ?>
  <?php endif; ?>
  <div class="l-main-wrapper">
    <div class="l-main">
      <div class="l-content-wrapper">
        <?php if ($breadcrumb): ?>
          <div class="l-breadcrumb">
            <?php print $breadcrumb; ?>
          </div>
        <?php endif; ?>
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

  <footer role="contentinfo">
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
    <div class="l-footer">
      <div class="l-footer__subregion">
        <?php print render($page['footer']); ?>
      </div>
      <div class="l-footer__copyright">
        <p>
          <?php print '&copy; ' . t('University of Helsinki') . ' ' . date('Y'); ?>
        </p>
      </div>
    </div>
  </footer>
</div>
