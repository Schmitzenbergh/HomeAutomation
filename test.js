#!/usr/bin/env node

//getmanname
function Result(){
  console.log( Result2() );
}

function Result2(){
  return ( Result3() );
}

function Result3(){
  return ("test");
}

Result()


//getmanname
function getManufacturerNameCall(){
  console.log( getManufacturerName() );
}

function getManufacturerName(){
  return ( Result3() );
}

function Result3(){
  return ("test");
}

Result()