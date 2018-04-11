setInterval(randomIntGenerator, 1000);

var theVar = 0;

function setVar(someVar){
    
    theVar = someVar;
    document.getElementById("demo").innerHTML = someVar;
}

function randomIntGenerator(){
    setVar(Math.floor((Math.random() * 10) + 1)); 
}