/***************************************************************************************************
*   Info:                                                                                          *
*                                                                                                  *
*   Tested on Philips Smart Tv (55PFS8209/12)                                                      *
*   - Need to be checked                                                                           *
*   Examples:                                                                                      *
*   GET  - getJSON('9',function(callback){ console.log(callback)})                                 *
*   POST - postJSON('12', { "key": "VolumeDown" }, function(callback){ console.log(callback) });   *
*                                                                                                  *
*   	                                                                                             *
***************************************************************************************************/       

//
//  TODO :      
//    * PERFORMANCE CHECK
//    * DEBUG COPYPASTE: http://192.168.0.97:1925/5/audio/volume
//    * PUT 'update objects'
//    * DELETE 'remove objects'
//



//tv.pushBufferobjInputKeyVolumeDown();
//tv.pushBufferobj('/5/input/key', { "key": "VolumeDown" });



var http = require("http");
//var request = require('request');

/******************\
| Predefined Paths |###############################################################################################################################################################################
\******************/
 var arrPos = 0;
 var sArrayPaths = [];
 sArrayPaths[0]=undefined;                                        //   EMPTY
 sArrayPaths[1]='/5/activities/tv';                               // GET -      // {"channelList":{"id":"alltv","version":"60"},"channel":{"name":"NPO 1 HD","preset":1,"ccid":1000147}}
 sArrayPaths[2]='/5/ambilight/cached';                            // GET - POST // {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":0}}}}
 sArrayPaths[3]='/5/ambilight/lounge';                            // GET - POST // {"speed":0,"colordelta":{"brightness":0,"saturation":0,"hue":0},"color":{"brightness":0,"saturation":0,"hue":0},"mode":"Default"}
 sArrayPaths[4]='/5/ambilight/measured';                          // GET -      // {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":`10}}}}
 sArrayPaths[5]='/5/ambilight/mode';                              // GET - POST // 
 sArrayPaths[6]='/5/ambilight/processed';                         // GET -      // {"layer1":{"bottom":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254}},"right":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254}},"left":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254}},"top":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254},"4":{"b":42,"g":0,"r":254},"5":{"b":42,"g":0,"r":254},"6":{"b":42,"g":0,"r":254},"7":{"b":42,"g":0,"r":254}}}}
 sArrayPaths[7]='/5/ambilight/topology';                          // GET -      // {"bottom":2,"left":4,"right":4,"top":8,"layers":"1"}
 sArrayPaths[8]='/5/applications';                                // GET -      // {"applications":[{"id":"com.google.tv.netflix.NetflixActivity-com.google.tv.netflix","order":4,"intent":{"action":"#Intent;action=android.intent.action.MAIN;category=android.intent.category.LAUNCHER;launchFlags=0x10200000;component=com.google.tv.netflix/.NetflixActivity;end","component":{"packageName":"com.google.tv.netflix","className":"com.google.tv.netflix.NetflixActivity"}},"label":"Netflix"}],"version":8048} 
 sArrayPaths[9]='/5/audio/volume';                                // GET - POST // {"min":0,"current":20,"muted":true,"max":60}
sArrayPaths[10]='/5/channeldb/tv';                                // GET -      // {"favoriteLists":[],"channelLists":[{"id":"alltv","version":"60"}]} 
sArrayPaths[11]='/5/context';                                     // GET -      // {"data":"NA","level2":"Playstate","level3":"NA","level1":"WatchExtension"} 
sArrayPaths[12]='/5/input/key';                                   //     - POST // { "key": "VolumeUp" }       
sArrayPaths[13]='/5/input/pointer';                               //     - POST //      
sArrayPaths[14]='/5/network/devices';                             // GET -      // [{"wake-on-lan":"Disabled","type":"Wifi","id":"wifi0","mac":"30:10:B3:C0:AB:65"},{"wake-on-lan":"Enabled","id":"eth0","mac":"1B:5A:6C:7E:80:77","type":"Ethernet","ip":"192.168.0.97"}]   
sArrayPaths[15]='/5/powerstate';                                  // GET - POST // {"powerstate":"On"} or {"powerstate":"Standby"}   
sArrayPaths[16]='/5/system';                                      // GET -      // {"serialnumber_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","nettvversion":"5.0.0","name":"wlan tv","model_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","menulanguage":"Dutch","softwareversion_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","deviceid_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","country":"Netherlands"}
sArrayPaths[17]='/5/system/country';                              // GET -      // {"country":"Netherlands"}  
sArrayPaths[18]='/5/system/deviceid_encrypted';                   // GET -      // {"serialnumber_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}  
sArrayPaths[19]='/5/system/epgsource';                            // GET -      // {"epgsource":"broadcast"}   
sArrayPaths[20]='/5/system/menulanguage';                         // GET -      // {"menulanguage":"Dutch"} 
sArrayPaths[21]='/5/system/model_encrypted';                      // GET -      // {"model_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}  
sArrayPaths[22]='/5/system/name';                                 // GET -      // {"name":"SmartTV"}
sArrayPaths[23]='/5/system/softwareversion_encrypted';            // GET -      // {"softwareversion_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}   
sArrayPaths[24]='/5/system/serialnumber_encrypted';               // GET -      // {"country":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}
sArrayPaths[25]='/5/system/timestamp';                            // GET -      // {"timestamp": "49348"}


var proto='http://';
var hostname= '192.168.0.97';
var port= 1925;
var path= '/5/activities/tv';
var sUri = hostname;
var sPort = port;



/***************\
| POST Function |###############################################################################################################################################################################
\***************/

exports.pushBufferobj = function(path, jObj, callback){

    var postOptions = {
        uri: proto + hostname + ':' + port + path,
        method: 'POST',
        body: jObj,
        json: true,
    };

    request.post( postOptions, function(err, res) {
        if ( err || res.statusCode != 200){ 
            console.log(err);
        }
    });
    return Result; 
}



/***************************\
| PreDefined POST Functions |###############################################################################################################################################################################
\***************************/

exports.pushBufferobjAmbilightCached = function (){               pushBufferobj(sArrayPaths[2] ,{"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":0}}}}, function(callback){ console.log(callback) }); }
exports.pushBufferobjAmbiLightLounge = function (){               pushBufferobj(sArrayPaths[3] ,{"speed":0,"colordelta":{"brightness":0,"saturation":0,"hue":0},"color":{"brightness":0,"saturation":0,"hue":0},"mode":"Default"}, function(callback){ console.log(callback) }); }
exports.pushBufferobjAmbiLightMode = function (){                 pushBufferobj(sArrayPaths[5] ,{"current":"internal"}, function(callback){ console.log(callback) }); }
exports.pushBufferobjAudioVolume = function (){                   pushBufferobj(sArrayPaths[9] ,{"min":0,"current":20,"muted":true,"max":60}, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputPointer = function (){                  pushBufferobj(sArrayPaths[11],{ "?????": "?????" }, function(callback){ console.log(callback) }); }   //????
exports.pushBufferobjInputKeyStandby = function (){               pushBufferobj(sArrayPaths[12],{ "key": "Standby" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyBack = function (){                  pushBufferobj(sArrayPaths[12],{ "key": "Back" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyFind = function (){                  pushBufferobj(sArrayPaths[12],{ "key": "Find" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyRedColour = function (){             pushBufferobj(sArrayPaths[12],{ "key": "RedColour" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyGreenColour = function (){           pushBufferobj(sArrayPaths[12],{ "key": "GreenColour" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyYellowColour = function (){          pushBufferobj(sArrayPaths[12],{ "key": "YellowColour" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyBlueColour = function (){            pushBufferobj(sArrayPaths[12],{ "key": "BlueColour" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyHome = function (){                  pushBufferobj(sArrayPaths[12],{ "key": "Home" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyVolumeUp = function (){              pushBufferobj(sArrayPaths[12],{ "key": "VolumeUp" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyVolumeDown = function (){            pushBufferobj(sArrayPaths[12],{ "key": "VolumeDown" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyMute = function (){                  pushBufferobj(sArrayPaths[12],{ "key": "Mute"  }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyOptions = function (){               pushBufferobj(sArrayPaths[12],{ "key": "Options" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDot = function (){                   pushBufferobj(sArrayPaths[12],{ "key": "Dot"    }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit0 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit0" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit1 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit1" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit2 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit2" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit3 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit3" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit4 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit4" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit5 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit5" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit6 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit6" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit7 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit7" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit8 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit8" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyDigit9 = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Digit9" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyInfo = function (){                  pushBufferobj(sArrayPaths[12],{ "key": "Info" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyCursorUp = function (){              pushBufferobj(sArrayPaths[12],{ "key": "CursorUp" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyCursorDown = function (){            pushBufferobj(sArrayPaths[12],{ "key": "CursorDown" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyCursorLeft = function (){            pushBufferobj(sArrayPaths[12],{ "key": "CursorLeft" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyCursorRight = function (){           pushBufferobj(sArrayPaths[12],{ "key": "CursorRight" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyConfirm = function (){               pushBufferobj(sArrayPaths[12],{ "key": "Confirm" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyNext = function (){                  pushBufferobj(sArrayPaths[12],{ "key": "Next" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyPrevious = function (){              pushBufferobj(sArrayPaths[12],{ "key": "Previous" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyAdjust = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Adjust" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyWatchTV = function (){               pushBufferobj(sArrayPaths[12],{ "key": "WatchTV" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyViewmode = function (){              pushBufferobj(sArrayPaths[12],{ "key": "Viewmode" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyTeletext = function (){              pushBufferobj(sArrayPaths[12],{ "key": "Teletext" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeySubtitle = function (){              pushBufferobj(sArrayPaths[12],{ "key": "Subtitle" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyChannelStepUp = function (){         pushBufferobj(sArrayPaths[12],{ "key": "ChannelStepUp" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyChannelStepDown = function (){       pushBufferobj(sArrayPaths[12],{ "key": "ChannelStepDown" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeySource = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Source" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyAmbilightOnOff = function (){        pushBufferobj(sArrayPaths[12],{ "key": "AmbilightOnOff" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyPlayPause = function (){             pushBufferobj(sArrayPaths[12],{ "key": "PlayPause" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyPause = function (){                 pushBufferobj(sArrayPaths[12],{ "key": "Pause" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyFastForward = function (){           pushBufferobj(sArrayPaths[12],{ "key": "FastForward" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyStop = function (){                  pushBufferobj(sArrayPaths[12],{ "key": "Stop" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyRewind = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Rewind" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyRecord = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Record" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjInputKeyOnline = function (){                pushBufferobj(sArrayPaths[12],{ "key": "Online" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjPowerstateOn = function (){                  pushBufferobj(sArrayPaths[15],{ "powerstate":"On" }, function(callback){ console.log(callback) }); }
exports.pushBufferobjPowerstateStandby = function (){             pushBufferobj(sArrayPaths[15],{ "powerstate":"Standby" }, function(callback){ console.log(callback) }); }

/**************\
| GET Function |###############################################################################################################################################################################
\**************/



getJSON = function(path){

    var getOptions = {
      hostname: '192.168.0.97',
      port: 1925,
      path: path,
      method: 'GET',
      headers: {
        'Content-Type': 'text/html',
        'Content-Length': Buffer.byteLength("")
      }
    };

    var req = http.request( getOptions, function(res) {
      res.on('data', (chunk) => {
        Result = JSON.parse(chunk);
      });//res.on('end', () => { /**/ });
    });
    req.end();

    return Result;
}


/**************************\
| PreDefined GET Functions |###############################################################################################################################################################################
\**************************/
exports.returnVolume = function (){                         getJSON(sArrayPaths[1] ); return Result; };
exports.returnActivitiesTv = function (){                   getJSON(sArrayPaths[1] ); return Result; };
exports.returnAmbilightCached = function (){                getJSON(sArrayPaths[2] ); return Result; };
exports.returnAmbilightLounge = function (){                getJSON(sArrayPaths[3] ); return Result; };
exports.returnAmbilightMeasured = function (){              getJSON(sArrayPaths[4] ); return Result; };
exports.returnAmbilightMode = function (){                  getJSON(sArrayPaths[5] ); return Result; };
exports.returnAmbilightProcessed = function (){             getJSON(sArrayPaths[6] ); return Result; };
exports.returnAmbilightTopology = function (){              getJSON(sArrayPaths[7] ); return Result; };
exports.returnApplications = function (){                   getJSON(sArrayPaths[8] ); return Result; };
exports.returnAudioVolume = function (){                    getJSON(sArrayPaths[9] ); return Result; };
exports.returnChanneldbTv = function (){                    getJSON(sArrayPaths[10]); return Result; };
exports.returnContext = function (){                        getJSON(sArrayPaths[11]); return Result; };
exports.returnNetworkDevices = function (){                 getJSON(sArrayPaths[14]); return Result; };
exports.returnPowerstate = function (){                     getJSON(sArrayPaths[15]); return Result; };
exports.returnSystem = function (){                         getJSON(sArrayPaths[16]); return Result; };
exports.returnSystemCountry = function (){                  getJSON(sArrayPaths[17]); return Result; };
exports.returnSystemDeviceIdEncrypted = function (){        getJSON(sArrayPaths[18]); return Result; };
exports.returnSystemEpgsource = function (){                getJSON(sArrayPaths[19]); return Result; };
exports.returnSystemMenulanguage = function (){             getJSON(sArrayPaths[20]); return Result; };
exports.returnSystemModelEncrypted = function (){           getJSON(sArrayPaths[21]); return Result; };
exports.returnSystemName = function (){                     getJSON(sArrayPaths[22]); return Result; };
exports.returnSystemSoftwareversionEncrypted = function (){ getJSON(sArrayPaths[23]); return Result; };
exports.returnSystemSerialnumberEncrypted = function (){    getJSON(sArrayPaths[24]); return Result; };
exports.returnSystemTimeStamp = function (){                getJSON(sArrayPaths[25]); return Result; };



/************************\
| OLD GET/POST Functions |###############################################################################################################################################################################
\************************/
//    function getJSON(arrPos, callback){           //Example: getJSON('9',function(callback){ console.log(callback)})
//    
//        if ( arrPos < 1 ) return;
//        request.get({ uri: sUri + ':' + sPort + sArrayPaths[arrPos], json: true } , 
//            function(err, res) {
//                if ( err || res.statusCode != 200){ 
//                  console.log(err);
//                }
//                return callback(JSON.parse(res));
//                //callback(res.body);
//            }
//        );
//    }
//    
//    function postJSON(arrPos, jObj, callback){    //  Example:   postJSON('12', { "key": "VolumeDown" }, function(callback){ console.log(callback) });
//        if ( arrPos < 1 ) return;
//        request.post({ url: sUri + ':' + sPort + sArrayPaths[arrPos], body: jObj, json: true } , 
//            function(err, res) {
//                if ( err || res.statusCode != 200){ 
//                  console.log(err);
//                }
//                //console.log( 'Modified: ' + res.request.uri.href + ' ' + res.request.body );
//                callback('Modified: ' + res.request.uri.href + ' ' + res.request.body)
//            }
//        );
//    }
//  New approach, without delay or timeouts
//  console.log(Result.layer1);
//  function getTvAmbiInfo(){
//  
//  var Result = {};
//  
//  var options = {
//    hostname: '192.168.0.97',
//    port: 1925,
//    path: '/5/ambilight/processed',
//    method: 'GET',
//    headers: {
//      'Content-Type': 'text/html',
//      'Content-Length': Buffer.byteLength("")
//    }
//  };
//  
//  var req = http.request(options, (res) => {
//    res.setEncoding('utf8');
//    res.on('data', (chunk) => { Result = JSON.parse("" + chunk);});
//    res.on('end', () => { console.log('response: ENDED');});
//  });
//  
//  
//  req.on('error', function(e) { console.log('problem with request: ' + e.message); });
//  
//  // write data to request body
//  req.write(JSON.stringify(Result));
//  req.end();
//  };



exports = Result = {};