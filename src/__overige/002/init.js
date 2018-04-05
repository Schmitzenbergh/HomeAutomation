#!/usr/bin/env node


var Variables = function() {
  
  this.hue = require('hue-sdk');
  this.client = new hue.Hue(require('./.credentials.json'));
  this.sensor = require('./sensor.js');
  this.light = require('./light.js');
  
  this.exec = require('child_process').exec;
  
  sVariableName = typeof sArrayVariableName !== 'undefined' ? sVariableName : "DefaultStartValue";
 
};
module.exports = Variables;






//var client = new Hue(require('./.credentials'));

//var host = "192.168.2.129",
//    username = "08a902b95915cdd9b75547cb50892dc4",
//    api;
//
//api = new HueApi(host, username);
//{
//	"host" : 192.168.0.101,
//	"user" : 
//}
//var auth = require('./auth.js');
//module.exports = auth;
//var client = new hue.Hue({
//  host: auth.host(),
//  user: auth.pass()
//});
//module.exports = client;
//var 
//module.exports = exec;
//	'use strict';
//	
//	let hue = require('hue-sdk');
//	let credentials = require('./.credentials.json');
//	
//	let client = new hue.Hue(credentials);
//	
//	module.exports = client;
//	
//	//Authentication
//	var client = new hue.Hue({
//	
//	});
//var hue = require('hue-module');
//
//hue.load({
//    "host"  : "IP Address", 
//    "key"   : "Username/Key",
//    "port"  : 80
//});
//
//hue.lights(function(lights) {
