#!/usr/bin/env node

exports.sayHelloInEnglish = function() {
  return "Hello";
};

exports.sayHelloInSpanish = function() {
  return "Hola";
};







// In the code above, we could have replaced exports with module.exports
// and achieved the same result. If this seems confusing, 
// remember that exports and module.exports reference the same object.

