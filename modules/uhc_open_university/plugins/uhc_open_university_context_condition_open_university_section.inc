<?php
/**
 * @file
 * Implementation class for plugin determining when we're at open university
 * context.
 */

class uhc_open_university_context_condition_open_university_section extends context_condition {

  function condition_values() {
    return array(
      'uhc_open_university_context_condition_open_university_section' => t('Check if we are on Open university section (course page, implementation page)')
    );
  }

  /**
   * Callback for executing and matching condition whether we are on Open
   * university section (course page, implementation page).
   */
  function execute($node) {
    if ($this->is_open_university_course_or_implementation($node)) {
      foreach ($this->get_contexts() as $context) {
        $this->condition_met($context);
      }
    }
  }

  /**
   * Is the given node Open university course or course implementation?
   *
   * @param $node object Node.
   * @return bool TRUE if the node is Open university course or course
   * implementation node, otherwise FALSE.
   */
  private function is_open_university_course_or_implementation($node) {

    // If node type is course and there's migration source set
    if ($node->type == 'course') {

      // Loop over each course implementation to find if one of them belongs to
      // open university.
      $field_imp_reference_to_courses = field_get_items('node', $node, 'field_imp_reference_to_courses');
      if (!empty($field_imp_reference_to_courses)) {
        foreach ($field_imp_reference_to_courses as $field_imp_reference_to_course) {
          // If node can be loaded and it belongs to open university, then
          // return TRUE indicating that we're in the context.
          $course_imp_node = node_load($field_imp_reference_to_course['target_id']);
          if ($course_imp_node && uhc_sources_is_from_organisation($course_imp_node, 'H930') === TRUE) {
            return TRUE;
          }
        }
      }

      // If we get to this, it means that we got a course node which has no
      // course implementations having open university organisation code listed.
      return FALSE;
    }
    elseif ($node->type == 'course_implementation') {
      return uhc_sources_is_from_organisation($node, 'H930');
    }
    elseif ($node->type == 'portal_page') {
      return field_get_items('node', $node, 'field_liftup_section')[0]['value'] == 'openuniversity';
    }

    // If we get to this, it means that we have tried to call this method with a
    // node from which we can't say whether it's from open university or not.
    return FALSE;
  }
}
