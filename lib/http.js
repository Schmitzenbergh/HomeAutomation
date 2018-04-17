//New approach, without delay or timeouts

var http = require("http");
var fs = require('fs');

























//httpGET();         //<-- is undefined
//console.log( httpGET() );         //<-- is undefined


//httpGET();

//var exports = module.exports = {};
//exports.httpGET = function(sHostname, iPort, sPath, callback){



//exports.httpGET = function(options, onResult)
//{
//    
//    console.log("rest::getJSON");
//
//    //var port = options.port == 443 ? https : http;
//    var req = http.request(options, function(res)
//    {
//        var output = '';
//        console.log(options.host + ':' + res.statusCode);
//        res.setEncoding('utf8');
//
//        res.on('data', function (chunk) {
//            output += chunk;
//        });
//
//        res.on('end', function() {
//            var obj = JSON.parse(output);
//            onResult(res.statusCode, obj);
//        });
//    });
//
//    req.on('error', function(err) {
//        //res.send('error: ' + err.message);
//    });
//
//    req.end();
//};



























   //const body = JSON.stringify(callback);
    
//                   var options = {
//                     hostname: sHostname,
//                     port: iPort,
//                     path: sPath,
//                     method: 'GET',
//                     headers: {
//                       'Content-Type': 'text/html',
//                       'Content-Length': Buffer.byteLength("")
//                     }
//                   };
//                http.get(options, function(res) {
//                  var body = '';
//                  res.on('data', function(chunk) {
//                    body += chunk;
//                  });
//                  res.on('end', function() {
//                    console.log(body);
//                  });
//                }).on('error', function(e) {
//                  console.log("Got error: " + e.message);
//                }); 








//            
//              var req = http.request(options, function(res) {
//                console.log('STATUS: ' + res.statusCode);
//                console.log('HEADERS: ' + JSON.stringify(res.headers));
//                res.setEncoding('utf8');
//                res.on('data', (chunk) => {
//                    console.log('BODY: ' + chunk);
//                    //console.log(" " + "TEST" + "                                                                         " + chunk);
//                    });
//                res.on('end', () => {
//                  if (typeof callback === {}){
//                      callback(null,"sometest654321");
//                  }
//                });
//              });
//              req.on('error', function(e) {
//                  console.log('problem with request: ' + e.message);
//              }); 
//              req.write('data\n');
//              req.write('data\n');
//              req.end();
 
//};




















//var chunks = [];

//var options = {
//  hostname: '192.168.0.97',
//  port: 1925,
//  path: '/5/ambilight/processed',
//  method: 'GET',
//  headers: {
//    'Content-Type': 'text/html',
//    'Content-Length': Buffer.byteLength("")
//  }
//};


//  console.log( httpGET() )       // <-- is undefined
//  

//exports.httpGET = function(options){
//   
// 
//  var req = http.request(options, function(res){      
//    //res.on('data', (chunk) => { consle });
//    res.on('data', function(chunk) {
//        setChunk(chunk);
//    });
//    res.on('end', () => {});
//  });
//
//  req.write('data\n');
//
//  req.end();
//
//
//  setChunk = function(chunk) {
//  //Response.prototype.setChunk = function(chunk) {
//      this.body += chunk;
//
//      return this;
//  };
//
//};






























    //res.on('end', () => {});    
    //res.end = function (chunk) {
    //  if (chunk){
    //    chunks.push(chunk);
    //  }
    //  var body = Buffer.concat(chunks).toString('utf8');
    //  console.log(req.path, body);
    //};


  //Result = JSON.parse(res);
  //console.log(res);
  //JSON.stringify(res);
  //fs.writeFileSync( "./temp.db", res);
  //      res.setEncoding('utf8');cd ./
  //      res.pipe(process.stdout);
  //    //  res.on('data', (chunk) => { 
  //    //    console.log(chunk);
  //    //    Result = JSON.parse("" + chunk); 
  //    //    });
  //res.on('end', () => { console.log('response: ENDED'); });
//  res.on('end', function() { console.log('finished'); });
//});
//req.on('error', function(e) { console.log('problem with request: ' + e.message); });
//
//// write data to request body
//req.end();

exports.httpGET = function(){
  body = '';
  var req = http.request( options = { hostname: '192.168.0.97', port: 1925, path: '/5/ambilight/processed', method: 'GET' }, function(res) {
    res.on('data', (chunk) => {
      //body += chunk;
      VarHolder = JSON.parse(chunk);
      });         //<-- got the needed output data
    res.on('end', () => {
     //console.log(body)
    });
  });
  req.write('data\n');
  req.end(body);
  return VarHolder;
};
















//console.log(httpGET('192.168.0.97', 1925, '/5/ambilight/processed'));
//        httpGET('192.168.0.97', 1925, '/5/ambilight/processed');
//        
//        
//        function httpGET(sHostname, iPort, sPath){
//           
//          var options = {
//            hostname: sHostname,
//            port: iPort,
//            path: sPath,
//            method: 'GET',
//            headers: {
//              'Content-Type': 'text/html',
//              'Content-Length': Buffer.byteLength("")
//            }
//          };
//        
//        
//          var req = http.request(options, function(res) {
//            res.on('data', (chunk) => { console.log(chunk); });
//            res.on('end', () => {});
//          });
//          req.write('data\n');
//          req.end();
//         
//        };



//var http = require("http");
//
//httpGET()
//
//function httpGET(){
//   
//  var req = http.request( options = { hostname: '192.168.0.97', port: 1925, path: '/5/ambilight/processed', method: 'GET' }, function(res) {
//    res.on('data', (chunk) => { console.log(chunk); });
//    res.on('end', () => {});
//  });
//  req.write('data\n');
//  req.end();
// };






//    exports.getCt = function (iLightNumber,cb){
//      
//
//        client.get('/lights/' + iLightNumber + '/', function (err, result) { 
//        if ( err){ return err; } 
//        iArrayLightCtCur[iLightNumber] = result.state.ct;
//        cb(result.state.ct);
//      });
//    };
/////var JSONStream = require('JSONStream');
/////var Stream = require('stream');
/////var http = require("http");
/////var buffers = [];
/////
/////console.log(httpGET());
/////function httpGET(){
/////   
/////  var options = {
/////    hostname: '192.168.0.97',
/////    port: 1925,
/////    path: '/5/ambilight/processed',
/////    method: 'GET',
/////    headers: {
/////      'Content-Type': 'text/html',
/////      'Content-Length': Buffer.byteLength("")
/////    }
/////  };
  
  // var retValue;//this is your returned value you need
  //var req = http.request(options, function(res){
      //var stream = JSONStream.parse('*')
      //res.pipe(stream)
      //stream.on('data', console.log.bind(console, 'an item'))  
      //tempvar = JSON.parse(chunk)
      //retValue.push(tempvar);
      //console.log(tempvar);
      //console.log(tempvar.layer1.bottom[0]);
      //tempvar = {};
      //var stream = JSONStream.parse('*')
      //console.log(JSON.parse(chunk));
//    res.on('data', function(chunk) { 
//      buffers.push(chunk);
//    });
//
//    res.on('end',function() {
//      JSON.parse(Buffer.concat(buffers).toString());
//    });
//    //res.pipe(stream)
//  });
  

  
//  req.write('data\n');
//  req.end();
//
 //};

//http.request(options, function(res) {
//  var stream = JSONStream.parse('*')
//  res.pipe(stream)
//  stream.on('data', console.log.bind(console, 'an item'))
//})

//http.request(options, function(res) {
//  var buffers = []
//  res
//    .on('data', function(chunk) {
//      buffers.push(chunk)
//    })
//    .on('end', function() {
//      JSON.parse(Buffer.concat(buffers).toString())
//    })
//})








//console.log(httpGET('192.168.0.97', 1925, '/5/ambilight/processed'));
//
//
//function httpGET(sHostname, iPort, sPath, callback){
//   
//  var options = {
//    hostname: sHostname,
//    port: iPort,
//    path: sPath,
//    method: 'GET',
//    headers: {
//      'Content-Type': 'text/html',
//      'Content-Length': Buffer.byteLength("")
//    }
//  };
//
//
//  var req = http.request(options, function(res) {
//    res.on('data', (chunk) => { 
//      console.log("" + chunk);
//      });
//    res.on('end', () => {});
//  });
//  req.write('data\n');
//  req.end();
//};




//getTransisitonTime = function (iLightNumber,cb){
//  var client.get('/lights/' + iLightNumber + '/', function (err, result) {
//    cb(result);
//    });
//};












