#!/usr/bin/env node

function VariablesDefaultB(){
  
  process.stdout.write( '\n' + " init b ");

  pathb1 = pathb + './1/';
  pathb2 = pathb + './2/';
  pathb3 = pathb + './3/';
  
  module.exports = require( pathb1 + './init.js');
  module.exports = require( pathb2 + './init.js');
  module.exports = require( pathb3 + './init.js');
};

//module.exports = VariablesDefault;
VariablesDefaultB();
