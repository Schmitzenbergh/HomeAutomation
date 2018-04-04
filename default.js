counter = 1;

/************
*   Paths   *
************/

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

    //Lib
    pathlib = pathroot + './lib/';

    //Src
    pathsrc = pathroot + './src/';    

/**********
*   Hue   *
*********/

  sObjectResults = {};
  //sObjectResults = result;      //Put all results in object 'document'.lights.*.*.*
  //sObjectResults = { result };  //Put all results in object 'document'.results.lights.*.*.*

/***************
*    Lights    *
***************/

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
     
/***************
*    Sensors   *
***************/

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


//****************************************************************************************************************************************/
if (typeof document !== 'undefined'){        // When browser
//****************************************************************************************************************************************/

  function clientGetUpdate(){
   
    //var myObj = JSON.parse(pathhue + "./json.txt");

    document.getElementById("demo").innerHTML = counter++;
    document.getElementById("demo01").innerHTML = Math.floor((Math.random() * 10) + 1);
    document.getElementById("demo02").innerHTML = pathresources;
    document.getElementById("demo03").innerHTML = pathroot;
    document.getElementById("demo04").innerHTML = pathconfig;
    document.getElementById("demo05").innerHTML = sArrayLightName;
    document.getElementById("demo06").innerHTML = pathsrc;
    if ( sObjectResults.config !== undefined ){   
      //document.getElementById("demo07").innerHTML = sObjectResults.config;
      //document.getElementById("demo07").innerHTML = JSON.stringify(sObjectResults.config);
    }
    document.getElementById("demo08").innerHTML = sArrayLightName["1"];
    document.getElementById("demo09").innerHTML = jArrayResults;
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
  bridge = require( pathhuebridge + './bridge.js');

  htmlServer();

  myInit();
};

//console.log(db.lights[1].state.xy[1])


function myInit() {

  console.log(counter++);

  if ( ( counter % 3 ) == 0 ){
    bridge.getInfoAll();
  }

  //if ( sObjectResults.lights !== undefined ){       //  ok
  //if ( sObjectResults.lights[1] !== undefined ){    //  Cannot read property '1' of undefined
  if ( ( counter % 3 ) == 0 && sObjectResults.config !== undefined ){   
    console.log('\t' + sObjectResults.config.UTC);
  }


  if ( counter == 1 || ( counter % 25 ) == 0 ){
    light.getInfoAll();
    sensor.getInfoAll();
  }

  if ( counter == 26 ||( counter % 250 ) == 1 ){
//    light.saveInfoAll();
//    light.loadInfoAll();
//    sensor.saveInfoAll();
//    sensor.loadInfoAll();
  }

  setTimeout(myInit, 1000);
}


function htmlServer(){
  console.log('init Server...');
  var http = require('http');
  var https = require('https');
  var fs = require('fs');
  var path = require('path');
  var sObjectResultsServer;
  http.createServer(function (request, response){
    console.log('request starting...');

    var filePath = '.' + request.url;
    if (filePath == './')
        filePath = './index.html';

        var filePath = '.' + request.url;
        if (filePath == './')
            filePath = './index.html';
    
        var extname = path.extname(filePath);
        var contentType = 'text/html';
        switch (extname) {
            case '.js':
                contentType = 'text/javascript';
                break;
            case '.css':
                contentType = 'text/css';
                break;
            case '.json':
                contentType = 'application/json';
                break;
            case '.png':
                contentType = 'image/png';
                break;      
            case '.jpg':
                contentType = 'image/jpg';
                break;
            case '.wav':
                contentType = 'audio/wav';
                break;
        }
    
        fs.readFile(filePath, function(error, content) {
            if (error) {
                if(error.code == 'ENOENT'){
                    fs.readFile('./404.html', function(error, content) {
                        response.writeHead(200, { 'Content-Type': contentType });
                        response.end(content, 'utf-8');
                    });
                }
                else {
                    response.writeHead(500);
                    response.end('Sorry, check with the site admin for error: '+error.code+' ..\n');
                    response.end(); 
                }
            }
            else {
                response.writeHead(200, { 'Content-Type': contentType });
                response.end(content, 'utf-8');
            }
        });

     }).listen(8080);
};



