#!/usr/bin/env node

var Variables = function(){

  hue = require('hue-sdk');
  client = new hue.Hue(require('./.credentials.json'));
  sensor = require('./sensor.js');
  light = require('./light.js');
  exec = require('child_process').exec;
  //debug = process.argv[2];
  debug = false;
  
  i = 0;
  // ##############
  // #   Lights   #
  // ##############

  iArrayLightConnected = [1, 2, 3, 4, 5 , 6, 7];
  
  //General attributes 
  sArrayLightManufacturerName = [''];   //
  sArrayLightProductname = [''];        //
  sArrayLightModelid = [''];            //
  sArrayLightName = [''];               //
  sArrayLightSwversion = [''];          //
  sArrayLightType = [''];               //
  sArrayLightUniqueid = [''];           //
  bArrayLightOn = [''];                 // true, false
  bArrayLightReachable = [''];          // true, false
  sArrayLightAlert = [''];              // none, select, lselect                
  sArrayLightColorMode = [''];          // hs, xy, ct
  sArrayLightEffect = [''];             // none, colorloop
  iArrayLightTransitionTime = [''];     // multiple of 100ms and defaults to 4 (400ms)
  
  //if ( debug ){ console.log('General:'); };
  //if ( typeof sArrayLightManufacturerName[i]     !== undefined){ process.stdout.write(" " + sArrayLightManufacturerName[i] ); };  
  //if ( typeof sArrayLightProductname[i]          !== undefined){ process.stdout.write(" " + sArrayLightProductname[i]        ); }; 
  //if ( typeof sArrayLightModelid[i]              !== undefined){ process.stdout.write(" " + sArrayLightModelid[i]             ); }; 
  //if ( typeof sArrayLightName[i]                 !== undefined){ process.stdout.write(" " + sArrayLightName[i]                ); }; 
  //if ( typeof sArrayLightSwversion[i]            !== undefined){ process.stdout.write(" " + sArrayLightSwversion[i]           ); }; 
  //if ( typeof sArrayLightType[i]                 !== undefined){ process.stdout.write(" " + sArrayLightType[i]                ); }; 
  //if ( typeof sArrayLightUniqueid[i]             !== undefined){ process.stdout.write(" " + sArrayLightUniqueid[i]            ); };
  
  //Color attributes (Currrent)            // Color attributes (New)            // Color attributes (Old)             // xy > ct > hs
  fArrayLightXyCur = [''];                 fArrayLightXyNew = [''];             fArrayLightXyOld = [''];          // 0.000 - 1.000
  fArrayLightXyXCur = [''];                fArrayLightXyXNew = [''];            fArrayLightXyXOld = [''];          // 0.000 - 1.000
  fArrayLightXyYCur = [''];                fArrayLightXyYNew = [''];            fArrayLightXyYOld = [''];          // 0.000 - 1.000
  iArrayLightCtCur = [''];                 iArrayLightCtNew = [''];             iArrayLightCtOld = [''];           // 153 - 500
  iArrayLightHueCur = [''];                iArrayLightHueNew = [''];            iArrayLightHueOld = [''];          // 0 - 65535
  iArrayLightSatCur = [''];                iArrayLightSatNew = [''];            iArrayLightSatOld = [''];          // 0 - 254
  iArrayLightBriCur = [''];                iArrayLightBriNew = [''];            iArrayLightBriOld = [''];          // 1-254
  iArrayLightRgbRedCur = [''];             iArrayLightRgbRedNew = [''];         iArrayLightRgbRedOld = [''];       // 0 - 254
  iArrayLightRgbGreenCur = [''];           iArrayLightRgbGreenNew = [''];       iArrayLightRgbGreenOld = [''];     // 0 - 254 
  iArrayLightRgbBlueCur = [''];            iArrayLightRgbBlueNew = [''];        iArrayLightRgbBlueOld = [''];  

  //if ( debug ){ console.log('State:'); };    
  //if ( typeof bArrayLightOn[i]                !== undefined){ process.stdout.write(" " + bArrayLightOn[i]                ); };     
  //if ( typeof bArrayLightReachable[i]         !== undefined){ process.stdout.write(" " + bArrayLightReachable[i]        ); };     
  //if ( typeof sArrayLightAlert[i]             !== undefined){ process.stdout.write(" " + sArrayLightAlert[i]            ); };     
  //if ( typeof sArrayLightColorMode[i]         !== undefined){ process.stdout.write(" " + sArrayLightColorMode[i]        ); };     
  //if ( typeof sArrayLightEffect[i]            !== undefined){ process.stdout.write(" " + sArrayLightEffect[i]            ); };     
  //if ( typeof iArrayLightTransitionTime[i]    !== undefined){ process.stdout.write(" " + iArrayLightTransitionTime[i]   ); };
  //if ( typeof fArrayLightXyCur[i]             !== undefined){ process.stdout.write(" " + fArrayLightXyCur[i]            ); };     
  //if ( typeof fArrayLightXyXCur[i]            !== undefined){ process.stdout.write(" " + fArrayLightXyXCur[i]            ); };     
  //if ( typeof fArrayLightXyYCur[i]            !== undefined){ process.stdout.write(" " + fArrayLightXyYCur[i]            ); };     
  //if ( typeof iArrayLightCtCur[i]             !== undefined){ process.stdout.write(" " + iArrayLightCtCur[i]            ); };     
  //if ( typeof iArrayLightHueCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightHueCur[i]            ); };     
  //if ( typeof iArrayLightSatCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightSatCur[i]            ); };     
  //if ( typeof iArrayLightBriCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightBriCur[i]            ); };     
  //if ( typeof iArrayLightRgbRedCur[i]         !== undefined){ process.stdout.write(" " + iArrayLightRgbRedCur[i]        ); };     
  //if ( typeof iArrayLightRgbGreenCur[i]       !== undefined){ process.stdout.write(" " + iArrayLightRgbGreenCur[i]        ); }; 
  //if ( typeof iArrayLightRgbBlueCur[i]        !== undefined){ process.stdout.write(" " + iArrayLightRgbBlueCur[i]        ); };     

  // ##############
  // #   Sensors  #
  // ##############

  iArraySensorConnected = [1, 2, 5, 6, 7, 8, 9, 10, 11];
 
  sArraySensorName = [''];                   
  sArraySensorType = [''];           
  sArraySensorModelId = [''];        
  sArraySensorManufacturerName = [''];
  sArraySensorSwversion = [''];  
  sArraySensorUniqueId = [''];
  bArraySensorRecycle = [''];

  //i++; if ( i == 3 ){ i = 5; } else if ( i == 11 ){ i = 1; } sensor.getInfo(i);
  
  //if (typeof sArraySensorName[i]                  !== undefined){ process.stdout.write(" " + sArraySensorName[i]); };
  //if (typeof sArraySensorType[i]                  !== undefined){ process.stdout.write(" " + sArraySensorType[i]); };
  //if (typeof sArraySensorModelId[i]               !== undefined){ process.stdout.write(" " + sArraySensorModelId[i]); };
  //if (typeof sArraySensorManufacturerName[i]      !== undefined){ process.stdout.write(" " + sArraySensorManufacturerName[i]); };
  //if (typeof sArraySensorSwversion[i]             !== undefined){ process.stdout.write(" " + sArraySensorSwversion[i]); };
  //if (typeof sArraySensorUniqueId[i]              !== undefined){ process.stdout.write(" " + sArraySensorUniqueId[i]); };
  //if (typeof bArraySensorRecycle[i]               !== undefined){ process.stdout.write(" " + bArraySensorRecycle[i]); };
    
  iArraySensorButtonEvent = [''];   
  iArraySensorLightLevel = [''];      
  bArraySensorDark = [''];          
  bArraySensorDaylight = [''];      
  iArraySensorStatus = [''];          
  sArraySensorLastupdated = [''];   
  bArraySensorPresence = [''];      
  iArraySensorTemperature = [''];   

  //if (typeof iArraySensorButtonEvent[i]             !== undefined){ process.stdout.write(" " + iArraySensorButtonEvent[i]); };
  //if (typeof iArraySensorLightLevel[i]              !== undefined){ process.stdout.write(" " + iArraySensorLightLevel[i]); };  
  //if (typeof bArraySensorDark[i]                    !== undefined){ process.stdout.write(" " + bArraySensorDark[i]); };  
  //if (typeof bArraySensorDaylight[i]                !== undefined){ process.stdout.write(" " + bArraySensorDaylight[i]); };  
  //if (typeof iArraySensorStatus[i]                  !== undefined){ process.stdout.write(" " + iArraySensorStatus[i]); };  
  //if (typeof sArraySensorLastupdated[i]             !== undefined){ process.stdout.write(" " + sArraySensorLastupdated[i]); };  
  //if (typeof bArraySensorPresence[i]                !== undefined){ process.stdout.write(" " + bArraySensorPresence[i]); };  
  //if (typeof iArraySensorTemperature[i]             !== undefined){ process.stdout.write(" " + iArraySensorTemperature[i]); };  
  
  
  bArraySensorOn = [''];            
  iArraySensorBattery = [''];       
  bArraySensorConfigured = [''];    
  bArraySensorReachable = [''];     
  sArraySensorAlert = [''];
  iArraySensorTholdDark = [''];
  iArraySensorTholdOffset = [''];
  iArraySensorStatus = ['']; 
  iArraySensorTholdOffset = ['']; 
  bArraySensorLedindication = ['']; 
  bArraySensorUsertest = [''];
  iArraySensorSensitivity = [''];   
  iArraySensorSensitivityMax = [''];
  iArraySensorSunsetoffset = [''];  
  iArraySensorSunriseoffset = ['']; 
  sArraySensorPending = ['']; 

  //if (typeof bArraySensorOn[i]                !== undefined){ process.stdout.write(" " + bArraySensorOn[i]); };
  //if (typeof iArraySensorBattery[i]           !== undefined){ process.stdout.write(" " + iArraySensorBattery[i]); };
  //if (typeof bArraySensorConfigured[i]        !== undefined){ process.stdout.write(" " + bArraySensorConfigured[i]); };
  //if (typeof bArraySensorReachable[i]         !== undefined){ process.stdout.write(" " + bArraySensorReachable[i]); };
  //if (typeof sArraySensorAlert[i]             !== undefined){ process.stdout.write(" " + sArraySensorAlert[i]); };
  //if (typeof iArraySensorStatus[i]            !== undefined){ process.stdout.write(" " + iArraySensorStatus[i]); };
  //if (typeof iArraySensorTholdOffset[i]       !== undefined){ process.stdout.write(" " + iArraySensorTholdOffset[i]); };
  //if (typeof bArraySensorLedindication[i]     !== undefined){ process.stdout.write(" " + bArraySensorLedindication[i]); };
  //if (typeof bArraySensorUsertest[i]          !== undefined){ process.stdout.write(" " + bArraySensorUsertest[i]); };
  //if (typeof iArraySensorSensitivity[i]       !== undefined){ process.stdout.write(" " + iArraySensorSensitivity[i]); };
  //if (typeof iArraySensorSensitivityMax[i]    !== undefined){ process.stdout.write(" " + iArraySensorSensitivityMax[i]); };
  //if (typeof iArraySensorSunsetoffset[i]      !== undefined){ process.stdout.write(" " + iArraySensorSunsetoffset[i]); };
  //if (typeof iArraySensorSunriseoffset[i]     !== undefined){ process.stdout.write(" " + iArraySensorSunriseoffset[i]); };
  //if (typeof sArraySensorPending[i]           !== undefined){ process.stdout.write(" " + sArraySensorPending[i]); };    

};
//  sVariableName = typeof sVariableName !== undefined ? sVariableName : "DefaultStartValue";

module.exports = Variables;







//module.exports = { 
//    Variables
//};
