var my_object = {a:1, b:2, c:2};

var len = 0;
for (var o in my_object) {
    len++;
}

console.log('Size of object: '+len);

console.log('Size of object: '+ Object.keys(my_object).length);