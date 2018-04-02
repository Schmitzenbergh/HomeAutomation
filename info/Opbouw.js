//Math.floor((Math.random() * 10) + 1)
//if ( result.state.buttonevent !== undefined && result.state.buttonevent !== null)






getOn = function(){

  var retValueContent = undefined;
  var tmpVar = undefined;
  client.get('/lights/1/', function (err, result) {
    if ( err || typeof result === undefined){ return err;}
    retValue(result.state.on);

    function retValue(input){
      if (input !== null && input !== undefined){ //Set from input
        retValueContent = input;                  //saveResult to an global var
      } else {                                    //Get from variable
        var tmpVar = retValueContent;             //getResult from the global var
        retValueContent = null;                   //resetResult
        return tmpVar;                            //returnResult
      }
    }
  })
}



  if (input !== null && input !== undefined){ //Set from input
    retValueContent = input;                  //saveResult to an global var
  } else {                                    //Get from variable
    var tmpVar = retValueContent;             //getResult from the global var
    retValueContent = null;                   //resetResult
    return tmpVar;                            //returnResult
  }
  
  
  
  
  return retValue();
}



























arrMyCallback = [''];


initCallBack = function(){  
  for ( i = 0; i < arrMyCallback.Length; i++){ //Zoek opslaglocatie
    if ( arrMyCallback[i] === '' ){
      arrMyCallback[i] === 'GetValue'         //Reserveer opslaglocatie
      return i;                               //Return opslaglocatienummer
    }
  }

  if ( i === arrMyCallback.Length){           //een leeg array
    return arrMyCallback.Length;
  }
}

setCallBack = function(loc, data){              //set de callback variabel
  arrMyCallback[x] = data;
}

getCallBack = function(loc){                    //get the callback variable
  return arrMyCallback[x];
}

resetCallBack = function(loc){                  //reset the callback variable
  arrMyCallback[loc] = '';
}





//function getCallback(){
//  tmpVar = callbackVar;
//  if (callbackVar !== null && callbackVar !== undefined){
//    resetCallback();
//    return tmpVar;
//  }
//}
//
//function setCallback(data){
//  callbackVar = data;
//}
//
//function resetCallback(){
//  callbackVar = null;
//}