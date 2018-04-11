#!/usr/bin/env node


var sArrayName = "test";           
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

exports.getInfo = function(iSensorNumber) {
	client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;
	
	//console.log(result);
	//console.log(result.state);
	//console.log(result.config);
	
	console.log(`Name:             ${result.name}`);
	//console.log(`Type:             ${result.type}`);
	//console.log(`ModelId:          ${result.modelid}`);
	//console.log(`Manufacturername: ${result.manufacturername}`);
	//console.log(`Swversion:        ${result.swversion}`);
	
	console.log(`Buttonevent:      ${result.state.buttonevent}`);
	//console.log(`Dark:             ${result.state.dark}`);
	//console.log(`Daylight:         ${result.state.daylight}`);
	//console.log(`Lastupdated:      ${result.state.lastupdated}`);
	//console.log(`LightLevel:       ${result.state.lightlevel}`); //10250
	//console.log(`Presence:         ${result.state.presence}`);
	//console.log(`Status:           ${result.state.status}`);
	//console.log(`Temperature:      ${result.state.temperature}`);

	//console.log(`Alert:            ${result.config.alert}`);
	//console.log(`Battery:          ${result.config.battery}`);
	//console.log(`Configured:       ${result.config.configured}`);
	//console.log(`Ledindication:    ${result.config.ledindication}`);
	//console.log(`On:               ${result.config.on}`);
	//console.log(`Reachable:        ${result.config.reachable}`);
	//console.log(`Sensitivity:      ${result.config.sensitivity}`);
	//console.log(`Sensitivitymax:   ${result.config.sensitivitymax}`);
	//console.log(`Sunsetoffset:     ${result.config.sunsetoffset}`);
	//console.log(`Unriseoffset:     ${result.config.sunriseoffset}`);
	//console.log(`Usertest:         ${result.config.usertest}`);

	});
}



function changeSensorConfig(iSensorNumber,bOn,iSunriseoffset,iSunsetoffset){

	bOn = typeof bOn !== 'undefined' ? bOn : true;
	iSunriseoffset = typeof iSunriseoffset !== 'undefined' ? iSunriseoffset : 0;
	iSunsetoffset = typeof iSunsetoffset !== 'undefined' ? iSunsetoffset : 0;
	
	client.changeSensorConfig(iSensorNumber, {"on": bOn, "sunriseoffset": iSunriseoffset, "sunsetoffset": iSunsetoffset}, function (err, result) { 
	if (err) 
		throw err;
	console.log(result);
	});
}
