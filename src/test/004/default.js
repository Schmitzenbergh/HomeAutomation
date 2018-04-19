#!/usr/bin/env node

process.stdout.write( '\n' + " Start: ");
var init = require('./init.js');
init();

//init.VariablesDefault();


console.log(" ");


var myInit = function() {
    
  //console.log(light.sArrayLightManufacturerName[1]);
	//sensor.getTemperature(6);
	//sensor.getButtonevent(5);
	//sensor.getLastupdated(5);
  console.log(counter++);

  
//console.log("pathhue:" + pathhue);
//console.log("pathroot:" + pathroot);
//
  
  
  
  
  
	setTimeout(myInit, 2000);
};
setTimeout(myInit, 2000);	//myInit();

















//if ( ( counter % 5 ) == 0){
//do {
//process.stdout.write('\n' + " Update Sensor...");
//for ( x = 0; x < iArraySensorConnected.length; x++ ){ 
//  process.stdout.write(" #" + x + "...");
//  sensor.getInfo(iArraySensorConnected[x]);
//}
//
//process.stdout.write('\n' + " Update Light #" + x + "...");
//for ( x = 0; x < iArrayLightConnected.length; x++ ){ 
//  process.stdout.write(" #" + x + "...");
//  light.getInfo(iArrayLightConnected[x]);
//}
//  process.stdout.write(".");
//}
//while ( sArrayLightManufacturerName === undefined) ;
//
//
//    
//  //};  
//
//
//
//
//
//
//var myInit = function() {
//    
//  //console.log(light.sArrayLightManufacturerName[1]);
//	//sensor.getTemperature(6);
//	//sensor.getButtonevent(5);
//	//sensor.getLastupdated(5);
//  console.log(counter++);
//  
//  console.log( "1" + sArrayLightName[1] + sArrayLightName[2] + sArrayLightName[3]);
//  
//  
//  console.log("pathhue:" + pathhue);
//  console.log("pathroot:" + pathroot);
//
//  
//  
//	setTimeout(myInit, 1000);
//};
//setTimeout(myInit, 2000);	//myInit();