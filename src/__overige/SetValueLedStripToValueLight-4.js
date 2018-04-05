#!/usr/bin/env node
console.log("\x1b[0m");

var debug = process.argv[2]

var hue = require("node-hue-api");
var HueApi = require("node-hue-api").HueApi;
var hostname = "192.168.0.101",
username = "SdIlXGmbkKDtkdIQGNudKHYZ8LGmouMFi0v5AO9t",
api = new HueApi(hostname, username);

var exec = require('child_process').exec;

// Variables for Colored messages
const colors = {
	//General
    Reset: "\x1b[0m", Bright: "\x1b[1m",
    Dim: "\x1b[2m",
    Underscore: "\x1b[4m",
    Blink: "\x1b[5m",
    Reverse: "\x1b[7m",
    Hidden: "\x1b[8m",
	
	//Font Color
    Black: "\x1b[30m",   	fgBlack: "\x1b[30m",		fgDarkGray: "\x1b[39m",
    Red: "\x1b[31m",     	fgRed: "\x1b[31m",          fgLightRed: "\x1b[91m",
    Green: "\x1b[32m",   	fgGreen: "\x1b[32m",        fgLightGreen: "\x1b[92m",
    Yellow: "\x1b[33m",  	fgYellow: "\x1b[33m",       fgLightYellow: "\x1b[93m",
    Blue: "\x1b[34m",    	fgBlue: "\x1b[34m",         fgLightBlue: "\x1b[94m",
    Magenta: "\x1b[35m", 	fgMagenta: "\x1b[35m",      fgLightMagenta: "\x1b[95m",
    Cyan: "\x1b[36m",    	fgCyan: "\x1b[36m",         fgLightCyan: "\x1b[96m",
    LightGray: "\x1b[37m",	fgLightGray: "\x1b[37m",    fgWhite: "\x1b[97m",
    Crimson: "\x1b[38m", 	fgCrimson: "\x1b[38m",
							fgDefault: "\x1b[39m",
					
	//Background Color
    bgBlack: "\x1b[40m",	bgDarkGray: "\x1b[100m",
    bgRed: "\x1b[41m",      bgLightRed: "\x1b[101m",
    bgGreen: "\x1b[42m",    bgLightGreen: "\x1b[102m",
    bgYellow: "\x1b[43m",   bgLightYellow: "\x1b[103m",
    bgBlue: "\x1b[44m",     bgLightBlue: "\x1b[104m",
    bgMagenta: "\x1b[45m",  bgLightMagenta: "\x1b[105m",
    bgCyan: "\x1b[46m",     bgLightCyan: "\x1b[106m",
    bgWhite: "\x1b[47m",
    bgCrimson: "\x1b[48m",
	bgDefault: "\x1b[49m",

};

var cLogSTDout = function(msg) { process.stdout.write(msg); };

function cLogSTDColor(color = colors.Reset, msg) {
    cLogSTDout(color + msg + colors.Reset);
};

var iTickrateDefault = 75;
const iTickrateLimit = 60000;
var iTickrate = iTickrateDefault;

var stepNumber = 0;

// LIGHT SETTINGS (General)
const colorName = [colors.Red, colors.Green, colors.Blue];
       

// LIGHT SETTINGS (Currrent)			// LIGHT SETTINGS (New)					// LIGHT SETTINGS (Old)
var aRgbCur = [255, 255, 255];			var aRgbNew = [255, 255, 255];			var aRgbOld = [0, 0, 0];
var iBriCur = 0;						var iBriNew = 0;						
var bStatusCur = false;					var bStatusNew = false;					
var iTransitionTimeCur = 4;				var iTransitionTimeNew = 4;				
var iHueCur = 0;						var iHueNew = 0;						
var iSatCur = 0;						var iSatNew = 0;						
var sEffectCur = "";					var sEffectNew = "";					
var aXyCur = [0, 0];					var aXyNew = [0.5, 0.5];				
var iCtCur = 0;							var iCtNew = 0;							
var sAlertCur = "";						var sAlertNew = "";						
var sColorModeCur = "";					var sColorModeNew = "";					
var bReachableCur = true;				var bReachableNew = true;				



// console.log
//var cLog = function(msg) { console.log(msg); };
//var cLogColor = function(msg) { console.log(msg + "" + colors.Reset);};
//var cLogJSON = function(msg) { console.log(JSON.stringify(msg, null, 2)); };
//var cLogJSONParseObj = function(obj) { console.log(JSON.parse(JSON.stringify(obj)));};
// process.stdout.write
//var cLogSTDoutColor = function(msg) { process.stdout.write(msg + "" + colors.Reset); };
//var cLogSTDoutJSON = function(msg) { process.stdout.write(JSON.stringify(msg, null, 2)); };

var myInit = function() {
    setTimeout(myInit, iTickrate);
	statusLightGetRGB(1);
	LightTransitionDifferenceFade();
}; 
setTimeout(myInit, iTickrate);	//myInit();

function initVarRgb(){
    for ( i = 0; i < aRgbCur.length; i++ ){ 
        aRgbCur[i] = aRgbNew[i];
    }
}

function initVarXy(){
    for ( i = 0; i < aRgbCur.length; i++ ){ 
        aXyCur[i] = aXyNew[i];
    }
}

function tickrateIncrease(iValue = 1){
	if ( iTickrateLimit >= ( iTickrate + iValue ) ){
		iTickrate += iValue;
	}	
}

function tickrateDecrease(iValue = 100){
	if ( iTickrateDefault <= ( iTickrate - iValue ) ){
		iTickrate -= iValue;
	}	
}

function statusLightGetRGB(iLightNumber){
	process.stdout.write(".");	
			
    var myCallback = function(data) {}; //With callback
    var fetchStatusLightGetRGB = function(iLightNumber,callback) {
        api.lightStatusWithRGB(iLightNumber, function(err, result) {
	
            if (err) {
				process.stdout.write(" error ")
				tickrateIncrease();
				iTickrateDefault++;
				throw err;
			}
			
			for (rgb = 0; rgb < 3; rgb++){ 
				if ( aRgbNew[rgb] != result.state.rgb[rgb]){
					aRgbNew[rgb] = result.state.rgb[rgb];
					tickrateDecrease();
				} else {
					tickrateIncrease();
				}
			}

        });
    };
    fetchStatusLightGetRGB(iLightNumber, myCallback);
}

function LightTransitionDifferenceFade(){
	const stepValue = [8, 4, 2, 1];
	var aDifference = [0, 0, 0]
	var stepError = [false, false, false];
	
	stepNumber = 0;

	while ( stepNumber < stepValue.length ){
		for (rgb = 0; rgb < 3; rgb++){
			if ( aRgbCur[rgb] > aRgbNew[rgb] ){
				aDifference[rgb] = aRgbCur[rgb] - aRgbNew[rgb];
			} else {
				aDifference[rgb] = aRgbNew[rgb] - aRgbCur[rgb];
			}
			if ( aDifference[rgb] >= stepValue[stepNumber] ){

				stepError[rgb] = false;
				LightTransitionDifferenceSwitch(rgb,stepValue[stepNumber])
			} else {
				stepError[rgb] = true;
			}
			if ( aDifference[rgb] < stepValue[stepNumber] || aRgbCur[rgb] == aRgbNew[rgb]){
				stepError[rgb] = true;
			}
			if ( stepError[0] == true ){
				if ( stepError[1] == true ){
					if ( stepError[2] == true ){
						stepNumber++;
						stepError = [false, false, false];
					}
				}
			}
		}
	}
	cLogSTDout(" Done! with ms:" + ( iTickrate - iTickrateDefault ) + " iTickrateDefault:" + iTickrateDefault + '\n' );
	
	bRgbDiffStatus = false;
}

function LightTransitionDifferenceSwitch(rgb,iLightTransitionStep = 1){
	if( aRgbCur[rgb] > aRgbNew[rgb] ){
		cLogSTDColor( colorName[rgb], "-" );
		LightTransitionDown(rgb, iLightTransitionStep);
	} else if ( aRgbCur[rgb] < aRgbNew[rgb] ){
		cLogSTDColor( colorName[rgb], "+" );
		LightTransitionUp(rgb, iLightTransitionStep);
	}
}

function LightTransitionDown(rgb,iLightTransitionStep = 1){
	aRgbCur[rgb] -= iLightTransitionStep;
	lightTransitionExec(rgb,iLightTransitionStep);
}

function LightTransitionUp(rgb,iLightTransitionStep = 1){
	aRgbCur[rgb] += iLightTransitionStep;
	lightTransitionExec(rgb, iLightTransitionStep);
}

function lightTransitionExec(rgb,iLightTransitionStep = 1){
    const GPIOPos = [17, 22, 25];
	exec("/usr/local/bin/pigs p " + GPIOPos[rgb] + " " + aRgbCur[rgb]);		
	aRgbOld[rgb] = aRgbCur[rgb];
}


