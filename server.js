//var jsonFile=fs.readFileSync('db.json', 'utf8');
//var jsonObj = JSON.parse(jsonFile);
var server;

//var keyArray    = fs.readFileSync(pathconfigvar + "./keyname.array", 'UTF8').split("\r");








 //console.log(data);  //htmlScript = toString().data;





/***************\
| NodeJS Server |###############################################################################################################################################################################
\***************/

server = http.createServer(function(req, res){
  console.log("Client connected");
  var bDoPageRefresh = false;
  var htmlScript;
    // your normal server code
    var path = url.parse(req.url).pathname;

    fs.readFile( pathconfig + 'db.var', "UTF8", function(err, data){
                  if (err){ return send404(res); };
                  htmlScript = data;
    });
    
    console.log(pathpublic);
    switch (path){
        case '/':
            fs.readFile( pathpublic + 'index.html', function(err, data){
              if (err){ return send404(res); };
              res.writeHead(200, {'Content-type': 'text/html'}); 
                res.write("<script>" + htmlScript + "</script>" + data + "test");
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
        fs.readFile(pathpublic + 'index.html', function(err, data){
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
//      setInterval(function(){  
//          socket.emit('test0', "test0");
//          socket.emit('test1', "test1");
//          socket.emit('test2', "test2");
//          socket.emit('test3', counter);
//          socket.emit('test4', counter);
//          socket.emit('test5', counter);
//          socket.emit('test6', counter);
//          socket.emit('test7', counter);
//          socket.emit('iArrayLightHueCur', iArrayLightHueCur);
//      }, 1000);
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














