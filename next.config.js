const withTM = require('next-transpile-modules')([
  'bs-platform',
  're-classnames',
  '@jsiebern/bs-material-ui',
  '@mscharley/bs-material-ui-icons',
  'bs-css',
]);

module.exports = withTM({
  pageExtensions: ['jsx', 'js', 'bs.js', 'tsx'],
});
