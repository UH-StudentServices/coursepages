Helsingin Yliopisto DOO theme (hy_doo)
===========================================

Requirements:
  - Nodejs (npm)

About:
  Fonts and scss assets come from the Helsinki University styleguide.
  these are installed with bower and gulp.

Getting started (for development):
  - Change directory to this theme directory
  - Install npm packages (to install bower and gulp)
      $ npm install
  - Install bower dependencies like HY Styleguide
      $ npm run gulp styleguide-update
  - Optional: Initialize SASS watcher
      $ npm run gulp watch
  - Optional: Automatically reload changes in your browser (disable css caching in drupal first)
      $ npm run gulp browsersync
