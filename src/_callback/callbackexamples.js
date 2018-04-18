doParth= '/5/powerstate';

function foo(doParth, cb){
    request.get({ uri: sUri + ':' + sPort + doParth, json: true } , 
        function(err, res) {
            if ( err || res.statusCode != 200){ 
              console.log(err);
            }
            //console.log(res.body);
            cb(res.body);
        }
    );
}

foo(doParth, function(body){
  console.log(body);
  return body; // this is where you get the return value
});

///////////////////////////////////////////////////////////////////////////////////////////

var sArrayItems = [];
sArrayItems[0]='/5/powerstate';


function foo(callback){
    request.get({ uri: sUri + ':' + sPort + sArrayItems[0], json: true } , 
        function(err, res) {
            if ( err || res.statusCode != 200){ 
              console.log(err);
            }
            callback(res.body);
        }
    );
}

foo(function(callback){
  console.log(callback);
});

///////////////////////////////////////////////////////////////////////////////////////////

exports.sayHelloInEnglish = function() {
  return "Hello";
};

exports.sayHelloInSpanish = function() {
  return "Hola";
};

// "Hello"
console.log(greetings.sayHelloInEnglish());

// "Hola" 
console.log(greetings.sayHelloInSpanish());

///////////////////////////////////////////////////////////////////////////////////////////

//#1 - to here
var myCallbackTemp = 
    function(data) { 
     console.log(''+data)
    };
//2 - output here
var usingItNowTemp = 
    function(callback) { 
      callback('get it?');
    };

usingItNowTemp(myCallbackTemp);

///////////////////////////////////////////////////////////////////////////////////////////

function doHomework(subject, callback) {
  alert(`Starting my ${subject} homework.`);
  callback();
}

doHomework('math', function() {
  alert('Finished my homework');
});

///////////////////////////////////////////////////////////////////////////////////////////

callback = function(response) {

  response.on('data', function (chunk) {
    str += chunk;
  });

  response.on('end', function () {
    console.log(req.data);
    console.log(str);
    // your code here if you want to use the results !
  });
}

var req = http.request(options, callback).end();

///////////////////////////////////////////////////////////////////////////////////////////

function myNew(next){
    console.log("Im the one who initates callback");
    next("nope", "success");
}


myNew(function(err, res){
    console.log("I got back from callback",err, res);
});

///////////////////////////////////////////////////////////////////////////////////////////

callBackFunction (data, function ( err, response ){
     console.log(response)
}) 

// callbackfunction 
function callBackFuntion (data, callback){
    //write your logic and return your result as
callback("",result) //if not error
callback(error, "") //if error
}

///////////////////////////////////////////////////////////////////////////////////////////

#### Default.js

modRequest = require( '/lib/request.js' );
console.log(JSON.stringify(modRequest.httpGET()));


#### Request.js

var Result;

exports.httpGET = function(){
  
  var req = http.request( options, function(res) {
    res.on('data', (chunk) => {
      Result = JSON.parse(chunk);
    });
    res.on('end', () => { /**/ });
  });
  req.end();
  
  return Result;
};

exports = Result;

///////////////////////////////////////////////////////////////////////////////////////////

function myNew(next){
    console.log("Im the one who initates callback");
    next("nope", "success");
}


myNew(function(err, res){
    console.log("I got back from callback",err, res);
});

///////////////////////////////////////////////////////////////////////////////////////////




///////////////////////////////////////////////////////////////////////////////////////////





///////////////////////////////////////////////////////////////////////////////////////////










