var net = require('net');     //  Moved to default

var HOST = '192.168.0.98';
var PORT = 10025;

//buildRequest( Parameter ,Zonename(optional) ,Source(optional) );
//buildRequest( arrayOptParamA ,arrayOptParamB(optional) ,arrayOptParamC(optional) );

//Options parameter A                             
var arrayOptParamA = [];
arrayOptParamA[0]  = 'source-selection' ;                                                                                                             
arrayOptParamA[1]  = 'power-off'        ;                                                                                                             
arrayOptParamA[2]  = 'power-on'         ;                                                                                                             
arrayOptParamA[3]  = 'mute-toggle'      ;                                                                                                             
arrayOptParamA[4]  = 'mute-on'          ;                                                                                                             
arrayOptParamA[5]  = 'mute-off'         ;                                                                                                             
arrayOptParamA[6]  = 'volume-down'      ;                                                                                                             
arrayOptParamA[7]  = 'volume-up'        ;                                                                                                             
arrayOptParamA[8]  = 'ok'               ;                                                                                                             
arrayOptParamA[9]  = 'home'             ;                                                                                                             
arrayOptParamA[10] = 'options'          ;                                                                                                             
arrayOptParamA[11] = 'down'             ;                                                                                                             
arrayOptParamA[12] = 'up'               ;                                                                                                             
arrayOptParamA[13] = 'left'             ;                                                                                                             
arrayOptParamA[14] = 'right'            ;                                                                                                             
arrayOptParamA[15] = 'back'             ;                                                                                                             
arrayOptParamA[16] = 'forward'          ;                                                                                                             
arrayOptParamA[17] = 'pause'            ;                                                                                                             
arrayOptParamA[18] = 'play'             ;                                                                                                             
arrayOptParamA[19] = 'next'             ;                                                                                                             
arrayOptParamA[20] = 'previous'         ;                                                                                                             
arrayOptParamA[21] = 'sleep'            ;                                                                                                             
arrayOptParamA[22] = 'delay'            ;                                                                                                             
arrayOptParamA[23] = 'channel-up'       ;                                                                                                             
arrayOptParamA[24] = 'channel-down'     ;                                                                                                             
arrayOptParamA[25] = 'tuner-up'         ;                                                                                                             
arrayOptParamA[26] = 'tuner-down'       ;                                                                                                             
                                                                                                              
//Options parameter B                                                                                                             
var arrayOptParamB = [];                                                                                                           
arrayOptParamB[0] = 'Main Zone'         ;                                                                                                             
arrayOptParamB[1] = 'Zone2'             ;                                                                                                             
                                                                                                              
//Options parameter C                                                                                                             
var arrayOptParamC = [];                                                                                                             
arrayOptParamC[0]  = 'AUX'              ;                                                                                                             
arrayOptParamC[1]  = 'TV'               ;                                                                                                             
arrayOptParamC[2]  = 'Cable Sat'        ;                                                                                                             
arrayOptParamC[3]  = 'STB'              ;                                                                                                             
arrayOptParamC[4]  = 'Radio'            ;                                                                                                             
arrayOptParamC[5]  = 'Game'             ;                                                                                                             
arrayOptParamC[6]  = 'USB'              ;                                                                                                             
arrayOptParamC[7]  = 'Disc'             ;                                                                                                             
arrayOptParamC[8]  = 'Media Server'     ;                                                                                                             
arrayOptParamC[9]  = 'Home Network'     ;
arrayOptParamC[10] = 'AM'               ;
arrayOptParamC[11] = 'FM'               ;
arrayOptParamC[12] = 'vTuner'           ;
arrayOptParamC[13] = 'Bluetooth'        ;

exports.SendCommand = function(cmd, zone, param){

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
    client.write(buildRequest(cmd,zone,param        ));
      console.log('CONNECTED TO: ' + HOST + ':' + PORT);
      client.destroy();     // Added Later
  });

}




    //client.write(buildRequest('source-selection','',''));


