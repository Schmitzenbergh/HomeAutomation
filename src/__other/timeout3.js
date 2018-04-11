#!/usr/bin/env node

function setDeceleratingTimeout(callback, factor, times)
{
    var internalCallback = function(tick, counter) {
        return function() {
            if (--tick >= 0) {
                setTimeout(internalCallback, ++counter * factor);
                callback();
            }
        }
    }(times, 0);

    setTimeout(internalCallback, factor);
};

// console.log() requires firebug    
setDeceleratingTimeout(function(){ console.log('hi'); }, 10, 10);
setDeceleratingTimeout(function(){ console.log('bye'); }, 100, 10);