
COURSE IMPLEMENTATION PROMOTION CONTENTS (IN JSON)
==================================================
curl -H "Accept: application/json" http://example.com/api/v1/course_implementations?course_implementation_id=101472950

  {
    "nid": "43",
    "title": "Animal Biotechnology B (KEL/KEBIOT230)",
    "header_image_url": "http://example.com/sites/default/files/styles/liftup_322_x_190/public/images/default_images/default_image.jpg?itok=pa07al6G",
    "header_image_attribution": "Caption Test 060177afc4bc",
    "header_headline": "Title Test 0601a99ca05d",
    "header_text": "Description Test 06018fc576ac\r\n",
    "url": "http://example.com/courses/815058/101472950",
    "has_material": true,
    "moodle_url": "http://example.com"
  }


COURSE IMPLEMENTATION PROMOTION CONTENTS (IN XML)
=================================================
curl -H "Accept: application/xml" http://example.com/api/v1/course_implementations?course_implementation_id=101472950

  <?xml version="1.0" encoding="utf-8"?>
  <result>
    <nid>43</nid>
    <title>Animal Biotechnology B (KEL/KEBIOT230)</title>
    <header_image_url>http://example.com/sites/default/files/styles/liftup_322_x_190/public/course-header-images/course_implementation_image_21.png?itok=ECp5M2V7</header_image_url>
    <header_image_attribution>Caption Test 042171bad12c</header_image_attribution>
    <header_headline>Title Test 042146c18e80</header_headline>
    <header_text>Description Test 0421b31f6c6c</header_text>
    <url>http://example.com/courses/815058/101472950</url>
    <has_material>1</has_material>
    <moodle_url>http://example.com</moodle_url>
  </result>


COURSE IMPLEMENTATION ONE-OFF EVENTS (IN JSON)
==============================================
curl -H "Accept: application/json" http://example.com/api/v1/events?course_implementation_id=101472950,105227604

  [
    {
      "course_implementation_id":"101472950",
      "title":"Title: Test 04159adb2253",
      "begin":"2015-04-15T14:00:00Z",
      "end":"2015-04-15T15:00:00Z",
      "where":"Place: Test 04156f654df1",
      "exam": true
    },
    {
      "course_implementation_id":"105227604",
      "title":"testitapahtuma",
      "begin":"2015-09-26T01:30:00Z",
      "end":"2015-09-26T03:00:00Z",
      "where":"",
      "exam":false
    },
  ]


COURSE IMPLEMENTATION ONE-OFF EVENTS (IN XML)
=============================================
curl -H "Accept: application/xml" http://example.com/api/v1/events?course_implementation_id=101472950,105227604

  <?xml version="1.0" encoding="utf-8"?>
  <result is_array="true">
    <item>
      <course_implementation_id>101472950</course_implementation_id>
      <title>Title: Test 04159adb2253</title>
      <begin>2015-04-15T14:00:00Z</begin>
      <end>2015-04-15T15:00:00Z</end>
      <where>Place: Test 04156f654df1</where>
      <exam>1</exam>
    </item>
    <item>
      <course_implementation_id>105227604</course_implementation_id>
      <title>testitapahtuma</title>
      <begin>2015-09-26T01:30:00Z</begin>
      <end>2015-09-26T03:00:00Z</end>
      <where/>
      <exam/>
    </item>
  </result>


COURSE IMPLEMENTATION ACTIVITY (IN JSON)
========================================
curl -H "Accept: application/json" http://example.com/api/v1/course_implementation_activity?course_implementation_id=108501466,108480731,108425818&timestamp=2013-01-01T00:00:00Z&langcode=en

  [
    {
      "id": 1,
      "course_imp_id": 108501466,
      "message": "<p>admin has created one-off event &quot;Test event&quot;</p>",
      "user": "admin",
      "oodi_uid": 123,
      "timestamp": "2015-04-30T04:49:20Z",
      "type": "course_implementation_event_create"
    },
    {
      "id": 2,
      "course_imp_id": 108480731,
      "message": "<p>admin p\u00e4ivitti viesti\u00e4</p>",
      "user": "admin",
      "oodi_uid": 123,
      "timestamp": "2015-04-30T04:21:40Z",
      "type": "course_implementation_comment_update"
    },
    {
      "id": 3,
      "course_imp_id": 108480731,
      "message": "<p>admin has written an message</p>",
      "user": "admin",
      "oodi_uid": 123,
      "timestamp": "2015-04-30T04:21:24Z",
      "type": "course_implementation_comment_create"
    },
    {
      "id": 4,
      "course_imp_id": 108425818,
      "message": "<p>admin has written an message</p>",
      "user": "admin",
      "oodi_uid": 123,
      "timestamp": "2015-04-29T09:08:27Z",
      "type": "course_implementation_comment_create"
    }
  ]

Activity types:

course_implementation_comment_create
course_implementation_comment_remove
course_implementation_comment_update
course_implementation_course_conduct_create
course_implementation_course_conduct_remove
course_implementation_course_conduct_update
course_implementation_course_overview_accordion_target
course_implementation_event_create
course_implementation_event_remove
course_implementation_event_update
course_implementation_material_create
course_implementation_material_description_update
course_implementation_material_remove
course_implementation_material_update
course_implementation_private_comment_create
course_implementation_private_comment_remove
course_implementation_private_comment_update
course_implementation_task_create
course_implementation_task_remove
course_implementation_task_update
course_implementation_teacher_section_create
course_implementation_teacher_section_remove
course_implementation_teacher_section_update


ACCORDION TARGET URL PARAMETERS
===============================
One can link to a specific course implementation page accordion element by
providing an accordion target parameter in the URL. For example, calling
https://courses.helsinki.fi/123/456?group-course-messages will open the
Messages accordion and scroll the viewport to that accordion. The accordions
and their target parameters are as follows:

| Accordion name        | Target URL parameter         | Activity message type                                  |
|-----------------------|------------------------------|--------------------------------------------------------|
| Messages              | group-course-messages        | course_implementation_comment_create                   |
|                       |                              | course_implementation_comment_remove                   |
|                       |                              | course_implementation_comment_update                   |
|-----------------------|------------------------------|--------------------------------------------------------|
| Timetable             | group-timetable              | course_implementation_event_create                     |
|                       |                              | course_implementation_event_remove                     |
|                       |                              | course_implementation_event_update                     |
|-----------------------|------------------------------|--------------------------------------------------------|
| Material              | group-imp-material           | course_implementation_material_create                  |
|                       |                              | course_implementation_material_description_update      |
|                       |                              | course_implementation_material_remove                  |
|                       |                              | course_implementation_material_update                  |
|-----------------------|------------------------------|--------------------------------------------------------|
| Custom section        | group-custom-section         | course_implementation_teacher_section_create           |
|                       |                              | course_implementation_teacher_section_remove           |
|                       |                              | course_implementation_teacher_section_update           |
|-----------------------|------------------------------|--------------------------------------------------------|
| Conduct of the course | group-conduct-of-course      | course_implementation_course_conduct_create            |
|                       |                              | course_implementation_course_conduct_remove            |
|                       |                              | course_implementation_course_conduct_update            |
|-----------------------|------------------------------|--------------------------------------------------------|
| Feedback              | group-imp-feedback           | course_implementation_feedback_accordion_target        |
|-----------------------|------------------------------|--------------------------------------------------------|
| Registration and fee  | group-imp-fee                | course_implementation_fee_accordion_target             |
|-----------------------|------------------------------|--------------------------------------------------------|
| Course overview       | group-description-objectives | course_implementation_course_overview_accordion_target |
|-----------------------|------------------------------|--------------------------------------------------------|
| Tasks                 | group-course-task-material   | course_implementation_task_create                      |
|                       |                              | course_implementation_task_remove                      |
|                       |                              | course_implementation_task_update                      |
