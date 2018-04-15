//var jsonFile=fs.readFileSync('db.json', 'utf8');
//var jsonObj = JSON.parse(jsonFile);
var server;










 //console.log(data);  //htmlScript = toString().data;





/***************\
| NodeJS Server |###############################################################################################################################################################################
\***************/

server = http.createServer(function(req, res){
  console.log("Client connected");
  var bDoPageRefresh = false;
  var htmlScript = fs.readFileSync( pathconfigvar + './db.var', "UTF8", function(err, data){  });
    // your normal server code
    var path = url.parse(req.url).pathname;

    
    
    //var varString     = fs.readFileSync(pathconfigvar + "./db.strings", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x +  " = '';");
    console.log(pathpublic);
    switch (path){
        case '/':
            fs.readFile( pathpublic + './index.html', function(err, data){
              if (err){ return send404(res); };
              res.writeHead(200, {'Content-type': 'text/html'}); 
                res.write("<script>" + '\n' + htmlScript +  '\n' + "</script>" +  '\n'  + data);
              res.end();
            });
            break;
        case '/test.html':
            fs.readFile( pathpublic + __dirname, function(err, data){
                if (err){ return send404(res); };
                res.writeHead(200, {'Content-type': 'text/html'});
                res.write(data, 'utf8');
                res.end();
            });
          break;

        //Run functions by call the url  
        case '/volup'  :   if (err){ return send404(res); }; volumeup();  bDoPageRefresh = true; 
          break;
        case '/voldown':   if (err){ return send404(res); }; volumeup();  bDoPageRefresh = true; 
          break;

        default: send404(res);

    }
    if (bDoPageRefresh){  // For all actions without a page
        fs.readFile(pathpublic + './index.html', function(err, data){
            if (err){ return send404(res); }
            res.writeHead(200, {'Content-type': 'text/html'});
            res.write(data, 'utf8'); res.end();
        });
    }
}),

//    http.createServer(function (req, res) {
//      var html = buildHtml(req);
//    
//      res.writeHead(200, {
//        'Content-Type': 'text/html',
//        'Content-Length': html.length,
//        'Expires': new Date().toUTCString()
//      });
//      res.end(html);
//    }).listen(8080);
//    
//    function buildHtml(req) {
//      var header = '';
//      var body = '';
//      var script = '';
//    
//      fs.readFile( pathpublic + 'index.html', function(err, data){
//          script = data;
//    });
//    
//    
//      // concatenate header string
//      // concatenate body string
//    
//      return '<!DOCTYPE html>'
//           + '<html><header>' + header + '</header><body>' + body + '</body></html>';
//    };







send404 = function(res){
    res.writeHead(404);
    res.write('404');
    res.end();
};

server.listen(80);





// use socket.io
var io = require('socket.io').listen(server);

  //turn off debug
  //io.set('log level', 0);

  // define interactions with client
  io.sockets.on('connection', function(socket){


      // Will do something when its get triggerd by emitter
      socket.on('power-off'       , function(data){ avr.SendCommand('power-off'       ); });
      socket.on('power-on'        , function(data){ avr.SendCommand('power-on'        ); });
      socket.on('mute-toggle'     , function(data){ avr.SendCommand('mute-toggle'     ); });
      socket.on('mute-on'         , function(data){ avr.SendCommand('mute-on'         ); });
      socket.on('mute-off'        , function(data){ avr.SendCommand('mute-off'        ); });
      socket.on('volume-down'     , function(data){ avr.SendCommand('volume-down'     ); });
      socket.on('volume-up'       , function(data){ avr.SendCommand('volume-up'       ); });
      socket.on('ok'              , function(data){ avr.SendCommand('ok'              ); });
      socket.on('home'            , function(data){ avr.SendCommand('home'            ); });
      socket.on('options'         , function(data){ avr.SendCommand('options'         ); });
      socket.on('down'            , function(data){ avr.SendCommand('down'            ); });
      socket.on('up'              , function(data){ avr.SendCommand('up'              ); });
      socket.on('left'            , function(data){ avr.SendCommand('left'            ); });
      socket.on('right'           , function(data){ avr.SendCommand('right'           ); });
      socket.on('back'            , function(data){ avr.SendCommand('back'            ); });
      socket.on('forward'         , function(data){ avr.SendCommand('forward'         ); });
      socket.on('pause'           , function(data){ avr.SendCommand('pause'           ); });
      socket.on('play'            , function(data){ avr.SendCommand('play'            ); });
      socket.on('next'            , function(data){ avr.SendCommand('next'            ); });
      socket.on('previous'        , function(data){ avr.SendCommand('previous'        ); });
      socket.on('sleep'           , function(data){ avr.SendCommand('sleep'           ); });
      socket.on('delay'           , function(data){ avr.SendCommand('delay'           ); });
      socket.on('channel-up'      , function(data){ avr.SendCommand('channel-up'      ); });
      socket.on('channel-down'    , function(data){ avr.SendCommand('channel-down'    ); });
      socket.on('tuner-up'        , function(data){ avr.SendCommand('tuner-up'        ); });
      socket.on('tuner-down'      , function(data){ avr.SendCommand('tuner-down'      ); });
      socket.on('AUX'             , function(data){ avr.SendCommand('source-selection', undefined, 'AUX'             ); });
      socket.on('TV'              , function(data){ avr.SendCommand('source-selection', undefined, 'TV'              ); });
      socket.on('Cable Sat'       , function(data){ avr.SendCommand('source-selection', undefined, 'Cable Sat'       ); });
      socket.on('STB'             , function(data){ avr.SendCommand('source-selection', undefined, 'STB'             ); });
      socket.on('Radio'           , function(data){ avr.SendCommand('source-selection', undefined, 'Radio'           ); });
      socket.on('Game'            , function(data){ avr.SendCommand('source-selection', undefined, 'Game'            ); });
      socket.on('USB'             , function(data){ avr.SendCommand('source-selection', undefined, 'USB'             ); });
      socket.on('Disc'            , function(data){ avr.SendCommand('source-selection', undefined, 'Disc'            ); });
      socket.on('Media Server'    , function(data){ avr.SendCommand('source-selection', undefined, 'Media Server'    ); });
      socket.on('Home Network'    , function(data){ avr.SendCommand('source-selection', undefined, 'Home Network'    ); });
      socket.on('AM'              , function(data){ avr.SendCommand('source-selection', undefined, 'AM'              ); });
      socket.on('FM'              , function(data){ avr.SendCommand('source-selection', undefined, 'FM'              ); });
      socket.on('vTuner'          , function(data){ avr.SendCommand('source-selection', undefined, 'vTuner'          ); });
      socket.on('Bluetooth'       , function(data){ avr.SendCommand('source-selection', undefined, 'Bluetooth'       ); });
      //socket.on('iPod'            , function(data){ avr.SendCommand('source-selection', undefined, 'iPod'            ); });
      //socket.on('Spotify'         , function(data){ avr.SendCommand('source-selection', undefined, 'Spotify'         ); });



      socket.on('postAmbilightCached'        , function(data){ tv.postAmbilightCached()        ; });
      socket.on('postAmbiLightLounge'        , function(data){ tv.postAmbiLightLounge()        ; });
      socket.on('postAmbiLightMode'          , function(data){ tv.postAmbiLightMode()          ; });
      socket.on('postAudioVolume'            , function(data){ tv.postAudioVolume()            ; });
      socket.on('postInputPointer'           , function(data){ tv.postInputPointer()           ; });


      socket.on('postInputKeyStandby'        , function(data){ tv.postInputKeyStandby()        ; });
      socket.on('postInputKeyBack'           , function(data){ tv.postInputKeyBack()           ; });
      socket.on('postInputKeyFind'           , function(data){ tv.postInputKeyFind()           ; });
      socket.on('postInputKeyRedColour'      , function(data){ tv.postInputKeyRedColour()      ; });
      socket.on('postInputKeyGreenColour'    , function(data){ tv.postInputKeyGreenColour()    ; });
      socket.on('postInputKeyYellowColour'   , function(data){ tv.postInputKeyYellowColour()   ; });
      socket.on('postInputKeyBlueColour'     , function(data){ tv.postInputKeyBlueColour()     ; });
      socket.on('postInputKeyHome'           , function(data){ tv.postInputKeyHome()           ; });
      socket.on('postInputKeyVolumeUp'       , function(data){ tv.postInputKeyVolumeUp()       ; });
      socket.on('postInputKeyVolumeDown'     , function(data){ tv.postInputKeyVolumeDown()     ; });
      socket.on('postInputKeyMute'           , function(data){ tv.postInputKeyMute()           ; });
      socket.on('postInputKeyOptions'        , function(data){ tv.postInputKeyOptions()        ; });
      socket.on('postInputKeyDot'            , function(data){ tv.postInputKeyDot()            ; });
      socket.on('postInputKeyDigit0'         , function(data){ tv.postInputKeyDigit0()         ; });
      socket.on('postInputKeyDigit1'         , function(data){ tv.postInputKeyDigit1()         ; });
      socket.on('postInputKeyDigit2'         , function(data){ tv.postInputKeyDigit2()         ; });
      socket.on('postInputKeyDigit3'         , function(data){ tv.postInputKeyDigit3()         ; });
      socket.on('postInputKeyDigit4'         , function(data){ tv.postInputKeyDigit4()         ; });
      socket.on('postInputKeyDigit5'         , function(data){ tv.postInputKeyDigit5()         ; });
      socket.on('postInputKeyDigit6'         , function(data){ tv.postInputKeyDigit6()         ; });
      socket.on('postInputKeyDigit7'         , function(data){ tv.postInputKeyDigit7()         ; });
      socket.on('postInputKeyDigit8'         , function(data){ tv.postInputKeyDigit8()         ; });
      socket.on('postInputKeyDigit9'         , function(data){ tv.postInputKeyDigit9()         ; });
      socket.on('postInputKeyInfo'           , function(data){ tv.postInputKeyInfo()           ; });
      socket.on('postInputKeyCursorUp'       , function(data){ tv.postInputKeyCursorUp()       ; });
      socket.on('postInputKeyCursorDown'     , function(data){ tv.postInputKeyCursorDown()     ; });
      socket.on('postInputKeyCursorLeft'     , function(data){ tv.postInputKeyCursorLeft()     ; });
      socket.on('postInputKeyCursorRight'    , function(data){ tv.postInputKeyCursorRight()    ; });
      socket.on('postInputKeyConfirm'        , function(data){ tv.postInputKeyConfirm()        ; });
      socket.on('postInputKeyNext'           , function(data){ tv.postInputKeyNext()           ; });
      socket.on('postInputKeyPrevious'       , function(data){ tv.postInputKeyPrevious()       ; });
      socket.on('postInputKeyAdjust'         , function(data){ tv.postInputKeyAdjust()         ; });
      socket.on('postInputKeyWatchTV'        , function(data){ tv.postInputKeyWatchTV()        ; });
      socket.on('postInputKeyViewmode'       , function(data){ tv.postInputKeyViewmode()       ; });
      socket.on('postInputKeyTeletext'       , function(data){ tv.postInputKeyTeletext()       ; });
      socket.on('postInputKeySubtitle'       , function(data){ tv.postInputKeySubtitle()       ; });
      socket.on('postInputKeyChannelStepUp'  , function(data){ tv.postInputKeyChannelStepUp()  ; });
      socket.on('postInputKeyChannelStepDown', function(data){ tv.postInputKeyChannelStepDown(); });
      socket.on('postInputKeySource'         , function(data){ tv.postInputKeySource()         ; });
      socket.on('postInputKeyAmbilightOnOff' , function(data){ tv.postInputKeyAmbilightOnOff (); });
      socket.on('postInputKeyPlayPause'      , function(data){ tv.postInputKeyPlayPause()      ; });
      socket.on('postInputKeyPause'          , function(data){ tv.postInputKeyPause()          ; });
      socket.on('postInputKeyFastForward'    , function(data){ tv.postInputKeyFastForward()    ; });
      socket.on('postInputKeyStop'           , function(data){ tv.postInputKeyStop()           ; });
      socket.on('postInputKeyRewind'         , function(data){ tv.postInputKeyRewind()         ; });
      socket.on('postInputKeyRecord'         , function(data){ tv.postInputKeyRecord()         ; });
      socket.on('postInputKeyOnline'         , function(data){ tv.postInputKeyOnline()         ; });

      socket.on('postPowerstateOn'           , function(data){ tv.postPowerstateOn()           ; });
      socket.on('postPowerstateStandby'      , function(data){ tv.postPowerstateStandby()      ; });

      socket.on('message'      , function(data){ console.log('client is here')      ; });;
      //socket.broadcast.emit('message', 'Another client has just connected!');


      // Will do something when its value changed
      setInterval(function(){  

          socket.emit('counter'                        , counter);
          socket.emit('newcounter'                        , counter);
          socket.emit('iArrayLightConnected'           ,iArrayLightConnected);                                         
          socket.emit('sArrayLightManufacturerName'    ,sArrayLightManufacturerName);                                         
          socket.emit('sArrayLightModelid'             ,sArrayLightModelid             );                                 
          socket.emit('sArrayLightName'                ,sArrayLightName                );                             
          socket.emit('sArrayLightSwversion'           ,sArrayLightSwversion           );                                   
          socket.emit('sArrayLightType'                ,sArrayLightType                );                             
          socket.emit('sArrayLightUniqueid'            ,sArrayLightUniqueid            );                                 
          socket.emit('bArrayLightOn'                  ,bArrayLightOn                  );                           
          socket.emit('bArrayLightReachable'           ,bArrayLightReachable           );                                   
          socket.emit('sArrayLightAlert'               ,sArrayLightAlert               );                               
          socket.emit('sArrayLightColorMode'           ,sArrayLightColorMode           );                                   
          socket.emit('sArrayLightEffect'              ,sArrayLightEffect              );                               
          socket.emit('iArrayLightTransitionTime'      ,iArrayLightTransitionTime      );                                       
          socket.emit('fArrayLightXyCur'               ,fArrayLightXyCur               );                               
          socket.emit('fArrayLightXyXCur'              ,fArrayLightXyXCur              );                               
          socket.emit('fArrayLightXyYCur'              ,fArrayLightXyYCur              );                               
          socket.emit('iArrayLightCtCur'               ,iArrayLightCtCur               );                               
          socket.emit('iArrayLightHueCur'              ,iArrayLightHueCur              );                               
          socket.emit('iArrayLightSatCur'              ,iArrayLightSatCur              );                               
          socket.emit('iArrayLightBriCur'              ,iArrayLightBriCur              );                               
          socket.emit('iArrayLightRgbRedCur'           ,iArrayLightRgbRedCur           );                                   
          socket.emit('iArrayLightRgbGreenCur'         ,iArrayLightRgbGreenCur         );                                     
          socket.emit('iArrayLightRgbBlueCur'          ,iArrayLightRgbBlueCur          );                                   
          socket.emit('fArrayLightXyNew'               ,fArrayLightXyNew               );                               
          socket.emit('fArrayLightXyXNew'              ,fArrayLightXyXNew              );                               
          socket.emit('fArrayLightXyYNew'              ,fArrayLightXyYNew              );                               
          socket.emit('iArrayLightCtNew'               ,iArrayLightCtNew               );                               
          socket.emit('iArrayLightHueNew'              ,iArrayLightHueNew              );                               
          socket.emit('iArrayLightSatNew'              ,iArrayLightSatNew              );                               
          socket.emit('iArrayLightBriNew'              ,iArrayLightBriNew              );                               
          socket.emit('iArrayLightRgbRedNew'           ,iArrayLightRgbRedNew           );                                   
          socket.emit('iArrayLightRgbGreenNew'         ,iArrayLightRgbGreenNew         );                                     
          socket.emit('iArrayLightRgbBlueNew'          ,iArrayLightRgbBlueNew          );                                   
          socket.emit('fArrayLightXyOld'               ,fArrayLightXyOld               );                               
          socket.emit('fArrayLightXyXOld'              ,fArrayLightXyXOld              );                               
          socket.emit('fArrayLightXyYOld'              ,fArrayLightXyYOld              );                               
          socket.emit('iArrayLightCtOld'               ,iArrayLightCtOld               );                               
          socket.emit('iArrayLightHueOld'              ,iArrayLightHueOld              );                               
          socket.emit('iArrayLightSatOld'              ,iArrayLightSatOld              );                               
          socket.emit('iArrayLightBriOld'              ,iArrayLightBriOld              );                               
          socket.emit('iArrayLightRgbRedOld'           ,iArrayLightRgbRedOld           );                                   
          socket.emit('iArrayLightRgbGreenOld'         ,iArrayLightRgbGreenOld         );                                     
          socket.emit('iArrayLightRgbBlueOld'          ,iArrayLightRgbBlueOld          );                                   
          socket.emit('iArraySensorConnected'          ,iArraySensorConnected          );                                   
          socket.emit('sArraySensorName'               ,sArraySensorName               );                               
          socket.emit('sArraySensorType'               ,sArraySensorType               );                               
          socket.emit('sArraySensorModelId'            ,sArraySensorModelId            );                                 
          socket.emit('sArraySensorManufacturerName'   ,sArraySensorManufacturerName   );                                           
          socket.emit('sArraySensorSwVersion'          ,sArraySensorSwVersion          );                                   
          socket.emit('sArraySensorUniqueId'           ,sArraySensorUniqueId           );                                   
          socket.emit('bArraySensorRecycle'            ,bArraySensorRecycle            );                                 
          socket.emit('sArraySensorNameCur'            ,sArraySensorNameCur            );                                 
          socket.emit('sArraySensorTypeCur'            ,sArraySensorTypeCur            );                                 
          socket.emit('sArraySensorModelIdCur'         ,sArraySensorModelIdCur         );                                     
          socket.emit('sArraySensorManufacturerNameCur',sArraySensorManufacturerNameCur);                                             
          socket.emit('sArraySensorSwVersionCur'       ,sArraySensorSwVersionCur       );                                       
          socket.emit('sArraySensorUniqueIdCur'        ,sArraySensorUniqueIdCur        );                                     
          socket.emit('bArraySensorRecycleCur'         ,bArraySensorRecycleCur         );                                     
          socket.emit('sArraySensorNameNew'            ,sArraySensorNameNew            );                                 
          socket.emit('sArraySensorTypeNew'            ,sArraySensorTypeNew            );                                 
          socket.emit('sArraySensorModelIdNew'         ,sArraySensorModelIdNew         );                                     
          socket.emit('sArraySensorManufacturerNameNew',sArraySensorManufacturerNameNew);                                             
          socket.emit('sArraySensorSwVersionNew'       ,sArraySensorSwVersionNew       );                                       
          socket.emit('sArraySensorUniqueIdNew'        ,sArraySensorUniqueIdNew        );                                     
          socket.emit('bArraySensorRecycleNew'         ,bArraySensorRecycleNew         );                                     
          socket.emit('sArraySensorNameOld'            ,sArraySensorNameOld            );                                 
          socket.emit('sArraySensorTypeOld'            ,sArraySensorTypeOld            );                                 
          socket.emit('sArraySensorModelIdOld'         ,sArraySensorModelIdOld         );                                     
          socket.emit('sArraySensorManufacturerNameOld',sArraySensorManufacturerNameOld);                                             
          socket.emit('sArraySensorSwVersionOld'       ,sArraySensorSwVersionOld       );                                       
          socket.emit('sArraySensorUniqueIdOld'        ,sArraySensorUniqueIdOld        );                                     
          socket.emit('bArraySensorRecycleOld'         ,bArraySensorRecycleOld         );                                     
          socket.emit('iArraySensorButtonEvent'        ,iArraySensorButtonEvent        );                                     
          socket.emit('iArraySensorLightLevel'         ,iArraySensorLightLevel         );                                     
          socket.emit('bArraySensorDark'               ,bArraySensorDark               );                               
          socket.emit('bArraySensorDaylight'           ,bArraySensorDaylight           );                                   
          socket.emit('iArraySensorStatus'             ,iArraySensorStatus             );                                 
          socket.emit('sArraySensorLastupdated'        ,sArraySensorLastupdated        );                                     
          socket.emit('bArraySensorPresence'           ,bArraySensorPresence           );                                   
          socket.emit('iArraySensorTemperature'        ,iArraySensorTemperature        );                                     
          socket.emit('iArraySensorButtonEventCur'     ,iArraySensorButtonEventCur     );                                         
          socket.emit('iArraySensorLightLevelCur'      ,iArraySensorLightLevelCur      );                                       
          socket.emit('bArraySensorDarkCur'            ,bArraySensorDarkCur            );                                 
          socket.emit('bArraySensorDaylightCur'        ,bArraySensorDaylightCur        );                                     
          socket.emit('iArraySensorStatusCur'          ,iArraySensorStatusCur          );                                   
          socket.emit('sArraySensorLastupdatedCur'     ,sArraySensorLastupdatedCur     );                                         
          socket.emit('bArraySensorPresenceCur'        ,bArraySensorPresenceCur        );                                     
          socket.emit('iArraySensorTemperatureCur'     ,iArraySensorTemperatureCur     );                                         
          socket.emit('iArraySensorButtonEventNew'     ,iArraySensorButtonEventNew     );                                         
          socket.emit('iArraySensorLightLevelNew'      ,iArraySensorLightLevelNew      );                                       
          socket.emit('bArraySensorDarkNew'            ,bArraySensorDarkNew            );                                 
          socket.emit('bArraySensorDaylightNew'        ,bArraySensorDaylightNew        );                                     
          socket.emit('iArraySensorStatusNew'          ,iArraySensorStatusNew          );                                   
          socket.emit('sArraySensorLastupdatedNew'     ,sArraySensorLastupdatedNew     );                                         
          socket.emit('bArraySensorPresenceNew'        ,bArraySensorPresenceNew        );                                     
          socket.emit('iArraySensorTemperatureNew'     ,iArraySensorTemperatureNew     );                                         
          socket.emit('iArraySensorButtonEventOld'     ,iArraySensorButtonEventOld     );                                         
          socket.emit('iArraySensorLightLevelOld'      ,iArraySensorLightLevelOld      );                                       
          socket.emit('bArraySensorDarkOld'            ,bArraySensorDarkOld            );                                 
          socket.emit('bArraySensorDaylightOld'        ,bArraySensorDaylightOld        );                                     
          socket.emit('iArraySensorStatusOld'          ,iArraySensorStatusOld          );                                   
          socket.emit('sArraySensorLastupdatedOld'     ,sArraySensorLastupdatedOld     );                                         
          socket.emit('bArraySensorPresenceOld'        ,bArraySensorPresenceOld        );                                     
          socket.emit('iArraySensorTemperatureOld'     ,iArraySensorTemperatureOld     );                                         
          socket.emit('bArraySensorOn'                 ,bArraySensorOn                 );                             
          socket.emit('iArraySensorBattery'            ,iArraySensorBattery            );                                 
          socket.emit('bArraySensorConfigured'         ,bArraySensorConfigured         );                                     
          socket.emit('bArraySensorReachable'          ,bArraySensorReachable          );                                   
          socket.emit('sArraySensorAlert'              ,sArraySensorAlert              );                               
          socket.emit('iArraySensorTholdDark'          ,iArraySensorTholdDark          );                                   
          socket.emit('iArraySensorTholdOffset'        ,iArraySensorTholdOffset        );                                     
          socket.emit('iArraySensorStatus'             ,iArraySensorStatus             );                                 
          socket.emit('iArraySensorTholdOffset'        ,iArraySensorTholdOffset        );                                     
          socket.emit('bArraySensorLedindication'      ,bArraySensorLedindication      );                                       
          socket.emit('bArraySensorUsertest'           ,bArraySensorUsertest           );                                   
          socket.emit('iArraySensorSensitivity'        ,iArraySensorSensitivity        );                                     
          socket.emit('iArraySensorSensitivityMax'     ,iArraySensorSensitivityMax     );                                         
          socket.emit('iArraySensorSunsetoffset'       ,iArraySensorSunsetoffset       );                                       
          socket.emit('iArraySensorSunriseoffset'      ,iArraySensorSunriseoffset      );                                       
          socket.emit('sArraySensorPending'            ,sArraySensorPending            );                                 
          socket.emit('bArraySensorOnCur'              ,bArraySensorOnCur              );                               
          socket.emit('iArraySensorBatteryCur'         ,iArraySensorBatteryCur         );                                     
          socket.emit('bArraySensorConfiguredCur'      ,bArraySensorConfiguredCur      );                                       
          socket.emit('bArraySensorReachableCur'       ,bArraySensorReachableCur       );                                       
          socket.emit('sArraySensorAlertCur'           ,sArraySensorAlertCur           );                                   
          socket.emit('iArraySensorTholdDarkCur'       ,iArraySensorTholdDarkCur       );                                       
          socket.emit('iArraySensorTholdOffsetCur'     ,iArraySensorTholdOffsetCur     );                                         
          socket.emit('iArraySensorStatusCur'          ,iArraySensorStatusCur          );                                   
          socket.emit('iArraySensorTholdOffsetCur'     ,iArraySensorTholdOffsetCur     );                                         
          socket.emit('bArraySensorLedindicationCur'   ,bArraySensorLedindicationCur   );                                           
          socket.emit('bArraySensorUsertestCur'        ,bArraySensorUsertestCur        );                                     
          socket.emit('iArraySensorSensitivityCur'     ,iArraySensorSensitivityCur     );                                         
          socket.emit('iArraySensorSensitivityMaxCur'  ,iArraySensorSensitivityMaxCur  );                                           
          socket.emit('iArraySensorSunsetoffsetCur'    ,iArraySensorSunsetoffsetCur    );                                         
          socket.emit('iArraySensorSunriseoffsetCur'   ,iArraySensorSunriseoffsetCur   );                                           
          socket.emit('sArraySensorPendingCur'         ,sArraySensorPendingCur         );                                     
          socket.emit('bArraySensorOnNew'              ,bArraySensorOnNew              );                               
          socket.emit('iArraySensorBatteryNew'         ,iArraySensorBatteryNew         );                                     
          socket.emit('bArraySensorConfiguredNew'      ,bArraySensorConfiguredNew      );                                       
          socket.emit('bArraySensorReachableNew'       ,bArraySensorReachableNew       );                                       
          socket.emit('sArraySensorAlertNew'           ,sArraySensorAlertNew           );                                   
          socket.emit('iArraySensorTholdDarkNew'       ,iArraySensorTholdDarkNew       );                                       
          socket.emit('iArraySensorTholdOffsetNew'     ,iArraySensorTholdOffsetNew     );                                         
          socket.emit('iArraySensorStatusNew'          ,iArraySensorStatusNew          );                                   
          socket.emit('iArraySensorTholdOffsetNew'     ,iArraySensorTholdOffsetNew     );                                         
          socket.emit('bArraySensorLedindicationNew'   ,bArraySensorLedindicationNew   );                                           
          socket.emit('bArraySensorUsertestNew'        ,bArraySensorUsertestNew        );                                     
          socket.emit('iArraySensorSensitivityNew'     ,iArraySensorSensitivityNew     );                                         
          socket.emit('iArraySensorSensitivityMaxNew'  ,iArraySensorSensitivityMaxNew  );                                           
          socket.emit('iArraySensorSunsetoffsetNew'    ,iArraySensorSunsetoffsetNew    );                                         
          socket.emit('iArraySensorSunriseoffsetNew'   ,iArraySensorSunriseoffsetNew   );                                           
          socket.emit('sArraySensorPendingNew'         ,sArraySensorPendingNew         );                                     
          socket.emit('bArraySensorOnOld'              ,bArraySensorOnOld              );                               
          socket.emit('iArraySensorBatteryOld'         ,iArraySensorBatteryOld         );                                     
          socket.emit('bArraySensorConfiguredOld'      ,bArraySensorConfiguredOld      );                                       
          socket.emit('bArraySensorReachableOld'       ,bArraySensorReachableOld       );                                       
          socket.emit('sArraySensorAlertOld'           ,sArraySensorAlertOld           );                                   
          socket.emit('iArraySensorTholdDarkOld'       ,iArraySensorTholdDarkOld       );                                       
          socket.emit('iArraySensorTholdOffsetOld'     ,iArraySensorTholdOffsetOld     );                                         
          socket.emit('iArraySensorStatusOld'          ,iArraySensorStatusOld          );                                   
          socket.emit('iArraySensorTholdOffsetOld'     ,iArraySensorTholdOffsetOld     );                                         
          socket.emit('bArraySensorLedindicationOld'   ,bArraySensorLedindicationOld   );                                           
          socket.emit('bArraySensorUsertestOld'        ,bArraySensorUsertestOld        );                                     
          socket.emit('iArraySensorSensitivityOld'     ,iArraySensorSensitivityOld     );                                         
          socket.emit('iArraySensorSensitivityMaxOld'  ,iArraySensorSensitivityMaxOld  );                                           
          socket.emit('iArraySensorSunsetoffsetOld'    ,iArraySensorSunsetoffsetOld    );                                         
          socket.emit('iArraySensorSunriseoffsetOld'   ,iArraySensorSunriseoffsetOld   );                                           
          socket.emit('sArraySensorPendingOld'         ,sArraySensorPendingOld         );                   
      }, 500);
});




function ReplicationCheck(){
    iArrayLightHueCur !== iArrayLightHueOld
}



exports.ReplicatedEvent = function(sVariableName){
    // use socket.io
    var io = require('socket.io').listen(server);

    //turn off debug
    //io.set('log level', 0);

    // define interactions with client
    io.sockets.on('connection', function(socket){
	  
    console.log("FunctionCall: ReplicatedEvent: " + sVariableName);		


             if (VarName == 'iArrayLightConnected'           ){ socket.emit('iArrayLightConnected'           ,iArrayLightConnected           ); }                
        else if (VarName == 'sArrayLightManufacturerName'    ){ socket.emit('sArrayLightManufacturerName'    ,sArrayLightManufacturerName    ); }         
        else if (VarName == 'sArrayLightModelid'             ){ socket.emit('sArrayLightModelid'             ,sArrayLightModelid             ); }     
        else if (VarName == 'sArrayLightName'                ){ socket.emit('sArrayLightName'                ,sArrayLightName                ); }     
        else if (VarName == 'sArrayLightSwversion'           ){ socket.emit('sArrayLightSwversion'           ,sArrayLightSwversion           ); }     
        else if (VarName == 'sArrayLightType'                ){ socket.emit('sArrayLightType'                ,sArrayLightType                ); }     
        else if (VarName == 'sArrayLightUniqueid'            ){ socket.emit('sArrayLightUniqueid'            ,sArrayLightUniqueid            ); }     
        else if (VarName == 'bArrayLightOn'                  ){ socket.emit('bArrayLightOn'                  ,bArrayLightOn                  ); }     
        else if (VarName == 'bArrayLightReachable'           ){ socket.emit('bArrayLightReachable'           ,bArrayLightReachable           ); }     
        else if (VarName == 'sArrayLightAlert'               ){ socket.emit('sArrayLightAlert'               ,sArrayLightAlert               ); }     
        else if (VarName == 'sArrayLightColorMode'           ){ socket.emit('sArrayLightColorMode'           ,sArrayLightColorMode           ); }     
        else if (VarName == 'sArrayLightEffect'              ){ socket.emit('sArrayLightEffect'              ,sArrayLightEffect              ); }     
        else if (VarName == 'iArrayLightTransitionTime'      ){ socket.emit('iArrayLightTransitionTime'      ,iArrayLightTransitionTime      ); }     
        else if (VarName == 'fArrayLightXyCur'               ){ socket.emit('fArrayLightXyCur'               ,fArrayLightXyCur               ); }     
        else if (VarName == 'fArrayLightXyXCur'              ){ socket.emit('fArrayLightXyXCur'              ,fArrayLightXyXCur              ); }     
        else if (VarName == 'fArrayLightXyYCur'              ){ socket.emit('fArrayLightXyYCur'              ,fArrayLightXyYCur              ); }     
        else if (VarName == 'iArrayLightCtCur'               ){ socket.emit('iArrayLightCtCur'               ,iArrayLightCtCur               ); }     
        else if (VarName == 'iArrayLightHueCur'              ){ socket.emit('iArrayLightHueCur'              ,iArrayLightHueCur              ); }     
        else if (VarName == 'iArrayLightSatCur'              ){ socket.emit('iArrayLightSatCur'              ,iArrayLightSatCur              ); }     
        else if (VarName == 'iArrayLightBriCur'              ){ socket.emit('iArrayLightBriCur'              ,iArrayLightBriCur              ); }     
        else if (VarName == 'iArrayLightRgbRedCur'           ){ socket.emit('iArrayLightRgbRedCur'           ,iArrayLightRgbRedCur           ); }     
        else if (VarName == 'iArrayLightRgbGreenCur'         ){ socket.emit('iArrayLightRgbGreenCur'         ,iArrayLightRgbGreenCur         ); }     
        else if (VarName == 'iArrayLightRgbBlueCur'          ){ socket.emit('iArrayLightRgbBlueCur'          ,iArrayLightRgbBlueCur          ); }     
        else if (VarName == 'fArrayLightXyNew'               ){ socket.emit('fArrayLightXyNew'               ,fArrayLightXyNew               ); }     
        else if (VarName == 'fArrayLightXyXNew'              ){ socket.emit('fArrayLightXyXNew'              ,fArrayLightXyXNew              ); }     
        else if (VarName == 'fArrayLightXyYNew'              ){ socket.emit('fArrayLightXyYNew'              ,fArrayLightXyYNew              ); }     
        else if (VarName == 'iArrayLightCtNew'               ){ socket.emit('iArrayLightCtNew'               ,iArrayLightCtNew               ); }     
        else if (VarName == 'iArrayLightHueNew'              ){ socket.emit('iArrayLightHueNew'              ,iArrayLightHueNew              ); }     
        else if (VarName == 'iArrayLightSatNew'              ){ socket.emit('iArrayLightSatNew'              ,iArrayLightSatNew              ); }     
        else if (VarName == 'iArrayLightBriNew'              ){ socket.emit('iArrayLightBriNew'              ,iArrayLightBriNew              ); }     
        else if (VarName == 'iArrayLightRgbRedNew'           ){ socket.emit('iArrayLightRgbRedNew'           ,iArrayLightRgbRedNew           ); }     
        else if (VarName == 'iArrayLightRgbGreenNew'         ){ socket.emit('iArrayLightRgbGreenNew'         ,iArrayLightRgbGreenNew         ); }     
        else if (VarName == 'iArrayLightRgbBlueNew'          ){ socket.emit('iArrayLightRgbBlueNew'          ,iArrayLightRgbBlueNew          ); }     
        else if (VarName == 'fArrayLightXyOld'               ){ socket.emit('fArrayLightXyOld'               ,fArrayLightXyOld               ); }     
        else if (VarName == 'fArrayLightXyXOld'              ){ socket.emit('fArrayLightXyXOld'              ,fArrayLightXyXOld              ); }     
        else if (VarName == 'fArrayLightXyYOld'              ){ socket.emit('fArrayLightXyYOld'              ,fArrayLightXyYOld              ); }     
        else if (VarName == 'iArrayLightCtOld'               ){ socket.emit('iArrayLightCtOld'               ,iArrayLightCtOld               ); }     
        else if (VarName == 'iArrayLightHueOld'              ){ socket.emit('iArrayLightHueOld'              ,iArrayLightHueOld              ); }     
        else if (VarName == 'iArrayLightSatOld'              ){ socket.emit('iArrayLightSatOld'              ,iArrayLightSatOld              ); }     
        else if (VarName == 'iArrayLightBriOld'              ){ socket.emit('iArrayLightBriOld'              ,iArrayLightBriOld              ); }     
        else if (VarName == 'iArrayLightRgbRedOld'           ){ socket.emit('iArrayLightRgbRedOld'           ,iArrayLightRgbRedOld           ); }     
        else if (VarName == 'iArrayLightRgbGreenOld'         ){ socket.emit('iArrayLightRgbGreenOld'         ,iArrayLightRgbGreenOld         ); }     
        else if (VarName == 'iArrayLightRgbBlueOld'          ){ socket.emit('iArrayLightRgbBlueOld'          ,iArrayLightRgbBlueOld          ); }     
        else if (VarName == 'iArraySensorConnected'          ){ socket.emit('iArraySensorConnected'          ,iArraySensorConnected          ); }     
        else if (VarName == 'sArraySensorName'               ){ socket.emit('sArraySensorName'               ,sArraySensorName               ); }     
        else if (VarName == 'sArraySensorType'               ){ socket.emit('sArraySensorType'               ,sArraySensorType               ); }     
        else if (VarName == 'sArraySensorModelId'            ){ socket.emit('sArraySensorModelId'            ,sArraySensorModelId            ); }     
        else if (VarName == 'sArraySensorManufacturerName'   ){ socket.emit('sArraySensorManufacturerName'   ,sArraySensorManufacturerName   ); }     
        else if (VarName == 'sArraySensorSwVersion'          ){ socket.emit('sArraySensorSwVersion'          ,sArraySensorSwVersion          ); }     
        else if (VarName == 'sArraySensorUniqueId'           ){ socket.emit('sArraySensorUniqueId'           ,sArraySensorUniqueId           ); }     
        else if (VarName == 'bArraySensorRecycle'            ){ socket.emit('bArraySensorRecycle'            ,bArraySensorRecycle            ); }     
        else if (VarName == 'sArraySensorNameCur'            ){ socket.emit('sArraySensorNameCur'            ,sArraySensorNameCur            ); }     
        else if (VarName == 'sArraySensorTypeCur'            ){ socket.emit('sArraySensorTypeCur'            ,sArraySensorTypeCur            ); }     
        else if (VarName == 'sArraySensorModelIdCur'         ){ socket.emit('sArraySensorModelIdCur'         ,sArraySensorModelIdCur         ); }     
        else if (VarName == 'sArraySensorManufacturerNameCur'){ socket.emit('sArraySensorManufacturerNameCur',sArraySensorManufacturerNameCur); }     
        else if (VarName == 'sArraySensorSwVersionCur'       ){ socket.emit('sArraySensorSwVersionCur'       ,sArraySensorSwVersionCur       ); }     
        else if (VarName == 'sArraySensorUniqueIdCur'        ){ socket.emit('sArraySensorUniqueIdCur'        ,sArraySensorUniqueIdCur        ); }     
        else if (VarName == 'bArraySensorRecycleCur'         ){ socket.emit('bArraySensorRecycleCur'         ,bArraySensorRecycleCur         ); }     
        else if (VarName == 'sArraySensorNameNew'            ){ socket.emit('sArraySensorNameNew'            ,sArraySensorNameNew            ); }     
        else if (VarName == 'sArraySensorTypeNew'            ){ socket.emit('sArraySensorTypeNew'            ,sArraySensorTypeNew            ); }     
        else if (VarName == 'sArraySensorModelIdNew'         ){ socket.emit('sArraySensorModelIdNew'         ,sArraySensorModelIdNew         ); }     
        else if (VarName == 'sArraySensorManufacturerNameNew'){ socket.emit('sArraySensorManufacturerNameNew',sArraySensorManufacturerNameNew); }     
        else if (VarName == 'sArraySensorSwVersionNew'       ){ socket.emit('sArraySensorSwVersionNew'       ,sArraySensorSwVersionNew       ); }     
        else if (VarName == 'sArraySensorUniqueIdNew'        ){ socket.emit('sArraySensorUniqueIdNew'        ,sArraySensorUniqueIdNew        ); }     
        else if (VarName == 'bArraySensorRecycleNew'         ){ socket.emit('bArraySensorRecycleNew'         ,bArraySensorRecycleNew         ); }     
        else if (VarName == 'sArraySensorNameOld'            ){ socket.emit('sArraySensorNameOld'            ,sArraySensorNameOld            ); }     
        else if (VarName == 'sArraySensorTypeOld'            ){ socket.emit('sArraySensorTypeOld'            ,sArraySensorTypeOld            ); }     
        else if (VarName == 'sArraySensorModelIdOld'         ){ socket.emit('sArraySensorModelIdOld'         ,sArraySensorModelIdOld         ); }     
        else if (VarName == 'sArraySensorManufacturerNameOld'){ socket.emit('sArraySensorManufacturerNameOld',sArraySensorManufacturerNameOld); }     
        else if (VarName == 'sArraySensorSwVersionOld'       ){ socket.emit('sArraySensorSwVersionOld'       ,sArraySensorSwVersionOld       ); }     
        else if (VarName == 'sArraySensorUniqueIdOld'        ){ socket.emit('sArraySensorUniqueIdOld'        ,sArraySensorUniqueIdOld        ); }     
        else if (VarName == 'bArraySensorRecycleOld'         ){ socket.emit('bArraySensorRecycleOld'         ,bArraySensorRecycleOld         ); }     
        else if (VarName == 'iArraySensorButtonEvent'        ){ socket.emit('iArraySensorButtonEvent'        ,iArraySensorButtonEvent        ); }     
        else if (VarName == 'iArraySensorLightLevel'         ){ socket.emit('iArraySensorLightLevel'         ,iArraySensorLightLevel         ); }     
        else if (VarName == 'bArraySensorDark'               ){ socket.emit('bArraySensorDark'               ,bArraySensorDark               ); }     
        else if (VarName == 'bArraySensorDaylight'           ){ socket.emit('bArraySensorDaylight'           ,bArraySensorDaylight           ); }     
        else if (VarName == 'iArraySensorStatus'             ){ socket.emit('iArraySensorStatus'             ,iArraySensorStatus             ); }     
        else if (VarName == 'sArraySensorLastupdated'        ){ socket.emit('sArraySensorLastupdated'        ,sArraySensorLastupdated        ); }     
        else if (VarName == 'bArraySensorPresence'           ){ socket.emit('bArraySensorPresence'           ,bArraySensorPresence           ); }     
        else if (VarName == 'iArraySensorTemperature'        ){ socket.emit('iArraySensorTemperature'        ,iArraySensorTemperature        ); }     
        else if (VarName == 'iArraySensorButtonEventCur'     ){ socket.emit('iArraySensorButtonEventCur'     ,iArraySensorButtonEventCur     ); }     
        else if (VarName == 'iArraySensorLightLevelCur'      ){ socket.emit('iArraySensorLightLevelCur'      ,iArraySensorLightLevelCur      ); }     
        else if (VarName == 'bArraySensorDarkCur'            ){ socket.emit('bArraySensorDarkCur'            ,bArraySensorDarkCur            ); }     
        else if (VarName == 'bArraySensorDaylightCur'        ){ socket.emit('bArraySensorDaylightCur'        ,bArraySensorDaylightCur        ); }     
        else if (VarName == 'iArraySensorStatusCur'          ){ socket.emit('iArraySensorStatusCur'          ,iArraySensorStatusCur          ); }     
        else if (VarName == 'sArraySensorLastupdatedCur'     ){ socket.emit('sArraySensorLastupdatedCur'     ,sArraySensorLastupdatedCur     ); }     
        else if (VarName == 'bArraySensorPresenceCur'        ){ socket.emit('bArraySensorPresenceCur'        ,bArraySensorPresenceCur        ); }     
        else if (VarName == 'iArraySensorTemperatureCur'     ){ socket.emit('iArraySensorTemperatureCur'     ,iArraySensorTemperatureCur     ); }     
        else if (VarName == 'iArraySensorButtonEventNew'     ){ socket.emit('iArraySensorButtonEventNew'     ,iArraySensorButtonEventNew     ); }     
        else if (VarName == 'iArraySensorLightLevelNew'      ){ socket.emit('iArraySensorLightLevelNew'      ,iArraySensorLightLevelNew      ); }     
        else if (VarName == 'bArraySensorDarkNew'            ){ socket.emit('bArraySensorDarkNew'            ,bArraySensorDarkNew            ); }     
        else if (VarName == 'bArraySensorDaylightNew'        ){ socket.emit('bArraySensorDaylightNew'        ,bArraySensorDaylightNew        ); }     
        else if (VarName == 'iArraySensorStatusNew'          ){ socket.emit('iArraySensorStatusNew'          ,iArraySensorStatusNew          ); }     
        else if (VarName == 'sArraySensorLastupdatedNew'     ){ socket.emit('sArraySensorLastupdatedNew'     ,sArraySensorLastupdatedNew     ); }     
        else if (VarName == 'bArraySensorPresenceNew'        ){ socket.emit('bArraySensorPresenceNew'        ,bArraySensorPresenceNew        ); }     
        else if (VarName == 'iArraySensorTemperatureNew'     ){ socket.emit('iArraySensorTemperatureNew'     ,iArraySensorTemperatureNew     ); }     
        else if (VarName == 'iArraySensorButtonEventOld'     ){ socket.emit('iArraySensorButtonEventOld'     ,iArraySensorButtonEventOld     ); }     
        else if (VarName == 'iArraySensorLightLevelOld'      ){ socket.emit('iArraySensorLightLevelOld'      ,iArraySensorLightLevelOld      ); }     
        else if (VarName == 'bArraySensorDarkOld'            ){ socket.emit('bArraySensorDarkOld'            ,bArraySensorDarkOld            ); }     
        else if (VarName == 'bArraySensorDaylightOld'        ){ socket.emit('bArraySensorDaylightOld'        ,bArraySensorDaylightOld        ); }     
        else if (VarName == 'iArraySensorStatusOld'          ){ socket.emit('iArraySensorStatusOld'          ,iArraySensorStatusOld          ); }     
        else if (VarName == 'sArraySensorLastupdatedOld'     ){ socket.emit('sArraySensorLastupdatedOld'     ,sArraySensorLastupdatedOld     ); }     
        else if (VarName == 'bArraySensorPresenceOld'        ){ socket.emit('bArraySensorPresenceOld'        ,bArraySensorPresenceOld        ); }     
        else if (VarName == 'iArraySensorTemperatureOld'     ){ socket.emit('iArraySensorTemperatureOld'     ,iArraySensorTemperatureOld     ); }     
        else if (VarName == 'bArraySensorOn'                 ){ socket.emit('bArraySensorOn'                 ,bArraySensorOn                 ); }     
        else if (VarName == 'iArraySensorBattery'            ){ socket.emit('iArraySensorBattery'            ,iArraySensorBattery            ); }     
        else if (VarName == 'bArraySensorConfigured'         ){ socket.emit('bArraySensorConfigured'         ,bArraySensorConfigured         ); }     
        else if (VarName == 'bArraySensorReachable'          ){ socket.emit('bArraySensorReachable'          ,bArraySensorReachable          ); }     
        else if (VarName == 'sArraySensorAlert'              ){ socket.emit('sArraySensorAlert'              ,sArraySensorAlert              ); }     
        else if (VarName == 'iArraySensorTholdDark'          ){ socket.emit('iArraySensorTholdDark'          ,iArraySensorTholdDark          ); }     
        else if (VarName == 'iArraySensorTholdOffset'        ){ socket.emit('iArraySensorTholdOffset'        ,iArraySensorTholdOffset        ); }     
        else if (VarName == 'iArraySensorStatus'             ){ socket.emit('iArraySensorStatus'             ,iArraySensorStatus             ); }     
        else if (VarName == 'iArraySensorTholdOffset'        ){ socket.emit('iArraySensorTholdOffset'        ,iArraySensorTholdOffset        ); }     
        else if (VarName == 'bArraySensorLedindication'      ){ socket.emit('bArraySensorLedindication'      ,bArraySensorLedindication      ); }     
        else if (VarName == 'bArraySensorUsertest'           ){ socket.emit('bArraySensorUsertest'           ,bArraySensorUsertest           ); }     
        else if (VarName == 'iArraySensorSensitivity'        ){ socket.emit('iArraySensorSensitivity'        ,iArraySensorSensitivity        ); }     
        else if (VarName == 'iArraySensorSensitivityMax'     ){ socket.emit('iArraySensorSensitivityMax'     ,iArraySensorSensitivityMax     ); }     
        else if (VarName == 'iArraySensorSunsetoffset'       ){ socket.emit('iArraySensorSunsetoffset'       ,iArraySensorSunsetoffset       ); }     
        else if (VarName == 'iArraySensorSunriseoffset'      ){ socket.emit('iArraySensorSunriseoffset'      ,iArraySensorSunriseoffset      ); }     
        else if (VarName == 'sArraySensorPending'            ){ socket.emit('sArraySensorPending'            ,sArraySensorPending            ); }     
        else if (VarName == 'bArraySensorOnCur'              ){ socket.emit('bArraySensorOnCur'              ,bArraySensorOnCur              ); }     
        else if (VarName == 'iArraySensorBatteryCur'         ){ socket.emit('iArraySensorBatteryCur'         ,iArraySensorBatteryCur         ); }     
        else if (VarName == 'bArraySensorConfiguredCur'      ){ socket.emit('bArraySensorConfiguredCur'      ,bArraySensorConfiguredCur      ); }     
        else if (VarName == 'bArraySensorReachableCur'       ){ socket.emit('bArraySensorReachableCur'       ,bArraySensorReachableCur       ); }     
        else if (VarName == 'sArraySensorAlertCur'           ){ socket.emit('sArraySensorAlertCur'           ,sArraySensorAlertCur           ); }     
        else if (VarName == 'iArraySensorTholdDarkCur'       ){ socket.emit('iArraySensorTholdDarkCur'       ,iArraySensorTholdDarkCur       ); }     
        else if (VarName == 'iArraySensorTholdOffsetCur'     ){ socket.emit('iArraySensorTholdOffsetCur'     ,iArraySensorTholdOffsetCur     ); }     
        else if (VarName == 'iArraySensorStatusCur'          ){ socket.emit('iArraySensorStatusCur'          ,iArraySensorStatusCur          ); }     
        else if (VarName == 'iArraySensorTholdOffsetCur'     ){ socket.emit('iArraySensorTholdOffsetCur'     ,iArraySensorTholdOffsetCur     ); }     
        else if (VarName == 'bArraySensorLedindicationCur'   ){ socket.emit('bArraySensorLedindicationCur'   ,bArraySensorLedindicationCur   ); }     
        else if (VarName == 'bArraySensorUsertestCur'        ){ socket.emit('bArraySensorUsertestCur'        ,bArraySensorUsertestCur        ); }     
        else if (VarName == 'iArraySensorSensitivityCur'     ){ socket.emit('iArraySensorSensitivityCur'     ,iArraySensorSensitivityCur     ); }     
        else if (VarName == 'iArraySensorSensitivityMaxCur'  ){ socket.emit('iArraySensorSensitivityMaxCur'  ,iArraySensorSensitivityMaxCur  ); }     
        else if (VarName == 'iArraySensorSunsetoffsetCur'    ){ socket.emit('iArraySensorSunsetoffsetCur'    ,iArraySensorSunsetoffsetCur    ); }     
        else if (VarName == 'iArraySensorSunriseoffsetCur'   ){ socket.emit('iArraySensorSunriseoffsetCur'   ,iArraySensorSunriseoffsetCur   ); }     
        else if (VarName == 'sArraySensorPendingCur'         ){ socket.emit('sArraySensorPendingCur'         ,sArraySensorPendingCur         ); }     
        else if (VarName == 'bArraySensorOnNew'              ){ socket.emit('bArraySensorOnNew'              ,bArraySensorOnNew              ); }     
        else if (VarName == 'iArraySensorBatteryNew'         ){ socket.emit('iArraySensorBatteryNew'         ,iArraySensorBatteryNew         ); }     
        else if (VarName == 'bArraySensorConfiguredNew'      ){ socket.emit('bArraySensorConfiguredNew'      ,bArraySensorConfiguredNew      ); }     
        else if (VarName == 'bArraySensorReachableNew'       ){ socket.emit('bArraySensorReachableNew'       ,bArraySensorReachableNew       ); }     
        else if (VarName == 'sArraySensorAlertNew'           ){ socket.emit('sArraySensorAlertNew'           ,sArraySensorAlertNew           ); }     
        else if (VarName == 'iArraySensorTholdDarkNew'       ){ socket.emit('iArraySensorTholdDarkNew'       ,iArraySensorTholdDarkNew       ); }     
        else if (VarName == 'iArraySensorTholdOffsetNew'     ){ socket.emit('iArraySensorTholdOffsetNew'     ,iArraySensorTholdOffsetNew     ); }     
        else if (VarName == 'iArraySensorStatusNew'          ){ socket.emit('iArraySensorStatusNew'          ,iArraySensorStatusNew          ); }     
        else if (VarName == 'iArraySensorTholdOffsetNew'     ){ socket.emit('iArraySensorTholdOffsetNew'     ,iArraySensorTholdOffsetNew     ); }     
        else if (VarName == 'bArraySensorLedindicationNew'   ){ socket.emit('bArraySensorLedindicationNew'   ,bArraySensorLedindicationNew   ); }     
        else if (VarName == 'bArraySensorUsertestNew'        ){ socket.emit('bArraySensorUsertestNew'        ,bArraySensorUsertestNew        ); }     
        else if (VarName == 'iArraySensorSensitivityNew'     ){ socket.emit('iArraySensorSensitivityNew'     ,iArraySensorSensitivityNew     ); }     
        else if (VarName == 'iArraySensorSensitivityMaxNew'  ){ socket.emit('iArraySensorSensitivityMaxNew'  ,iArraySensorSensitivityMaxNew  ); }     
        else if (VarName == 'iArraySensorSunsetoffsetNew'    ){ socket.emit('iArraySensorSunsetoffsetNew'    ,iArraySensorSunsetoffsetNew    ); }     
        else if (VarName == 'iArraySensorSunriseoffsetNew'   ){ socket.emit('iArraySensorSunriseoffsetNew'   ,iArraySensorSunriseoffsetNew   ); }     
        else if (VarName == 'sArraySensorPendingNew'         ){ socket.emit('sArraySensorPendingNew'         ,sArraySensorPendingNew         ); }     
        else if (VarName == 'bArraySensorOnOld'              ){ socket.emit('bArraySensorOnOld'              ,bArraySensorOnOld              ); }     
        else if (VarName == 'iArraySensorBatteryOld'         ){ socket.emit('iArraySensorBatteryOld'         ,iArraySensorBatteryOld         ); }     
        else if (VarName == 'bArraySensorConfiguredOld'      ){ socket.emit('bArraySensorConfiguredOld'      ,bArraySensorConfiguredOld      ); }     
        else if (VarName == 'bArraySensorReachableOld'       ){ socket.emit('bArraySensorReachableOld'       ,bArraySensorReachableOld       ); }     
        else if (VarName == 'sArraySensorAlertOld'           ){ socket.emit('sArraySensorAlertOld'           ,sArraySensorAlertOld           ); }     
        else if (VarName == 'iArraySensorTholdDarkOld'       ){ socket.emit('iArraySensorTholdDarkOld'       ,iArraySensorTholdDarkOld       ); }     
        else if (VarName == 'iArraySensorTholdOffsetOld'     ){ socket.emit('iArraySensorTholdOffsetOld'     ,iArraySensorTholdOffsetOld     ); }     
        else if (VarName == 'iArraySensorStatusOld'          ){ socket.emit('iArraySensorStatusOld'          ,iArraySensorStatusOld          ); }     
        else if (VarName == 'iArraySensorTholdOffsetOld'     ){ socket.emit('iArraySensorTholdOffsetOld'     ,iArraySensorTholdOffsetOld     ); }     
        else if (VarName == 'bArraySensorLedindicationOld'   ){ socket.emit('bArraySensorLedindicationOld'   ,bArraySensorLedindicationOld   ); }     
        else if (VarName == 'bArraySensorUsertestOld'        ){ socket.emit('bArraySensorUsertestOld'        ,bArraySensorUsertestOld        ); }     
        else if (VarName == 'iArraySensorSensitivityOld'     ){ socket.emit('iArraySensorSensitivityOld'     ,iArraySensorSensitivityOld     ); }     
        else if (VarName == 'iArraySensorSensitivityMaxOld'  ){ socket.emit('iArraySensorSensitivityMaxOld'  ,iArraySensorSensitivityMaxOld  ); }     
        else if (VarName == 'iArraySensorSunsetoffsetOld'    ){ socket.emit('iArraySensorSunsetoffsetOld'    ,iArraySensorSunsetoffsetOld    ); }     
        else if (VarName == 'iArraySensorSunriseoffsetOld'   ){ socket.emit('iArraySensorSunriseoffsetOld'   ,iArraySensorSunriseoffsetOld   ); }     
        else if (VarName == 'sArraySensorPendingOld'         ){ socket.emit('sArraySensorPendingOld'         ,sArraySensorPendingOld         ); }   
        else { //ReplicateAll; 
        };
    }
)};

//Reset the page to home
function goHomepage(){
      window.history.pushState("", "", '/');
}








////		for (x = 0; x < ModeArrayLength ; x++)
////		{                                                      								//		
////			ModeAccessLevelArray[x]=(ModeAccessLevelArray[x]); 								//		
////		}              













