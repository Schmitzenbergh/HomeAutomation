#!/usr/bin/env node

function VariablesDefaultC(){
  
  process.stdout.write( '\n' + " init c ");

  pathc1 = pathc + './1/';
  pathc2 = pathc + './2/';
  pathc3 = pathc + './3/';
  
  module.exports = require( pathc1 + './init.js');
  module.exports = require( pathc2 + './init.js');
  module.exports = require( pathc3 + './init.js');
};

//module.exports = VariablesDefault;
VariablesDefaultC();
