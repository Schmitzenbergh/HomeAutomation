#!/usr/bin/env node

debug = false;

exports.getName = function( iSensorNumber ){                client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.name === undefined ) return err;                 sArraySensorName[iSensorNumber] = result.state.name;                            });};    //if ( debug ){ console.log(`    Name:             ${result.name}`);                    }; });};
exports.getType= function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.type === undefined ) return err;                 sArraySensorType[iSensorNumber] = result.state.type;                            });};    //if ( debug ){ console.log(`    Type:             ${result.type}`);                    }; });};
exports.getModelId = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.modelid === undefined ) return err;              sArraySensorModelId[iSensorNumber] = result.state.modelid;                      });};    //if ( debug ){ console.log(`    ModelId:          ${result.modelid}`);                }; });};
exports.getManufacturername = function( iSensorNumber ){    client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.manufacturername === undefined ) return err;     sArraySensorManufacturerName[iSensorNumber] = result.state.manufacturername;    });};    //if ( debug ){ console.log(`    Manufacturername: ${result.manufacturername}`);        }; });};
exports.getSwversion = function( iSensorNumber ){           client.getSensor( iSensorNumber, function( err, result ){     if ( err || typeof result.state.swversion === undefined ) return err;            sArraySensorSwversion[iSensorNumber] = result.state.swversion;                  });};    //if ( debug ){ console.log(`    Swversion:        ${result.swversion}`);                }; });};
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


exports.getInfo = function( iSensorNumber,sValue){
    if ( sValue === "manufacturername" ){         sensor.getManufacturerName( iSensorNumber );
    } else if ( sValue === "modelid" ){           sensor.getModelId( iSensorNumber );
    } else if ( sValue === "manufacturername" ){  sensor.getManufacturerName( iSensorNumber );
    } else if ( sValue === "modelid" ){           sensor.getModelId( iSensorNumber );
    } else if ( sValue === "name" ){              sensor.getName( iSensorNumber );
    } else if ( sValue === "swversion" ){         sensor.getSwVersion( iSensorNumber );
    } else if ( sValue === "type" ){              sensor.getType( iSensorNumber );
    } else if ( sValue === "uniqueid" ){          sensor.getUniqueid( iSensorNumber );
    //Output all attributes found
    } else { 
        client.getSensor( iSensorNumber, function( err, result ){ 

            //if ( err) throw err;
            if ( err || result === undefined|| result.state === undefined|| result.config === undefined ) return err;
    
            if ( debug ){ console.log('General:' + iSensorNumber ); };            //if (typeof query !== undefined && query !== null)
            if ( typeof result.name !== undefined ){                     sArraySensorName[iSensorNumber] = result.name;                                };    //if ( debug ){ console.log(`    Name:             ${result.name}`) }; };
            if ( typeof result.type !== undefined ){                     sArraySensorType[iSensorNumber] = result.type;                                };    //if ( debug ){ console.log(`    Type:             ${result.type}`) }; };
            if ( typeof result.modelid !== undefined ){                  sArraySensorModelId[iSensorNumber] = result.modelid;                          };    //if ( debug ){ console.log(`    ModelId:          ${result.modelid}`) }; };
            if ( typeof result.manufacturername !== undefined ){         sArraySensorManufacturerName[iSensorNumber] = result.manufacturername;        };    //if ( debug ){ console.log(`    Manufacturername: ${result.manufacturername}`) }; };
            if ( typeof result.swversion !== undefined ){                sArraySensorSwversion[iSensorNumber] = result.swversion;                      };    //if ( debug ){ console.log(`    Swversion:        ${result.swversion}`) }; };
            if ( typeof result.uniqueid !== undefined ){                 sArraySensorUniqueId[iSensorNumber] = result.uniqueid;                        };    //if ( debug ){ console.log(`    Uniqueid:         ${result.uniqueid}`) }; };
            if ( typeof result.recycle !== undefined ){                  bArraySensorRecycle[iSensorNumber] = result.recycle;                          };    //if ( debug ){ console.log(`    Recycle:          ${result.recycle}`) }; };
    
            //if ( debug ){ console.log('State:'); };typeof query !== undefined && query !== null
            if ( result.state.buttonevent !== undefined && result.state.buttonevent !== null){ iArraySensorButtonEvent[iSensorNumber] = result.state.buttonevent; 
            //if ( debug ){ console.log(`    Buttonevent:      ${result.state.buttonevent}`) };
            };
            if ( typeof result.state.lightlevel !== undefined ){        iArraySensorLightLevel[iSensorNumber] = result.state.lightlevel;               };    //if ( debug ){ console.log(`    LightLevel:       ${result.state.lightlevel}`) }; }; //10250
            if ( typeof result.state.dark !== undefined ){              bArraySensorDark[iSensorNumber] = result.state.dark;                           };    //if ( debug ){ console.log(`    Dark:             ${result.state.dark}`) }; };
            if ( typeof result.state.daylight !== undefined ){          bArraySensorDaylight[iSensorNumber] = result.state.daylight;                   };    //if ( debug ){ console.log(`    Daylight:         ${result.state.daylight}`) }; };
            if ( typeof result.state.status !== undefined ){            iArraySensorStatus[iSensorNumber] = result.state.status;                       };    //if ( debug ){ console.log(`    Status:           ${result.state.status}`) }; };
            if ( typeof result.state.lastupdated !== undefined ){       sArraySensorLastupdated[iSensorNumber] = result.state.lastupdated;             };    //if ( debug ){ console.log(`    Lastupdated:      ${result.state.lastupdated}`) }; };
            if ( typeof result.state.presence !== undefined ){          bArraySensorPresence[iSensorNumber] = result.state.presence;                   };    //if ( debug ){ console.log(`    Presence:         ${result.state.presence}`) }; };
            if ( typeof result.state.temperature !== undefined ){       iArraySensorTemperature[iSensorNumber] = result.state.temperature;             };    //if ( debug ){ console.log(`    Temperature:      ${result.state.temperature}`) }; };
            
            if ( debug ){ console.log('Config:'); };
            if ( typeof result.config.on !== undefined ){               bArraySensorOn[iSensorNumber] = result.config.on;                              };    //if ( debug ){ console.log(`    On:               ${result.config.on}`) }; };
            if ( typeof result.config.battery  !== undefined ){         iArraySensorBattery[iSensorNumber] = result.config.battery;                    };    //if ( debug ){ console.log(`    Battery:          ${result.config.battery}`) }; };
            if ( typeof result.config.configured !== undefined ){       bArraySensorConfigured[iSensorNumber] = result.config.configured;              };    //if ( debug ){ console.log(`    Configured:       ${result.config.configured}`) }; };
            if ( typeof result.config.reachable !== undefined ){        bArraySensorReachable[iSensorNumber] = result.config.reachable;                };    //if ( debug ){ console.log(`    Reachable:        ${result.config.reachable}`) }; };
            if ( typeof result.config.alert !== undefined ){            sArraySensorAlert[iSensorNumber] = result.config.alert;                        };    //if ( debug ){ console.log(`    Alert:            ${result.config.alert}`) }; };
            if ( typeof result.config.tholddark !== undefined ){        iArraySensorTholdDark[iSensorNumber] = result.config.tholddark;                };    //if ( debug ){ console.log(`    TholdDark:        ${result.config.tholddark}`) }; };
            if ( typeof result.config.tholdoffset !== undefined ){      iArraySensorTholdOffset[iSensorNumber] = result.config.tholdoffset;            };    //if ( debug ){ console.log(`    TholdOffset:      ${result.config.tholdoffset}`) }; };
            if ( typeof result.config.ledindication !== undefined ){    bArraySensorLedindication[iSensorNumber] = result.config.ledindication;        };    //if ( debug ){ console.log(`    Ledindication:    ${result.config.ledindication}`) }; };
            if ( typeof result.config.usertest !== undefined ){         bArraySensorUsertest[iSensorNumber] = result.config.usertest;                  };    //if ( debug ){ console.log(`    Usertest:         ${result.config.usertest}`) }; };
            if ( typeof result.config.sensitivity !== undefined ){      iArraySensorSensitivity[iSensorNumber] = result.config.sensitivity;            };    //if ( debug ){ console.log(`    Sensitivity:      ${result.config.sensitivity}`) }; };
            if ( typeof result.config.sensitivitymax !== undefined ){   iArraySensorSensitivityMax[iSensorNumber] = result.config.sensitivitymax;      };    //if ( debug ){ console.log(`    Sensitivitymax:   ${result.config.sensitivitymax}`) }; };
            if ( typeof result.config.sunsetoffset !== undefined ){     iArraySensorSunsetoffset[iSensorNumber] = result.config.sunsetoffset;          };    //if ( debug ){ console.log(`    Sunsetoffset:     ${result.config.sunsetoffset}`) }; };
            if ( typeof result.config.sunriseoffset !== undefined ){    iArraySensorSunriseoffset[iSensorNumber] = result.config.sunriseoffset;        };    //if ( debug ){ console.log(`    Unriseoffset:     ${result.config.sunriseoffset}`) }; };
            if ( typeof result.config.pending !== undefined ){          sArraySensorPending[iSensorNumber] = result.config.pending;                    };    //if ( debug ){ console.log(`    Pending:          ${result.config.pending}`) }; };
        });
    }
    }

function changeSensorConfig( iSensorNumber,bOn,iSunriseoffset,iSunsetoffset){

    bOn = typeof bOn !== undefined ? bOn : true;
    iSunriseoffset = typeof iSunriseoffset !== undefined ? iSunriseoffset : 0;
    iSunsetoffset = typeof iSunsetoffset !== undefined ? iSunsetoffset : 0;
    
    client.changeSensorConfig( iSensorNumber, {"on": bOn, "sunriseoffset": iSunriseoffset, "sunsetoffset": iSunsetoffset}, function( err, result ){ 
    if ( err) 
        throw err;
    console.log(result);
    });
}

//exports.setInfo = function( iSensorNumber,sTarget,SomeValue){
//    //Temp Cleanup
//    sTarget = sTarget.toLowerCase();
//    fValue = SomeValue;
//    iValue = SomeValue;
//    sValue = SomeValue;
//    
//    if ( sTarget === "on" ){                        
//        } else if ( sTarget === "battery" ){        
//        } else if ( sTarget === "configured" ){        
//        } else if ( sTarget === "reachable" ){        
//        } else if ( sTarget === "alert" ){            
//        } else if ( sTarget === "tholddark" ){        
//        } else if ( sTarget === "tholdoffset" ){    
//        } else if ( sTarget === "ledindication" ){    
//        } else if ( sTarget === "usertest" ){        
//        } else if ( sTarget === "sensitivity" ){    
//        } else if ( sTarget === "sensitivitymax" ){    
//        } else if ( sTarget === "sunsetoffset" ){    
//        } else if ( sTarget === "sunriseoffset" ){    
//        } else if ( sTarget === "pending" ){        
//    }
//}
//
//exports.setName = function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.name}`);});};
//exports.setType= function( iSensorNumber ){                     client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.type}`);});};
//exports.setModelId = function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.modelid}`);});};
//exports.setManufacturername = function( iSensorNumber ){     client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.manufacturername}`);});};
//exports.setSwversion = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.swversion}`);});};
//exports.setUniqueid = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.uniqueid}`);});};
//exports.setRecycle = function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.recycle}`);});};
//
//exports.setButtonevent = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.state.buttonevent}`);});};
//exports.setLightLevel = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.state.lightlevel}`);});};
//exports.setDark = function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.state.dark}`);});};
//exports.setDaylight = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.state.daylight}`);});};
//exports.setStatus = function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.state.status}`);});};
//exports.setLastupdated = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.state.lastupdated}`);});};
//exports.setPresence = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.state.presence}`);});};
//exports.setTemperature = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.state.temperature}`);});};
//
//exports.setOn = function( iSensorNumber ){                     client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.on}`);});};
//exports.setBattery = function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.battery}`);});};
//exports.setConfigured = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.configured}`);});};
//exports.setReachable = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.reachable}`);});};
//exports.setAlert = function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.alert}`);});};
//exports.setTholdDark = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.tholddark}`);});};
//exports.setTholdOffset = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.tholdoffset}`);});};
//exports.setLedindication = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.ledindication}`);});};
//exports.setUsertest = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.usertest}`);});};
//exports.setSensitivity = function( iSensorNumber ){             client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.sensitivity}`);});};
//exports.setSensitivitymax = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.sensitivitymax}`);});};
//exports.setSunsetoffset = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.sunsetoffset}`);});};
//exports.setUnriseoffset = function( iSensorNumber ){         client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.sunriseoffset}`);});};
//exports.setPending = function( iSensorNumber ){                 client.getSensor( iSensorNumber, function( err, result ){ if ( err) throw err;    console.log(`${result.config.pending}`);});};




