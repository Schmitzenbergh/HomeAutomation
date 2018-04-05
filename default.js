counter = 1;

/************
*   Paths   *
************/

//Root
pathroot = '/root/scripts/HomeAutomation/';
    
    //Config
    pathconfig = pathroot + './config/';

    //Resources
    pathresources = pathroot + './resources/';
    
        //Avr
        pathavr = pathresources + './avr/';

        //Hue
        pathhue = pathresources + './hue/';
            
            //Bridge
            pathhuebridge = pathhue + './bridge/';                 //  pathbridge = pathhue + './bridge/';
            pathhuebridgevalues = pathhuebridge + './_values/';

            //Sensor
            pathhuesensor = pathhue + './sensor/';                 //  pathsensor = pathhue + './sensor/';
            pathhuesensorvalues = pathhuesensor + './_values/';

            //Light
            pathhuelight = pathhue + './light/';                   //  pathlight = pathhue + './light/';
            pathhuelightvalues = pathhuelight + './_values/';

        //Rpi
        pathrpi = pathresources + './RPi/';
        
            //Ledstrip
            pathledstrip = pathrpi + './ledstrip/';

    //Lib
    pathlib = pathroot + './lib/';

    //Src
    pathsrc = pathroot + './src/';    

/**********
*   Hue   *
*********/

  sObjectResults = {};
  //sObjectResults = result;      //Put all results in object 'document'.lights.*.*.*
  //sObjectResults = { result };  //Put all results in object 'document'.results.lights.*.*.*

/***************
*    Lights    *
***************/

  iArrayLightConnected = [1, 2, 3, 4, 5, 6];
  
  //General attributes 
  sArrayLightManufacturerName = [''];                                                                                                                                                                                                                                           
  sArrayLightProductname = [''];                                                              //Color attributes (Currrent)                 // Color attributes (New)                     // Color attributes (Old)         // xy > ct > hs                                                                                                                  
  sArrayLightModelid = [''];                                                                  fArrayLightXyCur = [''];                      fArrayLightXyNew = [''];                      fArrayLightXyOld = [''];          // 0.000 - 1.000                                                                                                                   
  sArrayLightName = ['', 'LightName'];                                                        fArrayLightXyXCur = [''];                     fArrayLightXyXNew = [''];                     fArrayLightXyXOld = [''];         // 0.000 - 1.000                                                                                                                   
  sArrayLightSwversion = [''];                                                                fArrayLightXyYCur = [''];                     fArrayLightXyYNew = [''];                     fArrayLightXyYOld = [''];         // 0.000 - 1.000                                                                                                                   
  sArrayLightType = [''];                                                                     iArrayLightCtCur = [''];                      iArrayLightCtNew = [''];                      iArrayLightCtOld = [''];          // 153 - 500                                                                                                                       
  sArrayLightUniqueid = [''];                                                                 iArrayLightHueCur = ['1'];                     iArrayLightHueNew = [''];                     iArrayLightHueOld = [''];         // 0 - 65535                                                                                                                       
  bArrayLightOn = [''];                 /* true, false                                 */     iArrayLightSatCur = [''];                     iArrayLightSatNew = [''];                     iArrayLightSatOld = [''];         // 0 - 254                                                                                                                         
  bArrayLightReachable = [''];          /* true, false                                 */     iArrayLightBriCur = [''];                     iArrayLightBriNew = [''];                     iArrayLightBriOld = [''];         // 1-254                                                                                                                           
  sArrayLightAlert = [''];              /* none, select, lselect                       */     iArrayLightRgbRedCur = [''];                  iArrayLightRgbRedNew = [''];                  iArrayLightRgbRedOld = [''];      // 0 - 254                                                                                                                         
  sArrayLightColorMode = [''];          /* hs, xy, ct                                  */     iArrayLightRgbGreenCur = [''];                iArrayLightRgbGreenNew = [''];                iArrayLightRgbGreenOld = [''];    // 0 - 254                                                    
  sArrayLightEffect = [''];             /* none, colorloop                             */     iArrayLightRgbBlueCur = [''];                 iArrayLightRgbBlueNew = [''];                 iArrayLightRgbBlueOld = [''];                                                                   
  iArrayLightTransitionTime = [''];     /* multiple of 100ms and defaults to 4 (400ms) */   
     
/***************
*    Sensors   *
***************/

  iArraySensorConnected = [1, 2, 5, 6, 7, 8, 9, 10, 11];        //i++; if ( i == 3 ){ i = 5; } else if ( i == 11 ){ i = 1; } sensor.getInfo(i);

  sArraySensorName = [''];                                                               sArraySensorNameCur = [''];                   sArraySensorNameNew = [''];                   sArraySensorNameOld = [''];                                                                                                                                                                                                                                      
  sArraySensorType = [''];                                                               sArraySensorTypeCur = [''];                   sArraySensorTypeNew = [''];                   sArraySensorTypeOld = [''];                                                                                                                                                                                                                                      
  sArraySensorModelId = [''];                                                            sArraySensorModelIdCur = [''];                sArraySensorModelIdNew = [''];                sArraySensorModelIdOld = [''];                                                                                                                                                                                                                                   
  sArraySensorManufacturerName = [''];                                                   sArraySensorManufacturerNameCur = [''];       sArraySensorManufacturerNameNew = [''];       sArraySensorManufacturerNameOld = [''];                                                                                                                                                                                                                          
  sArraySensorSwVersion = [''];                                                          sArraySensorSwVersionCur = [''];              sArraySensorSwVersionNew = [''];              sArraySensorSwVersionOld = [''];                                                                                                                                                                                                                                 
  sArraySensorUniqueId = [''];                                                           sArraySensorUniqueIdCur = [''];               sArraySensorUniqueIdNew = [''];               sArraySensorUniqueIdOld = [''];                                                                                                                                                                                                                                  
  bArraySensorRecycle = [''];                                                            bArraySensorRecycleCur = [''];                bArraySensorRecycleNew = [''];                bArraySensorRecycleOld = [''];                                                                                                                                                                                                                                   
                                                                                                                                                                                                                                                                                                                                                                                                               
  iArraySensorButtonEvent = [''];                                                        iArraySensorButtonEventCur = [''];            iArraySensorButtonEventNew = [''];            iArraySensorButtonEventOld = [''];                                                                                                                                                                                                                               
  iArraySensorLightLevel = [''];                                                         iArraySensorLightLevelCur = [''];             iArraySensorLightLevelNew = [''];             iArraySensorLightLevelOld = [''];                                                                                                                                                                                                                                
  bArraySensorDark = [''];                                                               bArraySensorDarkCur = [''];                   bArraySensorDarkNew = [''];                   bArraySensorDarkOld = [''];                                                                                                                                                                                                                                      
  bArraySensorDaylight = [''];                                                           bArraySensorDaylightCur = [''];               bArraySensorDaylightNew = [''];               bArraySensorDaylightOld = [''];                                                                                                                                                                                                                                  
  iArraySensorStatus = [''];                                                             iArraySensorStatusCur = [''];                 iArraySensorStatusNew = [''];                 iArraySensorStatusOld = [''];                                                                                                                                                                                                                                    
  sArraySensorLastupdated = [''];                                                        sArraySensorLastupdatedCur = [''];            sArraySensorLastupdatedNew = [''];            sArraySensorLastupdatedOld = [''];                                                                                                                                                                                                                               
  bArraySensorPresence = [''];                                                           bArraySensorPresenceCur = [''];               bArraySensorPresenceNew = [''];               bArraySensorPresenceOld = [''];                                                                                                                                                                                                                                  
  iArraySensorTemperature = [''];                                                        iArraySensorTemperatureCur = [''];            iArraySensorTemperatureNew = [''];            iArraySensorTemperatureOld = [''];                                                                                                                                                                                                                               
                                                                                                                                                                                                                                                                                                                                                                                                                                                   
  bArraySensorOn = [''];                                                                 bArraySensorOnCur = [''];                     bArraySensorOnNew = [''];                     bArraySensorOnOld = [''];                                                                                                                                                                                                                                        
  iArraySensorBattery = [''];                                                            iArraySensorBatteryCur = [''];                iArraySensorBatteryNew = [''];                iArraySensorBatteryOld = [''];                                                                                                                                                                                                                                   
  bArraySensorConfigured = [''];                                                         bArraySensorConfiguredCur = [''];             bArraySensorConfiguredNew = [''];             bArraySensorConfiguredOld = [''];                                                                                                                                                                                                                                
  bArraySensorReachable = [''];                                                          bArraySensorReachableCur = [''];              bArraySensorReachableNew = [''];              bArraySensorReachableOld = [''];                                                                                                                                                                                                                                 
  sArraySensorAlert = [''];                                                              sArraySensorAlertCur = [''];                  sArraySensorAlertNew = [''];                  sArraySensorAlertOld = [''];                                                                                                                                                                                                                                     
  iArraySensorTholdDark = [''];                                                          iArraySensorTholdDarkCur = [''];              iArraySensorTholdDarkNew = [''];              iArraySensorTholdDarkOld = [''];                                                                                                                                                                                                                                 
  iArraySensorTholdOffset = [''];                                                        iArraySensorTholdOffsetCur = [''];            iArraySensorTholdOffsetNew = [''];            iArraySensorTholdOffsetOld = [''];                                                                                                                                                                                                                               
  iArraySensorStatus = [''];                                                             iArraySensorStatusCur = [''];                 iArraySensorStatusNew = [''];                 iArraySensorStatusOld = [''];                                                                                                                                                                                                                                    
  iArraySensorTholdOffset = [''];                                                        iArraySensorTholdOffsetCur = [''];            iArraySensorTholdOffsetNew = [''];            iArraySensorTholdOffsetOld = [''];                                                                                                                                                                                                                               
  bArraySensorLedindication = [''];                                                      bArraySensorLedindicationCur = [''];          bArraySensorLedindicationNew = [''];          bArraySensorLedindicationOld = [''];                                                                                                                                                                                                                             
  bArraySensorUsertest = [''];                                                           bArraySensorUsertestCur = [''];               bArraySensorUsertestNew = [''];               bArraySensorUsertestOld = [''];                                                                                                                                                                                                                                  
  iArraySensorSensitivity = [''];                                                        iArraySensorSensitivityCur = [''];            iArraySensorSensitivityNew = [''];            iArraySensorSensitivityOld = [''];                                                                                                                                                                                                                               
  iArraySensorSensitivityMax = [''];                                                     iArraySensorSensitivityMaxCur = [''];         iArraySensorSensitivityMaxNew = [''];         iArraySensorSensitivityMaxOld = [''];                                                                                                                                                                                                                            
  iArraySensorSunsetoffset = [''];                                                       iArraySensorSunsetoffsetCur = [''];           iArraySensorSunsetoffsetNew = [''];           iArraySensorSunsetoffsetOld = [''];                                                                                                                                                                                                                              
  iArraySensorSunriseoffset = [''];                                                      iArraySensorSunriseoffsetCur = [''];          iArraySensorSunriseoffsetNew = [''];          iArraySensorSunriseoffsetOld = [''];                                                                                                                                                                                                                             
  sArraySensorPending = [''];                                                            sArraySensorPendingCur = [''];                sArraySensorPendingNew = [''];                sArraySensorPendingOld = [''];                                                                                                                                                                                                                                   


//****************************************************************************************************************************************/
if (typeof document !== 'undefined'){        // When browser
//****************************************************************************************************************************************/

  function clientGetUpdate(){
   
    //var myObj = JSON.parse(pathhue + "./json.txt");

    document.getElementById("demo").innerHTML = counter++;
    document.getElementById("demo01").innerHTML = Math.floor((Math.random() * 10) + 1);
    document.getElementById("demo02").innerHTML = pathresources;
    document.getElementById("demo03").innerHTML = pathroot;
    document.getElementById("demo04").innerHTML = pathconfig;
    document.getElementById("demo05").innerHTML = sArrayLightName;
    document.getElementById("demo06").innerHTML = pathsrc;
    if ( sObjectResults.config !== undefined ){   
      //document.getElementById("demo07").innerHTML = sObjectResults.config;
      //document.getElementById("demo07").innerHTML = JSON.stringify(sObjectResults.config);
    }
    document.getElementById("demo08").innerHTML = sArrayLightName["1"];
    document.getElementById("demo09").innerHTML = jArrayResults;
  }
  



  setInterval(clientGetUpdate, 1000);

//****************************************************************************************************************************************/  
} else if (typeof document === 'undefined'){  //When console
//****************************************************************************************************************************************/

  hue = require('hue-sdk');
  //hue = require( pathresources + './hue-sdk/lib/hue.js');
  client = new hue.Hue(require( pathconfig + './.credentials.json' ));
  fs = require('fs');
  exec = require('child_process').exec;
  light = require( pathhuelight + './light.js' );
  sensor = require( pathhuesensor + './sensor.js');
  bridge = require( pathhuebridge + './bridge.js');
  
  
  //app = require('http').createServer(handler)
  //io = require('socket.io')(app);

  startApp();
  
  //htmlServer();
  myInit();
};

//console.log(db.lights[1].state.xy[1])


function myInit() {

  //console.log(counter++);

  //if ( ( counter % 3 ) == 0 ){
    //bridge.getInfoAll();
 // }

  //if ( sObjectResults.lights !== undefined ){       //  ok
  //if ( sObjectResults.lights[1] !== undefined ){    //  Cannot read property '1' of undefined
  if ( ( counter % 3 ) == 0 && sObjectResults.config !== undefined ){   
    console.log('\t' + sObjectResults.config.UTC);
  }


  if ( counter == 1 || ( counter % 25 ) == 0 ){
    //light.getInfoAll();
    //sensor.getInfoAll();
  }

  if ( counter == 26 ||( counter % 250 ) == 1 ){
//    light.saveInfoAll();
//    light.loadInfoAll();
//    sensor.saveInfoAll();
//    sensor.loadInfoAll();
  }

  setTimeout(myInit, 1000);
}


function startApp(){

  var app = require('express')();
  var http = require('http').Server(app);
  var io = require('socket.io')(http);      //A server that integrates with (or mounts on) the Node.JS HTTP Server: socket.io
  
  app.get('/', function(req, res){
    res.sendFile(__dirname + '/index.html');
  });

  //Fired upon a connection including a successful reconnection.
  io.on('connection', function(socket){

      console.log('a user connected');

      socket.broadcast.emit('message', 'Another client has just connected!');

      socket.on('disconnect', function(){
        console.log('user disconnected');

      });

      //the server sends a message to the client when they connect, 
      //to confirm that the connection has worked properly
      //io.sockets.on('connection', function (socket) {
        socket.emit('message', 'You are connected!');
      //});

      // When the server receives a “message” type signal from the client   
      socket.on('message', function (message) {
        console.log('A client is speaking to me! They’re saying: ' + message);
      }); 

  });


  //  #socket.emit(eventName[, ...args][, ack])
  //  eventName (String)
  //  args
  //  ack (Function)
  //  Returns Socket
  //  Emits an event to the socket identified by the string name. Any other parameters can be included. All serializable datastructures are supported, including Buffer.
  //  
  //  socket.emit('hello', 'world');
  //  socket.emit('with-binary', 1, '2', { 3: '4', 5: new Buffer(6) });
  //  The ack argument is optional and will be called with the server answer.
  //  
  //  socket.emit('ferret', 'tobi', (data) => {
  //    console.log(data); // data will be 'woot'
  //  });
  //  
  //  // server:
  //  //  io.on('connection', (socket) => {
  //  //    socket.on('ferret', (name, fn) => {
  //  //      fn('woot');
  //  //    });
  //  //  });

    //In this case, for the sake of simplicity we’ll send the message to everyone, including the sender.
    io.on('connection', function(socket){
      socket.on('chat message', function(msg){
        io.emit('chat message', msg);
      });
    });
  //  
  //  #socket.on(eventName, callback)
  //  eventName (String)
  //  callback (Function)
  //  Returns Socket
  //  Register a new handler for the given event.
  //  
  //  socket.on('news', (data) => {
  //    console.log(data);
  //  });
  //  
  //  // with multiple arguments
  //  socket.on('news', (arg1, arg2, arg3, arg4) => {
  //    // ...
  //  });
  //  // with callback
  //  socket.on('news', (cb) => {
  //    cb(0);
  //  });
  //  The socket actually inherits every method of the Emitter class, like hasListeners, once or off (to remove an event listener).

  //  #socket.compress(value)
  //  value (Boolean)
  //  Returns Socket
  //  Sets a modifier for a subsequent event emission that the event data will only be compressed if the value is true. Defaults to true when you don't call the method.
  //  
  //  socket.compress(false).emit('an event', { some: 'data' });

  //  #socket.close()
  //  Returns Socket
  //  Disconnects the socket manually.
  //  
  //  #socket.disconnect()
  //  Synonym of socket.close().

  //  #Event: 'connect'
  //  Fired upon a connection including a successful reconnection.
  //
  //  socket.on('connect', () => {
  //    // ...
  //  });
  //
  //  //note: you should register event handlers outside of connect,
  //  //so they are not registered again on reconnection
  //  socket.on('myevent', () => {
  //    // ...
  //  });

  //  #Event: 'connect_error'
  //  error (Object) error object
  //  Fired upon a connection error.
  //  
  //  socket.on('connect_error', (error) => {
  //    // ...
  //  });

  //  #Event: 'connect_timeout'
  //  Fired upon a connection timeout.
  //  
  //  socket.on('connect_timeout', (timeout) => {
  //    // ...
  //  });

  //  #Event: 'error'
  //  error (Object) error object
  //  Fired when an error occurs.
  //  
  //  socket.on('error', (error) => {
  //    // ...
  //  });

  //  #Event: 'disconnect'
  //  reason (String) either 'io server disconnect' or 'io client disconnect'
  //  Fired upon a disconnection.
  //  
  //  socket.on('disconnect', (reason) => {
  //    // ...
  //  });

  //  #Event: 'reconnect'
  //  attempt (Number) reconnection attempt number
  //  Fired upon a successful reconnection.
  //  
  //  socket.on('reconnect', (attemptNumber) => {
  //    // ...
  //  });

  //  #Event: 'reconnect_attempt'
  //  attempt (Number) reconnection attempt number
  //  Fired upon an attempt to reconnect.
  //  
  //  socket.on('reconnect_attempt', (attemptNumber) => {
  //    // ...
  //  });

  //  #Event: 'reconnecting'
  //  attempt (Number) reconnection attempt number
  //  Fired upon an attempt to reconnect.
  //  
  //  socket.on('reconnecting', (attemptNumber) => {
  //    // ...
  //  });

  //  #Event: 'reconnect_error'
  //  error (Object) error object
  //  Fired upon a reconnection attempt error.
  //  
  //  socket.on('reconnect_error', (error) => {
  //    // ...
  //  });

  //  #Event: 'reconnect_failed'
  //  Fired when couldn't reconnect within reconnectionAttempts.
  //  
  //  socket.on('reconnect_failed', () => {
  //    // ...
  //  });

  //  #Event: 'ping'
  //  Fired when a ping packet is written out to the server.
  //  
  //  socket.on('ping', () => {
  //    // ...
  //  });

  //  #Event: 'pong'
  //  ms (Number) number of ms elapsed since ping packet (i.e.: latency).
  //  Fired when a pong is received from the server.
  //  
  //  socket.on('pong', (latency) => {
  //    // ...
  //  });












  //error (Object) error object

  ////Event: 'connect_timeout'
  ////Fired upon a connection timeout.
  //socket.on('connect_timeout', (timeout) => {
  //  // ...
  //});

  ////Fired upon a connection error.
  //socket.on('connect_error', (error) => {
  //  // ...
  //});

  //Event: 'error'  error (Object) error object



  http.listen(8080, function(){
    console.log('listening on *:8080');
  });


};









//        function startApp(){
//        
//          var app = require('express')();
//          var http = require('http').Server(app);
//          var io = require('socket.io')(http);      //A server that integrates with (or mounts on) the Node.JS HTTP Server: socket.io
//          
//          app.get('/', function(req, res){
//            res.sendFile(__dirname + '/index.html');
//          });
//          
//          //io.on('connection', function(socket){
//          //  console.log('a user connected');
//          //});
//        
//          //Each socket also fires a special disconnect event:
//          io.on('connection', function(socket){
//            console.log('a user connected');
//            socket.on('disconnect', function(){
//              console.log('user disconnected');
//            });
//          });
//        
//          //      //And in index.js we print out the chat message event:
//          //      io.on('connection', function(socket){
//          //        socket.on('chat message', function(msg){
//          //          console.log('message: ' + msg);
//          //        });
//          //      });
//          
//          //    //In order to send an event to everyone, Socket.IO gives us the io.emit:
//          //    io.emit('some event', { for: 'everyone' });
//        
//          //    //If you want to send a message to everyone except for a certain socket, we have the broadcast flag:
//          //    io.on('connection', function(socket){
//          //      socket.broadcast.emit('hi');
//          //    });
//        
//          //In this case, for the sake of simplicity we’ll send the message to everyone, including the sender.
//          io.on('connection', function(socket){
//        
//            socket.on('chat message', function(msg){
//              io.emit('chat message', msg);
//            });
//          });
//        
//        
//          http.listen(8080, function(){
//            console.log('listening on *:8080');
//          });
//        
//        
//        };

























//      function htmlServer(){
//        console.log('init Server...');
//        var http = require('http');
//        var https = require('https');
//        var fs = require('fs');
//        var path = require('path');
//        var sObjectResultsServer;
//        http.createServer(function (request, response){
//          console.log('request starting...');
//      
//          var filePath = '.' + request.url;
//          if (filePath == './')
//              filePath = './index.html';
//      
//              var filePath = '.' + request.url;
//              if (filePath == './')
//                  filePath = './index.html';
//          
//              var extname = path.extname(filePath);
//              var contentType = 'text/html';
//              switch (extname) {
//                  case '.js':
//                      contentType = 'text/javascript';
//                      break;
//                  case '.css':
//                      contentType = 'text/css';
//                      break;
//                  case '.json':
//                      contentType = 'application/json';
//                      break;
//                  case '.png':
//                      contentType = 'image/png';
//                      break;      
//                  case '.jpg':
//                      contentType = 'image/jpg';
//                      break;
//                  case '.wav':
//                      contentType = 'audio/wav';
//                      break;
//              }
//          
//              fs.readFile(filePath, function(error, content) {
//                  if (error) {
//                      if(error.code == 'ENOENT'){
//                          fs.readFile('./404.html', function(error, content) {
//                              response.writeHead(200, { 'Content-Type': contentType });
//                              response.end(content, 'utf-8');
//                          });
//                      }
//                      else {
//                          response.writeHead(500);
//                          response.end('Sorry, check with the site admin for error: '+error.code+' ..\n');
//                          response.end(); 
//                      }
//                  }
//                  else {
//                      response.writeHead(200, { 'Content-Type': contentType });
//                      response.end(content, 'utf-8');
//                  }
//              });
//      
//           }).listen(8080);
//      };



