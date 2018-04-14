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



function ReplicatedEvent(sVariableName){
	  console.log("FunctionCall: ReplicatedEvent: " + sVariableName);		

    //Request
	       if (VarName == 'iArrayLightHueCur'){ socket.emit('iArrayLightHueCur', iArrayLightHueCur); }
	  else if (VarName == 'iArrayLightHueNew'){	socket.emit('iArrayLightHueNew', iArrayLightHueNew); }
	  else if (VarName == 'iArrayLightHueOld'){	socket.emit('iArrayLightHueOld', iArrayLightHueCur); }
	  else { //ReplicateAll;
	  }
}

//Reset the page to home
function goHomepage(){
      window.history.pushState("", "", '/');
}








////		for (x = 0; x < ModeArrayLength ; x++)
////		{                                                      								//		
////			ModeAccessLevelArray[x]=(ModeAccessLevelArray[x]); 								//		
////		}              













