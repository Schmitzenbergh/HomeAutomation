#!/usr/bin/env node

var HueApi = require("node-hue-api").HueApi;
var ipHost = "192.168.0.101", 
	username = "SdIlXGmbkKDtkdIQGNudKHYZ8LGmouMFi0v5AO9t", 
	api = new HueApi(ipHost, username);

var iLightNumber;
var iLightAmount = 6 + 1;

var iSensorNumber;
var iSensorAmount = 11 + 1;

var arrLightStatusR = [];			//255
var arrLightStatusG = [];			//255
var arrLightStatusB = [];			//255
var arrLightStatusOn = [];			//true
var arrLightStatusBri = [];			//255
var arrLightStatusHue = [];			//65535
var arrLightStatusSat = [];			//255
var arrLightStatusEffect = [];		//"none"
var arrLightStatusX = [];			//1.000
var arrLightStatusy = [];			//1.000
var arrLightStatusCt = [];			//255
var arrLightStatusAlert = [];		//"none"
var arrLightStatusColorMode = [];	//"xy"
var arrLightStatusReachable = [];	//true

var arrSensorStatusDaylight = [];
var arrSensorStatusOn = [];
var arrSensorStatusConfigured = [];
var arrSensorStatusSunriseOffset = [];
var arrSensorStatusSunsetOffset = [];
var arrSensorStatusSunsetName = [];
var arrSensorStatusSunsetType = [];

const cursor = {
    Save: "\033[s",                   // Save cursor position
    Restore: "\033[u",                // Restore cursor position
    Erase: "\033[K",                  // Erase to end of line
    Clear: "\033[2J",                 // Clear the screen, move to (0,0)
    Move: {
        Up: "\033[1A",                // Move the cursor up 1 lines
        Down: "\033[1B",              // Move the cursor down 1 lines
        Forward: "\033[1C",           // Move the cursor forward 1 columns
        Backward: "\033[1D",          // Move the cursor backward 1 columns
        Position1: "\033[20;1H",      // \033[<L>;<C>H Position the Cursor, puts the cursor at line 1 and column 1)
        Position2: "\033[1;1f"        // \033[<L>;<C>f Position the Cursor, puts the cursor at line 1 and column 1)
									//	(puts the cursor at line L and column C)
    }
};

var displayResult = function(result) {
    console.log(JSON.stringify(result, null, 2));
};

var iRefreshCounter = 0;
setInterval(apiStatusGet, 1000);

function apiStatusGet(){

	iRefreshCounter++;
	
	if ( iRefreshCounter == 5){
		//process.stdout.write(cursor.Clear);
		iRefreshCounter = 0;
	}

	//process.stdout.write(cursor.Move.Position2);

	function apiStatusGetBridge(){
		
		// --------------------------
		// Using a callback
		api.config(function(err, bridgeconfig) {
			if (err) throw err;
			displayResult(bridgeconfig.name);
			displayResult(bridgeconfig.zigbeechannel);
			displayResult(bridgeconfig.bridgeid);
			displayResult(bridgeconfig.mac);
			displayResult(bridgeconfig.dhcp);
			displayResult(bridgeconfig.ipaddress);
			displayResult(bridgeconfig.netmask);
			displayResult(bridgeconfig.gateway);
			displayResult(bridgeconfig.proxyaddress);
			displayResult(bridgeconfig.proxyport);
			displayResult(bridgeconfig.UTC);
			displayResult(bridgeconfig.localtime);
			displayResult(bridgeconfig.timezone);
			displayResult(bridgeconfig.modelid);
			displayResult(bridgeconfig.datastoreversion);
			displayResult(bridgeconfig.swversion);
			displayResult(bridgeconfig.apiversion);
			displayResult(bridgeconfig.swupdate.updatestate);
			displayResult(bridgeconfig.swupdate.checkforupdate);
			displayResult(bridgeconfig.swupdate.devicetypes.bridges);
			displayResult(bridgeconfig.swupdate.devicetypes.lights);
			displayResult(bridgeconfig.swupdate.devicetypes.sensors);
			displayResult(bridgeconfig.swupdate.url);
			displayResult(bridgeconfig.swupdate.text);
			displayResult(bridgeconfig.swupdate.notify);
			displayResult(bridgeconfig.linkbutton);
			displayResult(bridgeconfig.portalservices);
			displayResult(bridgeconfig.portalconnection);
			displayResult(bridgeconfig.portalstate.signedon);
			displayResult(bridgeconfig.portalstate.incoming);
			displayResult(bridgeconfig.portalstate.outgoing);
			displayResult(bridgeconfig.portalstate.communication);
			displayResult(bridgeconfig.factorynew);
			displayResult(bridgeconfig.replacesbridgeid);
			displayResult(bridgeconfig.backup.status);
			displayResult(bridgeconfig.backup.errorcode);
			//displayResult(bridgeconfig.whitelist);

			//	displayResult(bridgeconfig.presence);
			//	displayResult(bridgeconfig.lightlevel);	
			//	displayResult(bridgeconfig.dark);
			//	displayResult(bridgeconfig.daylight);			
			//	displayResult(bridgeconfig.temperature);
			//	displayResult(bridgeconfig.lastupdated);
			//	displayResult(bridgeconfig.on);			
			//	displayResult(bridgeconfig.battery);
			//	displayResult(bridgeconfig.reachable);
			//	displayResult(bridgeconfig.alert);			
			//	displayResult(bridgeconfig.ledindication);
			//	displayResult(bridgeconfig.usertest);
			//	displayResult(bridgeconfig.duration);			
			//	displayResult(bridgeconfig.sensitivity);
			//	displayResult(bridgeconfig.sensitivitymax);
			//	displayResult(bridgeconfig.tholddark);
			//	displayResult(bridgeconfig.tholddaylight);
	
		});
	};
	//apiStatusGetBridge();			//Run function above
		
	function apiStatusGetLights(){

		var myCallback = function(data) {}; //With callback
		var fetchStatusLightGetAll = function(iLightNumber,callback) {
		
			api.lightStatusWithRGB(iLightNumber, function(err, result) {
			
				if (err) { throw err; }
				
				arrLightStatusR[iLightNumber] = result.state.rgb[0];
				arrLightStatusG[iLightNumber] = result.state.rgb[1];
				arrLightStatusB[iLightNumber] = result.state.rgb[2];
				arrLightStatusOn[iLightNumber] = result.state.on;
				arrLightStatusBri[iLightNumber] = result.state.bri;
				arrLightStatusHue[iLightNumber] = result.state.hue;
				arrLightStatusSat[iLightNumber] = result.state.sat;
				arrLightStatusEffect[iLightNumber] = result.state.effect;
				arrLightStatusX[iLightNumber] = result.state.xy[0];
				arrLightStatusy[iLightNumber] = result.state.xy[1];
				arrLightStatusCt[iLightNumber] = result.state.ct;
				arrLightStatusAlert[iLightNumber] = result.state.alert;
				arrLightStatusColorMode[iLightNumber] = result.state.colormode;
				arrLightStatusReachable[iLightNumber] = result.state.reachable;
			
			});
		
		};
		
		///Start
		for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
			fetchStatusLightGetAll(iLightNumber, myCallback);
		};

		process.stdout.write('\n' + "LightNumber:" + '\t');
		
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write(iLightNumber + '\t');
			};
		
		process.stdout.write('\n' + "------------");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + "------ ");
			};
		
		process.stdout.write('\n' + "R: " + '\t');
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusR[iLightNumber]);
			};
		
		process.stdout.write('\n' + "G: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusG[iLightNumber]);
			};
		
		process.stdout.write('\n' + "B: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusB[iLightNumber]);
			};
		
		process.stdout.write('\n' + "On: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusOn[iLightNumber]);
			};
		
		process.stdout.write('\n' + "Bri: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusBri[iLightNumber]);
			};
		
		process.stdout.write('\n' + "Hue: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusHue[iLightNumber]);
			};
		
		process.stdout.write('\n' + "Sat: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusSat[iLightNumber]);
			};
		
		process.stdout.write('\n' + "Effect: ");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusEffect[iLightNumber]);
			};
		
		process.stdout.write('\n' + "X: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusX[iLightNumber]);
			};
		
		process.stdout.write('\n' + "y: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusy[iLightNumber]);
			};
		
		process.stdout.write('\n' + "Ct: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusCt[iLightNumber]);
			};
		
		process.stdout.write('\n' + "Alert: " + "\t");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusAlert[iLightNumber]);
			};
		
		process.stdout.write('\n' + "ColorMode: ");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusColorMode[iLightNumber]);
			};
		
		process.stdout.write('\n' + "Reachable: ");
			for ( iLightNumber = 1; iLightNumber < iLightAmount; iLightNumber++){
				process.stdout.write('\t' + arrLightStatusReachable[iLightNumber]);
			};
	
		process.stdout.write('\n');

	};	
	//apiStatusGetLights();			//Run function above

	function apiStatusGetSensors(){


		//var myCallback = function(data) {}; //With callback
		//var fetchStatusSensorGetAll = function(iSensorNumber,callback) {
		//
		//	api.lightStatusWithRGB(iLightNumber, function(err, result) {







	
		// --------------------------
		// Using a callback
		api.getSensors(function(err, result) {
			if (err) throw err;
			//console.log(JSON.stringify(result, null, 2));
			
			//console.log(JSON.stringify(result.1.state.daylight, null, 2));
			//displayResult(results.state);
			//process.stdout.write('\n' + results);
			console.log(JSON.stringify(result.config, null, 2));
		});
	};
	apiStatusGetSensors();			//Run function above
	
	
	//	function apiStatusGetSensors(){
	//		
	//		var myCallback = function(data) {	}; //With callback		
	//		var fetchStatusSensorGetAll = function(iSensorNumber,callback) {
	//		
	//			//process.stdout.write('\n' + "a");
	//			
	//			//api.getSensors(iSensorNumber, function(err, result) {
	//			api.getConfig(function(err, result) {
	//				if (err) { throw err; }
	//				
	//				process.stdout.write('\n' + result);
	//				
	//				//process.stdout.write('\n' + result.state.daylight);
	//				//process.stdout.write('\n' + "test1");
	//				//arrSensorStatusDaylight[iSensorNumber] = result.state.daylight;
	//				
	//				//arrSensorStatusOn[iSensorNumber] = result.state.;
	//				//arrSensorStatusConfigured[iSensorNumber] = result.state.;
	//				//arrSensorStatusSunriseOffset[iSensorNumber] = result.state.;
	//				//arrSensorStatusSunsetOffset[iSensorNumber] = result.state.offset;
	//				//arrSensorStatusSunsetName[iSensorNumber] = result.state.name;
	//				//arrSensorStatusSunsetType[iSensorNumber] = result.state.type;
	//				//arrLightStatusR[iSensorNumber] = result.state.rgb[0];
	//				//arrLightStatusG[iLightNumber] = result.state.rgb[1];
	//				//arrLightStatusB[iLightNumber] = result.state.rgb[2];
	//				//arrLightStatusOn[iLightNumber] = result.state.on;
	//				//arrLightStatusBri[iLightNumber] = result.state.bri;
	//				//arrLightStatusHue[iLightNumber] = result.state.hue;
	//				//arrLightStatusSat[iLightNumber] = result.state.sat;
	//				//arrLightStatusEffect[iLightNumber] = result.state.effect;
	//				//arrLightStatusX[iLightNumber] = result.state.xy[0];
	//				//arrLightStatusy[iLightNumber] = result.state.xy[1];
	//				//arrLightStatusCt[iLightNumber] = result.state.ct;
	//				//arrLightStatusAlert[iLightNumber] = result.state.alert;
	//				//arrLightStatusColorMode[iLightNumber] = result.state.colormode;
	//				//arrLightStatusReachable[iLightNumber] = result.state.reachable;
	//			
	//			});
	//		}
	//	
	//		//	for ( iSensorNumber = 1; iSensorNumber < iSensorAmount; iSensorNumber++){
	//		//		fetchStatusSensorGetAll(iSensorNumber, myCallback);
	//		//	};
	//	
	//			fetchStatusSensorGetAll(iSensorNumber, myCallback);
	//		
	//		
	//			process.stdout.write('\n' + "SensorNumber:" + '\t');
	//			
	//				for ( iSensorNumber = 1; iSensorNumber < iSensorAmount; iSensorNumber++){
	//					process.stdout.write(iSensorNumber + '\t');
	//				};
	//			
	//			process.stdout.write('\n' + "------------");
	//				for ( iSensorNumber = 1; iSensorNumber < iSensorAmount; iSensorNumber++){
	//					process.stdout.write('\t' + "------ ");
	//				};
	//		
	//			process.stdout.write('\n' + "DayLight: ");
	//				for ( iSensorNumber = 1; iSensorNumber < iSensorAmount; iSensorNumber++){
	//					process.stdout.write('\t' + arrSensorStatusDaylight[iSensorNumber]);
	//				};
	//		}
	//	}
};

