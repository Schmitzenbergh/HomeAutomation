#!/usr/bin/env node

debug = false;

exports.getManufacturerName = function( iLightNumber ){ client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.manufacturername === undefined ) return err;    sArrayLightManufacturerName[iLightNumber] = result.state.manufacturername;    });};    //if ( debug ){ console.log(`    Manufacturername: ${result.manufacturername}`);};});};
exports.getProductName = function( iLightNumber ){      client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.productname === undefined ) return err;         sArrayLightProductname[iLightNumber] = result.state.productname;              });};    //if ( debug ){ console.log(`    ProductName:      ${result.productname}`);};});};
exports.getModelId = function( iLightNumber ){          client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.modelid === undefined ) return err;             sArrayLightModelid[iLightNumber] = result.state.modelid;                      });};    //if ( debug ){ console.log(`    ModelId:          ${result.modelid}`);};});};
exports.getName = function( iLightNumber ){             client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.name === undefined ) return err;                sArrayLightName[iLightNumber] = result.state.name;                            });};    //if ( debug ){ console.log(`    Name:             ${result.name}`);};});};
exports.getSwVersion = function( iLightNumber ){        client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.swversion === undefined ) return err;           sArrayLightSwversion[iLightNumber] = result.state.swversion;                  });};    //if ( debug ){ console.log(`    Swversion:        ${result.swversion}`);};});};
exports.getType = function( iLightNumber ){             client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.type === undefined ) return err;                sArrayLightType[iLightNumber] = result.state.type;                            });};    //if ( debug ){ console.log(`    Type:             ${result.type}`);};});};
exports.getUniqueid = function( iLightNumber ){         client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.uniqueid === undefined ) return err;            sArrayLightUniqueid[iLightNumber] = result.state.uniqueid;                    });};    //if ( debug ){ console.log(`    Uniqueid:         ${result.uniqueid}`);};});};
                                                                                                                                                                                           
exports.getOn = function( iLightNumber ){               client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.on === undefined ) return err;            bArrayLightOn[iLightNumber] = result.state.on;                                });};    //if ( debug ){ console.log(`    On:               ${result.state.on}`);};});};
exports.getBri = function( iLightNumber ){              client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.bri === undefined ) return err;           iArrayLightBriCur[iLightNumber] = result.state.bri;                           });};    //if ( debug ){ console.log(`    Bri:              ${result.state.bri}`);};});};
exports.getHue = function( iLightNumber ){              client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.hue === undefined ) return err;           iArrayLightHueCur[iLightNumber] = result.state.hue;                           });};    //if ( debug ){ console.log(`    Hue:              ${result.state.hue}`);};});}; //10250
exports.getSat = function( iLightNumber ){              client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.sat === undefined ) return err;           iArrayLightSatCur[iLightNumber] = result.state.sat;                           });};    //if ( debug ){ console.log(`    Sat:              ${result.state.sat}`);};});};
exports.getEffect = function( iLightNumber ){           client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.effect === undefined ) return err;        sArrayLightEffect[iLightNumber] = result.state.effect;                        });};    //if ( debug ){ console.log(`    Effect:           ${result.state.effect}`);};});};
exports.getXy = function( iLightNumber ){               client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.xy === undefined ) return err;            fArrayLightXyCur[iLightNumber] = result.state.xy;                             });};    //if ( debug ){ console.log(`    Xy:               ${result.state.xy}`);};});};
exports.getXyX = function( iLightNumber ){              client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.xy[0] === undefined ) return err;         fArrayLightXyXCur[iLightNumber] = result.state.xy[0];                         });};    //if ( debug ){ console.log(`    XyX:              ${result.state.xy[0]}`);};});};
exports.getXyY = function( iLightNumber ){              client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.xy === undefined ) return err;            fArrayLightXyYCur[iLightNumber] = result.state.xy[1];                         });};    //if ( debug ){ console.log(`    XyY:              ${result.state.xy[1]}`);};});};
exports.getCt = function( iLightNumber ){               client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.ct === undefined ) return err;            iArrayLightCtCur[iLightNumber] = result.state.ct;                             });};    //if ( debug ){ console.log(`    Ct:               ${result.state.ct}`);};});};
exports.getAlert = function( iLightNumber ){            client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.alert === undefined ) return err;         sArrayLightAlert[iLightNumber] = result.state.alert;                          });};    //if ( debug ){ console.log(`    Alert:            ${result.state.alert}`);};});};
exports.getColormode = function( iLightNumber ){        client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.colormode === undefined ) return err;     sArrayLightColorMode[iLightNumber] = result.state.colormode;                  });};    //if ( debug ){ console.log(`    Colormode:        ${result.state.colormode}`);};});};
exports.getReachable = function( iLightNumber ){        client.getLight( iLightNumber, function( err, result ){ if ( err || typeof result.state.reachable === undefined ) return err;     bArrayLightReachable[iLightNumber] = result.state.reachable;                  });};    //if ( debug ){ console.log(`    Reachable:        ${result.state.reachable}`);};});};

exports.getInfo = function( iLightNumber,sValue){
            
    if ( sValue === "manufacturername" ){               light.getManufacturerName( iLightNumber );
    } else if ( sValue === "modelid" ){                 light.getModelId( iLightNumber );
    } else if ( sValue === "manufacturername" ){        light.getManufacturerName( iLightNumber );
    } else if ( sValue === "modelid" ){                 light.getModelId( iLightNumber );
    } else if ( sValue === "name" ){                    light.getName( iLightNumber );
    } else if ( sValue === "swversion" ){               light.getSwVersion( iLightNumber );
    } else if ( sValue === "type" ){                    light.getType( iLightNumber );
    } else if ( sValue === "uniqueid" ){                light.getUniqueid( iLightNumber );
        
    } else if ( sValue === "on" ){                      light.getOn( iLightNumber );
    } else if ( sValue === "bri" ){                     light.getBri( iLightNumber );            
    } else if ( sValue === "hue" ){                     light.getHue( iLightNumber );
    } else if ( sValue === "sat" ){                     light.getSat( iLightNumber );
    } else if ( sValue === "effect" ){                  light.getEffect( iLightNumber );
    } else if ( sValue === "xy" ){                      light.getXy( iLightNumber );
    } else if ( sValue === "ct" ){                      light.getCt( iLightNumber );
    } else if ( sValue === "alert" ){                   light.getAlert( iLightNumber );
    } else if ( sValue === "colormode" ){               light.getColormode( iLightNumber );
    } else if ( sValue === "reachable" ){               light.getReachable( iLightNumber );
    
    //Output all attributes found
    } else { 
        client.getLight( iLightNumber, function( err, result ){ 
    
            //if ( err) throw err;
            if ( err || result === undefined || result.state === undefined ) return err;


            
            if ( debug ){ console.log('General:'); };
            if ( typeof result.manufacturername !== undefined ){ sArrayLightManufacturerName[iLightNumber] = result.manufacturername;  };    //    if ( debug ){ console.log(`    Manufacturername: ${result.manufacturername}`)}; };
            if ( typeof result.productname !== undefined ){      sArrayLightProductname[iLightNumber] = result.productname;            };    //    if ( debug ){ console.log(`    ProductName:      ${result.productname}`)}; };
            if ( typeof result.modelid !== undefined ){          sArrayLightModelid[iLightNumber] = result.modelid;                    };    //    if ( debug ){ console.log(`    ModelId:          ${result.modelid}`)}; };
            if ( typeof result.name !== undefined ){             sArrayLightName[iLightNumber] = result.name;                          };    //    if ( debug ){ console.log(`    Name:             ${result.name}`)}; };
            if ( typeof result.swversion !== undefined ){        sArrayLightSwversion[iLightNumber] = result.swversion;                };    //    if ( debug ){ console.log(`    Swversion:        ${result.swversion}`)}; };
            if ( typeof result.type !== undefined ){             sArrayLightType[iLightNumber] = result.type;                          };    //    if ( debug ){ console.log(`    Type:             ${result.type}`)}; };
            if ( typeof result.uniqueid !== undefined ){         sArrayLightUniqueid[iLightNumber] = result.uniqueid;                  };    //    if ( debug ){ console.log(`    Uniqueid:         ${result.uniqueid}`)}; };
            
            if ( debug ){ console.log('State:'); };
            if ( typeof result.state.on !== undefined ){         bArrayLightOn[iLightNumber] = result.state.on;                        };    //    if ( debug ){ console.log('On:' + "               " + result.state.on )}; };
            if ( typeof result.state.bri !== undefined ){        iArrayLightBriCur[iLightNumber] = result.state.bri;                   };    //    if ( debug ){ console.log(`    Bri:              ${result.state.bri}`)}; };
            if ( typeof result.state.hue !== undefined ){        iArrayLightHueCur[iLightNumber] = result.state.hue;                   };    //    if ( debug ){ console.log(`    Hue:              ${result.state.hue}`)}; }; //10250
            if ( typeof result.state.sat !== undefined ){        iArrayLightSatCur[iLightNumber] = result.state.sat;                   };    //    if ( debug ){ console.log(`    Sat:              ${result.state.sat}`)}; };
            if ( typeof result.state.effect !== undefined ){     sArrayLightEffect[iLightNumber] = result.state.effect;                };    //    if ( debug ){ console.log(`    Effect:           ${result.state.effect}`)}; };
            if ( typeof result.state.xy !== undefined ){         fArrayLightXyCur[iLightNumber] = result.state.xy;
                                                                 fArrayLightXyXCur[iLightNumber] = result.state.xy[0];                            
                                                                 fArrayLightXyYCur[iLightNumber] = result.state.xy[1];                 };    //    if ( debug ){ console.log(`    Status:           ${result.state.xy}`)}; };
            if ( typeof result.state.ct !== undefined ){         iArrayLightCtCur[iLightNumber] = result.state.ct;                     };    //    if ( debug ){ console.log(`    Ct:               ${result.state.ct}`)}; };
            if ( typeof result.state.alert !== undefined ){      sArrayLightAlert[iLightNumber] = result.state.alert;                  };    //    if ( debug ){ console.log(`    Alert:            ${result.state.alert}`)}; };
            if ( typeof result.state.colormode !== undefined ){  sArrayLightColorMode[iLightNumber] = result.state.colormode;          };    //    if ( debug ){ console.log(`    Colormode:        ${result.state.colormode}`)}; };
            if ( typeof result.state.reachable !== undefined ){  bArrayLightReachable[iLightNumber] = result.state.reachable;          };    //    if ( debug ){ console.log(`    Reachable:        ${result.state.reachable}`)}; };
        });
    }
}




exports.setOn = function( iLightNumber,bValue){                 bValue = typeof bValue !== undefined ? bValue : true;  client.setLightState( iLightNumber, { "on": bValue },                    function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setOff = function( iLightNumber ){                                                                             client.setLightState( iLightNumber, { "on": false },                     function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
                                                                                                                                                                                                                                            
exports.setBri = function( iLightNumber,iValue){               iValue = typeof iValue !== undefined ? iValue : 255;    client.setLightState( iLightNumber, { "bri": iValue },                   function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setBriDec = function( iLightNumber,iValue){            iValue = typeof iValue !== undefined ? iValue : 1;      client.setLightState( iLightNumber, { "bri_inc": -iValue },              function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setBriInc = function( iLightNumber,iValue){            iValue = typeof iValue !== undefined ? iValue : 1;      client.setLightState( iLightNumber, { "bri_inc": iValue },               function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setHue = function( iLightNumber,iValue){               iValue = typeof iValue !== undefined ? iValue : 255;    client.setLightState( iLightNumber, { "hue": iValue },                   function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setHueDec = function( iLightNumber,iValue){            iValue = typeof iValue !== undefined ? iValue : 1;      client.setLightState( iLightNumber, { "hue_inc": -iValue },              function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setHueInc = function( iLightNumber,iValue){            iValue = typeof iValue !== undefined ? iValue : 1;      client.setLightState( iLightNumber, { "hue_inc": iValue },               function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setSat = function( iLightNumber,iValue){               iValue = typeof iValue !== undefined ? iValue : 255;    client.setLightState( iLightNumber, { "sat": iValue },                   function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setSatDec = function( iLightNumber,iValue){            iValue = typeof iValue !== undefined ? iValue : 1;      client.setLightState( iLightNumber, { "sat_inc": -iValue },              function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setSatInc = function( iLightNumber,iValue){            iValue = typeof iValue !== undefined ? iValue : 1;      client.setLightState( iLightNumber, { "sat_inc": iValue },               function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setEffect = function( iLightNumber,sValue){            sValue = typeof sValue !== undefined ? sValue : 'none'; client.setLightState( iLightNumber, { "effect": sValue },                function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setXy = function( iLightNumber,fValue1,fValue2){                                                               client.setLightState( iLightNumber, { "xy": [fValue1, fValue2] },        function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setXyDec = function( iLightNumber,fValue){             fValue = typeof fValue !== undefined ? fValue : 0.1;    client.setLightState( iLightNumber, { "xy_inc": [-fValue, -fValue] },    function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setXyInc = function( iLightNumber,fValue){             fValue = typeof fValue !== undefined ? fValue : 0.1;    client.setLightState( iLightNumber, { "xy_inc": [fValue, fValue] },      function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setCt = function( iLightNumber,iValue){                                                                        client.setLightState( iLightNumber, { "ct": iValue },                    function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setAlert = function( iLightNumber,sValue){             sValue = typeof sValue !== undefined ? sValue : 'none'; client.setLightState( iLightNumber, { "alert": sValue },                 function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setAlertNone = function( iLightNumber ){                                                                       client.setLightState( iLightNumber, { "alert": `none` },                 function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };        //“none” – The light is not performing an alert effect.
exports.setAlertSelect = function( iLightNumber ){                                                                     client.setLightState( iLightNumber, { "alert": `select` },               function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };        //“select” – The light is performing one breathe cycle.
exports.setAlertLSelect = function( iLightNumber ){                                                                    client.setLightState( iLightNumber, { "alert": `lselect` },              function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };        //“lselect” – The light is performing breathe cycles for 15 seconds or until an "alert": "none" command is received.
exports.setColormode = function( iLightNumber,sValue){         sValue = typeof sValue !== undefined ? sValue : 'hs';   client.setLightState( iLightNumber, { "colormode": sValue },             function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setReachable = function( iLightNumber,bValue){                                                                 client.setLightState( iLightNumber, { "reachable": bValue },             function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };
exports.setTransitionTime = function( iLightNumber,iValue){    sValue = typeof sValue !== undefined ? sValue : 1;      client.setLightState( iLightNumber, { "transitiontime": iValue },        function( err, result ){ if ( err) return err;     }); };    //    if ( debug ){ console.log(result); }; }); };



exports.setInfo = function( iLightNumber,sTarget,SomeValue){
    //Temp Cleanup
    sTarget = sTarget.toLowerCase();
    fValue = SomeValue;
    iValue = SomeValue;
    sValue = SomeValue;
    
    if ( sTarget === "on" ){                        light.setOn( iLightNumber,iValue);
        } else if ( sTarget === "bri" ){            light.setBri( iLightNumber,iValue);
        } else if ( sTarget === "hue" ){            light.setHue( iLightNumber,iValue);
        } else if ( sTarget === "sat" ){            light.setSat( iLightNumber,iValue);
        } else if ( sTarget === "effect" ){         light.setEffect( iLightNumber,sValue);
        } else if ( sTarget === "xy" ){             light.setXy( iLightNumber,fValue);
        } else if ( sTarget === "xyx" ){            light.setXyX( iLightNumber,fValue);
        } else if ( sTarget === "xyy" ){            light.setXyY( iLightNumber,fValue);
        } else if ( sTarget === "ct" ){             light.setCt( iLightNumber,iValue);
        } else if ( sTarget === "alert" ){          light.setAlert( iLightNumber,sValue);            
        } else if ( sTarget === "colormode" ){      light.setColormode( iLightNumber,iValue);
        } else if ( sTarget === "reachable" ){      light.setReachable( iLightNumber,bValue);
        } else if ( sTarget === "transitiontime" ){ light.setTransitionTime( iLightNumber,iValue);
    }
}
