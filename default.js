require('./config/var/db.paths');
//module.exports.repl.ignoreUndefined = true;



path = require('path');
net = require('net');
http = require('http');
url = require('url');
fs = require('fs');

hue = require('hue-sdk');     //hue = require( pathresources + './hue-sdk/lib/hue.js'),
client = new hue.Hue(require( pathconfig + './.credentials.json' ));

require('./config/var/db.var.builder.js');
require('./config/var/db.var');

sensor = require( pathhuesensor + 'sensor.js' );
light = require( pathhuelight + 'light.js' );
avr = require( pathavrhk171s + 'default.js');
tv = require( pathsmarttv + 'tv.js' );

/*******\
| Start |###############################################################################################################################################################################
\*******/

setTimeout(function(){ require('./server'); 

light.loadInfoAll();
sensor.loadInfoAll();

  setInterval(function(){  
    counter++;
    light.getInfoAll();
    sensor.getInfoAll();

    if (( counter % 300) == 0 ){
       light.saveInfoAll();
      sensor.saveInfoAll();
    }


  }, 1000);


}, 2000);

