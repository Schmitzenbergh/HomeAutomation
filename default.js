#!/usr/bin/env node

function VariablesDefault(){
  
  process.stdout.write( '\n' + "initialize HomeAutomation");
  
  exec = require('child_process').exec;
  

  pathroot = '/root/scripts/HomeAutomation/';
  pathconfig = pathroot + './config/';
  pathresources = pathroot + './resources/';
  pathlib = pathroot + './lib/';
  pathsrc = pathroot + './src/';
  
  module.exports = require( pathconfig + './init.js');
  module.exports = require( pathlib + './init.js');
  module.exports = require( pathresources + './init.js');
  module.exports = require( pathsrc + './init.js');

  process.stdout.write( '\n' + " initialize Done!.. " + '\n' );
};
module.exports = VariablesDefault();

//Everything runs from this function

var myInit = function() {

  console.log("       " + counter++ + " " );

  if ( counter == 1 || ( counter % 20 ) == 0 ){
    light.getInfoAll();
    sensor.getInfoAll();

  }
  
  if ( ( counter % 100 ) == 1 ){
    light.saveInfoAll();
    light.loadInfoAll();
  }

  if ( ( counter % 10 ) == 0 ){
    //light.setEffect(2, 'colorloop');
  }

  setTimeout(myInit, 100);
};  setTimeout(myInit, 2000);
