<?php
/**
 * @file
 * This file does one modification based on module's default
 * comment-wrapper.tpl.php file.
 *
 * It renders the comment form before comments, because they are reversed using
 * sort_comments module. See DOO-697.
 *
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
?>
<div id="comments" class="<?php print $classes; ?>"<?php print $attributes; ?>>

  <?php if ($content['comment_form']): ?>
    <h2 class="title comment-form"><?php print t('Add new comment'); ?></h2>
    <?php print render($content['comment_form']); ?>
  <?php endif; ?>

  <?php print render($content['comments']); ?>
</div>
