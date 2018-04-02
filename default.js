
function VariablesDefault(){
        
  process.stdout.write( '\n' + "initialize HomeAutomation");
  
  exec = require('child_process').exec;

  pathroot = '/root/scripts/HomeAutomation/';
  pathconfig = pathroot + './config/';
  pathresources = pathroot + './resources/';
  pathlib = pathroot + './lib/';
  pathsrc = pathroot + './src/';
  
  module.exports = require( pathconfig + './init.js');
  module.exports = require( pathlib + './init.js');
  module.exports = require( pathresources + './init.js');
  module.exports = require( pathsrc + './init.js');

  process.stdout.write( '\n' + " initialize Done!.. " + '\n' );

  //index = require( './default.js' ); 

  

};
module.exports = VariablesDefault();

//global.retValueInit = function(){
//  console.log("Init: Length:" + retValueContent.length + " Content:" + retValueContent);
//
//  for (i = 0; i < retValueContent.length; i++){
//      console.log( i + " " + retValueContent[i]);
//  };
//  console.log("End")
//  for (i = 0; i < retValueContent.length; i++){
//    if ( retValueContent.length === undefined){
//      console.log("Init: Found:" +  i);
//      return i;
//    }
//  };
//
//  return retValueContent.length;
//}
//
//global.retValueSet = function(loc, input){
//  console.log("Set:" + " loc:" + loc + " Input:" + input);
//  if (input !== null && input !== undefined){   //Set from input
//    retValueContent[loc] = input;               //saveResult to an global var
//  }
//}
//
//global.retValueGet = function(loc){
//  var tmpVar = retValueContent[loc];           //getResult from the global var
//  retValueContent[loc] = null;                 //resetResult
//  console.log("Get:" + loc + " tmpVar:" + tmpVar);
//  return tmpVar;                               //returnResult
//}




//    console.log("New: " + retValueInit());
//    retValueContent[retValueContent.length] = "test";

//
////Everything runs from this function
//

////var myInit = function() {
function myInit() {
       console.log("       " + counter++ + " " );

       if ( counter == 1 || ( counter % 20 ) == 0 ){
         light.getInfoAll();
         sensor.getInfoAll();
     
       }
       
       if ( ( counter % 100 ) == 1 ){
         //light.saveInfoAll();
         //light.loadInfoAll();
       }
     
       //apt-get updatenode updateif ( ( counter % 20 ) == 0 ){ http.get('http://192.168.0.214/HKAPI/doVolumeDown.php', (resp) => { var data = ''; resp.on('data', (chunk) => { }); resp.on('end', () => { }); }).on("error", (err) => { }); };
       //if ( ( counter % 20 ) == 0 ){ exec("/usr/bin/php /root/scripts/HomeAutomation/resources/avr/control/doSelectSourceMHL.php"); };
    

//        getOn = function(iLightNumber){
//          client.get('/lights/' + iLightNumber + '/', function (err, result) {
//            if ( err || typeof result === undefined){ return err;}
//            retValue(result.state.on);
//          })
//          return retValue();
//       }
        //console.log("Status: " + light.getOn(1));
        //var NewResult = light.getBri(1);
        //console.log("NewResult:" + NewResult);

        //console.log("EndResult: " + light.getOn(1));

        console.log(light.getOn(1));
        //light.sometest();


  setTimeout(myInit, 1000);
};
setTimeout(myInit, 3000);






























//function sometestfunction(msg){
//  console.log(msg);
//}

//function setReturnValue(sValue){
//  xReturnValue = sValue;
//  return xReturnValue;
//};
//
//function clientGetUpdate(){
//  
//  function doConsolelog(msg){
//    xReturnValue = msg;
//    console.log(xReturnValue + "test");
//    document.getElementById("demo3").innerHTML = xReturnValue;
//  }
//  light.getOn(1, console.log)
//
//  document.getElementById("demo1").innerHTML = Math.floor((Math.random() * 10) + 1);
//  document.getElementById("demo2").innerHTML = counter++;
//  
//  document.getElementById("demo4").innerHTML = "test";
//  //document.getElementById("demo5").innerHTML = light.getOn(1);
//  //console.log(light.getOn2(1) + xReturnValue );
//  document.getElementById("demo6").innerHTML = "test";
//  //document.getElementById("demo3").innerHTML = tempvar();
//  //document.getElementById("demo4").innerHTML = counter++;
//  //document.getElementById("demo5").innerHTML = counter++;
//  
//
//}


//console.log = function (d) {
//  process.stdout.write(d + '\n');
//};




//function updatesPush(iCounterInput){
//  iCounterOutput = iCounterInput;
//      //document.getElementById("demo2").innerHTML = iCounterInput;
//      //window.getElementById("demo2").innerHTML = iCounterInput;
//}
//
//
//function updatesGet(){
//  updatesPush(counter++);
//}
//
//
//window.onload = function(){
//  // Init globals
//  parentElementMainTable = document.getElementById('main-table-body');
//  addOrderBtn = document.getElementById("add-order");

  // Add the onclick function to add rows in table
  //addOrderBtn.onclick = function(){
  //    addRow();
  //}
//}


//function htmlServer(){
//  var http = require('http');
//
//  http.createServer(function (request, response) {
//      console.log('New connection');
//     // userCount++;
//
//
//
//
//     function present(){
//      response.writeHead(200, {'Content-Type': 'text/plain'});
//      response.write('Hello!\n');
//      response.write('We have had '+counter+' visits!\n');
//      response.cork();
//     }
//     setTimeout(present, 1000);   
//
//      
//     //response.end();
//
//  }).listen(8080,'127.0.0.1');
//
//  console.log('Server started');
//};
//
//htmlServer();



/************
*   HTTP    *
************/
//  var http = require('http');
////////////////////////////////////////////////////////////////////////////////////////////////////
//  HTTP Properties and Methods
////////////////////////////////////////////////////////////////////////////////////////////////////
//  createClient()	Deprecated. Creates a HTTP client
//  createServer()	Creates an HTTP server
//  get()	Sets the method to GET, and returns an object containing the user's request
//  globalAgent	Returns the HTTP Agent
//  request()	Returns an object containing the user's request
////////////////////////////////////////////////////////////////////////////////////////////////////

/*************
*   STREAM   *
*************/
//  var stream = require('stream');
////////////////////////////////////////////////////////////////////////////////////////////////////
//  ### Readable Stream Properties and Methods
////////////////////////////////////////////////////////////////////////////////////////////////////
//  isPaused()	Returns true if the state of  the readable stream is paused, otherwise false
//  pause()	Pauses the readable stream
//  pipe()	Turns the readable stream into the specified writable stream
//  read()	Returns a specified part of the readable stream
//  resume()	Resumes a paused stream
//  setEncoding()	Sets the character encoding of the readable stream
//  unpipe()	Stops turning a readable stream into a writable stream, caused by the pipe() method
//  unshift()	Pushes some specified data back into the internal buffer
//  wrap()	Helps reading streams made by older Node.js versions
////////////////////////////////////////////////////////////////////////////////////////////////////
//  ### Writable Stream Properties and Methods
////////////////////////////////////////////////////////////////////////////////////////////////////
//  cork()	Stops the writable stream and all written data will be buffered in memory
//  end()	Ends the writable stream
//  setDefaultEncoding()	Sets the encoding for the writable stream
//  uncork()	Flushes all data that has been buffered since the cork() method was called
//  write()	Writes data to the stream
////////////////////////////////////////////////////////////////////////////////////////////////////







//      http.createServer(function(req, res){ }).listen(8888, '127.0.0.1');
//      response.writeHead(200, {'Content-Type': 'text/plain'});
//      res.writeHead(200, {'Content-Type': 'text/html'});  

//  res.write('<!doctype html>\n<html lang="en">\n' +  
//    '\n<meta charset="utf-8">\n<title>Test web page on node.js</title>\n' + 
//    '<style type="text/css">* {font-family:arial, sans-serif;}</style>\n' + 
//    '\n\n<h1>Euro 2012 teams</h1>\n' + 
//    '<div id="content"><p>The teams in Group D for Euro 2012 are:</p><ul><li>England</li><li>France</li><li>Sweden</li><li>Ukraine</li></ul></div>' + 
//    '\n\n');

//    http://theholmesoffice.com/how-to-build-a-simple-webpage-in-node-js/  




//       function someOtherFucntion(){
//          function getCallback(){
//            tmpVar = callbackVar;
//            if (callbackVar !== null){
//              resetCallback();
//              return tmpVar;
//            }
//          }
//
//          function setCallback(data){
//            callbackVar = data;
//          }
//
//          function resetCallback(){
//            callbackVar = null;
//          }
//          client.get('/lights/1/', function (err, result) {
//            if ( err || typeof result === undefined){ return err;}
//            setCallback(result.state.on);
//          })
//          return getCallback();
//       }
//
//      console.log(someOtherFucntion());



//        function getResult(){
//          if (callbackVar !== null && callbackVar !== undefined){
//            tmpVar = callbackVar;
//            callbackVar = null;
//            return tmpVar;
//          }
//        }
//
//        function saveResult(data){
//          callbackVar = data;
//        }
//
//        function someOtherFucntion(){
//
//          client.get('/lights/1/', function (err, result) {
//            if ( err || typeof result === undefined){ return err;}
//            saveResult(result.state.on);//setCall
//          })
//          return getResult();
//       }






