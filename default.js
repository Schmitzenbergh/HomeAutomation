require('./config/var/db.paths');
//module.exports.repl.ignoreUndefined = true;

//require('./config/var/db.var');

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

teststring = "sometestvaluehere";

/*******\
| Start |###############################################################################################################################################################################
\*******/

setTimeout(function(){ require('./server');
//light.getInfoAll();
 }, 2000);

//setInterval(function(){  
//  iArrayLightHueCur = counter++-20; 
//
//}, 2000);



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









//  exports.returnArrayValue = function(sVariableName, iPosition){  "use strict"
//    let temparr = global[sVariableName];
//  
//    console.log(temparr instanceof Array);
//    if (iPosition){
//      return temparr[iPosition];
//    } else {
//      return temparr;
//    }
//    
//  };  
//  //sArrayLightAlert[0] = "sometestexample";
//  console.log(returnArrayValue("sArrayLightAlert", 0));



