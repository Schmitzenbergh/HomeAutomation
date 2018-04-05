var fs = require('fs');
var access_logfile = fs.createWriteStream('./access.log', {flags: 'a'});

app.configure(function(){
    app.use(express.logger({stream: access_logfile }));
    app.set('views', __dirname + '/views');
    ...
});