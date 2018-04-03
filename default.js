

counter = 1;


pathroot = '/root/scripts/HomeAutomation/';
    
    pathconfig = pathroot + './config/';

    pathresources = pathroot + './resources/';
    
        pathavr = pathresources + './avr/';

        pathhue = pathresources + './hue/';
            
            pathhuebridge = pathhue + './bridge/';                 //  pathbridge = pathhue + './bridge/';
            pathhuebridgevalues = pathhuebridge + './_values/';

            pathhuesensor = pathhue + './sensor/';                 //  pathsensor = pathhue + './sensor/';
            pathhuesensorvalues = pathhuesensor + './_values/';

            pathhuelight = pathhue + './light/';                   //  pathlight = pathhue + './light/';
            pathhuelightvalues = pathhuelight + './_values/';

        pathrpi = pathresources + './RPi/';  

    pathlib = pathroot + './lib/';

    pathsrc = pathroot + './src/';
    


 /***************
  *    Lights    *
  ***************/
 iArrayLightConnected = [1, 2, 3, 4, 5, 6];
  
 //General attributes 
 sArrayLightManufacturerName = [''];   //                                                  //if ( typeof sArrayLightManufacturerName[i]     !== undefined){ process.stdout.write(" " + sArrayLightManufacturerName[i] ); };  
 sArrayLightProductname = [''];        //                                                  //if ( typeof sArrayLightProductname[i]          !== undefined){ process.stdout.write(" " + sArrayLightProductname[i]        ); }; 
 sArrayLightModelid = [''];            //                                                  //if ( typeof sArrayLightModelid[i]              !== undefined){ process.stdout.write(" " + sArrayLightModelid[i]             ); };
 sArrayLightName = ['', 'LightName'];  //                                                  //if ( typeof sArrayLightName[i]                 !== undefined){ process.stdout.write(" " + sArrayLightName[i]                ); };
 sArrayLightSwversion = [''];          //                                                  //if ( typeof sArrayLightSwversion[i]            !== undefined){ process.stdout.write(" " + sArrayLightSwversion[i]           ); };
 sArrayLightType = [''];               //                                                  //if ( typeof sArrayLightType[i]                 !== undefined){ process.stdout.write(" " + sArrayLightType[i]                ); };
 sArrayLightUniqueid = [''];           //                                                  //if ( typeof sArrayLightUniqueid[i]             !== undefined){ process.stdout.write(" " + sArrayLightUniqueid[i]            ); };
 bArrayLightOn = [''];                 // true, false                                      //if ( typeof bArrayLightOn[i]                   !== undefined){ process.stdout.write(" " + bArrayLightOn[i]                ); };
 bArrayLightReachable = [''];          // true, false                                      //if ( typeof bArrayLightReachable[i]            !== undefined){ process.stdout.write(" " + bArrayLightReachable[i]        ); }; 
 sArrayLightAlert = [''];              // none, select, lselect                            //if ( typeof sArrayLightAlert[i]                !== undefined){ process.stdout.write(" " + sArrayLightAlert[i]            ); }; 
 sArrayLightColorMode = [''];          // hs, xy, ct                                       //if ( typeof sArrayLightColorMode[i]            !== undefined){ process.stdout.write(" " + sArrayLightColorMode[i]        ); }; 
 sArrayLightEffect = [''];             // none, colorloop                                  //if ( typeof sArrayLightEffect[i]               !== undefined){ process.stdout.write(" " + sArrayLightEffect[i]            ); };
 iArrayLightTransitionTime = [''];     // multiple of 100ms and defaults to 4 (400ms)      //if ( typeof iArrayLightTransitionTime[i]       !== undefined){ process.stdout.write(" " + iArrayLightTransitionTime[i]   ); };

 
 //Color attributes (Currrent)            // Color attributes (New)            // Color attributes (Old)             // xy > ct > hs
 fArrayLightXyCur = [''];                 fArrayLightXyNew = [''];             fArrayLightXyOld = [''];          // 0.000 - 1.000          //if ( typeof fArrayLightXyCur[i]             !== undefined){ process.stdout.write(" " + fArrayLightXyCur[i]            ); };         
 fArrayLightXyXCur = [''];                fArrayLightXyXNew = [''];            fArrayLightXyXOld = [''];          // 0.000 - 1.000         //if ( typeof fArrayLightXyXCur[i]            !== undefined){ process.stdout.write(" " + fArrayLightXyXCur[i]            ); };     
 fArrayLightXyYCur = [''];                fArrayLightXyYNew = [''];            fArrayLightXyYOld = [''];          // 0.000 - 1.000         //if ( typeof fArrayLightXyYCur[i]            !== undefined){ process.stdout.write(" " + fArrayLightXyYCur[i]            ); };     
 iArrayLightCtCur = [''];                 iArrayLightCtNew = [''];             iArrayLightCtOld = [''];           // 153 - 500             //if ( typeof iArrayLightCtCur[i]             !== undefined){ process.stdout.write(" " + iArrayLightCtCur[i]            ); };     
 iArrayLightHueCur = [''];                iArrayLightHueNew = [''];            iArrayLightHueOld = [''];          // 0 - 65535             //if ( typeof iArrayLightHueCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightHueCur[i]            ); };     
 iArrayLightSatCur = [''];                iArrayLightSatNew = [''];            iArrayLightSatOld = [''];          // 0 - 254               //if ( typeof iArrayLightSatCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightSatCur[i]            ); };     
 iArrayLightBriCur = [''];                iArrayLightBriNew = [''];            iArrayLightBriOld = [''];          // 1-254                 //if ( typeof iArrayLightBriCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightBriCur[i]            ); };     
 iArrayLightRgbRedCur = [''];             iArrayLightRgbRedNew = [''];         iArrayLightRgbRedOld = [''];       // 0 - 254               //if ( typeof iArrayLightRgbRedCur[i]         !== undefined){ process.stdout.write(" " + iArrayLightRgbRedCur[i]        ); };     
 iArrayLightRgbGreenCur = [''];           iArrayLightRgbGreenNew = [''];       iArrayLightRgbGreenOld = [''];     // 0 - 254               //if ( typeof iArrayLightRgbGreenCur[i]       !== undefined){ process.stdout.write(" " + iArrayLightRgbGreenCur[i]        ); }; 
 iArrayLightRgbBlueCur = [''];            iArrayLightRgbBlueNew = [''];        iArrayLightRgbBlueOld = [''];                               //if ( typeof iArrayLightRgbBlueCur[i]        !== undefined){ process.stdout.write(" " + iArrayLightRgbBlueCur[i]        ); };  


  /***************
  *    Sensors   *
  ***************/
 iArraySensorConnected = [1, 2, 5, 6, 7, 8, 9, 10, 11];        //i++; if ( i == 3 ){ i = 5; } else if ( i == 11 ){ i = 1; } sensor.getInfo(i);
 
 //sensor.getLightLevel(8);
 //sensor.getTemperature(6);
 //sensor.getButtonevent(5);
 //sensor.getLastupdated(5);

 sArraySensorName = [''];                  //if (typeof sArraySensorName[i]               !== undefined){ process.stdout.write(" " + sArraySensorName[i]); };
 sArraySensorType = [''];                  //if (typeof sArraySensorType[i]               !== undefined){ process.stdout.write(" " + sArraySensorType[i]); };
 sArraySensorModelId = [''];               //if (typeof sArraySensorModelId[i]            !== undefined){ process.stdout.write(" " + sArraySensorModelId[i]); };
 sArraySensorManufacturerName = [''];      //if (typeof sArraySensorManufacturerName[i]   !== undefined){ process.stdout.write(" " + sArraySensorManufacturerName[i]); };
 sArraySensorSwVersion = [''];             //if (typeof sArraySensorSwVersion[i]          !== undefined){ process.stdout.write(" " + sArraySensorSwVersion[i]); };
 sArraySensorUniqueId = [''];              //if (typeof sArraySensorUniqueId[i]           !== undefined){ process.stdout.write(" " + sArraySensorUniqueId[i]); };
 bArraySensorRecycle = [''];               //if (typeof bArraySensorRecycle[i]            !== undefined){ process.stdout.write(" " + bArraySensorRecycle[i]); };

 iArraySensorButtonEvent = [''];           //if (typeof iArraySensorButtonEvent[i]       !== undefined){ process.stdout.write(" " + iArraySensorButtonEvent[i]); };
 iArraySensorLightLevel = [''];            //if (typeof iArraySensorLightLevel[i]        !== undefined){ process.stdout.write(" " + iArraySensorLightLevel[i]); };    
 bArraySensorDark = [''];                  //if (typeof bArraySensorDark[i]              !== undefined){ process.stdout.write(" " + bArraySensorDark[i]); };  
 bArraySensorDaylight = [''];              //if (typeof bArraySensorDaylight[i]          !== undefined){ process.stdout.write(" " + bArraySensorDaylight[i]); };  
 iArraySensorStatus = [''];                //if (typeof iArraySensorStatus[i]            !== undefined){ process.stdout.write(" " + iArraySensorStatus[i]); };    
 sArraySensorLastupdated = [''];           //if (typeof sArraySensorLastupdated[i]       !== undefined){ process.stdout.write(" " + sArraySensorLastupdated[i]); };  
 bArraySensorPresence = [''];              //if (typeof bArraySensorPresence[i]          !== undefined){ process.stdout.write(" " + bArraySensorPresence[i]); };  
 iArraySensorTemperature = [''];           //if (typeof iArraySensorTemperature[i]       !== undefined){ process.stdout.write(" " + iArraySensorTemperature[i]); };  

 bArraySensorOn = [''];                    //if (typeof bArraySensorOn[i]                !== undefined){ process.stdout.write(" " + bArraySensorOn[i]); };
 iArraySensorBattery = [''];               //if (typeof iArraySensorBattery[i]           !== undefined){ process.stdout.write(" " + iArraySensorBattery[i]); };
 bArraySensorConfigured = [''];            //if (typeof bArraySensorConfigured[i]        !== undefined){ process.stdout.write(" " + bArraySensorConfigured[i]); };
 bArraySensorReachable = [''];             //if (typeof bArraySensorReachable[i]         !== undefined){ process.stdout.write(" " + bArraySensorReachable[i]); };
 sArraySensorAlert = [''];                 //if (typeof sArraySensorAlert[i]             !== undefined){ process.stdout.write(" " + sArraySensorAlert[i]); };
 iArraySensorTholdDark = [''];             //if (typeof iArraySensorTholdOffset[i]       !== undefined){ process.stdout.write(" " + iArraySensorTholdOffset[i]); };
 iArraySensorTholdOffset = [''];           //if (typeof iArraySensorTholdOffset[i]       !== undefined){ process.stdout.write(" " + iArraySensorTholdOffset[i]); };
 iArraySensorStatus = [''];                //if (typeof iArraySensorStatus[i]            !== undefined){ process.stdout.write(" " + iArraySensorStatus[i]); };
 iArraySensorTholdOffset = [''];           //if (typeof iArraySensorTholdOffset[i]       !== undefined){ process.stdout.write(" " + iArraySensorTholdOffset[i]); };
 bArraySensorLedindication = [''];         //if (typeof bArraySensorLedindication[i]     !== undefined){ process.stdout.write(" " + bArraySensorLedindication[i]); };
 bArraySensorUsertest = [''];              //if (typeof bArraySensorUsertest[i]          !== undefined){ process.stdout.write(" " + bArraySensorUsertest[i]); };
 iArraySensorSensitivity = [''];           //if (typeof iArraySensorSensitivity[i]       !== undefined){ process.stdout.write(" " + iArraySensorSensitivity[i]); };
 iArraySensorSensitivityMax = [''];        //if (typeof iArraySensorSensitivityMax[i]    !== undefined){ process.stdout.write(" " + iArraySensorSensitivityMax[i]); };
 iArraySensorSunsetoffset = [''];          //if (typeof iArraySensorSunsetoffset[i]      !== undefined){ process.stdout.write(" " + iArraySensorSunsetoffset[i]); };
 iArraySensorSunriseoffset = [''];         //if (typeof iArraySensorSunriseoffset[i]     !== undefined){ process.stdout.write(" " + iArraySensorSunriseoffset[i]); };
 sArraySensorPending = [''];               //if (typeof sArraySensorPending[i]           !== undefined){ process.stdout.write(" " + sArraySensorPending[i]); };    


//****************************************************************************************************************************************/
if (typeof document !== 'undefined'){        // When browser
//****************************************************************************************************************************************/
  function clientGetUpdate(){

    document.getElementById("demo1").innerHTML = Math.floor((Math.random() * 10) + 1);
    document.getElementById("demo2").innerHTML = pathresources;
    document.getElementById("demo3").innerHTML = pathroot;
    document.getElementById("demo4").innerHTML = pathconfig;
    document.getElementById("demo5").innerHTML = pathsrc;
    document.getElementById("demo6").innerHTML = pathsrc;
    document.getElementById("demo7").innerHTML = pathsrc;
    document.getElementById("demo8").innerHTML = pathsrc;
    document.getElementById("demo9").innerHTML = pathsrc;
    document.getElementById("demo0").innerHTML = counter++;

  }
  setInterval(clientGetUpdate, 1000);
//****************************************************************************************************************************************/  
} else if (typeof document === 'undefined'){  //When console
//****************************************************************************************************************************************/

  hue = require('hue-sdk');
  //hue = require( pathresources + './hue-sdk/lib/hue.js');
  client = new hue.Hue(require( pathconfig + './.credentials.json' ));
  fs = require('fs');
  exec = require('child_process').exec;
  light = require( pathhuelight + './light.js' );
  sensor = require( pathhuesensor + './sensor.js');

  setInterval(myInit, 1000);
};

function myInit() {
  console.log("       " + counter++ + " " );
  
  if ( counter == 1 || ( counter % 20 ) == 0 ){
    light.getInfoAll();
    //sensor.getInfoAll();
  }

  if ( ( counter % 1000) == 1 ){
    //light.saveInfoAll();
    //light.loadInfoAll();
  }



   console.log(light.getOn(1));
   //light.sometest();
  
  setTimeout(myInit, 1000);
  };
  




//x = document.getElementById("demo")
//x.innerHTML = numbers[1];

//console.log = function (d) {
//process.stdout.write(d + '\n');
//};
//function updatesPush(iCounterInput){
//  iCounterOutput = iCounterInput;
//      //document.getElementById("demo2").innerHTML = iCounterInput;
//      //window.getElementById("demo2").innerHTML = iCounterInput;
//}
//
//
//function updatesGet(){
//  updatesPush(counter++);
//}
//
//









