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

    socket.on('volup', function(data){  avr.SendCommand('mute-on'); });
    socket.on('voldown', function(data){ avr.SendCommand('mute');   });


socket.on('on', function(data){ avr.VolDown(); });   
socket.on('off', function(data){ avr.SendCommand('Off'); });   
socket.on('sleep', function(data){ avr.SendCommand('sleep'); });   
socket.on('play', function(data){ avr.SendCommand('play'); });   
socket.on('pause', function(data){ avr.SendCommand('pause'); });   
socket.on('forward', function(data){ avr.SendCommand('forward'); });   
socket.on('reverse', function(data){ avr.SendCommand('reverse'); });   
socket.on('next', function(data){ avr.SendCommand('next'); });   
socket.on('previous', function(data){ avr.SendCommand('previous'); });   
socket.on('volumeDown', function(data){ avr.SendCommand('VolumeDown'); });   
socket.on('volumeUp', function(data){ avr.SendCommand('VolumeUp'); });   
socket.on('muteToggle', function(data){ avr.SendCommand('muteToggle'); });   
socket.on('mute-on', function(data){ avr.SendCommand('mute-on'); }); 
socket.on('mute-off', function(data){ avr.SendCommand('mute-off'); }); 
socket.on('up', function(data){ avr.SendCommand('up'); });   
socket.on('right', function(data){ avr.SendCommand('right'); });   
socket.on('down', function(data){ avr.SendCommand('down'); });   
socket.on('left', function(data){ avr.SendCommand('left'); });   
socket.on('ok', function(data){ avr.SendCommand('ok'); });   
socket.on('back', function(data){ avr.SendCommand('back'); });   
socket.on('home', function(data){ avr.SendCommand('home'); });   
socket.on('info', function(data){ avr.SendCommand('info'); });   
socket.on('options', function(data){ avr.SendCommand('options'); }); 
socket.on('heartAlive', function(data){ avr.SendCommand('heartAlive'); });   













































    //send data to client
    setInterval(function(){
        //socket.emit('date', counter);
        //socket.emit('date', {'date': new Date()});
        
        //Example1
        // socket.emit('date', {'date': jsonFile });
        socket.emit('jsonFile', jsonFile);
        
    }, 1000);

    socket.emit('button1', { hello: 'world' }); // Send data to client

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