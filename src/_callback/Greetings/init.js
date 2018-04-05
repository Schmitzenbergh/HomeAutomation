#!/usr/bin/env node

//module.exports = pathbridge = pathhue + './bridge/';
//module.exports = pathlight = pathhue + './light/';
//module.exports = pathsensor = pathhue + './sensor/';
//
//module.exports = require( pathbridge + './init.js');
//module.exports = require( pathlight + './init.js');
//module.exports = require( pathsensor + './init.js');



var Variables = function(){
  
  credentials = pathconfig + './.credentials.json';
  
  hue = require( pathsrc + './hue-sdk' );
  client = new hue.Hue( require( credentials ) );
  
  sensor = require( pathresources + './sensor.js' );
  light = require( pathresources + './light.js' );
  
  fs = require('fs');
  exec = require( 'child_process' ).exec;
  
  debug = false;  //debug = process.argv[2];
  
  i = 0;
};

module.exports = init;
