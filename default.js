require('./config/var/db.paths');
//module.exports.repl.ignoreUndefined = true;
<<<<<<< HEAD

//require('./config/var/db.var');
=======
require('./config/var/db.var.builder.js');
>>>>>>> parent of 65b2cc8... ...revert this, some msitake

path = require('path');
net = require('net');
http = require('http');
url = require('url');
fs = require('fs');

hue = require('hue-sdk');     //hue = require( pathresources + './hue-sdk/lib/hue.js'),
client = new hue.Hue(require( pathconfig + './.credentials.json' ));

require('./config/var/db.var.builder.js');

light = require( pathhuelight + 'light.js' );

avr = require( pathavrhk171s + 'default.js');
tv = require( pathsmarttv + 'tv.js' );

iArrayLightConnected =              [1, 2, 3, 4, 5, 6];
iArraySensorConnected =             [1, 2, 5, 6, 7, 8, 9, 10, 11];   

counter = 0;



/*******\
| Start |###############################################################################################################################################################################
\*******/

setTimeout(function(){ require('./server'); }, 2000);
setInterval(function(){  
  
  iArrayLightHueCur = counter++-20; 




}, 1000);



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












