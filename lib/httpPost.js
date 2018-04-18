var http = require("http");  

proto='http://';
hostname= '192.168.0.97';
port= 1925;
path= '/5/input/key';
jObj = { "key": "VolumeDown" };

var postOptions = {
  uri: proto + hostname + ':' + port + path,
  method: 'POST',
  body: jObj,
  json: true,
};



exports.pushBufferobj = function(){

    request.post( postOptions, function(err, res) {
        if ( err || res.statusCode != 200){ 
            console.log(err);
        }
    });
  
return Result; }

exports = Result = {};