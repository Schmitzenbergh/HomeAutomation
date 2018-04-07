//    var request = require('request');
//    var sUri = 'http://192.168.0.97';
//    var sPort = '1925';
//    
//    var jsonGET = function (sPath){ 
//      return { uri: sUri + ':' + sPort + sPath, json: true, }; 
//    };
//    
//    var jsonPOST = function (sPath, jInfo){
//      return { uri: sUri + ':' + sPort + sPath, method: 'POST', json: true, cb: jInfo }; 
//    };



//exports.ActivitiesTv        = function(){}                                                                               
//exports.AmbilightCached     = function(){}                                                                               
//exports.AmbilightLounge     = function(){}                                                                               
//exports.AmbilightMode       = function(){}                                                                               
//exports.AmbilightMeasured   = function(){}                                                                               
//exports.AmbilightProcessed  = function(){}                                                                               
//exports.AmbilightTopology   = function(){}                                                                               
//exports.Applications        = function(){}                                                                                
//exports.Volume              = function(){}                                                                          
//exports.ChanneldbTv         = function(){}                                                                               
//exports.Context             = function(){}                                                                                
//exports.Powerstate          = function(){}                                                                                
//exports.System              = function(){}                                                                                
//exports.Country             = function(){}                                                                         
//exports.Deviceid            = function(){}                                                        
//exports.Epgsource           = function(){}                                                                         
//exports.Menulanguage        = function(){}                                                                         
//exports.Model               = function(){}                                                    
//exports.Name                = function(){}                                                                         
//exports.Softwareversion     = function(){}                                                              
//exports.Serialnumber        = function(){}                                                            
//
//exports.getManufacturerName = function (iLightNumber){    , function (err, result) { if ( err || typeof result.manufacturername === undefined      ){ return err; } sArrayLightManufacturerName[iLightNumber]                              }); return sArrayLightManufacturerName[iLightNumber] ;};
//if ( err || res.statusCode != 200){ return; }; 

//console.log(JSON.stringify(this.body));


//var Somerequest = JSON.stringify(request(jsonGET("/5/audio/volume"), function(err, res) { if ( err ){ return err;}res.body; }));
//meer fout
//var Somerequest = request(jsonGET("/5/audio/volume"), function(err, res) { if ( err ){ return err;} JSON.stringify(res.body); });

//var testing = request(jsonGET("/5/audio/volume"), function(err, res) { if ( err ){ return err;} testing = JSON.stringify(res); });
//Somerequest = request(jsonGET("/5/audio/volume"), dubbelcheck )  
//dostuff = function(err, res) { 
//  if ( err ){ return err;}
//  console.log(res);
//  //Somerequest = res;
//}
//Somerequest = request(jsonGET("/5/audio/volume"), dostuff() )  



//function doCallback(data){
//  var self;
//  request(jsonGET("/5/audio/volume"),function (err, res, cb){ self = this; console.log(JSON.stringify(res));    });
//}




//testing = request(jsonGET("/5/audio/volume"), function(err, res) { if ( err ){ return err;} res(JSON.stringify(res)); });




//    function doCallback(data){
//      var self;
//      request(jsonGET("/5/audio/volume"),function (err, res, cb){ 
//        console.log(JSON.stringify(self));    });
//      console.log(JSON.stringify(self));
//    }
//    
//    
//    
//    //console.log(doCallback);
//    //doCallback(console.log());
//    //console.log(doCallback());
//    
//    
//    
//    console.log(JSON.stringify(doCallback()));
//    //console.log(JSON.stringify(this.testing));








//console.log();
//console.log(request(jsonGET("/5/audio/volume"), function(err, res) { if ( err ){ return; }; /********/ ; }));
//
//







////#1 - to here
//var myCallbackTemp = 
//    function(data) { 
//     console.log(''+data)
//    };





//2 - output here
//var usingItNowTemp = 
//    function(callback) { 
//      callback('get it?');
//    };
//
//usingItNowTemp(myCallbackTemp);






//function doMessageLog(msg){
//  //console.log(msg);

//}

//ActivitiesTv(console.log());

//console.log(newrequest());









//      
//request(jsonGET("/5/activities/tv")                        , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                        //      {"channelList":{"id":"alltv","version":"60"},"channel":{"name":"NPO 1 HD","preset":1,"ccid":1000147}}
//request(jsonGET("/5/ambilight/cached")                        , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                        //      {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":0}}}}
//request(jsonGET("/5/ambilight/lounge")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                        //      {"speed":40,"colordelta":{"brightness":100,"saturation":15,"hue":12},"color":{"brightness":180,"saturation":240,"hue":155},"mode":"Default"}
//request(jsonGET("/5/ambilight/mode")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                          //      {"current":"internal"}
//request(jsonGET("/5/ambilight/measured")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                      //      {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":`10}}}}
//request(jsonGET("/5/ambilight/processed")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                     //      {"layer1":{"bottom":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254}},"right":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254}},"left":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254}},"top":{"0":{"b":42,"g":0,"r":254},"1":{"b":42,"g":0,"r":254},"2":{"b":42,"g":0,"r":254},"3":{"b":42,"g":0,"r":254},"4":{"b":42,"g":0,"r":254},"5":{"b":42,"g":0,"r":254},"6":{"b":42,"g":0,"r":254},"7":{"b":42,"g":0,"r":254}}}}
//request(jsonGET("/5/ambilight/topology")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                      //      {"bottom":2,"left":4,"right":4,"top":8,"layers":"1"}
//request(jsonGET("/5/applications")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                            //      {"applications":[{"id":"com.google.tv.netflix.NetflixActivity-com.google.tv.netflix","order":4,"intent":{"action":"#Intent;action=android.intent.action.MAIN;category=android.intent.category.LAUNCHER;launchFlags=0x10200000;component=com.google.tv.netflix/.NetflixActivity;end","component":{"packageName":"com.google.tv.netflix","className":"com.google.tv.netflix.NetflixActivity"}},"label":"Netflix"}],"version":8048}
//request(jsonGET("/5/audio/volume")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                            //      {"min":0,"current":20,"muted":true,"max":60}
//request(jsonGET("/5/channeldb/tv")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                            //      {"favoriteLists":[],"channelLists":[{"id":"alltv","version":"60"}]}
//request(jsonGET("/5/context")                              , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                                 //      {"data":"NA","level2":"Playstate","level3":"NA","level1":"WatchExtension"}
//request(jsonGET("/5/powerstate")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                              //      {"powerstate":"On"}
//request(jsonGet("/5/system")                               , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                                  //      {"serialnumber_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","nettvversion":"5.0.0","name":"wlan tv","model_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","menulanguage":"Dutch","softwareversion_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","deviceid_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу=\n","country":"Netherlands"}
//request(jsonGet("/5/system/country")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                          //      {"country":"Netherlands"}
//request(jsonGet("/5/system/deviceid_encrypted")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });               //      {"serialnumber_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}
//request(jsonGet("/5/system/epgsource")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                        //      {"epgsource":"broadcast"}
//request(jsonGet("/5/system/menulanguage")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                     //      {"menulanguage":"Dutch"}
//request(jsonGet("/5/system/model_encrypted")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                  //      {"model_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}
//request(jsonGet("/5/system/name")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });                             //      {"name":"SmartTV"}
//request(jsonGet("/5/system/softwareversion_encrypted")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });        //      {"softwareversion_encrypted":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}
//request(jsonGet("/5/system/serialnumber_encrypted")                            , function(err, res, cb) {if ( err || res.statusCode != 200){ return;} console.log(cb);; });           //      {"country":"нєяєωιℓℓвєѕσмєєη¢яуρтє∂кєу"}
//
////POST 'Insert objects'
//request(jsonPOST("/5/ambilight/lounge", {} ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);; });                  //      {"speed":40,"colordelta":{"brightness":100,"saturation":15,"hue":12},"color":{"brightness":180,"saturation":240,"hue":155},"mode":"Default"}
//request(jsonPOST("/5/ambilight/mode", {} ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);; });                    //      {"current":"internal"}
//request(jsonPOST("/5/ambilight/cached", {} ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);; });                  //      {"layer1":{"bottom":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0}},"right":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"left":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0}},"top":{"0":{"b":0,"g":0,"r":0},"1":{"b":0,"g":0,"r":0},"2":{"b":0,"g":0,"r":0},"3":{"b":0,"g":0,"r":0},"4":{"b":0,"g":0,"r":0},"5":{"b":0,"g":0,"r":0},"6":{"b":0,"g":0,"r":0},"7":{"b":0,"g":0,"r":0}}}}
//request(jsonPOST("/5/activities/tv", {} ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);; });                     //      {"channelList":{"id":"alltv","version":"60"},"channel":{"name":"NPO 1 HD","preset":1,"ccid":1000147}}
//request(jsonPOST("/5/audio/volume", { "key": "VolumeUp" } ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);; });   //      {"min":0,"current":20,"muted":true,"max":60}
//request(jsonPOST("/5/input/key", {"key": "VolumeUp"} ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);; });                         //      { "key": "VolumeUp" }
//request(jsonPOST("/5/input/pointer", {} ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);; });                     //      {????}
//request(jsonPOST("/5/network/devices", {} ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);; });                   //      [{"wake-on-lan":"Disabled","type":"Wifi","id":"wifi0","mac":"30:10:B3:C0:AB:65"},{"wake-on-lan":"Enabled","id":"eth0","mac":"1B:5A:6C:7E:80:77","type":"Ethernet","ip":"192.168.0.97"}]
//request(jsonPOST("/5/powerstate", {"power":"Standby"} ), function (err, res, cb){if ( err || res.statusCode != 200){ return;} console.log(cb);});          //      {"powerstate":"On"} or {"powerstate":"Standby"}

//PUT 'update objects'
//DELETE 'update objects'






 

 var request = require('request');
var sUri = 'http://192.168.0.97';
var sPort = '1925';

var jsonGET = function (sPath){ 
  return { uri: sUri + ':' + sPort + sPath, json: true, }; 
};

var jsonPOST = function (sPath, jInfo){
  return { uri: sUri + ':' + sPort + sPath, method: 'POST', json: true, body: jInfo }; 
};

request(jsonGET("/5/ambilight/processed"), function(error, response, body) { console.log(body); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });


1 =



var jsonDataObj = { "key": "VolumeDown" };
request.post({
    url: 'http://192.168.0.97:1925/5/input/key',
    body: jsonDataObj,
    json: true
  }, function(error, response, body){
  console.log(response.statusCode );
});



var jsonDataObj = { "key": "VolumeDown" };
request.post({
    url: 'http://192.168.0.97:1925/5/input/key',
    body: jsonDataObj,
    json: true
  }, function(error, response, body){
  console.log(response.statusCode );
});