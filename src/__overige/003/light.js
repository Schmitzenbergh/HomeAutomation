#!/usr/bin/env node

exports.getManufacturerName = function(iLightNumber) {		client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.manufacturername}`);});};
exports.getModelId = function(iLightNumber) {				client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.modelid}`);});};
exports.getName = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.name}`);});};
exports.getSwVersion = function(iLightNumber) {				client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.swversion}`);});};
exports.getType = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.type}`);});};
exports.getUniqueid = function(iLightNumber) {				client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.uniqueid}`);});};

exports.getOn = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.on}`);});};
exports.getBri = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.bri}`);});};
exports.getHue = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.hue}`);});};
exports.getSat = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.sat}`);});};
exports.getEffect = function(iLightNumber) {				client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.effect}`);});};
exports.getXy = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.xy}`);});};
exports.getXyX = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.xy[0]}`);});};
exports.getXyY = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.xy[1]}`);});};
exports.getCt = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.ct}`);});};
exports.getAlert = function(iLightNumber) {					client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.alert}`);});};
exports.getColormode = function(iLightNumber) {				client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.colormode}`);});};
exports.getReachable = function(iLightNumber) {				client.getLight(iLightNumber, function (err, result) { if (err) throw err;	console.log(`${result.state.reachable}`);});};

exports.getInfo = function(iLightNumber,sValue) {
			
	if ( sValue === "manufacturername" ){					light.getManufacturerName(iLightNumber);
	} else if ( sValue === "modelid" ){					light.getModelId(iLightNumber);
	} else if ( sValue === "manufacturername" ){		light.getManufacturerName(iLightNumber);
	} else if ( sValue === "modelid" ){					light.getModelId(iLightNumber);
	} else if ( sValue === "name" ){					light.getName(iLightNumber);
	} else if ( sValue === "swversion" ){				light.getSwVersion(iLightNumber);
	} else if ( sValue === "type" ){					light.getType(iLightNumber);
	} else if ( sValue === "uniqueid" ){				light.getUniqueid(iLightNumber);
	
	} else if ( sValue === "on" ){						light.getOn(iLightNumber);
	} else if ( sValue === "bri" ){						light.getBri(iLightNumber);			
	} else if ( sValue === "hue" ){						light.getHue(iLightNumber);
	} else if ( sValue === "sat" ){						light.getSat(iLightNumber);
	} else if ( sValue === "effect" ){					light.getEffect(iLightNumber);
	} else if ( sValue === "xy" ){						light.getXy(iLightNumber);
	} else if ( sValue === "ct" ){						light.getCt(iLightNumber);
	} else if ( sValue === "alert" ){					light.getAlert(iLightNumber);
	} else if ( sValue === "colormode" ){ 				light.getColormode(iLightNumber);
	} else if ( sValue === "reachable" ){ 				light.getReachable(iLightNumber);
	
	//Output all attributes found
	} else { 
		client.getLight(iLightNumber, function (err, result) { 
	
			if (err) throw err;
	
			console.log('General:');
			if ( typeof result.name !== 'undefined'){ 					console.log(`    Name:             ${result.name}`)};
			if ( typeof result.type !== 'undefined'){ 					console.log(`    Type:             ${result.type}`)};
			if ( typeof result.modelid !== 'undefined'){ 				console.log(`    ModelId:          ${result.modelid}`)};
			if ( typeof result.manufacturername !== 'undefined'){ 		console.log(`    Manufacturername: ${result.manufacturername}`)};
			if ( typeof result.swversion !== 'undefined'){				console.log(`    Swversion:        ${result.swversion}`)};
			if ( typeof result.uniqueid !== 'undefined'){ 				console.log(`    Uniqueid:         ${result.uniqueid}`)};
			if ( typeof result.recycle !== 'undefined'){				console.log(`    Recycle:          ${result.recycle}`)};
			
			console.log('State:');
			if ( typeof result.state.on !== 'undefined'){ 				console.log(`    On:               ${result.state.on}`)};
			if ( typeof result.state.bri !== 'undefined'){				console.log(`    Bri:              ${result.state.bri}`)};
			if ( typeof result.state.hue !== 'undefined'){				console.log(`    Hue:              ${result.state.hue}`)}; //10250
			if ( typeof result.state.sat !== 'undefined'){ 				console.log(`    Sat:              ${result.state.sat}`)};
			if ( typeof result.state.effect !== 'undefined'){ 			console.log(`    Effect:           ${result.state.effect}`)};
			if ( typeof result.state.xy !== 'undefined'){				console.log(`    Status:           ${result.state.xy}`)};
			if ( typeof result.state.ct !== 'undefined'){ 				console.log(`    Ct:               ${result.state.ct}`)};
			if ( typeof result.state.alert !== 'undefined'){			console.log(`    Alert:            ${result.state.alert}`)};
			if ( typeof result.state.colormode !== 'undefined'){		console.log(`    Colormode:        ${result.state.colormode}`)};
			if ( typeof result.state.reachable !== 'undefined'){		console.log(`    Reachable:        ${result.state.reachable}`)};
		});
	}
}




exports.setOn = function(iLightNumber,bValue){ 				bValue = typeof bValue !== 'undefined' ? bValue : true; 	client.setLightState(iLightNumber, { "on": bValue }, function (err, result) { if (err) throw err; console.log(result); });};
exports.setOff = function(iLightNumber){ 																				client.setLightState(iLightNumber, { "on": false }, function (err, result) { if (err) throw err; console.log(result); });};
	
exports.setBri = function(iLightNumber,iValue){ 			iValue = typeof iValue !== 'undefined' ? iValue : 255; 		client.setLightState(iLightNumber, { "bri": iValue },					function (err, result) { if (err) throw err; console.log(result); });};
exports.setBriDec = function(iLightNumber,iValue){			iValue = typeof iValue !== 'undefined' ? iValue : 1;		client.setLightState(iLightNumber, { "bri_inc": -iValue },				function (err, result) { if (err) throw err; console.log(result); });};
exports.setBriInc = function(iLightNumber,iValue){			iValue = typeof iValue !== 'undefined' ? iValue : 1;		client.setLightState(iLightNumber, { "bri_inc": iValue },				function (err, result) { if (err) throw err; console.log(result); });};
exports.setHue = function(iLightNumber,iValue){   			iValue = typeof iValue !== 'undefined' ? iValue : 255;		client.setLightState(iLightNumber, { "hue": iValue },					function (err, result) { if (err) throw err; console.log(result); });};
exports.setHueDec = function(iLightNumber,iValue){			iValue = typeof iValue !== 'undefined' ? iValue : 1;		client.setLightState(iLightNumber, { "hue_inc": -iValue },				function (err, result) { if (err) throw err; console.log(result); });};
exports.setHueInc = function(iLightNumber,iValue){			iValue = typeof iValue !== 'undefined' ? iValue : 1;		client.setLightState(iLightNumber, { "hue_inc": iValue },				function (err, result) { if (err) throw err; console.log(result); });};
exports.setSat = function(iLightNumber,iValue){   			iValue = typeof iValue !== 'undefined' ? iValue : 255;		client.setLightState(iLightNumber, { "sat": iValue },					function (err, result) { if (err) throw err; console.log(result); });};
exports.setSatDec = function(iLightNumber,iValue){			iValue = typeof iValue !== 'undefined' ? iValue : 1;		client.setLightState(iLightNumber, { "sat_inc": -iValue },				function (err, result) { if (err) throw err; console.log(result); });};
exports.setSatInc = function(iLightNumber,iValue){			iValue = typeof iValue !== 'undefined' ? iValue : 1;		client.setLightState(iLightNumber, { "sat_inc": iValue },				function (err, result) { if (err) throw err; console.log(result); });};
exports.setEffect = function(iLightNumber,sValue){			sValue = typeof sValue !== 'undefined' ? sValue : 'none';	client.setLightState(iLightNumber, { "effect": sValue },				function (err, result) { if (err) throw err; console.log(result); });};
exports.setXy = function(iLightNumber,fValue1,fValue2){																	client.setLightState(iLightNumber, { "xy": [fValue1, fValue2] },		function (err, result) { if (err) throw err; console.log(result); });};
exports.setXyDec = function(iLightNumber,fValue){ 			fValue = typeof fValue !== 'undefined' ? fValue : 0.1;		client.setLightState(iLightNumber, { "xy_inc": [-fValue, -fValue] },	function (err, result) { if (err) throw err; console.log(result); });};
exports.setXyInc = function(iLightNumber,fValue){ 			fValue = typeof fValue !== 'undefined' ? fValue : 0.1;		client.setLightState(iLightNumber, { "xy_inc": [fValue, fValue] },		function (err, result) { if (err) throw err; console.log(result); });};
exports.setCt = function(iLightNumber,iValue){    																		client.setLightState(iLightNumber, { "ct": iValue },					function (err, result) { if (err) throw err; console.log(result);});};
exports.setAlert = function(iLightNumber,sValue){   		sValue = typeof sValue !== 'undefined' ? sValue : 'none';	client.setLightState(iLightNumber, { "alert": sValue },					function (err, result) { if (err) throw err; console.log(result);});};
exports.setAlertNone = function(iLightNumber){																			client.setLightState(iLightNumber, { "alert": `none` },					function (err, result) { if (err) throw err; console.log(result);});};		//“none” – The light is not performing an alert effect.
exports.setAlertSelect = function(iLightNumber){																		client.setLightState(iLightNumber, { "alert": `select` },				function (err, result) { if (err) throw err; console.log(result);});};		//“select” – The light is performing one breathe cycle.
exports.setAlertLSelect = function(iLightNumber){																		client.setLightState(iLightNumber, { "alert": `lselect` },				function (err, result) { if (err) throw err; console.log(result);});};		//“lselect” – The light is performing breathe cycles for 15 seconds or until an "alert": "none" command is received.
exports.setColormode = function(iLightNumber,sValue){		sValue = typeof sValue !== 'undefined' ? sValue : 'hs';		client.setLightState(iLightNumber, { "colormode": sValue },				function (err, result) { if (err) throw err; console.log(result);});};
exports.setReachable = function(iLightNumber,bValue){																	client.setLightState(iLightNumber, { "reachable": bValue },				function (err, result) { if (err) throw err; console.log(result); });};
exports.setTransitionTime = function(iLightNumber,iValue){	sValue = typeof sValue !== 'undefined' ? sValue : 1;		client.setLightState(iLightNumber, { "transitiontime": iValue },		function (err, result) { if (err) throw err; console.log(result); });};



exports.setInfo = function(iLightNumber,sTarget,SomeValue) {
	//Temp Cleanup
	sTarget = sTarget.toLowerCase();
	fValue = SomeValue;
	iValue = SomeValue;
	sValue = SomeValue;
	
	if ( sTarget === "on" ){						light.setOn(iLightNumber,iValue);
		} else if ( sTarget === "bri" ){			light.setBri(iLightNumber,iValue);
		} else if ( sTarget === "hue" ){			light.setHue(iLightNumber,iValue);
		} else if ( sTarget === "sat" ){			light.setSat(iLightNumber,iValue);
		} else if ( sTarget === "effect" ){			light.setEffect(iLightNumber,sValue);
		} else if ( sTarget === "xy" ){				light.setXy(iLightNumber,fValue);
		} else if ( sTarget === "xyx" ){			light.setXyX(iLightNumber,fValue);
		} else if ( sTarget === "xyy" ){			light.setXyY(iLightNumber,fValue);
		} else if ( sTarget === "ct" ){				light.setCt(iLightNumber,iValue);
		} else if ( sTarget === "alert" ){			light.setAlert(iLightNumber,sValue);			
		} else if ( sTarget === "colormode" ){		light.setColormode(iLightNumber,iValue);
		} else if ( sTarget === "reachable" ){		light.setReachable(iLightNumber,bValue);
		} else if ( sTarget === "transitiontime" ){	light.setTransitionTime(iLightNumber,iValue);
	}
}
