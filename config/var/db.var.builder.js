require("./db.paths");
var fs = require('fs');

function varBuilder(){
  var varArray      = fs.readFileSync(pathconfigvar + "./db.arrays", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = [''];");
  exports.keyArray  = keyArray = fs.readFileSync(pathconfigvar + "./db.arrays", 'UTF8').replace(/\n/g,'').split("\r").map( x => x );

  var varBool       = fs.readFileSync(pathconfigvar + "./db.bools", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = '';");
  exports.keyBool   = keyBool = fs.readFileSync(pathconfigvar + "./db.bools", 'UTF8').replace(/\n/g,'').split("\r").map(x => x + '\n');

  var varInterger   = fs.readFileSync(pathconfigvar + "./db.integers", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = '';");
  exports.keyInterger = keyInterger = fs.readFileSync(pathconfigvar + "./db.integers", 'UTF8').replace(/\n/g,'').split("\r").map(x => x + '\n');

  var varObject     = fs.readFileSync(pathconfigvar + "./db.objects", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = {};");
  exports.keyObject = keyObject = fs.readFileSync(pathconfigvar + "./db.objects", 'UTF8').replace(/\n/g,'').split("\r").map(x => x + '\n');

  var varString     = fs.readFileSync(pathconfigvar + "./db.strings", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x +  " = '';");
  exports.keyString = keyString = fs.readFileSync(pathconfigvar + "./db.strings", 'UTF8').replace(/\n/g,'').split("\r").map(x => x + '\n');

<<<<<<< HEAD
  var varPredefined = fs.readFileSync(pathconfigvar + "./db.predefined", 'UTF8').replace(/\r/gm,'').split("\r").map(x => '\n' + x);
  var varPath = fs.readFileSync(pathconfigvar + "./db.paths", 'UTF8');
  
  fs.writeFileSync( pathconfigvar + "./db.var",'');
  //fs.appendFileSync( pathconfigvar + "./db.var",varPath);
  
  fs.writeFileSync( pathconfigvar + "./keyname",'');
  fs.writeFileSync( pathconfigvar + "./keyname.array",'');

//fs.writeFileSync( pathconfigvar + "./db.var",fs.readFileSync(pathconfigvar + "./db.paths", 'UTF8'));

  //Array
=======
  fs.writeFileSync( pathconfigvar + "./db.var",fs.readFileSync(pathconfigvar + "./db.paths", 'UTF8'));
  fs.writeFileSync( pathconfigvar + "./keyname",'');
  fs.writeFileSync( pathconfigvar + "./keyname.array",'');

>>>>>>> parent of 32848da... ..update
  for ( x = 0; varArray.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Array:');
    }
    if ( varArray[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varArray[x] )
      fs.appendFileSync( pathconfigvar + "./keyname.array", keyArray[x] )
    }
  }

  for ( x = 0; varBool.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Bool:');
    }
    if ( varBool[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varBool[x] );
      fs.appendFileSync( pathconfigvar + "./keyname", keyBool[x] );
    }
  }

  for ( x = 0; varInterger.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Integer:');
    }
    if ( varInterger[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varInterger[x] );
      fs.appendFileSync( pathconfigvar + "./keyname", keyInterger[x] );
    }
  }

  for ( x = 0; varObject.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Object:');
    }
    if ( varObject[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varObject[x] );
      fs.appendFileSync( pathconfigvar + "./keyname", keyObject[x] );
    }
  }

  for ( x = 0; varString.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//String:');
    }
    if ( varString[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varString[x] );
      fs.appendFileSync( pathconfigvar + "./keyname", keyString[x] );
    }
  }
<<<<<<< HEAD
  for ( x = 0; keyString.length > x; x++ ){
        fs.appendFileSync( pathconfigvar + "./keyname", keyString[x] )
 }

fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Predefined:');
fs.appendFileSync( pathconfigvar + "./db.var", varPredefined );

//fs.writeFileSync(pathconfigvar + "./keyname", fs.readFileSync(pathconfigvar + "./keyname", 'UTF8'));

=======
>>>>>>> parent of 32848da... ..update
};
varBuilder();


