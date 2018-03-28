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
  
  if ( ( counter % 5 ) == 0 ){
    //sensor.saveInfoAll();
    //sensor.getInfoAll();
    //sensor.fetchInfo();
    //light.fetchInfo();

    sensor.setInfo(4);
  }


  //if ( iArraySensorTemperature[6] !== undefined ){
  //  if ( ( counter % 10 ) == 0 ){
  //    //console.log(light.sArrayLightManufacturerName[1]);
	//    process.stdout.write('\n' + "Last: " + sArraySensorLastupdated[5] + " Button: " + iArraySensorButtonEvent[5] + " Temp: " + iArraySensorTemperature[6]);
  //  }
  //}

  //light.getManufacturerName(1);
  process.stdout.write('.');
  setTimeout(myInit, 1000);
};
setTimeout(myInit, 2000);



