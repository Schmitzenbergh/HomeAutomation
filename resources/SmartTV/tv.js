var request = require('request');
var sUri = 'http://192.168.0.97';
var sPort = '1925';

var jsonGET = function (sPath){ 
  return { uri: sUri + ':' + sPort + sPath, json: true, }; 
};

var jsonPOST = function (sPath, jInfo){
  return { uri: sUri + ':' + sPort + sPath, method: 'POST', json: true, body: jInfo }; 
};



request(jsonGET("/5/ambilight/topology"), function(error, response, body) { console.log(body); });
request(jsonGET("/5/ambilight/processed"), function(error, response, body) { console.log(body); });
request(jsonGET("/5/audio/volume"), function(error, response, body) { console.log(body); });


request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });



//request(jsonGET("/5/ambilight"), function(error, response, body) { console.log(body); });


request(jsonGET("/5/sources"), function(error, response, body) { console.log(body); });


//GET:

//  fout channellists
//  fout channellists/id
//  fout channels
//  fout channels/current
//  fout channels/id       

request(jsonGet("/5/ambilight/lounge"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/ambilight/mode"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/ambilight/measured"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/ambilight/processed"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/ambilight"), function(error, response, body) { console.log(body); });
//request(jsonGet("/5/activities"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/applications"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/audio/volume"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/channeldb/tv"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/context"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/sources/current"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system/country"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system/name"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system/menulanguage"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system/deviceid_encrypted"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system/epgsource"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system/model"), function(error, response, body) { console.log(body); });                         //  !!!depreciated
request(jsonGet("/5/system/model_encrypted"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system/softwareversion"), function(error, response, body) { console.log(body); });                //  !!!depreciated
request(jsonGet("/5/system/softwareversion_encrypted"), function(error, response, body) { console.log(body); });
request(jsonGet("/5/system/serialnumber"), function(error, response, body) { console.log(body); });                   //  !!!depreciated
request(jsonGet("/5/system/serialnumber_encrypted"), function(error, response, body) { console.log(body); });


request(jsonPOST("/5/ambilight/lounge", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/ambilight/mode", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/ambilight/cached", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/audio/volume", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/key", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/input/pointer", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/sources", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/sources/current", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/powerstate", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/ambilight/power", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });
request(jsonPOST("/5/network/devices", {} ), function (error, res, body){ console.log(res.caseless.dict.date); });




                                                                      //Check JSON!!!!
http://192.168.0.97:1925/5/activities/tv                              {"channelList":{"id":"alltv","version":"6"},"channel":{"name":"France 4","preset":14,"ccid":26}}
//http://192.168.0.97:1925/5/ambilight/currentconfiguration             {"styleName":"FOLLOW_VIDEO","isExpert":false,"menuSetting":"STANDARD"}
http://192.168.0.97:1925/5/ambilight/lounge                           {"color":{"hue":0,"saturation":0,"brightness":0},"colordelta":{"hue":0,"saturation":0,"brightness":0},"speed":0,"mode":"Default"}
http://192.168.0.97:1925/5/ambilight/power                            {"power":"On"} or {"power":"Off"}
//http://192.168.0.97:1925/5/ambilight/supportedstyles                  {"supportedStyles":[{"styleName":"OFF"},{"styleName":"FOLLOW_VIDEO"},{"styleName":"FOLLOW_AUDIO","algorithms":["ENERGY_ADAPTIVE_BRIGHTNESS","ENERGY_ADAPTIVE_COLORS","VU_METER","SPECTRUM_ANALYZER","KNIGHT_RIDER_CLOCKWISE","KNIGHT_RIDER_ALTERNATING","RANDOM_PIXEL_FLASH","STROBO","PARTY"],"maxTuning":2},{"styleName":"FOLLOW_COLOR","algorithms":["MANUAL_HUE","AUTOMATIC_HUE"],"maxSpeed":255},{"styleName":"LOUNGE"},{"styleName":"MANUAL"},{"styleName":"EXPERT"},{"styleName":"GRID"}]}
http://192.168.0.97:1925/5/ambilight/mode                             {"current":"internal"}
http://192.168.0.97:1925/5/ambilight/cached                           {"layer1":{"left":{"0":{"r":0,"g":0,"b":0},"1":{"r":0,"g":0,"b":0},"2":{"r":0,"g":0,"b":0},"3":{"r":0,"g":0,"b":0}},"top":{"0":{"r":0,"g":0,"b":0},"1":{"r":0,"g":0,"b":0},"2":{"r":0,"g":0,"b":0},"3":{"r":0,"g":0,"b":0},"4":{"r":0,"g":0,"b":0},"5":{"r":0,"g":0,"b":0},"6":{"r":0,"g":0,"b":0},"7":{"r":0,"g":0,"b":0}},"right":{"0":{"r":0,"g":0,"b":0},"1":{"r":0,"g":0,"b":0},"2":{"r":0,"g":0,"b":0},"3":{"r":0,"g":0,"b":0}}}}
http://192.168.0.97:1925/5/ambilight/topology                         {"layers":"1","left":4,"top":8,"bottom":0,"right":4}
http://192.168.0.97:1925/5/ambilight/measured                         {"layer1":{"left":{"0":{"r":43,"g":18,"b":24},"1":{"r":122,"g":79,"b":84},"2":{"r":114,"g":154,"b":130},"3":{"r":164,"g":189,"b":191}},"top":{"0":{"r":173,"g":189,"b":191},"1":{"r":178,"g":186,"b":186},"2":{"r":186,"g":180,"b":172},"3":{"r":192,"g":186,"b":172},"4":{"r":196,"g":192,"b":181},"5":{"r":193,"g":187,"b":173},"6":{"r":192,"g":186,"b":172},"7":{"r":196,"g":188,"b":179}},"right":{"0":{"r":196,"g":191,"b":185},"1":{"r":113,"g":108,"b":115},"2":{"r":69,"g":75,"b":88},"3":{"r":56,"g":51,"b":23}}}}
http://192.168.0.97:1925/5/ambilight/processed                        {"layer1":{"left":{"0":{"r":145,"g":7,"b":32},"1":{"r":254,"g":75,"b":92},"2":{"r":102,"g":255,"b":158},"3":{"r":162,"g":245,"b":254}},"top":{"0":{"r":188,"g":247,"b":254},"1":{"r":222,"g":255,"b":254},"2":{"r":254,"g":231,"b":202},"3":{"r":254,"g":233,"b":186},"4":{"r":254,"g":240,"b":203},"5":{"r":254,"g":235,"b":184},"6":{"r":254,"g":234,"b":186},"7":{"r":254,"g":226,"b":197}},"right":{"0":{"r":254,"g":234,"b":213},"1":{"r":243,"g":213,"b":254},"2":{"r":133,"g":164,"b":254},"3":{"r":201,"g":164,"b":29}}}}
http://192.168.0.97:1925/5/powerstate                                 {"power":"On"} or {"power":"Standby"}
http://192.168.0.97:1925/5/system                                     {"menulanguage":"Dutch","name":"55PUS7181\/12","country":"Netherlands","serialnumber_encrypted":"F6905Z+vyquNhZoXegQ1DzZXCqMIcjJpkzy3LsiPac=\n","softwareversion_encrypted":"1YWR42sjQ6xdjuyIXWZbyPnoRswLoRswLmKtAhR9GRsBx1qY=\n","model_encrypted":"jGNvXDerdJoWjOpwh\/n0gw2MgM7oRswLoRswLKC73wfMgra3S62c4=\n","deviceid_encrypted":"7mv3ZEtMH8oRswL0RoRswLISTn38FN8HAqfmSF95qoaiRsuukSraQ=\n","nettvversion":"6.0.2","epgsource":"one","api_version":{"Major":6,"Minor":2,"Patch":0},"featuring":{"jsonfeatures":{"editfavorites":["TVChannels","SatChannels"],"recordings":["List","Schedule","Manage"],"ambilight":["LoungeLight","Hue","Ambilight"],"menuitems":["Setup_Menu"],"textentry":["context_based","initial_string_available","editor_info_available"],"applications":["TV_Apps","TV_Games","TV_Settings"],"pointer":["not_available"],"inputkey":["key"],"activities":["intent"],"channels":["preset_string"],"mappings":["server_mapping"]},"systemfeatures":{"tvtype":"consumer","content":["dmr","dms_tad"],"tvsearch":"intent","pairing_type":"digest_auth_pairing","secured_transport":"true"}}}


