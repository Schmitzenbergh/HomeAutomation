var http      = require('http');
var https = require('https');
var fs = require('fs');
var path = require('path');

//var app = http.createServer();
//var io  = ioo.listen(http.createServer());

// ... Place here Socket.IO configuration...

//var port = 8080;

const io = require('socket.io')(server, {
  path: './',
  serveClient: false,
  // below are engine.IO options
  pingInterval: 10000,
  pingTimeout: 5000,
  cookie: false
});

//app.listen( port, function() { console.log( 'Server started' ); } );
//http.createServer().listen( 8080, function() { console.log( 'Server started' ); } );

console.log('init Server...');
 
//http.createServer().listen( 8080, function(request, response){
http.createServer(function (request, response){
  console.log('request starting...');

  var filePath = '.' + request.url;
  if (filePath == './')
      filePath = './index.html';

      var filePath = '.' + request.url;
      if (filePath == './')
          filePath = './index.html';
  
      var extname = path.extname(filePath);
      var contentType = 'text/html';
      switch (extname) {
          case '.js':
              contentType = 'text/javascript';
              break;
          case '.css':
              contentType = 'text/css';
              break;
          case '.json':
              contentType = 'application/json';
              break;
          case '.png':
              contentType = 'image/png';
              break;      
          case '.jpg':
              contentType = 'image/jpg';
              break;
          case '.wav':
              contentType = 'audio/wav';
              break;
      }
  
      fs.readFile(filePath, function(error, content) {
          if (error) {
              if(error.code == 'ENOENT'){
                  fs.readFile('./404.html', function(error, content) {
                      response.writeHead(200, { 'Content-Type': contentType });
                      response.end(content, 'utf-8');
                  });
              }
              else {
                  response.writeHead(500);
                  response.end('Sorry, check with the site admin for error: '+error.code+' ..\n');
                  response.end(); 
              }
          }
          else {
              response.writeHead(200, { 'Content-Type': contentType });
              response.end(content, 'utf-8');
          }
      });

   }).listen(8080);



io.listen(http.createServer()).sockets.on( 'connection', function( socket ) {
    // Management messages
    socket.on( 'connect', function( name, fn ) { connect( socket, name, fn ); });
    socket.on( 'disconnect', function() { disconnect( socket.id ); });

    socket.on( 'joinRoom', function( roomName, fn ) { joinRoom( socket, roomName, fn ); });
    socket.on( 'leaveRoom', function( roomName, fn ) { leaveRoom( socket, roomName, fn ); });
} );


//...


function joinRoom( socket, roomName, fn ) {
    socket.join( roomName );
    socket.broadcast.to( roomName ).emit( 'serverMessage', 'a user enters' );
    socket.emit( 'message', 'You enter in room ' + roomName );
}

function leaveRoom( socket, roomName, fn ) {
    socket.leave( roomName );
    socket.broadcast.to( roomName ).emit( 'serverMessage', 'a user leaves' );
    socket.emit( 'message', 'You leave room ' + roomName );
}



//https://stackoverflow.com/questions/8424886/socket-onconnection-event-never-fired-nodejs-express-socket-io