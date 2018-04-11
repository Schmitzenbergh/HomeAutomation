#!/usr/bin/env node

var Variables = function() {

  hue = require('hue-sdk');
  client = new hue.Hue(require('./.credentials.json'));
  sensor = require('./sensor.js');
  light = require('./light.js');
  exec = require('child_process').exec;
  
  // ##############
  // #   Lights   #
  // ##############
  
  //General attributes 
  sArrayLightManufacturername = [''];   //
  sArrayLightProductname = [''];		//
  sArrayLightModelid = [''];     		//
  sArrayLightName = [''];        		//
  sArrayLightSwversion = [''];   		//
  sArrayLightType = [''];				//
  sArrayLightUniqueid = [''];			//
  bArrayLightOn = [''];					// true, false
  bArrayLightReachable = [''];			// true, false
  sArrayLightAlert = [''];				// none, select, lselect				
  sArrayLightColorMode = [''];			// hs, xy, ct
  sArrayLightEffect = [''];				// none, colorloop
  iArrayLightTransitionTime = [''];		// multiple of 100ms and defaults to 4 (400ms)
  
  //Color attributes (Currrent)			// Color attributes (New)			// Color attributes (Old)	  		// xy > ct > hs
  fArrayLightXyXCur = [''];				fArrayLightXyXNew = [''];			fArrayLightXyXOld = [''];          // 0.000 - 1.000
  fArrayLightXyYCur = [''];				fArrayLightXyYNew = [''];			fArrayLightXyYOld = [''];          // 0.000 - 1.000
  iArrayLightCtCur = [''];				iArrayLightCtNew = [''];			iArrayLightCtOld = [''];           // 153 - 500
  iArrayLightHueCur = [''];				iArrayLightHueNew = [''];			iArrayLightHueOld = [''];          // 0 - 65535
  iArrayLightSatCur = [''];				iArrayLightSatNew = [''];			iArrayLightSatOld = [''];          // 0 - 254
  iArrayLightBriCur = [''];				iArrayLightBriNew = [''];			iArrayLightBriOld = [''];          // 1-254
  iArrayLightRgbRedCur = [''];			iArrayLightRgbRedNew = [''];		iArrayLightRgbRedOld = [''];       // 0 - 254
  iArrayLightRgbGreenCur = [''];		iArrayLightRgbGreenNew = [''];		iArrayLightRgbGreenOld = [''];     // 0 - 254 
  iArrayLightRgbBlueCur = [''];			iArrayLightRgbBlueNew = [''];		iArrayLightRgbBlueOld = [''];  
  
  // ##############
  // #   Sensors  #
  // ##############
  
  sArraySensorName = [''];           
  sArraySensorType = [''];           
  sArraySensorModelId = [''];        
  sArraySensorManufacturername = [''];
  sArraySensorSwversion = [''];      
  iArraySensorButtonevent = [''];   
  bArraySensorDark = [''];          
  bArraySensorDaylight = [''];      
  sArraySensorLastupdated = [''];   
  iArraySensorLightLevel = [''];    
  bArraySensorPresence = [''];      
  iArraySensorStatus = [''];        
  iArraySensorTemperature = [''];   
  sArraySensorAlert = [''];         
  iArraySensorBattery = [''];       
  bArraySensorConfigured = [''];    
  bArraySensorLedindication = ['']; 
  bArraySensorOn = [''];            
  bArraySensorReachable = [''];     
  iArraySensorSensitivity = [''];   
  iArraySensorSensitivityMax = [''];
  iArraySensorSunsetoffset = [''];  
  iArraySensorSunriseoffset = ['']; 
  iArraySensorTholdDark = ['']; 
  iArraySensorTholdOffset = ['']; 
  bArraySensorUsertest = [''];
  
  sVariableName = typeof sVariableName !== 'undefined' ? sVariableName : "DefaultStartValue";
  
};

module.exports = Variables;

//module.exports = { 
//	Variables
//};
