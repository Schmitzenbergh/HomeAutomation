


somearray = [];
somearray[0] = "10";
somearray[1] = "9";
somearray[2] = "8";
somearray[3] = "7";
somearray[4] = "6";
somearray[5] = "5";
somearray[6] = "4";
somearray[7] = "3";
somearray[8] = "2";
somearray[9] = "1";



function returnArrayValue(sVariableName, iPosition){  "use strict"
  let temparr = global[sVariableName];
  return temparr[iPosition];
};  
console.log(returnArrayValue("somearray", 1));

//CONSOLE: 9


