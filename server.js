var http = require('http');
var url = require('url');
var fs = require('fs');
//var fs = require('angular-json-tree');
var path = require('path');
var jsonFile=fs.readFileSync('db.json', 'utf8');
var jsonObj = JSON.parse(jsonFile);
var server;
var counter = 1;

//avr = require( pathavrhk171s + 'default.js');



//var tv = require('');



/***************\
| NodeJS Server |###############################################################################################################################################################################
\***************/

server = http.createServer(function(req, res){
var bDoPageRefresh = false;
    // your normal server code
    var path = url.parse(req.url).pathname;
    counter++;
    switch (path){
        case '/':
            fs.readFile('index.html', function(err, data){
              if (err){ return send404(res); }
              res.writeHead(200, {'Content-type': 'text/html'}); 
              res.write(data, 'utf8'); 
              res.end();
            });
            break;
        case '/test.html':
            fs.readFile(__dirname, function(err, data){
                if (err){ return send404(res); }
                res.writeHead(200, {'Content-type': 'text/html'}); 
                res.write(data, 'utf8');
                res.end();
            });
          break;

        //Run functions by call the url  
        case '/volup'  :   if (err){ return send404(res); }; volumeup();  bDoPageRefresh = true; 
          break;
        case '/voldown':   if (err){ return send404(res); }; volumeup();  bDoPageRefresh = true; 
          break;

        default: send404(res);

    }
    if (bDoPageRefresh){  // For all actions without a page
        fs.readFile('index.html', function(err, data){
            if (err){ return send404(res); }
            res.writeHead(200, {'Content-type': 'text/html'});
            res.write(data, 'utf8'); res.end();
        });
    }
}),

send404 = function(res){
    res.writeHead(404);
    res.write('404');
    res.end();
};

server.listen(80);

// use socket.io
var io = require('socket.io').listen(server);

//turn off debug
//io.set('log level', 0);

// define interactions with client
io.sockets.on('connection', function(socket){

socket.on('power-off'       , function(data){ avr.SendCommand('power-off'       ); });
socket.on('power-on'        , function(data){ avr.SendCommand('power-on'        ); });
socket.on('mute-toggle'     , function(data){ avr.SendCommand('mute-toggle'     ); });
socket.on('mute-on'         , function(data){ avr.SendCommand('mute-on'         ); });
socket.on('mute-off'        , function(data){ avr.SendCommand('mute-off'        ); });
socket.on('volume-down'     , function(data){ avr.SendCommand('volume-down'     ); });
socket.on('volume-up'       , function(data){ avr.SendCommand('volume-up'       ); });
socket.on('ok'              , function(data){ avr.SendCommand('ok'              ); });
socket.on('home'            , function(data){ avr.SendCommand('home'            ); });
socket.on('options'         , function(data){ avr.SendCommand('options'         ); });
socket.on('down'            , function(data){ avr.SendCommand('down'            ); });
socket.on('up'              , function(data){ avr.SendCommand('up'              ); });
socket.on('left'            , function(data){ avr.SendCommand('left'            ); });
socket.on('right'           , function(data){ avr.SendCommand('right'           ); });
socket.on('back'            , function(data){ avr.SendCommand('back'            ); });
socket.on('forward'         , function(data){ avr.SendCommand('forward'         ); });
socket.on('pause'           , function(data){ avr.SendCommand('pause'           ); });
socket.on('play'            , function(data){ avr.SendCommand('play'            ); });
socket.on('next'            , function(data){ avr.SendCommand('next'            ); });
socket.on('previous'        , function(data){ avr.SendCommand('previous'        ); });
socket.on('sleep'           , function(data){ avr.SendCommand('sleep'           ); });
socket.on('delay'           , function(data){ avr.SendCommand('delay'           ); });
socket.on('channel-up'      , function(data){ avr.SendCommand('channel-up'      ); });
socket.on('channel-down'    , function(data){ avr.SendCommand('channel-down'    ); });
socket.on('tuner-up'        , function(data){ avr.SendCommand('tuner-up'        ); });
socket.on('tuner-down'      , function(data){ avr.SendCommand('tuner-down'      ); });
socket.on('AUX'             , function(data){ avr.SendCommand('source-selection', undefined, 'AUX'             ); });
socket.on('TV'              , function(data){ avr.SendCommand('source-selection', undefined, 'TV'              ); });
socket.on('Cable Sat'       , function(data){ avr.SendCommand('source-selection', undefined, 'Cable Sat'       ); });
socket.on('STB'             , function(data){ avr.SendCommand('source-selection', undefined, 'STB'             ); });
socket.on('Radio'           , function(data){ avr.SendCommand('source-selection', undefined, 'Radio'           ); });
socket.on('Game'            , function(data){ avr.SendCommand('source-selection', undefined, 'Game'            ); });
socket.on('USB'             , function(data){ avr.SendCommand('source-selection', undefined, 'USB'             ); });
socket.on('Disc'            , function(data){ avr.SendCommand('source-selection', undefined, 'Disc'            ); });
socket.on('Media Server'    , function(data){ avr.SendCommand('source-selection', undefined, 'Media Server'    ); });
socket.on('Home Network'    , function(data){ avr.SendCommand('source-selection', undefined, 'Home Network'    ); });
socket.on('AM'              , function(data){ avr.SendCommand('source-selection', undefined, 'AM'              ); });
socket.on('FM'              , function(data){ avr.SendCommand('source-selection', undefined, 'FM'              ); });
socket.on('vTuner'          , function(data){ avr.SendCommand('source-selection', undefined, 'vTuner'          ); });
socket.on('Bluetooth'       , function(data){ avr.SendCommand('source-selection', undefined, 'Bluetooth'       ); });



//    //send data to client
//    setInterval(function(){
//        //socket.emit('date', counter);
//        //socket.emit('date', {'date': new Date()});
//        
//        //Example1
//        // socket.emit('date', {'date': jsonFile });
//        socket.emit('jsonFile', jsonFile);
//        
//    }, 1000);
//


  //    //recieve client data
  //  socket.on('client_data', function(data){
  //      process.stdout.write(data.letter);
  //  });

});






//io.sockets.on('connection', function (socket) {
//  socket.emit('news', { hello: 'world' }); // Send data to client
//
//  // wait for the event raised by the client
//  socket.on('my other event', function (data) {  
//    console.log(data);
//  });
//});