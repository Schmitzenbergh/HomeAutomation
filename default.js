//var counter = 0;
var hueStateOld = {};
var hueStateNew = {};

require('./config/var/src/db.paths');
//module.exports.repl.ignoreUndefined = true;

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

modRequest = require( pathlib + 'request.js' );

/*******\
| Start |###############################################################################################################################################################################
\*******/

setTimeout(function(){ require('./server'); 

//light.loadInfoAll();
//sensor.loadInfoAll();
  setInterval(function(){  
    console.log(counter++);
    //console.log(JSON.stringify(VarHolder));
    //light.getInfoAll();
    //sensor.getInfoAll();

    //if(( counter % 300) == 0 ){
    //  light.saveInfoAll();
    //  sensor.saveInfoAll();
    //}


  //console.log(JSON.stringify(modRequest.httpGET()));
  //console.log(test.httpGET());


function myNew(next){
    console.log("Im the one who initates callback");
    next("nope", "success");
}


myNew(function(err, res){
    console.log("I got back from callback",err, res);
});



  }, 2000);


}, 3000);

