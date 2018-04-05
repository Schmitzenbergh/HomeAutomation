#!/usr/bin/env node

var myInit = function() {
    setTimeout(myInit, iTickrate);
}; myInit();
