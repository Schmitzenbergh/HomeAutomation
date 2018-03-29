#!/usr/bin/env node

debug = false;

//# Situation:                # Function:
//###############################################################################################################################################################################
//# Hue To Scriptvar          # getInfo, getInfoAll                 
//# Scriptvar to Hue          # setInfo, setInfoAll                 
//# From Hue                  # get[Variable]                       
//# To Hue                    # set[Variable]                       
//# From disk                 # loadInfo, loadInfoALL               
//# To disk                   # saveInfo, saveInfoAll               
//# From/To script            # not needed                          


/** getInfo **/
//get all attributes for 1 sensor from hue to script-variables
//Example: sensor.getInfo(iSensorNumber, Value)
//###############################################################################################################################################################################
exports.getInfo = function( iSensorNumber,sValue){
  client.getSensor( iSensorNumber, function( err, result ){ 

    if ( err || result === undefined || result.state === undefined ){ return err;}
    
    //General:
    if ( typeof result.manufacturername !== undefined      ){ sArraySensorManufacturerName[iSensorNumber] = result.manufacturername;    };  
    if ( typeof result.modelid !== undefined               ){ sArraySensorModelId[iSensorNumber] = result.modelid;                      };  
    if ( typeof result.name !== undefined                  ){ sArraySensorName[iSensorNumber] = result.name;                            };  
    if ( typeof result.swversion !== undefined             ){ sArraySensorSwVersion[iSensorNumber] = result.swversion;                  };  
    if ( typeof result.type !== undefined                  ){ sArraySensorType[iSensorNumber] = result.type;                            };  
    if ( typeof result.uniqueid !== undefined              ){ sArraySensorUniqueId[iSensorNumber] = result.uniqueid;                    };  
                                                                                                                                            
    //State:
    if ( typeof result.state.lightlevel !== undefined      ){ iArraySensorLightLevel[iSensorNumber] = result.state.lightlevel;          };
    if ( typeof result.state.dark !== undefined            ){ bArraySensorDark[iSensorNumber] = result.state.dark;                      };
    if ( typeof result.state.daylight !== undefined        ){ bArraySensorDaylight[iSensorNumber] = result.state.daylight;              };
    if ( typeof result.state.status !== undefined          ){ iArraySensorStatus[iSensorNumber] = result.state.status;                  };
    if ( typeof result.state.lastupdated !== undefined     ){ sArraySensorLastupdated[iSensorNumber] = result.state.lastupdated;        };
    if ( typeof result.state.presence !== undefined        ){ bArraySensorPresence[iSensorNumber] = result.state.presence;              };
    if ( typeof result.state.temperature !== undefined     ){ iArraySensorTemperature[iSensorNumber] = result.state.temperature;        };

    //Config:
    if ( typeof result.config.on !== undefined             ){ bArraySensorOn[iSensorNumber] = result.config.on;                         };
    if ( typeof result.config.battery  !== undefined       ){ iArraySensorBattery[iSensorNumber] = result.config.battery;               };
    if ( typeof result.config.configured !== undefined     ){ bArraySensorConfigured[iSensorNumber] = result.config.configured;         };
    if ( typeof result.config.reachable !== undefined      ){ bArraySensorReachable[iSensorNumber] = result.config.reachable;           };
    if ( typeof result.config.alert !== undefined          ){ sArraySensorAlert[iSensorNumber] = result.config.alert;                   };
    if ( typeof result.config.tholddark !== undefined      ){ iArraySensorTholdDark[iSensorNumber] = result.config.tholddark;           };
    if ( typeof result.config.tholdoffset !== undefined    ){ iArraySensorTholdOffset[iSensorNumber] = result.config.tholdoffset;       };
    if ( typeof result.config.ledindication !== undefined  ){ bArraySensorLedindication[iSensorNumber] = result.config.ledindication;   };
    if ( typeof result.config.usertest !== undefined       ){ bArraySensorUsertest[iSensorNumber] = result.config.usertest;             };
    if ( typeof result.config.sensitivity !== undefined    ){ iArraySensorSensitivity[iSensorNumber] = result.config.sensitivity;       };
    if ( typeof result.config.sensitivitymax !== undefined ){ iArraySensorSensitivityMax[iSensorNumber] = result.config.sensitivitymax; };
    if ( typeof result.config.sunsetoffset !== undefined   ){ iArraySensorSunsetoffset[iSensorNumber] = result.config.sunsetoffset;     };
    if ( typeof result.config.sunriseoffset !== undefined  ){ iArraySensorSunriseoffset[iSensorNumber] = result.config.sunriseoffset;   };
    if ( typeof result.config.pending !== undefined        ){ sArraySensorPending[iSensorNumber] = result.config.pending;               };

    //Recycle:
    if ( typeof result.recycle !== undefined               ){ bArraySensorRecycle[iSensorNumber] = result.recycle;                      };
  });
};


/** getInfo - ALL**/
//get all attributes for all sensors from hue to script-variables
// Example: sensor.getInfoAll()
//###############################################################################################################################################################################
exports.getInfoAll = function(){
  //process.stdout.write('\n' + " Fetch Sensor Info...");
  var x = 0;
  getInfoAllDo();

  function getInfoAllDo(){
    if ( x >= iArraySensorConnected.length ){ return; }
    sensor.getInfo(iArraySensorConnected[x++]);
    setTimeout(getInfoAllDo, 10);
  }
}


/** setInfo **/
//sets all attributes from 1 srnsor from script-variables to hue
// Example: sensor.setInfo( iSensorNumber,sValue )
//###############################################################################################################################################################################
exports.setInfo = function( iSensorNumber,sValue ){
  client.setLight( iSensorNumber, function( err, result ){
  
    if ( err || result === undefined || result.state === undefined ){ return err;}
    
    //State: 
    if ( bArrayLightOn[iSensorNumber]              !== undefined ){   client.setLightState( iSensorNumber, { "on": bArrayLightOn[iSensorNumber] },                          function( err, result ){ if ( err ) return err; }); };              
    if ( iArrayLightBriCur[iSensorNumber]          !== undefined ){   client.setLightState( iSensorNumber, { "bri": iArrayLightBriCur[iSensorNumber] },                     function( err, result ){ if ( err ) return err; }); };              
    if ( iArrayLightHueCur[iSensorNumber]          !== undefined ){   client.setLightState( iSensorNumber, { "hue": iArrayLightHueCur[iSensorNumber] },                     function( err, result ){ if ( err ) return err; }); };              
    if ( iArrayLightSatCur[iSensorNumber]          !== undefined ){   client.setLightState( iSensorNumber, { "sat": iArrayLightSatCur[iSensorNumber] },                     function( err, result ){ if ( err ) return err; }); };              
    if ( sArrayLightEffect[iSensorNumber]          !== undefined ){   client.setLightState( iSensorNumber, { "effect": sArrayLightEffect[iSensorNumber] },                  function( err, result ){ if ( err ) return err; }); };           
    if ( fArrayLightXyCur[iSensorNumber]           !== undefined ){   client.setLightState( iSensorNumber, { "xy": fArrayLightXyCur[iSensorNumber] },                       function( err, result ){ if ( err ) return err; }); };      
    if ( fArrayLightXyXCur[iSensorNumber]          !== undefined ){   client.setLightState( iSensorNumber, { "xy[0]": fArrayLightXyXCur[iSensorNumber] },                   function( err, result ){ if ( err ) return err; }); };          
    if ( fArrayLightXyYCur[iSensorNumber]          !== undefined ){   client.setLightState( iSensorNumber, { "xy[1]": fArrayLightXyYCur[iSensorNumber] },                   function( err, result ){ if ( err ) return err; }); };          
    if ( iArrayLightCtCur[iSensorNumber]           !== undefined ){   client.setLightState( iSensorNumber, { "ct": iArrayLightCtCur[iSensorNumber] },                       function( err, result ){ if ( err ) return err; }); };      
    if ( sArrayLightAlert[iSensorNumber]           !== undefined ){   client.setLightState( iSensorNumber, { "alert": sArrayLightAlert[iSensorNumber] },                    function( err, result ){ if ( err ) return err; }); };         
    if ( sArrayLightColorMode[iSensorNumber]       !== undefined ){   client.setLightState( iSensorNumber, { "colormode": sArrayLightColorMode[iSensorNumber] },            function( err, result ){ if ( err ) return err; }); };
    if ( bArrayLightReachable[iSensorNumber]       !== undefined ){   client.setLightState( iSensorNumber, { "reachable": bArrayLightReachable[iSensorNumber] },            function( err, result ){ if ( err ) return err; }); };   
    if ( iArrayLightTransitionTime[iSensorNumber]  !== undefined ){   client.setLightState( iSensorNumber, { "transitiontime": iArrayLightTransitionTime[iSensorNumber] },  function( err, result ){ if ( err ) return err; }); }; 
  
  });
}


/** setInfo **/
//sets all attributes from 1 sensor from script-variables to hue
//###############################################################################################################################################################################
exports.setInfo = function( iSensorNumber ){
  var result;
  // parameterinfo-state   : "buttonevent, dark, daylight, lastupdated, lightlevel, presence, temperature" are not modifiable, only "status" is modifiable
  // parameterinfo-config  : "configured, reachable, sensitivitymax" are not available, further "on, sunriseoffset, sunsetoffset, battery, alert, ledindication, usertest, pending, sensitivity, tholddark, tholdoffset" is modifiable
  // client.changeSensorConfig( iSensorNumber, {}, function( err, result ){ if ( err) throw err; console.log(result); });
  //  client.changeSensorState( iSensorNumber, {}, function( err, result ){ if ( err) throw err; console.log(result); });
  //result = false; switch (iSensorNumber) { case 1:; result=true;default:if (!result) break; COMMAND; };
  
  console.log("Start Test");
  
  //                                                                                                                                           if ( sArraySensorName[iSensorNumber] !== undefined ){                                                                    "name": sArraySensorName[iSensorNumber]                            }, function( err, result ){ if ( err) throw err; console.log(result); }); };         //Read-Only            //  "name": sArraySensorName[iSensorNumber]                                                                                                                          
  //                                                                                                                                           if ( sArraySensorType[iSensorNumber] !== undefined ){                                                                    "type": sArraySensorType[iSensorNumber]                            }, function( err, result ){ if ( err) throw err; console.log(result); }); };         //Read-Only            //  "type": sArraySensorType[iSensorNumber]                                                                                                                          
  //                                                                                                                                           if ( sArraySensorModelId[iSensorNumber] !== undefined ){                                                                 "modelid": sArraySensorModelId[iSensorNumber]                      }, function( err, result ){ if ( err) throw err; console.log(result); }); };         //Read-Only            //  "modelid": sArraySensorModelId[iSensorNumber]                                                                                                                       
  //                                                                                                                                           if ( sArraySensorManufacturerName[iSensorNumber] !== undefined ){                                                        "manufacturername": sArraySensorManufacturerName[iSensorNumber]    }, function( err, result ){ if ( err) throw err; console.log(result); }); };         //Read-Only            //  "manufacturername": sArraySensorManufacturerName[iSensorNumber]                                                                                                              
  //                                                                                                                                           if ( sArraySensorSwVersion[iSensorNumber] !== undefined ){                                                               "swversion": sArraySensorSwVersion[iSensorNumber]                  }, function( err, result ){ if ( err) throw err; console.log(result); }); };         //Read-Only            //  "swversion": sArraySensorSwVersion[iSensorNumber]                                                                                                                     
  //                                                                                                                                           if ( sArraySensorUniqueId[iSensorNumber] !== undefined ){                                                                "uniqueid": sArraySensorUniqueId[iSensorNumber]                    }, function( err, result ){ if ( err) throw err; console.log(result); }); };         //Read-Only            //  "uniqueid": sArraySensorUniqueId[iSensorNumber]                                                                                                               
  //result = false; switch (iSensorNumber) { case 2:;case 9:;case 10:;case 11:; result=true;default:if (!result) break;                        if ( bArraySensorRecycle[iSensorNumber] !== undefined ){                                                                 "recycle": bArraySensorRecycle[iSensorNumber]                      }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only            //  "recycle": bArraySensorRecycle[iSensorNumber]                                                                                                                 
  //result = false; switch (iSensorNumber) { case 5:; result=true;default:if (!result) break;                                                  if ( iArraySensorButtonEvent[iSensorNumber] !== undefined ){                 client.changeSensorConfig( iSensorNumber, { "buttonevent": iArraySensorButtonEvent[iSensorNumber]              }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only Config     //  "buttonevent": iArraySensorButtonEvent[iSensorNumber]                                                                
  //result = false; switch (iSensorNumber) { case 8:; result=true;default:if (!result) break;                                                  if ( iArraySensorLightLevel[iSensorNumber] !== undefined ){                  client.changeSensorConfig( iSensorNumber, { "lightlevel": iArraySensorLightLevel[iSensorNumber]                }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only Config     //  "lightlevel": iArraySensorLightLevel[iSensorNumber]                                                                   
  //result = false; switch (iSensorNumber) { case 8:; result=true;default:if (!result) break;                                                  if ( bArraySensorDark[iSensorNumber] !== undefined ){                        client.changeSensorConfig( iSensorNumber, { "dark": bArraySensorDark[iSensorNumber]                            }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only Config     //  "dark": bArraySensorDark[iSensorNumber]                                                                    
  //result = false; switch (iSensorNumber) { case 8:; result=true;default:if (!result) break;                                                  if ( bArraySensorDaylight[iSensorNumber] !== undefined ){                    client.changeSensorConfig( iSensorNumber, { "daylight": bArraySensorDaylight[iSensorNumber]                    }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only Config     //  "daylight": bArraySensorDaylight[iSensorNumber]                                                                    
  //                                                                                                                                           if ( sArraySensorLastupdated[iSensorNumber] !== undefined ){                 client.changeSensorConfig( iSensorNumber, { "lastupdated": sArraySensorLastupdated[iSensorNumber]              }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only Config     //  "lastupdated": sArraySensorLastupdated[iSensorNumber]                                                               
  //result = false; switch (iSensorNumber) {  case 7:;case 10:; case 11:; result=true;default:if (!result) break;                              if ( bArraySensorPresence[iSensorNumber] !== undefined ){                    client.changeSensorConfig( iSensorNumber, { "presence": bArraySensorPresence[iSensorNumber]                    }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only Config     //  "presence": bArraySensorPresence[iSensorNumber]                                                               
  //result = false; switch (iSensorNumber) { case 6:; result=true;default:if (!result) break;                                                  if ( iArraySensorTemperature[iSensorNumber] !== undefined ){                 client.changeSensorConfig( iSensorNumber, { "temperature": iArraySensorTemperature[iSensorNumber]              }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only Config     //  "temperature": iArraySensorTemperature[iSensorNumber]                                                               
                                                                                                                                               if ( bArraySensorOn[iSensorNumber] !== undefined ){                          client.changeSensorState(  iSensorNumber, { "on": bArraySensorOn[iSensorNumber]                                }, function( err, result ){ if ( err) throw err; console.log(result); }); ;}         //Enabled State        //  "on": bArraySensorOn[iSensorNumber]                                                                 
  result = false; switch (iSensorNumber) { case 2:;case 6:;case 7:;case 8:;result=true;default:if (!result) break;                             if ( iArraySensorBattery[iSensorNumber] !== undefined ){                     client.changeSensorConfig( iSensorNumber, { "battery": iArraySensorBattery[iSensorNumber]                      }, function( err, result ){ if ( err) throw err; console.log(result); }); ;} };      //Enabled State        //  "battery": iArraySensorBattery[iSensorNumber]                                                                
  //result = false; switch (iSensorNumber) { case 1:;result=true;default:if (!result) break;                                                   if ( bArraySensorConfigured[iSensorNumber] !== undefined ){                  client.changeSensorState(  iSensorNumber, { "configured": bArraySensorConfigured[iSensorNumber]                }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only state      //  "configured": bArraySensorConfigured[iSensorNumber]                                                              
  //result = false; switch (iSensorNumber) { case 2:;case 6:;case 7:;case 8:;case 9:;case 10:;case 11:;result=true;default:if (!result) break; if ( bArraySensorReachable[iSensorNumber] !== undefined ){                   client.changeSensorState(  iSensorNumber, { "reachable": bArraySensorReachable[iSensorNumber]                  }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only state      //  "reachable": bArraySensorReachable[iSensorNumber]                                                                     
  result = false; switch (iSensorNumber) { case 6:;case 7:;case 8:;result=true;default:if (!result) break;                                     if ( sArraySensorAlert[iSensorNumber] !== undefined ){                       client.changeSensorConfig( iSensorNumber, { "alert": sArraySensorAlert[iSensorNumber]                          }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "alert": sArraySensorAlert[iSensorNumber]                                                                   
  result = false; switch (iSensorNumber) { case 8:;result=true;default:if (!result) break;                                                     if ( iArraySensorTholdDark[iSensorNumber] !== undefined ){                   client.changeSensorConfig( iSensorNumber, { "tholddark": iArraySensorTholdDark[iSensorNumber]                  }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "tholddark": iArraySensorTholdDark[iSensorNumber]                                                                 
  result = false; switch (iSensorNumber) { case 8:;result=true;default:if (!result) break;                                                     if ( iArraySensorTholdOffset[iSensorNumber] !== undefined ){                 client.changeSensorConfig( iSensorNumber, { "tholdoffset": iArraySensorTholdOffset[iSensorNumber]              }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "tholdoffset": iArraySensorTholdOffset[iSensorNumber]                                                              
  result = false; switch (iSensorNumber) { case 2:;case 9:;result=true;default:if (!result) break;                                             if ( iArraySensorStatus[iSensorNumber] !== undefined ){                      client.changeSensorState(  iSensorNumber, { "status": iArraySensorStatus[iSensorNumber]                        }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "status": iArraySensorStatus[iSensorNumber]                                                              
  result = false; switch (iSensorNumber) { case 6:;case 7:;case 8:;result=true;default:if (!result) break;                                     if ( bArraySensorLedindication[iSensorNumber] !== undefined ){               client.changeSensorConfig( iSensorNumber, { "ledindication": bArraySensorLedindication[iSensorNumber]          }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "ledindication": bArraySensorLedindication[iSensorNumber]                                                              
  result = false; switch (iSensorNumber) { case 6:;case 7:;case 8:;result=true;default:if (!result) break;                                     if ( bArraySensorUsertest[iSensorNumber] !== undefined ){                    client.changeSensorConfig( iSensorNumber, { "usertest": bArraySensorUsertest[iSensorNumber]                    }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "usertest": bArraySensorUsertest[iSensorNumber]                                                              
  result = false; switch (iSensorNumber) { case 7:;result=true;default:if (!result) break;                                                     if ( iArraySensorSensitivity[iSensorNumber] !== undefined ){                 client.changeSensorConfig( iSensorNumber, { "sensitivity": iArraySensorSensitivity[iSensorNumber]              }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "sensitivity": iArraySensorSensitivity[iSensorNumber]                                                              
  //result = false; switch (iSensorNumber) { case 7:;result=true;default:if (!result) break;                                                   if ( iArraySensorSensitivityMax[iSensorNumber]!== undefined ){               client.changeSensorConfig( iSensorNumber, { "sensitivitymax": iArraySensorSensitivityMax[iSensorNumber]        }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Read-Only state      //  "sensitivitymax": iArraySensorSensitivityMax[iSensorNumber]                                                              
  result = false; switch (iSensorNumber) { case 1:;result=true;default:if (!result) break;                                                     if ( iArraySensorSunriseoffset[iSensorNumber] !== undefined ){               client.changeSensorConfig( iSensorNumber, { "sunriseoffset": iArraySensorSunriseoffset[iSensorNumber]          }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "sunriseoffset": iArraySensorSunriseoffset[iSensorNumber]                                                              
  result = false; switch (iSensorNumber) { case 1:;result=true;default:if (!result) break;                                                     if ( iArraySensorSunsetoffset[iSensorNumber] !== undefined ) {               client.changeSensorConfig( iSensorNumber, { "sunsetoffset": iArraySensorSunsetoffset[iSensorNumber]            }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "sunsetoffset": iArraySensorSunsetoffset[iSensorNumber]                                                              
  result = false; switch (iSensorNumber) { case 6:;case 7:;case 8:;result=true;default:if (!result) break;                                     if ( sArraySensorPending[iSensorNumber] !== undefined ){                     client.changeSensorConfig( iSensorNumber, { "pending": sArraySensorPending[iSensorNumber]                      }, function( err, result ){ if ( err) throw err; console.log(result); }); }; };      //Enabled State        //  "pending": sArraySensorPending[iSensorNumber]                                                              
};


/** setInfo - ALL**/
//sets all attributes for all sensors from script-variables to hue
// Example: sensor.setInfoAll()
//###############################################################################################################################################################################
exports.setInfoAll = function(){
  //process.stdout.write('\n' + " Push Sensor Info...");
  var x = 0;
  setInfoAllDo();

  function setInfoAllDo(){
    if ( x >= iArraySensorConnected.length ){ return; }
    sensor.setInfo(iArraySensorConnected[x++]);
    setTimeout(setInfoAllDo, 10);
  }
}


/** getValue **/
//get attribute from a single sensor
// Example: sensor.getManufacturerName(1, console.log)
//          sensor.getManufacturerName(1, output)
//###############################################################################################################################################################################
exports.getManufacturerName = function (iSensorNumber, callback ){ client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.manufacturername      === undefined ){ return err;} callback(result.manufacturername     ) } )}
exports.getProductName = function (iSensorNumber, callback ){      client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.productname           === undefined ){ return err;} callback(result.productname          ) } )}
exports.getModelId = function (iSensorNumber, callback ){          client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.modelid               === undefined ){ return err;} callback(result.modelid              ) } )}
exports.getName = function (iSensorNumber, callback ){             client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.name                  === undefined ){ return err;} callback(result.name                 ) } )}
exports.getSwVersion = function (iSensorNumber, callback ){        client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.swversion             === undefined ){ return err;} callback(result.swversion            ) } )}
exports.getType = function (iSensorNumber, callback ){             client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.type                  === undefined ){ return err;} callback(result.type                 ) } )}
exports.getUniqueid = function (iSensorNumber, callback ){         client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.uniqueid              === undefined ){ return err;} callback(result.uniqueid             ) } )}
exports.getUniqueid = function (iSensorNumber, callback ){         client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.recycle               === undefined ){ return err;} callback(result.recycle              ) } )}                                                                                                                                                                                                                                                                                                   
exports.getButtonevent = function (iSensorNumber, callback ){      client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.state.buttonevent     === undefined ){ return err;} callback(result.state.buttonevent    ) } )}
exports.getLightLevel = function (iSensorNumber, callback ){       client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.state.lightlevel      === undefined ){ return err;} callback(result.state.lightlevel     ) } )}
exports.getDark = function (iSensorNumber, callback ){             client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.state.dark            === undefined ){ return err;} callback(result.state.dark           ) } )}
exports.getDaylight = function (iSensorNumber, callback ){         client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.state.daylight        === undefined ){ return err;} callback(result.state.daylight       ) } )}
exports.getStatus = function (iSensorNumber, callback ){           client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.state.status          === undefined ){ return err;} callback(result.state.status         ) } )}
exports.getLastupdated = function (iSensorNumber, callback ){      client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.state.lastupdated     === undefined ){ return err;} callback(result.state.lastupdated    ) } )}
exports.getPresence = function (iSensorNumber, callback ){         client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.state.presence        === undefined ){ return err;} callback(result.state.presence       ) } )}
exports.getTemperature = function (iSensorNumber, callback ){      client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.state.temperature     === undefined ){ return err;} callback(result.state.temperature    ) } )}
exports.getOn = function (iSensorNumber, callback ){               client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.on             === undefined ){ return err;} callback(result.config.on            ) } )}
exports.getBattery = function (iSensorNumber, callback ){          client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.battery        === undefined ){ return err;} callback(result.config.battery       ) } )}
exports.getConfigured = function (iSensorNumber, callback ){       client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.configured     === undefined ){ return err;} callback(result.config.configured    ) } )}
exports.getReachable = function (iSensorNumber, callback ){        client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.reachable      === undefined ){ return err;} callback(result.config.reachable     ) } )}
exports.getAlert = function (iSensorNumber, callback ){            client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.alert          === undefined ){ return err;} callback(result.config.alert         ) } )}
exports.getTholdDark = function (iSensorNumber, callback ){        client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.tholddark      === undefined ){ return err;} callback(result.config.tholddark     ) } )}
exports.getTholdOffset = function (iSensorNumber, callback ){      client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.tholdoffset    === undefined ){ return err;} callback(result.config.tholdoffset   ) } )}
exports.getLedindication = function (iSensorNumber, callback ){    client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.ledindication  === undefined ){ return err;} callback(result.config.ledindication ) } )}
exports.getUsertest = function (iSensorNumber, callback ){         client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.usertest       === undefined ){ return err;} callback(result.config.usertest      ) } )}
exports.getSensitivity = function (iSensorNumber, callback ){      client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.sensitivity    === undefined ){ return err;} callback(result.config.sensitivity   ) } )}
exports.getSensitivitymax = function (iSensorNumber, callback ){   client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.sensitivitymax === undefined ){ return err;} callback(result.config.sensitivitymax) } )}
exports.getSunsetoffset = function (iSensorNumber, callback ){     client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.sunsetoffset   === undefined ){ return err;} callback(result.config.sunsetoffset  ) } )}
exports.getUnriseoffset = function (iSensorNumber, callback ){     client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.sunriseoffset  === undefined ){ return err;} callback(result.config.sunriseoffset ) } )}
exports.getPending = function (iSensorNumber, callback ){          client.get('/sensors/' + iSensorNumber + '/', function (err, result) { if ( err || typeof result.config.pending        === undefined ){ return err;} callback(result.config.pending       ) } )}


/** setValue **/
//set attribute for a single sensor
// Example: sensor.getManufacturerName(iSensorNumber, Value)
//###############################################################################################################################################################################






/** loadInfo **/
//load variables from 1 light from disk
// Example: sensor.loadInfo(iSensorNumber)
//###############################################################################################################################################################################
exports.loadInfo = function(iSensorNumber){
  //if (!fs.existsSync(pathhuelightvalues + iSensorNumber + "/state"))
  var path;

  path = pathhuesensorvalues + iSensorNumber + "/manufacturername"      ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArrayLightManufacturerName[iSensorNumber] = data; console.log("Read Sensor " + iSensorNumber + " - /manufacturername      : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/modelid"               ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArraySensorModelId[iSensorNumber]         = data; console.log("Read Sensor " + iSensorNumber + " - /modelid               : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/name"                  ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArraySensorName[iSensorNumber]            = data; console.log("Read Sensor " + iSensorNumber + " - /name                  : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/swversion"             ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArraySensorSwVersion[iSensorNumber]       = data; console.log("Read Sensor " + iSensorNumber + " - /swversion             : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/type"                  ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArraySensorType[iSensorNumber]            = data; console.log("Read Sensor " + iSensorNumber + " - /type                  : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/uniqueid"              ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArraySensorUniqueId[iSensorNumber]        = data; console.log("Read Sensor " + iSensorNumber + " - /uniqueid              : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/buttonevent"     ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorButtonEvent[iSensorNumber]     = data; console.log("Read Sensor " + iSensorNumber + " - /state/buttonevent     : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/lightlevel"      ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorLightLevel[iSensorNumber]      = data; console.log("Read Sensor " + iSensorNumber + " - /state/lightlevel      : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/dark"            ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArraySensorDark[iSensorNumber]            = data; console.log("Read Sensor " + iSensorNumber + " - /state/dark            : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/daylight"        ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArraySensorDaylight[iSensorNumber]        = data; console.log("Read Sensor " + iSensorNumber + " - /state/daylight        : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/status"          ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorStatus[iSensorNumber]          = data; console.log("Read Sensor " + iSensorNumber + " - /state/status          : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/lastupdated"     ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArraySensorLastupdated[iSensorNumber]     = data; console.log("Read Sensor " + iSensorNumber + " - /state/lastupdated     : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/presence"        ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArraySensorPresence[iSensorNumber]        = data; console.log("Read Sensor " + iSensorNumber + " - /state/presence        : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/temperature"     ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorTemperature[iSensorNumber]     = data; console.log("Read Sensor " + iSensorNumber + " - /state/temperature     : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/state/on"              ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArraySensorOn[iSensorNumber]              = data; console.log("Read Sensor " + iSensorNumber + " - /state/on              : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/battery"        ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorBattery[iSensorNumber]         = data; console.log("Read Sensor " + iSensorNumber + " - /config/battery        : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/configured"     ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArraySensorConfigured[iSensorNumber]      = data; console.log("Read Sensor " + iSensorNumber + " - /config/configured     : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/reachable"      ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArraySensorReachable[iSensorNumber]       = data; console.log("Read Sensor " + iSensorNumber + " - /config/reachable      : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/alert"          ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArraySensorAlert[iSensorNumber]           = data; console.log("Read Sensor " + iSensorNumber + " - /config/alert          : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/tholddark"      ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorTholdDark[iSensorNumber]       = data; console.log("Read Sensor " + iSensorNumber + " - /config/tholddark      : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/tholdoffset"    ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorTholdOffset[iSensorNumber]     = data; console.log("Read Sensor " + iSensorNumber + " - /config/tholdoffset    : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/ledindication"  ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArraySensorLedindication[iSensorNumber]   = data; console.log("Read Sensor " + iSensorNumber + " - /config/ledindication  : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/usertest"       ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ bArraySensorUsertest[iSensorNumber]        = data; console.log("Read Sensor " + iSensorNumber + " - /config/usertest       : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/sensitivity"    ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorSensitivity[iSensorNumber]     = data; console.log("Read Sensor " + iSensorNumber + " - /config/sensitivity    : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/sensitivitymax" ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorSensitivityMax[iSensorNumber]  = data; console.log("Read Sensor " + iSensorNumber + " - /config/sensitivitymax : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/sunsetoffset"   ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorSunsetoffset[iSensorNumber]    = data; console.log("Read Sensor " + iSensorNumber + " - /config/sunsetoffset   : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/sunriseoffset"  ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ iArraySensorSunriseoffset[iSensorNumber]   = data; console.log("Read Sensor " + iSensorNumber + " - /config/sunriseoffset  : " + data ); }; }); };
  path = pathhuesensorvalues + iSensorNumber + "/config/pending"        ; if ( fs.existsSync( path ) ){ fs.readFile( path , function read(err, data) { if(err) { return console.log(err); }   if( data !== undefined){ sArraySensorPending[iSensorNumber]         = data; console.log("Read Sensor " + iSensorNumber + " - /config/pending        : " + data ); }; }); };

};


/** loadInfo All**/
//loads all variables from all sensors from disk
// Example: sensor.loadInfoAll()
//###############################################################################################################################################################################
exports.loadInfoAll = function(){
  //process.stdout.write('\n' + " Push Sensor Info...");
  var x = 0;
  loadInfoAllDo();

  function loadInfoAllDo(){
    if ( x >= iArraySensorConnected.length ){ return; }
    sensor.loadInfo(iArraySensorConnected[x++]);
    setTimeout(loadInfoAllDo, 10);
  }
}


/** saveInfo **/
// saves all variables from 1 sensor to disk
// Example: sensor.saveInfo(iSensorNumber)
//###############################################################################################################################################################################
exports.saveInfo = function(iSensorNumber){

  if (!fs.existsSync(pathhuesensorvalues + iSensorNumber + "/state")) { exec("/bin/mkdir -p " + pathhuesensorvalues + iSensorNumber + "/state" ); };
  if (!fs.existsSync(pathhuesensorvalues + iSensorNumber + "/state")) { exec("/bin/mkdir -p " + pathhuesensorvalues + iSensorNumber + "/config" ); };

  if ( sArraySensorManufacturerName[iSensorNumber] !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/manufacturername"      , sArraySensorManufacturerName[iSensorNumber] , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /manufacturername      : " + sArraySensorManufacturerName[iSensorNumber]        ); }); };              
  if ( sArraySensorModelId[iSensorNumber]          !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/modelid"               , sArraySensorModelId[iSensorNumber]          , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /modelid               : " + sArraySensorModelId[iSensorNumber]                 ); }); };              
  if ( sArraySensorName[iSensorNumber]             !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/name"                  , sArraySensorName[iSensorNumber]             , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /name                  : " + sArraySensorName[iSensorNumber]                    ); }); };              
  if ( sArraySensorSwVersion[iSensorNumber]        !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/swversion"             , sArraySensorSwVersion[iSensorNumber]        , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /swversion             : " + sArraySensorSwVersion[iSensorNumber]               ); }); };              
  if ( sArraySensorType[iSensorNumber]             !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/type"                  , sArraySensorType[iSensorNumber]             , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /type                  : " + sArraySensorType[iSensorNumber]                    ); }); };              
  if ( sArraySensorUniqueId[iSensorNumber]         !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/uniqueid"              , sArraySensorUniqueId[iSensorNumber]         , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /uniqueid              : " + sArraySensorUniqueId[iSensorNumber]                ); }); };              
  if ( iArraySensorButtonEvent[iSensorNumber]      !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/buttonevent"     , iArraySensorButtonEvent[iSensorNumber]      , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/buttonevent     : " + iArraySensorButtonEvent[iSensorNumber]             ); }); };              
  if ( iArraySensorLightLevel[iSensorNumber]       !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/lightlevel"      , iArraySensorLightLevel[iSensorNumber]       , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/lightlevel      : " + iArraySensorLightLevel[iSensorNumber]              ); }); };              
  if ( bArraySensorDark[iSensorNumber]             !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/dark"            , bArraySensorDark[iSensorNumber]             , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/dark            : " + bArraySensorDark[iSensorNumber]                    ); }); };              
  if ( bArraySensorDaylight[iSensorNumber]         !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/daylight"        , bArraySensorDaylight[iSensorNumber]         , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/daylight        : " + bArraySensorDaylight[iSensorNumber]                ); }); };              
  if ( iArraySensorStatus[iSensorNumber]           !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/status"          , iArraySensorStatus[iSensorNumber]           , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/status          : " + iArraySensorStatus[iSensorNumber]                  ); }); };              
  if ( sArraySensorLastupdated[iSensorNumber]      !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/lastupdated"     , sArraySensorLastupdated[iSensorNumber]      , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/lastupdated     : " + sArraySensorLastupdated[iSensorNumber]             ); }); };              
  if ( bArraySensorPresence[iSensorNumber]         !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/presence"        , bArraySensorPresence[iSensorNumber]         , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/presence        : " + bArraySensorPresence[iSensorNumber]                ); }); };              
  if ( iArraySensorTemperature[iSensorNumber]      !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/temperature"     , iArraySensorTemperature[iSensorNumber]      , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/temperature     : " + iArraySensorTemperature[iSensorNumber]             ); }); };              
  if ( bArraySensorOn[iSensorNumber]               !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/state/on"              , bArraySensorOn[iSensorNumber]               , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /state/on              : " + bArraySensorOn[iSensorNumber]                      ); }); };              
  if ( iArraySensorBattery[iSensorNumber]          !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/battery"        , iArraySensorBattery[iSensorNumber]          , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/battery        : " + iArraySensorBattery[iSensorNumber]                 ); }); };              
  if ( bArraySensorConfigured[iSensorNumber]       !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/configured"     , bArraySensorConfigured[iSensorNumber]       , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/configured     : " + bArraySensorConfigured[iSensorNumber]              ); }); };              
  if ( bArraySensorReachable[iSensorNumber]        !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/reachable"      , bArraySensorReachable[iSensorNumber]        , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/reachable      : " + bArraySensorReachable[iSensorNumber]               ); }); };              
  if ( sArraySensorAlert[iSensorNumber]            !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/alert"          , sArraySensorAlert[iSensorNumber]            , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/alert          : " + sArraySensorAlert[iSensorNumber]                   ); }); };              
  if ( iArraySensorTholdDark[iSensorNumber]        !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/tholddark"      , iArraySensorTholdDark[iSensorNumber]        , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/tholddark      : " + iArraySensorTholdDark[iSensorNumber]               ); }); };              
  if ( iArraySensorTholdOffset[iSensorNumber]      !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/tholdoffset"    , iArraySensorTholdOffset[iSensorNumber]      , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/tholdoffset    : " + iArraySensorTholdOffset[iSensorNumber]             ); }); };              
  if ( bArraySensorLedindication[iSensorNumber]    !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/ledindication"  , bArraySensorLedindication[iSensorNumber]    , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/ledindication  : " + bArraySensorLedindication[iSensorNumber]           ); }); };              
  if ( bArraySensorUsertest[iSensorNumber]         !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/usertest"       , bArraySensorUsertest[iSensorNumber]         , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/usertest       : " + bArraySensorUsertest[iSensorNumber]                ); }); };              
  if ( iArraySensorSensitivity[iSensorNumber]      !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/sensitivity"    , iArraySensorSensitivity[iSensorNumber]      , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/sensitivity    : " + iArraySensorSensitivity[iSensorNumber]             ); }); };              
  if ( iArraySensorSensitivityMax[iSensorNumber]   !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/sensitivitymax" , iArraySensorSensitivityMax[iSensorNumber]   , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/sensitivitymax : " + iArraySensorSensitivityMax[iSensorNumber]          ); }); };              
  if ( iArraySensorSunsetoffset[iSensorNumber]     !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/sunsetoffset"   , iArraySensorSunsetoffset[iSensorNumber]     , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/sunsetoffset   : " + iArraySensorSunsetoffset[iSensorNumber]            ); }); };              
  if ( iArraySensorSunriseoffset[iSensorNumber]    !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/sunriseoffset"  , iArraySensorSunriseoffset[iSensorNumber]    , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/sunriseoffset  : " + iArraySensorSunriseoffset[iSensorNumber]           ); }); };              
  if ( sArraySensorPending[iSensorNumber]          !== undefined ){ fs.writeFile( pathhuesensorvalues + iSensorNumber + "/config/pending"        , sArraySensorPending[iSensorNumber]          , function(err) { if(err) { return console.log(err); } console.log("Saved Sensor " + iSensorNumber + " - /config/pending        : " + sArraySensorPending[iSensorNumber]                 ); }); };              
                
}

/** setInfo - ALL**/
//saves all variables from all sensors to disk
// Example: light.saveInfoAll()
//###############################################################################################################################################################################
exports.saveInfoAll = function(){
  //process.stdout.write('\n' + " Fetch Sensor Info...");
  var x = 0;
  saveInfoAllDo();

  function saveInfoAllDo(){
    if ( x >= iArraySensorConnected.length ){ return; }
    sensor.saveInfo(iArraySensorConnected[x++]);
    setTimeout(saveInfoAllDo, 10);
  }
}
