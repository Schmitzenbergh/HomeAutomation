var http = require("http");  

proto='http://';
hostname= '192.168.0.97';
port= 1925;
path= '/5/ambilight/processed';
jObj = {};

var options = {
  hostname: hostname,
  port: port,
  path: path,
  method: 'GET',
  headers: {
    'Content-Type': 'text/html',
    'Content-Length': Buffer.byteLength("")
  }
};



exports.returnJSONstring = function(){ getJSON(); return JSON.stringify(Result);}
exports.returnJSONobj = function(){ getJSON(); return Result; }
getJSON = function(){
 
  var req = http.request( options, function(res) {
    res.on('data', (chunk) => {
      Result = JSON.parse(chunk);
    });//res.on('end', () => { /**/ });
  });
  req.end();
}



exports.returnBufferobj = function(){ getBuffer(); return Result; }
exports.returnBufferstring = function(){ getBuffer(); return Result.toString(); }
getBuffer = function(){
 
  var req = http.request( options, function(res) {
    res.on('data', (chunk) => {
      Result = chunk;
    });//res.on('end', () => { /**/ });
  });
  req.end();
}

exports = Result = {};




//exports.getJSON = function(path, callback){
//
//    var getOptions = {
//      hostname: '192.168.0.97',
//      port: 1925,
//      path: '/5/activities/tv',
//      method: 'GET',
//      headers: {
//        'Content-Type': 'text/html',
//        'Content-Length': Buffer.byteLength("")
//      }
//    };
//
//    var req = http.request( getOptions, function(res) {
//      res.on('data', (chunk) => {
//        Result = JSON.parse(chunk);
//      });//res.on('end', () => { /**/ });
//    });
//    req.end();
//
//    return Result;
//}
