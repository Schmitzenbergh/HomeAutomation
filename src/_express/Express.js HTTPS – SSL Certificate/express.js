var fs = require('fs');

var hskey = fs.readFileSync('hacksparrow-key.pem');
var hscert = fs.readFileSync('hacksparrow-cert.pem')

var options = {
    key: hskey,
    cert: hscert
};
var app = require('express').createServer(options);