#!/usr/bin/env node

var counter = 10;

var myFunction = function() {
    counter += 100;
    setTimeout(myFunction, counter);
    console.log(" Counter:" +  counter)
}; myFunction();