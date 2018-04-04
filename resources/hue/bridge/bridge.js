exports.getInfoAll = function( iLightNumber,sValue){
  client.get('/', function (err, result) { 
    if ( err || typeof result === undefined ){ 
      return err;
    }  
  sObjectResults = result;
  console.log("getInfoAll-Bridge")
  });
};