#!/usr/bin/env node

function VariablesDefault(){
  
  process.stdout.write( '\n' + "initialize HomeAutomation");
  
  pathroot = '/root/scripts/HomeAutomation/';
  pathconfig = pathroot + './config/';
  pathresources = pathroot + './resources/';
  pathlib = pathroot + './lib/';
  module.exports = pathsrc = pathroot + './src/';
  
  module.exports = require( pathconfig + './init.js');
  module.exports = require( pathlib + './init.js');
  module.exports = require( pathresources + './init.js');
  module.exports = require( pathsrc + './init.js');

  process.stdout.write( '\n' + " initialize Done!.. " + '\n' );
};
module.exports = VariablesDefault();
//Everything runs from this function

var myInit = function() {

  counter++;
  
  if ( ( counter % 25 ) == 0 ){
    light.getInfoAll();
    sensor.getInfoAll();
  }
  if ( ( counter % 20 ) == 0 ){

    //console.log( "ArrayLight: " + sArrayLightManufacturerName[1]);
    //console.log( "ArraySensor: " + sArraySensorManufacturerName[1]);
    //console.log( '\n' )

  }

  if ( ( counter % 5 ) == 0 ){
      //console.log ( "Function: " + light.getManufacturerName(1) );
      //console.log( "endval: " + light.getManufacturerName(1) );
      //console.log( "endval: " + light.getManufacturerName(1, result ) );
      
  }


  //  Hue.prototype.get = function get(opts, cb) {
  //    if (typeof opts === 'string')
  //      opts = {path: opts};
  //    opts.method = 'GET';
  //  
  //    return this.request(opts, cb);
  //  };

  //exports.statusLightGetOn = function(iLightNumber){ client.get('/lights/' + iLightNumber + '/', function (err, result) { if (err) throw err; this.retVal = result.state.on; }); return this.retVal; };
  
  
  //function statusLightGetOn(iLightNumber){ client.get('/lights/' + iLightNumber + '/', function (err, result) { if (err) throw err; this.retVal = result.state.on; }); return this.retVal; };
  //statusLightGetOn = function( iLightNumber, retVal){ client.get('/lights/' + iLightNumber + '/', function (err, result) { if (err) throw err; this.retVal = result.state.on; }); return this.retVal; };




  console.log( statusLightGetOn(1) );
  //light.statusLightGetOn(1);
  //light.getManufacturerName(1);
  process.stdout.write('.');
  setTimeout(myInit, 1000);
};
setTimeout(myInit, 2000);


//var getLightOn = function(callback) {
//  client.get('/lights/1/', function (err, result) {
//    callback(result.state.on);
//  });
//};
//
//
//var myCallback = function(data) {
//  console.log(data);
//};
//getLightOn(myCallback)


