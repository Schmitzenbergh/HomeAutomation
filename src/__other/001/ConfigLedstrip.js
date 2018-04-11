#!/usr/bin/env node
//!!!! Draait alleen op Raspberry Pi


var exec = require('child_process').exec;


exec("/usr/local/bin/pigs p " + 17 + " " + 255);
exec("/usr/local/bin/pigs p " + 22 + " " + 255);
exec("/usr/local/bin/pigs p " + 25 + " " + 255);



//	//setInterval(initWaitForUpdate, tickrate);
//	
//	setLight(17,255);
//	setLight(22,255);
//	setLight(25,255);
//	
//	function getLight(iLightNumber){
//	
//	}
//	
//	function setLight(iGPIOPos, iValue){
//		exec("/usr/local/bin/pigs p " + iGPIOPos + " " + iValue);		
//	}



