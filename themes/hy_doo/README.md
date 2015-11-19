Helsingin Yliopisto subtheme - DOO (hy_doo)
===========================================

Requirements:
  - Nodejs (npm)
  - Grunt (bundle update for theme specific dependencies)
  - HY base theme (subtheme from OMEGA[4] theme)

About:
  The theme has references to the main theme folder for global mixin usage with
  override/legacy mixins from previous iterations which also applies to the
  variables. The goal is to be able to duplicate this theme for additional
  subthemes in future projects which also rely on the main HY theme.

Getting started:
  - Change directory to this theme directory
  - Install required libraries with bundle
      $ bundle install
  - Update dependencies
      $ sudo npm install -g grunt-cli
      $ npm install grunt --save-dev
      $ npm update --save-dev
  - Then initialize SASS watcher
      $ grunt watch
