#!/usr/bin/env node

function VariablesConfig(){
  
  process.stdout.write( '\n' + " initialize Config ");
  
  //  sVariableName = typeof sVariableName !== undefined ? sVariableName : "DefaultStartValue";
  
  fs = require('fs');
  debug = false;
  //retValueContent = ['reserved'];   
};
VariablesConfig();

//    function blockingIO(callback) {
//    	setTimeout(function() { callback("The blocking task has been completed"); }, 3000); }
//    // A demo callback function
//    function doThisWhenFinished(message) { console.log(message) };
//    // Calling our simulated I/O function
//    blockingIO(doThisWhenFinished);
//    // The event loop continues 
//    console.log("Prints before the IO tasks finishes");
//return callback(null, result.state.bri)



//function getCallback(){
//  tmpVar = callbackVar;
//  if (callbackVar !== null && callbackVar !== undefined){
//    resetCallback();
//    return tmpVar;
//  }
//}
//
//function setCallback(data){
//  callbackVar = data;
//}
//
//function resetCallback(){
//  callbackVar = null;
//}