require("./db.paths");
var fs = require('fs');

function varBuilder(){
  var varArray = fs.readFileSync(pathconfigvar + "./db.arrays", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map(x => '\n' + x + " = [''];");
  var keyArray = fs.readFileSync(pathconfigvar + "./db.arrays", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map( x => '\n' + x );

  var varBool = fs.readFileSync(pathconfigvar + "./db.bools", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map(x => '\n' + x + " = '';");
  var keyBool = fs.readFileSync(pathconfigvar + "./db.bools", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map( x => '\n' + x );

  var varInteger = fs.readFileSync(pathconfigvar + "./db.integers", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map(x => '\n' + x + " = '';");
  var keyInteger = fs.readFileSync(pathconfigvar + "./db.integers", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map( x => '\n' + x );

  var varObject = fs.readFileSync(pathconfigvar + "./db.objects", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map(x => '\n' + x + " = {};");
  var keyObject = fs.readFileSync(pathconfigvar + "./db.objects", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\n").map( x => '\n' + x );

  var varString = fs.readFileSync(pathconfigvar + "./db.strings", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map(x => '\n' + x +  " = '';");
  var keyString = fs.readFileSync(pathconfigvar + "./db.strings", 'UTF8').replace(/^\s*$(?:\r\n?|\n)/gm,'').split("\r").map( x => '\n' + x );

  fs.writeFileSync( pathconfigvar + "./db.var",fs.readFileSync(pathconfigvar + "./db.paths", 'UTF8'));
  
  fs.writeFileSync( pathconfigvar + "./keyname",'');
  fs.writeFileSync( pathconfigvar + "./keyname.array",'');

fs.writeFileSync( pathconfigvar + "./db.var",fs.readFileSync(pathconfigvar + "./db.paths", 'UTF8'));
fs.writeFileSync( pathconfigvar + "./db.var",fs.readFileSync(pathconfigvar + "./db.paths", 'UTF8'));
fs.writeFileSync( pathconfigvar + "./db.var",fs.readFileSync(pathconfigvar + "./db.paths", 'UTF8'));


  //Array
  for ( x = 0; varArray.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Array:');
    }
    if ( varArray[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varArray[x] )
    }
  }
  for ( x = 0; keyArray.length > x; x++ ){
    if ( keyArray[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./keyname.array", keyArray[x] )
    }
  }


//Bool
  for ( x = 0; varBool.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Bool:');
    }
    if ( varBool[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varBool[x] );
    }
  }
  for ( x = 0; keyBool.length > x; x++ ){
      fs.appendFileSync( pathconfigvar + "./keyname", keyBool[x] )
  }


//Integer
  for ( x = 0; varInteger.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Integer:');
    }
    fs.appendFileSync( pathconfigvar + "./db.var", varInteger[x] );
  }
  for ( x = 0; keyInteger.length > x; x++ ){
      fs.appendFileSync( pathconfigvar + "./keyname", keyInteger[x] )
  }


//Object
  for ( x = 0; varObject.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Object:');
    }
    if ( varObject[x].toString().length > 3){
      fs.appendFileSync( pathconfigvar + "./db.var", varObject[x] );
    }
  }
  for ( x = 0; keyObject.length > x; x++ ){
      fs.appendFileSync( pathconfigvar + "./keyname", keyObject[x] )
  }
  


//String
  for ( x = 0; varString.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//String:');
    }
    if ( varString[x].toString().length > 3){
      fs.appendFileSync( pathconfigvar + "./db.var", varString[x] );
    }
  }
  for ( x = 0; keyString.length > x; x++ ){
        fs.appendFileSync( pathconfigvar + "./keyname", keyString[x] )
 }


//Integer
  for ( x = 0; varInteger.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Integer:');
    }
    fs.appendFileSync( pathconfigvar + "./db.var", varInteger[x] );
  }
  for ( x = 0; keyInteger.length > x; x++ ){
      fs.appendFileSync( pathconfigvar + "./keyname", keyInteger[x] )
  }




   //fs.writeFileSync(pathconfigvar + "./keyname", fs.readFileSync(pathconfigvar + "./keyname", 'UTF8').replace(/^\s*[\r\n]/gm));
};
varBuilder();



