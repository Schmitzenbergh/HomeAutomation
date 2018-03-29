/** setValue **/
//set attribute for a single light
// Example: light.getManufacturerName(iLightNumber, Value)
//###############################################################################################################################################################################
//exports.setManufacturerName = function ( iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 0:; result=true;default:if (!result) break;                                                  if ( sArraySensorManufacturerName[iSensorNumber] !== undefined ){ client.changeSensorConfig( iSensorNumber, { "manufacturername": sArraySensorManufacturerName[iSensorNumber]    }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only       
//exports.setProductNam = function (       iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 0:; result=true;default:if (!result) break;                                                  if ( sArraySensorManufacturerName[iSensorNumber] !== undefined ){ client.changeSensorConfig( iSensorNumber, { "manufacturername": sArraySensorManufacturerName[iSensorNumber]    }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only       
//exports.setModelId = function (          iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 0:; result=true;default:if (!result) break;                                                  if ( sArraySensorModelId[iSensorNumber]          !== undefined ){ client.changeSensorConfig( iSensorNumber, { "modelid": sArraySensorModelId[iSensorNumber]                      }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only       
//exports.setName = function (             iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 0:; result=true;default:if (!result) break;                                                  if ( sArraySensorName[iSensorNumber]             !== undefined ){ client.changeSensorConfig( iSensorNumber, { "name": sArraySensorName[iSensorNumber]                            }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only       
//exports.setSwVersion = function (        iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 0:; result=true;default:if (!result) break;                                                  if ( sArraySensorSwVersion[iSensorNumber]        !== undefined ){ client.changeSensorConfig( iSensorNumber, { "swversion": sArraySensorSwVersion[iSensorNumber]                  }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only       
//exports.setType = function (             iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 0:; result=true;default:if (!result) break;                                                  if ( sArraySensorType[iSensorNumber]             !== undefined ){ client.changeSensorConfig( iSensorNumber, { "type": sArraySensorType[iSensorNumber]                            }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only       
//exports.setUniqueid = function (         iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 0:; result=true;default:if (!result) break;                                                  if ( sArraySensorUniqueId[iSensorNumber]         !== undefined ){ client.changeSensorConfig( iSensorNumber, { "uniqueid": sArraySensorUniqueId[iSensorNumber]                    }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only       
//exports.setRecycle = function (          iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 2:;case 9:;case 10:;case 11:; result=true;default:if (!result) break;                        if ( bArraySensorRecycle[iSensorNumber]          !== undefined ){ client.changeSensorConfig( iSensorNumber, { "recycle": bArraySensorRecycle[iSensorNumber]                      }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only       
//exports.setButtonevent = function (      iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 5:; result=true;default:if (!result) break;                                                  if ( iArraySensorButtonEvent[iSensorNumber]      !== undefined ){ client.changeSensorConfig( iSensorNumber, { "buttonevent": iArraySensorButtonEvent[iSensorNumber]              }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only Config
//exports.setLightLevel = function (       iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 8:; result=true;default:if (!result) break;                                                  if ( iArraySensorLightLevel[iSensorNumber]       !== undefined ){ client.changeSensorConfig( iSensorNumber, { "lightlevel": iArraySensorLightLevel[iSensorNumber]                }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only Config
//exports.setDark = function (             iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 8:; result=true;default:if (!result) break;                                                  if ( bArraySensorDark[iSensorNumber]             !== undefined ){ client.changeSensorConfig( iSensorNumber, { "dark": bArraySensorDark[iSensorNumber]                            }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only Config
//exports.setDaylight = function (         iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 8:; result=true;default:if (!result) break;                                                  if ( bArraySensorDaylight[iSensorNumber]         !== undefined ){ client.changeSensorConfig( iSensorNumber, { "daylight": bArraySensorDaylight[iSensorNumber]                    }, function( err, result ){ if ( err) return err; }); }; };     //Read-Only Config

  exports.setStatus = function (           iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 2:;case 9:;result=true;default:if (!result) break;                                           if ( iArraySensorStatus[iSensorNumber]           !== undefined ){ client.changeSensorState(  iSensorNumber, { "status": iArraySensorStatus[iSensorNumber]                        }, function( err, result ){ if ( err) return err; }); }; }; };     //Enabled State   
//exports.setLastupdated = function (      iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 0:; result=true;default:if (!result) break;                                                  if ( sArraySensorLastupdated[iSensorNumber]      !== undefined ){ client.changeSensorConfig( iSensorNumber, { "lastupdated": sArraySensorLastupdated[iSensorNumber]              }, function( err, result ){ if ( err) return err; }); }; }; };     //Read-Only Config
//exports.setPresence = function (         iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 7:;case 10:; case 11:; result=true;default:if (!result) break;                               if ( bArraySensorPresence[iSensorNumber]         !== undefined ){ client.changeSensorConfig( iSensorNumber, { "presence": bArraySensorPresence[iSensorNumber]                    }, function( err, result ){ if ( err) return err; }); }; }; };     //Read-Only Config
//exports.setTemperature = function (      iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 6:; result=true;default:if (!result) break;                                                  if ( iArraySensorTemperature[iSensorNumber]      !== undefined ){ client.changeSensorConfig( iSensorNumber, { "temperature": iArraySensorTemperature[iSensorNumber]              }, function( err, result ){ if ( err) return err; }); }; }; };     //Read-Only Config
  exports.setOn = function (               iSensorNumber, Value ){                                                                                                                                            if ( bArraySensorOn[iSensorNumber]               !== undefined ){ client.changeSensorState(  iSensorNumber, { "on": bArraySensorOn[iSensorNumber]                                }, function( err, result ){ if ( err) return err; }); };        //Enabled State   
  exports.setBattery = function (          iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 2:;case 6:;case 7:;case 8:;result=true;default:if (!result) break;                           if ( iArraySensorBattery[iSensorNumber]          !== undefined ){ client.changeSensorConfig( iSensorNumber, { "battery": iArraySensorBattery[iSensorNumber]                      }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
//exports.setConfigured = function (       iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 1:;result=true;default:if (!result) break;                                                   if ( bArraySensorConfigured[iSensorNumber]       !== undefined ){ client.changeSensorState(  iSensorNumber, { "configured": bArraySensorConfigured[iSensorNumber]                }, function( err, result ){ if ( err) return err; }); }; }; };      //Read-Only state 
//exports.setReachable = function (        iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 2:;case 6:;case 7:;case 8:;case 9:;case 10:;case 11:;result=true;default:if (!result) break; if ( bArraySensorReachable[iSensorNumber]        !== undefined ){ client.changeSensorState(  iSensorNumber, { "reachable": bArraySensorReachable[iSensorNumber]                  }, function( err, result ){ if ( err) return err; }); }; }; };      //Read-Only state 
  exports.setAlert = function (            iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 6:;case 7:;case 8:;result=true;default:if (!result) break;                                   if ( sArraySensorAlert[iSensorNumber]            !== undefined ){ client.changeSensorConfig( iSensorNumber, { "alert": sArraySensorAlert[iSensorNumber]                          }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
  exports.setTholdDark = function (        iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 8:;result=true;default:if (!result) break;                                                   if ( iArraySensorTholdDark[iSensorNumber]        !== undefined ){ client.changeSensorConfig( iSensorNumber, { "tholddark": iArraySensorTholdDark[iSensorNumber]                  }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
  exports.setTholdOffset = function (      iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 8:;result=true;default:if (!result) break;                                                   if ( iArraySensorTholdOffset[iSensorNumber]      !== undefined ){ client.changeSensorConfig( iSensorNumber, { "tholdoffset": iArraySensorTholdOffset[iSensorNumber]              }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
  exports.setLedindication = function (    iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 6:;case 7:;case 8:;result=true;default:if (!result) break;                                   if ( bArraySensorLedindication[iSensorNumber]    !== undefined ){ client.changeSensorConfig( iSensorNumber, { "ledindication": bArraySensorLedindication[iSensorNumber]          }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
  exports.setUsertest = function (         iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 6:;case 7:;case 8:;result=true;default:if (!result) break;                                   if ( bArraySensorUsertest[iSensorNumber]         !== undefined ){ client.changeSensorConfig( iSensorNumber, { "usertest": bArraySensorUsertest[iSensorNumber]                    }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
  exports.setSensitivity = function (      iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 7:;result=true;default:if (!result) break;                                                   if ( iArraySensorSensitivity[iSensorNumber]      !== undefined ){ client.changeSensorConfig( iSensorNumber, { "sensitivity": iArraySensorSensitivity[iSensorNumber]              }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
//exports.setSensitivitymax = function (   iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 7:;result=true;default:if (!result) break;                                                   if ( iArraySensorSensitivityMax[iSensorNumber]   !== undefined ){ client.changeSensorConfig( iSensorNumber, { "sensitivitymax": iArraySensorSensitivityMax[iSensorNumber]        }, function( err, result ){ if ( err) return err; }); }; }; };      //Read-Only state 
  exports.setSunsetoffset = function (     iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 1:;result=true;default:if (!result) break;                                                   if ( iArraySensorSunriseoffset[iSensorNumber]    !== undefined ){ client.changeSensorConfig( iSensorNumber, { "sunriseoffset": iArraySensorSunriseoffset[iSensorNumber]          }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
  exports.setUnriseoffset = function (     iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 1:;result=true;default:if (!result) break;                                                   if ( iArraySensorSunsetoffset[iSensorNumber]     !== undefined ){ client.changeSensorConfig( iSensorNumber, { "sunsetoffset": iArraySensorSunsetoffset[iSensorNumber]            }, function( err, result ){ if ( err) return err; }); }; }; };      //Enabled State   
  exports.setPending = function (          iSensorNumber, Value ){ result = false; switch (iSensorNumber) { case 6:;case 7:;case 8:;result=true;default:if (!result) break;                                   if ( sArraySensorPending[iSensorNumber]          !== undefined ){ client.changeSensorConfig( iSensorNumber, { "pending": sArraySensorPending[iSensorNumber]                      }, function( err, result ){ if ( err) return err; }); }; }; };     //Enabled State   

