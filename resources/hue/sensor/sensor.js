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
//get all attributes for 1 sensor from hue to script-variables
//###############################################################################################################################################################################
exports.getInfo = function( iSensorNumber,sValue){
  client.getSensor( iSensorNumber, function( err, result ){ 

    if ( err || result === undefined || result.state === undefined ){ return err;}
    
    //General:
    if ( typeof result.manufacturername !== undefined){         sArraySensorManufacturerName[iSensorNumber] = result.manufacturername;         };  
    if ( typeof result.modelid !== undefined         ){         sArraySensorModelId[iSensorNumber] = result.modelid;                           };  
    if ( typeof result.name !== undefined            ){         sArraySensorName[iSensorNumber] = result.name;                                 };  
    if ( typeof result.swversion !== undefined       ){         sArraySensorSwVersion[iSensorNumber] = result.swversion;                       };  
    if ( typeof result.type !== undefined            ){         sArraySensorType[iSensorNumber] = result.type;                                 };  
    if ( typeof result.uniqueid !== undefined        ){         sArraySensorUniqueId[iSensorNumber] = result.uniqueid;                         };  
                                                                                                                                            
    //State:
    if ( typeof result.state.lightlevel !== undefined ){        iArraySensorLightLevel[iSensorNumber] = result.state.lightlevel;               };
    if ( typeof result.state.dark !== undefined ){              bArraySensorDark[iSensorNumber] = result.state.dark;                           };
    if ( typeof result.state.daylight !== undefined ){          bArraySensorDaylight[iSensorNumber] = result.state.daylight;                   };
    if ( typeof result.state.status !== undefined ){            iArraySensorStatus[iSensorNumber] = result.state.status;                       };
    if ( typeof result.state.lastupdated !== undefined ){       sArraySensorLastupdated[iSensorNumber] = result.state.lastupdated;             };
    if ( typeof result.state.presence !== undefined ){          bArraySensorPresence[iSensorNumber] = result.state.presence;                   };
    if ( typeof result.state.temperature !== undefined ){       iArraySensorTemperature[iSensorNumber] = result.state.temperature;             };

    //Config:
    if ( typeof result.config.on !== undefined ){               bArraySensorOn[iSensorNumber] = result.config.on;                              };
    if ( typeof result.config.battery  !== undefined ){         iArraySensorBattery[iSensorNumber] = result.config.battery;                    };
    if ( typeof result.config.configured !== undefined ){       bArraySensorConfigured[iSensorNumber] = result.config.configured;              };
    if ( typeof result.config.reachable !== undefined ){        bArraySensorReachable[iSensorNumber] = result.config.reachable;                };
    if ( typeof result.config.alert !== undefined ){            sArraySensorAlert[iSensorNumber] = result.config.alert;                        };
    if ( typeof result.config.tholddark !== undefined ){        iArraySensorTholdDark[iSensorNumber] = result.config.tholddark;                };
    if ( typeof result.config.tholdoffset !== undefined ){      iArraySensorTholdOffset[iSensorNumber] = result.config.tholdoffset;            };
    if ( typeof result.config.ledindication !== undefined ){    bArraySensorLedindication[iSensorNumber] = result.config.ledindication;        };
    if ( typeof result.config.usertest !== undefined ){         bArraySensorUsertest[iSensorNumber] = result.config.usertest;                  };
    if ( typeof result.config.sensitivity !== undefined ){      iArraySensorSensitivity[iSensorNumber] = result.config.sensitivity;            };
    if ( typeof result.config.sensitivitymax !== undefined ){   iArraySensorSensitivityMax[iSensorNumber] = result.config.sensitivitymax;      };
    if ( typeof result.config.sunsetoffset !== undefined ){     iArraySensorSunsetoffset[iSensorNumber] = result.config.sunsetoffset;          };
    if ( typeof result.config.sunriseoffset !== undefined ){    iArraySensorSunriseoffset[iSensorNumber] = result.config.sunriseoffset;        };
    if ( typeof result.config.pending !== undefined ){          sArraySensorPending[iSensorNumber] = result.config.pending;                    };

    //Recycle:
    if ( typeof result.recycle !== undefined                      ){ bArraySensorRecycle[iSensorNumber] = result.recycle;                      };  // sensor.getRecycle( iSensorNumber );  
  });
};

/** getInfo - ALL**/
//get all attributes for all sensors from hue to script-variables
//###############################################################################################################################################################################
exports.getInfoAll = function(){
  //process.stdout.write('\n' + " Fetch Sensor Info...");
  for ( x = 0; x < iArraySensorConnected.length; x++ ){ 
    sensor.getInfo(iArraySensorConnected[x]); 
  }
}


/** setInfo **/
//sets all attributes from 1 sensor from script-variables to hue
//###############################################################################################################################################################################
exports.setInfo = function( iSensorNumber){
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




///** setInfo - ALL**/
//sets all attributes for all lights from script-variables to hue
////###############################################################################################################################################################################
//exports.setInfoAll = function(){
//  //process.stdout.write('\n' + " Fetch Sensor Info...");
//  for ( x = 0; x < iArraySensorConnected.length; x++ ){ 
//    sensor.setInfo(iArraySensorConnected[x]); 
//  }
//}




/** getValue **/
//get attribute from a single sensor
//###############################################################################################################################################################################
exports.getName = function( iSensorNumber ){                client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.name === undefined ) return err;                 sArraySensorName[iSensorNumber] = result.state.name;                            });};    //if ( debug ){ console.log(`    Name:             ${result.name}`);                    }; });};
exports.getType= function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.type === undefined ) return err;                 sArraySensorType[iSensorNumber] = result.state.type;                            });};    //if ( debug ){ console.log(`    Type:             ${result.type}`);                    }; });};
exports.getModelId = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.modelid === undefined ) return err;              sArraySensorModelId[iSensorNumber] = result.state.modelid;                      });};    //if ( debug ){ console.log(`    ModelId:          ${result.modelid}`);                }; });};
exports.getManufacturername = function( iSensorNumber ){    client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.manufacturername === undefined ) return err;     sArraySensorManufacturerName[iSensorNumber] = result.state.manufacturername;    });};    //if ( debug ){ console.log(`    Manufacturername: ${result.manufacturername}`);        }; });};
exports.getSwversion = function( iSensorNumber ){           client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.swversion === undefined ) return err;            sArraySensorSwVersion[iSensorNumber] = result.state.swversion;                  });};    //if ( debug ){ console.log(`    Swversion:        ${result.swversion}`);                }; });};
exports.getUniqueid = function( iSensorNumber ){            client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.uniqueid === undefined ) return err;             sArraySensorUniqueId[iSensorNumber] = result.state.uniqueid;                    });};    //if ( debug ){ console.log(`    Uniqueid:         ${result.uniqueid}`);                }; });};
exports.getRecycle = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.recycle === undefined ) return err;              bArraySensorRecycle[iSensorNumber] = result.state.recycle;                      });};    //if ( debug ){ console.log(`    Recycle:          ${result.recycle}`);                }; });};

exports.getButtonevent = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.buttonevent === undefined ) return err;          iArraySensorButtonEvent[iSensorNumber] = result.state.buttonevent;              });};    //if ( debug ){ console.log(`${result.state.buttonevent}`);        }; });};
exports.getLightLevel = function( iSensorNumber ){          client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.lightlevel === undefined ) return err;           iArraySensorLightLevel[iSensorNumber] = result.state.lightlevel;                });};    //if ( debug ){ console.log(`${result.state.lightlevel}`);         }; });};
exports.getDark = function( iSensorNumber ){                client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.dark === undefined ) return err;                 bArraySensorDark[iSensorNumber] = result.state.dark;                            });};    //if ( debug ){ console.log(`${result.state.dark}`);            }; });};
exports.getDaylight = function( iSensorNumber ){            client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.daylight === undefined ) return err;             bArraySensorDaylight[iSensorNumber] = result.state.daylight;                    });};    //if ( debug ){ console.log(`${result.state.daylight}`);        }; });};
exports.getStatus = function( iSensorNumber ){              client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.status === undefined ) return err;               iArraySensorStatus[iSensorNumber] = result.state.status;                        });};    //if ( debug ){ console.log(`${result.state.status}`);            }; });};
exports.getLastupdated = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.lastupdated === undefined ) return err;          sArraySensorLastupdated[iSensorNumber] = result.state.lastupdated;              });};    //if ( debug ){ console.log(`${result.state.lastupdated}`);        }; });};
exports.getPresence = function( iSensorNumber ){            client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.presence === undefined ) return err;             bArraySensorPresence[iSensorNumber] = result.state.presence;                    });};    //if ( debug ){ console.log(`${result.state.presence}`);        }; });};
exports.getTemperature = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.temperature === undefined ) return err;          iArraySensorTemperature[iSensorNumber] = result.state.temperature;              });};    //if ( debug ){ console.log(`${result.state.temperature}`);        }; });};

exports.getOn = function( iSensorNumber ){                  client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.on === undefined ) return err;                   bArraySensorOn[iSensorNumber] = result.state.on;                                });};    //if ( debug ){ console.log(`${result.config.on}`);                }; });};
exports.getBattery = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.battery === undefined ) return err;              iArraySensorBattery[iSensorNumber] = result.state.battery;                      });};    //if ( debug ){ console.log(`${result.config.battery}`);        }; });};
exports.getConfigured = function( iSensorNumber ){          client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.configured === undefined ) return err;           bArraySensorConfigured[iSensorNumber] = result.state.configured;                });};    //if ( debug ){ console.log(`${result.config.configured}`);        }; });};
exports.getReachable = function( iSensorNumber ){           client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.reachable === undefined ) return err;            bArraySensorReachable[iSensorNumber] = result.state.reachable;                  });};    //if ( debug ){ console.log(`${result.config.reachable}`);        }; });};
exports.getAlert = function( iSensorNumber ){               client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.tholddark === undefined ) return err;            sArraySensorAlert[iSensorNumber] = result.state.alert;                          });};    //if ( debug ){ console.log(`${result.config.alert}`);            }; });};
exports.getTholdDark = function( iSensorNumber ){           client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.alert === undefined ) return err;                iArraySensorTholdDark[iSensorNumber] = result.state.tholddark;                  });};    //if ( debug ){ console.log(`${result.config.tholddark}`);        }; });};
exports.getTholdOffset = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.tholdoffset === undefined ) return err;          iArraySensorTholdOffset[iSensorNumber] = result.state.tholdoffset;              });};    //if ( debug ){ console.log(`${result.config.tholdoffset}`);    }; });};
exports.getLedindication = function( iSensorNumber ){       client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.ledindication === undefined ) return err;        bArraySensorLedindication[iSensorNumber] = result.state.ledindication;          });};    //if ( debug ){ console.log(`${result.config.ledindication}`);    }; });};
exports.getUsertest = function( iSensorNumber ){            client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.usertest === undefined ) return err;             bArraySensorUsertest[iSensorNumber] = result.state.usertest;                    });};    //if ( debug ){ console.log(`${result.config.usertest}`);        }; });};
exports.getSensitivity = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.sensitivity === undefined ) return err;          iArraySensorSensitivity[iSensorNumber] = result.state.sensitivity;              });};    //if ( debug ){ console.log(`${result.config.sensitivity}`);    }; });};
exports.getSensitivitymax = function( iSensorNumber ){      client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.sensitivitymax === undefined ) return err;       iArraySensorSensitivityMax[iSensorNumber] = result.state.sensitivitymax;        });};    //if ( debug ){ console.log(`${result.config.sensitivitymax}`);    }; });};
exports.getSunsetoffset = function( iSensorNumber ){        client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.sunsetoffset === undefined ) return err;         iArraySensorSunsetoffset[iSensorNumber] = result.state.sunsetoffset;            });};    //if ( debug ){ console.log(`${result.config.sunsetoffset}`);    }; });};
exports.getUnriseoffset = function( iSensorNumber ){        client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.sunriseoffset === undefined ) return err;        iArraySensorSunriseoffset[iSensorNumber] = result.state.sunriseoffset;          });};    //if ( debug ){ console.log(`${result.config.sunriseoffset}`);    }; });};
exports.getPending = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.pending === undefined ) return err;              sArraySensorPending[iSensorNumber] = result.state.pending;                      });};    //if ( debug ){ console.log(`${result.config.pending}`);        }; });};

/** setValue **/
//set attribute for a single sensor
//###############################################################################################################################################################################


/** loadInfo **/
//loads all variables from 1 sensor to disk
//###############################################################################################################################################################################
exports.loadInfo = function(iSensorNumber){

  if ( sArraySensorManufacturerName[iSensorNumber] !== undefined ){ sArraySensorManufacturerName[iSensorNumber] = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/manufacturername"            ); };                                                  
  if ( sArraySensorModelId[iSensorNumber]          !== undefined ){ sArraySensorModelId[iSensorNumber]          = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/modelid"                     ); };                                                     
  if ( sArraySensorName[iSensorNumber]             !== undefined ){ sArraySensorName[iSensorNumber]             = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/name"                        ); };                                                                      
  if ( sArraySensorSwVersion[iSensorNumber]        !== undefined ){ sArraySensorSwVersion[iSensorNumber]        = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/swversion"                   ); };                                                                       
  if ( sArraySensorType[iSensorNumber]             !== undefined ){ sArraySensorType[iSensorNumber]             = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/type"                        ); };                                                                        
  if ( sArraySensorUniqueId[iSensorNumber]         !== undefined ){ sArraySensorUniqueId[iSensorNumber]         = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/uniqueid"                    ); };                                                                        
  if ( iArraySensorButtonEvent[iSensorNumber]      !== undefined ){ iArraySensorButtonEvent[iSensorNumber]      = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/buttonevent"            ); };                                                                        
  if ( iArraySensorLightLevel[iSensorNumber]       !== undefined ){ iArraySensorLightLevel[iSensorNumber]       = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/lightlevel"            ); };                                                                        
  if ( bArraySensorDark[iSensorNumber]             !== undefined ){ bArraySensorDark[iSensorNumber]             = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/dark"                  ); };                                                                  
  if ( bArraySensorDaylight[iSensorNumber]         !== undefined ){ bArraySensorDaylight[iSensorNumber]         = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/daylight"              ); };                                                                    
  if ( iArraySensorStatus[iSensorNumber]           !== undefined ){ iArraySensorStatus[iSensorNumber]           = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/status"                ); };                                                                    
  if ( sArraySensorLastupdated[iSensorNumber]      !== undefined ){ sArraySensorLastupdated[iSensorNumber]      = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/lastupdated"           ); };                                                                     
  if ( bArraySensorPresence[iSensorNumber]         !== undefined ){ bArraySensorPresence[iSensorNumber]         = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/presence"              ); };                                                                  
  if ( iArraySensorTemperature[iSensorNumber]      !== undefined ){ iArraySensorTemperature[iSensorNumber]      = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/temperature"           ); };                                                                 
  if ( bArraySensorOn[iSensorNumber]               !== undefined ){ bArraySensorOn[iSensorNumber]               = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/on"                    ); };                                                                    
  if ( iArraySensorBattery[iSensorNumber]          !== undefined ){ iArraySensorBattery[iSensorNumber]          = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/battery"        ); };                                                                    
  if ( bArraySensorConfigured[iSensorNumber]       !== undefined ){ bArraySensorConfigured[iSensorNumber]       = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/configured"     ); };                                                                    
  if ( bArraySensorReachable[iSensorNumber]        !== undefined ){ bArraySensorReachable[iSensorNumber]        = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/reachable"      ); };                                                                
  if ( sArraySensorAlert[iSensorNumber]            !== undefined ){ sArraySensorAlert[iSensorNumber]            = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/alert"          ); };                                                                
  if ( iArraySensorTholdDark[iSensorNumber]        !== undefined ){ iArraySensorTholdDark[iSensorNumber]        = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/tholddark"      ); };                                                
  if ( iArraySensorTholdOffset[iSensorNumber]      !== undefined ){ iArraySensorTholdOffset[iSensorNumber]      = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/tholdoffset"    ); };                                                
  if ( bArraySensorLedindication[iSensorNumber]    !== undefined ){ bArraySensorLedindication[iSensorNumber]    = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/ledindication"  ); };                                                                    
  if ( bArraySensorUsertest[iSensorNumber]         !== undefined ){ bArraySensorUsertest[iSensorNumber]         = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/usertest"       ); };                                                                    
  if ( iArraySensorSensitivity[iSensorNumber]      !== undefined ){ iArraySensorSensitivity[iSensorNumber]      = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/sensitivity"    ); };                                                                 
  if ( iArraySensorSensitivityMax[iSensorNumber]   !== undefined ){ iArraySensorSensitivityMax[iSensorNumber]   = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/sensitivitymax" ); };                                                                 
  if ( iArraySensorSunsetoffset[iSensorNumber]     !== undefined ){ iArraySensorSunsetoffset[iSensorNumber]     = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/sunsetoffset"   ); };                                               
  if ( iArraySensorSunriseoffset[iSensorNumber]    !== undefined ){ iArraySensorSunriseoffset[iSensorNumber]    = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/sunriseoffset"  ); };                                                
  if ( sArraySensorPending[iSensorNumber]          !== undefined ){ sArraySensorPending[iSensorNumber]          = exec( "/bin/cat " + pathhuesensorvalues + iSensorNumber + "/state/config/pending"        ); };                                                                    
}

/** loadInfo All**/
//loads all variables from all sensors to disk
//###############################################################################################################################################################################
exports.loadInfoAll = function(){
  //process.stdout.write('\n' + " Push Sensor Info...");
  for ( x = 0; x < iArraySensorConnected.length; x++ ){ 
    sensor.loadInfo(iArraySensorConnected[x]); 
  }
}

/** saveInfo **/
//saves all variables from 1 sensor to disk
//###############################################################################################################################################################################
exports.saveInfo = function(iSensorNumber){

  if (!fs.existsSync(pathhuesensorvalues + iSensorNumber + "/state")) { exec("/bin/mkdir -p " + pathhuesensorvalues + iSensorNumber + "/state" ); };

  if ( sArraySensorManufacturerName[iSensorNumber] !== undefined ){ exec( "/bin/echo " + sArraySensorManufacturerName[iSensorNumber] + " > " + pathhuesensorvalues + iSensorNumber + "/manufacturername" ); };  
  if ( sArraySensorModelId[iSensorNumber]          !== undefined ){ exec( "/bin/echo " + sArraySensorModelId[iSensorNumber]          + " > " + pathhuesensorvalues + iSensorNumber + "/modelid" ); };      
  if ( sArraySensorName[iSensorNumber]             !== undefined ){ exec( "/bin/echo " + sArraySensorName[iSensorNumber]             + " > " + pathhuesensorvalues + iSensorNumber + "/name" ); };                       
  if ( sArraySensorSwVersion[iSensorNumber]        !== undefined ){ exec( "/bin/echo " + sArraySensorSwVersion[iSensorNumber]        + " > " + pathhuesensorvalues + iSensorNumber + "/swversion" ); };                        
  if ( sArraySensorType[iSensorNumber]             !== undefined ){ exec( "/bin/echo " + sArraySensorType[iSensorNumber]             + " > " + pathhuesensorvalues + iSensorNumber + "/type" ); };                        
  if ( sArraySensorUniqueId[iSensorNumber]         !== undefined ){ exec( "/bin/echo " + sArraySensorUniqueId[iSensorNumber]         + " > " + pathhuesensorvalues + iSensorNumber + "/uniqueid" ); };                        
  if ( iArraySensorButtonEvent[iSensorNumber]      !== undefined ){ exec( "/bin/echo " + iArraySensorButtonEvent[iSensorNumber]      + " > " + pathhuesensorvalues + iSensorNumber + "/state/buttonevent" ); };                          
  if ( iArraySensorLightLevel[iSensorNumber]       !== undefined ){ exec( "/bin/echo " + iArraySensorLightLevel[iSensorNumber]       + " > " + pathhuesensorvalues + iSensorNumber + "/state/lightlevel" ); };                        
  if ( bArraySensorDark[iSensorNumber]             !== undefined ){ exec( "/bin/echo " + bArraySensorDark[iSensorNumber]             + " > " + pathhuesensorvalues + iSensorNumber + "/state/dark" ); };                  
  if ( bArraySensorDaylight[iSensorNumber]         !== undefined ){ exec( "/bin/echo " + bArraySensorDaylight[iSensorNumber]         + " > " + pathhuesensorvalues + iSensorNumber + "/state/daylight" ); };                     
  if ( iArraySensorStatus[iSensorNumber]           !== undefined ){ exec( "/bin/echo " + iArraySensorStatus[iSensorNumber]           + " > " + pathhuesensorvalues + iSensorNumber + "/state/status" ); };                     
  if ( sArraySensorLastupdated[iSensorNumber]      !== undefined ){ exec( "/bin/echo " + sArraySensorLastupdated[iSensorNumber]      + " > " + pathhuesensorvalues + iSensorNumber + "/state/lastupdated" ); };                     
  if ( bArraySensorPresence[iSensorNumber]         !== undefined ){ exec( "/bin/echo " + bArraySensorPresence[iSensorNumber]         + " > " + pathhuesensorvalues + iSensorNumber + "/state/presence" ); };                  
  if ( iArraySensorTemperature[iSensorNumber]      !== undefined ){ exec( "/bin/echo " + iArraySensorTemperature[iSensorNumber]      + " > " + pathhuesensorvalues + iSensorNumber + "/state/temperature" ); };                 
  if ( bArraySensorOn[iSensorNumber]               !== undefined ){ exec( "/bin/echo " + bArraySensorOn[iSensorNumber]               + " > " + pathhuesensorvalues + iSensorNumber + "/state/on" ); };                    
  if ( iArraySensorBattery[iSensorNumber]          !== undefined ){ exec( "/bin/echo " + iArraySensorBattery[iSensorNumber]          + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/battery" ); };                    
  if ( bArraySensorConfigured[iSensorNumber]       !== undefined ){ exec( "/bin/echo " + bArraySensorConfigured[iSensorNumber]       + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/configured" ); };                    
  if ( bArraySensorReachable[iSensorNumber]        !== undefined ){ exec( "/bin/echo " + bArraySensorReachable[iSensorNumber]        + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/reachable" ); };                 
  if ( sArraySensorAlert[iSensorNumber]            !== undefined ){ exec( "/bin/echo " + sArraySensorAlert[iSensorNumber]            + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/alert" ); };                 
  if ( iArraySensorTholdDark[iSensorNumber]        !== undefined ){ exec( "/bin/echo " + iArraySensorTholdDark[iSensorNumber]        + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/tholddark" ); };
  if ( iArraySensorTholdOffset[iSensorNumber]      !== undefined ){ exec( "/bin/echo " + iArraySensorTholdOffset[iSensorNumber]      + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/tholdoffset" ); };
  if ( bArraySensorLedindication[iSensorNumber]    !== undefined ){ exec( "/bin/echo " + bArraySensorLedindication[iSensorNumber]    + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/ledindication" ); };                    
  if ( bArraySensorUsertest[iSensorNumber]         !== undefined ){ exec( "/bin/echo " + bArraySensorUsertest[iSensorNumber]         + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/usertest" ); };                    
  if ( iArraySensorSensitivity[iSensorNumber]      !== undefined ){ exec( "/bin/echo " + iArraySensorSensitivity[iSensorNumber]      + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/sensitivity" ); };                 
  if ( iArraySensorSensitivityMax[iSensorNumber]   !== undefined ){ exec( "/bin/echo " + iArraySensorSensitivityMax[iSensorNumber]   + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/sensitivitymax" ); };                 
  if ( iArraySensorSunsetoffset[iSensorNumber]     !== undefined ){ exec( "/bin/echo " + iArraySensorSunsetoffset[iSensorNumber]     + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/sunsetoffset" ); };
  if ( iArraySensorSunriseoffset[iSensorNumber]    !== undefined ){ exec( "/bin/echo " + iArraySensorSunriseoffset[iSensorNumber]    + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/sunriseoffset" ); };
  if ( sArraySensorPending[iSensorNumber]          !== undefined ){ exec( "/bin/echo " + sArraySensorPending[iSensorNumber]          + " > " + pathhuesensorvalues + iSensorNumber + "/state/config/pending" ); };                    
}

/** saveInfo All**/
//saves all variables from all sensors to disk
//###############################################################################################################################################################################
exports.saveInfoAll = function(){
  //process.stdout.write('\n' + " Fetch Sensor Info...");
  for ( x = 0; x < iArraySensorConnected.length; x++ ){ 
    sensor.saveInfo(iArraySensorConnected[x]); 
  }
}
