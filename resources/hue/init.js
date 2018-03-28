#!/usr/bin/env node

function VariablesHue(){
  
  process.stdout.write( '\n' + " initialize Resources-Hue ");
  
  hue = require('hue-sdk');
  //hue = require( pathresources + './hue-sdk/lib/hue.js');
  client = new hue.Hue(require( pathconfig + './.credentials.json' ));
  
  pathhuebridge = pathhue + './bridge/';
  module.exports = require( pathhuebridge + './init.js');
 
  pathhuesensor = pathhue + './sensor/';
  module.exports = require( pathhuesensor + './init.js');
 
  pathhuelight = pathhue + './light/';
  module.exports = require( pathhuelight + './init.js');
  
};
VariablesHue();
 