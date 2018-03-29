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

  counter++;
  
  if ( ( counter % 20 ) == 0 ){
    light.getInfoAll();
    sensor.getInfoAll();
    light.saveInfoAll();
  }

  if ( ( counter % 3 ) == 0 ){
    if ( sArrayLightManufacturerName[1] !== undefined) { 
      console.log( "ArrayLight: " + sArrayLightManufacturerName[1] + '\n' );
    }
  }

//  if ( ( counter % 3 ) == 0 ){
//      //console.log ( "Function: " + light.getManufacturerName(1) );
//      console.log( "endval: " + light.getManufacturerName(1) );
//      //console.log( "endval: " + light.getManufacturerName(1, result ) );
//      
//  }


  //TEST
  if ( ( counter % 5 ) == 0 ){

    //fs.writeFile("test4", "Hey there!", function(err) { if(err) { return console.log(err); } console.log("The file was saved!"); }); };
    //fs.writeFile( pathhuelightvalues + "1" + "/manufacturername",  sArrayLightManufacturerName[1], function(err) { if(err) { return console.log(err); } console.log("The file was saved!"); }); };


  //  Hue.prototype.get = function get(opts, cb) {
  //    if (typeof opts === 'string')
  //      opts = {path: opts};
  //    opts.method = 'GET';
  //  
  //    return this.request(opts, cb);
  //  };

  //exports.statusLightGetOn = function(iLightNumber){ client.get('/lights/' + iLightNumber + '/', function (err, result) { if (err) throw err; this.retVal = result.state.on; }); return this.retVal; };
  
  
  //function statusLightGetOn(iLightNumber){ client.get('/lights/' + iLightNumber + '/', function (err, result) { if (err) throw err; this.retVal = result.state.on; }); return this.retVal; };
  //statusLightGetOn = function( iLightNumber){ client.get('/lights/' + iLightNumber + '/', function (err, result) { if (err) throw err; this.retVal = result.state.on; }); return this.retVal; };




  //console.log( light.statusLightGetOn(1) );
  //light.statusLightGetOn(1);
  //light.getManufacturerName(1);
  //process.stdout.write('.');
  }
  
  setTimeout(myInit, 1000);
};
setTimeout(myInit, 4000);



