#1 - to here
var myCallbackTemp = 
    function(data) { 
      console.log('got data: '+data);
    };

#2 - output here
var usingItNowTemp = 
    function(callback) { 
      callback('get it?');
    };

usingItNowTemp(myCallbackTemp);