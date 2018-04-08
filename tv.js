
var request = require('request');
var sUri = 'http://192.168.0.97';
var sPort = '1925';
var sArrayItems = [];

////GET 'Get objects'                         //CHECK PERFORMANCE LATER

//request.get({ uri: sUri + ':' + sPort + '/5/activities/tv',                       json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"channelList":{"id":"alltv","version":"60"},"channel":{"name":"NPO 1 HD","preset":1,"ccid":1000147}}
//request.get({ uri: sUri + ':' + sPort + '/5/ambilight/cached',                    json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(res));; });     //    {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":0}}}}
//request.get({ uri: sUri + ':' + sPort + '/5/ambilight/lounge',                    json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"speed":0,"colordelta":{"brightness":0,"saturation":0,"hue":0},"color":{"brightness":0,"saturation":0,"hue":0},"mode":"Default"}
//request.get({ uri: sUri + ':' + sPort + '/5/ambilight/measured',                  json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":`10}}}}
//request.get({ uri: sUri + ':' + sPort + '/5/ambilight/processed',                 json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"layer1":{"bottom":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254}},"right":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254}},"left":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254}},"top":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254},"4":{"b":42,"g":0,"r":254},"5":{"b":42,"g":0,"r":254},"6":{"b":42,"g":0,"r":254},"7":{"b":42,"g":0,"r":254}}}}
//request.get({ uri: sUri + ':' + sPort + '/5/ambilight/topology',                  json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"bottom":2,"left":4,"right":4,"top":8,"layers":"1"}
//request.get({ uri: sUri + ':' + sPort + '/5/applications',                        json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"applications":[{"id":"com.google.tv.netflix.NetflixActivity-com.google.tv.netflix","order":4,"intent":{"action":"#Intent;action=android.intent.action.MAIN;category=android.intent.category.LAUNCHER;launchFlags=0x10200000;component=com.google.tv.netflix/.NetflixActivity;end","component":{"packageName":"com.google.tv.netflix","className":"com.google.tv.netflix.NetflixActivity"}},"label":"Netflix"}],"version":8048}
//request.get({ uri: sUri + ':' + sPort + '/5/audio/volume',                        json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"min":0,"current":20,"muted":true,"max":60}
//request.get({ uri: sUri + ':' + sPort + '/5/channeldb/tv',                        json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"favoriteLists":[],"channelLists":[{"id":"alltv","version":"60"}]}
//request.get({ uri: sUri + ':' + sPort + '/5/context',                             json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"data":"NA","level2":"Playstate","level3":"NA","level1":"WatchExtension"}






sArrayItems[0]='/5/powerstate';
sArrayItems[1]='/5/activities/tv';
sArrayItems[2]='/5/ambilight/cached';
sArrayItems[3]='/5/ambilight/lounge';
sArrayItems[4]='/5/ambilight/measured';
sArrayItems[5]='/5/ambilight/processed';
sArrayItems[6]='/5/ambilight/topology';
sArrayItems[7]='/5/applications';
sArrayItems[8]='/5/audio/volume';
sArrayItems[9]='/5/channeldb/tv';
sArrayItems[10]='/5/context';
sArrayItems[11]=;
sArrayItems[12]=;
sArrayItems[13]=;
sArrayItems[14]=;
sArrayItems[15]=;
sArrayItems[16]=;
sArrayItems[11]=;
sArrayItems[12]=;
sArrayItems[13]=;
sArrayItems[14]=;
sArrayItems[15]=;
sArrayItems[16]=;








arrPos = 0;
//Return
//console.log(getPowerState(0, function(callback){ return callback; }));


var result;
function getResult(arrPos, callback){

    if ( arrPos < 1 ) return;
    request.get({ uri: sUri + ':' + sPort + sArrayItems[arrPos], json: true } , 
        function(err, res) {
            if ( err || res.statusCode != 200){ 
              console.log(err);
            }
            callback(JSON.stringify(res.body));
        }
    );
}


getResult('1',function(callback){
  console.log(callback);
  result = callback;
})


console.log(getResultNow);

//function showresult(){
//console.log(result);
//};
//setInterval(showresult,1000)




//    {"powerstate":"On"}
//request.get({ uri: sUri + ':' + sPort + '/5/system',                              json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"serialnumber_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","nettvversion":"5.0.0","name":"wlan tv","model_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","menulanguage":"Dutch","softwareversion_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","deviceid_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","country":"Netherlands"}
//request.get({ uri: sUri + ':' + sPort + '/5/system/country',                      json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"country":"Netherlands"}
//request.get({ uri: sUri + ':' + sPort + '/5/system/deviceid_encrypted',           json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"serialnumber_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}
//request.get({ uri: sUri + ':' + sPort + '/5/system/epgsource',                    json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"epgsource":"broadcast"}
//request.get({ uri: sUri + ':' + sPort + '/5/system/menulanguage',                 json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"menulanguage":"Dutch"}
//request.get({ uri: sUri + ':' + sPort + '/5/system/model_encrypted',              json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"model_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}
//request.get({ uri: sUri + ':' + sPort + '/5/system/name',                         json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"name":"SmartTV"}
//request.get({ uri: sUri + ':' + sPort + '/5/system/softwareversion_encrypted',    json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"softwareversion_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}
//request.get({ uri: sUri + ':' + sPort + '/5/system/serialnumber_encrypted',       json: true } , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(JSON.stringify(cb));; });     //    {"country":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}


////POST 'Insert objects'

//request.post({ url: sUri + ':' + sPort + '/5/ambilight/lounge', body: { "key": "VolumeDown" },                json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    {"speed":40,"colordelta":{"brightness":100,"saturation":15,"hue":12},"color":{"brightness":180,"saturation":240,"hue":155},"mode":"Default"}     
//request.post({ url: sUri + ':' + sPort + '/5/ambilight/mode', body: { "key": "VolumeDown" },                  json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    {"current":"internal"}     
//request.post({ url: sUri + ':' + sPort + '/5/ambilight/cached', body: { "key": "VolumeDown" },                json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":0}}}}   
//request.post({ url: sUri + ':' + sPort + '/5/activities/tv', body: { "key": "VolumeDown" },                   json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    {"channelList":{"id":"alltv","version":"60"},"channel":{"name":"NPO 1 HD","preset":1,"ccid":1000147}}   
//request.post({ url: sUri + ':' + sPort + '/5/audio/volume', body: { "key": "VolumeDown" },                    json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    {"min":0,"current":20,"muted":true,"max":60}   
//request.post({ url: sUri + ':' + sPort + '/5/input/key', body: { "key": "VolumeUp" },                       json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    { "key": "VolumeUp" }   
//request.post({ url: sUri + ':' + sPort + '/5/input/pointer', body: { "key": "VolumeDown" },                   json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    {????}   
//request.post({ url: sUri + ':' + sPort + '/5/network/devices', body: { "key": "VolumeDown" },                 json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    [{"wake-on-lan":"Disabled","type":"Wifi","id":"wifi0","mac":"30:10:B3:C0:AB:65"},{"wake-on-lan":"Enabled","id":"eth0","mac":"1B:5A:6C:7E:80:77","type":"Ethernet","ip":"192.168.0.97"}]   
//request.post({ url: sUri + ':' + sPort + '/5/powerstate', body: { "key": "VolumeDown" },                      json: true }, function(error, response){ console.log(JSON.stringify(response) ); });    //    {"powerstate":"On"} or {"powerstate":"Standby"}   

//PUT 'update objects'
//DELETE 'update objects'
