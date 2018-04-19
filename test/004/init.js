#!/usr/bin/env node

function VariablesDefault(){
  
  process.stdout.write( '\n' + " init Main ");
  
  pathroot = '/root/scripts/Testing/';       //  sVariableName = typeof sVariableName !== undefined ? sVariableName : "DefaultStartValue";
  patha = pathroot + './a/';
  pathb = pathroot + './b/';
  pathc = pathroot + './c/';
  
  module.exports = require( patha + './init.js');
  module.exports = require( pathb + './init.js');
  module.exports = require( pathc + './init.js');
};

//VariablesDefault();
module.exports = VariablesDefault;
