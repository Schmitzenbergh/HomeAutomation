#!/usr/bin/env node

module.exports = require('./init.js');

var counter = 0;
  
//var init = require('./init.js');init();
//Svar exec = require('child_process').exec;
//var execFile = require('child_process').execFile;

//init.Variables();
//init();

debug = false;

var myInit = function(){
    
    process.stdout.write('\n' + counter );
    
    if ( ( counter % 1 ) == 0 ){

        if ( ( counter % 10 ) == 0 ){
            //for ( x = 0; x < iArraySensorConnected.length; x++ ){ //process.stdout.write(" Update Sensor...");            //process.stdout.write(" #" + x + "...");
            //  sensor.getInfo(iArraySensorConnected[x]);
            //}
            
            for ( x = 0; x < iArrayLightConnected.length; x++ ){ //process.stdout.write(" Update Light #" + x + "..."); //process.stdout.write(" #" + x + "...");
                light.getInfo(iArrayLightConnected[x]);
            
                
                
            }
        }

    }
    
         if ( ( counter % 10 ) == 0 ){
            if (typeof iArraySensorLightLevel[8] !== 'undefined' ){ process.stdout.write( " " + iArraySensorLightLevel[8]); };
        }
    //process.stdout.write(" " + iArraySensorLightLevel[8] );
    
    if ( ( counter % 5 ) == 0 ){
        
        //light.getManufacturerName( counter );
        
        //exec("/bin/echo '" + "somevalue " + "' > " + pathresources  + "/hue/light/" + 1 + "/manufacturername" );
        
        if( iArraySensorLightLevel[8] < 10000 ){
            process.stdout.write(" zet aan ");
        //  exec("/bin/echo '1' > ./test" );
            
        } else {
            process.stdout.write(" zet uit ");
        //  exec("/bin/echo '0' > ./test" );
        }
    };
    
    
    //if (fs.existsSync("/root/")) {
    //      exec("/bin/echo '1' > " + "./rootmapgevonden" );
    //} else {
    //          exec("/bin/echo '0' > " + "./rootmapgevonden");
    //    }
    
    
    
    
    client.getLight( 1, function( err, result ){ if ( err || typeof result.manufacturername === undefined ) return err; sArrayLightManufacturerName[0] = result.manufacturername;    });
    
    
    //, ["apt-get","upgrade"]
   //light.getOn(1);
   process.stdout.write(" bArrayLightOn[0] " + sArrayLightManufacturerName[0] );
    
    counter++
    setTimeout(myInit, 5000);
    
    //Als er lampen branden

        
    //  if( bArrayLightOn[iArrayLightConnected[0]] ){
    //      process.stdout.write(" " + bArrayLightOn[iArrayLightConnected[0]] + " ");
    //      //exec("/bin/bash /usr/sbin/service ambilight start" );
    //  } else {
    //      //exec("/bin/bash /usr/sbin/service ambilight stop" );
    //  }
    
};
myInit();
