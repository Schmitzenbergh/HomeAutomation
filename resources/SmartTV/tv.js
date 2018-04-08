/***************************************************************************************************
*   Info:                                                                                          *
*                                                                                                  *
*   Tested on Philips Smart Tv (55PFS8209/12)                                                      *
*                                                                                                  *
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

var request = require('request');
var sUri = 'http://192.168.0.97';
var sPort = '1925';
var sArrayPaths = [];
var arrPos = 0;

/********************\
| Predefined Pathsns |###############################################################################################################################################################################
\********************/

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



/********************\
| GET/POST Functions |###############################################################################################################################################################################
\********************/

function getJSON(arrPos, callback){           //Example: getJSON('9',function(callback){ console.log(callback)})

    if ( arrPos < 1 ) return;
    request.get({ uri: sUri + ':' + sPort + sArrayPaths[arrPos], json: true } , 
        function(err, res) {
            if ( err || res.statusCode != 200){ 
              console.log(err);
            }
            callback(JSON.stringify(res.body));
            //callback(res.body);
        }
    );
}

function postJSON(arrPos, jObj, callback){    //  Example:   postJSON('12', { "key": "VolumeDown" }, function(callback){ console.log(callback) });
    if ( arrPos < 1 ) return;
    request.post({ url: sUri + ':' + sPort + sArrayPaths[arrPos], body: jObj, json: true } , 
        function(err, res) {
            if ( err || res.statusCode != 200){ 
              console.log(err);
            }
            //console.log( 'Modified: ' + res.request.uri.href + ' ' + res.request.body );
            callback('Modified: ' + res.request.uri.href + ' ' + res.request.body)
        }
    );
}


/**************************\
| PreDefined GET Functions |###############################################################################################################################################################################
\**************************/

function getVolume(){                         getJSON('1' ,function(callback){ console.log(callback)}) }
function getActivitiesTv(){                   getJSON('1' ,function(callback){ console.log(callback)}) }
function getAmbilightCached(){                getJSON('2' ,function(callback){ console.log(callback)}) }
function getAmbilightLounge(){                getJSON('3' ,function(callback){ console.log(callback)}) }
function getAmbilightMeasured(){              getJSON('4' ,function(callback){ console.log(callback)}) }
function getAmbilightMode(){                  getJSON('5' ,function(callback){ console.log(callback)}) }
function getAmbilightProcessed(){             getJSON('6' ,function(callback){ console.log(callback)}) }
function getAmbilightTopology(){              getJSON('7' ,function(callback){ console.log(callback)}) }
function getApplications(){                   getJSON('8' ,function(callback){ console.log(callback)}) }
function getAudioVolume(){                    getJSON('9' ,function(callback){ console.log(callback)}) }
function getChanneldbTv(){                    getJSON('10',function(callback){ console.log(callback)}) }
function getContext(){                        getJSON('11',function(callback){ console.log(callback)}) }
function getNetworkDevices(){                 getJSON('14',function(callback){ console.log(callback)}) }
function getPowerstate(){                     getJSON('15',function(callback){ console.log(callback)}) }
function getSystem(){                         getJSON('16',function(callback){ console.log(callback)}) }
function getSystemCountry(){                  getJSON('17',function(callback){ console.log(callback)}) }
function getSystemDeviceIdEncrypted(){        getJSON('18',function(callback){ console.log(callback)}) }
function getSystemEpgsource(){                getJSON('19',function(callback){ console.log(callback)}) }
function getSystemMenulanguage(){             getJSON('20',function(callback){ console.log(callback)}) }
function getSystemModelEncrypted(){           getJSON('21',function(callback){ console.log(callback)}) }
function getSystemName(){                     getJSON('22',function(callback){ console.log(callback)}) }
function getSystemSoftwareversionEncrypted(){ getJSON('23',function(callback){ console.log(callback)}) }
function getSystemSerialnumberEncrypted(){    getJSON('24',function(callback){ console.log(callback)}) }


/***************************\
| PreDefined POST Functions |###############################################################################################################################################################################
\***************************/

function postAmbilightCached(){               postJSON('2',  {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":0}}}} }, function(callback){ console.log(callback) });
function postAmbiLightLounge(){               postJSON('3',  {"speed":0,"colordelta":{"brightness":0,"saturation":0,"hue":0},"color":{"brightness":0,"saturation":0,"hue":0},"mode":"Default"}, function(callback){ console.log(callback) }); }
function postAmbiLightMode(){                 postJSON('5',  {"current":"internal"}, function(callback){ console.log(callback) }); }
function postAudioVolume(){                   postJSON('9',  {"min":0,"current":20,"muted":true,"max":60}, function(callback){ console.log(callback) }); }
function postInputPointer(){                  postJSON('11', { "?????": "?????" }, function(callback){ console.log(callback) }); }   //????
function postInputKeyStandby(){               postJSON('12', { "key": "Standby" }, function(callback){ console.log(callback) }); }
function postInputKeyBack(){                  postJSON('12', { "key": "Back" }, function(callback){ console.log(callback) }); }
function postInputKeyFind(){                  postJSON('12', { "key": "Find" }, function(callback){ console.log(callback) }); }
function postInputKeyRedColour(){             postJSON('12', { "key": "RedColour" }, function(callback){ console.log(callback) }); }
function postInputKeyGreenColour(){           postJSON('12', { "key": "GreenColour" }, function(callback){ console.log(callback) }); }
function postInputKeyYellowColour(){          postJSON('12', { "key": "YellowColour" }, function(callback){ console.log(callback) }); }
function postInputKeyBlueColour(){            postJSON('12', { "key": "BlueColour" }, function(callback){ console.log(callback) }); }
function postInputKeyHome(){                  postJSON('12', { "key": "Home" }, function(callback){ console.log(callback) }); }
function postInputKeyVolumeUp(){              postJSON('12', { "key": "VolumeUp" }, function(callback){ console.log(callback) }); }
function postInputKeyVolumeDown(){            postJSON('12', { "key": "VolumeDown" }, function(callback){ console.log(callback) }); }
function postInputKeyMute(){                  postJSON('12', { "key": "Mute" }, function(callback){ console.log(callback) }); }
function postInputKeyOptions(){               postJSON('12', { "key": "Options" }, function(callback){ console.log(callback) }); }
function postInputKeyDot(){                   postJSON('12', { "key": "Dot" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit0(){                postJSON('12', { "key": "Digit0" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit1(){                postJSON('12', { "key": "Digit1" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit2(){                postJSON('12', { "key": "Digit2" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit3(){                postJSON('12', { "key": "Digit3" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit4(){                postJSON('12', { "key": "Digit4" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit5(){                postJSON('12', { "key": "Digit5" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit6(){                postJSON('12', { "key": "Digit6" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit7(){                postJSON('12', { "key": "Digit7" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit8(){                postJSON('12', { "key": "Digit8" }, function(callback){ console.log(callback) }); }
function postInputKeyDigit9(){                postJSON('12', { "key": "Digit9" }, function(callback){ console.log(callback) }); }
function postInputKeyInfo(){                  postJSON('12', { "key": "Info" }, function(callback){ console.log(callback) }); }
function postInputKeyCursorUp(){              postJSON('12', { "key": "CursorUp" }, function(callback){ console.log(callback) }); }
function postInputKeyCursorDown(){            postJSON('12', { "key": "CursorDown" }, function(callback){ console.log(callback) }); }
function postInputKeyCursorLeft(){            postJSON('12', { "key": "CursorLeft" }, function(callback){ console.log(callback) }); }
function postInputKeyCursorRight(){           postJSON('12', { "key": "CursorRight" }, function(callback){ console.log(callback) }); }
function postInputKeyConfirm(){               postJSON('12', { "key": "Confirm" }, function(callback){ console.log(callback) }); }
function postInputKeyNext(){                  postJSON('12', { "key": "Next" }, function(callback){ console.log(callback) }); }
function postInputKeyPrevious(){              postJSON('12', { "key": "Previous" }, function(callback){ console.log(callback) }); }
function postInputKeyAdjust(){                postJSON('12', { "key": "Adjust" }, function(callback){ console.log(callback) }); }
function postInputKeyWatchTV(){               postJSON('12', { "key": "WatchTV" }, function(callback){ console.log(callback) }); }
function postInputKeyViewmode(){              postJSON('12', { "key": "Viewmode" }, function(callback){ console.log(callback) }); }
function postInputKeyTeletext(){              postJSON('12', { "key": "Teletext" }, function(callback){ console.log(callback) }); }
function postInputKeySubtitle(){              postJSON('12', { "key": "Subtitle" }, function(callback){ console.log(callback) }); }
function postInputKeyChannelStepUp(){         postJSON('12', { "key": "ChannelStepUp" }, function(callback){ console.log(callback) }); }
function postInputKeyChannelStepDown(){       postJSON('12', { "key": "ChannelStepDown" }, function(callback){ console.log(callback) }); }
function postInputKeySource(){                postJSON('12', { "key": "Source" }, function(callback){ console.log(callback) }); }
function postInputKeyAmbilightOnOff(){        postJSON('12', { "key": "AmbilightOnOff" }, function(callback){ console.log(callback) }); }
function postInputKeyPlayPause(){             postJSON('12', { "key": "PlayPause" }, function(callback){ console.log(callback) }); }
function postInputKeyPause(){                 postJSON('12', { "key": "Pause" }, function(callback){ console.log(callback) }); }
function postInputKeyFastForward(){           postJSON('12', { "key": "FastForward" }, function(callback){ console.log(callback) }); }
function postInputKeyStop(){                  postJSON('12', { "key": "Stop" }, function(callback){ console.log(callback) }); }
function postInputKeyRewind(){                postJSON('12', { "key": "Rewind" }, function(callback){ console.log(callback) }); }
function postInputKeyRecord(){                postJSON('12', { "key": "Record" }, function(callback){ console.log(callback) }); }
function postInputKeyOnline(){                postJSON('12', { "key": "Online" }, function(callback){ console.log(callback) }); }
function postPowerstateOn(){                  postJSON('15', { "powerstate":"On" }, function(callback){ console.log(callback) }); }
function postPowerstateStandby(){             postJSON('15', { "powerstate":"Standby" }, function(callback){ console.log(callback) }); }
