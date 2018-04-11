#!/usr/bin/env node

var hue = require('hue-sdk');


var exec = require('child_process').exec;

function discover(){
	hue.discover(function (err, result) {
	if (err)
		throw err;
	console.log(result);
	});
}

var credentials = require('./.credentials.js');

	//Authentication
	var client = new hue.Hue({
	  host: '192.168.0.101',
	  user: 'SdIlXGmbkKDtkdIQGNudKHYZ8LGmouMFi0v5AO9t'
	});


//setInterval(DogetLight, 1000);

//function DogetLight(){
//
//	setLight(1);
//	setLight(2);
//	setLight(3);
//	setLight(4);
//	setLight(5);
//	setLight(6);
//}

function getLight(iLightNumber){
	client.getLight(iLightNumber, function (err, result) { 
	//if (err) throw err;
	
	//console.log(`Manufacturername: ${result.manufacturername}`);
	//console.log(`ModelId:          ${result.modelid}`);	
	console.log(`Name:             ${result.name}`);
	//console.log(`Swversion:        ${result.swversion}`);
	//console.log(`Type:             ${result.type}`);
	//console.log(`Uniqueid:         ${result.uniqueid}`);

	//console.log(`On:               ${result.state.on}`);
	//console.log(`Brightness:       ${result.state.bri}`);
	//console.log(`Hue:              ${result.state.hue}`);
	//console.log(`Saturation:       ${result.state.sat}`);
	//console.log(`Effect:           ${result.state.effect}`);
	//console.log(`X/Y:              ${result.state.xy}`);
	//console.log(`X/Y:              ${result.state.xy[0]}, ${result.state.xy[1]}`);
	//console.log(`Color Temp:       ${result.state.ct}`);
	//console.log(`Alert:            ${result.state.alert}`);			
	//console.log(`Color mode:       ${result.state.colormode}`);
	//console.log(`Reachable:        ${result.state.reachable}`);

	});
}
getLight(1);



function setLight(iLightNumber){
	
	iLightNumber = typeof iLightNumber !== 'undefined' ? iLightNumber : 1;

	//client.setLightState(iLightNumber, { "on": true }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "bri": 254 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "hue": 65535 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "sat": 254 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "effect": "colorloop" }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "effect": "none" }, function (err, result) { if (err) throw err;	console.log(result); });
	
	//client.setLightState(iLightNumber, { "xy":[0.4000,0.4000] }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "xy[1]": 254 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "ct": 254 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "alert": 254 }, function (err, result) { if (err) throw err;	console.log(result); });
	
	//client.setLightState(iLightNumber, { "alert": "none" }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "alert": "select" }, function (err, result) { if (err) console.log(err);	console.log(result); });
	//client.setLightState(iLightNumber, { "alert": "lselect" }, function (err, result) { if (err) throw err;	console.log(result); });

	//client.setLightState(iLightNumber, { "colormode": "hs" }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "colormode": "xy" }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "colormode": "ct" }, function (err, result) { if (err) throw err;	console.log(result); });

	//client.setLightState(iLightNumber, { "reachable": true }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "transitiontime": 1 }, function (err, result) { if (err) throw err;	console.log(result); });

	//client.setLightState(iLightNumber, { "bri_inc": 1 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "hue_inc": 1 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "sat_inc": 1 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "xy_inc": [0.1, 0.1] }, function (err, result) { if (err) throw err;	console.log(result); });

	//client.setLightState(iLightNumber, { "bri_inc": -1 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "hue_inc": -1 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "sat_inc": -1 }, function (err, result) { if (err) throw err;	console.log(result); });
	//client.setLightState(iLightNumber, { "xy_inc": [-0.1, -0.1] }, function (err, result) { if (err) throw err;	console.log(result); });
	
}


//var hue = require('hue-module');
//
//hue.load({
//    "host"  : "IP Address", 
//    "key"   : "Username/Key",
//    "port"  : 80
//});
//
//hue.lights(function(lights) {
//	for (i in lights) {
//		if (lights.hasOwnProperty(i)) {
//			hue.change(lights[i].set({"on": true, "rgb":[0,255,255]}));
//        }
//    }
//});
