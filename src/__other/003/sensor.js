#!/usr/bin/env node

exports.getName = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.name}`);});};
exports.getType= function(iSensorNumber) { 					client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.type}`);});};
exports.getModelId = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.modelid}`);});};
exports.getManufacturername = function(iSensorNumber) { 	client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.manufacturername}`);});};
exports.getSwversion = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.swversion}`);});};
exports.getUniqueid = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.uniqueid}`);});};
exports.getRecycle = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.recycle}`);});};

exports.getButtonevent = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.buttonevent}`);});};
exports.getLightLevel = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.lightlevel}`);});};
exports.getDark = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.dark}`);});};
exports.getDaylight = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.daylight}`);});};
exports.getStatus = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.status}`);});};
exports.getLastupdated = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.lastupdated}`);});};
exports.getPresence = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.presence}`);});};
exports.getTemperature = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.temperature}`);});};

exports.getOn = function(iSensorNumber) { 					client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.on}`);});};
exports.getBattery = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.battery}`);});};
exports.getConfigured = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.configured}`);});};
exports.getReachable = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.reachable}`);});};
exports.getAlert = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.alert}`);});};
exports.getTholdDark = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.tholddark}`);});};
exports.getTholdOffset = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.tholdoffset}`);});};
exports.getLedindication = function(iSensorNumber) { 		client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.ledindication}`);});};
exports.getUsertest = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.usertest}`);});};
exports.getSensitivity = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.sensitivity}`);});};
exports.getSensitivitymax = function(iSensorNumber) { 		client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.sensitivitymax}`);});};
exports.getSunsetoffset = function(iSensorNumber) { 		client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.sunsetoffset}`);});};
exports.getUnriseoffset = function(iSensorNumber) { 		client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.sunriseoffset}`);});};
exports.getPending = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.pending}`);});};

exports.getInfo = function(iSensorNumber,sValue) {
	if ( sValue === "manufacturername" ){			sensor.getManufacturerName(iSensorNumber);
	} else if ( sValue === "modelid" ){				sensor.getModelId(iSensorNumber);
	} else if ( sValue === "manufacturername" ){	sensor.getManufacturerName(iSensorNumber);
	} else if ( sValue === "modelid" ){				sensor.getModelId(iSensorNumber);
	} else if ( sValue === "name" ){				sensor.getName(iSensorNumber);
	} else if ( sValue === "swversion" ){			sensor.getSwVersion(iSensorNumber);
	} else if ( sValue === "type" ){				sensor.getType(iSensorNumber);
	} else if ( sValue === "uniqueid" ){			sensor.getUniqueid(iSensorNumber);
	//Output all attributes found
	} else { 
		client.getSensor(iSensorNumber, function (err, result) { 
		
			//if (err) throw err;
	
			console.log('General:' + iSensorNumber);			//if (typeof query !== 'undefined' && query !== null)
			if ( typeof result.name !== 'undefined'){ 					console.log(`    Name:             ${result.name}`)};
			if ( typeof result.type !== 'undefined'){ 					console.log(`    Type:             ${result.type}`)};
			if ( typeof result.modelid !== 'undefined'){ 				console.log(`    ModelId:          ${result.modelid}`)};
			if ( typeof result.manufacturername !== 'undefined'){ 		console.log(`    Manufacturername: ${result.manufacturername}`)};
			if ( typeof result.swversion !== 'undefined'){				console.log(`    Swversion:        ${result.swversion}`)};
			if ( typeof result.uniqueid !== 'undefined'){ 				console.log(`    Uniqueid:         ${result.uniqueid}`)};
			if ( typeof result.recycle !== 'undefined'){				console.log(`    Recycle:          ${result.recycle}`)};
	
			console.log('State:');
			if ( typeof result.state.buttonevent !== 'undefined'){		console.log(`    Buttonevent:      ${result.state.buttonevent}`)};
			if ( typeof result.state.lightlevel !== 'undefined'){		console.log(`    LightLevel:       ${result.state.lightlevel}`)}; //10250
			if ( typeof result.state.dark !== 'undefined'){ 			console.log(`    Dark:             ${result.state.dark}`)};
			if ( typeof result.state.daylight !== 'undefined'){ 		console.log(`    Daylight:         ${result.state.daylight}`)};
			if ( typeof result.state.status !== 'undefined'){			console.log(`    Status:           ${result.state.status}`)};
			if ( typeof result.state.lastupdated !== 'undefined'){ 		console.log(`    Lastupdated:      ${result.state.lastupdated}`)};
			if ( typeof result.state.presence !== 'undefined'){			console.log(`    Presence:         ${result.state.presence}`)};
			if ( typeof result.state.temperature !== 'undefined'){		console.log(`    Temperature:      ${result.state.temperature}`)};
			
			console.log('Config:');
			if ( typeof result.config.on !== 'undefined'){ 				console.log(`    On:               ${result.config.on}`)};
			if ( typeof result.config.battery  !== 'undefined'){ 		console.log(`    Battery:          ${result.config.battery}`)};
			if ( typeof result.config.configured !== 'undefined'){ 		console.log(`    Configured:       ${result.config.configured}`)};
			if ( typeof result.config.reachable !== 'undefined'){ 		console.log(`    Reachable:        ${result.config.reachable}`)};
			if ( typeof result.config.alert !== 'undefined'){ 			console.log(`    Alert:            ${result.config.alert}`)};
			if ( typeof result.config.tholddark !== 'undefined'){ 		console.log(`    TholdDark:        ${result.config.tholddark}`)};
			if ( typeof result.config.tholdoffset !== 'undefined'){ 	console.log(`    TholdOffset:      ${result.config.tholdoffset}`)};
			if ( typeof result.config.ledindication !== 'undefined'){ 	console.log(`    Ledindication:    ${result.config.ledindication}`)};
			if ( typeof result.config.usertest !== 'undefined'){ 		console.log(`    Usertest:         ${result.config.usertest}`)};
			if ( typeof result.config.sensitivity !== 'undefined'){		console.log(`    Sensitivity:      ${result.config.sensitivity}`)};
			if ( typeof result.config.sensitivitymax !== 'undefined'){ 	console.log(`    Sensitivitymax:   ${result.config.sensitivitymax}`)};
			if ( typeof result.config.sunsetoffset !== 'undefined'){ 	console.log(`    Sunsetoffset:     ${result.config.sunsetoffset}`)};
			if ( typeof result.config.sunriseoffset !== 'undefined'){ 	console.log(`    Unriseoffset:     ${result.config.sunriseoffset}`)};
			if ( typeof result.config.pending !== 'undefined'){ 		console.log(`    Pending:          ${result.config.pending}`)};
		});
	}
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

//exports.setInfo = function(iSensorNumber,sTarget,SomeValue) {
//	//Temp Cleanup
//	sTarget = sTarget.toLowerCase();
//	fValue = SomeValue;
//	iValue = SomeValue;
//	sValue = SomeValue;
//	
//	if ( sTarget === "on" ){						
//		} else if ( sTarget === "battery" ){		
//		} else if ( sTarget === "configured" ){		
//		} else if ( sTarget === "reachable" ){		
//		} else if ( sTarget === "alert" ){			
//		} else if ( sTarget === "tholddark" ){		
//		} else if ( sTarget === "tholdoffset" ){	
//		} else if ( sTarget === "ledindication" ){	
//		} else if ( sTarget === "usertest" ){		
//		} else if ( sTarget === "sensitivity" ){	
//		} else if ( sTarget === "sensitivitymax" ){	
//		} else if ( sTarget === "sunsetoffset" ){	
//		} else if ( sTarget === "sunriseoffset" ){	
//		} else if ( sTarget === "pending" ){		
//	}
//}
//
//exports.setName = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.name}`);});};
//exports.setType= function(iSensorNumber) { 					client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.type}`);});};
//exports.setModelId = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.modelid}`);});};
//exports.setManufacturername = function(iSensorNumber) { 	client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.manufacturername}`);});};
//exports.setSwversion = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.swversion}`);});};
//exports.setUniqueid = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.uniqueid}`);});};
//exports.setRecycle = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.recycle}`);});};
//
//exports.setButtonevent = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.buttonevent}`);});};
//exports.setLightLevel = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.lightlevel}`);});};
//exports.setDark = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.dark}`);});};
//exports.setDaylight = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.daylight}`);});};
//exports.setStatus = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.status}`);});};
//exports.setLastupdated = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.lastupdated}`);});};
//exports.setPresence = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.presence}`);});};
//exports.setTemperature = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.temperature}`);});};
//
//exports.setOn = function(iSensorNumber) { 					client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.on}`);});};
//exports.setBattery = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.battery}`);});};
//exports.setConfigured = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.configured}`);});};
//exports.setReachable = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.reachable}`);});};
//exports.setAlert = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.alert}`);});};
//exports.setTholdDark = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.tholddark}`);});};
//exports.setTholdOffset = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.tholdoffset}`);});};
//exports.setLedindication = function(iSensorNumber) { 		client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.ledindication}`);});};
//exports.setUsertest = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.usertest}`);});};
//exports.setSensitivity = function(iSensorNumber) { 			client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.sensitivity}`);});};
//exports.setSensitivitymax = function(iSensorNumber) { 		client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.sensitivitymax}`);});};
//exports.setSunsetoffset = function(iSensorNumber) { 		client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.sunsetoffset}`);});};
//exports.setUnriseoffset = function(iSensorNumber) { 		client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.sunriseoffset}`);});};
//exports.setPending = function(iSensorNumber) { 				client.getSensor(iSensorNumber, function (err, result) { if (err) throw err;	console.log(`${result.config.pending}`);});};




