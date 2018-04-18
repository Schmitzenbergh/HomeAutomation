var http = require("http");  

var options = {
  hostname: '192.168.0.97',
  port: 1925,
  path: '/5/context',
  method: 'GET',
  headers: {
    'Content-Type': 'text/html',
    'Content-Length': Buffer.byteLength("")
  }
};



exports.getJSONstring = function(){ getJSON(); return JSON.stringify(Result);}
exports.getJSONobj = function(){ getJSON(); return Result; }
getJSON = function(){
 
  var req = http.request( options, function(res) {
    res.on('data', (chunk) => {
      Result = JSON.parse(chunk);
    });//res.on('end', () => { /**/ });
  });
  req.end();
}



exports.getBufferobj = function(){ getBuffer(); return Result; }
exports.getBufferstring = function(){ getBuffer(); return Result.toString(); }
getBuffer = function(){
 
  var req = http.request( options, function(res) {
    res.on('data', (chunk) => {
      Result = chunk;
    });//res.on('end', () => { /**/ });
  });
  req.end();
}




jObj = { "key": "VolumeDown" };
proto='http://';
hostname= '192.168.0.97';
port= 1925;
path= '/5/input/key';



var postOptions = {

  uri: proto + hostname + ':' + port + path,
  body: jObj,
  json: true,
  method: 'POST',
};


exports.postBufferobj = function(){
//options = { url: sUri + ':' + sPort + sArrayPaths[arrPos], body: jObj, json: true }

    request.post( postOptions, function(err, res) {
        if ( err || res.statusCode != 200){ 
            console.log(err);
        }
    });
  
return Result; }

  //var req = http.request( options, function(res) {
  //  res.on('data', (chunk) => {
  //    Result = JSON.parse(chunk);
  //  });//res.on('end', () => { /**/ });
  //});
  //req.end();









//options = { url: sUri + ':' + sPort + sArrayPaths[arrPos], body: jObj, json: true }


//function postJSON(arrPos, jObj, callback){    //  Example:   postJSON('12', { "key": "VolumeDown" }, function(callback){ console.log(callback) });
//    if ( arrPos < 1 ) return;
//    request.post({ url: sUri + ':' + sPort + sArrayPaths[arrPos], body: jObj, json: true } , 
//        function(err, res) {
//            if ( err || res.statusCode != 200){ 
//              console.log(err);
//            }
//            //console.log( 'Modified: ' + res.request.uri.href + ' ' + res.request.body );
//            callback('Modified: ' + res.request.uri.href + ' ' + res.request.body)
//        }
//    );
//}



//function getJSON(arrPos, callback){           //Example: getJSON('9',function(callback){ console.log(callback)})
//
//    if ( arrPos < 1 ) return;
//    request.get({ uri: sUri + ':' + sPort + sArrayPaths[arrPos], json: true } , 
//        function(err, res) {
//            if ( err || res.statusCode != 200){ 
//              console.log(err);
//            }
//            return callback(JSON.parse(res));
//            //callback(res.body);
//        }
//    );
//}



//function postJSON(arrPos, jObj, callback){    //  Example:   postJSON('12', { "key": "VolumeDown" }, function(callback){ console.log(callback) });
//    if ( arrPos < 1 ) return;
//    request.post({ url: sUri + ':' + sPort + sArrayPaths[arrPos], body: jObj, json: true } , 
//        function(err, res) {
//            if ( err || res.statusCode != 200){ 
//              console.log(err);
//            }
//            //console.log( 'Modified: ' + res.request.uri.href + ' ' + res.request.body );
//            callback('Modified: ' + res.request.uri.href + ' ' + res.request.body)
//1        }
//    );
//}












exports = Result = {};