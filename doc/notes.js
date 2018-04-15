//Math.floor((Math.random() * 10) + 1)
//if ( result.state.buttonevent !== undefined && result.state.buttonevent !== null)


//var jsonFile=fs.readFileSync('db.json', 'utf8');
//var jsonObj = JSON.parse(jsonFile);



getOn = function(){

  var retValueContent = undefined;
  var tmpVar = undefined;
  client.get('/lights/1/', function (err, result) {
    if ( err || typeof result === undefined){ return err;}
    retValue(result.state.on);

    function retValue(input){
      if (input !== null && input !== undefined){ //Set from input
        retValueContent = input;                  //saveResult to an global var
      } else {                                    //Get from variable
        var tmpVar = retValueContent;             //getResult from the global var
        retValueContent = null;                   //resetResult
        return tmpVar;                            //returnResult
      }
    }
  })
}



  if (input !== null && input !== undefined){ //Set from input
    retValueContent = input;                  //saveResult to an global var
  } else {                                    //Get from variable
    var tmpVar = retValueContent;             //getResult from the global var
    retValueContent = null;                   //resetResult
    return tmpVar;                            //returnResult
  }
  
  
  
  
  return retValue();
}











arrMyCallback = [''];


initCallBack = function(){  
  for ( i = 0; i < arrMyCallback.Length; i++){ //Zoek opslaglocatie
    if ( arrMyCallback[i] === '' ){
      arrMyCallback[i] === 'GetValue'         //Reserveer opslaglocatie
      return i;                               //Return opslaglocatienummer
    }
  }

  if ( i === arrMyCallback.Length){           //een leeg array
    return arrMyCallback.Length;
  }
}

setCallBack = function(loc, data){              //set de callback variabel
  arrMyCallback[x] = data;
}

getCallBack = function(loc){                    //get the callback variable
  return arrMyCallback[x];
}

resetCallBack = function(loc){                  //reset the callback variable
  arrMyCallback[loc] = '';
}





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






//<script type="text/javascript"></script>











//  counter = 0;
//  //module.exports.counter = counter = 0;
//  
//  module.exports.debug = debug = false;
//  module.exports.test1 = test1 = 'test1';
//  module.exports.test2 = test2 = 'test2';
//  module.exports.test3 = test3 = 'test3';
//  
//  exports.sometest = function(){
//    console.log("##########################################################################################################Succeed!!!");
//    console.log("##########################################################################################################Succeed!!!");
//    console.log("##########################################################################################################Succeed!!!");
//    console.log("##########################################################################################################Succeed!!!");
//    console.log("##########################################################################################################Succeed!!!");
//    console.log("##########################################################################################################Succeed!!!");
//  }






//function VariablesConfig(){
//  
  //process.stdout.write( '\n' + " initialize Config ");
  
  //  sVariableName = typeof sVariableName !== undefined ? sVariableName : "DefaultStartValue";
  

  
//};
//VariablesConfig();

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


function getCb(){
  tmpVar = callbackVar;
  if (callbackVar !== null && callbackVar !== undefined){
    resetCb();
    return tmpVar;
  }
}

function setCb(data){
  callbackVar = data;
}

function resetCb(){
  callbackVar = null;
}










//    var sPOST = {
//      uri: sUri + sPort + sPath,
//      method: 'POST',
//      json: true,
//      body: { "key": "VolumeUp" }
//    };
//    
//    var sGET = {
//      uri: sUri + sPort + sPath,
//      json: true,
//    };


//  method: null == GET

///   GET001
//    request({
//      url: 'http://192.168.0.97:1925/5/ambilight/processed',
//      json: true,
//    }, function(error, response, body) {
//      console.log(body);
//    });

///   GET002
//    request({
//      url: 'http://192.168.0.97:1925/5/ambilight/processed',
//      method: null,
//      json: true,
//      body: null
//    }, function(error, response, body) {
//      console.log(body);
//    });

///   POST001
///   var opts = {
///     uri: 'http://192.168.0.97:1925/5/input/key',
///     method: 'POST',
///     json: true,
///     body: { "key": "VolumeUp" }
///   };
///   request(opts, function (error, res, body){console.log(res); });

//POST001











//hostIp = 'http://192.168.0.97';
//hostPort = ':' + '1925';
//hostPath = '/5/input/key';
//
////POST001
//var opts = {
//  uri: hostIp + hostPort + hostPath,
//  method: 'POST',
//  json: true,
//  body: { "key": "VolumeUp" }
//};
//request(opts, function (error, res, body){console.log(res); });








//var options = {
//  hostname: 'http://192.168.0.97',
//  port: app.get('1925'),
//  path: '/1/ambilight/processed',
//  method: 'GET',
//  json:true
//}
//request(options, function(error, response, body){
//  if(error) console.log(error);
//  else console.log(body);
//});



//var options = {
//  hostname: '127.0.0.1',
//  port: app.get('port'),
//  path: '/users',
//  method: 'GET',
//  json:true
//}
//request(options, function(error, response, body){
//  if(error) console.log(error);
//  else console.log(body);
//});





//var urk = 'http://192.168.0.97:1925/5/input/key';
//var method = 'GET';
//var body  = { "key": "VolumeUp" };
//
//function setRequestOpt(urk, method, body){
//  var sRetVal = {
//      uri: 'http://192.168.0.97:1925/5/input/key',
//      method: method,
////      json: true,
//      body: { "key": "VolumeUp" }
//    };
//  return sRetVal;
//};
//
//
//
//request(setRequestOpt(), function (error, res, body){console.log(res); });










































//      var request = require('request');
//      
//      method = 'POST';
//      uri = 'http://192.168.0.97:1925/5/input/key';
//      json = { "key": "VolumeUp" };
//      
//      request(options = { uri: uri, method: method, json: json }, function (error, response, body) {
//        if (!error && response.statusCode == 200) {
//          //console.log(body.id) // Print the shortened url.
//          console.log(response) // Print the shortened url.
//        }
//      
//      });


//var request = require('request');
//method = 'POST';
//uri = 'http://192.168.0.97:1925/5/input/key';
//json = { "key": "VolumeUp" };
//      
//      var options = {
//        uri: uri,
//        method: 'POST',
//        json: true,
//        body: json
//      }
//      request(options, function (error, response, body){console.log(response); });


//      var request = require('request');
//      method = 'POST';
//      uri = 'http://192.168.0.97:1925/5/input/key';
//      json = { "key": "VolumeUp" };
//      request(options = { uri, method, json});



//var request = require('request');
//method = 'POST';
//uri = 'http://192.168.0.97:1925/5/input/key';
//json = { "key": "VolumeUp" };
//
//method = 'POST';
//uri = 'http://192.168.0.97:1925/5/input/key';
//json = { "key": "VolumeUp" };
//
//request(options = { uri: uri, method: method, json: json }, function (err, res, body){console.log(response)});


///     var request = require('request');
///     
///     var options = {
///       uri: 'http://192.168.0.97:1925/5/input/key',
///       method: 'POST',
///       json: { "key": "VolumeUp" },
///     }


//request(options, function (error, response, body){console.log(response); });



//var request = require('request');
//
//var options = {
//  uri: 'http://192.168.0.97:1925/5/input/key',
//  method: 'POST',
//  json: { "key": "VolumeUp" },
//}
//request(options, function (error, response, body){console.log(response); });



