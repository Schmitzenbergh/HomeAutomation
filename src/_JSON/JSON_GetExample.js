//    var jsonDataObj = { "key": "VolumeDown" };
//    request.post({
//        url: 'http://192.168.0.97:1925/5/input/key',
//        body: jsonDataObj,
//        json: true
//      }, function(error, response, body){
//      console.log(response.statusCode );
//    });






//     var request = require('request');
//    var sUri = 'http://192.168.0.97';
//    var sPort = '1925';
//    
//    var jsonGET = function (sPath){ 
//      return { uri: sUri + ':' + sPort + sPath, json: true, }; 
//    };
//    
//    var jsonPOST = function (sPath, jInfo){
//      return { uri: sUri + ':' + sPort + sPath, method: 'POST', json: true, body: jInfo }; 
//    };
//    
//    request(jsonGET("/5/ambilight/processed"), function(error, response, body) { console.log(body); });
//    request(jsonPOST("/5/input/key", { "key": "VolumeUp" } ), function (error, res, body){ console.log(res.caseless.dict.date); });










<!DOCTYPE html>
<html>
<body>

<div id="id01"></div>

<script>
var xmlhttp = new XMLHttpRequest();
var url = "myTutorials.txt";

xmlhttp.onreadystatechange = function() {
    if (this.readyState == 4 && this.status == 200) {
        var myArr = JSON.parse(this.responseText);
        myFunction(myArr);
    }
};
xmlhttp.open("GET", url, true);
xmlhttp.send();

function myFunction(arr) {
    var out = "";
    var i;
    for(i = 0; i < arr.length; i++) {
        out += '<a href="' + arr[i].url + '">' + 
        arr[i].display + '</a><br>';
    }
    document.getElementById("id01").innerHTML = out;
}
</script>

</body>
</html>












###########################################################################



var request = require("request");
var myJSON = require("JSON");

function getMyBody(url, callback) {
  request({
    url: url,
    json: true
  }, function (error, response, body) {
    if (error || response.statusCode !== 200) {
      return callback(error || {statusCode: response.statusCode});
    }
    callback(null, JSON.parse(body));  
  });
}

getMyBody(url, function(err, body) {
  if (err) {
    console.log(err);
  } else {
    js_traverse(body); 
  }
});




#########################################################################




























