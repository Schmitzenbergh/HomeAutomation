
<<<<<<< HEAD
require('./db.paths');

function buildvar(){
//function varBuilder(){
  var varArray      = fs.readFileSync(pathconfigvar + "./db.arrays", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = [''];");
//  exports.keyArray  = keyArray = fs.readFileSync(pathconfigvar + "./db.arrays", 'UTF8').replace(/\n/g,'').split("\r").map( x => x );

  var varBool       = fs.readFileSync(pathconfigvar + "./db.bools", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = '';");
//  exports.keyBool   = keyBool = fs.readFileSync(pathconfigvar + "./db.bools", 'UTF8').replace(/\n/g,'').split("\r").map(x => x + '\n');

  var varInterger   = fs.readFileSync(pathconfigvar + "./db.integers", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = '';");
//  exports.keyInterger = keyInterger = fs.readFileSync(pathconfigvar + "./db.integers", 'UTF8').replace(/\n/g,'').split("\r").map(x => x + '\n');

  var varObject     = fs.readFileSync(pathconfigvar + "./db.objects", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = {};");
//  exports.keyObject = keyObject = fs.readFileSync(pathconfigvar + "./db.objects", 'UTF8').replace(/\n/g,'').split("\r").map(x => x + '\n');

  var varString     = fs.readFileSync(pathconfigvar + "./db.strings", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x +  " = '';");
//  exports.keyString = keyString = fs.readFileSync(pathconfigvar + "./db.strings", 'UTF8').replace(/\n/g,'').split("\r").map(x => x + '\n');
=======
function varBuilder(){
  var varArray    = fs.readFileSync(pathconfigvar + "./db.arrays", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = [''];");
  var varBool     = fs.readFileSync(pathconfigvar + "./db.bools", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = '';");
  var varInterger = fs.readFileSync(pathconfigvar + "./db.integers", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = '';");
  var varObject   = fs.readFileSync(pathconfigvar + "./db.objects", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x + " = {};");
  var varString   = fs.readFileSync(pathconfigvar + "./db.strings", 'UTF8').replace(/\n/g,'').split("\r").map(x => '\n' + x +  " = '';");
>>>>>>> parent of 65b2cc8... ...revert this, some msitake

  fs.writeFileSync( pathconfigvar + "./db.var",fs.readFileSync(pathconfigvar + "./db.paths", 'UTF8'));

  for ( x = 0; varArray.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Array:');
    }
    if ( varArray[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varArray[x] );
    }
  }

  for ( x = 0; varBool.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Bool:');
    }
    if ( varBool[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varBool[x] );
    }
  }

  for ( x = 0; varInterger.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Integer:');
    }
    if ( varInterger[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varInterger[x] );
    }
  }

  for ( x = 0; varObject.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//Object:');
    }
    if ( varObject[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varObject[x] );
    }
  }

  for ( x = 0; varString.length > x; x++ ){
    if ( x == 0 ){
      fs.appendFileSync( pathconfigvar + "./db.var", '\n\n//String:');
    }
    if ( varString[x].toString().length > 7){
      fs.appendFileSync( pathconfigvar + "./db.var", varString[x] );
    }
  }
<<<<<<< HEAD
}

buildvar();
=======
};
varBuilder();

>>>>>>> parent of 65b2cc8... ...revert this, some msitake

