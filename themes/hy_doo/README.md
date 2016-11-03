Helsingin Yliopisto DOO theme (hy_doo)
===========================================

Requirements:
  - Nodejs (npm)

About:
  Fonts and scss assets come from the Helsinki University styleguide.
  these are installed with bower and gulp.

Getting started:
  - Change directory to this theme directory
  - Install npm packages
      $ npm install
  - Install HY Styleguide
      $ gulp styleguide-update
  - Initialize SASS watcher
      $ gulp watch
  - Automatically reload changes in your browser (disable css caching in drupal first)
      $ gulp browsersync
