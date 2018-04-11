#!/usr/bin/env node


//var colorCodes = {
//
//  back  : "#fff",
//  front : "#888",
//  side  : "#369"
//
//};


// ##############
// #   Lights   #
// ##############

//module.exports = hue;

//General attributes 
var sArrayManufacturername = [];	//
var sArrayProductname = [];			//
var sArrayModelid = [];     		//
var sArrayName = [];        		//
var sArraySwversion = [];   		//
var sArrayType = [];				//
var sArrayUniqueid = [];			//
var bArrayOn = [];					// true, false
var bArrayReachable = [];			// true, false
var sArrayAlert = [];				// none, select, lselect				
var sArrayColorMode = [];			// hs, xy, ct
var sArrayEffect = [];				// none, colorloop
var iArrayTransitionTime = [];		// multiple of 100ms and defaults to 4 (400ms)

//Color attributes (Currrent)		// Color attributes (New)		// Color attributes (Old)		// xy > ct > hs
var fArrayXyXCur = [];				var fArrayXyXNew = [];			var fArrayXyXOld = [];          // 0.000 - 1.000
var fArrayXyYCur = [];				var fArrayXyYNew = [];			var fArrayXyYOld = [];          // 0.000 - 1.000
var iArrayCtCur = [];				var iArrayCtNew = [];			var iArrayCtOld = [];           // 153 - 500
var iArrayHueCur = [];				var iArrayHueNew = [];			var iArrayHueOld = [];          // 0 - 65535
var iArraySatCur = [];				var iArraySatNew = [];			var iArraySatOld = [];          // 0 - 254
var iArrayBriCur = [];				var iArrayBriNew = [];			var iArrayBriOld = [];          // 1-254
var iArrayRgbRedCur = [];			var iArrayRgbRedNew = [];		var iArrayRgbRedOld = [];       // 0 - 254
var iArrayRgbGreenCur = [];			var iArrayRgbGreenNew = [];		var iArrayRgbGreenOld = [];     // 0 - 254 
var iArrayRgbBlueCur = [];			var iArrayRgbBlueNew = [];		var iArrayRgbBlueOld = [];  

var sArrayName = [];           
var sArrayType = [];           
var sArrayModelId = [];        
var sArrayManufacturername = [];
var sArraySwversion = [];      
var iArrayButtonevent = [];   
var bArrayDark = [];          
var bArrayDaylight = [];      
var sArrayLastupdated = [];   
var iArrayLightLevel = [];    
var bArrayPresence = [];      
var iArrayStatus = [];        
var iArrayTemperature = [];   
var sArrayAlert = [];         
var iArrayBattery = [];       
var bArrayConfigured = [];    
var bArrayLedindication = []; 
var bArrayOn = [];            
var bArrayReachable = [];     
var iArraySensitivity = [];   
var iArraySensitivityMax = [];
var iArraySunsetoffset = [];  
var iArraySunriseoffset = []; 
var iArrayTholdDark = []; 
var iArrayTholdOffset = []; 
var bArrayUsertest = [];


// ##############
// #   Lights   #
// ##############


var sArrayName = [];           
var sArrayType = [];           
var sArrayModelId = [];        
var sArrayManufacturername = [];
var sArraySwversion = [];      
var iArrayButtonevent = [];   
var bArrayDark = [];          
var bArrayDaylight = [];      
var sArrayLastupdated = [];   
var iArrayLightLevel = [];    
var bArrayPresence = [];      
var iArrayStatus = [];        
var iArrayTemperature = [];   
var sArrayAlert = [];         
var iArrayBattery = [];       
var bArrayConfigured = [];    
var bArrayLedindication = []; 
var bArrayOn = [];            
var bArrayReachable = [];     
var iArraySensitivity = [];   
var iArraySensitivityMax = [];
var iArraySunsetoffset = [];  
var iArraySunriseoffset = []; 
var iArrayTholdDark = []; 
var iArrayTholdOffset = []; 
var bArrayUsertest = [];


