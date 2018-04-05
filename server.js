var http = require('http');
var url = require('url');
var fs = require('fs');
//var fs = require('angular-json-tree');
var path = require('path');
var jsonFile=fs.readFileSync('db.json', 'utf8');
var jsonObj = JSON.parse(jsonFile);
var server;
var counter = 1;

server = http.createServer(function(req, res){
    // your normal server code
    var path = url.parse(req.url).pathname;
    counter++;
    switch (path){
        case '/':
            //res.writeHead(200, {'Content-Type': 'text/html'});
            //res.write('<h1>Hello! Try the <a href="/test.html">Test page</a></h1>');
            //res.end();
            fs.readFile('index.html', function(err, data){
              if (err){ 
                  return send404(res);
              }
              //res.writeHead(200, {'Content-Type': path == 'db.json' ? 'text/javascript' : 'text/html'});
              res.writeHead(200, {'Content-type': 'text/html'});
              res.write(data, 'utf8');
              res.end();
            });
            break;
        case '/test.html':
        //case '/':
            //fs.readFile(__dirname + path, function(err, data){
            fs.readFile(__dirname, function(err, data){
                if (err){ 
                    return send404(res);
                }
                //res.writeHead(200, {'Content-Type': path == 'db.json' ? 'text/javascript' : 'text/html'});
                res.writeHead(200, {'Content-type': 'text/html'});
                res.write(data, 'utf8');
                res.end();
            });
        break;
        default: send404(res);
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


    //send data to client
    setInterval(function(){
        //socket.emit('date', counter);
        //socket.emit('date', {'date': new Date()});
        
        //Example1
        // socket.emit('date', {'date': jsonFile });
        socket.emit('jsonFile', jsonFile);
        
    }, 1000);

  //    //recieve client data
  //  socket.on('client_data', function(data){
  //      process.stdout.write(data.letter);
  //  });

});