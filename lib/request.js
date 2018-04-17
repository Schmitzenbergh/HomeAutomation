var http = require("http");  

var options = {
  hostname: '192.168.0.97',
  port: 1925,
  path: '/5/ambilight/processed',
  method: 'GET',
  headers: {
    'Content-Type': 'text/html',
    'Content-Length': Buffer.byteLength("")
  }
};

exports.httpGET = function(){
  
  var req = http.request( options, function(res) {
    res.on('data', (chunk) => {
      Result = JSON.parse(chunk);
    });//res.on('end', () => { /**/ });
  });
  req.end();
  return Result;
}

exports = Result = {};