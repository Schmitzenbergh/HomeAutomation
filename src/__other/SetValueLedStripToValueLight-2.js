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

//Function for Colored messages
function cLogSTDColor(color, msg) { 

    var sItem = "";
    
    switch (color) {
        //General            
        case "Reset": sItem = "" + colors.Reset; break;
        case "Bright": sItem = "" + colors.Bright; break;
        case "Dim": sItem = "" + colors.Dim; break;
        case "Underscore": sItem = "" + colors.Underscore; break;
        case "Blink": sItem = "" + colors.Blink; break;
        case "Reverse": sItem = "" + colors.Reverse; break;
        case "Hidden": sItem = "" + colors.Hidden; break;

        //Foreground
        case "Default": sItem = "" + colors.Default; break;
        case "Black": sItem = "" + colors.Black; break;
        case "Red": sItem = "" + colors.Red; break;
        case "Green": sItem = "" + colors.Green; break;
        case "Yellow": sItem = "" + colors.Yellow; break;
        case "Blue": sItem = "" + colors.Blue; break;
        case "Magenta": sItem = "" + colors.Magenta; break;
        case "Cyan": sItem = "" + colors.Cyan; break;
        case "LightRed": sItem = "" + colors.LightRed; break;
        case "LightGreen": sItem = "" + colors.LightGreen; break;
        case "LightYellow": sItem = "" + colors.LightYellow; break;
        case "LightBlue": sItem = "" + colors.LightBlue; break;
        case "LightMagenta": sItem = "" + colors.LightMagenta; break;
        case "LightCyan": sItem = "" + colors.LightCyan; break;		
		case "LightGray": sItem = "" + colors.LightGray; break;
		case "DarkGray": sItem = "" + colors.DarkGray; break;
		case "White": sItem = "" + colors.White; break;
        case "Crimson": sItem = "" + colors.Crimson; break;
		
        //Background
        case "bgBlack": sItem = "" + colors.bgBlack; break;
        case "bgRed": sItem = "" + colors.bgRed; break;
        case "bgGreen": sItem = "" + colors.bgGreen; break;
        case "bgYellow": sItem = "" + colors.bgYellow; break;
        case "bgBlue": sItem = "" + colors.bgBlue; break;
        case "bgMagenta": sItem = "" + colors.bgMagenta; break;
        case "bgCyan": sItem = "" + colors.bgCyan; break;
        case "bgWhite": sItem = "" + colors.bgWhite; break;
        case "bgCrimson": sItem = "" + colors.bgCrimson; break;
		case "bgDefault": sItem = "" + colors.bgDefault; break;
		case "bgWhite": sItem = "" + colors.bgWhite; break;
		
        default:
    };
    
    cLogStdout(sItem + msg + colors.Reset);

};

// SYSTEM
//var bMotionDetected = 0;
//var iCounterUpdate = 0;


// SYSTEM
var iCounterAction = 0;
var iCounterUpdate = 0;
var iWaitForUpdate_LightGetRGB = 0;
var iTickrate = 100;
var iTickrateLimit = 10000;
var scriptLock = false;
var stepNumber = 0;

// LIGHT SETTINGS (General)
const colorCode = [colors.Red, colors.Green, colors.Blue];
const colorName = ["Red", "Green", "Blue"];
var iLightTransitionStep = 1;
var bRgbDiffStatus=true;         

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
var cLog = function(msg) { console.log(msg); };
var cLogColor = function(msg) { console.log(msg + "" + colors.Reset);};
var cLogJSON = function(msg) { console.log(JSON.stringify(msg, null, 2)); };
var cLogJSONParseObj = function(obj) { console.log(JSON.parse(JSON.stringify(obj)));};

// process.stdout.write
var cLogStdout = function(msg) { process.stdout.write(msg); };
var cLogStdoutColor = function(msg) { process.stdout.write(msg + "" + colors.Reset); };
var cLogStdoutJSON = function(msg) { process.stdout.write(JSON.stringify(msg, null, 2)); };

WaitForUpdate();

function init(){
}

function initVarRgb(){
    for (i = 0; i < aRgbCur.length; i++){ 
        aRgbCur[i] = aRgbNew[i];
    }
}

function initVarXy(){
    for (i = 0; i < aRgbCur.length; i++){ 
        aXyCur[i] = aXyNew[i];
    }
}

function tickrateIncrease(iValue){
	if ( iTickrateLimit >= ( iTickrate + iValue ){
		iTickrate += iValue;
	}	
}

function tickrateDecrease(iValue){
	if (iTickrate.default <= ( iTickrate - iValue )){
		iTickrate -= iValue;
	}	
}

function WaitForUpdate(){
	if (scriptLock == true){ 
		cLogStdout("!");
		return;
	} else {
		scriptLock = true;
		//setInterval(initWaitForUpdate, iTickrate);
		setInterval(initWaitForUpdate, 500);
		//cLogStdout(" tickrate:" + iTickrate);
		
	}
}

function initWaitForUpdate(){
	if (scriptLock == false){ 
		cLogStdout(" ! ERROR ! ");
		return;
	} else {
		scriptLock = true;
	}
	statusLightGetRGB(1);

	if ( bRgbDiffStatus == false) {
		iWaitForUpdate_LightGetRGB++;
		if (iWaitForUpdate_LightGetRGB < 2){
		} else {
			if (iTickrate < iTickrateLimit){
				iTickrate += 1; 
			}
		}
	} else if (bRgbDiffStatus == true) {	
		if (iTickrate > iTickrate.default && iTickrate > 5){
			iTickrate -= 1;
		}
		iWaitForUpdate_LightGetRGB = 0;
		iCounterUpdate++; 
		cLogStdout('\n');
		main();
	}
	
	if ( iTickrate == iTickrateLimit ){
		iTickrate = iTickrate.default;
	};
}

function main(){
	iCounterAction++;
	LightTransitionDifferenceFade();
	bRgbDiffStatus = false;
}

//function statusLightGet(iLightNumber){
//    var myCallback = function(data) {}; //With callback
//    var fetchStatusLightGet = function(iLightNumber,callback) {
//        api.lightStatus(iLightNumber, function(err, result) {
//            if (err) throw err; 
//			//callback(JSON.stringify(result, null, 2));
//			myCallback( result );
//
//        });
//    };
//    fetchStatusLightGet(iLightNumber, myCallback);
//}

function statusLightGetRGB(iLightNumber){
	//catch(err) {
	//	//console.log(e);
	//	// expected output: "Parameter is not a number!"
	//}

    var myCallback = function(data) {}; //With callback
    var fetchStatusLightGetRGB = function(iLightNumber,callback) {
        api.lightStatusWithRGB(iLightNumber, function(err, result) {
	
            if (err) {
				process.stdout.write(" error ")
				if (iTickrate < ( iTickrateLimit - 5 ) ){
					iTickrate += 5;
				}
				throw err;
			}
			
			process.stdout.write(".");
			
			if (iTickrate > ( iTickrate.default + 50 ) ){
				iTickrate -= 50;
			}			
			//callback(JSON.stringify(result.state.rgb, null, 2));
			if ( iWaitForUpdate_LightGetRGB == 0 ){	};
			
			for (rgb = 0; rgb < 3; rgb++){ 
				if ( aRgbNew[rgb] != result.state.rgb[rgb]){
					aRgbNew[rgb] = result.state.rgb[rgb];
					bRgbDiffStatus=true;
				} else {
					bRgbDiffStatus=false;
				}
			}
        });
    };
    fetchStatusLightGetRGB(iLightNumber, myCallback);
}

function LightTransitionDifferenceFade(){
	aDifference = [0, 0, 0]
	var stepError = [false, false, false];
	const stepValue = [ 7, 3, 1];
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
		cLogStdout(" Done! with ms:" + iTickrate );
}

function LightTransitionDifferenceSwitch(rgb,iLightTransitionStep){
	if( aRgbCur[rgb] > aRgbNew[rgb] ){
		cLogSTDColor( colorName[rgb], "-" );
		LightTransitionDown(rgb, iLightTransitionStep);
	} else if ( aRgbCur[rgb] < aRgbNew[rgb] ){
		cLogSTDColor( colorName[rgb], "+" );
		LightTransitionUp(rgb, iLightTransitionStep);
	}
}

function LightTransitionDown(rgb,iLightTransitionStep){
	aRgbCur[rgb] -= iLightTransitionStep;
	lightTransitionExec(rgb,iLightTransitionStep);
}

function LightTransitionUp(rgb,iLightTransitionStep){
	aRgbCur[rgb] += iLightTransitionStep;
	lightTransitionExec(rgb, iLightTransitionStep);
}

function lightTransitionExec(rgb,iLightTransitionStep){
    const GPIOPos = [17, 22, 25];
	exec("/usr/local/bin/pigs p " + GPIOPos[rgb] + " " + aRgbCur[rgb]);		
	aRgbOld[rgb] = aRgbCur[rgb];
}


