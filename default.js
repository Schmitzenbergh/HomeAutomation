//var counter = 0;
var hueStateOld = {};
var hueStateNew = {};

require('./config/var/src/db.paths');
//module.exports.repl.ignoreUndefined = true;
module.exports = VarHolder = {};
exec = require('child_process').exec;
fs = require('fs');
net = require('net');
http = require('http');
https = require("https");
path = require('path');
request = require('request');
url = require('url');

hue = require('hue-sdk');     //hue = require( pathresources + './hue-sdk/lib/hue.js'),
client = new hue.Hue(require( pathconfig + './.credentials.json' ));

require('./config/var/db.var.builder.js');
require('./config/var/db.var');

sensor = require( pathhuesensor + 'sensor.js' );
light = require( pathhuelight + 'light.js' );
avr = require( pathavrhk171s + 'default.js');
tv = require( pathsmarttv + 'tv.js' );
server = require( pathserver + 'server.js' );

test = require( pathlib + 'http.js' );

/*******\
| Start |###############################################################################################################################################################################
\*******/

setTimeout(function(){ require('./server'); 

  var options = {
    hostname: '192.168.0.97',
    port: 1925,
    path: '/5/ambilight/processed',
    method: 'GET',
    headers: {
      'Content-Type': 'text/html',
      'Content-Length': Buffer.byteLength("")
    }
  };


//light.loadInfoAll();
//sensor.loadInfoAll();
  setInterval(function(){  
    console.log(counter++);
    console.log(JSON.stringify(VarHolder));
    //light.getInfoAll();
    //sensor.getInfoAll();

    //if(( counter % 300) == 0 ){
    //  light.saveInfoAll();
    //  sensor.saveInfoAll();
    //}
    //require( pathlib + 'http.js' );
    //    test.httpGET('192.168.0.97', 1925, '/5/ambilight/processed');
    //    console.log(" " + counter + test.httpGET('192.168.0.97', 1925, '/5/ambilight/processed'));

  console.log(test.httpGET());
  //console.log(test.httpGET());




  }, 500);


}, 3000);


//var http = require("http");
//var options = {
//  hostname: '192.168.0.97',
//  port: 1925,
//  path: '/5/ambilight/processed',
//  method: 'GET',
//  headers: {
//    'Content-Type': 'text/html',
//    'Content-Length': Buffer.byteLength("")
//  }
//};
//
//var req = http.request(options, (res) => {
//  res.on('data', (chunk) => { Result = "" + chunk;});
//  //res.on('end', () => {});
//});
//
////console.log(tempResult);
//// write data to request body
////req.write("abc");
//req.end();

