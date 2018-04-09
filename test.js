var net = require('net');

var HOST = '192.168.0.98';
var PORT = 10025;

// Supported commands:
// volume-down
// mute-on
// source-selection (param is used: Component, DISC)
// Play

function buildRequest(cmd, zone, param) {
   var text = '';
   var payload = '<?xml version="1.0" encoding="UTF-8"?> <harman> <bds> <common> <control> <name>' + cmd + '</name> <zone>' + zone + '</zone> <para>' + param + '</para> </control> </common> </bds> </harman>';
   zone = zone || 'Main Zone';
   param = param || ''
   text += 'POST HK_APP HTTP/1.1\r\n';
   text += 'Host: :' + PORT + '\r\n';
   text += 'User-Agent: Harman Kardon BTS Remote Controller/1.0\r\n';
   text += 'Content-Length: ' + payload.length + '\r\n';
   text += '\r\n';
   text += payload;
   return text;
}

var client = new net.Socket();
client.connect(PORT, HOST, function() {
    console.log('CONNECTED TO: ' + HOST + ':' + PORT);
    client.write(buildRequest('mute-on'));
    client.destroy();     // Added Later
});

//  // Add a 'data' event handler for the client socket
//  // data is what the server sent to this socket
//  client.on('data', function(data) {
//      console.log('DATA: ' + data);
//      // Close the client socket completely
//      client.destroy();   
//  });



//  // Add a 'close' event handler for the client socket
//  client.on('close', function() {
//      console.log('Connection closed');
//  });
//  
//buildRequest('mute-off','Main Zone','MHL')
