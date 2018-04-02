#!/usr/bin/env node

function VariablesResources(){
  
  process.stdout.write( '\n' + " initialize Resources ");
  
  pathhue = pathresources + './hue/';
  pathrpi = pathresources + './RPi/';
  pathavr = pathresources + './avr/';
  
  module.exports = require( pathhue + './init.js');
  module.exports = require( pathrpi + './init.js');
  //module.exports = require( pathavr + './init.js');
    
};
VariablesResources();



