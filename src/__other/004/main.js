#!/usr/bin/env node

var counter = 0;
  
//var init = require('./init.js');
////init.Variables();
//init();

debug = false;

var myInit = function(){
    
	process.stdout.write('\n' + counter );
	
    if ( ( counter % 5 ) == 0 ){

		process.stdout.write(" Update Sensor...");
		for ( x = 0; x < iArraySensorConnected.length; x++ ){ 
			process.stdout.write(" #" + x + "...");
			sensor.getInfo(iArraySensorConnected[x]);
		}

		process.stdout.write(" Update Light #" + x + "...");
		for ( x = 0; x < iArrayLightConnected.length; x++ ){ 
			process.stdout.write(" #" + x + "...");
			light.getInfo(iArrayLightConnected[x]);
		}
	}

	

  if (typeof iArraySensorLightLevel[8] !== 'undefined' ){ process.stdout.write( " " + iArraySensorLightLevel[8]); };

  counter++
  setTimeout(myInit, 1000);
};
myInit();




//    sensor.getLightLevel(8);
//    console.log(iArraySensorLightLevel[8])
//    
//    if ( iArraySensorLightLevel[8] < 15000 ){
//        console.log("lager");
//    } else {
//        console.log("hoger");
//    }

    //sensor.getTemperature(6);
    //sensor.getButtonevent(5);
    //sensor.getLastupdated(5);
    
    

//}

//usingItNow(myCallback);
//var myCallback = function(data){ console.log('got data: '+data); };
//var usingItNow = function(callback){ callback('get it?'); };
//
//
//var myCallback = data();
//var usingItNow = callback();
//function data(){ console.log('got data: '+data); };
//function callback(){ callback('get it?'); };

//light.setOn(iLightNumber );
//light.setOn(iLightNumber,false);
//light.setOff(iLightNumber );

//light.setBri(iLightNumber,10);
//light.setBriDec(iLightNumber );
//light.setBriDec(iLightNumber,10);
//light.setBriInc(iLightNumber );

//console.log(sVariableName);

