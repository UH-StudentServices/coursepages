<?php
/**
 * @file
 * uhc_tour.context.inc
 */

/**
 * Implements hook_context_default_contexts().
 */
function uhc_tour_context_default_contexts() {
  $export = array();

  $context = new stdClass();
  $context->disabled = TRUE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course_implementation_edit_tour';
  $context->description = 'Course implementation edit tour for teachers';
  $context->tag = 'Tours';
  $context->conditions = array(
    'uhc_tour_context_condition_demo_content' => array(
      'values' => array(
        'uhc_tour_context_condition_demo_content' => 'uhc_tour_context_condition_demo_content',
      ),
    ),
    'node' => array(
      'values' => array(
        'course_implementation' => 'course_implementation',
      ),
      'options' => array(
        'node_form' => '2',
      ),
    ),
  );
  $context->reactions = array(
    'joyride_add' => array(
      'joyride_auto_start' => 1,
      'joyride_play_once' => 0,
      'joyride_tour_content' => '<li data-text="Next" class="edit-group_imp_moodle">
  <h2>Course implementation editing tour</h2>
  <p>"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.".</p>
</li>

<li data-id="edit-group_imp_moodle" data-text="Next" class="edit-group_messages">
  <h2>edit moodle url</h2>
  <p>"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.".</p>
</li>

<li data-id="edit-group_messages" data-text="Next" class="edit-group_timetable">
  <h2>Edit messagesn</h2>
  <p>"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.".</p>
</li>

<li data-id="edit-group_timetable" data-text="Next" class="edit-group_imp_material">
  <h2>edit timetable</h2>
  <p>"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.".</p>
</li>

<li data-id="edit-field-imp-material-description" data-text="Next">
  <h2>edit Material</h2>
  <p>"Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat. Duis aute irure dolor in reprehenderit in voluptate velit esse cillum dolore eu fugiat nulla pariatur. Excepteur sint occaecat cupidatat non proident, sunt in culpa qui officia deserunt mollit anim id est laborum.".</p>
</li>
',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Course implementation edit tour for teachers');
  t('Tours');
  $export['course_implementation_edit_tour'] = $context;

  $context = new stdClass();
  $context->disabled = FALSE; /* Edit this to true to make a default context disabled initially */
  $context->api_version = 3;
  $context->name = 'course_implementation_tour';
  $context->description = 'Course implementation tour for teachers';
  $context->tag = 'Tours';
  $context->conditions = array(
    'node' => array(
      'values' => array(
        'course_implementation' => 'course_implementation',
      ),
      'options' => array(
        'node_form' => '0',
      ),
    ),
    'uhc_tour_context_condition_demo_content' => array(
      'values' => array(
        'uhc_tour_context_condition_demo_content' => 'uhc_tour_context_condition_demo_content',
      ),
    ),
  );
  $context->reactions = array(
    'joyride_add' => array(
      'joyride_auto_start' => 1,
      'joyride_play_once' => 0,
      'joyride_tour_content' => '<li class="group-description-objectives" data-class="ds-node-metadata" data-text="Next">
  <h2>Header</h2>
  <p>This information is imported from WebOodi and can not be edited here.</p>
</li>

<li data-class="is-active" data-text="Next">
  <h2>Course Overview</h2>
  <p>This information is imported from WebOodi and can not be edited here.</p>
</li>

<li class="joyride-moodle" data-class="ds-node-banner"  data-text="Next">
  <h2>Promotion</h2>
  <p>Use this area for promoting the course to students. You can also add your own image.</p>
</li>

<li class="group-course-messages" data-class="moodle-button"  data-text="Next">
  <h2>moodle</h2>
  <p>The teacher may add the link to the Moodle course area.</p>
</li>

<li class="group-imp-interaction" data-class="is-active" data-text="Next">
  <h2>Messages</h2>
  <p>Messages might be public or restricted to course\'s participants only</p>
</li>

<li class="group-timetable" data-class="is-active"  data-text="Next">
  <h2>Interaction</h2>
  <p>The teacher may specify how the students are able to interact online in this course.</p>
</li>

<li class="group-imp-material" data-class="is-active" data-text="Next">
  <h2>Timetable</h2>
  <p>The timetable consists of events imported from WebOodi as well as events added in the course page</p>
</li>

<li class="group-imp-video" data-class="is-active" data-text="Next">
  <h2>Material</h2>
  <p>Material may consist of attachments, links or references, divided into different sections.</p>
</li>

<li class="group-course-task-material" data-class="is-active" data-text="Next">
  <h2>Video</h2>
  <p>Videos can be either linked or embedded.</p>
</li>

<li class="group-custom-section" data-class="is-active" data-text="Next">
  <h2>Tasks</h2>
  <p>Tasks may consist of written instruction and material provided by the teacher. Students are not able to submit their papers via course page.</p>
</li>

<li class="group-conduct-of-course" data-class="is-active" data-text="Next">
  <h2>Custom Section</h2>
  <p>The custom section may consist of text and links and the label written by the teacher.</p>
</li>

<li data-class="is-active" data-text="Next">
  <h2>Conduct of the course</h2>
  <p>The teacher may specify how the course is conducted and how the students are evaluated.</p>
</li>

<li data-class="edit-link" class="joyride-edit-link" data-text="Next">
  <h2>Edit</h2>
  <p>Switch to edit mode.</p>
</li>

<li class="joyride-logout-link" data-class="logout-link" data-text="Next">
  <h2>Logout</h2>
  <p>Remember to logout!</p>
</li>',
    ),
  );
  $context->condition_mode = 1;

  // Translatables
  // Included for use with string extractors like potx.
  t('Course implementation tour for teachers');
  t('Tours');
  $export['course_implementation_tour'] = $context;

  return $export;
}
