#!/usr/bin/env node

debug = false;

//# Situation:                # Function:
//###############################################################################################################################################################################
//# Hue To Scriptvar          # getInfo, getInfoAll
//# Scriptvar to Hue          # setInfo, setInfoAll
//# From Hue                  # get[Variable], get[Variable]]All
//# To Hue                    # set[Variable], set[Variable]]All
//# From disk                 # loadInfo, loadInfoALL
//# To disk                   # saveInfo, saveInfoAll

//# From/To script            # not needed


/** getInfo **/
//get all attributes for 1 light from hue to script-variables
//###############################################################################################################################################################################
exports.getInfo = function( iLightNumber,sValue){
  client.getLight( iLightNumber, function( err, result ){ 

    if ( err || result === undefined || result.state === undefined ){ return err;}
    
    //General:
    if ( typeof result.manufacturername !== undefined   ){ sArrayLightManufacturerName[iLightNumber] = result.manufacturername;  };  // light.getManufacturerName( iLightNumber );     
    if ( typeof result.productname !== undefined        ){ sArrayLightProductname[iLightNumber] = result.productname;            };  // light.getModelId( iLightNumber );              
    if ( typeof result.modelid !== undefined            ){ sArrayLightModelid[iLightNumber] = result.modelid;                    };  // light.getModelId( iLightNumber );              
    if ( typeof result.name !== undefined               ){ sArrayLightName[iLightNumber] = result.name;                          };  // light.getName( iLightNumber );                 
    if ( typeof result.swversion !== undefined          ){ sArrayLightSwversion[iLightNumber] = result.swversion;                };  // light.getSwVersion( iLightNumber );            
    if ( typeof result.type !== undefined               ){ sArrayLightType[iLightNumber] = result.type;                          };  // light.getType( iLightNumber );                 
    if ( typeof result.uniqueid !== undefined           ){ sArrayLightUniqueid[iLightNumber] = result.uniqueid;                  };  // light.getUniqueid( iLightNumber );             
                                                                                                                                            
    //State:                                                                                                  
    if ( typeof result.state.on !== undefined           ){ bArrayLightOn[iLightNumber] = result.state.on;                         };  //light.getOn( iLightNumber );       
    if ( typeof result.state.bri !== undefined          ){ iArrayLightBriCur[iLightNumber] = result.state.bri;                    };  //light.getBri( iLightNumber );      
    if ( typeof result.state.hue !== undefined          ){ iArrayLightHueCur[iLightNumber] = result.state.hue;                    };  //light.getHue( iLightNumber );      
    if ( typeof result.state.sat !== undefined          ){ iArrayLightSatCur[iLightNumber] = result.state.sat;                    };  //light.getSat( iLightNumber );      
    if ( typeof result.state.effect !== undefined       ){ sArrayLightEffect[iLightNumber] = result.state.effect;                 };  //light.getEffect( iLightNumber );   
    if ( typeof result.state.xy !== undefined           ){ fArrayLightXyCur[iLightNumber] = result.state.xy;                      };  //light.getXy( iLightNumber );       
    if ( typeof result.state.xy[0] !== undefined        ){ fArrayLightXyXCur[iLightNumber] = result.state.xy[0];                  };  //light.getXyX( iLightNumber );      
    if ( typeof result.state.xy[1] !== undefined        ){ fArrayLightXyYCur[iLightNumber] = result.state.xy[1];                  };  //light.getXyY( iLightNumber );      
    if ( typeof result.state.ct !== undefined           ){ iArrayLightCtCur[iLightNumber] = result.state.ct;                      };  //light.getCt( iLightNumber );       
    if ( typeof result.state.alert !== undefined        ){ sArrayLightAlert[iLightNumber] = result.state.alert;                   };  //light.getAlert( iLightNumber );    
    if ( typeof result.state.colormode !== undefined    ){ sArrayLightColorMode[iLightNumber] = result.state.colormode;           };  //light.getColormode( iLightNumber );
    if ( typeof result.state.reachable !== undefined    ){ bArrayLightReachable[iLightNumber] = result.state.reachable;           };  //light.getReachable( iLightNumber );

  });
}


/** getInfo - ALL**/
//get all attributes for all lights from hue to script-variables
//###############################################################################################################################################################################
exports.getInfoAll = function(){
  //process.stdout.write('\n' + " Fetch Light Info...");
  var x = 0;
  getInfoAllDo();

  function getInfoAllDo(){
    if ( x >= iArrayLightConnected.length ){ return; }
    light.getInfo(iArrayLightConnected[x++]);
    setTimeout(getInfoAllDo, 10);
  }
}


/** setInfo **/
//sets all attributes from 1 light from script-variables to hue
//###############################################################################################################################################################################
exports.setInfo = function( iLightNumber,sValue){
  client.setLight( iLightNumber, function( err, result ){
  
    if ( err || result === undefined || result.state === undefined ){ return err;}
    
    //State: 
    if ( bArrayLightOn[iLightNumber]              !== undefined ){   client.setLightState( iLightNumber, { "on": bArrayLightOn[iLightNumber] },                          function( err, result ){ if ( err ) return err; }); };              
    if ( iArrayLightBriCur[iLightNumber]          !== undefined ){   client.setLightState( iLightNumber, { "bri": iArrayLightBriCur[iLightNumber] },                     function( err, result ){ if ( err ) return err; }); };              
    if ( iArrayLightHueCur[iLightNumber]          !== undefined ){   client.setLightState( iLightNumber, { "hue": iArrayLightHueCur[iLightNumber] },                     function( err, result ){ if ( err ) return err; }); };              
    if ( iArrayLightSatCur[iLightNumber]          !== undefined ){   client.setLightState( iLightNumber, { "sat": iArrayLightSatCur[iLightNumber] },                     function( err, result ){ if ( err ) return err; }); };              
    if ( sArrayLightEffect[iLightNumber]          !== undefined ){   client.setLightState( iLightNumber, { "effect": sArrayLightEffect[iLightNumber] },                  function( err, result ){ if ( err ) return err; }); };           
    if ( fArrayLightXyCur[iLightNumber]           !== undefined ){   client.setLightState( iLightNumber, { "xy": fArrayLightXyCur[iLightNumber] },                       function( err, result ){ if ( err ) return err; }); };      
    if ( fArrayLightXyXCur[iLightNumber]          !== undefined ){   client.setLightState( iLightNumber, { "xy[0]": fArrayLightXyXCur[iLightNumber] },                   function( err, result ){ if ( err ) return err; }); };          
    if ( fArrayLightXyYCur[iLightNumber]          !== undefined ){   client.setLightState( iLightNumber, { "xy[1]": fArrayLightXyYCur[iLightNumber] },                   function( err, result ){ if ( err ) return err; }); };          
    if ( iArrayLightCtCur[iLightNumber]           !== undefined ){   client.setLightState( iLightNumber, { "ct": iArrayLightCtCur[iLightNumber] },                       function( err, result ){ if ( err ) return err; }); };      
    if ( sArrayLightAlert[iLightNumber]           !== undefined ){   client.setLightState( iLightNumber, { "alert": sArrayLightAlert[iLightNumber] },                    function( err, result ){ if ( err ) return err; }); };         
    if ( sArrayLightColorMode[iLightNumber]       !== undefined ){   client.setLightState( iLightNumber, { "colormode": sArrayLightColorMode[iLightNumber] },            function( err, result ){ if ( err ) return err; }); };
    if ( bArrayLightReachable[iLightNumber]       !== undefined ){   client.setLightState( iLightNumber, { "reachable": bArrayLightReachable[iLightNumber] },            function( err, result ){ if ( err ) return err; }); };   
    if ( iArrayLightTransitionTime[iLightNumber]  !== undefined ){   client.setLightState( iLightNumber, { "transitiontime": iArrayLightTransitionTime[iLightNumber] },  function( err, result ){ if ( err ) return err; }); }; 
  
  });
}


/** setInfo - ALL**/
//sets all attributes for all lights from script-variables to hue
//###############################################################################################################################################################################
exports.setInfoAll = function(){
  //process.stdout.write('\n' + " Push Light Info...");
  var x = 0;
  setInfoAllDo();

  function setInfoAllDo(){
    if ( x >= iArrayLightConnected.length ){ return; }
    light.setInfo(iArrayLightConnected[x++]);
    setTimeout(setInfoAllDo, 10);
  }
}


/** getValue **/
//get attribute from a single light
//###############################################################################################################################################################################
exports.getManufacturerName = function (iLightNumber, callback ){ client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.manufacturername === undefined      ){ return err;} callback(result.manufacturername      ) } )}
exports.getProductName = function (iLightNumber, callback ){      client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.productname === undefined           ){ return err;} callback(result.productname           ) } )}
exports.getModelId = function (iLightNumber, callback ){          client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.modelid === undefined               ){ return err;} callback(result.modelid               ) } )}
exports.getName = function (iLightNumber, callback ){             client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.name === undefined                  ){ return err;} callback(result.name                  ) } )}
exports.getSwVersion = function (iLightNumber, callback ){        client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.swversion === undefined             ){ return err;} callback(result.swversion             ) } )}
exports.getType = function (iLightNumber, callback ){             client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.type === undefined                  ){ return err;} callback(result.type                  ) } )}
exports.getUniqueid = function (iLightNumber, callback ){         client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.uniqueid === undefined              ){ return err;} callback(result.uniqueid              ) } )}
exports.getOn = function (iLightNumber, callback ){               client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.on === undefined              ){ return err;} callback(result.state.on              ) } )}
exports.getBri = function (iLightNumber, callback ){              client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.bri === undefined             ){ return err;} callback(result.state.bri             ) } )}
exports.getHue = function (iLightNumber, callback ){              client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.hue === undefined             ){ return err;} callback(result.state.hue             ) } )}
exports.getSat = function (iLightNumber, callback ){              client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.sat === undefined             ){ return err;} callback(result.state.sat             ) } )}
exports.getEffect = function (iLightNumber, callback ){           client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.effect === undefined          ){ return err;} callback(result.state.effect          ) } )}
exports.getXy = function (iLightNumber, callback ){               client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.xy === undefined              ){ return err;} callback(result.state.xy              ) } )}
exports.getXyX = function (iLightNumber, callback ){              client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.xy[0] === undefined           ){ return err;} callback(result.state.xy[0]           ) } )}
exports.getXyY = function (iLightNumber, callback ){              client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.xy[1] === undefined           ){ return err;} callback(result.state.xy[1]           ) } )}
exports.getCt = function (iLightNumber, callback ){               client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.ct === undefined              ){ return err;} callback(result.state.ct              ) } )}
exports.getAlert = function (iLightNumber, callback ){            client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.alert === undefined           ){ return err;} callback(result.state.alert           ) } )}
exports.getColormode = function (iLightNumber, callback ){        client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.colormode === undefined       ){ return err;} callback(result.state.colormode       ) } )}
exports.getReachable = function (iLightNumber, callback ){        client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.reachable === undefined       ){ return err;} callback(result.state.reachable       ) } )}
exports.getTransisitonTime = function (iLightNumber, callback ){  client.get('/lights/' + iLightNumber + '/', function (err, result) { if ( err || typeof result.state.transitiontime === undefined  ){ return err;} callback(result.state.transitiontime  ) } )}


/** setValue **/
//set attribute for a single light
//###############################################################################################################################################################################
exports.setOn = function( iLightNumber,bValue){             client.setLightState( iLightNumber, { "on": bValue },                    function( err, result ){ if ( err ) return err; }); };     // true/false
exports.setOff = function( iLightNumber ){                  client.setLightState( iLightNumber, { "on": false },                     function( err, result ){ if ( err ) return err; }); };     // none                          
exports.setBri = function( iLightNumber,iValue){            client.setLightState( iLightNumber, { "bri": iValue },                   function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setBriDec = function( iLightNumber,iValue){         client.setLightState( iLightNumber, { "bri_inc": -iValue },              function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setBriInc = function( iLightNumber,iValue){         client.setLightState( iLightNumber, { "bri_inc": iValue },               function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setHue = function( iLightNumber,iValue){            client.setLightState( iLightNumber, { "hue": iValue },                   function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setHueDec = function( iLightNumber,iValue){         client.setLightState( iLightNumber, { "hue_inc": -iValue },              function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setHueInc = function( iLightNumber,iValue){         client.setLightState( iLightNumber, { "hue_inc": iValue },               function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setSat = function( iLightNumber,iValue){            client.setLightState( iLightNumber, { "sat": iValue },                   function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setSatDec = function( iLightNumber,iValue){         client.setLightState( iLightNumber, { "sat_inc": -iValue },              function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setSatInc = function( iLightNumber,iValue){         client.setLightState( iLightNumber, { "sat_inc": iValue },               function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setEffect = function( iLightNumber,sValue){         client.setLightState( iLightNumber, { "effect": sValue },                function( err, result ){ if ( err ) return err; }); };     // "none","colorloop"
exports.setXy = function( iLightNumber,fValue1,fValue2){    client.setLightState( iLightNumber, { "xy": [fValue1, fValue2] },        function( err, result ){ if ( err ) return err; }); };     // [0-1,0-1]
exports.setXyDec = function( iLightNumber,fValue){          client.setLightState( iLightNumber, { "xy_inc": [-fValue, -fValue] },    function( err, result ){ if ( err ) return err; }); };     // 0-1
exports.setXyInc = function( iLightNumber,fValue){          client.setLightState( iLightNumber, { "xy_inc": [fValue, fValue] },      function( err, result ){ if ( err ) return err; }); };     // 0-1
exports.setCt = function( iLightNumber,iValue){             client.setLightState( iLightNumber, { "ct": iValue },                    function( err, result ){ if ( err ) return err; }); };     // 0-254
exports.setAlert = function( iLightNumber,sValue){          client.setLightState( iLightNumber, { "alert": sValue },                 function( err, result ){ if ( err ) return err; }); };     // "none","select","lselect" - till alert command is taken, The light is not performing an alert effect or The light is performing one breathe cycle, or “lselect” – The light is performing breathe cycles for 15 seconds or until an "alert": "none" command is received.
exports.setAlertNone = function( iLightNumber ){            client.setLightState( iLightNumber, { "alert": `none` },                 function( err, result ){ if ( err ) return err; }); };     // none
exports.setAlertSelect = function( iLightNumber ){          client.setLightState( iLightNumber, { "alert": `select` },               function( err, result ){ if ( err ) return err; }); };     // none
exports.setAlertLSelect = function( iLightNumber ){         client.setLightState( iLightNumber, { "alert": `lselect` },              function( err, result ){ if ( err ) return err; }); };     // none
exports.setColormode = function( iLightNumber,sValue){      client.setLightState( iLightNumber, { "colormode": sValue },             function( err, result ){ if ( err ) return err; }); };     // hs, ct, 
exports.setReachable = function( iLightNumber,bValue){      client.setLightState( iLightNumber, { "reachable": bValue },             function( err, result ){ if ( err ) return err; }); };     // true/false
exports.setTransitionTime = function( iLightNumber,iValue){ client.setLightState( iLightNumber, { "transitiontime": iValue },        function( err, result ){ if ( err ) return err; }); };     // a multiple of 100 milliseconds, e.g. 4 means 400ms


/** loadValue **/
//load variables from 1 light from disk
//###############################################################################################################################################################################
exports.loadInfo = function(iLightNumber){
  //if (!fs.existsSync(pathhuelightvalues + iLightNumber + "/state"))
  var path;

  path = pathhuelightvalues + iLightNumber + "/manufacturername"    ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightManufacturerName[iLightNumber] = data; console.log("Read Light " + iLightNumber + " - /manufacturername     : " + data ); }; }); };     //  if ( sArrayLightManufacturerName[iLightNumber] !== undefined ){ sArrayLightManufacturerName[iLightNumber] = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/manufacturername" ) };
  path = pathhuelightvalues + iLightNumber + "/productname"         ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightProductname[iLightNumber]      = data; console.log("Read Light " + iLightNumber + " - /productname          : " + data ); }; }); };     //  if ( sArrayLightProductname[iLightNumber]      !== undefined ){ sArrayLightProductname[iLightNumber]      = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/productname"      ) };
  path = pathhuelightvalues + iLightNumber + "/modelid"             ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightModelid[iLightNumber]          = data; console.log("Read Light " + iLightNumber + " - /modelid              : " + data ); }; }); };     //  if ( sArrayLightModelid[iLightNumber]          !== undefined ){ sArrayLightModelid[iLightNumber]          = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/modelid"          ) };
  path = pathhuelightvalues + iLightNumber + "/name"                ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightName[iLightNumber]             = data; console.log("Read Light " + iLightNumber + " - /name                 : " + data ); }; }); };     //  if ( sArrayLightName[iLightNumber]             !== undefined ){ sArrayLightName[iLightNumber]             = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/name"             ) };
  path = pathhuelightvalues + iLightNumber + "/swversion"           ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightSwversion[iLightNumber]        = data; console.log("Read Light " + iLightNumber + " - /swversion            : " + data ); }; }); };     //  if ( sArrayLightSwversion[iLightNumber]        !== undefined ){ sArrayLightSwversion[iLightNumber]        = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/swversion"        ) };
  path = pathhuelightvalues + iLightNumber + "/type"                ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightType[iLightNumber]             = data; console.log("Read Light " + iLightNumber + " - /type                 : " + data ); }; }); };     //  if ( sArrayLightType[iLightNumber]             !== undefined ){ sArrayLightType[iLightNumber]             = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/type"             ) };
  path = pathhuelightvalues + iLightNumber + "/uniqueid"            ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightUniqueid[iLightNumber]         = data; console.log("Read Light " + iLightNumber + " - /uniqueid             : " + data ); }; }); };     //  if ( sArrayLightUniqueid[iLightNumber]         !== undefined ){ sArrayLightUniqueid[iLightNumber]         = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/uniqueid"         ) };
  path = pathhuelightvalues + iLightNumber + "/state/on"            ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArrayLightOn[iLightNumber]               = data; console.log("Read Light " + iLightNumber + " - /state/on             : " + data ); }; }); };     //  if ( bArrayLightOn[iLightNumber]               !== undefined ){ bArrayLightOn[iLightNumber]               = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/on"         ) };
  path = pathhuelightvalues + iLightNumber + "/state/bri"           ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArrayLightBriCur[iLightNumber]           = data; console.log("Read Light " + iLightNumber + " - /state/bri            : " + data ); }; }); };     //  if ( iArrayLightBriCur[iLightNumber]           !== undefined ){ iArrayLightBriCur[iLightNumber]           = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/bri"        ) };
  path = pathhuelightvalues + iLightNumber + "/state/hue"           ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArrayLightHueCur[iLightNumber]           = data; console.log("Read Light " + iLightNumber + " - /state/hue            : " + data ); }; }); };     //  if ( iArrayLightHueCur[iLightNumber]           !== undefined ){ iArrayLightHueCur[iLightNumber]           = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/hue"        ) };
  path = pathhuelightvalues + iLightNumber + "/state/sat"           ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArrayLightSatCur[iLightNumber]           = data; console.log("Read Light " + iLightNumber + " - /state/sat            : " + data ); }; }); };     //  if ( iArrayLightSatCur[iLightNumber]           !== undefined ){ iArrayLightSatCur[iLightNumber]           = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/sat"        ) };
  path = pathhuelightvalues + iLightNumber + "/state/effect"        ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightEffect[iLightNumber]           = data; console.log("Read Light " + iLightNumber + " - /state/effect         : " + data ); }; }); };     //  if ( sArrayLightEffect[iLightNumber]           !== undefined ){ sArrayLightEffect[iLightNumber]           = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/effect"     ) };
  path = pathhuelightvalues + iLightNumber + "/state/xy"            ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ fArrayLightXyCur[iLightNumber]            = data; console.log("Read Light " + iLightNumber + " - /state/xy             : " + data ); }; }); };     //  if ( fArrayLightXyCur[iLightNumber]            !== undefined ){ fArrayLightXyCur[iLightNumber]            = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/xy/xy"      ) };
  path = pathhuelightvalues + iLightNumber + "/state/x"             ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ fArrayLightXyXCur[iLightNumber]           = data; console.log("Read Light " + iLightNumber + " - /state/x              : " + data ); }; }); };     //  if ( fArrayLightXyXCur[iLightNumber]           !== undefined ){ fArrayLightXyXCur[iLightNumber]           = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/xy/x"       ) };
  path = pathhuelightvalues + iLightNumber + "/state/y"             ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ fArrayLightXyYCur[iLightNumber]           = data; console.log("Read Light " + iLightNumber + " - /state/y              : " + data ); }; }); };     //  if ( fArrayLightXyYCur[iLightNumber]           !== undefined ){ fArrayLightXyYCur[iLightNumber]           = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/xy/y"       ) };
  path = pathhuelightvalues + iLightNumber + "/state/ct"            ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArrayLightCtCur[iLightNumber]            = data; console.log("Read Light " + iLightNumber + " - /state/ct             : " + data ); }; }); };     //  if ( iArrayLightCtCur[iLightNumber]            !== undefined ){ iArrayLightCtCur[iLightNumber]            = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/ct"         ) };
  path = pathhuelightvalues + iLightNumber + "/state/alert"         ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightAlert[iLightNumber]            = data; console.log("Read Light " + iLightNumber + " - /state/alert          : " + data ); }; }); };     //  if ( sArrayLightAlert[iLightNumber]            !== undefined ){ sArrayLightAlert[iLightNumber]            = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/alert"      ) };
  path = pathhuelightvalues + iLightNumber + "/state/colormode"     ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightColorMode[iLightNumber]        = data; console.log("Read Light " + iLightNumber + " - /state/colormode      : " + data ); }; }); };     //  if ( sArrayLightColorMode[iLightNumber]        !== undefined ){ sArrayLightColorMode[iLightNumber]        = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/colormode"  ) };
  path = pathhuelightvalues + iLightNumber + "/state/reachable"     ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArrayLightReachable[iLightNumber]        = data; console.log("Read Light " + iLightNumber + " - /state/reachable      : " + data ); }; }); };     //  if ( bArrayLightReachable[iLightNumber]        !== undefined ){ bArrayLightReachable[iLightNumber]        = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/reachable"  ) };
  path = pathhuelightvalues + iLightNumber + "/state/transitiontime"; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArrayLightTransitionTime[iLightNumber]   = data; console.log("Read Light " + iLightNumber + " - /state/transitiontime : " + data ); }; }); };     //  if ( bArrayLightReachable[iLightNumber]        !== undefined ){ bArrayLightReachable[iLightNumber]        = exec("/bin/cat " + pathhuelightvalues + iLightNumber + "/state/reachable"  ) };
  
};              


/** loadInfo All**/
//loads all variables from all lights from disk
//###############################################################################################################################################################################
exports.loadInfoAll = function(){
  //process.stdout.write('\n' + " Push Light Info...");
  var x = 0;
  loadInfoAllDo();

  function loadInfoAllDo(){
    if ( x >= iArrayLightConnected.length ){ return; }
    light.loadInfo(iArrayLightConnected[x++]);
    setTimeout(loadInfoAllDo, 10);
  }
}


/** saveValue **/
//saves all variables from 1 light to disk
// Example: light.getManufacturerName(1, console.log)
//###############################################################################################################################################################################
exports.saveInfo = function(iLightNumber){

  if (!fs.existsSync(pathhuelightvalues + iLightNumber + "/state")) { exec("/bin/mkdir -p " + pathhuelightvalues + iLightNumber + "/state" ); };
                                                                                                                                                                                                                                                                                                                                                                                                  //depreciated
  if ( sArrayLightManufacturerName[iLightNumber] !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/manufacturername",       sArrayLightManufacturerName[iLightNumber] , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /manufacturername     : " + sArrayLightManufacturerName[iLightNumber]        ); }); };              //if ( sArrayLightManufacturerName[iLightNumber]     !== undefined ){ exec( "/bin/echo " + sArrayLightManufacturerName[iLightNumber] + " > " + pathhuelightvalues + iLightNumber + "/manufacturername" ); };    
  if ( sArrayLightProductname[iLightNumber]      !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/productname",            sArrayLightProductname[iLightNumber]      , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /productname          : " + sArrayLightProductname[iLightNumber]             ); }); };              //if ( sArrayLightProductname[iLightNumber]          !== undefined ){ exec( "/bin/echo " + sArrayLightProductname[iLightNumber]      + " > " + pathhuelightvalues + iLightNumber + "/productname" ); };         
  if ( sArrayLightModelid[iLightNumber]          !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/modelid",                sArrayLightModelid[iLightNumber]          , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /modelid              : " + sArrayLightModelid[iLightNumber]                 ); }); };              //if ( sArrayLightModelid[iLightNumber]              !== undefined ){ exec( "/bin/echo " + sArrayLightModelid[iLightNumber]          + " > " + pathhuelightvalues + iLightNumber + "/modelid" ); };             
  if ( sArrayLightName[iLightNumber]             !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/name",                   sArrayLightName[iLightNumber]             , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /name                 : " + sArrayLightName[iLightNumber]                    ); }); };              //if ( sArrayLightName[iLightNumber]                 !== undefined ){ exec( "/bin/echo " + sArrayLightName[iLightNumber]             + " > " + pathhuelightvalues + iLightNumber + "/name" ); };                
  if ( sArrayLightSwversion[iLightNumber]        !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/swversion",              sArrayLightSwversion[iLightNumber]        , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /swversion            : " + sArrayLightSwversion[iLightNumber]               ); }); };              //if ( sArrayLightSwversion[iLightNumber]            !== undefined ){ exec( "/bin/echo " + sArrayLightSwversion[iLightNumber]        + " > " + pathhuelightvalues + iLightNumber + "/swversion" ); };           
  if ( sArrayLightType[iLightNumber]             !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/type",                   sArrayLightType[iLightNumber]             , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /type                 : " + sArrayLightType[iLightNumber]                    ); }); };              //if ( sArrayLightType[iLightNumber]                 !== undefined ){ exec( "/bin/echo " + sArrayLightType[iLightNumber]             + " > " + pathhuelightvalues + iLightNumber + "/type" ); };                
  if ( sArrayLightUniqueid[iLightNumber]         !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/uniqueid",               sArrayLightUniqueid[iLightNumber]         , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /uniqueid             : " + sArrayLightUniqueid[iLightNumber]                ); }); };              //if ( sArrayLightUniqueid[iLightNumber]             !== undefined ){ exec( "/bin/echo " + sArrayLightUniqueid[iLightNumber]         + " > " + pathhuelightvalues + iLightNumber + "/uniqueid" ); };            
  if ( bArrayLightOn[iLightNumber]               !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/on",               bArrayLightOn[iLightNumber]               , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/on             : " + bArrayLightOn[iLightNumber]                      ); }); };              //if ( bArrayLightOn[iLightNumber]                   !== undefined ){ exec( "/bin/echo " + bArrayLightOn[iLightNumber]               + " > " + pathhuelightvalues + iLightNumber + "/state/on" ); };            
  if ( iArrayLightBriCur[iLightNumber]           !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/bri",              iArrayLightBriCur[iLightNumber]           , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/bri            : " + iArrayLightBriCur[iLightNumber]                  ); }); };              //if ( iArrayLightBriCur[iLightNumber]               !== undefined ){ exec( "/bin/echo " + iArrayLightBriCur[iLightNumber]           + " > " + pathhuelightvalues + iLightNumber + "/state/bri" ); };           
  if ( iArrayLightHueCur[iLightNumber]           !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/hue",              iArrayLightHueCur[iLightNumber]           , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/hue            : " + iArrayLightHueCur[iLightNumber]                  ); }); };              //if ( iArrayLightHueCur[iLightNumber]               !== undefined ){ exec( "/bin/echo " + iArrayLightHueCur[iLightNumber]           + " > " + pathhuelightvalues + iLightNumber + "/state/hue" ); };           
  if ( iArrayLightSatCur[iLightNumber]           !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/sat",              iArrayLightSatCur[iLightNumber]           , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/sat            : " + iArrayLightSatCur[iLightNumber]                  ); }); };              //if ( iArrayLightSatCur[iLightNumber]               !== undefined ){ exec( "/bin/echo " + iArrayLightSatCur[iLightNumber]           + " > " + pathhuelightvalues + iLightNumber + "/state/sat" ); };           
  if ( sArrayLightEffect[iLightNumber]           !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/effect",           sArrayLightEffect[iLightNumber]           , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/effect         : " + sArrayLightEffect[iLightNumber]                  ); }); };              //if ( sArrayLightEffect[iLightNumber]               !== undefined ){ exec( "/bin/echo " + sArrayLightEffect[iLightNumber]           + " > " + pathhuelightvalues + iLightNumber + "/state/effect" ); };        
  if ( fArrayLightXyCur[iLightNumber]            !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/xy",               fArrayLightXyCur[iLightNumber]            , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/xy             : " + fArrayLightXyCur[iLightNumber]                   ); }); };              //if ( fArrayLightXyCur[iLightNumber]                !== undefined ){ exec( "/bin/echo " + fArrayLightXyCur[iLightNumber]            + " > " + pathhuelightvalues + iLightNumber + "/state/xy/xy" ); };         
  if ( fArrayLightXyXCur[iLightNumber]           !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/x",                fArrayLightXyXCur[iLightNumber]           , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/x              : " + fArrayLightXyXCur[iLightNumber]                  ); }); };              //if ( fArrayLightXyXCur[iLightNumber]               !== undefined ){ exec( "/bin/echo " + fArrayLightXyXCur[iLightNumber]           + " > " + pathhuelightvalues + iLightNumber + "/state/xy/x" ); };          
  if ( fArrayLightXyYCur[iLightNumber]           !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/y",                fArrayLightXyYCur[iLightNumber]           , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/y              : " + fArrayLightXyYCur[iLightNumber]                  ); }); };              //if ( fArrayLightXyYCur[iLightNumber]               !== undefined ){ exec( "/bin/echo " + fArrayLightXyYCur[iLightNumber]           + " > " + pathhuelightvalues + iLightNumber + "/state/xy/y" ); };          
  if ( iArrayLightCtCur[iLightNumber]            !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/ct",               iArrayLightCtCur[iLightNumber]            , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/ct             : " + iArrayLightCtCur[iLightNumber]                   ); }); };              //if ( iArrayLightCtCur[iLightNumber]                !== undefined ){ exec( "/bin/echo " + iArrayLightCtCur[iLightNumber]            + " > " + pathhuelightvalues + iLightNumber + "/state/ct" ); };            
  if ( sArrayLightAlert[iLightNumber]            !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/alert",            sArrayLightAlert[iLightNumber]            , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/alert          : " + sArrayLightAlert[iLightNumber]                   ); }); };              //if ( sArrayLightAlert[iLightNumber]                !== undefined ){ exec( "/bin/echo " + sArrayLightAlert[iLightNumber]            + " > " + pathhuelightvalues + iLightNumber + "/state/alert" ); };         
  if ( sArrayLightColorMode[iLightNumber]        !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/colormode",        sArrayLightColorMode[iLightNumber]        , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/colormode      : " + sArrayLightColorMode[iLightNumber]               ); }); };              //if ( sArrayLightColorMode[iLightNumber]            !== undefined ){ exec( "/bin/echo " + sArrayLightColorMode[iLightNumber]        + " > " + pathhuelightvalues + iLightNumber + "/state/colormode" ); };     
  if ( bArrayLightReachable[iLightNumber]        !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/reachable",        bArrayLightReachable[iLightNumber]        , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/reachable      : " + bArrayLightReachable[iLightNumber]               ); }); };              //if ( bArrayLightReachable[iLightNumber]            !== undefined ){ exec( "/bin/echo " + bArrayLightReachable[iLightNumber]        + " > " + pathhuelightvalues + iLightNumber + "/state/reachable" ); };     
  if ( iArrayLightTransitionTime[iLightNumber]   !== undefined ){ fs.writeFile( pathhuelightvalues + iLightNumber + "/state/transitiontime",   iArrayLightTransitionTime[iLightNumber]   , function(err) { if(err) { return console.log(err); } console.log("Saved Light " + iLightNumber + " - /state/transitiontime : " + iArrayLightTransitionTime[iLightNumber]          ); }); };              //if ( iArrayLightTransitionTime[iLightNumber]       !== undefined ){ exec( "/bin/echo " + iArrayLightTransitionTime[iLightNumber]   + " > " + pathhuelightvalues + iLightNumber + "/state/transitiontime" ); };

};

/** setInfo - ALL**/
//saves all variables from all lights to disk
exports.saveInfoAll = function(){
  //process.stdout.write('\n' + " Fetch Light Info...");
  var x = 0;
  saveInfoAllDo();

  function saveInfoAllDo(){
    if ( x >= iArrayLightConnected.length ){ return; }
    light.saveInfo(iArrayLightConnected[x++]);
    setTimeout(saveInfoAllDo, 10);
  }
}

