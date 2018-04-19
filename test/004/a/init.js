#!/usr/bin/env node

function VariablesDefaultA(){
  
  process.stdout.write( '\n' + " init a ");

  patha1 = patha + '1/';
  patha2 = patha + '2/';
  patha3 = patha + '3/';
  
  
  
  module.exports = require( patha1 + './init.js');
  module.exports = require( patha2 + './init.js');
  module.exports = require( patha3 + './init.js');
};

//module.exports = VariablesDefault;
//VariablesDefaultA();

//var VariablesDefaultA = function(){
//  
//  process.stdout.write( '\n' + " init a ");
//
//  patha1 = patha + '1/';
//  patha2 = patha + '2/';
//  patha3 = patha + '3/';
//  
//  module.exports = require( patha1 + './init.js');
//  module.exports = require( patha2 + './init.js');
//  module.exports = require( patha3 + './init.js');
//};

//module.exports = VariablesDefault;
VariablesDefaultA();

