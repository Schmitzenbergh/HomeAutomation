#!/usr/bin/env node

function VariablesLight(){

  process.stdout.write( '\n' + " initialize Resources-Hue-Light ");

  pathhuelightvalues = pathhuelight + './_values/';
  module.exports = require( pathhuelightvalues + './init.js');

  light = require( './light.js' );      //module.exports = light = require( pathlight + './light.js');
  //light = require( pathhuelight + './light.js');      //module.exports = light = require( pathlight + './light.js');

  /***************
  *    Lights    *
  ***************/
  iArrayLightConnected = [1, 2, 3, 4, 5, 6];
  
  //General attributes 
  sArrayLightManufacturerName = [''];   //                                                  //if ( typeof sArrayLightManufacturerName[i]     !== undefined){ process.stdout.write(" " + sArrayLightManufacturerName[i] ); };  
  sArrayLightProductname = [''];        //                                                  //if ( typeof sArrayLightProductname[i]          !== undefined){ process.stdout.write(" " + sArrayLightProductname[i]        ); }; 
  sArrayLightModelid = [''];            //                                                  //if ( typeof sArrayLightModelid[i]              !== undefined){ process.stdout.write(" " + sArrayLightModelid[i]             ); };
  sArrayLightName = ['', 'LightName'];  //                                                  //if ( typeof sArrayLightName[i]                 !== undefined){ process.stdout.write(" " + sArrayLightName[i]                ); };
  sArrayLightSwversion = [''];          //                                                  //if ( typeof sArrayLightSwversion[i]            !== undefined){ process.stdout.write(" " + sArrayLightSwversion[i]           ); };
  sArrayLightType = [''];               //                                                  //if ( typeof sArrayLightType[i]                 !== undefined){ process.stdout.write(" " + sArrayLightType[i]                ); };
  sArrayLightUniqueid = [''];           //                                                  //if ( typeof sArrayLightUniqueid[i]             !== undefined){ process.stdout.write(" " + sArrayLightUniqueid[i]            ); };
  bArrayLightOn = [''];                 // true, false                                      //if ( typeof bArrayLightOn[i]                   !== undefined){ process.stdout.write(" " + bArrayLightOn[i]                ); };
  bArrayLightReachable = [''];          // true, false                                      //if ( typeof bArrayLightReachable[i]            !== undefined){ process.stdout.write(" " + bArrayLightReachable[i]        ); }; 
  sArrayLightAlert = [''];              // none, select, lselect                            //if ( typeof sArrayLightAlert[i]                !== undefined){ process.stdout.write(" " + sArrayLightAlert[i]            ); }; 
  sArrayLightColorMode = [''];          // hs, xy, ct                                       //if ( typeof sArrayLightColorMode[i]            !== undefined){ process.stdout.write(" " + sArrayLightColorMode[i]        ); }; 
  sArrayLightEffect = [''];             // none, colorloop                                  //if ( typeof sArrayLightEffect[i]               !== undefined){ process.stdout.write(" " + sArrayLightEffect[i]            ); };
  iArrayLightTransitionTime = [''];     // multiple of 100ms and defaults to 4 (400ms)      //if ( typeof iArrayLightTransitionTime[i]       !== undefined){ process.stdout.write(" " + iArrayLightTransitionTime[i]   ); };

  
  //Color attributes (Currrent)            // Color attributes (New)            // Color attributes (Old)             // xy > ct > hs
  fArrayLightXyCur = [''];                 fArrayLightXyNew = [''];             fArrayLightXyOld = [''];          // 0.000 - 1.000          //if ( typeof fArrayLightXyCur[i]             !== undefined){ process.stdout.write(" " + fArrayLightXyCur[i]            ); };         
  fArrayLightXyXCur = [''];                fArrayLightXyXNew = [''];            fArrayLightXyXOld = [''];          // 0.000 - 1.000         //if ( typeof fArrayLightXyXCur[i]            !== undefined){ process.stdout.write(" " + fArrayLightXyXCur[i]            ); };     
  fArrayLightXyYCur = [''];                fArrayLightXyYNew = [''];            fArrayLightXyYOld = [''];          // 0.000 - 1.000         //if ( typeof fArrayLightXyYCur[i]            !== undefined){ process.stdout.write(" " + fArrayLightXyYCur[i]            ); };     
  iArrayLightCtCur = [''];                 iArrayLightCtNew = [''];             iArrayLightCtOld = [''];           // 153 - 500             //if ( typeof iArrayLightCtCur[i]             !== undefined){ process.stdout.write(" " + iArrayLightCtCur[i]            ); };     
  iArrayLightHueCur = [''];                iArrayLightHueNew = [''];            iArrayLightHueOld = [''];          // 0 - 65535             //if ( typeof iArrayLightHueCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightHueCur[i]            ); };     
  iArrayLightSatCur = [''];                iArrayLightSatNew = [''];            iArrayLightSatOld = [''];          // 0 - 254               //if ( typeof iArrayLightSatCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightSatCur[i]            ); };     
  iArrayLightBriCur = [''];                iArrayLightBriNew = [''];            iArrayLightBriOld = [''];          // 1-254                 //if ( typeof iArrayLightBriCur[i]            !== undefined){ process.stdout.write(" " + iArrayLightBriCur[i]            ); };     
  iArrayLightRgbRedCur = [''];             iArrayLightRgbRedNew = [''];         iArrayLightRgbRedOld = [''];       // 0 - 254               //if ( typeof iArrayLightRgbRedCur[i]         !== undefined){ process.stdout.write(" " + iArrayLightRgbRedCur[i]        ); };     
  iArrayLightRgbGreenCur = [''];           iArrayLightRgbGreenNew = [''];       iArrayLightRgbGreenOld = [''];     // 0 - 254               //if ( typeof iArrayLightRgbGreenCur[i]       !== undefined){ process.stdout.write(" " + iArrayLightRgbGreenCur[i]        ); }; 
  iArrayLightRgbBlueCur = [''];            iArrayLightRgbBlueNew = [''];        iArrayLightRgbBlueOld = [''];                               //if ( typeof iArrayLightRgbBlueCur[i]        !== undefined){ process.stdout.write(" " + iArrayLightRgbBlueCur[i]        ); };    
  
 }; 
VariablesLight();

//light.fetchInfo(); 


















