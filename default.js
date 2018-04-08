
counter = 1;
//module.exports.repl.ignoreUndefined = true;
/*******\
| Paths |###############################################################################################################################################################################
\*******/

//Root
pathroot = '/root/scripts/HomeAutomation/';
    
    //Config
    pathconfig = pathroot + './config/';

    //Resources
    pathresources = pathroot + './resources/';
    
        //Avr
        pathavr = pathresources + './avr/';

        //Hue
        pathhue = pathresources + './hue/';
            
            //Bridge
            pathhuebridge = pathhue + './bridge/';                 //  pathbridge = pathhue + './bridge/';
            pathhuebridgevalues = pathhuebridge + './_values/';

            //Sensor
            pathhuesensor = pathhue + './sensor/';                 //  pathsensor = pathhue + './sensor/';
            pathhuesensorvalues = pathhuesensor + './_values/';

            //Light
            pathhuelight = pathhue + './light/';                   //  pathlight = pathhue + './light/';
            pathhuelightvalues = pathhuelight + './_values/';

        //Rpi
        pathrpi = pathresources + './RPi/';
        
            //Ledstrip
            pathledstrip = pathrpi + './ledstrip/';

        //SmartTV
        pathsmarttv = pathresources + './SmartTV/';
    //Lib
    pathlib = pathroot + './lib/';

    //Src
    pathsrc = pathroot + './src/';    


/********\
| Lights |###############################################################################################################################################################################
\********/

  iArrayLightConnected = [1, 2, 3, 4, 5, 6];
  
  //General attributes 
  sArrayLightManufacturerName = [''];                                                                                                                                                                                                                                           
  sArrayLightProductname = [''];                                                              //Color attributes (Currrent)                 // Color attributes (New)                     // Color attributes (Old)         // xy > ct > hs                                                                                                                  
  sArrayLightModelid = [''];                                                                  fArrayLightXyCur = [''];                      fArrayLightXyNew = [''];                      fArrayLightXyOld = [''];          // 0.000 - 1.000                                                                                                                   
  sArrayLightName = ['', 'LightName'];                                                        fArrayLightXyXCur = [''];                     fArrayLightXyXNew = [''];                     fArrayLightXyXOld = [''];         // 0.000 - 1.000                                                                                                                   
  sArrayLightSwversion = [''];                                                                fArrayLightXyYCur = [''];                     fArrayLightXyYNew = [''];                     fArrayLightXyYOld = [''];         // 0.000 - 1.000                                                                                                                   
  sArrayLightType = [''];                                                                     iArrayLightCtCur = [''];                      iArrayLightCtNew = [''];                      iArrayLightCtOld = [''];          // 153 - 500                                                                                                                       
  sArrayLightUniqueid = [''];                                                                 iArrayLightHueCur = ['1'];                     iArrayLightHueNew = [''];                     iArrayLightHueOld = [''];         // 0 - 65535                                                                                                                       
  bArrayLightOn = [''];                 /* true, false                                 */     iArrayLightSatCur = [''];                     iArrayLightSatNew = [''];                     iArrayLightSatOld = [''];         // 0 - 254                                                                                                                         
  bArrayLightReachable = [''];          /* true, false                                 */     iArrayLightBriCur = [''];                     iArrayLightBriNew = [''];                     iArrayLightBriOld = [''];         // 1-254                                                                                                                           
  sArrayLightAlert = [''];              /* none, select, lselect                       */     iArrayLightRgbRedCur = [''];                  iArrayLightRgbRedNew = [''];                  iArrayLightRgbRedOld = [''];      // 0 - 254                                                                                                                         
  sArrayLightColorMode = [''];          /* hs, xy, ct                                  */     iArrayLightRgbGreenCur = [''];                iArrayLightRgbGreenNew = [''];                iArrayLightRgbGreenOld = [''];    // 0 - 254                                                    
  sArrayLightEffect = [''];             /* none, colorloop                             */     iArrayLightRgbBlueCur = [''];                 iArrayLightRgbBlueNew = [''];                 iArrayLightRgbBlueOld = [''];                                                                   
  iArrayLightTransitionTime = [''];     /* multiple of 100ms and defaults to 4 (400ms) */   
     
/*********\
| Sensors |###############################################################################################################################################################################
\*********/

  iArraySensorConnected = [1, 2, 5, 6, 7, 8, 9, 10, 11];        //i++; if ( i == 3 ){ i = 5; } else if ( i == 11 ){ i = 1; } sensor.getInfo(i);

  sArraySensorName = [''];                                                               sArraySensorNameCur = [''];                   sArraySensorNameNew = [''];                   sArraySensorNameOld = [''];                                                                                                                                                                                                                                      
  sArraySensorType = [''];                                                               sArraySensorTypeCur = [''];                   sArraySensorTypeNew = [''];                   sArraySensorTypeOld = [''];                                                                                                                                                                                                                                      
  sArraySensorModelId = [''];                                                            sArraySensorModelIdCur = [''];                sArraySensorModelIdNew = [''];                sArraySensorModelIdOld = [''];                                                                                                                                                                                                                                   
  sArraySensorManufacturerName = [''];                                                   sArraySensorManufacturerNameCur = [''];       sArraySensorManufacturerNameNew = [''];       sArraySensorManufacturerNameOld = [''];                                                                                                                                                                                                                          
  sArraySensorSwVersion = [''];                                                          sArraySensorSwVersionCur = [''];              sArraySensorSwVersionNew = [''];              sArraySensorSwVersionOld = [''];                                                                                                                                                                                                                                 
  sArraySensorUniqueId = [''];                                                           sArraySensorUniqueIdCur = [''];               sArraySensorUniqueIdNew = [''];               sArraySensorUniqueIdOld = [''];                                                                                                                                                                                                                                  
  bArraySensorRecycle = [''];                                                            bArraySensorRecycleCur = [''];                bArraySensorRecycleNew = [''];                bArraySensorRecycleOld = [''];                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                                                                                                                                                               
  iArraySensorButtonEvent = [''];                                                        iArraySensorButtonEventCur = [''];            iArraySensorButtonEventNew = [''];            iArraySensorButtonEventOld = [''];                                                                                                                                                                                                                               
  iArraySensorLightLevel = [''];                                                         iArraySensorLightLevelCur = [''];             iArraySensorLightLevelNew = [''];             iArraySensorLightLevelOld = [''];                                                                                                                                                                                                                                
  bArraySensorDark = [''];                                                               bArraySensorDarkCur = [''];                   bArraySensorDarkNew = [''];                   bArraySensorDarkOld = [''];                                                                                                                                                                                                                                      
  bArraySensorDaylight = [''];                                                           bArraySensorDaylightCur = [''];               bArraySensorDaylightNew = [''];               bArraySensorDaylightOld = [''];                                                                                                                                                                                                                                  
  iArraySensorStatus = [''];                                                             iArraySensorStatusCur = [''];                 iArraySensorStatusNew = [''];                 iArraySensorStatusOld = [''];                                                                                                                                                                                                                                    
  sArraySensorLastupdated = [''];                                                        sArraySensorLastupdatedCur = [''];            sArraySensorLastupdatedNew = [''];            sArraySensorLastupdatedOld = [''];                                                                                                                                                                                                                               
  bArraySensorPresence = [''];                                                           bArraySensorPresenceCur = [''];               bArraySensorPresenceNew = [''];               bArraySensorPresenceOld = [''];                                                                                                                                                                                                                                  
  iArraySensorTemperature = [''];                                                        iArraySensorTemperatureCur = [''];            iArraySensorTemperatureNew = [''];            iArraySensorTemperatureOld = [''];                                                                                                                                                                                                                               
                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  bArraySensorOn = [''];                                                                 bArraySensorOnCur = [''];                     bArraySensorOnNew = [''];                     bArraySensorOnOld = [''];                                                                                                                                                                                                                                        
  iArraySensorBattery = [''];                                                            iArraySensorBatteryCur = [''];                iArraySensorBatteryNew = [''];                iArraySensorBatteryOld = [''];                                                                                                                                                                                                                                   
  bArraySensorConfigured = [''];                                                         bArraySensorConfiguredCur = [''];             bArraySensorConfiguredNew = [''];             bArraySensorConfiguredOld = [''];                                                                                                                                                                                                                                
  bArraySensorReachable = [''];                                                          bArraySensorReachableCur = [''];              bArraySensorReachableNew = [''];              bArraySensorReachableOld = [''];                                                                                                                                                                                                                                 
  sArraySensorAlert = [''];                                                              sArraySensorAlertCur = [''];                  sArraySensorAlertNew = [''];                  sArraySensorAlertOld = [''];                                                                                                                                                                                                                                     
  iArraySensorTholdDark = [''];                                                          iArraySensorTholdDarkCur = [''];              iArraySensorTholdDarkNew = [''];              iArraySensorTholdDarkOld = [''];                                                                                                                                                                                                                                 
  iArraySensorTholdOffset = [''];                                                        iArraySensorTholdOffsetCur = [''];            iArraySensorTholdOffsetNew = [''];            iArraySensorTholdOffsetOld = [''];                                                                                                                                                                                                                               
  iArraySensorStatus = [''];                                                             iArraySensorStatusCur = [''];                 iArraySensorStatusNew = [''];                 iArraySensorStatusOld = [''];                                                                                                                                                                                                                                    
  iArraySensorTholdOffset = [''];                                                        iArraySensorTholdOffsetCur = [''];            iArraySensorTholdOffsetNew = [''];            iArraySensorTholdOffsetOld = [''];                                                                                                                                                                                                                               
  bArraySensorLedindication = [''];                                                      bArraySensorLedindicationCur = [''];          bArraySensorLedindicationNew = [''];          bArraySensorLedindicationOld = [''];                                                                                                                                                                                                                             
  bArraySensorUsertest = [''];                                                           bArraySensorUsertestCur = [''];               bArraySensorUsertestNew = [''];               bArraySensorUsertestOld = [''];                                                                                                                                                                                                                                  
  iArraySensorSensitivity = [''];                                                        iArraySensorSensitivityCur = [''];            iArraySensorSensitivityNew = [''];            iArraySensorSensitivityOld = [''];                                                                                                                                                                                                                               
  iArraySensorSensitivityMax = [''];                                                     iArraySensorSensitivityMaxCur = [''];         iArraySensorSensitivityMaxNew = [''];         iArraySensorSensitivityMaxOld = [''];                                                                                                                                                                                                                            
  iArraySensorSunsetoffset = [''];                                                       iArraySensorSunsetoffsetCur = [''];           iArraySensorSunsetoffsetNew = [''];           iArraySensorSunsetoffsetOld = [''];                                                                                                                                                                                                                              
  iArraySensorSunriseoffset = [''];                                                      iArraySensorSunriseoffsetCur = [''];          iArraySensorSunriseoffsetNew = [''];          iArraySensorSunriseoffsetOld = [''];                                                                                                                                                                                                                             
  sArraySensorPending = [''];                                                            sArraySensorPendingCur = [''];                sArraySensorPendingNew = [''];                sArraySensorPendingOld = [''];                                                                                                                                                                                                                                   

/*********\
| Sensors |###############################################################################################################################################################################
\*********/

hue = require('hue-sdk');
//hue = require( pathresources + './hue-sdk/lib/hue.js');
client = new hue.Hue(require( pathconfig + './.credentials.json' ));

//var tv = require( pathsmarttv + 'tv.js' );
//tv.postInputKeyVolumeUp();


var light = require( pathhuelight + 'light.js' );


//light.getManufacturerName('1', function(callback){ console.log(callback); });
//light.getModelId('1', function(callback){ console.log(callback); });
//light.getName('1', function(callback){ console.log(callback); });
//light.getSwVersion('1', function(callback){ console.log(callback); });
//light.getType('1', function(callback){ console.log(callback); });
//light.getUniqueid('1', function(callback){ console.log(callback); });
//light.getOn('1', function(callback){ console.log(callback); });
//light.getBri('1', function(callback){ console.log(callback); });
//light.getHue('1', function(callback){ console.log(callback); });
//light.getSat('1', function(callback){ console.log(callback); });
//light.getEffect('1', function(callback){ console.log(callback); });
//light.getXy('1', function(callback){ console.log(callback); });
//light.getXyX('1', function(callback){ console.log(callback); });
//light.getXyY('1', function(callback){ console.log(callback); });
//light.getCt('1', function(callback){ console.log(callback); });
//light.getAlert('1', function(callback){ console.log(callback); });
//light.getColormode('1', function(callback){ console.log(callback); });
//light.getReachable('1', function(callback){ console.log(callback); });
light.getTransisitonTime ('1', function(callback){ console.log(callback); });
