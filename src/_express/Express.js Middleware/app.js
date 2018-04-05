var http = require('http');
var connect = require('connect');

var ipban = require('./ipban.js');
var app = connect();
app.use(ipban());
app.use(function(req, res) {
    res.end('Hello!');
});

http.createServer(app).listen(3000);




//var ipfilter = require('./ipfilter');
//app.configure(function(){
//    app.use(ipfilter('on'));