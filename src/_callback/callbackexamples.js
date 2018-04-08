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











