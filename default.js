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

httpRequests = require( pathlib + 'httpRequests.js' );
httpPost = require( pathlib + 'httpPost.js' );
httpGet = require( pathlib + 'httpGet.js' );




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

  //Object.assign()
  //tempObj = { ,
  //'test': tv.returnPowerstate()}
 

  //fs.writeFileSync( "./JSONdb.var", JSON.stringify(tv.returnPowerstate()) );
  //fs.appendFileSync( "./JSONdb.var", JSON.stringify(tv.returnActivitiesTv()) );
 
 
  //console.log( fs.readFileSync( "./JSONdb.var", 'UTF8'));
  //tempObj[0] = tv.returnPowerstate();
  //tempObj[1] = tv.returnAmbilightCached();
//
  //console.log(tempObj);


//Object.assign(tv.returnActivitiesTv
//Object.create(person)
 console.log(tv.returnJSONObjAll()); 

  }, 5000);


}, 3000);

