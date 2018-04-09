
require('./config/localpaths.js');

var net = require('net');

hue = require('hue-sdk');     //hue = require( pathresources + './hue-sdk/lib/hue.js'),
client = new hue.Hue(require( pathconfig + './.credentials.json' ));

counter = 1;
//module.exports.repl.ignoreUndefined = true;

light = require( pathhuelight + 'light.js' );
avr = require( pathavrhk171s + 'default.js');


setTimeout(startServer, 2000);


function startServer(){
    server = require('./server');
}


//var tv = require( pathsmarttv + 'tv.js' ),
//tv.postInputKeyVolumeUp(),
//server = require('./server.js');

