#!/usr/bin/env node

function VariablesResources(){
  
  //process.stdout.write( '\n' + " initialize Resources-RPi ");
  
  pathledstrip = pathrpi + './ledstrip/';
  module.exports = require( pathledstrip + './init.js');
  
};
VariablesResources();



