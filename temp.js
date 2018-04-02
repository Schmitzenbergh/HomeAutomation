function getCb(){
  tmpVar = callbackVar;
  if (callbackVar !== null && callbackVar !== undefined){
    resetCb();
    return tmpVar;
  }
}

function setCb(data){
  callbackVar = data;
}

function resetCb(){
  callbackVar = null;
}