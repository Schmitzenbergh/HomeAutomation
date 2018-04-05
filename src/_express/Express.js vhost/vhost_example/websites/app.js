var express = require('express')
  , routes = require('./routes')
  , user = require('./routes/user')
  , http = require('http')
  , path = require('path');

var app = express();

// vhost apps
var apple_localhost = require('./websites/apple.localhost');
var book_localhost = require('./websites/book.localhost');

app.configure(function(){
  app.set('port', process.env.PORT || 3000);
  app.set('views', __dirname + '/views');
  app.set('view engine', 'jade');
  app.use(express.favicon());
  app.use(express.logger('dev'));
  app.use(express.bodyParser());
  app.use(express.methodOverride());
  
  // apply the vhost middleware, before the router middleware
  app.use(express.vhost('apple.localhost', apple_localhost))
  app.use(express.vhost('*.localhost', book_localhost));

  app.use(app.router);
  app.use(express.static(path.join(__dirname, 'public')));
});

app.get('/', routes.index);

http.createServer(app).listen(app.get('port'), function(){
  console.log("vhost enabled Express server listening on port " + app.get('port'));
});