#!/usr/bin/env node

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
var iArrayRgbBlueCur = [];			var iArrayRgbBlueNew = [];		var iArrayRgbBlueOld = [];      // 0 - 254 

exports.getInfo = function(iLightNumber,sValue) {
	
	iLightNumber = typeof iLightNumber !== 'undefined' ? iLightNumber : 1;
	sValue = typeof sValue !== 'undefined' ? sValue : "manufacturername";
			
	client.getLight(iLightNumber, function (err, result) { 
	
		//if (err) throw err;
		
		if ( sValue.toLowerCase() === "manufacturername" ){
			console.log(`manufacturername: ${result.manufacturername}`);
			
		} else if ( sValue.toLowerCase() === "modelid" ){
			console.log(`modelid:          ${result.modelid}`);	
			
		} else if ( sValue.toLowerCase() === "name" ){
			console.log(`name:             ${result.name}`);
			
		} else if ( sValue.toLowerCase() === "swversion" ){
			console.log(`swversion:        ${result.swversion}`);
			
		} else if ( sValue.toLowerCase() === "type" ){
			console.log(`type:             ${result.type}`);
			
		} else if ( sValue.toLowerCase() === "uniqueid" ){
			console.log(`uniqueid:         ${result.uniqueid}`);
			
		} else if ( sValue.toLowerCase() === "on" ){
			console.log(`on:               ${result.state.on}`);
			
		} else if ( sValue.toLowerCase() === "bri" ){
			console.log(`bri:       ${result.state.bri}`);
			
		} else if ( sValue.toLowerCase() === "hue" ){
			console.log(`hue:              ${result.state.hue}`);
			
		} else if ( sValue.toLowerCase() === "sat" ){
			console.log(`sat:       ${result.state.sat}`);
			
		} else if ( sValue.toLowerCase() === "effect" ){
			console.log(`effect:           ${result.state.effect}`);
			
		} else if ( sValue.toLowerCase() === "xy" ){
			console.log(`xy:              ${result.state.xy}`);
			
		} else if ( sValue.toLowerCase() === "xy2" ){
			console.log(`xy2:              ${result.state.xy[0]}, ${result.state.xy[1]}`);
			
		} else if ( sValue.toLowerCase() === "ct" ){
			console.log(`ct:       ${result.state.ct}`);
			
		} else if ( sValue.toLowerCase() === "alert" ){
			console.log(`alert:            ${result.state.alert}`);
			
		} else if ( sValue.toLowerCase() === "colormode" ){
			console.log(`colormode:       ${result.state.colormode}`);
			
		} else if ( sValue.toLowerCase() === "reachable" ){
			console.log(`reachable:        ${result.state.reachable}`);
		}
	});
}

exports.setOn = function(iLightNumber,bValue){
	client.setLightState(iLightNumber, { "on": bValue }, function (err, result) { if (err) throw err;	console.log(result);});
};

exports.setBri = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "bri": iValue }, function (err, result) { if (err) throw err;	console.log(result);});
};

exports.setBriDec = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "bri_inc": -iValue }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setBriInc = function(iLightNumber,bValue){
	client.setLightState(iLightNumber, { "bri_inc": iValue }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setHue = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "hue": iValue }, function (err, result) { if (err) throw err;	console.log(result);});
};

exports.setHueDec = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "hue_inc": -iValue }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setHueInc = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "hue_inc": iValue }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setSat = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "sat": iValue }, function (err, result) { if (err) throw err;	console.log(result);});
};

exports.setSatDec = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "sat_inc": -iValue }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setSatInc = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "sat_inc": iValue }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setEffect = function(iLightNumber,sValue){
	client.setLightState(iLightNumber, { "effect": sValue }, function (err, result) { if (err) throw err;	console.log(result);});
	//client.setLightState(iLightNumber, { "effect": "colorloop" }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "effect": "none" }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setXy = function(iLightNumber,bValue){
	client.setLightState(iLightNumber, { "on": bValue }, function (err, result) { if (err) throw err;	console.log(result);});
	//client.setLightState(iLightNumber, { "xy":[0.4000,0.4000] }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "xy[1]": 254 }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setXyDec = function(iLightNumber,fValue){
	client.setLightState(iLightNumber, { "xy_inc": [-fValue, -fValue] }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setXyInc = function(iLightNumber,fValue){
	client.setLightState(iLightNumber, { "xy_inc": [fValue, fValue] }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setCt = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "ct": iValue }, function (err, result) { if (err) throw err;	console.log(result);});
};

exports.setAlert = function(iLightNumber,sValue){
	client.setLightState(iLightNumber, { "alert": sValue }, function (err, result) { if (err) throw err;	console.log(result);});
	//client.setLightState(iLightNumber, { "alert": "none" }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "alert": "select" }, function (err, result) { if (err) console.log(err);	console.log(result); });
	//client.setLightState(iLightNumber, { "alert": "lselect" }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setColormode = function(iLightNumber,sValue){
	client.setLightState(iLightNumber, { "colormode": sValue }, function (err, result) { if (err) throw err;	console.log(result);});
	//client.setLightState(iLightNumber, { "colormode": "hs" }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "colormode": "xy" }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "colormode": "ct" }, function (err, result) { if (err) throw err;	console.log(result); });
};

exports.setReachable = function(iLightNumber,bValue){
	client.setLightState(iLightNumber, { "reachable": bValue }, function (err, result) { if (err) throw err;	console.log(result); });
};

//function setTransitionTime(iLightNumber,iValue){
exports.setTransitionTime = function(iLightNumber,iValue){
	client.setLightState(iLightNumber, { "transitiontime": iValue }, function (err, result) { if (err) throw err;	console.log(result); });
};







