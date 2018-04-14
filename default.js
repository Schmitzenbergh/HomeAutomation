require('./config/var/db.paths');
//module.exports.repl.ignoreUndefined = true;



path = require('path');
net = require('net');
http = require('http');
url = require('url');
fs = require('fs');

hue = require('hue-sdk');     //hue = require( pathresources + './hue-sdk/lib/hue.js'),
client = new hue.Hue(require( pathconfig + './.credentials.json' ));

require('./config/var/db.var.builder.js');
require('./config/var/db.var');

sensor = require( pathhuesensor + 'sensor.js' );
light = require( pathhuelight + 'light.js' );
avr = require( pathavrhk171s + 'default.js');
tv = require( pathsmarttv + 'tv.js' );

/*******\
| Start |###############################################################################################################################################################################
\*******/

setTimeout(function(){ require('./server'); 

  setInterval(function(){  
    counter++;
    light.getInfoAll();
    sensor.getInfoAll();
  }, 1000);


}, 2000);




//var myvars = {};
//var myString1 = "test1";
//var myString2 = "test2";
//var myString3 = "test3";
//var myString4 = "test4";

//SetTo5("test");
//
//function SetTo5(varString) {
//  var newValue = 5;
//  eval(varString + " = " + newValue);
//  console.log(test)
//}
//testing = 10;
//myvars[myString1] = '4';
//myvars[myString2] = '3';
//myvars[myString3] = '2';
//myvars[myString4] = '1';
//console.log(myvars);
//console.log(myvars.myString2);
//console.log(myvars.myString3);
//console.log(myvars.myString4);











