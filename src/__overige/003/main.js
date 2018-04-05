#!/usr/bin/env node
// process.argv[2]
var init = require('./init.js');
//init.Variables();
init();



var myInit = function() {
    
	setTimeout(myInit, 10000);
	sensor.getLightLevel(8);
	sensor.getTemperature(6);
	sensor.getButtonevent(5);
	sensor.getLastupdated(5);

};
setTimeout(myInit, 5000);	//myInit();


//sensor.getInfo(1);
//sensor.getInfo(2);
////sensor.getInfo(5);
//sensor.getInfo(6);
//sensor.getInfo(7);
//sensor.getInfo(8);
//sensor.getInfo(9);
//sensor.getInfo(10);
//sensor.getInfo(11);

//light.getInfo(iLightNumber,'manufacturername')
//light.getInfo(iLightNumber,'modelid')
//light.getInfo(iLightNumber,'name')
//light.getInfo(iLightNumber,'swversion')
//light.getInfo(iLightNumber,'type')
//light.getInfo(iLightNumber,'uniqueid')
//light.getInfo(iLightNumber,'on')
//light.getInfo(iLightNumber,'bri')
//light.getInfo(iLightNumber,'hue')
//light.getInfo(iLightNumber,'sat')
//light.getInfo(iLightNumber,'effect')
//light.getInfo(iLightNumber,'xy')
//light.getInfo(iLightNumber,'ct')
//light.getInfo(iLightNumber,'alert')
//light.getInfo(iLightNumber,'colormode')
//light.getInfo(iLightNumber,'reachable')

//light.getManufacturerName(iLightNumber);
//light.getModelId(iLightNumber);
//light.getName(iLightNumber);
//light.getSwVersion(iLightNumber);
//light.getType(iLightNumber);
//light.getUniqueid(iLightNumber);
//light.getOn(iLightNumber);
//light.getBri(iLightNumber);
//light.getHue(iLightNumber);
//light.getSat(iLightNumber);
//light.getEffect(iLightNumber);
//light.getXy(iLightNumber);
//light.getCt(iLightNumber);
//light.getAlert(iLightNumber);
//light.getColormode(iLightNumber);
//light.getReachable(iLightNumber);

//light.setOn(iLightNumber);
//light.setOn(iLightNumber,false);
//light.setOff(iLightNumber);

//light.setBri(iLightNumber,10);
//light.setBriDec(iLightNumber);
//light.setBriDec(iLightNumber,10);
//light.setBriInc(iLightNumber);

//light.getInfo(1,"type");
//light.getInfo(5);

//light.getInfo(4,"on");



//console.log(sVariableName);




