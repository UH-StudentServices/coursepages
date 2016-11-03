/**
 * @license GPL, or GNU General Public License, version 3
 * @license http://opensource.org/licenses/GPL-3.0
 * @see README.md how to contribute to this project
 */
function isMobile() {
  var mobile = false;
  var mobileUserAgents = ['Android', 'iPad', 'iPhone', 'iPod', 'Windows Phone'];
  mobileUserAgents.forEach(function(userAgent) {
    if (RegExp(userAgent, 'i').test(navigator.userAgent)) {
      mobile = true;
    }
  });
  return mobile;
}
