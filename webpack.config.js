const path = require('path');

module.exports = {
    entry: './lib/js/src/index.js',
    output: {
        path: path.resolve(__dirname, 'dist'),
        filename: 'bundle.js'
    }
}